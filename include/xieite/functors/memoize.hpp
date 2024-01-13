#ifndef XIEITE_HEADER_FUNCTORS_MEMOIZE
#	define XIEITE_HEADER_FUNCTORS_MEMOIZE

#	include <concepts>
#	include <cstdint>
#	include <functional>
#	include <type_traits>
#	include <utility>
#	include "../concepts/no_throw_invocable.hpp"
#	include "../functors/memo_map.hpp"

namespace xieite::functors {
	template<typename Functor, typename... Arguments>
	requires(std::invocable<Functor, Arguments...>)
	[[nodiscard]] inline const std::invoke_result_t<Functor, Arguments...>& memoize(Functor&& functor, Arguments&&... arguments)
	noexcept(xieite::concepts::NoThrowInvocable<Functor, Arguments...>) {
		xieite::functors::MemoMap<std::invoke_result_t<Functor, Arguments...>, Arguments...>* current;
		if constexpr (std::is_pointer_v<Functor>) {
			static std::unordered_map<std::uintptr_t, xieite::functors::MemoMap<std::invoke_result_t<Functor, Arguments...>, Arguments...>> maps;
			current = &maps[reinterpret_cast<std::uintptr_t>(functor)];
		} else {
			static MemoMap<std::invoke_result_t<Functor, Arguments...>, Arguments...> map;
			current = &map;
		}
		return current->has(std::forward<Arguments>(arguments)...) ? current->get(std::forward<Arguments>(arguments)...) : current->set(std::invoke(std::forward<Functor>(functor), std::forward<Arguments>(arguments)...), std::forward<Arguments>(arguments)...);
	}
}

#endif
