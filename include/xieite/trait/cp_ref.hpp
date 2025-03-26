#ifndef DETAIL_XIEITE_HEADER_TRAIT_CP_REF
#	define DETAIL_XIEITE_HEADER_TRAIT_CP_REF
#
#	include <type_traits>
#	include "../trait/add_lref.hpp"
#	include "../trait/is_lref.hpp"
#	include "../trait/cp_rref.hpp"
#	include "../trait/rm_ref.hpp"

namespace xieite {
	template<typename T, typename U>
	using cp_ref = std::conditional_t<xieite::is_lref<T>, xieite::add_lref<U>, xieite::cp_rref<T, xieite::rm_ref<U>>>;
}

#endif
