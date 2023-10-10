#pragma once

#include <type_traits>
#include "../concepts/derivable.hpp"

namespace xieite::traits {
	template<typename Type>
	struct Derivable
	: std::bool_constant<xieite::concepts::Derivable<Type>> {};
}
