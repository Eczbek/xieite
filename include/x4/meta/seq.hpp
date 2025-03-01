#pragma once

#include "../trait/issame.hpp"

namespace x4 {
	template<auto... i>
	requires(x4::issame<decltype(i)...>)
	struct seq {};
}
