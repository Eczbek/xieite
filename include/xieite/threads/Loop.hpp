#pragma once

#include <atomic>
#include <concepts>
#include <memory>
#include <thread>
#include <utility>

// Thanks to uno20001 for help

namespace xieite::threads {
	class Loop {
	private:
		std::shared_ptr<std::atomic<bool>> cancelled;
		std::thread thread;

	public:
		template<std::invocable<> Invocable>
		Loop(Invocable&& callback) noexcept
		: cancelled(std::make_shared<std::atomic<bool>>(false)), thread([this, callback = std::forward<Invocable>(callback)]() -> void {
			do
				callback();
			while (*this);
		}) {}

		~Loop() {
			cancel();
		}

		operator bool() const noexcept {
			return !*this->cancelled;
		}

		void cancel() noexcept {
			*this->cancelled = true;
			if (this->thread.joinable())
				this->thread.detach();
		}
	};
}
