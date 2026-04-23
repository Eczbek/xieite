#ifndef DETAIL_XTE_HEADER_DATA_ARRAY
#	define DETAIL_XTE_HEADER_DATA_ARRAY
#
#	include "../data/init_list.hpp"
#	include "../data/range_cmp.hpp"
#	include "../math/max.hpp"
#	include "../math/min.hpp"
#	include "../preproc/arrow.hpp"
#	include "../preproc/diagnostic.hpp"
#	include "../preproc/fwd.hpp"
#	include "../trait/copy_cvref.hpp"
#	include "../trait/is_assignable.hpp"
#	include "../trait/is_constructible.hpp"
#	include "../trait/is_copy_constructible.hpp"
#	include "../trait/is_derived_from.hpp"
#	include "../trait/is_noex_move_constructible.hpp"
#	include "../util/address.hpp"
#	include "../util/as_c.hpp"
#	include "../util/cast.hpp"
#	include "../util/construct.hpp"
#	include "../util/destroy.hpp"
#	include "../util/exchange.hpp"
#	include "../util/like.hpp"
#	include "../util/lvalue.hpp"
#	include "../util/numbers.hpp"
#	include "../util/reconstruct.hpp"
#	include "../util/xvalue.hpp"
#	include <compare>
#	include <iterator>
#	include <memory>
#	include <new>
#	include <ranges>
#	include <type_traits>
#	include <utility>

namespace xte {
	template<typename T>
	struct array {
	private:
		T* _data = nullptr;
		xte::uz _size = 0;
		xte::uz _capacity = 0;

		constexpr void _reallocate(xte::uz capacity) & noexcept(false) {
			if (xte::array<T> old = xte::xvalue(*this); capacity) {
				this->_data = std::allocator<T>().allocate(capacity);
				this->_capacity = capacity;
				try {
					for (xte::uz i = 0; i < old._size; this->_size = ++i) {
						xte::construct(this->_data[i], std::move_if_noexcept(old._data[i]));
					}
				} catch (...) {
					*this = xte::xvalue(old);
					throw;
				}
			}
		}

	public:
		using value_type = T;
		using allocator_type = std::allocator<T>;
		using size_type = xte::uz;
		using difference_type = xte::iptrdiff;
		using reference = T&;
		using const_reference = const T&;
		using pointer = T*;
		using const_pointer = const T*;
		using iterator = T*;
		using const_iterator = const T*;
		using reverse_iterator = std::reverse_iterator<T*>;
		using const_reverse_iterator = std::reverse_iterator<const T*>;

		[[nodiscard]] explicit(false) constexpr array() noexcept = default;

		[[nodiscard]] explicit(false) constexpr array(const xte::array<T>& other) noexcept(false)
		requires(xte::is_copy_constructible<T>)
		: xte::array<T>(std::from_range, other) {}

		[[nodiscard]] explicit(false) constexpr array(xte::array<T>&& other) noexcept
		: _data(xte::exchange(other._data, nullptr))
		, _size(xte::exchange(other._size, 0))
		, _capacity(xte::exchange(other._capacity, 0)) {}

		[[nodiscard]] explicit(false) constexpr array(xte::init_list<T> init_list) noexcept(false)
		: xte::array<T>(std::from_range, xte::xvalue(init_list)) {}

		template<std::ranges::input_range Range>
		[[nodiscard]] constexpr array(std::from_range_t, Range&& range) noexcept(false)
		requires(requires (T x) { x = static_cast<T>(xte::like<Range>(*xte::lvalue(std::ranges::begin(range)))); }) {
			this->push_range(XTE_FWD(range));
		}

		template<std::input_iterator Iter>
		[[nodiscard]] constexpr array(Iter begin, std::sentinel_for<Iter> auto end) XTE_ARROW_CTOR(,
			(xte::array<T>),((std::from_range, std::ranges::subrange(begin, end)))
		)

		[[nodiscard]] explicit constexpr array(xte::uz size) noexcept(false)
		requires(xte::is_constructible<T>) {
			this->resize(size);
		}

		[[nodiscard]] constexpr array(xte::uz size, const T& fill) noexcept(false)
		requires(xte::is_copy_constructible<T>) {
			this->resize(size, fill);
		}

		constexpr ~array() {
			this->reset();
		}

		constexpr xte::array<T>& operator=(const xte::array<T>& other) & noexcept(false)
		requires(requires (T x) { x = xte::lvalue(T(x)); }) {
			if (this != xte::address(other)) {
				if (other._size <= this->_capacity) {
					for (xte::uz i : std::views::indices(xte::min(this->_size, other._size))) {
						this->_data[i] = other._data[i];
					}
					for (xte::uz i = this->_size; i < other._size; this->_size = ++i) {
						xte::construct(this->_data[i], other._data[i]);
					}
					this->erase(other._size, -1uz);
				} else {
					this->reset();
					this->push_range(other);
				}
			}
			return *this;
		}

		constexpr xte::array<T>& operator=(xte::array<T>&& other) & noexcept {
			return (this == xte::address(other)) ? *this : xte::reconstruct(*this, xte::xvalue(other));
		}

		template<std::ranges::input_range Range>
		constexpr xte::array<T>& operator=(Range&& range) & noexcept(false)
		requires(!xte::is_derived_from<Range, xte::array<T>> && requires (T x) { x = static_cast<T>(xte::like<Range>(*xte::lvalue(std::ranges::begin(range)))); }) {
			if constexpr (std::ranges::sized_range<Range>) {
				if (xte::uz range_size = std::ranges::size(range); range_size <= this->_capacity) {
					auto iter = std::ranges::begin(range);
					for (xte::uz i : std::views::indices(xte::min(this->_size, range_size))) {
						this->_data[i] = static_cast<T>(xte::like<Range>(*iter));
						++iter;
					}
					while (this->_size < range_size) {
						xte::construct(this->_data[this->_size], xte::like<Range>(*iter));
						++this->_size;
						++iter;
					}
					this->erase(range_size, -1uz);
					return *this;
				}
			}
			this->reset();
			this->push_range(XTE_FWD(range));
			return *this;
		}

		[[nodiscard]] constexpr auto* data(this auto&& self) noexcept {
			return self._data;
		}

		[[nodiscard]] constexpr xte::uz size() const noexcept {
			return this->_size;
		}

		[[nodiscard]] constexpr xte::uz capacity() const noexcept {
			return this->_capacity;
		}

		[[nodiscard]] friend constexpr auto operator<=>(const xte::array<T>& lhs, const xte::array<T>& rhs) XTE_ARROW(
			xte::range_cmp(lhs, rhs)
		)

		[[nodiscard]] friend constexpr auto operator==(const xte::array<T>& lhs, const xte::array<T>& rhs) XTE_ARROW(
			(lhs._size == rhs._size) && std::is_eq(lhs <=> rhs)
		)

		[[nodiscard]] constexpr auto* begin(this auto&& self) noexcept {
			return self._data;
		}

		[[nodiscard]] constexpr const T* cbegin() const noexcept {
			return this->begin();
		}

		[[nodiscard]] constexpr auto* end(this auto&& self) noexcept {
			return self._data + self._size;
		}

		[[nodiscard]] constexpr const T* cend() const noexcept {
			return this->end();
		}

		[[nodiscard]] constexpr auto rbegin(this auto&& self) noexcept {
			return std::reverse_iterator(self.end());
		}

		[[nodiscard]] constexpr auto crbegin() const noexcept {
			return this->rbegin();
		}

		[[nodiscard]] constexpr auto rend(this auto&& self) noexcept {
			return std::reverse_iterator(self.begin());
		}

		[[nodiscard]] constexpr auto crend() const noexcept {
			return this->rend();
		}

		[[nodiscard]] constexpr auto&& front(this auto&& self, xte::uz index = 0) noexcept {
			return xte::like<decltype(self)>(self._data[index]);
		}
		
		[[nodiscard]] constexpr auto&& back(this auto&& self, xte::uz index = 0) noexcept {
			return xte::like<decltype(self)>(self._data[self._size - index - 1]);
		}

		[[nodiscard]] constexpr auto&& operator[](this auto&& self, xte::uz index) noexcept {
			return xte::like<decltype(self)>(self._data[index]);
		}

		[[nodiscard]] constexpr xte::array<T> slice(xte::uz index, xte::uz size = -1uz) const noexcept(false) {
			return (index < this->_size) ? xte::array<T>(this->begin() + index, this->begin() + index + xte::min(this->size() - index, size)) : xte::array<T>();
		}

		constexpr void reset() & noexcept {
			if (this->_capacity) {
				for (xte::uz i : std::views::indices(this->_size)) {
					xte::destroy(this->_data[i]);
				}
				std::allocator<T>().deallocate(this->_data, this->_capacity);
			}
			this->_data = nullptr;
			this->_size = 0;
			this->_capacity = 0;
		}

		constexpr void resize(xte::uz size) & noexcept(false)
		requires(xte::is_constructible<T>) {
			this->reserve_total(size);
			while (this->_size < size) {
				this->push();
			}
			this->erase(size, -1uz);
		}

		constexpr void resize(xte::uz size, const T& fill) & noexcept(false)
		requires(xte::is_copy_constructible<T>) {
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
				this->_reallocate(capacity);
			}
		}

		constexpr void shrink() & noexcept(false) {
			if (this->_capacity > this->_size) {
				this->_reallocate(this->_size);
			}
		}

		constexpr void insert_uninit(xte::uz index, xte::uz count = 1) & noexcept(false)
		requires(requires (T x) { x = T(xte::xvalue(x)); }) {
			index = xte::min(index, this->_size);
			this->reserve_total(this->_size + count);
			for (xte::uz i = count; i-- && ((this->_size - count + i) >= index);) {
				xte::construct(this->_data[this->_size + i], xte::xvalue(this->_data[this->_size - count + i]));
			}
			for (xte::uz i = this->_size; i-- && (i >= (index + count));) {
				this->_data[i] = xte::xvalue(this->_data[i - count]);
			}
			for (xte::uz i = index; (i < this->_size) && (i < (index + count)); ++i) {
				xte::destroy(this->_data[i]);
			}
			this->_size += count;
		}

		constexpr void insert(xte::uz index) & noexcept(false)
		requires(requires (T x) { x = T(); }) {
			this->reserve(this->_size == this->_capacity);
			if (index >= this->_size) {
				xte::construct(this->_data[this->_size++]);
				return;
			}
			xte::construct(this->_data[this->_size], xte::xvalue(this->_data[this->_size - 1]));
			for (xte::uz i = this->_size++ - 1; i-- > index;) {
				this->_data[i + 1] = xte::xvalue(this->_data[i]);
			}
			this->_data[index] = T();
		}

		template<typename U = T>
		constexpr void insert(xte::uz index, U&& arg, auto&&... args) & noexcept(false)
		requires(requires (T x) { x = xte::cast<T>(XTE_FWD(arg), XTE_FWD(args)...); }) {
			auto tmp = xte::cast<T>(XTE_FWD(arg), XTE_FWD(args)...);
			this->reserve(this->_size == this->_capacity);
			if (index >= this->_size) {
				xte::construct(this->_data[this->_size++], xte::xvalue(tmp));
				return;
			}
			xte::construct(this->_data[this->_size], xte::xvalue(this->_data[this->_size - 1]));
			for (xte::uz i = this->_size++ - 1; i-- > index;) {
				this->_data[i + 1] = xte::xvalue(this->_data[i]);
			}
			this->_data[index] = xte::xvalue(tmp);
		}

		template<std::ranges::input_range Range = xte::array<T>>
		constexpr void insert_range(xte::uz index, Range&& range) & noexcept(false)
		requires(requires (T x) { x = static_cast<T>(xte::like<Range>(*xte::lvalue(std::ranges::begin(range)))); }) {
			index = xte::min(index, this->_size);
			xte::uz range_size = 0;
			if constexpr (std::ranges::sized_range<Range>) {
				range_size = std::ranges::size(range);
				if ((this->_size + range_size) <= this->_capacity) {
					for (xte::uz i = range_size; i-- && ((range_size - i) <= (this->_size - index));) {
						xte::construct(this->_data[this->_size + i], xte::xvalue(this->_data[this->_size - range_size + i]));
					}
					for (xte::uz i = this->_size; i-- && (i >= (index + range_size));) {
						this->_data[i] = xte::xvalue(this->_data[i - range_size]);
					}
					auto iter = std::ranges::begin(range);
					for (xte::uz i = index; (i < this->_size) && ((i - index) < range_size); ++iter) {
						this->_data[i++] = static_cast<T>(xte::like<Range>(*iter));
					}
					for (xte::uz i = this->_size; (i - index) < range_size; ++iter) {
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
			if (index < this->_size) {
				this->_size -= (count = xte::min(count, this->_size - index));
				for (xte::uz i = index; i < this->_size; ++i) {
					this->_data[i] = xte::xvalue(this->_data[i + count]);
				}
				while (count--) {
					xte::destroy(this->_data[this->_size + count]);
				}
			}
		}

		constexpr auto push() & XTE_ARROW(
			this->insert(-1uz)
		)

		template<typename U = T>
		constexpr auto push(U&& arg, auto&&... args) & XTE_ARROW(
			this->insert(-1uz, XTE_FWD(arg), XTE_FWD(args)...)
		)

		template<typename Range = xte::array<T>>
		constexpr auto push_range(Range&& range) & XTE_ARROW(
			this->insert_range(-1uz, XTE_FWD(range))
		)

		constexpr T pop() & noexcept(xte::is_noex_move_constructible<T>) {
			auto last = T(xte::xvalue(*this).back());
			this->erase(this->_size - 1);
			return last;
		}

		[[nodiscard]] friend constexpr auto operator+(xte::is_derived_from<xte::array<T>> auto&& lhs, auto&& rhs) XTE_ARROW(
			auto(lhs.xte::template array<T>::operator+=(XTE_FWD(rhs)))
		)

		template<typename Lhs>
		requires(!xte::is_derived_from<Lhs, xte::array<T>>)
		[[nodiscard]] friend constexpr auto operator+(Lhs&& lhs, xte::is_derived_from<xte::array<T>> auto rhs) XTE_ARROW(
			rhs.xte::template array<T>::insert_range(0, XTE_FWD(lhs)),
			auto(rhs)
		)

		constexpr auto operator+=(this auto& lhs, auto&& rhs) XTE_ARROW(
			void(lhs.xte::template array<T>::push_range(XTE_FWD(rhs))),
			lhs
		)
	};

	template<typename T, typename... Ts>
	array(T&&, Ts&&...) -> array<std::common_type_t<T, Ts...>>;
}

#endif
