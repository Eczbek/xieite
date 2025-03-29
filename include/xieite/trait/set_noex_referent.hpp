#ifndef DETAIL_XIEITE_HEADER_TRAIT_SET_NOEX_REFERENT
#	define DETAIL_XIEITE_HEADER_TRAIT_SET_NOEX_REFERENT
#
#	include "../trait/add_noex_referent.hpp"
#	include "../trait/rm_noex_referent.hpp"

namespace xieite {
	template<bool qual, typename T>
	using set_noex_referent = std::conditional_t<qual, xieite::add_noex_referent<T>, xieite::rm_noex_referent<T>>;
}

#endif
