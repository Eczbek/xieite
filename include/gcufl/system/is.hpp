#pragma once

#include <gcufl/system/Type.hpp>


namespace gcufl::system {
	template<gcufl::system::Type>
	constexpr bool is = false;

#if defined(_WIN32) || defined(__WINDOWS__)
	template<>
	constexpr bool is<gcufl::system::Type::Windows> = true;
#endif

#if defined(__APPLE__) || defined(__MACH__)
	template<>
	constexpr bool is<gcufl::system::Type::Mac> = true;
#endif

#if defined(__unix__) || defined(__unix)
	template<>
	constexpr bool is<gcufl::system::Type::Unix> = true;
#endif
}
