#ifndef DETAIL_XTE_HEADER_TRAIT_IS_VOID
#	define DETAIL_XTE_HEADER_TRAIT_IS_VOID

namespace DETAIL_XTE {
	template<typename>
	constexpr bool is_void = false;

	template<>
	constexpr bool is_void<void> = true;

	template<>
	constexpr bool is_void<const void> = true;

	template<>
	constexpr bool is_void<volatile void> = true;

	template<>
	constexpr bool is_void<volatile const void> = true;
}

namespace xte {
	template<typename T>
	concept is_void = DETAIL_XTE::is_void<T>;
}

#endif
