#pragma once

namespace xieite::console {
	struct StyleResetLock {
		StyleResetLock() noexcept = default;

		~StyleResetLock();
	};
}
