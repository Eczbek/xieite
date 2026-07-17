#ifndef DETAIL_XTE_HEADER_TRAIT_COPY_VOLATILE
#	define DETAIL_XTE_HEADER_TRAIT_COPY_VOLATILE

namespace DETAIL_XTE::copy_volatile {
	template<typename T, typename U>
	constexpr auto impl = ^^U;

	template<typename T, typename U>
	constexpr auto impl<T, volatile U&> = ^^U&;

	template<typename T, typename U>
	constexpr auto impl<T, volatile U&&> = ^^U&&;

	template<typename T, typename U>
	constexpr auto impl<T&, volatile U> = ^^U;

	template<typename T, typename U>
	constexpr auto impl<T&, volatile U&> = ^^U&;

	template<typename T, typename U>
	constexpr auto impl<T&, volatile U&&> = ^^U&&;

	template<typename T, typename U>
	constexpr auto impl<T&&, volatile U> = ^^U;

	template<typename T, typename U>
	constexpr auto impl<T&&, volatile U&> = ^^U&;

	template<typename T, typename U>
	constexpr auto impl<T&&, volatile U&&> = ^^U&&;

	template<typename T, typename U>
	constexpr auto impl<volatile T, U> = ^^volatile U;

	template<typename T, typename U>
	constexpr auto impl<volatile T, U&> = ^^volatile U&;

	template<typename T, typename U>
	constexpr auto impl<volatile T, U&&> = ^^volatile U&&;

	template<typename T, typename U>
	constexpr auto impl<volatile T&, U> = ^^volatile U;

	template<typename T, typename U>
	constexpr auto impl<volatile T&, U&> = ^^volatile U&;

	template<typename T, typename U>
	constexpr auto impl<volatile T&, U&&> = ^^volatile U&&;

	template<typename T, typename U>
	constexpr auto impl<volatile T&&, U> = ^^volatile U;

	template<typename T, typename U>
	constexpr auto impl<volatile T&&, U&> = ^^volatile U&;

	template<typename T, typename U>
	constexpr auto impl<volatile T&&, U&&> = ^^volatile U&&;

	template<typename T, typename U>
	constexpr auto impl<volatile T, volatile U> = ^^volatile U;

	template<typename T, typename U>
	constexpr auto impl<volatile T, volatile U&> = ^^volatile U&;

	template<typename T, typename U>
	constexpr auto impl<volatile T, volatile U&&> = ^^volatile U&&;

	template<typename T, typename U>
	constexpr auto impl<volatile T&, volatile U> = ^^volatile U;

	template<typename T, typename U>
	constexpr auto impl<volatile T&, volatile U&> = ^^volatile U&;

	template<typename T, typename U>
	constexpr auto impl<volatile T&, volatile U&&> = ^^volatile U&&;

	template<typename T, typename U>
	constexpr auto impl<volatile T&&, volatile U> = ^^volatile U;

	template<typename T, typename U>
	constexpr auto impl<volatile T&&, volatile U&> = ^^volatile U&;

	template<typename T, typename U>
	constexpr auto impl<volatile T&&, volatile U&&> = ^^volatile U&&;
}

namespace xte {
	template<typename T, typename U>
	using copy_volatile = [:DETAIL_XTE::copy_volatile::impl<T, U>:];
}

#endif
