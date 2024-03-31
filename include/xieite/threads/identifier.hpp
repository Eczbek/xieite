#ifndef XIEITE_HEADER_THREADS_IDENTIFIER
#	define XIEITE_HEADER_THREADS_IDENTIFIER

#	include <atomic>
#	include <cstdint>

namespace xieite::detail {
	inline std::atomic<std::size_t> nextThreadIdentifier = 0;
}

namespace xieite::threads {
	thread_local const std::size_t identifier = xieite::detail::nextThreadIdentifier++;
}

#endif
