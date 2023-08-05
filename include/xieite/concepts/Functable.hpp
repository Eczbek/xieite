#ifndef XIEITE_HEADER__CONCEPTS__FUNCTABLE
#	define XIEITE_HEADER__CONCEPTS__FUNCTABLE

#	include "../traits/IsFunctable.hpp"

namespace xieite::concepts {
	template<typename Functor, typename Specification>
	concept Functable = xieite::traits::IsFunctable<Functor, Specification>::value;
}

#endif
