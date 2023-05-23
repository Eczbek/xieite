#ifndef XIEITE_HEADER_SYSTEM_SEGMENTATIONFAULT
#	define XIEITE_HEADER_SYSTEM_SEGMENTATIONFAULT

namespace xieite::system {
	[[noreturn]]
	inline void segmentationFault() noexcept {
		*static_cast<volatile int*>(nullptr);
	}
}

// Thanks to eightfold for original idea

#endif
