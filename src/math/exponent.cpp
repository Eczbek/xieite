export module xieite:math.Exponent;

import std;
import :concepts.Arithmetic;
import :containers.MaybeCopyAssignable;
import :containers.MaybeMoveAssignable;
import :math.power;

namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic>
	struct Exponent {
	private:
		struct Intermediate
		: xieite::containers::MaybeCopyAssignable<false>, xieite::containers::MaybeMoveAssignable<false> {
		public:
			explicit constexpr Intermediate(const Arithmetic value) noexcept
			: value(value) {}

			template<xieite::concepts::Arithmetic OtherArithmetic>
			[[nodiscard]] friend constexpr std::common_type_t<Arithmetic, OtherArithmetic> operator*(const OtherArithmetic base, const xieite::math::Exponent<Arithmetic>::Intermediate exponent) noexcept {
				return static_cast<std::common_type_t<Arithmetic, OtherArithmetic>>(xieite::math::power(base, exponent.value));
			}

		private:
			Arithmetic value;
		};

	public:
		explicit constexpr Exponent(const Arithmetic value) noexcept
		: value(value) {}

		template<xieite::concepts::Arithmetic OtherArithmetic>
		[[nodiscard]] explicit(false) constexpr operator std::common_type_t<Arithmetic, OtherArithmetic>() const noexcept {
			return static_cast<std::common_type_t<Arithmetic, OtherArithmetic>>(this->value);
		}

		[[nodiscard]] constexpr xieite::math::Exponent<Arithmetic>::Intermediate operator*() const noexcept {
			return xieite::math::Exponent<Arithmetic>::Intermediate(this->value);
		}

	private:
		Arithmetic value;
	};

	template<typename Type>
	Exponent(Type) -> xieite::math::Exponent<Type>;
}