#pragma once

#include <cstddef>
#include <tuple>
#include "../fn/unroll.hpp"
#include "../meta/type_list.hpp"

namespace xieite {
	template<typename... Ts>
	[[nodiscard]] constexpr typename xieite::type_list<Ts...>::reverse::template to<std::tuple> reverse_tuple(const std::tuple<Ts...>& tuple) noexcept {
		return xieite::unroll<Ts...>([&tuple]<std::size_t... i> {
			return xieite::type_list<Ts...>::reverse::template to<std::tuple>(std::get<sizeof...(Ts) - i - 1>(tuple)...);
		});
	}
}
