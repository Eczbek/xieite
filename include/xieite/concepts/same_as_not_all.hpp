#pragma once

#include "../concepts/same_as_all.hpp"

namespace xieite::concepts {
	template<typename Source, typename... Targets>
	concept SameAsNotAll = !xieite::concepts::SameAsAll<Source, Targets...>;
}
