#ifndef XIEITE_HEADER_NETWORK_STREAMSERVER
#	define XIEITE_HEADER_NETWORK_STREAMSERVER

#	include <xieite/macros/SYSTEM_TYPE.hpp>

#	ifdef XIEITE_SYSTEM_TYPE_LINUX
#		include <functional>
#		include <stdexcept>
#		include <sys/socket.h>
#		include <xieite/network/Address.hpp>
#		include <xieite/network/Stream.hpp>
#		include <xieite/network/StreamClient.hpp>

namespace xieite::network {
	class StreamServer
	: public xieite::network::Stream {
	public:
		StreamServer()
		: xieite::network::Stream() {}

		StreamServer(const int id) noexcept
		: xieite::network::Stream(id) {}

		void listen(const int maximumQueue) {
			if (::listen(this->id, maximumQueue) < 0) {
				throw std::runtime_error("Cannot listen to connections");
			}
		}

		void accepting(const std::function<void(xieite::network::StreamClient&)>& callback) {
			xieite::network::StreamClient client = xieite::network::StreamClient::accept(*this);
			++this->connectedClients;
			client.closing([this]() noexcept -> void {
				--this->connectedClients;
			});
			callback(client);
		}

	private:
		int connectedClients;
	};
}

#	else
#		error "System not supported"
#	endif

#endif
