#ifndef DETAIL_XTE_HEADER_DATA_STRING
#	define DETAIL_XTE_HEADER_DATA_STRING
#
#	include "../data/array.hpp"
#	include "../data/init_list.hpp"
#	include "../data/string_view.hpp"
#	include "../math/min.hpp"
#	include "../meta/type.hpp"
#	include "../preproc/arrow.hpp"
#	include "../preproc/fwd.hpp"
#	include "../trait/is_derived_from.hpp"
#	include "../trait/is_noex_implicit_castable.hpp"
#	include "../util/like.hpp"
#	include "../util/lvalue.hpp"
#	include "../util/types.hpp"
#	include "../util/xvalue.hpp"
#	include <algorithm>
#	include <compare>
#	include <cstdint>
#	include <format>
#	include <iterator>
#	include <memory>
#	include <ranges>

namespace xte {
	struct string {
	private:
		xte::array<char> _data;

	public:
		using value_type = char;
		using allocator_type = xte::array<char>::allocator_type;
		using size_type = xte::uz;
		using difference_type = std::ptrdiff_t;
		using reference = char&;
		using const_reference = const char&;
		using pointer = char*;
		using const_pointer = const char*;
		using iterator = char*;
		using const_iterator = const char*;
		using reverse_iterator = std::reverse_iterator<char*>;
		using const_reverse_iterator = std::reverse_iterator<const char*>;

		[[nodiscard]] explicit(false) constexpr string() noexcept = default;

		[[nodiscard]] explicit(false) constexpr string(const xte::string& other) noexcept(false)
		: _data(other._data) {}

		[[nodiscard]] explicit(false) constexpr string(xte::string&& other) noexcept
		: _data(xte::xvalue(other._data)) {}

		[[nodiscard]] constexpr string(xte::string_view view) noexcept(false)
		: xte::string(std::from_range, view) {}

		[[nodiscard]] explicit(false) constexpr string(xte::init_list<char> init_list) noexcept(false)
		: xte::string(std::from_range, xte::xvalue(init_list)) {}

		[[nodiscard]] constexpr string(std::from_range_t, auto&& range) XTE_ARROW_CTOR(
			((this->_data.size() && this->_data.back()) ? this->_data.push() : void()),
			_data,((std::from_range, XTE_FWD(range)))
		)

		template<std::input_iterator Iter>
		[[nodiscard]] constexpr string(Iter begin, std::sentinel_for<Iter> auto end) XTE_ARROW_CTOR(,
			(xte::string),((std::from_range, std::ranges::subrange(begin, end)))
		)

		[[nodiscard]] explicit constexpr string(xte::is_noex_implicit_castable<const char*> auto&& range) noexcept(false) {
			if (const char* data = range) do {
				this->_data.push(*data);
			} while (*data++);
		}

		[[nodiscard]] constexpr string(const char* data, xte::uz size) noexcept(false) {
			this->_data.reserve_total(size);
			while (size--) {
				this->_data.push(*data++);
			}
			if (!this->_data.size() || this->_data.back()) {
				this->_data.push();
				return;
			}
			while ((this->_data.size() > 1) && !this->_data.back(1)) {
				this->_data.pop();
			}
		}

		template<xte::uz size>
		[[nodiscard]] explicit(false) constexpr string(const xte::type<char[size]>& data) noexcept(false)
		: xte::string(data, size) {}

		[[nodiscard]] explicit(false) constexpr string(xte::uz size, char c = '\0') noexcept(false)
		: _data(size, c) {}

		constexpr xte::string& operator=(const xte::string& other) & noexcept(false) {
			this->_data = other._data;
			return *this;
		}

		constexpr xte::string& operator=(xte::string&& other) & noexcept {
			this->_data = xte::xvalue(other._data);
			return *this;
		}

		template<std::ranges::input_range Range>
		constexpr auto operator=(Range&& range) & noexcept(false)
		requires(!xte::is_derived_from<Range, xte::string> && requires (char x) { x = static_cast<char>(xte::like<Range>(*xte::lvalue(std::ranges::begin(range)))); }) {
			this->_data = XTE_FWD(range);
			if (!this->_data.size() || this->_data.back()) {
				this->_data.push();
			}
			return *this;
		}

		[[nodiscard]] constexpr auto* data(this auto&& self) noexcept {
			return self._data.data();
		}

		[[nodiscard]] constexpr xte::uz size() const noexcept {
			return this->_data.size() - !!this->_data.size();
		}

		[[nodiscard]] constexpr xte::uz capacity() const noexcept {
			return this->_data.capacity() - !!this->_data.capacity();
		}

		[[nodiscard]] constexpr auto* begin(this auto&& self) noexcept {
			return self.data();
		}

		[[nodiscard]] constexpr const char* cbegin() const noexcept {
			return this->begin();
		}

		[[nodiscard]] constexpr auto* end(this auto&& self) noexcept {
			return self.begin() + self.size();
		}

		[[nodiscard]] constexpr const char* cend() const noexcept {
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
			return XTE_FWD(self)._data.front(index);
		}
		
		[[nodiscard]] constexpr auto&& back(this auto&& self, xte::uz index = 0) noexcept {
			return XTE_FWD(self)._data.back(index + 1);
		}

		[[nodiscard]] constexpr auto&& operator[](this auto&& self, xte::uz index) noexcept {
			return XTE_FWD(self)._data[index];
		}

		[[nodiscard]] constexpr xte::string slice(xte::uz index, xte::uz size = -1uz) const noexcept(false) {
			return (index < this->size()) ? xte::string(this->begin() + index, this->begin() + index + xte::min(this->size() - index, size)) : "";
		}

		constexpr void reset() noexcept {
			this->_data.reset();
		}

		constexpr void resize(xte::uz size, char fill = '\0') & noexcept(false) {
			this->reserve_total(size + 1);
			while (this->size() < size) {
				this->push(fill);
			}
			this->erase(size, -1uz);
		}

		constexpr void reserve(xte::uz additional = 1) & noexcept(false) {
			this->_data.reserve(additional);
		}

		constexpr void reserve_total(xte::uz total) & noexcept(false) {
			this->_data.reserve_total(total + !!total);
		}

		constexpr void shrink() & noexcept(false) {
			this->_data.shrink();
		}

		constexpr void insert_uninit(xte::uz index, xte::uz count = 1) & noexcept(false) {
			bool was_empty = count && !this->_data.size();
			this->_data.insert_uninit(index, count + was_empty);
			if (was_empty) {
				this->_data.push();
			}
		}

		constexpr void insert(xte::uz index, char c = '\0') & noexcept(false) {
			this->_data.insert(xte::min(index, this->size()), c);
			if (this->_data.back()) {
				this->_data.push();
			}
		}

		template<std::ranges::input_range Range = xte::string>
		constexpr void insert_range(xte::uz index, Range&& range) noexcept(false)
		requires(xte::is_constructible<char, decltype(xte::like<Range>(*xte::lvalue(std::ranges::begin(range))))>) {
			this->_data.insert_range(xte::min(index, this->size()), XTE_FWD(range));
			if (!this->_data.size() || this->_data.back()) {
				this->_data.push();
			}
		}

		template<std::ranges::input_range Range = xte::string>
		constexpr void insert_string(xte::uz index, Range&& range) & noexcept(false)
		requires(xte::is_constructible<char, decltype(xte::like<Range>(*xte::lvalue(std::ranges::begin(range))))>) {
			index = xte::min(index, this->size());
			xte::uz old_size = this->size();
			this->insert_range(index, XTE_FWD(range));
			xte::uz range_size = this->size() - old_size;
			xte::uz i = range_size;
			while (i && !this->_data[index + i - 1]) {
				--i;
			}
			this->erase(index + i, range_size - i);
		}

		constexpr void erase(xte::uz index, xte::uz count = 1) & noexcept {
			if (index <= this->size()) {
				this->_data.erase(index, xte::min(count, this->size() - index));
			}
		}

		constexpr void push(char c = '\0') & noexcept(false) {
			this->insert(-1uz, c);
		}

		template<typename Range = xte::string>
		constexpr auto push_range(Range&& range) & XTE_ARROW(
			this->insert_range(-1uz, XTE_FWD(range))
		)

		template<typename Range = xte::string>
		constexpr auto push_string(Range&& range) & XTE_ARROW(
			this->insert_string(-1uz, XTE_FWD(range))
		)

		constexpr char pop() noexcept {
			char last = this->back();
			this->erase(this->size() - 1);
			return last;
		}

		[[nodiscard]] friend constexpr auto operator+(xte::is_derived_from<xte::string> auto&& lhs, auto&& rhs) XTE_ARROW(
			auto(lhs.xte::string::operator+=(XTE_FWD(rhs)))
		)

		[[nodiscard]] friend constexpr auto operator+(char lhs, xte::is_derived_from<xte::string> auto rhs) XTE_ARROW(
			rhs.xte::string::insert(0, lhs),
			auto(rhs)
		)

		template<typename Lhs>
		requires(!xte::is_derived_from<Lhs, xte::string>)
		[[nodiscard]] friend constexpr auto operator+(Lhs&& lhs, xte::is_derived_from<xte::string> auto rhs) XTE_ARROW(
			rhs.xte::string::insert_string(0, XTE_FWD(lhs)),
			auto(rhs)
		)

		constexpr xte::string& operator+=(this auto& lhs, char rhs) noexcept(false) {
			lhs.xte::string::push(rhs);
			return lhs;
		}

		constexpr auto operator+=(this auto& lhs, auto&& rhs) XTE_ARROW(
			void(lhs.xte::string::push_string(XTE_FWD(rhs))),
			lhs
		)
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
