export module xieite:is_enum;

import std;

export namespace xieite {
	template<typename T>
	concept is_enum = std::is_enum_v<T>;
}
