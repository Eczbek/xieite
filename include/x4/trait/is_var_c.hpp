#pragma once

#include "../trait/iscreft.hpp"
#include "../trait/isvar.hpp"

namespace x4 {
	template<typename T>
	concept isvarc = x4::isvar<T> && x4::iscreft<T>;
}
