#pragma once

#include <concepts>
#include <type_traits>

namespace xieite::traits {
	template<typename Derived, typename Base>
	struct DerivedFrom
	: std::bool_constant<std::derived_from<Derived, Base>> {};
}
