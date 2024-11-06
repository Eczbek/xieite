module;

#include <xieite/fwd.hpp>

export module xieite:dump;

import std;

export namespace xieite {
	template<typename... Args>
	void dump(Args&&... args) noexcept {
		static constexpr std::size_t size = sizeof...(Args) * 3 - 1;
		static constexpr auto data = ([] -> std::array<char, size> {
			std::array<char, size> data;
			for (std::size_t i = 0; i < size; ++i) {
				data[i] = "{} "[i % 3];
			}
			return data;
		})();
		std::println(std::format_string<Args...>(std::string_view(data.data(), size)), XIEITE_FWD(args)...);
	}
}
