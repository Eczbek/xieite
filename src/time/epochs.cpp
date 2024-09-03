export module xieite:time.Epochs;

import std;

export namespace xieite::time {
	using Epochs = std::chrono::duration<std::intmax_t, std::ratio<31556952000000>>;
}
