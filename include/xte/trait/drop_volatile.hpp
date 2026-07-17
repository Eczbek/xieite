#ifndef DETAIL_XTE_HEADER_TRAIT_DROP_VOLATILE
#	define DETAIL_XTE_HEADER_TRAIT_DROP_VOLATILE

namespace DETAIL_XTE::drop_volatile {
	template<typename T>
	constexpr auto impl = ^^T;

	template<typename T>
	constexpr auto impl<volatile T> = ^^T;

	template<typename T>
	constexpr auto impl<volatile T&> = ^^T&;

	template<typename T>
	constexpr auto impl<volatile T&&> = ^^T&&;
}

namespace xte {
	template<typename T>
	using drop_volatile = [:DETAIL_XTE::drop_volatile::impl<T>:];
}

#endif
