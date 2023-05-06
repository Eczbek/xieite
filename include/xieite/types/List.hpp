#pragma once

namespace xieite::types {
	template<typename... Types>
	struct List final {
		template<typename Type>
		constexpr auto operator->*(xieite::types::List<Type>) -> std::conditional_t<(std::is_same_v<Types, Type> || ...), xieite::types::List<Types...>, xieite::types::List<Types..., Type>>;
	};
}

// Thanks to Eisenwave for original code
