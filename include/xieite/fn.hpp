#pragma once

#include <cstddef>
#include <tuple>
#include <xieite/diag.hpp>
#include <xieite/fwd.hpp>

#define XIEITE_FN(...) XIEITE_DETAIL_FN(, __VA_ARGS__)
#define XIEITE_FN_LOCAL(...) XIEITE_DETAIL_FN(&, __VA_ARGS__)

XIEITE_DIAG_OFF_CLANG(-Wdollar-in-identifier-extension)

#define XIEITE_DETAIL_FN(capture, ...) \
	[capture][[nodiscard]](auto&&... $$) \
	noexcept(requires( \
		decltype(XIEITE_DETAIL::at<0>(XIEITE_FWD($$)...)) $0, \
		decltype(XIEITE_DETAIL::at<1>(XIEITE_FWD($$)...)) $1, \
		decltype(XIEITE_DETAIL::at<2>(XIEITE_FWD($$)...)) $2, \
		decltype(XIEITE_DETAIL::at<3>(XIEITE_FWD($$)...)) $3, \
		decltype(XIEITE_DETAIL::at<4>(XIEITE_FWD($$)...)) $4, \
		decltype(XIEITE_DETAIL::at<5>(XIEITE_FWD($$)...)) $5, \
		decltype(XIEITE_DETAIL::at<6>(XIEITE_FWD($$)...)) $6, \
		decltype(XIEITE_DETAIL::at<7>(XIEITE_FWD($$)...)) $7, \
		decltype(XIEITE_DETAIL::at<8>(XIEITE_FWD($$)...)) $8, \
		decltype(XIEITE_DETAIL::at<9>(XIEITE_FWD($$)...)) $9, \
		decltype(XIEITE_DETAIL::at<10>(XIEITE_FWD($$)...)) $10, \
		decltype(XIEITE_DETAIL::at<11>(XIEITE_FWD($$)...)) $11, \
		decltype(XIEITE_DETAIL::at<12>(XIEITE_FWD($$)...)) $12, \
		decltype(XIEITE_DETAIL::at<13>(XIEITE_FWD($$)...)) $13, \
		decltype(XIEITE_DETAIL::at<14>(XIEITE_FWD($$)...)) $14, \
		decltype(XIEITE_DETAIL::at<15>(XIEITE_FWD($$)...)) $15, \
		decltype(XIEITE_DETAIL::at<16>(XIEITE_FWD($$)...)) $16, \
		decltype(XIEITE_DETAIL::at<17>(XIEITE_FWD($$)...)) $17, \
		decltype(XIEITE_DETAIL::at<18>(XIEITE_FWD($$)...)) $18, \
		decltype(XIEITE_DETAIL::at<19>(XIEITE_FWD($$)...)) $19, \
		decltype(XIEITE_DETAIL::at<20>(XIEITE_FWD($$)...)) $20, \
		decltype(XIEITE_DETAIL::at<21>(XIEITE_FWD($$)...)) $21, \
		decltype(XIEITE_DETAIL::at<22>(XIEITE_FWD($$)...)) $22, \
		decltype(XIEITE_DETAIL::at<23>(XIEITE_FWD($$)...)) $23, \
		decltype(XIEITE_DETAIL::at<24>(XIEITE_FWD($$)...)) $24, \
		decltype(XIEITE_DETAIL::at<25>(XIEITE_FWD($$)...)) $25, \
		decltype(XIEITE_DETAIL::at<26>(XIEITE_FWD($$)...)) $26, \
		decltype(XIEITE_DETAIL::at<27>(XIEITE_FWD($$)...)) $27, \
		decltype(XIEITE_DETAIL::at<28>(XIEITE_FWD($$)...)) $28, \
		decltype(XIEITE_DETAIL::at<29>(XIEITE_FWD($$)...)) $29, \
		decltype(XIEITE_DETAIL::at<30>(XIEITE_FWD($$)...)) $30, \
		decltype(XIEITE_DETAIL::at<31>(XIEITE_FWD($$)...)) $31, \
		decltype(XIEITE_DETAIL::at<32>(XIEITE_FWD($$)...)) $32, \
		decltype(XIEITE_DETAIL::at<33>(XIEITE_FWD($$)...)) $33, \
		decltype(XIEITE_DETAIL::at<34>(XIEITE_FWD($$)...)) $34, \
		decltype(XIEITE_DETAIL::at<35>(XIEITE_FWD($$)...)) $35, \
		decltype(XIEITE_DETAIL::at<36>(XIEITE_FWD($$)...)) $36, \
		decltype(XIEITE_DETAIL::at<37>(XIEITE_FWD($$)...)) $37, \
		decltype(XIEITE_DETAIL::at<38>(XIEITE_FWD($$)...)) $38, \
		decltype(XIEITE_DETAIL::at<39>(XIEITE_FWD($$)...)) $39, \
		decltype(XIEITE_DETAIL::at<40>(XIEITE_FWD($$)...)) $40, \
		decltype(XIEITE_DETAIL::at<41>(XIEITE_FWD($$)...)) $41, \
		decltype(XIEITE_DETAIL::at<42>(XIEITE_FWD($$)...)) $42, \
		decltype(XIEITE_DETAIL::at<43>(XIEITE_FWD($$)...)) $43, \
		decltype(XIEITE_DETAIL::at<44>(XIEITE_FWD($$)...)) $44, \
		decltype(XIEITE_DETAIL::at<45>(XIEITE_FWD($$)...)) $45, \
		decltype(XIEITE_DETAIL::at<46>(XIEITE_FWD($$)...)) $46, \
		decltype(XIEITE_DETAIL::at<47>(XIEITE_FWD($$)...)) $47, \
		decltype(XIEITE_DETAIL::at<48>(XIEITE_FWD($$)...)) $48, \
		decltype(XIEITE_DETAIL::at<49>(XIEITE_FWD($$)...)) $49, \
		decltype(XIEITE_DETAIL::at<50>(XIEITE_FWD($$)...)) $50, \
		decltype(XIEITE_DETAIL::at<51>(XIEITE_FWD($$)...)) $51, \
		decltype(XIEITE_DETAIL::at<52>(XIEITE_FWD($$)...)) $52, \
		decltype(XIEITE_DETAIL::at<53>(XIEITE_FWD($$)...)) $53, \
		decltype(XIEITE_DETAIL::at<54>(XIEITE_FWD($$)...)) $54, \
		decltype(XIEITE_DETAIL::at<55>(XIEITE_FWD($$)...)) $55, \
		decltype(XIEITE_DETAIL::at<56>(XIEITE_FWD($$)...)) $56, \
		decltype(XIEITE_DETAIL::at<57>(XIEITE_FWD($$)...)) $57, \
		decltype(XIEITE_DETAIL::at<58>(XIEITE_FWD($$)...)) $58, \
		decltype(XIEITE_DETAIL::at<59>(XIEITE_FWD($$)...)) $59, \
		decltype(XIEITE_DETAIL::at<60>(XIEITE_FWD($$)...)) $60, \
		decltype(XIEITE_DETAIL::at<61>(XIEITE_FWD($$)...)) $61, \
		decltype(XIEITE_DETAIL::at<62>(XIEITE_FWD($$)...)) $62, \
		decltype(XIEITE_DETAIL::at<63>(XIEITE_FWD($$)...)) $63, \
		decltype(XIEITE_DETAIL::at<64>(XIEITE_FWD($$)...)) $64, \
		decltype(XIEITE_DETAIL::at<65>(XIEITE_FWD($$)...)) $65, \
		decltype(XIEITE_DETAIL::at<66>(XIEITE_FWD($$)...)) $66, \
		decltype(XIEITE_DETAIL::at<67>(XIEITE_FWD($$)...)) $67, \
		decltype(XIEITE_DETAIL::at<68>(XIEITE_FWD($$)...)) $68, \
		decltype(XIEITE_DETAIL::at<69>(XIEITE_FWD($$)...)) $69, \
		decltype(XIEITE_DETAIL::at<70>(XIEITE_FWD($$)...)) $70, \
		decltype(XIEITE_DETAIL::at<71>(XIEITE_FWD($$)...)) $71, \
		decltype(XIEITE_DETAIL::at<72>(XIEITE_FWD($$)...)) $72, \
		decltype(XIEITE_DETAIL::at<73>(XIEITE_FWD($$)...)) $73, \
		decltype(XIEITE_DETAIL::at<74>(XIEITE_FWD($$)...)) $74, \
		decltype(XIEITE_DETAIL::at<75>(XIEITE_FWD($$)...)) $75, \
		decltype(XIEITE_DETAIL::at<76>(XIEITE_FWD($$)...)) $76, \
		decltype(XIEITE_DETAIL::at<77>(XIEITE_FWD($$)...)) $77, \
		decltype(XIEITE_DETAIL::at<78>(XIEITE_FWD($$)...)) $78, \
		decltype(XIEITE_DETAIL::at<79>(XIEITE_FWD($$)...)) $79, \
		decltype(XIEITE_DETAIL::at<80>(XIEITE_FWD($$)...)) $80, \
		decltype(XIEITE_DETAIL::at<81>(XIEITE_FWD($$)...)) $81, \
		decltype(XIEITE_DETAIL::at<82>(XIEITE_FWD($$)...)) $82, \
		decltype(XIEITE_DETAIL::at<83>(XIEITE_FWD($$)...)) $83, \
		decltype(XIEITE_DETAIL::at<84>(XIEITE_FWD($$)...)) $84, \
		decltype(XIEITE_DETAIL::at<85>(XIEITE_FWD($$)...)) $85, \
		decltype(XIEITE_DETAIL::at<86>(XIEITE_FWD($$)...)) $86, \
		decltype(XIEITE_DETAIL::at<87>(XIEITE_FWD($$)...)) $87, \
		decltype(XIEITE_DETAIL::at<88>(XIEITE_FWD($$)...)) $88, \
		decltype(XIEITE_DETAIL::at<89>(XIEITE_FWD($$)...)) $89, \
		decltype(XIEITE_DETAIL::at<90>(XIEITE_FWD($$)...)) $90, \
		decltype(XIEITE_DETAIL::at<91>(XIEITE_FWD($$)...)) $91, \
		decltype(XIEITE_DETAIL::at<92>(XIEITE_FWD($$)...)) $92, \
		decltype(XIEITE_DETAIL::at<93>(XIEITE_FWD($$)...)) $93, \
		decltype(XIEITE_DETAIL::at<94>(XIEITE_FWD($$)...)) $94, \
		decltype(XIEITE_DETAIL::at<95>(XIEITE_FWD($$)...)) $95, \
		decltype(XIEITE_DETAIL::at<96>(XIEITE_FWD($$)...)) $96, \
		decltype(XIEITE_DETAIL::at<97>(XIEITE_FWD($$)...)) $97, \
		decltype(XIEITE_DETAIL::at<98>(XIEITE_FWD($$)...)) $98, \
		decltype(XIEITE_DETAIL::at<99>(XIEITE_FWD($$)...)) $99, \
		decltype(XIEITE_DETAIL::at<100>(XIEITE_FWD($$)...)) $100, \
		decltype(XIEITE_DETAIL::at<101>(XIEITE_FWD($$)...)) $101, \
		decltype(XIEITE_DETAIL::at<102>(XIEITE_FWD($$)...)) $102, \
		decltype(XIEITE_DETAIL::at<103>(XIEITE_FWD($$)...)) $103, \
		decltype(XIEITE_DETAIL::at<104>(XIEITE_FWD($$)...)) $104, \
		decltype(XIEITE_DETAIL::at<105>(XIEITE_FWD($$)...)) $105, \
		decltype(XIEITE_DETAIL::at<106>(XIEITE_FWD($$)...)) $106, \
		decltype(XIEITE_DETAIL::at<107>(XIEITE_FWD($$)...)) $107, \
		decltype(XIEITE_DETAIL::at<108>(XIEITE_FWD($$)...)) $108, \
		decltype(XIEITE_DETAIL::at<109>(XIEITE_FWD($$)...)) $109, \
		decltype(XIEITE_DETAIL::at<110>(XIEITE_FWD($$)...)) $110, \
		decltype(XIEITE_DETAIL::at<111>(XIEITE_FWD($$)...)) $111, \
		decltype(XIEITE_DETAIL::at<112>(XIEITE_FWD($$)...)) $112, \
		decltype(XIEITE_DETAIL::at<113>(XIEITE_FWD($$)...)) $113, \
		decltype(XIEITE_DETAIL::at<114>(XIEITE_FWD($$)...)) $114, \
		decltype(XIEITE_DETAIL::at<115>(XIEITE_FWD($$)...)) $115, \
		decltype(XIEITE_DETAIL::at<116>(XIEITE_FWD($$)...)) $116, \
		decltype(XIEITE_DETAIL::at<117>(XIEITE_FWD($$)...)) $117, \
		decltype(XIEITE_DETAIL::at<118>(XIEITE_FWD($$)...)) $118, \
		decltype(XIEITE_DETAIL::at<119>(XIEITE_FWD($$)...)) $119, \
		decltype(XIEITE_DETAIL::at<120>(XIEITE_FWD($$)...)) $120, \
		decltype(XIEITE_DETAIL::at<121>(XIEITE_FWD($$)...)) $121, \
		decltype(XIEITE_DETAIL::at<122>(XIEITE_FWD($$)...)) $122, \
		decltype(XIEITE_DETAIL::at<123>(XIEITE_FWD($$)...)) $123, \
		decltype(XIEITE_DETAIL::at<124>(XIEITE_FWD($$)...)) $124, \
		decltype(XIEITE_DETAIL::at<125>(XIEITE_FWD($$)...)) $125, \
		decltype(XIEITE_DETAIL::at<126>(XIEITE_FWD($$)...)) $126, \
		decltype(XIEITE_DETAIL::at<127>(XIEITE_FWD($$)...)) $127, \
		decltype(XIEITE_DETAIL::at<128>(XIEITE_FWD($$)...)) $128, \
		decltype(XIEITE_DETAIL::at<129>(XIEITE_FWD($$)...)) $129, \
		decltype(XIEITE_DETAIL::at<130>(XIEITE_FWD($$)...)) $130, \
		decltype(XIEITE_DETAIL::at<131>(XIEITE_FWD($$)...)) $131, \
		decltype(XIEITE_DETAIL::at<132>(XIEITE_FWD($$)...)) $132, \
		decltype(XIEITE_DETAIL::at<133>(XIEITE_FWD($$)...)) $133, \
		decltype(XIEITE_DETAIL::at<134>(XIEITE_FWD($$)...)) $134, \
		decltype(XIEITE_DETAIL::at<135>(XIEITE_FWD($$)...)) $135, \
		decltype(XIEITE_DETAIL::at<136>(XIEITE_FWD($$)...)) $136, \
		decltype(XIEITE_DETAIL::at<137>(XIEITE_FWD($$)...)) $137, \
		decltype(XIEITE_DETAIL::at<138>(XIEITE_FWD($$)...)) $138, \
		decltype(XIEITE_DETAIL::at<139>(XIEITE_FWD($$)...)) $139, \
		decltype(XIEITE_DETAIL::at<140>(XIEITE_FWD($$)...)) $140, \
		decltype(XIEITE_DETAIL::at<141>(XIEITE_FWD($$)...)) $141, \
		decltype(XIEITE_DETAIL::at<142>(XIEITE_FWD($$)...)) $142, \
		decltype(XIEITE_DETAIL::at<143>(XIEITE_FWD($$)...)) $143, \
		decltype(XIEITE_DETAIL::at<144>(XIEITE_FWD($$)...)) $144, \
		decltype(XIEITE_DETAIL::at<145>(XIEITE_FWD($$)...)) $145, \
		decltype(XIEITE_DETAIL::at<146>(XIEITE_FWD($$)...)) $146, \
		decltype(XIEITE_DETAIL::at<147>(XIEITE_FWD($$)...)) $147, \
		decltype(XIEITE_DETAIL::at<148>(XIEITE_FWD($$)...)) $148, \
		decltype(XIEITE_DETAIL::at<149>(XIEITE_FWD($$)...)) $149, \
		decltype(XIEITE_DETAIL::at<150>(XIEITE_FWD($$)...)) $150, \
		decltype(XIEITE_DETAIL::at<151>(XIEITE_FWD($$)...)) $151, \
		decltype(XIEITE_DETAIL::at<152>(XIEITE_FWD($$)...)) $152, \
		decltype(XIEITE_DETAIL::at<153>(XIEITE_FWD($$)...)) $153, \
		decltype(XIEITE_DETAIL::at<154>(XIEITE_FWD($$)...)) $154, \
		decltype(XIEITE_DETAIL::at<155>(XIEITE_FWD($$)...)) $155, \
		decltype(XIEITE_DETAIL::at<156>(XIEITE_FWD($$)...)) $156, \
		decltype(XIEITE_DETAIL::at<157>(XIEITE_FWD($$)...)) $157, \
		decltype(XIEITE_DETAIL::at<158>(XIEITE_FWD($$)...)) $158, \
		decltype(XIEITE_DETAIL::at<159>(XIEITE_FWD($$)...)) $159, \
		decltype(XIEITE_DETAIL::at<160>(XIEITE_FWD($$)...)) $160, \
		decltype(XIEITE_DETAIL::at<161>(XIEITE_FWD($$)...)) $161, \
		decltype(XIEITE_DETAIL::at<162>(XIEITE_FWD($$)...)) $162, \
		decltype(XIEITE_DETAIL::at<163>(XIEITE_FWD($$)...)) $163, \
		decltype(XIEITE_DETAIL::at<164>(XIEITE_FWD($$)...)) $164, \
		decltype(XIEITE_DETAIL::at<165>(XIEITE_FWD($$)...)) $165, \
		decltype(XIEITE_DETAIL::at<166>(XIEITE_FWD($$)...)) $166, \
		decltype(XIEITE_DETAIL::at<167>(XIEITE_FWD($$)...)) $167, \
		decltype(XIEITE_DETAIL::at<168>(XIEITE_FWD($$)...)) $168, \
		decltype(XIEITE_DETAIL::at<169>(XIEITE_FWD($$)...)) $169, \
		decltype(XIEITE_DETAIL::at<170>(XIEITE_FWD($$)...)) $170, \
		decltype(XIEITE_DETAIL::at<171>(XIEITE_FWD($$)...)) $171, \
		decltype(XIEITE_DETAIL::at<172>(XIEITE_FWD($$)...)) $172, \
		decltype(XIEITE_DETAIL::at<173>(XIEITE_FWD($$)...)) $173, \
		decltype(XIEITE_DETAIL::at<174>(XIEITE_FWD($$)...)) $174, \
		decltype(XIEITE_DETAIL::at<175>(XIEITE_FWD($$)...)) $175, \
		decltype(XIEITE_DETAIL::at<176>(XIEITE_FWD($$)...)) $176, \
		decltype(XIEITE_DETAIL::at<177>(XIEITE_FWD($$)...)) $177, \
		decltype(XIEITE_DETAIL::at<178>(XIEITE_FWD($$)...)) $178, \
		decltype(XIEITE_DETAIL::at<179>(XIEITE_FWD($$)...)) $179, \
		decltype(XIEITE_DETAIL::at<180>(XIEITE_FWD($$)...)) $180, \
		decltype(XIEITE_DETAIL::at<181>(XIEITE_FWD($$)...)) $181, \
		decltype(XIEITE_DETAIL::at<182>(XIEITE_FWD($$)...)) $182, \
		decltype(XIEITE_DETAIL::at<183>(XIEITE_FWD($$)...)) $183, \
		decltype(XIEITE_DETAIL::at<184>(XIEITE_FWD($$)...)) $184, \
		decltype(XIEITE_DETAIL::at<185>(XIEITE_FWD($$)...)) $185, \
		decltype(XIEITE_DETAIL::at<186>(XIEITE_FWD($$)...)) $186, \
		decltype(XIEITE_DETAIL::at<187>(XIEITE_FWD($$)...)) $187, \
		decltype(XIEITE_DETAIL::at<188>(XIEITE_FWD($$)...)) $188, \
		decltype(XIEITE_DETAIL::at<189>(XIEITE_FWD($$)...)) $189, \
		decltype(XIEITE_DETAIL::at<190>(XIEITE_FWD($$)...)) $190, \
		decltype(XIEITE_DETAIL::at<191>(XIEITE_FWD($$)...)) $191, \
		decltype(XIEITE_DETAIL::at<192>(XIEITE_FWD($$)...)) $192, \
		decltype(XIEITE_DETAIL::at<193>(XIEITE_FWD($$)...)) $193, \
		decltype(XIEITE_DETAIL::at<194>(XIEITE_FWD($$)...)) $194, \
		decltype(XIEITE_DETAIL::at<195>(XIEITE_FWD($$)...)) $195, \
		decltype(XIEITE_DETAIL::at<196>(XIEITE_FWD($$)...)) $196, \
		decltype(XIEITE_DETAIL::at<197>(XIEITE_FWD($$)...)) $197, \
		decltype(XIEITE_DETAIL::at<198>(XIEITE_FWD($$)...)) $198, \
		decltype(XIEITE_DETAIL::at<199>(XIEITE_FWD($$)...)) $199, \
		decltype(XIEITE_DETAIL::at<200>(XIEITE_FWD($$)...)) $200, \
		decltype(XIEITE_DETAIL::at<201>(XIEITE_FWD($$)...)) $201, \
		decltype(XIEITE_DETAIL::at<202>(XIEITE_FWD($$)...)) $202, \
		decltype(XIEITE_DETAIL::at<203>(XIEITE_FWD($$)...)) $203, \
		decltype(XIEITE_DETAIL::at<204>(XIEITE_FWD($$)...)) $204, \
		decltype(XIEITE_DETAIL::at<205>(XIEITE_FWD($$)...)) $205, \
		decltype(XIEITE_DETAIL::at<206>(XIEITE_FWD($$)...)) $206, \
		decltype(XIEITE_DETAIL::at<207>(XIEITE_FWD($$)...)) $207, \
		decltype(XIEITE_DETAIL::at<208>(XIEITE_FWD($$)...)) $208, \
		decltype(XIEITE_DETAIL::at<209>(XIEITE_FWD($$)...)) $209, \
		decltype(XIEITE_DETAIL::at<210>(XIEITE_FWD($$)...)) $210, \
		decltype(XIEITE_DETAIL::at<211>(XIEITE_FWD($$)...)) $211, \
		decltype(XIEITE_DETAIL::at<212>(XIEITE_FWD($$)...)) $212, \
		decltype(XIEITE_DETAIL::at<213>(XIEITE_FWD($$)...)) $213, \
		decltype(XIEITE_DETAIL::at<214>(XIEITE_FWD($$)...)) $214, \
		decltype(XIEITE_DETAIL::at<215>(XIEITE_FWD($$)...)) $215, \
		decltype(XIEITE_DETAIL::at<216>(XIEITE_FWD($$)...)) $216, \
		decltype(XIEITE_DETAIL::at<217>(XIEITE_FWD($$)...)) $217, \
		decltype(XIEITE_DETAIL::at<218>(XIEITE_FWD($$)...)) $218, \
		decltype(XIEITE_DETAIL::at<219>(XIEITE_FWD($$)...)) $219, \
		decltype(XIEITE_DETAIL::at<220>(XIEITE_FWD($$)...)) $220, \
		decltype(XIEITE_DETAIL::at<221>(XIEITE_FWD($$)...)) $221, \
		decltype(XIEITE_DETAIL::at<222>(XIEITE_FWD($$)...)) $222, \
		decltype(XIEITE_DETAIL::at<223>(XIEITE_FWD($$)...)) $223, \
		decltype(XIEITE_DETAIL::at<224>(XIEITE_FWD($$)...)) $224, \
		decltype(XIEITE_DETAIL::at<225>(XIEITE_FWD($$)...)) $225, \
		decltype(XIEITE_DETAIL::at<226>(XIEITE_FWD($$)...)) $226, \
		decltype(XIEITE_DETAIL::at<227>(XIEITE_FWD($$)...)) $227, \
		decltype(XIEITE_DETAIL::at<228>(XIEITE_FWD($$)...)) $228, \
		decltype(XIEITE_DETAIL::at<229>(XIEITE_FWD($$)...)) $229, \
		decltype(XIEITE_DETAIL::at<230>(XIEITE_FWD($$)...)) $230, \
		decltype(XIEITE_DETAIL::at<231>(XIEITE_FWD($$)...)) $231, \
		decltype(XIEITE_DETAIL::at<232>(XIEITE_FWD($$)...)) $232, \
		decltype(XIEITE_DETAIL::at<233>(XIEITE_FWD($$)...)) $233, \
		decltype(XIEITE_DETAIL::at<234>(XIEITE_FWD($$)...)) $234, \
		decltype(XIEITE_DETAIL::at<235>(XIEITE_FWD($$)...)) $235, \
		decltype(XIEITE_DETAIL::at<236>(XIEITE_FWD($$)...)) $236, \
		decltype(XIEITE_DETAIL::at<237>(XIEITE_FWD($$)...)) $237, \
		decltype(XIEITE_DETAIL::at<238>(XIEITE_FWD($$)...)) $238, \
		decltype(XIEITE_DETAIL::at<239>(XIEITE_FWD($$)...)) $239, \
		decltype(XIEITE_DETAIL::at<240>(XIEITE_FWD($$)...)) $240, \
		decltype(XIEITE_DETAIL::at<241>(XIEITE_FWD($$)...)) $241, \
		decltype(XIEITE_DETAIL::at<242>(XIEITE_FWD($$)...)) $242, \
		decltype(XIEITE_DETAIL::at<243>(XIEITE_FWD($$)...)) $243, \
		decltype(XIEITE_DETAIL::at<244>(XIEITE_FWD($$)...)) $244, \
		decltype(XIEITE_DETAIL::at<245>(XIEITE_FWD($$)...)) $245, \
		decltype(XIEITE_DETAIL::at<246>(XIEITE_FWD($$)...)) $246, \
		decltype(XIEITE_DETAIL::at<247>(XIEITE_FWD($$)...)) $247, \
		decltype(XIEITE_DETAIL::at<248>(XIEITE_FWD($$)...)) $248, \
		decltype(XIEITE_DETAIL::at<249>(XIEITE_FWD($$)...)) $249, \
		decltype(XIEITE_DETAIL::at<250>(XIEITE_FWD($$)...)) $250, \
		decltype(XIEITE_DETAIL::at<251>(XIEITE_FWD($$)...)) $251, \
		decltype(XIEITE_DETAIL::at<252>(XIEITE_FWD($$)...)) $252, \
		decltype(XIEITE_DETAIL::at<253>(XIEITE_FWD($$)...)) $253, \
		decltype(XIEITE_DETAIL::at<254>(XIEITE_FWD($$)...)) $254, \
		decltype(XIEITE_DETAIL::at<255>(XIEITE_FWD($$)...)) $255, \
		decltype(XIEITE_DETAIL::at<256>(XIEITE_FWD($$)...)) $256 \
	) { requires(noexcept(__VA_ARGS__)); }) \
	-> decltype(auto) \
	requires(requires( \
		decltype(XIEITE_DETAIL::at<0>(XIEITE_FWD($$)...)) $0, \
		decltype(XIEITE_DETAIL::at<1>(XIEITE_FWD($$)...)) $1, \
		decltype(XIEITE_DETAIL::at<2>(XIEITE_FWD($$)...)) $2, \
		decltype(XIEITE_DETAIL::at<3>(XIEITE_FWD($$)...)) $3, \
		decltype(XIEITE_DETAIL::at<4>(XIEITE_FWD($$)...)) $4, \
		decltype(XIEITE_DETAIL::at<5>(XIEITE_FWD($$)...)) $5, \
		decltype(XIEITE_DETAIL::at<6>(XIEITE_FWD($$)...)) $6, \
		decltype(XIEITE_DETAIL::at<7>(XIEITE_FWD($$)...)) $7, \
		decltype(XIEITE_DETAIL::at<8>(XIEITE_FWD($$)...)) $8, \
		decltype(XIEITE_DETAIL::at<9>(XIEITE_FWD($$)...)) $9, \
		decltype(XIEITE_DETAIL::at<10>(XIEITE_FWD($$)...)) $10, \
		decltype(XIEITE_DETAIL::at<11>(XIEITE_FWD($$)...)) $11, \
		decltype(XIEITE_DETAIL::at<12>(XIEITE_FWD($$)...)) $12, \
		decltype(XIEITE_DETAIL::at<13>(XIEITE_FWD($$)...)) $13, \
		decltype(XIEITE_DETAIL::at<14>(XIEITE_FWD($$)...)) $14, \
		decltype(XIEITE_DETAIL::at<15>(XIEITE_FWD($$)...)) $15, \
		decltype(XIEITE_DETAIL::at<16>(XIEITE_FWD($$)...)) $16, \
		decltype(XIEITE_DETAIL::at<17>(XIEITE_FWD($$)...)) $17, \
		decltype(XIEITE_DETAIL::at<18>(XIEITE_FWD($$)...)) $18, \
		decltype(XIEITE_DETAIL::at<19>(XIEITE_FWD($$)...)) $19, \
		decltype(XIEITE_DETAIL::at<20>(XIEITE_FWD($$)...)) $20, \
		decltype(XIEITE_DETAIL::at<21>(XIEITE_FWD($$)...)) $21, \
		decltype(XIEITE_DETAIL::at<22>(XIEITE_FWD($$)...)) $22, \
		decltype(XIEITE_DETAIL::at<23>(XIEITE_FWD($$)...)) $23, \
		decltype(XIEITE_DETAIL::at<24>(XIEITE_FWD($$)...)) $24, \
		decltype(XIEITE_DETAIL::at<25>(XIEITE_FWD($$)...)) $25, \
		decltype(XIEITE_DETAIL::at<26>(XIEITE_FWD($$)...)) $26, \
		decltype(XIEITE_DETAIL::at<27>(XIEITE_FWD($$)...)) $27, \
		decltype(XIEITE_DETAIL::at<28>(XIEITE_FWD($$)...)) $28, \
		decltype(XIEITE_DETAIL::at<29>(XIEITE_FWD($$)...)) $29, \
		decltype(XIEITE_DETAIL::at<30>(XIEITE_FWD($$)...)) $30, \
		decltype(XIEITE_DETAIL::at<31>(XIEITE_FWD($$)...)) $31, \
		decltype(XIEITE_DETAIL::at<32>(XIEITE_FWD($$)...)) $32, \
		decltype(XIEITE_DETAIL::at<33>(XIEITE_FWD($$)...)) $33, \
		decltype(XIEITE_DETAIL::at<34>(XIEITE_FWD($$)...)) $34, \
		decltype(XIEITE_DETAIL::at<35>(XIEITE_FWD($$)...)) $35, \
		decltype(XIEITE_DETAIL::at<36>(XIEITE_FWD($$)...)) $36, \
		decltype(XIEITE_DETAIL::at<37>(XIEITE_FWD($$)...)) $37, \
		decltype(XIEITE_DETAIL::at<38>(XIEITE_FWD($$)...)) $38, \
		decltype(XIEITE_DETAIL::at<39>(XIEITE_FWD($$)...)) $39, \
		decltype(XIEITE_DETAIL::at<40>(XIEITE_FWD($$)...)) $40, \
		decltype(XIEITE_DETAIL::at<41>(XIEITE_FWD($$)...)) $41, \
		decltype(XIEITE_DETAIL::at<42>(XIEITE_FWD($$)...)) $42, \
		decltype(XIEITE_DETAIL::at<43>(XIEITE_FWD($$)...)) $43, \
		decltype(XIEITE_DETAIL::at<44>(XIEITE_FWD($$)...)) $44, \
		decltype(XIEITE_DETAIL::at<45>(XIEITE_FWD($$)...)) $45, \
		decltype(XIEITE_DETAIL::at<46>(XIEITE_FWD($$)...)) $46, \
		decltype(XIEITE_DETAIL::at<47>(XIEITE_FWD($$)...)) $47, \
		decltype(XIEITE_DETAIL::at<48>(XIEITE_FWD($$)...)) $48, \
		decltype(XIEITE_DETAIL::at<49>(XIEITE_FWD($$)...)) $49, \
		decltype(XIEITE_DETAIL::at<50>(XIEITE_FWD($$)...)) $50, \
		decltype(XIEITE_DETAIL::at<51>(XIEITE_FWD($$)...)) $51, \
		decltype(XIEITE_DETAIL::at<52>(XIEITE_FWD($$)...)) $52, \
		decltype(XIEITE_DETAIL::at<53>(XIEITE_FWD($$)...)) $53, \
		decltype(XIEITE_DETAIL::at<54>(XIEITE_FWD($$)...)) $54, \
		decltype(XIEITE_DETAIL::at<55>(XIEITE_FWD($$)...)) $55, \
		decltype(XIEITE_DETAIL::at<56>(XIEITE_FWD($$)...)) $56, \
		decltype(XIEITE_DETAIL::at<57>(XIEITE_FWD($$)...)) $57, \
		decltype(XIEITE_DETAIL::at<58>(XIEITE_FWD($$)...)) $58, \
		decltype(XIEITE_DETAIL::at<59>(XIEITE_FWD($$)...)) $59, \
		decltype(XIEITE_DETAIL::at<60>(XIEITE_FWD($$)...)) $60, \
		decltype(XIEITE_DETAIL::at<61>(XIEITE_FWD($$)...)) $61, \
		decltype(XIEITE_DETAIL::at<62>(XIEITE_FWD($$)...)) $62, \
		decltype(XIEITE_DETAIL::at<63>(XIEITE_FWD($$)...)) $63, \
		decltype(XIEITE_DETAIL::at<64>(XIEITE_FWD($$)...)) $64, \
		decltype(XIEITE_DETAIL::at<65>(XIEITE_FWD($$)...)) $65, \
		decltype(XIEITE_DETAIL::at<66>(XIEITE_FWD($$)...)) $66, \
		decltype(XIEITE_DETAIL::at<67>(XIEITE_FWD($$)...)) $67, \
		decltype(XIEITE_DETAIL::at<68>(XIEITE_FWD($$)...)) $68, \
		decltype(XIEITE_DETAIL::at<69>(XIEITE_FWD($$)...)) $69, \
		decltype(XIEITE_DETAIL::at<70>(XIEITE_FWD($$)...)) $70, \
		decltype(XIEITE_DETAIL::at<71>(XIEITE_FWD($$)...)) $71, \
		decltype(XIEITE_DETAIL::at<72>(XIEITE_FWD($$)...)) $72, \
		decltype(XIEITE_DETAIL::at<73>(XIEITE_FWD($$)...)) $73, \
		decltype(XIEITE_DETAIL::at<74>(XIEITE_FWD($$)...)) $74, \
		decltype(XIEITE_DETAIL::at<75>(XIEITE_FWD($$)...)) $75, \
		decltype(XIEITE_DETAIL::at<76>(XIEITE_FWD($$)...)) $76, \
		decltype(XIEITE_DETAIL::at<77>(XIEITE_FWD($$)...)) $77, \
		decltype(XIEITE_DETAIL::at<78>(XIEITE_FWD($$)...)) $78, \
		decltype(XIEITE_DETAIL::at<79>(XIEITE_FWD($$)...)) $79, \
		decltype(XIEITE_DETAIL::at<80>(XIEITE_FWD($$)...)) $80, \
		decltype(XIEITE_DETAIL::at<81>(XIEITE_FWD($$)...)) $81, \
		decltype(XIEITE_DETAIL::at<82>(XIEITE_FWD($$)...)) $82, \
		decltype(XIEITE_DETAIL::at<83>(XIEITE_FWD($$)...)) $83, \
		decltype(XIEITE_DETAIL::at<84>(XIEITE_FWD($$)...)) $84, \
		decltype(XIEITE_DETAIL::at<85>(XIEITE_FWD($$)...)) $85, \
		decltype(XIEITE_DETAIL::at<86>(XIEITE_FWD($$)...)) $86, \
		decltype(XIEITE_DETAIL::at<87>(XIEITE_FWD($$)...)) $87, \
		decltype(XIEITE_DETAIL::at<88>(XIEITE_FWD($$)...)) $88, \
		decltype(XIEITE_DETAIL::at<89>(XIEITE_FWD($$)...)) $89, \
		decltype(XIEITE_DETAIL::at<90>(XIEITE_FWD($$)...)) $90, \
		decltype(XIEITE_DETAIL::at<91>(XIEITE_FWD($$)...)) $91, \
		decltype(XIEITE_DETAIL::at<92>(XIEITE_FWD($$)...)) $92, \
		decltype(XIEITE_DETAIL::at<93>(XIEITE_FWD($$)...)) $93, \
		decltype(XIEITE_DETAIL::at<94>(XIEITE_FWD($$)...)) $94, \
		decltype(XIEITE_DETAIL::at<95>(XIEITE_FWD($$)...)) $95, \
		decltype(XIEITE_DETAIL::at<96>(XIEITE_FWD($$)...)) $96, \
		decltype(XIEITE_DETAIL::at<97>(XIEITE_FWD($$)...)) $97, \
		decltype(XIEITE_DETAIL::at<98>(XIEITE_FWD($$)...)) $98, \
		decltype(XIEITE_DETAIL::at<99>(XIEITE_FWD($$)...)) $99, \
		decltype(XIEITE_DETAIL::at<100>(XIEITE_FWD($$)...)) $100, \
		decltype(XIEITE_DETAIL::at<101>(XIEITE_FWD($$)...)) $101, \
		decltype(XIEITE_DETAIL::at<102>(XIEITE_FWD($$)...)) $102, \
		decltype(XIEITE_DETAIL::at<103>(XIEITE_FWD($$)...)) $103, \
		decltype(XIEITE_DETAIL::at<104>(XIEITE_FWD($$)...)) $104, \
		decltype(XIEITE_DETAIL::at<105>(XIEITE_FWD($$)...)) $105, \
		decltype(XIEITE_DETAIL::at<106>(XIEITE_FWD($$)...)) $106, \
		decltype(XIEITE_DETAIL::at<107>(XIEITE_FWD($$)...)) $107, \
		decltype(XIEITE_DETAIL::at<108>(XIEITE_FWD($$)...)) $108, \
		decltype(XIEITE_DETAIL::at<109>(XIEITE_FWD($$)...)) $109, \
		decltype(XIEITE_DETAIL::at<110>(XIEITE_FWD($$)...)) $110, \
		decltype(XIEITE_DETAIL::at<111>(XIEITE_FWD($$)...)) $111, \
		decltype(XIEITE_DETAIL::at<112>(XIEITE_FWD($$)...)) $112, \
		decltype(XIEITE_DETAIL::at<113>(XIEITE_FWD($$)...)) $113, \
		decltype(XIEITE_DETAIL::at<114>(XIEITE_FWD($$)...)) $114, \
		decltype(XIEITE_DETAIL::at<115>(XIEITE_FWD($$)...)) $115, \
		decltype(XIEITE_DETAIL::at<116>(XIEITE_FWD($$)...)) $116, \
		decltype(XIEITE_DETAIL::at<117>(XIEITE_FWD($$)...)) $117, \
		decltype(XIEITE_DETAIL::at<118>(XIEITE_FWD($$)...)) $118, \
		decltype(XIEITE_DETAIL::at<119>(XIEITE_FWD($$)...)) $119, \
		decltype(XIEITE_DETAIL::at<120>(XIEITE_FWD($$)...)) $120, \
		decltype(XIEITE_DETAIL::at<121>(XIEITE_FWD($$)...)) $121, \
		decltype(XIEITE_DETAIL::at<122>(XIEITE_FWD($$)...)) $122, \
		decltype(XIEITE_DETAIL::at<123>(XIEITE_FWD($$)...)) $123, \
		decltype(XIEITE_DETAIL::at<124>(XIEITE_FWD($$)...)) $124, \
		decltype(XIEITE_DETAIL::at<125>(XIEITE_FWD($$)...)) $125, \
		decltype(XIEITE_DETAIL::at<126>(XIEITE_FWD($$)...)) $126, \
		decltype(XIEITE_DETAIL::at<127>(XIEITE_FWD($$)...)) $127, \
		decltype(XIEITE_DETAIL::at<128>(XIEITE_FWD($$)...)) $128, \
		decltype(XIEITE_DETAIL::at<129>(XIEITE_FWD($$)...)) $129, \
		decltype(XIEITE_DETAIL::at<130>(XIEITE_FWD($$)...)) $130, \
		decltype(XIEITE_DETAIL::at<131>(XIEITE_FWD($$)...)) $131, \
		decltype(XIEITE_DETAIL::at<132>(XIEITE_FWD($$)...)) $132, \
		decltype(XIEITE_DETAIL::at<133>(XIEITE_FWD($$)...)) $133, \
		decltype(XIEITE_DETAIL::at<134>(XIEITE_FWD($$)...)) $134, \
		decltype(XIEITE_DETAIL::at<135>(XIEITE_FWD($$)...)) $135, \
		decltype(XIEITE_DETAIL::at<136>(XIEITE_FWD($$)...)) $136, \
		decltype(XIEITE_DETAIL::at<137>(XIEITE_FWD($$)...)) $137, \
		decltype(XIEITE_DETAIL::at<138>(XIEITE_FWD($$)...)) $138, \
		decltype(XIEITE_DETAIL::at<139>(XIEITE_FWD($$)...)) $139, \
		decltype(XIEITE_DETAIL::at<140>(XIEITE_FWD($$)...)) $140, \
		decltype(XIEITE_DETAIL::at<141>(XIEITE_FWD($$)...)) $141, \
		decltype(XIEITE_DETAIL::at<142>(XIEITE_FWD($$)...)) $142, \
		decltype(XIEITE_DETAIL::at<143>(XIEITE_FWD($$)...)) $143, \
		decltype(XIEITE_DETAIL::at<144>(XIEITE_FWD($$)...)) $144, \
		decltype(XIEITE_DETAIL::at<145>(XIEITE_FWD($$)...)) $145, \
		decltype(XIEITE_DETAIL::at<146>(XIEITE_FWD($$)...)) $146, \
		decltype(XIEITE_DETAIL::at<147>(XIEITE_FWD($$)...)) $147, \
		decltype(XIEITE_DETAIL::at<148>(XIEITE_FWD($$)...)) $148, \
		decltype(XIEITE_DETAIL::at<149>(XIEITE_FWD($$)...)) $149, \
		decltype(XIEITE_DETAIL::at<150>(XIEITE_FWD($$)...)) $150, \
		decltype(XIEITE_DETAIL::at<151>(XIEITE_FWD($$)...)) $151, \
		decltype(XIEITE_DETAIL::at<152>(XIEITE_FWD($$)...)) $152, \
		decltype(XIEITE_DETAIL::at<153>(XIEITE_FWD($$)...)) $153, \
		decltype(XIEITE_DETAIL::at<154>(XIEITE_FWD($$)...)) $154, \
		decltype(XIEITE_DETAIL::at<155>(XIEITE_FWD($$)...)) $155, \
		decltype(XIEITE_DETAIL::at<156>(XIEITE_FWD($$)...)) $156, \
		decltype(XIEITE_DETAIL::at<157>(XIEITE_FWD($$)...)) $157, \
		decltype(XIEITE_DETAIL::at<158>(XIEITE_FWD($$)...)) $158, \
		decltype(XIEITE_DETAIL::at<159>(XIEITE_FWD($$)...)) $159, \
		decltype(XIEITE_DETAIL::at<160>(XIEITE_FWD($$)...)) $160, \
		decltype(XIEITE_DETAIL::at<161>(XIEITE_FWD($$)...)) $161, \
		decltype(XIEITE_DETAIL::at<162>(XIEITE_FWD($$)...)) $162, \
		decltype(XIEITE_DETAIL::at<163>(XIEITE_FWD($$)...)) $163, \
		decltype(XIEITE_DETAIL::at<164>(XIEITE_FWD($$)...)) $164, \
		decltype(XIEITE_DETAIL::at<165>(XIEITE_FWD($$)...)) $165, \
		decltype(XIEITE_DETAIL::at<166>(XIEITE_FWD($$)...)) $166, \
		decltype(XIEITE_DETAIL::at<167>(XIEITE_FWD($$)...)) $167, \
		decltype(XIEITE_DETAIL::at<168>(XIEITE_FWD($$)...)) $168, \
		decltype(XIEITE_DETAIL::at<169>(XIEITE_FWD($$)...)) $169, \
		decltype(XIEITE_DETAIL::at<170>(XIEITE_FWD($$)...)) $170, \
		decltype(XIEITE_DETAIL::at<171>(XIEITE_FWD($$)...)) $171, \
		decltype(XIEITE_DETAIL::at<172>(XIEITE_FWD($$)...)) $172, \
		decltype(XIEITE_DETAIL::at<173>(XIEITE_FWD($$)...)) $173, \
		decltype(XIEITE_DETAIL::at<174>(XIEITE_FWD($$)...)) $174, \
		decltype(XIEITE_DETAIL::at<175>(XIEITE_FWD($$)...)) $175, \
		decltype(XIEITE_DETAIL::at<176>(XIEITE_FWD($$)...)) $176, \
		decltype(XIEITE_DETAIL::at<177>(XIEITE_FWD($$)...)) $177, \
		decltype(XIEITE_DETAIL::at<178>(XIEITE_FWD($$)...)) $178, \
		decltype(XIEITE_DETAIL::at<179>(XIEITE_FWD($$)...)) $179, \
		decltype(XIEITE_DETAIL::at<180>(XIEITE_FWD($$)...)) $180, \
		decltype(XIEITE_DETAIL::at<181>(XIEITE_FWD($$)...)) $181, \
		decltype(XIEITE_DETAIL::at<182>(XIEITE_FWD($$)...)) $182, \
		decltype(XIEITE_DETAIL::at<183>(XIEITE_FWD($$)...)) $183, \
		decltype(XIEITE_DETAIL::at<184>(XIEITE_FWD($$)...)) $184, \
		decltype(XIEITE_DETAIL::at<185>(XIEITE_FWD($$)...)) $185, \
		decltype(XIEITE_DETAIL::at<186>(XIEITE_FWD($$)...)) $186, \
		decltype(XIEITE_DETAIL::at<187>(XIEITE_FWD($$)...)) $187, \
		decltype(XIEITE_DETAIL::at<188>(XIEITE_FWD($$)...)) $188, \
		decltype(XIEITE_DETAIL::at<189>(XIEITE_FWD($$)...)) $189, \
		decltype(XIEITE_DETAIL::at<190>(XIEITE_FWD($$)...)) $190, \
		decltype(XIEITE_DETAIL::at<191>(XIEITE_FWD($$)...)) $191, \
		decltype(XIEITE_DETAIL::at<192>(XIEITE_FWD($$)...)) $192, \
		decltype(XIEITE_DETAIL::at<193>(XIEITE_FWD($$)...)) $193, \
		decltype(XIEITE_DETAIL::at<194>(XIEITE_FWD($$)...)) $194, \
		decltype(XIEITE_DETAIL::at<195>(XIEITE_FWD($$)...)) $195, \
		decltype(XIEITE_DETAIL::at<196>(XIEITE_FWD($$)...)) $196, \
		decltype(XIEITE_DETAIL::at<197>(XIEITE_FWD($$)...)) $197, \
		decltype(XIEITE_DETAIL::at<198>(XIEITE_FWD($$)...)) $198, \
		decltype(XIEITE_DETAIL::at<199>(XIEITE_FWD($$)...)) $199, \
		decltype(XIEITE_DETAIL::at<200>(XIEITE_FWD($$)...)) $200, \
		decltype(XIEITE_DETAIL::at<201>(XIEITE_FWD($$)...)) $201, \
		decltype(XIEITE_DETAIL::at<202>(XIEITE_FWD($$)...)) $202, \
		decltype(XIEITE_DETAIL::at<203>(XIEITE_FWD($$)...)) $203, \
		decltype(XIEITE_DETAIL::at<204>(XIEITE_FWD($$)...)) $204, \
		decltype(XIEITE_DETAIL::at<205>(XIEITE_FWD($$)...)) $205, \
		decltype(XIEITE_DETAIL::at<206>(XIEITE_FWD($$)...)) $206, \
		decltype(XIEITE_DETAIL::at<207>(XIEITE_FWD($$)...)) $207, \
		decltype(XIEITE_DETAIL::at<208>(XIEITE_FWD($$)...)) $208, \
		decltype(XIEITE_DETAIL::at<209>(XIEITE_FWD($$)...)) $209, \
		decltype(XIEITE_DETAIL::at<210>(XIEITE_FWD($$)...)) $210, \
		decltype(XIEITE_DETAIL::at<211>(XIEITE_FWD($$)...)) $211, \
		decltype(XIEITE_DETAIL::at<212>(XIEITE_FWD($$)...)) $212, \
		decltype(XIEITE_DETAIL::at<213>(XIEITE_FWD($$)...)) $213, \
		decltype(XIEITE_DETAIL::at<214>(XIEITE_FWD($$)...)) $214, \
		decltype(XIEITE_DETAIL::at<215>(XIEITE_FWD($$)...)) $215, \
		decltype(XIEITE_DETAIL::at<216>(XIEITE_FWD($$)...)) $216, \
		decltype(XIEITE_DETAIL::at<217>(XIEITE_FWD($$)...)) $217, \
		decltype(XIEITE_DETAIL::at<218>(XIEITE_FWD($$)...)) $218, \
		decltype(XIEITE_DETAIL::at<219>(XIEITE_FWD($$)...)) $219, \
		decltype(XIEITE_DETAIL::at<220>(XIEITE_FWD($$)...)) $220, \
		decltype(XIEITE_DETAIL::at<221>(XIEITE_FWD($$)...)) $221, \
		decltype(XIEITE_DETAIL::at<222>(XIEITE_FWD($$)...)) $222, \
		decltype(XIEITE_DETAIL::at<223>(XIEITE_FWD($$)...)) $223, \
		decltype(XIEITE_DETAIL::at<224>(XIEITE_FWD($$)...)) $224, \
		decltype(XIEITE_DETAIL::at<225>(XIEITE_FWD($$)...)) $225, \
		decltype(XIEITE_DETAIL::at<226>(XIEITE_FWD($$)...)) $226, \
		decltype(XIEITE_DETAIL::at<227>(XIEITE_FWD($$)...)) $227, \
		decltype(XIEITE_DETAIL::at<228>(XIEITE_FWD($$)...)) $228, \
		decltype(XIEITE_DETAIL::at<229>(XIEITE_FWD($$)...)) $229, \
		decltype(XIEITE_DETAIL::at<230>(XIEITE_FWD($$)...)) $230, \
		decltype(XIEITE_DETAIL::at<231>(XIEITE_FWD($$)...)) $231, \
		decltype(XIEITE_DETAIL::at<232>(XIEITE_FWD($$)...)) $232, \
		decltype(XIEITE_DETAIL::at<233>(XIEITE_FWD($$)...)) $233, \
		decltype(XIEITE_DETAIL::at<234>(XIEITE_FWD($$)...)) $234, \
		decltype(XIEITE_DETAIL::at<235>(XIEITE_FWD($$)...)) $235, \
		decltype(XIEITE_DETAIL::at<236>(XIEITE_FWD($$)...)) $236, \
		decltype(XIEITE_DETAIL::at<237>(XIEITE_FWD($$)...)) $237, \
		decltype(XIEITE_DETAIL::at<238>(XIEITE_FWD($$)...)) $238, \
		decltype(XIEITE_DETAIL::at<239>(XIEITE_FWD($$)...)) $239, \
		decltype(XIEITE_DETAIL::at<240>(XIEITE_FWD($$)...)) $240, \
		decltype(XIEITE_DETAIL::at<241>(XIEITE_FWD($$)...)) $241, \
		decltype(XIEITE_DETAIL::at<242>(XIEITE_FWD($$)...)) $242, \
		decltype(XIEITE_DETAIL::at<243>(XIEITE_FWD($$)...)) $243, \
		decltype(XIEITE_DETAIL::at<244>(XIEITE_FWD($$)...)) $244, \
		decltype(XIEITE_DETAIL::at<245>(XIEITE_FWD($$)...)) $245, \
		decltype(XIEITE_DETAIL::at<246>(XIEITE_FWD($$)...)) $246, \
		decltype(XIEITE_DETAIL::at<247>(XIEITE_FWD($$)...)) $247, \
		decltype(XIEITE_DETAIL::at<248>(XIEITE_FWD($$)...)) $248, \
		decltype(XIEITE_DETAIL::at<249>(XIEITE_FWD($$)...)) $249, \
		decltype(XIEITE_DETAIL::at<250>(XIEITE_FWD($$)...)) $250, \
		decltype(XIEITE_DETAIL::at<251>(XIEITE_FWD($$)...)) $251, \
		decltype(XIEITE_DETAIL::at<252>(XIEITE_FWD($$)...)) $252, \
		decltype(XIEITE_DETAIL::at<253>(XIEITE_FWD($$)...)) $253, \
		decltype(XIEITE_DETAIL::at<254>(XIEITE_FWD($$)...)) $254, \
		decltype(XIEITE_DETAIL::at<255>(XIEITE_FWD($$)...)) $255, \
		decltype(XIEITE_DETAIL::at<256>(XIEITE_FWD($$)...)) $256 \
	) { (__VA_ARGS__); }) { \
		[[maybe_unused]] auto&& $0 = XIEITE_DETAIL::at<0>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $1 = XIEITE_DETAIL::at<1>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $2 = XIEITE_DETAIL::at<2>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $3 = XIEITE_DETAIL::at<3>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $4 = XIEITE_DETAIL::at<4>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $5 = XIEITE_DETAIL::at<5>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $6 = XIEITE_DETAIL::at<6>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $7 = XIEITE_DETAIL::at<7>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $8 = XIEITE_DETAIL::at<8>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $9 = XIEITE_DETAIL::at<9>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $10 = XIEITE_DETAIL::at<10>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $11 = XIEITE_DETAIL::at<11>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $12 = XIEITE_DETAIL::at<12>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $13 = XIEITE_DETAIL::at<13>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $14 = XIEITE_DETAIL::at<14>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $15 = XIEITE_DETAIL::at<15>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $16 = XIEITE_DETAIL::at<16>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $17 = XIEITE_DETAIL::at<17>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $18 = XIEITE_DETAIL::at<18>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $19 = XIEITE_DETAIL::at<19>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $20 = XIEITE_DETAIL::at<20>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $21 = XIEITE_DETAIL::at<21>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $22 = XIEITE_DETAIL::at<22>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $23 = XIEITE_DETAIL::at<23>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $24 = XIEITE_DETAIL::at<24>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $25 = XIEITE_DETAIL::at<25>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $26 = XIEITE_DETAIL::at<26>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $27 = XIEITE_DETAIL::at<27>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $28 = XIEITE_DETAIL::at<28>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $29 = XIEITE_DETAIL::at<29>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $30 = XIEITE_DETAIL::at<30>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $31 = XIEITE_DETAIL::at<31>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $32 = XIEITE_DETAIL::at<32>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $33 = XIEITE_DETAIL::at<33>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $34 = XIEITE_DETAIL::at<34>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $35 = XIEITE_DETAIL::at<35>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $36 = XIEITE_DETAIL::at<36>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $37 = XIEITE_DETAIL::at<37>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $38 = XIEITE_DETAIL::at<38>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $39 = XIEITE_DETAIL::at<39>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $40 = XIEITE_DETAIL::at<40>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $41 = XIEITE_DETAIL::at<41>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $42 = XIEITE_DETAIL::at<42>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $43 = XIEITE_DETAIL::at<43>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $44 = XIEITE_DETAIL::at<44>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $45 = XIEITE_DETAIL::at<45>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $46 = XIEITE_DETAIL::at<46>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $47 = XIEITE_DETAIL::at<47>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $48 = XIEITE_DETAIL::at<48>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $49 = XIEITE_DETAIL::at<49>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $50 = XIEITE_DETAIL::at<50>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $51 = XIEITE_DETAIL::at<51>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $52 = XIEITE_DETAIL::at<52>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $53 = XIEITE_DETAIL::at<53>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $54 = XIEITE_DETAIL::at<54>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $55 = XIEITE_DETAIL::at<55>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $56 = XIEITE_DETAIL::at<56>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $57 = XIEITE_DETAIL::at<57>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $58 = XIEITE_DETAIL::at<58>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $59 = XIEITE_DETAIL::at<59>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $60 = XIEITE_DETAIL::at<60>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $61 = XIEITE_DETAIL::at<61>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $62 = XIEITE_DETAIL::at<62>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $63 = XIEITE_DETAIL::at<63>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $64 = XIEITE_DETAIL::at<64>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $65 = XIEITE_DETAIL::at<65>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $66 = XIEITE_DETAIL::at<66>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $67 = XIEITE_DETAIL::at<67>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $68 = XIEITE_DETAIL::at<68>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $69 = XIEITE_DETAIL::at<69>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $70 = XIEITE_DETAIL::at<70>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $71 = XIEITE_DETAIL::at<71>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $72 = XIEITE_DETAIL::at<72>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $73 = XIEITE_DETAIL::at<73>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $74 = XIEITE_DETAIL::at<74>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $75 = XIEITE_DETAIL::at<75>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $76 = XIEITE_DETAIL::at<76>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $77 = XIEITE_DETAIL::at<77>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $78 = XIEITE_DETAIL::at<78>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $79 = XIEITE_DETAIL::at<79>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $80 = XIEITE_DETAIL::at<80>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $81 = XIEITE_DETAIL::at<81>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $82 = XIEITE_DETAIL::at<82>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $83 = XIEITE_DETAIL::at<83>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $84 = XIEITE_DETAIL::at<84>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $85 = XIEITE_DETAIL::at<85>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $86 = XIEITE_DETAIL::at<86>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $87 = XIEITE_DETAIL::at<87>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $88 = XIEITE_DETAIL::at<88>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $89 = XIEITE_DETAIL::at<89>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $90 = XIEITE_DETAIL::at<90>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $91 = XIEITE_DETAIL::at<91>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $92 = XIEITE_DETAIL::at<92>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $93 = XIEITE_DETAIL::at<93>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $94 = XIEITE_DETAIL::at<94>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $95 = XIEITE_DETAIL::at<95>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $96 = XIEITE_DETAIL::at<96>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $97 = XIEITE_DETAIL::at<97>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $98 = XIEITE_DETAIL::at<98>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $99 = XIEITE_DETAIL::at<99>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $100 = XIEITE_DETAIL::at<100>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $101 = XIEITE_DETAIL::at<101>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $102 = XIEITE_DETAIL::at<102>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $103 = XIEITE_DETAIL::at<103>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $104 = XIEITE_DETAIL::at<104>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $105 = XIEITE_DETAIL::at<105>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $106 = XIEITE_DETAIL::at<106>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $107 = XIEITE_DETAIL::at<107>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $108 = XIEITE_DETAIL::at<108>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $109 = XIEITE_DETAIL::at<109>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $110 = XIEITE_DETAIL::at<110>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $111 = XIEITE_DETAIL::at<111>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $112 = XIEITE_DETAIL::at<112>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $113 = XIEITE_DETAIL::at<113>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $114 = XIEITE_DETAIL::at<114>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $115 = XIEITE_DETAIL::at<115>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $116 = XIEITE_DETAIL::at<116>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $117 = XIEITE_DETAIL::at<117>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $118 = XIEITE_DETAIL::at<118>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $119 = XIEITE_DETAIL::at<119>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $120 = XIEITE_DETAIL::at<120>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $121 = XIEITE_DETAIL::at<121>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $122 = XIEITE_DETAIL::at<122>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $123 = XIEITE_DETAIL::at<123>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $124 = XIEITE_DETAIL::at<124>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $125 = XIEITE_DETAIL::at<125>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $126 = XIEITE_DETAIL::at<126>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $127 = XIEITE_DETAIL::at<127>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $128 = XIEITE_DETAIL::at<128>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $129 = XIEITE_DETAIL::at<129>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $130 = XIEITE_DETAIL::at<130>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $131 = XIEITE_DETAIL::at<131>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $132 = XIEITE_DETAIL::at<132>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $133 = XIEITE_DETAIL::at<133>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $134 = XIEITE_DETAIL::at<134>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $135 = XIEITE_DETAIL::at<135>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $136 = XIEITE_DETAIL::at<136>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $137 = XIEITE_DETAIL::at<137>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $138 = XIEITE_DETAIL::at<138>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $139 = XIEITE_DETAIL::at<139>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $140 = XIEITE_DETAIL::at<140>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $141 = XIEITE_DETAIL::at<141>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $142 = XIEITE_DETAIL::at<142>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $143 = XIEITE_DETAIL::at<143>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $144 = XIEITE_DETAIL::at<144>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $145 = XIEITE_DETAIL::at<145>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $146 = XIEITE_DETAIL::at<146>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $147 = XIEITE_DETAIL::at<147>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $148 = XIEITE_DETAIL::at<148>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $149 = XIEITE_DETAIL::at<149>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $150 = XIEITE_DETAIL::at<150>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $151 = XIEITE_DETAIL::at<151>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $152 = XIEITE_DETAIL::at<152>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $153 = XIEITE_DETAIL::at<153>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $154 = XIEITE_DETAIL::at<154>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $155 = XIEITE_DETAIL::at<155>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $156 = XIEITE_DETAIL::at<156>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $157 = XIEITE_DETAIL::at<157>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $158 = XIEITE_DETAIL::at<158>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $159 = XIEITE_DETAIL::at<159>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $160 = XIEITE_DETAIL::at<160>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $161 = XIEITE_DETAIL::at<161>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $162 = XIEITE_DETAIL::at<162>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $163 = XIEITE_DETAIL::at<163>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $164 = XIEITE_DETAIL::at<164>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $165 = XIEITE_DETAIL::at<165>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $166 = XIEITE_DETAIL::at<166>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $167 = XIEITE_DETAIL::at<167>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $168 = XIEITE_DETAIL::at<168>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $169 = XIEITE_DETAIL::at<169>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $170 = XIEITE_DETAIL::at<170>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $171 = XIEITE_DETAIL::at<171>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $172 = XIEITE_DETAIL::at<172>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $173 = XIEITE_DETAIL::at<173>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $174 = XIEITE_DETAIL::at<174>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $175 = XIEITE_DETAIL::at<175>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $176 = XIEITE_DETAIL::at<176>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $177 = XIEITE_DETAIL::at<177>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $178 = XIEITE_DETAIL::at<178>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $179 = XIEITE_DETAIL::at<179>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $180 = XIEITE_DETAIL::at<180>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $181 = XIEITE_DETAIL::at<181>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $182 = XIEITE_DETAIL::at<182>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $183 = XIEITE_DETAIL::at<183>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $184 = XIEITE_DETAIL::at<184>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $185 = XIEITE_DETAIL::at<185>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $186 = XIEITE_DETAIL::at<186>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $187 = XIEITE_DETAIL::at<187>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $188 = XIEITE_DETAIL::at<188>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $189 = XIEITE_DETAIL::at<189>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $190 = XIEITE_DETAIL::at<190>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $191 = XIEITE_DETAIL::at<191>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $192 = XIEITE_DETAIL::at<192>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $193 = XIEITE_DETAIL::at<193>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $194 = XIEITE_DETAIL::at<194>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $195 = XIEITE_DETAIL::at<195>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $196 = XIEITE_DETAIL::at<196>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $197 = XIEITE_DETAIL::at<197>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $198 = XIEITE_DETAIL::at<198>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $199 = XIEITE_DETAIL::at<199>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $200 = XIEITE_DETAIL::at<200>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $201 = XIEITE_DETAIL::at<201>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $202 = XIEITE_DETAIL::at<202>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $203 = XIEITE_DETAIL::at<203>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $204 = XIEITE_DETAIL::at<204>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $205 = XIEITE_DETAIL::at<205>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $206 = XIEITE_DETAIL::at<206>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $207 = XIEITE_DETAIL::at<207>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $208 = XIEITE_DETAIL::at<208>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $209 = XIEITE_DETAIL::at<209>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $210 = XIEITE_DETAIL::at<210>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $211 = XIEITE_DETAIL::at<211>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $212 = XIEITE_DETAIL::at<212>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $213 = XIEITE_DETAIL::at<213>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $214 = XIEITE_DETAIL::at<214>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $215 = XIEITE_DETAIL::at<215>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $216 = XIEITE_DETAIL::at<216>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $217 = XIEITE_DETAIL::at<217>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $218 = XIEITE_DETAIL::at<218>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $219 = XIEITE_DETAIL::at<219>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $220 = XIEITE_DETAIL::at<220>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $221 = XIEITE_DETAIL::at<221>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $222 = XIEITE_DETAIL::at<222>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $223 = XIEITE_DETAIL::at<223>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $224 = XIEITE_DETAIL::at<224>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $225 = XIEITE_DETAIL::at<225>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $226 = XIEITE_DETAIL::at<226>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $227 = XIEITE_DETAIL::at<227>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $228 = XIEITE_DETAIL::at<228>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $229 = XIEITE_DETAIL::at<229>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $230 = XIEITE_DETAIL::at<230>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $231 = XIEITE_DETAIL::at<231>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $232 = XIEITE_DETAIL::at<232>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $233 = XIEITE_DETAIL::at<233>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $234 = XIEITE_DETAIL::at<234>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $235 = XIEITE_DETAIL::at<235>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $236 = XIEITE_DETAIL::at<236>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $237 = XIEITE_DETAIL::at<237>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $238 = XIEITE_DETAIL::at<238>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $239 = XIEITE_DETAIL::at<239>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $240 = XIEITE_DETAIL::at<240>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $241 = XIEITE_DETAIL::at<241>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $242 = XIEITE_DETAIL::at<242>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $243 = XIEITE_DETAIL::at<243>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $244 = XIEITE_DETAIL::at<244>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $245 = XIEITE_DETAIL::at<245>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $246 = XIEITE_DETAIL::at<246>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $247 = XIEITE_DETAIL::at<247>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $248 = XIEITE_DETAIL::at<248>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $249 = XIEITE_DETAIL::at<249>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $250 = XIEITE_DETAIL::at<250>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $251 = XIEITE_DETAIL::at<251>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $252 = XIEITE_DETAIL::at<252>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $253 = XIEITE_DETAIL::at<253>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $254 = XIEITE_DETAIL::at<254>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $255 = XIEITE_DETAIL::at<255>(XIEITE_FWD($$)...); \
		[[maybe_unused]] auto&& $256 = XIEITE_DETAIL::at<256>(XIEITE_FWD($$)...); \
		return (__VA_ARGS__); \
	}

namespace XIEITE_DETAIL {
	// Template parameter must be named here due to GCC bug
	// https://gcc.gnu.org/bugzilla/show_bug.cgi?id=117422
	template<std::size_t idx> // <--
	constexpr auto&& at(auto&&...) noexcept;

	struct unusable {
		template<std::size_t idx>
		[[nodiscard]] friend constexpr auto&& at(auto&&... args) noexcept {
			if constexpr (idx < sizeof...(args)) {
				return std::get<idx>(std::forward_as_tuple(XIEITE_FWD(args)...));
			} else {
				static constexpr XIEITE_DETAIL::unusable unusable;
				return unusable;
			}
		}

	private:
		~unusable() = default;
	};
}
