#pragma once

namespace xieite::types {
	template<typename... Types>
	struct List final {
		template<typename Type>
		constexpr std::conditional_t<(std::is_same_v<Types, Type> || ...), xieite::types::List<Types...>, xieite::types::List<Types..., Type>> operator->*(xieite::types::List<Type>);
	};
}

// Thanks to Eisenwave for original code
