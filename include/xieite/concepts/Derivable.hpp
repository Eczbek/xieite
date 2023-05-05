#pragma once

#include <type_traits>

namespace xieite::concepts {
	template<typename Any>
	concept Derivable = std::is_class_v<Any> && !std::is_final_v<Any>;
}
