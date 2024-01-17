#ifndef XIEITE_HEADER_STRINGS_HASH_MD5
#	define XIEITE_HEADER_STRINGS_HASH_MD5

#	include <array>
#	include <cmath>
#	include <cstddef>
#	include <cstdint>
#	include <string>
#	include <string_view>
#	include <vector>
#	include "../math/bit_join.hpp"
#	include "../math/bit_unjoin.hpp"
#	include "../math/stringify.hpp"

namespace xieite::strings {
	[[nodiscard]] constexpr std::string hashMd5(const std::string_view value) noexcept {
		static constexpr std::array<std::uint32_t, 64> shifts = { 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21 };
		static constexpr std::array<std::uint32_t, 64> sines = { 3614090360, 3905402710, 606105819, 3250441966, 4118548399, 1200080426, 2821735955, 4249261313, 1770035416, 2336552879, 4294925233, 2304563134, 1804603682, 4254626195, 2792965006, 1236535329, 4129170786, 3225465664, 643717713, 3921069994, 3593408605, 38016083, 3634488961, 3889429448, 568446438, 3275163606, 4107603335, 1163531501, 2850285829, 4243563512, 1735328473, 2368359562, 4294588738, 2272392833, 1839030562, 4259657740, 2763975236, 1272893353, 4139469664, 3200236656, 681279174, 3936430074, 3572445317, 76029189, 3654602809, 3873151461, 530742520, 3299628645, 4096336452, 1126891415, 2878612391, 4237533241, 1700485571, 2399980690, 4293915773, 2240044497, 1873313359, 4264355552, 2734768916, 1309151649, 4149444226, 3174756917, 718787259, 3951481745 };
		std::array<std::uint32_t, 4> foo = { 1732584193, 4023233417, 2562383102, 271733878 };
		auto data = std::vector<char>(value.begin(), value.end());
		const std::uint64_t length = static_cast<std::uint64_t>(data.size()) * 8;
		data.emplace_back(128);
		const auto padding = std::vector<char>((120 - data.size() % 64) % 64, 0);
		const auto lengthBytes = xieite::math::bitUnjoin<std::uint8_t, 8>(xieite::math::bitJoin(length));
		data.insert(data.end(), padding.begin(), padding.end());
		data.insert(data.end(), lengthBytes.rbegin(), lengthBytes.rend());
		const std::size_t dataSize = data.size();
		for (std::size_t i = 0; i < dataSize; i += 64) {
			std::array<std::uint64_t, 16> chunks;
			for (std::size_t j = 0; j < 16; ++j) {
				chunks[j] = 0;
				for (std::size_t k = 0; k < 4; ++k) {
					chunks[j] |= static_cast<std::uint32_t>(static_cast<unsigned char>(data[i + j * 4 + k])) << (k * 8);
				}
			}
			std::array<std::uint32_t, 4> bar = foo;
			for (std::size_t l = 0; l < 64; ++l) {
				std::uint32_t baz;
				std::size_t qux;
				if (l < 16) {
					baz = (bar[1] & bar[2]) | (~bar[1] & bar[3]);
					qux = l;
				} else if (l < 32) {
					baz = (bar[1] & bar[3]) | (bar[2] & ~bar[3]);
					qux = (l * 5 + 1) % 16;
				} else if (l < 48) {
					baz = bar[1] ^ bar[2] ^ bar[3];
					qux = (l * 3 + 5) % 16;
				} else {
					baz = bar[2] ^ (bar[1] | ~bar[3]);
					qux = (l * 7) % 16;
				}
				baz += bar[0] + chunks[qux] + sines[l];
				bar[0] = bar[3];
				bar[3] = bar[2];
				bar[2] = bar[1];
				bar[1] += std::rotl(baz, shifts[l]);
			}
			for (std::size_t m = 0; m < 4; ++m) {
				foo[m] += bar[m];
			}
		}
		std::string result;
		for (const std::uint32_t item : foo) {
			const std::string part = xieite::math::stringify((item >> 24) | ((item & 16711680) >> 8) | ((item & 65280) << 8) | (item << 24), 16);
			result += std::string(8 - part.size(), '0') + part;
		}
		return result;
	}
}

#endif
