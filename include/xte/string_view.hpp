#ifndef DETAIL_XTE_HEADER_STRING_VIEW
#	define DETAIL_XTE_HEADER_STRING_VIEW
#
#	include "./aliases.hpp"
#	include "./class_traits.hpp"
#	include "./fundamental_traits.hpp"
#	include "./limits.hpp"
#	include "./macros.hpp"
#	include "./math/clamp.hpp"
#	include "./meta/type.hpp"
#	include "./ptr.hpp"
#	include "./range_compare.hpp"
#	include <compare>
#	include <format>
#	include <iterator>
#	include <meta>
#	include <ranges>
#	include <string_view>
#	include <type_traits>

namespace xte {
	template<xte::is_char char_type>
	struct string_view_base : std::ranges::view_base, xte::contiguous_container_aliases<char_type> {

		char_type const* _data = nullptr;
		xte::uz _size = 0;

		[[nodiscard]] constexpr explicit(false) string_view_base() noexcept = default;

		template<xte::uz size>
		[[nodiscard]] constexpr explicit(false) string_view_base(xte::type<char_type[size]> const& data) noexcept
			: xte::string_view_base<char_type>(data, size)
		{}

		[[nodiscard]] constexpr explicit(false) string_view_base(char_type const& c) noexcept
			: xte::string_view_base<char_type>(&c, 1)
		{}

		[[nodiscard]] constexpr explicit string_view_base(const xte::is_implicitly_convertible_noex<char_type const*> auto& range) noexcept
			: _data(range)
		{
			if (char_type const* copy = this->_data) {
				while (*copy++) {
					++this->_size;
				}
			}
		}

		[[nodiscard]] constexpr string_view_base(char_type const* data, xte::uz size) noexcept
			: _data(data)
			, _size(size)
		{
			if (this->_size && !this->back()) {
				--this->_size;
			}
		}

		template<std::ranges::contiguous_range range_type>
			requires xte::is_same<std::ranges::range_value_t<range_type>, char_type>
		[[nodiscard]] constexpr string_view_base(std::from_range_t, range_type const& range) XTE_CONSTRUCTS(
			((xte::string_view_base<char_type>), (std::ranges::data(range), std::ranges::size(range)))
		)

		[[nodiscard]] constexpr explicit(false) string_view_base(auto const& range) XTE_CONSTRUCTS(
			((xte::string_view_base<char_type>), (std::from_range, range))
		)

		template<std::input_iterator iter_type>
		[[nodiscard]] constexpr string_view_base(iter_type begin, std::sentinel_for<iter_type> auto end) XTE_CONSTRUCTS(
			((xte::string_view_base<char_type>), (std::ranges::subrange(begin, end)))
		)

		[[nodiscard]] constexpr char_type const* data() const noexcept {
			return this->_data;
		}

		[[nodiscard]] constexpr xte::uz size() const noexcept {
			return this->_size;
		}

		[[nodiscard]] friend constexpr std::strong_ordering operator<=>(xte::string_view_base<char_type> lhs, typename[:^^xte::string_view_base<char_type>:] rhs) noexcept {
			return xte::range_compare(lhs, rhs);
		}

		template<xte::uz rhs_size>
		[[nodiscard]] friend constexpr std::strong_ordering operator<=>(xte::string_view_base<char_type> lhs, xte::type<char_type[rhs_size]> const& rhs) noexcept {
			return lhs <=> xte::string_view_base<char_type>(rhs);
		}

		[[nodiscard]] friend constexpr bool operator==(xte::string_view_base<char_type> lhs, typename[:^^xte::string_view_base<char_type>:] rhs) noexcept {
			return (lhs.size() == rhs.size()) && std::is_eq(lhs <=> rhs);
		}

		template<xte::uz rhs_size>
		[[nodiscard]] friend constexpr bool operator==(xte::string_view_base<char_type> lhs, xte::type<char_type[rhs_size]> const& rhs) noexcept {
			return lhs == xte::string_view_base<char_type>(rhs);
		}

		[[nodiscard]] constexpr decltype(auto) make_c_str_for(auto&& func, auto&&... args) const noexcept(false)
			requires requires(char const* data) { XTE_FWD(func)(data, XTE_FWD(args)...); }
		{
			static constexpr xte::uz buffer_size = 256;
			auto f = [&](auto&& data) -> decltype(auto) {
				for (xte::uz i = 0; i < this->size(); ++i) {
					data[i] = (*this)[i];
				}
				return XTE_FWD(func)(static_cast<char_type const*>(data), XTE_FWD(args)...);
			};
			return ((this->size() + 1) < buffer_size)
				? f(typename[:^^char_type[buffer_size]:] {})
				: f(xte::ptr<char_type[]>::make(this->size() + 1));
		}

		[[nodiscard]] constexpr char_type const* begin() const noexcept {
			return this->_data;
		}

		[[nodiscard]] constexpr char_type const* cbegin() const noexcept {
			return this->begin();
		}

		[[nodiscard]] constexpr char_type const* end() const noexcept {
			return this->_data + this->_size;
		}

		[[nodiscard]] constexpr char_type const* cend() const noexcept {
			return this->end();
		}

		[[nodiscard]] constexpr auto rbegin() const noexcept {
			return std::reverse_iterator(this->end());
		}

		[[nodiscard]] constexpr auto crbegin() const noexcept {
			return this->rbegin();
		}

		[[nodiscard]] constexpr auto rend() const noexcept {
			return std::reverse_iterator(this->begin());
		}

		[[nodiscard]] constexpr auto crend() const noexcept {
			return this->rend();
		}

		[[nodiscard]] constexpr char_type front(xte::uz index = 0) const noexcept {
			return this->_data[index];
		}

		[[nodiscard]] constexpr char_type back(xte::uz index = 0) const noexcept {
			return this->_data[this->_size - index - 1];
		}

		[[nodiscard]] constexpr char_type const& operator[](xte::uz index) const noexcept {
			return this->_data[index];
		}

		[[nodiscard]] constexpr xte::string_view_base<char_type> subview(xte::uz index, xte::uz size = -1uz) const noexcept {
			return (index < this->_size) ? xte::string_view_base<char_type>(this->_data + index, xte::min(this->_size - index, size)) : "";
		}

		[[nodiscard]] constexpr bool contains(xte::string_view_base<char_type> pattern) const noexcept {
			return ~this->find(pattern);
		}

		[[nodiscard]] constexpr bool contains(char_type c) const noexcept {
			return ~this->find(c);
		}

		[[nodiscard]] constexpr xte::uz find(xte::string_view_base<char_type> pattern) const noexcept {
			if (pattern.size() <= this->size()) {
				xte::uz period = ([&] -> xte::uz {
					xte::uz critical = 0;
					xte::uz repeat = 0;
					for (xte::uz i = 0; (i + repeat) < pattern.size(); ++i) {
						if (pattern[i + repeat] == pattern[critical + repeat]) {
							++repeat;
							continue;
						}
						if (pattern[i + repeat] > pattern[critical + repeat]) {
							critical = i;
						} else {
							i += repeat;
						}
						repeat = 0;
					}
					for (xte::uz i = 1; i < pattern.size(); ++i) {
						if (pattern[i] != pattern[(i + critical) % pattern.size()]) {
							return i;
						}
					}
					return 1;
				})();
				for (xte::uz i = 0; i <= (this->size() - pattern.size()); i += period) {
					if (std::is_eq(xte::range_compare(this->subview(i, pattern.size()), pattern))) {
						return i;
					}
				}
			}
			return -1uz;
		}

		[[nodiscard]] constexpr xte::uz find(char_type c) const noexcept {
			for (xte::uz i = 0; i < this->_size; ++i) {
				if (this->_data[i] == c) {
					return i;
				}
			}
			return -1uz;
		}

		[[nodiscard]] constexpr xte::uz find_last(xte::string_view_base<char_type> pattern) const noexcept {
			if (pattern.size() <= this->size()) {
				xte::uz period = ([&] -> xte::uz {
					xte::uz critical = 0;
					xte::uz repeat = 0;
					for (xte::uz i = 0; (i + repeat) < pattern.size(); ++i) {
						if (pattern.back(i + repeat) == pattern.back(critical + repeat)) {
							++repeat;
							continue;
						}
						if (pattern.back(i + repeat) > pattern.back(critical + repeat)) {
							critical = i;
						} else {
							i += repeat;
						}
						repeat = 0;
					}
					for (xte::uz i = 1; i < pattern.size(); ++i) {
						if (pattern.back(i) != pattern.back((i + critical) % pattern.size())) {
							return i;
						}
					}
					return 1;
				})();
				for (xte::uz i = this->size(); i >= pattern.size(); i -= period) {
					if (std::is_eq(xte::range_compare(this->subview(i - pattern.size(), pattern.size()), pattern))) {
						return i - pattern.size();
					}
				}
			}
			return -1uz;
		}

		[[nodiscard]] constexpr xte::uz find_last(char_type c) const noexcept {
			for (xte::uz i = this->_size; i--;) {
				if (this->_data[i] == c) {
					return i;
				}
			}
			return -1uz;
		}

		[[nodiscard]] constexpr xte::uz find_any_of(xte::string_view_base<char_type> chars) const noexcept {
			for (xte::uz i = 0; i < this->_size; ++i) {
				if (chars.contains(this->_data[i])) {
					return i;
				}
			}
			return -1uz;
		}

		[[nodiscard]] constexpr xte::uz find_any_of(char_type c) const noexcept {
			return this->find(c);
		}

		[[nodiscard]] constexpr xte::uz find_last_of(xte::string_view_base<char_type> chars) const noexcept {
			for (xte::uz i = this->_size; i--;) {
				if (chars.contains(this->_data[i])) {
					return i;
				}
			}
			return -1uz;
		}

		[[nodiscard]] constexpr xte::uz find_last_of(char_type c) const noexcept {
			return this->find_last(c);
		}

		[[nodiscard]] constexpr xte::uz find_not_of(xte::string_view_base<char_type> chars) const noexcept {
			for (xte::uz i = 0; i < this->_size; ++i) {
				if (!chars.contains(this->_data[i])) {
					return i;
				}
			}
			return -1uz;
		}

		[[nodiscard]] constexpr xte::uz find_not_of(char_type c) const noexcept {
			for (xte::uz i = 0; i < this->_size; ++i) {
				if (this->_data[i] != c) {
					return i;
				}
			}
			return -1uz;
		}

		[[nodiscard]] constexpr xte::uz find_last_not_of(xte::string_view_base<char_type> chars) const noexcept {
			for (xte::uz i = this->_size; i--;) {
				if (!chars.contains(this->_data[i])) {
					return i;
				}
			}
			return -1uz;
		}

		[[nodiscard]] constexpr xte::uz find_last_not_of(char_type c) const noexcept {
			for (xte::uz i = this->_size; i--;) {
				if (this->_data[i] != c) {
					return i;
				}
			}
			return -1uz;
		}

		[[nodiscard]] constexpr xte::string_view_base<char_type> after(xte::string_view_base<char_type> pattern) const noexcept {
			return this->subview(this->find(pattern));
		}

		[[nodiscard]] constexpr xte::string_view_base<char_type> after(char_type c) const noexcept {
			return this->subview(this->find(c));
		}

		[[nodiscard]] constexpr xte::string_view_base<char_type> after_last(xte::string_view_base<char_type> pattern) const noexcept {
			return this->subview(this->find_last(pattern));
		}

		[[nodiscard]] constexpr xte::string_view_base<char_type> after_last(char_type c) const noexcept {
			return this->subview(this->find_last(c));
		}

		[[nodiscard]] constexpr xte::string_view_base<char_type> after_any_of(xte::string_view_base<char_type> chars) const noexcept {
			return this->subview(this->find_not_of(chars));
		}

		[[nodiscard]] constexpr xte::string_view_base<char_type> after_any_of(char_type c) const noexcept {
			return this->subview(this->find_not_of(c));
		}

		[[nodiscard]] constexpr xte::string_view_base<char_type> before(xte::string_view_base<char_type> pattern) const noexcept {
			return this->subview(0, this->find(pattern));
		}

		[[nodiscard]] constexpr xte::string_view_base<char_type> before(char_type c) const noexcept {
			return this->subview(0, this->find(c));
		}

		[[nodiscard]] constexpr xte::string_view_base<char_type> before_last(xte::string_view_base<char_type> pattern) const noexcept {
			return this->subview(0, this->find_last(pattern));
		}

		[[nodiscard]] constexpr xte::string_view_base<char_type> before_last(char_type c) const noexcept {
			return this->subview(0, this->find_last(c));
		}

		[[nodiscard]] constexpr xte::string_view_base<char_type> before_any_of(xte::string_view_base<char_type> chars) const noexcept {
			xte::uz last = this->find_last_not_of(chars);
			return this->subview(0, last + !!~last);
		}

		[[nodiscard]] constexpr xte::string_view_base<char_type> before_any_of(char_type c) const noexcept {
			xte::uz last = this->find_last_not_of(c);
			return this->subview(0, last + !!~last);
		}

		[[nodiscard]] constexpr xte::string_view_base<char_type> between(xte::string_view_base<char_type> start, xte::string_view_base<char_type> end) const noexcept {
			return this->after(start).before_last(end);
		}

		[[nodiscard]] constexpr xte::string_view_base<char_type> between(char_type start, xte::string_view_base<char_type> end) const noexcept {
			return this->after(start).before_last(end);
		}

		[[nodiscard]] constexpr xte::string_view_base<char_type> between(xte::string_view_base<char_type> start, char_type end) const noexcept {
			return this->after(start).before_last(end);
		}

		[[nodiscard]] constexpr xte::string_view_base<char_type> between(char_type start, char_type end) const noexcept {
			return this->after(start).before_last(end);
		}

		[[nodiscard]] constexpr xte::string_view_base<char_type> between(xte::string_view_base<char_type> pattern) const noexcept {
			return this->between(pattern, pattern);
		}

		[[nodiscard]] constexpr xte::string_view_base<char_type> between(char_type c) const noexcept {
			return this->between(c, c);
		}

		[[nodiscard]] constexpr xte::string_view_base<char_type> between_first(xte::string_view_base<char_type> start, xte::string_view_base<char_type> end) const noexcept {
			return this->after(start).before(end);
		}

		[[nodiscard]] constexpr xte::string_view_base<char_type> between_first(char_type start, xte::string_view_base<char_type> end) const noexcept {
			return this->after(start).before(end);
		}

		[[nodiscard]] constexpr xte::string_view_base<char_type> between_first(xte::string_view_base<char_type> start, char_type end) const noexcept {
			return this->after(start).before(end);
		}

		[[nodiscard]] constexpr xte::string_view_base<char_type> between_first(char_type start, char_type end) const noexcept {
			return this->after(start).before(end);
		}

		[[nodiscard]] constexpr xte::string_view_base<char_type> between_first(xte::string_view_base<char_type> pattern) const noexcept {
			xte::uz start = this->find(pattern);
			return this->subview(start, this->subview(start).find(pattern));
		}

		[[nodiscard]] constexpr xte::string_view_base<char_type> between_first(char_type c) const noexcept {
			xte::uz start = this->find(c);
			return this->subview(start, this->subview(start).find(c));
		}

		[[nodiscard]] constexpr xte::string_view_base<char_type> between_last(xte::string_view_base<char_type> start, xte::string_view_base<char_type> end) const noexcept {
			return this->after_last(start).before_last(end);
		}

		[[nodiscard]] constexpr xte::string_view_base<char_type> between_last(char_type start, xte::string_view_base<char_type> end) const noexcept {
			return this->after_last(start).before_last(end);
		}

		[[nodiscard]] constexpr xte::string_view_base<char_type> between_last(xte::string_view_base<char_type> start, char_type end) const noexcept {
			return this->after_last(start).before_last(end);
		}

		[[nodiscard]] constexpr xte::string_view_base<char_type> between_last(char_type start, char_type end) const noexcept {
			return this->after_last(start).before_last(end);
		}

		[[nodiscard]] constexpr xte::string_view_base<char_type> between_last(xte::string_view_base<char_type> pattern) const noexcept {
			xte::uz end = this->find_last(pattern);
			return this->subview(this->subview(0, end).find_last(pattern), end);
		}

		[[nodiscard]] constexpr xte::string_view_base<char_type> between_last(char_type c) const noexcept {
			xte::uz end = this->find_last(c);
			return this->subview(this->subview(0, end).find_last(c), end);
		}

		[[nodiscard]] constexpr xte::string_view_base<char_type> between_any_of(xte::string_view_base<char_type> start, xte::string_view_base<char_type> end) const noexcept {
			return this->after_any_of(start).before_any_of(end);
		}

		[[nodiscard]] constexpr xte::string_view_base<char_type> between_any_of(char_type start, xte::string_view_base<char_type> end) const noexcept {
			return this->after_any_of(start).before_any_of(end);
		}

		[[nodiscard]] constexpr xte::string_view_base<char_type> between_any_of(xte::string_view_base<char_type> start, char_type end) const noexcept {
			return this->after_any_of(start).before_any_of(end);
		}

		[[nodiscard]] constexpr xte::string_view_base<char_type> between_any_of(char_type start, char_type end) const noexcept {
			return this->after_any_of(start).before_any_of(end);
		}

		[[nodiscard]] constexpr xte::string_view_base<char_type> between_any_of(xte::string_view_base<char_type> chars) const noexcept {
			return this->between_any_of(chars, chars);
		}

		[[nodiscard]] constexpr xte::string_view_base<char_type> between_any_of(char_type c) const noexcept {
			return this->between_any_of(c, c);
		}

		constexpr void reset() noexcept {
			this->_data = nullptr;
			this->_size = 0;
		}
	};

	using string_view = xte::string_view_base<char>;
}

namespace xte::literal::string_view {
	[[nodiscard]] constexpr xte::string_view operator""_view(char const* data, xte::uz size) noexcept {
		return xte::string_view(data, size);
	}
}

template<>
struct std::formatter<xte::string_view> : std::formatter<std::string_view> {
	[[nodiscard]] constexpr auto parse(std::format_parse_context& ctx) noexcept {
		return std::formatter<std::string_view>::parse(ctx);
	}

	[[nodiscard]] auto format(xte::string_view string, std::format_context& ctx) const noexcept(false) {
		return std::formatter<std::string_view>::format(std::string_view(string), ctx);
	}
};

#endif
