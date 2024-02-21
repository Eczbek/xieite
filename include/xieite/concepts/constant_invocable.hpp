#ifndef XIEITE_HEADER_CONCEPTS_CONSTANT_INVOCABLE
#	define XIEITE_HEADER_CONCEPTS_CONSTANT_INVOCABLE

#	include <functional>

namespace xieite::concepts {
	template<typename Functor, typename... Arguments>
	concept ConstantInvocable = requires(const Functor functor, Arguments... arguments) {
		std::invoke(functor, arguments...);
	};
}

#endif
