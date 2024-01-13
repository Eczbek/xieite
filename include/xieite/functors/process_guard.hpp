#ifndef XIEITE_HEADER_FUNCTORS_PROCESS_GUARD
#	define XIEITE_HEADER_FUNCTORS_PROCESS_GUARD

#	include <concepts>
#	include <cstdint>
#	include <functor>
#	include <memory>
#	include <type_traits>
#	include <unordered_map>

namespace xieite::functors {
	class ProcessGuard {
	public:
		template<std::invocable<> Functor>
		ProcessGuard(Functor&& callback) noexcept
		: released(std::make_shared<bool>(false)) {
			struct Lock {
				const std::shared_ptr<bool> released;

				Lock(const std::shared_ptr<bool> released) noexcept
				: released(released) {}

				~Lock() {
					if (!*this->released) {
						std::invoke(callback);
					}
				}
			};
			if constexpr (std::is_pointer_v<Functor>) {
				static std::unordered_map<std::uintptr_t, Lock> locks;
				locks[reinterpret_cast<std::uintptr_t>(callback)] = Lock(this->released);
			} else {
				static Lock lock = Lock(this->released);
			}
		}

		void release() noexcept {
			*this->released = true;
		}

	private:
		std::shared_ptr<bool> released;
	};
}

#endif
