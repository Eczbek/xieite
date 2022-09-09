#pragma once

#include <gcufl/io/escapeCodes/Background.hpp>
#include <gcufl/io/escapeCodes/Effect.hpp>
#include <gcufl/io/escapeCodes/Foreground.hpp>
#include <gcufl/io/escapeCodes/Prefix.hpp>


namespace gcufl::io {
	template <gcufl::io::escapeCodes::Background B, gcufl::io::escapeCodes::Prefix P = gcufl::io::escapeCodes::Prefix::Hexadecimal>
	void setStyle() noexcept {
		std::cout << static_cast<char>(P) << '[' << static_cast<int>(B) << 'm';
	}

	template <gcufl::io::escapeCodes::Effect E, gcufl::io::escapeCodes::Prefix P = gcufl::io::escapeCodes::Prefix::Hexadecimal>
	void setStyle() noexcept {
		std::cout << static_cast<char>(P) << '[' << static_cast<int>(E) << 'm';
	}

	template <gcufl::io::escapeCodes::Foreground F, gcufl::io::escapeCodes::Prefix P = gcufl::io::escapeCodes::Prefix::Hexadecimal>
	void setStyle() noexcept {
		std::cout << static_cast<char>(P) << '[' << static_cast<int>(F) << 'm';
	}

	template <gcufl::io::escapeCodes::Effect E, gcufl::io::escapeCodes::Foreground F, gcufl::io::escapeCodes::Prefix P = gcufl::io::escapeCodes::Prefix::Hexadecimal>
	void setStyle() noexcept {
		std::cout << static_cast<char>(P) << '[' << static_cast<int>(E) << ';' << static_cast<int>(F) << 'm';
	}

	template <gcufl::io::escapeCodes::Effect E, gcufl::io::escapeCodes::Foreground F, gcufl::io::escapeCodes::Background B, gcufl::io::escapeCodes::Prefix P = gcufl::io::escapeCodes::Prefix::Hexadecimal>
	void setStyle() noexcept {
		std::cout << static_cast<char>(P) << '[' << static_cast<int>(E) << ';' << static_cast<int>(F) << ';' << static_cast<int>(B) << 'm';
	}
}
