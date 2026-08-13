#ifndef DETAIL_XTE_HEADER_DATA_STRING_VIEW
#	define DETAIL_XTE_HEADER_DATA_STRING_VIEW
#
#	include "../data/range_compare.hpp"
#	include "../math/max.hpp"
#	include "../math/min.hpp"
#	include "../math/width.hpp"
#	include "../meta/type.hpp"
#	include "../preproc/constructs.hpp"
#	include "../trait/is_castable_implicit_noex.hpp"
#	include "../util/number_types.hpp"
#	include <compare>
#	include <format>
#	include <iterator>
#	include <meta>
#	include <ranges>
#	include <string_view>
#	include <type_traits>

namespace xte {
	struct string_view : std::ranges::view_base {
		const char* _data = nullptr;
		xte::uz _size = 0;

		[[nodiscard]] explicit(false) constexpr string_view() noexcept = default;

		template<xte::uz size>
		[[nodiscard]] explicit(false) constexpr string_view(xte::type<const char[size]>& data) noexcept
		: xte::string_view(data, size) {}

		[[nodiscard]] explicit(false) constexpr string_view(const char& c) noexcept
		: xte::string_view(&c, 1) {}

		[[nodiscard]] explicit constexpr string_view(const xte::is_castable_implicit_noex<const char*> auto& range) noexcept
		: _data(range) {
			if (const char* copy = this->_data) {
				while (*copy++) {
					++this->_size;
				}
			}
		}

		[[nodiscard]] constexpr string_view(const char* data, xte::uz size) noexcept
		: _data(data), _size(size) {
			if (this->_size && !this->back()) {
				--this->_size;
			}
		}

		template<std::ranges::contiguous_range range_type>
		requires(xte::is_same<std::ranges::range_value_t<range_type>, char>)
		[[nodiscard]] constexpr string_view(std::from_range_t, const range_type& range) XTE_CONSTRUCTS(,
			(xte::string_view),((std::ranges::data(range), std::ranges::size(range)))
		)

		[[nodiscard]] explicit(false) constexpr string_view(const auto& range) XTE_CONSTRUCTS(,
			(xte::string_view),((std::from_range, range))
		)

		template<std::input_iterator iter_type>
		[[nodiscard]] constexpr string_view(iter_type begin, std::sentinel_for<iter_type> auto end) XTE_CONSTRUCTS(,
			(xte::string_view),((std::ranges::subrange(begin, end)))
		)

		[[nodiscard]] constexpr const char* data() const noexcept {
			return this->_data;
		}

		[[nodiscard]] constexpr xte::uz size() const noexcept {
			return this->_size;
		}

		[[nodiscard]] constexpr const char* begin() const noexcept {
			return this->_data;
		}

		[[nodiscard]] constexpr const char* cbegin() const noexcept {
			return this->begin();
		}

		[[nodiscard]] constexpr const char* end() const noexcept {
			return this->_data + this->_size;
		}

		[[nodiscard]] constexpr const char* cend() const noexcept {
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

		[[nodiscard]] constexpr char front(xte::uz index = 0) const noexcept {
			return this->_data[index];
		}

		[[nodiscard]] constexpr char back(xte::uz index = 0) const noexcept {
			return this->_data[this->_size - index - 1];
		}

		[[nodiscard]] constexpr const char& operator[](xte::uz index) const noexcept {
			return this->_data[index];
		}

		[[nodiscard]] constexpr xte::string_view subview(xte::uz index, xte::uz size = -1uz) const noexcept {
			return (index < this->_size) ? xte::string_view(this->_data + index, xte::min(this->_size - index, size)) : "";
		}

		[[nodiscard]] constexpr bool contains(xte::string_view pattern) const noexcept {
			return ~this->find(pattern);
		}

		[[nodiscard]] constexpr bool contains(char c) const noexcept {
			return ~this->find(c);
		}

		[[nodiscard]] constexpr xte::uz find(xte::string_view pattern) const noexcept {
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

		[[nodiscard]] constexpr xte::uz find(char c) const noexcept {
			for (xte::uz i = 0; i < this->_size; ++i) {
				if (this->_data[i] == c) {
					return i;
				}
			}
			return -1uz;
		}

		[[nodiscard]] constexpr xte::uz find_last(xte::string_view pattern) const noexcept {
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

		[[nodiscard]] constexpr xte::uz find_last(char c) const noexcept {
			for (xte::uz i = this->_size; i--;) {
				if (this->_data[i] == c) {
					return i;
				}
			}
			return -1uz;
		}

		[[nodiscard]] constexpr xte::uz find_any_of(xte::string_view chars) const noexcept {
			for (xte::uz i = 0; i < this->_size; ++i) {
				if (chars.contains(this->_data[i])) {
					return i;
				}
			}
			return -1uz;
		}

		[[nodiscard]] constexpr xte::uz find_any_of(char c) const noexcept {
			return this->find(c);
		}

		[[nodiscard]] constexpr xte::uz find_last_of(xte::string_view chars) const noexcept {
			for (xte::uz i = this->_size; i--;) {
				if (chars.contains(this->_data[i])) {
					return i;
				}
			}
			return -1uz;
		}

		[[nodiscard]] constexpr xte::uz find_last_of(char c) const noexcept {
			return this->find_last(c);
		}

		[[nodiscard]] constexpr xte::uz find_not_of(xte::string_view chars) const noexcept {
			for (xte::uz i = 0; i < this->_size; ++i) {
				if (!chars.contains(this->_data[i])) {
					return i;
				}
			}
			return -1uz;
		}

		[[nodiscard]] constexpr xte::uz find_not_of(char c) const noexcept {
			for (xte::uz i = 0; i < this->_size; ++i) {
				if (this->_data[i] != c) {
					return i;
				}
			}
			return -1uz;
		}

		[[nodiscard]] constexpr xte::uz find_last_not_of(xte::string_view chars) const noexcept {
			for (xte::uz i = this->_size; i--;) {
				if (!chars.contains(this->_data[i])) {
					return i;
				}
			}
			return -1uz;
		}

		[[nodiscard]] constexpr xte::uz find_last_not_of(char c) const noexcept {
			for (xte::uz i = this->_size; i--;) {
				if (this->_data[i] != c) {
					return i;
				}
			}
			return -1uz;
		}

		[[nodiscard]] constexpr xte::string_view after(xte::string_view pattern) const noexcept {
			return this->subview(this->find(pattern));
		}

		[[nodiscard]] constexpr xte::string_view after(char c) const noexcept {
			return this->subview(this->find(c));
		}

		[[nodiscard]] constexpr xte::string_view after_last(xte::string_view pattern) const noexcept {
			return this->subview(this->find_last(pattern));
		}

		[[nodiscard]] constexpr xte::string_view after_last(char c) const noexcept {
			return this->subview(this->find_last(c));
		}

		[[nodiscard]] constexpr xte::string_view after_any_of(xte::string_view chars) const noexcept {
			return this->subview(this->find_not_of(chars));
		}

		[[nodiscard]] constexpr xte::string_view after_any_of(char c) const noexcept {
			return this->subview(this->find_not_of(c));
		}

		[[nodiscard]] constexpr xte::string_view before(xte::string_view pattern) const noexcept {
			return this->subview(0, this->find(pattern));
		}

		[[nodiscard]] constexpr xte::string_view before(char c) const noexcept {
			return this->subview(0, this->find(c));
		}

		[[nodiscard]] constexpr xte::string_view before_last(xte::string_view pattern) const noexcept {
			return this->subview(0, this->find_last(pattern));
		}

		[[nodiscard]] constexpr xte::string_view before_last(char c) const noexcept {
			return this->subview(0, this->find_last(c));
		}

		[[nodiscard]] constexpr xte::string_view before_any_of(xte::string_view chars) const noexcept {
			xte::uz last = this->find_last_not_of(chars);
			return this->subview(0, last + !!~last);
		}

		[[nodiscard]] constexpr xte::string_view before_any_of(char c) const noexcept {
			xte::uz last = this->find_last_not_of(c);
			return this->subview(0, last + !!~last);
		}

		[[nodiscard]] constexpr xte::string_view between(xte::string_view start, xte::string_view end) const noexcept {
			return this->after(start).before_last(end);
		}

		[[nodiscard]] constexpr xte::string_view between(char start, xte::string_view end) const noexcept {
			return this->after(start).before_last(end);
		}

		[[nodiscard]] constexpr xte::string_view between(xte::string_view start, char end) const noexcept {
			return this->after(start).before_last(end);
		}

		[[nodiscard]] constexpr xte::string_view between(char start, char end) const noexcept {
			return this->after(start).before_last(end);
		}

		[[nodiscard]] constexpr xte::string_view between(xte::string_view pattern) const noexcept {
			return this->between(pattern, pattern);
		}

		[[nodiscard]] constexpr xte::string_view between(char c) const noexcept {
			return this->between(c, c);
		}

		[[nodiscard]] constexpr xte::string_view between_first(xte::string_view start, xte::string_view end) const noexcept {
			return this->after(start).before(end);
		}

		[[nodiscard]] constexpr xte::string_view between_first(char start, xte::string_view end) const noexcept {
			return this->after(start).before(end);
		}

		[[nodiscard]] constexpr xte::string_view between_first(xte::string_view start, char end) const noexcept {
			return this->after(start).before(end);
		}

		[[nodiscard]] constexpr xte::string_view between_first(char start, char end) const noexcept {
			return this->after(start).before(end);
		}

		[[nodiscard]] constexpr xte::string_view between_first(xte::string_view pattern) const noexcept {
			xte::uz start = this->find(pattern);
			return this->subview(start, this->subview(start).find(pattern));
		}

		[[nodiscard]] constexpr xte::string_view between_first(char c) const noexcept {
			xte::uz start = this->find(c);
			return this->subview(start, this->subview(start).find(c));
		}

		[[nodiscard]] constexpr xte::string_view between_last(xte::string_view start, xte::string_view end) const noexcept {
			return this->after_last(start).before_last(end);
		}

		[[nodiscard]] constexpr xte::string_view between_last(char start, xte::string_view end) const noexcept {
			return this->after_last(start).before_last(end);
		}

		[[nodiscard]] constexpr xte::string_view between_last(xte::string_view start, char end) const noexcept {
			return this->after_last(start).before_last(end);
		}

		[[nodiscard]] constexpr xte::string_view between_last(char start, char end) const noexcept {
			return this->after_last(start).before_last(end);
		}

		[[nodiscard]] constexpr xte::string_view between_last(xte::string_view pattern) const noexcept {
			xte::uz end = this->find_last(pattern);
			return this->subview(this->subview(0, end).find_last(pattern), end);
		}

		[[nodiscard]] constexpr xte::string_view between_last(char c) const noexcept {
			xte::uz end = this->find_last(c);
			return this->subview(this->subview(0, end).find_last(c), end);
		}

		[[nodiscard]] constexpr xte::string_view between_any_of(xte::string_view start, xte::string_view end) const noexcept {
			return this->after_any_of(start).before_any_of(end);
		}

		[[nodiscard]] constexpr xte::string_view between_any_of(char start, xte::string_view end) const noexcept {
			return this->after_any_of(start).before_any_of(end);
		}

		[[nodiscard]] constexpr xte::string_view between_any_of(xte::string_view start, char end) const noexcept {
			return this->after_any_of(start).before_any_of(end);
		}

		[[nodiscard]] constexpr xte::string_view between_any_of(char start, char end) const noexcept {
			return this->after_any_of(start).before_any_of(end);
		}

		[[nodiscard]] constexpr xte::string_view between_any_of(xte::string_view chars) const noexcept {
			return this->between_any_of(chars, chars);
		}

		[[nodiscard]] constexpr xte::string_view between_any_of(char c) const noexcept {
			return this->between_any_of(c, c);
		}

		constexpr void reset() noexcept {
			this->_data = nullptr;
			this->_size = 0;
		}
	};

	[[nodiscard]] constexpr std::strong_ordering operator<=>(xte::string_view lhs, xte::string_view rhs) noexcept {
		return xte::range_compare(lhs, rhs);
	}

	[[nodiscard]] constexpr bool operator==(xte::string_view lhs, xte::string_view rhs) noexcept {
		return (lhs.size() == rhs.size()) && std::is_eq(lhs <=> rhs);
	}
}

namespace xte::literal::string_view {
	[[nodiscard]] constexpr xte::string_view operator""_view(const char* data, xte::uz size) noexcept {
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
