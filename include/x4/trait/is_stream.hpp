#pragma once

#include "../trait/isistream.hpp"
#include "../trait/isostream.hpp"

namespace x4 {
	template<typename T>
	concept isstream = x4::isistream<T> || x4::isostream<T>;
}
