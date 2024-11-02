export module xieite:is_class;

import std;

export namespace xieite {
	template<typename T>
	concept is_class = std::is_class_v<T>;
}
