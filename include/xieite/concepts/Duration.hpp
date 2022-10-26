#pragma once
#include <xieite/traits/isDuration.hpp>
#include <type_traits>

namespace xieite::concepts {
	template<typename T>
	concept Duration = xieite::traits::isDuration<std::remove_cv_t<T>>;
}
