#pragma once

#include <atomic>
#include <cstddef>

namespace XIEITE_DETAIL::thread_id {
	std::atomic<std::size_t> state = 0;
}

namespace xieite {
	thread_local const std::size_t thread_id = XIEITE_DETAIL::thread_id::state++;
}
