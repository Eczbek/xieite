export module xieite:is_final;

import std;

export namespace xieite {
	template<typename T>
	concept is_final = std::is_final_v<T>;
}
