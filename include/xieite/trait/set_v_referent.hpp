#ifndef DETAIL_XIEITE_HEADER_TRAIT_SET_V_REFERENT
#	define DETAIL_XIEITE_HEADER_TRAIT_SET_V_REFERENT
#
#	include <type_traits>
#	include "../trait/add_v_referent.hpp"
#	include "../trait/rm_v_referent.hpp"

namespace xieite {
	template<bool qual, typename T>
	using set_v_referent = std::conditional_t<qual, xieite::add_v_referent<T>, xieite::rm_v_referent<T>>;
}

#endif
