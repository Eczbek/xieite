#pragma once

#include "../trait/iscreft.hpp"
#include "../trait/isrrefreft.hpp"

namespace x4 {
	template<typename T>
	concept iscrrefreft = x4::iscreft<T> && x4::isrrefreft<T>;
}
