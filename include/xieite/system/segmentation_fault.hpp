#pragma once

namespace xieite::system {
	inline void segmentationFault() noexcept {
		*static_cast<volatile const int*>(nullptr);
	}
}
