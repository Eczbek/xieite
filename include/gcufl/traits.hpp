#pragma once

#include <concepts>
#include <ostream>


namespace gcufl {
	namespace traits {
		template <typename V>
		concept Streamable = requires(std::ostream& stream, const V& value) {
			{ stream << value } -> std::convertible_to<std::ostream&>;
  		};
	}
}
