#ifndef DETAIL_XIEITE_HEADER_SYS_DETECT_COSMIC_RAY
#	define DETAIL_XIEITE_HEADER_SYS_DETECT_COSMIC_RAY
#
#	include <cstddef>
#	include <cstdint>
#	include <memory>

namespace xieite {
	inline void detect_cosmic_ray(std::size_t bytes) noexcept {
		const std::size_t size = bytes / sizeof(std::uintmax_t);
		const auto detector = std::make_unique<volatile const std::uintmax_t[]>(size);
		for (std::size_t i = 0; !detector[++i %= size];);
	}
}

#endif
