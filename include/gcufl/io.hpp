#pragma once

#include <fcntl.h>
#include <limits>
#include <string>
#include <string_view>
#include <termios.h>
#include <thread>
#include <unistd.h>


namespace gcufl {
	namespace io {
		class RawLock {
		private:
			termios cooked;

		public:
			RawLock(const bool echo = false) noexcept;

			~RawLock();
		};

		class NonBlockLock {
		private:
			const int blocking = fcntl(STDIN_FILENO, F_GETFL);

		public:
			NonBlockLock() noexcept;

			~NonBlockLock();
		};

		char waitChar(const bool echo = false) noexcept;

		char readChar(const char defaultChar = 0) noexcept;

		std::string readString(const std::size_t count = std::numeric_limits<std::streamsize>::max(), const char until = std::char_traits<char>::eof()) noexcept;

		void putbackString(std::string_view string) noexcept;

		struct Position {
			int row;
			int column;
		};

		enum class direction: char {
			Up = 'A',
			Down,
			Right,
			Left
		};

		gcufl::io::Position getWindowSize() noexcept;

		namespace cursor {
			gcufl::io::Position getPosition() noexcept;

			void setPosition(const gcufl::io::Position position) noexcept;

			void move(const char direction, const int count = 1) noexcept;
		}

		namespace style {
			constexpr std::string_view none = "\033[0m";

			constexpr std::string_view eraseLine = "\033[2K\r";
			constexpr std::string_view eraseAll = "\033[2J\033[H";

			namespace ef {
				constexpr std::string_view bold = "\033[1m";
				constexpr std::string_view dim = "\033[2m";
				constexpr std::string_view italic = "\033[3m";
				constexpr std::string_view underline = "\033[4m";
				constexpr std::string_view blink = "\033[5m";
				constexpr std::string_view invert = "\033[7m";
				constexpr std::string_view hide = "\033[8m";
				constexpr std::string_view strikethrough = "\033[9m";
				constexpr std::string_view doubleUnderline = "\033[21m";

				constexpr std::string_view hideCursor = "\033[?25l";
				constexpr std::string_view showCursor = "\033[?25h";
			}

			namespace fg {
				constexpr std::string_view dimBlack = "\033[30m";
				constexpr std::string_view dimRed = "\033[31m";
				constexpr std::string_view dimGreen = "\033[32m";
				constexpr std::string_view dimYellow = "\033[33m";
				constexpr std::string_view dimBlue = "\033[34m";
				constexpr std::string_view dimMagenta = "\033[35m";
				constexpr std::string_view dimCyan = "\033[36m";
				constexpr std::string_view dimWhite = "\033[37m";

				constexpr std::string_view brightBlack = "\033[90m";
				constexpr std::string_view brightRed = "\033[91m";
				constexpr std::string_view birghtGreen = "\033[92m";
				constexpr std::string_view brightYellow = "\033[93m";
				constexpr std::string_view brightBlue = "\033[94m";
				constexpr std::string_view brightMagenta = "\033[95m";
				constexpr std::string_view brightCyan = "\033[96m";
				constexpr std::string_view brightWhite = "\033[97m";
			}

			namespace bg {
				constexpr std::string_view dimBlack = "\033[40m";
				constexpr std::string_view dimRed = "\033[41m";
				constexpr std::string_view dimGreen = "\033[42m";
				constexpr std::string_view dimYellow = "\033[43m";
				constexpr std::string_view dimBlue = "\033[44m";
				constexpr std::string_view dimMagenta = "\033[45m";
				constexpr std::string_view dimCyan = "\033[46m";
				constexpr std::string_view dimWhite = "\033[47m";

				constexpr std::string_view brightBlack = "\033[100m";
				constexpr std::string_view brightRed = "\033[101m";
				constexpr std::string_view brightGreen = "\033[102m";
				constexpr std::string_view brightYellow = "\033[103m";
				constexpr std::string_view brightBlue = "\033[104m";
				constexpr std::string_view brightMagenta = "\033[105m";
				constexpr std::string_view brightCyan = "\033[106m";
				constexpr std::string_view brightWhite = "\033[107m";
			}
		}
	}
}
