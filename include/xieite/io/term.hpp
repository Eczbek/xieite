#pragma once

#include <cstdio>
#include <memory>
#include <print>
#include <stdio.h>
#include <string>
#include "../fn/scope_guard.hpp"
#include "../io/kb.hpp"
#include "../io/read.hpp"
#include "../math/abs.hpp"
#include "../math/color3.hpp"
#include "../math/str_num.hpp"
#include "../math/vec2.hpp"
#include "../pp/pltf.hpp"

#if !XIEITE_PLTF_TYPE_UNIX
#	warning "unsupported platform"
#endif

#include <fcntl.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <unistd.h>

namespace xieite {
	struct term {
	public:
		std::FILE* in;
		std::FILE* out;

		[[nodiscard]] term(std::FILE* in = stdin, std::FILE* out = stdout) noexcept
		: in(in), out(out), block_mode(::fcntl(::fileno(in), F_GETFL)) {
			::tcgetattr(::fileno(this->in), std::addressof(this->cooked_mode));
			this->is_block = !(this->block_mode & O_NONBLOCK);
			this->is_echo = this->cooked_mode.c_lflag & ECHO;
			this->is_canon = this->cooked_mode.c_lflag & ICANON;
			this->is_signal = (this->cooked_mode.c_iflag & IXON) || (this->cooked_mode.c_iflag & ICRNL) || (this->cooked_mode.c_lflag & IEXTEN) || (this->cooked_mode.c_lflag & ISIG);
			this->is_proc = this->cooked_mode.c_oflag & OPOST;
			this->flush();
		}

		term(const xieite::term&) = delete;

		~term() {
			this->reset_mode();
			this->reset_style();
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
			return "\x1B[38;2;" + xieite::str_num(r) + ";" + xieite::str_num(g) + ";" + xieite::str_num(b) + "m";
		}

		[[nodiscard]] static constexpr std::string fg_code(const xieite::color3& color) noexcept {
			return xieite::term::fg_code(color.r, color.g, color.b);
		}

		void fg(std::uint8_t r, std::uint8_t g, std::uint8_t b) noexcept {
			std::print(this->out, "{}", r, g, b);
		}

		void fg(const xieite::color3& color) noexcept {
			this->fg(color.r, color.g, color.b);
		}

		[[nodiscard]] static constexpr std::string fg_reset_code() noexcept {
			return "\x1B[38m";
		}

		void fg_reset() noexcept {
			std::print(this->out, "{}", xieite::term::fg_reset_code());
		}

		[[nodiscard]] static constexpr std::string bg_code(std::uint8_t r, std::uint8_t g, std::uint8_t b) noexcept {
			return "\x1B[48;2;" + xieite::str_num(r) + ";" + xieite::str_num(g) + ";" + xieite::str_num(b) + "m";
		}

		[[nodiscard]] static constexpr std::string bg_code(const xieite::color3& color) noexcept {
			return xieite::term::bg_code(color.r, color.g, color.b);
		}

		void bg(std::uint8_t r, std::uint8_t g, std::uint8_t b) noexcept {
			std::print(this->out, "{}", xieite::term::bg_code(r, g, b));
		}

		void bg(const xieite::color3& color) noexcept {
			this->bg(color.r, color.g, color.b);
		}

		[[nodiscard]] static constexpr std::string bg_reset_code() noexcept {
			return "\x1B[48m";
		}

		void bg_reset() noexcept {
			std::print(this->out, "{}", xieite::term::bg_reset_code());
		}

		[[nodiscard]] static constexpr std::string bold_code(bool x) noexcept {
			return x ? "\x1B[1m" : "\x1B[21m";
		}

		void bold(bool x) noexcept {
			std::print(this->out, "{}", xieite::term::bold_code(x));
		}

		[[nodiscard]] static constexpr std::string italic_code(bool x) noexcept {
			return x ? "\x1B[3m" : "\x1B[23m";
		}

		void italic(bool x) noexcept {
			std::print(this->out, "{}", xieite::term::italic_code(x));
		}

		[[nodiscard]] static constexpr std::string underl_code(bool x) noexcept {
			return x ? "\x1B[4m" : "\x1B[24m";
		}

		void underl(bool x) noexcept {
			std::print(this->out, "{}", xieite::term::underl_code(x));
		}

		[[nodiscard]] static constexpr std::string blink_code(bool x) noexcept {
			return x ? "\x1B[5m" : "\x1B[25m";
		}

		void blink(bool x) noexcept {
			std::print(this->out, "{}", xieite::term::blink_code(x));
		}

		[[nodiscard]] static constexpr std::string invis_code(bool x) noexcept {
			return x ? "\x1B[8m" : "\x1B[28m";
		}

		void invis(bool x) noexcept {
			std::print(this->out, "{}", xieite::term::invis_code(x));
		}

		[[nodiscard]] static constexpr std::string strike_code(bool x) noexcept {
			return x ? "\x1B[9m" : "\x1B[29m";
		}

		void strike(bool x) noexcept {
			std::print(this->out, "{}", xieite::term::strike_code(x));
		}

		[[nodiscard]] static constexpr std::string invert_code(bool x) noexcept {
			return x ? "\x1B[7m" : "\x1B[27m";
		}
		
		void invert(bool x) noexcept {
			std::print(this->out, "{}", xieite::term::invert_code(x));
		}

		[[nodiscard]] static constexpr std::string reset_style_code() noexcept {
			return "\x1B[0m";
		}

		void reset_style() noexcept {
			this->curs_invis(false);
			this->curs_alt(false);
			this->scr_alt(false);
			std::print(this->out, "{}", xieite::term::reset_style_code());
		}
		
		void reset_mode() noexcept {
			::fcntl(::fileno(this->in), F_SETFL, this->block_mode);
			::tcsetattr(::fileno(this->in), TCSANOW, std::addressof(this->cooked_mode));
		}

		[[nodiscard]] xieite::vec2<int> get_curs() noexcept {
			const bool canon_prev = this->is_canon;
			this->canon(false);
			std::print(this->out, "\x1B[6n");
			xieite::vec2<int> pos;
			std::fscanf(this->in, "\x1B[%i;%iR", &pos.y, &pos.x);
			this->canon(canon_prev);
			return pos - 1;
		}

		[[nodiscard]] constexpr std::string set_curs_code(int x, int y) noexcept {
			return "\x1B[" + xieite::str_num(y + 1) + ";" + xieite::str_num(x + 1) + "H";
		}

		[[nodiscard]] constexpr std::string set_curs_code(xieite::vec2<int> pos) noexcept {
			return xieite::term::set_curs_code(pos.x, pos.y);
		}

		void set_curs(int x, int y) noexcept {
			std::print(this->out, "{}", xieite::term::set_curs_code(x, y));
		}

		void set_curs(xieite::vec2<int> pos) noexcept {
			this->set_curs(pos.x, pos.y);
		}

		[[nodiscard]] constexpr std::string mv_curs_code(int x, int y) noexcept {
			std::string code;
			if (x) {
				code += "\x1B[";
				code += xieite::str_num(xieite::abs(x));
				code += "CD"[x < 0];
			}
			if (y) {
				code += "\x1B[";
				code += xieite::str_num(xieite::abs(y));
				code += "BA"[y < 0];
			}
			return code;
		}

		[[nodiscard]] constexpr std::string mv_curs_code(xieite::vec2<int> diff) noexcept {
			return xieite::term::mv_curs_code(diff.x, diff.y);
		}

		void mv_curs(int x, int y) noexcept {
			std::print(this->out, "{}", xieite::term::mv_curs_code(x, y));
		}

		void mv_curs(xieite::vec2<int> diff) noexcept {
			this->mv_curs(diff.x, diff.y);
		}

		[[nodiscard]] static constexpr std::string curs_invis_code(bool x) noexcept {
			return std::string("\x1B[?25") + "hl"[x];
		}

		void curs_invis(bool x) noexcept {
			std::print(this->out, "{}", xieite::term::curs_invis_code(x));
		}

		[[nodiscard]] static constexpr std::string curs_block_code(bool blink = false) noexcept {
			return "\1\x1B[" + xieite::str_num(2 - blink) + "q\2";
		}

		void curs_block(bool blink = false) noexcept {
			std::print(this->out, "{}", xieite::term::curs_block_code(blink));
		}

		[[nodiscard]] static constexpr std::string curs_undersc_code(bool blink = false) noexcept {
			return "\1\x1B[" + xieite::str_num(4 - blink) + "q\2";
		}

		void curs_undersc(bool blink = false) noexcept {
			std::print(this->out, "{}", xieite::term::curs_undersc_code(blink));
		}

		[[nodiscard]] static constexpr std::string curs_pipe_code(bool blink = false) noexcept {
			return "\1\x1B[" + xieite::str_num(6 - blink) + "q\2";
		}

		void curs_pipe(bool blink = false) noexcept {
			std::print(this->out, "{}", xieite::term::curs_pipe_code(blink));
		}

		[[nodiscard]] static constexpr std::string curs_alt_code(bool x) noexcept {
			return std::string("\x1B[") + "us"[x];
		}

		void curs_alt(bool x) noexcept {
			std::print(this->out, "{}", xieite::term::curs_alt_code(x));
		}

		[[nodiscard]] static constexpr std::string scr_alt_code(bool x) noexcept {
			return std::string("\x1B[?47") + "lh"[x];
		}

		void scr_alt(bool x) noexcept {
			std::print(this->out, "{}", xieite::term::scr_alt_code(x));
		}

		[[nodiscard]] xieite::vec2<int> scr_size() noexcept {
			::winsize size;
			::ioctl(::fileno(this->in), TIOCGWINSZ, std::addressof(size));
			return xieite::vec2<int>(size.ws_col, size.ws_row);
		}

		[[nodiscard]] static constexpr std::string clr_scr_code() noexcept {
			return "\x1B[2J";
		}

		void clr_scr() noexcept {
			std::print(this->out, "{}", xieite::term::clr_scr_code());
		}

		[[nodiscard]] static constexpr std::string clr_scr_until_code() noexcept {
			return "\x1B[1J";
		}
		
		void clr_scr_until() noexcept {
			std::print(this->out, "{}", xieite::term::clr_scr_until_code());
		}

		[[nodiscard]] static constexpr std::string clr_scr_from_code() noexcept {
			return "\x1B[0J";
		}
		
		void clr_scr_from() noexcept {
			std::print(this->out, "{}", xieite::term::clr_scr_from_code());
		}

		[[nodiscard]] static constexpr std::string clr_line_code() noexcept {
			return "\x1B[2K";
		}

		void clr_line() noexcept {
			std::print(this->out, "{}", xieite::term::clr_line_code());
		}

		[[nodiscard]] static constexpr std::string clr_line_until_code() noexcept {
			return "\x1B[1K";
		}

		void clr_line_until() noexcept {
			std::print(this->out, "{}", xieite::term::clr_line_until_code());
		}

		[[nodiscard]] static constexpr std::string clr_line_from_code() noexcept {
			return "\x1B[0K";
		}

		void clr_line_from() noexcept {
			std::print(this->out, "{}", xieite::term::clr_line_from_code());
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

		[[nodiscard]] xieite::kb read_key() noexcept {
			const xieite::scope_guard _ = [this, block_prev = this->is_block] -> void {
				this->block(block_prev);
			};
			const int c0 = this->read_ch();
			this->block(false);
			switch (c0) {
			case 0x00:
				switch (const int c1 = this->read_ch()) {
				case 0x00:
					return xieite::kb::pause;
				case 0x03:
					return xieite::kb::null;
				default:
					std::ungetc(c1, this->in);
				}
				break;
			case 0x01:
				return xieite::kb::ctrl_a;
			case 0x02:
				return xieite::kb::ctrl_b;
			case 0x03:
				return xieite::kb::ctrl_c;
			case 0x04:
				return xieite::kb::ctrl_d;
			case 0x05:
				return xieite::kb::ctrl_e;
			case 0x06:
				return xieite::kb::ctrl_f;
			case 0x07:
				return xieite::kb::ctrl_g;
			case 0x08:
				return xieite::kb::ctrl_h;
			case 0x09:
				return xieite::kb::ctrl_i;
			case 0x0A:
				return xieite::kb::ctrl_j;
			case 0x0B:
				return xieite::kb::ctrl_k;
			case 0x0C:
				return xieite::kb::ctrl_l;
			case 0x0D:
				return xieite::kb::ctrl_m;
			case 0x0E:
				return xieite::kb::ctrl_n;
			case 0x0F:
				return xieite::kb::ctrl_o;
			case 0x10:
				return xieite::kb::ctrl_p;
			case 0x11:
				return xieite::kb::ctrl_q;
			case 0x12:
				return xieite::kb::ctrl_r;
			case 0x13:
				return xieite::kb::ctrl_s;
			case 0x14:
				return xieite::kb::ctrl_t;
			case 0x15:
				return xieite::kb::ctrl_u;
			case 0x16:
				return xieite::kb::ctrl_v;
			case 0x17:
				return xieite::kb::ctrl_w;
			case 0x18:
				return xieite::kb::ctrl_x;
			case 0x19:
				return xieite::kb::ctrl_y;
			case 0x1A:
				return xieite::kb::ctrl_z;
			case 0x1B:
				switch (const int c1 = this->read_ch()) {
				case 0x01:
					return xieite::kb::ctrl_alt_a;
				case 0x02:
					return xieite::kb::ctrl_alt_b;
				case 0x03:
					return xieite::kb::ctrl_alt_c;
				case 0x04:
					return xieite::kb::ctrl_alt_d;
				case 0x05:
					return xieite::kb::ctrl_alt_e;
				case 0x06:
					return xieite::kb::ctrl_alt_f;
				case 0x07:
					return xieite::kb::ctrl_alt_g;
				case 0x08:
					return xieite::kb::ctrl_alt_h;
				case 0x09:
					return xieite::kb::ctrl_alt_i;
				case 0x0A:
					return xieite::kb::ctrl_alt_j;
				case 0x0B:
					return xieite::kb::ctrl_alt_k;
				case 0x0C:
					return xieite::kb::ctrl_alt_l;
				case 0x0D:
					return xieite::kb::ctrl_alt_m;
				case 0x0E:
					return xieite::kb::ctrl_alt_n;
				case 0x0F:
					return xieite::kb::ctrl_alt_o;
				case 0x10:
					return xieite::kb::ctrl_alt_p;
				case 0x11:
					return xieite::kb::ctrl_alt_q;
				case 0x12:
					return xieite::kb::ctrl_alt_r;
				case 0x13:
					return xieite::kb::ctrl_alt_s;
				case 0x14:
					return xieite::kb::ctrl_alt_t;
				case 0x15:
					return xieite::kb::ctrl_alt_u;
				case 0x16:
					return xieite::kb::ctrl_alt_v;
				case 0x17:
					return xieite::kb::ctrl_alt_w;
				case 0x18:
					return xieite::kb::ctrl_alt_x;
				case 0x19:
					return xieite::kb::ctrl_alt_y;
				case 0x1A:
					return xieite::kb::ctrl_alt_z;
				case 0x20:
					return xieite::kb::alt_sp;
				case 0x21:
					return xieite::kb::alt_exclam;
				case 0x22:
					return xieite::kb::alt_quot;
				case 0x23:
					return xieite::kb::alt_hash;
				case 0x24:
					return xieite::kb::alt_dollar;
				case 0x25:
					return xieite::kb::alt_pc;
				case 0x26:
					return xieite::kb::alt_et;
				case 0x27:
					return xieite::kb::alt_apos;
				case 0x28:
					return xieite::kb::alt_lparen;
				case 0x29:
					return xieite::kb::alt_rparen;
				case 0x2A:
					return xieite::kb::alt_star;
				case 0x2B:
					return xieite::kb::alt_plus;
				case 0x2C:
					return xieite::kb::alt_comma;
				case 0x2D:
					return xieite::kb::alt_dash;
				case 0x2E:
					return xieite::kb::alt_dot;
				case 0x2F:
					return xieite::kb::alt_sl;
				case 0x30:
					return xieite::kb::alt_0;
				case 0x31:
					return xieite::kb::alt_1;
				case 0x32:
					return xieite::kb::alt_2;
				case 0x33:
					return xieite::kb::alt_3;
				case 0x34:
					return xieite::kb::alt_4;
				case 0x35:
					return xieite::kb::alt_5;
				case 0x36:
					return xieite::kb::alt_6;
				case 0x37:
					return xieite::kb::alt_7;
				case 0x38:
					return xieite::kb::alt_8;
				case 0x39:
					return xieite::kb::alt_9;
				case 0x3A:
					return xieite::kb::alt_col;
				case 0x3B:
					return xieite::kb::alt_semicol;
				case 0x3C:
					return xieite::kb::alt_lt;
				case 0x3D:
					return xieite::kb::alt_eq;
				case 0x3E:
					return xieite::kb::alt_gt;
				case 0x3F:
					return xieite::kb::alt_question;
				case 0x40:
					return xieite::kb::alt_at;
				case 0x41:
					return xieite::kb::alt_A;
				case 0x42:
					return xieite::kb::alt_B;
				case 0x43:
					return xieite::kb::alt_C;
				case 0x44:
					return xieite::kb::alt_D;
				case 0x45:
					return xieite::kb::alt_E;
				case 0x46:
					return xieite::kb::alt_F;
				case 0x47:
					return xieite::kb::alt_G;
				case 0x48:
					return xieite::kb::alt_H;
				case 0x49:
					return xieite::kb::alt_I;
				case 0x4A:
					return xieite::kb::alt_J;
				case 0x4B:
					return xieite::kb::alt_K;
				case 0x4C:
					return xieite::kb::alt_L;
				case 0x4D:
					return xieite::kb::alt_M;
				case 0x4E:
					return xieite::kb::alt_N;
				case 0x4F:
					switch (const int c2 = this->read_ch()) {
					case 0x50:
						return xieite::kb::f1;
					case 0x51:
						return xieite::kb::f2;
					case 0x52:
						return xieite::kb::f3;
					case 0x53:
						return xieite::kb::f4;
					default:
						std::ungetc(c2, this->in);
					}
					return xieite::kb::alt_O;
				case 0x50:
					return xieite::kb::alt_P;
				case 0x51:
					return xieite::kb::alt_Q;
				case 0x52:
					return xieite::kb::alt_R;
				case 0x53:
					return xieite::kb::alt_S;
				case 0x54:
					return xieite::kb::alt_T;
				case 0x55:
					return xieite::kb::alt_U;
				case 0x56:
					return xieite::kb::alt_V;
				case 0x57:
					return xieite::kb::alt_W;
				case 0x58:
					return xieite::kb::alt_X;
				case 0x59:
					return xieite::kb::alt_Y;
				case 0x5A:
					return xieite::kb::alt_Z;
				case 0x5B:
					{
						const int c2 = this->read_ch();
						const int c3 = this->read_ch();
						if (c3 == 0x7E) {
							switch (c2) {
							case 0x20:
								return xieite::kb::np_0;
							case 0x21:
								return xieite::kb::np_dot;
							case 0x23:
								return xieite::kb::np_9;
							case 0x24:
								return xieite::kb::np_3;
							}
						}
						switch (c2) {
						case 0x29:
							return xieite::kb::np_8;
						case 0x2A:
							return xieite::kb::np_2;
						case 0x2B:
							return xieite::kb::np_6;
						case 0x2C:
							return xieite::kb::np_4;
						case 0x2D:
							return xieite::kb::np_5;
						case 0x2E:
							return xieite::kb::np_1;
						case 0x30:
							return xieite::kb::np_7;
						case 0x31:
							if (const int c4 = this->read_ch(); c4 == 0x7E) {
								switch (c3) {
								case 0x35:
									return xieite::kb::f5;
								case 0x37:
									return xieite::kb::f6;
								case 0x38:
									return xieite::kb::f7;
								case 0x39:
									return xieite::kb::f8;
								}
								std::ungetc(c4, this->in);
							}
							break;
						case 0x32:
							if (const int c4 = this->read_ch(); c4 == 0x7E) {
								switch (c3) {
								case 0x30:
									return xieite::kb::f9;
								case 0x31:
									return xieite::kb::f10;
								case 0x33:
									return xieite::kb::f11;
								case 0x34:
									return xieite::kb::f12;
								}
								std::ungetc(c4, this->in);
							}
							break;
						case 0x5B:
							switch (c3) {
							case 0x41:
								return xieite::kb::f1;
							case 0x42:
								return xieite::kb::f2;
							case 0x43:
								return xieite::kb::f3;
							case 0x44:
								return xieite::kb::f4;
							case 0x45:
								return xieite::kb::f5;
							}
							break;
						}
						std::ungetc(c3, this->in);
						std::ungetc(c2, this->in);
					}
					return xieite::kb::alt_lbrack;
				case 0x5C:
					return xieite::kb::alt_backsl;
				case 0x5D:
					return xieite::kb::alt_rbrack;
				case 0x5E:
					return xieite::kb::alt_caret;
				case 0x5F:
					return xieite::kb::alt_undersc;
				case 0x60:
					return xieite::kb::alt_grave;
				case 0x61:
					return xieite::kb::alt_a;
				case 0x62:
					return xieite::kb::alt_b;
				case 0x63:
					return xieite::kb::alt_c;
				case 0x64:
					return xieite::kb::alt_d;
				case 0x65:
					return xieite::kb::alt_e;
				case 0x66:
					return xieite::kb::alt_f;
				case 0x67:
					return xieite::kb::alt_g;
				case 0x68:
					return xieite::kb::alt_h;
				case 0x69:
					return xieite::kb::alt_i;
				case 0x6A:
					return xieite::kb::alt_j;
				case 0x6B:
					return xieite::kb::alt_k;
				case 0x6C:
					return xieite::kb::alt_l;
				case 0x6D:
					return xieite::kb::alt_m;
				case 0x6E:
					return xieite::kb::alt_n;
				case 0x6F:
					return xieite::kb::alt_o;
				case 0x70:
					return xieite::kb::alt_p;
				case 0x71:
					return xieite::kb::alt_q;
				case 0x72:
					return xieite::kb::alt_r;
				case 0x73:
					return xieite::kb::alt_s;
				case 0x74:
					return xieite::kb::alt_t;
				case 0x75:
					return xieite::kb::alt_u;
				case 0x76:
					return xieite::kb::alt_v;
				case 0x77:
					return xieite::kb::alt_w;
				case 0x78:
					return xieite::kb::alt_x;
				case 0x79:
					return xieite::kb::alt_y;
				case 0x7A:
					return xieite::kb::alt_z;
				case 0x7B:
					return xieite::kb::alt_lbrace;
				case 0x7C:
					return xieite::kb::alt_pipe;
				case 0x7D:
					return xieite::kb::alt_rbrace;
				case 0x7E:
					return xieite::kb::alt_tilde;
				case 0x7F:
					return xieite::kb::alt_backsp;
				default:
					std::ungetc(c1, this->in);
				}
				// TODO: Detect keys F13 through F24
				break;
			case 0x20:
				return xieite::kb::sp;
			case 0x21:
				return xieite::kb::exclam;
			case 0x22:
				return xieite::kb::quot;
			case 0x23:
				return xieite::kb::hash;
			case 0x24:
				return xieite::kb::dollar;
			case 0x25:
				return xieite::kb::pc;
			case 0x26:
				return xieite::kb::et;
			case 0x27:
				return xieite::kb::apos;
			case 0x28:
				return xieite::kb::lparen;
			case 0x29:
				return xieite::kb::rparen;
			case 0x2A:
				return xieite::kb::star;
			case 0x2B:
				return xieite::kb::plus;
			case 0x2C:
				return xieite::kb::comma;
			case 0x2D:
				return xieite::kb::dash;
			case 0x2E:
				return xieite::kb::dot;
			case 0x2F:
				return xieite::kb::sl;
			case 0x30:
				return xieite::kb::_0;
			case 0x31:
				return xieite::kb::_1;
			case 0x32:
				return xieite::kb::_2;
			case 0x33:
				return xieite::kb::_3;
			case 0x34:
				return xieite::kb::_4;
			case 0x35:
				return xieite::kb::_5;
			case 0x36:
				return xieite::kb::_6;
			case 0x37:
				return xieite::kb::_7;
			case 0x38:
				return xieite::kb::_8;
			case 0x39:
				return xieite::kb::_9;
			case 0x3A:
				return xieite::kb::col;
			case 0x3B:
				return xieite::kb::semicol;
			case 0x3C:
				return xieite::kb::lt;
			case 0x3D:
				return xieite::kb::eq;
			case 0x3E:
				return xieite::kb::gt;
			case 0x3F:
				return xieite::kb::question;
			case 0x40:
				return xieite::kb::at;
			case 0x41:
				return xieite::kb::A;
			case 0x42:
				return xieite::kb::B;
			case 0x43:
				return xieite::kb::C;
			case 0x44:
				return xieite::kb::D;
			case 0x45:
				return xieite::kb::E;
			case 0x46:
				return xieite::kb::F;
			case 0x47:
				return xieite::kb::G;
			case 0x48:
				return xieite::kb::H;
			case 0x49:
				return xieite::kb::I;
			case 0x4A:
				return xieite::kb::J;
			case 0x4B:
				return xieite::kb::K;
			case 0x4C:
				return xieite::kb::L;
			case 0x4D:
				return xieite::kb::M;
			case 0x4E:
				return xieite::kb::N;
			case 0x4F:
				return xieite::kb::O;
			case 0x50:
				return xieite::kb::P;
			case 0x51:
				return xieite::kb::Q;
			case 0x52:
				return xieite::kb::R;
			case 0x53:
				return xieite::kb::S;
			case 0x54:
				return xieite::kb::T;
			case 0x55:
				return xieite::kb::U;
			case 0x56:
				return xieite::kb::V;
			case 0x57:
				return xieite::kb::W;
			case 0x58:
				return xieite::kb::X;
			case 0x59:
				return xieite::kb::Y;
			case 0x5A:
				return xieite::kb::Z;
			case 0x5B:
				return xieite::kb::lbrack;
			case 0x5C:
				return xieite::kb::backsl;
			case 0x5D:
				return xieite::kb::rbrack;
			case 0x5E:
				return xieite::kb::caret;
			case 0x5F:
				return xieite::kb::undersc;
			case 0x60:
				return xieite::kb::grave;
			case 0x61:
				return xieite::kb::a;
			case 0x62:
				return xieite::kb::b;
			case 0x63:
				return xieite::kb::c;
			case 0x64:
				return xieite::kb::d;
			case 0x65:
				return xieite::kb::e;
			case 0x66:
				return xieite::kb::f;
			case 0x67:
				return xieite::kb::g;
			case 0x68:
				return xieite::kb::h;
			case 0x69:
				return xieite::kb::i;
			case 0x6A:
				return xieite::kb::j;
			case 0x6B:
				return xieite::kb::k;
			case 0x6C:
				return xieite::kb::l;
			case 0x6D:
				return xieite::kb::m;
			case 0x6E:
				return xieite::kb::n;
			case 0x6F:
				return xieite::kb::o;
			case 0x70:
				return xieite::kb::p;
			case 0x71:
				return xieite::kb::q;
			case 0x72:
				return xieite::kb::r;
			case 0x73:
				return xieite::kb::s;
			case 0x74:
				return xieite::kb::t;
			case 0x75:
				return xieite::kb::u;
			case 0x76:
				return xieite::kb::v;
			case 0x77:
				return xieite::kb::w;
			case 0x78:
				return xieite::kb::x;
			case 0x79:
				return xieite::kb::y;
			case 0x7A:
				return xieite::kb::z;
			case 0x7B:
				return xieite::kb::lbrace;
			case 0x7C:
				return xieite::kb::pipe;
			case 0x7D:
				return xieite::kb::rbrace;
			case 0x7E:
				return xieite::kb::tilde;
			case 0x7F:
				return xieite::kb::backsp;
			}
			std::ungetc(c0, this->in);
			return xieite::kb::unknown;
		}

	private:
		const int block_mode;
		::termios cooked_mode;

		bool is_block;
		bool is_echo;
		bool is_canon;
		bool is_signal;
		bool is_proc;

		void flush() noexcept {
			::fcntl(::fileno(this->in), F_SETFL, this->block_mode | (O_NONBLOCK * !this->is_block));
			::termios raw_mode = this->cooked_mode;
			raw_mode.c_iflag &= ~static_cast<::tcflag_t>((ICRNL * !this->is_signal) | (IXON * !this->is_signal));
			raw_mode.c_lflag &= ~static_cast<::tcflag_t>((ECHO * !this->is_echo) | (ICANON * !this->is_canon) | (IEXTEN * !this->is_signal) | (ISIG * !this->is_signal));
			raw_mode.c_oflag &= ~static_cast<::tcflag_t>(OPOST * !this->is_proc);
			::tcsetattr(::fileno(this->in), TCSANOW, std::addressof(raw_mode));
		}
	};
}
