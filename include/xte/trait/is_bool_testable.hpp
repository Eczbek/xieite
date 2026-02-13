#ifndef DETAIL_XTE_HEADER_TRAIT_IS_BOOL_TESTABLE
#	define DETAIL_XTE_HEADER_TRAIT_IS_BOOL_TESTABLE
#
#	include "../preproc/fwd.hpp"

namespace xte {
	template<typename T>
	concept is_bool_testable = requires (T&& x) {
		static_cast<bool>(XTE_FWD(x));
		static_cast<bool>(!XTE_FWD(x));
		static_cast<void(*)(bool)>(nullptr)(XTE_FWD(x));
		static_cast<void(*)(bool)>(nullptr)(!XTE_FWD(x));
		// TODO: Check `operator&&()` and `operator||()` to best ability
	};
}

#endif

// https://timsong-cpp.github.io/cppwp/n4950/concept.booleantestable
