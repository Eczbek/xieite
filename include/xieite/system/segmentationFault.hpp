#ifndef XIEITE_HEADER_SYSTEM_SEGMENTATIONFAULT
#	define XIEITE_HEADER_SYSTEM_SEGMENTATIONFAULT

namespace xieite::system {
	inline void segmentationFault() noexcept {
		*static_cast<volatile const int*>(nullptr);
	}
}

// Thanks to eightfold for original idea

#endif
