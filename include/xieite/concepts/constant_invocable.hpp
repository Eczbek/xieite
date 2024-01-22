#ifndef XIEITE_HEADER_CONCEPTS_CONSTANT_INVOCABLE
#	define XIEITE_HEADER_CONCEPTS_CONSTANT_INVOCABLE

#	include <concepts>
#	include <functional>
#	include <utility>

namespace xieite::concepts {
	template<typename Functor, typename... Arguments>
	concept ConstantInvocable = std::invocable<Functor, Arguments...> && requires(const Functor functor, Arguments... arguments) {
		std::invoke(functor, std::forward<Arguments>(arguments)...);
	};
}

#endif
