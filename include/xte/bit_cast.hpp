#ifndef DETAIL_XTE_HEADER_BIT_CAST
#	define DETAIL_XTE_HEADER_BIT_CAST
#
#	include "./aliases.hpp"
#	include "./compare.hpp"
#	include "./fixed_array.hpp"
#	include "./func/unfold.hpp"
#	include "./math/clamp.hpp"
#	include <bit>

namespace xte {
	template<typename target_type>
	constexpr auto bit_cast = [][[nodiscard]](auto const& x) noexcept -> target_type {
		return xte::unfold<xte::min(sizeof(target_type), sizeof(x))>([&]<xte::uz... i> {
			auto bytes = std::bit_cast<xte::fixed_array<unsigned char, sizeof(x)>>(x);
			return std::bit_cast<target_type>(xte::fixed_array<unsigned char, sizeof(target_type)> { bytes[i]... });
		});
	};
}

#endif
