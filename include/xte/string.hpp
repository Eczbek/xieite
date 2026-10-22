#ifndef DETAIL_XTE_HEADER_STRING
#	define DETAIL_XTE_HEADER_STRING
#
#	include "./aliases.hpp"
#	include "./array.hpp"
#	include "./class_traits.hpp"
#	include "./compare.hpp"
#	include "./fundamental_traits.hpp"
#	include "./in_place.hpp"
#	include "./init_list.hpp"
#	include "./macros.hpp"
#	include "./meta/req.hpp"
#	include "./meta/type.hpp"
#	include "./qual_traits.hpp"
#	include "./string_view.hpp"
#	include <compare>
#	include <format>
#	include <iterator>
#	include <memory>
#	include <ranges>
#	include <string_view>

namespace xte {
	template<xte::is_char char_type, typename allocator_type = std::allocator<char_type>> // TODO: constrain allocator_type
	struct string_base : xte::contiguous_container_aliases<char_type>, xte::dynamic_container_aliases<allocator_type> {
	private:
		xte::array<char_type, allocator_type> _data;

	public:
		[[nodiscard]] constexpr explicit(false) string_base() noexcept = default;

		[[nodiscard]] constexpr explicit(false) string_base(xte::string_base<char_type, allocator_type> const& other) noexcept(false)
			: _data(other._data)
		{}

		[[nodiscard]] constexpr explicit(false) string_base(xte::string_base<char_type, allocator_type>&& other) noexcept
			: _data(xte::as_xvalue(other._data))
		{}

		[[nodiscard]] constexpr string_base(xte::string_view_base<char_type> view) noexcept(false)
			: xte::string_base<char_type, allocator_type>(std::from_range, view)
		{}

		[[nodiscard]] constexpr explicit(false) string_base(xte::init_list<char_type> init_list) noexcept(false)
			: xte::string_base<char_type, allocator_type>(std::from_range, xte::as_xvalue(init_list))
		{}

		[[nodiscard]] constexpr string_base(std::from_range_t, auto&& range) XTE_CONSTRUCTS(
			(_data, (std::from_range, XTE_FWD(range))),
			(this->_data.size() && this->_data.back()) ? this->_data.append() : void()
		)

		template<std::input_iterator iter_type>
		[[nodiscard]] constexpr string_base(iter_type begin, std::sentinel_for<iter_type> auto end) XTE_CONSTRUCTS(
			((xte::string_base<char_type, allocator_type>), (std::from_range, xte::as_lvalue(std::ranges::subrange(begin, end))))
		)

		[[nodiscard]] constexpr explicit(false) string_base(xte::is_implicitly_convertible_noex<char_type const*> auto&& range) noexcept(false) {
			if (char_type const* data = range) do {
				this->_data.append(*data);
			} while (*data++);
		}

		[[nodiscard]] constexpr string_base(char_type const* data, xte::uz size) noexcept(false) {
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
		[[nodiscard]] constexpr explicit(false) string_base(xte::type<char_type[size]> const& data) noexcept(false)
			: xte::string_base<char_type, allocator_type>(data, size)
		{}

		[[nodiscard]] constexpr explicit(false) string_base(xte::uz size, char_type fill = '\0') noexcept(false)
			: _data(size, fill)
		{
			this->_data.append();
		}

		constexpr xte::string_base<char_type, allocator_type>& operator=(xte::string_base<char_type, allocator_type> const& other) & noexcept(false) {
			this->_data = other._data;
			return *this;
		}

		constexpr xte::string_base<char_type, allocator_type>& operator=(xte::string_base<char_type, allocator_type>&& other) & noexcept {
			this->_data = xte::as_xvalue(other._data);
			return *this;
		}

		template<std::ranges::input_range range_type>
		constexpr auto operator=(range_type&& range) & noexcept(false)
			requires (!xte::is_derived_from<range_type, xte::string_base<char_type, allocator_type>>
				&& requires { static_cast<char_type>(xte::like<range_type>(*xte::as_lvalue(std::ranges::begin(range)))); })
		{
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

		template<xte::uz rhs_size>
		[[nodiscard]] friend constexpr std::strong_ordering operator<=>(xte::string_base<char_type, allocator_type> lhs, xte::type<char_type[rhs_size]> const& rhs) noexcept {
			return lhs <=> xte::string_view_base<char_type>(rhs);
		}

		template<xte::uz rhs_size>
		[[nodiscard]] friend constexpr bool operator==(xte::string_base<char_type, allocator_type> lhs, xte::type<char_type[rhs_size]> const& rhs) noexcept {
			return lhs == xte::string_view_base<char_type>(rhs);
		}

		[[nodiscard]] constexpr char_type const* c_str() const noexcept {
			return this->_data.data();
		}

		[[nodiscard]] constexpr auto* begin(this auto&& self) noexcept {
			return self.data();
		}

		[[nodiscard]] constexpr char_type const* cbegin() const noexcept {
			return this->begin();
		}

		[[nodiscard]] constexpr auto* end(this auto&& self) noexcept {
			return self.begin() + self.size();
		}

		[[nodiscard]] constexpr char_type const* cend() const noexcept {
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

		[[nodiscard]] constexpr xte::string_view_base<char_type> subview(xte::uz index, xte::uz size = -1uz) const noexcept {
			return xte::string_view_base<char_type>(*this).subview(index, size);
		}

		[[nodiscard]] constexpr xte::string_base<char_type, allocator_type> substr(xte::uz index, xte::uz size = -1uz) const noexcept(false) {
			return (index < this->size()) ? xte::string_base<char_type, allocator_type>(this->begin() + index, this->begin() + index + xte::min(this->size() - index, size)) : "";
		}

		[[nodiscard]] constexpr bool contains(xte::string_view_base<char_type> pattern) const noexcept {
			return xte::string_view_base<char_type>(*this).contains(pattern);
		}

		[[nodiscard]] constexpr bool contains(char_type c) const noexcept {
			return xte::string_view_base<char_type>(*this).contains(c);
		}

		[[nodiscard]] constexpr xte::uz find(xte::string_view_base<char_type> pattern) const noexcept {
			return xte::string_view_base<char_type>(*this).find(pattern);
		}

		[[nodiscard]] constexpr xte::uz find(char_type c) const noexcept {
			return xte::string_view_base<char_type>(*this).find(c);
		}

		[[nodiscard]] constexpr xte::uz find_last(xte::string_view_base<char_type> pattern) const noexcept {
			return xte::string_view_base<char_type>(*this).find_last(pattern);
		}

		[[nodiscard]] constexpr xte::uz find_last(char_type c) const noexcept {
			return xte::string_view_base<char_type>(*this).find_last(c);
		}

		[[nodiscard]] constexpr xte::uz find_any_of(xte::string_view_base<char_type> chars) const noexcept {
			return xte::string_view_base<char_type>(*this).find_any_of(chars);
		}

		[[nodiscard]] constexpr xte::uz find_any_of(char_type c) const noexcept {
			return xte::string_view_base<char_type>(*this).find_any_of(c);
		}

		[[nodiscard]] constexpr xte::uz find_last_of(xte::string_view_base<char_type> chars) const noexcept {
			return xte::string_view_base<char_type>(*this).find_last_of(chars);
		}

		[[nodiscard]] constexpr xte::uz find_last_of(char_type c) const noexcept {
			return xte::string_view_base<char_type>(*this).find_last_of(c);
		}

		[[nodiscard]] constexpr xte::uz find_not_of(xte::string_view_base<char_type> chars) const noexcept {
			return xte::string_view_base<char_type>(*this).find_not_of(chars);
		}

		[[nodiscard]] constexpr xte::uz find_not_of(char_type c) const noexcept {
			return xte::string_view_base<char_type>(*this).find_not_of(c);
		}

		[[nodiscard]] constexpr xte::uz find_last_not_of(xte::string_view_base<char_type> chars) const noexcept {
			return xte::string_view_base<char_type>(*this).find_last_not_of(chars);
		}

		[[nodiscard]] constexpr xte::uz find_last_not_of(char_type c) const noexcept {
			return xte::string_view_base<char_type>(*this).find_last_not_of(c);
		}

		[[nodiscard]] constexpr xte::string_view_base<char_type> after(xte::string_view_base<char_type> pattern) const noexcept {
			return xte::string_view_base<char_type>(*this).after(pattern);
		}

		[[nodiscard]] constexpr xte::string_view_base<char_type> after(char_type c) const noexcept {
			return xte::string_view_base<char_type>(*this).after(c);
		}

		[[nodiscard]] constexpr xte::string_base<char_type, allocator_type> str_after(xte::string_view_base<char_type> pattern) const noexcept(false) {
			return xte::string_base<char_type, allocator_type>(this->after(pattern));
		}

		[[nodiscard]] constexpr xte::string_base<char_type, allocator_type> str_after(char_type c) const noexcept(false) {
			return xte::string_base<char_type, allocator_type>(this->after(c));
		}

		[[nodiscard]] constexpr xte::string_view_base<char_type> after_last(xte::string_view_base<char_type> pattern) const noexcept {
			return xte::string_view_base<char_type>(*this).after_last(pattern);
		}

		[[nodiscard]] constexpr xte::string_view_base<char_type> after_last(char_type c) const noexcept {
			return xte::string_view_base<char_type>(*this).after_last(c);
		}

		[[nodiscard]] constexpr xte::string_base<char_type, allocator_type> str_after_last(xte::string_view_base<char_type> pattern) const noexcept(false) {
			return xte::string_base<char_type, allocator_type>(this->after_last(pattern));
		}

		[[nodiscard]] constexpr xte::string_base<char_type, allocator_type> str_after_last(char_type c) const noexcept(false) {
			return xte::string_base<char_type, allocator_type>(this->after_last(c));
		}

		[[nodiscard]] constexpr xte::string_view_base<char_type> after_any_of(xte::string_view_base<char_type> chars) const noexcept {
			return xte::string_view_base<char_type>(*this).after_any_of(chars);
		}

		[[nodiscard]] constexpr xte::string_view_base<char_type> after_any_of(char_type c) const noexcept {
			return xte::string_view_base<char_type>(*this).after_any_of(c);
		}

		[[nodiscard]] constexpr xte::string_base<char_type, allocator_type> str_after_any_of(xte::string_view_base<char_type> chars) const noexcept(false) {
			return xte::string_base<char_type, allocator_type>(this->after_any_of(chars));
		}

		[[nodiscard]] constexpr xte::string_base<char_type, allocator_type> str_after_any_of(char_type c) const noexcept(false) {
			return xte::string_base<char_type, allocator_type>(this->after_any_of(c));
		}

		[[nodiscard]] constexpr xte::string_view_base<char_type> before(xte::string_view_base<char_type> pattern) const noexcept {
			return xte::string_view_base<char_type>(*this).before(pattern);
		}

		[[nodiscard]] constexpr xte::string_view_base<char_type> before(char_type c) const noexcept {
			return xte::string_view_base<char_type>(*this).before(c);
		}

		[[nodiscard]] constexpr xte::string_base<char_type, allocator_type> str_before(xte::string_view_base<char_type> pattern) const noexcept(false) {
			return xte::string_base<char_type, allocator_type>(this->before(pattern));
		}

		[[nodiscard]] constexpr xte::string_base<char_type, allocator_type> str_before(char_type c) const noexcept(false) {
			return xte::string_base<char_type, allocator_type>(this->before(c));
		}

		[[nodiscard]] constexpr xte::string_view_base<char_type> before_last(xte::string_view_base<char_type> pattern) const noexcept {
			return xte::string_view_base<char_type>(*this).before_last(pattern);
		}

		[[nodiscard]] constexpr xte::string_view_base<char_type> before_last(char_type c) const noexcept {
			return xte::string_view_base<char_type>(*this).before_last(c);
		}

		[[nodiscard]] constexpr xte::string_base<char_type, allocator_type> str_before_last(xte::string_view_base<char_type> pattern) const noexcept(false) {
			return xte::string_base<char_type, allocator_type>(this->before_last(pattern));
		}

		[[nodiscard]] constexpr xte::string_base<char_type, allocator_type> str_before_last(char_type c) const noexcept(false) {
			return xte::string_base<char_type, allocator_type>(this->before_last(c));
		}

		[[nodiscard]] constexpr xte::string_view_base<char_type> before_any_of(xte::string_view_base<char_type> chars) const noexcept {
			return xte::string_view_base<char_type>(*this).before_any_of(chars);
		}

		[[nodiscard]] constexpr xte::string_view_base<char_type> before_any_of(char_type c) const noexcept {
			return xte::string_view_base<char_type>(*this).before_any_of(c);
		}

		[[nodiscard]] constexpr xte::string_base<char_type, allocator_type> str_before_any_of(xte::string_view_base<char_type> chars) const noexcept(false) {
			return xte::string_base<char_type, allocator_type>(this->before_any_of(chars));
		}

		[[nodiscard]] constexpr xte::string_base<char_type, allocator_type> str_before_any_of(char_type c) const noexcept(false) {
			return xte::string_base<char_type, allocator_type>(this->before_any_of(c));
		}

		[[nodiscard]] constexpr xte::string_view_base<char_type> between(xte::string_view_base<char_type> start, xte::string_view_base<char_type> end) const noexcept {
			return xte::string_view_base<char_type>(*this).between(start, end);
		}

		[[nodiscard]] constexpr xte::string_view_base<char_type> between(char_type start, xte::string_view_base<char_type> end) const noexcept {
			return xte::string_view_base<char_type>(*this).between(start, end);
		}

		[[nodiscard]] constexpr xte::string_view_base<char_type> between(xte::string_view_base<char_type> start, char_type end) const noexcept {
			return xte::string_view_base<char_type>(*this).between(start, end);
		}

		[[nodiscard]] constexpr xte::string_view_base<char_type> between(char_type start, char_type end) const noexcept {
			return xte::string_view_base<char_type>(*this).between(start, end);
		}

		[[nodiscard]] constexpr xte::string_base<char_type, allocator_type> str_between(xte::string_view_base<char_type> start, xte::string_view_base<char_type> end) const noexcept(false) {
			return xte::string_base<char_type, allocator_type>(this->between(start, end));
		}

		[[nodiscard]] constexpr xte::string_base<char_type, allocator_type> str_between(char_type start, xte::string_view_base<char_type> end) const noexcept(false) {
			return xte::string_base<char_type, allocator_type>(this->between(start, end));
		}

		[[nodiscard]] constexpr xte::string_base<char_type, allocator_type> str_between(xte::string_view_base<char_type> start, char_type end) const noexcept(false) {
			return xte::string_base<char_type, allocator_type>(this->between(start, end));
		}

		[[nodiscard]] constexpr xte::string_base<char_type, allocator_type> str_between(char_type start, char_type end) const noexcept(false) {
			return xte::string_base<char_type, allocator_type>(this->between(start, end));
		}

		[[nodiscard]] constexpr xte::string_view_base<char_type> between_first(xte::string_view_base<char_type> start, xte::string_view_base<char_type> end) const noexcept {
			return xte::string_view_base<char_type>(*this).between_first(start, end);
		}

		[[nodiscard]] constexpr xte::string_view_base<char_type> between_first(char_type start, xte::string_view_base<char_type> end) const noexcept {
			return xte::string_view_base<char_type>(*this).between_first(start, end);
		}

		[[nodiscard]] constexpr xte::string_view_base<char_type> between_first(xte::string_view_base<char_type> start, char_type end) const noexcept {
			return xte::string_view_base<char_type>(*this).between_first(start, end);
		}

		[[nodiscard]] constexpr xte::string_view_base<char_type> between_first(char_type start, char_type end) const noexcept {
			return xte::string_view_base<char_type>(*this).between_first(start, end);
		}

		[[nodiscard]] constexpr xte::string_base<char_type, allocator_type> str_between_first(xte::string_view_base<char_type> start, xte::string_view_base<char_type> end) const noexcept(false) {
			return xte::string_base<char_type, allocator_type>(this->between_first(start, end));
		}

		[[nodiscard]] constexpr xte::string_base<char_type, allocator_type> str_between_first(char_type start, xte::string_view_base<char_type> end) const noexcept(false) {
			return xte::string_base<char_type, allocator_type>(this->between_first(start, end));
		}

		[[nodiscard]] constexpr xte::string_base<char_type, allocator_type> str_between_first(xte::string_view_base<char_type> start, char_type end) const noexcept(false) {
			return xte::string_base<char_type, allocator_type>(this->between_first(start, end));
		}

		[[nodiscard]] constexpr xte::string_base<char_type, allocator_type> str_between_first(char_type start, char_type end) const noexcept(false) {
			return xte::string_base<char_type, allocator_type>(this->between_first(start, end));
		}

		[[nodiscard]] constexpr xte::string_view_base<char_type> between_last(xte::string_view_base<char_type> start, xte::string_view_base<char_type> end) const noexcept {
			return xte::string_view_base<char_type>(*this).between_last(start, end);
		}

		[[nodiscard]] constexpr xte::string_view_base<char_type> between_last(char_type start, xte::string_view_base<char_type> end) const noexcept {
			return xte::string_view_base<char_type>(*this).between_last(start, end);
		}

		[[nodiscard]] constexpr xte::string_view_base<char_type> between_last(xte::string_view_base<char_type> start, char_type end) const noexcept {
			return xte::string_view_base<char_type>(*this).between_last(start, end);
		}

		[[nodiscard]] constexpr xte::string_view_base<char_type> between_last(char_type start, char_type end) const noexcept {
			return xte::string_view_base<char_type>(*this).between_last(start, end);
		}

		[[nodiscard]] constexpr xte::string_base<char_type, allocator_type> str_between_last(xte::string_view_base<char_type> start, xte::string_view_base<char_type> end) const noexcept(false) {
			return xte::string_base<char_type, allocator_type>(this->between_last(start, end));
		}

		[[nodiscard]] constexpr xte::string_base<char_type, allocator_type> str_between_last(char_type start, xte::string_view_base<char_type> end) const noexcept(false) {
			return xte::string_base<char_type, allocator_type>(this->between_last(start, end));
		}

		[[nodiscard]] constexpr xte::string_base<char_type, allocator_type> str_between_last(xte::string_view_base<char_type> start, char_type end) const noexcept(false) {
			return xte::string_base<char_type, allocator_type>(this->between_last(start, end));
		}

		[[nodiscard]] constexpr xte::string_base<char_type, allocator_type> str_between_last(char_type start, char_type end) const noexcept(false) {
			return xte::string_base<char_type, allocator_type>(this->between_last(start, end));
		}

		[[nodiscard]] constexpr xte::string_view_base<char_type> between_any_of(xte::string_view_base<char_type> start, xte::string_view_base<char_type> end) const noexcept {
			return xte::string_view_base<char_type>(*this).between_any_of(start, end);
		}

		[[nodiscard]] constexpr xte::string_view_base<char_type> between_any_of(char_type start, xte::string_view_base<char_type> end) const noexcept {
			return xte::string_view_base<char_type>(*this).between_any_of(start, end);
		}

		[[nodiscard]] constexpr xte::string_view_base<char_type> between_any_of(xte::string_view_base<char_type> start, char_type end) const noexcept {
			return xte::string_view_base<char_type>(*this).between_any_of(start, end);
		}

		[[nodiscard]] constexpr xte::string_view_base<char_type> between_any_of(char_type start, char_type end) const noexcept {
			return xte::string_view_base<char_type>(*this).between_any_of(start, end);
		}

		[[nodiscard]] constexpr xte::string_base<char_type, allocator_type> str_between_any_of(xte::string_view_base<char_type> start, xte::string_view_base<char_type> end) const noexcept(false) {
			return xte::string_base<char_type, allocator_type>(this->between_any_of(start, end));
		}

		[[nodiscard]] constexpr xte::string_base<char_type, allocator_type> str_between_any_of(char_type start, xte::string_view_base<char_type> end) const noexcept(false) {
			return xte::string_base<char_type, allocator_type>(this->between_any_of(start, end));
		}

		[[nodiscard]] constexpr xte::string_base<char_type, allocator_type> str_between_any_of(xte::string_view_base<char_type> start, char_type end) const noexcept(false) {
			return xte::string_base<char_type, allocator_type>(this->between_any_of(start, end));
		}

		[[nodiscard]] constexpr xte::string_base<char_type, allocator_type> str_between_any_of(char_type start, char_type end) const noexcept(false) {
			return xte::string_base<char_type, allocator_type>(this->between_any_of(start, end));
		}

		constexpr void reset() noexcept {
			this->_data.reset();
		}

		constexpr void resize(xte::uz size, char_type fill = '\0') & noexcept(false) {
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

		constexpr void reserve_and_init(xte::uz additional, xte::is_invocable<xte::uz(char_type*, xte::uz)> auto&& op) & noexcept(false) {
			this->_data.reserve_and_init(additional, XTE_FWD(op));
			if (this->_data.size() && this->_data.back()) {
				this->_data.append();
			}
		}

		constexpr void shrink_to_fit() & noexcept(false) {
			this->_data.shrink_to_fit();
		}

		constexpr void insert(xte::uz index, char_type c = '\0') & noexcept(false) {
			this->_data.insert(xte::min(index, this->size()), c);
			if (this->_data.back()) {
				this->_data.append();
			}
		}

		template<std::ranges::input_range range_type = xte::string_view_base<char_type>>
		constexpr void insert_range(xte::uz index, range_type&& range) noexcept(false)
			requires xte::is_constructible<char_type, decltype(xte::like<range_type>(*xte::as_lvalue(std::ranges::begin(range))))>
		{
			this->_data.insert_range(xte::min(index, this->size()), XTE_FWD(range));
			if (!this->_data.size() || this->_data.back()) {
				this->_data.append();
			}
		}

		template<std::ranges::input_range range_type = xte::string_view_base<char_type>>
		constexpr void insert_string(xte::uz index, range_type&& range) & noexcept(false)
			requires xte::is_constructible<char_type, decltype(xte::like<range_type>(*xte::as_lvalue(std::ranges::begin(range))))>
		{
			index = xte::min(index, this->size());
			xte::uz old_size = this->size();
			this->insert_range(index, XTE_FWD(range));
			xte::uz range_size = this->size() - old_size;
			if (range_size && !this->_data[index + range_size - 1]) {
				this->erase(index + range_size - 1);
			}
		}

		constexpr void insert_fill(xte::uz index, xte::uz count, char_type fill) & noexcept(false) {
			this->_data.insert_fill(xte::min(index, this->size()), count, fill);
		}

		constexpr void erase(xte::uz index, xte::uz count = 1) & noexcept {
			if (index <= this->size()) {
				this->_data.erase(index, xte::min(count, this->size() - index));
			}
		}

		constexpr void append(char_type c = '\0') & noexcept(false) {
			this->insert(-1uz, c);
		}

		template<typename range_type = xte::string_view_base<char_type>>
		constexpr auto append_range(range_type&& range) & XTE_RETURNS(
			this->insert_range(-1uz, XTE_FWD(range))
		)

		template<typename range_type = xte::string_view_base<char_type>>
		constexpr auto append_string(range_type&& range) & XTE_RETURNS(
			this->insert_string(-1uz, XTE_FWD(range))
		)

		constexpr char_type pop_back() noexcept {
			char_type last = this->back();
			this->erase(this->size() - 1);
			return last;
		}

		[[nodiscard]] friend constexpr auto operator+(xte::string_base<char_type, allocator_type> lhs, auto&& rhs) XTE_RETURNS(
			auto(xte::as_xvalue(lhs += XTE_FWD(rhs)))
		)

		[[nodiscard]] friend constexpr xte::string_base<char_type, allocator_type> operator+(char_type lhs, xte::string_base<char_type, allocator_type> rhs) noexcept(false) {
			rhs.insert(0, lhs);
			return xte::as_xvalue(rhs);
		}

		[[nodiscard]] friend constexpr auto operator+(xte::req_not<[]<xte::is_derived_from<xte::string_base<char_type, allocator_type>>>{}> auto&& lhs, xte::string_base<char_type, allocator_type> rhs) XTE_RETURNS(
			rhs.insert_string(0, XTE_FWD(lhs)),
			auto(xte::as_xvalue(rhs))
		)

		constexpr xte::string_base<char_type, allocator_type>& operator+=(char_type rhs) noexcept(false) {
			this->append(rhs);
			return *this;
		}

		constexpr auto operator+=(auto&& rhs) XTE_RETURNS(
			this->append_string(XTE_FWD(rhs)),
			*this
		)

		constexpr void replace(xte::string_view_base<char_type> current, xte::string_view_base<char_type> with) noexcept(false) {
			xte::string_base<char_type, allocator_type> result;
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

		[[nodiscard]] constexpr xte::string_base<char_type, allocator_type> quoted(this auto quoted, char_type delim = '"', char_type escape = '\\') noexcept(false) {
			if (delim != escape) {
				quoted.replace(escape, typename[:^^char_type[]:] { escape, escape });
			}
			quoted.replace(delim, typename[:^^char_type[]:] { escape, delim });
			return delim + xte::as_xvalue(quoted) + delim;
		}

		[[nodiscard]] constexpr xte::string_base<char_type, allocator_type> unquoted(this auto unquoted, char_type delim = '"', char_type escape = '\\') noexcept(false) {
			if ((unquoted.size() > 1) && (unquoted.front() == delim) && (unquoted.back() == delim)) {
				unquoted = unquoted.subview(1, unquoted.size() - 2);
			}
			if (delim != escape) {
				unquoted.replace(typename[:^^char_type[]:] { escape, escape }, escape);
			}
			unquoted.replace(typename[:^^char_type[]:] { escape, delim }, delim);
			return unquoted;
		}
	};

	using string = xte::string_base<char>;
}

namespace xte::literal::string {
	[[nodiscard]] constexpr xte::string operator""_str(char const* data, xte::uz size) noexcept(false) {
		return xte::string(data, size);
	}
}

template<typename allocator_type>
struct std::formatter<xte::string_base<char, allocator_type>> : std::formatter<std::string_view> {
	[[nodiscard]] constexpr auto parse(std::format_parse_context& ctx) noexcept {
		return std::formatter<std::string_view>::parse(ctx);
	}

	[[nodiscard]] auto format(xte::string_base<char, allocator_type> const& string, std::format_context& ctx) const noexcept(false) {
		return std::formatter<std::string_view>::format(std::string_view(string), ctx);
	}
};

#endif
