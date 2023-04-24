#pragma once

#include <xieite/concepts/NoThrowConvertibleTo.hpp>

namespace xieite::concepts {
	template<typename From, typename... Tos>
	concept NoThrowConvertibleToOneOf = (xieite::concepts::NoThrowConvertibleTo<From, Tos> || ...);
}
