#pragma once

#include <type_traits>
#include "../concepts/derived_from_none.hpp"

namespace xieite::traits {
	template<typename Derived, typename... Bases>
	struct DerivedFromNone
	: std::bool_constant<xieite::concepts::DerivedFromNone<Derived, Bases...>> {};
}
