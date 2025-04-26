#ifndef DETAIL_XIEITE_HEADER_SYS_SEGFAULT
#	define DETAIL_XIEITE_HEADER_SYS_SEGFAULT

namespace xieite {
	inline void segfault() noexcept {
		*static_cast<volatile int*>(nullptr);
	}
}

#endif
