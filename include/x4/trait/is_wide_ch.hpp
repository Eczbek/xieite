#pragma once

#include "../trait/issame_any.hpp"
#include "../trait/rmcv.hpp"

namespace x4 {
	template<typename T>
	concept iswidech = x4::issame_any<x4::rmcv<T>, wchar_t, char16_t, char32_t>;
}
