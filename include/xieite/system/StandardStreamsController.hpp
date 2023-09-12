#ifndef XIEITE_HEADER__SYSTEM__STANDARD_STREAMS_CONTROLLER
#	define XIEITE_HEADER__SYSTEM__STANDARD_STREAMS_CONTROLLER

#	include "../macros/SYSTEM_TYPE.hpp"

#	if !XIEITE__SYSTEM_TYPE__UNIX
#		error "System not supported"
#	endif

#	include <cmath>
#	include <cstddef>
#	include <cstdio>
#	include <fcntl.h>
#	include <istream>
#	include <ostream>
#	include <stdio.h>
#	include <string>
#	include <string_view>
#	include <sys/ioctl.h>
#	include <termios.h>
#	include <unistd.h>
#	include "../functors/ScopeGuard.hpp"
#	include "../graphics/Color.hpp"
#	include "../system/BufferPosition.hpp"
#	include "../system/getStreamFile.hpp"

namespace xieite::system {
	template<std::istream& inputStream, std::ostream& outputStream>
	class StandardStreamsController {
	public:
		StandardStreamsController() noexcept
		: inputStreamFile(xieite::system::getStreamFile(inputStream)), inputFileDescriptor(::fileno(this->inputStreamFile)), blockingStatus(::fcntl(this->inputFileDescriptor, F_GETFL)) {
			::tcgetattr(this->inputFileDescriptor, &this->cookedMode);
			this->blocking = !(this->blockingStatus & O_NONBLOCK);
			this->echo = this->cookedMode.c_lflag & ECHO;
			this->canonical = this->cookedMode.c_lflag & ICANON;
			this->signals = (this->cookedMode.c_iflag & IXON) || (this->cookedMode.c_iflag & ICRNL) || (this->cookedMode.c_lflag & IEXTEN) || (this->cookedMode.c_lflag & ISIG);
			this->processing = this->cookedMode.c_oflag & OPOST;
			this->update();
		}

		~StandardStreamsController() {
			this->resetModes();
			this->resetStyles();
		}

		template<std::istream& otherInputStream, std::ostream& otherOutputStream>
		void operator=(const xieite::system::StandardStreamsController<otherInputStream, otherOutputStream>&) = delete;

		void setInputBlocking(const bool value) noexcept {
			if (this->blocking != value) {
				this->blocking = value;
				this->update();
			}
		}

		void setInputEcho(const bool value) noexcept {
			if (this->echo != value) {
				this->echo = value;
				this->update();
			}
		}

		void setInputCanonical(const bool value) noexcept {
			if (this->canonical != value) {
				this->canonical = value;
				this->update();
			}
		}

		void setInputSignals(const bool value) noexcept {
			if (this->signals != value) {
				this->signals = value;
				this->update();
			}
		}

		void setOutputProcessing(const bool value) noexcept {
			if (this->processing != value) {
				this->processing = value;
				this->update();
			}
		}

		void setForegroundColor(const xieite::graphics::Color& color) noexcept {
			outputStream << "\x1B[38;2;" << static_cast<int>(color.red) << ';' << static_cast<int>(color.green) << ';' << static_cast<int>(color.blue) << 'm';
		}

		void resetForegroundColor() noexcept {
			outputStream << "\x1B[38m";
		}

		void setBackgroundColor(const xieite::graphics::Color& color) noexcept {
			outputStream << "\x1B[48;2;" << static_cast<int>(color.red) << ';' << static_cast<int>(color.green) << ';' << static_cast<int>(color.blue) << 'm';
		}

		void resetBackgroundColor() noexcept {
			outputStream << "\x1B[48m";
		}

		void setTextBold(const bool value) noexcept {
			outputStream << "\x1B[" << (21 - value * 20) << 'm';
		}

		void setTextItalic(const bool value) noexcept {
			outputStream << "\x1B[" << (23 - value * 20) << 'm';
		}

		void setTextUnderline(const bool value) noexcept {
			outputStream << "\x1B[" << (24 - value * 20) << 'm';
		}

		void setTextBlinking(const bool value) noexcept {
			outputStream << "\x1B[" << (25 - value * 20) << 'm';
		}

		void setColorsSwapped(const bool value) noexcept {
			outputStream << "\x1B[" << (27 - value * 20) << 'm';
		}

		void setTextVisible(const bool value) noexcept {
			outputStream << "\x1B[" << (8 + value * 20) << 'm';
		}

		void setTextStrikethrough(const bool value) noexcept {
			outputStream << "\x1B[" << (29 - value * 20) << 'm';
		}

		void resetStyles() noexcept {
			outputStream << "\x1B[0m";
		}
		
		void resetModes() noexcept {
			::fcntl(this->inputFileDescriptor, F_SETFL, this->blockingStatus);
			::tcsetattr(this->inputFileDescriptor, TCSANOW, &this->cookedMode);
		}

		void clearScreen() noexcept {
			outputStream << "\x1B[2J";
		}

		void clearLine() noexcept {
			outputStream << "\x1B[2K";
		}

		xieite::system::BufferPosition getCursorPosition() noexcept {
			const bool canonical = this->canonical;
			this->setInputCanonical(false);
			outputStream << "\x1B[6n";
			xieite::system::BufferPosition position;
			std::fscanf(this->inputStreamFile, "\x1B[%i;%iR", &position.row, &position.column);
			this->setInputCanonical(canonical);
			return xieite::system::BufferPosition(position.row - 1, position.column - 1);
		}

		void setCursorPosition(const xieite::system::BufferPosition position) noexcept {
			outputStream << "\x1B[" << (position.row + 1) << ';' << (position.column + 1) << 'H';
		}

		void moveCursorPosition(const xieite::system::BufferPosition difference) noexcept {
			if (difference.row) {
				outputStream << "\x1B[" << std::abs(difference.row) << "CD"[difference.row < 0];
			}
			if (difference.column) {
				outputStream << "\x1B[" << std::abs(difference.column) << "BA"[difference.column < 0];
			}
		}

		void setCursorVisible(const bool value) noexcept {
			outputStream << "\x1B[?25" << "lh"[value];
		}

		void setCursorAlternative(const bool value) noexcept {
			outputStream << "\x1b[" << static_cast<char>(117 - value * 2);
		}

		void setScreenAlternative(const bool value) noexcept {
			outputStream << "\x1B[?47" << "lh"[value];
		}

		xieite::system::BufferPosition getScreenSize() noexcept {
			::winsize size;
			::ioctl(this->inputFileDescriptor, TIOCGWINSZ, &size);
			return xieite::system::BufferPosition(size.ws_row, size.ws_col);
		}

		char readCharacter() noexcept {
			const bool canonical = this->canonical;
			this->setInputCanonical(false);
			const char input = inputStream.get();
			this->setInputCanonical(canonical);
			return input;	
		}

		std::string readString() noexcept {
			const bool blocking = this->blocking;
			const bool canonical = this->canonical;
			this->setInputBlocking(false);
			this->setInputCanonical(false);
			std::string input;
			char buffer;
			while (inputStream.get(buffer)) {
				input += buffer;
			}
			inputStream.clear();
			this->setInputBlocking(blocking);
			this->setInputCanonical(canonical);
			return input;
		}
		
		xieite::system::BufferPosition readArrow() noexcept {
			const char first = this->readCharacter();
			if (first == '\x1B') {
				xieite::functors::ScopeGuard scopeGuard = xieite::functors::ScopeGuard([this, blocking = this->blocking] {
					this->setInputBlocking(blocking);
				});
				this->setInputBlocking(false);
				if (this->readCharacter() == '[') {
					const char direction = this->readCharacter();
					switch (direction) {
					case 'A':
						return xieite::system::BufferPosition(-1, 0);
					case 'B':
						return xieite::system::BufferPosition(1, 0);
					case 'C':
						return xieite::system::BufferPosition(0, 1);
					case 'D':
						return xieite::system::BufferPosition(0, -1);
					}
					inputStream.putback(direction);
				}
				inputStream.putback('[');
			}
			inputStream.putback(first);
			return xieite::system::BufferPosition(0, 0);
		}

		void putBackString(const std::string_view value) noexcept {
			for (std::size_t i = value.size(); i--;) {
				inputStream.putback(value[i]);
			}
		}

		void backspace(const std::size_t count) noexcept {
			if (count) {
				outputStream << "\x1B[" << count << 'D' << std::string(count, ' ') << "\x1B[" << count << 'D';
			}
		}

	private:
		std::FILE* const inputStreamFile;
		const int inputFileDescriptor;

		int blockingStatus;
		termios cookedMode;

		bool blocking;
		bool echo;
		bool canonical;
		bool signals;
		bool processing;

		void update() noexcept {
			::fcntl(this->inputFileDescriptor, F_SETFL, this->blockingStatus | (O_NONBLOCK * !this->blocking));
			::termios rawMode = this->cookedMode;
			rawMode.c_iflag &= ~((ICRNL * !this->signals) | (IXON * !this->signals));
			rawMode.c_lflag &= ~((ECHO * !this->echo) | (ICANON * !this->canonical) | (IEXTEN * !this->signals) | (ISIG * !this->signals));
			rawMode.c_oflag &= ~(OPOST * !this->processing);
			::tcsetattr(this->inputFileDescriptor, TCSANOW, &rawMode);
		}
	};
}

#endif
