#pragma once


namespace gcufl::os {
	enum class type {
		Windows,
		Mac,
		Unix
	};

	template <gcufl::os::type>
	constexpr bool is = false;

#if defined(_WIN32) || defined(__WINDOWS__)
	template <>
	constexpr bool is<gcufl::os::type::Windows> = true;
#endif

#if defined(__APPLE__) || defined(__MACH__)
	template <>
	constexpr bool is<gcufl::os::type::Mac> = true;
#endif

#if defined(__unix__) || defined(__unix)
	template <>
	constexpr bool is<gcufl::os::type::Unix> = true;
#endif
}
