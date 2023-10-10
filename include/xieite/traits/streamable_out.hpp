#pragma once

#include <type_traits>
#include "../concepts/streamable_out.hpp"

namespace xieite::traits {
	template<typename Type>
	struct StreamableOut
	: std::bool_constant<xieite::concepts::StreamableOut<Type>> {};
}
