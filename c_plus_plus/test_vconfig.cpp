#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <linux/sockios.h>
#include <linux/socket.h>
#include <linux/if.h>
#include <arpa/inet.h>
#include <algorithm>
#include <iostream>
#include <linux/ethtool.h>
#include <linux/if_vlan.h>

using namespace std;

static const uint16_t kVlanIDMask = 0x0FFF;
int m_sockfd;
string m_ifName("eth0");

int  vconfig(struct vlan_ioctl_args &if_request)
{
   int iores = ioctl(m_sockfd, SIOCSIFVLAN, &if_request);
   if (iores < 0)
   {
      std::cout << "failed to call SIOCSIFVLAN: " << errno << endl;;
   }
   return 0;
}

int enableVLAN(uint16_t vlanTCI)
{
   uint16_t vid = (vlanTCI & kVlanIDMask);

   struct vlan_ioctl_args if_request;
   memset(&if_request, 0, sizeof(if_request));
   strcpy(if_request.device1, m_ifName.c_str());
   if_request.cmd = ADD_VLAN_CMD;
   if_request.u.VID = vid;

   std::cout << "enable VLan" << vid << '\n';
   int error = vconfig(if_request);
   return error;
}

int disableVLAN(uint16_t vlanTCI)
{
   uint16_t vid = (vlanTCI & kVlanIDMask);

   struct vlan_ioctl_args if_request;
   memset(&if_request, 0, sizeof(if_request));
   sprintf(if_request.device1, "%s.%d", m_ifName.c_str(), vid);
   if_request.cmd = DEL_VLAN_CMD;

   cout << "Disable VLAN" <<  if_request.device1 << endl;
   int  error = vconfig(if_request);
   return error;
}

int main()
{
   m_sockfd = socket(AF_INET, SOCK_DGRAM, 0);

   uint16_t vlanTCI = 0x6002;
   enableVLAN(vlanTCI);
   disableVLAN(vlanTCI);

   close(m_sockfd);
}
