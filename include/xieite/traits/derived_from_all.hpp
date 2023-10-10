#pragma once

#include <type_traits>
#include "../concepts/derived_from_all.hpp"

namespace xieite::traits {
	template<typename Derived, typename... Bases>
	struct DerivedFromAll
	: std::bool_constant<xieite::concepts::DerivedFromAll<Derived, Bases...>> {};
}
