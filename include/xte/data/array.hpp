#ifndef DETAIL_XTE_HEADER_DATA_ARRAY
#	define DETAIL_XTE_HEADER_DATA_ARRAY
#
#	include "../data/range_compare.hpp"
#	include "../math/max.hpp"
#	include "../math/min.hpp"
#	include "../meta/req_not.hpp"
#	include "../preproc/constructs.hpp"
#	include "../preproc/diagnostic.hpp"
#	include "../preproc/fwd.hpp"
#	include "../preproc/returns.hpp"
#	include "../trait/is_constructible.hpp"
#	include "../trait/is_copy_constructible.hpp"
#	include "../trait/is_derived_from.hpp"
#	include "../trait/is_destructible_noex.hpp"
#	include "../trait/is_invocable.hpp"
#	include "../trait/is_range_noex.hpp"
#	include "../trait/is_same_drop_cvref.hpp"
#	include "../util/address.hpp"
#	include "../util/as_const_lvalue.hpp"
#	include "../util/as_lvalue.hpp"
#	include "../util/as_xvalue.hpp"
#	include "../util/as_xvalue_if_noex.hpp"
#	include "../util/assign.hpp"
#	include "../util/construct.hpp"
#	include "../util/destroy.hpp"
#	include "../util/exchange.hpp"
#	include "../util/init_list.hpp"
#	include "../util/like.hpp"
#	include "../util/make.hpp"
#	include "../util/number_types.hpp"
#	include "../util/reconstruct.hpp"
#	include <compare>
#	include <iterator>
#	include <memory>
#	include <new>
#	include <ranges>
#	include <type_traits>

namespace xte {
	template<xte::is_destructible_noex item_type>
	struct array {
	private:
		item_type* _data = nullptr;
		xte::uz _size = 0;
		xte::uz _capacity = 0;

		constexpr void _reallocate(xte::uz capacity) & noexcept(false) {
			if (xte::array<item_type> old = xte::as_xvalue(*this); capacity) {
				this->_data = std::allocator<item_type>().allocate(capacity);
				this->_capacity = capacity;
				try {
					for (xte::uz i = 0; i < old._size; this->_size = ++i) {
						xte::construct(this->_data[i], xte::as_xvalue_if_noex(old._data[i]));
					}
				} catch (...) {
					*this = xte::as_xvalue(old);
					throw;
				}
			}
		}

	public:
		using value_type = item_type;
		using reference = item_type&;
		using const_reference = const item_type&;
		using pointer = item_type*;
		using const_pointer = const item_type*;
		using iterator = item_type*;
		using const_iterator = const item_type*;
		using reverse_iterator = std::reverse_iterator<item_type*>;
		using const_reverse_iterator = std::reverse_iterator<const item_type*>;
		using allocator_type = std::allocator<item_type>;
		using size_type = xte::uz;
		using difference_type = xte::iptrdiff;

		[[nodiscard]] explicit(false) constexpr array() noexcept = default;

		[[nodiscard]] explicit(false) constexpr array(const xte::array<item_type>& other) noexcept(false)
		requires(xte::is_copy_constructible<item_type>)
		: xte::array<item_type>(std::from_range, other) {}

		[[nodiscard]] explicit(false) constexpr array(xte::array<item_type>&& other) noexcept
		: _data(xte::exchange(other._data, nullptr))
		, _size(xte::exchange(other._size, 0))
		, _capacity(xte::exchange(other._capacity, 0)) {}

		[[nodiscard]] explicit(false) constexpr array(xte::init_list<item_type> init_list) noexcept(false)
		requires(requires (item_type x) { xte::make<item_type>(xte::as_xvalue(x)); })
		: xte::array<item_type>(std::from_range, xte::as_xvalue(init_list)) {}

		template<std::ranges::input_range range_type>
		[[nodiscard]] constexpr array(std::from_range_t, range_type&& range) noexcept(false)
		requires(requires { item_type(xte::like<range_type>(*xte::as_lvalue(std::ranges::begin(range)))); }
			&& (std::ranges::sized_range<range_type>
				|| requires (item_type x) { item_type(xte::as_xvalue_if_noex(x)); }))
		try {
			if constexpr (std::ranges::sized_range<range_type>) {
				this->reserve_total(std::ranges::size(range));
			}
			for (auto&& item : range) {
				if constexpr (!std::ranges::sized_range<range_type>) {
					this->reserve(this->_size == this->_capacity);
				}
				xte::construct(this->_data[this->_size], xte::like<range_type>(item));
				++this->_size;
			}
		} catch (...) {
			this->reset();
		}

		[[nodiscard]] constexpr array(std::from_range_t, xte::array<item_type>&& other) noexcept
		: xte::array<item_type>(xte::as_xvalue(other)) {}

		template<std::input_iterator iter_type>
		[[nodiscard]] constexpr array(iter_type begin, std::sentinel_for<iter_type> auto end) XTE_CONSTRUCTS(,
			(xte::array<item_type>),((std::from_range, xte::as_const_lvalue(std::ranges::subrange(begin, end))))
		)

		[[nodiscard]] explicit constexpr array(xte::uz size, auto&&... args) noexcept(false)
		requires(requires { item_type(args...); })
		try {
			this->reserve_total(size);
			while (this->_size < size) {
				xte::construct(this->_data[this->_size], args...);
				++this->_size;
			}
		} catch (...) {
			this->reset();
		}

		[[nodiscard]] constexpr array(xte::uz size, const item_type& fill) noexcept(false)
		requires(xte::is_copy_constructible<item_type>)
		try {
			this->reserve_total(size);
			while (this->_size < size) {
				xte::construct(this->_data[this->_size], fill);
				++this->_size;
			}
		} catch (...) {
			this->reset();
		}

		constexpr ~array() {
			this->reset();
		}

		constexpr xte::array<item_type>& operator=(const xte::array<item_type>& other) & noexcept(false)
		requires(requires (item_type x) { xte::construct(x, x); }) {
			if (this != xte::address(other)) {
				*this = std::ranges::subrange(other);
			}
			return *this;
		}

		constexpr xte::array<item_type>& operator=(xte::array<item_type>&& other) & noexcept {
			return (this == xte::address(other)) ? *this : xte::reconstruct(*this, xte::as_xvalue(other));
		}

		template<std::ranges::input_range range_type>
		constexpr xte::array<item_type>& operator=(range_type&& range) & noexcept(false)
		requires(!xte::is_derived_from<range_type, xte::array<item_type>>
			&& requires { item_type(xte::like<range_type>(*xte::as_lvalue(std::ranges::begin(range)))); })
		{
			if constexpr (std::ranges::sized_range<range_type>) {
				if (xte::uz range_size = std::ranges::size(range); range_size <= this->_capacity) {
					auto iter = std::ranges::begin(range);
					for (xte::uz i : std::views::indices(xte::min(this->_size, range_size))) {
						xte::assign(this->_data[i], xte::like<range_type>(*iter));
						++iter;
					}
					while (this->_size < range_size) {
						xte::construct(this->_data[this->_size], xte::like<range_type>(*iter));
						++this->_size;
						++iter;
					}
					this->truncate(range_size);
					return *this;
				}
			}
			this->reset();
			this->append_range(XTE_FWD(range));
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

		[[nodiscard]] friend constexpr auto operator<=>(const xte::array<item_type>& lhs, const xte::array<item_type>& rhs) XTE_RETURNS(
			xte::range_compare(lhs, rhs)
		)

		[[nodiscard]] friend constexpr auto operator==(const xte::array<item_type>& lhs, const xte::array<item_type>& rhs) XTE_RETURNS(
			(lhs._size == rhs._size) && std::is_eq(lhs <=> rhs)
		)

		[[nodiscard]] constexpr auto* begin(this auto&& self) noexcept {
			return self._data;
		}

		[[nodiscard]] constexpr const item_type* cbegin() const noexcept {
			return this->begin();
		}

		[[nodiscard]] constexpr auto* end(this auto&& self) noexcept {
			return self._data + self._size;
		}

		[[nodiscard]] constexpr const item_type* cend() const noexcept {
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

		[[nodiscard]] constexpr xte::array<item_type> subrange(this auto&& self, xte::uz index, xte::uz size = -1uz) noexcept(false) {
			return (index < self._size) ? xte::array<item_type>(std::from_range, xte::like<decltype(self)>(std::ranges::subrange(self.begin() + index, self.begin() + index + xte::min(self.size() - index, size)))) : xte::array<item_type>();
		}

		constexpr void reset() & noexcept {
			if (this->_capacity) {
				for (item_type& item : *this) {
					xte::destroy(item);
				}
				std::allocator<item_type>().deallocate(this->_data, this->_capacity);
			}
			this->_data = nullptr;
			this->_size = 0;
			this->_capacity = 0;
		}

		constexpr void resize(xte::uz size) & noexcept(false)
		requires(xte::is_constructible<item_type>
			&& requires (item_type x) { item_type(xte::as_xvalue_if_noex(x)); })
		{
			this->reserve_total(size);
			while (this->_size < size) {
				this->append();
			}
			this->truncate(size);
		}

		constexpr void resize(xte::uz size, const item_type& fill) & noexcept(false)
		requires(xte::is_copy_constructible<item_type>
			&& requires (item_type x) { item_type(xte::as_xvalue_if_noex(x)); })
		{
			this->reserve_total(size);
			while (this->_size < size) {
				this->append(fill);
			}
			this->truncate(size);
		}

		constexpr void reserve(xte::uz additional = 1) & noexcept(false)
		requires(requires (item_type x) { item_type(xte::as_xvalue_if_noex(x)); }) {
			this->reserve_total(this->_capacity + additional);
		}

		constexpr void reserve_total(xte::uz total) & noexcept(false)
		requires(requires (item_type x) { item_type(xte::as_xvalue_if_noex(x)); }) {
			if (total > this->_capacity) {
				XTE_DIAGNOSTIC_PUSH_GCC(OFF, "-Winterference-size")
				xte::uz capacity = xte::max(this->_capacity, std::hardware_destructive_interference_size / sizeof(item_type));
				XTE_DIAGNOSTIC_POP_GCC()
				while (capacity < total) {
					capacity += xte::max(1, capacity / 2);
				}
				this->_reallocate(capacity);
			}
		}

		constexpr void reserve_and_init(xte::uz additional, xte::is_invocable<xte::uz(item_type*, xte::uz)> auto&& op) & noexcept(false) {
			this->reserve_total(this->_size + additional);
			this->_size += XTE_FWD(op)(this->_data + this->_size, additional);
		}

		constexpr void shrink_to_fit() & noexcept(false) {
			if (this->_capacity > this->_size) {
				this->_reallocate(this->_size);
			}
		}

		constexpr void insert(xte::uz index) & noexcept(false)
		requires(xte::is_constructible<item_type>
			&& requires (item_type x) { { item_type(xte::as_xvalue_if_noex(x)) } noexcept; }
			&& requires (item_type x) { { xte::assign(x, xte::as_xvalue_if_noex(x)) } noexcept; })
		{
			this->reserve(this->_size == this->_capacity);
			if (index >= this->_size) {
				xte::construct(this->_data[this->_size++]);
				return;
			}
			xte::construct(this->_data[this->_size], xte::as_xvalue_if_noex(this->_data[this->_size - 1]));
			for (xte::uz i = this->_size++ - 1; i-- > index;) {
				xte::assign(this->_data[i + 1], xte::as_xvalue_if_noex(this->_data[i]));
			}
			xte::assign(this->_data[index]);
		}

		template<typename arg_type = item_type>
		constexpr void insert(xte::uz index, arg_type&& arg, auto&&... args) & noexcept(false)
		requires(requires { item_type(XTE_FWD(arg), XTE_FWD(args)...); }
			&& requires (item_type x) { { item_type(xte::as_xvalue_if_noex(x)) } noexcept; }
			&& requires (item_type x) { { xte::assign(x, xte::as_xvalue_if_noex(x)) } noexcept; })
		{
			if (this->_size < this->_capacity) {
				if (index >= this->_size) {
					xte::construct(this->_data[this->_size++], XTE_FWD(arg), XTE_FWD(args)...);
					return;
				}
			}
			auto tmp = xte::make<item_type>(XTE_FWD(arg), XTE_FWD(args)...);
			this->reserve(this->_size == this->_capacity);
			if (index >= this->_size) {
				xte::construct(this->_data[this->_size++], xte::as_xvalue_if_noex(tmp));
				return;
			}
			xte::construct(this->_data[this->_size], xte::as_xvalue_if_noex(this->_data[this->_size - 1]));
			for (xte::uz i = this->_size++ - 1; i-- > index;) {
				xte::assign(this->_data[i + 1], xte::as_xvalue_if_noex(this->_data[i]));
			}
			xte::assign(this->_data[index], xte::as_xvalue_if_noex(tmp));
		}

		template<std::ranges::input_range range_type = xte::array<item_type>>
		constexpr void insert_range(xte::uz index, range_type&& range) & noexcept(false)
		requires(xte::is_range_noex<range_type>
			&& requires (item_type x, decltype(std::ranges::begin(range)) iter) {
				{ item_type(xte::as_xvalue_if_noex(x)) } noexcept;
				{ xte::assign(x, xte::as_xvalue_if_noex(x)) } noexcept;
				{ item_type(xte::as_xvalue_if_noex(*iter)) } noexcept;
				{ xte::assign(x, xte::as_xvalue_if_noex(*iter)) } noexcept; })
		{
			index = xte::min(index, this->_size);
			auto range_copy = xte::array<item_type>(std::from_range, XTE_FWD(range));
			xte::uz range_size = 0;
			if constexpr (std::ranges::sized_range<range_type>) {
				range_size = std::ranges::size(range_copy);
				if ((this->_size + range_size) <= this->_capacity) {
					for (xte::uz i = range_size; i-- && ((range_size - i) <= (this->_size - index));) {
						xte::construct(this->_data[this->_size + i], xte::as_xvalue_if_noex(this->_data[this->_size - range_size + i]));
					}
					for (xte::uz i = this->_size; i-- && (i >= (index + range_size));) {
						xte::assign(this->_data[i], xte::as_xvalue_if_noex(this->_data[i - range_size]));
					}
					auto iter = std::ranges::begin(range_copy);
					for (xte::uz i = index; (i < this->_size) && ((i - index) < range_size); ++iter) {
						xte::assign(this->_data[i++], xte::as_xvalue_if_noex(*iter));
					}
					for (xte::uz i = this->_size; (i - index) < range_size; ++iter) {
						xte::construct(this->_data[i++], xte::as_xvalue_if_noex(*iter));
					}
					this->_size += range_size;
					return;
				}
			}
			xte::array<item_type> old = xte::as_xvalue(*this);
			this->reserve_total(old._size + range_size);
			for (auto&& item : old | std::views::take(index)) {
				this->append(xte::as_xvalue_if_noex(item));
			}
			for (auto&& item : range_copy) {
				this->append(xte::as_xvalue_if_noex(item));
			}
			for (auto&& item : old | std::views::drop(index)) {
				this->append(xte::as_xvalue_if_noex(item));
			}
		}

		constexpr void insert_fill(xte::uz index, xte::uz count) & noexcept(false)
		requires(xte::is_constructible_noex<item_type>
			&& requires (item_type x) { { item_type(xte::as_xvalue_if_noex(x)) } noexcept; }
			&& requires (item_type x) { { xte::assign(x, xte::as_xvalue_if_noex(x)) } noexcept; })
		{
			index = xte::min(index, this->_size);
			if ((this->_size + count) <= this->_capacity) {
				for (xte::uz i = count; i-- && ((count - i) <= (this->_size - index));) {
					xte::construct(this->_data[this->_size + i], xte::as_xvalue_if_noex(this->_data[this->_size - count + i]));
				}
				for (xte::uz i = this->_size; i-- && (i >= (index + count));) {
					xte::assign(this->_data[i], xte::as_xvalue_if_noex(this->_data[i - count]));
				}
				for (xte::uz i = index; (i < this->_size) && ((i - index) < count);) {
					xte::assign(this->_data[i++]);
				}
				for (xte::uz i = this->_size; (i - index) < count;) {
					xte::construct(this->_data[i++]);
				}
				this->_size += count;
				return;
			}
			xte::array<item_type> old = xte::as_xvalue(*this);
			this->reserve_total(old._size + count);
			for (auto&& item : old | std::views::take(index)) {
				this->append(xte::as_xvalue_if_noex(item));
			}
			while (count--) {
				this->append();
			}
			for (auto&& item : old | std::views::drop(index)) {
				this->append(xte::as_xvalue_if_noex(item));
			}
		}

		template<typename arg_type = item_type>
		constexpr void insert_fill(xte::uz index, xte::uz count, arg_type&& arg, auto&&... args) & noexcept(false)
		requires(requires { item_type(XTE_FWD(arg), XTE_FWD(args)...); }
			&& xte::is_copy_constructible_noex<item_type>
			&& requires (item_type x, const item_type fill) { { xte::assign(x, fill) } noexcept; }
			&& requires (item_type x) { { item_type(xte::as_xvalue_if_noex(x)) } noexcept; }
			&& requires (item_type x) { { xte::assign(x, xte::as_xvalue_if_noex(x)) } noexcept; })
		{
			index = xte::min(index, this->_size);
			const auto fill = xte::make<item_type>(XTE_FWD(arg), XTE_FWD(args)...);
			if ((this->_size + count) <= this->_capacity) {
				for (xte::uz i = count; i-- && ((count - i) <= (this->_size - index));) {
					xte::construct(this->_data[this->_size + i], xte::as_xvalue_if_noex(this->_data[this->_size - count + i]));
				}
				for (xte::uz i = this->_size; i-- && (i >= (index + count));) {
					xte::assign(this->_data[i], xte::as_xvalue_if_noex(this->_data[i - count]));
				}
				for (xte::uz i = index; (i < this->_size) && ((i - index) < count);) {
					xte::assign(this->_data[i++], fill);
				}
				for (xte::uz i = this->_size; (i - index) < count;) {
					xte::construct(this->_data[i++], fill);
				}
				this->_size += count;
				return;
			}
			xte::array<item_type> old = xte::as_xvalue(*this);
			this->reserve_total(old._size + count);
			for (auto&& item : old | std::views::take(index)) {
				this->append(xte::as_xvalue_if_noex(item));
			}
			while (count--) {
				this->append(fill);
			}
			for (auto&& item : old | std::views::drop(index)) {
				this->append(xte::as_xvalue_if_noex(item));
			}
		}

		constexpr void erase(xte::uz index, xte::uz count = 1) & noexcept(false)
		requires(requires (item_type x) { { xte::assign(x, xte::as_xvalue_if_noex(x)) } noexcept; }) {
			if (index < this->_size) {
				count = xte::min(count, this->_size - index);
				this->_size -= count;
				for (xte::uz i = index; i < this->_size; ++i) {
					xte::assign(this->_data[i], xte::as_xvalue_if_noex(this->_data[i + count]));
				}
				for (xte::uz i : std::views::indices(count)) {
					xte::destroy(this->_data[this->_size + i]);
				}
			}
		}

		constexpr void append() & noexcept(false)
		requires(xte::is_constructible<item_type>
			&& requires (item_type x) { item_type(xte::as_xvalue_if_noex(x)); })
		{
			this->reserve(this->_size == this->_capacity);
			xte::construct(this->_data[this->_size]);
			++this->_size;
		}

		template<typename arg_type = item_type>
		constexpr void append(arg_type&& arg, auto&&... args) & noexcept(false)
		requires(requires { item_type(XTE_FWD(arg), XTE_FWD(args)...); }
			&& requires (item_type x) { item_type(xte::as_xvalue_if_noex(x)); })
		{
			if (this->_size == this->_capacity) {
				auto tmp = xte::make<item_type>(XTE_FWD(arg), XTE_FWD(args)...);
				this->reserve();
				xte::construct(this->_data[this->_size], xte::as_xvalue_if_noex(tmp));
			} else {
				xte::construct(this->_data[this->_size], XTE_FWD(arg), XTE_FWD(args)...);
			}
			++this->_size;
		}

		template<std::ranges::input_range range_type = xte::array<item_type>>
		constexpr void append_range(range_type&& range) & noexcept(false)
		requires(requires { item_type(xte::as_xvalue_if_noex(*xte::as_lvalue(std::ranges::begin(range)))); }
			&& requires (item_type x) { item_type(xte::as_xvalue_if_noex(x)); })
		{
			auto range_copy = xte::array<item_type>(std::from_range, XTE_FWD(range));
			this->reserve_total(this->_size + range_copy.size());
			for (auto&& item : range_copy) {
				xte::construct(this->_data[this->_size], xte::as_xvalue_if_noex(item));
				++this->_size;
			}
		}

		constexpr void append_fill(xte::uz count) & noexcept(false)
		requires(xte::is_constructible<item_type>
			&& requires (item_type x) { item_type(xte::as_xvalue_if_noex(x)); })
		{
			this->reserve_total(this->_size + count);
			while (count--) {
				xte::construct(this->_data[this->_size]);
				++this->_size;
			}
		}

		constexpr void append_fill(xte::uz count, const item_type& fill) & noexcept(false)
		requires(xte::is_copy_constructible<item_type>
			&& requires (item_type x) { item_type(xte::as_xvalue_if_noex(x)); })
		{
			this->reserve_total(this->_size + count);
			while (count--) {
				xte::construct(this->_data[this->_size], fill);
				++this->_size;
			}
		}

		constexpr item_type pop_back() &
		noexcept(requires (item_type x) { { item_type(xte::as_xvalue_if_noex(x)) } noexcept; }) {
			auto last = item_type(xte::as_xvalue_if_noex(this->back()));
			xte::destroy(this->_data[--this->_size]);
			return last;
		}

		constexpr void truncate(xte::uz size) & noexcept {
			while (this->_size > size) {
				xte::destroy(this->_data[--this->_size]);
			}
		}

		[[nodiscard]] friend constexpr auto operator+(xte::array<item_type> lhs, auto&& rhs) XTE_RETURNS(
			auto(xte::as_xvalue(lhs += XTE_FWD(rhs)))
		)

		[[nodiscard]] friend constexpr auto operator+(xte::req_not<[]<xte::is_derived_from<xte::array<item_type>>>{}> auto&& lhs, xte::array<item_type> rhs) XTE_RETURNS(
			rhs.insert_range(0, XTE_FWD(lhs)),
			auto(xte::as_xvalue(rhs))
		)

		constexpr auto operator+=(auto&& rhs) XTE_RETURNS(
			this->append_range(XTE_FWD(rhs)),
			*this
		)
	};

	template<typename item_type, typename... types>
	array(item_type&&, types&&...) -> array<std::common_type_t<item_type, types...>>;
}

#endif
