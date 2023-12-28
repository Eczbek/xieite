#ifndef XIEITE_HEADER_NETWORK_DOMAIN
#	define XIEITE_HEADER_NETWORK_DOMAIN

#	include "../macros/platform.hpp"

#	if !XIEITE_PLATFORM_UNIX
#		error "Platform not supported"
#	endif

#	include <sys/socket.h>

namespace xieite::network {
	enum struct Domain
	: int {
		AmateurRadioAX25 = AF_AX25,
		AppleTalk = AF_APPLETALK,
		Bluetooth = AF_BLUETOOTH,
		ClusterDomainSockets = AF_TIPC,
		ControllerAreaNetwork = AF_CAN,
		CryptoNetlink = AF_ALG,
		DECnet = AF_DECnet,
		ExpressDataPath = AF_XDP,
		IPv4 = AF_INET,
		IPv6 = AF_INET6,
		InfiniBand = AF_IB,
		KernelConnectionMultiplexer = AF_KCM,
		Key = AF_KEY,
		Local = AF_UNIX,
		LogicalLinkControl = AF_LLC,
		MultiprotocolLabelSwitching = AF_MPLS,
		Netlink = AF_NETLINK,
		NovellIPX = AF_IPX,
		PPPOX = AF_PPPOX,
		Packet = AF_PACKET,
		ReliableDatagramSockets = AF_RDS,
		VMWareVSockets = AF_VSOCK,
		X25 = AF_X25
	};
}

#endif
