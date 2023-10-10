#pragma once

#include <type_traits>
#include "../concepts/output_stream.hpp"

namespace xieite::traits {
	template<typename Type>
	struct OutputStream
	: std::bool_constant<xieite::concepts::OutputStream<Type>> {};
}
