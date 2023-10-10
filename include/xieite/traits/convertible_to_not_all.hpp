#pragma once

#include <type_traits>
#include "../concepts/convertible_to_not_all.hpp"

namespace xieite::traits {
	template<typename Source, typename... Targets>
	struct ConvertibleToNotAll
	: std::bool_constant<xieite::concepts::ConvertibleToNotAll<Source, Targets...>> {};
}
