#ifndef DETAIL_XTE_HEADER_META_REFL
#	define DETAIL_XTE_HEADER_META_REFL
#
#	include "../util/lvalue.hpp"
#	include <algorithm>
#	include <meta>
#	include <vector>

namespace xte::refl {
	inline constexpr auto is_complete_class_type = [][[nodiscard]](std::meta::info x) static consteval noexcept -> bool {
		auto dealiased = std::meta::dealias(x);
		return std::meta::is_class_type(dealiased) && std::meta::is_complete_type(dealiased);
	};

	inline constexpr auto members_of = [][[nodiscard]](std::meta::info x, std::meta::access_context ctx = std::meta::access_context::current()) static consteval noexcept -> std::vector<std::meta::info> {
		if (xte::refl::is_complete_class_type(x)) {
			return std::meta::members_of(x, ctx);
		}
		return {};
	};

	inline constexpr auto bases_of = [][[nodiscard]](std::meta::info x, std::meta::access_context ctx = std::meta::access_context::current()) static consteval noexcept -> std::vector<std::meta::info> {
		if (xte::refl::is_complete_class_type(x)) {
			return std::meta::bases_of(x, ctx);
		}
		return {};
	};

	inline constexpr auto type_of = [][[nodiscard]](std::meta::info x) static consteval noexcept -> std::meta::info {
		auto dealiased = std::meta::dealias(x);
		return std::meta::is_type(dealiased) ? dealiased : std::meta::type_of(x);
	};

	template<decltype(auto) func, std::meta::info... args>
	requires(([] {
		if constexpr (std::meta::is_reflection_type(^^decltype(func))) {
			return std::meta::is_template(func) && std::meta::can_substitute(func, { args... });
		} else {
			return std::meta::is_class_type(^^decltype(func))
				&& std::ranges::any_of(
					xte::refl::members_of(^^decltype(func)),
					[](std::meta::info member) {
						return std::meta::is_operator_function_template(member)
							&& (std::meta::operator_of(member) == std::meta::op_parentheses)
							&& std::meta::can_substitute(member, { args... }); });
		}
	})())
	constexpr std::meta::info subst = ([] static -> std::meta::info {
		if constexpr (std::meta::is_reflection_type(^^decltype(func))) {
			return std::meta::substitute(func, { args... });
		} else {
			return std::meta::substitute(
				*std::ranges::find_if(
					xte::lvalue(xte::refl::members_of(^^decltype(func))),
					[](std::meta::info member) {
						return std::meta::is_operator_function_template(member)
							&& (std::meta::operator_of(member) == std::meta::op_parentheses)
							&& std::meta::can_substitute(member, { args... }); }),
				{ args... });
		}
	})();
}

#endif
