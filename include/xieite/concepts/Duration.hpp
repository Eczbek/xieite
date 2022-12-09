#pragma once
#include <type_traits> // std::remove_cv_t
#include <xieite/traits/isDuration.hpp> // xieite::traits::isDuration

namespace xieite::concepts {
	template<typename T>
	concept Duration = xieite::traits::isDuration<std::remove_cv_t<T>>;
}
