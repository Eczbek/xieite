#pragma once

#include <cstddef>
#include <type_traits>
#include "../pp/comma.hpp"
#include "../pp/diag.hpp"
#include "../pp/fwd.hpp"
#include "../pp/if.hpp"
#include "../pp/unwrap.hpp"

#define XIEITE_FN(...) []XIEITE_DETAIL_FN(0, __VA_ARGS__)
#define XIEITE_FN_LOCAL(...) [&]XIEITE_DETAIL_FN(1, __VA_ARGS__)
#define XIEITE_FN_THIS(...) []XIEITE_DETAIL_FN(1, __VA_ARGS__)
#define XIEITE_FN_MUT(captures_, ...) XIEITE_DETAIL::FN::indirect([XIEITE_UNWRAP(captures_)] mutable { return [&]XIEITE_DETAIL_FN(1, __VA_ARGS__); })

XIEITE_DIAG_OFF_CLANG("-Wdollar-in-identifier-extension")

#define XIEITE_DETAIL_FN(this_, ...) \
	< \
		typename... $$, \
		XIEITE_IF(this_)(typename $$this XIEITE_COMMA()) \
		typename $$0 = XIEITE_DETAIL::FN::t<0, $$...>, \
		typename $$1 = XIEITE_DETAIL::FN::t<1, $$...>, \
		typename $$2 = XIEITE_DETAIL::FN::t<2, $$...>, \
		typename $$3 = XIEITE_DETAIL::FN::t<3, $$...>, \
		typename $$4 = XIEITE_DETAIL::FN::t<4, $$...>, \
		typename $$5 = XIEITE_DETAIL::FN::t<5, $$...>, \
		typename $$6 = XIEITE_DETAIL::FN::t<6, $$...>, \
		typename $$7 = XIEITE_DETAIL::FN::t<7, $$...>, \
		typename $$8 = XIEITE_DETAIL::FN::t<8, $$...>, \
		typename $$9 = XIEITE_DETAIL::FN::t<9, $$...>, \
		typename $$10 = XIEITE_DETAIL::FN::t<10, $$...>, \
		typename $$11 = XIEITE_DETAIL::FN::t<11, $$...>, \
		typename $$12 = XIEITE_DETAIL::FN::t<12, $$...>, \
		typename $$13 = XIEITE_DETAIL::FN::t<13, $$...>, \
		typename $$14 = XIEITE_DETAIL::FN::t<14, $$...>, \
		typename $$15 = XIEITE_DETAIL::FN::t<15, $$...>, \
		typename $$16 = XIEITE_DETAIL::FN::t<16, $$...>, \
		typename $$17 = XIEITE_DETAIL::FN::t<17, $$...>, \
		typename $$18 = XIEITE_DETAIL::FN::t<18, $$...>, \
		typename $$19 = XIEITE_DETAIL::FN::t<19, $$...>, \
		typename $$20 = XIEITE_DETAIL::FN::t<20, $$...>, \
		typename $$21 = XIEITE_DETAIL::FN::t<21, $$...>, \
		typename $$22 = XIEITE_DETAIL::FN::t<22, $$...>, \
		typename $$23 = XIEITE_DETAIL::FN::t<23, $$...>, \
		typename $$24 = XIEITE_DETAIL::FN::t<24, $$...>, \
		typename $$25 = XIEITE_DETAIL::FN::t<25, $$...>, \
		typename $$26 = XIEITE_DETAIL::FN::t<26, $$...>, \
		typename $$27 = XIEITE_DETAIL::FN::t<27, $$...>, \
		typename $$28 = XIEITE_DETAIL::FN::t<28, $$...>, \
		typename $$29 = XIEITE_DETAIL::FN::t<29, $$...>, \
		typename $$30 = XIEITE_DETAIL::FN::t<30, $$...>, \
		typename $$31 = XIEITE_DETAIL::FN::t<31, $$...>, \
		typename $$32 = XIEITE_DETAIL::FN::t<32, $$...>, \
		typename $$33 = XIEITE_DETAIL::FN::t<33, $$...>, \
		typename $$34 = XIEITE_DETAIL::FN::t<34, $$...>, \
		typename $$35 = XIEITE_DETAIL::FN::t<35, $$...>, \
		typename $$36 = XIEITE_DETAIL::FN::t<36, $$...>, \
		typename $$37 = XIEITE_DETAIL::FN::t<37, $$...>, \
		typename $$38 = XIEITE_DETAIL::FN::t<38, $$...>, \
		typename $$39 = XIEITE_DETAIL::FN::t<39, $$...>, \
		typename $$40 = XIEITE_DETAIL::FN::t<40, $$...>, \
		typename $$41 = XIEITE_DETAIL::FN::t<41, $$...>, \
		typename $$42 = XIEITE_DETAIL::FN::t<42, $$...>, \
		typename $$43 = XIEITE_DETAIL::FN::t<43, $$...>, \
		typename $$44 = XIEITE_DETAIL::FN::t<44, $$...>, \
		typename $$45 = XIEITE_DETAIL::FN::t<45, $$...>, \
		typename $$46 = XIEITE_DETAIL::FN::t<46, $$...>, \
		typename $$47 = XIEITE_DETAIL::FN::t<47, $$...>, \
		typename $$48 = XIEITE_DETAIL::FN::t<48, $$...>, \
		typename $$49 = XIEITE_DETAIL::FN::t<49, $$...>, \
		typename $$50 = XIEITE_DETAIL::FN::t<50, $$...>, \
		typename $$51 = XIEITE_DETAIL::FN::t<51, $$...>, \
		typename $$52 = XIEITE_DETAIL::FN::t<52, $$...>, \
		typename $$53 = XIEITE_DETAIL::FN::t<53, $$...>, \
		typename $$54 = XIEITE_DETAIL::FN::t<54, $$...>, \
		typename $$55 = XIEITE_DETAIL::FN::t<55, $$...>, \
		typename $$56 = XIEITE_DETAIL::FN::t<56, $$...>, \
		typename $$57 = XIEITE_DETAIL::FN::t<57, $$...>, \
		typename $$58 = XIEITE_DETAIL::FN::t<58, $$...>, \
		typename $$59 = XIEITE_DETAIL::FN::t<59, $$...>, \
		typename $$60 = XIEITE_DETAIL::FN::t<60, $$...>, \
		typename $$61 = XIEITE_DETAIL::FN::t<61, $$...>, \
		typename $$62 = XIEITE_DETAIL::FN::t<62, $$...>, \
		typename $$63 = XIEITE_DETAIL::FN::t<63, $$...>, \
		typename $$64 = XIEITE_DETAIL::FN::t<64, $$...>, \
		typename $$65 = XIEITE_DETAIL::FN::t<65, $$...>, \
		typename $$66 = XIEITE_DETAIL::FN::t<66, $$...>, \
		typename $$67 = XIEITE_DETAIL::FN::t<67, $$...>, \
		typename $$68 = XIEITE_DETAIL::FN::t<68, $$...>, \
		typename $$69 = XIEITE_DETAIL::FN::t<69, $$...>, \
		typename $$70 = XIEITE_DETAIL::FN::t<70, $$...>, \
		typename $$71 = XIEITE_DETAIL::FN::t<71, $$...>, \
		typename $$72 = XIEITE_DETAIL::FN::t<72, $$...>, \
		typename $$73 = XIEITE_DETAIL::FN::t<73, $$...>, \
		typename $$74 = XIEITE_DETAIL::FN::t<74, $$...>, \
		typename $$75 = XIEITE_DETAIL::FN::t<75, $$...>, \
		typename $$76 = XIEITE_DETAIL::FN::t<76, $$...>, \
		typename $$77 = XIEITE_DETAIL::FN::t<77, $$...>, \
		typename $$78 = XIEITE_DETAIL::FN::t<78, $$...>, \
		typename $$79 = XIEITE_DETAIL::FN::t<79, $$...>, \
		typename $$80 = XIEITE_DETAIL::FN::t<80, $$...>, \
		typename $$81 = XIEITE_DETAIL::FN::t<81, $$...>, \
		typename $$82 = XIEITE_DETAIL::FN::t<82, $$...>, \
		typename $$83 = XIEITE_DETAIL::FN::t<83, $$...>, \
		typename $$84 = XIEITE_DETAIL::FN::t<84, $$...>, \
		typename $$85 = XIEITE_DETAIL::FN::t<85, $$...>, \
		typename $$86 = XIEITE_DETAIL::FN::t<86, $$...>, \
		typename $$87 = XIEITE_DETAIL::FN::t<87, $$...>, \
		typename $$88 = XIEITE_DETAIL::FN::t<88, $$...>, \
		typename $$89 = XIEITE_DETAIL::FN::t<89, $$...>, \
		typename $$90 = XIEITE_DETAIL::FN::t<90, $$...>, \
		typename $$91 = XIEITE_DETAIL::FN::t<91, $$...>, \
		typename $$92 = XIEITE_DETAIL::FN::t<92, $$...>, \
		typename $$93 = XIEITE_DETAIL::FN::t<93, $$...>, \
		typename $$94 = XIEITE_DETAIL::FN::t<94, $$...>, \
		typename $$95 = XIEITE_DETAIL::FN::t<95, $$...>, \
		typename $$96 = XIEITE_DETAIL::FN::t<96, $$...>, \
		typename $$97 = XIEITE_DETAIL::FN::t<97, $$...>, \
		typename $$98 = XIEITE_DETAIL::FN::t<98, $$...>, \
		typename $$99 = XIEITE_DETAIL::FN::t<99, $$...>, \
		typename $$100 = XIEITE_DETAIL::FN::t<100, $$...>, \
		typename $$101 = XIEITE_DETAIL::FN::t<101, $$...>, \
		typename $$102 = XIEITE_DETAIL::FN::t<102, $$...>, \
		typename $$103 = XIEITE_DETAIL::FN::t<103, $$...>, \
		typename $$104 = XIEITE_DETAIL::FN::t<104, $$...>, \
		typename $$105 = XIEITE_DETAIL::FN::t<105, $$...>, \
		typename $$106 = XIEITE_DETAIL::FN::t<106, $$...>, \
		typename $$107 = XIEITE_DETAIL::FN::t<107, $$...>, \
		typename $$108 = XIEITE_DETAIL::FN::t<108, $$...>, \
		typename $$109 = XIEITE_DETAIL::FN::t<109, $$...>, \
		typename $$110 = XIEITE_DETAIL::FN::t<110, $$...>, \
		typename $$111 = XIEITE_DETAIL::FN::t<111, $$...>, \
		typename $$112 = XIEITE_DETAIL::FN::t<112, $$...>, \
		typename $$113 = XIEITE_DETAIL::FN::t<113, $$...>, \
		typename $$114 = XIEITE_DETAIL::FN::t<114, $$...>, \
		typename $$115 = XIEITE_DETAIL::FN::t<115, $$...>, \
		typename $$116 = XIEITE_DETAIL::FN::t<116, $$...>, \
		typename $$117 = XIEITE_DETAIL::FN::t<117, $$...>, \
		typename $$118 = XIEITE_DETAIL::FN::t<118, $$...>, \
		typename $$119 = XIEITE_DETAIL::FN::t<119, $$...>, \
		typename $$120 = XIEITE_DETAIL::FN::t<120, $$...>, \
		typename $$121 = XIEITE_DETAIL::FN::t<121, $$...>, \
		typename $$122 = XIEITE_DETAIL::FN::t<122, $$...>, \
		typename $$123 = XIEITE_DETAIL::FN::t<123, $$...>, \
		typename $$124 = XIEITE_DETAIL::FN::t<124, $$...>, \
		typename $$125 = XIEITE_DETAIL::FN::t<125, $$...>, \
		typename $$126 = XIEITE_DETAIL::FN::t<126, $$...>, \
		typename $$127 = XIEITE_DETAIL::FN::t<127, $$...>, \
		typename $$128 = XIEITE_DETAIL::FN::t<128, $$...>, \
		typename $$129 = XIEITE_DETAIL::FN::t<129, $$...>, \
		typename $$130 = XIEITE_DETAIL::FN::t<130, $$...>, \
		typename $$131 = XIEITE_DETAIL::FN::t<131, $$...>, \
		typename $$132 = XIEITE_DETAIL::FN::t<132, $$...>, \
		typename $$133 = XIEITE_DETAIL::FN::t<133, $$...>, \
		typename $$134 = XIEITE_DETAIL::FN::t<134, $$...>, \
		typename $$135 = XIEITE_DETAIL::FN::t<135, $$...>, \
		typename $$136 = XIEITE_DETAIL::FN::t<136, $$...>, \
		typename $$137 = XIEITE_DETAIL::FN::t<137, $$...>, \
		typename $$138 = XIEITE_DETAIL::FN::t<138, $$...>, \
		typename $$139 = XIEITE_DETAIL::FN::t<139, $$...>, \
		typename $$140 = XIEITE_DETAIL::FN::t<140, $$...>, \
		typename $$141 = XIEITE_DETAIL::FN::t<141, $$...>, \
		typename $$142 = XIEITE_DETAIL::FN::t<142, $$...>, \
		typename $$143 = XIEITE_DETAIL::FN::t<143, $$...>, \
		typename $$144 = XIEITE_DETAIL::FN::t<144, $$...>, \
		typename $$145 = XIEITE_DETAIL::FN::t<145, $$...>, \
		typename $$146 = XIEITE_DETAIL::FN::t<146, $$...>, \
		typename $$147 = XIEITE_DETAIL::FN::t<147, $$...>, \
		typename $$148 = XIEITE_DETAIL::FN::t<148, $$...>, \
		typename $$149 = XIEITE_DETAIL::FN::t<149, $$...>, \
		typename $$150 = XIEITE_DETAIL::FN::t<150, $$...>, \
		typename $$151 = XIEITE_DETAIL::FN::t<151, $$...>, \
		typename $$152 = XIEITE_DETAIL::FN::t<152, $$...>, \
		typename $$153 = XIEITE_DETAIL::FN::t<153, $$...>, \
		typename $$154 = XIEITE_DETAIL::FN::t<154, $$...>, \
		typename $$155 = XIEITE_DETAIL::FN::t<155, $$...>, \
		typename $$156 = XIEITE_DETAIL::FN::t<156, $$...>, \
		typename $$157 = XIEITE_DETAIL::FN::t<157, $$...>, \
		typename $$158 = XIEITE_DETAIL::FN::t<158, $$...>, \
		typename $$159 = XIEITE_DETAIL::FN::t<159, $$...>, \
		typename $$160 = XIEITE_DETAIL::FN::t<160, $$...>, \
		typename $$161 = XIEITE_DETAIL::FN::t<161, $$...>, \
		typename $$162 = XIEITE_DETAIL::FN::t<162, $$...>, \
		typename $$163 = XIEITE_DETAIL::FN::t<163, $$...>, \
		typename $$164 = XIEITE_DETAIL::FN::t<164, $$...>, \
		typename $$165 = XIEITE_DETAIL::FN::t<165, $$...>, \
		typename $$166 = XIEITE_DETAIL::FN::t<166, $$...>, \
		typename $$167 = XIEITE_DETAIL::FN::t<167, $$...>, \
		typename $$168 = XIEITE_DETAIL::FN::t<168, $$...>, \
		typename $$169 = XIEITE_DETAIL::FN::t<169, $$...>, \
		typename $$170 = XIEITE_DETAIL::FN::t<170, $$...>, \
		typename $$171 = XIEITE_DETAIL::FN::t<171, $$...>, \
		typename $$172 = XIEITE_DETAIL::FN::t<172, $$...>, \
		typename $$173 = XIEITE_DETAIL::FN::t<173, $$...>, \
		typename $$174 = XIEITE_DETAIL::FN::t<174, $$...>, \
		typename $$175 = XIEITE_DETAIL::FN::t<175, $$...>, \
		typename $$176 = XIEITE_DETAIL::FN::t<176, $$...>, \
		typename $$177 = XIEITE_DETAIL::FN::t<177, $$...>, \
		typename $$178 = XIEITE_DETAIL::FN::t<178, $$...>, \
		typename $$179 = XIEITE_DETAIL::FN::t<179, $$...>, \
		typename $$180 = XIEITE_DETAIL::FN::t<180, $$...>, \
		typename $$181 = XIEITE_DETAIL::FN::t<181, $$...>, \
		typename $$182 = XIEITE_DETAIL::FN::t<182, $$...>, \
		typename $$183 = XIEITE_DETAIL::FN::t<183, $$...>, \
		typename $$184 = XIEITE_DETAIL::FN::t<184, $$...>, \
		typename $$185 = XIEITE_DETAIL::FN::t<185, $$...>, \
		typename $$186 = XIEITE_DETAIL::FN::t<186, $$...>, \
		typename $$187 = XIEITE_DETAIL::FN::t<187, $$...>, \
		typename $$188 = XIEITE_DETAIL::FN::t<188, $$...>, \
		typename $$189 = XIEITE_DETAIL::FN::t<189, $$...>, \
		typename $$190 = XIEITE_DETAIL::FN::t<190, $$...>, \
		typename $$191 = XIEITE_DETAIL::FN::t<191, $$...>, \
		typename $$192 = XIEITE_DETAIL::FN::t<192, $$...>, \
		typename $$193 = XIEITE_DETAIL::FN::t<193, $$...>, \
		typename $$194 = XIEITE_DETAIL::FN::t<194, $$...>, \
		typename $$195 = XIEITE_DETAIL::FN::t<195, $$...>, \
		typename $$196 = XIEITE_DETAIL::FN::t<196, $$...>, \
		typename $$197 = XIEITE_DETAIL::FN::t<197, $$...>, \
		typename $$198 = XIEITE_DETAIL::FN::t<198, $$...>, \
		typename $$199 = XIEITE_DETAIL::FN::t<199, $$...>, \
		typename $$200 = XIEITE_DETAIL::FN::t<200, $$...>, \
		typename $$201 = XIEITE_DETAIL::FN::t<201, $$...>, \
		typename $$202 = XIEITE_DETAIL::FN::t<202, $$...>, \
		typename $$203 = XIEITE_DETAIL::FN::t<203, $$...>, \
		typename $$204 = XIEITE_DETAIL::FN::t<204, $$...>, \
		typename $$205 = XIEITE_DETAIL::FN::t<205, $$...>, \
		typename $$206 = XIEITE_DETAIL::FN::t<206, $$...>, \
		typename $$207 = XIEITE_DETAIL::FN::t<207, $$...>, \
		typename $$208 = XIEITE_DETAIL::FN::t<208, $$...>, \
		typename $$209 = XIEITE_DETAIL::FN::t<209, $$...>, \
		typename $$210 = XIEITE_DETAIL::FN::t<210, $$...>, \
		typename $$211 = XIEITE_DETAIL::FN::t<211, $$...>, \
		typename $$212 = XIEITE_DETAIL::FN::t<212, $$...>, \
		typename $$213 = XIEITE_DETAIL::FN::t<213, $$...>, \
		typename $$214 = XIEITE_DETAIL::FN::t<214, $$...>, \
		typename $$215 = XIEITE_DETAIL::FN::t<215, $$...>, \
		typename $$216 = XIEITE_DETAIL::FN::t<216, $$...>, \
		typename $$217 = XIEITE_DETAIL::FN::t<217, $$...>, \
		typename $$218 = XIEITE_DETAIL::FN::t<218, $$...>, \
		typename $$219 = XIEITE_DETAIL::FN::t<219, $$...>, \
		typename $$220 = XIEITE_DETAIL::FN::t<220, $$...>, \
		typename $$221 = XIEITE_DETAIL::FN::t<221, $$...>, \
		typename $$222 = XIEITE_DETAIL::FN::t<222, $$...>, \
		typename $$223 = XIEITE_DETAIL::FN::t<223, $$...>, \
		typename $$224 = XIEITE_DETAIL::FN::t<224, $$...>, \
		typename $$225 = XIEITE_DETAIL::FN::t<225, $$...>, \
		typename $$226 = XIEITE_DETAIL::FN::t<226, $$...>, \
		typename $$227 = XIEITE_DETAIL::FN::t<227, $$...>, \
		typename $$228 = XIEITE_DETAIL::FN::t<228, $$...>, \
		typename $$229 = XIEITE_DETAIL::FN::t<229, $$...>, \
		typename $$230 = XIEITE_DETAIL::FN::t<230, $$...>, \
		typename $$231 = XIEITE_DETAIL::FN::t<231, $$...>, \
		typename $$232 = XIEITE_DETAIL::FN::t<232, $$...>, \
		typename $$233 = XIEITE_DETAIL::FN::t<233, $$...>, \
		typename $$234 = XIEITE_DETAIL::FN::t<234, $$...>, \
		typename $$235 = XIEITE_DETAIL::FN::t<235, $$...>, \
		typename $$236 = XIEITE_DETAIL::FN::t<236, $$...>, \
		typename $$237 = XIEITE_DETAIL::FN::t<237, $$...>, \
		typename $$238 = XIEITE_DETAIL::FN::t<238, $$...>, \
		typename $$239 = XIEITE_DETAIL::FN::t<239, $$...>, \
		typename $$240 = XIEITE_DETAIL::FN::t<240, $$...>, \
		typename $$241 = XIEITE_DETAIL::FN::t<241, $$...>, \
		typename $$242 = XIEITE_DETAIL::FN::t<242, $$...>, \
		typename $$243 = XIEITE_DETAIL::FN::t<243, $$...>, \
		typename $$244 = XIEITE_DETAIL::FN::t<244, $$...>, \
		typename $$245 = XIEITE_DETAIL::FN::t<245, $$...>, \
		typename $$246 = XIEITE_DETAIL::FN::t<246, $$...>, \
		typename $$247 = XIEITE_DETAIL::FN::t<247, $$...>, \
		typename $$248 = XIEITE_DETAIL::FN::t<248, $$...>, \
		typename $$249 = XIEITE_DETAIL::FN::t<249, $$...>, \
		typename $$250 = XIEITE_DETAIL::FN::t<250, $$...>, \
		typename $$251 = XIEITE_DETAIL::FN::t<251, $$...>, \
		typename $$252 = XIEITE_DETAIL::FN::t<252, $$...>, \
		typename $$253 = XIEITE_DETAIL::FN::t<253, $$...>, \
		typename $$254 = XIEITE_DETAIL::FN::t<254, $$...>, \
		typename $$255 = XIEITE_DETAIL::FN::t<255, $$...>, \
		typename $$256 = XIEITE_DETAIL::FN::t<256, $$...> \
	>[[nodiscard]]( \
		XIEITE_IF(this_)([[maybe_unused]] this $$this&& $this XIEITE_COMMA()) \
		auto&&... $ \
	) XIEITE_IF(this_)(, static) noexcept(requires ( \
		XIEITE_IF(this_)($$this&& $this XIEITE_COMMA()) \
		decltype(XIEITE_DETAIL::FN::v<0>(XIEITE_FWD($)...)) $0, \
		decltype(XIEITE_DETAIL::FN::v<1>(XIEITE_FWD($)...)) $1, \
		decltype(XIEITE_DETAIL::FN::v<2>(XIEITE_FWD($)...)) $2, \
		decltype(XIEITE_DETAIL::FN::v<3>(XIEITE_FWD($)...)) $3, \
		decltype(XIEITE_DETAIL::FN::v<4>(XIEITE_FWD($)...)) $4, \
		decltype(XIEITE_DETAIL::FN::v<5>(XIEITE_FWD($)...)) $5, \
		decltype(XIEITE_DETAIL::FN::v<6>(XIEITE_FWD($)...)) $6, \
		decltype(XIEITE_DETAIL::FN::v<7>(XIEITE_FWD($)...)) $7, \
		decltype(XIEITE_DETAIL::FN::v<8>(XIEITE_FWD($)...)) $8, \
		decltype(XIEITE_DETAIL::FN::v<9>(XIEITE_FWD($)...)) $9, \
		decltype(XIEITE_DETAIL::FN::v<10>(XIEITE_FWD($)...)) $10, \
		decltype(XIEITE_DETAIL::FN::v<11>(XIEITE_FWD($)...)) $11, \
		decltype(XIEITE_DETAIL::FN::v<12>(XIEITE_FWD($)...)) $12, \
		decltype(XIEITE_DETAIL::FN::v<13>(XIEITE_FWD($)...)) $13, \
		decltype(XIEITE_DETAIL::FN::v<14>(XIEITE_FWD($)...)) $14, \
		decltype(XIEITE_DETAIL::FN::v<15>(XIEITE_FWD($)...)) $15, \
		decltype(XIEITE_DETAIL::FN::v<16>(XIEITE_FWD($)...)) $16, \
		decltype(XIEITE_DETAIL::FN::v<17>(XIEITE_FWD($)...)) $17, \
		decltype(XIEITE_DETAIL::FN::v<18>(XIEITE_FWD($)...)) $18, \
		decltype(XIEITE_DETAIL::FN::v<19>(XIEITE_FWD($)...)) $19, \
		decltype(XIEITE_DETAIL::FN::v<20>(XIEITE_FWD($)...)) $20, \
		decltype(XIEITE_DETAIL::FN::v<21>(XIEITE_FWD($)...)) $21, \
		decltype(XIEITE_DETAIL::FN::v<22>(XIEITE_FWD($)...)) $22, \
		decltype(XIEITE_DETAIL::FN::v<23>(XIEITE_FWD($)...)) $23, \
		decltype(XIEITE_DETAIL::FN::v<24>(XIEITE_FWD($)...)) $24, \
		decltype(XIEITE_DETAIL::FN::v<25>(XIEITE_FWD($)...)) $25, \
		decltype(XIEITE_DETAIL::FN::v<26>(XIEITE_FWD($)...)) $26, \
		decltype(XIEITE_DETAIL::FN::v<27>(XIEITE_FWD($)...)) $27, \
		decltype(XIEITE_DETAIL::FN::v<28>(XIEITE_FWD($)...)) $28, \
		decltype(XIEITE_DETAIL::FN::v<29>(XIEITE_FWD($)...)) $29, \
		decltype(XIEITE_DETAIL::FN::v<30>(XIEITE_FWD($)...)) $30, \
		decltype(XIEITE_DETAIL::FN::v<31>(XIEITE_FWD($)...)) $31, \
		decltype(XIEITE_DETAIL::FN::v<32>(XIEITE_FWD($)...)) $32, \
		decltype(XIEITE_DETAIL::FN::v<33>(XIEITE_FWD($)...)) $33, \
		decltype(XIEITE_DETAIL::FN::v<34>(XIEITE_FWD($)...)) $34, \
		decltype(XIEITE_DETAIL::FN::v<35>(XIEITE_FWD($)...)) $35, \
		decltype(XIEITE_DETAIL::FN::v<36>(XIEITE_FWD($)...)) $36, \
		decltype(XIEITE_DETAIL::FN::v<37>(XIEITE_FWD($)...)) $37, \
		decltype(XIEITE_DETAIL::FN::v<38>(XIEITE_FWD($)...)) $38, \
		decltype(XIEITE_DETAIL::FN::v<39>(XIEITE_FWD($)...)) $39, \
		decltype(XIEITE_DETAIL::FN::v<40>(XIEITE_FWD($)...)) $40, \
		decltype(XIEITE_DETAIL::FN::v<41>(XIEITE_FWD($)...)) $41, \
		decltype(XIEITE_DETAIL::FN::v<42>(XIEITE_FWD($)...)) $42, \
		decltype(XIEITE_DETAIL::FN::v<43>(XIEITE_FWD($)...)) $43, \
		decltype(XIEITE_DETAIL::FN::v<44>(XIEITE_FWD($)...)) $44, \
		decltype(XIEITE_DETAIL::FN::v<45>(XIEITE_FWD($)...)) $45, \
		decltype(XIEITE_DETAIL::FN::v<46>(XIEITE_FWD($)...)) $46, \
		decltype(XIEITE_DETAIL::FN::v<47>(XIEITE_FWD($)...)) $47, \
		decltype(XIEITE_DETAIL::FN::v<48>(XIEITE_FWD($)...)) $48, \
		decltype(XIEITE_DETAIL::FN::v<49>(XIEITE_FWD($)...)) $49, \
		decltype(XIEITE_DETAIL::FN::v<50>(XIEITE_FWD($)...)) $50, \
		decltype(XIEITE_DETAIL::FN::v<51>(XIEITE_FWD($)...)) $51, \
		decltype(XIEITE_DETAIL::FN::v<52>(XIEITE_FWD($)...)) $52, \
		decltype(XIEITE_DETAIL::FN::v<53>(XIEITE_FWD($)...)) $53, \
		decltype(XIEITE_DETAIL::FN::v<54>(XIEITE_FWD($)...)) $54, \
		decltype(XIEITE_DETAIL::FN::v<55>(XIEITE_FWD($)...)) $55, \
		decltype(XIEITE_DETAIL::FN::v<56>(XIEITE_FWD($)...)) $56, \
		decltype(XIEITE_DETAIL::FN::v<57>(XIEITE_FWD($)...)) $57, \
		decltype(XIEITE_DETAIL::FN::v<58>(XIEITE_FWD($)...)) $58, \
		decltype(XIEITE_DETAIL::FN::v<59>(XIEITE_FWD($)...)) $59, \
		decltype(XIEITE_DETAIL::FN::v<60>(XIEITE_FWD($)...)) $60, \
		decltype(XIEITE_DETAIL::FN::v<61>(XIEITE_FWD($)...)) $61, \
		decltype(XIEITE_DETAIL::FN::v<62>(XIEITE_FWD($)...)) $62, \
		decltype(XIEITE_DETAIL::FN::v<63>(XIEITE_FWD($)...)) $63, \
		decltype(XIEITE_DETAIL::FN::v<64>(XIEITE_FWD($)...)) $64, \
		decltype(XIEITE_DETAIL::FN::v<65>(XIEITE_FWD($)...)) $65, \
		decltype(XIEITE_DETAIL::FN::v<66>(XIEITE_FWD($)...)) $66, \
		decltype(XIEITE_DETAIL::FN::v<67>(XIEITE_FWD($)...)) $67, \
		decltype(XIEITE_DETAIL::FN::v<68>(XIEITE_FWD($)...)) $68, \
		decltype(XIEITE_DETAIL::FN::v<69>(XIEITE_FWD($)...)) $69, \
		decltype(XIEITE_DETAIL::FN::v<70>(XIEITE_FWD($)...)) $70, \
		decltype(XIEITE_DETAIL::FN::v<71>(XIEITE_FWD($)...)) $71, \
		decltype(XIEITE_DETAIL::FN::v<72>(XIEITE_FWD($)...)) $72, \
		decltype(XIEITE_DETAIL::FN::v<73>(XIEITE_FWD($)...)) $73, \
		decltype(XIEITE_DETAIL::FN::v<74>(XIEITE_FWD($)...)) $74, \
		decltype(XIEITE_DETAIL::FN::v<75>(XIEITE_FWD($)...)) $75, \
		decltype(XIEITE_DETAIL::FN::v<76>(XIEITE_FWD($)...)) $76, \
		decltype(XIEITE_DETAIL::FN::v<77>(XIEITE_FWD($)...)) $77, \
		decltype(XIEITE_DETAIL::FN::v<78>(XIEITE_FWD($)...)) $78, \
		decltype(XIEITE_DETAIL::FN::v<79>(XIEITE_FWD($)...)) $79, \
		decltype(XIEITE_DETAIL::FN::v<80>(XIEITE_FWD($)...)) $80, \
		decltype(XIEITE_DETAIL::FN::v<81>(XIEITE_FWD($)...)) $81, \
		decltype(XIEITE_DETAIL::FN::v<82>(XIEITE_FWD($)...)) $82, \
		decltype(XIEITE_DETAIL::FN::v<83>(XIEITE_FWD($)...)) $83, \
		decltype(XIEITE_DETAIL::FN::v<84>(XIEITE_FWD($)...)) $84, \
		decltype(XIEITE_DETAIL::FN::v<85>(XIEITE_FWD($)...)) $85, \
		decltype(XIEITE_DETAIL::FN::v<86>(XIEITE_FWD($)...)) $86, \
		decltype(XIEITE_DETAIL::FN::v<87>(XIEITE_FWD($)...)) $87, \
		decltype(XIEITE_DETAIL::FN::v<88>(XIEITE_FWD($)...)) $88, \
		decltype(XIEITE_DETAIL::FN::v<89>(XIEITE_FWD($)...)) $89, \
		decltype(XIEITE_DETAIL::FN::v<90>(XIEITE_FWD($)...)) $90, \
		decltype(XIEITE_DETAIL::FN::v<91>(XIEITE_FWD($)...)) $91, \
		decltype(XIEITE_DETAIL::FN::v<92>(XIEITE_FWD($)...)) $92, \
		decltype(XIEITE_DETAIL::FN::v<93>(XIEITE_FWD($)...)) $93, \
		decltype(XIEITE_DETAIL::FN::v<94>(XIEITE_FWD($)...)) $94, \
		decltype(XIEITE_DETAIL::FN::v<95>(XIEITE_FWD($)...)) $95, \
		decltype(XIEITE_DETAIL::FN::v<96>(XIEITE_FWD($)...)) $96, \
		decltype(XIEITE_DETAIL::FN::v<97>(XIEITE_FWD($)...)) $97, \
		decltype(XIEITE_DETAIL::FN::v<98>(XIEITE_FWD($)...)) $98, \
		decltype(XIEITE_DETAIL::FN::v<99>(XIEITE_FWD($)...)) $99, \
		decltype(XIEITE_DETAIL::FN::v<100>(XIEITE_FWD($)...)) $100, \
		decltype(XIEITE_DETAIL::FN::v<101>(XIEITE_FWD($)...)) $101, \
		decltype(XIEITE_DETAIL::FN::v<102>(XIEITE_FWD($)...)) $102, \
		decltype(XIEITE_DETAIL::FN::v<103>(XIEITE_FWD($)...)) $103, \
		decltype(XIEITE_DETAIL::FN::v<104>(XIEITE_FWD($)...)) $104, \
		decltype(XIEITE_DETAIL::FN::v<105>(XIEITE_FWD($)...)) $105, \
		decltype(XIEITE_DETAIL::FN::v<106>(XIEITE_FWD($)...)) $106, \
		decltype(XIEITE_DETAIL::FN::v<107>(XIEITE_FWD($)...)) $107, \
		decltype(XIEITE_DETAIL::FN::v<108>(XIEITE_FWD($)...)) $108, \
		decltype(XIEITE_DETAIL::FN::v<109>(XIEITE_FWD($)...)) $109, \
		decltype(XIEITE_DETAIL::FN::v<110>(XIEITE_FWD($)...)) $110, \
		decltype(XIEITE_DETAIL::FN::v<111>(XIEITE_FWD($)...)) $111, \
		decltype(XIEITE_DETAIL::FN::v<112>(XIEITE_FWD($)...)) $112, \
		decltype(XIEITE_DETAIL::FN::v<113>(XIEITE_FWD($)...)) $113, \
		decltype(XIEITE_DETAIL::FN::v<114>(XIEITE_FWD($)...)) $114, \
		decltype(XIEITE_DETAIL::FN::v<115>(XIEITE_FWD($)...)) $115, \
		decltype(XIEITE_DETAIL::FN::v<116>(XIEITE_FWD($)...)) $116, \
		decltype(XIEITE_DETAIL::FN::v<117>(XIEITE_FWD($)...)) $117, \
		decltype(XIEITE_DETAIL::FN::v<118>(XIEITE_FWD($)...)) $118, \
		decltype(XIEITE_DETAIL::FN::v<119>(XIEITE_FWD($)...)) $119, \
		decltype(XIEITE_DETAIL::FN::v<120>(XIEITE_FWD($)...)) $120, \
		decltype(XIEITE_DETAIL::FN::v<121>(XIEITE_FWD($)...)) $121, \
		decltype(XIEITE_DETAIL::FN::v<122>(XIEITE_FWD($)...)) $122, \
		decltype(XIEITE_DETAIL::FN::v<123>(XIEITE_FWD($)...)) $123, \
		decltype(XIEITE_DETAIL::FN::v<124>(XIEITE_FWD($)...)) $124, \
		decltype(XIEITE_DETAIL::FN::v<125>(XIEITE_FWD($)...)) $125, \
		decltype(XIEITE_DETAIL::FN::v<126>(XIEITE_FWD($)...)) $126, \
		decltype(XIEITE_DETAIL::FN::v<127>(XIEITE_FWD($)...)) $127, \
		decltype(XIEITE_DETAIL::FN::v<128>(XIEITE_FWD($)...)) $128, \
		decltype(XIEITE_DETAIL::FN::v<129>(XIEITE_FWD($)...)) $129, \
		decltype(XIEITE_DETAIL::FN::v<130>(XIEITE_FWD($)...)) $130, \
		decltype(XIEITE_DETAIL::FN::v<131>(XIEITE_FWD($)...)) $131, \
		decltype(XIEITE_DETAIL::FN::v<132>(XIEITE_FWD($)...)) $132, \
		decltype(XIEITE_DETAIL::FN::v<133>(XIEITE_FWD($)...)) $133, \
		decltype(XIEITE_DETAIL::FN::v<134>(XIEITE_FWD($)...)) $134, \
		decltype(XIEITE_DETAIL::FN::v<135>(XIEITE_FWD($)...)) $135, \
		decltype(XIEITE_DETAIL::FN::v<136>(XIEITE_FWD($)...)) $136, \
		decltype(XIEITE_DETAIL::FN::v<137>(XIEITE_FWD($)...)) $137, \
		decltype(XIEITE_DETAIL::FN::v<138>(XIEITE_FWD($)...)) $138, \
		decltype(XIEITE_DETAIL::FN::v<139>(XIEITE_FWD($)...)) $139, \
		decltype(XIEITE_DETAIL::FN::v<140>(XIEITE_FWD($)...)) $140, \
		decltype(XIEITE_DETAIL::FN::v<141>(XIEITE_FWD($)...)) $141, \
		decltype(XIEITE_DETAIL::FN::v<142>(XIEITE_FWD($)...)) $142, \
		decltype(XIEITE_DETAIL::FN::v<143>(XIEITE_FWD($)...)) $143, \
		decltype(XIEITE_DETAIL::FN::v<144>(XIEITE_FWD($)...)) $144, \
		decltype(XIEITE_DETAIL::FN::v<145>(XIEITE_FWD($)...)) $145, \
		decltype(XIEITE_DETAIL::FN::v<146>(XIEITE_FWD($)...)) $146, \
		decltype(XIEITE_DETAIL::FN::v<147>(XIEITE_FWD($)...)) $147, \
		decltype(XIEITE_DETAIL::FN::v<148>(XIEITE_FWD($)...)) $148, \
		decltype(XIEITE_DETAIL::FN::v<149>(XIEITE_FWD($)...)) $149, \
		decltype(XIEITE_DETAIL::FN::v<150>(XIEITE_FWD($)...)) $150, \
		decltype(XIEITE_DETAIL::FN::v<151>(XIEITE_FWD($)...)) $151, \
		decltype(XIEITE_DETAIL::FN::v<152>(XIEITE_FWD($)...)) $152, \
		decltype(XIEITE_DETAIL::FN::v<153>(XIEITE_FWD($)...)) $153, \
		decltype(XIEITE_DETAIL::FN::v<154>(XIEITE_FWD($)...)) $154, \
		decltype(XIEITE_DETAIL::FN::v<155>(XIEITE_FWD($)...)) $155, \
		decltype(XIEITE_DETAIL::FN::v<156>(XIEITE_FWD($)...)) $156, \
		decltype(XIEITE_DETAIL::FN::v<157>(XIEITE_FWD($)...)) $157, \
		decltype(XIEITE_DETAIL::FN::v<158>(XIEITE_FWD($)...)) $158, \
		decltype(XIEITE_DETAIL::FN::v<159>(XIEITE_FWD($)...)) $159, \
		decltype(XIEITE_DETAIL::FN::v<160>(XIEITE_FWD($)...)) $160, \
		decltype(XIEITE_DETAIL::FN::v<161>(XIEITE_FWD($)...)) $161, \
		decltype(XIEITE_DETAIL::FN::v<162>(XIEITE_FWD($)...)) $162, \
		decltype(XIEITE_DETAIL::FN::v<163>(XIEITE_FWD($)...)) $163, \
		decltype(XIEITE_DETAIL::FN::v<164>(XIEITE_FWD($)...)) $164, \
		decltype(XIEITE_DETAIL::FN::v<165>(XIEITE_FWD($)...)) $165, \
		decltype(XIEITE_DETAIL::FN::v<166>(XIEITE_FWD($)...)) $166, \
		decltype(XIEITE_DETAIL::FN::v<167>(XIEITE_FWD($)...)) $167, \
		decltype(XIEITE_DETAIL::FN::v<168>(XIEITE_FWD($)...)) $168, \
		decltype(XIEITE_DETAIL::FN::v<169>(XIEITE_FWD($)...)) $169, \
		decltype(XIEITE_DETAIL::FN::v<170>(XIEITE_FWD($)...)) $170, \
		decltype(XIEITE_DETAIL::FN::v<171>(XIEITE_FWD($)...)) $171, \
		decltype(XIEITE_DETAIL::FN::v<172>(XIEITE_FWD($)...)) $172, \
		decltype(XIEITE_DETAIL::FN::v<173>(XIEITE_FWD($)...)) $173, \
		decltype(XIEITE_DETAIL::FN::v<174>(XIEITE_FWD($)...)) $174, \
		decltype(XIEITE_DETAIL::FN::v<175>(XIEITE_FWD($)...)) $175, \
		decltype(XIEITE_DETAIL::FN::v<176>(XIEITE_FWD($)...)) $176, \
		decltype(XIEITE_DETAIL::FN::v<177>(XIEITE_FWD($)...)) $177, \
		decltype(XIEITE_DETAIL::FN::v<178>(XIEITE_FWD($)...)) $178, \
		decltype(XIEITE_DETAIL::FN::v<179>(XIEITE_FWD($)...)) $179, \
		decltype(XIEITE_DETAIL::FN::v<180>(XIEITE_FWD($)...)) $180, \
		decltype(XIEITE_DETAIL::FN::v<181>(XIEITE_FWD($)...)) $181, \
		decltype(XIEITE_DETAIL::FN::v<182>(XIEITE_FWD($)...)) $182, \
		decltype(XIEITE_DETAIL::FN::v<183>(XIEITE_FWD($)...)) $183, \
		decltype(XIEITE_DETAIL::FN::v<184>(XIEITE_FWD($)...)) $184, \
		decltype(XIEITE_DETAIL::FN::v<185>(XIEITE_FWD($)...)) $185, \
		decltype(XIEITE_DETAIL::FN::v<186>(XIEITE_FWD($)...)) $186, \
		decltype(XIEITE_DETAIL::FN::v<187>(XIEITE_FWD($)...)) $187, \
		decltype(XIEITE_DETAIL::FN::v<188>(XIEITE_FWD($)...)) $188, \
		decltype(XIEITE_DETAIL::FN::v<189>(XIEITE_FWD($)...)) $189, \
		decltype(XIEITE_DETAIL::FN::v<190>(XIEITE_FWD($)...)) $190, \
		decltype(XIEITE_DETAIL::FN::v<191>(XIEITE_FWD($)...)) $191, \
		decltype(XIEITE_DETAIL::FN::v<192>(XIEITE_FWD($)...)) $192, \
		decltype(XIEITE_DETAIL::FN::v<193>(XIEITE_FWD($)...)) $193, \
		decltype(XIEITE_DETAIL::FN::v<194>(XIEITE_FWD($)...)) $194, \
		decltype(XIEITE_DETAIL::FN::v<195>(XIEITE_FWD($)...)) $195, \
		decltype(XIEITE_DETAIL::FN::v<196>(XIEITE_FWD($)...)) $196, \
		decltype(XIEITE_DETAIL::FN::v<197>(XIEITE_FWD($)...)) $197, \
		decltype(XIEITE_DETAIL::FN::v<198>(XIEITE_FWD($)...)) $198, \
		decltype(XIEITE_DETAIL::FN::v<199>(XIEITE_FWD($)...)) $199, \
		decltype(XIEITE_DETAIL::FN::v<200>(XIEITE_FWD($)...)) $200, \
		decltype(XIEITE_DETAIL::FN::v<201>(XIEITE_FWD($)...)) $201, \
		decltype(XIEITE_DETAIL::FN::v<202>(XIEITE_FWD($)...)) $202, \
		decltype(XIEITE_DETAIL::FN::v<203>(XIEITE_FWD($)...)) $203, \
		decltype(XIEITE_DETAIL::FN::v<204>(XIEITE_FWD($)...)) $204, \
		decltype(XIEITE_DETAIL::FN::v<205>(XIEITE_FWD($)...)) $205, \
		decltype(XIEITE_DETAIL::FN::v<206>(XIEITE_FWD($)...)) $206, \
		decltype(XIEITE_DETAIL::FN::v<207>(XIEITE_FWD($)...)) $207, \
		decltype(XIEITE_DETAIL::FN::v<208>(XIEITE_FWD($)...)) $208, \
		decltype(XIEITE_DETAIL::FN::v<209>(XIEITE_FWD($)...)) $209, \
		decltype(XIEITE_DETAIL::FN::v<210>(XIEITE_FWD($)...)) $210, \
		decltype(XIEITE_DETAIL::FN::v<211>(XIEITE_FWD($)...)) $211, \
		decltype(XIEITE_DETAIL::FN::v<212>(XIEITE_FWD($)...)) $212, \
		decltype(XIEITE_DETAIL::FN::v<213>(XIEITE_FWD($)...)) $213, \
		decltype(XIEITE_DETAIL::FN::v<214>(XIEITE_FWD($)...)) $214, \
		decltype(XIEITE_DETAIL::FN::v<215>(XIEITE_FWD($)...)) $215, \
		decltype(XIEITE_DETAIL::FN::v<216>(XIEITE_FWD($)...)) $216, \
		decltype(XIEITE_DETAIL::FN::v<217>(XIEITE_FWD($)...)) $217, \
		decltype(XIEITE_DETAIL::FN::v<218>(XIEITE_FWD($)...)) $218, \
		decltype(XIEITE_DETAIL::FN::v<219>(XIEITE_FWD($)...)) $219, \
		decltype(XIEITE_DETAIL::FN::v<220>(XIEITE_FWD($)...)) $220, \
		decltype(XIEITE_DETAIL::FN::v<221>(XIEITE_FWD($)...)) $221, \
		decltype(XIEITE_DETAIL::FN::v<222>(XIEITE_FWD($)...)) $222, \
		decltype(XIEITE_DETAIL::FN::v<223>(XIEITE_FWD($)...)) $223, \
		decltype(XIEITE_DETAIL::FN::v<224>(XIEITE_FWD($)...)) $224, \
		decltype(XIEITE_DETAIL::FN::v<225>(XIEITE_FWD($)...)) $225, \
		decltype(XIEITE_DETAIL::FN::v<226>(XIEITE_FWD($)...)) $226, \
		decltype(XIEITE_DETAIL::FN::v<227>(XIEITE_FWD($)...)) $227, \
		decltype(XIEITE_DETAIL::FN::v<228>(XIEITE_FWD($)...)) $228, \
		decltype(XIEITE_DETAIL::FN::v<229>(XIEITE_FWD($)...)) $229, \
		decltype(XIEITE_DETAIL::FN::v<230>(XIEITE_FWD($)...)) $230, \
		decltype(XIEITE_DETAIL::FN::v<231>(XIEITE_FWD($)...)) $231, \
		decltype(XIEITE_DETAIL::FN::v<232>(XIEITE_FWD($)...)) $232, \
		decltype(XIEITE_DETAIL::FN::v<233>(XIEITE_FWD($)...)) $233, \
		decltype(XIEITE_DETAIL::FN::v<234>(XIEITE_FWD($)...)) $234, \
		decltype(XIEITE_DETAIL::FN::v<235>(XIEITE_FWD($)...)) $235, \
		decltype(XIEITE_DETAIL::FN::v<236>(XIEITE_FWD($)...)) $236, \
		decltype(XIEITE_DETAIL::FN::v<237>(XIEITE_FWD($)...)) $237, \
		decltype(XIEITE_DETAIL::FN::v<238>(XIEITE_FWD($)...)) $238, \
		decltype(XIEITE_DETAIL::FN::v<239>(XIEITE_FWD($)...)) $239, \
		decltype(XIEITE_DETAIL::FN::v<240>(XIEITE_FWD($)...)) $240, \
		decltype(XIEITE_DETAIL::FN::v<241>(XIEITE_FWD($)...)) $241, \
		decltype(XIEITE_DETAIL::FN::v<242>(XIEITE_FWD($)...)) $242, \
		decltype(XIEITE_DETAIL::FN::v<243>(XIEITE_FWD($)...)) $243, \
		decltype(XIEITE_DETAIL::FN::v<244>(XIEITE_FWD($)...)) $244, \
		decltype(XIEITE_DETAIL::FN::v<245>(XIEITE_FWD($)...)) $245, \
		decltype(XIEITE_DETAIL::FN::v<246>(XIEITE_FWD($)...)) $246, \
		decltype(XIEITE_DETAIL::FN::v<247>(XIEITE_FWD($)...)) $247, \
		decltype(XIEITE_DETAIL::FN::v<248>(XIEITE_FWD($)...)) $248, \
		decltype(XIEITE_DETAIL::FN::v<249>(XIEITE_FWD($)...)) $249, \
		decltype(XIEITE_DETAIL::FN::v<250>(XIEITE_FWD($)...)) $250, \
		decltype(XIEITE_DETAIL::FN::v<251>(XIEITE_FWD($)...)) $251, \
		decltype(XIEITE_DETAIL::FN::v<252>(XIEITE_FWD($)...)) $252, \
		decltype(XIEITE_DETAIL::FN::v<253>(XIEITE_FWD($)...)) $253, \
		decltype(XIEITE_DETAIL::FN::v<254>(XIEITE_FWD($)...)) $254, \
		decltype(XIEITE_DETAIL::FN::v<255>(XIEITE_FWD($)...)) $255, \
		decltype(XIEITE_DETAIL::FN::v<256>(XIEITE_FWD($)...)) $256 \
	) { requires(noexcept((__VA_ARGS__))); }) \
	-> decltype(auto) \
	requires(requires ( \
		XIEITE_IF(this_)($$this&& $this XIEITE_COMMA()) \
		decltype(XIEITE_DETAIL::FN::v<0>(XIEITE_FWD($)...)) $0, \
		decltype(XIEITE_DETAIL::FN::v<1>(XIEITE_FWD($)...)) $1, \
		decltype(XIEITE_DETAIL::FN::v<2>(XIEITE_FWD($)...)) $2, \
		decltype(XIEITE_DETAIL::FN::v<3>(XIEITE_FWD($)...)) $3, \
		decltype(XIEITE_DETAIL::FN::v<4>(XIEITE_FWD($)...)) $4, \
		decltype(XIEITE_DETAIL::FN::v<5>(XIEITE_FWD($)...)) $5, \
		decltype(XIEITE_DETAIL::FN::v<6>(XIEITE_FWD($)...)) $6, \
		decltype(XIEITE_DETAIL::FN::v<7>(XIEITE_FWD($)...)) $7, \
		decltype(XIEITE_DETAIL::FN::v<8>(XIEITE_FWD($)...)) $8, \
		decltype(XIEITE_DETAIL::FN::v<9>(XIEITE_FWD($)...)) $9, \
		decltype(XIEITE_DETAIL::FN::v<10>(XIEITE_FWD($)...)) $10, \
		decltype(XIEITE_DETAIL::FN::v<11>(XIEITE_FWD($)...)) $11, \
		decltype(XIEITE_DETAIL::FN::v<12>(XIEITE_FWD($)...)) $12, \
		decltype(XIEITE_DETAIL::FN::v<13>(XIEITE_FWD($)...)) $13, \
		decltype(XIEITE_DETAIL::FN::v<14>(XIEITE_FWD($)...)) $14, \
		decltype(XIEITE_DETAIL::FN::v<15>(XIEITE_FWD($)...)) $15, \
		decltype(XIEITE_DETAIL::FN::v<16>(XIEITE_FWD($)...)) $16, \
		decltype(XIEITE_DETAIL::FN::v<17>(XIEITE_FWD($)...)) $17, \
		decltype(XIEITE_DETAIL::FN::v<18>(XIEITE_FWD($)...)) $18, \
		decltype(XIEITE_DETAIL::FN::v<19>(XIEITE_FWD($)...)) $19, \
		decltype(XIEITE_DETAIL::FN::v<20>(XIEITE_FWD($)...)) $20, \
		decltype(XIEITE_DETAIL::FN::v<21>(XIEITE_FWD($)...)) $21, \
		decltype(XIEITE_DETAIL::FN::v<22>(XIEITE_FWD($)...)) $22, \
		decltype(XIEITE_DETAIL::FN::v<23>(XIEITE_FWD($)...)) $23, \
		decltype(XIEITE_DETAIL::FN::v<24>(XIEITE_FWD($)...)) $24, \
		decltype(XIEITE_DETAIL::FN::v<25>(XIEITE_FWD($)...)) $25, \
		decltype(XIEITE_DETAIL::FN::v<26>(XIEITE_FWD($)...)) $26, \
		decltype(XIEITE_DETAIL::FN::v<27>(XIEITE_FWD($)...)) $27, \
		decltype(XIEITE_DETAIL::FN::v<28>(XIEITE_FWD($)...)) $28, \
		decltype(XIEITE_DETAIL::FN::v<29>(XIEITE_FWD($)...)) $29, \
		decltype(XIEITE_DETAIL::FN::v<30>(XIEITE_FWD($)...)) $30, \
		decltype(XIEITE_DETAIL::FN::v<31>(XIEITE_FWD($)...)) $31, \
		decltype(XIEITE_DETAIL::FN::v<32>(XIEITE_FWD($)...)) $32, \
		decltype(XIEITE_DETAIL::FN::v<33>(XIEITE_FWD($)...)) $33, \
		decltype(XIEITE_DETAIL::FN::v<34>(XIEITE_FWD($)...)) $34, \
		decltype(XIEITE_DETAIL::FN::v<35>(XIEITE_FWD($)...)) $35, \
		decltype(XIEITE_DETAIL::FN::v<36>(XIEITE_FWD($)...)) $36, \
		decltype(XIEITE_DETAIL::FN::v<37>(XIEITE_FWD($)...)) $37, \
		decltype(XIEITE_DETAIL::FN::v<38>(XIEITE_FWD($)...)) $38, \
		decltype(XIEITE_DETAIL::FN::v<39>(XIEITE_FWD($)...)) $39, \
		decltype(XIEITE_DETAIL::FN::v<40>(XIEITE_FWD($)...)) $40, \
		decltype(XIEITE_DETAIL::FN::v<41>(XIEITE_FWD($)...)) $41, \
		decltype(XIEITE_DETAIL::FN::v<42>(XIEITE_FWD($)...)) $42, \
		decltype(XIEITE_DETAIL::FN::v<43>(XIEITE_FWD($)...)) $43, \
		decltype(XIEITE_DETAIL::FN::v<44>(XIEITE_FWD($)...)) $44, \
		decltype(XIEITE_DETAIL::FN::v<45>(XIEITE_FWD($)...)) $45, \
		decltype(XIEITE_DETAIL::FN::v<46>(XIEITE_FWD($)...)) $46, \
		decltype(XIEITE_DETAIL::FN::v<47>(XIEITE_FWD($)...)) $47, \
		decltype(XIEITE_DETAIL::FN::v<48>(XIEITE_FWD($)...)) $48, \
		decltype(XIEITE_DETAIL::FN::v<49>(XIEITE_FWD($)...)) $49, \
		decltype(XIEITE_DETAIL::FN::v<50>(XIEITE_FWD($)...)) $50, \
		decltype(XIEITE_DETAIL::FN::v<51>(XIEITE_FWD($)...)) $51, \
		decltype(XIEITE_DETAIL::FN::v<52>(XIEITE_FWD($)...)) $52, \
		decltype(XIEITE_DETAIL::FN::v<53>(XIEITE_FWD($)...)) $53, \
		decltype(XIEITE_DETAIL::FN::v<54>(XIEITE_FWD($)...)) $54, \
		decltype(XIEITE_DETAIL::FN::v<55>(XIEITE_FWD($)...)) $55, \
		decltype(XIEITE_DETAIL::FN::v<56>(XIEITE_FWD($)...)) $56, \
		decltype(XIEITE_DETAIL::FN::v<57>(XIEITE_FWD($)...)) $57, \
		decltype(XIEITE_DETAIL::FN::v<58>(XIEITE_FWD($)...)) $58, \
		decltype(XIEITE_DETAIL::FN::v<59>(XIEITE_FWD($)...)) $59, \
		decltype(XIEITE_DETAIL::FN::v<60>(XIEITE_FWD($)...)) $60, \
		decltype(XIEITE_DETAIL::FN::v<61>(XIEITE_FWD($)...)) $61, \
		decltype(XIEITE_DETAIL::FN::v<62>(XIEITE_FWD($)...)) $62, \
		decltype(XIEITE_DETAIL::FN::v<63>(XIEITE_FWD($)...)) $63, \
		decltype(XIEITE_DETAIL::FN::v<64>(XIEITE_FWD($)...)) $64, \
		decltype(XIEITE_DETAIL::FN::v<65>(XIEITE_FWD($)...)) $65, \
		decltype(XIEITE_DETAIL::FN::v<66>(XIEITE_FWD($)...)) $66, \
		decltype(XIEITE_DETAIL::FN::v<67>(XIEITE_FWD($)...)) $67, \
		decltype(XIEITE_DETAIL::FN::v<68>(XIEITE_FWD($)...)) $68, \
		decltype(XIEITE_DETAIL::FN::v<69>(XIEITE_FWD($)...)) $69, \
		decltype(XIEITE_DETAIL::FN::v<70>(XIEITE_FWD($)...)) $70, \
		decltype(XIEITE_DETAIL::FN::v<71>(XIEITE_FWD($)...)) $71, \
		decltype(XIEITE_DETAIL::FN::v<72>(XIEITE_FWD($)...)) $72, \
		decltype(XIEITE_DETAIL::FN::v<73>(XIEITE_FWD($)...)) $73, \
		decltype(XIEITE_DETAIL::FN::v<74>(XIEITE_FWD($)...)) $74, \
		decltype(XIEITE_DETAIL::FN::v<75>(XIEITE_FWD($)...)) $75, \
		decltype(XIEITE_DETAIL::FN::v<76>(XIEITE_FWD($)...)) $76, \
		decltype(XIEITE_DETAIL::FN::v<77>(XIEITE_FWD($)...)) $77, \
		decltype(XIEITE_DETAIL::FN::v<78>(XIEITE_FWD($)...)) $78, \
		decltype(XIEITE_DETAIL::FN::v<79>(XIEITE_FWD($)...)) $79, \
		decltype(XIEITE_DETAIL::FN::v<80>(XIEITE_FWD($)...)) $80, \
		decltype(XIEITE_DETAIL::FN::v<81>(XIEITE_FWD($)...)) $81, \
		decltype(XIEITE_DETAIL::FN::v<82>(XIEITE_FWD($)...)) $82, \
		decltype(XIEITE_DETAIL::FN::v<83>(XIEITE_FWD($)...)) $83, \
		decltype(XIEITE_DETAIL::FN::v<84>(XIEITE_FWD($)...)) $84, \
		decltype(XIEITE_DETAIL::FN::v<85>(XIEITE_FWD($)...)) $85, \
		decltype(XIEITE_DETAIL::FN::v<86>(XIEITE_FWD($)...)) $86, \
		decltype(XIEITE_DETAIL::FN::v<87>(XIEITE_FWD($)...)) $87, \
		decltype(XIEITE_DETAIL::FN::v<88>(XIEITE_FWD($)...)) $88, \
		decltype(XIEITE_DETAIL::FN::v<89>(XIEITE_FWD($)...)) $89, \
		decltype(XIEITE_DETAIL::FN::v<90>(XIEITE_FWD($)...)) $90, \
		decltype(XIEITE_DETAIL::FN::v<91>(XIEITE_FWD($)...)) $91, \
		decltype(XIEITE_DETAIL::FN::v<92>(XIEITE_FWD($)...)) $92, \
		decltype(XIEITE_DETAIL::FN::v<93>(XIEITE_FWD($)...)) $93, \
		decltype(XIEITE_DETAIL::FN::v<94>(XIEITE_FWD($)...)) $94, \
		decltype(XIEITE_DETAIL::FN::v<95>(XIEITE_FWD($)...)) $95, \
		decltype(XIEITE_DETAIL::FN::v<96>(XIEITE_FWD($)...)) $96, \
		decltype(XIEITE_DETAIL::FN::v<97>(XIEITE_FWD($)...)) $97, \
		decltype(XIEITE_DETAIL::FN::v<98>(XIEITE_FWD($)...)) $98, \
		decltype(XIEITE_DETAIL::FN::v<99>(XIEITE_FWD($)...)) $99, \
		decltype(XIEITE_DETAIL::FN::v<100>(XIEITE_FWD($)...)) $100, \
		decltype(XIEITE_DETAIL::FN::v<101>(XIEITE_FWD($)...)) $101, \
		decltype(XIEITE_DETAIL::FN::v<102>(XIEITE_FWD($)...)) $102, \
		decltype(XIEITE_DETAIL::FN::v<103>(XIEITE_FWD($)...)) $103, \
		decltype(XIEITE_DETAIL::FN::v<104>(XIEITE_FWD($)...)) $104, \
		decltype(XIEITE_DETAIL::FN::v<105>(XIEITE_FWD($)...)) $105, \
		decltype(XIEITE_DETAIL::FN::v<106>(XIEITE_FWD($)...)) $106, \
		decltype(XIEITE_DETAIL::FN::v<107>(XIEITE_FWD($)...)) $107, \
		decltype(XIEITE_DETAIL::FN::v<108>(XIEITE_FWD($)...)) $108, \
		decltype(XIEITE_DETAIL::FN::v<109>(XIEITE_FWD($)...)) $109, \
		decltype(XIEITE_DETAIL::FN::v<110>(XIEITE_FWD($)...)) $110, \
		decltype(XIEITE_DETAIL::FN::v<111>(XIEITE_FWD($)...)) $111, \
		decltype(XIEITE_DETAIL::FN::v<112>(XIEITE_FWD($)...)) $112, \
		decltype(XIEITE_DETAIL::FN::v<113>(XIEITE_FWD($)...)) $113, \
		decltype(XIEITE_DETAIL::FN::v<114>(XIEITE_FWD($)...)) $114, \
		decltype(XIEITE_DETAIL::FN::v<115>(XIEITE_FWD($)...)) $115, \
		decltype(XIEITE_DETAIL::FN::v<116>(XIEITE_FWD($)...)) $116, \
		decltype(XIEITE_DETAIL::FN::v<117>(XIEITE_FWD($)...)) $117, \
		decltype(XIEITE_DETAIL::FN::v<118>(XIEITE_FWD($)...)) $118, \
		decltype(XIEITE_DETAIL::FN::v<119>(XIEITE_FWD($)...)) $119, \
		decltype(XIEITE_DETAIL::FN::v<120>(XIEITE_FWD($)...)) $120, \
		decltype(XIEITE_DETAIL::FN::v<121>(XIEITE_FWD($)...)) $121, \
		decltype(XIEITE_DETAIL::FN::v<122>(XIEITE_FWD($)...)) $122, \
		decltype(XIEITE_DETAIL::FN::v<123>(XIEITE_FWD($)...)) $123, \
		decltype(XIEITE_DETAIL::FN::v<124>(XIEITE_FWD($)...)) $124, \
		decltype(XIEITE_DETAIL::FN::v<125>(XIEITE_FWD($)...)) $125, \
		decltype(XIEITE_DETAIL::FN::v<126>(XIEITE_FWD($)...)) $126, \
		decltype(XIEITE_DETAIL::FN::v<127>(XIEITE_FWD($)...)) $127, \
		decltype(XIEITE_DETAIL::FN::v<128>(XIEITE_FWD($)...)) $128, \
		decltype(XIEITE_DETAIL::FN::v<129>(XIEITE_FWD($)...)) $129, \
		decltype(XIEITE_DETAIL::FN::v<130>(XIEITE_FWD($)...)) $130, \
		decltype(XIEITE_DETAIL::FN::v<131>(XIEITE_FWD($)...)) $131, \
		decltype(XIEITE_DETAIL::FN::v<132>(XIEITE_FWD($)...)) $132, \
		decltype(XIEITE_DETAIL::FN::v<133>(XIEITE_FWD($)...)) $133, \
		decltype(XIEITE_DETAIL::FN::v<134>(XIEITE_FWD($)...)) $134, \
		decltype(XIEITE_DETAIL::FN::v<135>(XIEITE_FWD($)...)) $135, \
		decltype(XIEITE_DETAIL::FN::v<136>(XIEITE_FWD($)...)) $136, \
		decltype(XIEITE_DETAIL::FN::v<137>(XIEITE_FWD($)...)) $137, \
		decltype(XIEITE_DETAIL::FN::v<138>(XIEITE_FWD($)...)) $138, \
		decltype(XIEITE_DETAIL::FN::v<139>(XIEITE_FWD($)...)) $139, \
		decltype(XIEITE_DETAIL::FN::v<140>(XIEITE_FWD($)...)) $140, \
		decltype(XIEITE_DETAIL::FN::v<141>(XIEITE_FWD($)...)) $141, \
		decltype(XIEITE_DETAIL::FN::v<142>(XIEITE_FWD($)...)) $142, \
		decltype(XIEITE_DETAIL::FN::v<143>(XIEITE_FWD($)...)) $143, \
		decltype(XIEITE_DETAIL::FN::v<144>(XIEITE_FWD($)...)) $144, \
		decltype(XIEITE_DETAIL::FN::v<145>(XIEITE_FWD($)...)) $145, \
		decltype(XIEITE_DETAIL::FN::v<146>(XIEITE_FWD($)...)) $146, \
		decltype(XIEITE_DETAIL::FN::v<147>(XIEITE_FWD($)...)) $147, \
		decltype(XIEITE_DETAIL::FN::v<148>(XIEITE_FWD($)...)) $148, \
		decltype(XIEITE_DETAIL::FN::v<149>(XIEITE_FWD($)...)) $149, \
		decltype(XIEITE_DETAIL::FN::v<150>(XIEITE_FWD($)...)) $150, \
		decltype(XIEITE_DETAIL::FN::v<151>(XIEITE_FWD($)...)) $151, \
		decltype(XIEITE_DETAIL::FN::v<152>(XIEITE_FWD($)...)) $152, \
		decltype(XIEITE_DETAIL::FN::v<153>(XIEITE_FWD($)...)) $153, \
		decltype(XIEITE_DETAIL::FN::v<154>(XIEITE_FWD($)...)) $154, \
		decltype(XIEITE_DETAIL::FN::v<155>(XIEITE_FWD($)...)) $155, \
		decltype(XIEITE_DETAIL::FN::v<156>(XIEITE_FWD($)...)) $156, \
		decltype(XIEITE_DETAIL::FN::v<157>(XIEITE_FWD($)...)) $157, \
		decltype(XIEITE_DETAIL::FN::v<158>(XIEITE_FWD($)...)) $158, \
		decltype(XIEITE_DETAIL::FN::v<159>(XIEITE_FWD($)...)) $159, \
		decltype(XIEITE_DETAIL::FN::v<160>(XIEITE_FWD($)...)) $160, \
		decltype(XIEITE_DETAIL::FN::v<161>(XIEITE_FWD($)...)) $161, \
		decltype(XIEITE_DETAIL::FN::v<162>(XIEITE_FWD($)...)) $162, \
		decltype(XIEITE_DETAIL::FN::v<163>(XIEITE_FWD($)...)) $163, \
		decltype(XIEITE_DETAIL::FN::v<164>(XIEITE_FWD($)...)) $164, \
		decltype(XIEITE_DETAIL::FN::v<165>(XIEITE_FWD($)...)) $165, \
		decltype(XIEITE_DETAIL::FN::v<166>(XIEITE_FWD($)...)) $166, \
		decltype(XIEITE_DETAIL::FN::v<167>(XIEITE_FWD($)...)) $167, \
		decltype(XIEITE_DETAIL::FN::v<168>(XIEITE_FWD($)...)) $168, \
		decltype(XIEITE_DETAIL::FN::v<169>(XIEITE_FWD($)...)) $169, \
		decltype(XIEITE_DETAIL::FN::v<170>(XIEITE_FWD($)...)) $170, \
		decltype(XIEITE_DETAIL::FN::v<171>(XIEITE_FWD($)...)) $171, \
		decltype(XIEITE_DETAIL::FN::v<172>(XIEITE_FWD($)...)) $172, \
		decltype(XIEITE_DETAIL::FN::v<173>(XIEITE_FWD($)...)) $173, \
		decltype(XIEITE_DETAIL::FN::v<174>(XIEITE_FWD($)...)) $174, \
		decltype(XIEITE_DETAIL::FN::v<175>(XIEITE_FWD($)...)) $175, \
		decltype(XIEITE_DETAIL::FN::v<176>(XIEITE_FWD($)...)) $176, \
		decltype(XIEITE_DETAIL::FN::v<177>(XIEITE_FWD($)...)) $177, \
		decltype(XIEITE_DETAIL::FN::v<178>(XIEITE_FWD($)...)) $178, \
		decltype(XIEITE_DETAIL::FN::v<179>(XIEITE_FWD($)...)) $179, \
		decltype(XIEITE_DETAIL::FN::v<180>(XIEITE_FWD($)...)) $180, \
		decltype(XIEITE_DETAIL::FN::v<181>(XIEITE_FWD($)...)) $181, \
		decltype(XIEITE_DETAIL::FN::v<182>(XIEITE_FWD($)...)) $182, \
		decltype(XIEITE_DETAIL::FN::v<183>(XIEITE_FWD($)...)) $183, \
		decltype(XIEITE_DETAIL::FN::v<184>(XIEITE_FWD($)...)) $184, \
		decltype(XIEITE_DETAIL::FN::v<185>(XIEITE_FWD($)...)) $185, \
		decltype(XIEITE_DETAIL::FN::v<186>(XIEITE_FWD($)...)) $186, \
		decltype(XIEITE_DETAIL::FN::v<187>(XIEITE_FWD($)...)) $187, \
		decltype(XIEITE_DETAIL::FN::v<188>(XIEITE_FWD($)...)) $188, \
		decltype(XIEITE_DETAIL::FN::v<189>(XIEITE_FWD($)...)) $189, \
		decltype(XIEITE_DETAIL::FN::v<190>(XIEITE_FWD($)...)) $190, \
		decltype(XIEITE_DETAIL::FN::v<191>(XIEITE_FWD($)...)) $191, \
		decltype(XIEITE_DETAIL::FN::v<192>(XIEITE_FWD($)...)) $192, \
		decltype(XIEITE_DETAIL::FN::v<193>(XIEITE_FWD($)...)) $193, \
		decltype(XIEITE_DETAIL::FN::v<194>(XIEITE_FWD($)...)) $194, \
		decltype(XIEITE_DETAIL::FN::v<195>(XIEITE_FWD($)...)) $195, \
		decltype(XIEITE_DETAIL::FN::v<196>(XIEITE_FWD($)...)) $196, \
		decltype(XIEITE_DETAIL::FN::v<197>(XIEITE_FWD($)...)) $197, \
		decltype(XIEITE_DETAIL::FN::v<198>(XIEITE_FWD($)...)) $198, \
		decltype(XIEITE_DETAIL::FN::v<199>(XIEITE_FWD($)...)) $199, \
		decltype(XIEITE_DETAIL::FN::v<200>(XIEITE_FWD($)...)) $200, \
		decltype(XIEITE_DETAIL::FN::v<201>(XIEITE_FWD($)...)) $201, \
		decltype(XIEITE_DETAIL::FN::v<202>(XIEITE_FWD($)...)) $202, \
		decltype(XIEITE_DETAIL::FN::v<203>(XIEITE_FWD($)...)) $203, \
		decltype(XIEITE_DETAIL::FN::v<204>(XIEITE_FWD($)...)) $204, \
		decltype(XIEITE_DETAIL::FN::v<205>(XIEITE_FWD($)...)) $205, \
		decltype(XIEITE_DETAIL::FN::v<206>(XIEITE_FWD($)...)) $206, \
		decltype(XIEITE_DETAIL::FN::v<207>(XIEITE_FWD($)...)) $207, \
		decltype(XIEITE_DETAIL::FN::v<208>(XIEITE_FWD($)...)) $208, \
		decltype(XIEITE_DETAIL::FN::v<209>(XIEITE_FWD($)...)) $209, \
		decltype(XIEITE_DETAIL::FN::v<210>(XIEITE_FWD($)...)) $210, \
		decltype(XIEITE_DETAIL::FN::v<211>(XIEITE_FWD($)...)) $211, \
		decltype(XIEITE_DETAIL::FN::v<212>(XIEITE_FWD($)...)) $212, \
		decltype(XIEITE_DETAIL::FN::v<213>(XIEITE_FWD($)...)) $213, \
		decltype(XIEITE_DETAIL::FN::v<214>(XIEITE_FWD($)...)) $214, \
		decltype(XIEITE_DETAIL::FN::v<215>(XIEITE_FWD($)...)) $215, \
		decltype(XIEITE_DETAIL::FN::v<216>(XIEITE_FWD($)...)) $216, \
		decltype(XIEITE_DETAIL::FN::v<217>(XIEITE_FWD($)...)) $217, \
		decltype(XIEITE_DETAIL::FN::v<218>(XIEITE_FWD($)...)) $218, \
		decltype(XIEITE_DETAIL::FN::v<219>(XIEITE_FWD($)...)) $219, \
		decltype(XIEITE_DETAIL::FN::v<220>(XIEITE_FWD($)...)) $220, \
		decltype(XIEITE_DETAIL::FN::v<221>(XIEITE_FWD($)...)) $221, \
		decltype(XIEITE_DETAIL::FN::v<222>(XIEITE_FWD($)...)) $222, \
		decltype(XIEITE_DETAIL::FN::v<223>(XIEITE_FWD($)...)) $223, \
		decltype(XIEITE_DETAIL::FN::v<224>(XIEITE_FWD($)...)) $224, \
		decltype(XIEITE_DETAIL::FN::v<225>(XIEITE_FWD($)...)) $225, \
		decltype(XIEITE_DETAIL::FN::v<226>(XIEITE_FWD($)...)) $226, \
		decltype(XIEITE_DETAIL::FN::v<227>(XIEITE_FWD($)...)) $227, \
		decltype(XIEITE_DETAIL::FN::v<228>(XIEITE_FWD($)...)) $228, \
		decltype(XIEITE_DETAIL::FN::v<229>(XIEITE_FWD($)...)) $229, \
		decltype(XIEITE_DETAIL::FN::v<230>(XIEITE_FWD($)...)) $230, \
		decltype(XIEITE_DETAIL::FN::v<231>(XIEITE_FWD($)...)) $231, \
		decltype(XIEITE_DETAIL::FN::v<232>(XIEITE_FWD($)...)) $232, \
		decltype(XIEITE_DETAIL::FN::v<233>(XIEITE_FWD($)...)) $233, \
		decltype(XIEITE_DETAIL::FN::v<234>(XIEITE_FWD($)...)) $234, \
		decltype(XIEITE_DETAIL::FN::v<235>(XIEITE_FWD($)...)) $235, \
		decltype(XIEITE_DETAIL::FN::v<236>(XIEITE_FWD($)...)) $236, \
		decltype(XIEITE_DETAIL::FN::v<237>(XIEITE_FWD($)...)) $237, \
		decltype(XIEITE_DETAIL::FN::v<238>(XIEITE_FWD($)...)) $238, \
		decltype(XIEITE_DETAIL::FN::v<239>(XIEITE_FWD($)...)) $239, \
		decltype(XIEITE_DETAIL::FN::v<240>(XIEITE_FWD($)...)) $240, \
		decltype(XIEITE_DETAIL::FN::v<241>(XIEITE_FWD($)...)) $241, \
		decltype(XIEITE_DETAIL::FN::v<242>(XIEITE_FWD($)...)) $242, \
		decltype(XIEITE_DETAIL::FN::v<243>(XIEITE_FWD($)...)) $243, \
		decltype(XIEITE_DETAIL::FN::v<244>(XIEITE_FWD($)...)) $244, \
		decltype(XIEITE_DETAIL::FN::v<245>(XIEITE_FWD($)...)) $245, \
		decltype(XIEITE_DETAIL::FN::v<246>(XIEITE_FWD($)...)) $246, \
		decltype(XIEITE_DETAIL::FN::v<247>(XIEITE_FWD($)...)) $247, \
		decltype(XIEITE_DETAIL::FN::v<248>(XIEITE_FWD($)...)) $248, \
		decltype(XIEITE_DETAIL::FN::v<249>(XIEITE_FWD($)...)) $249, \
		decltype(XIEITE_DETAIL::FN::v<250>(XIEITE_FWD($)...)) $250, \
		decltype(XIEITE_DETAIL::FN::v<251>(XIEITE_FWD($)...)) $251, \
		decltype(XIEITE_DETAIL::FN::v<252>(XIEITE_FWD($)...)) $252, \
		decltype(XIEITE_DETAIL::FN::v<253>(XIEITE_FWD($)...)) $253, \
		decltype(XIEITE_DETAIL::FN::v<254>(XIEITE_FWD($)...)) $254, \
		decltype(XIEITE_DETAIL::FN::v<255>(XIEITE_FWD($)...)) $255, \
		decltype(XIEITE_DETAIL::FN::v<256>(XIEITE_FWD($)...)) $256 \
	) { (__VA_ARGS__); }) { \
		[[maybe_unused]] auto&& $0 = XIEITE_DETAIL::FN::v<0>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $1 = XIEITE_DETAIL::FN::v<1>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $2 = XIEITE_DETAIL::FN::v<2>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $3 = XIEITE_DETAIL::FN::v<3>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $4 = XIEITE_DETAIL::FN::v<4>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $5 = XIEITE_DETAIL::FN::v<5>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $6 = XIEITE_DETAIL::FN::v<6>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $7 = XIEITE_DETAIL::FN::v<7>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $8 = XIEITE_DETAIL::FN::v<8>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $9 = XIEITE_DETAIL::FN::v<9>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $10 = XIEITE_DETAIL::FN::v<10>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $11 = XIEITE_DETAIL::FN::v<11>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $12 = XIEITE_DETAIL::FN::v<12>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $13 = XIEITE_DETAIL::FN::v<13>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $14 = XIEITE_DETAIL::FN::v<14>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $15 = XIEITE_DETAIL::FN::v<15>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $16 = XIEITE_DETAIL::FN::v<16>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $17 = XIEITE_DETAIL::FN::v<17>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $18 = XIEITE_DETAIL::FN::v<18>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $19 = XIEITE_DETAIL::FN::v<19>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $20 = XIEITE_DETAIL::FN::v<20>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $21 = XIEITE_DETAIL::FN::v<21>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $22 = XIEITE_DETAIL::FN::v<22>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $23 = XIEITE_DETAIL::FN::v<23>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $24 = XIEITE_DETAIL::FN::v<24>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $25 = XIEITE_DETAIL::FN::v<25>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $26 = XIEITE_DETAIL::FN::v<26>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $27 = XIEITE_DETAIL::FN::v<27>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $28 = XIEITE_DETAIL::FN::v<28>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $29 = XIEITE_DETAIL::FN::v<29>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $30 = XIEITE_DETAIL::FN::v<30>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $31 = XIEITE_DETAIL::FN::v<31>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $32 = XIEITE_DETAIL::FN::v<32>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $33 = XIEITE_DETAIL::FN::v<33>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $34 = XIEITE_DETAIL::FN::v<34>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $35 = XIEITE_DETAIL::FN::v<35>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $36 = XIEITE_DETAIL::FN::v<36>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $37 = XIEITE_DETAIL::FN::v<37>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $38 = XIEITE_DETAIL::FN::v<38>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $39 = XIEITE_DETAIL::FN::v<39>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $40 = XIEITE_DETAIL::FN::v<40>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $41 = XIEITE_DETAIL::FN::v<41>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $42 = XIEITE_DETAIL::FN::v<42>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $43 = XIEITE_DETAIL::FN::v<43>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $44 = XIEITE_DETAIL::FN::v<44>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $45 = XIEITE_DETAIL::FN::v<45>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $46 = XIEITE_DETAIL::FN::v<46>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $47 = XIEITE_DETAIL::FN::v<47>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $48 = XIEITE_DETAIL::FN::v<48>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $49 = XIEITE_DETAIL::FN::v<49>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $50 = XIEITE_DETAIL::FN::v<50>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $51 = XIEITE_DETAIL::FN::v<51>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $52 = XIEITE_DETAIL::FN::v<52>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $53 = XIEITE_DETAIL::FN::v<53>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $54 = XIEITE_DETAIL::FN::v<54>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $55 = XIEITE_DETAIL::FN::v<55>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $56 = XIEITE_DETAIL::FN::v<56>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $57 = XIEITE_DETAIL::FN::v<57>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $58 = XIEITE_DETAIL::FN::v<58>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $59 = XIEITE_DETAIL::FN::v<59>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $60 = XIEITE_DETAIL::FN::v<60>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $61 = XIEITE_DETAIL::FN::v<61>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $62 = XIEITE_DETAIL::FN::v<62>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $63 = XIEITE_DETAIL::FN::v<63>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $64 = XIEITE_DETAIL::FN::v<64>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $65 = XIEITE_DETAIL::FN::v<65>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $66 = XIEITE_DETAIL::FN::v<66>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $67 = XIEITE_DETAIL::FN::v<67>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $68 = XIEITE_DETAIL::FN::v<68>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $69 = XIEITE_DETAIL::FN::v<69>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $70 = XIEITE_DETAIL::FN::v<70>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $71 = XIEITE_DETAIL::FN::v<71>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $72 = XIEITE_DETAIL::FN::v<72>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $73 = XIEITE_DETAIL::FN::v<73>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $74 = XIEITE_DETAIL::FN::v<74>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $75 = XIEITE_DETAIL::FN::v<75>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $76 = XIEITE_DETAIL::FN::v<76>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $77 = XIEITE_DETAIL::FN::v<77>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $78 = XIEITE_DETAIL::FN::v<78>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $79 = XIEITE_DETAIL::FN::v<79>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $80 = XIEITE_DETAIL::FN::v<80>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $81 = XIEITE_DETAIL::FN::v<81>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $82 = XIEITE_DETAIL::FN::v<82>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $83 = XIEITE_DETAIL::FN::v<83>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $84 = XIEITE_DETAIL::FN::v<84>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $85 = XIEITE_DETAIL::FN::v<85>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $86 = XIEITE_DETAIL::FN::v<86>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $87 = XIEITE_DETAIL::FN::v<87>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $88 = XIEITE_DETAIL::FN::v<88>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $89 = XIEITE_DETAIL::FN::v<89>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $90 = XIEITE_DETAIL::FN::v<90>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $91 = XIEITE_DETAIL::FN::v<91>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $92 = XIEITE_DETAIL::FN::v<92>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $93 = XIEITE_DETAIL::FN::v<93>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $94 = XIEITE_DETAIL::FN::v<94>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $95 = XIEITE_DETAIL::FN::v<95>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $96 = XIEITE_DETAIL::FN::v<96>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $97 = XIEITE_DETAIL::FN::v<97>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $98 = XIEITE_DETAIL::FN::v<98>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $99 = XIEITE_DETAIL::FN::v<99>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $100 = XIEITE_DETAIL::FN::v<100>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $101 = XIEITE_DETAIL::FN::v<101>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $102 = XIEITE_DETAIL::FN::v<102>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $103 = XIEITE_DETAIL::FN::v<103>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $104 = XIEITE_DETAIL::FN::v<104>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $105 = XIEITE_DETAIL::FN::v<105>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $106 = XIEITE_DETAIL::FN::v<106>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $107 = XIEITE_DETAIL::FN::v<107>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $108 = XIEITE_DETAIL::FN::v<108>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $109 = XIEITE_DETAIL::FN::v<109>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $110 = XIEITE_DETAIL::FN::v<110>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $111 = XIEITE_DETAIL::FN::v<111>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $112 = XIEITE_DETAIL::FN::v<112>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $113 = XIEITE_DETAIL::FN::v<113>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $114 = XIEITE_DETAIL::FN::v<114>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $115 = XIEITE_DETAIL::FN::v<115>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $116 = XIEITE_DETAIL::FN::v<116>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $117 = XIEITE_DETAIL::FN::v<117>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $118 = XIEITE_DETAIL::FN::v<118>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $119 = XIEITE_DETAIL::FN::v<119>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $120 = XIEITE_DETAIL::FN::v<120>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $121 = XIEITE_DETAIL::FN::v<121>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $122 = XIEITE_DETAIL::FN::v<122>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $123 = XIEITE_DETAIL::FN::v<123>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $124 = XIEITE_DETAIL::FN::v<124>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $125 = XIEITE_DETAIL::FN::v<125>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $126 = XIEITE_DETAIL::FN::v<126>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $127 = XIEITE_DETAIL::FN::v<127>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $128 = XIEITE_DETAIL::FN::v<128>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $129 = XIEITE_DETAIL::FN::v<129>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $130 = XIEITE_DETAIL::FN::v<130>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $131 = XIEITE_DETAIL::FN::v<131>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $132 = XIEITE_DETAIL::FN::v<132>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $133 = XIEITE_DETAIL::FN::v<133>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $134 = XIEITE_DETAIL::FN::v<134>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $135 = XIEITE_DETAIL::FN::v<135>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $136 = XIEITE_DETAIL::FN::v<136>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $137 = XIEITE_DETAIL::FN::v<137>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $138 = XIEITE_DETAIL::FN::v<138>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $139 = XIEITE_DETAIL::FN::v<139>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $140 = XIEITE_DETAIL::FN::v<140>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $141 = XIEITE_DETAIL::FN::v<141>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $142 = XIEITE_DETAIL::FN::v<142>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $143 = XIEITE_DETAIL::FN::v<143>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $144 = XIEITE_DETAIL::FN::v<144>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $145 = XIEITE_DETAIL::FN::v<145>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $146 = XIEITE_DETAIL::FN::v<146>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $147 = XIEITE_DETAIL::FN::v<147>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $148 = XIEITE_DETAIL::FN::v<148>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $149 = XIEITE_DETAIL::FN::v<149>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $150 = XIEITE_DETAIL::FN::v<150>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $151 = XIEITE_DETAIL::FN::v<151>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $152 = XIEITE_DETAIL::FN::v<152>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $153 = XIEITE_DETAIL::FN::v<153>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $154 = XIEITE_DETAIL::FN::v<154>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $155 = XIEITE_DETAIL::FN::v<155>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $156 = XIEITE_DETAIL::FN::v<156>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $157 = XIEITE_DETAIL::FN::v<157>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $158 = XIEITE_DETAIL::FN::v<158>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $159 = XIEITE_DETAIL::FN::v<159>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $160 = XIEITE_DETAIL::FN::v<160>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $161 = XIEITE_DETAIL::FN::v<161>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $162 = XIEITE_DETAIL::FN::v<162>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $163 = XIEITE_DETAIL::FN::v<163>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $164 = XIEITE_DETAIL::FN::v<164>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $165 = XIEITE_DETAIL::FN::v<165>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $166 = XIEITE_DETAIL::FN::v<166>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $167 = XIEITE_DETAIL::FN::v<167>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $168 = XIEITE_DETAIL::FN::v<168>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $169 = XIEITE_DETAIL::FN::v<169>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $170 = XIEITE_DETAIL::FN::v<170>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $171 = XIEITE_DETAIL::FN::v<171>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $172 = XIEITE_DETAIL::FN::v<172>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $173 = XIEITE_DETAIL::FN::v<173>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $174 = XIEITE_DETAIL::FN::v<174>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $175 = XIEITE_DETAIL::FN::v<175>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $176 = XIEITE_DETAIL::FN::v<176>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $177 = XIEITE_DETAIL::FN::v<177>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $178 = XIEITE_DETAIL::FN::v<178>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $179 = XIEITE_DETAIL::FN::v<179>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $180 = XIEITE_DETAIL::FN::v<180>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $181 = XIEITE_DETAIL::FN::v<181>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $182 = XIEITE_DETAIL::FN::v<182>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $183 = XIEITE_DETAIL::FN::v<183>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $184 = XIEITE_DETAIL::FN::v<184>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $185 = XIEITE_DETAIL::FN::v<185>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $186 = XIEITE_DETAIL::FN::v<186>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $187 = XIEITE_DETAIL::FN::v<187>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $188 = XIEITE_DETAIL::FN::v<188>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $189 = XIEITE_DETAIL::FN::v<189>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $190 = XIEITE_DETAIL::FN::v<190>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $191 = XIEITE_DETAIL::FN::v<191>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $192 = XIEITE_DETAIL::FN::v<192>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $193 = XIEITE_DETAIL::FN::v<193>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $194 = XIEITE_DETAIL::FN::v<194>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $195 = XIEITE_DETAIL::FN::v<195>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $196 = XIEITE_DETAIL::FN::v<196>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $197 = XIEITE_DETAIL::FN::v<197>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $198 = XIEITE_DETAIL::FN::v<198>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $199 = XIEITE_DETAIL::FN::v<199>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $200 = XIEITE_DETAIL::FN::v<200>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $201 = XIEITE_DETAIL::FN::v<201>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $202 = XIEITE_DETAIL::FN::v<202>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $203 = XIEITE_DETAIL::FN::v<203>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $204 = XIEITE_DETAIL::FN::v<204>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $205 = XIEITE_DETAIL::FN::v<205>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $206 = XIEITE_DETAIL::FN::v<206>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $207 = XIEITE_DETAIL::FN::v<207>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $208 = XIEITE_DETAIL::FN::v<208>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $209 = XIEITE_DETAIL::FN::v<209>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $210 = XIEITE_DETAIL::FN::v<210>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $211 = XIEITE_DETAIL::FN::v<211>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $212 = XIEITE_DETAIL::FN::v<212>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $213 = XIEITE_DETAIL::FN::v<213>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $214 = XIEITE_DETAIL::FN::v<214>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $215 = XIEITE_DETAIL::FN::v<215>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $216 = XIEITE_DETAIL::FN::v<216>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $217 = XIEITE_DETAIL::FN::v<217>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $218 = XIEITE_DETAIL::FN::v<218>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $219 = XIEITE_DETAIL::FN::v<219>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $220 = XIEITE_DETAIL::FN::v<220>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $221 = XIEITE_DETAIL::FN::v<221>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $222 = XIEITE_DETAIL::FN::v<222>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $223 = XIEITE_DETAIL::FN::v<223>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $224 = XIEITE_DETAIL::FN::v<224>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $225 = XIEITE_DETAIL::FN::v<225>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $226 = XIEITE_DETAIL::FN::v<226>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $227 = XIEITE_DETAIL::FN::v<227>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $228 = XIEITE_DETAIL::FN::v<228>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $229 = XIEITE_DETAIL::FN::v<229>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $230 = XIEITE_DETAIL::FN::v<230>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $231 = XIEITE_DETAIL::FN::v<231>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $232 = XIEITE_DETAIL::FN::v<232>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $233 = XIEITE_DETAIL::FN::v<233>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $234 = XIEITE_DETAIL::FN::v<234>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $235 = XIEITE_DETAIL::FN::v<235>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $236 = XIEITE_DETAIL::FN::v<236>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $237 = XIEITE_DETAIL::FN::v<237>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $238 = XIEITE_DETAIL::FN::v<238>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $239 = XIEITE_DETAIL::FN::v<239>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $240 = XIEITE_DETAIL::FN::v<240>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $241 = XIEITE_DETAIL::FN::v<241>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $242 = XIEITE_DETAIL::FN::v<242>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $243 = XIEITE_DETAIL::FN::v<243>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $244 = XIEITE_DETAIL::FN::v<244>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $245 = XIEITE_DETAIL::FN::v<245>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $246 = XIEITE_DETAIL::FN::v<246>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $247 = XIEITE_DETAIL::FN::v<247>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $248 = XIEITE_DETAIL::FN::v<248>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $249 = XIEITE_DETAIL::FN::v<249>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $250 = XIEITE_DETAIL::FN::v<250>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $251 = XIEITE_DETAIL::FN::v<251>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $252 = XIEITE_DETAIL::FN::v<252>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $253 = XIEITE_DETAIL::FN::v<253>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $254 = XIEITE_DETAIL::FN::v<254>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $255 = XIEITE_DETAIL::FN::v<255>(XIEITE_FWD($)...); \
		[[maybe_unused]] auto&& $256 = XIEITE_DETAIL::FN::v<256>(XIEITE_FWD($)...); \
		return (__VA_ARGS__); \
	}

namespace XIEITE_DETAIL::FN {
	// Template parameter must be named here due to GCC bug
	// https://gcc.gnu.org/bugzilla/show_bug.cgi?id=117422
	template<std::size_t idx> // <--
	constexpr auto&& v(auto&&...) noexcept;

	struct unusable {
		template<std::size_t idx>
		[[nodiscard]] friend constexpr auto&& v(auto&&... args) noexcept {
			if constexpr (idx < sizeof...(args)) {
				return XIEITE_FWD(args...[idx]);
			} else {
				static constexpr XIEITE_DETAIL::FN::unusable unusable;
				return unusable;
			}
		}

	private:
		unusable() = default;
	};

	template<std::size_t idx, typename... Ts>
	using t = decltype(([] {
		if constexpr (idx < sizeof...(Ts)) {
			return std::type_identity<Ts...[idx]>();
		} else {
			return std::type_identity<XIEITE_DETAIL::FN::unusable>();
		}
	})())::type;

	// TODO: Remove this wrapper once GCC accepts `[x = 0] noexcept(noexcept(x)) {}`
	template<typename F>
	struct indirect : F {
		template<typename... Ts>
		[[nodiscard]] constexpr auto operator()(auto&&... args)
			XIEITE_ARROW((*static_cast<F*>(this))().template operator()<Ts...>(XIEITE_FWD(args)...))
	};

	template<typename F>
	indirect(F) -> indirect<F>;
}
