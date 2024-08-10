#ifndef XIEITE_HEADER_LITERALS_EXPONENT
#	define XIEITE_HEADER_LITERALS_EXPONENT

#	include <cmath>
#	include <type_traits>
#	include "../concepts/arithmetic.hpp"

namespace xieite::detail {
	template<xieite::concepts::Arithmetic Arithmetic_>
	struct Exponent {
	private:
		struct Value {
		public:
			constexpr Value(const Arithmetic_ value) noexcept
			: value(value) {}

			constexpr auto operator=(xieite::detail::Exponent<Arithmetic_>::Value) = delete;

			template<xieite::concepts::Arithmetic OtherArithmetic_>
			[[nodiscard]] friend constexpr std::common_type_t<Arithmetic_, OtherArithmetic_> operator*(const OtherArithmetic_ base, const xieite::detail::Exponent<Arithmetic_>::Value exponent) noexcept {
				return static_cast<Arithmetic_>(std::pow(base, exponent.value));
			}

		private:
			Arithmetic_ value;
		};

	public:
		constexpr Exponent(const Arithmetic_ value) noexcept
		: value(value) {}

		template<xieite::concepts::Arithmetic OtherArithmetic_>
		[[nodiscard]] explicit(false) constexpr operator OtherArithmetic_() const noexcept {
			return static_cast<OtherArithmetic_>(this->value.value);
		}

		[[nodiscard]] constexpr xieite::detail::Exponent<Arithmetic_>::Value operator*() const noexcept {
			return this->value;
		}

	private:
		xieite::detail::Exponent<Arithmetic_>::Value value;
	};
}

namespace xieite::literals::exponent {
	[[nodiscard]] constexpr auto operator""_exponent(const unsigned long long int value) noexcept {
		return xieite::detail::Exponent(value);
	}

	[[nodiscard]] constexpr auto operator""_exponent(const long double value) noexcept {
		return xieite::detail::Exponent(value);
	}
}

#endif
