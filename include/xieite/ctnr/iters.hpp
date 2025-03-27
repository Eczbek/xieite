#ifndef DETAIL_XIEITE_HEADER_CTNR_ITERS
#	define DETAIL_XIEITE_HEADER_CTNR_ITERS
#
#	include <iterator>
#	include <ranges>
#	include "../pp/arrow.hpp"
#	include "../pp/fwd.hpp"

namespace xieite {
	template<std::ranges::range R>
	struct iters {
	private:
		template<typename Iter>
		struct iter {
			using value_type = Iter;

			Iter value;

			[[nodiscard]] constexpr auto& operator*(this auto& self) noexcept {
				return self.value;
			}

			[[nodiscard]] friend constexpr auto operator==(xieite::iters<R>::iter<Iter> l, xieite::iters<R>::iter<Iter> r)
				XIEITE_ARROW(l.value == r.value)

			[[nodiscard]] friend constexpr auto operator==(xieite::iters<R>::iter<Iter> l, Iter r)
				XIEITE_ARROW(l.value == r)

			[[nodiscard]] friend constexpr auto operator!=(xieite::iters<R>::iter<Iter> l, xieite::iters<R>::iter<Iter> r)
				XIEITE_ARROW(l.value != r.value)

			[[nodiscard]] friend constexpr auto operator!=(xieite::iters<R>::iter<Iter> l, Iter r)
				XIEITE_ARROW(l.value != r)

			[[nodiscard]] friend constexpr auto operator+(xieite::iters<R>::iter<Iter> l, std::iter_difference_t<Iter> r)
				XIEITE_ARROW(xieite::iters<R>::iter(l.value + r))

			constexpr auto operator+=(std::iter_difference_t<Iter> r)
				XIEITE_ARROW(void(this->value += r), *this)

			constexpr auto operator++()
				XIEITE_ARROW(void(++this->value), *this)

			constexpr auto operator++(int)
				XIEITE_ARROW(([this](auto copy) XIEITE_ARROW(void(this->value++), auto(copy)))(*this))

			[[nodiscard]] friend constexpr auto operator-(xieite::iters<R>::iter<Iter> l, std::iter_difference_t<Iter> r)
				XIEITE_ARROW(xieite::iters<R>::iter(l.value - r))

			constexpr auto operator-=(std::iter_difference_t<Iter> r)
				XIEITE_ARROW(void(this->value -= r), *this)

			constexpr auto operator--()
				XIEITE_ARROW(void(--this->value), *this)

			constexpr auto operator--(int)
				XIEITE_ARROW(([this](auto copy) XIEITE_ARROW(void(this->value--), auto(copy)))(*this))
		};

		template<typename Iter>
		iter(Iter) -> iter<Iter>;

	public:
		R& value;

		[[nodiscard]] constexpr auto begin(this auto&& self)
			XIEITE_ARROW(xieite::iters<R>::iter(std::ranges::begin(XIEITE_FWD(self).value)))

		[[nodiscard]] constexpr auto cbegin(this auto&& self)
			XIEITE_ARROW(xieite::iters<R>::iter(std::ranges::cbegin(XIEITE_FWD(self).value)))

		[[nodiscard]] constexpr auto rbegin(this auto&& self)
			XIEITE_ARROW(xieite::iters<R>::iter(std::ranges::rbegin(XIEITE_FWD(self).value)))

		[[nodiscard]] constexpr auto crbegin(this auto&& self)
			XIEITE_ARROW(xieite::iters<R>::iter(std::ranges::crbegin(XIEITE_FWD(self).value)))

		[[nodiscard]] constexpr auto end(this auto&& self)
			XIEITE_ARROW(xieite::iters<R>::iter(std::ranges::end(XIEITE_FWD(self).value)))

		[[nodiscard]] constexpr auto cend(this auto&& self)
			XIEITE_ARROW(xieite::iters<R>::iter(std::ranges::cend(XIEITE_FWD(self).value)))

		[[nodiscard]] constexpr auto rend(this auto&& self)
			XIEITE_ARROW(xieite::iters<R>::iter(std::ranges::rend(XIEITE_FWD(self).value)))

		[[nodiscard]] constexpr auto crend(this auto&& self)
			XIEITE_ARROW(xieite::iters<R>::iter(std::ranges::crend(XIEITE_FWD(self).value)))
	};

	template<typename R>
	iters(R) -> iters<R>;
}

#endif
