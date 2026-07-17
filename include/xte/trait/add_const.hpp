#ifndef DETAIL_XTE_HEADER_TRAIT_ADD_CONST
#	define DETAIL_XTE_HEADER_TRAIT_ADD_CONST

namespace DETAIL_XTE::add_const {
	template<typename T>
	constexpr auto impl = ^^const T;

	template<typename T>
	constexpr auto impl<T&> = ^^const T&;

	template<typename T>
	constexpr auto impl<T&&> = ^^const T&&;
}

namespace xte {
	template<typename T>
	using add_const = [:DETAIL_XTE::add_const::impl<T>:];
}

#endif
