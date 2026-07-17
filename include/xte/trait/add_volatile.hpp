#ifndef DETAIL_XTE_HEADER_TRAIT_ADD_VOLATILE
#	define DETAIL_XTE_HEADER_TRAIT_ADD_VOLATILE
#
#	include "../meta/wrap_type.hpp"

namespace DETAIL_XTE::add_volatile {
	template<typename T>
	constexpr auto impl = ^^volatile T;

	template<typename T>
	constexpr auto impl<T&> = ^^volatile T&;

	template<typename T>
	constexpr auto impl<T&&> = ^^volatile T&&;
}

namespace xte {
	template<typename T>
	using add_volatile = [:DETAIL_XTE::add_volatile::impl<T>:];
}

#endif
