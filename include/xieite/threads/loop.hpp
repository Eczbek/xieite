#ifndef XIEITE_HEADER_THREADS_LOOP
#	define XIEITE_HEADER_THREADS_LOOP

#	include <concepts>
#	include <functional>
#	include <stop_token>
#	include <thread>

namespace xieite::threads {
	class Loop {
	public:
		template<std::invocable<> Functor>
		Loop(const Functor& callback) noexcept
		: thread([&callback](const std::stop_token stopToken) {
			while (!stopToken.stop_requested()) {
				std::invoke(callback);
			}
		}) {}

		~Loop() {
			if (this->good()) {
				this->stop();
			}
		}

		[[nodiscard]] bool good() const noexcept {
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

// Thanks to uno20001 for help
