export module xieite:is_scoped_enum;

import std;

export namespace xieite {
	template<typename T>
	concept is_scoped_enum = std::is_scoped_enum_v<T>;
}
