export module xieite:is_m_obj_ptr;

import std;

export namespace xieite {
	template<typename T>
	concept is_m_obj_ptr = std::is_member_object_pointer_v<T>;
}
