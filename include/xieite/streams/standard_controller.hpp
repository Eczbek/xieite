#pragma once

#include "../macros/platform.hpp"

#if !XIEITE_PLATFORM_UNIX
#	error "System not supported"
#endif

#include <cmath>
#include <cstddef>
#include <cstdio>
#include <fcntl.h>
#include <istream>
#include <ostream>
#include <ranges>
#include <stdio.h>
#include <string>
#include <string_view>
#include <sys/ioctl.h>
#include <termios.h>
#include <unistd.h>
#include "../functors/scope_guard.hpp"
#include "../graphics/color.hpp"
#include "../streams/key.hpp"
#include "../streams/position.hpp"
#include "../streams/get_file.hpp"

namespace xieite::streams {
	class StandardController {
	public:
		std::istream& inputStream;
		std::ostream& outputStream;

		StandardController(std::istream& inputStream, std::ostream& outputStream) noexcept
		: inputStream(inputStream), outputStream(outputStream), inputFile(xieite::streams::getFile(inputStream)), inputFileDescriptor(::fileno(this->inputFile)), blockingStatus(::fcntl(this->inputFileDescriptor, F_GETFL)) {
			tcgetattr(this->inputFileDescriptor, &this->cookedMode);
			this->blocking = !(this->blockingStatus & O_NONBLOCK);
			this->echo = this->cookedMode.c_lflag & ECHO;
			this->canonical = this->cookedMode.c_lflag & ICANON;
			this->signals = (this->cookedMode.c_iflag & IXON) || (this->cookedMode.c_iflag & ICRNL) || (this->cookedMode.c_lflag & IEXTEN) || (this->cookedMode.c_lflag & ISIG);
			this->processing = this->cookedMode.c_oflag & OPOST;
			this->update();
		}

		~StandardController() {
			this->resetModes();
			this->resetStyles();
		}

		void setInputBlocking(const bool value) const noexcept {
			if (this->blocking != value) {
				this->blocking = value;
				this->update();
			}
		}

		void setInputEcho(const bool value) const noexcept {
			if (this->echo != value) {
				this->echo = value;
				this->update();
			}
		}

		void setInputCanonical(const bool value) const noexcept {
			if (this->canonical != value) {
				this->canonical = value;
				this->update();
			}
		}

		void setInputSignals(const bool value) const noexcept {
			if (this->signals != value) {
				this->signals = value;
				this->update();
			}
		}

		void setOutputProcessing(const bool value) const noexcept {
			if (this->processing != value) {
				this->processing = value;
				this->update();
			}
		}

		void setForegroundColor(const xieite::graphics::Color& color) const noexcept {
			this->outputStream << "\x1B[38;2;" << static_cast<int>(color.red) << ';' << static_cast<int>(color.green) << ';' << static_cast<int>(color.blue) << 'm';
		}

		void resetForegroundColor() const noexcept {
			this->outputStream << "\x1B[38m";
		}

		void setBackgroundColor(const xieite::graphics::Color& color) const noexcept {
			this->outputStream << "\x1B[48;2;" << static_cast<int>(color.red) << ';' << static_cast<int>(color.green) << ';' << static_cast<int>(color.blue) << 'm';
		}

		void resetBackgroundColor() const noexcept {
			this->outputStream << "\x1B[48m";
		}

		void setTextBold(const bool value) const noexcept {
			this->outputStream << "\x1B[" << (21 - value * 20) << 'm';
		}

		void setTextItalic(const bool value) const noexcept {
			this->outputStream << "\x1B[" << (23 - value * 20) << 'm';
		}

		void setTextUnderline(const bool value) const noexcept {
			this->outputStream << "\x1B[" << (24 - value * 20) << 'm';
		}

		void setTextBlinking(const bool value) const noexcept {
			this->outputStream << "\x1B[" << (25 - value * 20) << 'm';
		}

		void setColorsSwapped(const bool value) const noexcept {
			this->outputStream << "\x1B[" << (27 - value * 20) << 'm';
		}

		void setTextVisible(const bool value) const noexcept {
			this->outputStream << "\x1B[" << (8 + value * 20) << 'm';
		}

		void setTextStrikethrough(const bool value) const noexcept {
			this->outputStream << "\x1B[" << (29 - value * 20) << 'm';
		}

		void resetStyles() const noexcept {
			this->outputStream << "\x1B[0m";
		}

		void resetModes() const noexcept {
			fcntl(this->inputFileDescriptor, F_SETFL, this->blockingStatus);
			tcsetattr(this->inputFileDescriptor, TCSANOW, &this->cookedMode);
		}

		void clearScreen() const noexcept {
			this->outputStream << "\x1B[2J";
		}

		void clearLine() const noexcept {
			this->outputStream << "\x1B[2K";
		}

		[[nodiscard]] xieite::streams::Position getCursorPosition() const noexcept {
			const bool canonical = this->canonical;
			this->setInputCanonical(false);
			this->outputStream << "\x1B[6n";
			xieite::streams::Position position;
			std::fscanf(this->inputFile, "\x1B[%i;%iR", &position.row, &position.column);
			this->setInputCanonical(canonical);
			return xieite::streams::Position(position.row - 1, position.column - 1);
		}

		void setCursorPosition(const xieite::streams::Position position) const noexcept {
			this->outputStream << "\x1B[" << (position.row + 1) << ';' << (position.column + 1) << 'H';
		}

		void moveCursorPosition(const xieite::streams::Position difference) const noexcept {
			if (difference.row) {
				this->outputStream << "\x1B[" << std::abs(difference.row) << "CD"[difference.row < 0];
			}
			if (difference.column) {
				this->outputStream << "\x1B[" << std::abs(difference.column) << "BA"[difference.column < 0];
			}
		}

		void setCursorVisible(const bool value) const noexcept {
			this->outputStream << "\x1B[?25" << "lh"[value];
		}

		void setCursorAlternative(const bool value) const noexcept {
			this->outputStream << "\x1B[" << static_cast<char>(117 - value * 2);
		}

		void setScreenAlternative(const bool value) const noexcept {
			this->outputStream << "\x1B[?47" << "lh"[value];
		}

		[[nodiscard]] xieite::streams::Position getScreenSize() const noexcept {
			winsize size;
			ioctl(this->inputFileDescriptor, TIOCGWINSZ, &size);
			return xieite::streams::Position(size.ws_row, size.ws_col);
		}

		char readCharacter() const noexcept {
			const bool canonical = this->canonical;
			this->setInputCanonical(false);
			const char input = this->inputStream.get();
			this->setInputCanonical(canonical);
			return input;
		}

		std::string readString() const noexcept {
			const bool blocking = this->blocking;
			const bool canonical = this->canonical;
			this->setInputBlocking(false);
			this->setInputCanonical(false);
			std::string input;
			char buffer;
			while (this->inputStream.get(buffer)) {
				input += buffer;
			}
			this->inputStream.clear();
			this->setInputBlocking(blocking);
			this->setInputCanonical(canonical);
			return input;
		}

		xieite::streams::Key readKey() const noexcept {
			const char foo = this->readCharacter();
			const xieite::functors::ScopeGuard terminalGuard = xieite::functors::ScopeGuard([this, blocking = this->blocking] {
				this->setInputBlocking(blocking);
			});
			this->setInputBlocking(false);
			switch (foo) {
				case 0: {
					const char bar = this->readCharacter();
					switch (bar) {
						case 0:
							return xieite::streams::Key::Pause;
						case 3:
							return xieite::streams::Key::Null;
					}
					this->inputStream.putback(bar);
					break;
				}
				case 1:
					return xieite::streams::Key::ControlA;
				case 2:
					return xieite::streams::Key::ControlB;
				case 3:
					return xieite::streams::Key::ControlC;
				case 4:
					return xieite::streams::Key::ControlD;
				case 5:
					return xieite::streams::Key::ControlE;
				case 6:
					return xieite::streams::Key::ControlF;
				case 7:
					return xieite::streams::Key::ControlG;
				case 8:
					return xieite::streams::Key::ControlH;
				case 9:
					return xieite::streams::Key::ControlI;
				case 10:
					return xieite::streams::Key::ControlJ;
				case 11:
					return xieite::streams::Key::ControlK;
				case 12:
					return xieite::streams::Key::ControlL;
				case 13:
					return xieite::streams::Key::ControlM;
				case 14:
					return xieite::streams::Key::ControlN;
				case 15:
					return xieite::streams::Key::ControlO;
				case 16:
					return xieite::streams::Key::ControlP;
				case 17:
					return xieite::streams::Key::ControlQ;
				case 18:
					return xieite::streams::Key::ControlR;
				case 19:
					return xieite::streams::Key::ControlS;
				case 20:
					return xieite::streams::Key::ControlT;
				case 21:
					return xieite::streams::Key::ControlU;
				case 22:
					return xieite::streams::Key::ControlV;
				case 23:
					return xieite::streams::Key::ControlW;
				case 24:
					return xieite::streams::Key::ControlX;
				case 25:
					return xieite::streams::Key::ControlY;
				case 26:
					return xieite::streams::Key::ControlZ;
				case 27: {
					const char baz = this->readCharacter();
					switch (baz) {
						case 79: {
							const char qux = this->readCharacter();
							switch (qux) {
								case 80:
									return xieite::streams::Key::Function1;
								case 81:
									return xieite::streams::Key::Function2;
								case 82:
									return xieite::streams::Key::Function3;
								case 83:
									return xieite::streams::Key::Function4;
							}
							this->inputStream.putback(qux);
							break;
						}
						case 91: {
							const char corge = this->readCharacter();
							switch (corge) {
								case 32: {
									const char grault = this->readCharacter();
									if (grault == 126) {
										return xieite::streams::Key::NumpadDigit0;
									}
									this->inputStream.putback(grault);
									break;
								}
								case 33: {
									const char garply = this->readCharacter();
									if (garply == 126) {
										return xieite::streams::Key::NumpadPeriod;
									}
									this->inputStream.putback(garply);
									break;
								}
								case 35: {
									const char waldo = this->readCharacter();
									if (waldo == 126) {
										return xieite::streams::Key::NumpadDigit9;
									}
									this->inputStream.putback(waldo);
									break;
								}
								case 36: {
									const char fred = this->readCharacter();
									if (fred == 126) {
										return xieite::streams::Key::NumpadDigit3;
									}
									this->inputStream.putback(fred);
									break;
								}
								case 41:
									return xieite::streams::Key::NumpadDigit8;
								case 42:
									return xieite::streams::Key::NumpadDigit2;
								case 43:
									return xieite::streams::Key::NumpadDigit6;
								case 44:
									return xieite::streams::Key::NumpadDigit4;
								case 45:
									return xieite::streams::Key::NumpadDigit5;
								case 46:
									return xieite::streams::Key::NumpadDigit1;
								case 48:
									return xieite::streams::Key::NumpadDigit7;
								case 49: {
									const char plugh = this->readCharacter();
									const char xyzzy = this->readCharacter();
									if (xyzzy == 126) {
										switch (plugh) {
											case 53:
												return xieite::streams::Key::Function5;
											case 55:
												return xieite::streams::Key::Function6;
											case 56:
												return xieite::streams::Key::Function7;
											case 57:
												return xieite::streams::Key::Function8;
										}
									}
									this->inputStream.putback(xyzzy);
									this->inputStream.putback(plugh);
									break;
								}
								case 50: {
									const char thud = this->readCharacter();
									const char glug = this->readCharacter();
									if (glug == 126) {
										switch (thud) {
											case 48:
												return xieite::streams::Key::Function9;
											case 50:
												return xieite::streams::Key::Function10;
											case 52:
												return xieite::streams::Key::Function11;
											case 53:
												return xieite::streams::Key::Function12;
										}
									}
									this->inputStream.putback(glug);
									this->inputStream.putback(thud);
									break;
								}
							}
							this->inputStream.putback(corge);
							break;
						}
					}
					this->inputStream.putback(baz);
					break;
				}
				case 32:
					return xieite::streams::Key::Space;
				case 33:
					return xieite::streams::Key::Ecphoneme;
				case 34:
					return xieite::streams::Key::Quotation;
				case 35:
					return xieite::streams::Key::Octothorpe;
				case 36:
					return xieite::streams::Key::Dollar;
				case 37:
					return xieite::streams::Key::Percent;
				case 38:
					return xieite::streams::Key::Ampersand;
				case 39:
					return xieite::streams::Key::Apostrophe;
				case 40:
					return xieite::streams::Key::ParenthesisOpen;
				case 41:
					return xieite::streams::Key::ParenthesisClose;
				case 42:
					return xieite::streams::Key::Asterisk;
				case 43:
					return xieite::streams::Key::Plus;
				case 44:
					return xieite::streams::Key::Comma;
				case 45:
					return xieite::streams::Key::Hyphen;
				case 46:
					return xieite::streams::Key::Period;
				case 47:
					return xieite::streams::Key::Slash;
				case 48:
					return xieite::streams::Key::Digit0;
				case 49:
					return xieite::streams::Key::Digit1;
				case 50:
					return xieite::streams::Key::Digit2;
				case 51:
					return xieite::streams::Key::Digit3;
				case 52:
					return xieite::streams::Key::Digit4;
				case 53:
					return xieite::streams::Key::Digit5;
				case 54:
					return xieite::streams::Key::Digit6;
				case 55:
					return xieite::streams::Key::Digit7;
				case 56:
					return xieite::streams::Key::Digit8;
				case 57:
					return xieite::streams::Key::Digit9;
				case 58:
					return xieite::streams::Key::Colon;
				case 59:
					return xieite::streams::Key::Semicolon;
				case 60:
					return xieite::streams::Key::Less;
				case 61:
					return xieite::streams::Key::Equal;
				case 62:
					return xieite::streams::Key::Greater;
				case 63:
					return xieite::streams::Key::Eroteme;
				case 64:
					return xieite::streams::Key::Ampersat;
				case 65:
					return xieite::streams::Key::UppercaseA;
				case 66:
					return xieite::streams::Key::UppercaseB;
				case 67:
					return xieite::streams::Key::UppercaseC;
				case 68:
					return xieite::streams::Key::UppercaseD;
				case 69:
					return xieite::streams::Key::UppercaseE;
				case 70:
					return xieite::streams::Key::UppercaseF;
				case 71:
					return xieite::streams::Key::UppercaseG;
				case 72:
					return xieite::streams::Key::UppercaseH;
				case 73:
					return xieite::streams::Key::UppercaseI;
				case 74:
					return xieite::streams::Key::UppercaseJ;
				case 75:
					return xieite::streams::Key::UppercaseK;
				case 76:
					return xieite::streams::Key::UppercaseL;
				case 77:
					return xieite::streams::Key::UppercaseM;
				case 78:
					return xieite::streams::Key::UppercaseN;
				case 79:
					return xieite::streams::Key::UppercaseO;
				case 80:
					return xieite::streams::Key::UppercaseP;
				case 81:
					return xieite::streams::Key::UppercaseQ;
				case 82:
					return xieite::streams::Key::UppercaseR;
				case 83:
					return xieite::streams::Key::UppercaseS;
				case 84:
					return xieite::streams::Key::UppercaseT;
				case 85:
					return xieite::streams::Key::UppercaseU;
				case 86:
					return xieite::streams::Key::UppercaseV;
				case 87:
					return xieite::streams::Key::UppercaseW;
				case 88:
					return xieite::streams::Key::UppercaseX;
				case 89:
					return xieite::streams::Key::UppercaseY;
				case 90:
					return xieite::streams::Key::UppercaseZ;
				case 91:
					return xieite::streams::Key::BracketOpen;
				case 92:
					return xieite::streams::Key::Backslash;
				case 93:
					return xieite::streams::Key::BracketClose;
				case 94:
					return xieite::streams::Key::Caret;
				case 95:
					return xieite::streams::Key::Underscore;
				case 96:
					return xieite::streams::Key::Grave;
				case 97:
					return xieite::streams::Key::LowercaseA;
				case 98:
					return xieite::streams::Key::LowercaseB;
				case 99:
					return xieite::streams::Key::LowercaseC;
				case 100:
					return xieite::streams::Key::LowercaseD;
				case 101:
					return xieite::streams::Key::LowercaseE;
				case 102:
					return xieite::streams::Key::LowercaseF;
				case 103:
					return xieite::streams::Key::LowercaseG;
				case 104:
					return xieite::streams::Key::LowercaseH;
				case 105:
					return xieite::streams::Key::LowercaseI;
				case 106:
					return xieite::streams::Key::LowercaseJ;
				case 107:
					return xieite::streams::Key::LowercaseK;
				case 108:
					return xieite::streams::Key::LowercaseL;
				case 109:
					return xieite::streams::Key::LowercaseM;
				case 110:
					return xieite::streams::Key::LowercaseN;
				case 111:
					return xieite::streams::Key::LowercaseO;
				case 112:
					return xieite::streams::Key::LowercaseP;
				case 113:
					return xieite::streams::Key::LowercaseQ;
				case 114:
					return xieite::streams::Key::LowercaseR;
				case 115:
					return xieite::streams::Key::LowercaseS;
				case 116:
					return xieite::streams::Key::LowercaseT;
				case 117:
					return xieite::streams::Key::LowercaseU;
				case 118:
					return xieite::streams::Key::LowercaseV;
				case 119:
					return xieite::streams::Key::LowercaseW;
				case 120:
					return xieite::streams::Key::LowercaseX;
				case 121:
					return xieite::streams::Key::LowercaseY;
				case 122:
					return xieite::streams::Key::LowercaseZ;
				case 123:
					return xieite::streams::Key::BraceOpen;
				case 124:
					return xieite::streams::Key::Pipe;
				case 125:
					return xieite::streams::Key::BraceClose;
				case 126:
					return xieite::streams::Key::Tilde;
				case 127:
					return xieite::streams::Key::Backspace;
			}
			this->inputStream.putback(foo);
			return xieite::streams::Key::Unknown;
		}

		void putBackString(const std::string_view value) const noexcept {
			for (const char character : std::views::reverse(value)) {
				this->inputStream.putback(character);
			}
		}

		void backspace(const std::size_t count) const noexcept {
			if (count) {
				this->outputStream << "\x1B[" << count << 'D' << std::string(count, ' ') << "\x1B[" << count << 'D';
			}
		}

	private:
		std::FILE* const inputFile;
		const int inputFileDescriptor;

		const int blockingStatus;
		termios cookedMode;

		mutable bool blocking;
		mutable bool echo;
		mutable bool canonical;
		mutable bool signals;
		mutable bool processing;

		void update() const noexcept {
			fcntl(this->inputFileDescriptor, F_SETFL, this->blockingStatus | (O_NONBLOCK * !this->blocking));
			termios rawMode = this->cookedMode;
			rawMode.c_iflag &= ~((ICRNL * !this->signals) | (IXON * !this->signals));
			rawMode.c_lflag &= ~((ECHO * !this->echo) | (ICANON * !this->canonical) | (IEXTEN * !this->signals) | (ISIG * !this->signals));
			rawMode.c_oflag &= ~(OPOST * !this->processing);
			tcsetattr(this->inputFileDescriptor, TCSANOW, &rawMode);
		}
	};
}
