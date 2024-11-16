module;

#include <xieite/fwd.hpp>

export module xieite:mixfix;

import std;
import :set_cp_assign;
import :set_mv_assign;
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
		struct proxy : xieite::set_cp_assign<false>, xieite::set_mv_assign<false> {
		public:
			constexpr proxy(const mixfix& mixfix, LeftArgRef&& left) noexcept
			: mixfix(mixfix), left(XIEITE_FWD(left)) {}

			template<std::convertible_to<RightArg> RightArgRef>
			friend constexpr decltype(auto) operator->*(const proxy&& proxy, RightArgRef&& right) noexcept(false) {
				return proxy.mixfix(XIEITE_FWD(proxy.left), XIEITE_FWD(right));
			}

			template<std::convertible_to<RightArg> RightArgRef>
			friend constexpr decltype(auto) operator*(const proxy&& proxy, RightArgRef&& right) noexcept(false) {
				return proxy.mixfix(XIEITE_FWD(proxy.left), XIEITE_FWD(right));
			}

			template<std::convertible_to<RightArg> RightArgRef>
			friend constexpr decltype(auto) operator/(const proxy&& proxy, RightArgRef&& right) noexcept(false) {
				return proxy.mixfix(XIEITE_FWD(proxy.left), XIEITE_FWD(right));
			}

			template<std::convertible_to<RightArg> RightArgRef>
			friend constexpr decltype(auto) operator%(const proxy&& proxy, RightArgRef&& right) noexcept(false) {
				return proxy.mixfix(XIEITE_FWD(proxy.left), XIEITE_FWD(right));
			}

			template<std::convertible_to<RightArg> RightArgRef>
			friend constexpr decltype(auto) operator+(const proxy&& proxy, RightArgRef&& right) noexcept(false) {
				return proxy.mixfix(XIEITE_FWD(proxy.left), XIEITE_FWD(right));
			}

			template<std::convertible_to<RightArg> RightArgRef>
			friend constexpr decltype(auto) operator-(const proxy&& proxy, RightArgRef&& right) noexcept(false) {
				return proxy.mixfix(XIEITE_FWD(proxy.left), XIEITE_FWD(right));
			}

			template<std::convertible_to<RightArg> RightArgRef>
			friend constexpr decltype(auto) operator<<(const proxy&& proxy, RightArgRef&& right) noexcept(false) {
				return proxy.mixfix(XIEITE_FWD(proxy.left), XIEITE_FWD(right));
			}

			template<std::convertible_to<RightArg> RightArgRef>
			friend constexpr decltype(auto) operator>>(const proxy&& proxy, RightArgRef&& right) noexcept(false) {
				return proxy.mixfix(XIEITE_FWD(proxy.left), XIEITE_FWD(right));
			}

			template<std::convertible_to<RightArg> RightArgRef>
			friend constexpr decltype(auto) operator<=>(const proxy&& proxy, RightArgRef&& right) noexcept(false) {
				return proxy.mixfix(XIEITE_FWD(proxy.left), XIEITE_FWD(right));
			}

			template<std::convertible_to<RightArg> RightArgRef>
			friend constexpr decltype(auto) operator<(const proxy&& proxy, RightArgRef&& right) noexcept(false) {
				return proxy.mixfix(XIEITE_FWD(proxy.left), XIEITE_FWD(right));
			}

			template<std::convertible_to<RightArg> RightArgRef>
			friend constexpr decltype(auto) operator<=(const proxy&& proxy, RightArgRef&& right) noexcept(false) {
				return proxy.mixfix(XIEITE_FWD(proxy.left), XIEITE_FWD(right));
			}

			template<std::convertible_to<RightArg> RightArgRef>
			friend constexpr decltype(auto) operator>(const proxy&& proxy, RightArgRef&& right) noexcept(false) {
				return proxy.mixfix(XIEITE_FWD(proxy.left), XIEITE_FWD(right));
			}

			template<std::convertible_to<RightArg> RightArgRef>
			friend constexpr decltype(auto) operator>=(const proxy&& proxy, RightArgRef&& right) noexcept(false) {
				return proxy.mixfix(XIEITE_FWD(proxy.left), XIEITE_FWD(right));
			}

			template<std::convertible_to<RightArg> RightArgRef>
			friend constexpr decltype(auto) operator==(const proxy&& proxy, RightArgRef&& right) noexcept(false) {
				return proxy.mixfix(XIEITE_FWD(proxy.left), XIEITE_FWD(right));
			}

			template<std::convertible_to<RightArg> RightArgRef>
			friend constexpr decltype(auto) operator!=(const proxy&& proxy, RightArgRef&& right) noexcept(false) {
				return proxy.mixfix(XIEITE_FWD(proxy.left), XIEITE_FWD(right));
			}

			template<std::convertible_to<RightArg> RightArgRef>
			friend constexpr decltype(auto) operator&(const proxy&& proxy, RightArgRef&& right) noexcept(false) {
				return proxy.mixfix(XIEITE_FWD(proxy.left), XIEITE_FWD(right));
			}

			template<std::convertible_to<RightArg> RightArgRef>
			friend constexpr decltype(auto) operator^(const proxy&& proxy, RightArgRef&& right) noexcept(false) {
				return proxy.mixfix(XIEITE_FWD(proxy.left), XIEITE_FWD(right));
			}

			template<std::convertible_to<RightArg> RightArgRef>
			friend constexpr decltype(auto) operator|(const proxy&& proxy, RightArgRef&& right) noexcept(false) {
				return proxy.mixfix(XIEITE_FWD(proxy.left), XIEITE_FWD(right));
			}

			template<std::convertible_to<RightArg> RightArgRef>
			friend constexpr decltype(auto) operator&&(const proxy&& proxy, RightArgRef&& right) noexcept(false) {
				return proxy.mixfix(XIEITE_FWD(proxy.left), XIEITE_FWD(right));
			}

			template<std::convertible_to<RightArg> RightArgRef>
			friend constexpr decltype(auto) operator||(const proxy&& proxy, RightArgRef&& right) noexcept(false) {
				return proxy.mixfix(XIEITE_FWD(proxy.left), XIEITE_FWD(right));
			}

			template<std::convertible_to<RightArg> RightArgRef>
			friend constexpr decltype(auto) operator*=(const proxy&& proxy, RightArgRef&& right) noexcept(false) {
				return proxy.mixfix(XIEITE_FWD(proxy.left), XIEITE_FWD(right));
			}

			template<std::convertible_to<RightArg> RightArgRef>
			friend constexpr decltype(auto) operator/=(const proxy&& proxy, RightArgRef&& right) noexcept(false) {
				return proxy.mixfix(XIEITE_FWD(proxy.left), XIEITE_FWD(right));
			}

			template<std::convertible_to<RightArg> RightArgRef>
			friend constexpr decltype(auto) operator%=(const proxy&& proxy, RightArgRef&& right) noexcept(false) {
				return proxy.mixfix(XIEITE_FWD(proxy.left), XIEITE_FWD(right));
			}

			template<std::convertible_to<RightArg> RightArgRef>
			friend constexpr decltype(auto) operator+=(const proxy&& proxy, RightArgRef&& right) noexcept(false) {
				return proxy.mixfix(XIEITE_FWD(proxy.left), XIEITE_FWD(right));
			}

			template<std::convertible_to<RightArg> RightArgRef>
			friend constexpr decltype(auto) operator-=(const proxy&& proxy, RightArgRef&& right) noexcept(false) {
				return proxy.mixfix(XIEITE_FWD(proxy.left), XIEITE_FWD(right));
			}

			template<std::convertible_to<RightArg> RightArgRef>
			friend constexpr decltype(auto) operator<<=(const proxy&& proxy, RightArgRef&& right) noexcept(false) {
				return proxy.mixfix(XIEITE_FWD(proxy.left), XIEITE_FWD(right));
			}

			template<std::convertible_to<RightArg> RightArgRef>
			friend constexpr decltype(auto) operator>>=(const proxy&& proxy, RightArgRef&& right) noexcept(false) {
				return proxy.mixfix(XIEITE_FWD(proxy.left), XIEITE_FWD(right));
			}

			template<std::convertible_to<RightArg> RightArgRef>
			friend constexpr decltype(auto) operator&=(const proxy&& proxy, RightArgRef&& right) noexcept(false) {
				return proxy.mixfix(XIEITE_FWD(proxy.left), XIEITE_FWD(right));
			}

			template<std::convertible_to<RightArg> RightArgRef>
			friend constexpr decltype(auto) operator^=(const proxy&& proxy, RightArgRef&& right) noexcept(false) {
				return proxy.mixfix(XIEITE_FWD(proxy.left), XIEITE_FWD(right));
			}

			template<std::convertible_to<RightArg> RightArgRef>
			friend constexpr decltype(auto) operator|=(const proxy&& proxy, RightArgRef&& right) noexcept(false) {
				return proxy.mixfix(XIEITE_FWD(proxy.left), XIEITE_FWD(right));
			}

			template<std::convertible_to<RightArg> RightArgRef>
			friend constexpr decltype(auto) operator,(const proxy&& proxy, RightArgRef&& right) noexcept(false) {
				return proxy.mixfix(XIEITE_FWD(proxy.left), XIEITE_FWD(right));
			}

		private:
			const xieite::mixfix<Ret(LeftArg, RightArg)>& mixfix;
			LeftArgRef&& left;
		};

	public:
		using xieite::fn<Ret(LeftArg, RightArg)>::fn;

		template<std::convertible_to<LeftArg> LeftArgRef>
		[[nodiscard]] friend constexpr decltype(auto) operator->*(LeftArgRef&& left, const mixfix& mixfix) noexcept(false) {
			return mixfix::proxy<LeftArgRef>(mixfix, XIEITE_FWD(left));
		}

		template<std::convertible_to<LeftArg> LeftArgRef>
		[[nodiscard]] friend constexpr decltype(auto) operator*(LeftArgRef&& left, const mixfix& mixfix) noexcept(false) {
			return mixfix::proxy<LeftArgRef>(mixfix, XIEITE_FWD(left));
		}

		template<std::convertible_to<LeftArg> LeftArgRef>
		[[nodiscard]] friend constexpr decltype(auto) operator/(LeftArgRef&& left, const mixfix& mixfix) noexcept(false) {
			return mixfix::proxy<LeftArgRef>(mixfix, XIEITE_FWD(left));
		}

		template<std::convertible_to<LeftArg> LeftArgRef>
		[[nodiscard]] friend constexpr decltype(auto) operator%(LeftArgRef&& left, const mixfix& mixfix) noexcept(false) {
			return mixfix::proxy<LeftArgRef>(mixfix, XIEITE_FWD(left));
		}

		template<std::convertible_to<LeftArg> LeftArgRef>
		[[nodiscard]] friend constexpr decltype(auto) operator+(LeftArgRef&& left, const mixfix& mixfix) noexcept(false) {
			return mixfix::proxy<LeftArgRef>(mixfix, XIEITE_FWD(left));
		}

		template<std::convertible_to<LeftArg> LeftArgRef>
		[[nodiscard]] friend constexpr decltype(auto) operator-(LeftArgRef&& left, const mixfix& mixfix) noexcept(false) {
			return mixfix::proxy<LeftArgRef>(mixfix, XIEITE_FWD(left));
		}

		template<std::convertible_to<LeftArg> LeftArgRef>
		[[nodiscard]] friend constexpr decltype(auto) operator<<(LeftArgRef&& left, const mixfix& mixfix) noexcept(false) {
			return mixfix::proxy<LeftArgRef>(mixfix, XIEITE_FWD(left));
		}

		template<std::convertible_to<LeftArg> LeftArgRef>
		[[nodiscard]] friend constexpr decltype(auto) operator>>(LeftArgRef&& left, const mixfix& mixfix) noexcept(false) {
			return mixfix::proxy<LeftArgRef>(mixfix, XIEITE_FWD(left));
		}

		template<std::convertible_to<LeftArg> LeftArgRef>
		[[nodiscard]] friend constexpr decltype(auto) operator<=>(LeftArgRef&& left, const mixfix& mixfix) noexcept(false) {
			return mixfix::proxy<LeftArgRef>(mixfix, XIEITE_FWD(left));
		}

		template<std::convertible_to<LeftArg> LeftArgRef>
		[[nodiscard]] friend constexpr decltype(auto) operator<(LeftArgRef&& left, const mixfix& mixfix) noexcept(false) {
			return mixfix::proxy<LeftArgRef>(mixfix, XIEITE_FWD(left));
		}

		template<std::convertible_to<LeftArg> LeftArgRef>
		[[nodiscard]] friend constexpr decltype(auto) operator<=(LeftArgRef&& left, const mixfix& mixfix) noexcept(false) {
			return mixfix::proxy<LeftArgRef>(mixfix, XIEITE_FWD(left));
		}

		template<std::convertible_to<LeftArg> LeftArgRef>
		[[nodiscard]] friend constexpr decltype(auto) operator>(LeftArgRef&& left, const mixfix& mixfix) noexcept(false) {
			return mixfix::proxy<LeftArgRef>(mixfix, XIEITE_FWD(left));
		}

		template<std::convertible_to<LeftArg> LeftArgRef>
		[[nodiscard]] friend constexpr decltype(auto) operator>=(LeftArgRef&& left, const mixfix& mixfix) noexcept(false) {
			return mixfix::proxy<LeftArgRef>(mixfix, XIEITE_FWD(left));
		}

		template<std::convertible_to<LeftArg> LeftArgRef>
		[[nodiscard]] friend constexpr decltype(auto) operator==(LeftArgRef&& left, const mixfix& mixfix) noexcept(false) {
			return mixfix::proxy<LeftArgRef>(mixfix, XIEITE_FWD(left));
		}

		template<std::convertible_to<LeftArg> LeftArgRef>
		[[nodiscard]] friend constexpr decltype(auto) operator!=(LeftArgRef&& left, const mixfix& mixfix) noexcept(false) {
			return mixfix::proxy<LeftArgRef>(mixfix, XIEITE_FWD(left));
		}

		template<std::convertible_to<LeftArg> LeftArgRef>
		[[nodiscard]] friend constexpr decltype(auto) operator&(LeftArgRef&& left, const mixfix& mixfix) noexcept(false) {
			return mixfix::proxy<LeftArgRef>(mixfix, XIEITE_FWD(left));
		}

		template<std::convertible_to<LeftArg> LeftArgRef>
		[[nodiscard]] friend constexpr decltype(auto) operator^(LeftArgRef&& left, const mixfix& mixfix) noexcept(false) {
			return mixfix::proxy<LeftArgRef>(mixfix, XIEITE_FWD(left));
		}

		template<std::convertible_to<LeftArg> LeftArgRef>
		[[nodiscard]] friend constexpr decltype(auto) operator|(LeftArgRef&& left, const mixfix& mixfix) noexcept(false) {
			return mixfix::proxy<LeftArgRef>(mixfix, XIEITE_FWD(left));
		}

		template<std::convertible_to<LeftArg> LeftArgRef>
		[[nodiscard]] friend constexpr decltype(auto) operator&&(LeftArgRef&& left, const mixfix& mixfix) noexcept(false) {
			return mixfix::proxy<LeftArgRef>(mixfix, XIEITE_FWD(left));
		}

		template<std::convertible_to<LeftArg> LeftArgRef>
		[[nodiscard]] friend constexpr decltype(auto) operator||(LeftArgRef&& left, const mixfix& mixfix) noexcept(false) {
			return mixfix::proxy<LeftArgRef>(mixfix, XIEITE_FWD(left));
		}

		template<std::convertible_to<LeftArg> LeftArgRef>
		[[nodiscard]] friend constexpr decltype(auto) operator*=(LeftArgRef&& left, const mixfix& mixfix) noexcept(false) {
			return mixfix::proxy<LeftArgRef>(mixfix, XIEITE_FWD(left));
		}

		template<std::convertible_to<LeftArg> LeftArgRef>
		[[nodiscard]] friend constexpr decltype(auto) operator/=(LeftArgRef&& left, const mixfix& mixfix) noexcept(false) {
			return mixfix::proxy<LeftArgRef>(mixfix, XIEITE_FWD(left));
		}

		template<std::convertible_to<LeftArg> LeftArgRef>
		[[nodiscard]] friend constexpr decltype(auto) operator%=(LeftArgRef&& left, const mixfix& mixfix) noexcept(false) {
			return mixfix::proxy<LeftArgRef>(mixfix, XIEITE_FWD(left));
		}

		template<std::convertible_to<LeftArg> LeftArgRef>
		[[nodiscard]] friend constexpr decltype(auto) operator+=(LeftArgRef&& left, const mixfix& mixfix) noexcept(false) {
			return mixfix::proxy<LeftArgRef>(mixfix, XIEITE_FWD(left));
		}

		template<std::convertible_to<LeftArg> LeftArgRef>
		[[nodiscard]] friend constexpr decltype(auto) operator-=(LeftArgRef&& left, const mixfix& mixfix) noexcept(false) {
			return mixfix::proxy<LeftArgRef>(mixfix, XIEITE_FWD(left));
		}

		template<std::convertible_to<LeftArg> LeftArgRef>
		[[nodiscard]] friend constexpr decltype(auto) operator<<=(LeftArgRef&& left, const mixfix& mixfix) noexcept(false) {
			return mixfix::proxy<LeftArgRef>(mixfix, XIEITE_FWD(left));
		}

		template<std::convertible_to<LeftArg> LeftArgRef>
		[[nodiscard]] friend constexpr decltype(auto) operator>>=(LeftArgRef&& left, const mixfix& mixfix) noexcept(false) {
			return mixfix::proxy<LeftArgRef>(mixfix, XIEITE_FWD(left));
		}

		template<std::convertible_to<LeftArg> LeftArgRef>
		[[nodiscard]] friend constexpr decltype(auto) operator&=(LeftArgRef&& left, const mixfix& mixfix) noexcept(false) {
			return mixfix::proxy<LeftArgRef>(mixfix, XIEITE_FWD(left));
		}

		template<std::convertible_to<LeftArg> LeftArgRef>
		[[nodiscard]] friend constexpr decltype(auto) operator^=(LeftArgRef&& left, const mixfix& mixfix) noexcept(false) {
			return mixfix::proxy<LeftArgRef>(mixfix, XIEITE_FWD(left));
		}

		template<std::convertible_to<LeftArg> LeftArgRef>
		[[nodiscard]] friend constexpr decltype(auto) operator|=(LeftArgRef&& left, const mixfix& mixfix) noexcept(false) {
			return mixfix::proxy<LeftArgRef>(mixfix, XIEITE_FWD(left));
		}

		template<std::convertible_to<LeftArg> LeftArgRef>
		[[nodiscard]] friend constexpr decltype(auto) operator,(LeftArgRef&& left, const mixfix& mixfix) noexcept(false) {
			return mixfix::proxy<LeftArgRef>(mixfix, XIEITE_FWD(left));
		}
	};
}
