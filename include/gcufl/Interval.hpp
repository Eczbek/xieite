#include <thread>
#include <concepts>
#include <atomic>
#include <gcufl/traits.hpp>

namespace gcufl {
	class Interval {
	private:
		std::atomic<bool> running = true;
		std::thread loop;

	public:
		template <std::invocable C, gcufl::traits::Duration D>
		Interval(const C& callback, const D timeout) noexcept
		: loop([this, &callback, timeout]() {
			while (running) {
				callback();
				std::this_thread::sleep_for(timeout);
			}
		}) {}

		~Interval();
	};
}
