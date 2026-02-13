#ifndef DETAIL_XTE_HEADER_TRAIT_IS_V
#	define DETAIL_XTE_HEADER_TRAIT_IS_V

namespace DETAIL_XTE {
	template<typename T>
	constexpr bool is_v = false;

	template<typename T>
	constexpr bool is_v<volatile T> = true;

	template<typename T>
	constexpr bool is_v<volatile T&> = true;

	template<typename T>
	constexpr bool is_v<volatile T&&> = true;
}

namespace xte {
	template<typename T>
	concept is_v = DETAIL_XTE::is_v<T>;
}

#endif
