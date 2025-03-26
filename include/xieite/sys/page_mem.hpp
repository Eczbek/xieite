#ifndef DETAIL_XIEITE_HEADER_SYS_PAGE_MEM
#	define DETAIL_XIEITE_HEADER_SYS_PAGE_MEM
#
#	include <cstddef>
#	include <memory>
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
	[[nodiscard]] inline std::size_t mem_page() noexcept {
#	if XIEITE_PLATFORM_TYPE_UNIX
		return static_cast<std::size_t>(::sysconf(_SC_PAGE_SIZE));
#	elif XIEITE_PLATFORM_TYPE_WINDOWS
		::SYSTEM_INFO info;
		::GetSystemInfo(std::addressof(info));
		return info.dwPageSize;
#	endif
	}
}

#endif
