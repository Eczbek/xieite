#pragma once

#include <type_traits>


namespace gcufl::concepts {
	template<typename T>
	concept Decayed = std::is_same_v<T, std::decay_t<T>>;
}
