#pragma once

#include "../traitrmcvreft.hpp"
#include "../traitrmrrefreft.hpp"

namespace x4 {
	template<typename T>
	usingrmcvrrefreft = x4:rmcvreft<x4:rmrrefreft<T>>;
}
