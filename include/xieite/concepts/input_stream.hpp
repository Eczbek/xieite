#pragma once

#include <concepts>
#include <istream>

namespace xieite::concepts {
	template<typename Type>
	concept InputStream = std::same_as<Type, std::istream> || std::derived_from<Type, std::istream>;
}
