#pragma once

#include <concepts>
#include <ostream>

namespace xieite::concepts {
	template<typename Type>
	concept StreamableOut = requires(Type value, std::ostream outputStream) {
		{ outputStream << value } -> std::same_as<std::ostream&>;
	};
}

// Thanks to fux for original code
