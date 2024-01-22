#ifndef XIEITE_HEADER_FUNCTORS_PROCESS_GUARD
#	define XIEITE_HEADER_FUNCTORS_PROCESS_GUARD

#	include <concepts>
#	include <cstdint>
#	include <functional>
#	include <memory>
#	include <type_traits>
#	include <unordered_map>
#	include "../functors/function.hpp"

namespace xieite::functors {
	class ProcessGuard {
	public:
		ProcessGuard(const xieite::functors::Function<void()>& callback) noexcept
		: released(std::make_shared<bool>(false)) {
			struct Lock {
				const std::shared_ptr<bool> released;

				Lock(const std::shared_ptr<bool> released) noexcept
				: released(released) {}

				~Lock() {
					if (!*this->released) {
						callback();
					}
				}
			};
			static Lock lock = Lock(this->released);
		}

		void release() noexcept {
			*this->released = true;
		}

	private:
		std::shared_ptr<bool> released;
	};
}

#endif
