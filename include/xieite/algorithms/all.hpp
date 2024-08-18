#ifndef XIEITE_HEADER_ALGORITHMS_ALL
#	define XIEITE_HEADER_ALGORITHMS_ALL

#	include <functional>
#	include <type_traits>
#	include "../concepts/functor.hpp"
#	include "../macros/forward.hpp"

namespace xieite::algorithms {
	template<typename... Values, typename Functor>
	requires((... && xieite::concepts::Functor<Functor, bool(Values)>))
	[[nodiscard]] constexpr bool all(Functor&& functor, Values&&... values)
	noexcept((... && std::is_nothrow_invocable_v<Functor, Values>)) {
		return (... && std::invoke(functor, XIEITE_FORWARD(values)));
	}
}

#endif
