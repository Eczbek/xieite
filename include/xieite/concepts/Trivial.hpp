#pragma once

#include <type_traits>

namespace xieite::concepts {
	template<typename Any>
	concept Trivial = std::is_trivial_v<Any>;
}
