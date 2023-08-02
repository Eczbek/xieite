#ifndef XIEITE_HEADER_TRAITS_ISFUNCTABLE
#	define XIEITE_HEADER_TRAITS_ISFUNCTABLE

#	include <concepts>
#	include <type_traits>

namespace xieite::traits {
	template<typename, typename>
	inline constexpr bool isFunctable = false;

	template<typename Functor, typename Result, typename... Parameters>
	inline constexpr bool isFunctable<Functor, Result(Parameters...)> = std::invocable<Functor, Parameters...> && std::convertible_to<Result, std::invoke_result_t<Functor, Parameters...>>;
}

#endif
