#pragma once

#include "../traits/functable.hpp"

namespace xieite::concepts {
	template<typename Functor, typename Signature>
	concept Functable = xieite::traits::Functable<Functor, Signature>::value;
}
