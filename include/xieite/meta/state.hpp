#ifndef DETAIL_XIEITE_HEADER_META_STATE
#	define DETAIL_XIEITE_HEADER_META_STATE
#
#	include <concepts>
#	include <cstddef>
#	include "../pp/diag.hpp"

XIEITE_DIAG_PUSH()
XIEITE_DIAG_OFF_GCC("-Wnon-template-friend")

namespace xieite {
	template<auto id = [] {}, std::integral T = std::size_t>
	struct state {
	private:
		template<T n>
		struct value {
			friend auto flag(xieite::state<id, T>::value<n>);

			struct set {
				static constexpr T value = n;

				friend auto flag(xieite::state<id, T>::value<n>) {}
			};
		};

	public:
		template<auto tag = [] {}>
		static consteval T get() noexcept {
			return ([]<T n = 0>(this auto self) -> T {
				if constexpr (requires { flag(xieite::state<id, T>::value<n>()); }) {
					return self.template operator()<n + 1>();
				} else {
					return n;
				}
			})();
		}

		template<auto tag = [] {}>
		static consteval T advance() noexcept {
			return xieite::state<id, T>::value<xieite::state<id, T>::get<tag>()>::set::value;
		}

		template<auto tag = [] {}>
		static consteval T next() noexcept {
			return xieite::state<id, T>::advance<tag>() + 1;
		}
	};
}

XIEITE_DIAG_POP()

#endif

// https://mc-deltat.github.io/articles/stateful-metaprogramming-cpp20
