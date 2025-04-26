#ifndef DETAIL_XIEITE_HEADER_MATH_BYTE_FILL
#	define DETAIL_XIEITE_HEADER_MATH_BYTE_FILL
#
#	include <array>
#	include <bit>
#	include <cstddef>
#	include "../fn/unroll.hpp"

namespace xieite {
	struct byte_fill {
		char value;

		[[nodiscard]] explicit constexpr byte_fill(std::integral auto byte) noexcept
		: value(static_cast<char>(byte)) {}

		template<typename T>
		[[nodiscard]] explicit(false) constexpr operator T() const noexcept {
			return xieite::unroll<sizeof(T)>([this]<std::size_t... i> -> std::array<char, sizeof(T)> {
				return std::bit_cast<T>(std::array<char, sizeof(T)> { (i, this->value)... });
			});
		}
	};
}

#endif
