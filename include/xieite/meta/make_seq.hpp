#ifndef DETAIL_XIEITE_HEADER_META_MAKE_SEQ
#	define DETAIL_XIEITE_HEADER_META_MAKE_SEQ
#
#	include <utility>
#	include "../meta/seq.hpp"

namespace xieite {
	template<auto count>
	constexpr auto make_seq = ([]<typename Int, Int... i>(std::integer_sequence<Int, i...>) {
		return xieite::seq<i...>();
	})(std::make_integer_sequence<decltype(count), count>());
}

#endif
