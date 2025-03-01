#pragma once

#include <type_traits>
#include "../trait/setcpass.hpp"

namespace x4 {
	template<typename T>
	using cpcpass = x4::setcpass<std::is_copy_assignable_v<T>>;
}
