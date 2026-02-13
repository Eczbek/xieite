#ifndef DETAIL_XTE_HEADER_TRAIT_COPY_C
#	define DETAIL_XTE_HEADER_TRAIT_COPY_C

namespace DETAIL_XTE {
	template<typename, typename U>
	constexpr auto copy_c = ^^U;

	template<typename T, typename U>
	constexpr auto copy_c<T, const U> = ^^U;

	template<typename T, typename U>
	constexpr auto copy_c<T, const U&> = ^^U&;

	template<typename T, typename U>
	constexpr auto copy_c<T, const U&&> = ^^U&&;

	template<typename T, typename U>
	constexpr auto copy_c<T&, const U> = ^^U;

	template<typename T, typename U>
	constexpr auto copy_c<T&, const U&> = ^^U&;

	template<typename T, typename U>
	constexpr auto copy_c<T&, const U&&> = ^^U&&;

	template<typename T, typename U>
	constexpr auto copy_c<T&&, const U> = ^^U;

	template<typename T, typename U>
	constexpr auto copy_c<T&&, const U&> = ^^U&;

	template<typename T, typename U>
	constexpr auto copy_c<T&&, const U&&> = ^^U&&;

	template<typename T, typename U>
	constexpr auto copy_c<const T, U> = ^^const U;

	template<typename T, typename U>
	constexpr auto copy_c<const T, U&> = ^^const U&;

	template<typename T, typename U>
	constexpr auto copy_c<const T, U&&> = ^^const U&&;

	template<typename T, typename U>
	constexpr auto copy_c<const T&, U> = ^^const U;

	template<typename T, typename U>
	constexpr auto copy_c<const T&, U&> = ^^const U&;

	template<typename T, typename U>
	constexpr auto copy_c<const T&, U&&> = ^^const U&&;

	template<typename T, typename U>
	constexpr auto copy_c<const T&&, U> = ^^const U;

	template<typename T, typename U>
	constexpr auto copy_c<const T&&, U&> = ^^const U&;

	template<typename T, typename U>
	constexpr auto copy_c<const T&&, U&&> = ^^const U&&;

	template<typename T, typename U>
	constexpr auto copy_c<const T, const U> = ^^const U;

	template<typename T, typename U>
	constexpr auto copy_c<const T, const U&> = ^^const U&;

	template<typename T, typename U>
	constexpr auto copy_c<const T, const U&&> = ^^const U&&;

	template<typename T, typename U>
	constexpr auto copy_c<const T&, const U> = ^^const U;

	template<typename T, typename U>
	constexpr auto copy_c<const T&, const U&> = ^^const U&;

	template<typename T, typename U>
	constexpr auto copy_c<const T&, const U&&> = ^^const U&&;

	template<typename T, typename U>
	constexpr auto copy_c<const T&&, const U> = ^^const U;

	template<typename T, typename U>
	constexpr auto copy_c<const T&&, const U&> = ^^const U&;

	template<typename T, typename U>
	constexpr auto copy_c<const T&&, const U&&> = ^^const U&&;
}

namespace xte {
	template<typename T, typename U>
	using copy_c = [:DETAIL_XTE::copy_c<T, U>:];
}

#endif
