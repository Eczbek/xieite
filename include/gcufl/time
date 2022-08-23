#pragma once

#include <array>
#include <chrono>
#include <string_view>


namespace gcufl {
	namespace time {
		constexpr std::array<std::string_view, 12> months { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
		constexpr std::array<std::string_view, 7> weekDays { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };

		template <typename D = std::chrono::nanoseconds>
		long now() noexcept {
			return std::chrono::duration_cast<D>(std::chrono::high_resolution_clock::now().time_since_epoch()).count();
		}
	}
}
