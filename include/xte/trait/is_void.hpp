#ifndef DETAIL_XTE_HEADER_TRAIT_IS_VOID
#	define DETAIL_XTE_HEADER_TRAIT_IS_VOID

namespace DETAIL_XTE::is_void {
	template<typename>
	constexpr bool impl = false;

	template<>
	constexpr bool impl<void> = true;

	template<>
	constexpr bool impl<const void> = true;

	template<>
	constexpr bool impl<volatile void> = true;

	template<>
	constexpr bool impl<volatile const void> = true;
}

namespace xte {
	template<typename T>
	concept is_void = DETAIL_XTE::is_void::impl<T>;
}

#endif
