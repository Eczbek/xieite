export module xieite:is_derivable;

import std;

export namespace xieite {
	template<typename T>
	concept is_derivable = !std::is_final_v<T>;
}
