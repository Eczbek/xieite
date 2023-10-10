#pragma once

#include <type_traits>
#include "../concepts/same_as_any.hpp"

namespace xieite::traits {
	template<typename Source, typename... Targets>
	struct SameAsAny
	: std::bool_constant<xieite::concepts::SameAsAny<Source, Targets...>> {};
}
