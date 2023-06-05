#ifndef XIEITE_HEADER_NETWORK_STREAM
#	define XIEITE_HEADER_NETWORK_STREAM

#	include <xieite/macros/SYSTEM_TYPE.hpp>

#	ifdef XIEITE_SYSTEM_TYPE_LINUX
#		include <concepts>
#		include <cstddef>
#		include <stdexcept>
#		include <string>
#		include <sys/socket.h>
#		include <xieite/concepts/Functable.hpp>
#		include <xieite/network/Address.hpp>
#		include <xieite/network/Domain.hpp>
#		include <xieite/network/Flag.hpp>
#		include <xieite/network/Socket.hpp>
#		include <xieite/network/Type.hpp>
#		include <xieite/system/bufferSize.hpp>

namespace xieite::network {
	struct Stream
	: xieite::network::Socket {
		Stream()
		: xieite::network::Socket(xieite::network::Domain::IPv6, xieite::network::Type::Stream, xieite::network::Protocol::TCP) {}

		Stream(const int id) noexcept
		: xieite::network::Socket(id) {}

		void send(const std::string& message) {
			if (::send(this->id, message.c_str(), message.size(), 0) != message.size()) {
				throw std::runtime_error("Cannot send message");
			}
		}

		void receiving(const xieite::concepts::Functable<void(const std::string&)> auto& callback) {
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
