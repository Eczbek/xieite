#pragma once

#include <concepts>

namespace x4 {
	template<typename... Ts>
	concept issame = (... && std::same_as<Ts...[0], Ts>);
}
