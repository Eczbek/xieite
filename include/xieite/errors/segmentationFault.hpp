#pragma once

namespace xieite::errors {
	[[noreturn]]
	inline void segmentationFault() noexcept {
		*static_cast<volatile int*>(nullptr);
	}
}

// Thanks to eightfold for idea
