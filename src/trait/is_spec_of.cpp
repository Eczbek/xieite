export module xieite:is_spec;

import std;

export namespace xieite {
	template<typename T, template<typename...> typename M>
	concept is_spec = requires {
		([]<typename... Args>(const M<Args...>&) {})(std::declval<T>());
	};
}

// TODO: Remove after `std::specialization_of` is implemented
