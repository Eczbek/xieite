export module xieite:thread_loop;

import std;

export namespace xieite {
	struct thread_loop {
	public:
		template<std::invocable<> F>
		[[nodiscard]] thread_loop(F&& fn) noexcept
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

// Thanks to uno20001 (https://github.com/uno20001) for help
