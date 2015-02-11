#include <unistd.h>
#include <time.h>
#include <sys/time.h>
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

#define ETHERTYPE  0x8899 
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

unsigned char send_buf[] = { 
   0xff, 0xff, 0xff, 0xff, 0xff, 0xff, // 0-5:  Dst mac address
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 6-11: src mac address 
   0x88, 0xf7, // 12-13: Etyertype  
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
   int datasize = 100;
   int i = 0;
   unsigned short etype = ETH_P_1588;
   unsigned short rxq_index = 2;
   unsigned char *hwaddr;
   struct ifreq device;
   struct sockaddr_ll ifsock_addr;
   struct igb_queue_select_cmd  config;
   fd_set recv_set;
   struct timeval timeout;

//   etype = 0x8899;
   sock_fd = socket(PF_PACKET, SOCK_RAW, htons(ETH_P_ALL));

   if (sock_fd == -1) 
   {
      printf("Failed to open a socket!\n");
      return 0 ;
   }

   ifsock_addr.sll_family = AF_PACKET;
   ifsock_addr.sll_protocol = htons(etype);

   memset(&device, 0, sizeof(device));
   strcpy(device.ifr_name, "eth0");

   err = ioctl(sock_fd,SIOCGIFINDEX,&device);
   ifsock_addr.sll_ifindex = device.ifr_ifindex;

   datasize = sizeof(send_buf);
   err = bind(sock_fd, (struct sockaddr *)&ifsock_addr, sizeof(ifsock_addr));

   device.ifr_ifru.ifru_data = (char *)&config;
   config.type = SELECT_QUEUE_ON;
   config.flag = SHARED_QUEUE;
   config.filter_type = QSELECT_FILTER_ETYPE; 
   config.etype = etype;
   config.queue_index = rxq_index;

   err = ioctl(sock_fd, SIOSTXQUEUESELECT, &device);
   err = ioctl(sock_fd, SIOSRXQUEUESELECT, &device);

   if (err == -1) 
   {
      printf("Failed to set the queue index!, errno is %d\n", errno );
      return errno;
   }

   FD_ZERO(&recv_set);
   FD_SET(sock_fd, &recv_set);   
   timeout.tv_sec = 2;
   timeout.tv_usec = 0;

   while (i < 5)
   {
      err = sendto(sock_fd, send_buf, datasize, 0, (struct sockaddr *)&ifsock_addr, sizeof(ifsock_addr));
      if (err == -1)
      {
         printf("Send fail, Errno is %d\n", errno);
      }
      err = select(FD_SETSIZE, &recv_set, (fd_set *)0, (fd_set *)0, &timeout);
      if (err == 0)
      {
         printf("Recv timeout\n");
      }
      else 
      {
         err = recvfrom(sock_fd, recv_buf, sizeof(recv_buf), 0, NULL, 0);
         if (err == -1)
         {
            printf("recv from is err, errno is %d\n", errno);
            break;
         }
         err = strncmp(send_buf, recv_buf, sizeof(send_buf));
         if (err != 0)
         {
            printf("The date received is not correct\n" );
            break;
         }
         else
         {
            memset(recv_buf, 0, sizeof(recv_buf));
         }
      }

      i++;
   }

   device.ifr_ifru.ifru_data = (char *)&config;
   config.type = SELECT_QUEUE_OFF;
   config.flag = SHARED_QUEUE;
   config.filter_type = QSELECT_FILTER_ETYPE; 
   config.etype = etype;
   config.queue_index = 2;
   config.enable_ts = -1;

   err = ioctl(sock_fd, SIOSRXQUEUESELECT, &device);

   i = 0;
   while (i < 5)
   {
      err = sendto(sock_fd, send_buf, datasize, 0, (struct sockaddr *)&ifsock_addr, sizeof(ifsock_addr));
      if (err == -1)
      {
         printf("Send fail, Errno is %d\n", errno);
         break;
      }
      err = select(FD_SETSIZE, &recv_set, (fd_set *)0, (fd_set *)0, &timeout);
      if (err == 0)
      {
         printf("Recv timeout\n");
      }
      else 
      {
         err = recvfrom(sock_fd, recv_buf, sizeof(recv_buf), 0, NULL, 0);
         printf("The return value of recv from is %d\n", err);
      }
      i++;
   }

   close(sock_fd);
   return 0;
}


