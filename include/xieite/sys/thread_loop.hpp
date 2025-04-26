#ifndef DETAIL_XIEITE_HEADER_SYS_THREAD_LOOP
#	define DETAIL_XIEITE_HEADER_SYS_THREAD_LOOP
#
#	include <concepts>
#	include <functional>
#	include <stop_token>
#	include <thread>

namespace xieite {
	struct thread_loop {
	public:
		template<std::invocable<> Fn>
		[[nodiscard]] thread_loop(Fn&& fn) noexcept
		: thread([&fn](std::stop_token token) -> void {
			while (!token.stop_requested()) {
				std::invoke(fn);
			}
		}) {}

		~thread_loop() {
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
