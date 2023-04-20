#pragma once

#include <concepts>
#include <stop_token>
#include <thread>
#include <utility>

namespace xieite::threads {
	class Loop {
	private:
		std::jthread thread;

	public:
		template<std::invocable<> Invocable>
		Loop(Invocable&& callback) noexcept
		: thread([callback = std::forward<Invocable>(callback)](const std::stop_token stopToken) -> void {
			do
				callback();
			while (!stopToken.stop_requested());
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
	};
}

// Thanks to uno20001 for help
