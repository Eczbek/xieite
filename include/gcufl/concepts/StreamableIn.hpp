#pragma once

#include <istream>
#include <type_traits>


namespace gcufl::concepts {
	template<typename T>
	concept StreamableOut = requires(std::istream& inStream, T value) {
		{ inStream >> value } -> std::convertible_to<std::istream&>;
	};
}
