#ifndef DETAIL_XTE_HEADER_META_META
#	define DETAIL_XTE_HEADER_META_META
#
#	include "../data/quote.hpp"
#	include "../data/string.hpp"
#	include "../data/string_view.hpp"
#	include "../preproc/feature.hpp"
#	include "../math/abs.hpp"
#	include "../math/stringify_number.hpp"
#	include "../meta/type.hpp"
#	include "../trait/add_array.hpp"
#	include "../trait/add_unbounded_array.hpp"
#	include "../trait/is_char.hpp"
#	include "../util/numbers.hpp"
#	include <algorithm>
#	include <meta>
#	include <ranges>
#	include <vector>

namespace DETAIL_XTE::meta {
	template<typename>
	inline constexpr std::meta::info class_type_of;

	template<typename Class, typename T>
	inline constexpr std::meta::info class_type_of<T Class::*> = ^^Class;

	template<typename Class, typename T>
	inline constexpr std::meta::info class_type_of<T Class::*&> = ^^Class;

	template<typename Class, typename T>
	inline constexpr std::meta::info class_type_of<T Class::*&&> = ^^Class;

	template<typename>
	inline constexpr std::meta::info member_type_of;

	template<typename Class, typename T>
	inline constexpr std::meta::info member_type_of<T Class::*> = ^^T;

	template<typename Class, typename T>
	inline constexpr std::meta::info member_type_of<T Class::*&> = ^^T&;

	template<typename Class, typename T>
	inline constexpr std::meta::info member_type_of<T Class::*&&> = ^^T&&;
}

namespace xte::meta {
	[[nodiscard]] consteval std::meta::info type_of(std::meta::info info) noexcept(false) {
		auto raw = std::meta::dealias(info);
		return std::meta::is_type(raw) ? raw : std::meta::type_of(raw);
	}

	[[nodiscard]] consteval std::meta::info class_type_of(std::meta::info info) noexcept(false) {
		if (auto type = std::meta::extract<std::meta::info>(std::meta::substitute(^^DETAIL_XTE::meta::class_type_of, { info })); type != ^^::) {
			return type;
		}
		throw std::meta::exception("reflection does not represent member pointer type", info);
	};

	[[nodiscard]] consteval std::meta::info member_type_of(std::meta::info info) noexcept(false) {
		if (auto type = std::meta::extract<std::meta::info>(std::meta::substitute(^^DETAIL_XTE::meta::member_type_of, { info })); type != ^^::) {
			return type;
		}
		throw std::meta::exception("reflection does not represent member pointer type", info);
	};

	[[nodiscard]] consteval bool is_complete_class_type(std::meta::info info) noexcept {
		auto type = std::meta::dealias(info);
		return std::meta::is_type(type) && std::meta::is_class_type(type) && std::meta::is_complete_type(type);
	};

	[[nodiscard]] consteval std::vector<std::meta::info> members_of(std::meta::info info, std::meta::access_context ctx = std::meta::access_context::current()) noexcept(false) {
		if (xte::meta::is_complete_class_type(info)) {
			return std::meta::members_of(info, ctx);
		}
		return {};
	};

	[[nodiscard]] consteval std::vector<std::meta::info> nonstatic_data_members_of(std::meta::info info, std::meta::access_context ctx = std::meta::access_context::current()) noexcept(false) {
		if (xte::meta::is_complete_class_type(info)) {
			return std::meta::nonstatic_data_members_of(info, ctx);
		}
		return {};
	};

	[[nodiscard]] consteval std::vector<std::meta::info> bases_of(std::meta::info info, std::meta::access_context ctx = std::meta::access_context::current()) noexcept {
		if (xte::meta::is_complete_class_type(info)) {
			return std::meta::bases_of(info, ctx);
		}
		return {};
	};

	[[nodiscard]] consteval std::meta::info add_array(std::meta::info type, xte::uz size) noexcept(false) {
		return std::meta::dealias(std::meta::substitute(^^xte::add_array, { type, std::meta::reflect_constant(size) }));
	};

	[[nodiscard]] consteval std::meta::info add_unbounded_array(std::meta::info type) noexcept(false) {
		return std::meta::dealias(std::meta::substitute(^^xte::add_unbounded_array, { type }));
	};

	[[nodiscard]] consteval xte::string_view name_of(std::meta::info info) noexcept(false) {
		static constexpr unsigned int ctx_none = 0b0000;
		static constexpr unsigned int ctx_prefix = 0b0001;
		static constexpr unsigned int ctx_postfix = 0b0010;
		static constexpr unsigned int ctx_parent = 0b0100;
		static constexpr unsigned int ctx_func = 0b1000;
		return xte::string_view(std::define_static_string(([](this auto name_of, std::meta::info info, unsigned int ctx) -> xte::string {
			if (info == ^^::) {
				return "::";
			}
			xte::string parent_name;
			if (~ctx & ctx_parent) {
				auto parent = info;
				while (std::meta::has_parent(parent)) {
					parent = std::meta::parent_of(parent);
					if (parent == ^^::) {
						break;
					}
					parent_name = name_of(parent, ctx_parent) + "::" + parent_name;
				}
			}
			auto tmpl_args_of = [&](std::meta::info info) -> xte::string {
				xte::string arg_list;
				for (auto arg : std::meta::template_arguments_of(info)) {
					if (arg_list.size()) {
						arg_list += ", ";
					}
					arg_list += name_of(arg, ctx_none);
				}
				return "<" + arg_list + ">";
			};
			auto func_name_of = [&](std::meta::info info, unsigned int ctx) -> xte::string {
				xte::string name;
				if (std::meta::is_template(info)) {
					if (~ctx & ctx_parent) {
						name = "<...>";
					}
				} else {
					for (auto param : std::meta::parameters_of(info)) {
						if (name.size()) {
							name += ", ";
						}
						name += name_of(xte::meta::type_of(param), ctx_none);
					}
					if (std::meta::is_vararg_function(info)) {
						if (name.size()) {
							name += ", ";
						}
						name += "...";
					}
					name = "(" + name + ")";
					if (std::meta::has_template_arguments(info) && !std::meta::is_conversion_function(info)) {
						name = tmpl_args_of(info) + name;
					}
				}
				if (ctx & (ctx_parent | ctx_func)) {
					auto parent = std::meta::has_parent(info) ? std::meta::parent_of(info) : ^^::;
					if (std::meta::has_template_arguments(parent)) {
						parent = std::meta::template_of(parent);
					}
					if (std::meta::is_constructor(info) || std::meta::is_constructor_template(info)) {
						name = std::meta::identifier_of(parent) + name;
					} else if (std::meta::is_destructor(info)) {
						name = "~" + xte::string(std::meta::identifier_of(parent)) + name;
					} else if (std::meta::is_conversion_function(info)) {
						name = "operator " + name_of(std::meta::return_type_of(info), ctx_postfix) + name;
					} else if (std::meta::is_conversion_function_template(info)) {
						name = "operator " + name;
					} else if (std::meta::is_operator_function(info) || std::meta::is_operator_function_template(info)) {
						auto op = std::meta::operator_of(info);
						name = "operator" + ([&] -> xte::string {
							switch (op) {
								case std::meta::op_new:
								case std::meta::op_delete:
								case std::meta::op_array_new:
								case std::meta::op_array_delete:
								case std::meta::op_co_await:
									return " ";
								default:
									return "";
							}
						})() + std::meta::symbol_of(op) + name;
					} else if (auto named = std::meta::has_template_arguments(info) ? std::meta::template_of(info) : info; std::meta::is_literal_operator(info) || std::meta::is_literal_operator_template(info)) {
						name = "operator\"\"" + xte::string(std::meta::identifier_of(named)) + name;
					} else {
						name = std::meta::identifier_of(named) + name;
					}
					name = parent_name + name;
				}
				if (std::meta::is_const(info)) {
					name += " const";
				}
				if (std::meta::is_volatile(info)) {
					name += " volatile";
				}
				if (std::meta::is_lvalue_reference_qualified(info)) {
					name += " &";
				} else if (std::meta::is_rvalue_reference_qualified(info)) {
					name += " &&";
				}
				if ((~ctx & ctx_parent) && std::meta::is_noexcept(info)) {
					name += " noexcept";
				}
				if ((~ctx & ctx_parent) && !std::meta::is_template(info) && !std::meta::is_constructor(info) && !std::meta::is_destructor(info) && ((~ctx & ctx_func) || !std::meta::is_conversion_function(info))) {
					name = name_of(std::meta::return_type_of(info), ctx_none) + ((ctx & ctx_func) ? xte::string(" ") : "") + name;
				}
				return (ctx & ctx_prefix) ? ("(" + name + ")") : name;
			};
			if (std::meta::is_function(info) || std::meta::is_function_template(info)) {
				return func_name_of(info, ctx | ctx_func);
			}
			return parent_name + ([&] -> xte::string {
				if (std::meta::has_template_arguments(info)) {
					return name_of(std::meta::template_of(info), ctx | ctx_parent) + tmpl_args_of(info);
				}
				if (std::meta::is_template(info)) {
					auto name = xte::string(std::meta::identifier_of(info));
					return (ctx & ctx_parent) ? name : (name + "<...>");
				}
				if (std::meta::has_identifier(info)) {
					return xte::string(std::meta::identifier_of(info));
				}
				if (std::meta::is_namespace(info)) {
					return "<anonymous>";
				}
				if (std::meta::is_type(info)) {
					if (std::meta::is_lvalue_reference_type(info)) {
						return name_of(std::meta::remove_reference(info), ctx_prefix) + "&";
					}
					if (std::meta::is_rvalue_reference_type(info)) {
						return name_of(std::meta::remove_reference(info), ctx_prefix) + "&&";
					}
					if (std::meta::is_unbounded_array_type(info)) {
						xte::string name = name_of(std::meta::remove_extent(info), ctx | ctx_prefix) + "[]";
						return (ctx & ctx_prefix) ? ("(" + name + ")") : name;
					}
					if (std::meta::is_array_type(info)) {
						xte::string name = name_of(std::meta::remove_extent(info), ctx | ctx_prefix) + "[" + name_of(std::meta::reflect_constant(std::meta::extent(info)), ctx_none) + "]";
						return (ctx & ctx_prefix) ? ("(" + name + ")") : name;
					}
					if (std::meta::is_const_type(info)) {
						return "const " + name_of(std::meta::remove_const(info), ctx | ctx_postfix);
					}
					if (std::meta::is_volatile_type(info)) {
						return "volatile " + name_of(std::meta::remove_volatile(info), ctx | ctx_postfix);
					}
					if (std::meta::is_pointer_type(info)) {
						xte::string name = name_of(std::meta::remove_pointer(info), ctx | ctx_prefix) + "*";
						return (ctx & ctx_postfix) ? ("(" + name + ")") : name;
					}
					if (std::meta::is_function_type(info)) {
						return func_name_of(info, ctx);
					}
					if (std::meta::is_member_function_pointer_type(info)) {
						return "(" + func_name_of(xte::meta::member_type_of(info), ctx) + ") " + name_of(xte::meta::class_type_of(info), ctx) + "::*";
					}
					if (info == ^^void) {
						return "void";
					}
					if (info == ^^bool) {
						return "bool";
					}
					if (info == ^^char) {
						return "char";
					}
					if (info == ^^unsigned char) {
						return "unsigned char";
					}
					if (info == ^^signed char) {
						return "signed char";
					}
					if (info == ^^wchar_t) {
						return "wchar_t";
					}
					if (info == ^^char8_t) {
						return "char8_t";
					}
					if (info == ^^char16_t) {
						return "char16_t";
					}
					if (info == ^^char32_t) {
						return "char32_t";
					}
					if (info == ^^unsigned short) {
						return "unsigned short";
					}
					if (info == ^^short) {
						return "short";
					}
					if (info == ^^unsigned int) {
						return "unsigned int";
					}
					if (info == ^^int) {
						return "int";
					}
					if (info == ^^unsigned long) {
						return "unsigned long";
					}
					if (info == ^^long) {
						return "long";
					}
					if (info == ^^unsigned long long) {
						return "unsigned long long";
					}
					if (info == ^^long long) {
						return "long long";
					}
#	ifdef __SIZEOF_INT128__
					if (info == std::meta::dealias(^^xte::u128)) {
						return "unsigned __int128";
					}
					if (info == std::meta::dealias(^^xte::i128)) {
						return "__int128";
					}
#	endif
					if (info == ^^float) {
						return "float";
					}
					if (info == ^^double) {
						return "double";
					}
					if (info == ^^long double) {
						return "long double";
					}
#	ifdef __STDCPP_FLOAT16_T__
					if (info == ^^decltype(0.0f16)) {
						return "std::float16_t";
					}
#	endif
#	ifdef __STDCPP_FLOAT32_T__
					if (info == ^^decltype(0.0f32)) {
						return "std::float32_t";
					}
#	endif
#	ifdef __STDCPP_FLOAT64_T__
					if (info == ^^decltype(0.0f64)) {
						return "std::float64_t";
					}
#	endif
#	ifdef __STDCPP_FLOAT128_T__
					if (info == ^^decltype(0.0f128)) {
						return "std::float128_t";
					}
#	endif
#	ifdef __STDCPP_BFLOAT16_T__
					if (info == ^^decltype(0.0bf16)) {
						return "std::bfloat16_t";
					}
#	endif
					if (info == ^^decltype(nullptr)) {
						return "std::nullptr_t";
					}
					if (info == ^^decltype(^^::)) {
						return "std::meta::info";
					}
					return (std::meta::is_class_type(info) && std::ranges::all_of(
						std::meta::members_of(info, std::meta::access_context::unchecked()),
						[](std::meta::info member) {
							return std::meta::is_nonstatic_data_member(member)
								|| ((std::meta::is_operator_function(member) || std::meta::is_operator_function_template(member))
									&& (std::meta::operator_of(member) == std::meta::op_parentheses));
						}
					)) ? xte::string("<lambda>") : "<unnamed>";
				}
				if (std::meta::is_value(info) || std::meta::is_object(info)) {
					return std::meta::extract<xte::type<xte::string()>*>(std::meta::substitute(
						xte::meta::members_of(^^decltype([]<auto name_of, auto value, unsigned int ctx> static -> xte::string {
							static constexpr auto type = std::meta::remove_cv(std::meta::type_of(std::meta::reflect_constant(value)));
							if constexpr (type == ^^bool) {
								return value ? "true" : "false";
							} else if constexpr (xte::is_char<typename[:type:]>) {
								return xte::quote(value);
							} else if constexpr (xte::is_number<typename[:type:]>) {
								return xte::stringify_number(value);
							} else if constexpr (std::meta::is_pointer_type(type) || (type == ^^decltype(nullptr))) {
								return "nullptr";
							} else if constexpr (std::meta::is_reflection_type(type)) {
								xte::string name = "^^" + name_of(value, ctx_postfix);
								return (ctx & ctx_postfix) ? ("(" + name + ")") : name;
							}
							xte::string member_names;
							template for (constexpr auto member : std::define_static_array(xte::meta::nonstatic_data_members_of(type))) {
								if (member_names.size()) {
									member_names += ", ";
								}
								if constexpr (using member_type = [:std::meta::type_of(member):]; std::is_array_v<member_type>) {
									member_names += ([]<typename T, xte::uz n>(this auto name_of_array, const xte::type<T[n]>& array) -> xte::string {
										xte::string item_names;
										for (auto&& item : array) {
											if (item_names.size()) {
												item_names += ", ";
											}
											if constexpr (std::is_array_v<T>) {
												item_names += name_of_array(item);
											} else {
												item_names += name_of(std::meta::reflect_constant(item), ctx_none);
											}
										}
										return "[" + item_names + "]";
									})(value.[:member:]);
								} else {
									member_names += name_of(std::meta::reflect_constant(value.[:member:]), ctx_none);
								}
							}
							return name_of(type, ctx_prefix) + "{" + member_names + "}";
						}))[0],
						{ std::meta::reflect_constant(name_of), info, std::meta::reflect_constant(ctx) }
					))();
				}
				throw std::meta::exception("reflection does not represent a nameable entity", info);
			})();
		})(info, ctx_none)));
	}
}

namespace xte::literal::info {
	[[nodiscard]] consteval std::meta::info operator""_info(unsigned long long x) noexcept {
		return std::meta::reflect_constant(x);
	}

	[[nodiscard]] consteval std::meta::info operator""_info(long double x) noexcept {
		return std::meta::reflect_constant(x);
	}

	[[nodiscard]] consteval std::meta::info operator""_info(const char* string, xte::uz size) noexcept {
		return std::meta::reflect_constant_string(std::ranges::subrange(string, string + size));
	}
}

#endif
