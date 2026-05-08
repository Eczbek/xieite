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
#	include "../trait/is_number_or_bool.hpp"
#	include "../util/cast.hpp"
#	include "../util/destroy.hpp"
#	include "../util/numbers.hpp"
#	include <exception>
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

		[[nodiscard]] explicit(false) constexpr data_type(DETAIL_XTE::eval::unsigned_type value = 0) noexcept
		: unsigned_value(value), tag(unsigned_tag) {}

		[[nodiscard]] explicit(false) constexpr data_type(DETAIL_XTE::eval::signed_type value) noexcept
		: signed_value(value), tag(unsigned_tag) {}

		[[nodiscard]] explicit(false) constexpr data_type(xte::big_int<> value) noexcept
		: big_value(xte::xvalue(value)), tag(big_tag) {}

		[[nodiscard]] explicit(false) constexpr data_type(DETAIL_XTE::eval::float_type value) noexcept
		: float_value(value), tag(float_tag) {}

		[[nodiscard]] explicit(false) constexpr data_type(bool value) noexcept
		: bool_value(value), tag(bool_tag) {}

		[[nodiscard]] constexpr data_type(const DETAIL_XTE::eval::data_type& other) noexcept(false) {
			switch (this->tag = other.tag) {
				case DETAIL_XTE::eval::data_type::unsigned_tag:
					this->unsigned_value = other.unsigned_value;
					break;
				case DETAIL_XTE::eval::data_type::signed_tag:
					this->signed_value = other.signed_value;
					break;
				case DETAIL_XTE::eval::data_type::big_tag:
					this->big_value = other.big_value;
					break;
				case DETAIL_XTE::eval::data_type::float_tag:
					this->float_value = other.float_value;
					break;
				case DETAIL_XTE::eval::data_type::bool_tag:
					this->bool_value = other.bool_value;
					break;
			}
		}

		[[nodiscard]] constexpr data_type(DETAIL_XTE::eval::data_type&& other) noexcept(false) {
			switch (this->tag = other.tag) {
				case DETAIL_XTE::eval::data_type::unsigned_tag:
					this->unsigned_value = other.unsigned_value;
					break;
				case DETAIL_XTE::eval::data_type::signed_tag:
					this->signed_value = other.signed_value;
					break;
				case DETAIL_XTE::eval::data_type::big_tag:
					this->big_value = xte::xvalue(other).big_value;
					break;
				case DETAIL_XTE::eval::data_type::float_tag:
					this->float_value = other.float_value;
					break;
				case DETAIL_XTE::eval::data_type::bool_tag:
					this->bool_value = other.bool_value;
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
			switch (this->tag = other.tag) {
				case DETAIL_XTE::eval::data_type::unsigned_tag:
					this->unsigned_value = other.unsigned_value;
					break;
				case DETAIL_XTE::eval::data_type::signed_tag:
					this->signed_value = other.signed_value;
					break;
				case DETAIL_XTE::eval::data_type::big_tag:
					this->big_value = other.big_value;
					break;
				case DETAIL_XTE::eval::data_type::float_tag:
					this->float_value = other.float_value;
					break;
				case DETAIL_XTE::eval::data_type::bool_tag:
					this->bool_value = other.bool_value;
					break;
			}
			return *this;
		}

		constexpr DETAIL_XTE::eval::data_type& operator=(DETAIL_XTE::eval::data_type&& other) noexcept {
			switch (this->tag = other.tag) {
				case DETAIL_XTE::eval::data_type::unsigned_tag:
					this->unsigned_value = other.unsigned_value;
					break;
				case DETAIL_XTE::eval::data_type::signed_tag:
					this->signed_value = other.signed_value;
					break;
				case DETAIL_XTE::eval::data_type::big_tag:
					this->big_value = xte::xvalue(other).big_value;
					break;
				case DETAIL_XTE::eval::data_type::float_tag:
					this->float_value = other.float_value;
					break;
				case DETAIL_XTE::eval::data_type::bool_tag:
					this->bool_value = other.bool_value;
					break;
			}
			return *this;
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
};

namespace xte {
	template<xte::is_number_or_bool T>
	constexpr auto eval = [][[nodiscard]](xte::string_view input) static noexcept(false) -> T {
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
					throw DETAIL_XTE::eval::error(pos, input, "expression");
				}
				if (input[pos] == '(') {
					++pos;
					DETAIL_XTE::eval::data_type result = expression();
					whitespace();
					if ((pos >= input.size()) || (input[pos] != ')')) {
						throw DETAIL_XTE::eval::error(pos, input, "closing parenthesis");
					}
					++pos;
					return result;
				}
				xte::uz start = pos;
				DETAIL_XTE::eval::data_type result;
				auto [whole, index] = xte::parse_number<decltype(result.unsigned_value)>.with_index(input.slice(pos), 10, {}, false);
				pos += index;
				result.unsigned_value = whole;
				result.tag = DETAIL_XTE::eval::data_type::unsigned_tag;
				if (pos >= input.size()) {
					return result;
				}
				if ((input[pos] >= '0') && (input[pos] <= '9')) {
					auto [whole, index] = xte::big_int<>::parse.with_index(input.slice(start));
					pos = start + index;
					result.big_value = xte::xvalue(whole);
					result.tag = DETAIL_XTE::eval::data_type::big_tag;
				}
				if (input[pos] != '.') {
					if (!xte::number_format_config().exp.contains(input[pos])) {
						return result;
					}
					auto [fraction, index] = xte::parse_number<decltype(result.float_value)>.with_index(input.slice(start));
					pos = start + index;
					result.float_value = fraction;
					result.tag = DETAIL_XTE::eval::data_type::float_tag;
				} else {
					auto [fraction, index] = xte::parse_number<decltype(result.float_value)>.with_index(input.slice(pos));
					pos += index;
					result.float_value = static_cast<decltype(result.float_value)>(result) + fraction;
					result.tag = DETAIL_XTE::eval::data_type::float_tag;
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
				xte::string_view id = identifier();
				if (!id.size()) {
					return primary();
				}
				whitespace();
				if (input[pos] != '(') {
					throw DETAIL_XTE::eval::error(pos, input, "argument list");
				}
				++pos;
				xte::array<DETAIL_XTE::eval::data_type> args;
				while (true) {
					whitespace();
					if (pos >= input.size()) {
						throw DETAIL_XTE::eval::error(pos, input, "argument");
					}
					args.push(expression());
					if (input[pos] == ',') {
						++pos;
						continue;
					}
					if (input[pos] == ')') {
						++pos;
						break;
					}
					throw DETAIL_XTE::eval::error(pos, input, "end of argument list");
				}
				struct func {
					xte::string_view id;
					xte::uz args;
					[:^^DETAIL_XTE::eval::data_type(xte::array<DETAIL_XTE::eval::data_type>):]* ptr;
				};
				for (const func& func : xte::fixed_array {
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
								throw DETAIL_XTE::eval::error(pos, "expected at least one argument");
							}
						} else if (args.size() != func.args) {
							throw DETAIL_XTE::eval::error(pos, "expected " + xte::stringify_number(func.args) + " arguments, found " + xte::stringify_number(args.size()));
						}
						return func.ptr(xte::xvalue(args));
					}
				}
				throw DETAIL_XTE::eval::error(pos, xte::string("undefined function: ") + id);
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
					if (pos >= end) {
						break;
					}
					if (input[pos] == '+') {
						to_int = true;
					} else if (input[pos] == '-') {
						flip_sign ^= 1;
					} else if (input[pos] == '!') {
						to_int = false;
						result.bool_value = !static_cast<bool>(result);
						result.tag = DETAIL_XTE::eval::data_type::bool_tag;
					} else {
						break;
					}
				}
				pos = end;
				if (!flip_sign) {
					if ((result.tag == DETAIL_XTE::eval::data_type::bool_tag) && to_int) {
						result.unsigned_value = result.bool_value;
						result.tag = DETAIL_XTE::eval::data_type::unsigned_tag;
					}
					return result;
				}
				switch (result.tag) {
					case DETAIL_XTE::eval::data_type::unsigned_tag:
						if (result.unsigned_value <= xte::abs(xte::lowest<DETAIL_XTE::eval::signed_type>)) {
							result.signed_value = static_cast<DETAIL_XTE::eval::signed_type>(-result.unsigned_value);
							result.tag = DETAIL_XTE::eval::data_type::signed_tag;
							break;
						}
						[[fallthrough]];
					case DETAIL_XTE::eval::data_type::big_tag:
						result.big_value = -static_cast<xte::big_int<>>(xte::xvalue(result));
						result.tag = DETAIL_XTE::eval::data_type::big_tag;
						break;
					case DETAIL_XTE::eval::data_type::signed_tag:
					case DETAIL_XTE::eval::data_type::bool_tag:
						if (static_cast<DETAIL_XTE::eval::signed_type>(result) == xte::lowest<DETAIL_XTE::eval::signed_type>) {
							result.unsigned_value = xte::abs(static_cast<DETAIL_XTE::eval::signed_type>(result));
							result.tag = DETAIL_XTE::eval::data_type::unsigned_tag;
							break;
						}
						result.signed_value = -static_cast<DETAIL_XTE::eval::signed_type>(result);
						result.tag = DETAIL_XTE::eval::data_type::signed_tag;
						break;
					case DETAIL_XTE::eval::data_type::float_tag:
						result.float_value = -result.float_value;
						break;
				}
				return result;
			};
			auto factor = [&] -> DETAIL_XTE::eval::data_type {
				DETAIL_XTE::eval::data_type result = prefix();
				while (true) {
					whitespace();
					if (pos >= input.size()) {
						break;
					}
					if (input[pos] == '*') {
						++pos;
						DETAIL_XTE::eval::data_type multiplicand = prefix();
						do {
							if ((result.tag == DETAIL_XTE::eval::data_type::float_tag) || (multiplicand.tag == DETAIL_XTE::eval::data_type::float_tag)) {
								result.float_value = static_cast<DETAIL_XTE::eval::float_type>(result) * static_cast<DETAIL_XTE::eval::float_type>(multiplicand);
								result.tag = DETAIL_XTE::eval::data_type::float_tag;
								break;
							}
							if (((result.tag == DETAIL_XTE::eval::data_type::unsigned_tag) || (result.tag == DETAIL_XTE::eval::data_type::bool_tag)) && ((multiplicand.tag == DETAIL_XTE::eval::data_type::unsigned_tag) || (multiplicand.tag == DETAIL_XTE::eval::data_type::bool_tag))) {
								if (auto prod = xte::mul_checked(static_cast<DETAIL_XTE::eval::unsigned_type>(result), static_cast<DETAIL_XTE::eval::unsigned_type>(multiplicand))) {
									result.unsigned_value = *prod;
									result.tag = DETAIL_XTE::eval::data_type::unsigned_tag;
									break;
								}
							} else if (((result.tag == DETAIL_XTE::eval::data_type::signed_tag) || (result.tag == DETAIL_XTE::eval::data_type::bool_tag)) && ((multiplicand.tag == DETAIL_XTE::eval::data_type::signed_tag) || (multiplicand.tag == DETAIL_XTE::eval::data_type::bool_tag))) {
								if ((static_cast<DETAIL_XTE::eval::signed_type>(result) == xte::lowest<DETAIL_XTE::eval::signed_type>) && (static_cast<DETAIL_XTE::eval::signed_type>(multiplicand) == -1)) {
									result.unsigned_value = xte::abs(static_cast<DETAIL_XTE::eval::signed_type>(result));
									result.tag = DETAIL_XTE::eval::data_type::unsigned_tag;
									break;
								}
								if (auto prod = xte::mul_checked(static_cast<DETAIL_XTE::eval::signed_type>(result), static_cast<DETAIL_XTE::eval::signed_type>(multiplicand))) {
									result.signed_value = *prod;
									result.tag = DETAIL_XTE::eval::data_type::signed_tag;
									break;
								}
							}
							result.big_value = static_cast<xte::big_int<>>(xte::xvalue(result)) * static_cast<xte::big_int<>>(xte::xvalue(multiplicand));
							result.tag = DETAIL_XTE::eval::data_type::big_tag;
						} while (false);
					} else if (input[pos] == '/') {
						xte::uz tmp = pos;
						++pos;
						DETAIL_XTE::eval::data_type divisor = prefix();
						if (((divisor.tag == DETAIL_XTE::eval::data_type::float_tag) && xte::approx_equal(divisor.float_value, 0)) || !divisor) {
							throw DETAIL_XTE::eval::error(tmp, "division by zero");
						}
						do {
							if (divisor.tag == DETAIL_XTE::eval::data_type::bool_tag) {
								break;
							}
							if ((result.tag == DETAIL_XTE::eval::data_type::float_tag) || (divisor.tag == DETAIL_XTE::eval::data_type::float_tag)) {
								result.float_value = static_cast<DETAIL_XTE::eval::float_type>(result) * static_cast<DETAIL_XTE::eval::float_type>(divisor);
								result.tag = DETAIL_XTE::eval::data_type::float_tag;
								break;
							}
							if (((result.tag == DETAIL_XTE::eval::data_type::unsigned_tag) || (result.tag == DETAIL_XTE::eval::data_type::bool_tag)) && (divisor.tag == DETAIL_XTE::eval::data_type::unsigned_tag)) {
								result.unsigned_value = static_cast<DETAIL_XTE::eval::unsigned_type>(result) / static_cast<DETAIL_XTE::eval::unsigned_type>(divisor);
								result.tag = DETAIL_XTE::eval::data_type::unsigned_tag;
								break;
							}
							if (((result.tag == DETAIL_XTE::eval::data_type::signed_tag) || (result.tag == DETAIL_XTE::eval::data_type::bool_tag)) && (divisor.tag == DETAIL_XTE::eval::data_type::signed_tag)) {
								if ((static_cast<DETAIL_XTE::eval::signed_type>(result) == xte::lowest<DETAIL_XTE::eval::signed_type>) && (divisor.signed_value == -1)) {
									result.unsigned_value = xte::abs(static_cast<DETAIL_XTE::eval::signed_type>(result));
									result.tag = DETAIL_XTE::eval::data_type::unsigned_tag;
									break;
								}
								result.signed_value = static_cast<DETAIL_XTE::eval::signed_type>(result) / divisor.signed_value;
								result.tag = DETAIL_XTE::eval::data_type::signed_tag;
								break;
							}
							result.big_value = static_cast<xte::big_int<>>(xte::xvalue(result)) / static_cast<xte::big_int<>>(xte::xvalue(divisor));
							result.tag = DETAIL_XTE::eval::data_type::big_tag;
						} while (false);
					} else if (input[pos] == '%') {
						xte::uz tmp = pos;
						++pos;
						DETAIL_XTE::eval::data_type divisor = prefix();
						if (((divisor.tag == DETAIL_XTE::eval::data_type::float_tag) && xte::approx_equal(divisor.float_value, 0)) || !divisor) {
							throw DETAIL_XTE::eval::error(tmp, "remainder of division by zero");
						}
						if ((result.tag == DETAIL_XTE::eval::data_type::float_tag) || (divisor.tag == DETAIL_XTE::eval::data_type::float_tag)) {
							result.float_value = xte::rem(static_cast<DETAIL_XTE::eval::float_type>(result), static_cast<DETAIL_XTE::eval::float_type>(divisor));
							result.tag = DETAIL_XTE::eval::data_type::float_tag;
						} else if (divisor.tag == DETAIL_XTE::eval::data_type::bool_tag) {
							result.unsigned_value = 0;
							result.tag = DETAIL_XTE::eval::data_type::unsigned_tag;
						} else if (((result.tag == DETAIL_XTE::eval::data_type::unsigned_tag) || (result.tag == DETAIL_XTE::eval::data_type::bool_tag)) && (divisor.tag == DETAIL_XTE::eval::data_type::unsigned_tag)) {
							result.unsigned_value = static_cast<DETAIL_XTE::eval::unsigned_type>(result) % divisor.unsigned_value;
							result.tag = DETAIL_XTE::eval::data_type::unsigned_tag;
						} else if (((result.tag == DETAIL_XTE::eval::data_type::signed_tag) || (result.tag == DETAIL_XTE::eval::data_type::bool_tag)) && (divisor.tag == DETAIL_XTE::eval::data_type::signed_tag)) {
							result.signed_value = xte::rem(static_cast<DETAIL_XTE::eval::signed_type>(result), divisor.signed_value);
							result.tag = DETAIL_XTE::eval::data_type::signed_tag;
						} else {
							result.big_value = static_cast<xte::big_int<>>(xte::xvalue(result)) % static_cast<xte::big_int<>>(xte::xvalue(divisor));
							result.tag = DETAIL_XTE::eval::data_type::big_tag;
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
					if (pos >= input.size()) {
						break;
					}
					if (input[pos] == '+') {
						++pos;
						DETAIL_XTE::eval::data_type addend = factor();
						do {
							if ((result.tag == DETAIL_XTE::eval::data_type::float_tag) || (addend.tag == DETAIL_XTE::eval::data_type::float_tag)) {
								result.float_value = static_cast<DETAIL_XTE::eval::float_type>(result) + static_cast<DETAIL_XTE::eval::float_type>(addend);
								result.tag = DETAIL_XTE::eval::data_type::float_tag;
								break;
							}
							if (((result.tag == DETAIL_XTE::eval::data_type::unsigned_tag) || (result.tag == DETAIL_XTE::eval::data_type::bool_tag)) && ((addend.tag == DETAIL_XTE::eval::data_type::unsigned_tag) || (addend.tag == DETAIL_XTE::eval::data_type::bool_tag))) {
								if (auto sum = xte::add_checked(static_cast<DETAIL_XTE::eval::unsigned_type>(result), static_cast<DETAIL_XTE::eval::unsigned_type>(addend))) {
									result.unsigned_value = *sum;
									result.tag = DETAIL_XTE::eval::data_type::unsigned_tag;
									break;
								}
							} else if (((result.tag == DETAIL_XTE::eval::data_type::signed_tag) || (result.tag == DETAIL_XTE::eval::data_type::bool_tag)) && ((addend.tag == DETAIL_XTE::eval::data_type::signed_tag) || (addend.tag == DETAIL_XTE::eval::data_type::bool_tag))) {
								if ((static_cast<DETAIL_XTE::eval::signed_type>(result) >= 0) && (static_cast<DETAIL_XTE::eval::signed_type>(addend) >= 0)) {
									result.unsigned_value = static_cast<DETAIL_XTE::eval::unsigned_type>(xte::add(static_cast<DETAIL_XTE::eval::signed_type>(result), static_cast<DETAIL_XTE::eval::signed_type>(addend)));
									result.tag = DETAIL_XTE::eval::data_type::unsigned_tag;
									break;
								}
								if (auto sum = xte::add_checked(static_cast<DETAIL_XTE::eval::signed_type>(result), static_cast<DETAIL_XTE::eval::signed_type>(addend))) {
									result.signed_value = *sum;
									result.tag = DETAIL_XTE::eval::data_type::signed_tag;
									break;
								}
							}
							result.big_value = static_cast<xte::big_int<>>(xte::xvalue(result)) + static_cast<xte::big_int<>>(xte::xvalue(addend));
							result.tag = DETAIL_XTE::eval::data_type::big_tag;
						} while (false);
						continue;
					}
					if (input[pos] == '-') {
						++pos;
						DETAIL_XTE::eval::data_type subtrahend = factor();
						do {
							if ((result.tag == DETAIL_XTE::eval::data_type::float_tag) || (subtrahend.tag == DETAIL_XTE::eval::data_type::float_tag)) {
								result.float_value = static_cast<DETAIL_XTE::eval::float_type>(result) - static_cast<DETAIL_XTE::eval::float_type>(subtrahend);
								result.tag = DETAIL_XTE::eval::data_type::float_tag;
								break;
							}
							if (((result.tag == DETAIL_XTE::eval::data_type::unsigned_tag) || (result.tag == DETAIL_XTE::eval::data_type::bool_tag)) && ((subtrahend.tag == DETAIL_XTE::eval::data_type::unsigned_tag) || (subtrahend.tag == DETAIL_XTE::eval::data_type::bool_tag))) {
								if (auto sum = xte::sub_checked(static_cast<DETAIL_XTE::eval::unsigned_type>(result), static_cast<DETAIL_XTE::eval::unsigned_type>(subtrahend))) {
									result.unsigned_value = *sum;
									result.tag = DETAIL_XTE::eval::data_type::unsigned_tag;
									break;
								}
							} else if (((result.tag == DETAIL_XTE::eval::data_type::signed_tag) || (result.tag == DETAIL_XTE::eval::data_type::bool_tag)) && ((subtrahend.tag == DETAIL_XTE::eval::data_type::signed_tag) || (subtrahend.tag == DETAIL_XTE::eval::data_type::bool_tag))) {
								if ((static_cast<DETAIL_XTE::eval::signed_type>(result) >= 0) && (static_cast<DETAIL_XTE::eval::signed_type>(subtrahend) < 0)) {
									result.unsigned_value = static_cast<DETAIL_XTE::eval::unsigned_type>(xte::sub(static_cast<DETAIL_XTE::eval::signed_type>(result), static_cast<DETAIL_XTE::eval::signed_type>(subtrahend)));
									result.tag = DETAIL_XTE::eval::data_type::unsigned_tag;
									break;
								}
								if (auto sum = xte::sub_checked(static_cast<DETAIL_XTE::eval::signed_type>(result), static_cast<DETAIL_XTE::eval::signed_type>(subtrahend))) {
									result.signed_value = *sum;
									result.tag = DETAIL_XTE::eval::data_type::signed_tag;
									break;
								}
							}
							result.big_value = static_cast<xte::big_int<>>(xte::xvalue(result)) - static_cast<xte::big_int<>>(xte::xvalue(subtrahend));
							result.tag = DETAIL_XTE::eval::data_type::big_tag;
						} while (false);
						continue;
					}
					break;
				}
				return result;
			};
			auto comparison = [&] -> DETAIL_XTE::eval::data_type {
				DETAIL_XTE::eval::data_type result = term();
				while (true) {
					whitespace();
					if (pos >= input.size()) {
						break;
					}
					if (input.slice(pos, 2) == "==") {
						pos += 2;
						DETAIL_XTE::eval::data_type comparand = term();
						do {
							if ((result.tag == DETAIL_XTE::eval::data_type::float_tag) || (comparand.tag == DETAIL_XTE::eval::data_type::float_tag)) {
								result.bool_value = xte::approx_equal(static_cast<DETAIL_XTE::eval::float_type>(result), static_cast<DETAIL_XTE::eval::float_type>(comparand));
								break;
							}
							if ((result.tag == DETAIL_XTE::eval::data_type::big_tag) || (comparand.tag == DETAIL_XTE::eval::data_type::big_tag)) {
								result.bool_value = static_cast<xte::big_int<>>(xte::xvalue(result)) == static_cast<xte::big_int<>>(xte::xvalue(comparand));
								break;
							}
							result.bool_value = ((result.tag == DETAIL_XTE::eval::data_type::signed_tag) && (comparand.tag == DETAIL_XTE::eval::data_type::signed_tag))
								? (result.signed_value == comparand.signed_value)
								: (((result.tag != DETAIL_XTE::eval::data_type::signed_tag) || (result.signed_value >= 0))
									&& ((comparand.tag != DETAIL_XTE::eval::data_type::signed_tag) || (comparand.signed_value >= 0))
									&& (static_cast<DETAIL_XTE::eval::unsigned_type>(result) == static_cast<DETAIL_XTE::eval::unsigned_type>(comparand)));
						} while (false);
						result.tag = DETAIL_XTE::eval::data_type::bool_tag;
						continue;
					}
					if (input.slice(pos, 2) == "!=") {
						pos += 2;
						DETAIL_XTE::eval::data_type comparand = term();
						do {
							if ((result.tag == DETAIL_XTE::eval::data_type::float_tag) || (comparand.tag == DETAIL_XTE::eval::data_type::float_tag)) {
								result.bool_value = !xte::approx_equal(static_cast<DETAIL_XTE::eval::float_type>(result), static_cast<DETAIL_XTE::eval::float_type>(comparand));
								break;
							}
							if ((result.tag == DETAIL_XTE::eval::data_type::big_tag) || (comparand.tag == DETAIL_XTE::eval::data_type::big_tag)) {
								result.bool_value = static_cast<xte::big_int<>>(xte::xvalue(result)) != static_cast<xte::big_int<>>(xte::xvalue(comparand));
								break;
							}
							result.bool_value = ((result.tag == DETAIL_XTE::eval::data_type::signed_tag) && (comparand.tag == DETAIL_XTE::eval::data_type::signed_tag))
								? (result.signed_value != comparand.signed_value)
								: (((result.tag == DETAIL_XTE::eval::data_type::signed_tag) && (result.signed_value < 0))
									|| ((comparand.tag == DETAIL_XTE::eval::data_type::signed_tag) && (comparand.signed_value < 0))
									|| (static_cast<DETAIL_XTE::eval::unsigned_type>(result) != static_cast<DETAIL_XTE::eval::unsigned_type>(comparand)));
						} while (false);
						result.tag = DETAIL_XTE::eval::data_type::bool_tag;
						continue;
					}
					if (input.slice(pos, 2) == ">=") {
						pos += 2;
						DETAIL_XTE::eval::data_type comparand = term();
						do {
							if ((result.tag == DETAIL_XTE::eval::data_type::float_tag) || (comparand.tag == DETAIL_XTE::eval::data_type::float_tag)) {
								result.bool_value = xte::approx_greater_equal(static_cast<DETAIL_XTE::eval::float_type>(result), static_cast<DETAIL_XTE::eval::float_type>(comparand));
								break;
							}
							if ((result.tag == DETAIL_XTE::eval::data_type::big_tag) || (comparand.tag == DETAIL_XTE::eval::data_type::big_tag)) {
								result.bool_value = static_cast<xte::big_int<>>(xte::xvalue(result)) >= static_cast<xte::big_int<>>(xte::xvalue(comparand));
								break;
							}
							result.bool_value = ((result.tag == DETAIL_XTE::eval::data_type::signed_tag) && (comparand.tag == DETAIL_XTE::eval::data_type::signed_tag))
								? (result.signed_value >= comparand.signed_value)
								: ((result.tag != DETAIL_XTE::eval::data_type::signed_tag) || (result.signed_value >= 0))
									? ((comparand.tag == DETAIL_XTE::eval::data_type::signed_tag) && (comparand.signed_value <= 0))
									: (static_cast<DETAIL_XTE::eval::unsigned_type>(result) >= static_cast<DETAIL_XTE::eval::unsigned_type>(comparand));
						} while (false);
						result.tag = DETAIL_XTE::eval::data_type::bool_tag;
						continue;
					}
					if (input.slice(pos, 2) == "<=") {
						pos += 2;
						DETAIL_XTE::eval::data_type comparand = term();
						do {
							if ((result.tag == DETAIL_XTE::eval::data_type::float_tag) || (comparand.tag == DETAIL_XTE::eval::data_type::float_tag)) {
								result.bool_value = xte::approx_less_equal(static_cast<DETAIL_XTE::eval::float_type>(result), static_cast<DETAIL_XTE::eval::float_type>(comparand));
								break;
							}
							if ((result.tag == DETAIL_XTE::eval::data_type::big_tag) || (comparand.tag == DETAIL_XTE::eval::data_type::big_tag)) {
								result.bool_value = static_cast<xte::big_int<>>(xte::xvalue(result)) <= static_cast<xte::big_int<>>(xte::xvalue(comparand));
								break;
							}
							result.bool_value = ((result.tag == DETAIL_XTE::eval::data_type::signed_tag) && (comparand.tag == DETAIL_XTE::eval::data_type::signed_tag))
								? (result.signed_value <= comparand.signed_value)
								: ((result.tag == DETAIL_XTE::eval::data_type::signed_tag) && (result.signed_value <= 0))
									? ((comparand.tag != DETAIL_XTE::eval::data_type::signed_tag) || (comparand.signed_value >= 0))
									: (static_cast<DETAIL_XTE::eval::unsigned_type>(result) <= static_cast<DETAIL_XTE::eval::unsigned_type>(comparand));
						} while (false);
						result.tag = DETAIL_XTE::eval::data_type::bool_tag;
						continue;
					}
					if (input[pos] == '>') {
						++pos;
						DETAIL_XTE::eval::data_type comparand = term();
						do {
							if ((result.tag == DETAIL_XTE::eval::data_type::float_tag) || (comparand.tag == DETAIL_XTE::eval::data_type::float_tag)) {
								result.bool_value = static_cast<DETAIL_XTE::eval::float_type>(result) > static_cast<DETAIL_XTE::eval::float_type>(comparand);
								break;
							}
							if ((result.tag == DETAIL_XTE::eval::data_type::big_tag) || (comparand.tag == DETAIL_XTE::eval::data_type::big_tag)) {
								result.bool_value = static_cast<xte::big_int<>>(xte::xvalue(result)) > static_cast<xte::big_int<>>(xte::xvalue(comparand));
								break;
							}
							result.bool_value = ((result.tag == DETAIL_XTE::eval::data_type::signed_tag) && (comparand.tag == DETAIL_XTE::eval::data_type::signed_tag))
								? (result.signed_value > comparand.signed_value)
								: ((result.tag != DETAIL_XTE::eval::data_type::signed_tag) || (result.signed_value >= 0))
									? ((comparand.tag == DETAIL_XTE::eval::data_type::signed_tag) && (comparand.signed_value < 0))
									: (static_cast<DETAIL_XTE::eval::unsigned_type>(result) > static_cast<DETAIL_XTE::eval::unsigned_type>(comparand));
						} while (false);
						result.tag = DETAIL_XTE::eval::data_type::bool_tag;
						continue;
					}
					if (input[pos] == '<') {
						++pos;
						DETAIL_XTE::eval::data_type comparand = term();
						do {
							if ((result.tag == DETAIL_XTE::eval::data_type::float_tag) || (comparand.tag == DETAIL_XTE::eval::data_type::float_tag)) {
								result.bool_value = static_cast<DETAIL_XTE::eval::float_type>(result) < static_cast<DETAIL_XTE::eval::float_type>(comparand);
								break;
							}
							if ((result.tag == DETAIL_XTE::eval::data_type::big_tag) || (comparand.tag == DETAIL_XTE::eval::data_type::big_tag)) {
								result.bool_value = static_cast<xte::big_int<>>(xte::xvalue(result)) < static_cast<xte::big_int<>>(xte::xvalue(comparand));
								break;
							}
							result.bool_value = ((result.tag == DETAIL_XTE::eval::data_type::signed_tag) && (comparand.tag == DETAIL_XTE::eval::data_type::signed_tag))
								? (result.signed_value <= comparand.signed_value)
								: ((result.tag == DETAIL_XTE::eval::data_type::signed_tag) && (result.signed_value < 0))
									? ((comparand.tag != DETAIL_XTE::eval::data_type::signed_tag) || (comparand.signed_value >= 0))
									: (static_cast<DETAIL_XTE::eval::unsigned_type>(result) <= static_cast<DETAIL_XTE::eval::unsigned_type>(comparand));
						} while (false);
						result.tag = DETAIL_XTE::eval::data_type::bool_tag;
						continue;
					}
					break;
				}
				return result;
			};
			return comparison();
		})();
		whitespace();
		if (pos < input.size()) {
			throw DETAIL_XTE::eval::error(pos, input, "end of expression");
		}
		return static_cast<T>(result);
	};
}

#endif
