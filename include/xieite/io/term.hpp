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
			this->is_process = this->cooked_mode.c_oflag & OPOST;
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

		void process(bool x) noexcept {
			if (this->is_process != x) {
				this->is_process = x;
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

		void bg(std::uint8_t r, std::uint8_t g, std::uint8_t b) {
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

		char read_ch() noexcept {
			const bool canon_prev = this->is_canon;
			this->canon(false);
			const char c = static_cast<char>(std::fgetc(this->in));
			this->canon(canon_prev);
			return c;
		}

		std::string read_str() noexcept {
			const bool block_prev = this->is_block;
			const bool canon_prev = this->is_canon;
			this->block(false);
			this->canon(false);
			const std::string input = xieite::read(this->in);
			this->block(block_prev);
			this->canon(canon_prev);
			return input;
		}

		xieite::kb read_key() noexcept {
			const xieite::scope_guard _ = [this, block_prev = this->is_block] -> void {
				this->block(block_prev);
			};
			const char c0 = this->read_ch();
			this->block(false);
			switch (c0) {
			case '\x00':
				switch (const char c1 = this->read_ch(); c1) {
				case '\x00':
					return xieite::kb::pause;
				case '\x03':
					return xieite::kb::null;
				default:
					std::ungetc(c1, this->in);
				}
				break;
			case '\x01':
				return xieite::kb::ctrl_a;
			case '\x02':
				return xieite::kb::ctrl_b;
			case '\x03':
				return xieite::kb::ctrl_c;
			case '\x04':
				return xieite::kb::ctrl_d;
			case '\x05':
				return xieite::kb::ctrl_e;
			case '\x06':
				return xieite::kb::ctrl_f;
			case '\x07':
				return xieite::kb::ctrl_g;
			case '\x08':
				return xieite::kb::ctrl_h;
			case '\x09':
				return xieite::kb::ctrl_i;
			case '\x0A':
				return xieite::kb::ctrl_j;
			case '\x0B':
				return xieite::kb::ctrl_k;
			case '\x0C':
				return xieite::kb::ctrl_l;
			case '\x0D':
				return xieite::kb::ctrl_m;
			case '\x0E':
				return xieite::kb::ctrl_n;
			case '\x0F':
				return xieite::kb::ctrl_o;
			case '\x10':
				return xieite::kb::ctrl_p;
			case '\x11':
				return xieite::kb::ctrl_q;
			case '\x12':
				return xieite::kb::ctrl_r;
			case '\x13':
				return xieite::kb::ctrl_s;
			case '\x14':
				return xieite::kb::ctrl_t;
			case '\x15':
				return xieite::kb::ctrl_u;
			case '\x16':
				return xieite::kb::ctrl_v;
			case '\x17':
				return xieite::kb::ctrl_w;
			case '\x18':
				return xieite::kb::ctrl_x;
			case '\x19':
				return xieite::kb::ctrl_y;
			case '\x1A':
				return xieite::kb::ctrl_z;
			case '\x1B':
				switch (const char c1 = this->read_ch(); c1) {
				case '\x01':
					return xieite::kb::ctrl_alt_a;
				case '\x02':
					return xieite::kb::ctrl_alt_b;
				case '\x03':
					return xieite::kb::ctrl_alt_c;
				case '\x04':
					return xieite::kb::ctrl_alt_d;
				case '\x05':
					return xieite::kb::ctrl_alt_e;
				case '\x06':
					return xieite::kb::ctrl_alt_f;
				case '\x07':
					return xieite::kb::ctrl_alt_g;
				case '\x08':
					return xieite::kb::ctrl_alt_h;
				case '\x09':
					return xieite::kb::ctrl_alt_i;
				case '\x0A':
					return xieite::kb::ctrl_alt_j;
				case '\x0B':
					return xieite::kb::ctrl_alt_k;
				case '\x0C':
					return xieite::kb::ctrl_alt_l;
				case '\x0D':
					return xieite::kb::ctrl_alt_m;
				case '\x0E':
					return xieite::kb::ctrl_alt_n;
				case '\x0F':
					return xieite::kb::ctrl_alt_o;
				case '\x10':
					return xieite::kb::ctrl_alt_p;
				case '\x11':
					return xieite::kb::ctrl_alt_q;
				case '\x12':
					return xieite::kb::ctrl_alt_r;
				case '\x13':
					return xieite::kb::ctrl_alt_s;
				case '\x14':
					return xieite::kb::ctrl_alt_t;
				case '\x15':
					return xieite::kb::ctrl_alt_u;
				case '\x16':
					return xieite::kb::ctrl_alt_v;
				case '\x17':
					return xieite::kb::ctrl_alt_w;
				case '\x18':
					return xieite::kb::ctrl_alt_x;
				case '\x19':
					return xieite::kb::ctrl_alt_y;
				case '\x1A':
					return xieite::kb::ctrl_alt_z;
				case '\x20':
					return xieite::kb::alt_sp;
				case '\x21':
					return xieite::kb::alt_exclam;
				case '\x22':
					return xieite::kb::alt_quot;
				case '\x23':
					return xieite::kb::alt_hash;
				case '\x24':
					return xieite::kb::alt_dollar;
				case '\x25':
					return xieite::kb::alt_pc;
				case '\x26':
					return xieite::kb::alt_et;
				case '\x27':
					return xieite::kb::alt_apos;
				case '\x28':
					return xieite::kb::alt_lparen;
				case '\x29':
					return xieite::kb::alt_rparen;
				case '\x2A':
					return xieite::kb::alt_star;
				case '\x2B':
					return xieite::kb::alt_plus;
				case '\x2C':
					return xieite::kb::alt_comma;
				case '\x2D':
					return xieite::kb::alt_dash;
				case '\x2E':
					return xieite::kb::alt_dot;
				case '\x2F':
					return xieite::kb::alt_sl;
				case '\x30':
					return xieite::kb::alt_0;
				case '\x31':
					return xieite::kb::alt_1;
				case '\x32':
					return xieite::kb::alt_2;
				case '\x33':
					return xieite::kb::alt_3;
				case '\x34':
					return xieite::kb::alt_4;
				case '\x35':
					return xieite::kb::alt_5;
				case '\x36':
					return xieite::kb::alt_6;
				case '\x37':
					return xieite::kb::alt_7;
				case '\x38':
					return xieite::kb::alt_8;
				case '\x39':
					return xieite::kb::alt_9;
				case '\x3A':
					return xieite::kb::alt_col;
				case '\x3B':
					return xieite::kb::alt_semicol;
				case '\x3C':
					return xieite::kb::alt_lt;
				case '\x3D':
					return xieite::kb::alt_eq;
				case '\x3E':
					return xieite::kb::alt_gt;
				case '\x3F':
					return xieite::kb::alt_question;
				case '\x40':
					return xieite::kb::alt_at;
				case '\x41':
					return xieite::kb::alt_A;
				case '\x42':
					return xieite::kb::alt_B;
				case '\x43':
					return xieite::kb::alt_C;
				case '\x44':
					return xieite::kb::alt_D;
				case '\x45':
					return xieite::kb::alt_E;
				case '\x46':
					return xieite::kb::alt_F;
				case '\x47':
					return xieite::kb::alt_G;
				case '\x48':
					return xieite::kb::alt_H;
				case '\x49':
					return xieite::kb::alt_I;
				case '\x4A':
					return xieite::kb::alt_J;
				case '\x4B':
					return xieite::kb::alt_K;
				case '\x4C':
					return xieite::kb::alt_L;
				case '\x4D':
					return xieite::kb::alt_M;
				case '\x4E':
					return xieite::kb::alt_N;
				case '\x4F':
					switch (const char c2 = this->read_ch(); c2) {
					case '\x50':
						return xieite::kb::f1;
					case '\x51':
						return xieite::kb::f2;
					case '\x52':
						return xieite::kb::f3;
					case '\x53':
						return xieite::kb::f4;
					default:
						std::ungetc(c2, this->in);
					}
					return xieite::kb::alt_O;
				case '\x50':
					return xieite::kb::alt_P;
				case '\x51':
					return xieite::kb::alt_Q;
				case '\x52':
					return xieite::kb::alt_R;
				case '\x53':
					return xieite::kb::alt_S;
				case '\x54':
					return xieite::kb::alt_T;
				case '\x55':
					return xieite::kb::alt_U;
				case '\x56':
					return xieite::kb::alt_V;
				case '\x57':
					return xieite::kb::alt_W;
				case '\x58':
					return xieite::kb::alt_X;
				case '\x59':
					return xieite::kb::alt_Y;
				case '\x5A':
					return xieite::kb::alt_Z;
				case '\x5B':
					{
						const char c2 = this->read_ch();
						const char c3 = this->read_ch();
						if (c3 == '\x7E') {
							switch (c2) {
							case '\x20':
								return xieite::kb::np_0;
							case '\x21':
								return xieite::kb::np_dot;
							case '\x23':
								return xieite::kb::np_9;
							case '\x24':
								return xieite::kb::np_3;
							}
						}
						switch (c2) {
						case '\x29':
							return xieite::kb::np_8;
						case '\x2A':
							return xieite::kb::np_2;
						case '\x2B':
							return xieite::kb::np_6;
						case '\x2C':
							return xieite::kb::np_4;
						case '\x2D':
							return xieite::kb::np_5;
						case '\x2E':
							return xieite::kb::np_1;
						case '\x30':
							return xieite::kb::np_7;
						case '\x31':
							if (const char c4 = this->read_ch(); c4 == '\x7E') {
								switch (c3) {
								case '\x35':
									return xieite::kb::f5;
								case '\x37':
									return xieite::kb::f6;
								case '\x38':
									return xieite::kb::f7;
								case '\x39':
									return xieite::kb::f8;
								}
								std::ungetc(c4, this->in);
							}
							break;
						case '\x32':
							if (const char c4 = this->read_ch(); c4 == '\x7E') {
								switch (c3) {
								case '\x30':
									return xieite::kb::f9;
								case '\x31':
									return xieite::kb::f10;
								case '\x33':
									return xieite::kb::f11;
								case '\x34':
									return xieite::kb::f12;
								}
								std::ungetc(c4, this->in);
							}
							break;
						case '\x5B':
							switch (c3) {
							case '\x41':
								return xieite::kb::f1;
							case '\x42':
								return xieite::kb::f2;
							case '\x43':
								return xieite::kb::f3;
							case '\x44':
								return xieite::kb::f4;
							case '\x45':
								return xieite::kb::f5;
							}
							break;
						}
						std::ungetc(c3, this->in);
						std::ungetc(c2, this->in);
					}
					return xieite::kb::alt_lbrack;
				case '\x5C':
					return xieite::kb::alt_backsl;
				case '\x5D':
					return xieite::kb::alt_rbrack;
				case '\x5E':
					return xieite::kb::alt_caret;
				case '\x5F':
					return xieite::kb::alt_undersc;
				case '\x60':
					return xieite::kb::alt_grave;
				case '\x61':
					return xieite::kb::alt_a;
				case '\x62':
					return xieite::kb::alt_b;
				case '\x63':
					return xieite::kb::alt_c;
				case '\x64':
					return xieite::kb::alt_d;
				case '\x65':
					return xieite::kb::alt_e;
				case '\x66':
					return xieite::kb::alt_f;
				case '\x67':
					return xieite::kb::alt_g;
				case '\x68':
					return xieite::kb::alt_h;
				case '\x69':
					return xieite::kb::alt_i;
				case '\x6A':
					return xieite::kb::alt_j;
				case '\x6B':
					return xieite::kb::alt_k;
				case '\x6C':
					return xieite::kb::alt_l;
				case '\x6D':
					return xieite::kb::alt_m;
				case '\x6E':
					return xieite::kb::alt_n;
				case '\x6F':
					return xieite::kb::alt_o;
				case '\x70':
					return xieite::kb::alt_p;
				case '\x71':
					return xieite::kb::alt_q;
				case '\x72':
					return xieite::kb::alt_r;
				case '\x73':
					return xieite::kb::alt_s;
				case '\x74':
					return xieite::kb::alt_t;
				case '\x75':
					return xieite::kb::alt_u;
				case '\x76':
					return xieite::kb::alt_v;
				case '\x77':
					return xieite::kb::alt_w;
				case '\x78':
					return xieite::kb::alt_x;
				case '\x79':
					return xieite::kb::alt_y;
				case '\x7A':
					return xieite::kb::alt_z;
				case '\x7B':
					return xieite::kb::alt_lbrace;
				case '\x7C':
					return xieite::kb::alt_pipe;
				case '\x7D':
					return xieite::kb::alt_rbrace;
				case '\x7E':
					return xieite::kb::alt_tilde;
				case '\x7F':
					return xieite::kb::alt_backsp;
				default:
					std::ungetc(c1, this->in);
				}
				// TODO: Detect keys F13 through F24
				break;
			case '\x20':
				return xieite::kb::sp;
			case '\x21':
				return xieite::kb::exclam;
			case '\x22':
				return xieite::kb::quot;
			case '\x23':
				return xieite::kb::hash;
			case '\x24':
				return xieite::kb::dollar;
			case '\x25':
				return xieite::kb::pc;
			case '\x26':
				return xieite::kb::et;
			case '\x27':
				return xieite::kb::apos;
			case '\x28':
				return xieite::kb::lparen;
			case '\x29':
				return xieite::kb::rparen;
			case '\x2A':
				return xieite::kb::star;
			case '\x2B':
				return xieite::kb::plus;
			case '\x2C':
				return xieite::kb::comma;
			case '\x2D':
				return xieite::kb::dash;
			case '\x2E':
				return xieite::kb::dot;
			case '\x2F':
				return xieite::kb::sl;
			case '\x30':
				return xieite::kb::_0;
			case '\x31':
				return xieite::kb::_1;
			case '\x32':
				return xieite::kb::_2;
			case '\x33':
				return xieite::kb::_3;
			case '\x34':
				return xieite::kb::_4;
			case '\x35':
				return xieite::kb::_5;
			case '\x36':
				return xieite::kb::_6;
			case '\x37':
				return xieite::kb::_7;
			case '\x38':
				return xieite::kb::_8;
			case '\x39':
				return xieite::kb::_9;
			case '\x3A':
				return xieite::kb::col;
			case '\x3B':
				return xieite::kb::semicol;
			case '\x3C':
				return xieite::kb::lt;
			case '\x3D':
				return xieite::kb::eq;
			case '\x3E':
				return xieite::kb::gt;
			case '\x3F':
				return xieite::kb::question;
			case '\x40':
				return xieite::kb::at;
			case '\x41':
				return xieite::kb::A;
			case '\x42':
				return xieite::kb::B;
			case '\x43':
				return xieite::kb::C;
			case '\x44':
				return xieite::kb::D;
			case '\x45':
				return xieite::kb::E;
			case '\x46':
				return xieite::kb::F;
			case '\x47':
				return xieite::kb::G;
			case '\x48':
				return xieite::kb::H;
			case '\x49':
				return xieite::kb::I;
			case '\x4A':
				return xieite::kb::J;
			case '\x4B':
				return xieite::kb::K;
			case '\x4C':
				return xieite::kb::L;
			case '\x4D':
				return xieite::kb::M;
			case '\x4E':
				return xieite::kb::N;
			case '\x4F':
				return xieite::kb::O;
			case '\x50':
				return xieite::kb::P;
			case '\x51':
				return xieite::kb::Q;
			case '\x52':
				return xieite::kb::R;
			case '\x53':
				return xieite::kb::S;
			case '\x54':
				return xieite::kb::T;
			case '\x55':
				return xieite::kb::U;
			case '\x56':
				return xieite::kb::V;
			case '\x57':
				return xieite::kb::W;
			case '\x58':
				return xieite::kb::X;
			case '\x59':
				return xieite::kb::Y;
			case '\x5A':
				return xieite::kb::Z;
			case '\x5B':
				return xieite::kb::lbrack;
			case '\x5C':
				return xieite::kb::backsl;
			case '\x5D':
				return xieite::kb::rbrack;
			case '\x5E':
				return xieite::kb::caret;
			case '\x5F':
				return xieite::kb::undersc;
			case '\x60':
				return xieite::kb::grave;
			case '\x61':
				return xieite::kb::a;
			case '\x62':
				return xieite::kb::b;
			case '\x63':
				return xieite::kb::c;
			case '\x64':
				return xieite::kb::d;
			case '\x65':
				return xieite::kb::e;
			case '\x66':
				return xieite::kb::f;
			case '\x67':
				return xieite::kb::g;
			case '\x68':
				return xieite::kb::h;
			case '\x69':
				return xieite::kb::i;
			case '\x6A':
				return xieite::kb::j;
			case '\x6B':
				return xieite::kb::k;
			case '\x6C':
				return xieite::kb::l;
			case '\x6D':
				return xieite::kb::m;
			case '\x6E':
				return xieite::kb::n;
			case '\x6F':
				return xieite::kb::o;
			case '\x70':
				return xieite::kb::p;
			case '\x71':
				return xieite::kb::q;
			case '\x72':
				return xieite::kb::r;
			case '\x73':
				return xieite::kb::s;
			case '\x74':
				return xieite::kb::t;
			case '\x75':
				return xieite::kb::u;
			case '\x76':
				return xieite::kb::v;
			case '\x77':
				return xieite::kb::w;
			case '\x78':
				return xieite::kb::x;
			case '\x79':
				return xieite::kb::y;
			case '\x7A':
				return xieite::kb::z;
			case '\x7B':
				return xieite::kb::lbrace;
			case '\x7C':
				return xieite::kb::pipe;
			case '\x7D':
				return xieite::kb::rbrace;
			case '\x7E':
				return xieite::kb::tilde;
			case '\x7F':
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
		bool is_process;

		void flush() noexcept {
			::fcntl(::fileno(this->in), F_SETFL, this->block_mode | (O_NONBLOCK * !this->is_block));
			::termios raw_mode = this->cooked_mode;
			raw_mode.c_iflag &= ~static_cast<::tcflag_t>((ICRNL * !this->is_signal) | (IXON * !this->is_signal));
			raw_mode.c_lflag &= ~static_cast<::tcflag_t>((ECHO * !this->is_echo) | (ICANON * !this->is_canon) | (IEXTEN * !this->is_signal) | (ISIG * !this->is_signal));
			raw_mode.c_oflag &= ~static_cast<::tcflag_t>(OPOST * !this->is_process);
			::tcsetattr(::fileno(this->in), TCSANOW, std::addressof(raw_mode));
		}
	};
}
