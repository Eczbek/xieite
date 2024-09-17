export module xieite:literals.exponent;

import std;
import :concepts.Arithmetic;

namespace {
	template<xieite::concepts::Arithmetic Arithmetic>
	struct Exponent {
	private:
		struct Intermediate {
		public:
			explicit(false) constexpr Intermediate(const Arithmetic value) noexcept
			: value(value) {}

			auto operator=(Exponent<Arithmetic>::Intermediate) = delete;

			template<xieite::concepts::Arithmetic OtherArithmetic>
			[[nodiscard]] friend constexpr std::common_type_t<Arithmetic, OtherArithmetic> operator*(const OtherArithmetic base, const Exponent<Arithmetic>::Intermediate exponent) noexcept {
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

		[[nodiscard]] constexpr Exponent<Arithmetic>::Intermediate operator*() const noexcept {
			return this->value;
		}

	private:
		Exponent<Arithmetic>::Intermediate value;
	};
}

export namespace xieite::literals::exponent {
	[[nodiscard]] constexpr auto operator""_exponent(const unsigned long long int value) noexcept {
		return Exponent(value);
	}

	[[nodiscard]] constexpr auto operator""_exponent(const long double value) noexcept {
		return Exponent(value);
	}
}
