module;

#include <xieite/platform.hpp>

#if XIEITE_PLATFORM_TYPE_UNIX
#	include <fcntl.h>
#	include <sys/ioctl.h>
#	include <termios.h>
#	include <unistd.h>
#else
#	warning "unsupported platform"
#endif

export module xieite:streams.StandardHandle;

import std.compat;
import :functors.ScopeGuard;
import :math.stringify;
import :streams.Color;
import :streams.Key;
import :streams.Position;
import :streams.read;

export namespace xieite::streams {
	struct StandardHandle {
	public:
		std::FILE* inputFile;
		std::FILE* outputFile;

		StandardHandle(std::FILE* const inputFile, std::FILE* const outputFile) noexcept
		: inputFile(inputFile), outputFile(outputFile), blockingStatus(::fcntl(::fileno(this->inputFile), F_GETFL)) {
			::tcgetattr(::fileno(this->inputFile), &this->cookedMode);
			this->blocking = !(this->blockingStatus & O_NONBLOCK);
			this->echo = this->cookedMode.c_lflag & ECHO;
			this->canon = this->cookedMode.c_lflag & ICANON;
			this->signals = (this->cookedMode.c_iflag & IXON) || (this->cookedMode.c_iflag & ICRNL) || (this->cookedMode.c_lflag & IEXTEN) || (this->cookedMode.c_lflag & ISIG);
			this->processing = this->cookedMode.c_oflag & OPOST;
			this->update();
		}

		~StandardHandle() {
			this->resetModes();
			this->resetStyles();
			std::fflush(this->outputFile);
		}

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

		void setInputCanon(const bool value) noexcept {
			if (this->canon != value) {
				this->canon = value;
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

		template<std::size_t channels>
		requires(channels >= 3)
		[[nodiscard]] static constexpr std::string stringSetForegroundColor(const xieite::streams::Color<channels>& color) noexcept {
			return "\x1B[48;2;" + xieite::math::stringify(color[0]) + ";" + xieite::math::stringify(color[1]) + ";" + xieite::math::stringify(color[2]) + "m";
		}

		template<std::size_t channels>
		requires(channels >= 3)
		void setForegroundColor(const xieite::streams::Color<channels>& color) noexcept {
			std::print(this->outputFile, "{}", StandardHandle::stringSetForegroundColor(color));
		}

		[[nodiscard]] static constexpr std::string stringResetForegroundColor() noexcept {
			return "\x1B[48m";
		}

		void resetForegroundColor() noexcept {
			std::print(this->outputFile, "{}", StandardHandle::stringResetForegroundColor());
		}

		template<std::size_t channels>
		requires(channels >= 3)
		[[nodiscard]] static constexpr std::string stringSetBackgroundColor(const xieite::streams::Color<channels>& color) noexcept {
			return "\x1B[38;2;" + xieite::math::stringify(color[0]) + ";" + xieite::math::stringify(color[1]) + ";" + xieite::math::stringify(color[2]) + "m";
		}

		template<std::size_t channels>
		requires(channels >= 3)
		void setBackgroundColor(const xieite::streams::Color<channels>& color) noexcept {
			std::print(this->outputFile, "{}", StandardHandle::stringSetForegroundColor(color));
		}

		[[nodiscard]] static constexpr std::string stringResetBackgroundColor() noexcept {
			return "\x1B[38m";
		}

		void resetBackgroundColor() noexcept {
			std::print(this->outputFile, "{}", StandardHandle::stringResetBackgroundColor());
		}

		[[nodiscard]] static constexpr std::string stringSetTextBold(const bool value) noexcept {
			return "\x1B[" + xieite::math::stringify(21 - value * 20) + "m";
		}

		void setTextBold(const bool value) noexcept {
			std::print(this->outputFile, "{}", StandardHandle::stringSetTextBold(value));
		}

		[[nodiscard]] static constexpr std::string stringSetTextItalic(const bool value) noexcept {
			return "\x1B[" + xieite::math::stringify(23 - value * 20) + "m";
		}

		void setTextItalic(const bool value) noexcept {
			std::print(this->outputFile, "{}", StandardHandle::stringSetTextItalic(value));
		}

		[[nodiscard]] static constexpr std::string stringSetTextUnderlined(const bool value) noexcept {
			return "\x1B[" + xieite::math::stringify(24 - value * 20) + "m";
		}

		void setTextUnderlined(const bool value) noexcept {
			std::print(this->outputFile, "{}", StandardHandle::stringSetTextUnderlined(value));
		}

		[[nodiscard]] static constexpr std::string stringSetTextBlinking(const bool value) noexcept {
			return "\x1B[" + xieite::math::stringify(25 - value * 20) + "m";
		}

		void setTextBlinking(const bool value) noexcept {
			std::print(this->outputFile, "{}", StandardHandle::stringSetTextBlinking(value));
		}

		[[nodiscard]] static constexpr std::string stringSetTextInvisible(const bool value) noexcept {
			return "\x1B[" + xieite::math::stringify(28 - value * 20) + "m";
		}

		void setTextInvisible(const bool value) noexcept {
			std::print(this->outputFile, "{}", StandardHandle::stringSetTextInvisible(value));
		}

		[[nodiscard]] static constexpr std::string stringSetTextStriked(const bool value) noexcept {
			return "\x1B[" + xieite::math::stringify(29 - value * 20) + "m";
		}

		void setTextStriked(const bool value) noexcept {
			std::print(this->outputFile, "{}", StandardHandle::stringSetTextStriked(value));
		}

		[[nodiscard]] static constexpr std::string stringSetColorsSwapped(const bool value) noexcept {
			return "\x1B[" + xieite::math::stringify(27 - value * 20) + "m";
		}
		
		void setColorsSwapped(const bool value) noexcept {
			std::print(this->outputFile, "{}", StandardHandle::stringSetColorsSwapped(value));
		}

		[[nodiscard]] static constexpr std::string stringResetStyles() noexcept {
			return "\x1B[0m";
		}

		void resetStyles() noexcept {
			this->setCursorInvisible(false);
			this->setCursorAlternate(false);
			this->setScreenAlternate(false);
			std::print(this->outputFile, "{}", StandardHandle::stringResetStyles());
		}
		
		void resetModes() noexcept {
			fcntl(::fileno(this->inputFile), F_SETFL, this->blockingStatus);
			tcsetattr(::fileno(this->inputFile), TCSANOW, &this->cookedMode);
		}

		[[nodiscard]] xieite::streams::Position getCursorPosition() noexcept {
			const bool canon = this->canon;
			this->setInputCanon(false);
			std::print(this->outputFile, "\x1B[6n");
			xieite::streams::Position position;
			std::fscanf(this->inputFile, "\x1B[%i;%iR", &position.row, &position.column);
			this->setInputCanon(canon);
			return xieite::streams::Position(position.row - 1, position.column - 1);
		}

		[[nodiscard]] constexpr std::string stringSetCursorPosition(const xieite::streams::Position position) noexcept {
			return "\x1B[" + xieite::math::stringify(position.row + 1) + ";" + xieite::math::stringify(position.column + 1) + "H";
		}

		void setCursorPosition(const xieite::streams::Position position) noexcept {
			std::print(this->outputFile, "{}", StandardHandle::stringSetCursorPosition(position));
		}

		[[nodiscard]] constexpr std::string stringMoveCursorPosition(const xieite::streams::Position difference) noexcept {
			if (difference.row) {
				return "\x1B[" + xieite::math::stringify(std::abs(difference.row)) + "CD"[difference.row < 0];
			}
			if (difference.column) {
				return "\x1B[" + xieite::math::stringify(std::abs(difference.column)) + "BA"[difference.column < 0];
			}
			return "";
		}

		void moveCursorPosition(const xieite::streams::Position difference) noexcept {
			std::print(this->outputFile, "{}", StandardHandle::stringMoveCursorPosition(difference));
		}

		[[nodiscard]] static constexpr std::string stringSetCursorInvisible(const bool value) noexcept {
			return std::string("\x1B[?25") + "hl"[value];
		}

		void setCursorInvisible(const bool value) noexcept {
			std::print(this->outputFile, "{}", StandardHandle::stringSetCursorInvisible(value));
		}

		[[nodiscard]] static constexpr std::string stringSetCursorShapeBlock(const bool blink) noexcept {
			return "\1\x1B[" + xieite::math::stringify(2 - blink) + "q\2";
		}

		void setCursorShapeBlock(const bool blink) noexcept {
			std::print(this->outputFile, "{}", StandardHandle::stringSetCursorShapeBlock(blink));
		}

		[[nodiscard]] static constexpr std::string stringSetCursorShapeUnderscore(const bool blink) noexcept {
			return "\1\x1B[" + xieite::math::stringify(4 - blink) + "q\2";
		}

		void setCursorShapeUnderscore(const bool blink) noexcept {
			std::print(this->outputFile, "{}", StandardHandle::stringSetCursorShapeUnderscore(blink));
		}

		[[nodiscard]] static constexpr std::string stringSetCursorShapePipe(const bool blink) noexcept {
			return "\1\x1B[" + xieite::math::stringify(6 - blink) + "q\2";
		}

		void setCursorShapePipe(const bool blink) noexcept {
			std::print(this->outputFile, "{}", StandardHandle::stringSetCursorShapePipe(blink));
		}

		[[nodiscard]] static constexpr std::string stringSetCursorAlternate(const bool value) noexcept {
			return std::string("\x1B[") + "us"[value];
		}

		void setCursorAlternate(const bool value) noexcept {
			std::print(this->outputFile, "{}", StandardHandle::stringSetCursorAlternate(value));
		}

		[[nodiscard]] static constexpr std::string stringSetScreenAlternate(const bool value) noexcept {
			return std::string("\x1B[?47") + "lh"[value];
		}

		void setScreenAlternate(const bool value) noexcept {
			std::print(this->outputFile, "{}", StandardHandle::stringSetScreenAlternate(value));
		}

		[[nodiscard]] xieite::streams::Position getScreenSize() noexcept {
			::winsize size;
			::ioctl(::fileno(this->inputFile), TIOCGWINSZ, std::addressof(size));
			return xieite::streams::Position(size.ws_row, size.ws_col);
		}

		[[nodiscard]] static constexpr std::string stringClearScreen() noexcept {
			return "\x1B[2J";
		}

		void clearScreen() noexcept {
			std::print(this->outputFile, "{}", StandardHandle::stringClearScreen());
		}

		[[nodiscard]] static constexpr std::string stringClearScreenUntil() noexcept {
			return "\x1B[1J";
		}
		
		void clearScreenUntil() noexcept {
			std::print(this->outputFile, "{}", StandardHandle::stringClearScreenUntil());
		}

		[[nodiscard]] static constexpr std::string stringClearScreenFrom() noexcept {
			return "\x1B[0J";
		}
		
		void clearScreenFrom() noexcept {
			std::print(this->outputFile, "{}", StandardHandle::stringClearScreenFrom());
		}

		[[nodiscard]] static constexpr std::string stringClearLine() noexcept {
			return "\x1B[2K";
		}

		void clearLine() noexcept {
			std::print(this->outputFile, "{}", StandardHandle::stringClearLine());
		}

		[[nodiscard]] static constexpr std::string stringClearLineUntil() noexcept {
			return "\x1B[1K";
		}

		void clearLineUntil() noexcept {
			std::print(this->outputFile, "{}", StandardHandle::stringClearLineUntil());
		}

		[[nodiscard]] static constexpr std::string stringClearLineFrom() noexcept {
			return "\x1B[0K";
		}

		void clearLineFrom() noexcept {
			std::print(this->outputFile, "{}", StandardHandle::stringClearLineFrom());
		}

		char readCharacter() noexcept {
			const bool canon = this->canon;
			this->setInputCanon(false);
			const char input = static_cast<char>(std::fgetc(this->inputFile));
			this->setInputCanon(canon);
			return input;
		}

		std::string readString() noexcept {
			const bool blocking = this->blocking;
			const bool canon = this->canon;
			this->setInputBlocking(false);
			this->setInputCanon(false);
			const std::string input = xieite::streams::read(this->inputFile);
			this->setInputBlocking(blocking);
			this->setInputCanon(canon);
			return input;
		}

		xieite::streams::Key readKey() noexcept {
			const xieite::functors::ScopeGuard _ = xieite::functors::ScopeGuard([this, blocking = this->blocking] {
				this->setInputBlocking(blocking);
			});
			const char first = this->readCharacter();
			this->setInputBlocking(false);
			switch (first) {
			case '\x00':
				switch (this->readCharacter()) {
				case '\x00':
					return xieite::streams::Key::Pause;
				case '\x03':
					return xieite::streams::Key::Null;
				}
				break;
			case '\x01':
				return xieite::streams::Key::ControlA;
			case '\x02':
				return xieite::streams::Key::ControlB;
			case '\x03':
				return xieite::streams::Key::ControlC;
			case '\x04':
				return xieite::streams::Key::ControlD;
			case '\x05':
				return xieite::streams::Key::ControlE;
			case '\x06':
				return xieite::streams::Key::ControlF;
			case '\x07':
				return xieite::streams::Key::ControlG;
			case '\x08':
				return xieite::streams::Key::ControlH;
			case '\x09':
				return xieite::streams::Key::ControlI;
			case '\x0A':
				return xieite::streams::Key::ControlJ;
			case '\x0B':
				return xieite::streams::Key::ControlK;
			case '\x0C':
				return xieite::streams::Key::ControlL;
			case '\x0D':
				return xieite::streams::Key::ControlM;
			case '\x0E':
				return xieite::streams::Key::ControlN;
			case '\x0F':
				return xieite::streams::Key::ControlO;
			case '\x10':
				return xieite::streams::Key::ControlP;
			case '\x11':
				return xieite::streams::Key::ControlQ;
			case '\x12':
				return xieite::streams::Key::ControlR;
			case '\x13':
				return xieite::streams::Key::ControlS;
			case '\x14':
				return xieite::streams::Key::ControlT;
			case '\x15':
				return xieite::streams::Key::ControlU;
			case '\x16':
				return xieite::streams::Key::ControlV;
			case '\x17':
				return xieite::streams::Key::ControlW;
			case '\x18':
				return xieite::streams::Key::ControlX;
			case '\x19':
				return xieite::streams::Key::ControlY;
			case '\x1A':
				return xieite::streams::Key::ControlZ;
			case '\x1B':
				switch (this->readCharacter()) {
				case '\x4F':
					switch (this->readCharacter()) {
					case '\x50':
						return xieite::streams::Key::Function1;
					case '\x51':
						return xieite::streams::Key::Function2;
					case '\x52':
						return xieite::streams::Key::Function3;
					case '\x53':
						return xieite::streams::Key::Function4;
					}
					break;
				case '\x5B':
					switch (this->readCharacter()) {
					case '\x20':
						if (this->readCharacter() == '\x7E') {
							return xieite::streams::Key::NumpadDigit0;
						}
						break;
					case '\x21':
						if (this->readCharacter() == '\x7E') {
							return xieite::streams::Key::NumpadPeriod;
						}
						break;
					case '\x23':
						if (this->readCharacter() == '\x7E') {
							return xieite::streams::Key::NumpadDigit9;
						}
						break;
					case '\x24':
						if (this->readCharacter() == '\x7E') {
							return xieite::streams::Key::NumpadDigit3;
						}
						break;
					case '\x29':
						return xieite::streams::Key::NumpadDigit8;
					case '\x2A':
						return xieite::streams::Key::NumpadDigit2;
					case '\x2B':
						return xieite::streams::Key::NumpadDigit6;
					case '\x2C':
						return xieite::streams::Key::NumpadDigit4;
					case '\x2D':
						return xieite::streams::Key::NumpadDigit5;
					case '\x2E':
						return xieite::streams::Key::NumpadDigit1;
					case '\x30':
						return xieite::streams::Key::NumpadDigit7;
					case '\x31':
						if (const char first = this->readCharacter(); this->readCharacter() == '\x7E') {
							switch (first) {
							case '\x35':
								return xieite::streams::Key::Function5;
							case '\x37':
								return xieite::streams::Key::Function6;
							case '\x38':
								return xieite::streams::Key::Function7;
							case '\x39':
								return xieite::streams::Key::Function8;
							}
						}
						break;
					case '\x32':
						if (const char first = this->readCharacter(); this->readCharacter() == '\x7E') {
							switch (first) {
							case '\x30':
								return xieite::streams::Key::Function9;
							case '\x32':
								return xieite::streams::Key::Function10;
							case '\x34':
								return xieite::streams::Key::Function11;
							case '\x35':
								return xieite::streams::Key::Function12;
							}
						}
						break;
					}
				}
				break;
			case '\x20':
				return xieite::streams::Key::Space;
			case '\x21':
				return xieite::streams::Key::Ecphoneme;
			case '\x22':
				return xieite::streams::Key::Quotation;
			case '\x23':
				return xieite::streams::Key::Octothorpe;
			case '\x24':
				return xieite::streams::Key::Dollar;
			case '\x25':
				return xieite::streams::Key::Percent;
			case '\x26':
				return xieite::streams::Key::Ampersand;
			case '\x27':
				return xieite::streams::Key::Apostrophe;
			case '\x28':
				return xieite::streams::Key::ParenthesisOpen;
			case '\x29':
				return xieite::streams::Key::ParenthesisClose;
			case '\x2A':
				return xieite::streams::Key::Asterisk;
			case '\x2B':
				return xieite::streams::Key::Plus;
			case '\x2C':
				return xieite::streams::Key::Comma;
			case '\x2D':
				return xieite::streams::Key::Hyphen;
			case '\x2E':
				return xieite::streams::Key::Period;
			case '\x2F':
				return xieite::streams::Key::Slash;
			case '\x30':
				return xieite::streams::Key::Digit0;
			case '\x31':
				return xieite::streams::Key::Digit1;
			case '\x32':
				return xieite::streams::Key::Digit2;
			case '\x33':
				return xieite::streams::Key::Digit3;
			case '\x34':
				return xieite::streams::Key::Digit4;
			case '\x35':
				return xieite::streams::Key::Digit5;
			case '\x36':
				return xieite::streams::Key::Digit6;
			case '\x37':
				return xieite::streams::Key::Digit7;
			case '\x38':
				return xieite::streams::Key::Digit8;
			case '\x39':
				return xieite::streams::Key::Digit9;
			case '\x3A':
				return xieite::streams::Key::Colon;
			case '\x3B':
				return xieite::streams::Key::Semicolon;
			case '\x3C':
				return xieite::streams::Key::Less;
			case '\x3D':
				return xieite::streams::Key::Equal;
			case '\x3E':
				return xieite::streams::Key::Greater;
			case '\x3F':
				return xieite::streams::Key::Eroteme;
			case '\x40':
				return xieite::streams::Key::Ampersat;
			case '\x41':
				return xieite::streams::Key::UppercaseA;
			case '\x42':
				return xieite::streams::Key::UppercaseB;
			case '\x43':
				return xieite::streams::Key::UppercaseC;
			case '\x44':
				return xieite::streams::Key::UppercaseD;
			case '\x45':
				return xieite::streams::Key::UppercaseE;
			case '\x46':
				return xieite::streams::Key::UppercaseF;
			case '\x47':
				return xieite::streams::Key::UppercaseG;
			case '\x48':
				return xieite::streams::Key::UppercaseH;
			case '\x49':
				return xieite::streams::Key::UppercaseI;
			case '\x4A':
				return xieite::streams::Key::UppercaseJ;
			case '\x4B':
				return xieite::streams::Key::UppercaseK;
			case '\x4C':
				return xieite::streams::Key::UppercaseL;
			case '\x4D':
				return xieite::streams::Key::UppercaseM;
			case '\x4E':
				return xieite::streams::Key::UppercaseN;
			case '\x4F':
				return xieite::streams::Key::UppercaseO;
			case '\x50':
				return xieite::streams::Key::UppercaseP;
			case '\x51':
				return xieite::streams::Key::UppercaseQ;
			case '\x52':
				return xieite::streams::Key::UppercaseR;
			case '\x53':
				return xieite::streams::Key::UppercaseS;
			case '\x54':
				return xieite::streams::Key::UppercaseT;
			case '\x55':
				return xieite::streams::Key::UppercaseU;
			case '\x56':
				return xieite::streams::Key::UppercaseV;
			case '\x57':
				return xieite::streams::Key::UppercaseW;
			case '\x58':
				return xieite::streams::Key::UppercaseX;
			case '\x59':
				return xieite::streams::Key::UppercaseY;
			case '\x5A':
				return xieite::streams::Key::UppercaseZ;
			case '\x5B':
				return xieite::streams::Key::BracketOpen;
			case '\x5C':
				return xieite::streams::Key::Backslash;
			case '\x5D':
				return xieite::streams::Key::BracketClose;
			case '\x5E':
				return xieite::streams::Key::Caret;
			case '\x5F':
				return xieite::streams::Key::Underscore;
			case '\x60':
				return xieite::streams::Key::Grave;
			case '\x61':
				return xieite::streams::Key::LowercaseA;
			case '\x62':
				return xieite::streams::Key::LowercaseB;
			case '\x63':
				return xieite::streams::Key::LowercaseC;
			case '\x64':
				return xieite::streams::Key::LowercaseD;
			case '\x65':
				return xieite::streams::Key::LowercaseE;
			case '\x66':
				return xieite::streams::Key::LowercaseF;
			case '\x67':
				return xieite::streams::Key::LowercaseG;
			case '\x68':
				return xieite::streams::Key::LowercaseH;
			case '\x69':
				return xieite::streams::Key::LowercaseI;
			case '\x6A':
				return xieite::streams::Key::LowercaseJ;
			case '\x6B':
				return xieite::streams::Key::LowercaseK;
			case '\x6C':
				return xieite::streams::Key::LowercaseL;
			case '\x6D':
				return xieite::streams::Key::LowercaseM;
			case '\x6E':
				return xieite::streams::Key::LowercaseN;
			case '\x6F':
				return xieite::streams::Key::LowercaseO;
			case '\x70':
				return xieite::streams::Key::LowercaseP;
			case '\x71':
				return xieite::streams::Key::LowercaseQ;
			case '\x72':
				return xieite::streams::Key::LowercaseR;
			case '\x73':
				return xieite::streams::Key::LowercaseS;
			case '\x74':
				return xieite::streams::Key::LowercaseT;
			case '\x75':
				return xieite::streams::Key::LowercaseU;
			case '\x76':
				return xieite::streams::Key::LowercaseV;
			case '\x77':
				return xieite::streams::Key::LowercaseW;
			case '\x78':
				return xieite::streams::Key::LowercaseX;
			case '\x79':
				return xieite::streams::Key::LowercaseY;
			case '\x7A':
				return xieite::streams::Key::LowercaseZ;
			case '\x7B':
				return xieite::streams::Key::BraceOpen;
			case '\x7C':
				return xieite::streams::Key::Pipe;
			case '\x7D':
				return xieite::streams::Key::BraceClose;
			case '\x7E':
				return xieite::streams::Key::Tilde;
			case '\x7F':
				return xieite::streams::Key::Backspace;
			}
			return xieite::streams::Key::Unknown;
		}

	private:
		const int blockingStatus;
		::termios cookedMode;

		bool blocking;
		bool echo;
		bool canon;
		bool signals;
		bool processing;

		void update() noexcept {
			::fcntl(::fileno(this->inputFile), F_SETFL, this->blockingStatus | (O_NONBLOCK * !this->blocking));
			::termios rawMode = this->cookedMode;
			rawMode.c_iflag &= ~static_cast<::tcflag_t>((ICRNL * !this->signals) | (IXON * !this->signals));
			rawMode.c_lflag &= ~static_cast<::tcflag_t>((ECHO * !this->echo) | (ICANON * !this->canon) | (IEXTEN * !this->signals) | (ISIG * !this->signals));
			rawMode.c_oflag &= ~static_cast<::tcflag_t>(OPOST * !this->processing);
			::tcsetattr(::fileno(this->inputFile), TCSANOW, std::addressof(rawMode));
		}
	};
}
