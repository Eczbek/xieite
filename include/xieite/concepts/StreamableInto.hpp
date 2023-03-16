#pragma once
#include <concepts> // std::convertible_to
#include <istream> // std::istream

namespace xieite::concepts {
	template<typename Any>
	concept StreamableInto = requires(std::istream& inputStream, Any value) {
		{ inputStream >> value } -> std::convertible_to<std::istream&>;
	};
}
