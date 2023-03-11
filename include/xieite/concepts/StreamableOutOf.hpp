#pragma once
#include <concepts> // std::convertible_to
#include <ostream> // std::ostream

// Thanks to fux for concept

namespace xieite::concepts {
	template<typename T>
	concept StreamableOutOf = requires(std::ostream& outputStream, T value) {
		{ outputStream << value } -> std::convertible_to<std::ostream&>;
	};
}
