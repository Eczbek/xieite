#pragma once

#include <type_traits>
#include "../math/pow.hpp"
#include "../trait/isarith.hpp"
#include "../traitrmcpass.hpp"
#include "../traitrmmvass.hpp"

namespace x4 {
	template<x4::isarith T>
	struct exp {
	private:
		struct proxy : x4:rmcpass, x4:rmmvass {
		public:
			[[nodiscard]] explicit constexpr proxy(T n) noexcept
			: value(n) {}

			template<x4::isarith U>
			[[nodiscard]] friend constexpr std::common_type_t<T, U> operator*(U base, x4::exp<T>::proxy proxy) noexcept {
				return static_cast<std::common_type_t<T, U>>(x4::pow(base, proxy.value));
			}

		private:
			T value;
		};

	public:
		[[nodiscard]] explicit constexpr exp(T n) noexcept
		: value(n) {}

		template<x4::isarith U>
		[[nodiscard]] explicit(false) constexpr operator std::common_type_t<T, U>() const noexcept {
			return static_cast<std::common_type_t<T, U>>(this->value);
		}

		[[nodiscard]] constexpr x4::exp<T>::proxy operator*() const noexcept {
			return x4::exp<T>::proxy(this->value);
		}

	private:
		T value;
	};

	template<typename T>
	exp(T) -> exp<T>;
}
