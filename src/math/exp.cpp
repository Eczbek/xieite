export module xieite:exp;

import std;
import :is_arith;
import :set_cp_assign;
import :set_mv_assign;
import :pow;

namespace xieite {
	template<xieite::is_arith T>
	struct exp {
	private:
		struct proxy : xieite::set_cp_assign<false>, xieite::set_mv_assign<false> {
		public:
			[[nodiscard]] explicit constexpr proxy(T value) noexcept
			: value(value) {}

			template<xieite::is_arith U>
			[[nodiscard]] friend constexpr std::common_type_t<T, U> operator*(U base, xieite::exp<T>::proxy proxy) noexcept {
				return static_cast<std::common_type_t<T, U>>(xieite::pow(base, proxy.value));
			}

		private:
			T value;
		};

	public:
		[[nodiscard]] explicit constexpr exp(T value) noexcept
		: value(value) {}

		template<xieite::is_arith U>
		[[nodiscard]] explicit(false) constexpr operator std::common_type_t<T, U>() const noexcept {
			return static_cast<std::common_type_t<T, U>>(this->value);
		}

		[[nodiscard]] constexpr xieite::exp<T>::proxy operator*() const noexcept {
			return xieite::exp<T>::proxy(this->value);
		}

	private:
		T value;
	};

	template<typename T>
	exp(T) -> exp<T>;
}
