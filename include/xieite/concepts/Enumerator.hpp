#pragma once

#include <type_traits>

namespace xieite::concepts {
	template<typename Any>
	concept Enumerator = std::is_enum_v<Any>;
}
