#ifndef DETAIL_XIEITE_HEADER_MATH_BYTE_FILL
#	define DETAIL_XIEITE_HEADER_MATH_BYTE_FILL
#
#	include <bit>
#	include <concepts>
#	include <cstddef>
#	include "../fn/unroll.hpp"
#	include "../pp/attr.hpp"

namespace xieite {
	struct byte_fill {
		char value;

		[[nodiscard]] explicit constexpr byte_fill(std::integral auto byte) noexcept
		: value(static_cast<char>(byte)) {}

		template<typename T>
		[[nodiscard]] explicit(false) constexpr operator T() const noexcept {
			struct XIEITE_ATTR_PACK(Array {
				char data[sizeof(T)];
			});
			return xieite::unroll<sizeof(T)>([this]<std::size_t... i> -> T {
				return std::bit_cast<T>(Array {{ (i, this->value)... }});
			});
		}
	};
}

#endif
