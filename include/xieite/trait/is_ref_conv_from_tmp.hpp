#pragma once

#include <type_traits>

namespace xieite {
	template<typename T, typename U>
	concept is_ref_conv_from_tmp = std::reference_converts_from_temporary_v<T, U>;
}
