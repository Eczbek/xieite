#ifndef DETAIL_XTE_HEADER_MATH_BIT_CAST
#	define DETAIL_XTE_HEADER_MATH_BIT_CAST
#
#	include "../data/fixed_array.hpp"
#	include "../func/unfold.hpp"
#	include "../math/min.hpp"
#	include "../util/types.hpp"
#	include <bit>

namespace xte {
	template<typename T>
	constexpr auto bit_cast = [][[nodiscard]](const auto& x) noexcept -> T {
		return xte::unfold<xte::min(sizeof(T), sizeof(x))>([&]<xte::uz... i> {
			auto bytes = std::bit_cast<xte::fixed_array<unsigned char, sizeof(x)>>(x);
			return std::bit_cast<T>(xte::fixed_array<unsigned char, sizeof(T)> { bytes[i]... });
		});
	};
}

#endif
