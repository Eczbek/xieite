#ifndef XIEITE_HEADER_TYPES_PLACEHOLDER
#	define XIEITE_HEADER_TYPES_PLACEHOLDER

#	include "../types/collapse_reference.hpp"

namespace xieite::types {
	struct Placeholder {
		template<typename... Arguments>
		constexpr Placeholder(Arguments&&...) noexcept {}

		template<typename Self, typename Type>
		constexpr operator xieite::types::CollapseReference<Type, Self>(this Self&&) noexcept;
	};
}

#endif
