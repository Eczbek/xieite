#pragma once

#include <cstddef>
#include <vector>

namespace xieite::system {
	inline void detectCosmicRay(const std::size_t detectionBytes) noexcept {
		const std::vector<std::size_t> detector(detectionBytes / sizeof(std::size_t), 0);
		bool detected = false;
		do {
			volatile const int undefinedBehaviorPreventionDummy = 0;
			for (const std::size_t bits : detector) {
				detected += bits;
			}
		} while (!detected);
	}
}
