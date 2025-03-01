#pragma once

#include "../trait/isrrefreft.hpp"
#include "../trait/isvar.hpp"

namespace x4 {
	template<typename T>
	concept isvarrref = x4::isvar<T> && x4::isrrefreft<T>;
}
