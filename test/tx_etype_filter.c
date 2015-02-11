#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include <stdlib.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <netpacket/packet.h>
#include <net/if.h>
#include <sys/stat.h>
#include <arpa/inet.h> // for htons
#include <linux/if_ether.h> // for ETH_P_1588

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

unsigned char buf[1500] = "this is a test";

int main(int argc, char *argv[])
{
   int sockfd;
   int err = 0, i = 0;
   int retval;
   int txq_index;
   struct igb_queue_select_cmd  config;
   unsigned char *hwaddr;
   unsigned short etype;
   struct ifreq device;
   struct sockaddr_ll ifsock_addr;

   etype = ETH_P_1588;
   txq_index = 2;

   sockfd = socket(PF_PACKET, SOCK_DGRAM, htons(etype));
   if (err == -1) 
   {
      printf("Failed to open a socket, errno is %d\n", errno);
      return 0 ;
   }

   ifsock_addr.sll_family = AF_PACKET;
   ifsock_addr.sll_protocol = htons(etype);

   memset(&device, 0, sizeof(device));
   strcpy(device.ifr_name, "eth0");

   err = ioctl(sockfd, SIOCGIFINDEX, &device);
   if (err == -1) 
   {
      printf("Failed to get the IF index, errno is %d\n", errno);
      return 0;
   }
   ifsock_addr.sll_ifindex = device.ifr_ifindex;

   err = bind(sockfd, (struct sockaddr *)&ifsock_addr, sizeof(ifsock_addr));
   if (err == -1) 
   {
      printf("Failed to bind the queue index!\n");
      return 0 ;
   }

   device.ifr_ifru.ifru_data = (char *)&config;
   config.type = SELECT_QUEUE_ON;
   config.flag = SHARED_QUEUE;
   config.filter_type = QSELECT_FILTER_ETYPE; 
   config.etype = etype;
   config.queue_index = txq_index;

   err = ioctl(sockfd, SIOSTXQUEUESELECT, &device);
   if (err == -1) 
   {
      printf("Failed to set the queue index!\n" );
      return 0 ;
   }

   i= 0;
   while (i < 5)
   {
      retval = sendto(sockfd, buf, sizeof(buf), 0, (struct sockaddr *)&ifsock_addr,sizeof(ifsock_addr));
      if (retval == -1)
         printf("Send failed, errno is %d\n", errno);	
      sleep(1);
      i++;
   }

   device.ifr_ifru.ifru_data = (char *)&config;
   config.type = SELECT_QUEUE_OFF;
   config.flag = SHARED_QUEUE;
   config.filter_type = QSELECT_FILTER_ETYPE; 
   config.etype = etype;
   config.queue_index = 2;

   err = ioctl(sockfd, SIOSTXQUEUESELECT, &device);

   if (err == -1) 
   {
      printf("Failed to set the queue index!\n" );
      return 0 ;
   }

   i= 0 ;
   while (i < 5)
   {
      retval = sendto(sockfd, buf, sizeof(buf), 0, (struct sockaddr *)&ifsock_addr,sizeof(ifsock_addr));
      printf("send: %x packets to default tx queue, pakcets size is %d\n",etype, retval);
      sleep(1);
      i++;
   }

   close(sockfd);
   return 0;
}


