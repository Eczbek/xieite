#ifndef XIEITE_HEADER_NETWORK_DOMAIN
#	define XIEITE_HEADER_NETWORK_DOMAIN

#	include "../macros/platform.hpp"

#	if !XIEITE_PLATFORM_TYPE_UNIX
#		error "Platform not supported"
#	endif

#	include <sys/socket.h>

namespace xieite::network {
	enum struct Domain
	: int {
		AppleTalk = AF_APPLETALK,
		AX_25 = AF_AX25,
		Bluetooth = AF_BLUETOOTH,
		CAN = AF_CAN,
		ALG = AF_ALG,
		DECnet = AF_DECnet,
		IB = AF_IB,
		IPv4 = AF_INET,
		IPv6 = AF_INET6,
		KCM = AF_KCM,
		Key = AF_KEY,
		LLC = AF_LLC,
		Local = AF_UNIX,
		MPLS = AF_MPLS,
		Netlink = AF_NETLINK,
		IPX = AF_IPX,
		Packet = AF_PACKET,
		PPPoX = AF_PPPOX,
		RDS = AF_RDS,
		TIPC = AF_TIPC,
		VSockets = AF_VSOCK,
		X_25 = AF_X25,
		XDP = AF_XDP
	};
}

#endif
