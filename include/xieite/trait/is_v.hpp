#pragma once

#include <type_traits>
#include "../trait/rm_ref.hpp"

namespace xieite {
	template<typename T>
	concept is_v = std::is_volatile_v<xieite::rm_ref<T>>;
}
