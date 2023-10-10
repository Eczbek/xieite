#pragma once

#include <concepts>

namespace xieite::concepts {
	template<typename Source, typename... Targets>
	concept ConvertibleToAll = (... && std::convertible_to<Source, Targets>);
}
