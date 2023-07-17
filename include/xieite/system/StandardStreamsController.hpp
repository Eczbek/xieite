#ifndef XIEITE_HEADER_SYSTEM_STANDARDSTREAMSCONTROLLER
#	define XIEITE_HEADER_SYSTEM_STANDARDSTREAMSCONTROLLER

#	include <xieite/macros/SYSTEM_TYPE.hpp>

#	if XIEITE_SYSTEM_TYPE_UNIX
#		include <cstddef>
#		include <cstdio>
#		include <fcntl.h>
#		include <istream>
#		include <ostream>
#		include <stdio.h>
#		include <string>
#		include <string_view>
#		include <sys/ioctl.h>
#		include <termios.h>
#		include <unistd.h>
#		include <xieite/graphics/Color.hpp>
#		include <xieite/math/baseTo.hpp>
#		include <xieite/memory/bufferSize.hpp>
#		include <xieite/system/OutputPosition.hpp>
#		include <xieite/system/getStreamFile.hpp>

namespace xieite::system {
	template<std::istream& inputStream, std::ostream& outputStream>
	class StandardStreamsController {
	public:
		StandardStreamsController() noexcept
		: inputStreamFile(xieite::system::getStreamFile(inputStream)), inputFileDescriptor(fileno(this->inputFile)), blockingMode(fcntl(this->inputFileDescriptor, F_GETFL)), blocking(true), echo(false), canonical(false), signals(false), processing(false) {
			tcgetattr(this->inputFileDescriptor, &this->cookedMode);
			this->update();
		}

		~StandardStreamsController() {
			fcntl(this->inputFileDescriptor, F_SETFL, this->blockingMode);
			tcsetattr(this->inputFileDescriptor, TCSANOW, &this->cookedMode);
			this->resetStyles();
		}

		auto operator=(const xieite::system::StandardStreamsController<auto, auto>&) = delete;

		void setInputBlocking(const bool value) noexcept {
			this->blocking = value;
			this->update();
		}

		void setInputEcho(const bool value) noexcept {
			this->echo = value;
			this->update();
		}

		void setInputCanonical(const bool value) noexcept {
			this->canonical = value;
			this->update();
		}

		void setInputSignals(const bool value) noexcept {
			this->signals = value;
			this->update();
		}

		void setInputProcessing(const bool value) noexcept {
			this->processing = value;
			this->update();
		}

		void setTextColor(const xieite::graphics::Color& color) noexcept {
			outputStream << "[38;2;" << xieite::math::baseTo(10, color.red) << ';' << xieite::math::baseTo(10, color.green) << ';' << xieite::math::baseTo(10, color.blue) << 'm';
		}

		void resetTextColor() noexcept {
			outputStream << "[38m";
		}

		void setHighlightColor(const xieite::graphics::Color& color) noexcept {
			outputStream << "[48;2;" << xieite::math::baseTo(10, color.red) << ';' << xieite::math::baseTo(10, color.green) << ';' << xieite::math::baseTo(10, color.blue) << 'm';
		}

		void resetHighlightColor() noexcept {
			outputStream << "[48m";
		}

		void setTextBold(const bool value) noexcept {
			outputStream << (value ? "[1m" : "[21m");
		}

		void setTextItalic(const bool value) noexcept {
			outputStream << (value ? "[3m" : "[23m");
		}

		void setTextUnderline(const bool value) noexcept {
			outputStream << (value ? "[4m" : "[24m");
		}

		void setTextBlinking(const bool value) noexcept {
			outputStream << (value ? "[5m" : "[25m");
		}

		void setColorsSwapped(const bool value) noexcept {
			outputStream << (value ? "[7m" : "[27m");
		}

		void setTextVisible(const bool value) noexcept {
			outputStream << (value ? "[28m" : "[8m");
		}

		void setTextStrikethrough(const bool value) noexcept {
			outputStream << (value ? "[9m" : "[29m");
		}

		void resetStyles() noexcept {
			outputStream << "[0m";
		}

		void clearScreen() noexcept {
			outputStream << "[2J";
		}

		void clearLine() noexcept {
			outputStream << "[2K";
		}

		[[nodiscard]]
		xieite::system::OutputPosition getCursorPosition() noexcept {
			outputStream << "[6n";
			xieite::system::OutputPosition position = xieite::system::OutputPosition(0, 0);
			std::fscanf(this->inputStreamFile, "[%i;%iR", &position.row, &position.column);
			return xieite::system::OutputPosition(position.row - 1, position.column - 1);
		}

		void setCursorPosition(const xieite::system::OutputPosition position) noexcept {
			outputStream << "[" << xieite::math::baseTo(10, position.row + 1) << ';' << xieite::math::baseTo(10, position.column + 1) << 'H';
		}

		void setCursorVisible(const bool value) noexcept {
			outputStream << (value ? "[?25h" : "[?25l");
		}

		void setCursorAlternative(const bool value) noexcept {
			outputStream << (value ? "[s" : "[u");
		}

		void setScreenAlternative(const bool value) noexcept {
			outputStream << (value ? "[?47h" : "[?47l");
		}

		[[nodiscard]]
		xieite::system::OutputPosition getScreenSize() noexcept {
			winsize size;
			ioctl(this->inputFileDescriptor, TIOCGWINSZ, &size);
			return xieite::system::OutputPosition(size.ws_row, size.ws_col);
		}

		[[nodiscard]]
		char readCharacter() noexcept {
			const bool blocking = this->blocking;
			if (blocking) {
				this->setInputBlocking(false);
			}
			char input = 0;
			read(this->inputFileDescriptor, &input, 1);
			if (blocking) {
				this->setInputBlocking(true);
			}
			return input;	
		}

		[[nodiscard]]
		std::string readString() noexcept {
			const bool blocking = this->blocking;
			if (blocking) {
				this->setInputBlocking(false);
			}
			std::string result;
			while (true) {
				std::string buffer = std::string(xieite::memory::bufferSize, '\0');
				read(this->inputFileDescriptor, buffer.data(), buffer.size());
				if (!buffer.size()) {
					break;
				}
				result += buffer;
			}
			if (blocking) {
				this->setInputBlocking(true);
			}
			return result;
		}

		void putBackString(const std::string_view value) noexcept {
			for (std::size_t i = value.size(); i--;) {
				inputStream.putback(value[i]);
			}
		}

	private:
		std::FILE* const inputStreamFile;
		const int inputFileDescriptor;;

		termios cookedMode;
		int blockingMode;

		bool blocking;
		bool echo;
		bool canonical;
		bool signals;
		bool processing;

		void update() noexcept {
			fcntl(this->inputFileDescriptor, F_SETFL, this->blockingMode | (O_NONBLOCK * !this->blocking));
			termios rawMode = this->cookedMode;
			rawMode.c_iflag &= ~((ICRNL * !this->signals) | (IXON * !this->signals));
			rawMode.c_lflag &= ~((ECHO * !this->echo) | (ICANON * !this->canonical) | (IEXTEN * !this->signals) | (ISIG * !this->signals));
			rawMode.c_oflag &= ~(OPOST * !this->processing);
			tcsetattr(this->inputFileDescriptor, TCSANOW, &rawMode);
		}
	};
}

#	else
#		error "System not supported"
#	endif

#endif
