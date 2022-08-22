#pragma once


namespace gcufl {
	enum class os {
		Windows,
		Mac,
		Unix
	};

#if defined(_WIN32) || defined(__WINDOWS__)
	constexpr auto thisOS = gcufl::os::Windows;
#elif defined(__APPLE__) || defined(__MACH__)
	constexpr auto thisOS = gcufl::os::Mac;
#elif defined(__unix__) || defined(__unix)
	constexpr auto thisOS = gcufl::os::Unix;
#endif
}
