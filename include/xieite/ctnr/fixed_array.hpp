#pragma once

#include <compare>
#include <cstddef>
#include <iterator>
#include <ranges>
#include <stdexcept>
#include "../fn/range_cmp_op.hpp"
#include "../fn/repeat.hpp"
#include "../fn/unroll.hpp"
#include "../pp/arrow.hpp"
#include "../pp/fwd.hpp"
#include "../trait/is_noex_iter.hpp"

namespace xieite {
	template<typename T, std::size_t n>
	struct fixed_array {
	public:
		using value_type = T;
		using reference =  xieite::fixed_array<T, n>::value_type&;
		using const_reference = const xieite::fixed_array<T, n>::value_type&;
		using pointer = xieite::fixed_array<T, n>::value_type*;
		using const_pointer = const xieite::fixed_array<T, n>::value_type*;
		using size_type = std::size_t;
		using difference_type = std::ptrdiff_t;
		using iterator = xieite::fixed_array<T, n>::pointer;
		using const_iterator = xieite::fixed_array<T, n>::const_pointer;
		using reverse_iterator = std::reverse_iterator<xieite::fixed_array<T, n>::pointer>;
		using const_reverse_iterator = std::reverse_iterator<xieite::fixed_array<T, n>::const_pointer>;

		T array[n];

		[[nodiscard]] friend constexpr auto operator<=>(const xieite::fixed_array<T, n>& l, const xieite::fixed_array<T, n>& r)
			XIEITE_ARROW(xieite::range_cmp_op::operator<=>(l, r))

		[[nodiscard]] constexpr auto&& operator[](this auto&& self, const xieite::fixed_array<T, n>::size_type idx) noexcept {
			return XIEITE_FWD(self).array[idx];
		}

		[[nodiscard]] constexpr auto&& at(this auto&& self, const xieite::fixed_array<T, n>::size_type idx) {
			if (idx >= n) {
				throw std::out_of_range("index must be within range");
			}
			return XIEITE_FWD(self)[idx];
		}

		[[nodiscard]] constexpr auto* data(this auto&& self) noexcept {
			return XIEITE_FWD(self).array;
		}

		[[nodiscard]] constexpr auto front(this auto&& self) noexcept {
			return *XIEITE_FWD(self).begin();
		}

		[[nodiscard]] constexpr auto back(this auto&& self) noexcept {
			return *std::ranges::prev(XIEITE_FWD(self).end());
		}

		[[nodiscard]] constexpr auto begin(this auto&& self) noexcept {
			return std::ranges::begin(XIEITE_FWD(self).array);
		}

		[[nodiscard]] constexpr xieite::fixed_array<T, n>::const_iterator cbegin() const noexcept {
			return std::ranges::cbegin(this->array);
		}

		[[nodiscard]] constexpr auto rbegin(this auto&& self) noexcept {
			return std::ranges::rbegin(XIEITE_FWD(self).array);
		}

		[[nodiscard]] constexpr xieite::fixed_array<T, n>::const_reverse_iterator crbegin() const noexcept {
			return std::ranges::crbegin(this->array);
		}

		[[nodiscard]] constexpr auto end(this auto&& self) noexcept {
			return std::ranges::end(XIEITE_FWD(self).array);
		}

		[[nodiscard]] constexpr xieite::fixed_array<T, n>::const_iterator cend() const noexcept {
			return std::ranges::cend(this->array);
		}

		[[nodiscard]] constexpr auto rend(this auto&& self) noexcept {
			return std::ranges::rend(XIEITE_FWD(self).array);
		}

		[[nodiscard]] constexpr xieite::fixed_array<T, n>::const_reverse_iterator crend() const noexcept {
			return std::ranges::crend(this->array);
		}

		[[nodiscard]] static constexpr bool empty() noexcept {
			return false;
		}

		[[nodiscard]] static constexpr std::size_t size() noexcept {
			return n;
		}

		[[nodiscard]] static constexpr std::size_t max_size() noexcept {
			return n;
		}

		constexpr void fill(const T& value)
			XIEITE_ARROW_RET(xieite::unroll<n>(
				[]<std::size_t... i>(auto& array, const T& value) static
					XIEITE_ARROW(void((..., (array[i] = value)))),
				this->array,
				value
			))

		constexpr void swap(auto&& range)
			XIEITE_ARROW_RET(xieite::repeat<n>(
				[]<std::size_t>(auto& iter0, auto& iter1) static
					XIEITE_ARROW(std::ranges::iter_swap(iter0++, iter1++)),
				this->begin(),
				std::ranges::begin(range)
			))

		template<std::ranges::input_range R>
		[[nodiscard]] static constexpr auto from(R&& range)
			XIEITE_ARROW(xieite::unroll<n>(
				[]<std::size_t... i>(auto iter) static
					XIEITE_ARROW(xieite::fixed_array<T, n> {
						([]<typename I>(I& iter) static noexcept(xieite::is_noex_iter<I>) -> decltype(auto) {
							if constexpr (i) {
								++iter;
							}
							return *iter;
						})(iter)...
					}),
				std::ranges::begin(range)
			))
	};

	template<typename T>
	struct fixed_array<T, 0> {
		using value_type = T;
		using reference =  xieite::fixed_array<T, 0>::value_type&;
		using const_reference = const xieite::fixed_array<T, 0>::value_type&;
		using pointer = xieite::fixed_array<T, 0>::value_type*;
		using const_pointer = const xieite::fixed_array<T, 0>::value_type*;
		using size_type = std::size_t;
		using difference_type = std::ptrdiff_t;
		using iterator = xieite::fixed_array<T, 0>::pointer;
		using const_iterator = xieite::fixed_array<T, 0>::const_pointer;
		using reverse_iterator = std::reverse_iterator<xieite::fixed_array<T, 0>::pointer>;
		using const_reverse_iterator = std::reverse_iterator<xieite::fixed_array<T, 0>::const_pointer>;

		[[nodiscard]] friend constexpr std::strong_ordering operator<=>(const xieite::fixed_array<T, 0>&, const xieite::fixed_array<T, 0>&) noexcept {
			return std::strong_ordering::equal;
		}

		[[nodiscard]] constexpr const T* data() const noexcept {
			return nullptr;
		}

		[[nodiscard]] constexpr xieite::fixed_array<T, 0>::const_iterator begin() const noexcept {
			return nullptr;
		}

		[[nodiscard]] constexpr xieite::fixed_array<T, 0>::const_iterator cbegin() const noexcept {
			return nullptr;
		}

		[[nodiscard]] constexpr xieite::fixed_array<T, 0>::const_reverse_iterator rbegin() const noexcept {
			return nullptr;
		}

		[[nodiscard]] constexpr xieite::fixed_array<T, 0>::const_reverse_iterator crbegin() const noexcept {
			return nullptr;
		}

		[[nodiscard]] constexpr xieite::fixed_array<T, 0>::const_iterator end() const noexcept {
			return nullptr;
		}

		[[nodiscard]] constexpr xieite::fixed_array<T, 0>::const_iterator cend() const noexcept {
			return nullptr;
		}

		[[nodiscard]] constexpr xieite::fixed_array<T, 0>::const_reverse_iterator rend() const noexcept {
			return nullptr;
		}

		[[nodiscard]] constexpr xieite::fixed_array<T, 0>::const_reverse_iterator crend() const noexcept {
			return nullptr;
		}

		[[nodiscard]] static constexpr bool empty() noexcept {
			return true;
		}

		[[nodiscard]] static constexpr std::size_t size() noexcept {
			return 0;
		}

		[[nodiscard]] static constexpr std::size_t max_size() noexcept {
			return 0;
		}

		constexpr void fill(const T&) const noexcept {}

		constexpr void swap(auto&&) const noexcept {}

		template<std::ranges::input_range R>
		[[nodiscard]] static constexpr auto from(R&&) noexcept {
			return xieite::fixed_array<T, 0>();
		}
	};

	template<typename T, typename... Ts>
	fixed_array(T, Ts...) -> fixed_array<T, (sizeof...(Ts) + 1)>;
}
