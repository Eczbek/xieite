#pragma once

#include "../concepts/same_as_any.hpp"

namespace xieite::concepts {
	template<typename Source, typename... Targets>
	concept SameAsNone = !xieite::concepts::SameAsAny<Source, Targets...>;
}
