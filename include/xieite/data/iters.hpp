#ifndef DETAIL_XIEITE_HEADER_DATA_ITERS
#	define DETAIL_XIEITE_HEADER_DATA_ITERS
#
#	include <iterator>
#	include <ranges>
#	include "../pp/arrow.hpp"
#	include "../pp/fwd.hpp"

namespace xieite {
	template<std::ranges::range Range>
	struct iters {
	private:
		template<typename Iter>
		struct iter {
			using value_type = Iter;

			Iter value;

			[[nodiscard]] constexpr auto& operator*(this auto& self) noexcept {
				return self.value;
			}

			[[nodiscard]] friend constexpr auto operator==(xieite::iters<Range>::iter<Iter> lhs, xieite::iters<Range>::iter<Iter> rhs) XIEITE_ARROW(
				lhs.value == rhs.value
			)

			[[nodiscard]] friend constexpr auto operator==(xieite::iters<Range>::iter<Iter> lhs, Iter rhs) XIEITE_ARROW(
				lhs.value == rhs
			)

			[[nodiscard]] friend constexpr auto operator!=(xieite::iters<Range>::iter<Iter> lhs, xieite::iters<Range>::iter<Iter> rhs) XIEITE_ARROW(
				lhs.value != rhs.value
			)

			[[nodiscard]] friend constexpr auto operator!=(xieite::iters<Range>::iter<Iter> lhs, Iter rhs) XIEITE_ARROW(
				lhs.value != rhs
			)

			[[nodiscard]] friend constexpr auto operator+(xieite::iters<Range>::iter<Iter> lhs, std::iter_difference_t<Iter> rhs) XIEITE_ARROW(
				xieite::iters<Range>::iter(lhs.value + rhs)
			)

			constexpr auto operator+=(std::iter_difference_t<Iter> rhs) XIEITE_ARROW(
				void(this->value += rhs),
				*this
			)

			constexpr auto operator++() XIEITE_ARROW(
				void(++this->value),
				*this
			)

			constexpr auto operator++(int) XIEITE_ARROW(
				([this](auto copy) XIEITE_ARROW(
					void(this->value++),
					auto(copy)
				))(*this)
			)

			[[nodiscard]] friend constexpr auto operator-(xieite::iters<Range>::iter<Iter> lhs, std::iter_difference_t<Iter> rhs) XIEITE_ARROW(
				xieite::iters<Range>::iter(lhs.value - rhs)
			)

			constexpr auto operator-=(std::iter_difference_t<Iter> rhs) XIEITE_ARROW(
				void(this->value -= rhs),
				*this
			)

			constexpr auto operator--() XIEITE_ARROW(
				void(--this->value),
				*this
			)

			constexpr auto operator--(int) XIEITE_ARROW(
				([this](auto copy) XIEITE_ARROW(
					void(this->value--),
					auto(copy)
				))(*this)
			)
		};

		template<typename Iter>
		iter(Iter) -> iter<Iter>;

	public:
		Range& value;

		[[nodiscard]] constexpr auto begin(this auto&& self) XIEITE_ARROW(
			xieite::iters<Range>::iter(std::ranges::begin(XIEITE_FWD(self).value))
		)

		[[nodiscard]] constexpr auto cbegin(this auto&& self) XIEITE_ARROW(
			xieite::iters<Range>::iter(std::ranges::cbegin(XIEITE_FWD(self).value))
		)

		[[nodiscard]] constexpr auto rbegin(this auto&& self) XIEITE_ARROW(
			xieite::iters<Range>::iter(std::ranges::rbegin(XIEITE_FWD(self).value))
		)

		[[nodiscard]] constexpr auto crbegin(this auto&& self) XIEITE_ARROW(
			xieite::iters<Range>::iter(std::ranges::crbegin(XIEITE_FWD(self).value))
		)

		[[nodiscard]] constexpr auto end(this auto&& self) XIEITE_ARROW(
			xieite::iters<Range>::iter(std::ranges::end(XIEITE_FWD(self).value))
		)

		[[nodiscard]] constexpr auto cend(this auto&& self) XIEITE_ARROW(
			xieite::iters<Range>::iter(std::ranges::cend(XIEITE_FWD(self).value))
		)

		[[nodiscard]] constexpr auto rend(this auto&& self) XIEITE_ARROW(
			xieite::iters<Range>::iter(std::ranges::rend(XIEITE_FWD(self).value))
		)

		[[nodiscard]] constexpr auto crend(this auto&& self) XIEITE_ARROW(
			xieite::iters<Range>::iter(std::ranges::crend(XIEITE_FWD(self).value))
		)
	};

	template<typename Range>
	iters(Range&&) -> iters<Range>;
}

#endif
