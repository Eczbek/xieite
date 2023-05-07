#pragma once

namespace xieite::system {
	[[noreturn]]
	inline void segmentationFault() noexcept {
		*static_cast<volatile int*>(nullptr);
	}
}

// Thanks to eightfold for idea
