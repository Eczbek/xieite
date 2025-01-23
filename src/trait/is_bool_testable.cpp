module;

#include <xieite/fwd.hpp>

export module xieite:is_bool_testable;

export namespace xieite {
	template<typename T>
	concept is_bool_testable = requires(T&& x) {
		static_cast<bool>(XIEITE_FWD(x));
		static_cast<bool>(!XIEITE_FWD(x));
		static_cast<void(*)(bool)>(nullptr)(XIEITE_FWD(x));
		static_cast<void(*)(bool)>(nullptr)(!XIEITE_FWD(x));
	};
}

// TODO: Check `operator&&` and `operator||` to best ability
// https://timsong-cpp.github.io/cppwp/n4950/concept.booleantestable
