#ifndef DETAIL_XIEITE_HEADER_MATH_EXP
#	define DETAIL_XIEITE_HEADER_MATH_EXP
#
#	include <type_traits>
#	include "../math/pow.hpp"
#	include "../trait/is_arith.hpp"
#	include "../trait/rm_cp_assign.hpp"
#	include "../trait/rm_mv_assign.hpp"

namespace xieite {
	template<xieite::is_arith Arith>
	struct exp {
	private:
		struct proxy : xieite::rm_cp_assign, xieite::rm_mv_assign {
		public:
			[[nodiscard]] explicit constexpr proxy(Arith value) noexcept
			: value(value) {}

			template<xieite::is_arith OtherArith>
			[[nodiscard]] friend constexpr std::common_type_t<Arith, OtherArith> operator*(OtherArith base, xieite::exp<Arith>::proxy proxy) noexcept {
				return static_cast<std::common_type_t<Arith, OtherArith>>(xieite::pow(base, proxy.value));
			}

		private:
			Arith value;
		};

	public:
		[[nodiscard]] explicit constexpr exp(Arith value) noexcept
		: value(value) {}

		template<xieite::is_arith OtherArith>
		[[nodiscard]] explicit(false) constexpr operator std::common_type_t<Arith, OtherArith>() const noexcept {
			return static_cast<std::common_type_t<Arith, OtherArith>>(this->value);
		}

		[[nodiscard]] constexpr xieite::exp<Arith>::proxy operator*() const noexcept {
			return xieite::exp<Arith>::proxy(this->value);
		}

	private:
		Arith value;
	};

	template<typename Arith>
	exp(Arith) -> exp<Arith>;
}

#endif
