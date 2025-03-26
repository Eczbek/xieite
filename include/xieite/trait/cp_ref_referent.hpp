#ifndef DETAIL_XIEITE_HEADER_TRAIT_CP_REF_REFERENT
#	define DETAIL_XIEITE_HEADER_TRAIT_CP_REF_REFERENT
#
#	include <type_traits>
#	include "../trait/add_lref_referent.hpp"
#	include "../trait/is_lref_referent.hpp"
#	include "../trait/cp_rref_referent.hpp"
#	include "../trait/rm_ref_referent.hpp"

namespace xieite {
	template<typename T, typename U>
	using cp_ref_referent = std::conditional_t<xieite::is_lref_referent<T>, xieite::add_lref_referent<U>, xieite::cp_rref_referent<T, xieite::rm_ref_referent<U>>>;
}

#endif
