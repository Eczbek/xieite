#ifndef XIEITE_HEADER_MATH_EXPONENT
#	define XIEITE_HEADER_MATH_EXPONENT

#	include <cmath>
#	include <type_traits>
#	include "../concepts/numeric.hpp"

namespace xieite::math {
	template<xieite::concepts::Numeric Number>
	class Exponent {
	private:
		class Value {
		public:
			constexpr Value(const Number value) noexcept
			: value(value) {}

			constexpr auto operator=(xieite::math::Exponent<Number>::Value) = delete;

			template<xieite::concepts::Numeric OtherNumber>
			[[nodiscard]] friend constexpr std::common_type_t<Number, OtherNumber> operator*(const OtherNumber base, const xieite::math::Exponent<Number>::Value exponent) noexcept {
				return static_cast<Number>(std::pow(base, exponent.value));
			}

		private:
			const Number value;
		};

	public:
		constexpr Exponent(const Number value) noexcept
		: value(value) {}

		template<xieite::concepts::Numeric OtherNumber>
		[[nodiscard]] constexpr operator OtherNumber() const noexcept {
			return static_cast<OtherNumber>(this->value.value);
		}

		[[nodiscard]] constexpr xieite::math::Exponent<Number>::Value operator*() const noexcept {
			return this->value;
		}

	private:
		xieite::math::Exponent<Number>::Value value;
	};
}

#endif
