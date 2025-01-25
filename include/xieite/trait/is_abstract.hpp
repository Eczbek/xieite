#pragma once

#include <type_traits>

namespace xieite {
	template<typename T>
	concept is_abstract = std::is_abstract_v<T>;
}
