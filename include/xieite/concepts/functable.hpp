#ifndef XIEITE_HEADER_CONCEPTS_FUNCTABLE
#	define XIEITE_HEADER_CONCEPTS_FUNCTABLE

#	include "../traits/functable.hpp"

namespace xieite::concepts {
	template<typename Functor, typename Signature>
	concept Functable = xieite::traits::Functable<Functor, Signature>::value;
}

#endif
