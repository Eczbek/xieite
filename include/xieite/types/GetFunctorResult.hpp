#ifndef XIEITE_HEADER__TYPES__GET_FUNCTOR_RESULT
#	define XIEITE_HEADER__TYPES__GET_FUNCTOR_RESULT

namespace xieite::types {
	template<typename>
	struct GetFunctorResult;

	template<typename Result, typename Pointer, typename... Arguments>
	struct GetFunctorResult<Result(Pointer::*)(Arguments...)> {
		using Type = Result;
	};

	template<typename Result, typename Pointer, typename... Arguments>
	struct GetFunctorResult<Result(Pointer::*)(Arguments...) const> {
		using Type = Result;
	};
}

#endif
