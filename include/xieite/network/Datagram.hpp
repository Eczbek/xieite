#ifndef XIEITE_HEADER_NETWORK_DATAGRAM
#	define XIEITE_HEADER_NETWORK_DATAGRAM

#	warning "'xieite::network::Datagram' is incomplete"

#	include <xieite/macros/SYSTEM_TYPE.hpp>

#	ifdef XIEITE_SYSTEM_TYPE_LINUX
#		include <concepts>
#		include <stdexcept>
#		include <string>
#		include <sys/socket.h>
#		include <xieite/network/Address.hpp>
#		include <xieite/network/Domain.hpp>
#		include <xieite/network/Flag.hpp>
#		include <xieite/network/Socket.hpp>
#		include <xieite/network/Type.hpp>
#		include <xieite/system/bufferSize.hpp>

namespace xieite::network {
	struct Datagram
	: xieite::network::Socket {
		Datagram()
		: xieite::network::Socket(xieite::network::Domain::IPv6, xieite::network::Type::Datagram, xieite::network::Protocol::UDP) {}

		void send(xieite::network::Address clientAddress, const std::string& message) {
			if (::sendto(this->id, message.c_str(), message.size(), 0, clientAddress.data(), *clientAddress.size()) < 0) {
				throw std::runtime_error("Cannot send message");
			}
		}

		std::string receive(xieite::network::Address clientAddress) noexcept {
			std::string message;
			ssize_t status;
			while (true) {
				std::string buffer = std::string(xieite::system::bufferSize, '\0');
				status = ::recvfrom(this->id, buffer.data(), buffer.size(), xieite::network::Flag::DoNotWait * !!message.size(), clientAddress.data(), clientAddress.size());
				if (status < 1) {
					break;
				}
				message += buffer;
			}
			return message;
		}
	};
}

#	else
#		error "System not supported"
#	endif

#endif
