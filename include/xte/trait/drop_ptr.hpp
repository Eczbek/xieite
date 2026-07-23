#ifndef DETAIL_XTE_HEADER_TRAIT_DROP_PTR
#	define DETAIL_XTE_HEADER_TRAIT_DROP_PTR
#
#	include "../util/number_types.hpp"

namespace DETAIL_XTE::drop_ptr {
	template<typename T, xte::uz depth>
	constexpr auto impl = ^^T;

	template<typename T, xte::uz depth>
	requires(!!depth)
	constexpr auto impl<T*, depth> = impl<T, (depth - 1)>;

	template<typename T, xte::uz depth>
	requires(!!depth)
	constexpr auto impl<T*&, depth> = impl<T&, (depth - 1)>;

	template<typename T, xte::uz depth>
	requires(!!depth)
	constexpr auto impl<T*&&, depth> = impl<T&, (depth - 1)>;
}

namespace xte {
	template<typename T, xte::uz depth = 1>
	using drop_ptr = [:DETAIL_XTE::drop_ptr::impl<T, depth>:];
}

#endif
