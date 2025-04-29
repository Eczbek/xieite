#ifndef DETAIL_XIEITE_HEADER_DATA_FIXED_ARRAY
#	define DETAIL_XIEITE_HEADER_DATA_FIXED_ARRAY
#
#	include <compare>
#	include <cstddef>
#	include <functional>
#	include <iterator>
#	include <ranges>
#	include <stdexcept>
#	include "../fn/range_cmp_op.hpp"
#	include "../fn/repeat.hpp"
#	include "../fn/unroll.hpp"
#	include "../pp/arrow.hpp"
#	include "../pp/fwd.hpp"
#	include "../trait/has_cp_ctor.hpp"

namespace xieite {
	template<typename Value, std::size_t length>
	struct fixed_array {
		using value_type = Value;
		using reference = xieite::fixed_array<Value, length>::value_type&;
		using const_reference = const xieite::fixed_array<Value, length>::value_type&;
		using pointer = xieite::fixed_array<Value, length>::value_type*;
		using const_pointer = const xieite::fixed_array<Value, length>::value_type*;
		using size_type = std::size_t;
		using difference_type = std::ptrdiff_t;
		using iterator = xieite::fixed_array<Value, length>::pointer;
		using const_iterator = xieite::fixed_array<Value, length>::const_pointer;
		using reverse_iterator = std::reverse_iterator<xieite::fixed_array<Value, length>::pointer>;
		using const_reverse_iterator = std::reverse_iterator<xieite::fixed_array<Value, length>::const_pointer>;

		Value array[length];

		[[nodiscard]] friend constexpr auto operator<=>(const xieite::fixed_array<Value, length>& lhs, const xieite::fixed_array<Value, length>& rhs)
			XIEITE_ARROW(xieite::range_cmp_op::operator<=>(lhs, rhs))

		[[nodiscard]] constexpr auto&& operator[](this auto&& self, const xieite::fixed_array<Value, length>::size_type idx) noexcept {
			return XIEITE_FWD(self).array[idx];
		}

		template<std::size_t other_length>
		[[nodiscard]] friend constexpr xieite::fixed_array<Value, (length + other_length)> operator+(const xieite::fixed_array<Value, length>& lhs, const xieite::fixed_array<Value, other_length>& rhs)
		noexcept(xieite::has_cp_ctor<Value>) {
			return xieite::unroll<(length + other_length)>([&]<std::size_t... i> {
				return xieite::fixed_array<Value, (length + other_length)> {
					([&] {
						if constexpr (i < length) {
							return lhs[i];
						} else {
							return rhs[i - length];
						}
					})()...
				};
			});
		}

		[[nodiscard]] constexpr auto&& at(this auto&& self, const xieite::fixed_array<Value, length>::size_type idx) {
			if (idx >= length) {
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

		[[nodiscard]] constexpr xieite::fixed_array<Value, length>::const_iterator cbegin() const noexcept {
			return std::ranges::cbegin(this->array);
		}

		[[nodiscard]] constexpr auto rbegin(this auto&& self) noexcept {
			return std::ranges::rbegin(XIEITE_FWD(self).array);
		}

		[[nodiscard]] constexpr xieite::fixed_array<Value, length>::const_reverse_iterator crbegin() const noexcept {
			return std::ranges::crbegin(this->array);
		}

		[[nodiscard]] constexpr auto end(this auto&& self) noexcept {
			return std::ranges::end(XIEITE_FWD(self).array);
		}

		[[nodiscard]] constexpr xieite::fixed_array<Value, length>::const_iterator cend() const noexcept {
			return std::ranges::cend(this->array);
		}

		[[nodiscard]] constexpr auto rend(this auto&& self) noexcept {
			return std::ranges::rend(XIEITE_FWD(self).array);
		}

		[[nodiscard]] constexpr xieite::fixed_array<Value, length>::const_reverse_iterator crend() const noexcept {
			return std::ranges::crend(this->array);
		}

		[[nodiscard]] static constexpr bool empty() noexcept {
			return false;
		}

		[[nodiscard]] static constexpr std::size_t size() noexcept {
			return length;
		}

		[[nodiscard]] static constexpr std::size_t max_size() noexcept {
			return length;
		}

		constexpr void fill(const Value& value)
			XIEITE_ARROW_RET(xieite::unroll<length>(
				[]<std::size_t... i>(auto& array, const Value& value) static
					XIEITE_ARROW((..., void(array[i] = value))),
				this->array,
				value
			))

		constexpr void swap(auto&& range)
			XIEITE_ARROW_RET(xieite::repeat<length>(
				[]<std::size_t>(auto& iter0, auto& iter1) static
					XIEITE_ARROW(std::ranges::iter_swap(iter0++, iter1++)),
				this->begin(),
				std::ranges::begin(range)
			))

		[[nodiscard]] constexpr auto apply(this auto&& self, auto&& fn)
			XIEITE_ARROW(xieite::unroll<length>(
				[]<std::size_t... i>(auto&& fn, Value* array) static
					XIEITE_ARROW(std::invoke(XIEITE_FWD(fn), std::forward_like<decltype(self)>(array[i])...)),
				XIEITE_FWD(fn),
				self.array
			))

		[[nodiscard]] static constexpr auto from(std::ranges::input_range auto&& range)
			XIEITE_ARROW(xieite::unroll<length>(
				[]<std::size_t... i>(auto iter) static
					XIEITE_ARROW(xieite::fixed_array { ([](auto& iter) static XIEITE_ARROW_IF(i, ++iter, *iter))(iter)... }),
				std::ranges::begin(range)
			))
	};

	template<typename Value>
	struct fixed_array<Value, 0> {
		using value_type = Value;
		using reference = xieite::fixed_array<Value, 0>::value_type&;
		using const_reference = const xieite::fixed_array<Value, 0>::value_type&;
		using pointer = xieite::fixed_array<Value, 0>::value_type*;
		using const_pointer = const xieite::fixed_array<Value, 0>::value_type*;
		using size_type = std::size_t;
		using difference_type = std::ptrdiff_t;
		using iterator = xieite::fixed_array<Value, 0>::pointer;
		using const_iterator = xieite::fixed_array<Value, 0>::const_pointer;
		using reverse_iterator = std::reverse_iterator<xieite::fixed_array<Value, 0>::pointer>;
		using const_reverse_iterator = std::reverse_iterator<xieite::fixed_array<Value, 0>::const_pointer>;

		[[nodiscard]] friend constexpr std::strong_ordering operator<=>(const xieite::fixed_array<Value, 0>&, const xieite::fixed_array<Value, 0>&) noexcept {
			return std::strong_ordering::equal;
		}

		[[nodiscard]] constexpr const Value* data() const noexcept {
			return nullptr;
		}

		[[nodiscard]] constexpr xieite::fixed_array<Value, 0>::const_iterator begin() const noexcept {
			return nullptr;
		}

		[[nodiscard]] constexpr xieite::fixed_array<Value, 0>::const_iterator cbegin() const noexcept {
			return nullptr;
		}

		[[nodiscard]] constexpr xieite::fixed_array<Value, 0>::const_reverse_iterator rbegin() const noexcept {
			return nullptr;
		}

		[[nodiscard]] constexpr xieite::fixed_array<Value, 0>::const_reverse_iterator crbegin() const noexcept {
			return nullptr;
		}

		[[nodiscard]] constexpr xieite::fixed_array<Value, 0>::const_iterator end() const noexcept {
			return nullptr;
		}

		[[nodiscard]] constexpr xieite::fixed_array<Value, 0>::const_iterator cend() const noexcept {
			return nullptr;
		}

		[[nodiscard]] constexpr xieite::fixed_array<Value, 0>::const_reverse_iterator rend() const noexcept {
			return nullptr;
		}

		[[nodiscard]] constexpr xieite::fixed_array<Value, 0>::const_reverse_iterator crend() const noexcept {
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

		constexpr void fill(const Value&) const noexcept {}

		constexpr void swap(auto&&) const noexcept {}

		[[nodiscard]] constexpr auto apply(auto&& fn)
			XIEITE_ARROW(std::invoke(XIEITE_FWD(fn)))

		[[nodiscard]] static constexpr auto from(std::ranges::input_range auto&&) noexcept {
			return xieite::fixed_array<Value, 0>();
		}
	};

	template<typename Value, typename... Values>
	fixed_array(Value, Values...) -> fixed_array<Value, (sizeof...(Values) + 1)>;
}

#endif
