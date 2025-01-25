#pragma once

#include <concepts>
#include <istream>
#include <type_traits>

namespace xieite {
	template<typename T>
	concept is_istream = std::same_as<std::remove_cv_t<T>, std::istream> || std::derived_from<std::remove_cv_t<T>, std::istream>;
}
