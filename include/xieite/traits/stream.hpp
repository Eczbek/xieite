#pragma once

#include <type_traits>
#include "../concepts/stream.hpp"

namespace xieite::traits {
	template<typename Type>
	struct Stream
	: std::bool_constant<xieite::concepts::Stream<Type>> {};
}
