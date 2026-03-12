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
#	include "../trait/copy_cvref.hpp"
#	include "../trait/is_assignable.hpp"
#	include "../trait/is_castable.hpp"
#	include "../trait/is_derived_from.hpp"
#	include "../trait/is_noex_move_constructible.hpp"
#	include "../util/address.hpp"
#	include "../util/as_c.hpp"
#	include "../util/construct.hpp"
#	include "../util/destroy.hpp"
#	include "../util/exchange.hpp"
#	include "../util/like.hpp"
#	include "../util/reconstruct.hpp"
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

		constexpr void reset(T* data = nullptr) & noexcept {
			if (this->_capacity) {
				for (xte::uz i = 0; i < this->_size; ++i) {
					xte::destroy(this->_data[i]);
				}
				std::allocator<T>().deallocate(this->_data, this->_capacity);
			}
			this->_data = data;
		}

		constexpr void reallocate(xte::uz capacity) & noexcept(false) {
			T* data = nullptr;
			if (capacity) {
				data = std::allocator<T>().allocate(capacity);
				for (xte::uz i : std::views::indices(this->_size)) {
					xte::construct(data[i], xte::xvalue(this->_data[i]));
				}
			}
			this->reset(data);
			this->_capacity = capacity;
		}

	public:
		[[nodiscard]] explicit(false) constexpr array() noexcept = default;

		[[nodiscard]] explicit(false) constexpr array(const xte::array<T>& other) noexcept(false)
		requires(std::is_copy_constructible_v<T>) {
			this->reserve_total(other._size);
			for (xte::uz i : std::views::indices(this->_size = other._size)) {
				xte::construct(this->_data[i], other._data[i]);
			}
		}

		[[nodiscard]] explicit(false) constexpr array(xte::array<T>&& other) noexcept
		: _data(xte::exchange(other._data, nullptr))
		, _size(xte::exchange(other._size, 0))
		, _capacity(xte::exchange(other._capacity, 0)) {}

		[[nodiscard]] explicit(false) constexpr array(xte::init_list<T> init_list) noexcept(false) {
			this->reserve_total(init_list.size());
			for (auto&& item : init_list) {
				this->push(xte::xvalue(item));
			}
		}

		template<std::ranges::input_range Range>
		requires(!xte::is_derived_from<Range, xte::array<T>>
			&& xte::is_castable<std::ranges::range_value_t<Range>, T>)
		[[nodiscard]] explicit constexpr array(Range&& range) noexcept(false) {
			if constexpr (std::ranges::sized_range<Range>) {
				this->reserve_total(std::ranges::size(range));
			}
			for (auto&& item : range) {
				this->push(xte::like<decltype(range)>(item));
			}
		}

		[[nodiscard]] explicit constexpr array(xte::uz size) noexcept(false)
		requires(std::is_default_constructible_v<T>) {
			this->resize(size);
		}

		[[nodiscard]] constexpr array(xte::uz size, const T& fill) noexcept(false)
		requires(std::is_copy_constructible_v<T>) {
			this->resize(size, fill);
		}

		constexpr ~array() {
			this->reset();
		}

		constexpr xte::array<T>& operator=(const xte::array<T>& other) & noexcept(false)
		requires(xte::is_assignable<T&, const T&>) {
			if (this != xte::address(other)) {
				if (other._size <= this->_capacity) {
					for (xte::uz i = 0; (i < this->_size) && (i < other._size); ++i) {
						this->_data[i] = other._data[i];
					}
					for (xte::uz i = this->_size; i < other._size; ++i) {
						xte::construct(this->_data[i], other._data[i]);
					}
					this->erase(other._size, -1uz);
				} else {
					this->reset();
					this->push(other);
				}
			}
			return *this;
		}

		constexpr xte::array<T>& operator=(xte::array<T>&& other) & noexcept {
			return (this == xte::address(other)) ? *this : xte::reconstruct(*this, xte::xvalue(other));
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
			(lhs._size == rhs._size) && std::is_eq(lhs <=> rhs)
		)

		constexpr void resize(xte::uz size) & noexcept(false)
		requires(std::is_default_constructible_v<T>) {
			this->reserve_total(size);
			while (this->_size < size) {
				this->push();
			}
			this->erase(size, -1uz);
		}

		constexpr void resize(xte::uz size, const T& fill) & noexcept(false)
		requires(std::is_copy_constructible_v<T>) {
			this->reserve_total(size);
			while (this->_size < size) {
				this->push(fill);
			}
			this->erase(size, -1uz);
		}

		constexpr void reserve(xte::uz additional = 1) & noexcept(false) {
			this->reserve_total(this->_capacity + additional);
		}

		constexpr void reserve_total(xte::uz total) & noexcept(false) {
			if (total > this->_capacity) {
				XTE_DIAGNOSTIC_PUSH_GCC(OFF, "-Winterference-size")
				xte::uz capacity = xte::max(this->_capacity, std::hardware_destructive_interference_size / sizeof(T));
				XTE_DIAGNOSTIC_POP_GCC()
				while (capacity < total) {
					capacity += xte::max(1, capacity / 2);
				}
				this->reallocate(capacity);
			}
		}

		constexpr void shrink() & noexcept(false) {
			if (this->_capacity > this->_size) {
				this->reallocate(this->_size);
			}
		}

		template<xte::is_castable<T> U = T>
		constexpr void insert(xte::uz index, U&& x = {}) & noexcept(false)
		requires(xte::is_assignable<T&, T&&>) {
			this->reserve(this->_size == this->_capacity);
			if (index == this->_size) {
				xte::construct(this->_data[this->_size++], XTE_FWD(x));
				return;
			}
			T tmp = T(XTE_FWD(x));
			xte::construct(this->_data[this->_size], xte::xvalue(this->_data[this->_size - 1]));
			for (xte::uz i = this->_size++ - 1; i-- > index;) {
				this->_data[i + 1] = xte::xvalue(this->_data[i]);
			}
			this->_data[index] = xte::xvalue(tmp);
		}

		template<std::ranges::input_range Range>
		requires(xte::is_castable<std::ranges::range_value_t<Range>, T>)
		constexpr void insert(xte::uz index, Range&& range) & noexcept(false)
		requires(xte::is_assignable<T&, T&&> && requires { T(xte::like<Range>(*std::ranges::begin(range))); }) {
			xte::uz range_size = 0;
			if constexpr (std::ranges::sized_range<Range>) {
				range_size = std::ranges::size(range);
				if ((this->_size + range_size) <= this->_capacity) {
					for (xte::uz i = range_size; i-- && ((this->_size - (range_size - i)) >= index);) {
						xte::construct(this->_data[this->_size + i], xte::xvalue(this->_data[this->_size - (range_size - i)]));
					}
					for (xte::uz i = this->_size; i-- && (i >= (index + range_size));) {
						this->_data[i] = xte::xvalue(this->_data[i - range_size]);
					}
					auto iter = std::ranges::begin(range);
					for (xte::uz i = index; (i < this->_size) && (i < (index + range_size)); ++iter) {
						this->_data[i++] = T(xte::like<Range>(*iter));
					}
					auto end = std::ranges::end(range);
					for (xte::uz i = this->_size; iter != end; ++iter) {
						xte::construct(this->_data[i++], xte::like<Range>(*iter));
					}
					this->_size += range_size;
					return;
				}
			}
			xte::array<T> old = xte::xvalue(*this);
			this->reserve_total(old._size + range_size);
			for (auto&& item : old | std::views::take(index)) {
				this->push(xte::xvalue(item));
			}
			for (auto&& item : range) {
				this->push(xte::like<Range>(item));
			}
			for (auto&& item : old | std::views::drop(index)) {
				this->push(xte::xvalue(item));
			}
		}

		constexpr void erase(xte::uz index, xte::uz count = 1) & noexcept {
			if (index <= this->_size) {
				count = xte::min(count, this->_size - index);
				for (xte::uz i = index; i < (this->_size - count); ++i) {
					this->_data[i] = xte::xvalue(this->_data[i + count]);
				}
				while (count--) {
					xte::destroy(this->_data[--this->_size + count]);
				}
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

		constexpr T pop() & noexcept(xte::is_noex_move_constructible<T>) {
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

// TODO: Assume move constructors, move assignment, and destructors can throw
