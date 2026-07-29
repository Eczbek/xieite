#ifndef DETAIL_XTE_HEADER_IO_FILE_MODE
#	define DETAIL_XTE_HEADER_IO_FILE_MODE
#
#	include "../util/number_types.hpp"
#	include <utility>

namespace xte {
	struct file_mode {
	private:
		xte::uz _mask;
	
		[[nodiscard]] constexpr file_mode(xte::uz mask) noexcept
		: _mask(mask) {}

	public:
		[[nodiscard]] constexpr file_mode() noexcept
		: _mask(xte::file_mode::none) {}

		static const xte::file_mode none;
		static const xte::file_mode read;
		static const xte::file_mode write;
		static const xte::file_mode overwrite;
		static const xte::file_mode append;
		static const xte::file_mode read_write;
		static const xte::file_mode read_overwrite;
		static const xte::file_mode read_append;
		
		[[nodiscard]] explicit(false) constexpr operator xte::uz() const noexcept {
			return this->_mask;
		}

		[[nodiscard]] explicit(false) constexpr operator const char*() const noexcept;
	};

	constexpr xte::file_mode xte::file_mode::none = xte::file_mode(0b0000);
	constexpr xte::file_mode xte::file_mode::read = xte::file_mode(0b0001);
	constexpr xte::file_mode xte::file_mode::write = xte::file_mode(0b0010);
	constexpr xte::file_mode xte::file_mode::overwrite = xte::file_mode(0b0110);
	constexpr xte::file_mode xte::file_mode::append = xte::file_mode(0b1000);
	constexpr xte::file_mode xte::file_mode::read_write = xte::file_mode(0b0011);
	constexpr xte::file_mode xte::file_mode::read_overwrite = xte::file_mode(0b0111);
	constexpr xte::file_mode xte::file_mode::read_append = xte::file_mode(0b1001);

	constexpr xte::file_mode::operator const char*() const noexcept {
		switch (this->_mask) {
			case xte::file_mode::read:
				return "r";
			case xte::file_mode::write:
				return "wx";
			case xte::file_mode::overwrite:
				return "w";
			case xte::file_mode::append:
				return "a";
			case xte::file_mode::read_write:
				return "r+";
			case xte::file_mode::read_overwrite:
				return "wx+";
			case xte::file_mode::read_append:
				return "a+";
			default:
				std::unreachable();
		}
	}
}

#endif
