#pragma once

#include <concepts>
#include "../fn/fn.hpp"
#include "../pp/fwd.hpp"
#include "../trait/rmcpass.hpp"
#include "../trait/rmmvass.hpp"

namespace x4 {
	template<typename>
	struct mixfix;

	template<typename Ret, typename Arg>
	struct mixfix<Ret(Arg)> : x4::fn<Ret(Arg)> {
		using x4::fn<Ret(Arg)>::fn;

		template<std::convertible_to<Arg> ArgRef>
		[[nodiscard]] constexpr decltype(auto) operator->*(this auto&& self, ArgRef&& arg) noexcept(false) {
			return self(X4FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		[[nodiscard]] friend constexpr decltype(auto) operator->*(ArgRef&& arg, const x4::mixfix<Ret(Arg)>& self) noexcept(false) {
			return self(X4FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		[[nodiscard]] constexpr decltype(auto) operator*(this auto&& self, ArgRef&& arg) noexcept(false) {
			return self(X4FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		[[nodiscard]] friend constexpr decltype(auto) operator*(ArgRef&& arg, const x4::mixfix<Ret(Arg)>& self) noexcept(false) {
			return self(X4FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		[[nodiscard]] constexpr decltype(auto) operator/(this auto&& self, ArgRef&& arg) noexcept(false) {
			return self(X4FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		[[nodiscard]] friend constexpr decltype(auto) operator/(ArgRef&& arg, const x4::mixfix<Ret(Arg)>& self) noexcept(false) {
			return self(X4FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		[[nodiscard]] constexpr decltype(auto) operator%(this auto&& self, ArgRef&& arg) noexcept(false) {
			return self(X4FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		[[nodiscard]] friend constexpr decltype(auto) operator%(ArgRef&& arg, const x4::mixfix<Ret(Arg)>& self) noexcept(false) {
			return self(X4FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		[[nodiscard]] constexpr decltype(auto) operator+(this auto&& self, ArgRef&& arg) noexcept(false) {
			return self(X4FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		[[nodiscard]] friend constexpr decltype(auto) operator+(ArgRef&& arg, const x4::mixfix<Ret(Arg)>& self) noexcept(false) {
			return self(X4FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		[[nodiscard]] constexpr decltype(auto) operator-(this auto&& self, ArgRef&& arg) noexcept(false) {
			return self(X4FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		[[nodiscard]] friend constexpr decltype(auto) operator-(ArgRef&& arg, const x4::mixfix<Ret(Arg)>& self) noexcept(false) {
			return self(X4FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		[[nodiscard]] constexpr decltype(auto) operator<<(this auto&& self, ArgRef&& arg) noexcept(false) {
			return self(X4FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		[[nodiscard]] friend constexpr decltype(auto) operator<<(ArgRef&& arg, const x4::mixfix<Ret(Arg)>& self) noexcept(false) {
			return self(X4FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		[[nodiscard]] constexpr decltype(auto) operator>>(this auto&& self, ArgRef&& arg) noexcept(false) {
			return self(X4FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		[[nodiscard]] friend constexpr decltype(auto) operator>>(ArgRef&& arg, const x4::mixfix<Ret(Arg)>& self) noexcept(false) {
			return self(X4FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		[[nodiscard]] constexpr decltype(auto) operator<=>(this auto&& self, ArgRef&& arg) noexcept(false) {
			return self(X4FWD(arg));
		}
		
		template<std::convertible_to<Arg> ArgRef>
		[[nodiscard]] friend constexpr decltype(auto) operator<=>(ArgRef&& arg, const x4::mixfix<Ret(Arg)>& self) noexcept(false) {
			return self(X4FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		[[nodiscard]] constexpr decltype(auto) operator<(this auto&& self, ArgRef&& arg) noexcept(false) {
			return self(X4FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		[[nodiscard]] friend constexpr decltype(auto) operator<(ArgRef&& arg, const x4::mixfix<Ret(Arg)>& self) noexcept(false) {
			return self(X4FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		[[nodiscard]] constexpr decltype(auto) operator<=(this auto&& self, ArgRef&& arg) noexcept(false) {
			return self(X4FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		[[nodiscard]] friend constexpr decltype(auto) operator<=(ArgRef&& arg, const x4::mixfix<Ret(Arg)>& self) noexcept(false) {
			return self(X4FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		[[nodiscard]] constexpr decltype(auto) operator>(this auto&& self, ArgRef&& arg) noexcept(false) {
			return self(X4FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		[[nodiscard]] friend constexpr decltype(auto) operator>(ArgRef&& arg, const x4::mixfix<Ret(Arg)>& self) noexcept(false) {
			return self(X4FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		[[nodiscard]] constexpr decltype(auto) operator>=(this auto&& self, ArgRef&& arg) noexcept(false) {
			return self(X4FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		[[nodiscard]] friend constexpr decltype(auto) operator>=(ArgRef&& arg, const x4::mixfix<Ret(Arg)>& self) noexcept(false) {
			return self(X4FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		[[nodiscard]] constexpr decltype(auto) operator==(this auto&& self, ArgRef&& arg) noexcept(false) {
			return self(X4FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		[[nodiscard]] friend constexpr decltype(auto) operator==(ArgRef&& arg, const x4::mixfix<Ret(Arg)>& self) noexcept(false) {
			return self(X4FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		[[nodiscard]] constexpr decltype(auto) operator!=(this auto&& self, ArgRef&& arg) noexcept(false) {
			return self(X4FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		[[nodiscard]] friend constexpr decltype(auto) operator!=(ArgRef&& arg, const x4::mixfix<Ret(Arg)>& self) noexcept(false) {
			return self(X4FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		[[nodiscard]] constexpr decltype(auto) operator&(this auto&& self, ArgRef&& arg) noexcept(false) {
			return self(X4FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		[[nodiscard]] friend constexpr decltype(auto) operator&(ArgRef&& arg, const x4::mixfix<Ret(Arg)>& self) noexcept(false) {
			return self(X4FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		[[nodiscard]] constexpr decltype(auto) operator^(this auto&& self, ArgRef&& arg) noexcept(false) {
			return self(X4FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		[[nodiscard]] friend constexpr decltype(auto) operator^(ArgRef&& arg, const x4::mixfix<Ret(Arg)>& self) noexcept(false) {
			return self(X4FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		[[nodiscard]] constexpr decltype(auto) operator|(this auto&& self, ArgRef&& arg) noexcept(false) {
			return self(X4FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		[[nodiscard]] friend constexpr decltype(auto) operator|(ArgRef&& arg, const x4::mixfix<Ret(Arg)>& self) noexcept(false) {
			return self(X4FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		[[nodiscard]] constexpr decltype(auto) operator&&(this auto&& self, ArgRef&& arg) noexcept(false) {
			return self(X4FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		[[nodiscard]] friend constexpr decltype(auto) operator&&(ArgRef&& arg, const x4::mixfix<Ret(Arg)>& self) noexcept(false) {
			return self(X4FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		[[nodiscard]] constexpr decltype(auto) operator||(this auto&& self, ArgRef&& arg) noexcept(false) {
			return self(X4FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		[[nodiscard]] friend constexpr decltype(auto) operator||(ArgRef&& arg, const x4::mixfix<Ret(Arg)>& self) noexcept(false) {
			return self(X4FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		constexpr decltype(auto) operator*=(this auto&& self, ArgRef&& arg) noexcept(false) {
			return self(X4FWD(arg));
		}
		
		template<std::convertible_to<Arg> ArgRef>
		friend constexpr decltype(auto) operator*=(ArgRef&& arg, const x4::mixfix<Ret(Arg)>& self) noexcept(false) {
			return self(X4FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		constexpr decltype(auto) operator/=(this auto&& self, ArgRef&& arg) noexcept(false) {
			return self(X4FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		friend constexpr decltype(auto) operator/=(ArgRef&& arg, const x4::mixfix<Ret(Arg)>& self) noexcept(false) {
			return self(X4FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		constexpr decltype(auto) operator%=(this auto&& self, ArgRef&& arg) noexcept(false) {
			return self(X4FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		friend constexpr decltype(auto) operator%=(ArgRef&& arg, const x4::mixfix<Ret(Arg)>& self) noexcept(false) {
			return self(X4FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		constexpr decltype(auto) operator+=(this auto&& self, ArgRef&& arg) noexcept(false) {
			return self(X4FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		friend constexpr decltype(auto) operator+=(ArgRef&& arg, const x4::mixfix<Ret(Arg)>& self) noexcept(false) {
			return self(X4FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		constexpr decltype(auto) operator-=(this auto&& self, ArgRef&& arg) noexcept(false) {
			return self(X4FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		friend constexpr decltype(auto) operator-=(ArgRef&& arg, const x4::mixfix<Ret(Arg)>& self) noexcept(false) {
			return self(X4FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		constexpr decltype(auto) operator<<=(this auto&& self, ArgRef&& arg) noexcept(false) {
			return self(X4FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		friend constexpr decltype(auto) operator<<=(ArgRef&& arg, const x4::mixfix<Ret(Arg)>& self) noexcept(false) {
			return self(X4FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		constexpr decltype(auto) operator>>=(this auto&& self, ArgRef&& arg) noexcept(false) {
			return self(X4FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		friend constexpr decltype(auto) operator>>=(ArgRef&& arg, const x4::mixfix<Ret(Arg)>& self) noexcept(false) {
			return self(X4FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		constexpr decltype(auto) operator&=(this auto&& self, ArgRef&& arg) noexcept(false) {
			return self(X4FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		friend constexpr decltype(auto) operator&=(ArgRef&& arg, const x4::mixfix<Ret(Arg)>& self) noexcept(false) {
			return self(X4FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		constexpr decltype(auto) operator^=(this auto&& self, ArgRef&& arg) noexcept(false) {
			return self(X4FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		friend constexpr decltype(auto) operator^=(ArgRef&& arg, const x4::mixfix<Ret(Arg)>& self) noexcept(false) {
			return self(X4FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		constexpr decltype(auto) operator|=(this auto&& self, ArgRef&& arg) noexcept(false) {
			return self(X4FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		friend constexpr decltype(auto) operator|=(ArgRef&& arg, const x4::mixfix<Ret(Arg)>& self) noexcept(false) {
			return self(X4FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		[[nodiscard]] constexpr decltype(auto) operator,(this auto&& self, ArgRef&& arg) noexcept(false) {
			return self(X4FWD(arg));
		}

		template<std::convertible_to<Arg> ArgRef>
		[[nodiscard]] friend constexpr decltype(auto) operator,(ArgRef&& arg, const x4::mixfix<Ret(Arg)>& self) noexcept(false) {
			return self(X4FWD(arg));
		}
	};

	template<typename Ret, typename Arg0, typename Arg1>
	struct mixfix<Ret(Arg0, Arg1)> : x4::fn<Ret(Arg0, Arg1)> {
	private:
		template<typename ArgRef0>
		struct proxy : x4::rmcpass, x4::rmmvass {
		public:
			[[nodiscard]] constexpr proxy(const auto& parent, ArgRef0&& l) noexcept
			: parent(parent), value(X4FWD(l)) {}

			template<std::convertible_to<Arg1> ArgRef1>
			[[nodiscard]] constexpr decltype(auto) operator->*(this auto&& self, ArgRef1&& r) noexcept(false) {
				return self.parent(self.value, X4FWD(r));
			}

			template<std::convertible_to<Arg1> ArgRef1>
			[[nodiscard]] constexpr decltype(auto) operator*(this auto&& self, ArgRef1&& r) noexcept(false) {
				return self.parent(self.value, X4FWD(r));
			}

			template<std::convertible_to<Arg1> ArgRef1>
			[[nodiscard]] constexpr decltype(auto) operator/(this auto&& self, ArgRef1&& r) noexcept(false) {
				return self.parent(self.value, X4FWD(r));
			}

			template<std::convertible_to<Arg1> ArgRef1>
			[[nodiscard]] constexpr decltype(auto) operator%(this auto&& self, ArgRef1&& r) noexcept(false) {
				return self.parent(self.value, X4FWD(r));
			}

			template<std::convertible_to<Arg1> ArgRef1>
			[[nodiscard]] constexpr decltype(auto) operator+(this auto&& self, ArgRef1&& r) noexcept(false) {
				return self.parent(self.value, X4FWD(r));
			}

			template<std::convertible_to<Arg1> ArgRef1>
			[[nodiscard]] constexpr decltype(auto) operator-(this auto&& self, ArgRef1&& r) noexcept(false) {
				return self.parent(self.value, X4FWD(r));
			}

			template<std::convertible_to<Arg1> ArgRef1>
			[[nodiscard]] constexpr decltype(auto) operator<<(this auto&& self, ArgRef1&& r) noexcept(false) {
				return self.parent(self.value, X4FWD(r));
			}

			template<std::convertible_to<Arg1> ArgRef1>
			[[nodiscard]] constexpr decltype(auto) operator>>(this auto&& self, ArgRef1&& r) noexcept(false) {
				return self.parent(self.value, X4FWD(r));
			}

			template<std::convertible_to<Arg1> ArgRef1>
			[[nodiscard]] constexpr decltype(auto) operator<=>(this auto&& self, ArgRef1&& r) noexcept(false) {
				return self.parent(self.value, X4FWD(r));
			}

			template<std::convertible_to<Arg1> ArgRef1>
			[[nodiscard]] constexpr decltype(auto) operator<(this auto&& self, ArgRef1&& r) noexcept(false) {
				return self.parent(self.value, X4FWD(r));
			}

			template<std::convertible_to<Arg1> ArgRef1>
			[[nodiscard]] constexpr decltype(auto) operator<=(this auto&& self, ArgRef1&& r) noexcept(false) {
				return self.parent(self.value, X4FWD(r));
			}

			template<std::convertible_to<Arg1> ArgRef1>
			[[nodiscard]] constexpr decltype(auto) operator>(this auto&& self, ArgRef1&& r) noexcept(false) {
				return self.parent(self.value, X4FWD(r));
			}

			template<std::convertible_to<Arg1> ArgRef1>
			[[nodiscard]] constexpr decltype(auto) operator>=(this auto&& self, ArgRef1&& r) noexcept(false) {
				return self.parent(self.value, X4FWD(r));
			}

			template<std::convertible_to<Arg1> ArgRef1>
			[[nodiscard]] constexpr decltype(auto) operator==(this auto&& self, ArgRef1&& r) noexcept(false) {
				return self.parent(self.value, X4FWD(r));
			}

			template<std::convertible_to<Arg1> ArgRef1>
			[[nodiscard]] constexpr decltype(auto) operator!=(this auto&& self, ArgRef1&& r) noexcept(false) {
				return self.parent(self.value, X4FWD(r));
			}

			template<std::convertible_to<Arg1> ArgRef1>
			[[nodiscard]] constexpr decltype(auto) operator&(this auto&& self, ArgRef1&& r) noexcept(false) {
				return self.parent(self.value, X4FWD(r));
			}

			template<std::convertible_to<Arg1> ArgRef1>
			[[nodiscard]] constexpr decltype(auto) operator^(this auto&& self, ArgRef1&& r) noexcept(false) {
				return self.parent(self.value, X4FWD(r));
			}

			template<std::convertible_to<Arg1> ArgRef1>
			[[nodiscard]] constexpr decltype(auto) operator|(this auto&& self, ArgRef1&& r) noexcept(false) {
				return self.parent(self.value, X4FWD(r));
			}

			template<std::convertible_to<Arg1> ArgRef1>
			[[nodiscard]] constexpr decltype(auto) operator&&(this auto&& self, ArgRef1&& r) noexcept(false) {
				return self.parent(self.value, X4FWD(r));
			}

			template<std::convertible_to<Arg1> ArgRef1>
			[[nodiscard]] constexpr decltype(auto) operator||(this auto&& self, ArgRef1&& r) noexcept(false) {
				return self.parent(self.value, X4FWD(r));
			}

			template<std::convertible_to<Arg1> ArgRef1>
			constexpr decltype(auto) operator*=(this auto&& self, ArgRef1&& r) noexcept(false) {
				return self.parent(self.value, X4FWD(r));
			}

			template<std::convertible_to<Arg1> ArgRef1>
			constexpr decltype(auto) operator/=(this auto&& self, ArgRef1&& r) noexcept(false) {
				return self.parent(self.value, X4FWD(r));
			}

			template<std::convertible_to<Arg1> ArgRef1>
			constexpr decltype(auto) operator%=(this auto&& self, ArgRef1&& r) noexcept(false) {
				return self.parent(self.value, X4FWD(r));
			}

			template<std::convertible_to<Arg1> ArgRef1>
			constexpr decltype(auto) operator+=(this auto&& self, ArgRef1&& r) noexcept(false) {
				return self.parent(self.value, X4FWD(r));
			}

			template<std::convertible_to<Arg1> ArgRef1>
			constexpr decltype(auto) operator-=(this auto&& self, ArgRef1&& r) noexcept(false) {
				return self.parent(self.value, X4FWD(r));
			}

			template<std::convertible_to<Arg1> ArgRef1>
			constexpr decltype(auto) operator<<=(this auto&& self, ArgRef1&& r) noexcept(false) {
				return self.parent(self.value, X4FWD(r));
			}

			template<std::convertible_to<Arg1> ArgRef1>
			constexpr decltype(auto) operator>>=(this auto&& self, ArgRef1&& r) noexcept(false) {
				return self.parent(self.value, X4FWD(r));
			}

			template<std::convertible_to<Arg1> ArgRef1>
			constexpr decltype(auto) operator&=(this auto&& self, ArgRef1&& r) noexcept(false) {
				return self.parent(self.value, X4FWD(r));
			}

			template<std::convertible_to<Arg1> ArgRef1>
			constexpr decltype(auto) operator^=(this auto&& self, ArgRef1&& r) noexcept(false) {
				return self.parent(self.value, X4FWD(r));
			}

			template<std::convertible_to<Arg1> ArgRef1>
			constexpr decltype(auto) operator|=(this auto&& self, ArgRef1&& r) noexcept(false) {
				return self.parent(self.value, X4FWD(r));
			}

			template<std::convertible_to<Arg1> ArgRef1>
			[[nodiscard]] constexpr decltype(auto) operator,(this auto&& self, ArgRef1&& r) noexcept(false) {
				return self.parent(self.value, X4FWD(r));
			}

		private:
			const x4::mixfix<Ret(Arg0, Arg1)>& parent;
			ArgRef0&& value;
		};

	public:
		using x4::fn<Ret(Arg0, Arg1)>::fn;

		template<std::convertible_to<Arg0> ArgRef0>
		[[nodiscard]] friend constexpr decltype(auto) operator->*(ArgRef0&& l, const x4::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return x4::mixfix<Ret(Arg0, Arg1)>::proxy<ArgRef0>(self, X4FWD(l));
		}

		template<std::convertible_to<Arg0> ArgRef0>
		[[nodiscard]] friend constexpr decltype(auto) operator*(ArgRef0&& l, const x4::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return x4::mixfix<Ret(Arg0, Arg1)>::proxy<ArgRef0>(self, X4FWD(l));
		}

		template<std::convertible_to<Arg0> ArgRef0>
		[[nodiscard]] friend constexpr decltype(auto) operator/(ArgRef0&& l, const x4::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return x4::mixfix<Ret(Arg0, Arg1)>::proxy<ArgRef0>(self, X4FWD(l));
		}

		template<std::convertible_to<Arg0> ArgRef0>
		[[nodiscard]] friend constexpr decltype(auto) operator%(ArgRef0&& l, const x4::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return x4::mixfix<Ret(Arg0, Arg1)>::proxy<ArgRef0>(self, X4FWD(l));
		}

		template<std::convertible_to<Arg0> ArgRef0>
		[[nodiscard]] friend constexpr decltype(auto) operator+(ArgRef0&& l, const x4::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return x4::mixfix<Ret(Arg0, Arg1)>::proxy<ArgRef0>(self, X4FWD(l));
		}

		template<std::convertible_to<Arg0> ArgRef0>
		[[nodiscard]] friend constexpr decltype(auto) operator-(ArgRef0&& l, const x4::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return x4::mixfix<Ret(Arg0, Arg1)>::proxy<ArgRef0>(self, X4FWD(l));
		}

		template<std::convertible_to<Arg0> ArgRef0>
		[[nodiscard]] friend constexpr decltype(auto) operator<<(ArgRef0&& l, const x4::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return x4::mixfix<Ret(Arg0, Arg1)>::proxy<ArgRef0>(self, X4FWD(l));
		}

		template<std::convertible_to<Arg0> ArgRef0>
		[[nodiscard]] friend constexpr decltype(auto) operator>>(ArgRef0&& l, const x4::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return x4::mixfix<Ret(Arg0, Arg1)>::proxy<ArgRef0>(self, X4FWD(l));
		}

		template<std::convertible_to<Arg0> ArgRef0>
		[[nodiscard]] friend constexpr decltype(auto) operator<=>(ArgRef0&& l, const x4::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return x4::mixfix<Ret(Arg0, Arg1)>::proxy<ArgRef0>(self, X4FWD(l));
		}

		template<std::convertible_to<Arg0> ArgRef0>
		[[nodiscard]] friend constexpr decltype(auto) operator<(ArgRef0&& l, const x4::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return x4::mixfix<Ret(Arg0, Arg1)>::proxy<ArgRef0>(self, X4FWD(l));
		}

		template<std::convertible_to<Arg0> ArgRef0>
		[[nodiscard]] friend constexpr decltype(auto) operator<=(ArgRef0&& l, const x4::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return x4::mixfix<Ret(Arg0, Arg1)>::proxy<ArgRef0>(self, X4FWD(l));
		}

		template<std::convertible_to<Arg0> ArgRef0>
		[[nodiscard]] friend constexpr decltype(auto) operator>(ArgRef0&& l, const x4::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return x4::mixfix<Ret(Arg0, Arg1)>::proxy<ArgRef0>(self, X4FWD(l));
		}

		template<std::convertible_to<Arg0> ArgRef0>
		[[nodiscard]] friend constexpr decltype(auto) operator>=(ArgRef0&& l, const x4::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return x4::mixfix<Ret(Arg0, Arg1)>::proxy<ArgRef0>(self, X4FWD(l));
		}

		template<std::convertible_to<Arg0> ArgRef0>
		[[nodiscard]] friend constexpr decltype(auto) operator==(ArgRef0&& l, const x4::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return x4::mixfix<Ret(Arg0, Arg1)>::proxy<ArgRef0>(self, X4FWD(l));
		}

		template<std::convertible_to<Arg0> ArgRef0>
		[[nodiscard]] friend constexpr decltype(auto) operator!=(ArgRef0&& l, const x4::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return x4::mixfix<Ret(Arg0, Arg1)>::proxy<ArgRef0>(self, X4FWD(l));
		}

		template<std::convertible_to<Arg0> ArgRef0>
		[[nodiscard]] friend constexpr decltype(auto) operator&(ArgRef0&& l, const x4::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return x4::mixfix<Ret(Arg0, Arg1)>::proxy<ArgRef0>(self, X4FWD(l));
		}

		template<std::convertible_to<Arg0> ArgRef0>
		[[nodiscard]] friend constexpr decltype(auto) operator^(ArgRef0&& l, const x4::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return x4::mixfix<Ret(Arg0, Arg1)>::proxy<ArgRef0>(self, X4FWD(l));
		}

		template<std::convertible_to<Arg0> ArgRef0>
		[[nodiscard]] friend constexpr decltype(auto) operator|(ArgRef0&& l, const x4::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return x4::mixfix<Ret(Arg0, Arg1)>::proxy<ArgRef0>(self, X4FWD(l));
		}

		template<std::convertible_to<Arg0> ArgRef0>
		[[nodiscard]] friend constexpr decltype(auto) operator&&(ArgRef0&& l, const x4::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return x4::mixfix<Ret(Arg0, Arg1)>::proxy<ArgRef0>(self, X4FWD(l));
		}

		template<std::convertible_to<Arg0> ArgRef0>
		[[nodiscard]] friend constexpr decltype(auto) operator||(ArgRef0&& l, const x4::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return x4::mixfix<Ret(Arg0, Arg1)>::proxy<ArgRef0>(self, X4FWD(l));
		}

		template<std::convertible_to<Arg0> ArgRef0>
		friend constexpr decltype(auto) operator*=(ArgRef0&& l, const x4::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return x4::mixfix<Ret(Arg0, Arg1)>::proxy<ArgRef0>(self, X4FWD(l));
		}

		template<std::convertible_to<Arg0> ArgRef0>
		friend constexpr decltype(auto) operator/=(ArgRef0&& l, const x4::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return x4::mixfix<Ret(Arg0, Arg1)>::proxy<ArgRef0>(self, X4FWD(l));
		}

		template<std::convertible_to<Arg0> ArgRef0>
		friend constexpr decltype(auto) operator%=(ArgRef0&& l, const x4::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return x4::mixfix<Ret(Arg0, Arg1)>::proxy<ArgRef0>(self, X4FWD(l));
		}

		template<std::convertible_to<Arg0> ArgRef0>
		friend constexpr decltype(auto) operator+=(ArgRef0&& l, const x4::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return x4::mixfix<Ret(Arg0, Arg1)>::proxy<ArgRef0>(self, X4FWD(l));
		}

		template<std::convertible_to<Arg0> ArgRef0>
		friend constexpr decltype(auto) operator-=(ArgRef0&& l, const x4::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return x4::mixfix<Ret(Arg0, Arg1)>::proxy<ArgRef0>(self, X4FWD(l));
		}

		template<std::convertible_to<Arg0> ArgRef0>
		friend constexpr decltype(auto) operator<<=(ArgRef0&& l, const x4::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return x4::mixfix<Ret(Arg0, Arg1)>::proxy<ArgRef0>(self, X4FWD(l));
		}

		template<std::convertible_to<Arg0> ArgRef0>
		friend constexpr decltype(auto) operator>>=(ArgRef0&& l, const x4::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return x4::mixfix<Ret(Arg0, Arg1)>::proxy<ArgRef0>(self, X4FWD(l));
		}

		template<std::convertible_to<Arg0> ArgRef0>
		friend constexpr decltype(auto) operator&=(ArgRef0&& l, const x4::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return x4::mixfix<Ret(Arg0, Arg1)>::proxy<ArgRef0>(self, X4FWD(l));
		}

		template<std::convertible_to<Arg0> ArgRef0>
		friend constexpr decltype(auto) operator^=(ArgRef0&& l, const x4::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return x4::mixfix<Ret(Arg0, Arg1)>::proxy<ArgRef0>(self, X4FWD(l));
		}

		template<std::convertible_to<Arg0> ArgRef0>
		friend constexpr decltype(auto) operator|=(ArgRef0&& l, const x4::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return x4::mixfix<Ret(Arg0, Arg1)>::proxy<ArgRef0>(self, X4FWD(l));
		}

		template<std::convertible_to<Arg0> ArgRef0>
		[[nodiscard]] friend constexpr decltype(auto) operator,(ArgRef0&& l, const x4::mixfix<Ret(Arg0, Arg1)>& self) noexcept(false) {
			return x4::mixfix<Ret(Arg0, Arg1)>::proxy<ArgRef0>(self, X4FWD(l));
		}
	};
}
