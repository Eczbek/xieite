#pragma once

#include <type_traits>

namespace xieite {
	template<typename T>
	concept is_polymorphic = std::is_polymorphic_v<T>;
}
