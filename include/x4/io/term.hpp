#pragma once

#include <cstdio>
#include <memory>
#include <stdio.h>
#include <string>
#include "../fn/scopeguard.hpp"
#include "../io/keys.hpp"
#include "../io/rd.hpp"
#include "../math/abs.hpp"
#include "../math/color3.hpp"
#include "../math/strn.hpp"
#include "../math/vec2.hpp"
#include "../pp/pltf.hpp"

#if !X4PLTF_UNIX
#	warning "unsupported platform"
#endif

#include <fcntl.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <unistd.h>

using namespace std::literals;

namespace x4 {
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

		term(const x4::term&) = delete;

		~term() {
			this->resetmode();
			this->resetstyle();
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

		[[nodiscard]] static constexpr std::string fgcode(std::uint8_t r, std::uint8_t g, std::uint8_t b) noexcept {
			return "\x1B[38;2;"s + x4::strn(r) + ";"s + x4::strn(g) + ";"s + x4::strn(b) + "m"s;
		}

		[[nodiscard]] static constexpr std::string fgcode(const x4::color3& color) noexcept {
			return x4::term::fgcode(color.r, color.g, color.b);
		}

		void fg(std::uint8_t r, std::uint8_t g, std::uint8_t b) noexcept {
			std::fputs(x4::term::fgcode(r, g, b).c_str(), this->out);
		}

		void fg(const x4::color3& color) noexcept {
			this->fg(color.r, color.g, color.b);
		}

		[[nodiscard]] static constexpr std::string fgresetcode() noexcept {
			return "\x1B[38m";
		}

		void fgreset() noexcept {
			std::fputs(x4::term::fgresetcode().c_str(), this->out);
		}

		[[nodiscard]] static constexpr std::string bgcode(std::uint8_t r, std::uint8_t g, std::uint8_t b) noexcept {
			return "\x1B[48;2;"s + x4::strn(r) + ";"s + x4::strn(g) + ";"s + x4::strn(b) + "m"s;
		}

		[[nodiscard]] static constexpr std::string bgcode(const x4::color3& color) noexcept {
			return x4::term::bgcode(color.r, color.g, color.b);
		}

		void bg(std::uint8_t r, std::uint8_t g, std::uint8_t b) noexcept {
			std::fputs(x4::term::bgcode(r, g, b).c_str(), this->out);
		}

		void bg(const x4::color3& color) noexcept {
			this->bg(color.r, color.g, color.b);
		}

		[[nodiscard]] static constexpr std::string bgresetcode() noexcept {
			return "\x1B[48m";
		}

		void bgreset() noexcept {
			std::fputs(x4::term::bgresetcode().c_str(), this->out);
		}

		[[nodiscard]] static constexpr std::string boldcode(bool x) noexcept {
			return x ? "\x1B[1m" : "\x1B[21m";
		}

		void bold(bool x) noexcept {
			std::fputs(x4::term::boldcode(x).c_str(), this->out);
		}

		[[nodiscard]] static constexpr std::string italiccode(bool x) noexcept {
			return x ? "\x1B[3m" : "\x1B[23m";
		}

		void italic(bool x) noexcept {
			std::fputs(x4::term::italiccode(x).c_str(), this->out);
		}

		[[nodiscard]] static constexpr std::string underlcode(bool x) noexcept {
			return x ? "\x1B[4m" : "\x1B[24m";
		}

		void underl(bool x) noexcept {
			std::fputs(x4::term::underlcode(x).c_str(), this->out);
		}

		[[nodiscard]] static constexpr std::string blinkcode(bool x) noexcept {
			return x ? "\x1B[5m" : "\x1B[25m";
		}

		void blink(bool x) noexcept {
			std::fputs(x4::term::blinkcode(x).c_str(), this->out);
		}

		[[nodiscard]] static constexpr std::string inviscode(bool x) noexcept {
			return x ? "\x1B[8m" : "\x1B[28m";
		}

		void invis(bool x) noexcept {
			std::fputs(x4::term::inviscode(x).c_str(), this->out);
		}

		[[nodiscard]] static constexpr std::string strikecode(bool x) noexcept {
			return x ? "\x1B[9m" : "\x1B[29m";
		}

		void strike(bool x) noexcept {
			std::fputs(x4::term::strikecode(x).c_str(), this->out);
		}

		[[nodiscard]] static constexpr std::string invertcode(bool x) noexcept {
			return x ? "\x1B[7m" : "\x1B[27m";
		}
		
		void invert(bool x) noexcept {
			std::fputs(x4::term::invertcode(x).c_str(), this->out);
		}

		[[nodiscard]] static constexpr std::string resetstylecode() noexcept {
			return "\x1B[0m";
		}

		void resetstyle() noexcept {
			std::fputs(x4::term::resetstylecode().c_str(), this->out);
		}
		
		void resetmode() noexcept {
			::fcntl(::fileno(this->in), F_SETFL, this->block_mode);
			::tcsetattr(::fileno(this->in), TCSANOW, std::addressof(this->cooked_mode));
		}

		[[nodiscard]] x4::vec2<int> getcurs() noexcept {
			const bool canon_prev = this->is_canon;
			this->canon(false);
			std::fputs("\x1B[6n", this->out);
			x4::vec2<int> pos;
			std::fscanf(this->in, "\x1B[%i;%iR", &pos.y, &pos.x);
			this->canon(canon_prev);
			return pos - 1;
		}

		[[nodiscard]] constexpr std::string setcurscode(int row, int col) noexcept {
			return "\x1B["s + x4::strn(row + 1) + ";"s + x4::strn(col + 1) + "H"s;
		}

		[[nodiscard]] constexpr std::string setcurscode(x4::vec2<int> pos) noexcept {
			return x4::term::setcurscode(pos.y, pos.x);
		}

		void setcurs(int row, int col) noexcept {
			std::fputs(x4::term::setcurscode(row, col).c_str(), this->out);
		}

		void setcurs(x4::vec2<int> pos) noexcept {
			this->setcurs(pos.y, pos.x);
		}

		[[nodiscard]] constexpr std::string mvcurscode(int row, int col) noexcept {
			std::string code;
			if (row) {
				code += "\x1B[";
				code += x4::strn(x4::abs(row));
				code += "BA"[row < 0];
			}
			if (col) {
				code += "\x1B[";
				code += x4::strn(x4::abs(col));
				code += "CD"[col < 0];
			}
			return code;
		}

		[[nodiscard]] constexpr std::string mvcurscode(x4::vec2<int> diff) noexcept {
			return x4::term::mvcurscode(diff.y, diff.x);
		}

		void mvcurs(int row, int col) noexcept {
			std::fputs(x4::term::mvcurscode(row, col).c_str(), this->out);
		}

		void mvcurs(x4::vec2<int> diff) noexcept {
			this->mvcurs(diff.y, diff.x);
		}

		[[nodiscard]] static constexpr std::string cursinviscode(bool x) noexcept {
			return "\x1B[?25"s + "hl"[x];
		}

		void cursinvis(bool x) noexcept {
			std::fputs(x4::term::cursinviscode(x).c_str(), this->out);
		}

		[[nodiscard]] static constexpr std::string cursblockcode(bool blink = false) noexcept {
			return "\1\x1B["s + x4::strn(2 - blink) + "q\2"s;
		}

		void cursblock(bool blink = false) noexcept {
			std::fputs(x4::term::cursblockcode(blink).c_str(), this->out);
		}

		[[nodiscard]] static constexpr std::string cursundersccode(bool blink = false) noexcept {
			return "\1\x1B["s + x4::strn(4 - blink) + "q\2"s;
		}

		void cursundersc(bool blink = false) noexcept {
			std::fputs(x4::term::cursundersccode(blink).c_str(), this->out);
		}

		[[nodiscard]] static constexpr std::string curspipecode(bool blink = false) noexcept {
			return "\1\x1B["s + x4::strn(6 - blink) + "q\2"s;
		}

		void curspipe(bool blink = false) noexcept {
			std::fputs(x4::term::curspipecode(blink).c_str(), this->out);
		}

		[[nodiscard]] static constexpr std::string cursaltcode(bool x) noexcept {
			return "\x1B["s + "us"[x];
		}

		void cursalt(bool x) noexcept {
			std::fputs(x4::term::cursaltcode(x).c_str(), this->out);
		}

		[[nodiscard]] static constexpr std::string screen_altcode(bool x) noexcept {
			return "\x1B[?47"s + "lh"[x];
		}

		void screen_alt(bool x) noexcept {
			std::fputs(x4::term::screen_altcode(x).c_str(), this->out);
		}

		[[nodiscard]] x4::vec2<int> screensz() noexcept {
			::winsize size;
			::ioctl(::fileno(this->in), TIOCGWINSZ, std::addressof(size));
			return x4::vec2<int>(size.ws_row, size.ws_col);
		}

		[[nodiscard]] static constexpr std::string clrscreencode() noexcept {
			return "\x1B[2J";
		}

		void clrscreen() noexcept {
			std::fputs(x4::term::clrscreencode().c_str(), this->out);
		}

		[[nodiscard]] static constexpr std::string clrscreenuntilcode() noexcept {
			return "\x1B[1J";
		}
		
		void clrscreenuntil() noexcept {
			std::fputs(x4::term::clrscreenuntilcode().c_str(), this->out);
		}

		[[nodiscard]] static constexpr std::string clrscreenfromcode() noexcept {
			return "\x1B[0J";
		}
		
		void clrscreenfrom() noexcept {
			std::fputs(x4::term::clrscreenfromcode().c_str(), this->out);
		}

		[[nodiscard]] static constexpr std::string clrlinecode() noexcept {
			return "\x1B[2K";
		}

		void clrline() noexcept {
			std::fputs(x4::term::clrlinecode().c_str(), this->out);
		}

		[[nodiscard]] static constexpr std::string clrlineuntilcode() noexcept {
			return "\x1B[1K";
		}

		void clrlineuntil() noexcept {
			std::fputs(x4::term::clrlineuntilcode().c_str(), this->out);
		}

		[[nodiscard]] static constexpr std::string clrlinefromcode() noexcept {
			return "\x1B[0K";
		}

		void clrlinefrom() noexcept {
			std::fputs(x4::term::clrlinefromcode().c_str(), this->out);
		}

		[[nodiscard]] int rdch() noexcept {
			const bool canon_prev = this->is_canon;
			this->canon(false);
			const int c = std::fgetc(this->in);
			this->canon(canon_prev);
			return c;
		}

		[[nodiscard]] std::string rdstr() noexcept {
			const bool block_prev = this->is_block;
			const bool canon_prev = this->is_canon;
			this->block(false);
			this->canon(false);
			const std::string input = x4::rd(this->in);
			this->block(block_prev);
			this->canon(canon_prev);
			return input;
		}

		[[nodiscard]] x4::keys rdkey() noexcept {
			const x4::scopeguard _ = [this, block_prev = this->is_block] { this->block(block_prev); };
			const int c0 = this->rdch();
			this->block(false);
			switch (c0) {
			case 0x00:
				switch (const int c1 = this->rdch()) {
				case 0x00:
					return x4::keys::pause;
				case 0x03:
					return x4::keys::null;
				default:
					std::ungetc(c1, this->in);
				}
				break;
			case 0x01:
				return x4::keys::ctrl_a;
			case 0x02:
				return x4::keys::ctrl_b;
			case 0x03:
				return x4::keys::ctrl_c;
			case 0x04:
				return x4::keys::ctrl_d;
			case 0x05:
				return x4::keys::ctrl_e;
			case 0x06:
				return x4::keys::ctrl_f;
			case 0x07:
				return x4::keys::ctrl_g;
			case 0x08:
				return x4::keys::ctrl_h;
			case 0x09:
				return x4::keys::ctrl_i;
			case 0x0A:
				return x4::keys::ctrl_j;
			case 0x0B:
				return x4::keys::ctrl_k;
			case 0x0C:
				return x4::keys::ctrl_l;
			case 0x0D:
				return x4::keys::ctrl_m;
			case 0x0E:
				return x4::keys::ctrl_n;
			case 0x0F:
				return x4::keys::ctrl_o;
			case 0x10:
				return x4::keys::ctrl_p;
			case 0x11:
				return x4::keys::ctrl_q;
			case 0x12:
				return x4::keys::ctrl_r;
			case 0x13:
				return x4::keys::ctrl_s;
			case 0x14:
				return x4::keys::ctrl_t;
			case 0x15:
				return x4::keys::ctrl_u;
			case 0x16:
				return x4::keys::ctrl_v;
			case 0x17:
				return x4::keys::ctrl_w;
			case 0x18:
				return x4::keys::ctrl_x;
			case 0x19:
				return x4::keys::ctrl_y;
			case 0x1A:
				return x4::keys::ctrl_z;
			case 0x1B:
				switch (const int c1 = this->rdch()) {
				case 0x01:
					return x4::keys::ctrl_alt_a;
				case 0x02:
					return x4::keys::ctrl_alt_b;
				case 0x03:
					return x4::keys::ctrl_alt_c;
				case 0x04:
					return x4::keys::ctrl_alt_d;
				case 0x05:
					return x4::keys::ctrl_alt_e;
				case 0x06:
					return x4::keys::ctrl_alt_f;
				case 0x07:
					return x4::keys::ctrl_alt_g;
				case 0x08:
					return x4::keys::ctrl_alt_h;
				case 0x09:
					return x4::keys::ctrl_alt_i;
				case 0x0A:
					return x4::keys::ctrl_alt_j;
				case 0x0B:
					return x4::keys::ctrl_alt_k;
				case 0x0C:
					return x4::keys::ctrl_alt_l;
				case 0x0D:
					return x4::keys::ctrl_alt_m;
				case 0x0E:
					return x4::keys::ctrl_alt_n;
				case 0x0F:
					return x4::keys::ctrl_alt_o;
				case 0x10:
					return x4::keys::ctrl_alt_p;
				case 0x11:
					return x4::keys::ctrl_alt_q;
				case 0x12:
					return x4::keys::ctrl_alt_r;
				case 0x13:
					return x4::keys::ctrl_alt_s;
				case 0x14:
					return x4::keys::ctrl_alt_t;
				case 0x15:
					return x4::keys::ctrl_alt_u;
				case 0x16:
					return x4::keys::ctrl_alt_v;
				case 0x17:
					return x4::keys::ctrl_alt_w;
				case 0x18:
					return x4::keys::ctrl_alt_x;
				case 0x19:
					return x4::keys::ctrl_alt_y;
				case 0x1A:
					return x4::keys::ctrl_alt_z;
				case 0x20:
					return x4::keys::alt_sp;
				case 0x21:
					return x4::keys::alt_exclam;
				case 0x22:
					return x4::keys::alt_quot;
				case 0x23:
					return x4::keys::alt_hash;
				case 0x24:
					return x4::keys::alt_dollar;
				case 0x25:
					return x4::keys::alt_pc;
				case 0x26:
					return x4::keys::alt_et;
				case 0x27:
					return x4::keys::alt_apos;
				case 0x28:
					return x4::keys::alt_lparen;
				case 0x29:
					return x4::keys::alt_rparen;
				case 0x2A:
					return x4::keys::alt_star;
				case 0x2B:
					return x4::keys::alt_plus;
				case 0x2C:
					return x4::keys::alt_comma;
				case 0x2D:
					return x4::keys::alt_dash;
				case 0x2E:
					return x4::keys::alt_dot;
				case 0x2F:
					return x4::keys::alt_sl;
				case 0x30:
					return x4::keys::alt_0;
				case 0x31:
					return x4::keys::alt_1;
				case 0x32:
					return x4::keys::alt_2;
				case 0x33:
					return x4::keys::alt_3;
				case 0x34:
					return x4::keys::alt_4;
				case 0x35:
					return x4::keys::alt_5;
				case 0x36:
					return x4::keys::alt_6;
				case 0x37:
					return x4::keys::alt_7;
				case 0x38:
					return x4::keys::alt_8;
				case 0x39:
					return x4::keys::alt_9;
				case 0x3A:
					return x4::keys::alt_col;
				case 0x3B:
					return x4::keys::alt_semicol;
				case 0x3C:
					return x4::keys::alt_lt;
				case 0x3D:
					return x4::keys::alt_eq;
				case 0x3E:
					return x4::keys::alt_gt;
				case 0x3F:
					return x4::keys::alt_question;
				case 0x40:
					return x4::keys::alt_at;
				case 0x41:
					return x4::keys::alt_A;
				case 0x42:
					return x4::keys::alt_B;
				case 0x43:
					return x4::keys::alt_C;
				case 0x44:
					return x4::keys::alt_D;
				case 0x45:
					return x4::keys::alt_E;
				case 0x46:
					return x4::keys::alt_F;
				case 0x47:
					return x4::keys::alt_G;
				case 0x48:
					return x4::keys::alt_H;
				case 0x49:
					return x4::keys::alt_I;
				case 0x4A:
					return x4::keys::alt_J;
				case 0x4B:
					return x4::keys::alt_K;
				case 0x4C:
					return x4::keys::alt_L;
				case 0x4D:
					return x4::keys::alt_M;
				case 0x4E:
					return x4::keys::alt_N;
				case 0x4F:
					switch (const int c2 = this->rdch()) {
					case 0x50:
						return x4::keys::f1;
					case 0x51:
						return x4::keys::f2;
					case 0x52:
						return x4::keys::f3;
					case 0x53:
						return x4::keys::f4;
					default:
						std::ungetc(c2, this->in);
					}
					return x4::keys::alt_O;
				case 0x50:
					return x4::keys::alt_P;
				case 0x51:
					return x4::keys::alt_Q;
				case 0x52:
					return x4::keys::alt_R;
				case 0x53:
					return x4::keys::alt_S;
				case 0x54:
					return x4::keys::alt_T;
				case 0x55:
					return x4::keys::alt_U;
				case 0x56:
					return x4::keys::alt_V;
				case 0x57:
					return x4::keys::alt_W;
				case 0x58:
					return x4::keys::alt_X;
				case 0x59:
					return x4::keys::alt_Y;
				case 0x5A:
					return x4::keys::alt_Z;
				case 0x5B:
					{
						const int c2 = this->rdch();
						const int c3 = this->rdch();
						if (c3 == 0x7E) {
							switch (c2) {
							case 0x20:
								return x4::keys::np_0;
							case 0x21:
								return x4::keys::np_dot;
							case 0x23:
								return x4::keys::np_9;
							case 0x24:
								return x4::keys::np_3;
							}
						}
						switch (c2) {
						case 0x29:
							return x4::keys::np_8;
						case 0x2A:
							return x4::keys::np_2;
						case 0x2B:
							return x4::keys::np_6;
						case 0x2C:
							return x4::keys::np_4;
						case 0x2D:
							return x4::keys::np_5;
						case 0x2E:
							return x4::keys::np_1;
						case 0x30:
							return x4::keys::np_7;
						case 0x31:
							if (const int c4 = this->rdch(); c4 == 0x7E) {
								switch (c3) {
								case 0x35:
									return x4::keys::f5;
								case 0x37:
									return x4::keys::f6;
								case 0x38:
									return x4::keys::f7;
								case 0x39:
									return x4::keys::f8;
								}
								std::ungetc(c4, this->in);
							}
							break;
						case 0x32:
							if (const int c4 = this->rdch(); c4 == 0x7E) {
								switch (c3) {
								case 0x30:
									return x4::keys::f9;
								case 0x31:
									return x4::keys::f10;
								case 0x33:
									return x4::keys::f11;
								case 0x34:
									return x4::keys::f12;
								}
								std::ungetc(c4, this->in);
							}
							break;
						case 0x41:
							return x4::keys::up;
						case 0x42:
							return x4::keys::down;
						case 0x43:
							return x4::keys::right;
						case 0x44:
							return x4::keys::left;
						case 0x5B:
							switch (c3) {
							case 0x41:
								return x4::keys::f1;
							case 0x42:
								return x4::keys::f2;
							case 0x43:
								return x4::keys::f3;
							case 0x44:
								return x4::keys::f4;
							case 0x45:
								return x4::keys::f5;
							}
							break;
						}
						std::ungetc(c3, this->in);
						std::ungetc(c2, this->in);
					}
					return x4::keys::alt_lbrack;
				case 0x5C:
					return x4::keys::alt_backsl;
				case 0x5D:
					return x4::keys::alt_rbrack;
				case 0x5E:
					return x4::keys::alt_caret;
				case 0x5F:
					return x4::keys::alt_undersc;
				case 0x60:
					return x4::keys::alt_grave;
				case 0x61:
					return x4::keys::alt_a;
				case 0x62:
					return x4::keys::alt_b;
				case 0x63:
					return x4::keys::alt_c;
				case 0x64:
					return x4::keys::alt_d;
				case 0x65:
					return x4::keys::alt_e;
				case 0x66:
					return x4::keys::alt_f;
				case 0x67:
					return x4::keys::alt_g;
				case 0x68:
					return x4::keys::alt_h;
				case 0x69:
					return x4::keys::alt_i;
				case 0x6A:
					return x4::keys::alt_j;
				case 0x6B:
					return x4::keys::alt_k;
				case 0x6C:
					return x4::keys::alt_l;
				case 0x6D:
					return x4::keys::alt_m;
				case 0x6E:
					return x4::keys::alt_n;
				case 0x6F:
					return x4::keys::alt_o;
				case 0x70:
					return x4::keys::alt_p;
				case 0x71:
					return x4::keys::alt_q;
				case 0x72:
					return x4::keys::alt_r;
				case 0x73:
					return x4::keys::alt_s;
				case 0x74:
					return x4::keys::alt_t;
				case 0x75:
					return x4::keys::alt_u;
				case 0x76:
					return x4::keys::alt_v;
				case 0x77:
					return x4::keys::alt_w;
				case 0x78:
					return x4::keys::alt_x;
				case 0x79:
					return x4::keys::alt_y;
				case 0x7A:
					return x4::keys::alt_z;
				case 0x7B:
					return x4::keys::alt_lbrace;
				case 0x7C:
					return x4::keys::alt_pipe;
				case 0x7D:
					return x4::keys::alt_rbrace;
				case 0x7E:
					return x4::keys::alt_tilde;
				case 0x7F:
					return x4::keys::alt_backsp;
				default:
					std::ungetc(c1, this->in);
				}
				break;
			case 0x20:
				return x4::keys::sp;
			case 0x21:
				return x4::keys::exclam;
			case 0x22:
				return x4::keys::quot;
			case 0x23:
				return x4::keys::hash;
			case 0x24:
				return x4::keys::dollar;
			case 0x25:
				return x4::keys::pc;
			case 0x26:
				return x4::keys::et;
			case 0x27:
				return x4::keys::apos;
			case 0x28:
				return x4::keys::lparen;
			case 0x29:
				return x4::keys::rparen;
			case 0x2A:
				return x4::keys::star;
			case 0x2B:
				return x4::keys::plus;
			case 0x2C:
				return x4::keys::comma;
			case 0x2D:
				return x4::keys::dash;
			case 0x2E:
				return x4::keys::dot;
			case 0x2F:
				return x4::keys::sl;
			case 0x30:
				return x4::keys::_0;
			case 0x31:
				return x4::keys::_1;
			case 0x32:
				return x4::keys::_2;
			case 0x33:
				return x4::keys::_3;
			case 0x34:
				return x4::keys::_4;
			case 0x35:
				return x4::keys::_5;
			case 0x36:
				return x4::keys::_6;
			case 0x37:
				return x4::keys::_7;
			case 0x38:
				return x4::keys::_8;
			case 0x39:
				return x4::keys::_9;
			case 0x3A:
				return x4::keys::col;
			case 0x3B:
				return x4::keys::semicol;
			case 0x3C:
				return x4::keys::lt;
			case 0x3D:
				return x4::keys::eq;
			case 0x3E:
				return x4::keys::gt;
			case 0x3F:
				return x4::keys::question;
			case 0x40:
				return x4::keys::at;
			case 0x41:
				return x4::keys::A;
			case 0x42:
				return x4::keys::B;
			case 0x43:
				return x4::keys::C;
			case 0x44:
				return x4::keys::D;
			case 0x45:
				return x4::keys::E;
			case 0x46:
				return x4::keys::F;
			case 0x47:
				return x4::keys::G;
			case 0x48:
				return x4::keys::H;
			case 0x49:
				return x4::keys::I;
			case 0x4A:
				return x4::keys::J;
			case 0x4B:
				return x4::keys::K;
			case 0x4C:
				return x4::keys::L;
			case 0x4D:
				return x4::keys::M;
			case 0x4E:
				return x4::keys::N;
			case 0x4F:
				return x4::keys::O;
			case 0x50:
				return x4::keys::P;
			case 0x51:
				return x4::keys::Q;
			case 0x52:
				return x4::keys::R;
			case 0x53:
				return x4::keys::S;
			case 0x54:
				return x4::keys::T;
			case 0x55:
				return x4::keys::U;
			case 0x56:
				return x4::keys::V;
			case 0x57:
				return x4::keys::W;
			case 0x58:
				return x4::keys::X;
			case 0x59:
				return x4::keys::Y;
			case 0x5A:
				return x4::keys::Z;
			case 0x5B:
				return x4::keys::lbrack;
			case 0x5C:
				return x4::keys::backsl;
			case 0x5D:
				return x4::keys::rbrack;
			case 0x5E:
				return x4::keys::caret;
			case 0x5F:
				return x4::keys::undersc;
			case 0x60:
				return x4::keys::grave;
			case 0x61:
				return x4::keys::a;
			case 0x62:
				return x4::keys::b;
			case 0x63:
				return x4::keys::c;
			case 0x64:
				return x4::keys::d;
			case 0x65:
				return x4::keys::e;
			case 0x66:
				return x4::keys::f;
			case 0x67:
				return x4::keys::g;
			case 0x68:
				return x4::keys::h;
			case 0x69:
				return x4::keys::i;
			case 0x6A:
				return x4::keys::j;
			case 0x6B:
				return x4::keys::k;
			case 0x6C:
				return x4::keys::l;
			case 0x6D:
				return x4::keys::m;
			case 0x6E:
				return x4::keys::n;
			case 0x6F:
				return x4::keys::o;
			case 0x70:
				return x4::keys::p;
			case 0x71:
				return x4::keys::q;
			case 0x72:
				return x4::keys::r;
			case 0x73:
				return x4::keys::s;
			case 0x74:
				return x4::keys::t;
			case 0x75:
				return x4::keys::u;
			case 0x76:
				return x4::keys::v;
			case 0x77:
				return x4::keys::w;
			case 0x78:
				return x4::keys::x;
			case 0x79:
				return x4::keys::y;
			case 0x7A:
				return x4::keys::z;
			case 0x7B:
				return x4::keys::lbrace;
			case 0x7C:
				return x4::keys::pipe;
			case 0x7D:
				return x4::keys::rbrace;
			case 0x7E:
				return x4::keys::tilde;
			case 0x7F:
				return x4::keys::backsp;
			}
			std::ungetc(c0, this->in);
			return x4::keys::unknown;
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
