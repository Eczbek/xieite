#ifndef DETAIL_XIEITE_HEADER_TRAIT_SET_NOEX
#	define DETAIL_XIEITE_HEADER_TRAIT_SET_NOEX
#
#	include "../trait/add_noex.hpp"
#	include "../trait/rm_noex.hpp"

namespace xieite {
	template<bool qual, typename T>
	using set_noex = std::conditional_t<qual, xieite::add_noex<T>, xieite::rm_noex<T>>;
}

#endif
