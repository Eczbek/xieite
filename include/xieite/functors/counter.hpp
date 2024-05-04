#ifndef XIEITE_HEADER_FUNCTORS_COUNTER
#	define XIEITE_HEADER_FUNCTORS_COUNTER

#	include <cstddef>

namespace xieite::detail {
	template<auto tag_, std::size_t current_>
	struct CounterReader {
		template<typename>
		friend auto XIEITE_DETAIL_COUNTER_FLAG(xieite::detail::CounterReader<tag_, current_>) noexcept;
	};

	template<auto tag_, std::size_t current_>
	struct CounterWriter {
		template<typename>
		friend auto XIEITE_DETAIL_COUNTER_FLAG(xieite::detail::CounterReader<tag_, current_>) noexcept {}

		static constexpr std::size_t value = current_;
	};

	template<auto tag_, auto unique_, std::size_t current_ = 0>
	[[nodiscard]] constexpr std::size_t advanceCounter() noexcept {
		if constexpr (requires(xieite::detail::CounterReader<tag_, current_> reader) {
			XIEITE_DETAIL_COUNTER_FLAG<void>(reader);
		}) {
			return xieite::detail::advanceCounter<tag_, unique_, current_ + 1>();
		} else {
			return xieite::detail::CounterWriter<tag_, current_>::value;
		}
	}

	inline constexpr auto defaultCounterTag = [] {};
}

namespace xieite::functors {
	template<auto tag_ = xieite::detail::defaultCounterTag, auto unique_ = [] {}>
	[[nodiscard]] constexpr std::size_t counter() noexcept {
		return xieite::detail::advanceCounter<tag_, unique_>();
	}
}

#endif

// https://mc-deltat.github.io/articles/stateful-metaprogramming-cpp20
// XIEITE_DETAIL_COUNTER_FLAG is a template to avoid warnings on GCC
