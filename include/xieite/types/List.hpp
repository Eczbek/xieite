#pragma once

#include <concepts>
#include <type_traits>

namespace xieite::types {
	template<typename... Types>
	struct List final {
		template<typename Type>
		constexpr std::conditional_t<(std::same_as<Types, Type> || ...), xieite::types::List<Types...>, xieite::types::List<Types..., Type>> operator->*(xieite::types::List<Type>);
	};
}

// Thanks to Eisenwave for original code
