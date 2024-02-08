#ifndef XIEITE_HEADER_FUNCTORS_COUNTER
#	define XIEITE_HEADER_FUNCTORS_COUNTER

#	include <cstddef>

namespace xieite::detail {
	template<std::size_t current>
	struct CounterReader {
		template<typename>
		friend auto XIEITE_DETAIL_COUNTER_FLAG(xieite::detail::CounterReader<current>) noexcept;
	};


	template<std::size_t current>
	struct CounterSetter {
		template<typename>
		friend auto XIEITE_DETAIL_COUNTER_FLAG(xieite::detail::CounterReader<current>) noexcept {}

		static constexpr std::size_t value = current;
	};

	template<auto tag = [] {}, std::size_t next = 0>
	[[nodiscard]] constexpr std::size_t counterHelper() noexcept {
		if constexpr (requires(xieite::detail::CounterReader<next> reader) {
			XIEITE_DETAIL_COUNTER_FLAG<void>(reader);
		}) {
			return xieite::detail::counterHelper<tag, next + 1>();
		} else {
			return xieite::detail::CounterSetter<next>().value;
		}
	}
}

namespace xieite {
	template<auto tag = [] {}>
	[[nodiscard]] constexpr std::size_t counter() noexcept {
		return xieite::detail::counterHelper<tag>();
	}
}

#endif

// Thanks to Reese Jones (https://github.com/MC-DeltaT) for original code

// This is technically not IFNDR but causes wonky behavior in templates
