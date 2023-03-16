#pragma once
#include <concepts> // std::same_as
#include <type_traits> // std::decay_t

namespace xieite::concepts {
	template<typename Any>
	concept Decayed = std::same_as<Any, std::decay_t<Any>>;
}
