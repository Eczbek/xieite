export module xieite:thread_id;

import std;

namespace {
	std::atomic<std::size_t> thread_id_state = 0;
}

export namespace xieite {
	thread_local const std::size_t thread_id = thread_id_state++;
}
