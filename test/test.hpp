#pragma once

#include <string_view>

using std::literals::operator""sv;

#define TEST(...) \
	([] -> bool { \
		return (__VA_ARGS__) \
			? "\x1B[92mPASSED\x1B[0m "sv #__VA_ARGS__ \
			: "\x1B[91mFAILED\x1B[0m "sv #__VA_ARGS__; \
	})()
