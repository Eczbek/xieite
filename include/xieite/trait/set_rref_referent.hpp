#ifndef DETAIL_XIEITE_HEADER_TRAIT_SET_RREF_REFERENT
#	define DETAIL_XIEITE_HEADER_TRAIT_SET_RREF_REFERENT
#
#	include <type_traits>
#	include "../trait/add_rref_referent.hpp"
#	include "../trait/rm_rref_referent.hpp"

namespace xieite {
	template<bool qual, typename T>
	using set_rref_referent = std::conditional_t<qual, xieite::add_rref_referent<T>, xieite::rm_rref_referent<T>>;
}

#endif
