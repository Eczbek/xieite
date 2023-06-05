#ifndef XIEITE_HEADER_NETWORK_PROTOCOL
#	define XIEITE_HEADER_NETWORK_PROTOCOL

#	include <xieite/macros/SYSTEM_TYPE.hpp>

#	ifdef XIEITE_SYSTEM_TYPE_LINUX
#		include <sys/socket.h>

namespace xieite::network {
	enum struct Protocol
	: int {
		Default = 0,
		TCP = IPPROTO_TCP,
		UDP = IPPROTO_UDP,
		ICMP = IPPROTO_ICMP,
		Raw = IPPROTO_RAW,
		IPv4 = IPPROTO_IP,
		IPv6 = IPPROTO_IPV6,
		ICMPv6 = IPPROTO_ICMPV6
	};
}

#	else
#		error "System not supported"
#	endif

#endif
