#pragma once

#include <type_traits>
#include "../concepts/no_throw_convertible_to_any.hpp"

namespace xieite::traits {
	template<typename Source, typename... Targets>
	struct NoThrowConvertibleToAny
	: std::bool_constant<xieite::concepts::NoThrowConvertibleToAny<Source, Targets...>> {};
}
