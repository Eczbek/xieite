#pragma once

#include <concepts>

namespace xieite::concepts {
	template<typename Source, typename... Targets>
	concept SameAsAll = (... || std::same_as<Source, Targets>);
}
