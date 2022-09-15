#pragma once

#include <ostream>
#include <type_traits>


namespace gcufl::concepts {

	template<typename T>
	concept Streamable = requires(std::ostream& ostream, const T& value) {
		{ ostream << value } -> std::convertible_to<std::ostream&>;
	};
}
