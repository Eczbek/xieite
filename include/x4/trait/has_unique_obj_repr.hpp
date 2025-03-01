#pragma once

#include <type_traits>

namespace x4 {
	template<typename T>
	concept hasuniqueobjrepr = std::has_unique_object_representations_v<T>;
}
