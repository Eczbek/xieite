export module xieite:system.segmentationFault;

export namespace xieite::system {
	void segmentationFault() noexcept {
		*static_cast<volatile int*>(nullptr);
	}
}
