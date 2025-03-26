#ifndef DETAIL_XIEITE_HEADER_TRAIT_SET_RREF
#	define DETAIL_XIEITE_HEADER_TRAIT_SET_RREF
#
#	include <type_traits>
#	include "../trait/add_rref.hpp"
#	include "../trait/rm_ref.hpp"
#	include "../trait/rm_rref.hpp"

namespace xieite {
	template<bool qual, typename T>
	using set_rref = std::conditional_t<qual, xieite::add_rref<xieite::rm_ref<T>>, xieite::rm_rref<T>>;
}

#endif
