#ifndef DETAIL_XTE_HEADER_TRAIT_ADD_PTR
#	define DETAIL_XTE_HEADER_TRAIT_ADD_PTR
#
#	include "../util/number_types.hpp"

namespace DETAIL_XTE::add_ptr {
	template<typename T, xte::uz depth>
	constexpr auto impl = ^^typename[:impl<T, (depth - 1)>:]*;

	template<typename T>
	constexpr auto impl<T, 0> = ^^T;

	template<typename T>
	constexpr auto impl<T&, 0> = ^^T;

	template<typename T>
	constexpr auto impl<T&&, 0> = ^^T;
}

namespace xte {
	template<typename T, xte::uz depth = 1>
	using add_ptr = [:DETAIL_XTE::add_ptr::impl<T, depth>:];
}

#endif
