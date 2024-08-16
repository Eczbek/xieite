#ifndef XIEITE_HEADER_ALGORITHMS_ALL
#	define XIEITE_HEADER_ALGORITHMS_ALL

#	include <functional>
#	include "../concepts/functor.hpp"
#	include "../concepts/no_throw_invocable.hpp"
#	include "../macros/forward.hpp"

namespace xieite::algorithms {
	template<typename... Values, typename Functor>
	requires((... && xieite::concepts::Functor<Functor, bool(Values)>))
	[[nodiscard]] constexpr bool all(Functor&& functor, Values&&... values)
	noexcept((... && xieite::concepts::NoThrowInvocable<Functor, Values>)) {
		return (... && std::invoke(functor, XIEITE_FORWARD(values)));
	}
}

#endif
