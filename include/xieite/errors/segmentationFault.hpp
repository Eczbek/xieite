#pragma once


// Thanks to eightfold for idea

namespace xieite::errors {
	[[noreturn]]
	inline void segmentationFault() noexcept {
		*(volatile int*)(nullptr);
	}
}
