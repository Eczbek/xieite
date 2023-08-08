#ifndef XIEITE_HEADER__FUNCTORS__RESULT
#	define XIEITE_HEADER__FUNCTORS__RESULT

#	include "../types/GetFunctorResult.hpp"

namespace xieite::functors {
	template<typename Functor>
	using Result = xieite::types::GetFunctorResult<decltype(&Functor::operator())>::Type;
}

#endif
