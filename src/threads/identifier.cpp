export module xieite:threads.identifier;

import std;

namespace {
	std::atomic<std::size_t> nextThreadIdentifier = 0;
}

export namespace xieite::threads {
	thread_local const std::size_t identifier = nextThreadIdentifier++;
}
