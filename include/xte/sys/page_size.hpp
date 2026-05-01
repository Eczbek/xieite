#ifndef DETAIL_XTE_HEADER_SYS_PAGE_SIZE
#	define DETAIL_XTE_HEADER_SYS_PAGE_SIZE
#
#	include "../preproc/platform.hpp"
#	include "../util/numbers.hpp"
#
#	if XTE_PLATFORM_UNIX
#		include <unistd.h>
#	elif XTE_PLATFORM_WINDOWS
#		include <windows.h>
#	else
#		warning unsupported platform
#	endif

namespace xte {
	[[nodiscard]] inline xte::uz page_size() noexcept {
#	if XTE_PLATFORM_UNIX
		return static_cast<xte::uz>(::getpagesize());
#	elif XTE_PLATFORM_WINDOWS
		::SYSTEM_INFO info;
		::GetSystemInfo(&info);
		return static_cast<xte::uz>(info.dwPageSize);
#	else
		return 0;
#	endif
	}
}

#endif
