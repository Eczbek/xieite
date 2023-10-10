#pragma once

#include <type_traits>
#include "../concepts/no_throw_convertible_to_none.hpp"

namespace xieite::traits {
	template<typename Source, typename... Targets>
	struct NoThrowConvertibleToNone
	: std::bool_constant<xieite::concepts::NoThrowConvertibleToNone<Source, Targets...>> {};
}
