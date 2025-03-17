#pragma once

#include <concepts>
#include "../trait/rm_ref.hpp"

namespace xieite {
	template<typename T, typename U>
	concept is_ref_to = std::same_as<xieite::rm_ref<T>, U>;
}
