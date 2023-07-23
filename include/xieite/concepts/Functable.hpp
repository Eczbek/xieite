#ifndef XIEITE_HEADER_CONCEPTS_FUNCTABLE
#	define XIEITE_HEADER_CONCEPTS_FUNCTABLE

#	include <xieite/traits/isFunctable.hpp>

namespace xieite::concepts {
	template<typename Functor, typename Type>
	concept Functable = xieite::traits::isFunctable<Functor, Type>;
}

#endif
