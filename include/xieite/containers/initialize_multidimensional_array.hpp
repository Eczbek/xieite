#ifndef XIEITE_HEADER_CONTAINERS_INITIALIZE_MULTIDIMENSIONAL_ARRAY
#	define XIEITE_HEADER_CONTAINERS_INITIALIZE_MULTIDIMENSIONAL_ARRAY

#	include <array>
#	include <cstddef>
#	include <initializer_list>
#	include <utility>
#	include "../types/dynamic_matrix.hpp"
#	include "../types/fixed_matrix.hpp"

namespace xieite::containers {
	template<typename Value_>
	[[nodiscard]] constexpr Value_ initializeMultidimensionalArray(const Value_& value) noexcept {
		return value;
	}

	template<typename Value_, std::size_t firstDimension_, std::size_t... restDimensions_>
	[[nodiscard]] constexpr xieite::types::FixedMatrix<std::array, Value_, firstDimension_, restDimensions_...> initializeMultidimensionalArray(const xieite::types::DynamicMatrix<std::initializer_list, Value_, sizeof...(restDimensions_) + 1> list) noexcept {
		return ([&list]<std::size_t... i_>(std::index_sequence<i_...>) {
			auto iterator = list.begin();
			return std::array<xieite::types::FixedMatrix<std::array, Value_, restDimensions_...>, firstDimension_> {
				(void(i_), xieite::containers::initializeMultidimensionalArray<Value_, restDimensions_...>(*iterator++))...
			};
		})(std::make_index_sequence<firstDimension_>());
	}
}

#endif
