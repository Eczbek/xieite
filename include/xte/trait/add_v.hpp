#ifndef DETAIL_XTE_HEADER_TRAIT_ADD_V
#	define DETAIL_XTE_HEADER_TRAIT_ADD_V
#
#	include "../meta/wrap_type.hpp"

namespace DETAIL_XTE {
	template<typename T>
	constexpr auto add_v = ^^volatile T;

	template<typename T>
	constexpr auto add_v<T&> = ^^volatile T&;

	template<typename T>
	constexpr auto add_v<T&&> = ^^volatile T&&;
}

namespace xte {
	template<typename T>
	using add_v = [:DETAIL_XTE::add_v<T>:];
}

#endif
