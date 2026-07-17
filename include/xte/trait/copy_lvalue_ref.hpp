#ifndef DETAIL_XTE_HEADER_TRAIT_COPY_LVALUE_REF
#	define DETAIL_XTE_HEADER_TRAIT_COPY_LVALUE_REF

namespace DETAIL_XTE::copy_lvalue_ref {
	template<typename, typename U>
	constexpr auto impl = ^^U;

	template<typename T, typename U>
	constexpr auto impl<T, U&> = ^^U;

	template<typename T, typename U>
	constexpr auto impl<T&, U> = ^^U&;

	template<typename T, typename U>
	constexpr auto impl<T&, U&> = ^^U&;

	template<typename T, typename U>
	constexpr auto impl<T&&, U> = ^^U;

	template<typename T, typename U>
	constexpr auto impl<T&&, U&> = ^^U;
}

namespace xte {
	template<typename T, typename U>
	using copy_lvalue_ref = [:DETAIL_XTE::copy_lvalue_ref::impl<T, U>:];
}

#endif
