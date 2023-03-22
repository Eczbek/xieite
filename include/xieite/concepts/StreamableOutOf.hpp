#pragma once

#include <concepts>
#include <ostream>

namespace xieite::concepts {
	template<typename Any>
	concept StreamableOutOf = requires(std::ostream& outputStream, Any value) {
		{ outputStream << value } -> std::convertible_to<std::ostream&>;
	};
}

// Thanks to fux for concept
