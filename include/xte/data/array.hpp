#ifndef DETAIL_XTE_HEADER_DATA_ARRAY
#	define DETAIL_XTE_HEADER_DATA_ARRAY
#
#	include "../data/range_cmp.hpp"
#	include "../func/with_result.hpp"
#	include "../math/max.hpp"
#	include "../preproc/diagnostic.hpp"
#	include "../preproc/fwd.hpp"
#	include "../preproc/lift.hpp"
#	include "../trait/is_castable.hpp"
#	include "../trait/is_derived_from.hpp"
#	include "../trait/is_noex_move_assignable.hpp"
#	include "../trait/is_noex_move_ctor.hpp"
#	include "../trait/is_input_sized_range.hpp"
#	include "../util/exchange.hpp"
#	include "../util/like.hpp"
#	include "../util/types.hpp"
#	include "../util/xvalue.hpp"
#	include <compare>
#	include <initializer_list>
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

		[[nodiscard]] constexpr T* reallocate(xte::uz capacity) & noexcept(false) {
			T* data = std::allocator<T>().allocate(capacity);
			for (xte::uz i : std::views::indices(this->size())) {
				::new(data + i) T(xte::xvalue(*this)[i]);
			}
			return data;
		}

		constexpr void reset(T* data = nullptr) & noexcept(std::is_nothrow_destructible_v<T>) {
			if (this->capacity()) {
				for (T& item : *this) {
					item.~T();
				}
				std::allocator<T>().deallocate(this->data(), this->capacity());
			}
			this->_data = data;
		}

	public:
		[[nodiscard]] explicit(false) array() = default;

		[[nodiscard]] explicit(false) constexpr array(const xte::array<T>& other) noexcept(false) {
			this->_data = this->reallocate(other.capacity());
			while (this->size() < other.size()) {
				::new(this->data() + this->size()) T(other[this->_size++]);
			}
		}

		[[nodiscard]] explicit(false) constexpr array(xte::array<T>&& other) noexcept
		: _data(xte::exchange(other._data, nullptr))
		, _size(xte::exchange(other._size, 0))
		, _capacity(xte::exchange(other._capacity, 0)) {}

		[[nodiscard]] explicit(false) constexpr array(std::initializer_list<T> init_list) noexcept(false) {
			this->reserve_exact(init_list.size());
			for (auto&& item : init_list) {
				this->push(item);
			}
		}

		template<xte::is_input_sized_range Range>
		requires(xte::is_castable<std::ranges::range_value_t<Range>, T>)
		[[nodiscard]] explicit constexpr array(Range&& range) noexcept(false) {
			this->reserve_exact(std::ranges::size(range));
			for (auto&& item : range) {
				this->push(xte::like<decltype(range)>(item));
			}
		}

		template<std::ranges::input_range Range>
		requires(xte::is_castable<std::ranges::range_value_t<Range>, T>)
		[[nodiscard]] explicit(false) constexpr array(Range&& range) noexcept(false) {
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

		[[nodiscard]] constexpr auto&& operator[](this auto&& self, xte::uz index) noexcept {
			return xte::like<decltype(self)>(self.data()[index]);
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
			return this->data();
		}

		[[nodiscard]] constexpr T* end() const & noexcept {
			return this->data() + this->size();
		}

		[[nodiscard]] constexpr auto&& front(this auto&& self, xte::uz index = 0) noexcept {
			return XTE_FWD(self)[index];
		}
		
		[[nodiscard]] constexpr auto&& back(this auto&& self, xte::uz index = 0) noexcept {
			return XTE_FWD(self)[self.size() - index - 1];
		}

		[[nodiscard]] friend constexpr auto operator<=>(const xte::array<T>& lhs, const xte::array<T>& rhs) XTE_ARROW(
			xte::range_cmp(lhs, rhs)
		)

		[[nodiscard]] friend constexpr auto operator==(const xte::array<T>& lhs, const xte::array<T>& rhs) XTE_ARROW(
			std::is_eq(lhs <=> rhs)
		)

		constexpr void resize(xte::uz size, const T& fill = {}) & noexcept(false) {
			if (this->size() < size) {
				this->reserve(this->size() - size);
				while (this->size() < size) {
					(*this)[++this->_size] = fill;
				}
				return;
			}
			while (this->size() > size) {
				(*this)[--this->_size].~T();
			}
		}

		constexpr void reserve(xte::uz additional = 1) & noexcept(false) {
			if (additional) {
				XTE_DIAGNOSTIC_PUSH_GCC(OFF, "-Winterference-size")
				xte::uz new_capacity = xte::max(std::hardware_destructive_interference_size / sizeof(T), this->capacity());
				XTE_DIAGNOSTIC_POP_GCC()
				while (new_capacity <= (this->capacity() + additional)) {
					new_capacity += new_capacity / 2;
				}
				this->reserve_exact(new_capacity - this->capacity());
			}
		}

		constexpr void reserve_exact(xte::uz additional) & noexcept(false) {
			if (additional) {
				this->reset(this->reallocate(this->capacity() + additional));
				this->_capacity += additional;
			}
		}

		constexpr void shrink() & noexcept(false) {
			if (this->capacity() != this->size()) {
				this->reset(this->reallocate(this->size()));
			}
		}

		template<xte::is_castable<T> U = T>
		constexpr void insert(xte::uz index, U&& x = {}) & noexcept(false) {
			this->reserve(this->size() == this->capacity());
			if (index >= this->size()) {
				::new(this->data() + this->_size++) T(XTE_FWD(x));
				return;
			}
			::new(this->data() + this->_size++) T(xte::xvalue(*this).back());
			for (xte::uz i = this->size(); --i > index;) {
				(*this)[i] = xte::xvalue(*this)[i - 1];
			}
		}

		template<std::ranges::input_range Range>
		requires(xte::is_castable<std::ranges::range_value_t<Range>, T>)
		constexpr void insert(xte::uz index, Range&& range) & noexcept(false) {
			xte::array<T> old = xte::xvalue(*this);
			this->reserve(old.capacity());
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

		constexpr void erase(xte::uz index, xte::uz count = 1) & noexcept(xte::is_noex_move_assignable<T>) {
			if (count) {
				for (; index < (this->size() - count); ++index) {
					(*this)[index] = xte::xvalue(*this)[index + count];
				}
				while (count--) {
					(*this)[--this->_size].~T();
				}
			}
		}

		template<xte::is_castable<T> U = T>
		constexpr void push(U&& x = xte::with_result(XTE_LIFT(U))) & noexcept(false) {
			this->insert(this->size(), XTE_FWD(x));
		}

		template<std::ranges::input_range Range>
		requires(xte::is_castable<std::ranges::range_value_t<Range>, T>)
		constexpr void push(Range&& range) & noexcept(false) {
			this->insert(this->size(), XTE_FWD(range));
		}

		constexpr T pop() & noexcept(xte::is_noex_move_ctor<T>) {
			auto last = T(xte::xvalue(*this)[this->size() - 1]);
			this->erase(this->size() - 1);
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
			lhs.xte::template array<T>::push(XTE_FWD(rhs));
			return lhs;
		}
	};
}

#endif
