#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char * argv[])
{
	int src_sockfd;
	int src_len, dst_len;
	struct sockaddr_in src_address, dst_address;
	int err=0;
	char *buf;
	int datasize = 1500;
	char src_ip[16], dst_ip[16];

	printf("Input the data size:");
	scanf("%d",&datasize);
	getchar();	

	printf("Input the src ip address:");
	gets(src_ip);	

	printf("Input the dst ip address:");
	gets(dst_ip);	

	src_sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	
	src_address.sin_family = AF_INET;
	src_address.sin_addr.s_addr = inet_addr(src_ip);
	src_address.sin_port = htons(61557);
	src_len = sizeof(src_address);

	bind(src_sockfd,(struct sockaddr *)&src_address, src_len);

	dst_address.sin_family = AF_INET;
	dst_address.sin_addr.s_addr = inet_addr(dst_ip);
	dst_address.sin_port = htons(61558);
	dst_len = sizeof(dst_address);
	
	buf = (char *)malloc(datasize);
	
	printf("Send UDP packets from %s to %s\n", src_ip, dst_ip);

	while(1)
	{
		err = sendto(src_sockfd, buf, datasize, 0, (struct sockaddr *)&dst_address, dst_len);	
      if (err == -1)
   		printf(" is %d\n", errno);
		sleep(1);
	}

	free(buf);
	return err;
}


