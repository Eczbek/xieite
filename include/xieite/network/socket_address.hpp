#ifndef XIEITE_HEADER__NETWORK__SOCKET_ADDRESS
#	define XIEITE_HEADER__NETWORK__SOCKET_ADDRESS

#	include "../macros/system_type.hpp"

#	if !XIEITE__SYSTEM_TYPE__UNIX
#		error "System not supported"
#	endif

#	include <cstdint>
#	include <netinet/in.h>
#	include <string>
#	include "../network/address.hpp"

namespace xieite::network {
	struct SocketAddress
	: xieite::network::Address {
		SocketAddress(const std::string& host = "::", const std::uint16_t port = 0)
		: xieite::network::Address(host) {
			this->address.sin6_port = htons(port);
		}
	};
}

#endif
