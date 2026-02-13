#ifndef DETAIL_XTE_HEADER_TRAIT_COPY_LREF
#	define DETAIL_XTE_HEADER_TRAIT_COPY_LREF

namespace DETAIL_XTE {
	template<typename, typename U>
	constexpr auto copy_lref = ^^U;

	template<typename T, typename U>
	constexpr auto copy_lref<T, U&> = ^^U;

	template<typename T, typename U>
	constexpr auto copy_lref<T&, U> = ^^U&;

	template<typename T, typename U>
	constexpr auto copy_lref<T&, U&> = ^^U&;

	template<typename T, typename U>
	constexpr auto copy_lref<T&&, U> = ^^U;

	template<typename T, typename U>
	constexpr auto copy_lref<T&&, U&> = ^^U;
}

namespace xte {
	template<typename T, typename U>
	using copy_lref = [:DETAIL_XTE::copy_lref<T, U>:];
}

#endif
