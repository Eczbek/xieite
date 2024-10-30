module;

#include <xieite/diag.hpp>

export module xieite:state;

import std;
import :value_identity;

XIEITE_DIAG_PUSH()
XIEITE_DIAG_OFF_GCC(-Wnon-template-friend)

export namespace xieite {
	template<auto id = [] {}, std::integral T = std::size_t>
	struct state {
	private:
		template<T n>
		struct value {
			friend auto flag(xieite::state<id, T>::value<n>);

			struct set : xieite::value_identity<n> {
				friend auto flag(xieite::state<id, T>::value<n>) {}
			};
		};

	public:
		template<auto = [] {}>
		static consteval T get() noexcept {
			return ([]<T n = 0>(this auto self) {
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

// https://mc-deltat.github.io/articles/stateful-metaprogramming-cpp20
// `flag` is a template to avoid GCC warnings
