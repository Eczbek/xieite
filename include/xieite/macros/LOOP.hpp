#pragma once

#include <xieite/macros/CONCATENATE.hpp>

#define XIEITE_LOOP(count, callback, initial, arguments...) \
	XIEITE_CONCATENATE(XIEITE_INTERNAL_LOOP_, count)(callback, initial, arguments...)

#define XIEITE_INTERNAL_LOOP_0(callback, previous, arguments...)

#define XIEITE_INTERNAL_LOOP_1(callback, previous, arguments...) \
	callback(0, previous, arguments)

#define XIEITE_INTERNAL_LOOP_2(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_1(callback, callback(1, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_3(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_2(callback, callback(2, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_4(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_3(callback, callback(3, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_5(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_4(callback, callback(4, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_6(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_5(callback, callback(5, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_7(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_6(callback, callback(6, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_8(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_7(callback, callback(7, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_9(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_8(callback, callback(8, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_10(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_9(callback, callback(9, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_11(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_10(callback, callback(10, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_12(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_11(callback, callback(11, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_13(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_12(callback, callback(12, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_14(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_13(callback, callback(13, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_15(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_14(callback, callback(14, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_16(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_15(callback, callback(15, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_17(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_16(callback, callback(16, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_18(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_17(callback, callback(17, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_19(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_18(callback, callback(18, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_20(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_19(callback, callback(19, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_21(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_20(callback, callback(20, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_22(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_21(callback, callback(21, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_23(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_22(callback, callback(22, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_24(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_23(callback, callback(23, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_25(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_24(callback, callback(24, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_26(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_25(callback, callback(25, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_27(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_26(callback, callback(26, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_28(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_27(callback, callback(27, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_29(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_28(callback, callback(28, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_30(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_29(callback, callback(29, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_31(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_30(callback, callback(30, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_32(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_31(callback, callback(31, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_33(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_32(callback, callback(32, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_34(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_33(callback, callback(33, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_35(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_34(callback, callback(34, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_36(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_35(callback, callback(35, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_37(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_36(callback, callback(36, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_38(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_37(callback, callback(37, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_39(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_38(callback, callback(38, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_40(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_39(callback, callback(39, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_41(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_40(callback, callback(40, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_42(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_41(callback, callback(41, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_43(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_42(callback, callback(42, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_44(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_43(callback, callback(43, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_45(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_44(callback, callback(44, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_46(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_45(callback, callback(45, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_47(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_46(callback, callback(46, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_48(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_47(callback, callback(47, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_49(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_48(callback, callback(48, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_50(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_49(callback, callback(49, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_51(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_50(callback, callback(50, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_52(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_51(callback, callback(51, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_53(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_52(callback, callback(52, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_54(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_53(callback, callback(53, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_55(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_54(callback, callback(54, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_56(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_55(callback, callback(55, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_57(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_56(callback, callback(56, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_58(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_57(callback, callback(57, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_59(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_58(callback, callback(58, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_60(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_59(callback, callback(59, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_61(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_60(callback, callback(60, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_62(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_61(callback, callback(61, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_63(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_62(callback, callback(62, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_64(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_63(callback, callback(63, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_65(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_64(callback, callback(64, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_66(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_65(callback, callback(65, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_67(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_66(callback, callback(66, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_68(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_67(callback, callback(67, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_69(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_68(callback, callback(68, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_70(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_69(callback, callback(69, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_71(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_70(callback, callback(70, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_72(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_71(callback, callback(71, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_73(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_72(callback, callback(72, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_74(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_73(callback, callback(73, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_75(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_74(callback, callback(74, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_76(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_75(callback, callback(75, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_77(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_76(callback, callback(76, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_78(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_77(callback, callback(77, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_79(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_78(callback, callback(78, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_80(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_79(callback, callback(79, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_81(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_80(callback, callback(80, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_82(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_81(callback, callback(81, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_83(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_82(callback, callback(82, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_84(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_83(callback, callback(83, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_85(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_84(callback, callback(84, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_86(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_85(callback, callback(85, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_87(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_86(callback, callback(86, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_88(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_87(callback, callback(87, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_89(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_88(callback, callback(88, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_90(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_89(callback, callback(89, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_91(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_90(callback, callback(90, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_92(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_91(callback, callback(91, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_93(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_92(callback, callback(92, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_94(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_93(callback, callback(93, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_95(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_94(callback, callback(94, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_96(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_95(callback, callback(95, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_97(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_96(callback, callback(96, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_98(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_97(callback, callback(97, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_99(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_98(callback, callback(98, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_100(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_99(callback, callback(99, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_101(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_100(callback, callback(100, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_102(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_101(callback, callback(101, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_103(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_102(callback, callback(102, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_104(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_103(callback, callback(103, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_105(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_104(callback, callback(104, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_106(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_105(callback, callback(105, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_107(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_106(callback, callback(106, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_108(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_107(callback, callback(107, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_109(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_108(callback, callback(108, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_110(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_109(callback, callback(109, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_111(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_110(callback, callback(110, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_112(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_111(callback, callback(111, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_113(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_112(callback, callback(112, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_114(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_113(callback, callback(113, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_115(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_114(callback, callback(114, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_116(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_115(callback, callback(115, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_117(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_116(callback, callback(116, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_118(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_117(callback, callback(117, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_119(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_118(callback, callback(118, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_120(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_119(callback, callback(119, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_121(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_120(callback, callback(120, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_122(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_121(callback, callback(121, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_123(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_122(callback, callback(122, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_124(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_123(callback, callback(123, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_125(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_124(callback, callback(124, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_126(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_125(callback, callback(125, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_127(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_126(callback, callback(126, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_128(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_127(callback, callback(127, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_129(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_128(callback, callback(128, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_130(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_129(callback, callback(129, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_131(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_130(callback, callback(130, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_132(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_131(callback, callback(131, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_133(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_132(callback, callback(132, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_134(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_133(callback, callback(133, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_135(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_134(callback, callback(134, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_136(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_135(callback, callback(135, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_137(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_136(callback, callback(136, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_138(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_137(callback, callback(137, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_139(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_138(callback, callback(138, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_140(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_139(callback, callback(139, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_141(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_140(callback, callback(140, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_142(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_141(callback, callback(141, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_143(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_142(callback, callback(142, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_144(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_143(callback, callback(143, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_145(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_144(callback, callback(144, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_146(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_145(callback, callback(145, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_147(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_146(callback, callback(146, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_148(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_147(callback, callback(147, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_149(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_148(callback, callback(148, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_150(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_149(callback, callback(149, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_151(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_150(callback, callback(150, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_152(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_151(callback, callback(151, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_153(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_152(callback, callback(152, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_154(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_153(callback, callback(153, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_155(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_154(callback, callback(154, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_156(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_155(callback, callback(155, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_157(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_156(callback, callback(156, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_158(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_157(callback, callback(157, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_159(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_158(callback, callback(158, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_160(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_159(callback, callback(159, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_161(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_160(callback, callback(160, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_162(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_161(callback, callback(161, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_163(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_162(callback, callback(162, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_164(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_163(callback, callback(163, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_165(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_164(callback, callback(164, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_166(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_165(callback, callback(165, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_167(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_166(callback, callback(166, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_168(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_167(callback, callback(167, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_169(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_168(callback, callback(168, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_170(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_169(callback, callback(169, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_171(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_170(callback, callback(170, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_172(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_171(callback, callback(171, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_173(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_172(callback, callback(172, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_174(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_173(callback, callback(173, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_175(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_174(callback, callback(174, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_176(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_175(callback, callback(175, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_177(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_176(callback, callback(176, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_178(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_177(callback, callback(177, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_179(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_178(callback, callback(178, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_180(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_179(callback, callback(179, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_181(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_180(callback, callback(180, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_182(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_181(callback, callback(181, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_183(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_182(callback, callback(182, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_184(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_183(callback, callback(183, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_185(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_184(callback, callback(184, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_186(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_185(callback, callback(185, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_187(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_186(callback, callback(186, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_188(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_187(callback, callback(187, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_189(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_188(callback, callback(188, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_190(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_189(callback, callback(189, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_191(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_190(callback, callback(190, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_192(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_191(callback, callback(191, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_193(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_192(callback, callback(192, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_194(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_193(callback, callback(193, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_195(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_194(callback, callback(194, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_196(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_195(callback, callback(195, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_197(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_196(callback, callback(196, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_198(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_197(callback, callback(197, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_199(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_198(callback, callback(198, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_200(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_199(callback, callback(199, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_201(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_200(callback, callback(200, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_202(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_201(callback, callback(201, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_203(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_202(callback, callback(202, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_204(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_203(callback, callback(203, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_205(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_204(callback, callback(204, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_206(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_205(callback, callback(205, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_207(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_206(callback, callback(206, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_208(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_207(callback, callback(207, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_209(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_208(callback, callback(208, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_210(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_209(callback, callback(209, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_211(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_210(callback, callback(210, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_212(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_211(callback, callback(211, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_213(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_212(callback, callback(212, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_214(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_213(callback, callback(213, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_215(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_214(callback, callback(214, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_216(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_215(callback, callback(215, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_217(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_216(callback, callback(216, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_218(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_217(callback, callback(217, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_219(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_218(callback, callback(218, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_220(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_219(callback, callback(219, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_221(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_220(callback, callback(220, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_222(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_221(callback, callback(221, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_223(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_222(callback, callback(222, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_224(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_223(callback, callback(223, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_225(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_224(callback, callback(224, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_226(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_225(callback, callback(225, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_227(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_226(callback, callback(226, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_228(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_227(callback, callback(227, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_229(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_228(callback, callback(228, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_230(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_229(callback, callback(229, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_231(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_230(callback, callback(230, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_232(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_231(callback, callback(231, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_233(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_232(callback, callback(232, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_234(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_233(callback, callback(233, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_235(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_234(callback, callback(234, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_236(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_235(callback, callback(235, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_237(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_236(callback, callback(236, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_238(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_237(callback, callback(237, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_239(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_238(callback, callback(238, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_240(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_239(callback, callback(239, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_241(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_240(callback, callback(240, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_242(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_241(callback, callback(241, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_243(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_242(callback, callback(242, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_244(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_243(callback, callback(243, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_245(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_244(callback, callback(244, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_246(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_245(callback, callback(245, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_247(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_246(callback, callback(246, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_248(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_247(callback, callback(247, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_249(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_248(callback, callback(248, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_250(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_249(callback, callback(249, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_251(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_250(callback, callback(250, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_252(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_251(callback, callback(251, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_253(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_252(callback, callback(252, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_254(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_253(callback, callback(253, previous, arguments), arguments)

#define XIEITE_INTERNAL_LOOP_255(callback, previous, arguments...) \
	XIEITE_INTERNAL_LOOP_254(callback, callback(254, previous, arguments), arguments)
