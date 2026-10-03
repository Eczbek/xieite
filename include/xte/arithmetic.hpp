#ifndef DETAIL_XTE_HEADER_ARITHMETIC
#	define DETAIL_XTE_HEADER_ARITHMETIC
#
#	include "./abs.hpp"
#	include "./assign.hpp"
#	include "./detect/feature.hpp"
#	include "./func/unfold.hpp"
#	include "./fundamental_traits.hpp"
#	include "./limits.hpp"
#	include "./make.hpp"
#	include "./math/float.hpp"
#	include "./math/sign.hpp"
#	include "./opt.hpp"
#	include <cmath>
#	include <type_traits>

namespace xte {
	template<xte::is_arithmetic augend_type, xte::is_arithmetic... addend_types,
		typename common_type = std::common_type_t<augend_type, addend_types...>>
	[[nodiscard]] constexpr common_type add(augend_type augend, addend_types... addends) noexcept {
		using unsigned_type = xte::try_unsigned<common_type>;
		return static_cast<common_type>((xte::make<unsigned_type>(augend) + ... + xte::make<unsigned_type>(addends)));
	}

	template<xte::is_arithmetic minuend_type, xte::is_arithmetic... subtrahend_types,
		typename common_type = std::common_type_t<minuend_type, subtrahend_types...>>
	[[nodiscard]] constexpr common_type sub(minuend_type minuend, subtrahend_types... subtrahends) noexcept {
		using unsigned_type = xte::try_unsigned<common_type>;
		return static_cast<common_type>((xte::make<unsigned_type>(minuend) - ... - xte::make<unsigned_type>(subtrahends)));
	}

	template<xte::is_arithmetic multiplier_type, xte::is_arithmetic... multiplicand_types,
		typename common_type = std::common_type_t<multiplier_type, multiplicand_types...>>
	[[nodiscard]] constexpr common_type mul(multiplier_type multiplier, multiplicand_types... multiplicands) noexcept {
		using unsigned_type = xte::try_unsigned<common_type>;
		return static_cast<common_type>((xte::make<unsigned_type>(multiplier) * ... * xte::make<unsigned_type>(multiplicands)));
	}

	template<xte::is_arithmetic dividend_type, xte::is_arithmetic... divisor_types,
		typename common_type = std::common_type_t<dividend_type, divisor_types...>>
	[[nodiscard]] constexpr common_type div(dividend_type dividend, divisor_types... divisors) noexcept {
		using unsigned_type = xte::try_unsigned<common_type>;
		return static_cast<common_type>(xte::make<unsigned_type>((xte::make<unsigned_type>(xte::abs(dividend)) / ... / xte::make<unsigned_type>(xte::abs(divisors))))
			* static_cast<unsigned_type>(xte::sign(dividend, divisors...)));
	}

	template<xte::is_arithmetic dividend_type, xte::is_arithmetic... divisor_types,
		typename common_type = std::common_type_t<dividend_type, divisor_types...>>
	[[nodiscard]] constexpr common_type rem(dividend_type dividend, divisor_types... divisors) noexcept {
		if constexpr (xte::is_float<common_type>) {
			auto result = xte::make<common_type>(dividend);
			return (..., (result = std::fmod(result, xte::make<common_type>(divisors))));
		} else {
			using unsigned_type = std::make_unsigned_t<common_type>;
			return static_cast<common_type>(static_cast<unsigned_type>((static_cast<unsigned_type>(xte::abs(dividend)) % ... % static_cast<unsigned_type>(xte::abs(divisors))))
				* static_cast<unsigned_type>(xte::sign(dividend)));
		}
	}

	template<xte::is_arithmetic dividend_type, xte::is_arithmetic... divisor_types,
		typename common_type = std::common_type_t<dividend_type, divisor_types...>>
	[[nodiscard]] constexpr common_type mod(dividend_type dividend, divisor_types... divisors) noexcept {
		auto result = xte::make<common_type>(dividend);
		return (..., (result = xte::rem(xte::rem(result, divisors) + xte::make<common_type>(divisors) * (xte::sign(result, divisors) < 0), divisors)));
	}

	template<xte::is_arithmetic base_type, xte::is_arithmetic... exp_types,
		typename common_type = std::common_type_t<base_type, exp_types...>>
	[[nodiscard]] constexpr common_type pow(base_type base, exp_types... exps) noexcept {
		if constexpr (sizeof...(exps)) {
			return ([](this auto pow, auto base, auto exp, auto... exps) {
				common_type power = ([&] {
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
				})();
				if constexpr (sizeof...(exps)) {
					return pow(power, exps...);
				}
				return power;
			})(base, exps...);
		} else {
			return base;
		}
	}

	template<xte::is_arithmetic augend_type, xte::is_arithmetic... addend_types,
		typename common_type = std::common_type_t<augend_type, addend_types...>>
	[[nodiscard]] constexpr xte::opt<common_type> checked_add(augend_type augend, addend_types... addends) noexcept {
		auto sum = xte::make<common_type>(augend);
#	if XTE_HAS_BUILTIN(add_overflow)
		if constexpr (!xte::is_float<common_type>) {
			return (... || __builtin_add_overflow(sum, static_cast<common_type>(addends), &sum)) ? xte::null : xte::opt(sum);
		}
#	endif
		return (!xte::is_finite(augend) || ... || (!xte::is_finite(addends) || ((sum < 0) ? ((xte::lowest<common_type> - sum) > xte::make<common_type>(addends)) : ((xte::highest<common_type> - sum) < xte::make<common_type>(addends))) || (sum += xte::make<common_type>(addends), false))) ? xte::null : xte::opt(sum);
	}

	template<xte::is_arithmetic minuend_type, xte::is_arithmetic... subtrahend_types,
		typename common_type = std::common_type_t<minuend_type, subtrahend_types...>>
	[[nodiscard]] constexpr xte::opt<common_type> checked_sub(minuend_type minuend, subtrahend_types... subtrahends) noexcept {
		auto diff = xte::make<common_type>(minuend);
#	if XTE_HAS_BUILTIN(sub_overflow)
		if constexpr (!xte::is_float<common_type>) {
			return (... || __builtin_sub_overflow(diff, static_cast<common_type>(subtrahends), &diff)) ? xte::null : xte::opt(diff);
		}
#	endif
		return (!xte::is_finite(diff) || ... || ((!xte::is_finite(subtrahends) && ((subtrahends < 0) ? ((xte::highest<common_type> + xte::make<common_type>(subtrahends)) < diff) : ((xte::lowest<common_type> + xte::make<common_type>(subtrahends)) < diff))) || (diff -= xte::make<common_type>(subtrahends), false))) ? xte::null : xte::opt(diff);
	}

	template<xte::is_arithmetic multiplier_type, xte::is_arithmetic... multiplicand_types,
		typename common_type = std::common_type_t<multiplier_type, multiplicand_types...>>
	[[nodiscard]] constexpr xte::opt<common_type> checked_mul(multiplier_type multiplier, multiplicand_types... multiplicands) noexcept {
		auto prod = xte::make<common_type>(multiplier);
#	if XTE_HAS_BUILTIN(mul_overflow)
		if constexpr (!xte::is_float<common_type>) {
			return (... || __builtin_mul_overflow(prod, static_cast<common_type>(multiplicands), &prod)) ? xte::null : xte::opt(prod);
		}
#	endif
		bool overflow = false;
		(void)(!xte::is_finite(prod) || ... || (!prod || (overflow = !xte::is_finite(multiplicands) || (xte::abs(xte::make<common_type>(multiplicands)) > (xte::abs(((prod < 0) == (multiplicands < 0)) ? xte::highest<common_type> : xte::lowest<common_type>) / xte::abs(prod)))) || !xte::assign(prod, prod * xte::make<common_type>(multiplicands))));
		return overflow ? xte::null : xte::opt(prod);
	}

	template<xte::is_arithmetic dividend_type, xte::is_arithmetic... divisor_types,
		typename common_type = std::common_type_t<dividend_type, divisor_types...>>
	[[nodiscard]] constexpr xte::opt<common_type> checked_div(dividend_type dividend, divisor_types... divisors) noexcept {
		if constexpr (xte::is_float<common_type>) {
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

	template<xte::is_arithmetic dividend_type, xte::is_arithmetic... divisor_types,
		typename common_type = std::common_type_t<dividend_type, divisor_types...>>
	[[nodiscard]] constexpr xte::opt<common_type> checked_rem(dividend_type dividend, divisor_types... divisors) noexcept {
		return (!xte::is_finite(dividend) || ... || (!xte::is_finite(divisors) || !divisors))
			? xte::null
			: xte::opt(xte::rem(dividend, divisors...));
	}

	template<xte::is_arithmetic dividend_type, xte::is_arithmetic... divisor_types,
		typename common_type = std::common_type_t<dividend_type, divisor_types...>>
	[[nodiscard]] constexpr xte::opt<common_type> checked_mod(dividend_type dividend, divisor_types... divisors) noexcept {
		return (!xte::is_finite(dividend) || ... || (!xte::is_finite(dividend) || !divisors))
			? xte::null
			: xte::opt(xte::mod(dividend, divisors...));
	}

	template<xte::is_arithmetic base_type, xte::is_arithmetic... exp_types,
		typename common_type = std::common_type_t<base_type, exp_types...>>
	[[nodiscard]] constexpr xte::opt<common_type> checked_pow(base_type base, exp_types... exps) noexcept {
		if constexpr (sizeof...(exps)) {
			return ([](this auto checked_pow, auto base, auto exp, auto... exps) {
				auto power = ([&] -> xte::opt<common_type> {
					if constexpr (xte::is_float<common_type>) {
						return (xte::is_finite(base) && xte::is_finite(exp))
							? xte::opt(std::pow(xte::make<common_type>(base), xte::make<common_type>(exp)))
							: xte::null;
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
								if (auto prod = xte::checked_mul(power, base)) {
									power = *prod;
								} else {
									return xte::null;
								}
								--exp;
							}
							if (auto prod = xte::checked_mul(base, base)) {
								base = *prod;
							} else {
								return xte::null;
							}
							exp >>= 1;
						}
						return xte::opt(power * static_cast<common_type>(base));
					}
				})();
				if constexpr (sizeof...(exps)) {
					if (power) {
						return checked_pow(*power, exps...);
					}
				}
				return power;
			})(base, exps...);
		} else {
			return base;
		}
	}
}

#endif
