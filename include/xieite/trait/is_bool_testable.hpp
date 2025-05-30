#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_BOOL_TESTABLE
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_BOOL_TESTABLE
#
#	include "../pp/fwd.hpp"

namespace xieite {
	template<typename T>
	concept is_bool_testable = requires(T&& x) {
		static_cast<bool>(XIEITE_FWD(x));
		static_cast<bool>(!XIEITE_FWD(x));
		static_cast<void(*)(bool)>(nullptr)(XIEITE_FWD(x));
		static_cast<void(*)(bool)>(nullptr)(!XIEITE_FWD(x));
		// TODO: Check `operator&&()` and `operator||()` to best ability
	};
}

#endif

// https://timsong-cpp.github.io/cppwp/n4950/concept.booleantestable
