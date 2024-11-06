export module xieite:tuple_reverse;

import std;
import :unroll;
import :type_list;

export namespace xieite {
	template<typename... Ts>
	[[nodiscard]] constexpr typename xieite::type_list<Ts...>::reverse::template to<std::tuple> tuple_reverse(const std::tuple<Ts...>& tuple) noexcept {
		return xieite::unroll<Ts...>([&tuple]<std::size_t... i> {
			return xieite::type_list<Ts...>::reverse::template to<std::tuple>(std::get<sizeof...(Ts) - i - 1>(tuple)...);
		});
	}
}
