#ifndef XIEITE_HEADER_NETWORK_SOCKET
#	define XIEITE_HEADER_NETWORK_SOCKET

#	include <xieite/macros/SYSTEM_TYPE.hpp>

#	ifdef XIEITE_SYSTEM_TYPE_LINUX
#		include <concepts>
#		include <functional>
#		include <stdexcept>
#		include <sys/socket.h>
#		include <unistd.h>
#		include <vector>
#		include <xieite/network/Address.hpp>
#		include <xieite/network/Domain.hpp>
#		include <xieite/network/Modifier.hpp>
#		include <xieite/network/Protocol.hpp>
#		include <xieite/network/Type.hpp>

namespace xieite::network {
	class Socket {
	public:
		const int id;

		Socket(const xieite::network::Domain domain, const xieite::network::Type type, const xieite::network::Protocol protocol, const std::same_as<xieite::network::Modifier> auto...)
		: open(true), id(::socket(static_cast<int>(domain), static_cast<int>(type), static_cast<int>(protocol))) {
			if (this->id < 0) {
				throw std::runtime_error("Cannot open socket");
			}
		}

		Socket(const int id) noexcept
		: open(true), id(id) {}

		~Socket() {
			if (this->open) {
				this->close();
			}
		}

		void bind(const xieite::network::Address& address) {
			if (::bind(this->id, address.data(), address.size()) < 0) {
				throw std::runtime_error("Cannot bind address to socket");
			}
		}

		void close() {
			this->open = false;
			for (const std::function<void()>& callback : this->callbacks) {
				callback();
			}
			if (::close(this->id) < 0) {
				throw std::runtime_error("Cannot close socket");
			}
		}

		void closing(const std::function<void()>& callback) {
			this->callbacks.push_back(callback);
		}

	private:
		bool open;
		std::vector<std::function<void()>> callbacks;
	};
}

#	else
#		error "System not supported"
#	endif

#endif
