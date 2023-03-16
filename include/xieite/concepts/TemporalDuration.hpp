#pragma once
#include <type_traits> // std::remove_cv_t
#include <xieite/traits/isTemporalDuration.hpp>

namespace xieite::concepts {
	template<typename Any>
	concept TemporalDuration = xieite::traits::isTemporalDuration<std::remove_cv_t<Any>>;
}
