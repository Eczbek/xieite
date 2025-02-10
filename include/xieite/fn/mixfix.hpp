#pragma once

#include <concepts>
#include "../fn/fn.hpp"
#include "../pp/fwd.hpp"
#include "../trait/rm_cp_assign.hpp"
#include "../trait/rm_mv_assign.hpp"

namespace xieite {
	template<typename>
	struct mixfix;

	template<typename Ret, typename Arg>
	struct mixfix<Ret(Arg)> : xieite::fn<Ret(Arg)> {
		using xieite::fn<Ret(Arg)>::fn;

		template<std::convertible_to<Arg> ArgRef>
		[[nodiscard]] constexpr decltype(auto) operator->*(this auto&& self, ArgRef&& arg) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		[[nodiscard]] friend constexpr decltype(auto) operator->*(ArgRef&& arg, const xieite::mixfix<Ret(Arg)>& self) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		[[nodiscard]] constexpr decltype(auto) operator*(this auto&& self, ArgRef&& arg) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		[[nodiscard]] friend constexpr decltype(auto) operator*(ArgRef&& arg, const xieite::mixfix<Ret(Arg)>& self) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		[[nodiscard]] constexpr decltype(auto) operator/(this auto&& self, ArgRef&& arg) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		[[nodiscard]] friend constexpr decltype(auto) operator/(ArgRef&& arg, const xieite::mixfix<Ret(Arg)>& self) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		[[nodiscard]] constexpr decltype(auto) operator%(this auto&& self, ArgRef&& arg) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		[[nodiscard]] friend constexpr decltype(auto) operator%(ArgRef&& arg, const xieite::mixfix<Ret(Arg)>& self) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		[[nodiscard]] constexpr decltype(auto) operator+(this auto&& self, ArgRef&& arg) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		[[nodiscard]] friend constexpr decltype(auto) operator+(ArgRef&& arg, const xieite::mixfix<Ret(Arg)>& self) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		[[nodiscard]] constexpr decltype(auto) operator-(this auto&& self, ArgRef&& arg) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		[[nodiscard]] friend constexpr decltype(auto) operator-(ArgRef&& arg, const xieite::mixfix<Ret(Arg)>& self) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		[[nodiscard]] constexpr decltype(auto) operator<<(this auto&& self, ArgRef&& arg) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		[[nodiscard]] friend constexpr decltype(auto) operator<<(ArgRef&& arg, const xieite::mixfix<Ret(Arg)>& self) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		[[nodiscard]] constexpr decltype(auto) operator>>(this auto&& self, ArgRef&& arg) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		[[nodiscard]] friend constexpr decltype(auto) operator>>(ArgRef&& arg, const xieite::mixfix<Ret(Arg)>& self) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		[[nodiscard]] constexpr decltype(auto) operator<=>(this auto&& self, ArgRef&& arg) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}
		
		template<std::convertible_to<Arg> ArgRef>
		[[nodiscard]] friend constexpr decltype(auto) operator<=>(ArgRef&& arg, const xieite::mixfix<Ret(Arg)>& self) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		[[nodiscard]] constexpr decltype(auto) operator<(this auto&& self, ArgRef&& arg) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		[[nodiscard]] friend constexpr decltype(auto) operator<(ArgRef&& arg, const xieite::mixfix<Ret(Arg)>& self) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		[[nodiscard]] constexpr decltype(auto) operator<=(this auto&& self, ArgRef&& arg) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		[[nodiscard]] friend constexpr decltype(auto) operator<=(ArgRef&& arg, const xieite::mixfix<Ret(Arg)>& self) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		[[nodiscard]] constexpr decltype(auto) operator>(this auto&& self, ArgRef&& arg) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		[[nodiscard]] friend constexpr decltype(auto) operator>(ArgRef&& arg, const xieite::mixfix<Ret(Arg)>& self) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		[[nodiscard]] constexpr decltype(auto) operator>=(this auto&& self, ArgRef&& arg) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		[[nodiscard]] friend constexpr decltype(auto) operator>=(ArgRef&& arg, const xieite::mixfix<Ret(Arg)>& self) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		[[nodiscard]] constexpr decltype(auto) operator==(this auto&& self, ArgRef&& arg) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		[[nodiscard]] friend constexpr decltype(auto) operator==(ArgRef&& arg, const xieite::mixfix<Ret(Arg)>& self) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		[[nodiscard]] constexpr decltype(auto) operator!=(this auto&& self, ArgRef&& arg) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		[[nodiscard]] friend constexpr decltype(auto) operator!=(ArgRef&& arg, const xieite::mixfix<Ret(Arg)>& self) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		[[nodiscard]] constexpr decltype(auto) operator&(this auto&& self, ArgRef&& arg) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		[[nodiscard]] friend constexpr decltype(auto) operator&(ArgRef&& arg, const xieite::mixfix<Ret(Arg)>& self) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		[[nodiscard]] constexpr decltype(auto) operator^(this auto&& self, ArgRef&& arg) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		[[nodiscard]] friend constexpr decltype(auto) operator^(ArgRef&& arg, const xieite::mixfix<Ret(Arg)>& self) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		[[nodiscard]] constexpr decltype(auto) operator|(this auto&& self, ArgRef&& arg) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		[[nodiscard]] friend constexpr decltype(auto) operator|(ArgRef&& arg, const xieite::mixfix<Ret(Arg)>& self) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		[[nodiscard]] constexpr decltype(auto) operator&&(this auto&& self, ArgRef&& arg) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		[[nodiscard]] friend constexpr decltype(auto) operator&&(ArgRef&& arg, const xieite::mixfix<Ret(Arg)>& self) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		[[nodiscard]] constexpr decltype(auto) operator||(this auto&& self, ArgRef&& arg) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		[[nodiscard]] friend constexpr decltype(auto) operator||(ArgRef&& arg, const xieite::mixfix<Ret(Arg)>& self) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		constexpr decltype(auto) operator*=(this auto&& self, ArgRef&& arg) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}
		
		template<std::convertible_to<Arg> ArgRef>
		friend constexpr decltype(auto) operator*=(ArgRef&& arg, const xieite::mixfix<Ret(Arg)>& self) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		constexpr decltype(auto) operator/=(this auto&& self, ArgRef&& arg) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		friend constexpr decltype(auto) operator/=(ArgRef&& arg, const xieite::mixfix<Ret(Arg)>& self) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		constexpr decltype(auto) operator%=(this auto&& self, ArgRef&& arg) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		friend constexpr decltype(auto) operator%=(ArgRef&& arg, const xieite::mixfix<Ret(Arg)>& self) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		constexpr decltype(auto) operator+=(this auto&& self, ArgRef&& arg) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		friend constexpr decltype(auto) operator+=(ArgRef&& arg, const xieite::mixfix<Ret(Arg)>& self) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		constexpr decltype(auto) operator-=(this auto&& self, ArgRef&& arg) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		friend constexpr decltype(auto) operator-=(ArgRef&& arg, const xieite::mixfix<Ret(Arg)>& self) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		constexpr decltype(auto) operator<<=(this auto&& self, ArgRef&& arg) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		friend constexpr decltype(auto) operator<<=(ArgRef&& arg, const xieite::mixfix<Ret(Arg)>& self) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		constexpr decltype(auto) operator>>=(this auto&& self, ArgRef&& arg) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		friend constexpr decltype(auto) operator>>=(ArgRef&& arg, const xieite::mixfix<Ret(Arg)>& self) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		constexpr decltype(auto) operator&=(this auto&& self, ArgRef&& arg) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		friend constexpr decltype(auto) operator&=(ArgRef&& arg, const xieite::mixfix<Ret(Arg)>& self) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		constexpr decltype(auto) operator^=(this auto&& self, ArgRef&& arg) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		friend constexpr decltype(auto) operator^=(ArgRef&& arg, const xieite::mixfix<Ret(Arg)>& self) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		constexpr decltype(auto) operator|=(this auto&& self, ArgRef&& arg) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		friend constexpr decltype(auto) operator|=(ArgRef&& arg, const xieite::mixfix<Ret(Arg)>& self) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		[[nodiscard]] constexpr decltype(auto) operator,(this auto&& self, ArgRef&& arg) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		[[nodiscard]] friend constexpr decltype(auto) operator,(ArgRef&& arg, const xieite::mixfix<Ret(Arg)>& self) noexcept(false) {
			return self(XIEITE_FWD(arg));
		}
	};

	template<typename Ret, typename Arg0, typename Arg1>
	struct mixfix<Ret(Arg0, Arg1)> : xieite::fn<Ret(Arg0, Arg1)> {
	private:
		template<typename ArgRef0>
		struct proxy : xieite::rm_cp_assign, xieite::rm_mv_assign {
		public:
			[[nodiscard]] constexpr proxy(const auto& parent, ArgRef0&& l) noexcept
			: parent(parent), value(XIEITE_FWD(l)) {}

			template<std::convertible_to<Arg1> ArgRef1>
			[[nodiscard]] constexpr decltype(auto) operator->*(this auto&& self, ArgRef1&& r) noexcept(false) {
				return self.parent(self.value, XIEITE_FWD(r));
			}

			template<std::convertible_to<Arg1> ArgRef1>
			[[nodiscard]] constexpr decltype(auto) operator*(this auto&& self, ArgRef1&& r) noexcept(false) {
				return self.parent(self.value, XIEITE_FWD(r));
			}

			template<std::convertible_to<Arg1> ArgRef1>
			[[nodiscard]] constexpr decltype(auto) operator/(this auto&& self, ArgRef1&& r) noexcept(false) {
				return self.parent(self.value, XIEITE_FWD(r));
			}

			template<std::convertible_to<Arg1> ArgRef1>
			[[nodiscard]] constexpr decltype(auto) operator%(this auto&& self, ArgRef1&& r) noexcept(false) {
				return self.parent(self.value, XIEITE_FWD(r));
			}

			template<std::convertible_to<Arg1> ArgRef1>
			[[nodiscard]] constexpr decltype(auto) operator+(this auto&& self, ArgRef1&& r) noexcept(false) {
				return self.parent(self.value, XIEITE_FWD(r));
			}

			template<std::convertible_to<Arg1> ArgRef1>
			[[nodiscard]] constexpr decltype(auto) operator-(this auto&& self, ArgRef1&& r) noexcept(false) {
				return self.parent(self.value, XIEITE_FWD(r));
			}

			template<std::convertible_to<Arg1> ArgRef1>
			[[nodiscard]] constexpr decltype(auto) operator<<(this auto&& self, ArgRef1&& r) noexcept(false) {
				return self.parent(self.value, XIEITE_FWD(r));
			}

			template<std::convertible_to<Arg1> ArgRef1>
			[[nodiscard]] constexpr decltype(auto) operator>>(this auto&& self, ArgRef1&& r) noexcept(false) {
				return self.parent(self.value, XIEITE_FWD(r));
			}

			template<std::convertible_to<Arg1> ArgRef1>
			[[nodiscard]] constexpr decltype(auto) operator<=>(this auto&& self, ArgRef1&& r) noexcept(false) {
				return self.parent(self.value, XIEITE_FWD(r));
			}

			template<std::convertible_to<Arg1> ArgRef1>
			[[nodiscard]] constexpr decltype(auto) operator<(this auto&& self, ArgRef1&& r) noexcept(false) {
				return self.parent(self.value, XIEITE_FWD(r));
			}

			template<std::convertible_to<Arg1> ArgRef1>
			[[nodiscard]] constexpr decltype(auto) operator<=(this auto&& self, ArgRef1&& r) noexcept(false) {
				return self.parent(self.value, XIEITE_FWD(r));
			}

			template<std::convertible_to<Arg1> ArgRef1>
			[[nodiscard]] constexpr decltype(auto) operator>(this auto&& self, ArgRef1&& r) noexcept(false) {
				return self.parent(self.value, XIEITE_FWD(r));
			}

			template<std::convertible_to<Arg1> ArgRef1>
			[[nodiscard]] constexpr decltype(auto) operator>=(this auto&& self, ArgRef1&& r) noexcept(false) {
				return self.parent(self.value, XIEITE_FWD(r));
			}

			template<std::convertible_to<Arg1> ArgRef1>
			[[nodiscard]] constexpr decltype(auto) operator==(this auto&& self, ArgRef1&& r) noexcept(false) {
				return self.parent(self.value, XIEITE_FWD(r));
			}

			template<std::convertible_to<Arg1> ArgRef1>
			[[nodiscard]] constexpr decltype(auto) operator!=(this auto&& self, ArgRef1&& r) noexcept(false) {
				return self.parent(self.value, XIEITE_FWD(r));
			}

			template<std::convertible_to<Arg1> ArgRef1>
			[[nodiscard]] constexpr decltype(auto) operator&(this auto&& self, ArgRef1&& r) noexcept(false) {
				return self.parent(self.value, XIEITE_FWD(r));
			}

			template<std::convertible_to<Arg1> ArgRef1>
			[[nodiscard]] constexpr decltype(auto) operator^(this auto&& self, ArgRef1&& r) noexcept(false) {
				return self.parent(self.value, XIEITE_FWD(r));
			}

			template<std::convertible_to<Arg1> ArgRef1>
			[[nodiscard]] constexpr decltype(auto) operator|(this auto&& self, ArgRef1&& r) noexcept(false) {
				return self.parent(self.value, XIEITE_FWD(r));
			}

			template<std::convertible_to<Arg1> ArgRef1>
			[[nodiscard]] constexpr decltype(auto) operator&&(this auto&& self, ArgRef1&& r) noexcept(false) {
				return self.parent(self.value, XIEITE_FWD(r));
			}

			template<std::convertible_to<Arg1> ArgRef1>
			[[nodiscard]] constexpr decltype(auto) operator||(this auto&& self, ArgRef1&& r) noexcept(false) {
				return self.parent(self.value, XIEITE_FWD(r));
			}

			template<std::convertible_to<Arg1> ArgRef1>
			constexpr decltype(auto) operator*=(this auto&& self, ArgRef1&& r) noexcept(false) {
				return self.parent(self.value, XIEITE_FWD(r));
			}

			template<std::convertible_to<Arg1> ArgRef1>
			constexpr decltype(auto) operator/=(this auto&& self, ArgRef1&& r) noexcept(false) {
				return self.parent(self.value, XIEITE_FWD(r));
			}

			template<std::convertible_to<Arg1> ArgRef1>
			constexpr decltype(auto) operator%=(this auto&& self, ArgRef1&& r) noexcept(false) {
				return self.parent(self.value, XIEITE_FWD(r));
			}

			template<std::convertible_to<Arg1> ArgRef1>
			constexpr decltype(auto) operator+=(this auto&& self, ArgRef1&& r) noexcept(false) {
				return self.parent(self.value, XIEITE_FWD(r));
			}

			template<std::convertible_to<Arg1> ArgRef1>
			constexpr decltype(auto) operator-=(this auto&& self, ArgRef1&& r) noexcept(false) {
				return self.parent(self.value, XIEITE_FWD(r));
			}

			template<std::convertible_to<Arg1> ArgRef1>
			constexpr decltype(auto) operator<<=(this auto&& self, ArgRef1&& r) noexcept(false) {
				return self.parent(self.value, XIEITE_FWD(r));
			}

			template<std::convertible_to<Arg1> ArgRef1>
			constexpr decltype(auto) operator>>=(this auto&& self, ArgRef1&& r) noexcept(false) {
				return self.parent(self.value, XIEITE_FWD(r));
			}

			template<std::convertible_to<Arg1> ArgRef1>
			constexpr decltype(auto) operator&=(this auto&& self, ArgRef1&& r) noexcept(false) {
				return self.parent(self.value, XIEITE_FWD(r));
			}

			template<std::convertible_to<Arg1> ArgRef1>
			constexpr decltype(auto) operator^=(this auto&& self, ArgRef1&& r) noexcept(false) {
				return self.parent(self.value, XIEITE_FWD(r));
			}

			template<std::convertible_to<Arg1> ArgRef1>
			constexpr decltype(auto) operator|=(this auto&& self, ArgRef1&& r) noexcept(false) {
				return self.parent(self.value, XIEITE_FWD(r));
			}

			template<std::convertible_to<Arg1> ArgRef1>
			[[nodiscard]] constexpr decltype(auto) operator,(this auto&& self, ArgRef1&& r) noexcept(false) {
				return self.parent(self.value, XIEITE_FWD(r));
			}

		private:
			const xieite::mixfix<Ret(Arg0, Arg1)>& parent;
			ArgRef0&& value;
		};

	public:
		using xieite::fn<Ret(Arg0, Arg1)>::fn;

		template<std::convertible_to<Arg0> ArgRef0>
		[[nodiscard]] friend constexpr decltype(auto) operator->*(ArgRef0&& l, const xieite::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return xieite::mixfix<Ret(Arg0, Arg1)>::proxy<ArgRef0>(self, XIEITE_FWD(l));
		}

		template<std::convertible_to<Arg0> ArgRef0>
		[[nodiscard]] friend constexpr decltype(auto) operator*(ArgRef0&& l, const xieite::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return xieite::mixfix<Ret(Arg0, Arg1)>::proxy<ArgRef0>(self, XIEITE_FWD(l));
		}

		template<std::convertible_to<Arg0> ArgRef0>
		[[nodiscard]] friend constexpr decltype(auto) operator/(ArgRef0&& l, const xieite::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return xieite::mixfix<Ret(Arg0, Arg1)>::proxy<ArgRef0>(self, XIEITE_FWD(l));
		}

		template<std::convertible_to<Arg0> ArgRef0>
		[[nodiscard]] friend constexpr decltype(auto) operator%(ArgRef0&& l, const xieite::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return xieite::mixfix<Ret(Arg0, Arg1)>::proxy<ArgRef0>(self, XIEITE_FWD(l));
		}

		template<std::convertible_to<Arg0> ArgRef0>
		[[nodiscard]] friend constexpr decltype(auto) operator+(ArgRef0&& l, const xieite::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return xieite::mixfix<Ret(Arg0, Arg1)>::proxy<ArgRef0>(self, XIEITE_FWD(l));
		}

		template<std::convertible_to<Arg0> ArgRef0>
		[[nodiscard]] friend constexpr decltype(auto) operator-(ArgRef0&& l, const xieite::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return xieite::mixfix<Ret(Arg0, Arg1)>::proxy<ArgRef0>(self, XIEITE_FWD(l));
		}

		template<std::convertible_to<Arg0> ArgRef0>
		[[nodiscard]] friend constexpr decltype(auto) operator<<(ArgRef0&& l, const xieite::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return xieite::mixfix<Ret(Arg0, Arg1)>::proxy<ArgRef0>(self, XIEITE_FWD(l));
		}

		template<std::convertible_to<Arg0> ArgRef0>
		[[nodiscard]] friend constexpr decltype(auto) operator>>(ArgRef0&& l, const xieite::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return xieite::mixfix<Ret(Arg0, Arg1)>::proxy<ArgRef0>(self, XIEITE_FWD(l));
		}

		template<std::convertible_to<Arg0> ArgRef0>
		[[nodiscard]] friend constexpr decltype(auto) operator<=>(ArgRef0&& l, const xieite::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return xieite::mixfix<Ret(Arg0, Arg1)>::proxy<ArgRef0>(self, XIEITE_FWD(l));
		}

		template<std::convertible_to<Arg0> ArgRef0>
		[[nodiscard]] friend constexpr decltype(auto) operator<(ArgRef0&& l, const xieite::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return xieite::mixfix<Ret(Arg0, Arg1)>::proxy<ArgRef0>(self, XIEITE_FWD(l));
		}

		template<std::convertible_to<Arg0> ArgRef0>
		[[nodiscard]] friend constexpr decltype(auto) operator<=(ArgRef0&& l, const xieite::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return xieite::mixfix<Ret(Arg0, Arg1)>::proxy<ArgRef0>(self, XIEITE_FWD(l));
		}

		template<std::convertible_to<Arg0> ArgRef0>
		[[nodiscard]] friend constexpr decltype(auto) operator>(ArgRef0&& l, const xieite::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return xieite::mixfix<Ret(Arg0, Arg1)>::proxy<ArgRef0>(self, XIEITE_FWD(l));
		}

		template<std::convertible_to<Arg0> ArgRef0>
		[[nodiscard]] friend constexpr decltype(auto) operator>=(ArgRef0&& l, const xieite::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return xieite::mixfix<Ret(Arg0, Arg1)>::proxy<ArgRef0>(self, XIEITE_FWD(l));
		}

		template<std::convertible_to<Arg0> ArgRef0>
		[[nodiscard]] friend constexpr decltype(auto) operator==(ArgRef0&& l, const xieite::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return xieite::mixfix<Ret(Arg0, Arg1)>::proxy<ArgRef0>(self, XIEITE_FWD(l));
		}

		template<std::convertible_to<Arg0> ArgRef0>
		[[nodiscard]] friend constexpr decltype(auto) operator!=(ArgRef0&& l, const xieite::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return xieite::mixfix<Ret(Arg0, Arg1)>::proxy<ArgRef0>(self, XIEITE_FWD(l));
		}

		template<std::convertible_to<Arg0> ArgRef0>
		[[nodiscard]] friend constexpr decltype(auto) operator&(ArgRef0&& l, const xieite::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return xieite::mixfix<Ret(Arg0, Arg1)>::proxy<ArgRef0>(self, XIEITE_FWD(l));
		}

		template<std::convertible_to<Arg0> ArgRef0>
		[[nodiscard]] friend constexpr decltype(auto) operator^(ArgRef0&& l, const xieite::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return xieite::mixfix<Ret(Arg0, Arg1)>::proxy<ArgRef0>(self, XIEITE_FWD(l));
		}

		template<std::convertible_to<Arg0> ArgRef0>
		[[nodiscard]] friend constexpr decltype(auto) operator|(ArgRef0&& l, const xieite::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return xieite::mixfix<Ret(Arg0, Arg1)>::proxy<ArgRef0>(self, XIEITE_FWD(l));
		}

		template<std::convertible_to<Arg0> ArgRef0>
		[[nodiscard]] friend constexpr decltype(auto) operator&&(ArgRef0&& l, const xieite::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return xieite::mixfix<Ret(Arg0, Arg1)>::proxy<ArgRef0>(self, XIEITE_FWD(l));
		}

		template<std::convertible_to<Arg0> ArgRef0>
		[[nodiscard]] friend constexpr decltype(auto) operator||(ArgRef0&& l, const xieite::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return xieite::mixfix<Ret(Arg0, Arg1)>::proxy<ArgRef0>(self, XIEITE_FWD(l));
		}

		template<std::convertible_to<Arg0> ArgRef0>
		friend constexpr decltype(auto) operator*=(ArgRef0&& l, const xieite::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return xieite::mixfix<Ret(Arg0, Arg1)>::proxy<ArgRef0>(self, XIEITE_FWD(l));
		}

		template<std::convertible_to<Arg0> ArgRef0>
		friend constexpr decltype(auto) operator/=(ArgRef0&& l, const xieite::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return xieite::mixfix<Ret(Arg0, Arg1)>::proxy<ArgRef0>(self, XIEITE_FWD(l));
		}

		template<std::convertible_to<Arg0> ArgRef0>
		friend constexpr decltype(auto) operator%=(ArgRef0&& l, const xieite::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return xieite::mixfix<Ret(Arg0, Arg1)>::proxy<ArgRef0>(self, XIEITE_FWD(l));
		}

		template<std::convertible_to<Arg0> ArgRef0>
		friend constexpr decltype(auto) operator+=(ArgRef0&& l, const xieite::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return xieite::mixfix<Ret(Arg0, Arg1)>::proxy<ArgRef0>(self, XIEITE_FWD(l));
		}

		template<std::convertible_to<Arg0> ArgRef0>
		friend constexpr decltype(auto) operator-=(ArgRef0&& l, const xieite::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return xieite::mixfix<Ret(Arg0, Arg1)>::proxy<ArgRef0>(self, XIEITE_FWD(l));
		}

		template<std::convertible_to<Arg0> ArgRef0>
		friend constexpr decltype(auto) operator<<=(ArgRef0&& l, const xieite::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return xieite::mixfix<Ret(Arg0, Arg1)>::proxy<ArgRef0>(self, XIEITE_FWD(l));
		}

		template<std::convertible_to<Arg0> ArgRef0>
		friend constexpr decltype(auto) operator>>=(ArgRef0&& l, const xieite::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return xieite::mixfix<Ret(Arg0, Arg1)>::proxy<ArgRef0>(self, XIEITE_FWD(l));
		}

		template<std::convertible_to<Arg0> ArgRef0>
		friend constexpr decltype(auto) operator&=(ArgRef0&& l, const xieite::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return xieite::mixfix<Ret(Arg0, Arg1)>::proxy<ArgRef0>(self, XIEITE_FWD(l));
		}

		template<std::convertible_to<Arg0> ArgRef0>
		friend constexpr decltype(auto) operator^=(ArgRef0&& l, const xieite::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return xieite::mixfix<Ret(Arg0, Arg1)>::proxy<ArgRef0>(self, XIEITE_FWD(l));
		}

		template<std::convertible_to<Arg0> ArgRef0>
		friend constexpr decltype(auto) operator|=(ArgRef0&& l, const xieite::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return xieite::mixfix<Ret(Arg0, Arg1)>::proxy<ArgRef0>(self, XIEITE_FWD(l));
		}

		template<std::convertible_to<Arg0> ArgRef0>
		[[nodiscard]] friend constexpr decltype(auto) operator,(ArgRef0&& l, const xieite::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return xieite::mixfix<Ret(Arg0, Arg1)>::proxy<ArgRef0>(self, XIEITE_FWD(l));
		}
	};
}
