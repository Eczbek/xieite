#pragma once

#include <concepts>

namespace xieite::concepts {
	template<typename Source, typename... Targets>
	concept SameAsAny = (... || std::same_as<Source, Targets>);
}
