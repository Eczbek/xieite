#pragma once

#include <cstddef>
#include <tuple>
#include "../meta/type_list.hpp"
#include "../fn/unroll.hpp"

namespace xieite {
	template<typename... Ts>
	[[nodiscard]] constexpr typename xieite::type_list<Ts...>::rev::template to<std::tuple> tuple_rev(const std::tuple<Ts...>& tuple) noexcept {
		return xieite::unroll<Ts...>([&tuple]<std::size_t... i> {
			return xieite::type_list<Ts...>::rev::template to<std::tuple>(std::get<sizeof...(Ts) - i - 1>(tuple)...);
		});
	}
}