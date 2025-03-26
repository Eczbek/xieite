#ifndef DETAIL_XIEITE_HEADER_TRAIT_CP_V_REFERENT
#	define DETAIL_XIEITE_HEADER_TRAIT_CP_V_REFERENT
#
#	include <type_traits>
#	include "../trait/add_v_referent.hpp"
#	include "../trait/is_v_referent.hpp"
#	include "../trait/rm_v_referent.hpp"

namespace xieite {
	template<typename T, typename U>
	using cp_v_referent = std::conditional_t<xieite::is_v_referent<T>, xieite::add_v_referent<U>, xieite::rm_v_referent<U>>;
}

#endif
