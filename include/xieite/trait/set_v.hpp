#ifndef DETAIL_XIEITE_HEADER_TRAIT_SET_V
#	define DETAIL_XIEITE_HEADER_TRAIT_SET_V
#
#	include <type_traits>
#	include "../trait/add_v.hpp"
#	include "../trait/rm_v.hpp"

namespace xieite {
	template<bool qual, typename T>
	using set_v = std::conditional_t<qual, xieite::add_v<T>, xieite::rm_v<T>>;
}

#endif
