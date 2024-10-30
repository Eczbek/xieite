export module xieite:djb2;

import std;
import :sign_cast;

export namespace xieite {
	[[nodiscard]] constexpr std::size_t djb2(std::string_view str) noexcept {
		std::size_t result = 5381;
		for (char c : str) {
			result = result * 33 + xieite::sign_cast<std::size_t>(c);
		}
		return result;
	}
}
