#pragma once

#include <cstddef>
#include <tuple>
#include "../fn/unroll.hpp"
#include "../meta/typl.hpp"

namespace x4 {
	template<typename... Ts>
	[[nodiscard]] constexpr typename x4::typl<Ts...>::reverse::template to<std::tuple> rvstup(const std::tuple<Ts...>& tuple) noexcept {
		return x4::unroll<Ts...>([&tuple]<std::size_t... i> {
			return x4::typl<Ts...>::reverse::template to<std::tuple>(std::get<sizeof...(Ts) - i - 1>(tuple)...);
		});
	}
}
