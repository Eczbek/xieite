#pragma once

#include <concepts>
#include <ostream>

namespace xieite::concepts {
	template<typename Type>
	concept OutputStream = std::same_as<Type, std::ostream> || std::derived_from<Type, std::ostream>;
}
