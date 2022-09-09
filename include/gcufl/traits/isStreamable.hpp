#pragma once

#include <gcufl/concepts/Streamable.hpp>


namespace gcufl::traits {
	template <typename T>
	constexpr bool isStreamable = gcufl::concepts::Streamable<T>;
}
