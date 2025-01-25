#pragma once

#include <concepts>

namespace xieite {
	template<typename... Ts>
	concept is_same = (... && std::same_as<Ts...[0], Ts>);
}
