#pragma once

#include "../concepts/no_throw_convertible_to_any.hpp"

namespace xieite::concepts {
	template<typename Source, typename... Targets>
	concept NoThrowConvertibleToNone = !xieite::concepts::NoThrowConvertibleToAny<Source, Targets...>;
}
