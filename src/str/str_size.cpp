export module xieite:str_size;

import std;
import :is_ch;

export namespace xieite {
	template<xieite::is_ch Ch>
	[[nodiscard]] constexpr std::size_t str_size(Ch* str) noexcept {
		std::size_t size = 0;
		while (str[size]) {
			++size;
		}
		return size;
	}

	template<xieite::is_ch Ch, std::size_t size>
	[[nodiscard]] constexpr std::size_t str_size(Ch(&)[size]) noexcept {
		return size;
	}
}
