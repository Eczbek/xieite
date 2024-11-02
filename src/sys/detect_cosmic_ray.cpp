export module xieite:detect_cosmic_ray;

import std;

export namespace xieite {
	void detect_cosmic_ray(std::size_t bytes) noexcept {
		using Array = volatile const std::byte[];
		const std::size_t size = bytes / sizeof(std::intmax_t);
		const auto detector = std::make_unique<Array>(size);
		std::size_t i = 0;
		while (!detector[++i %= size]);
	}
}
