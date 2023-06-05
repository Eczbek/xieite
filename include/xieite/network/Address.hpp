#ifndef XIEITE_HEADER_NETWORK_ADDRESS
#	define XIEITE_HEADER_NETWORK_ADDRESS

#	include <xieite/macros/SYSTEM_TYPE.hpp>

#	ifdef XIEITE_SYSTEM_TYPE_LINUX
#		include <arpa/inet.h>
#		include <cstdint>
#		include <netinet/in.h>
#		include <stdexcept>
#		include <string>
#		include <xieite/network/Domain.hpp>

namespace xieite::network {
	class Address {
	public:
		Address() noexcept
		: addressSize(sizeof(this->address)) {}

		Address(const std::string& host, const std::uint16_t port) {
			this->address.sin6_family = static_cast<int>(xieite::network::Domain::IPv6);
			if (inet_pton(static_cast<int>(xieite::network::Domain::IPv6), host.c_str(), &this->address.sin6_addr) < 1) {
				throw std::runtime_error("Cannot create address with invalid host");
			}
			if (port < 1024) {
				throw std::runtime_error("Cannot create address with reserved port");
			}
			this->address.sin6_port = htons(port);
			this->addressSize = sizeof(this->address);
		}

		sockaddr* data() noexcept {
			return reinterpret_cast<sockaddr*>(&this->address);
		}

		const sockaddr* data() const noexcept {
			return reinterpret_cast<const sockaddr*>(&this->address);
		}

		socklen_t* size() noexcept {
			return &this->addressSize;
		}

		const socklen_t size() const noexcept {
			return this->addressSize;
		}

	private:
		sockaddr_in6 address;
		socklen_t addressSize;
	};
}

#	else
#		error "System not supported"
#	endif

#endif
