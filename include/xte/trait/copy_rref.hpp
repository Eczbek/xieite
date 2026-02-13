#ifndef DETAIL_XTE_HEADER_TRAIT_COPY_RREF
#	define DETAIL_XTE_HEADER_TRAIT_COPY_RREF

namespace DETAIL_XTE {
	template<typename, typename U>
	constexpr auto copy_rref = ^^U;

	template<typename T, typename U>
	constexpr auto copy_rref<T, U&&> = ^^U;

	template<typename T, typename U>
	constexpr auto copy_rref<T&&, U> = ^^U&&;

	template<typename T, typename U>
	constexpr auto copy_rref<T&&, U&> = ^^U&&;

	template<typename T, typename U>
	constexpr auto copy_rref<T&&, U&&> = ^^U&&;
}

namespace xte {
	template<typename T, typename U>
	using copy_rref = [:DETAIL_XTE::copy_rref<T, U>:];
}

#endif
