#ifndef DETAIL_XTE_HEADER_TRAIT_DROP_PTR
#	define DETAIL_XTE_HEADER_TRAIT_DROP_PTR
#
#	include "../util/numbers.hpp"

namespace DETAIL_XTE {
	template<typename T, xte::uz n>
	constexpr auto remove_ptr = ^^T;

	template<typename T, xte::uz n>
	requires(!!n)
	constexpr auto remove_ptr<T*, n> = DETAIL_XTE::remove_ptr<T, ~-n>;

	template<typename T, xte::uz n>
	requires(!!n)
	constexpr auto remove_ptr<T*&, n> = DETAIL_XTE::remove_ptr<T&, ~-n>;

	template<typename T, xte::uz n>
	requires(!!n)
	constexpr auto remove_ptr<T*&&, n> = DETAIL_XTE::remove_ptr<T&, ~-n>;
}

namespace xte {
	template<typename T, xte::uz n = 1>
	using drop_ptr = [:DETAIL_XTE::remove_ptr<T, n>:];
}

#endif
