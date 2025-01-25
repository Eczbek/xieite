#pragma once

#include <type_traits>

namespace xieite {
	template<typename T>
	using t = std::type_identity<T>;
}
