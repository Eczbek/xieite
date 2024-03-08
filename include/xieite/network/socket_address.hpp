#ifndef XIEITE_HEADER_NETWORK_SOCKET_ADDRESS
#	define XIEITE_HEADER_NETWORK_SOCKET_ADDRESS

#	include "../macros/platform.hpp"

#	if !XIEITE_PLATFORM_TYPE_UNIX
#		error "Platform not supported"
#	endif

#	include <cstdint>
#	include <netinet/in.h>
#	include <string>
#	include "../concepts/string.hpp"
#	include "../network/address.hpp"

namespace xieite::network {
	struct SocketAddress
	: xieite::network::Address {
		template<xieite::concepts::String String = std::string>
		SocketAddress(const String& host = "::", const std::uint16_t port = 0)
		: xieite::network::Address(host) {
			this->address.sin6_port = ::htons(port);
		}
	};
}

#endif
