#ifndef XIEITE_HEADER_FUNCTORS_MEMOIZE
#	define XIEITE_HEADER_FUNCTORS_MEMOIZE

#	include <concepts>
#	include <cstdint>
#	include <functional>
#	include <tuple>
#	include <type_traits>
#	include <unordered_map>
#	include <utility>
#	include "../concepts/no_throw_invocable.hpp"
#	include "../containers/tuple_map.hpp"

namespace xieite::functors {
	template<typename Functor, typename... Arguments>
	requires(std::invocable<Functor, Arguments...>)
	[[nodiscard]] inline const std::invoke_result_t<Functor, Arguments...>& memoize(Functor&& functor, Arguments&&... arguments)
	noexcept(xieite::concepts::NoThrowInvocable<Functor, Arguments...>) {
		using Map = xieite::containers::TupleMap<std::unordered_map, std::tuple<Arguments...>, std::invoke_result_t<Functor, Arguments...>>;
		Map* current;
		if constexpr (std::is_pointer_v<Functor>) {
			static std::unordered_map<std::uintptr_t, Map> maps;
			current = &maps[reinterpret_cast<std::uintptr_t>(functor)];
		} else {
			static Map map;
			current = &map;
		}
		const auto keys = std::make_tuple(std::forward<Arguments>(arguments)...);
		if (!current->contains(keys)) {
			current->insert(keys, std::invoke(std::forward<Functor>(functor), std::forward<Arguments>(arguments)...));
		}
		return (*current)[keys];
	}
}

#endif
