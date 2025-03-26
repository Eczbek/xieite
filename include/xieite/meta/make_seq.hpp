#ifndef DETAIL_XIEITE_HEADER_META_MAKE_SEQ
#	define DETAIL_XIEITE_HEADER_META_MAKE_SEQ
#
#	include <utility>
#	include "../meta/seq.hpp"

namespace xieite {
	template<auto n>
	constexpr decltype(([]<typename T, T... i>(std::integer_sequence<T, i...>) static {
		return xieite::seq<i...>();
	})(std::make_integer_sequence<decltype(n), n>())) make_seq;
}

#endif
