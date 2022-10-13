#pragma once
#include <chrono>
#include <gcufl/concepts/Duration.hpp>

namespace gcufl {
	class Timer {
	private:
		std::chrono::time_point<std::chrono::high_resolution_clock> start;

	public:
		Timer() noexcept;

		template<gcufl::concepts::Duration D = std::chrono::nanoseconds>
		D::rep get() noexcept {
			return std::chrono::duration_cast<D>(std::chrono::high_resolution_clock::now() - start).count();
		}
		
		void reset() noexcept;
	};
}
