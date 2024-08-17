#ifndef XIEITE_HEADER_TYPES_COLLAPSE_REFERENCE
#	define XIEITE_HEADER_TYPES_COLLAPSE_REFERENCE

#	include <type_traits>

namespace xieite::types {
	template<typename Source, typename Target>
	using CollapseReference = std::conditional_t<std::is_lvalue_reference_v<Source>, Target&, std::conditional_t<std::is_rvalue_reference_v<Source>, Target&&, Target>>;
}

#endif
