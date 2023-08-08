#ifndef XIEITE_HEADER__FUNCTORS__ARGUMENTS
#	define XIEITE_HEADER__FUNCTORS__ARGUMENTS

#	include "../types/GetFunctorArguments.hpp"

namespace xieite::functors {
	template<typename Functor>
	using Arguments = xieite::types::GetFunctorArguments<decltype(&Functor::operator())>::Type;
}

#endif
