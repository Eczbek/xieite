#ifndef XIEITE_HEADER_FUNCTORS_POST_OPERATION
#	define XIEITE_HEADER_FUNCTORS_POST_OPERATION

#	include <functional>
#	include "../concepts/no_throw_invocable.hpp"
#	include "../macros/forward.hpp"

namespace xieite::functors {
	template<typename Type, std::invocable<Type&> Functor>
	[[nodiscard]] constexpr Type postOperation(Type& value, Functor&& functor)
	noexcept(xieite::concepts::NoThrowInvocable<Functor, Type&>) {
		const Type copy = value;
		std::invoke(XIEITE_FORWARD(functor), value);
		return copy;
	}
}

#endif
