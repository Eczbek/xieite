#ifndef XIEITE_HEADER__TYPES__LIST
#	define XIEITE_HEADER__TYPES__LIST

#	include <cmath>
#	include <concepts>
#	include <tuple>
#	include <type_traits>
#	include <utility>

namespace xieite::types {
	template<typename... Types>
	class List {
	private:
		template<typename... UniqueTypes>
		struct UniqueHelper {
			using Data = xieite::types::List<UniqueTypes...>;

			template<typename Type>
			consteval std::conditional_t<(... || std::same_as<UniqueTypes, Type>), xieite::types::List<Types...>::UniqueHelper<UniqueTypes...>, xieite::types::List<Types...>::UniqueHelper<UniqueTypes..., Type>> operator->*(xieite::types::List<Types...>::UniqueHelper<Type>) const noexcept;
		};

		template<std::size_t offset, std::size_t... indices>
		static consteval xieite::types::List<std::tuple_element_t<indices + offset, std::tuple<Types...>>...> sliceHelper(std::index_sequence<indices...>) noexcept;
		
		template<std::size_t... indices>
		static consteval xieite::types::List<std::tuple_element_t<sizeof...(Types) - indices - 1, std::tuple<Types...>>...> reverseHelper(std::index_sequence<indices...>) noexcept;

	public:
		using Data = std::tuple<Types...>;

		template<typename... OtherTypes>
		using Append = xieite::types::List<Types..., OtherTypes...>;

		template<typename... OtherTypes>
		using Prepend = xieite::types::List<OtherTypes..., Types...>;

		using Unique = decltype((xieite::types::List<Types...>::UniqueHelper<>()->*...->*xieite::types::List<Types...>::UniqueHelper<Types>()))::Data;

		template<std::size_t start, std::size_t end = sizeof...(Types)>
		using Slice = decltype(xieite::types::List<Types...>::sliceHelper<std::min(start, end)>(std::make_index_sequence<std::min(std::max(start, end), sizeof...(Types)) - std::min(std::min(start, end), sizeof...(Types))>()));

		using Reverse = decltype(xieite::types::List<Types...>::reverseHelper(std::make_index_sequence<sizeof...(Types)>()));
	};
}

// Thanks to Eisenwave and eightfold for help

#endif
