export module xieite:containers.FixedString;

import std;

export namespace xieite::containers {
	template<std::size_t characters, typename Character = char>
	struct FixedString {
		static constexpr std::size_t size = characters;
		std::array<Character, characters> data;

		constexpr FixedString(const Character(&data)[characters]) noexcept {
			std::ranges::copy(data, this->data.begin());
		}

		[[nodiscard]] constexpr std::string_view view() const noexcept {
			return std::string_view(this->data.begin(), this->data.end());
		}
	};

	template<std::size_t characters, typename Character>
	FixedString(const Character(&)[characters]) -> xieite::containers::FixedString<characters, Character>;
}
