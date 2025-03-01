#pragma once

#include <type_traits>

namespace x4 {
	template<typename T, typename U>
	concept isrefconvfromtmp = std::reference_converts_from_temporary_v<T, U>;
}
