#ifndef XIEITE_HEADER_SYSTEM_STANDARDSTREAMSCONTROLLER
#	define XIEITE_HEADER_SYSTEM_STANDARDSTREAMSCONTROLLER

#	include "../macros/SYSTEM_TYPE.hpp"

#	if XIEITE_SYSTEM_TYPE_UNIX
#		include <cmath>
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
#		include "../graphics/Color.hpp"
#		include "../math/baseTo.hpp"
#		include "../memory/bufferSize.hpp"
#		include "../system/BufferPosition.hpp"
#		include "../system/getStreamFile.hpp"

namespace xieite::system {
	template<std::istream& inputStream, std::ostream& outputStream>
	class StandardStreamsController {
	public:
		StandardStreamsController() noexcept
		: inputStreamFile(xieite::system::getStreamFile(inputStream)), inputFileDescriptor(::fileno(this->inputStreamFile)), blockingStatus(::fcntl(this->inputFileDescriptor, F_GETFL)), blocking(true), echo(true), canonical(true), signals(true), processing(true) {
			::tcgetattr(this->inputFileDescriptor, &this->cookedMode);
			this->update();
		}

		~StandardStreamsController() {
			::fcntl(this->inputFileDescriptor, F_SETFL, this->blockingStatus);
			::tcsetattr(this->inputFileDescriptor, TCSANOW, &this->cookedMode);
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

		void setTextColor(const xieite::graphics::Color& color) noexcept {
			outputStream << "\x1B[38;2;" << xieite::math::baseTo(10, color.red) << ';' << xieite::math::baseTo(10, color.green) << ';' << xieite::math::baseTo(10, color.blue) << 'm';
			outputStream.flush();
		}

		void resetTextColor() noexcept {
			outputStream << "\x1B[38m";
			outputStream.flush();
		}

		void setHighlightColor(const xieite::graphics::Color& color) noexcept {
			outputStream << "\x1B[48;2;" << xieite::math::baseTo(10, color.red) << ';' << xieite::math::baseTo(10, color.green) << ';' << xieite::math::baseTo(10, color.blue) << 'm';
			outputStream.flush();
		}

		void resetHighlightColor() noexcept {
			outputStream << "\x1B[48m";
			outputStream.flush();
		}

		void setTextBold(const bool value) noexcept {
			outputStream << "\x1B[" << (21 - value * 20) << 'm';
			outputStream.flush();
		}

		void setTextItalic(const bool value) noexcept {
			outputStream << "\x1B[" << (23 - value * 20) << 'm';
			outputStream.flush();
		}

		void setTextUnderline(const bool value) noexcept {
			outputStream << "\x1B[" << (24 - value * 20) << 'm';
			outputStream.flush();
		}

		void setTextBlinking(const bool value) noexcept {
			outputStream << "\x1B[" << (25 - value * 20) << 'm';
			outputStream.flush();
		}

		void setColorsSwapped(const bool value) noexcept {
			outputStream << "\x1B[" << (27 - value * 20) << 'm';
			outputStream.flush();
		}

		void setTextVisible(const bool value) noexcept {
			outputStream << "\x1B[" << (8 + value * 20) << 'm';
			outputStream.flush();
		}

		void setTextStrikethrough(const bool value) noexcept {
			outputStream << "\x1B[" << (29 - value * 20) << 'm';
			outputStream.flush();
		}

		void resetStyles() noexcept {
			outputStream << "\x1B[0m";
			outputStream.flush();
		}

		void clearScreen() noexcept {
			outputStream << "\x1B[2J";
			outputStream.flush();
		}

		void clearLine() noexcept {
			outputStream << "\x1B[2K";
			outputStream.flush();
		}

		[[nodiscard]]
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
			outputStream << "\x1B[" << xieite::math::baseTo(10, position.row + 1) << ';' << xieite::math::baseTo(10, position.column + 1) << 'H';
			outputStream.flush();
		}

		void moveCursorPosition(const xieite::system::BufferPosition difference) noexcept {
			if (difference.row) {
				outputStream << "\x1B[" << std::abs(difference.row) << "CD"[difference.row < 0];
			}
			if (difference.column) {
				outputStream << "\x1B[" << std::abs(difference.column) << "BA"[difference.column < 0];
			}
			outputStream.flush();
		}

		void setCursorVisible(const bool value) noexcept {
			outputStream << "\x1B[?25" << (value ? 'h' : 'l');
			outputStream.flush();
		}

		void setCursorAlternative(const bool value) noexcept {
			outputStream << "\x1B " << (8 - value);
			outputStream.flush();
		}

		void setScreenAlternative(const bool value) noexcept {
			outputStream << "\x1B[?47" << (value ? 'h' : 'l');
			outputStream.flush();
		}

		[[nodiscard]]
		xieite::system::BufferPosition getScreenSize() noexcept {
			::winsize size;
			::ioctl(this->inputFileDescriptor, TIOCGWINSZ, &size);
			return xieite::system::BufferPosition(size.ws_row, size.ws_col);
		}

		[[nodiscard]]
		char readCharacter() noexcept {
			const bool blocking = this->blocking;
			const bool canonical = this->canonical;
			this->setInputBlocking(false);
			this->setInputCanonical(false);
			const char input = inputStream.get();
			this->setInputBlocking(blocking);
			this->setInputCanonical(canonical);
			return input;	
		}

		[[nodiscard]]
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

		termios cookedMode;
		int blockingStatus;

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

#	else
#		error "System not supported"
#	endif

#endif
