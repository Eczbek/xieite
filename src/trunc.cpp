export module xieite:trunc;

import std;
import :sv;

export namespace xieite {
	[[nodiscard]] constexpr std::string trunc(std::string_view str, std::size_t size, xieite::sv sfx = "") noexcept {
		return (str.size() <= size)
			? std::string(str)
			: ((sfx.size() > size)
				? std::string(sfx.substr(0, size))
				: (std::string(str.substr(0, size - sfx.size())) + sfx));
	}
}
