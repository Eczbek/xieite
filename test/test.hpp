#define TEST(...) ([] { return (__VA_ARGS__) ? "\x1B[92mPASSED\x1B[0m "sv #__VA_ARGS__ : "\x1B[91mFAILED\x1B[0m "sv #__VA_ARGS__; })()
