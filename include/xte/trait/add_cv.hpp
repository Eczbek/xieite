#ifndef DETAIL_XTE_HEADER_TRAIT_ADD_CV
#	define DETAIL_XTE_HEADER_TRAIT_ADD_CV
#
#	include "../trait/add_const.hpp"
#	include "../trait/add_volatile.hpp"

namespace xte {
	template<typename T>
	using add_cv = xte::add_volatile<xte::add_const<T>>;
}

#endif
