#ifndef XIEITE_HEADER_CONTAINERS_STATIC_STRING
#	define XIEITE_HEADER_CONTAINERS_STATIC_STRING

#	include <array>
#	include <cstddef>
#	include <string_view>

namespace xieite::containers {
	template<std::size_t characters_, typename Character_ = char>
	struct FixedString {
		std::array<Character_, characters_ + 1> data;

		template<std::size_t otherCharacters_>
		constexpr FixedString(const Character_(&data)[otherCharacters_]) noexcept {
			for (std::size_t i = 0; i < otherCharacters_; ++i) {
				this->data[i] = data[i];
			}
		}

		[[nodiscard]] static constexpr std::size_t size() noexcept {
			return characters_;
		}

		[[nodiscard]] constexpr std::string_view view() const noexcept {
			const std::string_view view = std::string_view(this->data, this->data + characters_);
			return view.substr(0, view.find('\0'));
		}
	};

	template<std::size_t characters_, typename Character_>
	FixedString(const Character_(&)[characters_]) -> xieite::containers::FixedString<characters_ - 1, Character_>;
}

#endif
