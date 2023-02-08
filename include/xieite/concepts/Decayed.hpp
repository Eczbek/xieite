#pragma once
#include <concepts> // std::same_as
#include <type_traits> // std::decay_t

namespace xieite::concepts {
	template<typename T>
	concept Decayed = std::same_as<T, std::decay_t<T>>;
}
