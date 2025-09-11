#ifndef DETAIL_XIEITE_HEADER_META_ENUM_SIZE
#	define DETAIL_XIEITE_HEADER_META_ENUM_SIZE
#
#	include <cstddef>
#	include <limits>
#	include <type_traits>
#	include <utility>
#	include "../math/bit_size.hpp"
#	include "../meta/fold_for.hpp"
#	include "../meta/value_id.hpp"
#	include "../pp/diagnostic.hpp"
#	include "../trait/is_enum.hpp"
#	include "../trait/is_enum_value.hpp"

XIEITE_DIAGNOSTIC_PUSH_GCC()
XIEITE_DIAGNOSTIC_OFF_GCC("-Wconversion")

namespace xieite {
	template<xieite::is_enum Enum>
	constexpr std::size_t enum_size = xieite::fold_for<
		[]<typename Pair, auto> {
			static constexpr std::size_t min = Pair::first_type::value;
			static constexpr std::size_t max = Pair::second_type::value;
			static constexpr std::size_t mid = min / 2 + max / 2;
			if constexpr (!xieite::is_enum_value<mid, Enum>) {
				return std::pair<xieite::value_id<min>, xieite::value_id<mid>>();
			} else {
				return std::pair<xieite::value_id<mid>, xieite::value_id<max>>();
			}
		},
		std::pair<xieite::value_id<0uz>, xieite::value_id<static_cast<std::size_t>(std::numeric_limits<std::underlying_type_t<Enum>>::max())>>,
		xieite::bit_size<std::size_t>
	>::second_type::value;
}

XIEITE_DIAGNOSTIC_POP_GCC()

#endif
