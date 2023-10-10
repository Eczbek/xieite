#pragma once

#include <type_traits>
#include "../concepts/narrow_character.hpp"

namespace xieite::traits {
	template<typename Type>
	struct NarrowCharacter
	: std::bool_constant<xieite::concepts::NarrowCharacter<Type>> {};
}
