#ifndef DETAIL_XTE_HEADER_META_REQ
#	define DETAIL_XTE_HEADER_META_REQ
#
#	include "../meta/meta.hpp"
#	include <meta>

namespace xte {
	template<typename T, auto... predicates>
	concept req = (... && (std::meta::is_reflection_type(^^decltype(predicates))
		? (std::meta::is_template(predicates) && std::meta::can_substitute(predicates, { ^^T }))
		: (std::meta::is_class_type(^^decltype(predicates)) && std::ranges::any_of(
			xte::meta::members_of(^^decltype(predicates)),
			[](std::meta::info member) {
				return std::meta::is_operator_function_template(member)
					&& (std::meta::operator_of(member) == std::meta::op_parentheses)
					&& std::meta::can_substitute(member, { ^^T });
			}
		))));
}

#endif

// TODO: Change parameter type back to `decltype(auto)`
// https://gcc.gnu.org/bugzilla/show_bug.cgi?id=124893
