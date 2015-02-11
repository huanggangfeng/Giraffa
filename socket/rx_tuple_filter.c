#include <unistd.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netpacket/packet.h>
#include <net/if.h>
#include <sys/stat.h>
#include <linux/if_ether.h>
#include <string.h>
#include <arpa/inet.h> // for htons

#define ETHERTYPE  0x88F7 
#define SIOSTXQUEUESELECT       SIOCDEVPRIVATE
#define SIOSRXQUEUESELECT       (SIOCDEVPRIVATE+1)

struct filter_tuple {
   unsigned short protocol;
   unsigned short port;
};

enum igb_queue_select_type {
   SELECT_QUEUE_ON,
   SELECT_QUEUE_OFF,
};

enum igb_queue_select_flag {
   SHARED_QUEUE,
   EXCLUSIVE_QUEUE,
};


enum igb_filter_type {
   /*L2 Ether-type */
   QSELECT_FILTER_ETYPE = 0x1,
   /* protocol and destination TCP/UDP port */
   QSELECT_FILTER_TUPLE = (0x1 << 1),
};

struct igb_queue_select_cmd {
   int type; /* on/off */
   int flag; /* shared/exclusively */
   int queue_index; /* queue_index */
   int filter_type; /* filter type */
   unsigned short etype;
   struct filter_tuple tuple;
   unsigned short vlan_tag;
   int enable_ts;
};

unsigned char buf[] = { 
   0xff, 0xff, 0xff, 0xff, 0xff, 0xff, // 0-5:  Dst mac address
   0xa0, 0x36, 0x9f, 0x10, 0xcf, 0xb1, // 6-11: src mac address 
   0x08, 0x00, // 12-13: IP  
   0x45, 0x00, // 14-15: IPV4, headlength 20 
   0x00, 0x80, // 16-17: length: 128
   0x64, 0x11, // 18-19: Identification 0x6411
   0x40, 0x00, // 20-21:Don't Fragment
   0x40, // 22: Time to live 
   0x11, // 23: Protocol: UDP(17)
   0x9c, 0xa0, // 24-25: Header Checksum
   0x0a, 0x90, 0x12, 0x4e, // 26-29: Src ip
   0x0a, 0x90, 0x12, 0x4e, // 30-33: Dst ip
   0xf0, 0x75, // 34-35: Src port: 61557
   0xf0, 0x76, // 36-37: Dst port: 61558
   0x00, 0x6c, // 38-39: Length
   0x39, 0xec, // 40-41: CheckSum
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

char recv_buf[1522] = {0,};

int main()
{
   int sock_fd;
   int len; 
   int err;
   int i = 0;

   unsigned char *hwaddr;
   struct ifreq device;
   struct sockaddr_ll ifsock_addr;
   struct igb_queue_select_cmd  config;

   fd_set recv_set;
   struct timeval timeout;

   // Create a socket with ethertype: ETH_P_IP
   sock_fd = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_IP));

   if (sock_fd == -1) 
   {
      printf("Failed to open a socket!\n");
      return 0 ;
   }

   ifsock_addr.sll_family = AF_PACKET;
   ifsock_addr.sll_protocol = htons(ETH_P_IP);

   // Get the mac address of eth0
   memset(&device, 0, sizeof(device));
   strcpy(device.ifr_name, "eth0");
   err = ioctl(sock_fd, SIOCGIFHWADDR, &device);
   hwaddr = (unsigned char *)device.ifr_hwaddr.sa_data;
   for (i = 0; i< 6; i++)
      printf("%x:", hwaddr[i]);
   printf("\n");

   // Get the ifindex of eth0
   memset(&device, 0, sizeof(device));
   strcpy(device.ifr_name, "eth0");
   err = ioctl(sock_fd, SIOCGIFINDEX, &device);
   
   ifsock_addr.sll_ifindex = device.ifr_ifindex;

   // Bind this socket to eth0
   err = bind(sock_fd, (struct sockaddr *)&ifsock_addr, sizeof(ifsock_addr));
   if (err == -1)
   {
      printf("Failed to bind the sockt to eth0, errno is %d\n", errno );
      return 0 ;
   }
   // Set 2-tuple filter: protocol: UDP; Destination Port: 61558
   device.ifr_ifru.ifru_data = (char *)&config;
   config.type = SELECT_QUEUE_ON;
   config.flag = SHARED_QUEUE;
   config.filter_type = QSELECT_FILTER_TUPLE; 
   config.tuple.protocol = IPPROTO_UDP;
   config.tuple.port = 61558;
   config.queue_index = 2;
   config.enable_ts= 1;
   err = ioctl(sock_fd, SIOSRXQUEUESELECT, &device);
   if (err == -1) 
   {
      printf("Failed to set the queue index!, errno is %d\n", errno );
      return 0 ;
   }

   FD_ZERO(&recv_set);
   FD_SET(sock_fd, &recv_set);   
   timeout.tv_sec = 2;
   timeout.tv_usec = 0;
   i = 0;
   while (i < 5)
   {
      err = sendto(sock_fd, buf, sizeof(buf), 0, (struct sockaddr *)&ifsock_addr, sizeof(ifsock_addr));
      if (err == -1)
         printf("Send fail, Errno is %d\n", errno);
      else
         printf("Send packet, size is %d\n", err);
      err = select(FD_SETSIZE, &recv_set, (fd_set *)0, (fd_set *)0, &timeout);
      if (err == 0)
         printf("Receive Timeout\n");
      else
      {
         err = recvfrom(sock_fd, recv_buf, sizeof(recv_buf), 0, NULL, 0);
         if (err == -1)
            printf("Receive err, errno is %d\n", errno);
         else
            printf("Receive packet, size is %d\n", err);
      }
      i++;
   }

   device.ifr_ifru.ifru_data = (char *)&config;
   config.type = SELECT_QUEUE_OFF;
   config.flag = SHARED_QUEUE;
   config.filter_type = QSELECT_FILTER_TUPLE; 
   config.tuple.protocol = IPPROTO_UDP;
   config.tuple.port = 61558;
   config.queue_index = 2;
   config.enable_ts= 0;

   err = ioctl(sock_fd, SIOSRXQUEUESELECT, &device);

   close(sock_fd);
   return 0;
}


