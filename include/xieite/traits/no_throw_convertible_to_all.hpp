#pragma once

#include <type_traits>
#include "../concepts/no_throw_convertible_to_all.hpp"

namespace xieite::traits {
	template<typename Source, typename... Targets>
	struct NoThrowConvertibleToAll
	: std::bool_constant<xieite::concepts::NoThrowConvertibleToAll<Source, Targets...>> {};
}
