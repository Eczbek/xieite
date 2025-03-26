#ifndef DETAIL_XIEITE_HEADER_TRAIT_SET_C
#	define DETAIL_XIEITE_HEADER_TRAIT_SET_C
#
#	include <type_traits>
#	include "../trait/add_c.hpp"
#	include "../trait/rm_c.hpp"

namespace xieite {
	template<bool qual, typename T>
	using set_c = std::conditional_t<qual, xieite::add_c<T>, xieite::rm_c<T>>;
}

#endif
