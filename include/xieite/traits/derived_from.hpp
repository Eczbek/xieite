#ifndef XIEITE_HEADER_TRAITS_DERIVED_FROM
#	define XIEITE_HEADER_TRAITS_DERIVED_FROM

#	include <concepts>
#	include <type_traits>

namespace xieite::traits {
	template<typename Derived, typename Base>
	struct DerivedFrom
	: std::bool_constant<std::derived_from<Derived, Base>> {};
}

#endif
