#ifndef DETAIL_XIEITE_HEADER_META_STATE
#	define DETAIL_XIEITE_HEADER_META_STATE
#
#	include <concepts>
#	include <cstddef>
#	include "../pp/diagnostic.hpp"

XIEITE_DIAGNOSTIC_PUSH()
XIEITE_DIAGNOSTIC_OFF_GCC("-Wnon-template-friend")
XIEITE_DIAGNOSTIC_OFF_GCC("-Wsfinae-incomplete")

namespace xieite {
	template<auto id = [] {}, std::integral Int = std::size_t>
	struct state {
	private:
		template<Int x>
		struct value {
			friend auto flag(xieite::state<id, Int>::value<x>);

			struct set {
				static constexpr Int value = x;

				friend auto flag(xieite::state<id, Int>::value<x>) {}
			};
		};

	public:
		template<auto tag = [] {}>
		static consteval Int get() noexcept {
			return ([]<Int x = 0>(this auto self) -> Int {
				if constexpr (requires { flag(xieite::state<id, Int>::value<x>()); }) {
					return self.template operator()<x + 1>();
				} else {
					return x;
				}
			})();
		}

		template<auto tag = [] {}>
		static consteval Int advance() noexcept {
			return xieite::state<id, Int>::value<xieite::state<id, Int>::get<tag>()>::set::value;
		}

		template<auto tag = [] {}>
		static consteval Int next() noexcept {
			return xieite::state<id, Int>::advance<tag>() + 1;
		}
	};
}

XIEITE_DIAGNOSTIC_POP()

#endif

// https://mc-deltat.github.io/articles/stateful-metaprogramming-cpp20
