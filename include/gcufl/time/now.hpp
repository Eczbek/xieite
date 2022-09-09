#pragma once

#include <chrono>
#include <gcufl/concepts/Duration.hpp>


namespace gcufl::time {
	template <gcufl::concepts::Duration D = std::chrono::nanoseconds>
	D::rep now() noexcept {
		return std::chrono::duration_cast<D>(std::chrono::high_resolution_clock::now().time_since_epoch()).count();
	}
}
