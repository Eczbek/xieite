#pragma once

#include <type_traits>
#include "../concepts/same_as_not_all.hpp"

namespace xieite::traits {
	template<typename Source, typename... Targets>
	struct SameAsNotAll
	: std::bool_constant<xieite::concepts::SameAsNotAll<Source, Targets...>> {};
}
