#pragma once

#include "../trait/is_same.hpp"

namespace xieite {
	template<auto... i>
	requires(xieite::is_same<decltype(i)...>)
	struct seq {};
}
