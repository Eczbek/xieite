#ifndef XIEITE_HEADER_TRAITS_ISFUNCTABLE
#	define XIEITE_HEADER_TRAITS_ISFUNCTABLE

#	include <concepts>
#	include <utility>

namespace xieite::traits {
	template<typename, typename>
	inline constexpr bool isFunctable = false;

	template<typename Functor, typename Result, typename... Parameters>
	inline constexpr bool isFunctable<Functor, Result(Parameters...)> = std::same_as<Result, decltype(std::declval<Functor>()(std::declval<Parameters>()...))>;

	template<typename Functor, typename Result, typename... Parameters>
	inline constexpr bool isFunctable<Result(Parameters...), Functor> = xieite::traits::isFunctable<Functor, Result(Parameters...)>;
}

#endif
