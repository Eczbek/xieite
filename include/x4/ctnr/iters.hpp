#pragma once

#include <iterator>
#include <ranges>
#include "../pp/ar.hpp"
#include "../pp/fwd.hpp"

namespace x4 {
	template<std::ranges::range R>
	struct iters {
	private:
		template<typename Iter>
		struct proxy {
			using value_type = Iter;

			Iter value;

			[[nodiscard]] constexpr auto& operator*(this auto& self) noexcept {
				return self.value;
			}

			[[nodiscard]] friend constexpr auto operator==(x4::iters<R>::proxy<Iter> l, x4::iters<R>::proxy<Iter> r)
				X4AR(l.value == r.value)

			[[nodiscard]] friend constexpr auto operator==(x4::iters<R>::proxy<Iter> l, Iter r)
				X4AR(l.value == r)

			[[nodiscard]] friend constexpr auto operator!=(x4::iters<R>::proxy<Iter> l, x4::iters<R>::proxy<Iter> r)
				X4AR(l.value != r.value)

			[[nodiscard]] friend constexpr auto operator!=(x4::iters<R>::proxy<Iter> l, Iter r)
				X4AR(l.value != r)

			[[nodiscard]] friend constexpr auto operator+(x4::iters<R>::proxy<Iter> l, std::iter_difference_t<Iter> r)
				X4AR(x4::iters<R>::proxy(l.value + r))

			constexpr auto operator+=(std::iter_difference_t<Iter> r)
				X4AR(void(this->value += r), *this)

			constexpr auto operator++()
				X4AR(void(++this->value), *this)

			constexpr auto operator++(int)
				X4AR(([this](auto copy) X4ARRET(void(this->value++), copy))(*this))

			[[nodiscard]] friend constexpr auto operator-(x4::iters<R>::proxy<Iter> l, std::iter_difference_t<Iter> r)
				X4AR(x4::iters<R>::proxy(l.value - r))

			constexpr auto operator-=(std::iter_difference_t<Iter> r)
				X4AR(void(this->value -= r), *this)

			constexpr auto operator--()
				X4AR(void(--this->value), *this)

			constexpr auto operator--(int)
				X4AR(([this](auto copy) X4ARRET(void(this->value--), copy))(*this))
		};

		template<typename Iter>
		proxy(Iter) -> proxy<Iter>;

	public:
		R& value;

		[[nodiscard]] constexpr auto begin(this auto&& self)
			X4AR(x4::iters<R>::proxy(std::ranges::begin(X4FWD(self).value)))

		[[nodiscard]] constexpr auto cbegin(this auto&& self)
			X4AR(x4::iters<R>::proxy(std::ranges::cbegin(X4FWD(self).value)))

		[[nodiscard]] constexpr auto rbegin(this auto&& self)
			X4AR(x4::iters<R>::proxy(std::ranges::rbegin(X4FWD(self).value)))

		[[nodiscard]] constexpr auto crbegin(this auto&& self)
			X4AR(x4::iters<R>::proxy(std::ranges::crbegin(X4FWD(self).value)))

		[[nodiscard]] constexpr auto end(this auto&& self)
			X4AR(x4::iters<R>::proxy(std::ranges::end(X4FWD(self).value)))

		[[nodiscard]] constexpr auto cend(this auto&& self)
			X4AR(x4::iters<R>::proxy(std::ranges::cend(X4FWD(self).value)))

		[[nodiscard]] constexpr auto rend(this auto&& self)
			X4AR(x4::iters<R>::proxy(std::ranges::rend(X4FWD(self).value)))

		[[nodiscard]] constexpr auto crend(this auto&& self)
			X4AR(x4::iters<R>::proxy(std::ranges::crend(X4FWD(self).value)))
	};

	template<typename R>
	iters(R) -> iters<R>;
}
