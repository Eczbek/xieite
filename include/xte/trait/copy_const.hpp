#ifndef DETAIL_XTE_HEADER_TRAIT_COPY_CONST
#	define DETAIL_XTE_HEADER_TRAIT_COPY_CONST

namespace DETAIL_XTE::copy_const {
	template<typename, typename U>
	constexpr auto impl = ^^U;

	template<typename T, typename U>
	constexpr auto impl<T, const U> = ^^U;

	template<typename T, typename U>
	constexpr auto impl<T, const U&> = ^^U&;

	template<typename T, typename U>
	constexpr auto impl<T, const U&&> = ^^U&&;

	template<typename T, typename U>
	constexpr auto impl<T&, const U> = ^^U;

	template<typename T, typename U>
	constexpr auto impl<T&, const U&> = ^^U&;

	template<typename T, typename U>
	constexpr auto impl<T&, const U&&> = ^^U&&;

	template<typename T, typename U>
	constexpr auto impl<T&&, const U> = ^^U;

	template<typename T, typename U>
	constexpr auto impl<T&&, const U&> = ^^U&;

	template<typename T, typename U>
	constexpr auto impl<T&&, const U&&> = ^^U&&;

	template<typename T, typename U>
	constexpr auto impl<const T, U> = ^^const U;

	template<typename T, typename U>
	constexpr auto impl<const T, U&> = ^^const U&;

	template<typename T, typename U>
	constexpr auto impl<const T, U&&> = ^^const U&&;

	template<typename T, typename U>
	constexpr auto impl<const T&, U> = ^^const U;

	template<typename T, typename U>
	constexpr auto impl<const T&, U&> = ^^const U&;

	template<typename T, typename U>
	constexpr auto impl<const T&, U&&> = ^^const U&&;

	template<typename T, typename U>
	constexpr auto impl<const T&&, U> = ^^const U;

	template<typename T, typename U>
	constexpr auto impl<const T&&, U&> = ^^const U&;

	template<typename T, typename U>
	constexpr auto impl<const T&&, U&&> = ^^const U&&;

	template<typename T, typename U>
	constexpr auto impl<const T, const U> = ^^const U;

	template<typename T, typename U>
	constexpr auto impl<const T, const U&> = ^^const U&;

	template<typename T, typename U>
	constexpr auto impl<const T, const U&&> = ^^const U&&;

	template<typename T, typename U>
	constexpr auto impl<const T&, const U> = ^^const U;

	template<typename T, typename U>
	constexpr auto impl<const T&, const U&> = ^^const U&;

	template<typename T, typename U>
	constexpr auto impl<const T&, const U&&> = ^^const U&&;

	template<typename T, typename U>
	constexpr auto impl<const T&&, const U> = ^^const U;

	template<typename T, typename U>
	constexpr auto impl<const T&&, const U&> = ^^const U&;

	template<typename T, typename U>
	constexpr auto impl<const T&&, const U&&> = ^^const U&&;
}

namespace xte {
	template<typename T, typename U>
	using copy_const = [:DETAIL_XTE::copy_const::impl<T, U>:];
}

#endif
