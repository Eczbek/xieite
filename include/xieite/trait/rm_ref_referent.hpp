#ifndef DETAIL_XIEITE_HEADER_TRAIT_RM_REF_REFERENT
#	define DETAIL_XIEITE_HEADER_TRAIT_RM_REF_REFERENT
#
#	include <type_traits>
#	include "../trait/is_lref_referent.hpp"
#	include "../trait/is_rref_referent.hpp"
#	include "../trait/rm_lref_referent.hpp"
#	include "../trait/rm_rref_referent.hpp"

namespace xieite {
	template<typename T, typename U = T>
	using rm_ref_referent = std::conditional_t<xieite::is_lref_referent<U>, xieite::rm_lref_referent<T>, std::conditional_t<xieite::is_rref_referent<U>, xieite::rm_rref_referent<T>, std::type_identity<T>>>;
}

#endif
