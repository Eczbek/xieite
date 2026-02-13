#ifndef DETAIL_XTE_HEADER_TRAIT_IS_INSTANCE_OF
#	define DETAIL_XTE_HEADER_TRAIT_IS_INSTANCE_OF
#
#	include <meta>

namespace xte {
	template<typename T, std::meta::info tmpl>
	concept is_instance_of = std::meta::has_template_arguments(^^T) && (std::meta::template_of(^^T) == tmpl);
}

#endif
