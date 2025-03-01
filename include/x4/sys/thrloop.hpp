#pragma once

#include <concepts>
#include <functional>
#include <stop_token>
#include <thread>

namespace x4 {
	struct thrloop {
	public:
		template<std::invocable<> F>
		[[nodiscard]] thrloop(F&& fn) noexcept
		: thread([&fn](std::stop_token token) -> void {
			while (!token.stop_requested()) {
				std::invoke(fn);
			}
		}) {}

		~thrloop() {
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
