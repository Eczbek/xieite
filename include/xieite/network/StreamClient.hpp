#ifndef XIEITE_HEADER_NETWORK_STREAMCLIENT
#	define XIEITE_HEADER_NETWORK_STREAMCLIENT

#	warning "'xieite::network::StreamClient' is incomplete"

#	include <xieite/macros/SYSTEM_TYPE.hpp>

#	ifdef XIEITE_SYSTEM_TYPE_LINUX
#		include <functional>
#		include <stdexcept>
#		include <string>
#		include <sys/socket.h>
#		include <unistd.h>
#		include <xieite/network/Address.hpp>
#		include <xieite/network/Flag.hpp>
#		include <xieite/network/Stream.hpp>
#		include <xieite/system/bufferSize.hpp>

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

		void send(const std::string& message) {
			if (::send(this->id, message.c_str(), message.size(), 0) < 0) {
				throw std::runtime_error("Cannot send message");
			}
		}

		void receiving(const std::function<void(const std::string&)>& callback) {
			std::string message;
			ssize_t status;
			while (true) {
				std::string buffer = std::string(xieite::system::bufferSize, '\0');
				status = ::recv(this->id, buffer.data(), buffer.size(), static_cast<int>(xieite::network::Flag::DoNotWait) * !!message.size());
				if (status < 1) {
					break;
				}
				message += buffer;
			}
			callback(message);
		}
	};
}

#	else
#		error "System not supported"
#	endif

#endif
