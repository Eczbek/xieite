#ifndef XIEITE_HEADER_TYPES_LIST
#	define XIEITE_HEADER_TYPES_LIST

#	include <concepts>
#	include <tuple>
#	include <type_traits>

namespace xieite::types {
	template<typename... Types>
	struct List {
		using Data = std::tuple<Types...>;

		template<typename Type>
		constexpr std::conditional_t<(std::same_as<Types, Type> || ...), xieite::types::List<Types...>, xieite::types::List<Types..., Type>> operator->*(xieite::types::List<Type>) const noexcept;
	};
}

// Thanks to Eisenwave for original code

#endif
