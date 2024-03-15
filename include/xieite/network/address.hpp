#ifndef XIEITE_HEADER_NETWORK_ADDRESS
#	define XIEITE_HEADER_NETWORK_ADDRESS

#	include "../macros/platform.hpp"

#	if !XIEITE_PLATFORM_TYPE_UNIX
#		error "Platform not supported"
#	endif

#	include <arpa/inet.h>
#	include <netinet/in.h>
#	include <string>
#	include <type_traits>
#	include "../exceptions/invalid_network_address.hpp"
#	include "../network/domain.hpp"

namespace xieite::network {
	struct Address {
	public:
		Address(const std::string& host = "::") {
			this->address.sin6_family = static_cast<int>(xieite::network::Domain::IPv6);
			if (::inet_pton(static_cast<int>(xieite::network::Domain::IPv6), host.c_str(), &this->address.sin6_addr) < 1) {
				throw xieite::exceptions::InvalidNetworkAddress("Cannot create address with invalid host");
			}
			this->addressSize = sizeof(this->address);
		}

		template<typename Self>
		[[nodiscard]] std::conditional_t<std::is_const_v<Self>, const ::sockaddr*, ::sockaddr*> data(this Self& self) noexcept {
			return reinterpret_cast<std::conditional_t<std::is_const_v<Self>, const ::sockaddr*, ::sockaddr*>>(&self.address);
		}

		template<typename Self>
		[[nodiscard]] std::conditional_t<std::is_const_v<Self>, const ::socklen_t*, ::socklen_t*> size(this Self& self) noexcept {
			return &self.addressSize;
		}

	protected:
		::sockaddr_in6 address;

	private:
		::socklen_t addressSize;
	};
}

#endif
