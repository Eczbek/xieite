export module xieite:functors.counter;

import std;

template<auto tag, std::size_t current>
struct CounterReader {
	template<typename>
	friend auto counterFlag(CounterReader<tag, current>) noexcept;
};

template<auto tag, std::size_t current>
struct CounterWriter {
	template<typename>
	friend auto counterFlag(CounterReader<tag, current>) noexcept {}

	static constexpr std::size_t value = current;
};

template<auto tag, auto unique, std::size_t current = 0>
[[nodiscard]] constexpr std::size_t counterAdvance() noexcept {
	if constexpr (requires(CounterReader<tag, current> reader) { counterFlag<void>(reader); }) { return counterAdvance<tag, unique, current + 1>(); } else {
		return CounterWriter<tag, current>::value;
	}
}

constexpr auto defaultCounterTag = [] {};

export namespace xieite::functors {
	template<auto tag = defaultCounterTag, auto unique = [] {}>
	[[nodiscard]] constexpr std::size_t counter() noexcept {
		return counterAdvance<tag, unique>();
	}
}

// https://mc-deltat.github.io/articles/stateful-metaprogramming-cpp20
// `counterFlag` is a template to avoid warnings when compiled with GCC
// `counterAdvance` is a separate function (rather than a lambda inside `counter`) likely because of Clang warnings/errors
