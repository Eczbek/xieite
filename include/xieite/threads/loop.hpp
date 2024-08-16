#ifndef XIEITE_HEADER_THREADS_LOOP
#	define XIEITE_HEADER_THREADS_LOOP

#	include <concepts>
#	include <functional>
#	include <stop_token>
#	include <thread>

namespace xieite::threads {
	struct Loop {
	public:
		template<std::invocable<> Functor>
		explicit Loop(Functor&& callback) noexcept
		: thread([&callback](const std::stop_token stopToken) -> void {
			while (!stopToken.stop_requested()) {
				std::invoke(callback);
			}
		}) {}

		~Loop() {
			if (*this) {
				this->stop();
			}
		}

		[[nodiscard]] explicit operator bool() const noexcept {
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
