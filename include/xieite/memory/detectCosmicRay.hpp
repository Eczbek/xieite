#ifndef XIEITE_HEADER__MEMORY__DETECT_COSMIC_RAY
#	define XIEITE_HEADER__MEMORY__DETECT_COSMIC_RAY

#	include <concepts>
#	include <cstddef>
#	include <memory>

namespace xieite::memory {
	template<std::unsigned_integral Chunk = std::uintmax_t>
	constexpr void detectCosmicRay(const std::size_t bytes) noexcept {
		const std::size_t size = bytes / sizeof(Chunk);
		const auto detector = std::make_unique<volatile const Chunk[]>(size);
		for (std::size_t i = 0; !detector[i]; i = (i + 1) % size);
	}
}

#endif
