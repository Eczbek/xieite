#ifndef DETAIL_XTE_HEADER_TRAIT_DROP_CONST
#	define DETAIL_XTE_HEADER_TRAIT_DROP_CONST

namespace DETAIL_XTE::drop_const {
	template<typename T>
	constexpr auto impl = ^^T;

	template<typename T>
	constexpr auto impl<const T> = ^^T;

	template<typename T>
	constexpr auto impl<const T&> = ^^T&;

	template<typename T>
	constexpr auto impl<const T&&> = ^^T&&;
}

namespace xte {
	template<typename T>
	using drop_const = [:DETAIL_XTE::drop_const::impl<T>:];
}

#endif
