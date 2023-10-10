#pragma once

#include <concepts>

namespace xieite::concepts {
	template<typename Derived, typename... Bases>
	concept DerivedFromAny = (... || std::derived_from<Derived, Bases>);
}
