#ifndef DETAIL_XTE_HEADER_TRAIT_COPY_REF
#	define DETAIL_XTE_HEADER_TRAIT_COPY_REF

namespace DETAIL_XTE {
	template<typename, typename U>
	constexpr auto copy_ref = ^^U;

	template<typename T, typename U>
	constexpr auto copy_ref<T, U&> = ^^U;

	template<typename T, typename U>
	constexpr auto copy_ref<T, U&&> = ^^U;

	template<typename T, typename U>
	constexpr auto copy_ref<T&, U> = ^^U&;

	template<typename T, typename U>
	constexpr auto copy_ref<T&, U&> = ^^U&;

	template<typename T, typename U>
	constexpr auto copy_ref<T&&, U> = ^^U&&;

	template<typename T, typename U>
	constexpr auto copy_ref<T&&, U&> = ^^U&&;

	template<typename T, typename U>
	constexpr auto copy_ref<T&&, U&&> = ^^U&&;
}

namespace xte {
	template<typename T, typename U>
	using copy_ref = [:DETAIL_XTE::copy_ref<T, U>:];
}

#endif
