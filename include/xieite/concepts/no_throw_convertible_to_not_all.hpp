#pragma once

#include "../concepts/no_throw_convertible_to_all.hpp"

namespace xieite::concepts {
	template<typename Source, typename... Targets>
	concept NoThrowConvertibleToNotAll = !xieite::concepts::NoThrowConvertibleToAll<Source, Targets...>;
}
