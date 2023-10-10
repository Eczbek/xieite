#pragma once

#include <type_traits>
#include "../concepts/same_as_any.hpp"
#include "../concepts/wide_character.hpp"

namespace xieite::concepts {
	template<typename Type>
	concept Character = xieite::concepts::WideCharacter<Type> || xieite::concepts::SameAsAny<std::remove_cv_t<Type>, char, char8_t>;
}
