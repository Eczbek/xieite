#pragma once

#include "../concepts/convertible_to_any.hpp"

namespace xieite::concepts {
	template<typename Source, typename... Targets>
	concept ConvertibleToNone = !xieite::concepts::ConvertibleToAny<Source, Targets...>;
}
