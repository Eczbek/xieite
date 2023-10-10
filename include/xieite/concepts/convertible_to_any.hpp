#pragma once

#include <concepts>

namespace xieite::concepts {
	template<typename Source, typename... Targets>
	concept ConvertibleToAny = (... || std::convertible_to<Source, Targets>);
}
