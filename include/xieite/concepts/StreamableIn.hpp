#pragma once
#include <istream>
#include <type_traits>

namespace xieite::concepts {
	template<typename T>
	concept StreamableIn = requires(std::istream& inStream, T value) {
		{ inStream >> value } -> std::convertible_to<std::istream&>;
	};
}
