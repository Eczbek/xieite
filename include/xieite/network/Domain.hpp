#ifndef XIEITE_HEADER_NETWORK_DOMAIN
#	define XIEITE_HEADER_NETWORK_DOMAIN

#	include <xieite/macros/SYSTEM_TYPE.hpp>

#	ifdef XIEITE_SYSTEM_TYPE_LINUX
#		include <sys/socket.h>

namespace xieite::network {
	enum struct Domain
	: int {
		Local = AF_UNIX,
		IPv4 = AF_INET,
		AmateurRadioAX25 = AF_AX25,
		NovellIPX = AF_IPX,
		AppleTalk = AF_APPLETALK,
		X25 = AF_X25,
		IPv6 = AF_INET6,
		DECnet = AF_DECnet,
		Key = AF_KEY,
		Netlink = AF_NETLINK,
		Packet = AF_PACKET,
		ReliableDatagramSockets = AF_RDS,
		PPPOX = AF_PPPOX,
		LogicalLinkControl = AF_LLC,
		InfiniBand = AF_IB,
		MultiprotocolLabelSwitching = AF_MPLS,
		ControllerAreaNetwork = AF_CAN,
		ClusterDomainSockets = AF_TIPC,
		Bluetooth = AF_BLUETOOTH,
		CryptoNetlink = AF_ALG,
		VMWareVSockets = AF_VSOCK,
		KernelConnectionMultiplexer = AF_KCM,
		ExpressDataPath = AF_XDP
	};
}

#	else
#		error "System not supported"
#	endif

#endif
