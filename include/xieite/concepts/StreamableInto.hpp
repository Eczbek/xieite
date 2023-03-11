#pragma once
#include <concepts> // std::convertible_to
#include <istream> // std::istream

namespace xieite::concepts {
	template<typename T>
	concept StreamableInto = requires(std::istream& inputStream, T value) {
		{ inputStream >> value } -> std::convertible_to<std::istream&>;
	};
}
