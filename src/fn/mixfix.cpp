module;

#include <xieite/fwd.hpp>

export module xieite:mixfix;

import std;
import :maybe_copy_assignable;
import :maybe_move_assignable;
import :fn;

export namespace xieite {
	template<typename>
	struct mixfix;

	template<typename Ret, typename Arg>
	struct mixfix<Ret(Arg)> : xieite::fn<Ret(Arg)> {
		using xieite::fn<Ret(Arg)>::fn;

		template<std::convertible_to<Arg> ArgRef>
		friend constexpr decltype(auto) operator->*(const mixfix& mixfix, ArgRef&& arg) noexcept(false) {
			return mixfix(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		friend constexpr decltype(auto) operator*(const mixfix& mixfix, ArgRef&& arg) noexcept(false) {
			return mixfix(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		friend constexpr decltype(auto) operator/(const mixfix& mixfix, ArgRef&& arg) noexcept(false) {
			return mixfix(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		friend constexpr decltype(auto) operator%(const mixfix& mixfix, ArgRef&& arg) noexcept(false) {
			return mixfix(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		friend constexpr decltype(auto) operator+(const mixfix& mixfix, ArgRef&& arg) noexcept(false) {
			return mixfix(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		friend constexpr decltype(auto) operator-(const mixfix& mixfix, ArgRef&& arg) noexcept(false) {
			return mixfix(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		friend constexpr decltype(auto) operator<<(const mixfix& mixfix, ArgRef&& arg) noexcept(false) {
			return mixfix(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		friend constexpr decltype(auto) operator>>(const mixfix& mixfix, ArgRef&& arg) noexcept(false) {
			return mixfix(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		friend constexpr decltype(auto) operator<=>(const mixfix& mixfix, ArgRef&& arg) noexcept(false) {
			return mixfix(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		friend constexpr decltype(auto) operator<(const mixfix& mixfix, ArgRef&& arg) noexcept(false) {
			return mixfix(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		friend constexpr decltype(auto) operator<=(const mixfix& mixfix, ArgRef&& arg) noexcept(false) {
			return mixfix(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		friend constexpr decltype(auto) operator>(const mixfix& mixfix, ArgRef&& arg) noexcept(false) {
			return mixfix(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		friend constexpr decltype(auto) operator>=(const mixfix& mixfix, ArgRef&& arg) noexcept(false) {
			return mixfix(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		friend constexpr decltype(auto) operator==(const mixfix& mixfix, ArgRef&& arg) noexcept(false) {
			return mixfix(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		friend constexpr decltype(auto) operator!=(const mixfix& mixfix, ArgRef&& arg) noexcept(false) {
			return mixfix(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		friend constexpr decltype(auto) operator&(const mixfix& mixfix, ArgRef&& arg) noexcept(false) {
			return mixfix(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		friend constexpr decltype(auto) operator^(const mixfix& mixfix, ArgRef&& arg) noexcept(false) {
			return mixfix(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		friend constexpr decltype(auto) operator|(const mixfix& mixfix, ArgRef&& arg) noexcept(false) {
			return mixfix(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		friend constexpr decltype(auto) operator&&(const mixfix& mixfix, ArgRef&& arg) noexcept(false) {
			return mixfix(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		friend constexpr decltype(auto) operator||(const mixfix& mixfix, ArgRef&& arg) noexcept(false) {
			return mixfix(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		friend constexpr decltype(auto) operator*=(const mixfix& mixfix, ArgRef&& arg) noexcept(false) {
			return mixfix(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		friend constexpr decltype(auto) operator/=(const mixfix& mixfix, ArgRef&& arg) noexcept(false) {
			return mixfix(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		friend constexpr decltype(auto) operator%=(const mixfix& mixfix, ArgRef&& arg) noexcept(false) {
			return mixfix(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		friend constexpr decltype(auto) operator+=(const mixfix& mixfix, ArgRef&& arg) noexcept(false) {
			return mixfix(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		friend constexpr decltype(auto) operator-=(const mixfix& mixfix, ArgRef&& arg) noexcept(false) {
			return mixfix(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		friend constexpr decltype(auto) operator<<=(const mixfix& mixfix, ArgRef&& arg) noexcept(false) {
			return mixfix(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		friend constexpr decltype(auto) operator>>=(const mixfix& mixfix, ArgRef&& arg) noexcept(false) {
			return mixfix(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		friend constexpr decltype(auto) operator&=(const mixfix& mixfix, ArgRef&& arg) noexcept(false) {
			return mixfix(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		friend constexpr decltype(auto) operator^=(const mixfix& mixfix, ArgRef&& arg) noexcept(false) {
			return mixfix(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		friend constexpr decltype(auto) operator|=(const mixfix& mixfix, ArgRef&& arg) noexcept(false) {
			return mixfix(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		friend constexpr decltype(auto) operator,(const mixfix& mixfix, ArgRef&& arg) noexcept(false) {
			return mixfix(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		friend constexpr decltype(auto) operator->*(ArgRef&& arg, const mixfix& mixfix) noexcept(false) {
			return mixfix(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		friend constexpr decltype(auto) operator*(ArgRef&& arg, const mixfix& mixfix) noexcept(false) {
			return mixfix(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		friend constexpr decltype(auto) operator/(ArgRef&& arg, const mixfix& mixfix) noexcept(false) {
			return mixfix(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		friend constexpr decltype(auto) operator%(ArgRef&& arg, const mixfix& mixfix) noexcept(false) {
			return mixfix(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		friend constexpr decltype(auto) operator+(ArgRef&& arg, const mixfix& mixfix) noexcept(false) {
			return mixfix(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		friend constexpr decltype(auto) operator-(ArgRef&& arg, const mixfix& mixfix) noexcept(false) {
			return mixfix(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		friend constexpr decltype(auto) operator<<(ArgRef&& arg, const mixfix& mixfix) noexcept(false) {
			return mixfix(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		friend constexpr decltype(auto) operator>>(ArgRef&& arg, const mixfix& mixfix) noexcept(false) {
			return mixfix(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		friend constexpr decltype(auto) operator<=>(ArgRef&& arg, const mixfix& mixfix) noexcept(false) {
			return mixfix(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		friend constexpr decltype(auto) operator<(ArgRef&& arg, const mixfix& mixfix) noexcept(false) {
			return mixfix(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		friend constexpr decltype(auto) operator<=(ArgRef&& arg, const mixfix& mixfix) noexcept(false) {
			return mixfix(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		friend constexpr decltype(auto) operator>(ArgRef&& arg, const mixfix& mixfix) noexcept(false) {
			return mixfix(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		friend constexpr decltype(auto) operator>=(ArgRef&& arg, const mixfix& mixfix) noexcept(false) {
			return mixfix(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		friend constexpr decltype(auto) operator==(ArgRef&& arg, const mixfix& mixfix) noexcept(false) {
			return mixfix(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		friend constexpr decltype(auto) operator!=(ArgRef&& arg, const mixfix& mixfix) noexcept(false) {
			return mixfix(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		friend constexpr decltype(auto) operator&(ArgRef&& arg, const mixfix& mixfix) noexcept(false) {
			return mixfix(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		friend constexpr decltype(auto) operator^(ArgRef&& arg, const mixfix& mixfix) noexcept(false) {
			return mixfix(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		friend constexpr decltype(auto) operator|(ArgRef&& arg, const mixfix& mixfix) noexcept(false) {
			return mixfix(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		friend constexpr decltype(auto) operator&&(ArgRef&& arg, const mixfix& mixfix) noexcept(false) {
			return mixfix(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		friend constexpr decltype(auto) operator||(ArgRef&& arg, const mixfix& mixfix) noexcept(false) {
			return mixfix(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		friend constexpr decltype(auto) operator*=(ArgRef&& arg, const mixfix& mixfix) noexcept(false) {
			return mixfix(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		friend constexpr decltype(auto) operator/=(ArgRef&& arg, const mixfix& mixfix) noexcept(false) {
			return mixfix(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		friend constexpr decltype(auto) operator%=(ArgRef&& arg, const mixfix& mixfix) noexcept(false) {
			return mixfix(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		friend constexpr decltype(auto) operator+=(ArgRef&& arg, const mixfix& mixfix) noexcept(false) {
			return mixfix(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		friend constexpr decltype(auto) operator-=(ArgRef&& arg, const mixfix& mixfix) noexcept(false) {
			return mixfix(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		friend constexpr decltype(auto) operator<<=(ArgRef&& arg, const mixfix& mixfix) noexcept(false) {
			return mixfix(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		friend constexpr decltype(auto) operator>>=(ArgRef&& arg, const mixfix& mixfix) noexcept(false) {
			return mixfix(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		friend constexpr decltype(auto) operator&=(ArgRef&& arg, const mixfix& mixfix) noexcept(false) {
			return mixfix(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		friend constexpr decltype(auto) operator^=(ArgRef&& arg, const mixfix& mixfix) noexcept(false) {
			return mixfix(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		friend constexpr decltype(auto) operator|=(ArgRef&& arg, const mixfix& mixfix) noexcept(false) {
			return mixfix(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		friend constexpr decltype(auto) operator,(ArgRef&& arg, const mixfix& mixfix) noexcept(false) {
			return mixfix(XIEITE_FWD(arg));
		}
	};

	template<typename Ret, typename LeftArg, typename RightArg>
	struct mixfix<Ret(LeftArg, RightArg)> : xieite::fn<Ret(LeftArg, RightArg)> {
	private:
		template<typename LeftArgRef>
		struct inter : xieite::maybe_copy_assignable<false>, xieite::maybe_move_assignable<false> {
		public:
			constexpr inter(const mixfix& mixfix, LeftArgRef&& left) noexcept
			: mixfix(mixfix), left(XIEITE_FWD(left)) {}

			template<std::convertible_to<RightArg> RightArgRef>
			friend constexpr decltype(auto) operator->*(const inter&& inter, RightArgRef&& right) noexcept(false) {
				return inter.mixfix(XIEITE_FWD(inter.left), XIEITE_FWD(right));
			}

			template<std::convertible_to<RightArg> RightArgRef>
			friend constexpr decltype(auto) operator*(const inter&& inter, RightArgRef&& right) noexcept(false) {
				return inter.mixfix(XIEITE_FWD(inter.left), XIEITE_FWD(right));
			}

			template<std::convertible_to<RightArg> RightArgRef>
			friend constexpr decltype(auto) operator/(const inter&& inter, RightArgRef&& right) noexcept(false) {
				return inter.mixfix(XIEITE_FWD(inter.left), XIEITE_FWD(right));
			}

			template<std::convertible_to<RightArg> RightArgRef>
			friend constexpr decltype(auto) operator%(const inter&& inter, RightArgRef&& right) noexcept(false) {
				return inter.mixfix(XIEITE_FWD(inter.left), XIEITE_FWD(right));
			}

			template<std::convertible_to<RightArg> RightArgRef>
			friend constexpr decltype(auto) operator+(const inter&& inter, RightArgRef&& right) noexcept(false) {
				return inter.mixfix(XIEITE_FWD(inter.left), XIEITE_FWD(right));
			}

			template<std::convertible_to<RightArg> RightArgRef>
			friend constexpr decltype(auto) operator-(const inter&& inter, RightArgRef&& right) noexcept(false) {
				return inter.mixfix(XIEITE_FWD(inter.left), XIEITE_FWD(right));
			}

			template<std::convertible_to<RightArg> RightArgRef>
			friend constexpr decltype(auto) operator<<(const inter&& inter, RightArgRef&& right) noexcept(false) {
				return inter.mixfix(XIEITE_FWD(inter.left), XIEITE_FWD(right));
			}

			template<std::convertible_to<RightArg> RightArgRef>
			friend constexpr decltype(auto) operator>>(const inter&& inter, RightArgRef&& right) noexcept(false) {
				return inter.mixfix(XIEITE_FWD(inter.left), XIEITE_FWD(right));
			}

			template<std::convertible_to<RightArg> RightArgRef>
			friend constexpr decltype(auto) operator<=>(const inter&& inter, RightArgRef&& right) noexcept(false) {
				return inter.mixfix(XIEITE_FWD(inter.left), XIEITE_FWD(right));
			}

			template<std::convertible_to<RightArg> RightArgRef>
			friend constexpr decltype(auto) operator<(const inter&& inter, RightArgRef&& right) noexcept(false) {
				return inter.mixfix(XIEITE_FWD(inter.left), XIEITE_FWD(right));
			}

			template<std::convertible_to<RightArg> RightArgRef>
			friend constexpr decltype(auto) operator<=(const inter&& inter, RightArgRef&& right) noexcept(false) {
				return inter.mixfix(XIEITE_FWD(inter.left), XIEITE_FWD(right));
			}

			template<std::convertible_to<RightArg> RightArgRef>
			friend constexpr decltype(auto) operator>(const inter&& inter, RightArgRef&& right) noexcept(false) {
				return inter.mixfix(XIEITE_FWD(inter.left), XIEITE_FWD(right));
			}

			template<std::convertible_to<RightArg> RightArgRef>
			friend constexpr decltype(auto) operator>=(const inter&& inter, RightArgRef&& right) noexcept(false) {
				return inter.mixfix(XIEITE_FWD(inter.left), XIEITE_FWD(right));
			}

			template<std::convertible_to<RightArg> RightArgRef>
			friend constexpr decltype(auto) operator==(const inter&& inter, RightArgRef&& right) noexcept(false) {
				return inter.mixfix(XIEITE_FWD(inter.left), XIEITE_FWD(right));
			}

			template<std::convertible_to<RightArg> RightArgRef>
			friend constexpr decltype(auto) operator!=(const inter&& inter, RightArgRef&& right) noexcept(false) {
				return inter.mixfix(XIEITE_FWD(inter.left), XIEITE_FWD(right));
			}

			template<std::convertible_to<RightArg> RightArgRef>
			friend constexpr decltype(auto) operator&(const inter&& inter, RightArgRef&& right) noexcept(false) {
				return inter.mixfix(XIEITE_FWD(inter.left), XIEITE_FWD(right));
			}

			template<std::convertible_to<RightArg> RightArgRef>
			friend constexpr decltype(auto) operator^(const inter&& inter, RightArgRef&& right) noexcept(false) {
				return inter.mixfix(XIEITE_FWD(inter.left), XIEITE_FWD(right));
			}

			template<std::convertible_to<RightArg> RightArgRef>
			friend constexpr decltype(auto) operator|(const inter&& inter, RightArgRef&& right) noexcept(false) {
				return inter.mixfix(XIEITE_FWD(inter.left), XIEITE_FWD(right));
			}

			template<std::convertible_to<RightArg> RightArgRef>
			friend constexpr decltype(auto) operator&&(const inter&& inter, RightArgRef&& right) noexcept(false) {
				return inter.mixfix(XIEITE_FWD(inter.left), XIEITE_FWD(right));
			}

			template<std::convertible_to<RightArg> RightArgRef>
			friend constexpr decltype(auto) operator||(const inter&& inter, RightArgRef&& right) noexcept(false) {
				return inter.mixfix(XIEITE_FWD(inter.left), XIEITE_FWD(right));
			}

			template<std::convertible_to<RightArg> RightArgRef>
			friend constexpr decltype(auto) operator*=(const inter&& inter, RightArgRef&& right) noexcept(false) {
				return inter.mixfix(XIEITE_FWD(inter.left), XIEITE_FWD(right));
			}

			template<std::convertible_to<RightArg> RightArgRef>
			friend constexpr decltype(auto) operator/=(const inter&& inter, RightArgRef&& right) noexcept(false) {
				return inter.mixfix(XIEITE_FWD(inter.left), XIEITE_FWD(right));
			}

			template<std::convertible_to<RightArg> RightArgRef>
			friend constexpr decltype(auto) operator%=(const inter&& inter, RightArgRef&& right) noexcept(false) {
				return inter.mixfix(XIEITE_FWD(inter.left), XIEITE_FWD(right));
			}

			template<std::convertible_to<RightArg> RightArgRef>
			friend constexpr decltype(auto) operator+=(const inter&& inter, RightArgRef&& right) noexcept(false) {
				return inter.mixfix(XIEITE_FWD(inter.left), XIEITE_FWD(right));
			}

			template<std::convertible_to<RightArg> RightArgRef>
			friend constexpr decltype(auto) operator-=(const inter&& inter, RightArgRef&& right) noexcept(false) {
				return inter.mixfix(XIEITE_FWD(inter.left), XIEITE_FWD(right));
			}

			template<std::convertible_to<RightArg> RightArgRef>
			friend constexpr decltype(auto) operator<<=(const inter&& inter, RightArgRef&& right) noexcept(false) {
				return inter.mixfix(XIEITE_FWD(inter.left), XIEITE_FWD(right));
			}

			template<std::convertible_to<RightArg> RightArgRef>
			friend constexpr decltype(auto) operator>>=(const inter&& inter, RightArgRef&& right) noexcept(false) {
				return inter.mixfix(XIEITE_FWD(inter.left), XIEITE_FWD(right));
			}

			template<std::convertible_to<RightArg> RightArgRef>
			friend constexpr decltype(auto) operator&=(const inter&& inter, RightArgRef&& right) noexcept(false) {
				return inter.mixfix(XIEITE_FWD(inter.left), XIEITE_FWD(right));
			}

			template<std::convertible_to<RightArg> RightArgRef>
			friend constexpr decltype(auto) operator^=(const inter&& inter, RightArgRef&& right) noexcept(false) {
				return inter.mixfix(XIEITE_FWD(inter.left), XIEITE_FWD(right));
			}

			template<std::convertible_to<RightArg> RightArgRef>
			friend constexpr decltype(auto) operator|=(const inter&& inter, RightArgRef&& right) noexcept(false) {
				return inter.mixfix(XIEITE_FWD(inter.left), XIEITE_FWD(right));
			}

			template<std::convertible_to<RightArg> RightArgRef>
			friend constexpr decltype(auto) operator,(const inter&& inter, RightArgRef&& right) noexcept(false) {
				return inter.mixfix(XIEITE_FWD(inter.left), XIEITE_FWD(right));
			}

		private:
			const xieite::mixfix<Ret(LeftArg, RightArg)>& mixfix;
			LeftArgRef&& left;
		};

	public:
		using xieite::fn<Ret(LeftArg, RightArg)>::fn;

		template<std::convertible_to<LeftArg> LeftArgRef>
		[[nodiscard]] friend constexpr decltype(auto) operator->*(LeftArgRef&& left, const mixfix& mixfix) noexcept(false) {
			return mixfix::inter<LeftArgRef>(mixfix, XIEITE_FWD(left));
		}

		template<std::convertible_to<LeftArg> LeftArgRef>
		[[nodiscard]] friend constexpr decltype(auto) operator*(LeftArgRef&& left, const mixfix& mixfix) noexcept(false) {
			return mixfix::inter<LeftArgRef>(mixfix, XIEITE_FWD(left));
		}

		template<std::convertible_to<LeftArg> LeftArgRef>
		[[nodiscard]] friend constexpr decltype(auto) operator/(LeftArgRef&& left, const mixfix& mixfix) noexcept(false) {
			return mixfix::inter<LeftArgRef>(mixfix, XIEITE_FWD(left));
		}

		template<std::convertible_to<LeftArg> LeftArgRef>
		[[nodiscard]] friend constexpr decltype(auto) operator%(LeftArgRef&& left, const mixfix& mixfix) noexcept(false) {
			return mixfix::inter<LeftArgRef>(mixfix, XIEITE_FWD(left));
		}

		template<std::convertible_to<LeftArg> LeftArgRef>
		[[nodiscard]] friend constexpr decltype(auto) operator+(LeftArgRef&& left, const mixfix& mixfix) noexcept(false) {
			return mixfix::inter<LeftArgRef>(mixfix, XIEITE_FWD(left));
		}

		template<std::convertible_to<LeftArg> LeftArgRef>
		[[nodiscard]] friend constexpr decltype(auto) operator-(LeftArgRef&& left, const mixfix& mixfix) noexcept(false) {
			return mixfix::inter<LeftArgRef>(mixfix, XIEITE_FWD(left));
		}

		template<std::convertible_to<LeftArg> LeftArgRef>
		[[nodiscard]] friend constexpr decltype(auto) operator<<(LeftArgRef&& left, const mixfix& mixfix) noexcept(false) {
			return mixfix::inter<LeftArgRef>(mixfix, XIEITE_FWD(left));
		}

		template<std::convertible_to<LeftArg> LeftArgRef>
		[[nodiscard]] friend constexpr decltype(auto) operator>>(LeftArgRef&& left, const mixfix& mixfix) noexcept(false) {
			return mixfix::inter<LeftArgRef>(mixfix, XIEITE_FWD(left));
		}

		template<std::convertible_to<LeftArg> LeftArgRef>
		[[nodiscard]] friend constexpr decltype(auto) operator<=>(LeftArgRef&& left, const mixfix& mixfix) noexcept(false) {
			return mixfix::inter<LeftArgRef>(mixfix, XIEITE_FWD(left));
		}

		template<std::convertible_to<LeftArg> LeftArgRef>
		[[nodiscard]] friend constexpr decltype(auto) operator<(LeftArgRef&& left, const mixfix& mixfix) noexcept(false) {
			return mixfix::inter<LeftArgRef>(mixfix, XIEITE_FWD(left));
		}

		template<std::convertible_to<LeftArg> LeftArgRef>
		[[nodiscard]] friend constexpr decltype(auto) operator<=(LeftArgRef&& left, const mixfix& mixfix) noexcept(false) {
			return mixfix::inter<LeftArgRef>(mixfix, XIEITE_FWD(left));
		}

		template<std::convertible_to<LeftArg> LeftArgRef>
		[[nodiscard]] friend constexpr decltype(auto) operator>(LeftArgRef&& left, const mixfix& mixfix) noexcept(false) {
			return mixfix::inter<LeftArgRef>(mixfix, XIEITE_FWD(left));
		}

		template<std::convertible_to<LeftArg> LeftArgRef>
		[[nodiscard]] friend constexpr decltype(auto) operator>=(LeftArgRef&& left, const mixfix& mixfix) noexcept(false) {
			return mixfix::inter<LeftArgRef>(mixfix, XIEITE_FWD(left));
		}

		template<std::convertible_to<LeftArg> LeftArgRef>
		[[nodiscard]] friend constexpr decltype(auto) operator==(LeftArgRef&& left, const mixfix& mixfix) noexcept(false) {
			return mixfix::inter<LeftArgRef>(mixfix, XIEITE_FWD(left));
		}

		template<std::convertible_to<LeftArg> LeftArgRef>
		[[nodiscard]] friend constexpr decltype(auto) operator!=(LeftArgRef&& left, const mixfix& mixfix) noexcept(false) {
			return mixfix::inter<LeftArgRef>(mixfix, XIEITE_FWD(left));
		}

		template<std::convertible_to<LeftArg> LeftArgRef>
		[[nodiscard]] friend constexpr decltype(auto) operator&(LeftArgRef&& left, const mixfix& mixfix) noexcept(false) {
			return mixfix::inter<LeftArgRef>(mixfix, XIEITE_FWD(left));
		}

		template<std::convertible_to<LeftArg> LeftArgRef>
		[[nodiscard]] friend constexpr decltype(auto) operator^(LeftArgRef&& left, const mixfix& mixfix) noexcept(false) {
			return mixfix::inter<LeftArgRef>(mixfix, XIEITE_FWD(left));
		}

		template<std::convertible_to<LeftArg> LeftArgRef>
		[[nodiscard]] friend constexpr decltype(auto) operator|(LeftArgRef&& left, const mixfix& mixfix) noexcept(false) {
			return mixfix::inter<LeftArgRef>(mixfix, XIEITE_FWD(left));
		}

		template<std::convertible_to<LeftArg> LeftArgRef>
		[[nodiscard]] friend constexpr decltype(auto) operator&&(LeftArgRef&& left, const mixfix& mixfix) noexcept(false) {
			return mixfix::inter<LeftArgRef>(mixfix, XIEITE_FWD(left));
		}

		template<std::convertible_to<LeftArg> LeftArgRef>
		[[nodiscard]] friend constexpr decltype(auto) operator||(LeftArgRef&& left, const mixfix& mixfix) noexcept(false) {
			return mixfix::inter<LeftArgRef>(mixfix, XIEITE_FWD(left));
		}

		template<std::convertible_to<LeftArg> LeftArgRef>
		[[nodiscard]] friend constexpr decltype(auto) operator*=(LeftArgRef&& left, const mixfix& mixfix) noexcept(false) {
			return mixfix::inter<LeftArgRef>(mixfix, XIEITE_FWD(left));
		}

		template<std::convertible_to<LeftArg> LeftArgRef>
		[[nodiscard]] friend constexpr decltype(auto) operator/=(LeftArgRef&& left, const mixfix& mixfix) noexcept(false) {
			return mixfix::inter<LeftArgRef>(mixfix, XIEITE_FWD(left));
		}

		template<std::convertible_to<LeftArg> LeftArgRef>
		[[nodiscard]] friend constexpr decltype(auto) operator%=(LeftArgRef&& left, const mixfix& mixfix) noexcept(false) {
			return mixfix::inter<LeftArgRef>(mixfix, XIEITE_FWD(left));
		}

		template<std::convertible_to<LeftArg> LeftArgRef>
		[[nodiscard]] friend constexpr decltype(auto) operator+=(LeftArgRef&& left, const mixfix& mixfix) noexcept(false) {
			return mixfix::inter<LeftArgRef>(mixfix, XIEITE_FWD(left));
		}

		template<std::convertible_to<LeftArg> LeftArgRef>
		[[nodiscard]] friend constexpr decltype(auto) operator-=(LeftArgRef&& left, const mixfix& mixfix) noexcept(false) {
			return mixfix::inter<LeftArgRef>(mixfix, XIEITE_FWD(left));
		}

		template<std::convertible_to<LeftArg> LeftArgRef>
		[[nodiscard]] friend constexpr decltype(auto) operator<<=(LeftArgRef&& left, const mixfix& mixfix) noexcept(false) {
			return mixfix::inter<LeftArgRef>(mixfix, XIEITE_FWD(left));
		}

		template<std::convertible_to<LeftArg> LeftArgRef>
		[[nodiscard]] friend constexpr decltype(auto) operator>>=(LeftArgRef&& left, const mixfix& mixfix) noexcept(false) {
			return mixfix::inter<LeftArgRef>(mixfix, XIEITE_FWD(left));
		}

		template<std::convertible_to<LeftArg> LeftArgRef>
		[[nodiscard]] friend constexpr decltype(auto) operator&=(LeftArgRef&& left, const mixfix& mixfix) noexcept(false) {
			return mixfix::inter<LeftArgRef>(mixfix, XIEITE_FWD(left));
		}

		template<std::convertible_to<LeftArg> LeftArgRef>
		[[nodiscard]] friend constexpr decltype(auto) operator^=(LeftArgRef&& left, const mixfix& mixfix) noexcept(false) {
			return mixfix::inter<LeftArgRef>(mixfix, XIEITE_FWD(left));
		}

		template<std::convertible_to<LeftArg> LeftArgRef>
		[[nodiscard]] friend constexpr decltype(auto) operator|=(LeftArgRef&& left, const mixfix& mixfix) noexcept(false) {
			return mixfix::inter<LeftArgRef>(mixfix, XIEITE_FWD(left));
		}

		template<std::convertible_to<LeftArg> LeftArgRef>
		[[nodiscard]] friend constexpr decltype(auto) operator,(LeftArgRef&& left, const mixfix& mixfix) noexcept(false) {
			return mixfix::inter<LeftArgRef>(mixfix, XIEITE_FWD(left));
		}
	};
}
