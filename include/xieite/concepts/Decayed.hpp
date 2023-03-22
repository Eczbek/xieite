#pragma once

#include <concepts>
#include <type_traits>

namespace xieite::concepts {
	template<typename Any>
	concept Decayed = std::same_as<Any, std::decay_t<Any>>;
}
