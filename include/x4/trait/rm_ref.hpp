#pragma once

#include <type_traits>

namespace x4 {
	template<typename T>
	using rmref = std::remove_reference_t<T>;
}
