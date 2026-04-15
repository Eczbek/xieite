#ifndef DETAIL_XTE_HEADER_DATA_STRING_VIEW
#	define DETAIL_XTE_HEADER_DATA_STRING_VIEW
#
#	include "../data/range_cmp.hpp"
#	include "../math/max.hpp"
#	include "../math/min.hpp"
#	include "../math/width.hpp"
#	include "../meta/type.hpp"
#	include "../preproc/arrow.hpp"
#	include "../trait/is_noex_implicit_castable.hpp"
#	include "../util/types.hpp"
#	include <algorithm>
#	include <compare>
#	include <format>
#	include <iterator>
#	include <ranges>

namespace xte {
	struct string_view : std::ranges::view_base {
		const char* _data = nullptr;
		xte::uz _size = 0;

		[[nodiscard]] explicit(false) constexpr string_view() noexcept = default;

		template<xte::uz size>
		[[nodiscard]] explicit(false) constexpr string_view(const xte::type<char[size]>& data) noexcept
		: xte::string_view(data, size) {}

		[[nodiscard]] explicit(false) constexpr string_view(const char& c) noexcept
		: _data(&c), _size(1) {}

		[[nodiscard]] explicit constexpr string_view(xte::is_noex_implicit_castable<const char*> auto&& range) noexcept
		: _data(range) {
			if (const char* copy = this->_data) {
				while (*copy++) {
					++this->_size;
				}
			}
		}

		[[nodiscard]] constexpr string_view(const char* data, xte::uz size) noexcept
		: _data(data), _size(size) {
			while (this->_size && !this->back()) {
				--this->_size;
			}
		}

		template<std::ranges::contiguous_range Range>
		requires(xte::is_same<std::ranges::range_value_t<Range>, char>)
		[[nodiscard]] constexpr string_view(std::from_range_t, const Range& range) XTE_ARROW_CTOR(,
			(xte::string_view),((std::ranges::data(range), std::ranges::size(range)))
		)

		[[nodiscard]] explicit(false) constexpr string_view(const auto& range) XTE_ARROW_CTOR(,
			(xte::string_view),((std::from_range, range))
		)

		template<std::input_iterator Iter>
		[[nodiscard]] constexpr string_view(Iter begin, std::sentinel_for<Iter> auto end) XTE_ARROW_CTOR(,
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

		[[nodiscard]] constexpr char operator[](xte::uz index) const noexcept {
			return this->_data[index];
		}

		[[nodiscard]] constexpr xte::string_view slice(xte::uz index, xte::uz size = -1uz) const noexcept {
			return (index < this->_size) ? xte::string_view(this->_data + index, xte::min(this->_size - index, size)) : "";
		}

		constexpr void reset() noexcept {
			this->_data = nullptr;
			this->_size = 0;
		}

		[[nodiscard]] constexpr xte::uz find(xte::string_view substr) const noexcept {
			if (substr._size <= this->_size) {
				for (xte::uz i = 0; i <= this->_size - substr._size; ++i) {
					xte::uz j = 0;
					while ((j < substr._size) && (substr[j] == this->_data[i + j])) {
						++j;
					}
					if (j == substr._size) {
						return i;
					}
				}
			}
			return -1uz;
		}

		[[nodiscard]] constexpr xte::uz find_last(xte::string_view substr) const noexcept {
			if (substr._size <= this->_size) {
				for (xte::uz i = this->_size; i-- >= substr._size;) {
					xte::uz j = 0;
					while ((j < substr._size) && (substr.back(j) == this->_data[i + j])) {
						++j;
					}
					if (j == substr._size) {
						return i;
					}
				}
			}
			return -1uz;
		}

		[[nodiscard]] constexpr bool contains(xte::string_view substr) const noexcept {
			return ~this->find(substr);
		}

		[[nodiscard]] constexpr xte::uz find_any_of(xte::string_view chars) const noexcept {
			for (xte::uz i = 0; i < this->_size; ++i) {
				if (chars.contains(this->_data[i])) {
					return i;
				}
			}
			return -1uz;
		}

		[[nodiscard]] constexpr xte::uz find_last_of(xte::string_view chars) const noexcept {
			for (xte::uz i = this->_size; i--;) {
				if (chars.contains(this->_data[i])) {
					return i;
				}
			}
			return -1uz;
		}

		[[nodiscard]] constexpr xte::uz find_not_of(xte::string_view chars) const noexcept {
			for (xte::uz i = 0; i < this->_size; ++i) {
				if (!chars.contains(this->_data[i])) {
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

		[[nodiscard]] constexpr xte::string_view after(xte::string_view substr) const noexcept {
			return this->slice(this->find(substr)).slice(substr._size);
		}

		[[nodiscard]] constexpr xte::string_view before(xte::string_view substr) const noexcept {
			return this->slice(0, this->find_last(substr));
		}

		[[nodiscard]] constexpr xte::string_view between(xte::string_view substr_start, xte::string_view substr_end) const noexcept {
			return this->after(substr_start).before(substr_end);
		}

		[[nodiscard]] constexpr xte::string_view between(xte::string_view substr) const noexcept {
			return this->between(substr, substr);
		}

		[[nodiscard]] constexpr xte::string_view after_any_of(xte::string_view chars) const noexcept {
			return this->slice(this->find_not_of(chars));
		}

		[[nodiscard]] constexpr xte::string_view before_any_of(xte::string_view chars) const noexcept {
			xte::uz last = this->find_last_not_of(chars);
			return this->slice(0, last + !!~last);
		}

		[[nodiscard]] constexpr xte::string_view between_any_of(xte::string_view chars_start, xte::string_view chars_end) const noexcept {
			return this->after_any_of(chars_start).before_any_of(chars_end);
		}

		[[nodiscard]] constexpr xte::string_view between_any_of(xte::string_view chars) const noexcept {
			return this->between_any_of(chars, chars);
		}
	};
}

[[nodiscard]] constexpr std::strong_ordering operator<=>(xte::string_view lhs, xte::string_view rhs) noexcept {
	return xte::range_cmp(lhs, rhs);
}

[[nodiscard]] constexpr bool operator==(xte::string_view lhs, xte::string_view rhs) noexcept {
	return (lhs.size() == rhs.size()) && std::is_eq(lhs <=> rhs);
}

namespace xte::literal::string_view {
	[[nodiscard]] constexpr xte::string_view operator""_view(const char* data, xte::uz size) noexcept {
		return xte::string_view(data, size);
	}
}

template<>
struct std::formatter<xte::string_view> {
	[[nodiscard]] constexpr auto parse(std::format_parse_context& ctx) noexcept {
		return ctx.begin();
	}

	[[nodiscard]] auto format(xte::string_view string, std::format_context& ctx) const noexcept(false) {
		return std::ranges::copy(string, ctx.out()).out;
	}
};

#endif
