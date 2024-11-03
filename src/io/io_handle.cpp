module;

#include <xieite/pltf.hpp>

#if XIEITE_PLTF_TYPE_UNIX
#	include <fcntl.h>
#	include <sys/ioctl.h>
#	include <termios.h>
#	include <unistd.h>
#else
#	warning "unsupported platform"
#endif

export module xieite:io_handle;

import std.compat;
import :abs;
import :color;
import :keyboard;
import :num_str;
import :read;
import :scope_guard;
import :vec;

export namespace xieite {
	struct io_handle {
	public:
		std::FILE* input;
		std::FILE* output;

		io_handle(std::FILE* input, std::FILE* output) noexcept :
			input(input),
			output(output),
			blocking_mode(::fcntl(::fileno(this->input), F_GETFL))
		{
			::tcgetattr(::fileno(this->input), &this->cooked_mode);
			this->block_enabled = !(this->blocking_mode & O_NONBLOCK);
			this->echo_enabled = this->cooked_mode.c_lflag & ECHO;
			this->canon_enabled = this->cooked_mode.c_lflag & ICANON;
			this->signals_enabled = (this->cooked_mode.c_iflag & IXON) || (this->cooked_mode.c_iflag & ICRNL) || (this->cooked_mode.c_lflag & IEXTEN) || (this->cooked_mode.c_lflag & ISIG);
			this->processing_enabled = this->cooked_mode.c_oflag & OPOST;
			this->update();
		}

		~io_handle() {
			this->reset_mode();
			this->reset_style();
			std::fflush(this->output);
		}

		void blocking(bool value) noexcept {
			if (this->block_enabled != value) {
				this->block_enabled = value;
				this->update();
			}
		}

		void echo(bool value) noexcept {
			if (this->echo_enabled != value) {
				this->echo_enabled = value;
				this->update();
			}
		}

		void canon(bool value) noexcept {
			if (this->canon_enabled != value) {
				this->canon_enabled = value;
				this->update();
			}
		}

		void signals(bool value) noexcept {
			if (this->signals_enabled != value) {
				this->signals_enabled = value;
				this->update();
			}
		}

		void processing(bool value) noexcept {
			if (this->processing_enabled != value) {
				this->processing_enabled = value;
				this->update();
			}
		}

		template<std::size_t channels>
		requires(channels >= 3)
		[[nodiscard]] static constexpr std::string fg_code(const xieite::color<channels>& color) noexcept {
			return "\x1B[48;2;" + xieite::num_str(color[0]) + ";" + xieite::num_str(color[1]) + ";" + xieite::num_str(color[2]) + "m";
		}

		template<std::size_t channels>
		requires(channels >= 3)
		void fg(const xieite::color<channels>& color) noexcept {
			std::print(this->output, "{}", io_handle::fg_set(color));
		}

		[[nodiscard]] static constexpr std::string fg_reset_code() noexcept {
			return "\x1B[48m";
		}

		void fg_reset() noexcept {
			std::print(this->output, "{}", io_handle::fg_reset_code());
		}

		template<std::size_t channels>
		requires(channels >= 3)
		[[nodiscard]] static constexpr std::string bg_code(const xieite::color<channels>& color) noexcept {
			return "\x1B[38;2;" + xieite::num_str(color[0]) + ";" + xieite::num_str(color[1]) + ";" + xieite::num_str(color[2]) + "m";
		}

		template<std::size_t channels>
		requires(channels >= 3)
		void bg(const xieite::color<channels>& color) noexcept {
			std::print(this->output, "{}", io_handle::set_bg_code(color));
		}

		[[nodiscard]] static constexpr std::string bg_reset_code() noexcept {
			return "\x1B[38m";
		}

		void bg_reset() noexcept {
			std::print(this->output, "{}", io_handle::bg_reset_code());
		}

		[[nodiscard]] static constexpr std::string bold_code(bool value) noexcept {
			return "\x1B[" + xieite::num_str(21 - value * 20) + "m";
		}

		void bold(bool value) noexcept {
			std::print(this->output, "{}", io_handle::bold_code(value));
		}

		[[nodiscard]] static constexpr std::string italic_code(bool value) noexcept {
			return "\x1B[" + xieite::num_str(23 - value * 20) + "m";
		}

		void italic(bool value) noexcept {
			std::print(this->output, "{}", io_handle::italic_code(value));
		}

		[[nodiscard]] static constexpr std::string underline_code(bool value) noexcept {
			return "\x1B[" + xieite::num_str(24 - value * 20) + "m";
		}

		void underline(bool value) noexcept {
			std::print(this->output, "{}", io_handle::underline_code(value));
		}

		[[nodiscard]] static constexpr std::string blink_code(bool value) noexcept {
			return "\x1B[" + xieite::num_str(25 - value * 20) + "m";
		}

		void blink(bool value) noexcept {
			std::print(this->output, "{}", io_handle::blink_code(value));
		}

		[[nodiscard]] static constexpr std::string invis_code(bool value) noexcept {
			return "\x1B[" + xieite::num_str(28 - value * 20) + "m";
		}

		void invis(bool value) noexcept {
			std::print(this->output, "{}", io_handle::invis_code(value));
		}

		[[nodiscard]] static constexpr std::string striked_code(bool value) noexcept {
			return "\x1B[" + xieite::num_str(29 - value * 20) + "m";
		}

		void striked(bool value) noexcept {
			std::print(this->output, "{}", io_handle::striked_code(value));
		}

		[[nodiscard]] static constexpr std::string swap_colors_code(bool value) noexcept {
			return "\x1B[" + xieite::num_str(27 - value * 20) + "m";
		}
		
		void swap_colors(bool value) noexcept {
			std::print(this->output, "{}", io_handle::swap_colors_code(value));
		}

		[[nodiscard]] static constexpr std::string reset_style_code() noexcept {
			return "\x1B[0m";
		}

		void reset_style() noexcept {
			this->cursor_invis(false);
			this->cursor_alt(false);
			this->screen_alt(false);
			std::print(this->output, "{}", io_handle::reset_style_code());
		}
		
		void reset_mode() noexcept {
			fcntl(::fileno(this->input), F_SETFL, this->blocking_mode);
			tcsetattr(::fileno(this->input), TCSANOW, &this->cooked_mode);
		}

		[[nodiscard]] xieite::vec2<int> get_cursor() noexcept {
			const bool canon_prev = this->canon_enabled;
			this->canon(false);
			std::print(this->output, "\x1B[6n");
			xieite::vec2<int> pos;
			std::fscanf(this->input, "\x1B[%i;%iR", &pos[0], &pos[1]);
			this->canon(canon_prev);
			return pos - xieite::vec2(-1, -1);
		}

		[[nodiscard]] constexpr std::string set_cursor_code(xieite::vec<int, 2> pos) noexcept {
			return "\x1B[" + xieite::num_str(pos[0] + 1) + ";" + xieite::num_str(pos[1] + 1) + "H";
		}

		void set_cursor(xieite::vec<int, 2> pos) noexcept {
			std::print(this->output, "{}", io_handle::set_cursor_code(pos));
		}

		[[nodiscard]] constexpr std::string move_cursor_code(xieite::vec<int, 2> diff) noexcept {
			if (diff[0]) {
				return "\x1B[" + xieite::num_str(xieite::abs(diff[0])) + "CD"[diff[0] < 0];
			}
			if (diff[1]) {
				return "\x1B[" + xieite::num_str(xieite::abs(diff[1])) + "BA"[diff[1] < 0];
			}
			return "";
		}

		void move_cursor(xieite::vec<int, 2> diff) noexcept {
			std::print(this->output, "{}", io_handle::move_cursor_code(diff));
		}

		[[nodiscard]] static constexpr std::string cursor_invis_code(bool value) noexcept {
			return std::string("\x1B[?25") + "hl"[value];
		}

		void cursor_invis(bool value) noexcept {
			std::print(this->output, "{}", io_handle::cursor_invis_code(value));
		}

		[[nodiscard]] static constexpr std::string cursor_block_code(bool blink = false) noexcept {
			return "\1\x1B[" + xieite::num_str(2 - blink) + "q\2";
		}

		void cursor_block(bool blink = false) noexcept {
			std::print(this->output, "{}", io_handle::cursor_block_code(blink));
		}

		[[nodiscard]] static constexpr std::string cursor_underscore_code(bool blink = false) noexcept {
			return "\1\x1B[" + xieite::num_str(4 - blink) + "q\2";
		}

		void cursor_underscore(bool blink = false) noexcept {
			std::print(this->output, "{}", io_handle::cursor_underscore(blink));
		}

		[[nodiscard]] static constexpr std::string cursor_pipe_code(bool blink = false) noexcept {
			return "\1\x1B[" + xieite::num_str(6 - blink) + "q\2";
		}

		void cursor_pipe(bool blink = false) noexcept {
			std::print(this->output, "{}", io_handle::cursor_pipe_code(blink));
		}

		[[nodiscard]] static constexpr std::string cursor_alt_code(bool value) noexcept {
			return std::string("\x1B[") + "us"[value];
		}

		void cursor_alt(bool value) noexcept {
			std::print(this->output, "{}", io_handle::cursor_alt_code(value));
		}

		[[nodiscard]] static constexpr std::string screen_alt_code(bool value) noexcept {
			return std::string("\x1B[?47") + "lh"[value];
		}

		void screen_alt(bool value) noexcept {
			std::print(this->output, "{}", io_handle::screen_alt_code(value));
		}

		[[nodiscard]] xieite::vec<int, 2> screen_size() noexcept {
			::winsize size;
			::ioctl(::fileno(this->input), TIOCGWINSZ, std::addressof(size));
			return xieite::vec<int, 2>(size.ws_row, size.ws_col);
		}

		[[nodiscard]] static constexpr std::string clear_screen_code() noexcept {
			return "\x1B[2J";
		}

		void clear_screen() noexcept {
			std::print(this->output, "{}", io_handle::clear_screen_code());
		}

		[[nodiscard]] static constexpr std::string clear_screen_until_code() noexcept {
			return "\x1B[1J";
		}
		
		void clear_screen_until() noexcept {
			std::print(this->output, "{}", io_handle::clear_screen_until_code());
		}

		[[nodiscard]] static constexpr std::string clear_screen_from_code() noexcept {
			return "\x1B[0J";
		}
		
		void clear_screen_from() noexcept {
			std::print(this->output, "{}", io_handle::clear_screen_from_code());
		}

		[[nodiscard]] static constexpr std::string clear_line_code() noexcept {
			return "\x1B[2K";
		}

		void clear_line() noexcept {
			std::print(this->output, "{}", io_handle::clear_line_code());
		}

		[[nodiscard]] static constexpr std::string clear_line_until_code() noexcept {
			return "\x1B[1K";
		}

		void clear_line_until() noexcept {
			std::print(this->output, "{}", io_handle::clear_line_until_code());
		}

		[[nodiscard]] static constexpr std::string clear_line_from_code() noexcept {
			return "\x1B[0K";
		}

		void clear_line_from() noexcept {
			std::print(this->output, "{}", io_handle::clear_line_from_code());
		}

		char read_char() noexcept {
			const bool canon_prev = this->canon_enabled;
			this->canon(false);
			const char input = static_cast<char>(std::fgetc(this->input));
			this->canon(canon_prev);
			return input;
		}

		std::string read_str() noexcept {
			const bool block_prev = this->block_enabled;
			const bool canon_prev = this->canon_enabled;
			this->blocking(false);
			this->canon(false);
			const std::string input = xieite::read(this->input);
			this->blocking(block_prev);
			this->canon(canon_prev);
			return input;
		}

		xieite::keyboard read_key() noexcept {
			const xieite::scope_guard _ = xieite::scope_guard([this, block_prev = this->block_enabled] {
				this->blocking(block_prev);
			});
			const char c = this->read_char();
			this->blocking(false);
			switch (c) {
			case '\x00':
				switch (this->read_char()) {
				case '\x00':
					return xieite::keyboard::pause;
				case '\x03':
					return xieite::keyboard::null;
				}
				break;
			case '\x01':
				return xieite::keyboard::ctrl_a;
			case '\x02':
				return xieite::keyboard::ctrl_b;
			case '\x03':
				return xieite::keyboard::ctrl_c;
			case '\x04':
				return xieite::keyboard::ctrl_d;
			case '\x05':
				return xieite::keyboard::ctrl_e;
			case '\x06':
				return xieite::keyboard::ctrl_f;
			case '\x07':
				return xieite::keyboard::ctrl_g;
			case '\x08':
				return xieite::keyboard::ctrl_h;
			case '\x09':
				return xieite::keyboard::ctrl_i;
			case '\x0A':
				return xieite::keyboard::ctrl_j;
			case '\x0B':
				return xieite::keyboard::ctrl_k;
			case '\x0C':
				return xieite::keyboard::ctrl_l;
			case '\x0D':
				return xieite::keyboard::ctrl_m;
			case '\x0E':
				return xieite::keyboard::ctrl_n;
			case '\x0F':
				return xieite::keyboard::ctrl_o;
			case '\x10':
				return xieite::keyboard::ctrl_p;
			case '\x11':
				return xieite::keyboard::ctrl_q;
			case '\x12':
				return xieite::keyboard::ctrl_r;
			case '\x13':
				return xieite::keyboard::ctrl_s;
			case '\x14':
				return xieite::keyboard::ctrl_t;
			case '\x15':
				return xieite::keyboard::ctrl_u;
			case '\x16':
				return xieite::keyboard::ctrl_v;
			case '\x17':
				return xieite::keyboard::ctrl_w;
			case '\x18':
				return xieite::keyboard::ctrl_x;
			case '\x19':
				return xieite::keyboard::ctrl_y;
			case '\x1A':
				return xieite::keyboard::ctrl_z;
			case '\x1B':
				switch (this->read_char()) {
				case '\x4F':
					switch (this->read_char()) {
					case '\x50':
						return xieite::keyboard::fn_1;
					case '\x51':
						return xieite::keyboard::fn_2;
					case '\x52':
						return xieite::keyboard::fn_3;
					case '\x53':
						return xieite::keyboard::fn_4;
					}
					break;
				case '\x5B':
					switch (this->read_char()) {
					case '\x20':
						if (this->read_char() == '\x7E') {
							return xieite::keyboard::numpad_0;
						}
						break;
					case '\x21':
						if (this->read_char() == '\x7E') {
							return xieite::keyboard::numpad_dot;
						}
						break;
					case '\x23':
						if (this->read_char() == '\x7E') {
							return xieite::keyboard::numpad_9;
						}
						break;
					case '\x24':
						if (this->read_char() == '\x7E') {
							return xieite::keyboard::numpad_3;
						}
						break;
					case '\x29':
						return xieite::keyboard::numpad_8;
					case '\x2A':
						return xieite::keyboard::numpad_2;
					case '\x2B':
						return xieite::keyboard::numpad_6;
					case '\x2C':
						return xieite::keyboard::numpad_4;
					case '\x2D':
						return xieite::keyboard::numpad_5;
					case '\x2E':
						return xieite::keyboard::numpad_1;
					case '\x30':
						return xieite::keyboard::numpad_7;
					case '\x31':
						if (char c = this->read_char(); this->read_char() == '\x7E') {
							switch (c) {
							case '\x35':
								return xieite::keyboard::fn_5;
							case '\x37':
								return xieite::keyboard::fn_6;
							case '\x38':
								return xieite::keyboard::fn_7;
							case '\x39':
								return xieite::keyboard::fn_8;
							}
						}
						break;
					case '\x32':
						if (char c = this->read_char(); this->read_char() == '\x7E') {
							switch (c) {
							case '\x30':
								return xieite::keyboard::fn_9;
							case '\x32':
								return xieite::keyboard::fn_10;
							case '\x34':
								return xieite::keyboard::fn_11;
							case '\x35':
								return xieite::keyboard::fn_12;
							}
						}
						break;
					}
				}
				break;
			case '\x20':
				return xieite::keyboard::space;
			case '\x21':
				return xieite::keyboard::ecphoneme;
			case '\x22':
				return xieite::keyboard::quote;
			case '\x23':
				return xieite::keyboard::hash;
			case '\x24':
				return xieite::keyboard::dollar;
			case '\x25':
				return xieite::keyboard::percent;
			case '\x26':
				return xieite::keyboard::ampersand;
			case '\x27':
				return xieite::keyboard::apostrophe;
			case '\x28':
				return xieite::keyboard::lparen;
			case '\x29':
				return xieite::keyboard::rparen;
			case '\x2A':
				return xieite::keyboard::star;
			case '\x2B':
				return xieite::keyboard::plus;
			case '\x2C':
				return xieite::keyboard::comma;
			case '\x2D':
				return xieite::keyboard::dash;
			case '\x2E':
				return xieite::keyboard::dot;
			case '\x2F':
				return xieite::keyboard::slash;
			case '\x30':
				return xieite::keyboard::digit_0;
			case '\x31':
				return xieite::keyboard::digit_1;
			case '\x32':
				return xieite::keyboard::digit_2;
			case '\x33':
				return xieite::keyboard::digit_3;
			case '\x34':
				return xieite::keyboard::digit_4;
			case '\x35':
				return xieite::keyboard::digit_5;
			case '\x36':
				return xieite::keyboard::digit_6;
			case '\x37':
				return xieite::keyboard::digit_7;
			case '\x38':
				return xieite::keyboard::digit_8;
			case '\x39':
				return xieite::keyboard::digit_9;
			case '\x3A':
				return xieite::keyboard::colon;
			case '\x3B':
				return xieite::keyboard::semicolon;
			case '\x3C':
				return xieite::keyboard::less;
			case '\x3D':
				return xieite::keyboard::equal;
			case '\x3E':
				return xieite::keyboard::greater;
			case '\x3F':
				return xieite::keyboard::eroteme;
			case '\x40':
				return xieite::keyboard::at;
			case '\x41':
				return xieite::keyboard::upper_a;
			case '\x42':
				return xieite::keyboard::upper_b;
			case '\x43':
				return xieite::keyboard::upper_c;
			case '\x44':
				return xieite::keyboard::upper_d;
			case '\x45':
				return xieite::keyboard::upper_e;
			case '\x46':
				return xieite::keyboard::upper_f;
			case '\x47':
				return xieite::keyboard::upper_g;
			case '\x48':
				return xieite::keyboard::upper_h;
			case '\x49':
				return xieite::keyboard::upper_i;
			case '\x4A':
				return xieite::keyboard::upper_j;
			case '\x4B':
				return xieite::keyboard::upper_k;
			case '\x4C':
				return xieite::keyboard::upper_l;
			case '\x4D':
				return xieite::keyboard::upper_m;
			case '\x4E':
				return xieite::keyboard::upper_n;
			case '\x4F':
				return xieite::keyboard::upper_o;
			case '\x50':
				return xieite::keyboard::upper_p;
			case '\x51':
				return xieite::keyboard::upper_q;
			case '\x52':
				return xieite::keyboard::upper_r;
			case '\x53':
				return xieite::keyboard::upper_s;
			case '\x54':
				return xieite::keyboard::upper_t;
			case '\x55':
				return xieite::keyboard::upper_u;
			case '\x56':
				return xieite::keyboard::upper_v;
			case '\x57':
				return xieite::keyboard::upper_w;
			case '\x58':
				return xieite::keyboard::upper_x;
			case '\x59':
				return xieite::keyboard::upper_y;
			case '\x5A':
				return xieite::keyboard::upper_z;
			case '\x5B':
				return xieite::keyboard::lbracket;
			case '\x5C':
				return xieite::keyboard::backslash;
			case '\x5D':
				return xieite::keyboard::rbracket;
			case '\x5E':
				return xieite::keyboard::caret;
			case '\x5F':
				return xieite::keyboard::underscore;
			case '\x60':
				return xieite::keyboard::grave;
			case '\x61':
				return xieite::keyboard::lower_a;
			case '\x62':
				return xieite::keyboard::lower_b;
			case '\x63':
				return xieite::keyboard::lower_c;
			case '\x64':
				return xieite::keyboard::lower_d;
			case '\x65':
				return xieite::keyboard::lower_e;
			case '\x66':
				return xieite::keyboard::lower_f;
			case '\x67':
				return xieite::keyboard::lower_g;
			case '\x68':
				return xieite::keyboard::lower_h;
			case '\x69':
				return xieite::keyboard::lower_i;
			case '\x6A':
				return xieite::keyboard::lower_j;
			case '\x6B':
				return xieite::keyboard::lower_k;
			case '\x6C':
				return xieite::keyboard::lower_l;
			case '\x6D':
				return xieite::keyboard::lower_m;
			case '\x6E':
				return xieite::keyboard::lower_n;
			case '\x6F':
				return xieite::keyboard::lower_o;
			case '\x70':
				return xieite::keyboard::lower_p;
			case '\x71':
				return xieite::keyboard::lower_q;
			case '\x72':
				return xieite::keyboard::lower_r;
			case '\x73':
				return xieite::keyboard::lower_s;
			case '\x74':
				return xieite::keyboard::lower_t;
			case '\x75':
				return xieite::keyboard::lower_u;
			case '\x76':
				return xieite::keyboard::lower_v;
			case '\x77':
				return xieite::keyboard::lower_w;
			case '\x78':
				return xieite::keyboard::lower_x;
			case '\x79':
				return xieite::keyboard::lower_y;
			case '\x7A':
				return xieite::keyboard::lower_z;
			case '\x7B':
				return xieite::keyboard::lbrace;
			case '\x7C':
				return xieite::keyboard::pipe;
			case '\x7D':
				return xieite::keyboard::rbrace;
			case '\x7E':
				return xieite::keyboard::tilde;
			case '\x7F':
				return xieite::keyboard::backspace;
			}
			return xieite::keyboard::unknown;
		}

	private:
		const int blocking_mode;
		::termios cooked_mode;

		bool block_enabled;
		bool echo_enabled;
		bool canon_enabled;
		bool signals_enabled;
		bool processing_enabled;

		void update() noexcept {
			::fcntl(::fileno(this->input), F_SETFL, this->blocking_mode | (O_NONBLOCK * !this->block_enabled));
			::termios raw_mode = this->cooked_mode;
			raw_mode.c_iflag &= ~static_cast<::tcflag_t>((ICRNL * !this->signals_enabled) | (IXON * !this->signals_enabled));
			raw_mode.c_lflag &= ~static_cast<::tcflag_t>((ECHO * !this->echo_enabled) | (ICANON * !this->canon_enabled) | (IEXTEN * !this->signals_enabled) | (ISIG * !this->signals_enabled));
			raw_mode.c_oflag &= ~static_cast<::tcflag_t>(OPOST * !this->processing_enabled);
			::tcsetattr(::fileno(this->input), TCSANOW, std::addressof(raw_mode));
		}
	};
}
