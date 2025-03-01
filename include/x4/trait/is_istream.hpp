#pragma once

#include <concepts>
#include <istream>
#include <type_traits>

namespace x4 {
	template<typename T>
	concept isistream = std::same_as<std::remove_cv_t<T>, std::istream> || std::derived_from<std::remove_cv_t<T>, std::istream>;
}
