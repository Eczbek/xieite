#ifndef DETAIL_XTE_HEADER_TRAIT_IS_PTR
#	define DETAIL_XTE_HEADER_TRAIT_IS_PTR
#
#	include "../trait/remove_cvref.hpp"
#	include "../trait/remove_ptr.hpp"
#	include "../util/types.hpp"

namespace DETAIL_XTE {
	template<typename>
	constexpr bool is_ptr = false;

	template<typename T>
	constexpr bool is_ptr<T*> = true;
}

namespace xte {
	template<typename T, xte::uz depth = 0>
	concept is_ptr = DETAIL_XTE::is_ptr<xte::remove_ptr<xte::remove_cvref<T>, depth>>;
}

#endif
