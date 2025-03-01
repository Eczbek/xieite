#pragma once

#include <type_traits>

namespace x4 {
	template<typename T, typename U>
	concept isrefctorfromtmp = std::reference_constructs_from_temporary_v<T, U>;
}
