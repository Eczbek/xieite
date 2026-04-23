#ifndef DETAIL_XTE_HEADER_META_REFL
#	define DETAIL_XTE_HEADER_META_REFL
#
#	include "../trait/add_array.hpp"
#	include "../trait/add_unbounded_array.hpp"
#	include "../util/lvalue.hpp"
#	include "../util/numbers.hpp"
#	include <algorithm>
#	include <meta>
#	include <ranges>
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

	template<auto func, std::meta::info... args>
	requires(std::meta::is_reflection_type(^^decltype(func))
		? std::meta::is_template(func) && std::meta::can_substitute(func, { args... })
		: std::meta::is_class_type(^^decltype(func))
			&& std::ranges::any_of(
				xte::refl::members_of(^^decltype(func)),
				[](std::meta::info member) {
					return std::meta::is_operator_function_template(member)
						&& (std::meta::operator_of(member) == std::meta::op_parentheses)
						&& std::meta::can_substitute(member, { args... }); }))
	constexpr std::meta::info subst = ([] {
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

	inline constexpr auto add_array = [](std::meta::info type, xte::uz size) static consteval noexcept -> std::meta::info {
		return std::meta::dealias(std::meta::substitute(^^xte::add_array, { type, std::meta::reflect_constant(size) }));
	};

	inline constexpr auto add_unbounded_array = [](std::meta::info type) static consteval noexcept -> std::meta::info {
		return std::meta::dealias(std::meta::substitute(^^xte::add_unbounded_array, { type }));
	};
}

namespace xte::literal::refl {
	[[nodiscard]] consteval std::meta::info operator""_refl(unsigned long long x) noexcept {
		return std::meta::reflect_constant(x);
	}

	[[nodiscard]] consteval std::meta::info operator""_refl(long double x) noexcept {
		return std::meta::reflect_constant(x);
	}

	[[nodiscard]] consteval std::meta::info operator""_refl(const char* string, xte::uz size) noexcept {
		return std::meta::reflect_constant_string(std::ranges::subrange(string, string + size));
	}
}

#endif
