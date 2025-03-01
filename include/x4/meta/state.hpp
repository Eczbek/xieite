#pragma once

#include <concepts>
#include <cstddef>
#include "../meta/v.hpp"
#include "../pp/diag.hpp"

X4DIAGPUSH()
X4DIAGOFF_GCC("-Wnon-template-friend")

namespace x4 {
	template<auto id = [] {}, std::integral T = std::size_t>
	struct state {
	private:
		template<T n>
		struct v {
			friend auto flag(x4::state<id, T>::v<n>);

			struct set : x4::v<n> {
				friend auto flag(x4::state<id, T>::v<n>) {}
			};
		};

	public:
		template<auto = [] {}>
		static consteval T get() noexcept {
			return ([]<T n = 0>(this auto self) -> T {
				if constexpr (requires { flag(x4::state<id, T>::v<n>()); }) {
					return self.template operator()<n + 1>();
				} else {
					return n;
				}
			})();
		}

		template<auto tag = [] {}>
		static consteval T adv() noexcept {
			return x4::state<id, T>::v<x4::state<id, T>::get<tag>()>::set::v;
		}

		template<auto tag = [] {}>
		static consteval T next() noexcept {
			return x4::state<id, T>::adv<tag>() + 1;
		}
	};
}

X4DIAGPOP()
