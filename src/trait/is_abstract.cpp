export module xieite:is_abstract;

import std;

export namespace xieite {
	template<typename T>
	concept is_abstract = std::is_abstract_v<T>;
}
