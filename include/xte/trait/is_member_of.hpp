#ifndef DETAIL_XTE_HEADER_TRAIT_IS_MEMBER_OF
#	define DETAIL_XTE_HEADER_TRAIT_IS_MEMBER_OF

namespace DETAIL_XTE::is_member_of {
	template<typename, typename>
	constexpr bool impl = false;

	template<typename T, typename U>
	constexpr bool impl<T U::*, U> = true;

	template<typename T, typename U>
	constexpr bool impl<T U::*&, U> = true;

	template<typename T, typename U>
	constexpr bool impl<T U::*&&, U> = true;
}

namespace xte {
	template<typename T, typename U>
	concept is_member_of = DETAIL_XTE::is_member_of::impl<T, U>;
}

#endif
