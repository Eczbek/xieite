#pragma once

#include <type_traits>
#include <xieite/types/List.hpp>

namespace xieite::types {
	template<typename... Types>
	using Set = decltype((xieite::types::List<>()->*...->*xieite::types::List<Types>()));
}

// Thanks to Eisenwave for original code
