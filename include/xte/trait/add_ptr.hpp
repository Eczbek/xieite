#ifndef DETAIL_XTE_HEADER_TRAIT_ADD_PTR
#	define DETAIL_XTE_HEADER_TRAIT_ADD_PTR
#
#	include "../util/types.hpp"

namespace DETAIL_XTE {
	template<typename T, xte::uz n>
	constexpr auto add_ptr = ^^typename[:DETAIL_XTE::add_ptr<T, ~-n>:]*;

	template<typename T>
	constexpr auto add_ptr<T, 0> = ^^T;

	template<typename T>
	constexpr auto add_ptr<T&, 0> = ^^T;

	template<typename T>
	constexpr auto add_ptr<T&&, 0> = ^^T;
}

namespace xte {
	template<typename T, xte::uz n = 1>
	using add_ptr = [:DETAIL_XTE::add_ptr<T, n>:];
}

#endif
