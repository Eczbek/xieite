#pragma once

#include "../trait/isvar.hpp"
#include "../trait/setvar.hpp"

namespace x4 {
	template<typename T, typename U>
	using cpvar = x4::setvar<x4::isvar<T>, U>;
}
