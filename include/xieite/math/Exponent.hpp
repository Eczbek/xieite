#ifndef XIEITE_HEADER__MATH__EXPONENT
#	define XIEITE_HEADER__MATH__EXPONENT

#	include <cmath>
#	include <type_traits>
#	include "../concepts/Arithmetic.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic>
	class Exponent {
	private:
		class Value {
		public:
			constexpr Value(const Arithmetic value) noexcept
			: value(value) {}

			constexpr auto operator=(xieite::math::Exponent<Arithmetic>::Value) = delete;

			template<xieite::concepts::Arithmetic OtherArithmetic>
			[[nodiscard]] friend constexpr std::common_type_t<Arithmetic, OtherArithmetic> operator*(const OtherArithmetic base, const xieite::math::Exponent<Arithmetic>::Value exponent) noexcept {
				return std::pow(base, exponent.value);
			}

		private:
			const Arithmetic value;
		};

	public:
		constexpr Exponent(const Arithmetic value) noexcept
		: value(value) {}

		template<xieite::concepts::Arithmetic OtherArithmetic>
		[[nodiscard]] constexpr operator OtherArithmetic() const noexcept {
			return static_cast<OtherArithmetic>(this->value.value);
		}

		[[nodiscard]] constexpr xieite::math::Exponent<Arithmetic>::Value operator*() const noexcept {
			return this->value;
		}

	private:
		xieite::math::Exponent<Arithmetic>::Value value;
	};
}

#endif
