#ifndef XIEITE_HEADER_THREADS_LOOP
#	define XIEITE_HEADER_THREADS_LOOP

#	include <concepts>
#	include <stop_token>
#	include <thread>

namespace xieite::threads {
	class Loop final {
	public:
		Loop(const std::invocable auto& callback) noexcept
		: thread([&callback](const std::stop_token stopToken) -> void {
			while (!stopToken.stop_requested()) {
				callback();
			}
		}) {}

		~Loop() {
			this->stop();
		}

		bool good() const noexcept {
			return this->thread.joinable();
		}

		void stop() noexcept {
			if (this->good()) {
				this->thread.request_stop();
				this->thread.detach();
			}
		}

	private:
		std::jthread thread;
	};
}

// Thanks to uno20001 for help

#endif
