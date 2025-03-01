#pragma once

#include <array>
#include <cstddef>
#include <format>
#include <print>
#include <string_view>
#include "../fn/unroll.hpp"
#include "../pp/fwd.hpp"

namespace x4 {
	template<typename... Args>
	void dump(Args&&... args) noexcept {
		static constexpr std::size_t size = sizeof...(Args) * 3 - !!sizeof...(Args);
		static constexpr std::array<char, size> data = x4::unroll<size>([]<std::size_t... i> static {
			return std::array<char, size> { "{} "[i % 3]... };
		});
		std::println(std::format_string<Args...>(std::string_view(data.data(), size)), X4FWD(args)...);
	}
}
