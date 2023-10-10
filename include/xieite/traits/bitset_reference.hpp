#pragma once

#include <type_traits>
#include "../concepts/bitset_reference.hpp"

namespace xieite::traits {
	template<typename Type>
	struct BitsetReference
	: std::bool_constant<xieite::concepts::BitsetReference<Type>> {};
}
