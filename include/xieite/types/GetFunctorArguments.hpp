#ifndef XIEITE_HEADER__TYPES__GET_FUNCTOR_ARGUMENTS
#	define XIEITE_HEADER__TYPES__GET_FUNCTOR_ARGUMENTS

#	include <tuple>

namespace xieite::types {
	template<typename>
	struct GetFunctorArguments;

	template<typename Result, typename Pointer, typename... Arguments>
	struct GetFunctorArguments<Result(Pointer::*)(Arguments...)> {
		using Type = std::tuple<Arguments...>;
	};

	template<typename Result, typename Pointer, typename... Arguments>
	struct GetFunctorArguments<Result(Pointer::*)(Arguments...) const> {
		using Type = std::tuple<Arguments...>;
	};
}

#endif
