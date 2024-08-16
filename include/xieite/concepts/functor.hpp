#ifndef XIEITE_HEADER_CONCEPTS_FUNCTOR
#	define XIEITE_HEADER_CONCEPTS_FUNCTOR

#	include "../traits/is_functor.hpp"

namespace xieite::concepts {
	template<typename Type, typename Signature>
	concept Functor = xieite::traits::IsFunctor<Type, Signature>::value;
}

#endif
