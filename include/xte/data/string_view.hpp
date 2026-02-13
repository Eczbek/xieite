#ifndef DETAIL_XTE_HEADER_DATA_STRING_VIEW
#	define DETAIL_XTE_HEADER_DATA_STRING_VIEW
#
#	include "../data/range_cmp.hpp"
#	include "../math/max.hpp"
#	include "../math/min.hpp"
#	include "../math/width.hpp"
#	include "../meta/type.hpp"
#	include "../preproc/arrow.hpp"
#	include "../trait/is_castable.hpp"
#	include "../trait/is_contiguous_input_range.hpp"
#	include "../trait/is_implicit_castable.hpp"
#	include "../util/types.hpp"
#	include <algorithm>
#	include <compare>
#	include <format>
#	include <ranges>

namespace xte {
	struct string_view : std::ranges::view_base {
		const char* _data;
		xte::uz _size;

		[[nodiscard]] explicit(false) constexpr string_view() noexcept
		: _data(nullptr), _size(0) {}

		template<xte::uz size>
		[[nodiscard]] explicit(false) constexpr string_view(const xte::type<char[size]>& data) noexcept
		: _data(data), _size(size - (size && !data[size - 1])) {}

		[[nodiscard]] explicit(false) constexpr string_view(const char& c) noexcept
		: _data(&c), _size(1) {}

		[[nodiscard]] explicit constexpr string_view(const xte::is_implicit_castable<const char*> auto& data, xte::uz size = -1uz) noexcept
		: _data(data), _size(size) {
			const char* copy = this->_data;
			if (!~size) do {
				++this->_size;
			} while (*copy++);
		}

		template<xte::is_contiguous_input_range Range>
		requires(xte::is_same<std::ranges::range_value_t<Range>, char>)
		[[nodiscard]] explicit(false) constexpr string_view(const Range& range) XTE_ARROW_CTOR(,
			_data,((std::ranges::data(range))),
			_size,((std::ranges::size(range)))
		)

		[[nodiscard]] friend constexpr std::strong_ordering operator<=>(xte::string_view lhs, xte::string_view rhs) noexcept {
			return xte::range_cmp(lhs, rhs);
		}

		[[nodiscard]] friend constexpr bool operator==(xte::string_view lhs, xte::string_view rhs) noexcept {
			return std::is_eq(lhs <=> rhs);
		}

		[[nodiscard]] constexpr char operator[](xte::uz index) const noexcept {
			return this->data()[index];
		}

		[[nodiscard]] constexpr const char* data() const noexcept {
			return this->_data;
		}

		[[nodiscard]] constexpr xte::uz size() const noexcept {
			return this->_size;
		}

		[[nodiscard]] constexpr const char* begin() const & noexcept {
			return this->data();
		}

		[[nodiscard]] constexpr const char* end() const & noexcept {
			return this->data() + this->size();
		}

		[[nodiscard]] constexpr char front(xte::uz index = 0) const noexcept {
			return (*this)[index];
		}

		[[nodiscard]] constexpr char back(xte::uz index = 0) const noexcept {
			return (*this)[this->size() - index - 1];
		}

		[[nodiscard]] constexpr xte::string_view substr(xte::uz index, xte::uz size) const noexcept {
			return xte::string_view(this->data() + xte::min(this->size(), index), xte::max(xte::min(this->size(), size), index) - index);
		}

		[[nodiscard]] constexpr xte::string_view substr(xte::uz index) const noexcept {
			return this->substr(index, this->size());
		}

		[[nodiscard]] constexpr xte::uz find(xte::string_view substr) const noexcept {
			if (substr.size() <= this->size()) {
				for (xte::uz i = 0; i <= this->size() - substr.size(); ++i) {
					xte::uz j = 0;
					while ((j < substr.size()) && (substr[j] == (*this)[i + j])) {
						++j;
					}
					if (j == substr.size()) {
						return i;
					}
				}
			}
			return -1uz;
		}

		[[nodiscard]] constexpr xte::uz find_last(xte::string_view substr) const noexcept {
			if (substr.size() <= this->size()) {
				for (xte::uz i = this->size(); i-- >= substr.size();) {
					xte::uz j = 0;
					while ((j < substr.size()) && (substr.back(j) == (*this)[i + j])) {
						++j;
					}
					if (j == substr.size()) {
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
			for (xte::uz i = 0; i < this->size(); ++i) {
				if (chars.contains((*this)[i])) {
					return i;
				}
			}
			return -1uz;
		}

		[[nodiscard]] constexpr xte::uz find_last_of(xte::string_view chars) const noexcept {
			for (xte::uz i = this->size(); i--;) {
				if (chars.contains((*this)[i])) {
					return i;
				}
			}
			return -1uz;
		}

		[[nodiscard]] constexpr xte::uz find_not_of(xte::string_view chars) const noexcept {
			for (xte::uz i = 0; i < this->size(); ++i) {
				if (!chars.contains((*this)[i])) {
					return i;
				}
			}
			return -1uz;
		}

		[[nodiscard]] constexpr xte::uz find_last_not_of(xte::string_view chars) const noexcept {
			for (xte::uz i = this->size(); i--;) {
				if (!chars.contains((*this)[i])) {
					return i;
				}
			}
			return -1uz;
		}

		[[nodiscard]] constexpr xte::string_view after(xte::string_view substr) const noexcept {
			return this->substr(this->find(substr)).substr(substr.size());
		}

		[[nodiscard]] constexpr xte::string_view before(xte::string_view substr) const noexcept {
			return this->substr(0, this->find_last(substr));
		}

		[[nodiscard]] constexpr xte::string_view between(xte::string_view substr_start, xte::string_view substr_end) const noexcept {
			return this->after(substr_start).before(substr_end);
		}

		[[nodiscard]] constexpr xte::string_view between(xte::string_view substr) const noexcept {
			return this->between(substr, substr);
		}

		[[nodiscard]] constexpr xte::string_view after_any_of(xte::string_view chars) const noexcept {
			return this->substr(this->find_not_of(chars));
		}

		[[nodiscard]] constexpr xte::string_view before_any_of(xte::string_view chars) const noexcept {
			xte::uz last = this->find_last_not_of(chars);
			return this->substr(0, last + !!~last);
		}

		[[nodiscard]] constexpr xte::string_view between_any_of(xte::string_view chars_start, xte::string_view chars_end) const noexcept {
			return this->after_any_of(chars_start).before_any_of(chars_end);
		}

		[[nodiscard]] constexpr xte::string_view between_any_of(xte::string_view chars) const noexcept {
			return this->between_any_of(chars, chars);
		}
	};
}

namespace xte::literal::string_view {
	[[nodiscard]] constexpr xte::string_view operator""_view(const char* data, xte::uz size) noexcept {
		return xte::string_view(data, size);
	}
}

template<>
struct std::formatter<xte::string_view> {
	constexpr auto parse(std::format_parse_context& ctx) {
		return ctx.begin();
	}

	auto format(xte::string_view string, std::format_context& ctx) const {
		return std::ranges::copy(string, ctx.out()).out;
	}
};

#endif
