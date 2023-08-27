#ifndef XIEITE_HEADER__NETWORK__ADDRESS
#	define XIEITE_HEADER__NETWORK__ADDRESS

#	include "../macros/SYSTEM_TYPE.hpp"

#	if !XIEITE__SYSTEM_TYPE__UNIX
#		error "System not supported"
#	endif

#	include <arpa/inet.h>
#	include <netinet/in.h>
#	include <stdexcept>
#	include <string>
#	include "../network/Domain.hpp"

namespace xieite::network {
	class Address {
	public:
		Address(const std::string& host = "::") {
			this->address.sin6_family = static_cast<int>(xieite::network::Domain::IPv6);
			if (::inet_pton(static_cast<int>(xieite::network::Domain::IPv6), host.c_str(), &this->address.sin6_addr) < 1) {
				throw std::runtime_error("Cannot create address with invalid host");
			}
			this->addressSize = sizeof(this->address);
		}

		::sockaddr* data() noexcept {
			return reinterpret_cast<::sockaddr*>(&this->address);
		}

		const ::sockaddr* data() const noexcept {
			return reinterpret_cast<const ::sockaddr*>(&this->address);
		}

		::socklen_t* size() noexcept {
			return &this->addressSize;
		}

		const ::socklen_t size() const noexcept {
			return this->addressSize;
		}

	protected:
		::sockaddr_in6 address;

	private:
		::socklen_t addressSize;
	};
}

#endif
