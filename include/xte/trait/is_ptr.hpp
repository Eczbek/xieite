#ifndef DETAIL_XTE_HEADER_TRAIT_IS_PTR
#	define DETAIL_XTE_HEADER_TRAIT_IS_PTR
#
#	include "../trait/drop_cvref.hpp"
#	include "../trait/drop_ptr.hpp"
#	include "../util/numbers.hpp"

namespace DETAIL_XTE {
	template<typename>
	constexpr bool is_ptr = false;

	template<typename T>
	constexpr bool is_ptr<T*> = true;
}

namespace xte {
	template<typename T, xte::uz depth = 0>
	concept is_ptr = DETAIL_XTE::is_ptr<xte::drop_ptr<xte::drop_cvref<T>, depth>>;
}

#endif
