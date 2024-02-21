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
		template<auto = [] {}>
		ProcessGuard(const xieite::functors::Function<void()>& callback) noexcept
		: released(std::make_shared<bool>(false)) {
			struct Guard {
				const std::shared_ptr<bool> released;
				const xieite::functors::Function<void()>& callback;

				Guard(const std::shared_ptr<bool> released, const xieite::functors::Function<void()>& callback) noexcept
				: released(released), callback(callback) {}

				~Guard() {
					if (!*this->released) {
						this->callback();
					}
				}
			};

			static Guard _ = Guard(this->released, callback);
		}

		void release() noexcept {
			*this->released = true;
		}

	private:
		std::shared_ptr<bool> released;
	};
}

#endif
