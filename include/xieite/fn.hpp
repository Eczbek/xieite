#pragma once

#include <cstddef>
#include <tuple>
#include <type_traits>
#include <utility>
#include <xieite/diag.hpp>
#include <xieite/fwd.hpp>

#define XIEITE_FN(...) XIEITE_DETAIL_FN(, __VA_ARGS__)
#define XIEITE_FN_LOCAL(...) XIEITE_DETAIL_FN(&, __VA_ARGS__)

XIEITE_DIAG_OFF_CLANG(-Wdollar-in-identifier-extension)

#define XIEITE_DETAIL_FN(capture, ...) \
	[capture]<typename... $$_, \
		typename $0_ = XIEITE_DETAIL::at1<0, $$_...>, \
		typename $1_ = XIEITE_DETAIL::at1<1, $$_...>, \
		typename $2_ = XIEITE_DETAIL::at1<2, $$_...>, \
		typename $3_ = XIEITE_DETAIL::at1<3, $$_...>, \
		typename $4_ = XIEITE_DETAIL::at1<4, $$_...>, \
		typename $5_ = XIEITE_DETAIL::at1<5, $$_...>, \
		typename $6_ = XIEITE_DETAIL::at1<6, $$_...>, \
		typename $7_ = XIEITE_DETAIL::at1<7, $$_...>, \
		typename $8_ = XIEITE_DETAIL::at1<8, $$_...>, \
		typename $9_ = XIEITE_DETAIL::at1<9, $$_...>, \
		typename $10_ = XIEITE_DETAIL::at1<10, $$_...>, \
		typename $11_ = XIEITE_DETAIL::at1<11, $$_...>, \
		typename $12_ = XIEITE_DETAIL::at1<12, $$_...>, \
		typename $13_ = XIEITE_DETAIL::at1<13, $$_...>, \
		typename $14_ = XIEITE_DETAIL::at1<14, $$_...>, \
		typename $15_ = XIEITE_DETAIL::at1<15, $$_...>, \
		typename $16_ = XIEITE_DETAIL::at1<16, $$_...>, \
		typename $17_ = XIEITE_DETAIL::at1<17, $$_...>, \
		typename $18_ = XIEITE_DETAIL::at1<18, $$_...>, \
		typename $19_ = XIEITE_DETAIL::at1<19, $$_...>, \
		typename $20_ = XIEITE_DETAIL::at1<20, $$_...>, \
		typename $21_ = XIEITE_DETAIL::at1<21, $$_...>, \
		typename $22_ = XIEITE_DETAIL::at1<22, $$_...>, \
		typename $23_ = XIEITE_DETAIL::at1<23, $$_...>, \
		typename $24_ = XIEITE_DETAIL::at1<24, $$_...>, \
		typename $25_ = XIEITE_DETAIL::at1<25, $$_...>, \
		typename $26_ = XIEITE_DETAIL::at1<26, $$_...>, \
		typename $27_ = XIEITE_DETAIL::at1<27, $$_...>, \
		typename $28_ = XIEITE_DETAIL::at1<28, $$_...>, \
		typename $29_ = XIEITE_DETAIL::at1<29, $$_...>, \
		typename $30_ = XIEITE_DETAIL::at1<30, $$_...>, \
		typename $31_ = XIEITE_DETAIL::at1<31, $$_...>, \
		typename $32_ = XIEITE_DETAIL::at1<32, $$_...>, \
		typename $33_ = XIEITE_DETAIL::at1<33, $$_...>, \
		typename $34_ = XIEITE_DETAIL::at1<34, $$_...>, \
		typename $35_ = XIEITE_DETAIL::at1<35, $$_...>, \
		typename $36_ = XIEITE_DETAIL::at1<36, $$_...>, \
		typename $37_ = XIEITE_DETAIL::at1<37, $$_...>, \
		typename $38_ = XIEITE_DETAIL::at1<38, $$_...>, \
		typename $39_ = XIEITE_DETAIL::at1<39, $$_...>, \
		typename $40_ = XIEITE_DETAIL::at1<40, $$_...>, \
		typename $41_ = XIEITE_DETAIL::at1<41, $$_...>, \
		typename $42_ = XIEITE_DETAIL::at1<42, $$_...>, \
		typename $43_ = XIEITE_DETAIL::at1<43, $$_...>, \
		typename $44_ = XIEITE_DETAIL::at1<44, $$_...>, \
		typename $45_ = XIEITE_DETAIL::at1<45, $$_...>, \
		typename $46_ = XIEITE_DETAIL::at1<46, $$_...>, \
		typename $47_ = XIEITE_DETAIL::at1<47, $$_...>, \
		typename $48_ = XIEITE_DETAIL::at1<48, $$_...>, \
		typename $49_ = XIEITE_DETAIL::at1<49, $$_...>, \
		typename $50_ = XIEITE_DETAIL::at1<50, $$_...>, \
		typename $51_ = XIEITE_DETAIL::at1<51, $$_...>, \
		typename $52_ = XIEITE_DETAIL::at1<52, $$_...>, \
		typename $53_ = XIEITE_DETAIL::at1<53, $$_...>, \
		typename $54_ = XIEITE_DETAIL::at1<54, $$_...>, \
		typename $55_ = XIEITE_DETAIL::at1<55, $$_...>, \
		typename $56_ = XIEITE_DETAIL::at1<56, $$_...>, \
		typename $57_ = XIEITE_DETAIL::at1<57, $$_...>, \
		typename $58_ = XIEITE_DETAIL::at1<58, $$_...>, \
		typename $59_ = XIEITE_DETAIL::at1<59, $$_...>, \
		typename $60_ = XIEITE_DETAIL::at1<60, $$_...>, \
		typename $61_ = XIEITE_DETAIL::at1<61, $$_...>, \
		typename $62_ = XIEITE_DETAIL::at1<62, $$_...>, \
		typename $63_ = XIEITE_DETAIL::at1<63, $$_...>, \
		typename $64_ = XIEITE_DETAIL::at1<64, $$_...>, \
		typename $65_ = XIEITE_DETAIL::at1<65, $$_...>, \
		typename $66_ = XIEITE_DETAIL::at1<66, $$_...>, \
		typename $67_ = XIEITE_DETAIL::at1<67, $$_...>, \
		typename $68_ = XIEITE_DETAIL::at1<68, $$_...>, \
		typename $69_ = XIEITE_DETAIL::at1<69, $$_...>, \
		typename $70_ = XIEITE_DETAIL::at1<70, $$_...>, \
		typename $71_ = XIEITE_DETAIL::at1<71, $$_...>, \
		typename $72_ = XIEITE_DETAIL::at1<72, $$_...>, \
		typename $73_ = XIEITE_DETAIL::at1<73, $$_...>, \
		typename $74_ = XIEITE_DETAIL::at1<74, $$_...>, \
		typename $75_ = XIEITE_DETAIL::at1<75, $$_...>, \
		typename $76_ = XIEITE_DETAIL::at1<76, $$_...>, \
		typename $77_ = XIEITE_DETAIL::at1<77, $$_...>, \
		typename $78_ = XIEITE_DETAIL::at1<78, $$_...>, \
		typename $79_ = XIEITE_DETAIL::at1<79, $$_...>, \
		typename $80_ = XIEITE_DETAIL::at1<80, $$_...>, \
		typename $81_ = XIEITE_DETAIL::at1<81, $$_...>, \
		typename $82_ = XIEITE_DETAIL::at1<82, $$_...>, \
		typename $83_ = XIEITE_DETAIL::at1<83, $$_...>, \
		typename $84_ = XIEITE_DETAIL::at1<84, $$_...>, \
		typename $85_ = XIEITE_DETAIL::at1<85, $$_...>, \
		typename $86_ = XIEITE_DETAIL::at1<86, $$_...>, \
		typename $87_ = XIEITE_DETAIL::at1<87, $$_...>, \
		typename $88_ = XIEITE_DETAIL::at1<88, $$_...>, \
		typename $89_ = XIEITE_DETAIL::at1<89, $$_...>, \
		typename $90_ = XIEITE_DETAIL::at1<90, $$_...>, \
		typename $91_ = XIEITE_DETAIL::at1<91, $$_...>, \
		typename $92_ = XIEITE_DETAIL::at1<92, $$_...>, \
		typename $93_ = XIEITE_DETAIL::at1<93, $$_...>, \
		typename $94_ = XIEITE_DETAIL::at1<94, $$_...>, \
		typename $95_ = XIEITE_DETAIL::at1<95, $$_...>, \
		typename $96_ = XIEITE_DETAIL::at1<96, $$_...>, \
		typename $97_ = XIEITE_DETAIL::at1<97, $$_...>, \
		typename $98_ = XIEITE_DETAIL::at1<98, $$_...>, \
		typename $99_ = XIEITE_DETAIL::at1<99, $$_...>, \
		typename $100_ = XIEITE_DETAIL::at1<100, $$_...>, \
		typename $101_ = XIEITE_DETAIL::at1<101, $$_...>, \
		typename $102_ = XIEITE_DETAIL::at1<102, $$_...>, \
		typename $103_ = XIEITE_DETAIL::at1<103, $$_...>, \
		typename $104_ = XIEITE_DETAIL::at1<104, $$_...>, \
		typename $105_ = XIEITE_DETAIL::at1<105, $$_...>, \
		typename $106_ = XIEITE_DETAIL::at1<106, $$_...>, \
		typename $107_ = XIEITE_DETAIL::at1<107, $$_...>, \
		typename $108_ = XIEITE_DETAIL::at1<108, $$_...>, \
		typename $109_ = XIEITE_DETAIL::at1<109, $$_...>, \
		typename $110_ = XIEITE_DETAIL::at1<110, $$_...>, \
		typename $111_ = XIEITE_DETAIL::at1<111, $$_...>, \
		typename $112_ = XIEITE_DETAIL::at1<112, $$_...>, \
		typename $113_ = XIEITE_DETAIL::at1<113, $$_...>, \
		typename $114_ = XIEITE_DETAIL::at1<114, $$_...>, \
		typename $115_ = XIEITE_DETAIL::at1<115, $$_...>, \
		typename $116_ = XIEITE_DETAIL::at1<116, $$_...>, \
		typename $117_ = XIEITE_DETAIL::at1<117, $$_...>, \
		typename $118_ = XIEITE_DETAIL::at1<118, $$_...>, \
		typename $119_ = XIEITE_DETAIL::at1<119, $$_...>, \
		typename $120_ = XIEITE_DETAIL::at1<120, $$_...>, \
		typename $121_ = XIEITE_DETAIL::at1<121, $$_...>, \
		typename $122_ = XIEITE_DETAIL::at1<122, $$_...>, \
		typename $123_ = XIEITE_DETAIL::at1<123, $$_...>, \
		typename $124_ = XIEITE_DETAIL::at1<124, $$_...>, \
		typename $125_ = XIEITE_DETAIL::at1<125, $$_...>, \
		typename $126_ = XIEITE_DETAIL::at1<126, $$_...>, \
		typename $127_ = XIEITE_DETAIL::at1<127, $$_...>, \
		typename $128_ = XIEITE_DETAIL::at1<128, $$_...>, \
		typename $129_ = XIEITE_DETAIL::at1<129, $$_...>, \
		typename $130_ = XIEITE_DETAIL::at1<130, $$_...>, \
		typename $131_ = XIEITE_DETAIL::at1<131, $$_...>, \
		typename $132_ = XIEITE_DETAIL::at1<132, $$_...>, \
		typename $133_ = XIEITE_DETAIL::at1<133, $$_...>, \
		typename $134_ = XIEITE_DETAIL::at1<134, $$_...>, \
		typename $135_ = XIEITE_DETAIL::at1<135, $$_...>, \
		typename $136_ = XIEITE_DETAIL::at1<136, $$_...>, \
		typename $137_ = XIEITE_DETAIL::at1<137, $$_...>, \
		typename $138_ = XIEITE_DETAIL::at1<138, $$_...>, \
		typename $139_ = XIEITE_DETAIL::at1<139, $$_...>, \
		typename $140_ = XIEITE_DETAIL::at1<140, $$_...>, \
		typename $141_ = XIEITE_DETAIL::at1<141, $$_...>, \
		typename $142_ = XIEITE_DETAIL::at1<142, $$_...>, \
		typename $143_ = XIEITE_DETAIL::at1<143, $$_...>, \
		typename $144_ = XIEITE_DETAIL::at1<144, $$_...>, \
		typename $145_ = XIEITE_DETAIL::at1<145, $$_...>, \
		typename $146_ = XIEITE_DETAIL::at1<146, $$_...>, \
		typename $147_ = XIEITE_DETAIL::at1<147, $$_...>, \
		typename $148_ = XIEITE_DETAIL::at1<148, $$_...>, \
		typename $149_ = XIEITE_DETAIL::at1<149, $$_...>, \
		typename $150_ = XIEITE_DETAIL::at1<150, $$_...>, \
		typename $151_ = XIEITE_DETAIL::at1<151, $$_...>, \
		typename $152_ = XIEITE_DETAIL::at1<152, $$_...>, \
		typename $153_ = XIEITE_DETAIL::at1<153, $$_...>, \
		typename $154_ = XIEITE_DETAIL::at1<154, $$_...>, \
		typename $155_ = XIEITE_DETAIL::at1<155, $$_...>, \
		typename $156_ = XIEITE_DETAIL::at1<156, $$_...>, \
		typename $157_ = XIEITE_DETAIL::at1<157, $$_...>, \
		typename $158_ = XIEITE_DETAIL::at1<158, $$_...>, \
		typename $159_ = XIEITE_DETAIL::at1<159, $$_...>, \
		typename $160_ = XIEITE_DETAIL::at1<160, $$_...>, \
		typename $161_ = XIEITE_DETAIL::at1<161, $$_...>, \
		typename $162_ = XIEITE_DETAIL::at1<162, $$_...>, \
		typename $163_ = XIEITE_DETAIL::at1<163, $$_...>, \
		typename $164_ = XIEITE_DETAIL::at1<164, $$_...>, \
		typename $165_ = XIEITE_DETAIL::at1<165, $$_...>, \
		typename $166_ = XIEITE_DETAIL::at1<166, $$_...>, \
		typename $167_ = XIEITE_DETAIL::at1<167, $$_...>, \
		typename $168_ = XIEITE_DETAIL::at1<168, $$_...>, \
		typename $169_ = XIEITE_DETAIL::at1<169, $$_...>, \
		typename $170_ = XIEITE_DETAIL::at1<170, $$_...>, \
		typename $171_ = XIEITE_DETAIL::at1<171, $$_...>, \
		typename $172_ = XIEITE_DETAIL::at1<172, $$_...>, \
		typename $173_ = XIEITE_DETAIL::at1<173, $$_...>, \
		typename $174_ = XIEITE_DETAIL::at1<174, $$_...>, \
		typename $175_ = XIEITE_DETAIL::at1<175, $$_...>, \
		typename $176_ = XIEITE_DETAIL::at1<176, $$_...>, \
		typename $177_ = XIEITE_DETAIL::at1<177, $$_...>, \
		typename $178_ = XIEITE_DETAIL::at1<178, $$_...>, \
		typename $179_ = XIEITE_DETAIL::at1<179, $$_...>, \
		typename $180_ = XIEITE_DETAIL::at1<180, $$_...>, \
		typename $181_ = XIEITE_DETAIL::at1<181, $$_...>, \
		typename $182_ = XIEITE_DETAIL::at1<182, $$_...>, \
		typename $183_ = XIEITE_DETAIL::at1<183, $$_...>, \
		typename $184_ = XIEITE_DETAIL::at1<184, $$_...>, \
		typename $185_ = XIEITE_DETAIL::at1<185, $$_...>, \
		typename $186_ = XIEITE_DETAIL::at1<186, $$_...>, \
		typename $187_ = XIEITE_DETAIL::at1<187, $$_...>, \
		typename $188_ = XIEITE_DETAIL::at1<188, $$_...>, \
		typename $189_ = XIEITE_DETAIL::at1<189, $$_...>, \
		typename $190_ = XIEITE_DETAIL::at1<190, $$_...>, \
		typename $191_ = XIEITE_DETAIL::at1<191, $$_...>, \
		typename $192_ = XIEITE_DETAIL::at1<192, $$_...>, \
		typename $193_ = XIEITE_DETAIL::at1<193, $$_...>, \
		typename $194_ = XIEITE_DETAIL::at1<194, $$_...>, \
		typename $195_ = XIEITE_DETAIL::at1<195, $$_...>, \
		typename $196_ = XIEITE_DETAIL::at1<196, $$_...>, \
		typename $197_ = XIEITE_DETAIL::at1<197, $$_...>, \
		typename $198_ = XIEITE_DETAIL::at1<198, $$_...>, \
		typename $199_ = XIEITE_DETAIL::at1<199, $$_...>, \
		typename $200_ = XIEITE_DETAIL::at1<200, $$_...>, \
		typename $201_ = XIEITE_DETAIL::at1<201, $$_...>, \
		typename $202_ = XIEITE_DETAIL::at1<202, $$_...>, \
		typename $203_ = XIEITE_DETAIL::at1<203, $$_...>, \
		typename $204_ = XIEITE_DETAIL::at1<204, $$_...>, \
		typename $205_ = XIEITE_DETAIL::at1<205, $$_...>, \
		typename $206_ = XIEITE_DETAIL::at1<206, $$_...>, \
		typename $207_ = XIEITE_DETAIL::at1<207, $$_...>, \
		typename $208_ = XIEITE_DETAIL::at1<208, $$_...>, \
		typename $209_ = XIEITE_DETAIL::at1<209, $$_...>, \
		typename $210_ = XIEITE_DETAIL::at1<210, $$_...>, \
		typename $211_ = XIEITE_DETAIL::at1<211, $$_...>, \
		typename $212_ = XIEITE_DETAIL::at1<212, $$_...>, \
		typename $213_ = XIEITE_DETAIL::at1<213, $$_...>, \
		typename $214_ = XIEITE_DETAIL::at1<214, $$_...>, \
		typename $215_ = XIEITE_DETAIL::at1<215, $$_...>, \
		typename $216_ = XIEITE_DETAIL::at1<216, $$_...>, \
		typename $217_ = XIEITE_DETAIL::at1<217, $$_...>, \
		typename $218_ = XIEITE_DETAIL::at1<218, $$_...>, \
		typename $219_ = XIEITE_DETAIL::at1<219, $$_...>, \
		typename $220_ = XIEITE_DETAIL::at1<220, $$_...>, \
		typename $221_ = XIEITE_DETAIL::at1<221, $$_...>, \
		typename $222_ = XIEITE_DETAIL::at1<222, $$_...>, \
		typename $223_ = XIEITE_DETAIL::at1<223, $$_...>, \
		typename $224_ = XIEITE_DETAIL::at1<224, $$_...>, \
		typename $225_ = XIEITE_DETAIL::at1<225, $$_...>, \
		typename $226_ = XIEITE_DETAIL::at1<226, $$_...>, \
		typename $227_ = XIEITE_DETAIL::at1<227, $$_...>, \
		typename $228_ = XIEITE_DETAIL::at1<228, $$_...>, \
		typename $229_ = XIEITE_DETAIL::at1<229, $$_...>, \
		typename $230_ = XIEITE_DETAIL::at1<230, $$_...>, \
		typename $231_ = XIEITE_DETAIL::at1<231, $$_...>, \
		typename $232_ = XIEITE_DETAIL::at1<232, $$_...>, \
		typename $233_ = XIEITE_DETAIL::at1<233, $$_...>, \
		typename $234_ = XIEITE_DETAIL::at1<234, $$_...>, \
		typename $235_ = XIEITE_DETAIL::at1<235, $$_...>, \
		typename $236_ = XIEITE_DETAIL::at1<236, $$_...>, \
		typename $237_ = XIEITE_DETAIL::at1<237, $$_...>, \
		typename $238_ = XIEITE_DETAIL::at1<238, $$_...>, \
		typename $239_ = XIEITE_DETAIL::at1<239, $$_...>, \
		typename $240_ = XIEITE_DETAIL::at1<240, $$_...>, \
		typename $241_ = XIEITE_DETAIL::at1<241, $$_...>, \
		typename $242_ = XIEITE_DETAIL::at1<242, $$_...>, \
		typename $243_ = XIEITE_DETAIL::at1<243, $$_...>, \
		typename $244_ = XIEITE_DETAIL::at1<244, $$_...>, \
		typename $245_ = XIEITE_DETAIL::at1<245, $$_...>, \
		typename $246_ = XIEITE_DETAIL::at1<246, $$_...>, \
		typename $247_ = XIEITE_DETAIL::at1<247, $$_...>, \
		typename $248_ = XIEITE_DETAIL::at1<248, $$_...>, \
		typename $249_ = XIEITE_DETAIL::at1<249, $$_...>, \
		typename $250_ = XIEITE_DETAIL::at1<250, $$_...>, \
		typename $251_ = XIEITE_DETAIL::at1<251, $$_...>, \
		typename $252_ = XIEITE_DETAIL::at1<252, $$_...>, \
		typename $253_ = XIEITE_DETAIL::at1<253, $$_...>, \
		typename $254_ = XIEITE_DETAIL::at1<254, $$_...>, \
		typename $255_ = XIEITE_DETAIL::at1<255, $$_...>, \
		typename $256_ = XIEITE_DETAIL::at1<256, $$_...> \
	>[[nodiscard]](auto&&... $$) \
	noexcept(requires( \
		decltype(XIEITE_DETAIL::at0<0>(XIEITE_FWD($$)...)) $0, \
		decltype(XIEITE_DETAIL::at0<1>(XIEITE_FWD($$)...)) $1, \
		decltype(XIEITE_DETAIL::at0<2>(XIEITE_FWD($$)...)) $2, \
		decltype(XIEITE_DETAIL::at0<3>(XIEITE_FWD($$)...)) $3, \
		decltype(XIEITE_DETAIL::at0<4>(XIEITE_FWD($$)...)) $4, \
		decltype(XIEITE_DETAIL::at0<5>(XIEITE_FWD($$)...)) $5, \
		decltype(XIEITE_DETAIL::at0<6>(XIEITE_FWD($$)...)) $6, \
		decltype(XIEITE_DETAIL::at0<7>(XIEITE_FWD($$)...)) $7, \
		decltype(XIEITE_DETAIL::at0<8>(XIEITE_FWD($$)...)) $8, \
		decltype(XIEITE_DETAIL::at0<9>(XIEITE_FWD($$)...)) $9, \
		decltype(XIEITE_DETAIL::at0<10>(XIEITE_FWD($$)...)) $10, \
		decltype(XIEITE_DETAIL::at0<11>(XIEITE_FWD($$)...)) $11, \
		decltype(XIEITE_DETAIL::at0<12>(XIEITE_FWD($$)...)) $12, \
		decltype(XIEITE_DETAIL::at0<13>(XIEITE_FWD($$)...)) $13, \
		decltype(XIEITE_DETAIL::at0<14>(XIEITE_FWD($$)...)) $14, \
		decltype(XIEITE_DETAIL::at0<15>(XIEITE_FWD($$)...)) $15, \
		decltype(XIEITE_DETAIL::at0<16>(XIEITE_FWD($$)...)) $16, \
		decltype(XIEITE_DETAIL::at0<17>(XIEITE_FWD($$)...)) $17, \
		decltype(XIEITE_DETAIL::at0<18>(XIEITE_FWD($$)...)) $18, \
		decltype(XIEITE_DETAIL::at0<19>(XIEITE_FWD($$)...)) $19, \
		decltype(XIEITE_DETAIL::at0<20>(XIEITE_FWD($$)...)) $20, \
		decltype(XIEITE_DETAIL::at0<21>(XIEITE_FWD($$)...)) $21, \
		decltype(XIEITE_DETAIL::at0<22>(XIEITE_FWD($$)...)) $22, \
		decltype(XIEITE_DETAIL::at0<23>(XIEITE_FWD($$)...)) $23, \
		decltype(XIEITE_DETAIL::at0<24>(XIEITE_FWD($$)...)) $24, \
		decltype(XIEITE_DETAIL::at0<25>(XIEITE_FWD($$)...)) $25, \
		decltype(XIEITE_DETAIL::at0<26>(XIEITE_FWD($$)...)) $26, \
		decltype(XIEITE_DETAIL::at0<27>(XIEITE_FWD($$)...)) $27, \
		decltype(XIEITE_DETAIL::at0<28>(XIEITE_FWD($$)...)) $28, \
		decltype(XIEITE_DETAIL::at0<29>(XIEITE_FWD($$)...)) $29, \
		decltype(XIEITE_DETAIL::at0<30>(XIEITE_FWD($$)...)) $30, \
		decltype(XIEITE_DETAIL::at0<31>(XIEITE_FWD($$)...)) $31, \
		decltype(XIEITE_DETAIL::at0<32>(XIEITE_FWD($$)...)) $32, \
		decltype(XIEITE_DETAIL::at0<33>(XIEITE_FWD($$)...)) $33, \
		decltype(XIEITE_DETAIL::at0<34>(XIEITE_FWD($$)...)) $34, \
		decltype(XIEITE_DETAIL::at0<35>(XIEITE_FWD($$)...)) $35, \
		decltype(XIEITE_DETAIL::at0<36>(XIEITE_FWD($$)...)) $36, \
		decltype(XIEITE_DETAIL::at0<37>(XIEITE_FWD($$)...)) $37, \
		decltype(XIEITE_DETAIL::at0<38>(XIEITE_FWD($$)...)) $38, \
		decltype(XIEITE_DETAIL::at0<39>(XIEITE_FWD($$)...)) $39, \
		decltype(XIEITE_DETAIL::at0<40>(XIEITE_FWD($$)...)) $40, \
		decltype(XIEITE_DETAIL::at0<41>(XIEITE_FWD($$)...)) $41, \
		decltype(XIEITE_DETAIL::at0<42>(XIEITE_FWD($$)...)) $42, \
		decltype(XIEITE_DETAIL::at0<43>(XIEITE_FWD($$)...)) $43, \
		decltype(XIEITE_DETAIL::at0<44>(XIEITE_FWD($$)...)) $44, \
		decltype(XIEITE_DETAIL::at0<45>(XIEITE_FWD($$)...)) $45, \
		decltype(XIEITE_DETAIL::at0<46>(XIEITE_FWD($$)...)) $46, \
		decltype(XIEITE_DETAIL::at0<47>(XIEITE_FWD($$)...)) $47, \
		decltype(XIEITE_DETAIL::at0<48>(XIEITE_FWD($$)...)) $48, \
		decltype(XIEITE_DETAIL::at0<49>(XIEITE_FWD($$)...)) $49, \
		decltype(XIEITE_DETAIL::at0<50>(XIEITE_FWD($$)...)) $50, \
		decltype(XIEITE_DETAIL::at0<51>(XIEITE_FWD($$)...)) $51, \
		decltype(XIEITE_DETAIL::at0<52>(XIEITE_FWD($$)...)) $52, \
		decltype(XIEITE_DETAIL::at0<53>(XIEITE_FWD($$)...)) $53, \
		decltype(XIEITE_DETAIL::at0<54>(XIEITE_FWD($$)...)) $54, \
		decltype(XIEITE_DETAIL::at0<55>(XIEITE_FWD($$)...)) $55, \
		decltype(XIEITE_DETAIL::at0<56>(XIEITE_FWD($$)...)) $56, \
		decltype(XIEITE_DETAIL::at0<57>(XIEITE_FWD($$)...)) $57, \
		decltype(XIEITE_DETAIL::at0<58>(XIEITE_FWD($$)...)) $58, \
		decltype(XIEITE_DETAIL::at0<59>(XIEITE_FWD($$)...)) $59, \
		decltype(XIEITE_DETAIL::at0<60>(XIEITE_FWD($$)...)) $60, \
		decltype(XIEITE_DETAIL::at0<61>(XIEITE_FWD($$)...)) $61, \
		decltype(XIEITE_DETAIL::at0<62>(XIEITE_FWD($$)...)) $62, \
		decltype(XIEITE_DETAIL::at0<63>(XIEITE_FWD($$)...)) $63, \
		decltype(XIEITE_DETAIL::at0<64>(XIEITE_FWD($$)...)) $64, \
		decltype(XIEITE_DETAIL::at0<65>(XIEITE_FWD($$)...)) $65, \
		decltype(XIEITE_DETAIL::at0<66>(XIEITE_FWD($$)...)) $66, \
		decltype(XIEITE_DETAIL::at0<67>(XIEITE_FWD($$)...)) $67, \
		decltype(XIEITE_DETAIL::at0<68>(XIEITE_FWD($$)...)) $68, \
		decltype(XIEITE_DETAIL::at0<69>(XIEITE_FWD($$)...)) $69, \
		decltype(XIEITE_DETAIL::at0<70>(XIEITE_FWD($$)...)) $70, \
		decltype(XIEITE_DETAIL::at0<71>(XIEITE_FWD($$)...)) $71, \
		decltype(XIEITE_DETAIL::at0<72>(XIEITE_FWD($$)...)) $72, \
		decltype(XIEITE_DETAIL::at0<73>(XIEITE_FWD($$)...)) $73, \
		decltype(XIEITE_DETAIL::at0<74>(XIEITE_FWD($$)...)) $74, \
		decltype(XIEITE_DETAIL::at0<75>(XIEITE_FWD($$)...)) $75, \
		decltype(XIEITE_DETAIL::at0<76>(XIEITE_FWD($$)...)) $76, \
		decltype(XIEITE_DETAIL::at0<77>(XIEITE_FWD($$)...)) $77, \
		decltype(XIEITE_DETAIL::at0<78>(XIEITE_FWD($$)...)) $78, \
		decltype(XIEITE_DETAIL::at0<79>(XIEITE_FWD($$)...)) $79, \
		decltype(XIEITE_DETAIL::at0<80>(XIEITE_FWD($$)...)) $80, \
		decltype(XIEITE_DETAIL::at0<81>(XIEITE_FWD($$)...)) $81, \
		decltype(XIEITE_DETAIL::at0<82>(XIEITE_FWD($$)...)) $82, \
		decltype(XIEITE_DETAIL::at0<83>(XIEITE_FWD($$)...)) $83, \
		decltype(XIEITE_DETAIL::at0<84>(XIEITE_FWD($$)...)) $84, \
		decltype(XIEITE_DETAIL::at0<85>(XIEITE_FWD($$)...)) $85, \
		decltype(XIEITE_DETAIL::at0<86>(XIEITE_FWD($$)...)) $86, \
		decltype(XIEITE_DETAIL::at0<87>(XIEITE_FWD($$)...)) $87, \
		decltype(XIEITE_DETAIL::at0<88>(XIEITE_FWD($$)...)) $88, \
		decltype(XIEITE_DETAIL::at0<89>(XIEITE_FWD($$)...)) $89, \
		decltype(XIEITE_DETAIL::at0<90>(XIEITE_FWD($$)...)) $90, \
		decltype(XIEITE_DETAIL::at0<91>(XIEITE_FWD($$)...)) $91, \
		decltype(XIEITE_DETAIL::at0<92>(XIEITE_FWD($$)...)) $92, \
		decltype(XIEITE_DETAIL::at0<93>(XIEITE_FWD($$)...)) $93, \
		decltype(XIEITE_DETAIL::at0<94>(XIEITE_FWD($$)...)) $94, \
		decltype(XIEITE_DETAIL::at0<95>(XIEITE_FWD($$)...)) $95, \
		decltype(XIEITE_DETAIL::at0<96>(XIEITE_FWD($$)...)) $96, \
		decltype(XIEITE_DETAIL::at0<97>(XIEITE_FWD($$)...)) $97, \
		decltype(XIEITE_DETAIL::at0<98>(XIEITE_FWD($$)...)) $98, \
		decltype(XIEITE_DETAIL::at0<99>(XIEITE_FWD($$)...)) $99, \
		decltype(XIEITE_DETAIL::at0<100>(XIEITE_FWD($$)...)) $100, \
		decltype(XIEITE_DETAIL::at0<101>(XIEITE_FWD($$)...)) $101, \
		decltype(XIEITE_DETAIL::at0<102>(XIEITE_FWD($$)...)) $102, \
		decltype(XIEITE_DETAIL::at0<103>(XIEITE_FWD($$)...)) $103, \
		decltype(XIEITE_DETAIL::at0<104>(XIEITE_FWD($$)...)) $104, \
		decltype(XIEITE_DETAIL::at0<105>(XIEITE_FWD($$)...)) $105, \
		decltype(XIEITE_DETAIL::at0<106>(XIEITE_FWD($$)...)) $106, \
		decltype(XIEITE_DETAIL::at0<107>(XIEITE_FWD($$)...)) $107, \
		decltype(XIEITE_DETAIL::at0<108>(XIEITE_FWD($$)...)) $108, \
		decltype(XIEITE_DETAIL::at0<109>(XIEITE_FWD($$)...)) $109, \
		decltype(XIEITE_DETAIL::at0<110>(XIEITE_FWD($$)...)) $110, \
		decltype(XIEITE_DETAIL::at0<111>(XIEITE_FWD($$)...)) $111, \
		decltype(XIEITE_DETAIL::at0<112>(XIEITE_FWD($$)...)) $112, \
		decltype(XIEITE_DETAIL::at0<113>(XIEITE_FWD($$)...)) $113, \
		decltype(XIEITE_DETAIL::at0<114>(XIEITE_FWD($$)...)) $114, \
		decltype(XIEITE_DETAIL::at0<115>(XIEITE_FWD($$)...)) $115, \
		decltype(XIEITE_DETAIL::at0<116>(XIEITE_FWD($$)...)) $116, \
		decltype(XIEITE_DETAIL::at0<117>(XIEITE_FWD($$)...)) $117, \
		decltype(XIEITE_DETAIL::at0<118>(XIEITE_FWD($$)...)) $118, \
		decltype(XIEITE_DETAIL::at0<119>(XIEITE_FWD($$)...)) $119, \
		decltype(XIEITE_DETAIL::at0<120>(XIEITE_FWD($$)...)) $120, \
		decltype(XIEITE_DETAIL::at0<121>(XIEITE_FWD($$)...)) $121, \
		decltype(XIEITE_DETAIL::at0<122>(XIEITE_FWD($$)...)) $122, \
		decltype(XIEITE_DETAIL::at0<123>(XIEITE_FWD($$)...)) $123, \
		decltype(XIEITE_DETAIL::at0<124>(XIEITE_FWD($$)...)) $124, \
		decltype(XIEITE_DETAIL::at0<125>(XIEITE_FWD($$)...)) $125, \
		decltype(XIEITE_DETAIL::at0<126>(XIEITE_FWD($$)...)) $126, \
		decltype(XIEITE_DETAIL::at0<127>(XIEITE_FWD($$)...)) $127, \
		decltype(XIEITE_DETAIL::at0<128>(XIEITE_FWD($$)...)) $128, \
		decltype(XIEITE_DETAIL::at0<129>(XIEITE_FWD($$)...)) $129, \
		decltype(XIEITE_DETAIL::at0<130>(XIEITE_FWD($$)...)) $130, \
		decltype(XIEITE_DETAIL::at0<131>(XIEITE_FWD($$)...)) $131, \
		decltype(XIEITE_DETAIL::at0<132>(XIEITE_FWD($$)...)) $132, \
		decltype(XIEITE_DETAIL::at0<133>(XIEITE_FWD($$)...)) $133, \
		decltype(XIEITE_DETAIL::at0<134>(XIEITE_FWD($$)...)) $134, \
		decltype(XIEITE_DETAIL::at0<135>(XIEITE_FWD($$)...)) $135, \
		decltype(XIEITE_DETAIL::at0<136>(XIEITE_FWD($$)...)) $136, \
		decltype(XIEITE_DETAIL::at0<137>(XIEITE_FWD($$)...)) $137, \
		decltype(XIEITE_DETAIL::at0<138>(XIEITE_FWD($$)...)) $138, \
		decltype(XIEITE_DETAIL::at0<139>(XIEITE_FWD($$)...)) $139, \
		decltype(XIEITE_DETAIL::at0<140>(XIEITE_FWD($$)...)) $140, \
		decltype(XIEITE_DETAIL::at0<141>(XIEITE_FWD($$)...)) $141, \
		decltype(XIEITE_DETAIL::at0<142>(XIEITE_FWD($$)...)) $142, \
		decltype(XIEITE_DETAIL::at0<143>(XIEITE_FWD($$)...)) $143, \
		decltype(XIEITE_DETAIL::at0<144>(XIEITE_FWD($$)...)) $144, \
		decltype(XIEITE_DETAIL::at0<145>(XIEITE_FWD($$)...)) $145, \
		decltype(XIEITE_DETAIL::at0<146>(XIEITE_FWD($$)...)) $146, \
		decltype(XIEITE_DETAIL::at0<147>(XIEITE_FWD($$)...)) $147, \
		decltype(XIEITE_DETAIL::at0<148>(XIEITE_FWD($$)...)) $148, \
		decltype(XIEITE_DETAIL::at0<149>(XIEITE_FWD($$)...)) $149, \
		decltype(XIEITE_DETAIL::at0<150>(XIEITE_FWD($$)...)) $150, \
		decltype(XIEITE_DETAIL::at0<151>(XIEITE_FWD($$)...)) $151, \
		decltype(XIEITE_DETAIL::at0<152>(XIEITE_FWD($$)...)) $152, \
		decltype(XIEITE_DETAIL::at0<153>(XIEITE_FWD($$)...)) $153, \
		decltype(XIEITE_DETAIL::at0<154>(XIEITE_FWD($$)...)) $154, \
		decltype(XIEITE_DETAIL::at0<155>(XIEITE_FWD($$)...)) $155, \
		decltype(XIEITE_DETAIL::at0<156>(XIEITE_FWD($$)...)) $156, \
		decltype(XIEITE_DETAIL::at0<157>(XIEITE_FWD($$)...)) $157, \
		decltype(XIEITE_DETAIL::at0<158>(XIEITE_FWD($$)...)) $158, \
		decltype(XIEITE_DETAIL::at0<159>(XIEITE_FWD($$)...)) $159, \
		decltype(XIEITE_DETAIL::at0<160>(XIEITE_FWD($$)...)) $160, \
		decltype(XIEITE_DETAIL::at0<161>(XIEITE_FWD($$)...)) $161, \
		decltype(XIEITE_DETAIL::at0<162>(XIEITE_FWD($$)...)) $162, \
		decltype(XIEITE_DETAIL::at0<163>(XIEITE_FWD($$)...)) $163, \
		decltype(XIEITE_DETAIL::at0<164>(XIEITE_FWD($$)...)) $164, \
		decltype(XIEITE_DETAIL::at0<165>(XIEITE_FWD($$)...)) $165, \
		decltype(XIEITE_DETAIL::at0<166>(XIEITE_FWD($$)...)) $166, \
		decltype(XIEITE_DETAIL::at0<167>(XIEITE_FWD($$)...)) $167, \
		decltype(XIEITE_DETAIL::at0<168>(XIEITE_FWD($$)...)) $168, \
		decltype(XIEITE_DETAIL::at0<169>(XIEITE_FWD($$)...)) $169, \
		decltype(XIEITE_DETAIL::at0<170>(XIEITE_FWD($$)...)) $170, \
		decltype(XIEITE_DETAIL::at0<171>(XIEITE_FWD($$)...)) $171, \
		decltype(XIEITE_DETAIL::at0<172>(XIEITE_FWD($$)...)) $172, \
		decltype(XIEITE_DETAIL::at0<173>(XIEITE_FWD($$)...)) $173, \
		decltype(XIEITE_DETAIL::at0<174>(XIEITE_FWD($$)...)) $174, \
		decltype(XIEITE_DETAIL::at0<175>(XIEITE_FWD($$)...)) $175, \
		decltype(XIEITE_DETAIL::at0<176>(XIEITE_FWD($$)...)) $176, \
		decltype(XIEITE_DETAIL::at0<177>(XIEITE_FWD($$)...)) $177, \
		decltype(XIEITE_DETAIL::at0<178>(XIEITE_FWD($$)...)) $178, \
		decltype(XIEITE_DETAIL::at0<179>(XIEITE_FWD($$)...)) $179, \
		decltype(XIEITE_DETAIL::at0<180>(XIEITE_FWD($$)...)) $180, \
		decltype(XIEITE_DETAIL::at0<181>(XIEITE_FWD($$)...)) $181, \
		decltype(XIEITE_DETAIL::at0<182>(XIEITE_FWD($$)...)) $182, \
		decltype(XIEITE_DETAIL::at0<183>(XIEITE_FWD($$)...)) $183, \
		decltype(XIEITE_DETAIL::at0<184>(XIEITE_FWD($$)...)) $184, \
		decltype(XIEITE_DETAIL::at0<185>(XIEITE_FWD($$)...)) $185, \
		decltype(XIEITE_DETAIL::at0<186>(XIEITE_FWD($$)...)) $186, \
		decltype(XIEITE_DETAIL::at0<187>(XIEITE_FWD($$)...)) $187, \
		decltype(XIEITE_DETAIL::at0<188>(XIEITE_FWD($$)...)) $188, \
		decltype(XIEITE_DETAIL::at0<189>(XIEITE_FWD($$)...)) $189, \
		decltype(XIEITE_DETAIL::at0<190>(XIEITE_FWD($$)...)) $190, \
		decltype(XIEITE_DETAIL::at0<191>(XIEITE_FWD($$)...)) $191, \
		decltype(XIEITE_DETAIL::at0<192>(XIEITE_FWD($$)...)) $192, \
		decltype(XIEITE_DETAIL::at0<193>(XIEITE_FWD($$)...)) $193, \
		decltype(XIEITE_DETAIL::at0<194>(XIEITE_FWD($$)...)) $194, \
		decltype(XIEITE_DETAIL::at0<195>(XIEITE_FWD($$)...)) $195, \
		decltype(XIEITE_DETAIL::at0<196>(XIEITE_FWD($$)...)) $196, \
		decltype(XIEITE_DETAIL::at0<197>(XIEITE_FWD($$)...)) $197, \
		decltype(XIEITE_DETAIL::at0<198>(XIEITE_FWD($$)...)) $198, \
		decltype(XIEITE_DETAIL::at0<199>(XIEITE_FWD($$)...)) $199, \
		decltype(XIEITE_DETAIL::at0<200>(XIEITE_FWD($$)...)) $200, \
		decltype(XIEITE_DETAIL::at0<201>(XIEITE_FWD($$)...)) $201, \
		decltype(XIEITE_DETAIL::at0<202>(XIEITE_FWD($$)...)) $202, \
		decltype(XIEITE_DETAIL::at0<203>(XIEITE_FWD($$)...)) $203, \
		decltype(XIEITE_DETAIL::at0<204>(XIEITE_FWD($$)...)) $204, \
		decltype(XIEITE_DETAIL::at0<205>(XIEITE_FWD($$)...)) $205, \
		decltype(XIEITE_DETAIL::at0<206>(XIEITE_FWD($$)...)) $206, \
		decltype(XIEITE_DETAIL::at0<207>(XIEITE_FWD($$)...)) $207, \
		decltype(XIEITE_DETAIL::at0<208>(XIEITE_FWD($$)...)) $208, \
		decltype(XIEITE_DETAIL::at0<209>(XIEITE_FWD($$)...)) $209, \
		decltype(XIEITE_DETAIL::at0<210>(XIEITE_FWD($$)...)) $210, \
		decltype(XIEITE_DETAIL::at0<211>(XIEITE_FWD($$)...)) $211, \
		decltype(XIEITE_DETAIL::at0<212>(XIEITE_FWD($$)...)) $212, \
		decltype(XIEITE_DETAIL::at0<213>(XIEITE_FWD($$)...)) $213, \
		decltype(XIEITE_DETAIL::at0<214>(XIEITE_FWD($$)...)) $214, \
		decltype(XIEITE_DETAIL::at0<215>(XIEITE_FWD($$)...)) $215, \
		decltype(XIEITE_DETAIL::at0<216>(XIEITE_FWD($$)...)) $216, \
		decltype(XIEITE_DETAIL::at0<217>(XIEITE_FWD($$)...)) $217, \
		decltype(XIEITE_DETAIL::at0<218>(XIEITE_FWD($$)...)) $218, \
		decltype(XIEITE_DETAIL::at0<219>(XIEITE_FWD($$)...)) $219, \
		decltype(XIEITE_DETAIL::at0<220>(XIEITE_FWD($$)...)) $220, \
		decltype(XIEITE_DETAIL::at0<221>(XIEITE_FWD($$)...)) $221, \
		decltype(XIEITE_DETAIL::at0<222>(XIEITE_FWD($$)...)) $222, \
		decltype(XIEITE_DETAIL::at0<223>(XIEITE_FWD($$)...)) $223, \
		decltype(XIEITE_DETAIL::at0<224>(XIEITE_FWD($$)...)) $224, \
		decltype(XIEITE_DETAIL::at0<225>(XIEITE_FWD($$)...)) $225, \
		decltype(XIEITE_DETAIL::at0<226>(XIEITE_FWD($$)...)) $226, \
		decltype(XIEITE_DETAIL::at0<227>(XIEITE_FWD($$)...)) $227, \
		decltype(XIEITE_DETAIL::at0<228>(XIEITE_FWD($$)...)) $228, \
		decltype(XIEITE_DETAIL::at0<229>(XIEITE_FWD($$)...)) $229, \
		decltype(XIEITE_DETAIL::at0<230>(XIEITE_FWD($$)...)) $230, \
		decltype(XIEITE_DETAIL::at0<231>(XIEITE_FWD($$)...)) $231, \
		decltype(XIEITE_DETAIL::at0<232>(XIEITE_FWD($$)...)) $232, \
		decltype(XIEITE_DETAIL::at0<233>(XIEITE_FWD($$)...)) $233, \
		decltype(XIEITE_DETAIL::at0<234>(XIEITE_FWD($$)...)) $234, \
		decltype(XIEITE_DETAIL::at0<235>(XIEITE_FWD($$)...)) $235, \
		decltype(XIEITE_DETAIL::at0<236>(XIEITE_FWD($$)...)) $236, \
		decltype(XIEITE_DETAIL::at0<237>(XIEITE_FWD($$)...)) $237, \
		decltype(XIEITE_DETAIL::at0<238>(XIEITE_FWD($$)...)) $238, \
		decltype(XIEITE_DETAIL::at0<239>(XIEITE_FWD($$)...)) $239, \
		decltype(XIEITE_DETAIL::at0<240>(XIEITE_FWD($$)...)) $240, \
		decltype(XIEITE_DETAIL::at0<241>(XIEITE_FWD($$)...)) $241, \
		decltype(XIEITE_DETAIL::at0<242>(XIEITE_FWD($$)...)) $242, \
		decltype(XIEITE_DETAIL::at0<243>(XIEITE_FWD($$)...)) $243, \
		decltype(XIEITE_DETAIL::at0<244>(XIEITE_FWD($$)...)) $244, \
		decltype(XIEITE_DETAIL::at0<245>(XIEITE_FWD($$)...)) $245, \
		decltype(XIEITE_DETAIL::at0<246>(XIEITE_FWD($$)...)) $246, \
		decltype(XIEITE_DETAIL::at0<247>(XIEITE_FWD($$)...)) $247, \
		decltype(XIEITE_DETAIL::at0<248>(XIEITE_FWD($$)...)) $248, \
		decltype(XIEITE_DETAIL::at0<249>(XIEITE_FWD($$)...)) $249, \
		decltype(XIEITE_DETAIL::at0<250>(XIEITE_FWD($$)...)) $250, \
		decltype(XIEITE_DETAIL::at0<251>(XIEITE_FWD($$)...)) $251, \
		decltype(XIEITE_DETAIL::at0<252>(XIEITE_FWD($$)...)) $252, \
		decltype(XIEITE_DETAIL::at0<253>(XIEITE_FWD($$)...)) $253, \
		decltype(XIEITE_DETAIL::at0<254>(XIEITE_FWD($$)...)) $254, \
		decltype(XIEITE_DETAIL::at0<255>(XIEITE_FWD($$)...)) $255, \
		decltype(XIEITE_DETAIL::at0<256>(XIEITE_FWD($$)...)) $256 \
	) { requires(noexcept((__VA_ARGS__))); }) \
	-> decltype(auto) \
	requires(requires( \
		decltype(XIEITE_DETAIL::at0<0>(XIEITE_FWD($$)...)) $0, \
		decltype(XIEITE_DETAIL::at0<1>(XIEITE_FWD($$)...)) $1, \
		decltype(XIEITE_DETAIL::at0<2>(XIEITE_FWD($$)...)) $2, \
		decltype(XIEITE_DETAIL::at0<3>(XIEITE_FWD($$)...)) $3, \
		decltype(XIEITE_DETAIL::at0<4>(XIEITE_FWD($$)...)) $4, \
		decltype(XIEITE_DETAIL::at0<5>(XIEITE_FWD($$)...)) $5, \
		decltype(XIEITE_DETAIL::at0<6>(XIEITE_FWD($$)...)) $6, \
		decltype(XIEITE_DETAIL::at0<7>(XIEITE_FWD($$)...)) $7, \
		decltype(XIEITE_DETAIL::at0<8>(XIEITE_FWD($$)...)) $8, \
		decltype(XIEITE_DETAIL::at0<9>(XIEITE_FWD($$)...)) $9, \
		decltype(XIEITE_DETAIL::at0<10>(XIEITE_FWD($$)...)) $10, \
		decltype(XIEITE_DETAIL::at0<11>(XIEITE_FWD($$)...)) $11, \
		decltype(XIEITE_DETAIL::at0<12>(XIEITE_FWD($$)...)) $12, \
		decltype(XIEITE_DETAIL::at0<13>(XIEITE_FWD($$)...)) $13, \
		decltype(XIEITE_DETAIL::at0<14>(XIEITE_FWD($$)...)) $14, \
		decltype(XIEITE_DETAIL::at0<15>(XIEITE_FWD($$)...)) $15, \
		decltype(XIEITE_DETAIL::at0<16>(XIEITE_FWD($$)...)) $16, \
		decltype(XIEITE_DETAIL::at0<17>(XIEITE_FWD($$)...)) $17, \
		decltype(XIEITE_DETAIL::at0<18>(XIEITE_FWD($$)...)) $18, \
		decltype(XIEITE_DETAIL::at0<19>(XIEITE_FWD($$)...)) $19, \
		decltype(XIEITE_DETAIL::at0<20>(XIEITE_FWD($$)...)) $20, \
		decltype(XIEITE_DETAIL::at0<21>(XIEITE_FWD($$)...)) $21, \
		decltype(XIEITE_DETAIL::at0<22>(XIEITE_FWD($$)...)) $22, \
		decltype(XIEITE_DETAIL::at0<23>(XIEITE_FWD($$)...)) $23, \
		decltype(XIEITE_DETAIL::at0<24>(XIEITE_FWD($$)...)) $24, \
		decltype(XIEITE_DETAIL::at0<25>(XIEITE_FWD($$)...)) $25, \
		decltype(XIEITE_DETAIL::at0<26>(XIEITE_FWD($$)...)) $26, \
		decltype(XIEITE_DETAIL::at0<27>(XIEITE_FWD($$)...)) $27, \
		decltype(XIEITE_DETAIL::at0<28>(XIEITE_FWD($$)...)) $28, \
		decltype(XIEITE_DETAIL::at0<29>(XIEITE_FWD($$)...)) $29, \
		decltype(XIEITE_DETAIL::at0<30>(XIEITE_FWD($$)...)) $30, \
		decltype(XIEITE_DETAIL::at0<31>(XIEITE_FWD($$)...)) $31, \
		decltype(XIEITE_DETAIL::at0<32>(XIEITE_FWD($$)...)) $32, \
		decltype(XIEITE_DETAIL::at0<33>(XIEITE_FWD($$)...)) $33, \
		decltype(XIEITE_DETAIL::at0<34>(XIEITE_FWD($$)...)) $34, \
		decltype(XIEITE_DETAIL::at0<35>(XIEITE_FWD($$)...)) $35, \
		decltype(XIEITE_DETAIL::at0<36>(XIEITE_FWD($$)...)) $36, \
		decltype(XIEITE_DETAIL::at0<37>(XIEITE_FWD($$)...)) $37, \
		decltype(XIEITE_DETAIL::at0<38>(XIEITE_FWD($$)...)) $38, \
		decltype(XIEITE_DETAIL::at0<39>(XIEITE_FWD($$)...)) $39, \
		decltype(XIEITE_DETAIL::at0<40>(XIEITE_FWD($$)...)) $40, \
		decltype(XIEITE_DETAIL::at0<41>(XIEITE_FWD($$)...)) $41, \
		decltype(XIEITE_DETAIL::at0<42>(XIEITE_FWD($$)...)) $42, \
		decltype(XIEITE_DETAIL::at0<43>(XIEITE_FWD($$)...)) $43, \
		decltype(XIEITE_DETAIL::at0<44>(XIEITE_FWD($$)...)) $44, \
		decltype(XIEITE_DETAIL::at0<45>(XIEITE_FWD($$)...)) $45, \
		decltype(XIEITE_DETAIL::at0<46>(XIEITE_FWD($$)...)) $46, \
		decltype(XIEITE_DETAIL::at0<47>(XIEITE_FWD($$)...)) $47, \
		decltype(XIEITE_DETAIL::at0<48>(XIEITE_FWD($$)...)) $48, \
		decltype(XIEITE_DETAIL::at0<49>(XIEITE_FWD($$)...)) $49, \
		decltype(XIEITE_DETAIL::at0<50>(XIEITE_FWD($$)...)) $50, \
		decltype(XIEITE_DETAIL::at0<51>(XIEITE_FWD($$)...)) $51, \
		decltype(XIEITE_DETAIL::at0<52>(XIEITE_FWD($$)...)) $52, \
		decltype(XIEITE_DETAIL::at0<53>(XIEITE_FWD($$)...)) $53, \
		decltype(XIEITE_DETAIL::at0<54>(XIEITE_FWD($$)...)) $54, \
		decltype(XIEITE_DETAIL::at0<55>(XIEITE_FWD($$)...)) $55, \
		decltype(XIEITE_DETAIL::at0<56>(XIEITE_FWD($$)...)) $56, \
		decltype(XIEITE_DETAIL::at0<57>(XIEITE_FWD($$)...)) $57, \
		decltype(XIEITE_DETAIL::at0<58>(XIEITE_FWD($$)...)) $58, \
		decltype(XIEITE_DETAIL::at0<59>(XIEITE_FWD($$)...)) $59, \
		decltype(XIEITE_DETAIL::at0<60>(XIEITE_FWD($$)...)) $60, \
		decltype(XIEITE_DETAIL::at0<61>(XIEITE_FWD($$)...)) $61, \
		decltype(XIEITE_DETAIL::at0<62>(XIEITE_FWD($$)...)) $62, \
		decltype(XIEITE_DETAIL::at0<63>(XIEITE_FWD($$)...)) $63, \
		decltype(XIEITE_DETAIL::at0<64>(XIEITE_FWD($$)...)) $64, \
		decltype(XIEITE_DETAIL::at0<65>(XIEITE_FWD($$)...)) $65, \
		decltype(XIEITE_DETAIL::at0<66>(XIEITE_FWD($$)...)) $66, \
		decltype(XIEITE_DETAIL::at0<67>(XIEITE_FWD($$)...)) $67, \
		decltype(XIEITE_DETAIL::at0<68>(XIEITE_FWD($$)...)) $68, \
		decltype(XIEITE_DETAIL::at0<69>(XIEITE_FWD($$)...)) $69, \
		decltype(XIEITE_DETAIL::at0<70>(XIEITE_FWD($$)...)) $70, \
		decltype(XIEITE_DETAIL::at0<71>(XIEITE_FWD($$)...)) $71, \
		decltype(XIEITE_DETAIL::at0<72>(XIEITE_FWD($$)...)) $72, \
		decltype(XIEITE_DETAIL::at0<73>(XIEITE_FWD($$)...)) $73, \
		decltype(XIEITE_DETAIL::at0<74>(XIEITE_FWD($$)...)) $74, \
		decltype(XIEITE_DETAIL::at0<75>(XIEITE_FWD($$)...)) $75, \
		decltype(XIEITE_DETAIL::at0<76>(XIEITE_FWD($$)...)) $76, \
		decltype(XIEITE_DETAIL::at0<77>(XIEITE_FWD($$)...)) $77, \
		decltype(XIEITE_DETAIL::at0<78>(XIEITE_FWD($$)...)) $78, \
		decltype(XIEITE_DETAIL::at0<79>(XIEITE_FWD($$)...)) $79, \
		decltype(XIEITE_DETAIL::at0<80>(XIEITE_FWD($$)...)) $80, \
		decltype(XIEITE_DETAIL::at0<81>(XIEITE_FWD($$)...)) $81, \
		decltype(XIEITE_DETAIL::at0<82>(XIEITE_FWD($$)...)) $82, \
		decltype(XIEITE_DETAIL::at0<83>(XIEITE_FWD($$)...)) $83, \
		decltype(XIEITE_DETAIL::at0<84>(XIEITE_FWD($$)...)) $84, \
		decltype(XIEITE_DETAIL::at0<85>(XIEITE_FWD($$)...)) $85, \
		decltype(XIEITE_DETAIL::at0<86>(XIEITE_FWD($$)...)) $86, \
		decltype(XIEITE_DETAIL::at0<87>(XIEITE_FWD($$)...)) $87, \
		decltype(XIEITE_DETAIL::at0<88>(XIEITE_FWD($$)...)) $88, \
		decltype(XIEITE_DETAIL::at0<89>(XIEITE_FWD($$)...)) $89, \
		decltype(XIEITE_DETAIL::at0<90>(XIEITE_FWD($$)...)) $90, \
		decltype(XIEITE_DETAIL::at0<91>(XIEITE_FWD($$)...)) $91, \
		decltype(XIEITE_DETAIL::at0<92>(XIEITE_FWD($$)...)) $92, \
		decltype(XIEITE_DETAIL::at0<93>(XIEITE_FWD($$)...)) $93, \
		decltype(XIEITE_DETAIL::at0<94>(XIEITE_FWD($$)...)) $94, \
		decltype(XIEITE_DETAIL::at0<95>(XIEITE_FWD($$)...)) $95, \
		decltype(XIEITE_DETAIL::at0<96>(XIEITE_FWD($$)...)) $96, \
		decltype(XIEITE_DETAIL::at0<97>(XIEITE_FWD($$)...)) $97, \
		decltype(XIEITE_DETAIL::at0<98>(XIEITE_FWD($$)...)) $98, \
		decltype(XIEITE_DETAIL::at0<99>(XIEITE_FWD($$)...)) $99, \
		decltype(XIEITE_DETAIL::at0<100>(XIEITE_FWD($$)...)) $100, \
		decltype(XIEITE_DETAIL::at0<101>(XIEITE_FWD($$)...)) $101, \
		decltype(XIEITE_DETAIL::at0<102>(XIEITE_FWD($$)...)) $102, \
		decltype(XIEITE_DETAIL::at0<103>(XIEITE_FWD($$)...)) $103, \
		decltype(XIEITE_DETAIL::at0<104>(XIEITE_FWD($$)...)) $104, \
		decltype(XIEITE_DETAIL::at0<105>(XIEITE_FWD($$)...)) $105, \
		decltype(XIEITE_DETAIL::at0<106>(XIEITE_FWD($$)...)) $106, \
		decltype(XIEITE_DETAIL::at0<107>(XIEITE_FWD($$)...)) $107, \
		decltype(XIEITE_DETAIL::at0<108>(XIEITE_FWD($$)...)) $108, \
		decltype(XIEITE_DETAIL::at0<109>(XIEITE_FWD($$)...)) $109, \
		decltype(XIEITE_DETAIL::at0<110>(XIEITE_FWD($$)...)) $110, \
		decltype(XIEITE_DETAIL::at0<111>(XIEITE_FWD($$)...)) $111, \
		decltype(XIEITE_DETAIL::at0<112>(XIEITE_FWD($$)...)) $112, \
		decltype(XIEITE_DETAIL::at0<113>(XIEITE_FWD($$)...)) $113, \
		decltype(XIEITE_DETAIL::at0<114>(XIEITE_FWD($$)...)) $114, \
		decltype(XIEITE_DETAIL::at0<115>(XIEITE_FWD($$)...)) $115, \
		decltype(XIEITE_DETAIL::at0<116>(XIEITE_FWD($$)...)) $116, \
		decltype(XIEITE_DETAIL::at0<117>(XIEITE_FWD($$)...)) $117, \
		decltype(XIEITE_DETAIL::at0<118>(XIEITE_FWD($$)...)) $118, \
		decltype(XIEITE_DETAIL::at0<119>(XIEITE_FWD($$)...)) $119, \
		decltype(XIEITE_DETAIL::at0<120>(XIEITE_FWD($$)...)) $120, \
		decltype(XIEITE_DETAIL::at0<121>(XIEITE_FWD($$)...)) $121, \
		decltype(XIEITE_DETAIL::at0<122>(XIEITE_FWD($$)...)) $122, \
		decltype(XIEITE_DETAIL::at0<123>(XIEITE_FWD($$)...)) $123, \
		decltype(XIEITE_DETAIL::at0<124>(XIEITE_FWD($$)...)) $124, \
		decltype(XIEITE_DETAIL::at0<125>(XIEITE_FWD($$)...)) $125, \
		decltype(XIEITE_DETAIL::at0<126>(XIEITE_FWD($$)...)) $126, \
		decltype(XIEITE_DETAIL::at0<127>(XIEITE_FWD($$)...)) $127, \
		decltype(XIEITE_DETAIL::at0<128>(XIEITE_FWD($$)...)) $128, \
		decltype(XIEITE_DETAIL::at0<129>(XIEITE_FWD($$)...)) $129, \
		decltype(XIEITE_DETAIL::at0<130>(XIEITE_FWD($$)...)) $130, \
		decltype(XIEITE_DETAIL::at0<131>(XIEITE_FWD($$)...)) $131, \
		decltype(XIEITE_DETAIL::at0<132>(XIEITE_FWD($$)...)) $132, \
		decltype(XIEITE_DETAIL::at0<133>(XIEITE_FWD($$)...)) $133, \
		decltype(XIEITE_DETAIL::at0<134>(XIEITE_FWD($$)...)) $134, \
		decltype(XIEITE_DETAIL::at0<135>(XIEITE_FWD($$)...)) $135, \
		decltype(XIEITE_DETAIL::at0<136>(XIEITE_FWD($$)...)) $136, \
		decltype(XIEITE_DETAIL::at0<137>(XIEITE_FWD($$)...)) $137, \
		decltype(XIEITE_DETAIL::at0<138>(XIEITE_FWD($$)...)) $138, \
		decltype(XIEITE_DETAIL::at0<139>(XIEITE_FWD($$)...)) $139, \
		decltype(XIEITE_DETAIL::at0<140>(XIEITE_FWD($$)...)) $140, \
		decltype(XIEITE_DETAIL::at0<141>(XIEITE_FWD($$)...)) $141, \
		decltype(XIEITE_DETAIL::at0<142>(XIEITE_FWD($$)...)) $142, \
		decltype(XIEITE_DETAIL::at0<143>(XIEITE_FWD($$)...)) $143, \
		decltype(XIEITE_DETAIL::at0<144>(XIEITE_FWD($$)...)) $144, \
		decltype(XIEITE_DETAIL::at0<145>(XIEITE_FWD($$)...)) $145, \
		decltype(XIEITE_DETAIL::at0<146>(XIEITE_FWD($$)...)) $146, \
		decltype(XIEITE_DETAIL::at0<147>(XIEITE_FWD($$)...)) $147, \
		decltype(XIEITE_DETAIL::at0<148>(XIEITE_FWD($$)...)) $148, \
		decltype(XIEITE_DETAIL::at0<149>(XIEITE_FWD($$)...)) $149, \
		decltype(XIEITE_DETAIL::at0<150>(XIEITE_FWD($$)...)) $150, \
		decltype(XIEITE_DETAIL::at0<151>(XIEITE_FWD($$)...)) $151, \
		decltype(XIEITE_DETAIL::at0<152>(XIEITE_FWD($$)...)) $152, \
		decltype(XIEITE_DETAIL::at0<153>(XIEITE_FWD($$)...)) $153, \
		decltype(XIEITE_DETAIL::at0<154>(XIEITE_FWD($$)...)) $154, \
		decltype(XIEITE_DETAIL::at0<155>(XIEITE_FWD($$)...)) $155, \
		decltype(XIEITE_DETAIL::at0<156>(XIEITE_FWD($$)...)) $156, \
		decltype(XIEITE_DETAIL::at0<157>(XIEITE_FWD($$)...)) $157, \
		decltype(XIEITE_DETAIL::at0<158>(XIEITE_FWD($$)...)) $158, \
		decltype(XIEITE_DETAIL::at0<159>(XIEITE_FWD($$)...)) $159, \
		decltype(XIEITE_DETAIL::at0<160>(XIEITE_FWD($$)...)) $160, \
		decltype(XIEITE_DETAIL::at0<161>(XIEITE_FWD($$)...)) $161, \
		decltype(XIEITE_DETAIL::at0<162>(XIEITE_FWD($$)...)) $162, \
		decltype(XIEITE_DETAIL::at0<163>(XIEITE_FWD($$)...)) $163, \
		decltype(XIEITE_DETAIL::at0<164>(XIEITE_FWD($$)...)) $164, \
		decltype(XIEITE_DETAIL::at0<165>(XIEITE_FWD($$)...)) $165, \
		decltype(XIEITE_DETAIL::at0<166>(XIEITE_FWD($$)...)) $166, \
		decltype(XIEITE_DETAIL::at0<167>(XIEITE_FWD($$)...)) $167, \
		decltype(XIEITE_DETAIL::at0<168>(XIEITE_FWD($$)...)) $168, \
		decltype(XIEITE_DETAIL::at0<169>(XIEITE_FWD($$)...)) $169, \
		decltype(XIEITE_DETAIL::at0<170>(XIEITE_FWD($$)...)) $170, \
		decltype(XIEITE_DETAIL::at0<171>(XIEITE_FWD($$)...)) $171, \
		decltype(XIEITE_DETAIL::at0<172>(XIEITE_FWD($$)...)) $172, \
		decltype(XIEITE_DETAIL::at0<173>(XIEITE_FWD($$)...)) $173, \
		decltype(XIEITE_DETAIL::at0<174>(XIEITE_FWD($$)...)) $174, \
		decltype(XIEITE_DETAIL::at0<175>(XIEITE_FWD($$)...)) $175, \
		decltype(XIEITE_DETAIL::at0<176>(XIEITE_FWD($$)...)) $176, \
		decltype(XIEITE_DETAIL::at0<177>(XIEITE_FWD($$)...)) $177, \
		decltype(XIEITE_DETAIL::at0<178>(XIEITE_FWD($$)...)) $178, \
		decltype(XIEITE_DETAIL::at0<179>(XIEITE_FWD($$)...)) $179, \
		decltype(XIEITE_DETAIL::at0<180>(XIEITE_FWD($$)...)) $180, \
		decltype(XIEITE_DETAIL::at0<181>(XIEITE_FWD($$)...)) $181, \
		decltype(XIEITE_DETAIL::at0<182>(XIEITE_FWD($$)...)) $182, \
		decltype(XIEITE_DETAIL::at0<183>(XIEITE_FWD($$)...)) $183, \
		decltype(XIEITE_DETAIL::at0<184>(XIEITE_FWD($$)...)) $184, \
		decltype(XIEITE_DETAIL::at0<185>(XIEITE_FWD($$)...)) $185, \
		decltype(XIEITE_DETAIL::at0<186>(XIEITE_FWD($$)...)) $186, \
		decltype(XIEITE_DETAIL::at0<187>(XIEITE_FWD($$)...)) $187, \
		decltype(XIEITE_DETAIL::at0<188>(XIEITE_FWD($$)...)) $188, \
		decltype(XIEITE_DETAIL::at0<189>(XIEITE_FWD($$)...)) $189, \
		decltype(XIEITE_DETAIL::at0<190>(XIEITE_FWD($$)...)) $190, \
		decltype(XIEITE_DETAIL::at0<191>(XIEITE_FWD($$)...)) $191, \
		decltype(XIEITE_DETAIL::at0<192>(XIEITE_FWD($$)...)) $192, \
		decltype(XIEITE_DETAIL::at0<193>(XIEITE_FWD($$)...)) $193, \
		decltype(XIEITE_DETAIL::at0<194>(XIEITE_FWD($$)...)) $194, \
		decltype(XIEITE_DETAIL::at0<195>(XIEITE_FWD($$)...)) $195, \
		decltype(XIEITE_DETAIL::at0<196>(XIEITE_FWD($$)...)) $196, \
		decltype(XIEITE_DETAIL::at0<197>(XIEITE_FWD($$)...)) $197, \
		decltype(XIEITE_DETAIL::at0<198>(XIEITE_FWD($$)...)) $198, \
		decltype(XIEITE_DETAIL::at0<199>(XIEITE_FWD($$)...)) $199, \
		decltype(XIEITE_DETAIL::at0<200>(XIEITE_FWD($$)...)) $200, \
		decltype(XIEITE_DETAIL::at0<201>(XIEITE_FWD($$)...)) $201, \
		decltype(XIEITE_DETAIL::at0<202>(XIEITE_FWD($$)...)) $202, \
		decltype(XIEITE_DETAIL::at0<203>(XIEITE_FWD($$)...)) $203, \
		decltype(XIEITE_DETAIL::at0<204>(XIEITE_FWD($$)...)) $204, \
		decltype(XIEITE_DETAIL::at0<205>(XIEITE_FWD($$)...)) $205, \
		decltype(XIEITE_DETAIL::at0<206>(XIEITE_FWD($$)...)) $206, \
		decltype(XIEITE_DETAIL::at0<207>(XIEITE_FWD($$)...)) $207, \
		decltype(XIEITE_DETAIL::at0<208>(XIEITE_FWD($$)...)) $208, \
		decltype(XIEITE_DETAIL::at0<209>(XIEITE_FWD($$)...)) $209, \
		decltype(XIEITE_DETAIL::at0<210>(XIEITE_FWD($$)...)) $210, \
		decltype(XIEITE_DETAIL::at0<211>(XIEITE_FWD($$)...)) $211, \
		decltype(XIEITE_DETAIL::at0<212>(XIEITE_FWD($$)...)) $212, \
		decltype(XIEITE_DETAIL::at0<213>(XIEITE_FWD($$)...)) $213, \
		decltype(XIEITE_DETAIL::at0<214>(XIEITE_FWD($$)...)) $214, \
		decltype(XIEITE_DETAIL::at0<215>(XIEITE_FWD($$)...)) $215, \
		decltype(XIEITE_DETAIL::at0<216>(XIEITE_FWD($$)...)) $216, \
		decltype(XIEITE_DETAIL::at0<217>(XIEITE_FWD($$)...)) $217, \
		decltype(XIEITE_DETAIL::at0<218>(XIEITE_FWD($$)...)) $218, \
		decltype(XIEITE_DETAIL::at0<219>(XIEITE_FWD($$)...)) $219, \
		decltype(XIEITE_DETAIL::at0<220>(XIEITE_FWD($$)...)) $220, \
		decltype(XIEITE_DETAIL::at0<221>(XIEITE_FWD($$)...)) $221, \
		decltype(XIEITE_DETAIL::at0<222>(XIEITE_FWD($$)...)) $222, \
		decltype(XIEITE_DETAIL::at0<223>(XIEITE_FWD($$)...)) $223, \
		decltype(XIEITE_DETAIL::at0<224>(XIEITE_FWD($$)...)) $224, \
		decltype(XIEITE_DETAIL::at0<225>(XIEITE_FWD($$)...)) $225, \
		decltype(XIEITE_DETAIL::at0<226>(XIEITE_FWD($$)...)) $226, \
		decltype(XIEITE_DETAIL::at0<227>(XIEITE_FWD($$)...)) $227, \
		decltype(XIEITE_DETAIL::at0<228>(XIEITE_FWD($$)...)) $228, \
		decltype(XIEITE_DETAIL::at0<229>(XIEITE_FWD($$)...)) $229, \
		decltype(XIEITE_DETAIL::at0<230>(XIEITE_FWD($$)...)) $230, \
		decltype(XIEITE_DETAIL::at0<231>(XIEITE_FWD($$)...)) $231, \
		decltype(XIEITE_DETAIL::at0<232>(XIEITE_FWD($$)...)) $232, \
		decltype(XIEITE_DETAIL::at0<233>(XIEITE_FWD($$)...)) $233, \
		decltype(XIEITE_DETAIL::at0<234>(XIEITE_FWD($$)...)) $234, \
		decltype(XIEITE_DETAIL::at0<235>(XIEITE_FWD($$)...)) $235, \
		decltype(XIEITE_DETAIL::at0<236>(XIEITE_FWD($$)...)) $236, \
		decltype(XIEITE_DETAIL::at0<237>(XIEITE_FWD($$)...)) $237, \
		decltype(XIEITE_DETAIL::at0<238>(XIEITE_FWD($$)...)) $238, \
		decltype(XIEITE_DETAIL::at0<239>(XIEITE_FWD($$)...)) $239, \
		decltype(XIEITE_DETAIL::at0<240>(XIEITE_FWD($$)...)) $240, \
		decltype(XIEITE_DETAIL::at0<241>(XIEITE_FWD($$)...)) $241, \
		decltype(XIEITE_DETAIL::at0<242>(XIEITE_FWD($$)...)) $242, \
		decltype(XIEITE_DETAIL::at0<243>(XIEITE_FWD($$)...)) $243, \
		decltype(XIEITE_DETAIL::at0<244>(XIEITE_FWD($$)...)) $244, \
		decltype(XIEITE_DETAIL::at0<245>(XIEITE_FWD($$)...)) $245, \
		decltype(XIEITE_DETAIL::at0<246>(XIEITE_FWD($$)...)) $246, \
		decltype(XIEITE_DETAIL::at0<247>(XIEITE_FWD($$)...)) $247, \
		decltype(XIEITE_DETAIL::at0<248>(XIEITE_FWD($$)...)) $248, \
		decltype(XIEITE_DETAIL::at0<249>(XIEITE_FWD($$)...)) $249, \
		decltype(XIEITE_DETAIL::at0<250>(XIEITE_FWD($$)...)) $250, \
		decltype(XIEITE_DETAIL::at0<251>(XIEITE_FWD($$)...)) $251, \
		decltype(XIEITE_DETAIL::at0<252>(XIEITE_FWD($$)...)) $252, \
		decltype(XIEITE_DETAIL::at0<253>(XIEITE_FWD($$)...)) $253, \
		decltype(XIEITE_DETAIL::at0<254>(XIEITE_FWD($$)...)) $254, \
		decltype(XIEITE_DETAIL::at0<255>(XIEITE_FWD($$)...)) $255, \
		decltype(XIEITE_DETAIL::at0<256>(XIEITE_FWD($$)...)) $256 \
	) { (__VA_ARGS__); }) { \
		[[maybe_unused]] auto&& $0 = XIEITE_DETAIL::at0<0>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $1 = XIEITE_DETAIL::at0<1>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $2 = XIEITE_DETAIL::at0<2>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $3 = XIEITE_DETAIL::at0<3>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $4 = XIEITE_DETAIL::at0<4>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $5 = XIEITE_DETAIL::at0<5>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $6 = XIEITE_DETAIL::at0<6>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $7 = XIEITE_DETAIL::at0<7>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $8 = XIEITE_DETAIL::at0<8>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $9 = XIEITE_DETAIL::at0<9>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $10 = XIEITE_DETAIL::at0<10>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $11 = XIEITE_DETAIL::at0<11>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $12 = XIEITE_DETAIL::at0<12>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $13 = XIEITE_DETAIL::at0<13>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $14 = XIEITE_DETAIL::at0<14>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $15 = XIEITE_DETAIL::at0<15>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $16 = XIEITE_DETAIL::at0<16>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $17 = XIEITE_DETAIL::at0<17>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $18 = XIEITE_DETAIL::at0<18>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $19 = XIEITE_DETAIL::at0<19>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $20 = XIEITE_DETAIL::at0<20>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $21 = XIEITE_DETAIL::at0<21>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $22 = XIEITE_DETAIL::at0<22>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $23 = XIEITE_DETAIL::at0<23>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $24 = XIEITE_DETAIL::at0<24>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $25 = XIEITE_DETAIL::at0<25>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $26 = XIEITE_DETAIL::at0<26>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $27 = XIEITE_DETAIL::at0<27>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $28 = XIEITE_DETAIL::at0<28>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $29 = XIEITE_DETAIL::at0<29>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $30 = XIEITE_DETAIL::at0<30>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $31 = XIEITE_DETAIL::at0<31>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $32 = XIEITE_DETAIL::at0<32>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $33 = XIEITE_DETAIL::at0<33>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $34 = XIEITE_DETAIL::at0<34>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $35 = XIEITE_DETAIL::at0<35>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $36 = XIEITE_DETAIL::at0<36>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $37 = XIEITE_DETAIL::at0<37>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $38 = XIEITE_DETAIL::at0<38>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $39 = XIEITE_DETAIL::at0<39>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $40 = XIEITE_DETAIL::at0<40>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $41 = XIEITE_DETAIL::at0<41>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $42 = XIEITE_DETAIL::at0<42>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $43 = XIEITE_DETAIL::at0<43>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $44 = XIEITE_DETAIL::at0<44>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $45 = XIEITE_DETAIL::at0<45>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $46 = XIEITE_DETAIL::at0<46>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $47 = XIEITE_DETAIL::at0<47>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $48 = XIEITE_DETAIL::at0<48>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $49 = XIEITE_DETAIL::at0<49>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $50 = XIEITE_DETAIL::at0<50>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $51 = XIEITE_DETAIL::at0<51>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $52 = XIEITE_DETAIL::at0<52>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $53 = XIEITE_DETAIL::at0<53>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $54 = XIEITE_DETAIL::at0<54>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $55 = XIEITE_DETAIL::at0<55>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $56 = XIEITE_DETAIL::at0<56>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $57 = XIEITE_DETAIL::at0<57>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $58 = XIEITE_DETAIL::at0<58>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $59 = XIEITE_DETAIL::at0<59>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $60 = XIEITE_DETAIL::at0<60>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $61 = XIEITE_DETAIL::at0<61>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $62 = XIEITE_DETAIL::at0<62>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $63 = XIEITE_DETAIL::at0<63>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $64 = XIEITE_DETAIL::at0<64>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $65 = XIEITE_DETAIL::at0<65>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $66 = XIEITE_DETAIL::at0<66>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $67 = XIEITE_DETAIL::at0<67>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $68 = XIEITE_DETAIL::at0<68>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $69 = XIEITE_DETAIL::at0<69>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $70 = XIEITE_DETAIL::at0<70>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $71 = XIEITE_DETAIL::at0<71>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $72 = XIEITE_DETAIL::at0<72>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $73 = XIEITE_DETAIL::at0<73>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $74 = XIEITE_DETAIL::at0<74>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $75 = XIEITE_DETAIL::at0<75>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $76 = XIEITE_DETAIL::at0<76>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $77 = XIEITE_DETAIL::at0<77>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $78 = XIEITE_DETAIL::at0<78>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $79 = XIEITE_DETAIL::at0<79>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $80 = XIEITE_DETAIL::at0<80>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $81 = XIEITE_DETAIL::at0<81>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $82 = XIEITE_DETAIL::at0<82>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $83 = XIEITE_DETAIL::at0<83>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $84 = XIEITE_DETAIL::at0<84>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $85 = XIEITE_DETAIL::at0<85>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $86 = XIEITE_DETAIL::at0<86>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $87 = XIEITE_DETAIL::at0<87>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $88 = XIEITE_DETAIL::at0<88>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $89 = XIEITE_DETAIL::at0<89>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $90 = XIEITE_DETAIL::at0<90>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $91 = XIEITE_DETAIL::at0<91>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $92 = XIEITE_DETAIL::at0<92>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $93 = XIEITE_DETAIL::at0<93>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $94 = XIEITE_DETAIL::at0<94>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $95 = XIEITE_DETAIL::at0<95>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $96 = XIEITE_DETAIL::at0<96>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $97 = XIEITE_DETAIL::at0<97>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $98 = XIEITE_DETAIL::at0<98>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $99 = XIEITE_DETAIL::at0<99>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $100 = XIEITE_DETAIL::at0<100>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $101 = XIEITE_DETAIL::at0<101>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $102 = XIEITE_DETAIL::at0<102>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $103 = XIEITE_DETAIL::at0<103>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $104 = XIEITE_DETAIL::at0<104>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $105 = XIEITE_DETAIL::at0<105>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $106 = XIEITE_DETAIL::at0<106>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $107 = XIEITE_DETAIL::at0<107>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $108 = XIEITE_DETAIL::at0<108>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $109 = XIEITE_DETAIL::at0<109>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $110 = XIEITE_DETAIL::at0<110>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $111 = XIEITE_DETAIL::at0<111>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $112 = XIEITE_DETAIL::at0<112>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $113 = XIEITE_DETAIL::at0<113>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $114 = XIEITE_DETAIL::at0<114>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $115 = XIEITE_DETAIL::at0<115>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $116 = XIEITE_DETAIL::at0<116>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $117 = XIEITE_DETAIL::at0<117>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $118 = XIEITE_DETAIL::at0<118>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $119 = XIEITE_DETAIL::at0<119>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $120 = XIEITE_DETAIL::at0<120>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $121 = XIEITE_DETAIL::at0<121>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $122 = XIEITE_DETAIL::at0<122>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $123 = XIEITE_DETAIL::at0<123>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $124 = XIEITE_DETAIL::at0<124>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $125 = XIEITE_DETAIL::at0<125>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $126 = XIEITE_DETAIL::at0<126>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $127 = XIEITE_DETAIL::at0<127>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $128 = XIEITE_DETAIL::at0<128>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $129 = XIEITE_DETAIL::at0<129>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $130 = XIEITE_DETAIL::at0<130>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $131 = XIEITE_DETAIL::at0<131>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $132 = XIEITE_DETAIL::at0<132>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $133 = XIEITE_DETAIL::at0<133>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $134 = XIEITE_DETAIL::at0<134>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $135 = XIEITE_DETAIL::at0<135>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $136 = XIEITE_DETAIL::at0<136>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $137 = XIEITE_DETAIL::at0<137>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $138 = XIEITE_DETAIL::at0<138>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $139 = XIEITE_DETAIL::at0<139>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $140 = XIEITE_DETAIL::at0<140>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $141 = XIEITE_DETAIL::at0<141>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $142 = XIEITE_DETAIL::at0<142>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $143 = XIEITE_DETAIL::at0<143>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $144 = XIEITE_DETAIL::at0<144>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $145 = XIEITE_DETAIL::at0<145>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $146 = XIEITE_DETAIL::at0<146>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $147 = XIEITE_DETAIL::at0<147>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $148 = XIEITE_DETAIL::at0<148>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $149 = XIEITE_DETAIL::at0<149>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $150 = XIEITE_DETAIL::at0<150>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $151 = XIEITE_DETAIL::at0<151>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $152 = XIEITE_DETAIL::at0<152>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $153 = XIEITE_DETAIL::at0<153>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $154 = XIEITE_DETAIL::at0<154>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $155 = XIEITE_DETAIL::at0<155>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $156 = XIEITE_DETAIL::at0<156>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $157 = XIEITE_DETAIL::at0<157>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $158 = XIEITE_DETAIL::at0<158>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $159 = XIEITE_DETAIL::at0<159>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $160 = XIEITE_DETAIL::at0<160>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $161 = XIEITE_DETAIL::at0<161>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $162 = XIEITE_DETAIL::at0<162>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $163 = XIEITE_DETAIL::at0<163>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $164 = XIEITE_DETAIL::at0<164>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $165 = XIEITE_DETAIL::at0<165>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $166 = XIEITE_DETAIL::at0<166>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $167 = XIEITE_DETAIL::at0<167>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $168 = XIEITE_DETAIL::at0<168>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $169 = XIEITE_DETAIL::at0<169>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $170 = XIEITE_DETAIL::at0<170>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $171 = XIEITE_DETAIL::at0<171>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $172 = XIEITE_DETAIL::at0<172>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $173 = XIEITE_DETAIL::at0<173>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $174 = XIEITE_DETAIL::at0<174>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $175 = XIEITE_DETAIL::at0<175>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $176 = XIEITE_DETAIL::at0<176>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $177 = XIEITE_DETAIL::at0<177>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $178 = XIEITE_DETAIL::at0<178>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $179 = XIEITE_DETAIL::at0<179>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $180 = XIEITE_DETAIL::at0<180>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $181 = XIEITE_DETAIL::at0<181>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $182 = XIEITE_DETAIL::at0<182>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $183 = XIEITE_DETAIL::at0<183>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $184 = XIEITE_DETAIL::at0<184>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $185 = XIEITE_DETAIL::at0<185>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $186 = XIEITE_DETAIL::at0<186>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $187 = XIEITE_DETAIL::at0<187>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $188 = XIEITE_DETAIL::at0<188>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $189 = XIEITE_DETAIL::at0<189>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $190 = XIEITE_DETAIL::at0<190>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $191 = XIEITE_DETAIL::at0<191>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $192 = XIEITE_DETAIL::at0<192>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $193 = XIEITE_DETAIL::at0<193>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $194 = XIEITE_DETAIL::at0<194>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $195 = XIEITE_DETAIL::at0<195>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $196 = XIEITE_DETAIL::at0<196>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $197 = XIEITE_DETAIL::at0<197>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $198 = XIEITE_DETAIL::at0<198>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $199 = XIEITE_DETAIL::at0<199>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $200 = XIEITE_DETAIL::at0<200>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $201 = XIEITE_DETAIL::at0<201>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $202 = XIEITE_DETAIL::at0<202>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $203 = XIEITE_DETAIL::at0<203>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $204 = XIEITE_DETAIL::at0<204>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $205 = XIEITE_DETAIL::at0<205>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $206 = XIEITE_DETAIL::at0<206>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $207 = XIEITE_DETAIL::at0<207>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $208 = XIEITE_DETAIL::at0<208>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $209 = XIEITE_DETAIL::at0<209>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $210 = XIEITE_DETAIL::at0<210>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $211 = XIEITE_DETAIL::at0<211>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $212 = XIEITE_DETAIL::at0<212>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $213 = XIEITE_DETAIL::at0<213>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $214 = XIEITE_DETAIL::at0<214>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $215 = XIEITE_DETAIL::at0<215>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $216 = XIEITE_DETAIL::at0<216>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $217 = XIEITE_DETAIL::at0<217>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $218 = XIEITE_DETAIL::at0<218>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $219 = XIEITE_DETAIL::at0<219>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $220 = XIEITE_DETAIL::at0<220>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $221 = XIEITE_DETAIL::at0<221>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $222 = XIEITE_DETAIL::at0<222>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $223 = XIEITE_DETAIL::at0<223>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $224 = XIEITE_DETAIL::at0<224>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $225 = XIEITE_DETAIL::at0<225>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $226 = XIEITE_DETAIL::at0<226>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $227 = XIEITE_DETAIL::at0<227>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $228 = XIEITE_DETAIL::at0<228>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $229 = XIEITE_DETAIL::at0<229>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $230 = XIEITE_DETAIL::at0<230>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $231 = XIEITE_DETAIL::at0<231>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $232 = XIEITE_DETAIL::at0<232>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $233 = XIEITE_DETAIL::at0<233>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $234 = XIEITE_DETAIL::at0<234>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $235 = XIEITE_DETAIL::at0<235>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $236 = XIEITE_DETAIL::at0<236>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $237 = XIEITE_DETAIL::at0<237>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $238 = XIEITE_DETAIL::at0<238>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $239 = XIEITE_DETAIL::at0<239>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $240 = XIEITE_DETAIL::at0<240>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $241 = XIEITE_DETAIL::at0<241>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $242 = XIEITE_DETAIL::at0<242>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $243 = XIEITE_DETAIL::at0<243>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $244 = XIEITE_DETAIL::at0<244>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $245 = XIEITE_DETAIL::at0<245>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $246 = XIEITE_DETAIL::at0<246>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $247 = XIEITE_DETAIL::at0<247>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $248 = XIEITE_DETAIL::at0<248>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $249 = XIEITE_DETAIL::at0<249>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $250 = XIEITE_DETAIL::at0<250>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $251 = XIEITE_DETAIL::at0<251>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $252 = XIEITE_DETAIL::at0<252>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $253 = XIEITE_DETAIL::at0<253>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $254 = XIEITE_DETAIL::at0<254>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $255 = XIEITE_DETAIL::at0<255>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $256 = XIEITE_DETAIL::at0<256>(XIEITE_FWD($$)...); \
		return (__VA_ARGS__); \
	}

// What did you expect?

namespace XIEITE_DETAIL {
	// Template parameter must be named here due to GCC bug
	// https://gcc.gnu.org/bugzilla/show_bug.cgi?id=117422
	template<std::size_t idx> // <--
	constexpr auto&& at0(auto&&...) noexcept;

	struct unusable {
		template<std::size_t idx>
		[[nodiscard]] friend constexpr auto&& at0(auto&&... args) noexcept {
			if constexpr (idx < sizeof...(args)) {
				return std::get<idx>(std::forward_as_tuple(XIEITE_FWD(args)...));
			} else {
				static constexpr XIEITE_DETAIL::unusable unusable;
				return unusable;
			}
		}

	private:
		unusable() = default;
	};

	template<std::size_t idx, typename... Ts>
	using at1 = decltype(([] {
		if constexpr (idx < sizeof...(Ts)) {
			return std::tuple_element_t<idx, std::tuple<std::type_identity<Ts>...>>();
		} else {
			return std::type_identity<XIEITE_DETAIL::unusable>();
		}
	})())::type;
}
