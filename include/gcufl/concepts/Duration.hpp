#pragma once

#include <gcufl/traits/isDuration.hpp>
#include <type_traits>


namespace gcufl::concepts {
	template<typename T>
	concept Duration = gcufl::traits::isDuration<std::remove_cv_t<T>>;
}
