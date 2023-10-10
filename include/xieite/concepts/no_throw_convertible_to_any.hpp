#pragma once

#include "../concepts/no_throw_convertible_to.hpp"

namespace xieite::concepts {
	template<typename Source, typename... Targets>
	concept NoThrowConvertibleToAny = (... || xieite::concepts::NoThrowConvertibleTo<Source, Targets>);
}
