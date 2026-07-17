#ifndef DETAIL_XTE_HEADER_TRAIT_COPY_RVALUE_REF
#	define DETAIL_XTE_HEADER_TRAIT_COPY_RVALUE_REF

namespace DETAIL_XTE::copy_rvalue_ref {
	template<typename, typename U>
	constexpr auto impl = ^^U;

	template<typename T, typename U>
	constexpr auto impl<T, U&&> = ^^U;

	template<typename T, typename U>
	constexpr auto impl<T&&, U> = ^^U&&;

	template<typename T, typename U>
	constexpr auto impl<T&&, U&> = ^^U&&;

	template<typename T, typename U>
	constexpr auto impl<T&&, U&&> = ^^U&&;
}

namespace xte {
	template<typename T, typename U>
	using copy_rvalue_ref = [:DETAIL_XTE::copy_rvalue_ref::impl<T, U>:];
}

#endif
