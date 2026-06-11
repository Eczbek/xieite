#ifndef DETAIL_XTE_HEADER_TRAIT_IS_MEMBER_OF
#	define DETAIL_XTE_HEADER_TRAIT_IS_MEMBER_OF

namespace DETAIL_XTE {
	template<typename, typename>
	constexpr bool is_member_of = false;

	template<typename T, typename U>
	constexpr bool is_member_of<T U::*, U> = true;

	template<typename T, typename U>
	constexpr bool is_member_of<T U::*&, U> = true;

	template<typename T, typename U>
	constexpr bool is_member_of<T U::*&&, U> = true;
}

namespace xte {
	template<typename T, typename U>
	concept is_member_of = DETAIL_XTE::is_member_of<T, U>;
}

#endif
