#ifndef XIEITE_HEADER_CONCEPTS_FUNCTABLE
#	define XIEITE_HEADER_CONCEPTS_FUNCTABLE

#	include "../traits/is_functable.hpp"

namespace xieite::concepts {
	template<typename Functor_, typename Signature_>
	concept Functable = xieite::traits::IsFunctable<Functor_, Signature_>::value;
}

#endif
