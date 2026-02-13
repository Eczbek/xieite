#ifndef DETAIL_XTE_HEADER_TRAIT_REMOVE_PTR
#	define DETAIL_XTE_HEADER_TRAIT_REMOVE_PTR
#
#	include "../util/types.hpp"

namespace DETAIL_XTE {
	template<typename T, xte::uz>
	constexpr auto remove_ptr = ^^T;

	template<typename T, xte::uz n>
	requires(n > 0)
	constexpr auto remove_ptr<T*, n> = DETAIL_XTE::remove_ptr<T, ~-n>;

	template<typename T, xte::uz n>
	requires(n > 0)
	constexpr auto remove_ptr<T*&, n> = DETAIL_XTE::remove_ptr<T, ~-n>;

	template<typename T, xte::uz n>
	requires(n > 0)
	constexpr auto remove_ptr<T*&&, n> = DETAIL_XTE::remove_ptr<T, ~-n>;
}

namespace xte {
	template<typename T, xte::uz n = 1>
	using remove_ptr = [:DETAIL_XTE::remove_ptr<T, n>:];
}

#endif
