#pragma once

#include <type_traits>
#include "../concepts/convertible_to_none.hpp"

namespace xieite::traits {
	template<typename Source, typename... Targets>
	struct ConvertibleToNone
	: std::bool_constant<xieite::concepts::ConvertibleToNone<Source, Targets...>> {};
}
