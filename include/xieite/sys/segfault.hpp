#pragma once

namespace xieite {
	inline void segfault() noexcept {
		*static_cast<volatile int*>(nullptr);
	}
}
