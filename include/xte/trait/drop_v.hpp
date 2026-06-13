#ifndef DETAIL_XTE_HEADER_TRAIT_DROP_V
#	define DETAIL_XTE_HEADER_TRAIT_DROP_V

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
	using drop_v = [:DETAIL_XTE::remove_v<T>:];
}

#endif
