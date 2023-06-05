#ifndef XIEITE_HEADER_NETWORK_STREAMCLIENT
#	define XIEITE_HEADER_NETWORK_STREAMCLIENT

#	include <xieite/macros/SYSTEM_TYPE.hpp>

#	ifdef XIEITE_SYSTEM_TYPE_LINUX
#		include <stdexcept>
#		include <sys/socket.h>
#		include <xieite/network/Address.hpp>
#		include <xieite/network/Stream.hpp>

namespace xieite::network {
	struct StreamClient
	: xieite::network::Stream {
		static xieite::network::StreamClient accept(const xieite::network::Stream& stream) {
			xieite::network::Address address;
			xieite::network::StreamClient client = xieite::network::StreamClient(::accept(stream.id, address.data(), address.size()));
			if (client.id < 0) {
				throw std::runtime_error("Cannot accept client socket");
			}
			return client;
		}

		StreamClient()
		: xieite::network::Stream() {}

		StreamClient(const int id) noexcept
		: xieite::network::Stream(id) {}

		void bind(const xieite::network::Address&) = delete;

		void connect(const xieite::network::Address& serverAddress) {
			if (::connect(this->id, serverAddress.data(), serverAddress.size()) < 0) {
				throw std::runtime_error("Cannot connect to server socket");
			}
		}
	};
}

#	else
#		error "System not supported"
#	endif

#endif
