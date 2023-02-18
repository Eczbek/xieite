#pragma once
#include <concepts> // std::convertible_to
#include <ostream> // std::ostream

// Thanks to fux for concept

namespace xieite::concepts {
	template<typename T>
	concept StreamableOut = requires(std::ostream& outStream, T value) {
		{ outStream << value } -> std::convertible_to<std::ostream&>;
	};
}
