module;

#include <xieite/arrow.hpp>
#include <xieite/fwd.hpp>

export module xieite:iters;

import std;

export namespace xieite {
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

			[[nodiscard]] friend constexpr auto operator==(xieite::iters<R>::proxy<Iter> l, xieite::iters<R>::proxy<Iter> r)
				XIEITE_ARROW(l.value == r.value)

			[[nodiscard]] friend constexpr auto operator==(xieite::iters<R>::proxy<Iter> l, Iter r)
				XIEITE_ARROW(l.value == r)

			[[nodiscard]] friend constexpr auto operator!=(xieite::iters<R>::proxy<Iter> l, xieite::iters<R>::proxy<Iter> r)
				XIEITE_ARROW(l.value != r.value)

			[[nodiscard]] friend constexpr auto operator!=(xieite::iters<R>::proxy<Iter> l, Iter r)
				XIEITE_ARROW(l.value != r)

			[[nodiscard]] friend constexpr auto operator+(xieite::iters<R>::proxy<Iter> l, std::iter_difference_t<Iter> r)
				XIEITE_ARROW(xieite::iters<R>::proxy(l.value + r))

			constexpr auto operator+=(std::iter_difference_t<Iter> r)
				XIEITE_ARROW(void(this->value += r), *this)

			constexpr auto operator++()
				XIEITE_ARROW(void(++this->value), *this)

			constexpr auto operator++(int)
				XIEITE_ARROW(([this](auto copy) XIEITE_ARROW_RET(void(this->value++), copy))(*this))

			[[nodiscard]] friend constexpr auto operator-(xieite::iters<R>::proxy<Iter> l, std::iter_difference_t<Iter> r)
				XIEITE_ARROW(xieite::iters<R>::proxy(l.value - r))

			constexpr auto operator-=(std::iter_difference_t<Iter> r)
				XIEITE_ARROW(void(this->value -= r), *this)

			constexpr auto operator--()
				XIEITE_ARROW(void(--this->value), *this)

			constexpr auto operator--(int)
				XIEITE_ARROW(([this](auto copy) XIEITE_ARROW_RET(void(this->value--), copy))(*this))
		};

		template<typename Iter>
		proxy(Iter) -> proxy<Iter>;

	public:
		R& value;

		[[nodiscard]] constexpr auto begin(this auto&& self)
			XIEITE_ARROW(xieite::iters<R>::proxy(std::ranges::begin(XIEITE_FWD(self).value)))

		[[nodiscard]] constexpr auto cbegin(this auto&& self)
			XIEITE_ARROW(xieite::iters<R>::proxy(std::ranges::cbegin(XIEITE_FWD(self).value)))

		[[nodiscard]] constexpr auto rbegin(this auto&& self)
			XIEITE_ARROW(xieite::iters<R>::proxy(std::ranges::rbegin(XIEITE_FWD(self).value)))

		[[nodiscard]] constexpr auto crbegin(this auto&& self)
			XIEITE_ARROW(xieite::iters<R>::proxy(std::ranges::crbegin(XIEITE_FWD(self).value)))

		[[nodiscard]] constexpr auto end(this auto&& self)
			XIEITE_ARROW(xieite::iters<R>::proxy(std::ranges::end(XIEITE_FWD(self).value)))

		[[nodiscard]] constexpr auto cend(this auto&& self)
			XIEITE_ARROW(xieite::iters<R>::proxy(std::ranges::cend(XIEITE_FWD(self).value)))

		[[nodiscard]] constexpr auto rend(this auto&& self)
			XIEITE_ARROW(xieite::iters<R>::proxy(std::ranges::rend(XIEITE_FWD(self).value)))

		[[nodiscard]] constexpr auto crend(this auto&& self)
			XIEITE_ARROW(xieite::iters<R>::proxy(std::ranges::crend(XIEITE_FWD(self).value)))
	};

	template<typename R>
	iters(R) -> iters<R>;
}
