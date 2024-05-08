#ifndef XIEITE_HEADER_FUNCTORS_POST_OPERATION
#	define XIEITE_HEADER_FUNCTORS_POST_OPERATION

#	include <functional>
#	include "../concepts/no_throw_invocable.hpp"
#	include "../macros/forward.hpp"

namespace xieite::functors {
	template<typename Type_, std::invocable<Type_&> Functor_>
	[[nodiscard]] constexpr Type_ postOperation(Type_& value, Functor_&& functor)
	noexcept(xieite::concepts::NoThrowInvocable<Functor_, Type_&>) {
		const Type_ copy = value;
		std::invoke(XIEITE_FORWARD(functor), value);
		return copy;
	}
}

#endif
