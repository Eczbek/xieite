#ifndef DETAIL_XTE_HEADER_TRAIT_REMOVE_V
#	define DETAIL_XTE_HEADER_TRAIT_REMOVE_V

namespace DETAIL_XTE {
	template<typename T>
	constexpr auto remove_v = ^^T;

	template<typename T>
	constexpr auto remove_v<volatile T> = ^^T;

	template<typename T>
	constexpr auto remove_v<volatile T&> = ^^T&;

	template<typename T>
	constexpr auto remove_v<volatile T&&> = ^^T&&;
}

namespace xte {
	template<typename T>
	using remove_v = [:DETAIL_XTE::remove_v<T>:];
}

#endif
