#ifndef XIEITE_HEADER_THREADS_LOOP
#	define XIEITE_HEADER_THREADS_LOOP

#	include <concepts>
#	include <stop_token>
#	include <thread>
#	include "../functors/function.hpp"

namespace xieite::threads {
	class Loop {
	public:
		Loop(const xieite::functors::Function<void()>& callback) noexcept
		: thread([&callback](const std::stop_token stopToken) -> void {
			while (!stopToken.stop_requested()) {
				callback();
			}
		}) {}

		~Loop() {
			if (*this) {
				this->stop();
			}
		}

		[[nodiscard]] operator bool() const noexcept {
			return this->thread.joinable();
		}

		void stop() noexcept {
			this->thread.request_stop();
			this->thread.detach();
		}

	private:
		std::jthread thread;
	};
}

#endif

// Thanks to uno20001 (https://github.com/uno20001) for help
