#pragma once

#include "../macros/platform.hpp"

#if !XIEITE_PLATFORM_UNIX
#	error "System not supported"
#endif

#include <cstdint>
#include <netinet/in.h>
#include <string>
#include "../network/address.hpp"

namespace xieite::network {
	struct SocketAddress
	: xieite::network::Address {
		SocketAddress(const std::string& host = "::", const std::uint16_t port = 0)
		: xieite::network::Address(host) {
			this->address.sin6_port = htons(port);
		}
	};
}
