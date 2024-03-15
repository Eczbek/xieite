#ifndef XIEITE_HEADER_MEMORY_DETECT_COSMIC_RAY
#	define XIEITE_HEADER_MEMORY_DETECT_COSMIC_RAY

#	include <concepts>
#	include <cstddef>
#	include <cstdint>
#	include <memory>

namespace xieite::memory {
	inline void detectCosmicRay(const std::size_t bytes) noexcept {
		using Array = volatile const std::byte[];
		const std::size_t size = bytes / sizeof(std::intmax_t);
		const std::unique_ptr<Array> detector = std::make_unique<Array>(size);
		for (std::size_t i = 0; !detector[i]; i = (i + 1) % size);
	}
}

#endif
