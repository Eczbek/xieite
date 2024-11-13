export module xieite:is_no_padding;

import std;

export namespace xieite {
	template<typename T>
	concept is_unique_obj_repr = std::has_unique_object_representations_v<T>;
}
