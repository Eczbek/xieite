export module xieite:system.segmentationFault;

export namespace xieite::system {
	inline void segmentationFault() noexcept {
		*static_cast<volatile int*>(nullptr);
	}
}

// TODO: Remove `inline` once wreien fixes related bug next week
