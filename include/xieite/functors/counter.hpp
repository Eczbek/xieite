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
}

namespace xieite::functors {
	template<auto tag = [] {}>
	[[nodiscard]] constexpr std::size_t counter() noexcept {
		return ([]<std::size_t current = 0, typename Self>(this const Self& self) -> std::size_t {
			if constexpr (requires(xieite::detail::CounterReader<current> reader) {
				XIEITE_DETAIL_COUNTER_FLAG<void>(reader);
			}) {
				return self.template operator()<current + 1>();
			} else {
				return xieite::detail::CounterSetter<current>::value;
			}
		})();
	}
}

#endif

// Thanks to Reese Jones (https://github.com/MC-DeltaT) for original code

// This is technically not IFNDR but causes wonky behavior if used in template constraints
