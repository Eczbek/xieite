#ifndef XIEITE_HEADER_FUNCTIONS_PROCESSGUARD
#	define XIEITE_HEADER_FUNCTIONS_PROCESSGUARD

#	include <concepts>
#	include <memory>

namespace xieite::functions {
	class ProcessGuard {
	public:
		template<std::invocable<> Invocable>
		ProcessGuard(const Invocable& callback) noexcept
		: released(std::make_shared<bool>(false)) {
			static const Invocable callbackCopy = callback;
			static const std::shared_ptr<bool> released = this->released;
			static const struct Lock final {
				~Lock() {
					if (!*released) {
						callbackCopy();
					}
				}
			} lock;
		}

		void release() noexcept {
			*this->released = true;
		}

	private:
		std::shared_ptr<bool> released;
	};
}

#endif
