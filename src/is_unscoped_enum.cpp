export module xieite:is_unscoped_enum;

import std;

export namespace xieite {
	template<typename T>
	concept is_unscoped_enum = std::is_enum_v<T> && !std::is_scoped_enum_v<T>;
}
