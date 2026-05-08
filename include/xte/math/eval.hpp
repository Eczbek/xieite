#ifndef DETAIL_XTE_HEADER_MATH_EVAL
#	define DETAIL_XTE_HEADER_MATH_EVAL
#
#	include "../data/array.hpp"
#	include "../data/fixed_array.hpp"
#	include "../data/string.hpp"
#	include "../data/string_view.hpp"
#	include "../data/uppercase.hpp"
#	include "../math/abs.hpp"
#	include "../math/add.hpp"
#	include "../math/add_checked.hpp"
#	include "../math/approx_equal.hpp"
#	include "../math/approx_greater_equal.hpp"
#	include "../math/approx_less_equal.hpp"
#	include "../math/big_int.hpp"
#	include "../math/ceil.hpp"
#	include "../math/floor.hpp"
#	include "../math/less.hpp"
#	include "../math/mod.hpp"
#	include "../math/mul_checked.hpp"
#	include "../math/number_format_config.hpp"
#	include "../math/parse_number.hpp"
#	include "../math/pow.hpp"
#	include "../math/rem.hpp"
#	include "../math/stringify_number.hpp"
#	include "../math/sub.hpp"
#	include "../math/sub_checked.hpp"
#	include "../preproc/feature.hpp"
#	include "../preproc/fwd.hpp"
#	include "../trait/is_instance_of.hpp"
#	include "../trait/is_number_or_bool.hpp"
#	include "../util/address.hpp"
#	include "../util/cast.hpp"
#	include "../util/construct.hpp"
#	include "../util/destroy.hpp"
#	include "../util/numbers.hpp"
#	include "../util/reconstruct.hpp"
#	include "../util/xvalue.hpp"
#	include <exception>
#	include <limits>
#	include <ranges>
#	include <utility>

namespace DETAIL_XTE::eval {
#	if XTE_FEATURE_INT_128
	using unsigned_type = xte::u128;
	using signed_type = xte::i128;
#	else
	using unsigned_type = unsigned long long;
	using signed_type = long long;
#	endif
#	if XTE_FEATURE_FLOAT_128
	using float_type = xte::f128;
#	else
	using float_type = long double;
#	endif

	struct data_type {
		union {
			DETAIL_XTE::eval::unsigned_type unsigned_value;
			DETAIL_XTE::eval::signed_type signed_value;
			DETAIL_XTE::eval::float_type float_value;
			xte::big_int<> big_value;
			bool bool_value;
		};
		enum {
			unsigned_tag,
			signed_tag,
			big_tag,
			float_tag,
			bool_tag
		} tag;

		[[nodiscard]] explicit(false) constexpr data_type(DETAIL_XTE::eval::unsigned_type value) noexcept
		: unsigned_value(value), tag(DETAIL_XTE::eval::data_type::unsigned_tag) {}

		[[nodiscard]] explicit(false) constexpr data_type(DETAIL_XTE::eval::signed_type value) noexcept
		: signed_value(value), tag(DETAIL_XTE::eval::data_type::signed_tag) {}

		[[nodiscard]] explicit(false) constexpr data_type(xte::big_int<> value) noexcept
		: big_value(xte::xvalue(value)), tag(DETAIL_XTE::eval::data_type::big_tag) {}

		[[nodiscard]] explicit(false) constexpr data_type(DETAIL_XTE::eval::float_type value) noexcept
		: float_value(value), tag(DETAIL_XTE::eval::data_type::float_tag) {}

		[[nodiscard]] explicit(false) constexpr data_type(bool value) noexcept
		: bool_value(value), tag(DETAIL_XTE::eval::data_type::bool_tag) {}

		[[nodiscard]] constexpr data_type(const DETAIL_XTE::eval::data_type& other) noexcept(false) {
			switch (this->tag = other.tag) {
				case DETAIL_XTE::eval::data_type::unsigned_tag:
					xte::construct(this->unsigned_value, other.unsigned_value);
					break;
				case DETAIL_XTE::eval::data_type::signed_tag:
					xte::construct(this->signed_value, other.signed_value);
					break;
				case DETAIL_XTE::eval::data_type::big_tag:
					xte::construct(this->big_value, other.big_value);
					break;
				case DETAIL_XTE::eval::data_type::float_tag:
					xte::construct(this->float_value, other.float_value);
					break;
				case DETAIL_XTE::eval::data_type::bool_tag:
					xte::construct(this->bool_value, other.bool_value);
					break;
			}
		}

		[[nodiscard]] constexpr data_type(DETAIL_XTE::eval::data_type&& other) noexcept {
			switch (this->tag = other.tag) {
				case DETAIL_XTE::eval::data_type::unsigned_tag:
					xte::construct(this->unsigned_value, other.unsigned_value);
					break;
				case DETAIL_XTE::eval::data_type::signed_tag:
					xte::construct(this->signed_value, other.signed_value);
					break;
				case DETAIL_XTE::eval::data_type::big_tag:
					xte::construct(this->big_value, xte::xvalue(other).big_value);
					break;
				case DETAIL_XTE::eval::data_type::float_tag:
					xte::construct(this->float_value, other.float_value);
					break;
				case DETAIL_XTE::eval::data_type::bool_tag:
					xte::construct(this->bool_value, other.bool_value);
					break;
			}
		}

		constexpr ~data_type() {
			switch (this->tag) {
				case DETAIL_XTE::eval::data_type::unsigned_tag:
					xte::destroy(this->unsigned_value);
					break;
				case DETAIL_XTE::eval::data_type::signed_tag:
					xte::destroy(this->signed_value);
					break;
				case DETAIL_XTE::eval::data_type::big_tag:
					xte::destroy(this->big_value);
					break;
				case DETAIL_XTE::eval::data_type::float_tag:
					xte::destroy(this->float_value);
					break;
				case DETAIL_XTE::eval::data_type::bool_tag:
					xte::destroy(this->bool_value);
					break;
			}
		}

		constexpr DETAIL_XTE::eval::data_type& operator=(const DETAIL_XTE::eval::data_type& other) noexcept(false) {
			return (this == xte::address(other)) ? *this : xte::reconstruct(*this, other);
		}

		constexpr DETAIL_XTE::eval::data_type& operator=(DETAIL_XTE::eval::data_type&& other) noexcept {
			return (this == xte::address(other)) ? *this : xte::reconstruct(*this, xte::xvalue(other));
		}

		constexpr DETAIL_XTE::eval::data_type& operator=(DETAIL_XTE::eval::unsigned_type value) noexcept {
			return xte::reconstruct(*this, value);
		}

		constexpr DETAIL_XTE::eval::data_type& operator=(DETAIL_XTE::eval::signed_type value) noexcept {
			return xte::reconstruct(*this, value);
		}

		constexpr DETAIL_XTE::eval::data_type& operator=(xte::big_int<> value) noexcept {
			return xte::reconstruct(*this, xte::xvalue(value));
		}

		constexpr DETAIL_XTE::eval::data_type& operator=(DETAIL_XTE::eval::float_type value) noexcept {
			return xte::reconstruct(*this, value);
		}

		constexpr DETAIL_XTE::eval::data_type& operator=(bool value) noexcept {
			return xte::reconstruct(*this, value);
		}

		template<typename T>
		[[nodiscard]] explicit constexpr operator T(this auto&& self) noexcept(false) {
			switch (self.tag) {
				case DETAIL_XTE::eval::data_type::unsigned_tag:
					return xte::cast<T>(self.unsigned_value);
				case DETAIL_XTE::eval::data_type::signed_tag:
					return xte::cast<T>(self.signed_value);
				case DETAIL_XTE::eval::data_type::big_tag:
					return static_cast<T>(XTE_FWD(self).big_value);
				case DETAIL_XTE::eval::data_type::float_tag:
					return xte::cast<T>(self.float_value);
				case DETAIL_XTE::eval::data_type::bool_tag:
					return static_cast<T>(+self.bool_value);
			}
			std::unreachable();
		}
	};
};

namespace xte {
	template<typename T>
	requires(xte::is_number_or_bool<T> || xte::is_instance_of<T, ^^xte::big_int>)
	constexpr auto eval = [][[nodiscard]](xte::string_view input) static noexcept(false) -> T {
		struct [[nodiscard]] error : std::exception {
			xte::string message;

			constexpr error(xte::uz pos, xte::string_view message) noexcept(false)
			: message("at " + xte::stringify_number(pos) + ": " + message) {}

			constexpr error(xte::uz pos, xte::string_view input, xte::string_view expected) noexcept(false)
			: message("at " + xte::stringify_number(pos) + ": expected " + expected + ((pos < input.size()) ? (xte::string(", found: ") + input[pos]) : "")) {}

			[[nodiscard]] virtual constexpr const char* what() const noexcept override {
				return this->message.data();
			}
		};
		xte::uz pos = 0;
		auto whitespace = [&] -> void {
			while ((pos < input.size()) && xte::string_view(" \t\n").contains(input[pos])) {
				++pos;
			}
		};
		DETAIL_XTE::eval::data_type result = ([&](this auto expression) -> DETAIL_XTE::eval::data_type {
			auto primary = [&] -> DETAIL_XTE::eval::data_type {
				whitespace();
				if (pos >= input.size()) {
					throw error(pos, input, "expression");
				}
				if (input[pos] == '(') {
					++pos;
					DETAIL_XTE::eval::data_type result = expression();
					whitespace();
					if ((pos >= input.size()) || (input[pos] != ')')) {
						throw error(pos, input, "closing parenthesis");
					}
					++pos;
					return result;
				}
				xte::uz start = pos;
				auto [whole, index] = xte::parse_number<DETAIL_XTE::eval::unsigned_type>.with_index(input.slice(pos), 10, {}, false);
				DETAIL_XTE::eval::data_type result = whole;
				pos += index;
				if (pos >= input.size()) {
					return result;
				}
				if ((input[pos] >= '0') && (input[pos] <= '9')) {
					auto [whole, index] = xte::big_int<>::parse.with_index(input.slice(start));
					result = xte::xvalue(whole);
					pos = start + index;
				}
				if (input[pos] != '.') {
					if (!xte::number_format_config().exp.contains(input[pos])) {
						return result;
					}
					auto [fraction, index] = xte::parse_number<DETAIL_XTE::eval::float_type>.with_index(input.slice(start));
					result = fraction;
					pos = start + index;
				} else {
					auto [fraction, index] = xte::parse_number<DETAIL_XTE::eval::float_type>.with_index(input.slice(pos));
					result = static_cast<DETAIL_XTE::eval::float_type>(result) + fraction;
					pos += index;
				}
				return result;
			};
			auto identifier = [&] -> xte::string_view {
				static constexpr auto is_word = [](char c) -> bool {
					return xte::string_view("ABCDEFGHIJKLMNOPQRSTUVWXYZ_").contains(xte::uppercase(c));
				};
				whitespace();
				if (!is_word(input[pos])) {
					return "";
				}
				xte::uz tmp = pos;
				while ((++pos < input.size()) && (((input[pos] >= '0') && (input[pos] <= '9')) || is_word(input[pos])));
				return input.slice(tmp, pos - tmp);
			};
			auto function = [&] -> DETAIL_XTE::eval::data_type {
				xte::uz start = pos;
				xte::string_view id = identifier();
				if (!id.size()) {
					return primary();
				}
				whitespace();
				struct var {
					xte::string_view id;
					[:^^DETAIL_XTE::eval::data_type():]* get;
				};
				static constexpr bool has_inf = std::numeric_limits<DETAIL_XTE::eval::float_type>::has_infinity;
				for (const var& var : xte::fixed_array {
					var("true", [] static -> DETAIL_XTE::eval::data_type { return true; }),
					var("false", [] static -> DETAIL_XTE::eval::data_type { return false; }),
					var("e", [] static -> DETAIL_XTE::eval::data_type { return std::numbers::e_v<DETAIL_XTE::eval::float_type>; }),
					var("pi", [] static -> DETAIL_XTE::eval::data_type { return std::numbers::pi_v<DETAIL_XTE::eval::float_type>; }),
					var("tau", [] static -> DETAIL_XTE::eval::data_type { return std::numbers::pi_v<DETAIL_XTE::eval::float_type> * 2; }),
					var("phi", [] static -> DETAIL_XTE::eval::data_type { return std::numbers::phi_v<DETAIL_XTE::eval::float_type>; }),
					has_inf ? var("inf", [] static -> DETAIL_XTE::eval::data_type {
						if constexpr (has_inf) {
							return std::numeric_limits<DETAIL_XTE::eval::float_type>::infinity();
						}
						std::unreachable();
					}) : var("", nullptr)
				}) {
					if (id == var.id) {
						return var.get();
					}
				}
				if (input.slice(pos, 1) != "(") {
					throw error(start, xte::string("undefined variable: ") + id);
				}
				++pos;
				xte::array<DETAIL_XTE::eval::data_type> args;
				while (true) {
					whitespace();
					args.push(expression());
					if (input.slice(pos, 1) == ",") {
						++pos;
						continue;
					}
					if (input.slice(pos, 1) == ")") {
						++pos;
						break;
					}
					throw error(pos, input, "end of argument list");
				}
				struct func {
					xte::string_view id;
					xte::uz args;
					[:^^DETAIL_XTE::eval::data_type(xte::array<DETAIL_XTE::eval::data_type>):]* ptr;
				};
				for (const func& func : xte::fixed_array {
					func("floor", 1, [](xte::array<DETAIL_XTE::eval::data_type> args) static -> DETAIL_XTE::eval::data_type {
						return (args[0].tag == DETAIL_XTE::eval::data_type::float_tag)
							? xte::floor(args[0].float_value)
							: args[0];
					}),
					func("ceil", 1, [](xte::array<DETAIL_XTE::eval::data_type> args) static -> DETAIL_XTE::eval::data_type {
						return (args[0].tag == DETAIL_XTE::eval::data_type::float_tag)
							? xte::ceil(args[0].float_value)
							: args[0];
					}),
					func("abs", 1, [](xte::array<DETAIL_XTE::eval::data_type> args) static -> DETAIL_XTE::eval::data_type {
						switch (args[0].tag) {
							case DETAIL_XTE::eval::data_type::unsigned_tag:
							case DETAIL_XTE::eval::data_type::bool_tag:
								return args[0];
							case DETAIL_XTE::eval::data_type::signed_tag:
								return xte::abs(args[0].signed_value);
							case DETAIL_XTE::eval::data_type::big_tag:
								return xte::xvalue(args)[0].big_value.abs();
							case DETAIL_XTE::eval::data_type::float_tag:
								return xte::abs(args[0].float_value);
						}
						std::unreachable();
					}),
					func("pow", 2, [](xte::array<DETAIL_XTE::eval::data_type> args) static -> DETAIL_XTE::eval::data_type {
						if ((args[0].tag == DETAIL_XTE::eval::data_type::float_tag) || (args[1].tag == DETAIL_XTE::eval::data_type::float_tag)) {
							return xte::pow(static_cast<DETAIL_XTE::eval::float_type>(args[0]), static_cast<DETAIL_XTE::eval::float_type>(args[1]));
						}
						return static_cast<xte::big_int<>>(xte::xvalue(args)[0]).pow(static_cast<xte::big_int<>>(xte::xvalue(args)[1]));
					})
				}) {
					if (id == func.id) {
						if (!func.args) {
							if (!args.size()) {
								throw error(pos, "expected at least one argument");
							}
						} else if (args.size() != func.args) {
							throw error(pos, "expected " + xte::stringify_number(func.args) + " arguments, found " + xte::stringify_number(args.size()));
						}
						return func.ptr(xte::xvalue(args));
					}
				}
				throw error(start, xte::string("undefined function: ") + id);
			};
			auto prefix = [&] -> DETAIL_XTE::eval::data_type {
				xte::uz start = pos;
				for (;; ++pos) {
					whitespace();
					if ((pos >= input.size()) || !xte::string_view("+-!").contains(input[pos])) {
						break;
					}
				}
				DETAIL_XTE::eval::data_type result = function();
				xte::uz end = pos;
				pos = start;
				bool flip_sign = false;
				bool to_int = false;
				for (;; ++pos) {
					whitespace();
					if (input.slice(pos, 1) == "+") {
						to_int = true;
					} else if (input.slice(pos, 1) == "-") {
						flip_sign ^= 1;
					} else if (input.slice(pos, 1) == "!") {
						to_int = false;
						result = !static_cast<bool>(result);
					} else {
						break;
					}
				}
				pos = end;
				if (!flip_sign) {
					if ((result.tag == DETAIL_XTE::eval::data_type::bool_tag) && to_int) {
						result = static_cast<DETAIL_XTE::eval::unsigned_type>(result.bool_value);
					}
					return result;
				}
				switch (result.tag) {
					case DETAIL_XTE::eval::data_type::unsigned_tag:
						if (result.unsigned_value <= xte::abs(xte::lowest<DETAIL_XTE::eval::signed_type>)) {
							result = static_cast<DETAIL_XTE::eval::signed_type>(-result.unsigned_value);
							break;
						}
						[[fallthrough]];
					case DETAIL_XTE::eval::data_type::big_tag:
						result = -static_cast<xte::big_int<>>(xte::xvalue(result));
						break;
					case DETAIL_XTE::eval::data_type::signed_tag:
					case DETAIL_XTE::eval::data_type::bool_tag:
						if (static_cast<DETAIL_XTE::eval::signed_type>(result) == xte::lowest<DETAIL_XTE::eval::signed_type>) {
							result = xte::abs(static_cast<DETAIL_XTE::eval::signed_type>(result));
							break;
						}
						result = -static_cast<DETAIL_XTE::eval::signed_type>(result);
						break;
					case DETAIL_XTE::eval::data_type::float_tag:
						result = -result.float_value;
						break;
				}
				return result;
			};
			auto factor = [&] -> DETAIL_XTE::eval::data_type {
				DETAIL_XTE::eval::data_type result = prefix();
				while (true) {
					whitespace();
					if (input.slice(pos, 1) == "*") {
						++pos;
						DETAIL_XTE::eval::data_type multiplicand = prefix();
						do {
							if ((result.tag == DETAIL_XTE::eval::data_type::float_tag) || (multiplicand.tag == DETAIL_XTE::eval::data_type::float_tag)) {
								result = static_cast<DETAIL_XTE::eval::float_type>(result) * static_cast<DETAIL_XTE::eval::float_type>(multiplicand);
								break;
							}
							if (((result.tag == DETAIL_XTE::eval::data_type::unsigned_tag) || (result.tag == DETAIL_XTE::eval::data_type::bool_tag)) && ((multiplicand.tag == DETAIL_XTE::eval::data_type::unsigned_tag) || (multiplicand.tag == DETAIL_XTE::eval::data_type::bool_tag))) {
								if (auto prod = xte::mul_checked(static_cast<DETAIL_XTE::eval::unsigned_type>(result), static_cast<DETAIL_XTE::eval::unsigned_type>(multiplicand))) {
									result = *prod;
									break;
								}
							} else if (((result.tag == DETAIL_XTE::eval::data_type::signed_tag) || (result.tag == DETAIL_XTE::eval::data_type::bool_tag)) && ((multiplicand.tag == DETAIL_XTE::eval::data_type::signed_tag) || (multiplicand.tag == DETAIL_XTE::eval::data_type::bool_tag))) {
								if ((static_cast<DETAIL_XTE::eval::signed_type>(result) == xte::lowest<DETAIL_XTE::eval::signed_type>) && (static_cast<DETAIL_XTE::eval::signed_type>(multiplicand) == -1)) {
									result = xte::abs(static_cast<DETAIL_XTE::eval::signed_type>(result));
									break;
								}
								if (auto prod = xte::mul_checked(static_cast<DETAIL_XTE::eval::signed_type>(result), static_cast<DETAIL_XTE::eval::signed_type>(multiplicand))) {
									result = *prod;
									break;
								}
							}
							result = static_cast<xte::big_int<>>(xte::xvalue(result)) * static_cast<xte::big_int<>>(xte::xvalue(multiplicand));
						} while (false);
					} else if (input.slice(pos, 1) == "/") {
						xte::uz tmp = pos;
						++pos;
						DETAIL_XTE::eval::data_type divisor = prefix();
						if (((divisor.tag == DETAIL_XTE::eval::data_type::float_tag) && xte::approx_equal(divisor.float_value, 0)) || !divisor) {
							throw error(tmp, "division by zero");
						}
						do {
							if (divisor.tag == DETAIL_XTE::eval::data_type::bool_tag) {
								break;
							}
							if ((result.tag == DETAIL_XTE::eval::data_type::float_tag) || (divisor.tag == DETAIL_XTE::eval::data_type::float_tag)) {
								result = static_cast<DETAIL_XTE::eval::float_type>(result) / static_cast<DETAIL_XTE::eval::float_type>(divisor);
								break;
							}
							if (((result.tag == DETAIL_XTE::eval::data_type::unsigned_tag) || (result.tag == DETAIL_XTE::eval::data_type::bool_tag)) && (divisor.tag == DETAIL_XTE::eval::data_type::unsigned_tag)) {
								result = static_cast<DETAIL_XTE::eval::unsigned_type>(result) / static_cast<DETAIL_XTE::eval::unsigned_type>(divisor);
								break;
							}
							if (((result.tag == DETAIL_XTE::eval::data_type::signed_tag) || (result.tag == DETAIL_XTE::eval::data_type::bool_tag)) && (divisor.tag == DETAIL_XTE::eval::data_type::signed_tag)) {
								if ((static_cast<DETAIL_XTE::eval::signed_type>(result) == xte::lowest<DETAIL_XTE::eval::signed_type>) && (divisor.signed_value == -1)) {
									result = xte::abs(static_cast<DETAIL_XTE::eval::signed_type>(result));
									break;
								}
								result = static_cast<DETAIL_XTE::eval::signed_type>(result) / divisor.signed_value;
								break;
							}
							result = static_cast<xte::big_int<>>(xte::xvalue(result)) / static_cast<xte::big_int<>>(xte::xvalue(divisor));
						} while (false);
					} else if (input.slice(pos, 1) == "%") {
						xte::uz tmp = pos;
						++pos;
						DETAIL_XTE::eval::data_type divisor = prefix();
						if (((divisor.tag == DETAIL_XTE::eval::data_type::float_tag) && xte::approx_equal(divisor.float_value, 0)) || !divisor) {
							throw error(tmp, "remainder of division by zero");
						}
						if ((result.tag == DETAIL_XTE::eval::data_type::float_tag) || (divisor.tag == DETAIL_XTE::eval::data_type::float_tag)) {
							result = xte::rem(static_cast<DETAIL_XTE::eval::float_type>(result), static_cast<DETAIL_XTE::eval::float_type>(divisor));
						} else if (divisor.tag == DETAIL_XTE::eval::data_type::bool_tag) {
							result = static_cast<DETAIL_XTE::eval::unsigned_type>(0);
						} else if (((result.tag == DETAIL_XTE::eval::data_type::unsigned_tag) || (result.tag == DETAIL_XTE::eval::data_type::bool_tag)) && (divisor.tag == DETAIL_XTE::eval::data_type::unsigned_tag)) {
							result = static_cast<DETAIL_XTE::eval::unsigned_type>(result) % divisor.unsigned_value;
						} else if (((result.tag == DETAIL_XTE::eval::data_type::signed_tag) || (result.tag == DETAIL_XTE::eval::data_type::bool_tag)) && (divisor.tag == DETAIL_XTE::eval::data_type::signed_tag)) {
							result = xte::rem(static_cast<DETAIL_XTE::eval::signed_type>(result), divisor.signed_value);
						} else {
							result = static_cast<xte::big_int<>>(xte::xvalue(result)) % static_cast<xte::big_int<>>(xte::xvalue(divisor));
						}
					} else {
						break;
					}
				}
				return result;
			};
			auto term = [&] -> DETAIL_XTE::eval::data_type {
				DETAIL_XTE::eval::data_type result = factor();
				while (true) {
					whitespace();
					if (input.slice(pos, 1) == "+") {
						++pos;
						DETAIL_XTE::eval::data_type addend = factor();
						do {
							if ((result.tag == DETAIL_XTE::eval::data_type::float_tag) || (addend.tag == DETAIL_XTE::eval::data_type::float_tag)) {
								result = static_cast<DETAIL_XTE::eval::float_type>(result) + static_cast<DETAIL_XTE::eval::float_type>(addend);
								break;
							}
							if (((result.tag == DETAIL_XTE::eval::data_type::unsigned_tag) || (result.tag == DETAIL_XTE::eval::data_type::bool_tag)) && ((addend.tag == DETAIL_XTE::eval::data_type::unsigned_tag) || (addend.tag == DETAIL_XTE::eval::data_type::bool_tag))) {
								if (auto sum = xte::add_checked(static_cast<DETAIL_XTE::eval::unsigned_type>(result), static_cast<DETAIL_XTE::eval::unsigned_type>(addend))) {
									result = *sum;
									break;
								}
							} else if (((result.tag == DETAIL_XTE::eval::data_type::signed_tag) || (result.tag == DETAIL_XTE::eval::data_type::bool_tag)) && ((addend.tag == DETAIL_XTE::eval::data_type::signed_tag) || (addend.tag == DETAIL_XTE::eval::data_type::bool_tag))) {
								if ((static_cast<DETAIL_XTE::eval::signed_type>(result) >= 0) && (static_cast<DETAIL_XTE::eval::signed_type>(addend) >= 0)) {
									result = static_cast<DETAIL_XTE::eval::unsigned_type>(xte::add(static_cast<DETAIL_XTE::eval::signed_type>(result), static_cast<DETAIL_XTE::eval::signed_type>(addend)));
									break;
								}
								if (auto sum = xte::add_checked(static_cast<DETAIL_XTE::eval::signed_type>(result), static_cast<DETAIL_XTE::eval::signed_type>(addend))) {
									result = *sum;
									break;
								}
							}
							result = static_cast<xte::big_int<>>(xte::xvalue(result)) + static_cast<xte::big_int<>>(xte::xvalue(addend));
						} while (false);
					} else if (input.slice(pos, 1) == "-") {
						++pos;
						DETAIL_XTE::eval::data_type subtrahend = factor();
						do {
							if ((result.tag == DETAIL_XTE::eval::data_type::float_tag) || (subtrahend.tag == DETAIL_XTE::eval::data_type::float_tag)) {
								result = static_cast<DETAIL_XTE::eval::float_type>(result) - static_cast<DETAIL_XTE::eval::float_type>(subtrahend);
								break;
							}
							if (((result.tag == DETAIL_XTE::eval::data_type::unsigned_tag) || (result.tag == DETAIL_XTE::eval::data_type::bool_tag)) && ((subtrahend.tag == DETAIL_XTE::eval::data_type::unsigned_tag) || (subtrahend.tag == DETAIL_XTE::eval::data_type::bool_tag))) {
								if (auto sum = xte::sub_checked(static_cast<DETAIL_XTE::eval::unsigned_type>(result), static_cast<DETAIL_XTE::eval::unsigned_type>(subtrahend))) {
									result = *sum;
									break;
								}
							} else if (((result.tag == DETAIL_XTE::eval::data_type::signed_tag) || (result.tag == DETAIL_XTE::eval::data_type::bool_tag)) && ((subtrahend.tag == DETAIL_XTE::eval::data_type::signed_tag) || (subtrahend.tag == DETAIL_XTE::eval::data_type::bool_tag))) {
								if ((static_cast<DETAIL_XTE::eval::signed_type>(result) >= 0) && (static_cast<DETAIL_XTE::eval::signed_type>(subtrahend) < 0)) {
									result = static_cast<DETAIL_XTE::eval::unsigned_type>(xte::sub(static_cast<DETAIL_XTE::eval::signed_type>(result), static_cast<DETAIL_XTE::eval::signed_type>(subtrahend)));
									break;
								}
								if (auto sum = xte::sub_checked(static_cast<DETAIL_XTE::eval::signed_type>(result), static_cast<DETAIL_XTE::eval::signed_type>(subtrahend))) {
									result = *sum;
									break;
								}
							}
							result = static_cast<xte::big_int<>>(xte::xvalue(result)) - static_cast<xte::big_int<>>(xte::xvalue(subtrahend));
						} while (false);
					} else {
						break;
					}
				}
				return result;
			};
			auto comparison = [&] -> DETAIL_XTE::eval::data_type {
				DETAIL_XTE::eval::data_type result = term();
				while (true) {
					whitespace();
					if (input.slice(pos, 2) == "==") {
						pos += 2;
						DETAIL_XTE::eval::data_type comparand = term();
						if ((result.tag == DETAIL_XTE::eval::data_type::float_tag) || (comparand.tag == DETAIL_XTE::eval::data_type::float_tag)) {
							result = xte::approx_equal(static_cast<DETAIL_XTE::eval::float_type>(result), static_cast<DETAIL_XTE::eval::float_type>(comparand));
						} else if ((result.tag == DETAIL_XTE::eval::data_type::big_tag) || (comparand.tag == DETAIL_XTE::eval::data_type::big_tag)) {
							result = static_cast<xte::big_int<>>(xte::xvalue(result)) == static_cast<xte::big_int<>>(xte::xvalue(comparand));
						} else {
							result = ((result.tag == DETAIL_XTE::eval::data_type::signed_tag) && (comparand.tag == DETAIL_XTE::eval::data_type::signed_tag))
								? (result.signed_value == comparand.signed_value)
								: (((result.tag != DETAIL_XTE::eval::data_type::signed_tag) || (result.signed_value >= 0))
									&& ((comparand.tag != DETAIL_XTE::eval::data_type::signed_tag) || (comparand.signed_value >= 0))
									&& (static_cast<DETAIL_XTE::eval::unsigned_type>(result) == static_cast<DETAIL_XTE::eval::unsigned_type>(comparand)));
						}
					} else if (input.slice(pos, 2) == "!=") {
						pos += 2;
						DETAIL_XTE::eval::data_type comparand = term();
						if ((result.tag == DETAIL_XTE::eval::data_type::float_tag) || (comparand.tag == DETAIL_XTE::eval::data_type::float_tag)) {
							result = !xte::approx_equal(static_cast<DETAIL_XTE::eval::float_type>(result), static_cast<DETAIL_XTE::eval::float_type>(comparand));
						} else if ((result.tag == DETAIL_XTE::eval::data_type::big_tag) || (comparand.tag == DETAIL_XTE::eval::data_type::big_tag)) {
							result = static_cast<xte::big_int<>>(xte::xvalue(result)) != static_cast<xte::big_int<>>(xte::xvalue(comparand));
						} else {
							result = ((result.tag == DETAIL_XTE::eval::data_type::signed_tag) && (comparand.tag == DETAIL_XTE::eval::data_type::signed_tag))
								? (result.signed_value != comparand.signed_value)
								: (((result.tag == DETAIL_XTE::eval::data_type::signed_tag) && (result.signed_value < 0))
									|| ((comparand.tag == DETAIL_XTE::eval::data_type::signed_tag) && (comparand.signed_value < 0))
									|| (static_cast<DETAIL_XTE::eval::unsigned_type>(result) != static_cast<DETAIL_XTE::eval::unsigned_type>(comparand)));
						}
					} else if (input.slice(pos, 2) == ">=") {
						pos += 2;
						DETAIL_XTE::eval::data_type comparand = term();
						if ((result.tag == DETAIL_XTE::eval::data_type::float_tag) || (comparand.tag == DETAIL_XTE::eval::data_type::float_tag)) {
							result = xte::approx_greater_equal(static_cast<DETAIL_XTE::eval::float_type>(result), static_cast<DETAIL_XTE::eval::float_type>(comparand));
						} else if ((result.tag == DETAIL_XTE::eval::data_type::big_tag) || (comparand.tag == DETAIL_XTE::eval::data_type::big_tag)) {
							result = static_cast<xte::big_int<>>(xte::xvalue(result)) >= static_cast<xte::big_int<>>(xte::xvalue(comparand));
						} else {
							result = ((result.tag == DETAIL_XTE::eval::data_type::signed_tag) && (comparand.tag == DETAIL_XTE::eval::data_type::signed_tag))
								? (result.signed_value >= comparand.signed_value)
								: ((result.tag != DETAIL_XTE::eval::data_type::signed_tag) || (result.signed_value >= 0))
									? ((comparand.tag == DETAIL_XTE::eval::data_type::signed_tag) && (comparand.signed_value <= 0))
									: (static_cast<DETAIL_XTE::eval::unsigned_type>(result) >= static_cast<DETAIL_XTE::eval::unsigned_type>(comparand));
						}
					} else if (input.slice(pos, 2) == "<=") {
						pos += 2;
						DETAIL_XTE::eval::data_type comparand = term();
						if ((result.tag == DETAIL_XTE::eval::data_type::float_tag) || (comparand.tag == DETAIL_XTE::eval::data_type::float_tag)) {
							result = xte::approx_less_equal(static_cast<DETAIL_XTE::eval::float_type>(result), static_cast<DETAIL_XTE::eval::float_type>(comparand));
						} else if ((result.tag == DETAIL_XTE::eval::data_type::big_tag) || (comparand.tag == DETAIL_XTE::eval::data_type::big_tag)) {
							result = static_cast<xte::big_int<>>(xte::xvalue(result)) <= static_cast<xte::big_int<>>(xte::xvalue(comparand));
						} else {
							result = ((result.tag == DETAIL_XTE::eval::data_type::signed_tag) && (comparand.tag == DETAIL_XTE::eval::data_type::signed_tag))
								? (result.signed_value <= comparand.signed_value)
								: ((result.tag == DETAIL_XTE::eval::data_type::signed_tag) && (result.signed_value <= 0))
									? ((comparand.tag != DETAIL_XTE::eval::data_type::signed_tag) || (comparand.signed_value >= 0))
									: (static_cast<DETAIL_XTE::eval::unsigned_type>(result) <= static_cast<DETAIL_XTE::eval::unsigned_type>(comparand));
						}
					} else if (input.slice(pos, 1) == ">") {
						++pos;
						DETAIL_XTE::eval::data_type comparand = term();
						if ((result.tag == DETAIL_XTE::eval::data_type::float_tag) || (comparand.tag == DETAIL_XTE::eval::data_type::float_tag)) {
							result = static_cast<DETAIL_XTE::eval::float_type>(result) > static_cast<DETAIL_XTE::eval::float_type>(comparand);
						} else if ((result.tag == DETAIL_XTE::eval::data_type::big_tag) || (comparand.tag == DETAIL_XTE::eval::data_type::big_tag)) {
							result = static_cast<xte::big_int<>>(xte::xvalue(result)) > static_cast<xte::big_int<>>(xte::xvalue(comparand));
						} else {
							result = ((result.tag == DETAIL_XTE::eval::data_type::signed_tag) && (comparand.tag == DETAIL_XTE::eval::data_type::signed_tag))
								? (result.signed_value > comparand.signed_value)
								: ((result.tag != DETAIL_XTE::eval::data_type::signed_tag) || (result.signed_value >= 0))
									? ((comparand.tag == DETAIL_XTE::eval::data_type::signed_tag) && (comparand.signed_value < 0))
									: (static_cast<DETAIL_XTE::eval::unsigned_type>(result) > static_cast<DETAIL_XTE::eval::unsigned_type>(comparand));
						}
					} else if (input.slice(pos, 1) == "<") {
						++pos;
						DETAIL_XTE::eval::data_type comparand = term();
						if ((result.tag == DETAIL_XTE::eval::data_type::float_tag) || (comparand.tag == DETAIL_XTE::eval::data_type::float_tag)) {
							result = static_cast<DETAIL_XTE::eval::float_type>(result) < static_cast<DETAIL_XTE::eval::float_type>(comparand);
						} else if ((result.tag == DETAIL_XTE::eval::data_type::big_tag) || (comparand.tag == DETAIL_XTE::eval::data_type::big_tag)) {
							result = static_cast<xte::big_int<>>(xte::xvalue(result)) < static_cast<xte::big_int<>>(xte::xvalue(comparand));
						} else {
							result = ((result.tag == DETAIL_XTE::eval::data_type::signed_tag) && (comparand.tag == DETAIL_XTE::eval::data_type::signed_tag))
								? (result.signed_value <= comparand.signed_value)
								: ((result.tag == DETAIL_XTE::eval::data_type::signed_tag) && (result.signed_value < 0))
									? ((comparand.tag != DETAIL_XTE::eval::data_type::signed_tag) || (comparand.signed_value >= 0))
									: (static_cast<DETAIL_XTE::eval::unsigned_type>(result) <= static_cast<DETAIL_XTE::eval::unsigned_type>(comparand));
						}
					} else {
						break;
					}
				}
				return result;
			};
			return comparison();
		})();
		whitespace();
		if (pos < input.size()) {
			throw error(pos, input, "end of expression");
		}
		return static_cast<T>(result);
	};
}

#endif
