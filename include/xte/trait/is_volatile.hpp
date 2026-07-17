#ifndef DETAIL_XTE_HEADER_TRAIT_IS_VOLATILE
#	define DETAIL_XTE_HEADER_TRAIT_IS_VOLATILE

namespace DETAIL_XTE::is_volatile {
	template<typename T>
	constexpr bool impl = false;

	template<typename T>
	constexpr bool impl<volatile T> = true;

	template<typename T>
	constexpr bool impl<volatile T&> = true;

	template<typename T>
	constexpr bool impl<volatile T&&> = true;
}

namespace xte {
	template<typename T>
	concept is_volatile = DETAIL_XTE::is_volatile::impl<T>;
}

#endif
