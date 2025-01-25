#pragma once

#include <type_traits>

namespace xieite {
	template<typename T>
	using id = std::type_identity_t<T>;
}
