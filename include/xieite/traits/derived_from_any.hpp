#pragma once

#include <type_traits>
#include "../concepts/derived_from_any.hpp"

namespace xieite::traits {
	template<typename Derived, typename... Bases>
	struct DerivedFromAny
	: std::bool_constant<xieite::concepts::DerivedFromAny<Derived, Bases...>> {};
}
