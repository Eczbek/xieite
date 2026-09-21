#ifndef DETAIL_XTE_HEADER_ARITHMETIC
#	define DETAIL_XTE_HEADER_ARITHMETIC
#
#	include "./abs.hpp"
#	include "./assign.hpp"
#	include "./detect/feature.hpp"
#	include "./func/unfold.hpp"
#	include "./limits.hpp"
#	include "./make.hpp"
#	include "./math/float.hpp"
#	include "./math/sign.hpp"
#	include "./meta/end.hpp"
#	include "./opt.hpp"
#	include "./trait/is_arithmetic.hpp"
#	include "./trait/is_float.hpp"
#	include "./trait/is_signed_int.hpp"
#	include "./trait/try_unsigned.hpp"
#	include <cmath>
#	include <type_traits>

namespace xte {
	[[nodiscard]] constexpr auto add(xte::is_arithmetic auto augend, xte::is_arithmetic auto... addends) noexcept {
		using common_type = std::common_type_t<decltype(augend), decltype(addends)...>;
		using unsigned_type = xte::try_unsigned<common_type>;
		return static_cast<common_type>((xte::make<unsigned_type>(augend) + ... + xte::make<unsigned_type>(addends)));
	}

	[[nodiscard]] constexpr auto sub(xte::is_arithmetic auto minuend, xte::is_arithmetic auto... subtrahends) noexcept {
		using common_type = std::common_type_t<decltype(minuend), decltype(subtrahends)...>;
		using unsigned_type = xte::try_unsigned<common_type>;
		return static_cast<common_type>((xte::make<unsigned_type>(minuend) - ... - xte::make<unsigned_type>(subtrahends)));
	}

	[[nodiscard]] constexpr auto mul(xte::is_arithmetic auto first, xte::is_arithmetic auto... rest) noexcept {
		using common_type = std::common_type_t<decltype(first), decltype(rest)...>;
		using unsigned_type = xte::try_unsigned<common_type>;
		return static_cast<common_type>((xte::make<unsigned_type>(first) * ... * xte::make<unsigned_type>(rest)));
	}

	[[nodiscard]] constexpr auto div(xte::is_arithmetic auto dividend, xte::is_arithmetic auto... divisors) noexcept {
		using common_type = std::common_type_t<decltype(dividend), decltype(divisors)...>;
		using unsigned_type = xte::try_unsigned<common_type>;
		return static_cast<common_type>(xte::make<unsigned_type>((xte::make<unsigned_type>(xte::abs(dividend)) / ... / xte::make<unsigned_type>(xte::abs(divisors))))
			* static_cast<unsigned_type>(xte::sign(dividend, divisors...)));
	}

	[[nodiscard]] constexpr auto rem(xte::is_arithmetic auto dividend, xte::is_arithmetic auto... divisors) noexcept {
		using common_type = std::common_type_t<decltype(dividend), decltype(divisors)...>;
		if constexpr (xte::is_float<common_type>) {
			auto result = xte::make<common_type>(dividend);
			return (..., (result = std::fmod(result, xte::make<common_type>(divisors))));
		} else {
			using unsigned_type = std::make_unsigned_t<common_type>;
			return static_cast<common_type>(static_cast<unsigned_type>((static_cast<unsigned_type>(xte::abs(dividend)) % ... % static_cast<unsigned_type>(xte::abs(divisors))))
				* static_cast<unsigned_type>(xte::sign(dividend)));
		}
	}

	[[nodiscard]] constexpr auto mod(xte::is_arithmetic auto dividend, xte::is_arithmetic auto... divisors) noexcept {
		using common_type = std::common_type_t<decltype(dividend), decltype(divisors)...>;
		auto result = xte::make<common_type>(dividend);
		return (..., (result = xte::rem(xte::rem(result, divisors) + xte::make<common_type>(divisors) * (xte::sign(result, divisors) < 0), divisors)));
	}

	template<xte::is_arithmetic base_type, xte::is_arithmetic exp_type, xte::end...,
		typename common_type = std::common_type_t<base_type, exp_type>>
	[[nodiscard]] constexpr common_type pow(base_type base, exp_type exp) noexcept {
		if constexpr (xte::is_float<common_type>) {
			return std::pow(xte::make<common_type>(base), xte::make<common_type>(exp));
		} else {
			if ((base == 1) || (exp == 1)) {
				return static_cast<common_type>(base);
			}
			if (base == -1) {
				return static_cast<common_type>((exp & 1) ? base : -base);
			}
			if (exp < 0) {
				return static_cast<common_type>(0);
			}
			if (!exp) {
				return static_cast<common_type>(1);
			}
			common_type power = 1;
			while (base && (exp > 1)) {
				if (exp & 1) {
					power = xte::mul(power, base);
					--exp;
				}
				base = xte::mul(base, base);
				exp >>= 1;
			}
			return power * static_cast<common_type>(base);
		}
	}

	[[nodiscard]] constexpr auto add_checked(xte::is_arithmetic auto augend, xte::is_arithmetic auto... addends) noexcept {
		using common_type = std::common_type_t<decltype(augend), decltype(addends)...>;
		auto sum = xte::make<common_type>(augend);
#	if XTE_HAS_BUILTIN(add_overflow)
		if constexpr (!xte::is_float<common_type>) {
			return (... || __builtin_add_overflow(sum, static_cast<common_type>(addends), &sum)) ? xte::null : xte::opt(sum);
		}
#	endif
		return (!xte::is_finite(augend) || ... || (!xte::is_finite(addends) || ((sum < 0) ? ((xte::lowest<common_type> - sum) > xte::make<common_type>(addends)) : ((xte::highest<common_type> - sum) < xte::make<common_type>(addends))) || (sum += xte::make<common_type>(addends), false))) ? xte::null : xte::opt(sum);
	}

	[[nodiscard]] constexpr auto sub_checked(xte::is_arithmetic auto minuend, xte::is_arithmetic auto... subtrahends) noexcept {
		using common_type = std::common_type_t<decltype(minuend), decltype(subtrahends)...>;
		auto diff = xte::make<common_type>(minuend);
#	if XTE_HAS_BUILTIN(sub_overflow)
		if constexpr (!xte::is_float<common_type>) {
			return (... || __builtin_sub_overflow(diff, static_cast<common_type>(subtrahends), &diff)) ? xte::null : xte::opt(diff);
		}
#	endif
		return (!xte::is_finite(diff) || ... || ((!xte::is_finite(subtrahends) && ((subtrahends < 0) ? ((xte::highest<common_type> + xte::make<common_type>(subtrahends)) < diff) : ((xte::lowest<common_type> + xte::make<common_type>(subtrahends)) < diff))) || (diff -= xte::make<common_type>(subtrahends), false))) ? xte::null : xte::opt(diff);
	}

	[[nodiscard]] constexpr auto mul_checked(xte::is_arithmetic auto first, xte::is_arithmetic auto... rest) noexcept {
		using common_type = std::common_type_t<decltype(first), decltype(rest)...>;
		auto prod = xte::make<common_type>(first);
#	if XTE_HAS_BUILTIN(mul_overflow)
		if constexpr (!xte::is_float<common_type>) {
			return (... || __builtin_mul_overflow(prod, static_cast<common_type>(rest), &prod)) ? xte::null : xte::opt(prod);
		}
#	endif
		bool overflow = false;
		(void)(!xte::is_finite(prod) || ... || (!prod || (overflow = !xte::is_finite(rest) || (xte::abs(xte::make<common_type>(rest)) > (xte::abs(((prod < 0) == (rest < 0)) ? xte::highest<common_type> : xte::lowest<common_type>) / xte::abs(prod)))) || !xte::assign(prod, prod * xte::make<common_type>(rest))));
		return overflow ? xte::null : xte::opt(prod);
	}

	[[nodiscard]] constexpr auto div_checked(xte::is_arithmetic auto dividend, xte::is_arithmetic auto... divisors) noexcept {
		if constexpr (using common_type = std::common_type_t<decltype(dividend), decltype(divisors)...>; xte::is_float<common_type>) {
			return (!xte::is_finite(dividend) || ... || (!xte::is_finite(divisors) || !divisors))
				? xte::null
				: xte::opt<common_type>((xte::make<common_type>(dividend) / ... / xte::make<common_type>(divisors)));
		} else {
			if ((... || !divisors)) {
				return xte::opt<common_type>(xte::null);
			}
			using unsigned_type = std::make_unsigned_t<common_type>;
			auto quot = static_cast<unsigned_type>((static_cast<unsigned_type>(xte::abs(dividend)) / ... / static_cast<unsigned_type>(xte::abs(divisors))));
			auto sign = xte::sign(dividend, divisors...);
			if constexpr (xte::is_signed_int<common_type>) {
				if ((sign > 0) && (quot == xte::abs(xte::lowest<common_type>))) {
					return xte::opt<common_type>(xte::null);
				}
			}
			return xte::opt<common_type>(static_cast<common_type>(quot * static_cast<unsigned_type>(sign)));
		}
	}

	[[nodiscard]] constexpr auto rem_checked(xte::is_arithmetic auto dividend, xte::is_arithmetic auto... divisors) noexcept {
		return (!xte::is_finite(dividend) || ... || (!xte::is_finite(divisors) || !divisors))
			? xte::null
			: xte::opt(xte::rem(dividend, divisors...));
	}

	[[nodiscard]] constexpr auto mod_checked(xte::is_arithmetic auto dividend, xte::is_arithmetic auto... divisors) noexcept {
		return (!xte::is_finite(dividend) || ... || (!xte::is_finite(dividend) || !divisors))
			? xte::null
			: xte::opt(xte::mod(dividend, divisors...));
	}

	template<xte::is_arithmetic base_type, xte::is_arithmetic exp_type, xte::end...,
		typename common_type = std::common_type_t<base_type, exp_type>>
	[[nodiscard]] constexpr xte::opt<common_type> pow_checked(base_type base, exp_type exp) noexcept {
		if constexpr (xte::is_float<common_type>) {
			return (xte::is_finite(base) && xte::is_finite(exp)) ? xte::opt(std::pow(xte::make<common_type>(base), xte::make<common_type>(exp))) : xte::null;
		} else {
			if ((base == 1) || (exp == 1)) {
				return xte::opt<common_type>(base);
			}
			if (base == -1) {
				return xte::opt<common_type>((exp & 1) ? base : -base);
			}
			if (exp < 0) {
				if (!base) {
					return xte::null;
				}
				return xte::opt<common_type>(0);
			}
			if (!exp) {
				return xte::opt<common_type>(1);
			}
			common_type power = 1;
			while (power && base && (exp > 1)) {
				if (exp & 1) {
					if (auto prod = xte::mul_checked(power, base)) {
						power = *prod;
					} else {
						return xte::null;
					}
					--exp;
				}
				if (auto prod = xte::mul_checked(base, base)) {
					base = *prod;
				} else {
					return xte::null;
				}
				exp >>= 1;
			}
			return xte::opt(power * static_cast<common_type>(base));
		}
	}
}

#endif
