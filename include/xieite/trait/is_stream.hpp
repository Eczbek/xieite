#pragma once

#include "../trait/is_istream.hpp"
#include "../trait/is_ostream.hpp"

namespace xieite {
	template<typename T>
	concept is_stream = xieite::is_istream<T> || xieite::is_ostream<T>;
}
