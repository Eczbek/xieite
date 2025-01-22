module;

#include <xieite/fwd.hpp>

export module xieite:dump;

import std;
import :unroll;

export namespace xieite {
	template<typename... Args>
	void dump(Args&&... args) noexcept {
		static constexpr std::size_t size = sizeof...(Args) * 3 - !!sizeof...(Args);
		static constexpr std::array<char, size> data = xieite::unroll<size>([]<std::size_t... i> {
			return std::array<char, size> { "{} "[i % 3]... };
		});
		std::println(std::format_string<Args...>(std::string_view(data.data(), size)), XIEITE_FWD(args)...);
	}
}
