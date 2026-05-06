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
#	include "../math/div.hpp"
#	include "../math/mod.hpp"
#	include "../math/mul.hpp"
#	include "../math/parse_number.hpp"
#	include "../math/pow.hpp"
#	include "../math/rem.hpp"
#	include "../math/stringify_number.hpp"
#	include "../math/sub.hpp"
#	include "../trait/is_number.hpp"
#	include "../util/numbers.hpp"
#	include <algorithm>
#	include <exception>

namespace xte {
	template<xte::is_number T>
	constexpr auto eval = [][[nodiscard]](xte::string_view input) static noexcept(false) -> T {
		struct [[nodiscard]] error : std::exception {
			xte::string message;

			constexpr error(xte::uz pos, xte::string_view message)
			: message("at " + xte::stringify_number(pos) + ": " + message) {}

			constexpr error(xte::uz pos, xte::string_view input, xte::string_view expected)
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
		T value = ([&](this auto expression) -> T {
			auto primary = [&] -> T {
				whitespace();
				if (pos >= input.size()) {
					throw error(pos, input, "expression");
				}
				if (input[pos] == '(') {
					++pos;
					T value = expression();
					whitespace();
					if ((pos >= input.size()) || (input[pos] != ')')) {
						throw error(pos, input, "closing parenthesis");
					}
					++pos;
					return value;
				}
				auto [value, size] = xte::parse_number<T>.with_index(input.slice(pos));
				if (!size) {
					throw error(pos, input, "number");
				}
				pos += size;
				return value;
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
			auto function = [&] -> T {
				xte::string_view id = identifier();
				if (!id.size()) {
					return primary();
				}
				whitespace();
				if (input[pos] != '(') {
					throw error(pos, input, "argument list");
				}
				++pos;
				xte::array<T> args;
				while (true) {
					whitespace();
					if (pos >= input.size()) {
						throw error(pos, input, "argument");
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
					throw error(pos, input, "end of argument list");
				}
				struct func {
					xte::string_view id;
					xte::uz args;
					[:^^T(const xte::array<T>&):]* ptr;
				};
				for (const func& func : xte::fixed_array {
					func("abs", 1, [](const xte::array<T>& args) { return static_cast<T>(xte::abs(args[0])); }),
					func("pow", 2, [](const xte::array<T>& args) { return xte::pow(args[0], args[1]); }),
					func("max", 0, [](const xte::array<T>& args) { return *std::ranges::max_element(args); }),
					func("min", 0, [](const xte::array<T>& args) { return *std::ranges::min_element(args); }),
					func("mod", 2, [](const xte::array<T>& args) { return xte::mod(args[0], args[1]); })
				}) {
					if (id == func.id) {
						if (!func.args) {
							if (!args.size()) {
								throw error(pos, "expected at least one argument");
							}
						} else if (args.size() != func.args) {
							throw error(pos, "expected " + xte::stringify_number(func.args) + " arguments, found " + xte::stringify_number(args.size()));
						}
						return func.ptr(args);
					}
				}
				throw error(pos, xte::string("undefined function: ") + id);
			};
			auto prefix = [&] -> T {
				T sign = 1;
				while (true) {
					whitespace();
					if (pos >= input.size()) {
						break;
					}
					if (input[pos] == '+') {
						++pos;
						continue;
					}
					if (input[pos] == '-') {
						++pos;
						sign = -sign;
						continue;
					}
					break;
				}
				return xte::mul(sign, function());
			};
			auto suffix = [&] -> T {
				return prefix();
			};
			auto factor = [&] -> T {
				T value = suffix();
				while (true) {
					whitespace();
					if (pos >= input.size()) {
						break;
					}
					if (input[pos] == '*') {
						++pos;
						value = xte::mul(value, suffix());
						continue;
					}
					if (input[pos] == '/') {
						xte::uz tmp = pos;
						++pos;
						T divisor = suffix();
						if (xte::approx_equal(divisor, 0)) {
							throw error(tmp, "division by zero");
						}
						value = xte::div(value, divisor);
					}
					if (input[pos] == '%') {
						xte::uz tmp = pos;
						++pos;
						T divisor = suffix();
						if (xte::approx_equal(divisor, 0)) {
							throw error(tmp, "remainder of division by zero");
						}
						value = xte::rem(value, divisor);
					}
					break;
				}
				return value;
			};
			auto term = [&] -> T {
				T value = factor();
				while (true) {
					whitespace();
					if (pos >= input.size()) {
						break;
					}
					if (input[pos] == '+') {
						++pos;
						value = xte::add(value, factor());
						continue;
					}
					if (input[pos] == '-') {
						++pos;
						value = xte::sub(value, factor());
						continue;
					}
					break;
				}
				return value;
			};
			auto comparison = [&] -> T {
				T value = term();
				while (true) {
					whitespace();
					if (pos >= input.size()) {
						break;
					}
					if (input.slice(pos, 2) == "==") {
						pos += 2;
						value = xte::approx_equal(value, term());
						continue;
					}
					if (input.slice(pos, 2) == "!=") {
						pos += 2;
						value = !xte::approx_equal(value, term());
						continue;
					}
					if (input.slice(pos, 2) == ">=") {
						pos += 2;
						value = value >= term();
						continue;
					}
					if (input.slice(pos, 2) == "<=") {
						pos += 2;
						value = value <= term();
						continue;
					}
					if (input[pos] == '>') {
						++pos;
						value = value > term();
						continue;
					}
					if (input[pos] == '<') {
						++pos;
						value = value < term();
						continue;
					}
					break;
				}
				return value;
			};
			return comparison();
		})();
		whitespace();
		if (pos < input.size()) {
			throw error(pos, input, "end of expression");
		}
		return value;
	};
}

#endif
