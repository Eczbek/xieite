#ifndef DETAIL_XTE_HEADER_TRAIT_IS_CONST
#	define DETAIL_XTE_HEADER_TRAIT_IS_CONST

namespace DETAIL_XTE::is_const {
	template<typename T>
	constexpr bool impl = false;

	template<typename T>
	constexpr bool impl<const T> = true;

	template<typename T>
	constexpr bool impl<const T&> = true;

	template<typename T>
	constexpr bool impl<const T&&> = true;
}

namespace xte {
	template<typename T>
	concept is_const = DETAIL_XTE::is_const::impl<T>;
}

#endif
