#pragma once
#include <concepts> // std::convertible_to
#include <istream> // std::istream

namespace xieite::concepts {
	template<typename T>
	concept StreamableIn = requires(std::istream& inStream, T value) {
		{ inStream >> value } -> std::convertible_to<std::istream&>;
	};
}
