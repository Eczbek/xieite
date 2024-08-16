#ifndef XIEITE_HEADER_LITERALS_EXPONENT
#	define XIEITE_HEADER_LITERALS_EXPONENT

#	include <cmath>
#	include <type_traits>
#	include "../concepts/arithmetic.hpp"

namespace xieite::detail {
	template<xieite::concepts::Arithmetic Arithmetic>
	struct Exponent {
	private:
		struct Value {
		public:
			explicit(false) constexpr Value(const Arithmetic value) noexcept
			: value(value) {}

			auto operator=(xieite::detail::Exponent<Arithmetic>::Value) noexcept = delete;

			template<xieite::concepts::Arithmetic OtherArithmetic>
			[[nodiscard]] friend constexpr std::common_type_t<Arithmetic, OtherArithmetic> operator*(const OtherArithmetic base, const xieite::detail::Exponent<Arithmetic>::Value exponent) noexcept {
				return static_cast<Arithmetic>(std::pow(base, exponent.value));
			}

		private:
			Arithmetic value;
		};

	public:
		explicit(false) constexpr Exponent(const Arithmetic value) noexcept
		: value(value) {}

		template<xieite::concepts::Arithmetic OtherArithmetic>
		[[nodiscard]] explicit(false) constexpr operator OtherArithmetic() const noexcept {
			return static_cast<OtherArithmetic>(this->value.value);
		}

		[[nodiscard]] constexpr xieite::detail::Exponent<Arithmetic>::Value operator*() const noexcept {
			return this->value;
		}

	private:
		xieite::detail::Exponent<Arithmetic>::Value value;
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
