#pragma once

#include <cstddef>
#include <type_traits>
#include "../pp/ar.hpp"
#include "../pp/comma.hpp"
#include "../pp/diag.hpp"
#include "../pp/fwd.hpp"
#include "../pp/if.hpp"
#include "../pp/unwrap.hpp"

#define X4FN(...) ([]DETAIL_X4FN(0, __VA_ARGS__))
#define X4FNTHIS(...) ([]DETAIL_X4FN(1, __VA_ARGS__))
#define X4FNLOC(...) ([&]DETAIL_X4FN(1, __VA_ARGS__))
#define X4FNMUT(captures_, ...) (DETAIL_X4::FN::indirect { [X4UNWRAP(captures_)] mutable { return [&]DETAIL_X4FN(1, __VA_ARGS__); } })

X4DIAGOFF_CLANG("-Wdollar-in-identifier-extension")

#define DETAIL_X4FN(this_, ...) \
	< \
		typename... $$, \
		X4IF(this_)(typename $$this X4COMMA()) \
		typename $$0 = DETAIL_X4::FN::t<0, $$...>, \
		typename $$1 = DETAIL_X4::FN::t<1, $$...>, \
		typename $$2 = DETAIL_X4::FN::t<2, $$...>, \
		typename $$3 = DETAIL_X4::FN::t<3, $$...>, \
		typename $$4 = DETAIL_X4::FN::t<4, $$...>, \
		typename $$5 = DETAIL_X4::FN::t<5, $$...>, \
		typename $$6 = DETAIL_X4::FN::t<6, $$...>, \
		typename $$7 = DETAIL_X4::FN::t<7, $$...>, \
		typename $$8 = DETAIL_X4::FN::t<8, $$...>, \
		typename $$9 = DETAIL_X4::FN::t<9, $$...>, \
		typename $$10 = DETAIL_X4::FN::t<10, $$...>, \
		typename $$11 = DETAIL_X4::FN::t<11, $$...>, \
		typename $$12 = DETAIL_X4::FN::t<12, $$...>, \
		typename $$13 = DETAIL_X4::FN::t<13, $$...>, \
		typename $$14 = DETAIL_X4::FN::t<14, $$...>, \
		typename $$15 = DETAIL_X4::FN::t<15, $$...>, \
		typename $$16 = DETAIL_X4::FN::t<16, $$...>, \
		typename $$17 = DETAIL_X4::FN::t<17, $$...>, \
		typename $$18 = DETAIL_X4::FN::t<18, $$...>, \
		typename $$19 = DETAIL_X4::FN::t<19, $$...>, \
		typename $$20 = DETAIL_X4::FN::t<20, $$...>, \
		typename $$21 = DETAIL_X4::FN::t<21, $$...>, \
		typename $$22 = DETAIL_X4::FN::t<22, $$...>, \
		typename $$23 = DETAIL_X4::FN::t<23, $$...>, \
		typename $$24 = DETAIL_X4::FN::t<24, $$...>, \
		typename $$25 = DETAIL_X4::FN::t<25, $$...>, \
		typename $$26 = DETAIL_X4::FN::t<26, $$...>, \
		typename $$27 = DETAIL_X4::FN::t<27, $$...>, \
		typename $$28 = DETAIL_X4::FN::t<28, $$...>, \
		typename $$29 = DETAIL_X4::FN::t<29, $$...>, \
		typename $$30 = DETAIL_X4::FN::t<30, $$...>, \
		typename $$31 = DETAIL_X4::FN::t<31, $$...>, \
		typename $$32 = DETAIL_X4::FN::t<32, $$...>, \
		typename $$33 = DETAIL_X4::FN::t<33, $$...>, \
		typename $$34 = DETAIL_X4::FN::t<34, $$...>, \
		typename $$35 = DETAIL_X4::FN::t<35, $$...>, \
		typename $$36 = DETAIL_X4::FN::t<36, $$...>, \
		typename $$37 = DETAIL_X4::FN::t<37, $$...>, \
		typename $$38 = DETAIL_X4::FN::t<38, $$...>, \
		typename $$39 = DETAIL_X4::FN::t<39, $$...>, \
		typename $$40 = DETAIL_X4::FN::t<40, $$...>, \
		typename $$41 = DETAIL_X4::FN::t<41, $$...>, \
		typename $$42 = DETAIL_X4::FN::t<42, $$...>, \
		typename $$43 = DETAIL_X4::FN::t<43, $$...>, \
		typename $$44 = DETAIL_X4::FN::t<44, $$...>, \
		typename $$45 = DETAIL_X4::FN::t<45, $$...>, \
		typename $$46 = DETAIL_X4::FN::t<46, $$...>, \
		typename $$47 = DETAIL_X4::FN::t<47, $$...>, \
		typename $$48 = DETAIL_X4::FN::t<48, $$...>, \
		typename $$49 = DETAIL_X4::FN::t<49, $$...>, \
		typename $$50 = DETAIL_X4::FN::t<50, $$...>, \
		typename $$51 = DETAIL_X4::FN::t<51, $$...>, \
		typename $$52 = DETAIL_X4::FN::t<52, $$...>, \
		typename $$53 = DETAIL_X4::FN::t<53, $$...>, \
		typename $$54 = DETAIL_X4::FN::t<54, $$...>, \
		typename $$55 = DETAIL_X4::FN::t<55, $$...>, \
		typename $$56 = DETAIL_X4::FN::t<56, $$...>, \
		typename $$57 = DETAIL_X4::FN::t<57, $$...>, \
		typename $$58 = DETAIL_X4::FN::t<58, $$...>, \
		typename $$59 = DETAIL_X4::FN::t<59, $$...>, \
		typename $$60 = DETAIL_X4::FN::t<60, $$...>, \
		typename $$61 = DETAIL_X4::FN::t<61, $$...>, \
		typename $$62 = DETAIL_X4::FN::t<62, $$...>, \
		typename $$63 = DETAIL_X4::FN::t<63, $$...>, \
		typename $$64 = DETAIL_X4::FN::t<64, $$...>, \
		typename $$65 = DETAIL_X4::FN::t<65, $$...>, \
		typename $$66 = DETAIL_X4::FN::t<66, $$...>, \
		typename $$67 = DETAIL_X4::FN::t<67, $$...>, \
		typename $$68 = DETAIL_X4::FN::t<68, $$...>, \
		typename $$69 = DETAIL_X4::FN::t<69, $$...>, \
		typename $$70 = DETAIL_X4::FN::t<70, $$...>, \
		typename $$71 = DETAIL_X4::FN::t<71, $$...>, \
		typename $$72 = DETAIL_X4::FN::t<72, $$...>, \
		typename $$73 = DETAIL_X4::FN::t<73, $$...>, \
		typename $$74 = DETAIL_X4::FN::t<74, $$...>, \
		typename $$75 = DETAIL_X4::FN::t<75, $$...>, \
		typename $$76 = DETAIL_X4::FN::t<76, $$...>, \
		typename $$77 = DETAIL_X4::FN::t<77, $$...>, \
		typename $$78 = DETAIL_X4::FN::t<78, $$...>, \
		typename $$79 = DETAIL_X4::FN::t<79, $$...>, \
		typename $$80 = DETAIL_X4::FN::t<80, $$...>, \
		typename $$81 = DETAIL_X4::FN::t<81, $$...>, \
		typename $$82 = DETAIL_X4::FN::t<82, $$...>, \
		typename $$83 = DETAIL_X4::FN::t<83, $$...>, \
		typename $$84 = DETAIL_X4::FN::t<84, $$...>, \
		typename $$85 = DETAIL_X4::FN::t<85, $$...>, \
		typename $$86 = DETAIL_X4::FN::t<86, $$...>, \
		typename $$87 = DETAIL_X4::FN::t<87, $$...>, \
		typename $$88 = DETAIL_X4::FN::t<88, $$...>, \
		typename $$89 = DETAIL_X4::FN::t<89, $$...>, \
		typename $$90 = DETAIL_X4::FN::t<90, $$...>, \
		typename $$91 = DETAIL_X4::FN::t<91, $$...>, \
		typename $$92 = DETAIL_X4::FN::t<92, $$...>, \
		typename $$93 = DETAIL_X4::FN::t<93, $$...>, \
		typename $$94 = DETAIL_X4::FN::t<94, $$...>, \
		typename $$95 = DETAIL_X4::FN::t<95, $$...>, \
		typename $$96 = DETAIL_X4::FN::t<96, $$...>, \
		typename $$97 = DETAIL_X4::FN::t<97, $$...>, \
		typename $$98 = DETAIL_X4::FN::t<98, $$...>, \
		typename $$99 = DETAIL_X4::FN::t<99, $$...>, \
		typename $$100 = DETAIL_X4::FN::t<100, $$...>, \
		typename $$101 = DETAIL_X4::FN::t<101, $$...>, \
		typename $$102 = DETAIL_X4::FN::t<102, $$...>, \
		typename $$103 = DETAIL_X4::FN::t<103, $$...>, \
		typename $$104 = DETAIL_X4::FN::t<104, $$...>, \
		typename $$105 = DETAIL_X4::FN::t<105, $$...>, \
		typename $$106 = DETAIL_X4::FN::t<106, $$...>, \
		typename $$107 = DETAIL_X4::FN::t<107, $$...>, \
		typename $$108 = DETAIL_X4::FN::t<108, $$...>, \
		typename $$109 = DETAIL_X4::FN::t<109, $$...>, \
		typename $$110 = DETAIL_X4::FN::t<110, $$...>, \
		typename $$111 = DETAIL_X4::FN::t<111, $$...>, \
		typename $$112 = DETAIL_X4::FN::t<112, $$...>, \
		typename $$113 = DETAIL_X4::FN::t<113, $$...>, \
		typename $$114 = DETAIL_X4::FN::t<114, $$...>, \
		typename $$115 = DETAIL_X4::FN::t<115, $$...>, \
		typename $$116 = DETAIL_X4::FN::t<116, $$...>, \
		typename $$117 = DETAIL_X4::FN::t<117, $$...>, \
		typename $$118 = DETAIL_X4::FN::t<118, $$...>, \
		typename $$119 = DETAIL_X4::FN::t<119, $$...>, \
		typename $$120 = DETAIL_X4::FN::t<120, $$...>, \
		typename $$121 = DETAIL_X4::FN::t<121, $$...>, \
		typename $$122 = DETAIL_X4::FN::t<122, $$...>, \
		typename $$123 = DETAIL_X4::FN::t<123, $$...>, \
		typename $$124 = DETAIL_X4::FN::t<124, $$...>, \
		typename $$125 = DETAIL_X4::FN::t<125, $$...>, \
		typename $$126 = DETAIL_X4::FN::t<126, $$...>, \
		typename $$127 = DETAIL_X4::FN::t<127, $$...>, \
		typename $$128 = DETAIL_X4::FN::t<128, $$...>, \
		typename $$129 = DETAIL_X4::FN::t<129, $$...>, \
		typename $$130 = DETAIL_X4::FN::t<130, $$...>, \
		typename $$131 = DETAIL_X4::FN::t<131, $$...>, \
		typename $$132 = DETAIL_X4::FN::t<132, $$...>, \
		typename $$133 = DETAIL_X4::FN::t<133, $$...>, \
		typename $$134 = DETAIL_X4::FN::t<134, $$...>, \
		typename $$135 = DETAIL_X4::FN::t<135, $$...>, \
		typename $$136 = DETAIL_X4::FN::t<136, $$...>, \
		typename $$137 = DETAIL_X4::FN::t<137, $$...>, \
		typename $$138 = DETAIL_X4::FN::t<138, $$...>, \
		typename $$139 = DETAIL_X4::FN::t<139, $$...>, \
		typename $$140 = DETAIL_X4::FN::t<140, $$...>, \
		typename $$141 = DETAIL_X4::FN::t<141, $$...>, \
		typename $$142 = DETAIL_X4::FN::t<142, $$...>, \
		typename $$143 = DETAIL_X4::FN::t<143, $$...>, \
		typename $$144 = DETAIL_X4::FN::t<144, $$...>, \
		typename $$145 = DETAIL_X4::FN::t<145, $$...>, \
		typename $$146 = DETAIL_X4::FN::t<146, $$...>, \
		typename $$147 = DETAIL_X4::FN::t<147, $$...>, \
		typename $$148 = DETAIL_X4::FN::t<148, $$...>, \
		typename $$149 = DETAIL_X4::FN::t<149, $$...>, \
		typename $$150 = DETAIL_X4::FN::t<150, $$...>, \
		typename $$151 = DETAIL_X4::FN::t<151, $$...>, \
		typename $$152 = DETAIL_X4::FN::t<152, $$...>, \
		typename $$153 = DETAIL_X4::FN::t<153, $$...>, \
		typename $$154 = DETAIL_X4::FN::t<154, $$...>, \
		typename $$155 = DETAIL_X4::FN::t<155, $$...>, \
		typename $$156 = DETAIL_X4::FN::t<156, $$...>, \
		typename $$157 = DETAIL_X4::FN::t<157, $$...>, \
		typename $$158 = DETAIL_X4::FN::t<158, $$...>, \
		typename $$159 = DETAIL_X4::FN::t<159, $$...>, \
		typename $$160 = DETAIL_X4::FN::t<160, $$...>, \
		typename $$161 = DETAIL_X4::FN::t<161, $$...>, \
		typename $$162 = DETAIL_X4::FN::t<162, $$...>, \
		typename $$163 = DETAIL_X4::FN::t<163, $$...>, \
		typename $$164 = DETAIL_X4::FN::t<164, $$...>, \
		typename $$165 = DETAIL_X4::FN::t<165, $$...>, \
		typename $$166 = DETAIL_X4::FN::t<166, $$...>, \
		typename $$167 = DETAIL_X4::FN::t<167, $$...>, \
		typename $$168 = DETAIL_X4::FN::t<168, $$...>, \
		typename $$169 = DETAIL_X4::FN::t<169, $$...>, \
		typename $$170 = DETAIL_X4::FN::t<170, $$...>, \
		typename $$171 = DETAIL_X4::FN::t<171, $$...>, \
		typename $$172 = DETAIL_X4::FN::t<172, $$...>, \
		typename $$173 = DETAIL_X4::FN::t<173, $$...>, \
		typename $$174 = DETAIL_X4::FN::t<174, $$...>, \
		typename $$175 = DETAIL_X4::FN::t<175, $$...>, \
		typename $$176 = DETAIL_X4::FN::t<176, $$...>, \
		typename $$177 = DETAIL_X4::FN::t<177, $$...>, \
		typename $$178 = DETAIL_X4::FN::t<178, $$...>, \
		typename $$179 = DETAIL_X4::FN::t<179, $$...>, \
		typename $$180 = DETAIL_X4::FN::t<180, $$...>, \
		typename $$181 = DETAIL_X4::FN::t<181, $$...>, \
		typename $$182 = DETAIL_X4::FN::t<182, $$...>, \
		typename $$183 = DETAIL_X4::FN::t<183, $$...>, \
		typename $$184 = DETAIL_X4::FN::t<184, $$...>, \
		typename $$185 = DETAIL_X4::FN::t<185, $$...>, \
		typename $$186 = DETAIL_X4::FN::t<186, $$...>, \
		typename $$187 = DETAIL_X4::FN::t<187, $$...>, \
		typename $$188 = DETAIL_X4::FN::t<188, $$...>, \
		typename $$189 = DETAIL_X4::FN::t<189, $$...>, \
		typename $$190 = DETAIL_X4::FN::t<190, $$...>, \
		typename $$191 = DETAIL_X4::FN::t<191, $$...>, \
		typename $$192 = DETAIL_X4::FN::t<192, $$...>, \
		typename $$193 = DETAIL_X4::FN::t<193, $$...>, \
		typename $$194 = DETAIL_X4::FN::t<194, $$...>, \
		typename $$195 = DETAIL_X4::FN::t<195, $$...>, \
		typename $$196 = DETAIL_X4::FN::t<196, $$...>, \
		typename $$197 = DETAIL_X4::FN::t<197, $$...>, \
		typename $$198 = DETAIL_X4::FN::t<198, $$...>, \
		typename $$199 = DETAIL_X4::FN::t<199, $$...>, \
		typename $$200 = DETAIL_X4::FN::t<200, $$...>, \
		typename $$201 = DETAIL_X4::FN::t<201, $$...>, \
		typename $$202 = DETAIL_X4::FN::t<202, $$...>, \
		typename $$203 = DETAIL_X4::FN::t<203, $$...>, \
		typename $$204 = DETAIL_X4::FN::t<204, $$...>, \
		typename $$205 = DETAIL_X4::FN::t<205, $$...>, \
		typename $$206 = DETAIL_X4::FN::t<206, $$...>, \
		typename $$207 = DETAIL_X4::FN::t<207, $$...>, \
		typename $$208 = DETAIL_X4::FN::t<208, $$...>, \
		typename $$209 = DETAIL_X4::FN::t<209, $$...>, \
		typename $$210 = DETAIL_X4::FN::t<210, $$...>, \
		typename $$211 = DETAIL_X4::FN::t<211, $$...>, \
		typename $$212 = DETAIL_X4::FN::t<212, $$...>, \
		typename $$213 = DETAIL_X4::FN::t<213, $$...>, \
		typename $$214 = DETAIL_X4::FN::t<214, $$...>, \
		typename $$215 = DETAIL_X4::FN::t<215, $$...>, \
		typename $$216 = DETAIL_X4::FN::t<216, $$...>, \
		typename $$217 = DETAIL_X4::FN::t<217, $$...>, \
		typename $$218 = DETAIL_X4::FN::t<218, $$...>, \
		typename $$219 = DETAIL_X4::FN::t<219, $$...>, \
		typename $$220 = DETAIL_X4::FN::t<220, $$...>, \
		typename $$221 = DETAIL_X4::FN::t<221, $$...>, \
		typename $$222 = DETAIL_X4::FN::t<222, $$...>, \
		typename $$223 = DETAIL_X4::FN::t<223, $$...>, \
		typename $$224 = DETAIL_X4::FN::t<224, $$...>, \
		typename $$225 = DETAIL_X4::FN::t<225, $$...>, \
		typename $$226 = DETAIL_X4::FN::t<226, $$...>, \
		typename $$227 = DETAIL_X4::FN::t<227, $$...>, \
		typename $$228 = DETAIL_X4::FN::t<228, $$...>, \
		typename $$229 = DETAIL_X4::FN::t<229, $$...>, \
		typename $$230 = DETAIL_X4::FN::t<230, $$...>, \
		typename $$231 = DETAIL_X4::FN::t<231, $$...>, \
		typename $$232 = DETAIL_X4::FN::t<232, $$...>, \
		typename $$233 = DETAIL_X4::FN::t<233, $$...>, \
		typename $$234 = DETAIL_X4::FN::t<234, $$...>, \
		typename $$235 = DETAIL_X4::FN::t<235, $$...>, \
		typename $$236 = DETAIL_X4::FN::t<236, $$...>, \
		typename $$237 = DETAIL_X4::FN::t<237, $$...>, \
		typename $$238 = DETAIL_X4::FN::t<238, $$...>, \
		typename $$239 = DETAIL_X4::FN::t<239, $$...>, \
		typename $$240 = DETAIL_X4::FN::t<240, $$...>, \
		typename $$241 = DETAIL_X4::FN::t<241, $$...>, \
		typename $$242 = DETAIL_X4::FN::t<242, $$...>, \
		typename $$243 = DETAIL_X4::FN::t<243, $$...>, \
		typename $$244 = DETAIL_X4::FN::t<244, $$...>, \
		typename $$245 = DETAIL_X4::FN::t<245, $$...>, \
		typename $$246 = DETAIL_X4::FN::t<246, $$...>, \
		typename $$247 = DETAIL_X4::FN::t<247, $$...>, \
		typename $$248 = DETAIL_X4::FN::t<248, $$...>, \
		typename $$249 = DETAIL_X4::FN::t<249, $$...>, \
		typename $$250 = DETAIL_X4::FN::t<250, $$...>, \
		typename $$251 = DETAIL_X4::FN::t<251, $$...>, \
		typename $$252 = DETAIL_X4::FN::t<252, $$...>, \
		typename $$253 = DETAIL_X4::FN::t<253, $$...>, \
		typename $$254 = DETAIL_X4::FN::t<254, $$...>, \
		typename $$255 = DETAIL_X4::FN::t<255, $$...>, \
		typename $$256 = DETAIL_X4::FN::t<256, $$...> \
	>[[nodiscard]]( \
		X4IF(this_)([[maybe_unused]] this $$this&& $this X4COMMA()) \
		auto&&... $ \
	) X4IF(this_)(, static) noexcept(requires ( \
		X4IF(this_)($$this&& $this X4COMMA()) \
		decltype(DETAIL_X4::FN::v<0>(X4FWD($)...)) $0, \
		decltype(DETAIL_X4::FN::v<1>(X4FWD($)...)) $1, \
		decltype(DETAIL_X4::FN::v<2>(X4FWD($)...)) $2, \
		decltype(DETAIL_X4::FN::v<3>(X4FWD($)...)) $3, \
		decltype(DETAIL_X4::FN::v<4>(X4FWD($)...)) $4, \
		decltype(DETAIL_X4::FN::v<5>(X4FWD($)...)) $5, \
		decltype(DETAIL_X4::FN::v<6>(X4FWD($)...)) $6, \
		decltype(DETAIL_X4::FN::v<7>(X4FWD($)...)) $7, \
		decltype(DETAIL_X4::FN::v<8>(X4FWD($)...)) $8, \
		decltype(DETAIL_X4::FN::v<9>(X4FWD($)...)) $9, \
		decltype(DETAIL_X4::FN::v<10>(X4FWD($)...)) $10, \
		decltype(DETAIL_X4::FN::v<11>(X4FWD($)...)) $11, \
		decltype(DETAIL_X4::FN::v<12>(X4FWD($)...)) $12, \
		decltype(DETAIL_X4::FN::v<13>(X4FWD($)...)) $13, \
		decltype(DETAIL_X4::FN::v<14>(X4FWD($)...)) $14, \
		decltype(DETAIL_X4::FN::v<15>(X4FWD($)...)) $15, \
		decltype(DETAIL_X4::FN::v<16>(X4FWD($)...)) $16, \
		decltype(DETAIL_X4::FN::v<17>(X4FWD($)...)) $17, \
		decltype(DETAIL_X4::FN::v<18>(X4FWD($)...)) $18, \
		decltype(DETAIL_X4::FN::v<19>(X4FWD($)...)) $19, \
		decltype(DETAIL_X4::FN::v<20>(X4FWD($)...)) $20, \
		decltype(DETAIL_X4::FN::v<21>(X4FWD($)...)) $21, \
		decltype(DETAIL_X4::FN::v<22>(X4FWD($)...)) $22, \
		decltype(DETAIL_X4::FN::v<23>(X4FWD($)...)) $23, \
		decltype(DETAIL_X4::FN::v<24>(X4FWD($)...)) $24, \
		decltype(DETAIL_X4::FN::v<25>(X4FWD($)...)) $25, \
		decltype(DETAIL_X4::FN::v<26>(X4FWD($)...)) $26, \
		decltype(DETAIL_X4::FN::v<27>(X4FWD($)...)) $27, \
		decltype(DETAIL_X4::FN::v<28>(X4FWD($)...)) $28, \
		decltype(DETAIL_X4::FN::v<29>(X4FWD($)...)) $29, \
		decltype(DETAIL_X4::FN::v<30>(X4FWD($)...)) $30, \
		decltype(DETAIL_X4::FN::v<31>(X4FWD($)...)) $31, \
		decltype(DETAIL_X4::FN::v<32>(X4FWD($)...)) $32, \
		decltype(DETAIL_X4::FN::v<33>(X4FWD($)...)) $33, \
		decltype(DETAIL_X4::FN::v<34>(X4FWD($)...)) $34, \
		decltype(DETAIL_X4::FN::v<35>(X4FWD($)...)) $35, \
		decltype(DETAIL_X4::FN::v<36>(X4FWD($)...)) $36, \
		decltype(DETAIL_X4::FN::v<37>(X4FWD($)...)) $37, \
		decltype(DETAIL_X4::FN::v<38>(X4FWD($)...)) $38, \
		decltype(DETAIL_X4::FN::v<39>(X4FWD($)...)) $39, \
		decltype(DETAIL_X4::FN::v<40>(X4FWD($)...)) $40, \
		decltype(DETAIL_X4::FN::v<41>(X4FWD($)...)) $41, \
		decltype(DETAIL_X4::FN::v<42>(X4FWD($)...)) $42, \
		decltype(DETAIL_X4::FN::v<43>(X4FWD($)...)) $43, \
		decltype(DETAIL_X4::FN::v<44>(X4FWD($)...)) $44, \
		decltype(DETAIL_X4::FN::v<45>(X4FWD($)...)) $45, \
		decltype(DETAIL_X4::FN::v<46>(X4FWD($)...)) $46, \
		decltype(DETAIL_X4::FN::v<47>(X4FWD($)...)) $47, \
		decltype(DETAIL_X4::FN::v<48>(X4FWD($)...)) $48, \
		decltype(DETAIL_X4::FN::v<49>(X4FWD($)...)) $49, \
		decltype(DETAIL_X4::FN::v<50>(X4FWD($)...)) $50, \
		decltype(DETAIL_X4::FN::v<51>(X4FWD($)...)) $51, \
		decltype(DETAIL_X4::FN::v<52>(X4FWD($)...)) $52, \
		decltype(DETAIL_X4::FN::v<53>(X4FWD($)...)) $53, \
		decltype(DETAIL_X4::FN::v<54>(X4FWD($)...)) $54, \
		decltype(DETAIL_X4::FN::v<55>(X4FWD($)...)) $55, \
		decltype(DETAIL_X4::FN::v<56>(X4FWD($)...)) $56, \
		decltype(DETAIL_X4::FN::v<57>(X4FWD($)...)) $57, \
		decltype(DETAIL_X4::FN::v<58>(X4FWD($)...)) $58, \
		decltype(DETAIL_X4::FN::v<59>(X4FWD($)...)) $59, \
		decltype(DETAIL_X4::FN::v<60>(X4FWD($)...)) $60, \
		decltype(DETAIL_X4::FN::v<61>(X4FWD($)...)) $61, \
		decltype(DETAIL_X4::FN::v<62>(X4FWD($)...)) $62, \
		decltype(DETAIL_X4::FN::v<63>(X4FWD($)...)) $63, \
		decltype(DETAIL_X4::FN::v<64>(X4FWD($)...)) $64, \
		decltype(DETAIL_X4::FN::v<65>(X4FWD($)...)) $65, \
		decltype(DETAIL_X4::FN::v<66>(X4FWD($)...)) $66, \
		decltype(DETAIL_X4::FN::v<67>(X4FWD($)...)) $67, \
		decltype(DETAIL_X4::FN::v<68>(X4FWD($)...)) $68, \
		decltype(DETAIL_X4::FN::v<69>(X4FWD($)...)) $69, \
		decltype(DETAIL_X4::FN::v<70>(X4FWD($)...)) $70, \
		decltype(DETAIL_X4::FN::v<71>(X4FWD($)...)) $71, \
		decltype(DETAIL_X4::FN::v<72>(X4FWD($)...)) $72, \
		decltype(DETAIL_X4::FN::v<73>(X4FWD($)...)) $73, \
		decltype(DETAIL_X4::FN::v<74>(X4FWD($)...)) $74, \
		decltype(DETAIL_X4::FN::v<75>(X4FWD($)...)) $75, \
		decltype(DETAIL_X4::FN::v<76>(X4FWD($)...)) $76, \
		decltype(DETAIL_X4::FN::v<77>(X4FWD($)...)) $77, \
		decltype(DETAIL_X4::FN::v<78>(X4FWD($)...)) $78, \
		decltype(DETAIL_X4::FN::v<79>(X4FWD($)...)) $79, \
		decltype(DETAIL_X4::FN::v<80>(X4FWD($)...)) $80, \
		decltype(DETAIL_X4::FN::v<81>(X4FWD($)...)) $81, \
		decltype(DETAIL_X4::FN::v<82>(X4FWD($)...)) $82, \
		decltype(DETAIL_X4::FN::v<83>(X4FWD($)...)) $83, \
		decltype(DETAIL_X4::FN::v<84>(X4FWD($)...)) $84, \
		decltype(DETAIL_X4::FN::v<85>(X4FWD($)...)) $85, \
		decltype(DETAIL_X4::FN::v<86>(X4FWD($)...)) $86, \
		decltype(DETAIL_X4::FN::v<87>(X4FWD($)...)) $87, \
		decltype(DETAIL_X4::FN::v<88>(X4FWD($)...)) $88, \
		decltype(DETAIL_X4::FN::v<89>(X4FWD($)...)) $89, \
		decltype(DETAIL_X4::FN::v<90>(X4FWD($)...)) $90, \
		decltype(DETAIL_X4::FN::v<91>(X4FWD($)...)) $91, \
		decltype(DETAIL_X4::FN::v<92>(X4FWD($)...)) $92, \
		decltype(DETAIL_X4::FN::v<93>(X4FWD($)...)) $93, \
		decltype(DETAIL_X4::FN::v<94>(X4FWD($)...)) $94, \
		decltype(DETAIL_X4::FN::v<95>(X4FWD($)...)) $95, \
		decltype(DETAIL_X4::FN::v<96>(X4FWD($)...)) $96, \
		decltype(DETAIL_X4::FN::v<97>(X4FWD($)...)) $97, \
		decltype(DETAIL_X4::FN::v<98>(X4FWD($)...)) $98, \
		decltype(DETAIL_X4::FN::v<99>(X4FWD($)...)) $99, \
		decltype(DETAIL_X4::FN::v<100>(X4FWD($)...)) $100, \
		decltype(DETAIL_X4::FN::v<101>(X4FWD($)...)) $101, \
		decltype(DETAIL_X4::FN::v<102>(X4FWD($)...)) $102, \
		decltype(DETAIL_X4::FN::v<103>(X4FWD($)...)) $103, \
		decltype(DETAIL_X4::FN::v<104>(X4FWD($)...)) $104, \
		decltype(DETAIL_X4::FN::v<105>(X4FWD($)...)) $105, \
		decltype(DETAIL_X4::FN::v<106>(X4FWD($)...)) $106, \
		decltype(DETAIL_X4::FN::v<107>(X4FWD($)...)) $107, \
		decltype(DETAIL_X4::FN::v<108>(X4FWD($)...)) $108, \
		decltype(DETAIL_X4::FN::v<109>(X4FWD($)...)) $109, \
		decltype(DETAIL_X4::FN::v<110>(X4FWD($)...)) $110, \
		decltype(DETAIL_X4::FN::v<111>(X4FWD($)...)) $111, \
		decltype(DETAIL_X4::FN::v<112>(X4FWD($)...)) $112, \
		decltype(DETAIL_X4::FN::v<113>(X4FWD($)...)) $113, \
		decltype(DETAIL_X4::FN::v<114>(X4FWD($)...)) $114, \
		decltype(DETAIL_X4::FN::v<115>(X4FWD($)...)) $115, \
		decltype(DETAIL_X4::FN::v<116>(X4FWD($)...)) $116, \
		decltype(DETAIL_X4::FN::v<117>(X4FWD($)...)) $117, \
		decltype(DETAIL_X4::FN::v<118>(X4FWD($)...)) $118, \
		decltype(DETAIL_X4::FN::v<119>(X4FWD($)...)) $119, \
		decltype(DETAIL_X4::FN::v<120>(X4FWD($)...)) $120, \
		decltype(DETAIL_X4::FN::v<121>(X4FWD($)...)) $121, \
		decltype(DETAIL_X4::FN::v<122>(X4FWD($)...)) $122, \
		decltype(DETAIL_X4::FN::v<123>(X4FWD($)...)) $123, \
		decltype(DETAIL_X4::FN::v<124>(X4FWD($)...)) $124, \
		decltype(DETAIL_X4::FN::v<125>(X4FWD($)...)) $125, \
		decltype(DETAIL_X4::FN::v<126>(X4FWD($)...)) $126, \
		decltype(DETAIL_X4::FN::v<127>(X4FWD($)...)) $127, \
		decltype(DETAIL_X4::FN::v<128>(X4FWD($)...)) $128, \
		decltype(DETAIL_X4::FN::v<129>(X4FWD($)...)) $129, \
		decltype(DETAIL_X4::FN::v<130>(X4FWD($)...)) $130, \
		decltype(DETAIL_X4::FN::v<131>(X4FWD($)...)) $131, \
		decltype(DETAIL_X4::FN::v<132>(X4FWD($)...)) $132, \
		decltype(DETAIL_X4::FN::v<133>(X4FWD($)...)) $133, \
		decltype(DETAIL_X4::FN::v<134>(X4FWD($)...)) $134, \
		decltype(DETAIL_X4::FN::v<135>(X4FWD($)...)) $135, \
		decltype(DETAIL_X4::FN::v<136>(X4FWD($)...)) $136, \
		decltype(DETAIL_X4::FN::v<137>(X4FWD($)...)) $137, \
		decltype(DETAIL_X4::FN::v<138>(X4FWD($)...)) $138, \
		decltype(DETAIL_X4::FN::v<139>(X4FWD($)...)) $139, \
		decltype(DETAIL_X4::FN::v<140>(X4FWD($)...)) $140, \
		decltype(DETAIL_X4::FN::v<141>(X4FWD($)...)) $141, \
		decltype(DETAIL_X4::FN::v<142>(X4FWD($)...)) $142, \
		decltype(DETAIL_X4::FN::v<143>(X4FWD($)...)) $143, \
		decltype(DETAIL_X4::FN::v<144>(X4FWD($)...)) $144, \
		decltype(DETAIL_X4::FN::v<145>(X4FWD($)...)) $145, \
		decltype(DETAIL_X4::FN::v<146>(X4FWD($)...)) $146, \
		decltype(DETAIL_X4::FN::v<147>(X4FWD($)...)) $147, \
		decltype(DETAIL_X4::FN::v<148>(X4FWD($)...)) $148, \
		decltype(DETAIL_X4::FN::v<149>(X4FWD($)...)) $149, \
		decltype(DETAIL_X4::FN::v<150>(X4FWD($)...)) $150, \
		decltype(DETAIL_X4::FN::v<151>(X4FWD($)...)) $151, \
		decltype(DETAIL_X4::FN::v<152>(X4FWD($)...)) $152, \
		decltype(DETAIL_X4::FN::v<153>(X4FWD($)...)) $153, \
		decltype(DETAIL_X4::FN::v<154>(X4FWD($)...)) $154, \
		decltype(DETAIL_X4::FN::v<155>(X4FWD($)...)) $155, \
		decltype(DETAIL_X4::FN::v<156>(X4FWD($)...)) $156, \
		decltype(DETAIL_X4::FN::v<157>(X4FWD($)...)) $157, \
		decltype(DETAIL_X4::FN::v<158>(X4FWD($)...)) $158, \
		decltype(DETAIL_X4::FN::v<159>(X4FWD($)...)) $159, \
		decltype(DETAIL_X4::FN::v<160>(X4FWD($)...)) $160, \
		decltype(DETAIL_X4::FN::v<161>(X4FWD($)...)) $161, \
		decltype(DETAIL_X4::FN::v<162>(X4FWD($)...)) $162, \
		decltype(DETAIL_X4::FN::v<163>(X4FWD($)...)) $163, \
		decltype(DETAIL_X4::FN::v<164>(X4FWD($)...)) $164, \
		decltype(DETAIL_X4::FN::v<165>(X4FWD($)...)) $165, \
		decltype(DETAIL_X4::FN::v<166>(X4FWD($)...)) $166, \
		decltype(DETAIL_X4::FN::v<167>(X4FWD($)...)) $167, \
		decltype(DETAIL_X4::FN::v<168>(X4FWD($)...)) $168, \
		decltype(DETAIL_X4::FN::v<169>(X4FWD($)...)) $169, \
		decltype(DETAIL_X4::FN::v<170>(X4FWD($)...)) $170, \
		decltype(DETAIL_X4::FN::v<171>(X4FWD($)...)) $171, \
		decltype(DETAIL_X4::FN::v<172>(X4FWD($)...)) $172, \
		decltype(DETAIL_X4::FN::v<173>(X4FWD($)...)) $173, \
		decltype(DETAIL_X4::FN::v<174>(X4FWD($)...)) $174, \
		decltype(DETAIL_X4::FN::v<175>(X4FWD($)...)) $175, \
		decltype(DETAIL_X4::FN::v<176>(X4FWD($)...)) $176, \
		decltype(DETAIL_X4::FN::v<177>(X4FWD($)...)) $177, \
		decltype(DETAIL_X4::FN::v<178>(X4FWD($)...)) $178, \
		decltype(DETAIL_X4::FN::v<179>(X4FWD($)...)) $179, \
		decltype(DETAIL_X4::FN::v<180>(X4FWD($)...)) $180, \
		decltype(DETAIL_X4::FN::v<181>(X4FWD($)...)) $181, \
		decltype(DETAIL_X4::FN::v<182>(X4FWD($)...)) $182, \
		decltype(DETAIL_X4::FN::v<183>(X4FWD($)...)) $183, \
		decltype(DETAIL_X4::FN::v<184>(X4FWD($)...)) $184, \
		decltype(DETAIL_X4::FN::v<185>(X4FWD($)...)) $185, \
		decltype(DETAIL_X4::FN::v<186>(X4FWD($)...)) $186, \
		decltype(DETAIL_X4::FN::v<187>(X4FWD($)...)) $187, \
		decltype(DETAIL_X4::FN::v<188>(X4FWD($)...)) $188, \
		decltype(DETAIL_X4::FN::v<189>(X4FWD($)...)) $189, \
		decltype(DETAIL_X4::FN::v<190>(X4FWD($)...)) $190, \
		decltype(DETAIL_X4::FN::v<191>(X4FWD($)...)) $191, \
		decltype(DETAIL_X4::FN::v<192>(X4FWD($)...)) $192, \
		decltype(DETAIL_X4::FN::v<193>(X4FWD($)...)) $193, \
		decltype(DETAIL_X4::FN::v<194>(X4FWD($)...)) $194, \
		decltype(DETAIL_X4::FN::v<195>(X4FWD($)...)) $195, \
		decltype(DETAIL_X4::FN::v<196>(X4FWD($)...)) $196, \
		decltype(DETAIL_X4::FN::v<197>(X4FWD($)...)) $197, \
		decltype(DETAIL_X4::FN::v<198>(X4FWD($)...)) $198, \
		decltype(DETAIL_X4::FN::v<199>(X4FWD($)...)) $199, \
		decltype(DETAIL_X4::FN::v<200>(X4FWD($)...)) $200, \
		decltype(DETAIL_X4::FN::v<201>(X4FWD($)...)) $201, \
		decltype(DETAIL_X4::FN::v<202>(X4FWD($)...)) $202, \
		decltype(DETAIL_X4::FN::v<203>(X4FWD($)...)) $203, \
		decltype(DETAIL_X4::FN::v<204>(X4FWD($)...)) $204, \
		decltype(DETAIL_X4::FN::v<205>(X4FWD($)...)) $205, \
		decltype(DETAIL_X4::FN::v<206>(X4FWD($)...)) $206, \
		decltype(DETAIL_X4::FN::v<207>(X4FWD($)...)) $207, \
		decltype(DETAIL_X4::FN::v<208>(X4FWD($)...)) $208, \
		decltype(DETAIL_X4::FN::v<209>(X4FWD($)...)) $209, \
		decltype(DETAIL_X4::FN::v<210>(X4FWD($)...)) $210, \
		decltype(DETAIL_X4::FN::v<211>(X4FWD($)...)) $211, \
		decltype(DETAIL_X4::FN::v<212>(X4FWD($)...)) $212, \
		decltype(DETAIL_X4::FN::v<213>(X4FWD($)...)) $213, \
		decltype(DETAIL_X4::FN::v<214>(X4FWD($)...)) $214, \
		decltype(DETAIL_X4::FN::v<215>(X4FWD($)...)) $215, \
		decltype(DETAIL_X4::FN::v<216>(X4FWD($)...)) $216, \
		decltype(DETAIL_X4::FN::v<217>(X4FWD($)...)) $217, \
		decltype(DETAIL_X4::FN::v<218>(X4FWD($)...)) $218, \
		decltype(DETAIL_X4::FN::v<219>(X4FWD($)...)) $219, \
		decltype(DETAIL_X4::FN::v<220>(X4FWD($)...)) $220, \
		decltype(DETAIL_X4::FN::v<221>(X4FWD($)...)) $221, \
		decltype(DETAIL_X4::FN::v<222>(X4FWD($)...)) $222, \
		decltype(DETAIL_X4::FN::v<223>(X4FWD($)...)) $223, \
		decltype(DETAIL_X4::FN::v<224>(X4FWD($)...)) $224, \
		decltype(DETAIL_X4::FN::v<225>(X4FWD($)...)) $225, \
		decltype(DETAIL_X4::FN::v<226>(X4FWD($)...)) $226, \
		decltype(DETAIL_X4::FN::v<227>(X4FWD($)...)) $227, \
		decltype(DETAIL_X4::FN::v<228>(X4FWD($)...)) $228, \
		decltype(DETAIL_X4::FN::v<229>(X4FWD($)...)) $229, \
		decltype(DETAIL_X4::FN::v<230>(X4FWD($)...)) $230, \
		decltype(DETAIL_X4::FN::v<231>(X4FWD($)...)) $231, \
		decltype(DETAIL_X4::FN::v<232>(X4FWD($)...)) $232, \
		decltype(DETAIL_X4::FN::v<233>(X4FWD($)...)) $233, \
		decltype(DETAIL_X4::FN::v<234>(X4FWD($)...)) $234, \
		decltype(DETAIL_X4::FN::v<235>(X4FWD($)...)) $235, \
		decltype(DETAIL_X4::FN::v<236>(X4FWD($)...)) $236, \
		decltype(DETAIL_X4::FN::v<237>(X4FWD($)...)) $237, \
		decltype(DETAIL_X4::FN::v<238>(X4FWD($)...)) $238, \
		decltype(DETAIL_X4::FN::v<239>(X4FWD($)...)) $239, \
		decltype(DETAIL_X4::FN::v<240>(X4FWD($)...)) $240, \
		decltype(DETAIL_X4::FN::v<241>(X4FWD($)...)) $241, \
		decltype(DETAIL_X4::FN::v<242>(X4FWD($)...)) $242, \
		decltype(DETAIL_X4::FN::v<243>(X4FWD($)...)) $243, \
		decltype(DETAIL_X4::FN::v<244>(X4FWD($)...)) $244, \
		decltype(DETAIL_X4::FN::v<245>(X4FWD($)...)) $245, \
		decltype(DETAIL_X4::FN::v<246>(X4FWD($)...)) $246, \
		decltype(DETAIL_X4::FN::v<247>(X4FWD($)...)) $247, \
		decltype(DETAIL_X4::FN::v<248>(X4FWD($)...)) $248, \
		decltype(DETAIL_X4::FN::v<249>(X4FWD($)...)) $249, \
		decltype(DETAIL_X4::FN::v<250>(X4FWD($)...)) $250, \
		decltype(DETAIL_X4::FN::v<251>(X4FWD($)...)) $251, \
		decltype(DETAIL_X4::FN::v<252>(X4FWD($)...)) $252, \
		decltype(DETAIL_X4::FN::v<253>(X4FWD($)...)) $253, \
		decltype(DETAIL_X4::FN::v<254>(X4FWD($)...)) $254, \
		decltype(DETAIL_X4::FN::v<255>(X4FWD($)...)) $255, \
		decltype(DETAIL_X4::FN::v<256>(X4FWD($)...)) $256 \
	) { requires(noexcept((__VA_ARGS__))); }) \
	-> decltype(auto) \
	requires(requires ( \
		X4IF(this_)($$this&& $this X4COMMA()) \
		decltype(DETAIL_X4::FN::v<0>(X4FWD($)...)) $0, \
		decltype(DETAIL_X4::FN::v<1>(X4FWD($)...)) $1, \
		decltype(DETAIL_X4::FN::v<2>(X4FWD($)...)) $2, \
		decltype(DETAIL_X4::FN::v<3>(X4FWD($)...)) $3, \
		decltype(DETAIL_X4::FN::v<4>(X4FWD($)...)) $4, \
		decltype(DETAIL_X4::FN::v<5>(X4FWD($)...)) $5, \
		decltype(DETAIL_X4::FN::v<6>(X4FWD($)...)) $6, \
		decltype(DETAIL_X4::FN::v<7>(X4FWD($)...)) $7, \
		decltype(DETAIL_X4::FN::v<8>(X4FWD($)...)) $8, \
		decltype(DETAIL_X4::FN::v<9>(X4FWD($)...)) $9, \
		decltype(DETAIL_X4::FN::v<10>(X4FWD($)...)) $10, \
		decltype(DETAIL_X4::FN::v<11>(X4FWD($)...)) $11, \
		decltype(DETAIL_X4::FN::v<12>(X4FWD($)...)) $12, \
		decltype(DETAIL_X4::FN::v<13>(X4FWD($)...)) $13, \
		decltype(DETAIL_X4::FN::v<14>(X4FWD($)...)) $14, \
		decltype(DETAIL_X4::FN::v<15>(X4FWD($)...)) $15, \
		decltype(DETAIL_X4::FN::v<16>(X4FWD($)...)) $16, \
		decltype(DETAIL_X4::FN::v<17>(X4FWD($)...)) $17, \
		decltype(DETAIL_X4::FN::v<18>(X4FWD($)...)) $18, \
		decltype(DETAIL_X4::FN::v<19>(X4FWD($)...)) $19, \
		decltype(DETAIL_X4::FN::v<20>(X4FWD($)...)) $20, \
		decltype(DETAIL_X4::FN::v<21>(X4FWD($)...)) $21, \
		decltype(DETAIL_X4::FN::v<22>(X4FWD($)...)) $22, \
		decltype(DETAIL_X4::FN::v<23>(X4FWD($)...)) $23, \
		decltype(DETAIL_X4::FN::v<24>(X4FWD($)...)) $24, \
		decltype(DETAIL_X4::FN::v<25>(X4FWD($)...)) $25, \
		decltype(DETAIL_X4::FN::v<26>(X4FWD($)...)) $26, \
		decltype(DETAIL_X4::FN::v<27>(X4FWD($)...)) $27, \
		decltype(DETAIL_X4::FN::v<28>(X4FWD($)...)) $28, \
		decltype(DETAIL_X4::FN::v<29>(X4FWD($)...)) $29, \
		decltype(DETAIL_X4::FN::v<30>(X4FWD($)...)) $30, \
		decltype(DETAIL_X4::FN::v<31>(X4FWD($)...)) $31, \
		decltype(DETAIL_X4::FN::v<32>(X4FWD($)...)) $32, \
		decltype(DETAIL_X4::FN::v<33>(X4FWD($)...)) $33, \
		decltype(DETAIL_X4::FN::v<34>(X4FWD($)...)) $34, \
		decltype(DETAIL_X4::FN::v<35>(X4FWD($)...)) $35, \
		decltype(DETAIL_X4::FN::v<36>(X4FWD($)...)) $36, \
		decltype(DETAIL_X4::FN::v<37>(X4FWD($)...)) $37, \
		decltype(DETAIL_X4::FN::v<38>(X4FWD($)...)) $38, \
		decltype(DETAIL_X4::FN::v<39>(X4FWD($)...)) $39, \
		decltype(DETAIL_X4::FN::v<40>(X4FWD($)...)) $40, \
		decltype(DETAIL_X4::FN::v<41>(X4FWD($)...)) $41, \
		decltype(DETAIL_X4::FN::v<42>(X4FWD($)...)) $42, \
		decltype(DETAIL_X4::FN::v<43>(X4FWD($)...)) $43, \
		decltype(DETAIL_X4::FN::v<44>(X4FWD($)...)) $44, \
		decltype(DETAIL_X4::FN::v<45>(X4FWD($)...)) $45, \
		decltype(DETAIL_X4::FN::v<46>(X4FWD($)...)) $46, \
		decltype(DETAIL_X4::FN::v<47>(X4FWD($)...)) $47, \
		decltype(DETAIL_X4::FN::v<48>(X4FWD($)...)) $48, \
		decltype(DETAIL_X4::FN::v<49>(X4FWD($)...)) $49, \
		decltype(DETAIL_X4::FN::v<50>(X4FWD($)...)) $50, \
		decltype(DETAIL_X4::FN::v<51>(X4FWD($)...)) $51, \
		decltype(DETAIL_X4::FN::v<52>(X4FWD($)...)) $52, \
		decltype(DETAIL_X4::FN::v<53>(X4FWD($)...)) $53, \
		decltype(DETAIL_X4::FN::v<54>(X4FWD($)...)) $54, \
		decltype(DETAIL_X4::FN::v<55>(X4FWD($)...)) $55, \
		decltype(DETAIL_X4::FN::v<56>(X4FWD($)...)) $56, \
		decltype(DETAIL_X4::FN::v<57>(X4FWD($)...)) $57, \
		decltype(DETAIL_X4::FN::v<58>(X4FWD($)...)) $58, \
		decltype(DETAIL_X4::FN::v<59>(X4FWD($)...)) $59, \
		decltype(DETAIL_X4::FN::v<60>(X4FWD($)...)) $60, \
		decltype(DETAIL_X4::FN::v<61>(X4FWD($)...)) $61, \
		decltype(DETAIL_X4::FN::v<62>(X4FWD($)...)) $62, \
		decltype(DETAIL_X4::FN::v<63>(X4FWD($)...)) $63, \
		decltype(DETAIL_X4::FN::v<64>(X4FWD($)...)) $64, \
		decltype(DETAIL_X4::FN::v<65>(X4FWD($)...)) $65, \
		decltype(DETAIL_X4::FN::v<66>(X4FWD($)...)) $66, \
		decltype(DETAIL_X4::FN::v<67>(X4FWD($)...)) $67, \
		decltype(DETAIL_X4::FN::v<68>(X4FWD($)...)) $68, \
		decltype(DETAIL_X4::FN::v<69>(X4FWD($)...)) $69, \
		decltype(DETAIL_X4::FN::v<70>(X4FWD($)...)) $70, \
		decltype(DETAIL_X4::FN::v<71>(X4FWD($)...)) $71, \
		decltype(DETAIL_X4::FN::v<72>(X4FWD($)...)) $72, \
		decltype(DETAIL_X4::FN::v<73>(X4FWD($)...)) $73, \
		decltype(DETAIL_X4::FN::v<74>(X4FWD($)...)) $74, \
		decltype(DETAIL_X4::FN::v<75>(X4FWD($)...)) $75, \
		decltype(DETAIL_X4::FN::v<76>(X4FWD($)...)) $76, \
		decltype(DETAIL_X4::FN::v<77>(X4FWD($)...)) $77, \
		decltype(DETAIL_X4::FN::v<78>(X4FWD($)...)) $78, \
		decltype(DETAIL_X4::FN::v<79>(X4FWD($)...)) $79, \
		decltype(DETAIL_X4::FN::v<80>(X4FWD($)...)) $80, \
		decltype(DETAIL_X4::FN::v<81>(X4FWD($)...)) $81, \
		decltype(DETAIL_X4::FN::v<82>(X4FWD($)...)) $82, \
		decltype(DETAIL_X4::FN::v<83>(X4FWD($)...)) $83, \
		decltype(DETAIL_X4::FN::v<84>(X4FWD($)...)) $84, \
		decltype(DETAIL_X4::FN::v<85>(X4FWD($)...)) $85, \
		decltype(DETAIL_X4::FN::v<86>(X4FWD($)...)) $86, \
		decltype(DETAIL_X4::FN::v<87>(X4FWD($)...)) $87, \
		decltype(DETAIL_X4::FN::v<88>(X4FWD($)...)) $88, \
		decltype(DETAIL_X4::FN::v<89>(X4FWD($)...)) $89, \
		decltype(DETAIL_X4::FN::v<90>(X4FWD($)...)) $90, \
		decltype(DETAIL_X4::FN::v<91>(X4FWD($)...)) $91, \
		decltype(DETAIL_X4::FN::v<92>(X4FWD($)...)) $92, \
		decltype(DETAIL_X4::FN::v<93>(X4FWD($)...)) $93, \
		decltype(DETAIL_X4::FN::v<94>(X4FWD($)...)) $94, \
		decltype(DETAIL_X4::FN::v<95>(X4FWD($)...)) $95, \
		decltype(DETAIL_X4::FN::v<96>(X4FWD($)...)) $96, \
		decltype(DETAIL_X4::FN::v<97>(X4FWD($)...)) $97, \
		decltype(DETAIL_X4::FN::v<98>(X4FWD($)...)) $98, \
		decltype(DETAIL_X4::FN::v<99>(X4FWD($)...)) $99, \
		decltype(DETAIL_X4::FN::v<100>(X4FWD($)...)) $100, \
		decltype(DETAIL_X4::FN::v<101>(X4FWD($)...)) $101, \
		decltype(DETAIL_X4::FN::v<102>(X4FWD($)...)) $102, \
		decltype(DETAIL_X4::FN::v<103>(X4FWD($)...)) $103, \
		decltype(DETAIL_X4::FN::v<104>(X4FWD($)...)) $104, \
		decltype(DETAIL_X4::FN::v<105>(X4FWD($)...)) $105, \
		decltype(DETAIL_X4::FN::v<106>(X4FWD($)...)) $106, \
		decltype(DETAIL_X4::FN::v<107>(X4FWD($)...)) $107, \
		decltype(DETAIL_X4::FN::v<108>(X4FWD($)...)) $108, \
		decltype(DETAIL_X4::FN::v<109>(X4FWD($)...)) $109, \
		decltype(DETAIL_X4::FN::v<110>(X4FWD($)...)) $110, \
		decltype(DETAIL_X4::FN::v<111>(X4FWD($)...)) $111, \
		decltype(DETAIL_X4::FN::v<112>(X4FWD($)...)) $112, \
		decltype(DETAIL_X4::FN::v<113>(X4FWD($)...)) $113, \
		decltype(DETAIL_X4::FN::v<114>(X4FWD($)...)) $114, \
		decltype(DETAIL_X4::FN::v<115>(X4FWD($)...)) $115, \
		decltype(DETAIL_X4::FN::v<116>(X4FWD($)...)) $116, \
		decltype(DETAIL_X4::FN::v<117>(X4FWD($)...)) $117, \
		decltype(DETAIL_X4::FN::v<118>(X4FWD($)...)) $118, \
		decltype(DETAIL_X4::FN::v<119>(X4FWD($)...)) $119, \
		decltype(DETAIL_X4::FN::v<120>(X4FWD($)...)) $120, \
		decltype(DETAIL_X4::FN::v<121>(X4FWD($)...)) $121, \
		decltype(DETAIL_X4::FN::v<122>(X4FWD($)...)) $122, \
		decltype(DETAIL_X4::FN::v<123>(X4FWD($)...)) $123, \
		decltype(DETAIL_X4::FN::v<124>(X4FWD($)...)) $124, \
		decltype(DETAIL_X4::FN::v<125>(X4FWD($)...)) $125, \
		decltype(DETAIL_X4::FN::v<126>(X4FWD($)...)) $126, \
		decltype(DETAIL_X4::FN::v<127>(X4FWD($)...)) $127, \
		decltype(DETAIL_X4::FN::v<128>(X4FWD($)...)) $128, \
		decltype(DETAIL_X4::FN::v<129>(X4FWD($)...)) $129, \
		decltype(DETAIL_X4::FN::v<130>(X4FWD($)...)) $130, \
		decltype(DETAIL_X4::FN::v<131>(X4FWD($)...)) $131, \
		decltype(DETAIL_X4::FN::v<132>(X4FWD($)...)) $132, \
		decltype(DETAIL_X4::FN::v<133>(X4FWD($)...)) $133, \
		decltype(DETAIL_X4::FN::v<134>(X4FWD($)...)) $134, \
		decltype(DETAIL_X4::FN::v<135>(X4FWD($)...)) $135, \
		decltype(DETAIL_X4::FN::v<136>(X4FWD($)...)) $136, \
		decltype(DETAIL_X4::FN::v<137>(X4FWD($)...)) $137, \
		decltype(DETAIL_X4::FN::v<138>(X4FWD($)...)) $138, \
		decltype(DETAIL_X4::FN::v<139>(X4FWD($)...)) $139, \
		decltype(DETAIL_X4::FN::v<140>(X4FWD($)...)) $140, \
		decltype(DETAIL_X4::FN::v<141>(X4FWD($)...)) $141, \
		decltype(DETAIL_X4::FN::v<142>(X4FWD($)...)) $142, \
		decltype(DETAIL_X4::FN::v<143>(X4FWD($)...)) $143, \
		decltype(DETAIL_X4::FN::v<144>(X4FWD($)...)) $144, \
		decltype(DETAIL_X4::FN::v<145>(X4FWD($)...)) $145, \
		decltype(DETAIL_X4::FN::v<146>(X4FWD($)...)) $146, \
		decltype(DETAIL_X4::FN::v<147>(X4FWD($)...)) $147, \
		decltype(DETAIL_X4::FN::v<148>(X4FWD($)...)) $148, \
		decltype(DETAIL_X4::FN::v<149>(X4FWD($)...)) $149, \
		decltype(DETAIL_X4::FN::v<150>(X4FWD($)...)) $150, \
		decltype(DETAIL_X4::FN::v<151>(X4FWD($)...)) $151, \
		decltype(DETAIL_X4::FN::v<152>(X4FWD($)...)) $152, \
		decltype(DETAIL_X4::FN::v<153>(X4FWD($)...)) $153, \
		decltype(DETAIL_X4::FN::v<154>(X4FWD($)...)) $154, \
		decltype(DETAIL_X4::FN::v<155>(X4FWD($)...)) $155, \
		decltype(DETAIL_X4::FN::v<156>(X4FWD($)...)) $156, \
		decltype(DETAIL_X4::FN::v<157>(X4FWD($)...)) $157, \
		decltype(DETAIL_X4::FN::v<158>(X4FWD($)...)) $158, \
		decltype(DETAIL_X4::FN::v<159>(X4FWD($)...)) $159, \
		decltype(DETAIL_X4::FN::v<160>(X4FWD($)...)) $160, \
		decltype(DETAIL_X4::FN::v<161>(X4FWD($)...)) $161, \
		decltype(DETAIL_X4::FN::v<162>(X4FWD($)...)) $162, \
		decltype(DETAIL_X4::FN::v<163>(X4FWD($)...)) $163, \
		decltype(DETAIL_X4::FN::v<164>(X4FWD($)...)) $164, \
		decltype(DETAIL_X4::FN::v<165>(X4FWD($)...)) $165, \
		decltype(DETAIL_X4::FN::v<166>(X4FWD($)...)) $166, \
		decltype(DETAIL_X4::FN::v<167>(X4FWD($)...)) $167, \
		decltype(DETAIL_X4::FN::v<168>(X4FWD($)...)) $168, \
		decltype(DETAIL_X4::FN::v<169>(X4FWD($)...)) $169, \
		decltype(DETAIL_X4::FN::v<170>(X4FWD($)...)) $170, \
		decltype(DETAIL_X4::FN::v<171>(X4FWD($)...)) $171, \
		decltype(DETAIL_X4::FN::v<172>(X4FWD($)...)) $172, \
		decltype(DETAIL_X4::FN::v<173>(X4FWD($)...)) $173, \
		decltype(DETAIL_X4::FN::v<174>(X4FWD($)...)) $174, \
		decltype(DETAIL_X4::FN::v<175>(X4FWD($)...)) $175, \
		decltype(DETAIL_X4::FN::v<176>(X4FWD($)...)) $176, \
		decltype(DETAIL_X4::FN::v<177>(X4FWD($)...)) $177, \
		decltype(DETAIL_X4::FN::v<178>(X4FWD($)...)) $178, \
		decltype(DETAIL_X4::FN::v<179>(X4FWD($)...)) $179, \
		decltype(DETAIL_X4::FN::v<180>(X4FWD($)...)) $180, \
		decltype(DETAIL_X4::FN::v<181>(X4FWD($)...)) $181, \
		decltype(DETAIL_X4::FN::v<182>(X4FWD($)...)) $182, \
		decltype(DETAIL_X4::FN::v<183>(X4FWD($)...)) $183, \
		decltype(DETAIL_X4::FN::v<184>(X4FWD($)...)) $184, \
		decltype(DETAIL_X4::FN::v<185>(X4FWD($)...)) $185, \
		decltype(DETAIL_X4::FN::v<186>(X4FWD($)...)) $186, \
		decltype(DETAIL_X4::FN::v<187>(X4FWD($)...)) $187, \
		decltype(DETAIL_X4::FN::v<188>(X4FWD($)...)) $188, \
		decltype(DETAIL_X4::FN::v<189>(X4FWD($)...)) $189, \
		decltype(DETAIL_X4::FN::v<190>(X4FWD($)...)) $190, \
		decltype(DETAIL_X4::FN::v<191>(X4FWD($)...)) $191, \
		decltype(DETAIL_X4::FN::v<192>(X4FWD($)...)) $192, \
		decltype(DETAIL_X4::FN::v<193>(X4FWD($)...)) $193, \
		decltype(DETAIL_X4::FN::v<194>(X4FWD($)...)) $194, \
		decltype(DETAIL_X4::FN::v<195>(X4FWD($)...)) $195, \
		decltype(DETAIL_X4::FN::v<196>(X4FWD($)...)) $196, \
		decltype(DETAIL_X4::FN::v<197>(X4FWD($)...)) $197, \
		decltype(DETAIL_X4::FN::v<198>(X4FWD($)...)) $198, \
		decltype(DETAIL_X4::FN::v<199>(X4FWD($)...)) $199, \
		decltype(DETAIL_X4::FN::v<200>(X4FWD($)...)) $200, \
		decltype(DETAIL_X4::FN::v<201>(X4FWD($)...)) $201, \
		decltype(DETAIL_X4::FN::v<202>(X4FWD($)...)) $202, \
		decltype(DETAIL_X4::FN::v<203>(X4FWD($)...)) $203, \
		decltype(DETAIL_X4::FN::v<204>(X4FWD($)...)) $204, \
		decltype(DETAIL_X4::FN::v<205>(X4FWD($)...)) $205, \
		decltype(DETAIL_X4::FN::v<206>(X4FWD($)...)) $206, \
		decltype(DETAIL_X4::FN::v<207>(X4FWD($)...)) $207, \
		decltype(DETAIL_X4::FN::v<208>(X4FWD($)...)) $208, \
		decltype(DETAIL_X4::FN::v<209>(X4FWD($)...)) $209, \
		decltype(DETAIL_X4::FN::v<210>(X4FWD($)...)) $210, \
		decltype(DETAIL_X4::FN::v<211>(X4FWD($)...)) $211, \
		decltype(DETAIL_X4::FN::v<212>(X4FWD($)...)) $212, \
		decltype(DETAIL_X4::FN::v<213>(X4FWD($)...)) $213, \
		decltype(DETAIL_X4::FN::v<214>(X4FWD($)...)) $214, \
		decltype(DETAIL_X4::FN::v<215>(X4FWD($)...)) $215, \
		decltype(DETAIL_X4::FN::v<216>(X4FWD($)...)) $216, \
		decltype(DETAIL_X4::FN::v<217>(X4FWD($)...)) $217, \
		decltype(DETAIL_X4::FN::v<218>(X4FWD($)...)) $218, \
		decltype(DETAIL_X4::FN::v<219>(X4FWD($)...)) $219, \
		decltype(DETAIL_X4::FN::v<220>(X4FWD($)...)) $220, \
		decltype(DETAIL_X4::FN::v<221>(X4FWD($)...)) $221, \
		decltype(DETAIL_X4::FN::v<222>(X4FWD($)...)) $222, \
		decltype(DETAIL_X4::FN::v<223>(X4FWD($)...)) $223, \
		decltype(DETAIL_X4::FN::v<224>(X4FWD($)...)) $224, \
		decltype(DETAIL_X4::FN::v<225>(X4FWD($)...)) $225, \
		decltype(DETAIL_X4::FN::v<226>(X4FWD($)...)) $226, \
		decltype(DETAIL_X4::FN::v<227>(X4FWD($)...)) $227, \
		decltype(DETAIL_X4::FN::v<228>(X4FWD($)...)) $228, \
		decltype(DETAIL_X4::FN::v<229>(X4FWD($)...)) $229, \
		decltype(DETAIL_X4::FN::v<230>(X4FWD($)...)) $230, \
		decltype(DETAIL_X4::FN::v<231>(X4FWD($)...)) $231, \
		decltype(DETAIL_X4::FN::v<232>(X4FWD($)...)) $232, \
		decltype(DETAIL_X4::FN::v<233>(X4FWD($)...)) $233, \
		decltype(DETAIL_X4::FN::v<234>(X4FWD($)...)) $234, \
		decltype(DETAIL_X4::FN::v<235>(X4FWD($)...)) $235, \
		decltype(DETAIL_X4::FN::v<236>(X4FWD($)...)) $236, \
		decltype(DETAIL_X4::FN::v<237>(X4FWD($)...)) $237, \
		decltype(DETAIL_X4::FN::v<238>(X4FWD($)...)) $238, \
		decltype(DETAIL_X4::FN::v<239>(X4FWD($)...)) $239, \
		decltype(DETAIL_X4::FN::v<240>(X4FWD($)...)) $240, \
		decltype(DETAIL_X4::FN::v<241>(X4FWD($)...)) $241, \
		decltype(DETAIL_X4::FN::v<242>(X4FWD($)...)) $242, \
		decltype(DETAIL_X4::FN::v<243>(X4FWD($)...)) $243, \
		decltype(DETAIL_X4::FN::v<244>(X4FWD($)...)) $244, \
		decltype(DETAIL_X4::FN::v<245>(X4FWD($)...)) $245, \
		decltype(DETAIL_X4::FN::v<246>(X4FWD($)...)) $246, \
		decltype(DETAIL_X4::FN::v<247>(X4FWD($)...)) $247, \
		decltype(DETAIL_X4::FN::v<248>(X4FWD($)...)) $248, \
		decltype(DETAIL_X4::FN::v<249>(X4FWD($)...)) $249, \
		decltype(DETAIL_X4::FN::v<250>(X4FWD($)...)) $250, \
		decltype(DETAIL_X4::FN::v<251>(X4FWD($)...)) $251, \
		decltype(DETAIL_X4::FN::v<252>(X4FWD($)...)) $252, \
		decltype(DETAIL_X4::FN::v<253>(X4FWD($)...)) $253, \
		decltype(DETAIL_X4::FN::v<254>(X4FWD($)...)) $254, \
		decltype(DETAIL_X4::FN::v<255>(X4FWD($)...)) $255, \
		decltype(DETAIL_X4::FN::v<256>(X4FWD($)...)) $256 \
	) { (__VA_ARGS__); }) { \
		[[maybe_unused]] auto&& $0 = DETAIL_X4::FN::v<0>(X4FWD($)...); \
		[[maybe_unused]] auto&& $1 = DETAIL_X4::FN::v<1>(X4FWD($)...); \
		[[maybe_unused]] auto&& $2 = DETAIL_X4::FN::v<2>(X4FWD($)...); \
		[[maybe_unused]] auto&& $3 = DETAIL_X4::FN::v<3>(X4FWD($)...); \
		[[maybe_unused]] auto&& $4 = DETAIL_X4::FN::v<4>(X4FWD($)...); \
		[[maybe_unused]] auto&& $5 = DETAIL_X4::FN::v<5>(X4FWD($)...); \
		[[maybe_unused]] auto&& $6 = DETAIL_X4::FN::v<6>(X4FWD($)...); \
		[[maybe_unused]] auto&& $7 = DETAIL_X4::FN::v<7>(X4FWD($)...); \
		[[maybe_unused]] auto&& $8 = DETAIL_X4::FN::v<8>(X4FWD($)...); \
		[[maybe_unused]] auto&& $9 = DETAIL_X4::FN::v<9>(X4FWD($)...); \
		[[maybe_unused]] auto&& $10 = DETAIL_X4::FN::v<10>(X4FWD($)...); \
		[[maybe_unused]] auto&& $11 = DETAIL_X4::FN::v<11>(X4FWD($)...); \
		[[maybe_unused]] auto&& $12 = DETAIL_X4::FN::v<12>(X4FWD($)...); \
		[[maybe_unused]] auto&& $13 = DETAIL_X4::FN::v<13>(X4FWD($)...); \
		[[maybe_unused]] auto&& $14 = DETAIL_X4::FN::v<14>(X4FWD($)...); \
		[[maybe_unused]] auto&& $15 = DETAIL_X4::FN::v<15>(X4FWD($)...); \
		[[maybe_unused]] auto&& $16 = DETAIL_X4::FN::v<16>(X4FWD($)...); \
		[[maybe_unused]] auto&& $17 = DETAIL_X4::FN::v<17>(X4FWD($)...); \
		[[maybe_unused]] auto&& $18 = DETAIL_X4::FN::v<18>(X4FWD($)...); \
		[[maybe_unused]] auto&& $19 = DETAIL_X4::FN::v<19>(X4FWD($)...); \
		[[maybe_unused]] auto&& $20 = DETAIL_X4::FN::v<20>(X4FWD($)...); \
		[[maybe_unused]] auto&& $21 = DETAIL_X4::FN::v<21>(X4FWD($)...); \
		[[maybe_unused]] auto&& $22 = DETAIL_X4::FN::v<22>(X4FWD($)...); \
		[[maybe_unused]] auto&& $23 = DETAIL_X4::FN::v<23>(X4FWD($)...); \
		[[maybe_unused]] auto&& $24 = DETAIL_X4::FN::v<24>(X4FWD($)...); \
		[[maybe_unused]] auto&& $25 = DETAIL_X4::FN::v<25>(X4FWD($)...); \
		[[maybe_unused]] auto&& $26 = DETAIL_X4::FN::v<26>(X4FWD($)...); \
		[[maybe_unused]] auto&& $27 = DETAIL_X4::FN::v<27>(X4FWD($)...); \
		[[maybe_unused]] auto&& $28 = DETAIL_X4::FN::v<28>(X4FWD($)...); \
		[[maybe_unused]] auto&& $29 = DETAIL_X4::FN::v<29>(X4FWD($)...); \
		[[maybe_unused]] auto&& $30 = DETAIL_X4::FN::v<30>(X4FWD($)...); \
		[[maybe_unused]] auto&& $31 = DETAIL_X4::FN::v<31>(X4FWD($)...); \
		[[maybe_unused]] auto&& $32 = DETAIL_X4::FN::v<32>(X4FWD($)...); \
		[[maybe_unused]] auto&& $33 = DETAIL_X4::FN::v<33>(X4FWD($)...); \
		[[maybe_unused]] auto&& $34 = DETAIL_X4::FN::v<34>(X4FWD($)...); \
		[[maybe_unused]] auto&& $35 = DETAIL_X4::FN::v<35>(X4FWD($)...); \
		[[maybe_unused]] auto&& $36 = DETAIL_X4::FN::v<36>(X4FWD($)...); \
		[[maybe_unused]] auto&& $37 = DETAIL_X4::FN::v<37>(X4FWD($)...); \
		[[maybe_unused]] auto&& $38 = DETAIL_X4::FN::v<38>(X4FWD($)...); \
		[[maybe_unused]] auto&& $39 = DETAIL_X4::FN::v<39>(X4FWD($)...); \
		[[maybe_unused]] auto&& $40 = DETAIL_X4::FN::v<40>(X4FWD($)...); \
		[[maybe_unused]] auto&& $41 = DETAIL_X4::FN::v<41>(X4FWD($)...); \
		[[maybe_unused]] auto&& $42 = DETAIL_X4::FN::v<42>(X4FWD($)...); \
		[[maybe_unused]] auto&& $43 = DETAIL_X4::FN::v<43>(X4FWD($)...); \
		[[maybe_unused]] auto&& $44 = DETAIL_X4::FN::v<44>(X4FWD($)...); \
		[[maybe_unused]] auto&& $45 = DETAIL_X4::FN::v<45>(X4FWD($)...); \
		[[maybe_unused]] auto&& $46 = DETAIL_X4::FN::v<46>(X4FWD($)...); \
		[[maybe_unused]] auto&& $47 = DETAIL_X4::FN::v<47>(X4FWD($)...); \
		[[maybe_unused]] auto&& $48 = DETAIL_X4::FN::v<48>(X4FWD($)...); \
		[[maybe_unused]] auto&& $49 = DETAIL_X4::FN::v<49>(X4FWD($)...); \
		[[maybe_unused]] auto&& $50 = DETAIL_X4::FN::v<50>(X4FWD($)...); \
		[[maybe_unused]] auto&& $51 = DETAIL_X4::FN::v<51>(X4FWD($)...); \
		[[maybe_unused]] auto&& $52 = DETAIL_X4::FN::v<52>(X4FWD($)...); \
		[[maybe_unused]] auto&& $53 = DETAIL_X4::FN::v<53>(X4FWD($)...); \
		[[maybe_unused]] auto&& $54 = DETAIL_X4::FN::v<54>(X4FWD($)...); \
		[[maybe_unused]] auto&& $55 = DETAIL_X4::FN::v<55>(X4FWD($)...); \
		[[maybe_unused]] auto&& $56 = DETAIL_X4::FN::v<56>(X4FWD($)...); \
		[[maybe_unused]] auto&& $57 = DETAIL_X4::FN::v<57>(X4FWD($)...); \
		[[maybe_unused]] auto&& $58 = DETAIL_X4::FN::v<58>(X4FWD($)...); \
		[[maybe_unused]] auto&& $59 = DETAIL_X4::FN::v<59>(X4FWD($)...); \
		[[maybe_unused]] auto&& $60 = DETAIL_X4::FN::v<60>(X4FWD($)...); \
		[[maybe_unused]] auto&& $61 = DETAIL_X4::FN::v<61>(X4FWD($)...); \
		[[maybe_unused]] auto&& $62 = DETAIL_X4::FN::v<62>(X4FWD($)...); \
		[[maybe_unused]] auto&& $63 = DETAIL_X4::FN::v<63>(X4FWD($)...); \
		[[maybe_unused]] auto&& $64 = DETAIL_X4::FN::v<64>(X4FWD($)...); \
		[[maybe_unused]] auto&& $65 = DETAIL_X4::FN::v<65>(X4FWD($)...); \
		[[maybe_unused]] auto&& $66 = DETAIL_X4::FN::v<66>(X4FWD($)...); \
		[[maybe_unused]] auto&& $67 = DETAIL_X4::FN::v<67>(X4FWD($)...); \
		[[maybe_unused]] auto&& $68 = DETAIL_X4::FN::v<68>(X4FWD($)...); \
		[[maybe_unused]] auto&& $69 = DETAIL_X4::FN::v<69>(X4FWD($)...); \
		[[maybe_unused]] auto&& $70 = DETAIL_X4::FN::v<70>(X4FWD($)...); \
		[[maybe_unused]] auto&& $71 = DETAIL_X4::FN::v<71>(X4FWD($)...); \
		[[maybe_unused]] auto&& $72 = DETAIL_X4::FN::v<72>(X4FWD($)...); \
		[[maybe_unused]] auto&& $73 = DETAIL_X4::FN::v<73>(X4FWD($)...); \
		[[maybe_unused]] auto&& $74 = DETAIL_X4::FN::v<74>(X4FWD($)...); \
		[[maybe_unused]] auto&& $75 = DETAIL_X4::FN::v<75>(X4FWD($)...); \
		[[maybe_unused]] auto&& $76 = DETAIL_X4::FN::v<76>(X4FWD($)...); \
		[[maybe_unused]] auto&& $77 = DETAIL_X4::FN::v<77>(X4FWD($)...); \
		[[maybe_unused]] auto&& $78 = DETAIL_X4::FN::v<78>(X4FWD($)...); \
		[[maybe_unused]] auto&& $79 = DETAIL_X4::FN::v<79>(X4FWD($)...); \
		[[maybe_unused]] auto&& $80 = DETAIL_X4::FN::v<80>(X4FWD($)...); \
		[[maybe_unused]] auto&& $81 = DETAIL_X4::FN::v<81>(X4FWD($)...); \
		[[maybe_unused]] auto&& $82 = DETAIL_X4::FN::v<82>(X4FWD($)...); \
		[[maybe_unused]] auto&& $83 = DETAIL_X4::FN::v<83>(X4FWD($)...); \
		[[maybe_unused]] auto&& $84 = DETAIL_X4::FN::v<84>(X4FWD($)...); \
		[[maybe_unused]] auto&& $85 = DETAIL_X4::FN::v<85>(X4FWD($)...); \
		[[maybe_unused]] auto&& $86 = DETAIL_X4::FN::v<86>(X4FWD($)...); \
		[[maybe_unused]] auto&& $87 = DETAIL_X4::FN::v<87>(X4FWD($)...); \
		[[maybe_unused]] auto&& $88 = DETAIL_X4::FN::v<88>(X4FWD($)...); \
		[[maybe_unused]] auto&& $89 = DETAIL_X4::FN::v<89>(X4FWD($)...); \
		[[maybe_unused]] auto&& $90 = DETAIL_X4::FN::v<90>(X4FWD($)...); \
		[[maybe_unused]] auto&& $91 = DETAIL_X4::FN::v<91>(X4FWD($)...); \
		[[maybe_unused]] auto&& $92 = DETAIL_X4::FN::v<92>(X4FWD($)...); \
		[[maybe_unused]] auto&& $93 = DETAIL_X4::FN::v<93>(X4FWD($)...); \
		[[maybe_unused]] auto&& $94 = DETAIL_X4::FN::v<94>(X4FWD($)...); \
		[[maybe_unused]] auto&& $95 = DETAIL_X4::FN::v<95>(X4FWD($)...); \
		[[maybe_unused]] auto&& $96 = DETAIL_X4::FN::v<96>(X4FWD($)...); \
		[[maybe_unused]] auto&& $97 = DETAIL_X4::FN::v<97>(X4FWD($)...); \
		[[maybe_unused]] auto&& $98 = DETAIL_X4::FN::v<98>(X4FWD($)...); \
		[[maybe_unused]] auto&& $99 = DETAIL_X4::FN::v<99>(X4FWD($)...); \
		[[maybe_unused]] auto&& $100 = DETAIL_X4::FN::v<100>(X4FWD($)...); \
		[[maybe_unused]] auto&& $101 = DETAIL_X4::FN::v<101>(X4FWD($)...); \
		[[maybe_unused]] auto&& $102 = DETAIL_X4::FN::v<102>(X4FWD($)...); \
		[[maybe_unused]] auto&& $103 = DETAIL_X4::FN::v<103>(X4FWD($)...); \
		[[maybe_unused]] auto&& $104 = DETAIL_X4::FN::v<104>(X4FWD($)...); \
		[[maybe_unused]] auto&& $105 = DETAIL_X4::FN::v<105>(X4FWD($)...); \
		[[maybe_unused]] auto&& $106 = DETAIL_X4::FN::v<106>(X4FWD($)...); \
		[[maybe_unused]] auto&& $107 = DETAIL_X4::FN::v<107>(X4FWD($)...); \
		[[maybe_unused]] auto&& $108 = DETAIL_X4::FN::v<108>(X4FWD($)...); \
		[[maybe_unused]] auto&& $109 = DETAIL_X4::FN::v<109>(X4FWD($)...); \
		[[maybe_unused]] auto&& $110 = DETAIL_X4::FN::v<110>(X4FWD($)...); \
		[[maybe_unused]] auto&& $111 = DETAIL_X4::FN::v<111>(X4FWD($)...); \
		[[maybe_unused]] auto&& $112 = DETAIL_X4::FN::v<112>(X4FWD($)...); \
		[[maybe_unused]] auto&& $113 = DETAIL_X4::FN::v<113>(X4FWD($)...); \
		[[maybe_unused]] auto&& $114 = DETAIL_X4::FN::v<114>(X4FWD($)...); \
		[[maybe_unused]] auto&& $115 = DETAIL_X4::FN::v<115>(X4FWD($)...); \
		[[maybe_unused]] auto&& $116 = DETAIL_X4::FN::v<116>(X4FWD($)...); \
		[[maybe_unused]] auto&& $117 = DETAIL_X4::FN::v<117>(X4FWD($)...); \
		[[maybe_unused]] auto&& $118 = DETAIL_X4::FN::v<118>(X4FWD($)...); \
		[[maybe_unused]] auto&& $119 = DETAIL_X4::FN::v<119>(X4FWD($)...); \
		[[maybe_unused]] auto&& $120 = DETAIL_X4::FN::v<120>(X4FWD($)...); \
		[[maybe_unused]] auto&& $121 = DETAIL_X4::FN::v<121>(X4FWD($)...); \
		[[maybe_unused]] auto&& $122 = DETAIL_X4::FN::v<122>(X4FWD($)...); \
		[[maybe_unused]] auto&& $123 = DETAIL_X4::FN::v<123>(X4FWD($)...); \
		[[maybe_unused]] auto&& $124 = DETAIL_X4::FN::v<124>(X4FWD($)...); \
		[[maybe_unused]] auto&& $125 = DETAIL_X4::FN::v<125>(X4FWD($)...); \
		[[maybe_unused]] auto&& $126 = DETAIL_X4::FN::v<126>(X4FWD($)...); \
		[[maybe_unused]] auto&& $127 = DETAIL_X4::FN::v<127>(X4FWD($)...); \
		[[maybe_unused]] auto&& $128 = DETAIL_X4::FN::v<128>(X4FWD($)...); \
		[[maybe_unused]] auto&& $129 = DETAIL_X4::FN::v<129>(X4FWD($)...); \
		[[maybe_unused]] auto&& $130 = DETAIL_X4::FN::v<130>(X4FWD($)...); \
		[[maybe_unused]] auto&& $131 = DETAIL_X4::FN::v<131>(X4FWD($)...); \
		[[maybe_unused]] auto&& $132 = DETAIL_X4::FN::v<132>(X4FWD($)...); \
		[[maybe_unused]] auto&& $133 = DETAIL_X4::FN::v<133>(X4FWD($)...); \
		[[maybe_unused]] auto&& $134 = DETAIL_X4::FN::v<134>(X4FWD($)...); \
		[[maybe_unused]] auto&& $135 = DETAIL_X4::FN::v<135>(X4FWD($)...); \
		[[maybe_unused]] auto&& $136 = DETAIL_X4::FN::v<136>(X4FWD($)...); \
		[[maybe_unused]] auto&& $137 = DETAIL_X4::FN::v<137>(X4FWD($)...); \
		[[maybe_unused]] auto&& $138 = DETAIL_X4::FN::v<138>(X4FWD($)...); \
		[[maybe_unused]] auto&& $139 = DETAIL_X4::FN::v<139>(X4FWD($)...); \
		[[maybe_unused]] auto&& $140 = DETAIL_X4::FN::v<140>(X4FWD($)...); \
		[[maybe_unused]] auto&& $141 = DETAIL_X4::FN::v<141>(X4FWD($)...); \
		[[maybe_unused]] auto&& $142 = DETAIL_X4::FN::v<142>(X4FWD($)...); \
		[[maybe_unused]] auto&& $143 = DETAIL_X4::FN::v<143>(X4FWD($)...); \
		[[maybe_unused]] auto&& $144 = DETAIL_X4::FN::v<144>(X4FWD($)...); \
		[[maybe_unused]] auto&& $145 = DETAIL_X4::FN::v<145>(X4FWD($)...); \
		[[maybe_unused]] auto&& $146 = DETAIL_X4::FN::v<146>(X4FWD($)...); \
		[[maybe_unused]] auto&& $147 = DETAIL_X4::FN::v<147>(X4FWD($)...); \
		[[maybe_unused]] auto&& $148 = DETAIL_X4::FN::v<148>(X4FWD($)...); \
		[[maybe_unused]] auto&& $149 = DETAIL_X4::FN::v<149>(X4FWD($)...); \
		[[maybe_unused]] auto&& $150 = DETAIL_X4::FN::v<150>(X4FWD($)...); \
		[[maybe_unused]] auto&& $151 = DETAIL_X4::FN::v<151>(X4FWD($)...); \
		[[maybe_unused]] auto&& $152 = DETAIL_X4::FN::v<152>(X4FWD($)...); \
		[[maybe_unused]] auto&& $153 = DETAIL_X4::FN::v<153>(X4FWD($)...); \
		[[maybe_unused]] auto&& $154 = DETAIL_X4::FN::v<154>(X4FWD($)...); \
		[[maybe_unused]] auto&& $155 = DETAIL_X4::FN::v<155>(X4FWD($)...); \
		[[maybe_unused]] auto&& $156 = DETAIL_X4::FN::v<156>(X4FWD($)...); \
		[[maybe_unused]] auto&& $157 = DETAIL_X4::FN::v<157>(X4FWD($)...); \
		[[maybe_unused]] auto&& $158 = DETAIL_X4::FN::v<158>(X4FWD($)...); \
		[[maybe_unused]] auto&& $159 = DETAIL_X4::FN::v<159>(X4FWD($)...); \
		[[maybe_unused]] auto&& $160 = DETAIL_X4::FN::v<160>(X4FWD($)...); \
		[[maybe_unused]] auto&& $161 = DETAIL_X4::FN::v<161>(X4FWD($)...); \
		[[maybe_unused]] auto&& $162 = DETAIL_X4::FN::v<162>(X4FWD($)...); \
		[[maybe_unused]] auto&& $163 = DETAIL_X4::FN::v<163>(X4FWD($)...); \
		[[maybe_unused]] auto&& $164 = DETAIL_X4::FN::v<164>(X4FWD($)...); \
		[[maybe_unused]] auto&& $165 = DETAIL_X4::FN::v<165>(X4FWD($)...); \
		[[maybe_unused]] auto&& $166 = DETAIL_X4::FN::v<166>(X4FWD($)...); \
		[[maybe_unused]] auto&& $167 = DETAIL_X4::FN::v<167>(X4FWD($)...); \
		[[maybe_unused]] auto&& $168 = DETAIL_X4::FN::v<168>(X4FWD($)...); \
		[[maybe_unused]] auto&& $169 = DETAIL_X4::FN::v<169>(X4FWD($)...); \
		[[maybe_unused]] auto&& $170 = DETAIL_X4::FN::v<170>(X4FWD($)...); \
		[[maybe_unused]] auto&& $171 = DETAIL_X4::FN::v<171>(X4FWD($)...); \
		[[maybe_unused]] auto&& $172 = DETAIL_X4::FN::v<172>(X4FWD($)...); \
		[[maybe_unused]] auto&& $173 = DETAIL_X4::FN::v<173>(X4FWD($)...); \
		[[maybe_unused]] auto&& $174 = DETAIL_X4::FN::v<174>(X4FWD($)...); \
		[[maybe_unused]] auto&& $175 = DETAIL_X4::FN::v<175>(X4FWD($)...); \
		[[maybe_unused]] auto&& $176 = DETAIL_X4::FN::v<176>(X4FWD($)...); \
		[[maybe_unused]] auto&& $177 = DETAIL_X4::FN::v<177>(X4FWD($)...); \
		[[maybe_unused]] auto&& $178 = DETAIL_X4::FN::v<178>(X4FWD($)...); \
		[[maybe_unused]] auto&& $179 = DETAIL_X4::FN::v<179>(X4FWD($)...); \
		[[maybe_unused]] auto&& $180 = DETAIL_X4::FN::v<180>(X4FWD($)...); \
		[[maybe_unused]] auto&& $181 = DETAIL_X4::FN::v<181>(X4FWD($)...); \
		[[maybe_unused]] auto&& $182 = DETAIL_X4::FN::v<182>(X4FWD($)...); \
		[[maybe_unused]] auto&& $183 = DETAIL_X4::FN::v<183>(X4FWD($)...); \
		[[maybe_unused]] auto&& $184 = DETAIL_X4::FN::v<184>(X4FWD($)...); \
		[[maybe_unused]] auto&& $185 = DETAIL_X4::FN::v<185>(X4FWD($)...); \
		[[maybe_unused]] auto&& $186 = DETAIL_X4::FN::v<186>(X4FWD($)...); \
		[[maybe_unused]] auto&& $187 = DETAIL_X4::FN::v<187>(X4FWD($)...); \
		[[maybe_unused]] auto&& $188 = DETAIL_X4::FN::v<188>(X4FWD($)...); \
		[[maybe_unused]] auto&& $189 = DETAIL_X4::FN::v<189>(X4FWD($)...); \
		[[maybe_unused]] auto&& $190 = DETAIL_X4::FN::v<190>(X4FWD($)...); \
		[[maybe_unused]] auto&& $191 = DETAIL_X4::FN::v<191>(X4FWD($)...); \
		[[maybe_unused]] auto&& $192 = DETAIL_X4::FN::v<192>(X4FWD($)...); \
		[[maybe_unused]] auto&& $193 = DETAIL_X4::FN::v<193>(X4FWD($)...); \
		[[maybe_unused]] auto&& $194 = DETAIL_X4::FN::v<194>(X4FWD($)...); \
		[[maybe_unused]] auto&& $195 = DETAIL_X4::FN::v<195>(X4FWD($)...); \
		[[maybe_unused]] auto&& $196 = DETAIL_X4::FN::v<196>(X4FWD($)...); \
		[[maybe_unused]] auto&& $197 = DETAIL_X4::FN::v<197>(X4FWD($)...); \
		[[maybe_unused]] auto&& $198 = DETAIL_X4::FN::v<198>(X4FWD($)...); \
		[[maybe_unused]] auto&& $199 = DETAIL_X4::FN::v<199>(X4FWD($)...); \
		[[maybe_unused]] auto&& $200 = DETAIL_X4::FN::v<200>(X4FWD($)...); \
		[[maybe_unused]] auto&& $201 = DETAIL_X4::FN::v<201>(X4FWD($)...); \
		[[maybe_unused]] auto&& $202 = DETAIL_X4::FN::v<202>(X4FWD($)...); \
		[[maybe_unused]] auto&& $203 = DETAIL_X4::FN::v<203>(X4FWD($)...); \
		[[maybe_unused]] auto&& $204 = DETAIL_X4::FN::v<204>(X4FWD($)...); \
		[[maybe_unused]] auto&& $205 = DETAIL_X4::FN::v<205>(X4FWD($)...); \
		[[maybe_unused]] auto&& $206 = DETAIL_X4::FN::v<206>(X4FWD($)...); \
		[[maybe_unused]] auto&& $207 = DETAIL_X4::FN::v<207>(X4FWD($)...); \
		[[maybe_unused]] auto&& $208 = DETAIL_X4::FN::v<208>(X4FWD($)...); \
		[[maybe_unused]] auto&& $209 = DETAIL_X4::FN::v<209>(X4FWD($)...); \
		[[maybe_unused]] auto&& $210 = DETAIL_X4::FN::v<210>(X4FWD($)...); \
		[[maybe_unused]] auto&& $211 = DETAIL_X4::FN::v<211>(X4FWD($)...); \
		[[maybe_unused]] auto&& $212 = DETAIL_X4::FN::v<212>(X4FWD($)...); \
		[[maybe_unused]] auto&& $213 = DETAIL_X4::FN::v<213>(X4FWD($)...); \
		[[maybe_unused]] auto&& $214 = DETAIL_X4::FN::v<214>(X4FWD($)...); \
		[[maybe_unused]] auto&& $215 = DETAIL_X4::FN::v<215>(X4FWD($)...); \
		[[maybe_unused]] auto&& $216 = DETAIL_X4::FN::v<216>(X4FWD($)...); \
		[[maybe_unused]] auto&& $217 = DETAIL_X4::FN::v<217>(X4FWD($)...); \
		[[maybe_unused]] auto&& $218 = DETAIL_X4::FN::v<218>(X4FWD($)...); \
		[[maybe_unused]] auto&& $219 = DETAIL_X4::FN::v<219>(X4FWD($)...); \
		[[maybe_unused]] auto&& $220 = DETAIL_X4::FN::v<220>(X4FWD($)...); \
		[[maybe_unused]] auto&& $221 = DETAIL_X4::FN::v<221>(X4FWD($)...); \
		[[maybe_unused]] auto&& $222 = DETAIL_X4::FN::v<222>(X4FWD($)...); \
		[[maybe_unused]] auto&& $223 = DETAIL_X4::FN::v<223>(X4FWD($)...); \
		[[maybe_unused]] auto&& $224 = DETAIL_X4::FN::v<224>(X4FWD($)...); \
		[[maybe_unused]] auto&& $225 = DETAIL_X4::FN::v<225>(X4FWD($)...); \
		[[maybe_unused]] auto&& $226 = DETAIL_X4::FN::v<226>(X4FWD($)...); \
		[[maybe_unused]] auto&& $227 = DETAIL_X4::FN::v<227>(X4FWD($)...); \
		[[maybe_unused]] auto&& $228 = DETAIL_X4::FN::v<228>(X4FWD($)...); \
		[[maybe_unused]] auto&& $229 = DETAIL_X4::FN::v<229>(X4FWD($)...); \
		[[maybe_unused]] auto&& $230 = DETAIL_X4::FN::v<230>(X4FWD($)...); \
		[[maybe_unused]] auto&& $231 = DETAIL_X4::FN::v<231>(X4FWD($)...); \
		[[maybe_unused]] auto&& $232 = DETAIL_X4::FN::v<232>(X4FWD($)...); \
		[[maybe_unused]] auto&& $233 = DETAIL_X4::FN::v<233>(X4FWD($)...); \
		[[maybe_unused]] auto&& $234 = DETAIL_X4::FN::v<234>(X4FWD($)...); \
		[[maybe_unused]] auto&& $235 = DETAIL_X4::FN::v<235>(X4FWD($)...); \
		[[maybe_unused]] auto&& $236 = DETAIL_X4::FN::v<236>(X4FWD($)...); \
		[[maybe_unused]] auto&& $237 = DETAIL_X4::FN::v<237>(X4FWD($)...); \
		[[maybe_unused]] auto&& $238 = DETAIL_X4::FN::v<238>(X4FWD($)...); \
		[[maybe_unused]] auto&& $239 = DETAIL_X4::FN::v<239>(X4FWD($)...); \
		[[maybe_unused]] auto&& $240 = DETAIL_X4::FN::v<240>(X4FWD($)...); \
		[[maybe_unused]] auto&& $241 = DETAIL_X4::FN::v<241>(X4FWD($)...); \
		[[maybe_unused]] auto&& $242 = DETAIL_X4::FN::v<242>(X4FWD($)...); \
		[[maybe_unused]] auto&& $243 = DETAIL_X4::FN::v<243>(X4FWD($)...); \
		[[maybe_unused]] auto&& $244 = DETAIL_X4::FN::v<244>(X4FWD($)...); \
		[[maybe_unused]] auto&& $245 = DETAIL_X4::FN::v<245>(X4FWD($)...); \
		[[maybe_unused]] auto&& $246 = DETAIL_X4::FN::v<246>(X4FWD($)...); \
		[[maybe_unused]] auto&& $247 = DETAIL_X4::FN::v<247>(X4FWD($)...); \
		[[maybe_unused]] auto&& $248 = DETAIL_X4::FN::v<248>(X4FWD($)...); \
		[[maybe_unused]] auto&& $249 = DETAIL_X4::FN::v<249>(X4FWD($)...); \
		[[maybe_unused]] auto&& $250 = DETAIL_X4::FN::v<250>(X4FWD($)...); \
		[[maybe_unused]] auto&& $251 = DETAIL_X4::FN::v<251>(X4FWD($)...); \
		[[maybe_unused]] auto&& $252 = DETAIL_X4::FN::v<252>(X4FWD($)...); \
		[[maybe_unused]] auto&& $253 = DETAIL_X4::FN::v<253>(X4FWD($)...); \
		[[maybe_unused]] auto&& $254 = DETAIL_X4::FN::v<254>(X4FWD($)...); \
		[[maybe_unused]] auto&& $255 = DETAIL_X4::FN::v<255>(X4FWD($)...); \
		[[maybe_unused]] auto&& $256 = DETAIL_X4::FN::v<256>(X4FWD($)...); \
		return (__VA_ARGS__); \
	}

namespace DETAIL_X4::FN {
	template<std::size_t idx>
	constexpr auto&& v(auto&&...) noexcept;

	struct unusable {
	public:
		template<std::size_t idx>
		[[nodiscard]] friend constexpr auto&& v(auto&&... args) noexcept {
			if constexpr (idx < sizeof...(args)) {
				return X4FWD(args...[idx]);
			} else {
				static constexpr DETAIL_X4::FN::unusable unusable;
				return unusable;
			}
		}

	private:
		unusable() = default;
	};

	template<std::size_t idx, typename... Ts>
	using t = decltype(([]<typename... Us> static {
		if constexpr (idx < sizeof...(Us)) {
			return std::type_identity<Us...[idx]>();
		} else {
			return std::type_identity<DETAIL_X4::FN::unusable>();
		}
	}).template operator()<Ts...>())::type;
	template<typename F>
	struct indirect : F {
		template<typename... Ts>
		constexpr auto operator()(this auto&& self, auto&&... args)
			X4AR(static_cast<F&>(self)().template operator()<Ts...>(X4FWD(args)...))
	};
}
