#pragma once

namespace x4 {
	inline void segfault() noexcept {
		*static_cast<volatile int*>(nullptr);
	}
}
