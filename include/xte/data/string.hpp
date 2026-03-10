#ifndef DETAIL_XTE_HEADER_DATA_STRING
#	define DETAIL_XTE_HEADER_DATA_STRING
#
#	include "../data/lowercase.hpp"
#	include "../data/range_cmp.hpp"
#	include "../data/string_view.hpp"
#	include "../data/uppercase.hpp"
#	include "../meta/type.hpp"
#	include "../math/max.hpp"
#	include "../math/min.hpp"
#	include "../preproc/diagnostic.hpp"
#	include "../preproc/fwd.hpp"
#	include "../trait/is_castable.hpp"
#	include "../trait/is_implicit_castable.hpp"
#	include "../util/address.hpp"
#	include "../util/as_c.hpp"
#	include "../util/destroy.hpp"
#	include "../util/exchange.hpp"
#	include "../util/like.hpp"
#	include "../util/lvalue.hpp"
#	include "../util/types.hpp"
#	include "../util/xvalue.hpp"
#	include <algorithm>
#	include <compare>
#	include <format>
#	include <memory>
#	include <new>
#	include <ranges>
#	include <type_traits>

namespace xte {
	struct string {
	private:
		char* _data = nullptr;
		xte::uz _size = 0;
		xte::uz _capacity = 0;

		constexpr void reset(char* data = nullptr) & noexcept {
			if (this->_capacity) {
				for (xte::uz i = 0; i < this->_size; ++i) {
					xte::destroy(this->_data[i]);
				}
				std::allocator<char>().deallocate(this->_data, this->_capacity);
			}
			this->_data = data;
		}

		constexpr void reallocate(xte::uz capacity) & noexcept(false) {
			char* data = std::allocator<char>().allocate(capacity);
			for (xte::uz i : std::views::indices(this->_size)) {
				::new(data + i) char(this->_data[i]);
			}
			this->reset(data);
			this->_capacity = capacity;
		}

	public:
		[[nodiscard]] explicit(false) constexpr string() noexcept = default;

		[[nodiscard]] explicit(false) constexpr string(const xte::string& other) noexcept(false) {
			this->reallocate(other._capacity);
			while (this->_size < other._size) {
				::new(this->_data + this->_size) char(other._data[this->_size++]);
			}
		}

		[[nodiscard]] explicit(false) constexpr string(xte::string& other) noexcept(false)
		: xte::string(xte::as_c(other)) {}

		[[nodiscard]] explicit(false) constexpr string(xte::string&& other) noexcept
		: _data(xte::exchange(other._data, nullptr))
		, _size(xte::exchange(other._size, 0))
		, _capacity(xte::exchange(other._capacity, 0)) {}

		[[nodiscard]] explicit(false) constexpr string(const xte::string&& other) noexcept(false)
		: xte::string(other) {}

		[[nodiscard]] constexpr string(const char* data, xte::uz size) noexcept(false) {
			if (size) {
				while (size && !data[size - 1]) {
					--size;
				}
				this->reserve(size);
				for (xte::uz i : std::views::indices(size)) {
					::new(this->_data + i) char(data[i]);
				}
				::new(this->_data + size) char('\0');
				this->_size = size + 1;
			}
		}

		[[nodiscard]] explicit(false) constexpr string(char c, xte::uz size = 1) noexcept(false) {
			this->resize(size, c);
		}

		template<xte::uz size>
		[[nodiscard]] explicit(false) constexpr string(const xte::type<char[size]>& data) noexcept(false)
		: xte::string(data, size) {}

		[[nodiscard]] explicit constexpr string(const xte::is_implicit_castable<const char*> auto&& range) noexcept(false) {
			if (const char* data = range) {
				while (*data) {
					this->push(*data++);
				}
			}
		}

		template<std::ranges::input_range Range>
		requires(xte::is_castable<std::ranges::range_value_t<Range>, char>)
		[[nodiscard]] explicit constexpr string(Range&& range) noexcept(false) {
			if constexpr (std::ranges::sized_range<Range>) {
				this->reserve(std::ranges::size(range));
			}
			xte::uz last = 0;
			xte::uz i = 0;
			for (char c : range) {
				this->push(c);
				if (this->_data[i++]) {
					last = i;
				}
			}
			this->resize(last);
		}

		constexpr ~string() {
			this->reset();
		}

		constexpr xte::string& operator=(const xte::string& other) & noexcept(false) {
			if (this != xte::address(other)) {
				this->reset();
				this->reserve(other._capacity);
				for (char c : other) {
					this->push(c);
				}
			}
			return *this;
		}

		constexpr xte::string& operator=(xte::string&& other) & noexcept {
			if (this == xte::address(other)) {
				return *this;
			}
			this->~string();
			return *::new(this) xte::string(xte::xvalue(other));
		}

		[[nodiscard]] constexpr auto&& operator[](this auto&& self, xte::uz index) noexcept {
			return xte::like<decltype(self)>(self._data[index]);
		}

		[[nodiscard]] constexpr char* data() const noexcept {
			return this->_data;
		}

		[[nodiscard]] constexpr xte::uz size() const noexcept {
			return this->_size - !!this->_size;
		}

		[[nodiscard]] constexpr xte::uz capacity() const noexcept {
			return this->_capacity;
		}

		[[nodiscard]] constexpr char* begin() const & noexcept {
			return this->_data;
		}

		[[nodiscard]] constexpr char* end() const & noexcept {
			return this->_data + !!this->_data * ~-this->_size;
		}

		[[nodiscard]] constexpr auto&& front(this auto&& self, xte::uz index = 0) noexcept {
			return XTE_FWD(self)._data[index];
		}
		
		[[nodiscard]] constexpr auto&& back(this auto&& self, xte::uz index = 0) noexcept {
			return XTE_FWD(self)._data[self._size - index - 2];
		}

		[[nodiscard]] friend constexpr std::strong_ordering operator<=>(const xte::string& lhs, const xte::string& rhs) noexcept {
			return xte::range_cmp(lhs, rhs);
		}

		[[nodiscard]] friend constexpr bool operator==(const xte::string& lhs, const xte::string& rhs) noexcept {
			return std::is_eq(lhs <=> rhs);
		}

		constexpr void resize(xte::uz size, char fill = '\0') & noexcept(false) {
			if (this->_size <= size) {
				this->reserve(size - this->_size);
				while (this->_size <= size) {
					this->push(fill);
				}
				return;
			}
			this->erase(size, -1uz);
		}

		constexpr void reserve(xte::uz additional = 1) & noexcept(false) {
			if (additional) {
				XTE_DIAGNOSTIC_PUSH_GCC(OFF, "-Winterference-size")
				xte::uz new_capacity = xte::max(this->_capacity, std::hardware_destructive_interference_size);
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

		template<xte::is_castable<char> U = char>
		constexpr void insert(xte::uz index, U&& x = {}) & noexcept(false) {
			if (index <= (this->_size - !!this->_size)) {
				this->reserve(this->_size >= this->_capacity);
				for (xte::uz i = this->_size; i-- > index;) {
					this->_data[i] = this->_data[i - 1];
				}
				this->_data[index] = static_cast<char>(XTE_FWD(x));
				this->_size += 1 + !this->_size;
				::new(this->_data + this->_size - 1) char('\0');
			}
		}

		template<std::ranges::input_range Range>
		requires(xte::is_castable<std::ranges::range_value_t<Range>, char>)
		constexpr void insert(xte::uz index, Range&& range) & noexcept(false) {
			if (index <= (this->_size - !!this->_size)) {
				xte::string old = xte::xvalue(*this);
				this->reserve(old._capacity);
				if constexpr (std::ranges::sized_range<Range>) {
					this->reserve(std::ranges::size(range));
				}
				for (char c : old | std::views::take(index)) {
					this->push(c);
				}
				for (auto&& item : range) {
					this->push(xte::like<decltype(range)>(item));
				}
				for (char c : old | std::views::drop(index)) {
					this->push(c);
				}
			}
		}

		constexpr void erase(xte::uz index, xte::uz count = 1) & noexcept {
			if (index <= (this->_size - !!this->_size)) {
				count = xte::min(count, this->_size - !!this->_size - index);
				for (xte::uz i = index; i < (this->_size - !!this->_size - count); ++i) {
					this->_data[i] = this->_data[i + count];
					xte::destroy(this->_data[this->_size - !!this->_size - count + i]);
				}
				if (this->_size -= count) {
					this->_data[this->_size - 1] = '\0';
				}
			}
		}

		template<xte::is_castable<char> U = char>
		constexpr void push(U&& x = {}) & noexcept(false) {
			this->insert(this->_size - !!this->_size, XTE_FWD(x));
		}

		template<std::ranges::input_range Range>
		requires(xte::is_castable<std::ranges::range_value_t<Range>, char>)
		constexpr void push(Range&& range) & noexcept(false) {
			this->insert(this->_size - !!this->_size, XTE_FWD(range));
		}

		constexpr char pop() & noexcept {
			char last = this->back();
			this->erase(this->_size - 1);
			return last;
		}

		constexpr xte::string& operator+=(xte::string_view rhs) & noexcept(false) {
			this->push(rhs);
			return *this;
		}

		[[nodiscard]] friend constexpr xte::string operator+(xte::string_view lhs, xte::string_view rhs) noexcept(false) {
			return xte::lvalue(xte::string(lhs)) += rhs;
		}

		[[nodiscard]] constexpr xte::string uppercase() const noexcept {
			return xte::uppercase(*this);
		}

		[[nodiscard]] constexpr xte::string lowercase() const noexcept {
			return xte::lowercase(*this);
		}
	};
}

namespace xte::literal::string {
	[[nodiscard]] constexpr xte::string operator""_str(const char* data, xte::uz size) noexcept(false) {
		return xte::string(data, size);
	}
}

template<>
struct std::formatter<xte::string> {
	[[nodiscard]] constexpr auto parse(std::format_parse_context& ctx) noexcept {
		return ctx.begin();
	}

	[[nodiscard]] auto format(const xte::string& string, std::format_context& ctx) const noexcept(false) {
		return std::ranges::copy(string, ctx.out()).out;
	}
};

#endif
