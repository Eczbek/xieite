export module xieite:memory.detectCosmicRay;

import std;

export namespace xieite::memory {
	void detectCosmicRay(const std::size_t bytes) noexcept {
		using Array = volatile const std::byte[];
		const std::size_t size = bytes / sizeof(std::intmax_t);
		const std::unique_ptr<Array> detector = std::make_unique<Array>(size);
		for (std::size_t i = 0; !static_cast<bool>(detector[i]); i = (i + 1) % size);
	}
}
