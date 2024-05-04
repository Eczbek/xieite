#ifndef XIEITE_HEADER_ALGORITHMS_ANY
#	define XIEITE_HEADER_ALGORITHMS_ANY

#	include <functional>
#	include "../concepts/functable.hpp"
#	include "../concepts/no_throw_invocable.hpp"
#	include "../macros/forward.hpp"

namespace xieite::algorithms {
	template<typename... Values_, typename Functor_>
	requires((... && xieite::concepts::Functable<Functor_, bool(Values_)>))
	[[nodiscard]] constexpr bool any(Functor_&& functor, Values_&&... values)
	noexcept((... && xieite::concepts::NoThrowInvocable<Functor_, Values_>)) {
		return (... || std::invoke(functor, XIEITE_FORWARD(values)));
	}
}

#endif
