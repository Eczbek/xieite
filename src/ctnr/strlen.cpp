export module xieite:strlen;

import std;
import :is_ch;

export namespace xieite {
	template<typename Str>
	requires(std::is_pointer_v<Str> && xieite::is_ch<std::remove_pointer_t<Str>>)
	[[nodiscard]] constexpr std::size_t strlen(Str str) noexcept {
		std::size_t size = 0;
		while (str[size++]);
		return size;
	}

	template<xieite::is_ch Ch, std::size_t size>
	[[nodiscard]] constexpr std::size_t strlen(Ch(&)[size]) noexcept {
		return size;
	}
}
