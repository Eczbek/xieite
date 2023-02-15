#pragma once
#include <atomic> // std::atomic
#include <concepts> // std::invocable
#include <memory> // std::make_shared, std::shared_ptr
#include <thread> // std::this_thread::sleep_for, std::thread
#include <utility> // std::forward
#include <xieite/concepts/Duration.hpp>

namespace xieite::async {
	class Interval {
	private:
		std::shared_ptr<std::atomic<bool>> cancelled;
		std::thread thread;

	public:
		template<std::invocable<> C, xieite::concepts::Duration D>
		inline Interval(C&& callback, const D duration) noexcept
		: cancelled(std::make_shared<std::atomic<bool>>(false)), thread([this, callback = std::forward<C>(callback), duration]() -> void {
			while (true) {
				std::this_thread::sleep_for(duration);
				if (!this)
					break;
				callback();
			}
		}) {}

		inline ~Interval() {
			if (thread.joinable())
				cancel();
		}

		inline operator bool() const noexcept {
			return !*cancelled;
		}

		inline void cancel() noexcept {
			*cancelled = true;
			thread.detach();
		}
	};
}
