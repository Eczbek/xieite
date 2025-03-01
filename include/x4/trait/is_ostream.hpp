#pragma once

#include <concepts>
#include <ostream>
#include <type_traits>

namespace x4 {
	template<typename T>
	concept isostream = std::same_as<std::remove_cv_t<T>, std::ostream> || std::derived_from<std::remove_cv_t<T>, std::ostream>;
}
