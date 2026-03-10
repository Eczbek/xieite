#ifndef DETAIL_XTE_HEADER_DATA_ARRAY
#	define DETAIL_XTE_HEADER_DATA_ARRAY
#
#	include "../data/init_list.hpp"
#	include "../data/range_cmp.hpp"
#	include "../func/with_result.hpp"
#	include "../math/max.hpp"
#	include "../math/min.hpp"
#	include "../preproc/diagnostic.hpp"
#	include "../preproc/fwd.hpp"
#	include "../preproc/lift.hpp"
#	include "../trait/is_castable.hpp"
#	include "../trait/is_derived_from.hpp"
#	include "../trait/is_noex_move_assignable.hpp"
#	include "../trait/is_noex_move_ctor.hpp"
#	include "../util/address.hpp"
#	include "../util/as_c.hpp"
#	include "../util/exchange.hpp"
#	include "../util/like.hpp"
#	include "../util/types.hpp"
#	include "../util/xvalue.hpp"
#	include <compare>
#	include <memory>
#	include <new>
#	include <ranges>
#	include <type_traits>

namespace xte {
	template<typename T>
	struct array {
	private:
		T* _data = nullptr;
		xte::uz _size = 0;
		xte::uz _capacity = 0;

		constexpr void reset(T* data = nullptr) & noexcept(std::is_nothrow_destructible_v<T>) {
			if (this->_capacity) {
				for (xte::uz i = 0; i < this->_size; ++i) {
					this->_data[i].~T();
				}
				std::allocator<T>().deallocate(this->_data, this->_capacity);
			}
			this->_data = data;
		}

		constexpr void reallocate(xte::uz capacity) & noexcept(false) {
			T* data = std::allocator<T>().allocate(capacity);
			for (xte::uz i : std::views::indices(this->_size)) {
				::new(data + i) T(xte::xvalue(*this)._data[i]);
			}
			this->reset(data);
			this->_capacity = capacity;
		}

	public:
		[[nodiscard]] explicit(false) constexpr array() noexcept = default;

		[[nodiscard]] explicit(false) constexpr array(const xte::array<T>& other) noexcept(false) {
			this->reallocate(other._capacity);
			while (this->_size < other._size) {
				::new(this->_data + this->_size) T(other[this->_size++]);
			}
		}

		[[nodiscard]] explicit(false) constexpr array(xte::array<T>& other) noexcept(false)
		: xte::array<T>(xte::as_c(other)) {}

		[[nodiscard]] explicit(false) constexpr array(xte::array<T>&& other) noexcept
		: _data(xte::exchange(other._data, nullptr))
		, _size(xte::exchange(other._size, 0))
		, _capacity(xte::exchange(other._capacity, 0)) {}

		[[nodiscard]] explicit(false) constexpr array(const xte::array<T>&& other) noexcept(false)
		: xte::array<T>(other) {}

		[[nodiscard]] explicit(false) constexpr array(xte::init_list<T> init_list) noexcept(false) {
			this->reserve(init_list.size());
			for (auto&& item : init_list) {
				this->push(xte::xvalue(item));
			}
		}

		template<std::ranges::input_range Range>
		requires(xte::is_castable<std::ranges::range_value_t<Range>, T>)
		[[nodiscard]] explicit constexpr array(Range&& range) noexcept(false) {
			if constexpr (std::ranges::sized_range<Range>) {
				this->reserve(std::ranges::size(range));
			}
			for (auto&& item : range) {
				this->push(xte::like<decltype(range)>(item));
			}
		}

		[[nodiscard]] explicit constexpr array(xte::uz size, const T& fill = {}) noexcept(false) {
			this->resize(size, fill);
		}

		constexpr ~array() {
			this->reset();
		}

		constexpr xte::array<T>& operator=(const xte::array<T>& other) & noexcept(false) {
			if (this != xte::address(other)) {
				this->reallocate(other._capacity);
				while (this->_size < other._size) {
					::new(this->_data + this->_size) T(other._data[this->_size++]);
				}
			}
			return *this;
		}

		constexpr xte::array<T>& operator=(xte::array<T>&& other) & noexcept {
			if (this == xte::address(other)) {
				return *this;
			}
			this->~array();
			return *::new(this) xte::array<T>(xte::xvalue(other));
		}

		[[nodiscard]] constexpr auto&& operator[](this auto&& self, xte::uz index) noexcept {
			return xte::like<decltype(self)>(self._data[index]);
		}

		[[nodiscard]] constexpr T* data() const noexcept {
			return this->_data;
		}

		[[nodiscard]] constexpr xte::uz size() const noexcept {
			return this->_size;
		}

		[[nodiscard]] constexpr xte::uz capacity() const noexcept {
			return this->_capacity;
		}

		[[nodiscard]] constexpr T* begin() const & noexcept {
			return this->_data;
		}

		[[nodiscard]] constexpr T* end() const & noexcept {
			return this->_data + this->_size;
		}

		[[nodiscard]] constexpr auto&& front(this auto&& self, xte::uz index = 0) noexcept {
			return XTE_FWD(self)._data[index];
		}
		
		[[nodiscard]] constexpr auto&& back(this auto&& self, xte::uz index = 0) noexcept {
			return XTE_FWD(self)._data[self._size - index - 1];
		}

		[[nodiscard]] friend constexpr auto operator<=>(const xte::array<T>& lhs, const xte::array<T>& rhs) XTE_ARROW(
			xte::range_cmp(lhs, rhs)
		)

		[[nodiscard]] friend constexpr auto operator==(const xte::array<T>& lhs, const xte::array<T>& rhs) XTE_ARROW(
			std::is_eq(lhs <=> rhs)
		)

		constexpr void resize(xte::uz size, const T& fill = {}) & noexcept(false) {
			if (this->_size < size) {
				this->reserve(size - this->_size);
				while (this->_size < size) {
					this->push(fill);
				}
				return;
			}
			this->erase(size, -1uz);
		}

		constexpr void reserve(xte::uz additional = 1) & noexcept(false) {
			if (additional) {
				XTE_DIAGNOSTIC_PUSH_GCC(OFF, "-Winterference-size")
				xte::uz new_capacity = xte::max(this->_capacity, std::hardware_destructive_interference_size / sizeof(T));
				XTE_DIAGNOSTIC_POP_GCC()
				while (new_capacity < (this->_capacity + additional)) {
					new_capacity += new_capacity / 2;
				}
				this->reserve_total(new_capacity);
			}
		}

		constexpr void reserve_total(xte::uz total) & noexcept(false) {
			if (total > this->_capacity) {
				this->reallocate(total);
			}
		}

		constexpr void shrink() & noexcept(false) {
			if (this->_capacity != this->_size) {
				this->reallocate(this->_size);
			}
		}

		template<xte::is_castable<T> U = T>
		constexpr void insert(xte::uz index, U&& x = {}) & noexcept(false) {
			if (index <= this->_size) {
				this->reserve(this->_size >= this->_capacity);
				for (xte::uz i = this->_size++; i-- > index;) {
					this->_data[i] = this->_data[i - 1];
				}
				this->_data[index] = static_cast<char>(XTE_FWD(x));
			}
		}

		template<std::ranges::input_range Range>
		requires(xte::is_castable<std::ranges::range_value_t<Range>, T>)
		constexpr void insert(xte::uz index, Range&& range) & noexcept(false) {
			if (index <= this->_size) {
				xte::array<T> old = xte::xvalue(*this);
				this->reserve(old._capacity);
				if constexpr (std::ranges::sized_range<Range>) {
					this->reserve(std::ranges::size(range));
				}
				for (auto&& item : old | std::views::take(index)) {
					this->push(xte::xvalue(item));
				}
				for (auto&& item : range) {
					this->push(xte::like<decltype(range)>(item));
				}
				for (auto&& item : old | std::views::drop(index)) {
					this->push(xte::xvalue(item));
				}
			}
		}

		constexpr void erase(xte::uz index, xte::uz count = 1) & noexcept(xte::is_noex_move_assignable<T>) {
			if (index <= this->_size) {
				count = xte::min(count, this->_size - index);
				for (xte::uz i = index; i < (this->_size - count); ++i) {
					this->_data[i] = this->_data[i + count];
					this->_data[this->_size - count + i].~T();
				}
				this->_size -= count;
			}
		}

		template<xte::is_castable<T> U = T>
		constexpr void push(U&& x = xte::with_result(XTE_LIFT(U))) & noexcept(false) {
			this->insert(this->_size, XTE_FWD(x));
		}

		template<std::ranges::input_range Range>
		requires(xte::is_castable<std::ranges::range_value_t<Range>, T>)
		constexpr void push(Range&& range) & noexcept(false) {
			this->insert(this->_size, XTE_FWD(range));
		}

		constexpr T pop() & noexcept(xte::is_noex_move_ctor<T>) {
			auto last = T(xte::xvalue(*this).back());
			this->erase(this->_size - 1);
			return last;
		}

		template<std::ranges::input_range Range>
		requires(xte::is_castable<std::ranges::range_value_t<Range>, T>)
		constexpr auto& operator+=(this auto& lhs, Range&& rhs) noexcept(false) {
			lhs.xte::template array<T>::push(XTE_FWD(rhs));
			return lhs;
		}

		template<xte::is_derived_from<xte::array<T>> Self, std::ranges::input_range Range>
		requires(xte::is_castable<std::ranges::range_value_t<Range>, T>)
		[[nodiscard]] friend constexpr auto operator+(Self lhs, Range&& rhs) noexcept(false) {
			return lhs += XTE_FWD(rhs);
		}
	};
}

#endif
