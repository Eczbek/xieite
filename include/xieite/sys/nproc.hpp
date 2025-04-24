#ifndef DETAIL_XIEITE_HEADER_SYS_NPROC
#	define DETAIL_XIEITE_HEADER_SYS_NPROC
#
#	include <cstddef>
#	include "../pp/platform.hpp"
#
#	if XIEITE_PLATFORM_TYPE_UNIX
#		include <unistd.h>
#	elif XIEITE_PLATFORM_TYPE_WINDOWS
#		include <windows.h>
#	else
#		warning unsupported platform
#	endif

namespace xieite {
	inline std::size_t nproc() noexcept {
#	if XIEITE_PLATFORM_TYPE_UNIX
		return static_cast<std::size_t>(::sysconf(_SC_NPROCESSORS_ONLN));
#	elif XIEITE_PLATFORM_TYPE_WINDOWS
		::SYSTEM_INFO info;
		::GetSystemInfo(&info);
		return static_cast<std::size_t>(info.dwNumberOfProcessors);
#	else
		return 0;
#	endif
	}
}

#endif
