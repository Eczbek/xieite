#pragma once

#include <concepts>

namespace xieite {
	template<typename... Ts>
	concept is_same_any = (... || std::same_as<Ts...[0], Ts>);
}
