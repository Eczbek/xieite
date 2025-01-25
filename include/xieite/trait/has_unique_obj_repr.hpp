#pragma once

#include <type_traits>

namespace xieite {
	template<typename T>
	concept has_unique_obj_repr = std::has_unique_object_representations_v<T>;
}
