#ifndef DETAIL_XTE_HEADER_TRAIT_COPY_V
#	define DETAIL_XTE_HEADER_TRAIT_COPY_V

namespace DETAIL_XTE {
	template<typename T, typename U>
	constexpr auto copy_v = ^^U;

	template<typename T, typename U>
	constexpr auto copy_v<T, volatile U&> = ^^U&;

	template<typename T, typename U>
	constexpr auto copy_v<T, volatile U&&> = ^^U&&;

	template<typename T, typename U>
	constexpr auto copy_v<T&, volatile U> = ^^U;

	template<typename T, typename U>
	constexpr auto copy_v<T&, volatile U&> = ^^U&;

	template<typename T, typename U>
	constexpr auto copy_v<T&, volatile U&&> = ^^U&&;

	template<typename T, typename U>
	constexpr auto copy_v<T&&, volatile U> = ^^U;

	template<typename T, typename U>
	constexpr auto copy_v<T&&, volatile U&> = ^^U&;

	template<typename T, typename U>
	constexpr auto copy_v<T&&, volatile U&&> = ^^U&&;

	template<typename T, typename U>
	constexpr auto copy_v<volatile T, U> = ^^volatile U;

	template<typename T, typename U>
	constexpr auto copy_v<volatile T, U&> = ^^volatile U&;

	template<typename T, typename U>
	constexpr auto copy_v<volatile T, U&&> = ^^volatile U&&;

	template<typename T, typename U>
	constexpr auto copy_v<volatile T&, U> = ^^volatile U;

	template<typename T, typename U>
	constexpr auto copy_v<volatile T&, U&> = ^^volatile U&;

	template<typename T, typename U>
	constexpr auto copy_v<volatile T&, U&&> = ^^volatile U&&;

	template<typename T, typename U>
	constexpr auto copy_v<volatile T&&, U> = ^^volatile U;

	template<typename T, typename U>
	constexpr auto copy_v<volatile T&&, U&> = ^^volatile U&;

	template<typename T, typename U>
	constexpr auto copy_v<volatile T&&, U&&> = ^^volatile U&&;

	template<typename T, typename U>
	constexpr auto copy_v<volatile T, volatile U> = ^^volatile U;

	template<typename T, typename U>
	constexpr auto copy_v<volatile T, volatile U&> = ^^volatile U&;

	template<typename T, typename U>
	constexpr auto copy_v<volatile T, volatile U&&> = ^^volatile U&&;

	template<typename T, typename U>
	constexpr auto copy_v<volatile T&, volatile U> = ^^volatile U;

	template<typename T, typename U>
	constexpr auto copy_v<volatile T&, volatile U&> = ^^volatile U&;

	template<typename T, typename U>
	constexpr auto copy_v<volatile T&, volatile U&&> = ^^volatile U&&;

	template<typename T, typename U>
	constexpr auto copy_v<volatile T&&, volatile U> = ^^volatile U;

	template<typename T, typename U>
	constexpr auto copy_v<volatile T&&, volatile U&> = ^^volatile U&;

	template<typename T, typename U>
	constexpr auto copy_v<volatile T&&, volatile U&&> = ^^volatile U&&;
}

namespace xte {
	template<typename T, typename U>
	using copy_v = [:DETAIL_XTE::copy_v<T, Y>:];
}

#endif
