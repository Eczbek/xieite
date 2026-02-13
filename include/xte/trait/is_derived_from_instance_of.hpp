#ifndef DETAIL_XTE_HEADER_TRAIT_IS_DERIVED_FROM_INSTANCE_OF
#	define DETAIL_XTE_HEADER_TRAIT_IS_DERIVED_FROM_INSTANCE_OF
#
#	include "../meta/refl.hpp"
#	include <meta>
#	include <ranges>

namespace xte {
	template<typename T, std::meta::info tmpl>
	concept is_derived_from_instance_of =
		std::meta::is_class_type(std::meta::dealias(^^T))
		&& std::meta::is_class_template(tmpl)
		&& std::meta::any_of(
			xte::refl::bases_of(^^T) | std::views::transform(std::meta::type_of),
			[](std::meta::info base) {
				return std::meta::has_template_arguments(base)
					&& (std::meta::template_of(base) == tmpl);
			}
		);
}

#endif
