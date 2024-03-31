#ifndef XIEITE_HEADER_FUNCTORS_COUNTER
#	define XIEITE_HEADER_FUNCTORS_COUNTER

#	include <cstddef>

namespace xieite::detail {
	template<auto tag, std::size_t current>
	struct CounterReader {
		template<typename>
		friend auto XIEITE_DETAIL_COUNTER_FLAG(xieite::detail::CounterReader<tag, current>) noexcept;
	};

	template<auto tag, std::size_t current>
	struct CounterWriter {
		template<typename>
		friend auto XIEITE_DETAIL_COUNTER_FLAG(xieite::detail::CounterReader<tag, current>) noexcept {}

		static constexpr std::size_t value = current;
	};

	template<auto tag, auto unique, std::size_t current = 0>
	[[nodiscard]] constexpr std::size_t advanceCounter() noexcept {
		if constexpr (requires(xieite::detail::CounterReader<tag, current> reader) {
			XIEITE_DETAIL_COUNTER_FLAG<void>(reader);
		}) {
			return xieite::detail::advanceCounter<tag, unique, current + 1>();
		} else {
			return xieite::detail::CounterWriter<tag, current>::value;
		}
	}

	inline constexpr auto defaultCounterTag = [] {};
}

namespace xieite::functors {
	template<auto tag = xieite::detail::defaultCounterTag, auto unique = [] {}>
	[[nodiscard]] constexpr std::size_t counter() noexcept {
		return xieite::detail::advanceCounter<tag, unique>();
	}
}

#endif

// https://mc-deltat.github.io/articles/stateful-metaprogramming-cpp20
