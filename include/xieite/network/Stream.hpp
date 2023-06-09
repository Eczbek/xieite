#ifndef XIEITE_HEADER_NETWORK_STREAM
#	define XIEITE_HEADER_NETWORK_STREAM

#	warning "'xieite::network::Stream' is incomplete"

#	include <xieite/macros/SYSTEM_TYPE.hpp>

#	ifdef XIEITE_SYSTEM_TYPE_LINUX
#		include <concepts>
#		include <cstddef>
#		include <stdexcept>
#		include <string>
#		include <sys/socket.h>
#		include <xieite/concepts/Functable.hpp>
#		include <xieite/network/Address.hpp>
#		include <xieite/network/Domain.hpp>
#		include <xieite/network/Flag.hpp>
#		include <xieite/network/Socket.hpp>
#		include <xieite/network/Type.hpp>
#		include <xieite/system/bufferSize.hpp>

namespace xieite::network {
	struct Stream
	: xieite::network::Socket {
		Stream()
		: xieite::network::Socket(xieite::network::Domain::IPv6, xieite::network::Type::Stream, xieite::network::Protocol::TCP) {}

		Stream(const int id) noexcept
		: xieite::network::Socket(id) {}
	};
}

#	else
#		error "System not supported"
#	endif

#endif
