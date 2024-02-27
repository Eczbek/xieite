#ifndef XIEITE_HEADER_LITERALS_EXPONENT
#	define XIEITE_HEADER_LITERALS_EXPONENT

#	include <cmath>
#	include <type_traits>
#	include "../concepts/numeric.hpp"

namespace xieite::detail {
	template<xieite::concepts::Numeric Number>
	struct Exponent {
	private:
		struct Value {
		public:
			constexpr Value(const Number value) noexcept
			: value(value) {}

			constexpr auto operator=(xieite::detail::Exponent<Number>::Value) = delete;

			template<xieite::concepts::Numeric OtherNumber>
			[[nodiscard]] friend constexpr std::common_type_t<Number, OtherNumber> operator*(const OtherNumber base, const xieite::detail::Exponent<Number>::Value exponent) noexcept {
				return static_cast<Number>(std::pow(base, exponent.value));
			}

		private:
			Number value;
		};

	public:
		constexpr Exponent(const Number value) noexcept
		: value(value) {}

		template<xieite::concepts::Numeric OtherNumber>
		[[nodiscard]] constexpr operator OtherNumber() const noexcept {
			return static_cast<OtherNumber>(this->value.value);
		}

		[[nodiscard]] constexpr xieite::detail::Exponent<Number>::Value operator*() const noexcept {
			return this->value;
		}

	private:
		xieite::detail::Exponent<Number>::Value value;
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
