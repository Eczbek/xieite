export module xieite:segfault;

export namespace xieite {
	void segfault() noexcept {
		*static_cast<volatile int*>(nullptr);
	}
}
