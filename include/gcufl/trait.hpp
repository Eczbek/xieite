#pragma once

#include <concepts>
#include <ostream>


namespace gcufl {
	namespace trait {
		template <typename V>
		concept Streamable = requires(std::ostream& stream, const V& value) {
			{ stream << value } -> std::convertible_to<std::ostream&>;
  		};
	}
}
