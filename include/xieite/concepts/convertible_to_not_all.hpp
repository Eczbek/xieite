#pragma once

#include "../concepts/convertible_to_all.hpp"

namespace xieite::concepts {
	template<typename Source, typename... Targets>
	concept ConvertibleToNotAll = !xieite::concepts::ConvertibleToAll<Source, Targets...>;
}
