#ifndef XIEITE_HEADER_NETWORK_STREAMSERVER
#	define XIEITE_HEADER_NETWORK_STREAMSERVER

#	warning "'xieite::network::StreamServer' is incomplete"

#	include <xieite/macros/SYSTEM_TYPE.hpp>

#	ifdef XIEITE_SYSTEM_TYPE_LINUX
#		include <condition_variable>
#		include <cstddef>
#		include <functional>
#		include <mutex>
#		include <stdexcept>
#		include <sys/socket.h>
#		include <thread>
#		include <vector>
#		include <xieite/network/Address.hpp>
#		include <xieite/network/Stream.hpp>
#		include <xieite/network/StreamClient.hpp>
#		include <xieite/threads/Loop.hpp>
#		include <xieite/threads/Pool.hpp>

namespace xieite::network {
	class StreamServer
	: public xieite::network::Stream {
	public:
		StreamServer(const std::size_t maximumClients)
		: xieite::network::Stream(), maximumClients(maximumClients), connectedClients(0), loop([this]() -> void {
			xieite::network::StreamClient client = xieite::network::StreamClient::accept(*this);
			auto serverLock = std::unique_lock<std::mutex>(this->serverMutex);
			this->serverCondition.wait(serverLock, [this]() noexcept -> bool {
				return this->connectedClients < this->maximumClients;
			});
			++this->connectedClients;
			client.closing([this]() noexcept -> void {
				--this->connectedClients;
				this->serverCondition.notify_one();
			});
			for (const std::function<void(xieite::network::StreamClient&)>& callback : this->callbacks) {
				this->pool.enqueue([clientPointer, &clientMutex, &callback]() -> void {
					const auto clientLock = std::lock_guard<std::mutex>(clientMutex);
					callback(*clientPointer);
				});
			}
		}) {}

		void listen(const std::size_t maximumQueue) {
			if (::listen(this->id, maximumQueue) < 0) {
				throw std::runtime_error("Cannot listen for connections");
			}
		}

		void accepting(const std::function<void(xieite::network::StreamClient&)>& callback) {
			this->callbacks.push_back(callback);
		}

	private:
		const std::size_t maximumClients;
		std::size_t connectedClients;
		std::mutex serverMutex;
		std::condition_variable serverCondition;
		xieite::threads::Loop loop;
		xieite::threads::Pool pool;
		std::vector<std::function<void(xieite::network::StreamClient&)>> callbacks;
	};
}

#	else
#		error "System not supported"
#	endif

#endif
