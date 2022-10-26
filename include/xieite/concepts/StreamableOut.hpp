#pragma once
#include <ostream>
#include <type_traits>

namespace xieite::concepts {
	template<typename T>
	concept StreamableOut = requires(std::ostream& outStream, T value) {
		{ outStream << value } -> std::convertible_to<std::ostream&>;
	};
}
