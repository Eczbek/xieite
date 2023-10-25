#ifndef XIEITE_HEADER_CONCEPTS_NO_THROW_INVOCABLE
#	define XIEITE_HEADER_CONCEPTS_NO_THROW_INVOCABLE

#	include <concepts>
#	include <utility>

namespace xieite::concepts {
	template<typename Functor, typename... Arguments>
	concept NoThrowInvocable = std::invocable<Functor, Arguments...> && noexcept(std::declval<Functor>()(std::declval<Arguments>()...));
}

#endif
