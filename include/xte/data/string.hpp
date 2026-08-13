#ifndef DETAIL_XTE_HEADER_DATA_STRING
#	define DETAIL_XTE_HEADER_DATA_STRING
#
#	include "../data/array.hpp"
#	include "../data/string_view.hpp"
#	include "../math/min.hpp"
#	include "../meta/req_not.hpp"
#	include "../meta/type.hpp"
#	include "../preproc/constructs.hpp"
#	include "../preproc/fwd.hpp"
#	include "../preproc/returns.hpp"
#	include "../trait/is_castable_implicit_noex.hpp"
#	include "../trait/is_derived_from.hpp"
#	include "../trait/is_invocable.hpp"
#	include "../util/as_lvalue.hpp"
#	include "../util/as_xvalue.hpp"
#	include "../util/assign.hpp"
#	include "../util/init_list.hpp"
#	include "../util/like.hpp"
#	include "../util/number_types.hpp"
#	include <algorithm>
#	include <compare>
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
		using reference = char&;
		using const_reference = const char&;
		using pointer = char*;
		using const_pointer = const char*;
		using iterator = char*;
		using const_iterator = const char*;
		using reverse_iterator = std::reverse_iterator<char*>;
		using const_reverse_iterator = std::reverse_iterator<const char*>;
		using allocator_type = xte::array<char>::allocator_type;
		using size_type = xte::uz;
		using difference_type = xte::iptrdiff;

		[[nodiscard]] explicit(false) constexpr string() noexcept = default;

		[[nodiscard]] explicit(false) constexpr string(const xte::string& other) noexcept(false)
		: _data(other._data) {}

		[[nodiscard]] explicit(false) constexpr string(xte::string&& other) noexcept
		: _data(xte::as_xvalue(other._data)) {}

		[[nodiscard]] constexpr string(xte::string_view view) noexcept(false)
		: xte::string(std::from_range, view) {}

		[[nodiscard]] explicit(false) constexpr string(xte::init_list<char> init_list) noexcept(false)
		: xte::string(std::from_range, xte::as_xvalue(init_list)) {}

		[[nodiscard]] constexpr string(std::from_range_t, auto&& range) XTE_CONSTRUCTS(
			((this->_data.size() && this->_data.back()) ? this->_data.append() : void()),
			_data,((std::from_range, XTE_FWD(range)))
		)

		template<std::input_iterator iter_type>
		[[nodiscard]] constexpr string(iter_type begin, std::sentinel_for<iter_type> auto end) XTE_CONSTRUCTS(,
			(xte::string),((std::from_range, xte::as_lvalue(std::ranges::subrange(begin, end))))
		)

		[[nodiscard]] explicit(false) constexpr string(xte::is_castable_implicit_noex<const char*> auto&& range) noexcept(false) {
			if (const char* data = range) do {
				this->_data.append(*data);
			} while (*data++);
		}

		[[nodiscard]] constexpr string(const char* data, xte::uz size) noexcept(false) {
			this->_data.reserve_total(size);
			while (size--) {
				this->_data.append(*data++);
			}
			if (!this->_data.size() || this->_data.back()) {
				this->_data.append();
				return;
			}
			if ((this->_data.size() > 1) && !this->_data.back(1)) {
				this->_data.pop_back();
			}
		}

		template<xte::uz size>
		[[nodiscard]] explicit(false) constexpr string(xte::type<const char[size]>& data) noexcept(false)
		: xte::string(data, size) {}

		[[nodiscard]] explicit(false) constexpr string(xte::uz size, char c = '\0') noexcept(false)
		: _data(size, c) {
			this->_data.append();
		}

		constexpr xte::string& operator=(const xte::string& other) & noexcept(false) {
			this->_data = other._data;
			return *this;
		}

		constexpr xte::string& operator=(xte::string&& other) & noexcept {
			this->_data = xte::as_xvalue(other._data);
			return *this;
		}

		template<std::ranges::input_range range_type>
		constexpr auto operator=(range_type&& range) & noexcept(false)
		requires(!xte::is_derived_from<range_type, xte::string> && requires (char x) { xte::assign(x, xte::like<range_type>(*xte::as_lvalue(std::ranges::begin(range)))); }) {
			this->_data = XTE_FWD(range);
			if (!this->_data.size() || this->_data.back()) {
				this->_data.append();
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

		[[nodiscard]] constexpr xte::string_view subview(xte::uz index, xte::uz size = -1uz) const noexcept {
			return xte::string_view(*this).subview(index, size);
		}

		[[nodiscard]] constexpr xte::string substr(xte::uz index, xte::uz size = -1uz) const noexcept(false) {
			return (index < this->size()) ? xte::string(this->begin() + index, this->begin() + index + xte::min(this->size() - index, size)) : "";
		}

		[[nodiscard]] constexpr bool contains(xte::string_view substr) const noexcept {
			return xte::string_view(*this).contains(substr);
		}

		[[nodiscard]] constexpr bool contains(char c) const noexcept {
			return xte::string_view(*this).contains(c);
		}

		[[nodiscard]] constexpr xte::uz find(xte::string_view substr) const noexcept {
			return xte::string_view(*this).find(substr);
		}

		[[nodiscard]] constexpr xte::uz find(char c) const noexcept {
			return xte::string_view(*this).find(c);
		}

		[[nodiscard]] constexpr xte::uz find_last(xte::string_view substr) const noexcept {
			return xte::string_view(*this).find_last(substr);
		}

		[[nodiscard]] constexpr xte::uz find_last(char c) const noexcept {
			return xte::string_view(*this).find_last(c);
		}

		[[nodiscard]] constexpr xte::uz find_any_of(xte::string_view chars) const noexcept {
			return xte::string_view(*this).find_any_of(chars);
		}

		[[nodiscard]] constexpr xte::uz find_any_of(char c) const noexcept {
			return xte::string_view(*this).find_any_of(c);
		}

		[[nodiscard]] constexpr xte::uz find_last_of(xte::string_view chars) const noexcept {
			return xte::string_view(*this).find_last_of(chars);
		}

		[[nodiscard]] constexpr xte::uz find_last_of(char c) const noexcept {
			return xte::string_view(*this).find_last_of(c);
		}

		[[nodiscard]] constexpr xte::uz find_not_of(xte::string_view chars) const noexcept {
			return xte::string_view(*this).find_not_of(chars);
		}

		[[nodiscard]] constexpr xte::uz find_not_of(char c) const noexcept {
			return xte::string_view(*this).find_not_of(c);
		}

		[[nodiscard]] constexpr xte::uz find_last_not_of(xte::string_view chars) const noexcept {
			return xte::string_view(*this).find_last_not_of(chars);
		}

		[[nodiscard]] constexpr xte::uz find_last_not_of(char c) const noexcept {
			return xte::string_view(*this).find_last_not_of(c);
		}

		[[nodiscard]] constexpr xte::string_view after(xte::string_view substr) const noexcept {
			return xte::string_view(*this).after(substr);
		}

		[[nodiscard]] constexpr xte::string_view after(char c) const noexcept {
			return xte::string_view(*this).after(c);
		}

		[[nodiscard]] constexpr xte::string_view str_after(xte::string_view substr) const noexcept(false) {
			return xte::string(this->after(substr));
		}

		[[nodiscard]] constexpr xte::string_view str_after(char c) const noexcept(false) {
			return xte::string(this->after(c));
		}

		[[nodiscard]] constexpr xte::string_view after_last(xte::string_view substr) const noexcept {
			return xte::string_view(*this).after_last(substr);
		}

		[[nodiscard]] constexpr xte::string_view after_last(char c) const noexcept {
			return xte::string_view(*this).after_last(c);
		}

		[[nodiscard]] constexpr xte::string_view str_after_last(xte::string_view substr) const noexcept(false) {
			return xte::string(this->after_last(substr));
		}

		[[nodiscard]] constexpr xte::string_view str_after_last(char c) const noexcept(false) {
			return xte::string(this->after_last(c));
		}

		[[nodiscard]] constexpr xte::string_view after_any_of(xte::string_view chars) const noexcept {
			return xte::string_view(*this).after_any_of(chars);
		}

		[[nodiscard]] constexpr xte::string_view after_any_of(char c) const noexcept {
			return xte::string_view(*this).after_any_of(c);
		}

		[[nodiscard]] constexpr xte::string_view str_after_any_of(xte::string_view chars) const noexcept(false) {
			return xte::string(this->after_any_of(chars));
		}

		[[nodiscard]] constexpr xte::string_view str_after_any_of(char c) const noexcept(false) {
			return xte::string(this->after_any_of(c));
		}

		[[nodiscard]] constexpr xte::string_view before(xte::string_view substr) const noexcept {
			return xte::string_view(*this).before(substr);
		}

		[[nodiscard]] constexpr xte::string_view before(char c) const noexcept {
			return xte::string_view(*this).before(c);
		}

		[[nodiscard]] constexpr xte::string_view str_before(xte::string_view substr) const noexcept(false) {
			return xte::string(this->before(substr));
		}

		[[nodiscard]] constexpr xte::string_view str_before(char c) const noexcept(false) {
			return xte::string(this->before(c));
		}

		[[nodiscard]] constexpr xte::string_view before_last(xte::string_view substr) const noexcept {
			return xte::string_view(*this).before_last(substr);
		}

		[[nodiscard]] constexpr xte::string_view before_last(char c) const noexcept {
			return xte::string_view(*this).before_last(c);
		}

		[[nodiscard]] constexpr xte::string_view str_before_last(xte::string_view substr) const noexcept(false) {
			return xte::string(this->before_last(substr));
		}

		[[nodiscard]] constexpr xte::string_view str_before_last(char c) const noexcept(false) {
			return xte::string(this->before_last(c));
		}

		[[nodiscard]] constexpr xte::string_view before_any_of(xte::string_view chars) const noexcept {
			return xte::string_view(*this).before_any_of(chars);
		}

		[[nodiscard]] constexpr xte::string_view before_any_of(char c) const noexcept {
			return xte::string_view(*this).before_any_of(c);
		}

		[[nodiscard]] constexpr xte::string_view str_before_any_of(xte::string_view chars) const noexcept(false) {
			return xte::string(this->before_any_of(chars));
		}

		[[nodiscard]] constexpr xte::string_view str_before_any_of(char c) const noexcept(false) {
			return xte::string(this->before_any_of(c));
		}

		[[nodiscard]] constexpr xte::string_view between(xte::string_view start, xte::string_view end) const noexcept {
			return xte::string_view(*this).between(start, end);
		}

		[[nodiscard]] constexpr xte::string_view between(char start, xte::string_view end) const noexcept {
			return xte::string_view(*this).between(start, end);
		}

		[[nodiscard]] constexpr xte::string_view between(xte::string_view start, char end) const noexcept {
			return xte::string_view(*this).between(start, end);
		}

		[[nodiscard]] constexpr xte::string_view between(char start, char end) const noexcept {
			return xte::string_view(*this).between(start, end);
		}

		[[nodiscard]] constexpr xte::string_view str_between(xte::string_view start, xte::string_view end) const noexcept(false) {
			return xte::string(this->between(start, end));
		}

		[[nodiscard]] constexpr xte::string_view str_between(char start, xte::string_view end) const noexcept(false) {
			return xte::string(this->between(start, end));
		}

		[[nodiscard]] constexpr xte::string_view str_between(xte::string_view start, char end) const noexcept(false) {
			return xte::string(this->between(start, end));
		}

		[[nodiscard]] constexpr xte::string_view str_between(char start, char end) const noexcept(false) {
			return xte::string(this->between(start, end));
		}

		[[nodiscard]] constexpr xte::string_view between_first(xte::string_view start, xte::string_view end) const noexcept {
			return xte::string_view(*this).between_first(start, end);
		}

		[[nodiscard]] constexpr xte::string_view between_first(char start, xte::string_view end) const noexcept {
			return xte::string_view(*this).between_first(start, end);
		}

		[[nodiscard]] constexpr xte::string_view between_first(xte::string_view start, char end) const noexcept {
			return xte::string_view(*this).between_first(start, end);
		}

		[[nodiscard]] constexpr xte::string_view between_first(char start, char end) const noexcept {
			return xte::string_view(*this).between_first(start, end);
		}

		[[nodiscard]] constexpr xte::string_view str_between_first(xte::string_view start, xte::string_view end) const noexcept(false) {
			return xte::string(this->between_first(start, end));
		}

		[[nodiscard]] constexpr xte::string_view str_between_first(char start, xte::string_view end) const noexcept(false) {
			return xte::string(this->between_first(start, end));
		}

		[[nodiscard]] constexpr xte::string_view str_between_first(xte::string_view start, char end) const noexcept(false) {
			return xte::string(this->between_first(start, end));
		}

		[[nodiscard]] constexpr xte::string_view str_between_first(char start, char end) const noexcept(false) {
			return xte::string(this->between_first(start, end));
		}

		[[nodiscard]] constexpr xte::string_view between_last(xte::string_view start, xte::string_view end) const noexcept {
			return xte::string_view(*this).between_last(start, end);
		}

		[[nodiscard]] constexpr xte::string_view between_last(char start, xte::string_view end) const noexcept {
			return xte::string_view(*this).between_last(start, end);
		}

		[[nodiscard]] constexpr xte::string_view between_last(xte::string_view start, char end) const noexcept {
			return xte::string_view(*this).between_last(start, end);
		}

		[[nodiscard]] constexpr xte::string_view between_last(char start, char end) const noexcept {
			return xte::string_view(*this).between_last(start, end);
		}

		[[nodiscard]] constexpr xte::string_view str_between_last(xte::string_view start, xte::string_view end) const noexcept(false) {
			return xte::string(this->between_last(start, end));
		}

		[[nodiscard]] constexpr xte::string_view str_between_last(char start, xte::string_view end) const noexcept(false) {
			return xte::string(this->between_last(start, end));
		}

		[[nodiscard]] constexpr xte::string_view str_between_last(xte::string_view start, char end) const noexcept(false) {
			return xte::string(this->between_last(start, end));
		}

		[[nodiscard]] constexpr xte::string_view str_between_last(char start, char end) const noexcept(false) {
			return xte::string(this->between_last(start, end));
		}

		[[nodiscard]] constexpr xte::string_view between_any_of(xte::string_view start, xte::string_view end) const noexcept {
			return xte::string_view(*this).between_any_of(start, end);
		}

		[[nodiscard]] constexpr xte::string_view between_any_of(char start, xte::string_view end) const noexcept {
			return xte::string_view(*this).between_any_of(start, end);
		}

		[[nodiscard]] constexpr xte::string_view between_any_of(xte::string_view start, char end) const noexcept {
			return xte::string_view(*this).between_any_of(start, end);
		}

		[[nodiscard]] constexpr xte::string_view between_any_of(char start, char end) const noexcept {
			return xte::string_view(*this).between_any_of(start, end);
		}

		[[nodiscard]] constexpr xte::string_view str_between_any_of(xte::string_view start, xte::string_view end) const noexcept(false) {
			return xte::string(this->between_any_of(start, end));
		}

		[[nodiscard]] constexpr xte::string_view str_between_any_of(char start, xte::string_view end) const noexcept(false) {
			return xte::string(this->between_any_of(start, end));
		}

		[[nodiscard]] constexpr xte::string_view str_between_any_of(xte::string_view start, char end) const noexcept(false) {
			return xte::string(this->between_any_of(start, end));
		}

		[[nodiscard]] constexpr xte::string_view str_between_any_of(char start, char end) const noexcept(false) {
			return xte::string(this->between_any_of(start, end));
		}

		constexpr void reset() noexcept {
			this->_data.reset();
		}

		constexpr void resize(xte::uz size, char fill = '\0') & noexcept(false) {
			this->reserve_total(size + 1);
			while (this->size() < size) {
				this->append(fill);
			}
			this->erase(size, -1uz);
		}

		constexpr void reserve(xte::uz additional = 1) & noexcept(false) {
			this->_data.reserve(additional);
		}

		constexpr void reserve_total(xte::uz total) & noexcept(false) {
			this->_data.reserve_total(total + !!total);
		}

		constexpr void reserve_and_init(xte::uz additional, xte::is_invocable<xte::uz(char*, xte::uz)> auto&& op) & noexcept(false) {
			this->_data.reserve_and_init(additional, XTE_FWD(op));
			if (this->_data.size() && this->_data.back()) {
				this->_data.append();
			}
		}

		constexpr void shrink_to_fit() & noexcept(false) {
			this->_data.shrink_to_fit();
		}

		constexpr void insert(xte::uz index, char c = '\0') & noexcept(false) {
			this->_data.insert(xte::min(index, this->size()), c);
			if (this->_data.back()) {
				this->_data.append();
			}
		}

		template<std::ranges::input_range range_type = xte::string>
		constexpr void insert_range(xte::uz index, range_type&& range) noexcept(false)
		requires(xte::is_constructible<char, decltype(xte::like<range_type>(*xte::as_lvalue(std::ranges::begin(range))))>) {
			this->_data.insert_range(xte::min(index, this->size()), XTE_FWD(range));
			if (!this->_data.size() || this->_data.back()) {
				this->_data.append();
			}
		}

		template<std::ranges::input_range range_type = xte::string>
		constexpr void insert_string(xte::uz index, range_type&& range) & noexcept(false)
		requires(xte::is_constructible<char, decltype(xte::like<range_type>(*xte::as_lvalue(std::ranges::begin(range))))>) {
			index = xte::min(index, this->size());
			xte::uz old_size = this->size();
			this->insert_range(index, XTE_FWD(range));
			xte::uz range_size = this->size() - old_size;
			if (range_size && !this->_data[index + range_size - 1]) {
				this->erase(index + range_size - 1);
			}
		}

		constexpr void insert_fill(xte::uz index, xte::uz count, char c) & noexcept(false) {
			this->_data.insert_fill(xte::min(index, this->size()), count, c);
		}

		constexpr void erase(xte::uz index, xte::uz count = 1) & noexcept {
			if (index <= this->size()) {
				this->_data.erase(index, xte::min(count, this->size() - index));
			}
		}

		constexpr void append(char c = '\0') & noexcept(false) {
			this->insert(-1uz, c);
		}

		template<typename range_type = xte::string>
		constexpr auto append_range(range_type&& range) & XTE_RETURNS(
			this->insert_range(-1uz, XTE_FWD(range))
		)

		template<typename range_type = xte::string>
		constexpr auto append_string(range_type&& range) & XTE_RETURNS(
			this->insert_string(-1uz, XTE_FWD(range))
		)

		constexpr char pop_back() noexcept {
			char last = this->back();
			this->erase(this->size() - 1);
			return last;
		}

		[[nodiscard]] friend constexpr auto operator+(xte::string lhs, auto&& rhs) XTE_RETURNS(
			auto(xte::as_xvalue(lhs += XTE_FWD(rhs)))
		)

		[[nodiscard]] friend constexpr xte::string operator+(char lhs, xte::string rhs) noexcept(false) {
			rhs.insert(0, lhs);
			return xte::as_xvalue(rhs);
		}

		[[nodiscard]] friend constexpr auto operator+(xte::req_not<[]<xte::is_derived_from<xte::string>>{}> auto&& lhs, xte::string rhs) XTE_RETURNS(
			rhs.insert_string(0, XTE_FWD(lhs)),
			auto(xte::as_xvalue(rhs))
		)

		constexpr xte::string& operator+=(char rhs) noexcept(false) {
			this->append(rhs);
			return *this;
		}

		constexpr auto operator+=(auto&& rhs) XTE_RETURNS(
			this->append_string(XTE_FWD(rhs)),
			*this
		)

		constexpr void replace(xte::string_view current, xte::string_view with) noexcept(false) {
			xte::string result;
			xte::uz start = 0;
			while (true) {
				auto rest = this->subview(start);
				xte::uz next = rest.find(current);
				result += rest.subview(0, next);
				if (!~next) {
					break;
				}
				result += with;
				start += next + current.size();
			}
			*this = xte::as_xvalue(result);
		}

		[[nodiscard]] constexpr xte::string quoted(this auto quoted, char delim = '"', char escape = '\\') noexcept(false) {
			if (delim != escape) {
				quoted.replace(escape, xte::string { escape, escape });
			}
			quoted.replace(delim, xte::string { escape, delim });
			return delim + xte::as_xvalue(quoted) + delim;
		}

		[[nodiscard]] constexpr xte::string unquoted(this auto unquoted, char delim = '"', char escape = '\\') noexcept(false) {
			if ((unquoted.size() > 1) && (unquoted.front() == delim) && (unquoted.back() == delim)) {
				unquoted = unquoted.subview(1, unquoted.size() - 2);
			}
			if (delim != escape) {
				unquoted.replace(xte::string { escape, escape }, escape);
			}
			unquoted.replace(xte::string { escape, delim }, delim);
			return unquoted;
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
