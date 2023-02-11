#include <xieite/errors/segmentationFault.hpp>

void xieite::errors::segmentationFault() noexcept {
	*(volatile int*)(nullptr);
}
