export module xieite:is_obj;

import std;

export namespace xieite {
	template<typename T>
	concept is_obj = std::is_object_v<T>;
}
