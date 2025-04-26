#ifndef DETAIL_XIEITE_HEADER_FN_MIXFIX
#	define DETAIL_XIEITE_HEADER_FN_MIXFIX
#
#	include "../fn/fn.hpp"
#	include "../pp/fwd.hpp"
#	include "../trait/is_ref_to.hpp"
#	include "../trait/rm_cp_assign.hpp"
#	include "../trait/rm_mv_assign.hpp"

namespace xieite {
	template<typename>
	struct mixfix;

	template<typename Ret, typename Arg>
	struct mixfix<Ret(Arg)> : xieite::fn<Ret(Arg)> {
		using xieite::fn<Ret(Arg)>::fn;

		[[nodiscard]] constexpr decltype(auto) operator->*(this auto&& self, xieite::is_ref_to<Arg> auto&& arg) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		[[nodiscard]] friend constexpr decltype(auto) operator->*(xieite::is_ref_to<Arg> auto&& arg, const xieite::mixfix<Ret(Arg)>& self) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		[[nodiscard]] constexpr decltype(auto) operator*(this auto&& self, xieite::is_ref_to<Arg> auto&& arg) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		[[nodiscard]] friend constexpr decltype(auto) operator*(xieite::is_ref_to<Arg> auto&& arg, const xieite::mixfix<Ret(Arg)>& self) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		[[nodiscard]] constexpr decltype(auto) operator/(this auto&& self, xieite::is_ref_to<Arg> auto&& arg) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		[[nodiscard]] friend constexpr decltype(auto) operator/(xieite::is_ref_to<Arg> auto&& arg, const xieite::mixfix<Ret(Arg)>& self) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		[[nodiscard]] constexpr decltype(auto) operator%(this auto&& self, xieite::is_ref_to<Arg> auto&& arg) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		[[nodiscard]] friend constexpr decltype(auto) operator%(xieite::is_ref_to<Arg> auto&& arg, const xieite::mixfix<Ret(Arg)>& self) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		[[nodiscard]] constexpr decltype(auto) operator+(this auto&& self, xieite::is_ref_to<Arg> auto&& arg) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		[[nodiscard]] friend constexpr decltype(auto) operator+(xieite::is_ref_to<Arg> auto&& arg, const xieite::mixfix<Ret(Arg)>& self) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		[[nodiscard]] constexpr decltype(auto) operator-(this auto&& self, xieite::is_ref_to<Arg> auto&& arg) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		[[nodiscard]] friend constexpr decltype(auto) operator-(xieite::is_ref_to<Arg> auto&& arg, const xieite::mixfix<Ret(Arg)>& self) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		[[nodiscard]] constexpr decltype(auto) operator<<(this auto&& self, xieite::is_ref_to<Arg> auto&& arg) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		[[nodiscard]] friend constexpr decltype(auto) operator<<(xieite::is_ref_to<Arg> auto&& arg, const xieite::mixfix<Ret(Arg)>& self) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		[[nodiscard]] constexpr decltype(auto) operator>>(this auto&& self, xieite::is_ref_to<Arg> auto&& arg) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		[[nodiscard]] friend constexpr decltype(auto) operator>>(xieite::is_ref_to<Arg> auto&& arg, const xieite::mixfix<Ret(Arg)>& self) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		[[nodiscard]] constexpr decltype(auto) operator<=>(this auto&& self, xieite::is_ref_to<Arg> auto&& arg) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}
		
		[[nodiscard]] friend constexpr decltype(auto) operator<=>(xieite::is_ref_to<Arg> auto&& arg, const xieite::mixfix<Ret(Arg)>& self) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		[[nodiscard]] constexpr decltype(auto) operator<(this auto&& self, xieite::is_ref_to<Arg> auto&& arg) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		[[nodiscard]] friend constexpr decltype(auto) operator<(xieite::is_ref_to<Arg> auto&& arg, const xieite::mixfix<Ret(Arg)>& self) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		[[nodiscard]] constexpr decltype(auto) operator<=(this auto&& self, xieite::is_ref_to<Arg> auto&& arg) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		[[nodiscard]] friend constexpr decltype(auto) operator<=(xieite::is_ref_to<Arg> auto&& arg, const xieite::mixfix<Ret(Arg)>& self) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		[[nodiscard]] constexpr decltype(auto) operator>(this auto&& self, xieite::is_ref_to<Arg> auto&& arg) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		[[nodiscard]] friend constexpr decltype(auto) operator>(xieite::is_ref_to<Arg> auto&& arg, const xieite::mixfix<Ret(Arg)>& self) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		[[nodiscard]] constexpr decltype(auto) operator>=(this auto&& self, xieite::is_ref_to<Arg> auto&& arg) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		[[nodiscard]] friend constexpr decltype(auto) operator>=(xieite::is_ref_to<Arg> auto&& arg, const xieite::mixfix<Ret(Arg)>& self) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		[[nodiscard]] constexpr decltype(auto) operator==(this auto&& self, xieite::is_ref_to<Arg> auto&& arg) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		[[nodiscard]] friend constexpr decltype(auto) operator==(xieite::is_ref_to<Arg> auto&& arg, const xieite::mixfix<Ret(Arg)>& self) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		[[nodiscard]] constexpr decltype(auto) operator!=(this auto&& self, xieite::is_ref_to<Arg> auto&& arg) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		[[nodiscard]] friend constexpr decltype(auto) operator!=(xieite::is_ref_to<Arg> auto&& arg, const xieite::mixfix<Ret(Arg)>& self) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		[[nodiscard]] constexpr decltype(auto) operator&(this auto&& self, xieite::is_ref_to<Arg> auto&& arg) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		[[nodiscard]] friend constexpr decltype(auto) operator&(xieite::is_ref_to<Arg> auto&& arg, const xieite::mixfix<Ret(Arg)>& self) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		[[nodiscard]] constexpr decltype(auto) operator^(this auto&& self, xieite::is_ref_to<Arg> auto&& arg) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		[[nodiscard]] friend constexpr decltype(auto) operator^(xieite::is_ref_to<Arg> auto&& arg, const xieite::mixfix<Ret(Arg)>& self) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		[[nodiscard]] constexpr decltype(auto) operator|(this auto&& self, xieite::is_ref_to<Arg> auto&& arg) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		[[nodiscard]] friend constexpr decltype(auto) operator|(xieite::is_ref_to<Arg> auto&& arg, const xieite::mixfix<Ret(Arg)>& self) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		[[nodiscard]] constexpr decltype(auto) operator&&(this auto&& self, xieite::is_ref_to<Arg> auto&& arg) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		[[nodiscard]] friend constexpr decltype(auto) operator&&(xieite::is_ref_to<Arg> auto&& arg, const xieite::mixfix<Ret(Arg)>& self) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		[[nodiscard]] constexpr decltype(auto) operator||(this auto&& self, xieite::is_ref_to<Arg> auto&& arg) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		[[nodiscard]] friend constexpr decltype(auto) operator||(xieite::is_ref_to<Arg> auto&& arg, const xieite::mixfix<Ret(Arg)>& self) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		constexpr decltype(auto) operator*=(this auto&& self, xieite::is_ref_to<Arg> auto&& arg) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}
		
		friend constexpr decltype(auto) operator*=(xieite::is_ref_to<Arg> auto&& arg, const xieite::mixfix<Ret(Arg)>& self) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		constexpr decltype(auto) operator/=(this auto&& self, xieite::is_ref_to<Arg> auto&& arg) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		friend constexpr decltype(auto) operator/=(xieite::is_ref_to<Arg> auto&& arg, const xieite::mixfix<Ret(Arg)>& self) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		constexpr decltype(auto) operator%=(this auto&& self, xieite::is_ref_to<Arg> auto&& arg) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		friend constexpr decltype(auto) operator%=(xieite::is_ref_to<Arg> auto&& arg, const xieite::mixfix<Ret(Arg)>& self) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		constexpr decltype(auto) operator+=(this auto&& self, xieite::is_ref_to<Arg> auto&& arg) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		friend constexpr decltype(auto) operator+=(xieite::is_ref_to<Arg> auto&& arg, const xieite::mixfix<Ret(Arg)>& self) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		constexpr decltype(auto) operator-=(this auto&& self, xieite::is_ref_to<Arg> auto&& arg) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		friend constexpr decltype(auto) operator-=(xieite::is_ref_to<Arg> auto&& arg, const xieite::mixfix<Ret(Arg)>& self) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		constexpr decltype(auto) operator<<=(this auto&& self, xieite::is_ref_to<Arg> auto&& arg) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		friend constexpr decltype(auto) operator<<=(xieite::is_ref_to<Arg> auto&& arg, const xieite::mixfix<Ret(Arg)>& self) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		constexpr decltype(auto) operator>>=(this auto&& self, xieite::is_ref_to<Arg> auto&& arg) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		friend constexpr decltype(auto) operator>>=(xieite::is_ref_to<Arg> auto&& arg, const xieite::mixfix<Ret(Arg)>& self) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		constexpr decltype(auto) operator&=(this auto&& self, xieite::is_ref_to<Arg> auto&& arg) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		friend constexpr decltype(auto) operator&=(xieite::is_ref_to<Arg> auto&& arg, const xieite::mixfix<Ret(Arg)>& self) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		constexpr decltype(auto) operator^=(this auto&& self, xieite::is_ref_to<Arg> auto&& arg) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		friend constexpr decltype(auto) operator^=(xieite::is_ref_to<Arg> auto&& arg, const xieite::mixfix<Ret(Arg)>& self) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		constexpr decltype(auto) operator|=(this auto&& self, xieite::is_ref_to<Arg> auto&& arg) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		friend constexpr decltype(auto) operator|=(xieite::is_ref_to<Arg> auto&& arg, const xieite::mixfix<Ret(Arg)>& self) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		[[nodiscard]] constexpr decltype(auto) operator,(this auto&& self, xieite::is_ref_to<Arg> auto&& arg) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		[[nodiscard]] friend constexpr decltype(auto) operator,(xieite::is_ref_to<Arg> auto&& arg, const xieite::mixfix<Ret(Arg)>& self) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}
	};

	template<typename Ret, typename Arg0, typename Arg1>
	struct mixfix<Ret(Arg0, Arg1)> : xieite::fn<Ret(Arg0, Arg1)> {
	private:
		struct proxy : xieite::rm_cp_assign, xieite::rm_mv_assign {
		public:
			[[nodiscard]] constexpr proxy(const auto& parent, Arg0&& lhs) noexcept
			: parent(parent), value(XIEITE_FWD(lhs)) {}

			[[nodiscard]] constexpr decltype(auto) operator->*(this auto&& self, xieite::is_ref_to<Arg1> auto&& rhs) noexcept(false) {
				return self.parent(self.value, XIEITE_FWD(rhs));
			}

			[[nodiscard]] constexpr decltype(auto) operator*(this auto&& self, xieite::is_ref_to<Arg1> auto&& rhs) noexcept(false) {
				return self.parent(self.value, XIEITE_FWD(rhs));
			}

			[[nodiscard]] constexpr decltype(auto) operator/(this auto&& self, xieite::is_ref_to<Arg1> auto&& rhs) noexcept(false) {
				return self.parent(self.value, XIEITE_FWD(rhs));
			}

			[[nodiscard]] constexpr decltype(auto) operator%(this auto&& self, xieite::is_ref_to<Arg1> auto&& rhs) noexcept(false) {
				return self.parent(self.value, XIEITE_FWD(rhs));
			}

			[[nodiscard]] constexpr decltype(auto) operator+(this auto&& self, xieite::is_ref_to<Arg1> auto&& rhs) noexcept(false) {
				return self.parent(self.value, XIEITE_FWD(rhs));
			}

			[[nodiscard]] constexpr decltype(auto) operator-(this auto&& self, xieite::is_ref_to<Arg1> auto&& rhs) noexcept(false) {
				return self.parent(self.value, XIEITE_FWD(rhs));
			}

			[[nodiscard]] constexpr decltype(auto) operator<<(this auto&& self, xieite::is_ref_to<Arg1> auto&& rhs) noexcept(false) {
				return self.parent(self.value, XIEITE_FWD(rhs));
			}

			[[nodiscard]] constexpr decltype(auto) operator>>(this auto&& self, xieite::is_ref_to<Arg1> auto&& rhs) noexcept(false) {
				return self.parent(self.value, XIEITE_FWD(rhs));
			}

			[[nodiscard]] constexpr decltype(auto) operator<=>(this auto&& self, xieite::is_ref_to<Arg1> auto&& rhs) noexcept(false) {
				return self.parent(self.value, XIEITE_FWD(rhs));
			}

			[[nodiscard]] constexpr decltype(auto) operator<(this auto&& self, xieite::is_ref_to<Arg1> auto&& rhs) noexcept(false) {
				return self.parent(self.value, XIEITE_FWD(rhs));
			}

			[[nodiscard]] constexpr decltype(auto) operator<=(this auto&& self, xieite::is_ref_to<Arg1> auto&& rhs) noexcept(false) {
				return self.parent(self.value, XIEITE_FWD(rhs));
			}

			[[nodiscard]] constexpr decltype(auto) operator>(this auto&& self, xieite::is_ref_to<Arg1> auto&& rhs) noexcept(false) {
				return self.parent(self.value, XIEITE_FWD(rhs));
			}

			[[nodiscard]] constexpr decltype(auto) operator>=(this auto&& self, xieite::is_ref_to<Arg1> auto&& rhs) noexcept(false) {
				return self.parent(self.value, XIEITE_FWD(rhs));
			}

			[[nodiscard]] constexpr decltype(auto) operator==(this auto&& self, xieite::is_ref_to<Arg1> auto&& rhs) noexcept(false) {
				return self.parent(self.value, XIEITE_FWD(rhs));
			}

			[[nodiscard]] constexpr decltype(auto) operator!=(this auto&& self, xieite::is_ref_to<Arg1> auto&& rhs) noexcept(false) {
				return self.parent(self.value, XIEITE_FWD(rhs));
			}

			[[nodiscard]] constexpr decltype(auto) operator&(this auto&& self, xieite::is_ref_to<Arg1> auto&& rhs) noexcept(false) {
				return self.parent(self.value, XIEITE_FWD(rhs));
			}

			[[nodiscard]] constexpr decltype(auto) operator^(this auto&& self, xieite::is_ref_to<Arg1> auto&& rhs) noexcept(false) {
				return self.parent(self.value, XIEITE_FWD(rhs));
			}

			[[nodiscard]] constexpr decltype(auto) operator|(this auto&& self, xieite::is_ref_to<Arg1> auto&& rhs) noexcept(false) {
				return self.parent(self.value, XIEITE_FWD(rhs));
			}

			[[nodiscard]] constexpr decltype(auto) operator&&(this auto&& self, xieite::is_ref_to<Arg1> auto&& rhs) noexcept(false) {
				return self.parent(self.value, XIEITE_FWD(rhs));
			}

			[[nodiscard]] constexpr decltype(auto) operator||(this auto&& self, xieite::is_ref_to<Arg1> auto&& rhs) noexcept(false) {
				return self.parent(self.value, XIEITE_FWD(rhs));
			}

			constexpr decltype(auto) operator*=(this auto&& self, xieite::is_ref_to<Arg1> auto&& rhs) noexcept(false) {
				return self.parent(self.value, XIEITE_FWD(rhs));
			}

			constexpr decltype(auto) operator/=(this auto&& self, xieite::is_ref_to<Arg1> auto&& rhs) noexcept(false) {
				return self.parent(self.value, XIEITE_FWD(rhs));
			}

			constexpr decltype(auto) operator%=(this auto&& self, xieite::is_ref_to<Arg1> auto&& rhs) noexcept(false) {
				return self.parent(self.value, XIEITE_FWD(rhs));
			}

			constexpr decltype(auto) operator+=(this auto&& self, xieite::is_ref_to<Arg1> auto&& rhs) noexcept(false) {
				return self.parent(self.value, XIEITE_FWD(rhs));
			}

			constexpr decltype(auto) operator-=(this auto&& self, xieite::is_ref_to<Arg1> auto&& rhs) noexcept(false) {
				return self.parent(self.value, XIEITE_FWD(rhs));
			}

			constexpr decltype(auto) operator<<=(this auto&& self, xieite::is_ref_to<Arg1> auto&& rhs) noexcept(false) {
				return self.parent(self.value, XIEITE_FWD(rhs));
			}

			constexpr decltype(auto) operator>>=(this auto&& self, xieite::is_ref_to<Arg1> auto&& rhs) noexcept(false) {
				return self.parent(self.value, XIEITE_FWD(rhs));
			}

			constexpr decltype(auto) operator&=(this auto&& self, xieite::is_ref_to<Arg1> auto&& rhs) noexcept(false) {
				return self.parent(self.value, XIEITE_FWD(rhs));
			}

			constexpr decltype(auto) operator^=(this auto&& self, xieite::is_ref_to<Arg1> auto&& rhs) noexcept(false) {
				return self.parent(self.value, XIEITE_FWD(rhs));
			}

			constexpr decltype(auto) operator|=(this auto&& self, xieite::is_ref_to<Arg1> auto&& rhs) noexcept(false) {
				return self.parent(self.value, XIEITE_FWD(rhs));
			}

			[[nodiscard]] constexpr decltype(auto) operator,(this auto&& self, xieite::is_ref_to<Arg1> auto&& rhs) noexcept(false) {
				return self.parent(self.value, XIEITE_FWD(rhs));
			}

		private:
			const xieite::mixfix<Ret(Arg0, Arg1)>& parent;
			Arg0&& value;
		};

	public:
		using xieite::fn<Ret(Arg0, Arg1)>::fn;

		[[nodiscard]] friend constexpr auto operator->*(xieite::is_ref_to<Arg0> auto&& lhs, const xieite::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return xieite::mixfix<Ret(Arg0, Arg1)>::proxy(self, XIEITE_FWD(lhs));
		}

		[[nodiscard]] friend constexpr auto operator*(xieite::is_ref_to<Arg0> auto&& lhs, const xieite::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return xieite::mixfix<Ret(Arg0, Arg1)>::proxy(self, XIEITE_FWD(lhs));
		}

		[[nodiscard]] friend constexpr auto operator/(xieite::is_ref_to<Arg0> auto&& lhs, const xieite::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return xieite::mixfix<Ret(Arg0, Arg1)>::proxy(self, XIEITE_FWD(lhs));
		}

		[[nodiscard]] friend constexpr auto operator%(xieite::is_ref_to<Arg0> auto&& lhs, const xieite::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return xieite::mixfix<Ret(Arg0, Arg1)>::proxy(self, XIEITE_FWD(lhs));
		}

		[[nodiscard]] friend constexpr auto operator+(xieite::is_ref_to<Arg0> auto&& lhs, const xieite::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return xieite::mixfix<Ret(Arg0, Arg1)>::proxy(self, XIEITE_FWD(lhs));
		}

		[[nodiscard]] friend constexpr auto operator-(xieite::is_ref_to<Arg0> auto&& lhs, const xieite::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return xieite::mixfix<Ret(Arg0, Arg1)>::proxy(self, XIEITE_FWD(lhs));
		}

		[[nodiscard]] friend constexpr auto operator<<(xieite::is_ref_to<Arg0> auto&& lhs, const xieite::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return xieite::mixfix<Ret(Arg0, Arg1)>::proxy(self, XIEITE_FWD(lhs));
		}

		[[nodiscard]] friend constexpr auto operator>>(xieite::is_ref_to<Arg0> auto&& lhs, const xieite::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return xieite::mixfix<Ret(Arg0, Arg1)>::proxy(self, XIEITE_FWD(lhs));
		}

		[[nodiscard]] friend constexpr auto operator<=>(xieite::is_ref_to<Arg0> auto&& lhs, const xieite::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return xieite::mixfix<Ret(Arg0, Arg1)>::proxy(self, XIEITE_FWD(lhs));
		}

		[[nodiscard]] friend constexpr auto operator<(xieite::is_ref_to<Arg0> auto&& lhs, const xieite::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return xieite::mixfix<Ret(Arg0, Arg1)>::proxy(self, XIEITE_FWD(lhs));
		}

		[[nodiscard]] friend constexpr auto operator<=(xieite::is_ref_to<Arg0> auto&& lhs, const xieite::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return xieite::mixfix<Ret(Arg0, Arg1)>::proxy(self, XIEITE_FWD(lhs));
		}

		[[nodiscard]] friend constexpr auto operator>(xieite::is_ref_to<Arg0> auto&& lhs, const xieite::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return xieite::mixfix<Ret(Arg0, Arg1)>::proxy(self, XIEITE_FWD(lhs));
		}

		[[nodiscard]] friend constexpr auto operator>=(xieite::is_ref_to<Arg0> auto&& lhs, const xieite::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return xieite::mixfix<Ret(Arg0, Arg1)>::proxy(self, XIEITE_FWD(lhs));
		}

		[[nodiscard]] friend constexpr auto operator==(xieite::is_ref_to<Arg0> auto&& lhs, const xieite::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return xieite::mixfix<Ret(Arg0, Arg1)>::proxy(self, XIEITE_FWD(lhs));
		}

		[[nodiscard]] friend constexpr auto operator!=(xieite::is_ref_to<Arg0> auto&& lhs, const xieite::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return xieite::mixfix<Ret(Arg0, Arg1)>::proxy(self, XIEITE_FWD(lhs));
		}

		[[nodiscard]] friend constexpr auto operator&(xieite::is_ref_to<Arg0> auto&& lhs, const xieite::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return xieite::mixfix<Ret(Arg0, Arg1)>::proxy(self, XIEITE_FWD(lhs));
		}

		[[nodiscard]] friend constexpr auto operator^(xieite::is_ref_to<Arg0> auto&& lhs, const xieite::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return xieite::mixfix<Ret(Arg0, Arg1)>::proxy(self, XIEITE_FWD(lhs));
		}

		[[nodiscard]] friend constexpr auto operator|(xieite::is_ref_to<Arg0> auto&& lhs, const xieite::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return xieite::mixfix<Ret(Arg0, Arg1)>::proxy(self, XIEITE_FWD(lhs));
		}

		[[nodiscard]] friend constexpr auto operator&&(xieite::is_ref_to<Arg0> auto&& lhs, const xieite::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return xieite::mixfix<Ret(Arg0, Arg1)>::proxy(self, XIEITE_FWD(lhs));
		}

		[[nodiscard]] friend constexpr auto operator||(xieite::is_ref_to<Arg0> auto&& lhs, const xieite::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return xieite::mixfix<Ret(Arg0, Arg1)>::proxy(self, XIEITE_FWD(lhs));
		}

		friend constexpr auto operator*=(xieite::is_ref_to<Arg0> auto&& lhs, const xieite::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return xieite::mixfix<Ret(Arg0, Arg1)>::proxy(self, XIEITE_FWD(lhs));
		}

		friend constexpr auto operator/=(xieite::is_ref_to<Arg0> auto&& lhs, const xieite::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return xieite::mixfix<Ret(Arg0, Arg1)>::proxy(self, XIEITE_FWD(lhs));
		}

		friend constexpr auto operator%=(xieite::is_ref_to<Arg0> auto&& lhs, const xieite::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return xieite::mixfix<Ret(Arg0, Arg1)>::proxy(self, XIEITE_FWD(lhs));
		}

		friend constexpr auto operator+=(xieite::is_ref_to<Arg0> auto&& lhs, const xieite::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return xieite::mixfix<Ret(Arg0, Arg1)>::proxy(self, XIEITE_FWD(lhs));
		}

		friend constexpr auto operator-=(xieite::is_ref_to<Arg0> auto&& lhs, const xieite::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return xieite::mixfix<Ret(Arg0, Arg1)>::proxy(self, XIEITE_FWD(lhs));
		}

		friend constexpr auto operator<<=(xieite::is_ref_to<Arg0> auto&& lhs, const xieite::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return xieite::mixfix<Ret(Arg0, Arg1)>::proxy(self, XIEITE_FWD(lhs));
		}

		friend constexpr auto operator>>=(xieite::is_ref_to<Arg0> auto&& lhs, const xieite::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return xieite::mixfix<Ret(Arg0, Arg1)>::proxy(self, XIEITE_FWD(lhs));
		}

		friend constexpr auto operator&=(xieite::is_ref_to<Arg0> auto&& lhs, const xieite::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return xieite::mixfix<Ret(Arg0, Arg1)>::proxy(self, XIEITE_FWD(lhs));
		}

		friend constexpr auto operator^=(xieite::is_ref_to<Arg0> auto&& lhs, const xieite::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return xieite::mixfix<Ret(Arg0, Arg1)>::proxy(self, XIEITE_FWD(lhs));
		}

		friend constexpr auto operator|=(xieite::is_ref_to<Arg0> auto&& lhs, const xieite::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return xieite::mixfix<Ret(Arg0, Arg1)>::proxy(self, XIEITE_FWD(lhs));
		}

		[[nodiscard]] friend constexpr auto operator,(xieite::is_ref_to<Arg0> auto&& lhs, const xieite::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return xieite::mixfix<Ret(Arg0, Arg1)>::proxy(self, XIEITE_FWD(lhs));
		}
	};
}

#endif
