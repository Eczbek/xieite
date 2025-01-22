export module xieite:exp;

import std;
import :is_arith;
import :pow;
import :rm_cp_assign;
import :rm_mv_assign;

export namespace xieite {
	template<xieite::is_arith T>
	struct exp {
	private:
		struct proxy : xieite::rm_cp_assign, xieite::rm_mv_assign {
		public:
			[[nodiscard]] explicit constexpr proxy(T n) noexcept
			: value(n) {}

			template<xieite::is_arith U>
			[[nodiscard]] friend constexpr std::common_type_t<T, U> operator*(U base, xieite::exp<T>::proxy proxy) noexcept {
				return static_cast<std::common_type_t<T, U>>(xieite::pow(base, proxy.value));
			}

		private:
			T value;
		};

	public:
		[[nodiscard]] explicit constexpr exp(T n) noexcept
		: value(n) {}

		template<xieite::is_arith U>
		[[nodiscard]] constexpr operator std::common_type_t<T, U>() const noexcept {
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
