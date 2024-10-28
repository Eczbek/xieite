export module xieite:is_complete;

export namespace xieite {
	template<typename T, auto tag = [] {}>
	concept is_complete = (tag, !!sizeof(T));
}
