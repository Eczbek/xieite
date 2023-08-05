#ifndef XIEITE_HEADER__CONCEPTS__IS_DERIVED_FROM_ALL_OF
#	define XIEITE_HEADER__CONCEPTS__IS_DERIVED_FROM_ALL_OF

#	include <concepts>
#	include <type_traits>

namespace xieite::traits {
	template<typename Derived, typename... Bases>
	struct IsDerivedFromAllOf
	: std::bool_constant<(std::derived_from<Derived, Bases> && ...)> {};
}

#endif
