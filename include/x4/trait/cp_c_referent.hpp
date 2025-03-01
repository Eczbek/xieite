#pragma once

#include "../trait/setcreft.hpp"
#include "../trait/iscreft.hpp"

namespace x4 {
	template<typename T, typename U>
	using cpcreft = x4::setcreft<x4::iscreft<T>, U>;
}
