#ifndef DETAIL_XTE_HEADER_TRAIT_IS_SPECIALIZATION_OF
#	define DETAIL_XTE_HEADER_TRAIT_IS_SPECIALIZATION_OF
#
#	include <meta>

namespace xte {
	template<typename T, std::meta::info tmpl>
	concept is_specialization_of = std::meta::has_template_arguments(^^T) && (std::meta::template_of(^^T) == tmpl);
}

#endif
