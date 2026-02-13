#ifndef DETAIL_XTE_HEADER_DATA_STRING
#	define DETAIL_XTE_HEADER_DATA_STRING
#
#	include "../data/array.hpp"
#	include "../data/lowercase.hpp"
#	include "../data/uppercase.hpp"
#	include "../util/types.hpp"
#	include <algorithm>
#	include <format>
#	include <ranges>

namespace xte {
	struct string : xte::array<char> {
		using xte::array<char>::array;

		[[nodiscard]] explicit constexpr string(const char* data) noexcept(false) {
			if (data) do {
				this->push(*data);
			} while (*data++);
		}

		[[nodiscard]] constexpr string(const char* data, xte::uz size) noexcept(false) {
			this->resize(size);
			for (xte::uz i : std::views::indices(size)) {
				(*this)[i] = data[i];
			}
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
	[[nodiscard]] constexpr xte::string operator""_string(const char* data, xte::uz size) noexcept(false) {
		return xte::string(data, size);
	}
}

template<>
struct std::formatter<xte::string> {
	constexpr auto parse(std::format_parse_context& ctx) {
		return ctx.begin();
	}

	auto format(const xte::string& string, std::format_context& ctx) const {
		return std::ranges::copy(string, ctx.out()).out;
	}
};

#endif
