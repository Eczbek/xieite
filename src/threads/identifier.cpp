export module xieite:threads.identifier;

import std;

std::atomic<std::size_t> next = 0;

export namespace xieite::threads {
	thread_local const std::size_t identifier = next++;
}
