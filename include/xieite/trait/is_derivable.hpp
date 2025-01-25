#pragma once

#include <type_traits>

namespace xieite {
	template<typename T>
	concept is_derivable = !std::is_final_v<T>;
}
