#ifndef DETAIL_XIEITE_HEADER_IO_DUMP
#	define DETAIL_XIEITE_HEADER_IO_DUMP
#
#	include <array>
#	include <cstddef>
#	include <format>
#	include <print>
#	include <string_view>
#	include "../fn/unroll.hpp"
#	include "../pp/fwd.hpp"

namespace xieite {
	template<typename... Args>
	void dump(Args&&... args) noexcept {
		static constexpr std::size_t size = sizeof...(Args) * 3 - !!sizeof...(Args);
		static constexpr std::array<char, size> data = xieite::unroll<size>([]<std::size_t... i> static {
			return std::array<char, size> { "{} "[i % 3]... };
		});
		std::println(std::format_string<Args...>(std::string_view(data.data(), size)), XIEITE_FWD(args)...);
	}
}

#endif
