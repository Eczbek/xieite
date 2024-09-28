module;

#include <xieite/sequence.hpp>

export module xieite:bits.Fill;

import std;

export namespace xieite::bits {
	struct Fill {
		std::byte value;

		template<std::integral Integral>
		explicit constexpr Fill(const Integral value) noexcept
		: value(static_cast<std::byte>(value)) {}

		template<typename Type>
		[[nodiscard]] constexpr operator Type() const noexcept {
			return XIEITE_SEQUENCE(i, sizeof(Type), {
				return std::bit_cast<Type>(std::array<std::byte, sizeof(Type)> {
					(void(i), this->value)...
				});
			});
		}
	};
}
