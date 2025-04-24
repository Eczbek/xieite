#ifndef DETAIL_XIEITE_HEADER_IO_TERM
#	define DETAIL_XIEITE_HEADER_IO_TERM
#
#	include <cstdio>
#	include <stdio.h>
#	include <string>
#	include "../fn/scope_guard.hpp"
#	include "../io/keys.hpp"
#	include "../io/pos.hpp"
#	include "../io/read.hpp"
#	include "../math/abs.hpp"
#	include "../math/color3.hpp"
#	include "../math/str_num.hpp"
#	include "../pp/out.hpp"
#	include "../pp/platform.hpp"
#
#	if XIEITE_PLATFORM_TYPE_UNIX
#		include <fcntl.h>
#		include <sys/ioctl.h>
#		include <termios.h>
#		include <unistd.h>
#	else
#		warning unsupported platform
#	endif

using namespace std::literals;

namespace xieite {
	struct term {
	public:
		std::FILE* in;
		std::FILE* out;

		[[nodiscard]] term(std::FILE* in = stdin, std::FILE* out = stdout) noexcept
		: in(in)
		, out(out)
		, block_mode(::fcntl(::fileno(in), F_GETFL))
		, cooked_mode(XIEITE_OUT_LOCAL(::tcgetattr(::fileno(in), &$))(::termios()))
		, is_block(!(this->block_mode & O_NONBLOCK))
		, is_echo(this->cooked_mode.c_lflag & ECHO)
		, is_canon(this->cooked_mode.c_lflag & ICANON)
		, is_signal((this->cooked_mode.c_iflag & (IXON | ICRNL)) || (this->cooked_mode.c_lflag & (IEXTEN | ISIG)))
		, is_proc(this->cooked_mode.c_oflag & OPOST)
		{ this->flush(); }

		term(const xieite::term&) = delete;

		~term() {
			this->reset_mode();
			this->reset_style();
			this->reset_screen();
			std::fflush(this->out);
		}

		void block(bool x) noexcept {
			if (this->is_block != x) {
				this->is_block = x;
				this->flush();
			}
		}

		void echo(bool x) noexcept {
			if (this->is_echo != x) {
				this->is_echo = x;
				this->flush();
			}
		}

		void canon(bool x) noexcept {
			if (this->is_canon != x) {
				this->is_canon = x;
				this->flush();
			}
		}

		void signal(bool x) noexcept {
			if (this->is_signal != x) {
				this->is_signal = x;
				this->flush();
			}
		}

		void proc(bool x) noexcept {
			if (this->is_proc != x) {
				this->is_proc = x;
				this->flush();
			}
		}

		[[nodiscard]] static constexpr std::string fg_code(std::uint8_t r, std::uint8_t g, std::uint8_t b) noexcept {
			return "\x1B[38;2;"s + xieite::str_num(r) + ";"s + xieite::str_num(g) + ";"s + xieite::str_num(b) + "m"s;
		}

		[[nodiscard]] static constexpr std::string fg_code(const xieite::color3& color) noexcept {
			return xieite::term::fg_code(color.r, color.g, color.b);
		}

		void fg(std::uint8_t r, std::uint8_t g, std::uint8_t b) noexcept {
			std::fputs(xieite::term::fg_code(r, g, b).c_str(), this->out);
		}

		void fg(const xieite::color3& color) noexcept {
			this->fg(color.r, color.g, color.b);
		}

		[[nodiscard]] static constexpr std::string bg_code(std::uint8_t r, std::uint8_t g, std::uint8_t b) noexcept {
			return "\x1B[48;2;"s + xieite::str_num(r) + ";"s + xieite::str_num(g) + ";"s + xieite::str_num(b) + "m"s;
		}

		[[nodiscard]] static constexpr std::string bg_code(const xieite::color3& color) noexcept {
			return xieite::term::bg_code(color.r, color.g, color.b);
		}

		void bg(std::uint8_t r, std::uint8_t g, std::uint8_t b) noexcept {
			std::fputs(xieite::term::bg_code(r, g, b).c_str(), this->out);
		}

		void bg(const xieite::color3& color) noexcept {
			this->bg(color.r, color.g, color.b);
		}

		[[nodiscard]] static constexpr std::string bold_code(bool x) noexcept {
			return x ? "\x1B[1m" : "\x1B[21m";
		}

		void bold(bool x) noexcept {
			std::fputs(xieite::term::bold_code(x).c_str(), this->out);
		}

		[[nodiscard]] static constexpr std::string italic_code(bool x) noexcept {
			return x ? "\x1B[3m" : "\x1B[23m";
		}

		void italic(bool x) noexcept {
			std::fputs(xieite::term::italic_code(x).c_str(), this->out);
		}

		[[nodiscard]] static constexpr std::string underln_code(bool x) noexcept {
			return x ? "\x1B[4m" : "\x1B[24m";
		}

		void underln(bool x) noexcept {
			std::fputs(xieite::term::underln_code(x).c_str(), this->out);
		}

		[[nodiscard]] static constexpr std::string blink_code(bool x) noexcept {
			return x ? "\x1B[5m" : "\x1B[25m";
		}

		void blink(bool x) noexcept {
			std::fputs(xieite::term::blink_code(x).c_str(), this->out);
		}

		[[nodiscard]] static constexpr std::string invis_code(bool x) noexcept {
			return x ? "\x1B[8m" : "\x1B[28m";
		}

		void invis(bool x) noexcept {
			std::fputs(xieite::term::invis_code(x).c_str(), this->out);
		}

		[[nodiscard]] static constexpr std::string strike_code(bool x) noexcept {
			return x ? "\x1B[9m" : "\x1B[29m";
		}

		void strike(bool x) noexcept {
			std::fputs(xieite::term::strike_code(x).c_str(), this->out);
		}

		[[nodiscard]] static constexpr std::string invert_code(bool x) noexcept {
			return x ? "\x1B[7m" : "\x1B[27m";
		}
		
		void invert(bool x) noexcept {
			std::fputs(xieite::term::invert_code(x).c_str(), this->out);
		}

		[[nodiscard]] static constexpr std::string reset_style_code() noexcept {
			return "\x1B[0m";
		}

		void reset_style() noexcept {
			std::fputs(xieite::term::reset_style_code().c_str(), this->out);
		}
		
		void reset_mode() noexcept {
			::fcntl(::fileno(this->in), F_SETFL, this->block_mode);
			::tcsetattr(::fileno(this->in), TCSANOW, &this->cooked_mode);
		}

		void reset_screen() noexcept {
			this->cursor_invis(false);
			this->screen_alt(false);
			this->cursor_alt(false);
		}

		[[nodiscard]] xieite::pos get_cursor() noexcept {
			const bool canon_prev = this->is_canon;
			this->canon(false);
			std::fputs("\x1B[6n", this->out);
			int row;
			int col;
			std::fscanf(this->in, "\x1B[%i;%iR", &row, &col);
			this->canon(canon_prev);
			return xieite::pos(static_cast<xieite::ssize_t>(row - 1), static_cast<xieite::ssize_t>(col - 1));
		}

		[[nodiscard]] constexpr std::string set_cursor_code(xieite::ssize_t row, xieite::ssize_t col) noexcept {
			return "\x1B["s + xieite::str_num(row + 1) + ";"s + xieite::str_num(col + 1) + "H"s;
		}

		[[nodiscard]] constexpr std::string set_cursor_code(xieite::pos pos) noexcept {
			return xieite::term::set_cursor_code(pos.row, pos.col);
		}

		void set_cursor(xieite::ssize_t row, xieite::ssize_t col) noexcept {
			std::fputs(xieite::term::set_cursor_code(row, col).c_str(), this->out);
		}

		void set_cursor(xieite::pos pos) noexcept {
			this->set_cursor(pos.row, pos.col);
		}

		[[nodiscard]] constexpr std::string mv_cursor_code(xieite::ssize_t row, xieite::ssize_t col) noexcept {
			std::string code;
			if (row) {
				code += "\x1B[";
				code += xieite::str_num(xieite::abs(row));
				code += "BA"[row < 0];
			}
			if (col) {
				code += "\x1B[";
				code += xieite::str_num(xieite::abs(col));
				code += "CD"[col < 0];
			}
			return code;
		}

		[[nodiscard]] constexpr std::string mv_cursor_code(xieite::pos diff) noexcept {
			return xieite::term::mv_cursor_code(diff.row, diff.col);
		}

		void mv_cursor(xieite::ssize_t row, xieite::ssize_t col) noexcept {
			std::fputs(xieite::term::mv_cursor_code(row, col).c_str(), this->out);
		}

		void mv_cursor(xieite::pos diff) noexcept {
			this->mv_cursor(diff.row, diff.col);
		}

		[[nodiscard]] static constexpr std::string cursor_invis_code(bool x) noexcept {
			return "\x1B[?25"s + "hl"[x];
		}

		void cursor_invis(bool x) noexcept {
			if (this->is_cursor_invis != x) {
				this->is_cursor_invis = x;
				std::fputs(xieite::term::cursor_invis_code(x).c_str(), this->out);
			}
		}

		[[nodiscard]] static constexpr std::string cursor_block_code(bool blink = false) noexcept {
			return "\1\x1B["s + xieite::str_num(2 - blink) + "q\2"s;
		}

		void cursor_block(bool blink = false) noexcept {
			std::fputs(xieite::term::cursor_block_code(blink).c_str(), this->out);
		}

		[[nodiscard]] static constexpr std::string cursor_undersc_code(bool blink = false) noexcept {
			return "\1\x1B["s + xieite::str_num(4 - blink) + "q\2"s;
		}

		void cursor_undersc(bool blink = false) noexcept {
			std::fputs(xieite::term::cursor_undersc_code(blink).c_str(), this->out);
		}

		[[nodiscard]] static constexpr std::string cursor_pipe_code(bool blink = false) noexcept {
			return "\1\x1B["s + xieite::str_num(6 - blink) + "q\2"s;
		}

		void cursor_pipe(bool blink = false) noexcept {
			std::fputs(xieite::term::cursor_pipe_code(blink).c_str(), this->out);
		}

		[[nodiscard]] static constexpr std::string cursor_alt_code(bool x) noexcept {
			return "\x1B["s + "us"[x];
		}

		void cursor_alt(bool x) noexcept {
			if (this->is_cursor_alt != x) {
				this->is_cursor_alt = x;
				std::fputs(xieite::term::cursor_alt_code(x).c_str(), this->out);
			}
		}

		[[nodiscard]] static constexpr std::string screen_alt_code(bool x) noexcept {
			return "\x1B[?47"s + "lh"[x];
		}

		void screen_alt(bool x) noexcept {
			if (this->is_screen_alt != x) {
				this->is_screen_alt = x;
				std::fputs(xieite::term::screen_alt_code(x).c_str(), this->out);
			}
		}

		[[nodiscard]] xieite::pos screen_size() noexcept {
			::winsize size;
			::ioctl(::fileno(this->in), TIOCGWINSZ, &size);
			return xieite::pos(size.ws_row, size.ws_col);
		}

		[[nodiscard]] static constexpr std::string clear_screen_code() noexcept {
			return "\x1B[2J";
		}

		void clear_screen() noexcept {
			std::fputs(xieite::term::clear_screen_code().c_str(), this->out);
		}

		[[nodiscard]] static constexpr std::string clear_screen_until_code() noexcept {
			return "\x1B[1J";
		}
		
		void clear_screen_until() noexcept {
			std::fputs(xieite::term::clear_screen_until_code().c_str(), this->out);
		}

		[[nodiscard]] static constexpr std::string clear_screen_from_code() noexcept {
			return "\x1B[0J";
		}
		
		void clear_screen_from() noexcept {
			std::fputs(xieite::term::clear_screen_from_code().c_str(), this->out);
		}

		[[nodiscard]] static constexpr std::string clear_line_code() noexcept {
			return "\x1B[2K";
		}

		void clear_line() noexcept {
			std::fputs(xieite::term::clear_line_code().c_str(), this->out);
		}

		[[nodiscard]] static constexpr std::string clear_line_until_code() noexcept {
			return "\x1B[1K";
		}

		void clear_line_until() noexcept {
			std::fputs(xieite::term::clear_line_until_code().c_str(), this->out);
		}

		[[nodiscard]] static constexpr std::string clear_line_from_code() noexcept {
			return "\x1B[0K";
		}

		void clear_line_from() noexcept {
			std::fputs(xieite::term::clear_line_from_code().c_str(), this->out);
		}

		[[nodiscard]] int read_ch() noexcept {
			const bool canon_prev = this->is_canon;
			this->canon(false);
			const int c = std::fgetc(this->in);
			this->canon(canon_prev);
			return c;
		}

		[[nodiscard]] std::string read_str() noexcept {
			const bool block_prev = this->is_block;
			const bool canon_prev = this->is_canon;
			this->block(false);
			this->canon(false);
			const std::string input = xieite::read(this->in);
			this->block(block_prev);
			this->canon(canon_prev);
			return input;
		}

		[[nodiscard]] xieite::keys read_key() noexcept {
			const xieite::scope_guard _ = [this, block_prev = this->is_block] { this->block(block_prev); };
			const int c0 = this->read_ch();
			this->block(false);
			switch (c0) {
			case 0x00:
				switch (const int c1 = this->read_ch()) {
				case 0x00:
					return xieite::keys::pause;
				case 0x03:
					return xieite::keys::null;
				default:
					std::ungetc(c1, this->in);
				}
				break;
			case 0x01:
				return xieite::keys::ctrl_a;
			case 0x02:
				return xieite::keys::ctrl_b;
			case 0x03:
				return xieite::keys::ctrl_c;
			case 0x04:
				return xieite::keys::ctrl_d;
			case 0x05:
				return xieite::keys::ctrl_e;
			case 0x06:
				return xieite::keys::ctrl_f;
			case 0x07:
				return xieite::keys::ctrl_g;
			case 0x08:
				return xieite::keys::ctrl_h;
			case 0x09:
				return xieite::keys::ctrl_i;
			case 0x0A:
				return xieite::keys::ctrl_j;
			case 0x0B:
				return xieite::keys::ctrl_k;
			case 0x0C:
				return xieite::keys::ctrl_l;
			case 0x0D:
				return xieite::keys::ctrl_m;
			case 0x0E:
				return xieite::keys::ctrl_n;
			case 0x0F:
				return xieite::keys::ctrl_o;
			case 0x10:
				return xieite::keys::ctrl_p;
			case 0x11:
				return xieite::keys::ctrl_q;
			case 0x12:
				return xieite::keys::ctrl_r;
			case 0x13:
				return xieite::keys::ctrl_s;
			case 0x14:
				return xieite::keys::ctrl_t;
			case 0x15:
				return xieite::keys::ctrl_u;
			case 0x16:
				return xieite::keys::ctrl_v;
			case 0x17:
				return xieite::keys::ctrl_w;
			case 0x18:
				return xieite::keys::ctrl_x;
			case 0x19:
				return xieite::keys::ctrl_y;
			case 0x1A:
				return xieite::keys::ctrl_z;
			case 0x1B:
				switch (const int c1 = this->read_ch()) {
				case 0x01:
					return xieite::keys::ctrl_alt_a;
				case 0x02:
					return xieite::keys::ctrl_alt_b;
				case 0x03:
					return xieite::keys::ctrl_alt_c;
				case 0x04:
					return xieite::keys::ctrl_alt_d;
				case 0x05:
					return xieite::keys::ctrl_alt_e;
				case 0x06:
					return xieite::keys::ctrl_alt_f;
				case 0x07:
					return xieite::keys::ctrl_alt_g;
				case 0x08:
					return xieite::keys::ctrl_alt_h;
				case 0x09:
					return xieite::keys::ctrl_alt_i;
				case 0x0A:
					return xieite::keys::ctrl_alt_j;
				case 0x0B:
					return xieite::keys::ctrl_alt_k;
				case 0x0C:
					return xieite::keys::ctrl_alt_l;
				case 0x0D:
					return xieite::keys::ctrl_alt_m;
				case 0x0E:
					return xieite::keys::ctrl_alt_n;
				case 0x0F:
					return xieite::keys::ctrl_alt_o;
				case 0x10:
					return xieite::keys::ctrl_alt_p;
				case 0x11:
					return xieite::keys::ctrl_alt_q;
				case 0x12:
					return xieite::keys::ctrl_alt_r;
				case 0x13:
					return xieite::keys::ctrl_alt_s;
				case 0x14:
					return xieite::keys::ctrl_alt_t;
				case 0x15:
					return xieite::keys::ctrl_alt_u;
				case 0x16:
					return xieite::keys::ctrl_alt_v;
				case 0x17:
					return xieite::keys::ctrl_alt_w;
				case 0x18:
					return xieite::keys::ctrl_alt_x;
				case 0x19:
					return xieite::keys::ctrl_alt_y;
				case 0x1A:
					return xieite::keys::ctrl_alt_z;
				case 0x20:
					return xieite::keys::alt_sp;
				case 0x21:
					return xieite::keys::alt_bang;
				case 0x22:
					return xieite::keys::alt_quot;
				case 0x23:
					return xieite::keys::alt_hash;
				case 0x24:
					return xieite::keys::alt_dollar;
				case 0x25:
					return xieite::keys::alt_pc;
				case 0x26:
					return xieite::keys::alt_et;
				case 0x27:
					return xieite::keys::alt_apos;
				case 0x28:
					return xieite::keys::alt_lparen;
				case 0x29:
					return xieite::keys::alt_rparen;
				case 0x2A:
					return xieite::keys::alt_star;
				case 0x2B:
					return xieite::keys::alt_plus;
				case 0x2C:
					return xieite::keys::alt_comma;
				case 0x2D:
					return xieite::keys::alt_dash;
				case 0x2E:
					return xieite::keys::alt_dot;
				case 0x2F:
					return xieite::keys::alt_sl;
				case 0x30:
					return xieite::keys::alt_0;
				case 0x31:
					return xieite::keys::alt_1;
				case 0x32:
					return xieite::keys::alt_2;
				case 0x33:
					return xieite::keys::alt_3;
				case 0x34:
					return xieite::keys::alt_4;
				case 0x35:
					return xieite::keys::alt_5;
				case 0x36:
					return xieite::keys::alt_6;
				case 0x37:
					return xieite::keys::alt_7;
				case 0x38:
					return xieite::keys::alt_8;
				case 0x39:
					return xieite::keys::alt_9;
				case 0x3A:
					return xieite::keys::alt_col;
				case 0x3B:
					return xieite::keys::alt_semicol;
				case 0x3C:
					return xieite::keys::alt_lt;
				case 0x3D:
					return xieite::keys::alt_eq;
				case 0x3E:
					return xieite::keys::alt_gt;
				case 0x3F:
					return xieite::keys::alt_hook;
				case 0x40:
					return xieite::keys::alt_at;
				case 0x41:
					return xieite::keys::alt_A;
				case 0x42:
					return xieite::keys::alt_B;
				case 0x43:
					return xieite::keys::alt_C;
				case 0x44:
					return xieite::keys::alt_D;
				case 0x45:
					return xieite::keys::alt_E;
				case 0x46:
					return xieite::keys::alt_F;
				case 0x47:
					return xieite::keys::alt_G;
				case 0x48:
					return xieite::keys::alt_H;
				case 0x49:
					return xieite::keys::alt_I;
				case 0x4A:
					return xieite::keys::alt_J;
				case 0x4B:
					return xieite::keys::alt_K;
				case 0x4C:
					return xieite::keys::alt_L;
				case 0x4D:
					return xieite::keys::alt_M;
				case 0x4E:
					return xieite::keys::alt_N;
				case 0x4F:
					switch (const int c2 = this->read_ch()) {
					case 0x50:
						return xieite::keys::f1;
					case 0x51:
						return xieite::keys::f2;
					case 0x52:
						return xieite::keys::f3;
					case 0x53:
						return xieite::keys::f4;
					default:
						std::ungetc(c2, this->in);
					}
					return xieite::keys::alt_O;
				case 0x50:
					return xieite::keys::alt_P;
				case 0x51:
					return xieite::keys::alt_Q;
				case 0x52:
					return xieite::keys::alt_R;
				case 0x53:
					return xieite::keys::alt_S;
				case 0x54:
					return xieite::keys::alt_T;
				case 0x55:
					return xieite::keys::alt_U;
				case 0x56:
					return xieite::keys::alt_V;
				case 0x57:
					return xieite::keys::alt_W;
				case 0x58:
					return xieite::keys::alt_X;
				case 0x59:
					return xieite::keys::alt_Y;
				case 0x5A:
					return xieite::keys::alt_Z;
				case 0x5B:
					{
						const int c2 = this->read_ch();
						const int c3 = this->read_ch();
						if (c3 == 0x7E) {
							switch (c2) {
							case 0x20:
								return xieite::keys::np_0;
							case 0x21:
								return xieite::keys::np_dot;
							case 0x23:
								return xieite::keys::np_9;
							case 0x24:
								return xieite::keys::np_3;
							}
						}
						switch (c2) {
						case 0x29:
							return xieite::keys::np_8;
						case 0x2A:
							return xieite::keys::np_2;
						case 0x2B:
							return xieite::keys::np_6;
						case 0x2C:
							return xieite::keys::np_4;
						case 0x2D:
							return xieite::keys::np_5;
						case 0x2E:
							return xieite::keys::np_1;
						case 0x30:
							return xieite::keys::np_7;
						case 0x31:
							if (const int c4 = this->read_ch(); c4 == 0x7E) {
								switch (c3) {
								case 0x35:
									return xieite::keys::f5;
								case 0x37:
									return xieite::keys::f6;
								case 0x38:
									return xieite::keys::f7;
								case 0x39:
									return xieite::keys::f8;
								}
								std::ungetc(c4, this->in);
							}
							break;
						case 0x32:
							if (const int c4 = this->read_ch(); c4 == 0x7E) {
								switch (c3) {
								case 0x30:
									return xieite::keys::f9;
								case 0x31:
									return xieite::keys::f10;
								case 0x33:
									return xieite::keys::f11;
								case 0x34:
									return xieite::keys::f12;
								}
								std::ungetc(c4, this->in);
							}
							break;
						case 0x41:
							return xieite::keys::up;
						case 0x42:
							return xieite::keys::down;
						case 0x43:
							return xieite::keys::right;
						case 0x44:
							return xieite::keys::left;
						case 0x5B:
							switch (c3) {
							case 0x41:
								return xieite::keys::f1;
							case 0x42:
								return xieite::keys::f2;
							case 0x43:
								return xieite::keys::f3;
							case 0x44:
								return xieite::keys::f4;
							case 0x45:
								return xieite::keys::f5;
							}
							break;
						}
						std::ungetc(c3, this->in);
						std::ungetc(c2, this->in);
					}
					return xieite::keys::alt_lbrack;
				case 0x5C:
					return xieite::keys::alt_backsl;
				case 0x5D:
					return xieite::keys::alt_rbrack;
				case 0x5E:
					return xieite::keys::alt_caret;
				case 0x5F:
					return xieite::keys::alt_undersc;
				case 0x60:
					return xieite::keys::alt_grave;
				case 0x61:
					return xieite::keys::alt_a;
				case 0x62:
					return xieite::keys::alt_b;
				case 0x63:
					return xieite::keys::alt_c;
				case 0x64:
					return xieite::keys::alt_d;
				case 0x65:
					return xieite::keys::alt_e;
				case 0x66:
					return xieite::keys::alt_f;
				case 0x67:
					return xieite::keys::alt_g;
				case 0x68:
					return xieite::keys::alt_h;
				case 0x69:
					return xieite::keys::alt_i;
				case 0x6A:
					return xieite::keys::alt_j;
				case 0x6B:
					return xieite::keys::alt_k;
				case 0x6C:
					return xieite::keys::alt_l;
				case 0x6D:
					return xieite::keys::alt_m;
				case 0x6E:
					return xieite::keys::alt_n;
				case 0x6F:
					return xieite::keys::alt_o;
				case 0x70:
					return xieite::keys::alt_p;
				case 0x71:
					return xieite::keys::alt_q;
				case 0x72:
					return xieite::keys::alt_r;
				case 0x73:
					return xieite::keys::alt_s;
				case 0x74:
					return xieite::keys::alt_t;
				case 0x75:
					return xieite::keys::alt_u;
				case 0x76:
					return xieite::keys::alt_v;
				case 0x77:
					return xieite::keys::alt_w;
				case 0x78:
					return xieite::keys::alt_x;
				case 0x79:
					return xieite::keys::alt_y;
				case 0x7A:
					return xieite::keys::alt_z;
				case 0x7B:
					return xieite::keys::alt_lbrace;
				case 0x7C:
					return xieite::keys::alt_pipe;
				case 0x7D:
					return xieite::keys::alt_rbrace;
				case 0x7E:
					return xieite::keys::alt_tilde;
				case 0x7F:
					return xieite::keys::alt_backsp;
				default:
					std::ungetc(c1, this->in);
				}
				// TODO: Detect keys F13 through F24
				break;
			case 0x20:
				return xieite::keys::sp;
			case 0x21:
				return xieite::keys::b;
			case 0x22:
				return xieite::keys::quot;
			case 0x23:
				return xieite::keys::hash;
			case 0x24:
				return xieite::keys::dollar;
			case 0x25:
				return xieite::keys::pc;
			case 0x26:
				return xieite::keys::et;
			case 0x27:
				return xieite::keys::apos;
			case 0x28:
				return xieite::keys::lparen;
			case 0x29:
				return xieite::keys::rparen;
			case 0x2A:
				return xieite::keys::star;
			case 0x2B:
				return xieite::keys::plus;
			case 0x2C:
				return xieite::keys::comma;
			case 0x2D:
				return xieite::keys::dash;
			case 0x2E:
				return xieite::keys::dot;
			case 0x2F:
				return xieite::keys::sl;
			case 0x30:
				return xieite::keys::_0;
			case 0x31:
				return xieite::keys::_1;
			case 0x32:
				return xieite::keys::_2;
			case 0x33:
				return xieite::keys::_3;
			case 0x34:
				return xieite::keys::_4;
			case 0x35:
				return xieite::keys::_5;
			case 0x36:
				return xieite::keys::_6;
			case 0x37:
				return xieite::keys::_7;
			case 0x38:
				return xieite::keys::_8;
			case 0x39:
				return xieite::keys::_9;
			case 0x3A:
				return xieite::keys::col;
			case 0x3B:
				return xieite::keys::semicol;
			case 0x3C:
				return xieite::keys::lt;
			case 0x3D:
				return xieite::keys::eq;
			case 0x3E:
				return xieite::keys::gt;
			case 0x3F:
				return xieite::keys::hook;
			case 0x40:
				return xieite::keys::at;
			case 0x41:
				return xieite::keys::A;
			case 0x42:
				return xieite::keys::B;
			case 0x43:
				return xieite::keys::C;
			case 0x44:
				return xieite::keys::D;
			case 0x45:
				return xieite::keys::E;
			case 0x46:
				return xieite::keys::F;
			case 0x47:
				return xieite::keys::G;
			case 0x48:
				return xieite::keys::H;
			case 0x49:
				return xieite::keys::I;
			case 0x4A:
				return xieite::keys::J;
			case 0x4B:
				return xieite::keys::K;
			case 0x4C:
				return xieite::keys::L;
			case 0x4D:
				return xieite::keys::M;
			case 0x4E:
				return xieite::keys::N;
			case 0x4F:
				return xieite::keys::O;
			case 0x50:
				return xieite::keys::P;
			case 0x51:
				return xieite::keys::Q;
			case 0x52:
				return xieite::keys::R;
			case 0x53:
				return xieite::keys::S;
			case 0x54:
				return xieite::keys::T;
			case 0x55:
				return xieite::keys::U;
			case 0x56:
				return xieite::keys::V;
			case 0x57:
				return xieite::keys::W;
			case 0x58:
				return xieite::keys::X;
			case 0x59:
				return xieite::keys::Y;
			case 0x5A:
				return xieite::keys::Z;
			case 0x5B:
				return xieite::keys::lbrack;
			case 0x5C:
				return xieite::keys::backsl;
			case 0x5D:
				return xieite::keys::rbrack;
			case 0x5E:
				return xieite::keys::caret;
			case 0x5F:
				return xieite::keys::undersc;
			case 0x60:
				return xieite::keys::grave;
			case 0x61:
				return xieite::keys::a;
			case 0x62:
				return xieite::keys::b;
			case 0x63:
				return xieite::keys::c;
			case 0x64:
				return xieite::keys::d;
			case 0x65:
				return xieite::keys::e;
			case 0x66:
				return xieite::keys::f;
			case 0x67:
				return xieite::keys::g;
			case 0x68:
				return xieite::keys::h;
			case 0x69:
				return xieite::keys::i;
			case 0x6A:
				return xieite::keys::j;
			case 0x6B:
				return xieite::keys::k;
			case 0x6C:
				return xieite::keys::l;
			case 0x6D:
				return xieite::keys::m;
			case 0x6E:
				return xieite::keys::n;
			case 0x6F:
				return xieite::keys::o;
			case 0x70:
				return xieite::keys::p;
			case 0x71:
				return xieite::keys::q;
			case 0x72:
				return xieite::keys::r;
			case 0x73:
				return xieite::keys::s;
			case 0x74:
				return xieite::keys::t;
			case 0x75:
				return xieite::keys::u;
			case 0x76:
				return xieite::keys::v;
			case 0x77:
				return xieite::keys::w;
			case 0x78:
				return xieite::keys::x;
			case 0x79:
				return xieite::keys::y;
			case 0x7A:
				return xieite::keys::z;
			case 0x7B:
				return xieite::keys::lbrace;
			case 0x7C:
				return xieite::keys::pipe;
			case 0x7D:
				return xieite::keys::rbrace;
			case 0x7E:
				return xieite::keys::tilde;
			case 0x7F:
				return xieite::keys::backsp;
			}
			std::ungetc(c0, this->in);
			return xieite::keys::unknown;
		}

	private:
		const int block_mode;
		::termios cooked_mode;

		bool is_block = false;
		bool is_echo = false;
		bool is_canon = false;
		bool is_signal = false;
		bool is_proc = false;

		bool is_cursor_invis = false;
		bool is_cursor_alt = false;
		bool is_screen_alt = false;

		void flush() noexcept {
			::fcntl(::fileno(this->in), F_SETFL, this->block_mode | (O_NONBLOCK * !this->is_block));
			::termios raw_mode = this->cooked_mode;
			raw_mode.c_iflag &= ~static_cast<::tcflag_t>((ICRNL * !this->is_signal) | (IXON * !this->is_signal));
			raw_mode.c_lflag &= ~static_cast<::tcflag_t>((ECHO * !this->is_echo) | (ICANON * !this->is_canon) | (IEXTEN * !this->is_signal) | (ISIG * !this->is_signal));
			raw_mode.c_oflag &= ~static_cast<::tcflag_t>(OPOST * !this->is_proc);
			::tcsetattr(::fileno(this->in), TCSANOW, &raw_mode);
		}
	};
}

#endif
