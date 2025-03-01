#pragma once

#include <cstddef>
#include <string>
#include <string_view>
#include "../trait/isch.hpp"
#include "../trait/rmptr.hpp"
#include "../trait/rmref.hpp"

namespace x4 {
	template<typename Ch>
	[[nodiscard]] constexpr std::size_t strlen(std::basic_string_view<Ch> strv) noexcept {
		return strv.size();
	}

	template<typename Ch>
	[[nodiscard]] constexpr std::size_t strlen(const std::basic_string<Ch>& str) noexcept {
		return str.size();
	}

	template<x4::isch Ch, std::size_t n>
	[[nodiscard]] constexpr std::size_t strlen(const Ch(&)[n]) noexcept {
		return n - !!n;
	}

	template<x4::isch Ch, typename Str>
	requires(std::same_as<Ch, x4::rmptr<x4::rmref<Str>>>)
	[[nodiscard]] constexpr std::size_t strlen(Str str) noexcept {
		std::size_t i = 0;
		while (str && str[i]) {
			++i;
		}
		return i;
	}

	template<x4::isch Ch>
	[[nodiscard]] constexpr std::size_t strlen(Ch) noexcept {
		return 1;
	}
}
