#ifndef DETAIL_XIEITE_HEADER_SYS_THREAD_ID
#	define DETAIL_XIEITE_HEADER_SYS_THREAD_ID
#
#	include <atomic>
#	include <cstddef>

namespace DETAIL_XIEITE::thread_id {
	inline std::atomic<std::size_t> state = 0;
}

namespace xieite {
	thread_local const std::size_t thread_id = DETAIL_XIEITE::thread_id::state++;
}

#endif
