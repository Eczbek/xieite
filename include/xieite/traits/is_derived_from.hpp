#ifndef XIEITE_HEADER_TRAITS_IS_DERIVED_FROM
#	define XIEITE_HEADER_TRAITS_IS_DERIVED_FROM

#	include <concepts>
#	include <type_traits>

namespace xieite::traits {
	template<typename Derived_, typename Base_>
	struct IsDerivedFrom
	: std::bool_constant<std::derived_from<Derived_, Base_>> {};
}

#endif
