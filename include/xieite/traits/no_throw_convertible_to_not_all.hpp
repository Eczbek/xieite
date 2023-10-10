#pragma once

#include <type_traits>
#include "../concepts/no_throw_convertible_to_not_all.hpp"

namespace xieite::traits {
	template<typename Source, typename... Targets>
	struct NoThrowConvertibleToNotAll
	: std::bool_constant<xieite::concepts::NoThrowConvertibleToNotAll<Source, Targets...>> {};
}
