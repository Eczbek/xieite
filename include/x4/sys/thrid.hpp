#pragma once

#include <atomic>
#include <cstddef>

namespace DETAIL_X4::thrid {
	inline std::atomic<std::size_t> state = 0;
}

namespace x4 {
	thread_local const std::size_t thrid = DETAIL_X4::thrid::state++;
}
