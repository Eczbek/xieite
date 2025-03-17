#pragma once

#include <concepts>
#include "../fn/fn.hpp"
#include "../pp/fwd.hpp"
#include "../trait/is_ref_to.hpp"
#include "../trait/rm_cp_assign.hpp"
#include "../trait/rm_mv_assign.hpp"

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
			[[nodiscard]] constexpr proxy(const auto& parent, Arg0&& l) noexcept
			: parent(parent), value(XIEITE_FWD(l)) {}

			[[nodiscard]] constexpr decltype(auto) operator->*(this auto&& self, xieite::is_ref_to<Arg1> auto&& r) noexcept(false) {
				return self.parent(self.value, XIEITE_FWD(r));
			}

			[[nodiscard]] constexpr decltype(auto) operator*(this auto&& self, xieite::is_ref_to<Arg1> auto&& r) noexcept(false) {
				return self.parent(self.value, XIEITE_FWD(r));
			}

			[[nodiscard]] constexpr decltype(auto) operator/(this auto&& self, xieite::is_ref_to<Arg1> auto&& r) noexcept(false) {
				return self.parent(self.value, XIEITE_FWD(r));
			}

			[[nodiscard]] constexpr decltype(auto) operator%(this auto&& self, xieite::is_ref_to<Arg1> auto&& r) noexcept(false) {
				return self.parent(self.value, XIEITE_FWD(r));
			}

			[[nodiscard]] constexpr decltype(auto) operator+(this auto&& self, xieite::is_ref_to<Arg1> auto&& r) noexcept(false) {
				return self.parent(self.value, XIEITE_FWD(r));
			}

			[[nodiscard]] constexpr decltype(auto) operator-(this auto&& self, xieite::is_ref_to<Arg1> auto&& r) noexcept(false) {
				return self.parent(self.value, XIEITE_FWD(r));
			}

			[[nodiscard]] constexpr decltype(auto) operator<<(this auto&& self, xieite::is_ref_to<Arg1> auto&& r) noexcept(false) {
				return self.parent(self.value, XIEITE_FWD(r));
			}

			[[nodiscard]] constexpr decltype(auto) operator>>(this auto&& self, xieite::is_ref_to<Arg1> auto&& r) noexcept(false) {
				return self.parent(self.value, XIEITE_FWD(r));
			}

			[[nodiscard]] constexpr decltype(auto) operator<=>(this auto&& self, xieite::is_ref_to<Arg1> auto&& r) noexcept(false) {
				return self.parent(self.value, XIEITE_FWD(r));
			}

			[[nodiscard]] constexpr decltype(auto) operator<(this auto&& self, xieite::is_ref_to<Arg1> auto&& r) noexcept(false) {
				return self.parent(self.value, XIEITE_FWD(r));
			}

			[[nodiscard]] constexpr decltype(auto) operator<=(this auto&& self, xieite::is_ref_to<Arg1> auto&& r) noexcept(false) {
				return self.parent(self.value, XIEITE_FWD(r));
			}

			[[nodiscard]] constexpr decltype(auto) operator>(this auto&& self, xieite::is_ref_to<Arg1> auto&& r) noexcept(false) {
				return self.parent(self.value, XIEITE_FWD(r));
			}

			[[nodiscard]] constexpr decltype(auto) operator>=(this auto&& self, xieite::is_ref_to<Arg1> auto&& r) noexcept(false) {
				return self.parent(self.value, XIEITE_FWD(r));
			}

			[[nodiscard]] constexpr decltype(auto) operator==(this auto&& self, xieite::is_ref_to<Arg1> auto&& r) noexcept(false) {
				return self.parent(self.value, XIEITE_FWD(r));
			}

			[[nodiscard]] constexpr decltype(auto) operator!=(this auto&& self, xieite::is_ref_to<Arg1> auto&& r) noexcept(false) {
				return self.parent(self.value, XIEITE_FWD(r));
			}

			[[nodiscard]] constexpr decltype(auto) operator&(this auto&& self, xieite::is_ref_to<Arg1> auto&& r) noexcept(false) {
				return self.parent(self.value, XIEITE_FWD(r));
			}

			[[nodiscard]] constexpr decltype(auto) operator^(this auto&& self, xieite::is_ref_to<Arg1> auto&& r) noexcept(false) {
				return self.parent(self.value, XIEITE_FWD(r));
			}

			[[nodiscard]] constexpr decltype(auto) operator|(this auto&& self, xieite::is_ref_to<Arg1> auto&& r) noexcept(false) {
				return self.parent(self.value, XIEITE_FWD(r));
			}

			[[nodiscard]] constexpr decltype(auto) operator&&(this auto&& self, xieite::is_ref_to<Arg1> auto&& r) noexcept(false) {
				return self.parent(self.value, XIEITE_FWD(r));
			}

			[[nodiscard]] constexpr decltype(auto) operator||(this auto&& self, xieite::is_ref_to<Arg1> auto&& r) noexcept(false) {
				return self.parent(self.value, XIEITE_FWD(r));
			}

			constexpr decltype(auto) operator*=(this auto&& self, xieite::is_ref_to<Arg1> auto&& r) noexcept(false) {
				return self.parent(self.value, XIEITE_FWD(r));
			}

			constexpr decltype(auto) operator/=(this auto&& self, xieite::is_ref_to<Arg1> auto&& r) noexcept(false) {
				return self.parent(self.value, XIEITE_FWD(r));
			}

			constexpr decltype(auto) operator%=(this auto&& self, xieite::is_ref_to<Arg1> auto&& r) noexcept(false) {
				return self.parent(self.value, XIEITE_FWD(r));
			}

			constexpr decltype(auto) operator+=(this auto&& self, xieite::is_ref_to<Arg1> auto&& r) noexcept(false) {
				return self.parent(self.value, XIEITE_FWD(r));
			}

			constexpr decltype(auto) operator-=(this auto&& self, xieite::is_ref_to<Arg1> auto&& r) noexcept(false) {
				return self.parent(self.value, XIEITE_FWD(r));
			}

			constexpr decltype(auto) operator<<=(this auto&& self, xieite::is_ref_to<Arg1> auto&& r) noexcept(false) {
				return self.parent(self.value, XIEITE_FWD(r));
			}

			constexpr decltype(auto) operator>>=(this auto&& self, xieite::is_ref_to<Arg1> auto&& r) noexcept(false) {
				return self.parent(self.value, XIEITE_FWD(r));
			}

			constexpr decltype(auto) operator&=(this auto&& self, xieite::is_ref_to<Arg1> auto&& r) noexcept(false) {
				return self.parent(self.value, XIEITE_FWD(r));
			}

			constexpr decltype(auto) operator^=(this auto&& self, xieite::is_ref_to<Arg1> auto&& r) noexcept(false) {
				return self.parent(self.value, XIEITE_FWD(r));
			}

			constexpr decltype(auto) operator|=(this auto&& self, xieite::is_ref_to<Arg1> auto&& r) noexcept(false) {
				return self.parent(self.value, XIEITE_FWD(r));
			}

			[[nodiscard]] constexpr decltype(auto) operator,(this auto&& self, xieite::is_ref_to<Arg1> auto&& r) noexcept(false) {
				return self.parent(self.value, XIEITE_FWD(r));
			}

		private:
			const xieite::mixfix<Ret(Arg0, Arg1)>& parent;
			Arg0&& value;
		};

	public:
		using xieite::fn<Ret(Arg0, Arg1)>::fn;

		[[nodiscard]] friend constexpr auto operator->*(xieite::is_ref_to<Arg0> auto&& l, const xieite::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return xieite::mixfix<Ret(Arg0, Arg1)>::proxy(self, XIEITE_FWD(l));
		}

		[[nodiscard]] friend constexpr auto operator*(xieite::is_ref_to<Arg0> auto&& l, const xieite::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return xieite::mixfix<Ret(Arg0, Arg1)>::proxy(self, XIEITE_FWD(l));
		}

		[[nodiscard]] friend constexpr auto operator/(xieite::is_ref_to<Arg0> auto&& l, const xieite::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return xieite::mixfix<Ret(Arg0, Arg1)>::proxy(self, XIEITE_FWD(l));
		}

		[[nodiscard]] friend constexpr auto operator%(xieite::is_ref_to<Arg0> auto&& l, const xieite::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return xieite::mixfix<Ret(Arg0, Arg1)>::proxy(self, XIEITE_FWD(l));
		}

		[[nodiscard]] friend constexpr auto operator+(xieite::is_ref_to<Arg0> auto&& l, const xieite::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return xieite::mixfix<Ret(Arg0, Arg1)>::proxy(self, XIEITE_FWD(l));
		}

		[[nodiscard]] friend constexpr auto operator-(xieite::is_ref_to<Arg0> auto&& l, const xieite::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return xieite::mixfix<Ret(Arg0, Arg1)>::proxy(self, XIEITE_FWD(l));
		}

		[[nodiscard]] friend constexpr auto operator<<(xieite::is_ref_to<Arg0> auto&& l, const xieite::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return xieite::mixfix<Ret(Arg0, Arg1)>::proxy(self, XIEITE_FWD(l));
		}

		[[nodiscard]] friend constexpr auto operator>>(xieite::is_ref_to<Arg0> auto&& l, const xieite::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return xieite::mixfix<Ret(Arg0, Arg1)>::proxy(self, XIEITE_FWD(l));
		}

		[[nodiscard]] friend constexpr auto operator<=>(xieite::is_ref_to<Arg0> auto&& l, const xieite::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return xieite::mixfix<Ret(Arg0, Arg1)>::proxy(self, XIEITE_FWD(l));
		}

		[[nodiscard]] friend constexpr auto operator<(xieite::is_ref_to<Arg0> auto&& l, const xieite::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return xieite::mixfix<Ret(Arg0, Arg1)>::proxy(self, XIEITE_FWD(l));
		}

		[[nodiscard]] friend constexpr auto operator<=(xieite::is_ref_to<Arg0> auto&& l, const xieite::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return xieite::mixfix<Ret(Arg0, Arg1)>::proxy(self, XIEITE_FWD(l));
		}

		[[nodiscard]] friend constexpr auto operator>(xieite::is_ref_to<Arg0> auto&& l, const xieite::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return xieite::mixfix<Ret(Arg0, Arg1)>::proxy(self, XIEITE_FWD(l));
		}

		[[nodiscard]] friend constexpr auto operator>=(xieite::is_ref_to<Arg0> auto&& l, const xieite::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return xieite::mixfix<Ret(Arg0, Arg1)>::proxy(self, XIEITE_FWD(l));
		}

		[[nodiscard]] friend constexpr auto operator==(xieite::is_ref_to<Arg0> auto&& l, const xieite::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return xieite::mixfix<Ret(Arg0, Arg1)>::proxy(self, XIEITE_FWD(l));
		}

		[[nodiscard]] friend constexpr auto operator!=(xieite::is_ref_to<Arg0> auto&& l, const xieite::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return xieite::mixfix<Ret(Arg0, Arg1)>::proxy(self, XIEITE_FWD(l));
		}

		[[nodiscard]] friend constexpr auto operator&(xieite::is_ref_to<Arg0> auto&& l, const xieite::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return xieite::mixfix<Ret(Arg0, Arg1)>::proxy(self, XIEITE_FWD(l));
		}

		[[nodiscard]] friend constexpr auto operator^(xieite::is_ref_to<Arg0> auto&& l, const xieite::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return xieite::mixfix<Ret(Arg0, Arg1)>::proxy(self, XIEITE_FWD(l));
		}

		[[nodiscard]] friend constexpr auto operator|(xieite::is_ref_to<Arg0> auto&& l, const xieite::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return xieite::mixfix<Ret(Arg0, Arg1)>::proxy(self, XIEITE_FWD(l));
		}

		[[nodiscard]] friend constexpr auto operator&&(xieite::is_ref_to<Arg0> auto&& l, const xieite::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return xieite::mixfix<Ret(Arg0, Arg1)>::proxy(self, XIEITE_FWD(l));
		}

		[[nodiscard]] friend constexpr auto operator||(xieite::is_ref_to<Arg0> auto&& l, const xieite::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return xieite::mixfix<Ret(Arg0, Arg1)>::proxy(self, XIEITE_FWD(l));
		}

		friend constexpr auto operator*=(xieite::is_ref_to<Arg0> auto&& l, const xieite::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return xieite::mixfix<Ret(Arg0, Arg1)>::proxy(self, XIEITE_FWD(l));
		}

		friend constexpr auto operator/=(xieite::is_ref_to<Arg0> auto&& l, const xieite::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return xieite::mixfix<Ret(Arg0, Arg1)>::proxy(self, XIEITE_FWD(l));
		}

		friend constexpr auto operator%=(xieite::is_ref_to<Arg0> auto&& l, const xieite::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return xieite::mixfix<Ret(Arg0, Arg1)>::proxy(self, XIEITE_FWD(l));
		}

		friend constexpr auto operator+=(xieite::is_ref_to<Arg0> auto&& l, const xieite::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return xieite::mixfix<Ret(Arg0, Arg1)>::proxy(self, XIEITE_FWD(l));
		}

		friend constexpr auto operator-=(xieite::is_ref_to<Arg0> auto&& l, const xieite::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return xieite::mixfix<Ret(Arg0, Arg1)>::proxy(self, XIEITE_FWD(l));
		}

		friend constexpr auto operator<<=(xieite::is_ref_to<Arg0> auto&& l, const xieite::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return xieite::mixfix<Ret(Arg0, Arg1)>::proxy(self, XIEITE_FWD(l));
		}

		friend constexpr auto operator>>=(xieite::is_ref_to<Arg0> auto&& l, const xieite::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return xieite::mixfix<Ret(Arg0, Arg1)>::proxy(self, XIEITE_FWD(l));
		}

		friend constexpr auto operator&=(xieite::is_ref_to<Arg0> auto&& l, const xieite::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return xieite::mixfix<Ret(Arg0, Arg1)>::proxy(self, XIEITE_FWD(l));
		}

		friend constexpr auto operator^=(xieite::is_ref_to<Arg0> auto&& l, const xieite::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return xieite::mixfix<Ret(Arg0, Arg1)>::proxy(self, XIEITE_FWD(l));
		}

		friend constexpr auto operator|=(xieite::is_ref_to<Arg0> auto&& l, const xieite::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return xieite::mixfix<Ret(Arg0, Arg1)>::proxy(self, XIEITE_FWD(l));
		}

		[[nodiscard]] friend constexpr auto operator,(xieite::is_ref_to<Arg0> auto&& l, const xieite::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return xieite::mixfix<Ret(Arg0, Arg1)>::proxy(self, XIEITE_FWD(l));
		}
	};
}
