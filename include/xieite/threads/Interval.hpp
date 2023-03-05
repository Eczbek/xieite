#pragma once
#include <atomic> // std::atomic
#include <concepts> // std::invocable
#include <memory> // std::make_shared, std::shared_ptr
#include <thread> // std::this_thread::sleep_for, std::thread
#include <utility> // std::forward
#include <xieite/concepts/TemporalDuration.hpp>

namespace xieite::threads {
	class Interval {
	private:
		std::shared_ptr<std::atomic<bool>> cancelled;
		std::thread thread;

	public:
		template<std::invocable<> C, xieite::concepts::TemporalDuration D>
		Interval(C&& callback, const D duration) noexcept
		: cancelled(std::make_shared<std::atomic<bool>>(false)), thread([cancelled = cancelled, callback = std::forward<C>(callback), duration]() -> void {
			while (true) {
				std::this_thread::sleep_for(duration);
				if (*cancelled)
					break;
				callback();
			}
		}) {}

		~Interval() {
			if (thread.joinable())
				cancel();
		}

		operator bool() const noexcept {
			return !*cancelled;
		}

		void cancel() noexcept {
			*cancelled = true;
			thread.detach();
		}
	};
}
