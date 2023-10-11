#ifndef XIEITE_HEADER_SYSTEM_SEGMENTATION_FAULT
#	define XIEITE_HEADER_SYSTEM_SEGMENTATION_FAULT

namespace xieite::system {
	inline void segmentationFault() noexcept {
		*static_cast<volatile const int*>(nullptr);
	}
}

#endif
