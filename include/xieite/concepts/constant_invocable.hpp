#ifndef XIEITE_HEADER_CONCEPTS_CONSTANT_INVOCABLE
#	define XIEITE_HEADER_CONCEPTS_CONSTANT_INVOCABLE

#	include <functional>

namespace xieite::concepts {
	template<typename Functor_, typename... Arguments_>
	concept ConstantInvocable = requires(const Functor_ functor, Arguments_... arguments) {
		std::invoke(functor, arguments...);
	};
}

#endif
