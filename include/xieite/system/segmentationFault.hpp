#ifndef XIEITE_HEADER__SYSTEM__SEGMENTATION_FAULT
#	define XIEITE_HEADER__SYSTEM__SEGMENTATION_FAULT

namespace xieite::system {
	inline void segmentationFault() noexcept {
		*static_cast<volatile const int*>(nullptr);
	}
}

// Thanks to eightfold for original idea

#endif
