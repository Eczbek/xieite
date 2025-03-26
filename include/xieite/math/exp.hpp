#ifndef DETAIL_XIEITE_HEADER_MATH_EXP
#	define DETAIL_XIEITE_HEADER_MATH_EXP
#
#	include <type_traits>
#	include "../math/pow.hpp"
#	include "../trait/is_arith.hpp"
#	include "../trait/rm_cp_assign.hpp"
#	include "../trait/rm_mv_assign.hpp"

namespace xieite {
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

#endif
