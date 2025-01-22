export module xieite:thread_id;

import std;

namespace detail::thread_id {
	std::atomic<std::size_t> state = 0;
}

export namespace xieite {
	thread_local const std::size_t thread_id = detail::thread_id::state++;
}
