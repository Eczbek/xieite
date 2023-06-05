#ifndef XIEITE_HEADER_NETWORK_TYPE
#	define XIEITE_HEADER_NETWORK_TYPE

#	include <xieite/macros/SYSTEM_TYPE.hpp>

#	ifdef XIEITE_SYSTEM_TYPE_LINUX
#		include <sys/socket.h>

namespace xieite::network {
	enum struct Type
	: int {
		Stream = SOCK_STREAM,
		Datagram = SOCK_DGRAM,
		SequencedPacket = SOCK_SEQPACKET,
		Raw = SOCK_RAW,
		ReliableDatagram = SOCK_RDM,
		Packet = SOCK_PACKET
	};
}

#	else
#		error "System not supported"
#	endif

#endif
