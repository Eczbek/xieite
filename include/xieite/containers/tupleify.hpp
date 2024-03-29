#ifndef XIEITE_HEADER_CONTAINERS_DETAIL_TUPLEIFY
#	define XIEITE_HEADER_CONTAINERS_DETAIL_TUPLEIFY

#	include <tuple>
#	include <utility>
#	include "../types/collapse_reference.hpp"

#	define XIEITE_DETAIL_0(macro) XIEITE_DETAIL_##macro(0)
#	define XIEITE_DETAIL_1(macro) XIEITE_DETAIL_0(macro), XIEITE_DETAIL_##macro(1)
#	define XIEITE_DETAIL_2(macro) XIEITE_DETAIL_1(macro), XIEITE_DETAIL_##macro(2)
#	define XIEITE_DETAIL_3(macro) XIEITE_DETAIL_2(macro), XIEITE_DETAIL_##macro(3)
#	define XIEITE_DETAIL_4(macro) XIEITE_DETAIL_3(macro), XIEITE_DETAIL_##macro(4)
#	define XIEITE_DETAIL_5(macro) XIEITE_DETAIL_4(macro), XIEITE_DETAIL_##macro(5)
#	define XIEITE_DETAIL_6(macro) XIEITE_DETAIL_5(macro), XIEITE_DETAIL_##macro(6)
#	define XIEITE_DETAIL_7(macro) XIEITE_DETAIL_6(macro), XIEITE_DETAIL_##macro(7)
#	define XIEITE_DETAIL_8(macro) XIEITE_DETAIL_7(macro), XIEITE_DETAIL_##macro(8)
#	define XIEITE_DETAIL_9(macro) XIEITE_DETAIL_8(macro), XIEITE_DETAIL_##macro(9)
#	define XIEITE_DETAIL_10(macro) XIEITE_DETAIL_9(macro), XIEITE_DETAIL_##macro(10)
#	define XIEITE_DETAIL_11(macro) XIEITE_DETAIL_10(macro), XIEITE_DETAIL_##macro(11)
#	define XIEITE_DETAIL_12(macro) XIEITE_DETAIL_11(macro), XIEITE_DETAIL_##macro(12)
#	define XIEITE_DETAIL_13(macro) XIEITE_DETAIL_12(macro), XIEITE_DETAIL_##macro(13)
#	define XIEITE_DETAIL_14(macro) XIEITE_DETAIL_13(macro), XIEITE_DETAIL_##macro(14)
#	define XIEITE_DETAIL_15(macro) XIEITE_DETAIL_14(macro), XIEITE_DETAIL_##macro(15)
#	define XIEITE_DETAIL_16(macro) XIEITE_DETAIL_15(macro), XIEITE_DETAIL_##macro(16)
#	define XIEITE_DETAIL_17(macro) XIEITE_DETAIL_16(macro), XIEITE_DETAIL_##macro(17)
#	define XIEITE_DETAIL_18(macro) XIEITE_DETAIL_17(macro), XIEITE_DETAIL_##macro(18)
#	define XIEITE_DETAIL_19(macro) XIEITE_DETAIL_18(macro), XIEITE_DETAIL_##macro(19)
#	define XIEITE_DETAIL_20(macro) XIEITE_DETAIL_19(macro), XIEITE_DETAIL_##macro(20)
#	define XIEITE_DETAIL_21(macro) XIEITE_DETAIL_20(macro), XIEITE_DETAIL_##macro(21)
#	define XIEITE_DETAIL_22(macro) XIEITE_DETAIL_21(macro), XIEITE_DETAIL_##macro(22)
#	define XIEITE_DETAIL_23(macro) XIEITE_DETAIL_22(macro), XIEITE_DETAIL_##macro(23)
#	define XIEITE_DETAIL_24(macro) XIEITE_DETAIL_23(macro), XIEITE_DETAIL_##macro(24)
#	define XIEITE_DETAIL_25(macro) XIEITE_DETAIL_24(macro), XIEITE_DETAIL_##macro(25)
#	define XIEITE_DETAIL_26(macro) XIEITE_DETAIL_25(macro), XIEITE_DETAIL_##macro(26)
#	define XIEITE_DETAIL_27(macro) XIEITE_DETAIL_26(macro), XIEITE_DETAIL_##macro(27)
#	define XIEITE_DETAIL_28(macro) XIEITE_DETAIL_27(macro), XIEITE_DETAIL_##macro(28)
#	define XIEITE_DETAIL_29(macro) XIEITE_DETAIL_28(macro), XIEITE_DETAIL_##macro(29)
#	define XIEITE_DETAIL_30(macro) XIEITE_DETAIL_29(macro), XIEITE_DETAIL_##macro(30)
#	define XIEITE_DETAIL_31(macro) XIEITE_DETAIL_30(macro), XIEITE_DETAIL_##macro(31)
#	define XIEITE_DETAIL_32(macro) XIEITE_DETAIL_31(macro), XIEITE_DETAIL_##macro(32)
#	define XIEITE_DETAIL_33(macro) XIEITE_DETAIL_32(macro), XIEITE_DETAIL_##macro(33)
#	define XIEITE_DETAIL_34(macro) XIEITE_DETAIL_33(macro), XIEITE_DETAIL_##macro(34)
#	define XIEITE_DETAIL_35(macro) XIEITE_DETAIL_34(macro), XIEITE_DETAIL_##macro(35)
#	define XIEITE_DETAIL_36(macro) XIEITE_DETAIL_35(macro), XIEITE_DETAIL_##macro(36)
#	define XIEITE_DETAIL_37(macro) XIEITE_DETAIL_36(macro), XIEITE_DETAIL_##macro(37)
#	define XIEITE_DETAIL_38(macro) XIEITE_DETAIL_37(macro), XIEITE_DETAIL_##macro(38)
#	define XIEITE_DETAIL_39(macro) XIEITE_DETAIL_38(macro), XIEITE_DETAIL_##macro(39)
#	define XIEITE_DETAIL_40(macro) XIEITE_DETAIL_39(macro), XIEITE_DETAIL_##macro(40)
#	define XIEITE_DETAIL_41(macro) XIEITE_DETAIL_40(macro), XIEITE_DETAIL_##macro(41)
#	define XIEITE_DETAIL_42(macro) XIEITE_DETAIL_41(macro), XIEITE_DETAIL_##macro(42)
#	define XIEITE_DETAIL_43(macro) XIEITE_DETAIL_42(macro), XIEITE_DETAIL_##macro(43)
#	define XIEITE_DETAIL_44(macro) XIEITE_DETAIL_43(macro), XIEITE_DETAIL_##macro(44)
#	define XIEITE_DETAIL_45(macro) XIEITE_DETAIL_44(macro), XIEITE_DETAIL_##macro(45)
#	define XIEITE_DETAIL_46(macro) XIEITE_DETAIL_45(macro), XIEITE_DETAIL_##macro(46)
#	define XIEITE_DETAIL_47(macro) XIEITE_DETAIL_46(macro), XIEITE_DETAIL_##macro(47)
#	define XIEITE_DETAIL_48(macro) XIEITE_DETAIL_47(macro), XIEITE_DETAIL_##macro(48)
#	define XIEITE_DETAIL_49(macro) XIEITE_DETAIL_48(macro), XIEITE_DETAIL_##macro(49)
#	define XIEITE_DETAIL_50(macro) XIEITE_DETAIL_49(macro), XIEITE_DETAIL_##macro(50)
#	define XIEITE_DETAIL_51(macro) XIEITE_DETAIL_50(macro), XIEITE_DETAIL_##macro(51)
#	define XIEITE_DETAIL_52(macro) XIEITE_DETAIL_51(macro), XIEITE_DETAIL_##macro(52)
#	define XIEITE_DETAIL_53(macro) XIEITE_DETAIL_52(macro), XIEITE_DETAIL_##macro(53)
#	define XIEITE_DETAIL_54(macro) XIEITE_DETAIL_53(macro), XIEITE_DETAIL_##macro(54)
#	define XIEITE_DETAIL_55(macro) XIEITE_DETAIL_54(macro), XIEITE_DETAIL_##macro(55)
#	define XIEITE_DETAIL_56(macro) XIEITE_DETAIL_55(macro), XIEITE_DETAIL_##macro(56)
#	define XIEITE_DETAIL_57(macro) XIEITE_DETAIL_56(macro), XIEITE_DETAIL_##macro(57)
#	define XIEITE_DETAIL_58(macro) XIEITE_DETAIL_57(macro), XIEITE_DETAIL_##macro(58)
#	define XIEITE_DETAIL_59(macro) XIEITE_DETAIL_58(macro), XIEITE_DETAIL_##macro(59)
#	define XIEITE_DETAIL_60(macro) XIEITE_DETAIL_59(macro), XIEITE_DETAIL_##macro(60)
#	define XIEITE_DETAIL_61(macro) XIEITE_DETAIL_60(macro), XIEITE_DETAIL_##macro(61)
#	define XIEITE_DETAIL_62(macro) XIEITE_DETAIL_61(macro), XIEITE_DETAIL_##macro(62)
#	define XIEITE_DETAIL_63(macro) XIEITE_DETAIL_62(macro), XIEITE_DETAIL_##macro(63)
#	define XIEITE_DETAIL_64(macro) XIEITE_DETAIL_63(macro), XIEITE_DETAIL_##macro(64)
#	define XIEITE_DETAIL_65(macro) XIEITE_DETAIL_64(macro), XIEITE_DETAIL_##macro(65)
#	define XIEITE_DETAIL_66(macro) XIEITE_DETAIL_65(macro), XIEITE_DETAIL_##macro(66)
#	define XIEITE_DETAIL_67(macro) XIEITE_DETAIL_66(macro), XIEITE_DETAIL_##macro(67)
#	define XIEITE_DETAIL_68(macro) XIEITE_DETAIL_67(macro), XIEITE_DETAIL_##macro(68)
#	define XIEITE_DETAIL_69(macro) XIEITE_DETAIL_68(macro), XIEITE_DETAIL_##macro(69)
#	define XIEITE_DETAIL_70(macro) XIEITE_DETAIL_69(macro), XIEITE_DETAIL_##macro(70)
#	define XIEITE_DETAIL_71(macro) XIEITE_DETAIL_70(macro), XIEITE_DETAIL_##macro(71)
#	define XIEITE_DETAIL_72(macro) XIEITE_DETAIL_71(macro), XIEITE_DETAIL_##macro(72)
#	define XIEITE_DETAIL_73(macro) XIEITE_DETAIL_72(macro), XIEITE_DETAIL_##macro(73)
#	define XIEITE_DETAIL_74(macro) XIEITE_DETAIL_73(macro), XIEITE_DETAIL_##macro(74)
#	define XIEITE_DETAIL_75(macro) XIEITE_DETAIL_74(macro), XIEITE_DETAIL_##macro(75)
#	define XIEITE_DETAIL_76(macro) XIEITE_DETAIL_75(macro), XIEITE_DETAIL_##macro(76)
#	define XIEITE_DETAIL_77(macro) XIEITE_DETAIL_76(macro), XIEITE_DETAIL_##macro(77)
#	define XIEITE_DETAIL_78(macro) XIEITE_DETAIL_77(macro), XIEITE_DETAIL_##macro(78)
#	define XIEITE_DETAIL_79(macro) XIEITE_DETAIL_78(macro), XIEITE_DETAIL_##macro(79)
#	define XIEITE_DETAIL_80(macro) XIEITE_DETAIL_79(macro), XIEITE_DETAIL_##macro(80)
#	define XIEITE_DETAIL_81(macro) XIEITE_DETAIL_80(macro), XIEITE_DETAIL_##macro(81)
#	define XIEITE_DETAIL_82(macro) XIEITE_DETAIL_81(macro), XIEITE_DETAIL_##macro(82)
#	define XIEITE_DETAIL_83(macro) XIEITE_DETAIL_82(macro), XIEITE_DETAIL_##macro(83)
#	define XIEITE_DETAIL_84(macro) XIEITE_DETAIL_83(macro), XIEITE_DETAIL_##macro(84)
#	define XIEITE_DETAIL_85(macro) XIEITE_DETAIL_84(macro), XIEITE_DETAIL_##macro(85)
#	define XIEITE_DETAIL_86(macro) XIEITE_DETAIL_85(macro), XIEITE_DETAIL_##macro(86)
#	define XIEITE_DETAIL_87(macro) XIEITE_DETAIL_86(macro), XIEITE_DETAIL_##macro(87)
#	define XIEITE_DETAIL_88(macro) XIEITE_DETAIL_87(macro), XIEITE_DETAIL_##macro(88)
#	define XIEITE_DETAIL_89(macro) XIEITE_DETAIL_88(macro), XIEITE_DETAIL_##macro(89)
#	define XIEITE_DETAIL_90(macro) XIEITE_DETAIL_89(macro), XIEITE_DETAIL_##macro(90)
#	define XIEITE_DETAIL_91(macro) XIEITE_DETAIL_90(macro), XIEITE_DETAIL_##macro(91)
#	define XIEITE_DETAIL_92(macro) XIEITE_DETAIL_91(macro), XIEITE_DETAIL_##macro(92)
#	define XIEITE_DETAIL_93(macro) XIEITE_DETAIL_92(macro), XIEITE_DETAIL_##macro(93)
#	define XIEITE_DETAIL_94(macro) XIEITE_DETAIL_93(macro), XIEITE_DETAIL_##macro(94)
#	define XIEITE_DETAIL_95(macro) XIEITE_DETAIL_94(macro), XIEITE_DETAIL_##macro(95)
#	define XIEITE_DETAIL_96(macro) XIEITE_DETAIL_95(macro), XIEITE_DETAIL_##macro(96)
#	define XIEITE_DETAIL_97(macro) XIEITE_DETAIL_96(macro), XIEITE_DETAIL_##macro(97)
#	define XIEITE_DETAIL_98(macro) XIEITE_DETAIL_97(macro), XIEITE_DETAIL_##macro(98)
#	define XIEITE_DETAIL_99(macro) XIEITE_DETAIL_98(macro), XIEITE_DETAIL_##macro(99)
#	define XIEITE_DETAIL_100(macro) XIEITE_DETAIL_99(macro), XIEITE_DETAIL_##macro(100)
#	define XIEITE_DETAIL_101(macro) XIEITE_DETAIL_100(macro), XIEITE_DETAIL_##macro(101)
#	define XIEITE_DETAIL_102(macro) XIEITE_DETAIL_101(macro), XIEITE_DETAIL_##macro(102)
#	define XIEITE_DETAIL_103(macro) XIEITE_DETAIL_102(macro), XIEITE_DETAIL_##macro(103)
#	define XIEITE_DETAIL_104(macro) XIEITE_DETAIL_103(macro), XIEITE_DETAIL_##macro(104)
#	define XIEITE_DETAIL_105(macro) XIEITE_DETAIL_104(macro), XIEITE_DETAIL_##macro(105)
#	define XIEITE_DETAIL_106(macro) XIEITE_DETAIL_105(macro), XIEITE_DETAIL_##macro(106)
#	define XIEITE_DETAIL_107(macro) XIEITE_DETAIL_106(macro), XIEITE_DETAIL_##macro(107)
#	define XIEITE_DETAIL_108(macro) XIEITE_DETAIL_107(macro), XIEITE_DETAIL_##macro(108)
#	define XIEITE_DETAIL_109(macro) XIEITE_DETAIL_108(macro), XIEITE_DETAIL_##macro(109)
#	define XIEITE_DETAIL_110(macro) XIEITE_DETAIL_109(macro), XIEITE_DETAIL_##macro(110)
#	define XIEITE_DETAIL_111(macro) XIEITE_DETAIL_110(macro), XIEITE_DETAIL_##macro(111)
#	define XIEITE_DETAIL_112(macro) XIEITE_DETAIL_111(macro), XIEITE_DETAIL_##macro(112)
#	define XIEITE_DETAIL_113(macro) XIEITE_DETAIL_112(macro), XIEITE_DETAIL_##macro(113)
#	define XIEITE_DETAIL_114(macro) XIEITE_DETAIL_113(macro), XIEITE_DETAIL_##macro(114)
#	define XIEITE_DETAIL_115(macro) XIEITE_DETAIL_114(macro), XIEITE_DETAIL_##macro(115)
#	define XIEITE_DETAIL_116(macro) XIEITE_DETAIL_115(macro), XIEITE_DETAIL_##macro(116)
#	define XIEITE_DETAIL_117(macro) XIEITE_DETAIL_116(macro), XIEITE_DETAIL_##macro(117)
#	define XIEITE_DETAIL_118(macro) XIEITE_DETAIL_117(macro), XIEITE_DETAIL_##macro(118)
#	define XIEITE_DETAIL_119(macro) XIEITE_DETAIL_118(macro), XIEITE_DETAIL_##macro(119)
#	define XIEITE_DETAIL_120(macro) XIEITE_DETAIL_119(macro), XIEITE_DETAIL_##macro(120)
#	define XIEITE_DETAIL_121(macro) XIEITE_DETAIL_120(macro), XIEITE_DETAIL_##macro(121)
#	define XIEITE_DETAIL_122(macro) XIEITE_DETAIL_121(macro), XIEITE_DETAIL_##macro(122)
#	define XIEITE_DETAIL_123(macro) XIEITE_DETAIL_122(macro), XIEITE_DETAIL_##macro(123)
#	define XIEITE_DETAIL_124(macro) XIEITE_DETAIL_123(macro), XIEITE_DETAIL_##macro(124)
#	define XIEITE_DETAIL_125(macro) XIEITE_DETAIL_124(macro), XIEITE_DETAIL_##macro(125)
#	define XIEITE_DETAIL_126(macro) XIEITE_DETAIL_125(macro), XIEITE_DETAIL_##macro(126)
#	define XIEITE_DETAIL_127(macro) XIEITE_DETAIL_126(macro), XIEITE_DETAIL_##macro(127)
#	define XIEITE_DETAIL_128(macro) XIEITE_DETAIL_127(macro), XIEITE_DETAIL_##macro(128)
#	define XIEITE_DETAIL_129(macro) XIEITE_DETAIL_128(macro), XIEITE_DETAIL_##macro(129)
#	define XIEITE_DETAIL_130(macro) XIEITE_DETAIL_129(macro), XIEITE_DETAIL_##macro(130)
#	define XIEITE_DETAIL_131(macro) XIEITE_DETAIL_130(macro), XIEITE_DETAIL_##macro(131)
#	define XIEITE_DETAIL_132(macro) XIEITE_DETAIL_131(macro), XIEITE_DETAIL_##macro(132)
#	define XIEITE_DETAIL_133(macro) XIEITE_DETAIL_132(macro), XIEITE_DETAIL_##macro(133)
#	define XIEITE_DETAIL_134(macro) XIEITE_DETAIL_133(macro), XIEITE_DETAIL_##macro(134)
#	define XIEITE_DETAIL_135(macro) XIEITE_DETAIL_134(macro), XIEITE_DETAIL_##macro(135)
#	define XIEITE_DETAIL_136(macro) XIEITE_DETAIL_135(macro), XIEITE_DETAIL_##macro(136)
#	define XIEITE_DETAIL_137(macro) XIEITE_DETAIL_136(macro), XIEITE_DETAIL_##macro(137)
#	define XIEITE_DETAIL_138(macro) XIEITE_DETAIL_137(macro), XIEITE_DETAIL_##macro(138)
#	define XIEITE_DETAIL_139(macro) XIEITE_DETAIL_138(macro), XIEITE_DETAIL_##macro(139)
#	define XIEITE_DETAIL_140(macro) XIEITE_DETAIL_139(macro), XIEITE_DETAIL_##macro(140)
#	define XIEITE_DETAIL_141(macro) XIEITE_DETAIL_140(macro), XIEITE_DETAIL_##macro(141)
#	define XIEITE_DETAIL_142(macro) XIEITE_DETAIL_141(macro), XIEITE_DETAIL_##macro(142)
#	define XIEITE_DETAIL_143(macro) XIEITE_DETAIL_142(macro), XIEITE_DETAIL_##macro(143)
#	define XIEITE_DETAIL_144(macro) XIEITE_DETAIL_143(macro), XIEITE_DETAIL_##macro(144)
#	define XIEITE_DETAIL_145(macro) XIEITE_DETAIL_144(macro), XIEITE_DETAIL_##macro(145)
#	define XIEITE_DETAIL_146(macro) XIEITE_DETAIL_145(macro), XIEITE_DETAIL_##macro(146)
#	define XIEITE_DETAIL_147(macro) XIEITE_DETAIL_146(macro), XIEITE_DETAIL_##macro(147)
#	define XIEITE_DETAIL_148(macro) XIEITE_DETAIL_147(macro), XIEITE_DETAIL_##macro(148)
#	define XIEITE_DETAIL_149(macro) XIEITE_DETAIL_148(macro), XIEITE_DETAIL_##macro(149)
#	define XIEITE_DETAIL_150(macro) XIEITE_DETAIL_149(macro), XIEITE_DETAIL_##macro(150)
#	define XIEITE_DETAIL_151(macro) XIEITE_DETAIL_150(macro), XIEITE_DETAIL_##macro(151)
#	define XIEITE_DETAIL_152(macro) XIEITE_DETAIL_151(macro), XIEITE_DETAIL_##macro(152)
#	define XIEITE_DETAIL_153(macro) XIEITE_DETAIL_152(macro), XIEITE_DETAIL_##macro(153)
#	define XIEITE_DETAIL_154(macro) XIEITE_DETAIL_153(macro), XIEITE_DETAIL_##macro(154)
#	define XIEITE_DETAIL_155(macro) XIEITE_DETAIL_154(macro), XIEITE_DETAIL_##macro(155)
#	define XIEITE_DETAIL_156(macro) XIEITE_DETAIL_155(macro), XIEITE_DETAIL_##macro(156)
#	define XIEITE_DETAIL_157(macro) XIEITE_DETAIL_156(macro), XIEITE_DETAIL_##macro(157)
#	define XIEITE_DETAIL_158(macro) XIEITE_DETAIL_157(macro), XIEITE_DETAIL_##macro(158)
#	define XIEITE_DETAIL_159(macro) XIEITE_DETAIL_158(macro), XIEITE_DETAIL_##macro(159)
#	define XIEITE_DETAIL_160(macro) XIEITE_DETAIL_159(macro), XIEITE_DETAIL_##macro(160)
#	define XIEITE_DETAIL_161(macro) XIEITE_DETAIL_160(macro), XIEITE_DETAIL_##macro(161)
#	define XIEITE_DETAIL_162(macro) XIEITE_DETAIL_161(macro), XIEITE_DETAIL_##macro(162)
#	define XIEITE_DETAIL_163(macro) XIEITE_DETAIL_162(macro), XIEITE_DETAIL_##macro(163)
#	define XIEITE_DETAIL_164(macro) XIEITE_DETAIL_163(macro), XIEITE_DETAIL_##macro(164)
#	define XIEITE_DETAIL_165(macro) XIEITE_DETAIL_164(macro), XIEITE_DETAIL_##macro(165)
#	define XIEITE_DETAIL_166(macro) XIEITE_DETAIL_165(macro), XIEITE_DETAIL_##macro(166)
#	define XIEITE_DETAIL_167(macro) XIEITE_DETAIL_166(macro), XIEITE_DETAIL_##macro(167)
#	define XIEITE_DETAIL_168(macro) XIEITE_DETAIL_167(macro), XIEITE_DETAIL_##macro(168)
#	define XIEITE_DETAIL_169(macro) XIEITE_DETAIL_168(macro), XIEITE_DETAIL_##macro(169)
#	define XIEITE_DETAIL_170(macro) XIEITE_DETAIL_169(macro), XIEITE_DETAIL_##macro(170)
#	define XIEITE_DETAIL_171(macro) XIEITE_DETAIL_170(macro), XIEITE_DETAIL_##macro(171)
#	define XIEITE_DETAIL_172(macro) XIEITE_DETAIL_171(macro), XIEITE_DETAIL_##macro(172)
#	define XIEITE_DETAIL_173(macro) XIEITE_DETAIL_172(macro), XIEITE_DETAIL_##macro(173)
#	define XIEITE_DETAIL_174(macro) XIEITE_DETAIL_173(macro), XIEITE_DETAIL_##macro(174)
#	define XIEITE_DETAIL_175(macro) XIEITE_DETAIL_174(macro), XIEITE_DETAIL_##macro(175)
#	define XIEITE_DETAIL_176(macro) XIEITE_DETAIL_175(macro), XIEITE_DETAIL_##macro(176)
#	define XIEITE_DETAIL_177(macro) XIEITE_DETAIL_176(macro), XIEITE_DETAIL_##macro(177)
#	define XIEITE_DETAIL_178(macro) XIEITE_DETAIL_177(macro), XIEITE_DETAIL_##macro(178)
#	define XIEITE_DETAIL_179(macro) XIEITE_DETAIL_178(macro), XIEITE_DETAIL_##macro(179)
#	define XIEITE_DETAIL_180(macro) XIEITE_DETAIL_179(macro), XIEITE_DETAIL_##macro(180)
#	define XIEITE_DETAIL_181(macro) XIEITE_DETAIL_180(macro), XIEITE_DETAIL_##macro(181)
#	define XIEITE_DETAIL_182(macro) XIEITE_DETAIL_181(macro), XIEITE_DETAIL_##macro(182)
#	define XIEITE_DETAIL_183(macro) XIEITE_DETAIL_182(macro), XIEITE_DETAIL_##macro(183)
#	define XIEITE_DETAIL_184(macro) XIEITE_DETAIL_183(macro), XIEITE_DETAIL_##macro(184)
#	define XIEITE_DETAIL_185(macro) XIEITE_DETAIL_184(macro), XIEITE_DETAIL_##macro(185)
#	define XIEITE_DETAIL_186(macro) XIEITE_DETAIL_185(macro), XIEITE_DETAIL_##macro(186)
#	define XIEITE_DETAIL_187(macro) XIEITE_DETAIL_186(macro), XIEITE_DETAIL_##macro(187)
#	define XIEITE_DETAIL_188(macro) XIEITE_DETAIL_187(macro), XIEITE_DETAIL_##macro(188)
#	define XIEITE_DETAIL_189(macro) XIEITE_DETAIL_188(macro), XIEITE_DETAIL_##macro(189)
#	define XIEITE_DETAIL_190(macro) XIEITE_DETAIL_189(macro), XIEITE_DETAIL_##macro(190)
#	define XIEITE_DETAIL_191(macro) XIEITE_DETAIL_190(macro), XIEITE_DETAIL_##macro(191)
#	define XIEITE_DETAIL_192(macro) XIEITE_DETAIL_191(macro), XIEITE_DETAIL_##macro(192)
#	define XIEITE_DETAIL_193(macro) XIEITE_DETAIL_192(macro), XIEITE_DETAIL_##macro(193)
#	define XIEITE_DETAIL_194(macro) XIEITE_DETAIL_193(macro), XIEITE_DETAIL_##macro(194)
#	define XIEITE_DETAIL_195(macro) XIEITE_DETAIL_194(macro), XIEITE_DETAIL_##macro(195)
#	define XIEITE_DETAIL_196(macro) XIEITE_DETAIL_195(macro), XIEITE_DETAIL_##macro(196)
#	define XIEITE_DETAIL_197(macro) XIEITE_DETAIL_196(macro), XIEITE_DETAIL_##macro(197)
#	define XIEITE_DETAIL_198(macro) XIEITE_DETAIL_197(macro), XIEITE_DETAIL_##macro(198)
#	define XIEITE_DETAIL_199(macro) XIEITE_DETAIL_198(macro), XIEITE_DETAIL_##macro(199)
#	define XIEITE_DETAIL_200(macro) XIEITE_DETAIL_199(macro), XIEITE_DETAIL_##macro(200)
#	define XIEITE_DETAIL_201(macro) XIEITE_DETAIL_200(macro), XIEITE_DETAIL_##macro(201)
#	define XIEITE_DETAIL_202(macro) XIEITE_DETAIL_201(macro), XIEITE_DETAIL_##macro(202)
#	define XIEITE_DETAIL_203(macro) XIEITE_DETAIL_202(macro), XIEITE_DETAIL_##macro(203)
#	define XIEITE_DETAIL_204(macro) XIEITE_DETAIL_203(macro), XIEITE_DETAIL_##macro(204)
#	define XIEITE_DETAIL_205(macro) XIEITE_DETAIL_204(macro), XIEITE_DETAIL_##macro(205)
#	define XIEITE_DETAIL_206(macro) XIEITE_DETAIL_205(macro), XIEITE_DETAIL_##macro(206)
#	define XIEITE_DETAIL_207(macro) XIEITE_DETAIL_206(macro), XIEITE_DETAIL_##macro(207)
#	define XIEITE_DETAIL_208(macro) XIEITE_DETAIL_207(macro), XIEITE_DETAIL_##macro(208)
#	define XIEITE_DETAIL_209(macro) XIEITE_DETAIL_208(macro), XIEITE_DETAIL_##macro(209)
#	define XIEITE_DETAIL_210(macro) XIEITE_DETAIL_209(macro), XIEITE_DETAIL_##macro(210)
#	define XIEITE_DETAIL_211(macro) XIEITE_DETAIL_210(macro), XIEITE_DETAIL_##macro(211)
#	define XIEITE_DETAIL_212(macro) XIEITE_DETAIL_211(macro), XIEITE_DETAIL_##macro(212)
#	define XIEITE_DETAIL_213(macro) XIEITE_DETAIL_212(macro), XIEITE_DETAIL_##macro(213)
#	define XIEITE_DETAIL_214(macro) XIEITE_DETAIL_213(macro), XIEITE_DETAIL_##macro(214)
#	define XIEITE_DETAIL_215(macro) XIEITE_DETAIL_214(macro), XIEITE_DETAIL_##macro(215)
#	define XIEITE_DETAIL_216(macro) XIEITE_DETAIL_215(macro), XIEITE_DETAIL_##macro(216)
#	define XIEITE_DETAIL_217(macro) XIEITE_DETAIL_216(macro), XIEITE_DETAIL_##macro(217)
#	define XIEITE_DETAIL_218(macro) XIEITE_DETAIL_217(macro), XIEITE_DETAIL_##macro(218)
#	define XIEITE_DETAIL_219(macro) XIEITE_DETAIL_218(macro), XIEITE_DETAIL_##macro(219)
#	define XIEITE_DETAIL_220(macro) XIEITE_DETAIL_219(macro), XIEITE_DETAIL_##macro(220)
#	define XIEITE_DETAIL_221(macro) XIEITE_DETAIL_220(macro), XIEITE_DETAIL_##macro(221)
#	define XIEITE_DETAIL_222(macro) XIEITE_DETAIL_221(macro), XIEITE_DETAIL_##macro(222)
#	define XIEITE_DETAIL_223(macro) XIEITE_DETAIL_222(macro), XIEITE_DETAIL_##macro(223)
#	define XIEITE_DETAIL_224(macro) XIEITE_DETAIL_223(macro), XIEITE_DETAIL_##macro(224)
#	define XIEITE_DETAIL_225(macro) XIEITE_DETAIL_224(macro), XIEITE_DETAIL_##macro(225)
#	define XIEITE_DETAIL_226(macro) XIEITE_DETAIL_225(macro), XIEITE_DETAIL_##macro(226)
#	define XIEITE_DETAIL_227(macro) XIEITE_DETAIL_226(macro), XIEITE_DETAIL_##macro(227)
#	define XIEITE_DETAIL_228(macro) XIEITE_DETAIL_227(macro), XIEITE_DETAIL_##macro(228)
#	define XIEITE_DETAIL_229(macro) XIEITE_DETAIL_228(macro), XIEITE_DETAIL_##macro(229)
#	define XIEITE_DETAIL_230(macro) XIEITE_DETAIL_229(macro), XIEITE_DETAIL_##macro(230)
#	define XIEITE_DETAIL_231(macro) XIEITE_DETAIL_230(macro), XIEITE_DETAIL_##macro(231)
#	define XIEITE_DETAIL_232(macro) XIEITE_DETAIL_231(macro), XIEITE_DETAIL_##macro(232)
#	define XIEITE_DETAIL_233(macro) XIEITE_DETAIL_232(macro), XIEITE_DETAIL_##macro(233)
#	define XIEITE_DETAIL_234(macro) XIEITE_DETAIL_233(macro), XIEITE_DETAIL_##macro(234)
#	define XIEITE_DETAIL_235(macro) XIEITE_DETAIL_234(macro), XIEITE_DETAIL_##macro(235)
#	define XIEITE_DETAIL_236(macro) XIEITE_DETAIL_235(macro), XIEITE_DETAIL_##macro(236)
#	define XIEITE_DETAIL_237(macro) XIEITE_DETAIL_236(macro), XIEITE_DETAIL_##macro(237)
#	define XIEITE_DETAIL_238(macro) XIEITE_DETAIL_237(macro), XIEITE_DETAIL_##macro(238)
#	define XIEITE_DETAIL_239(macro) XIEITE_DETAIL_238(macro), XIEITE_DETAIL_##macro(239)
#	define XIEITE_DETAIL_240(macro) XIEITE_DETAIL_239(macro), XIEITE_DETAIL_##macro(240)
#	define XIEITE_DETAIL_241(macro) XIEITE_DETAIL_240(macro), XIEITE_DETAIL_##macro(241)
#	define XIEITE_DETAIL_242(macro) XIEITE_DETAIL_241(macro), XIEITE_DETAIL_##macro(242)
#	define XIEITE_DETAIL_243(macro) XIEITE_DETAIL_242(macro), XIEITE_DETAIL_##macro(243)
#	define XIEITE_DETAIL_244(macro) XIEITE_DETAIL_243(macro), XIEITE_DETAIL_##macro(244)
#	define XIEITE_DETAIL_245(macro) XIEITE_DETAIL_244(macro), XIEITE_DETAIL_##macro(245)
#	define XIEITE_DETAIL_246(macro) XIEITE_DETAIL_245(macro), XIEITE_DETAIL_##macro(246)
#	define XIEITE_DETAIL_247(macro) XIEITE_DETAIL_246(macro), XIEITE_DETAIL_##macro(247)
#	define XIEITE_DETAIL_248(macro) XIEITE_DETAIL_247(macro), XIEITE_DETAIL_##macro(248)
#	define XIEITE_DETAIL_249(macro) XIEITE_DETAIL_248(macro), XIEITE_DETAIL_##macro(249)
#	define XIEITE_DETAIL_250(macro) XIEITE_DETAIL_249(macro), XIEITE_DETAIL_##macro(250)
#	define XIEITE_DETAIL_251(macro) XIEITE_DETAIL_250(macro), XIEITE_DETAIL_##macro(251)
#	define XIEITE_DETAIL_252(macro) XIEITE_DETAIL_251(macro), XIEITE_DETAIL_##macro(252)
#	define XIEITE_DETAIL_253(macro) XIEITE_DETAIL_252(macro), XIEITE_DETAIL_##macro(253)
#	define XIEITE_DETAIL_254(macro) XIEITE_DETAIL_253(macro), XIEITE_DETAIL_##macro(254)
#	define XIEITE_DETAIL_255(macro) XIEITE_DETAIL_254(macro), XIEITE_DETAIL_##macro(255)
#	define XIEITE_DETAIL_256(macro) XIEITE_DETAIL_255(macro), XIEITE_DETAIL_##macro(256)
#	define XIEITE_DETAIL_257(count) _##count
#	define XIEITE_DETAIL_258(count) std::forward<xieite::types::CollapseReference<decltype(_##count), Structure>>(_##count)
#	define XIEITE_DETAIL_259(count) \
		template<typename... Values, typename Structure> \
		requires(sizeof...(Values) == (count + 1)) \
		[[nodiscard]] constexpr std::tuple<Values...> tupleify(Structure&& structure) { \
			auto&& [XIEITE_DETAIL_##count(257)] = structure; \
			return std::tuple<Values...>(XIEITE_DETAIL_##count(258)); \
		}

namespace xieite::containers {
	template<typename Structure>
	[[nodiscard]] constexpr std::tuple<> tupleify(Structure&&) noexcept {
		return std::tuple<>();
	}

	XIEITE_DETAIL_259(0)
	XIEITE_DETAIL_259(1)
	XIEITE_DETAIL_259(2)
	XIEITE_DETAIL_259(3)
	XIEITE_DETAIL_259(4)
	XIEITE_DETAIL_259(5)
	XIEITE_DETAIL_259(6)
	XIEITE_DETAIL_259(7)
	XIEITE_DETAIL_259(8)
	XIEITE_DETAIL_259(9)
	XIEITE_DETAIL_259(10)
	XIEITE_DETAIL_259(11)
	XIEITE_DETAIL_259(12)
	XIEITE_DETAIL_259(13)
	XIEITE_DETAIL_259(14)
	XIEITE_DETAIL_259(15)
	XIEITE_DETAIL_259(16)
	XIEITE_DETAIL_259(17)
	XIEITE_DETAIL_259(18)
	XIEITE_DETAIL_259(19)
	XIEITE_DETAIL_259(20)
	XIEITE_DETAIL_259(21)
	XIEITE_DETAIL_259(22)
	XIEITE_DETAIL_259(23)
	XIEITE_DETAIL_259(24)
	XIEITE_DETAIL_259(25)
	XIEITE_DETAIL_259(26)
	XIEITE_DETAIL_259(27)
	XIEITE_DETAIL_259(28)
	XIEITE_DETAIL_259(29)
	XIEITE_DETAIL_259(30)
	XIEITE_DETAIL_259(31)
	XIEITE_DETAIL_259(32)
	XIEITE_DETAIL_259(33)
	XIEITE_DETAIL_259(34)
	XIEITE_DETAIL_259(35)
	XIEITE_DETAIL_259(36)
	XIEITE_DETAIL_259(37)
	XIEITE_DETAIL_259(38)
	XIEITE_DETAIL_259(39)
	XIEITE_DETAIL_259(40)
	XIEITE_DETAIL_259(41)
	XIEITE_DETAIL_259(42)
	XIEITE_DETAIL_259(43)
	XIEITE_DETAIL_259(44)
	XIEITE_DETAIL_259(45)
	XIEITE_DETAIL_259(46)
	XIEITE_DETAIL_259(47)
	XIEITE_DETAIL_259(48)
	XIEITE_DETAIL_259(49)
	XIEITE_DETAIL_259(50)
	XIEITE_DETAIL_259(51)
	XIEITE_DETAIL_259(52)
	XIEITE_DETAIL_259(53)
	XIEITE_DETAIL_259(54)
	XIEITE_DETAIL_259(55)
	XIEITE_DETAIL_259(56)
	XIEITE_DETAIL_259(57)
	XIEITE_DETAIL_259(58)
	XIEITE_DETAIL_259(59)
	XIEITE_DETAIL_259(60)
	XIEITE_DETAIL_259(61)
	XIEITE_DETAIL_259(62)
	XIEITE_DETAIL_259(63)
	XIEITE_DETAIL_259(64)
	XIEITE_DETAIL_259(65)
	XIEITE_DETAIL_259(66)
	XIEITE_DETAIL_259(67)
	XIEITE_DETAIL_259(68)
	XIEITE_DETAIL_259(69)
	XIEITE_DETAIL_259(70)
	XIEITE_DETAIL_259(71)
	XIEITE_DETAIL_259(72)
	XIEITE_DETAIL_259(73)
	XIEITE_DETAIL_259(74)
	XIEITE_DETAIL_259(75)
	XIEITE_DETAIL_259(76)
	XIEITE_DETAIL_259(77)
	XIEITE_DETAIL_259(78)
	XIEITE_DETAIL_259(79)
	XIEITE_DETAIL_259(80)
	XIEITE_DETAIL_259(81)
	XIEITE_DETAIL_259(82)
	XIEITE_DETAIL_259(83)
	XIEITE_DETAIL_259(84)
	XIEITE_DETAIL_259(85)
	XIEITE_DETAIL_259(86)
	XIEITE_DETAIL_259(87)
	XIEITE_DETAIL_259(88)
	XIEITE_DETAIL_259(89)
	XIEITE_DETAIL_259(90)
	XIEITE_DETAIL_259(91)
	XIEITE_DETAIL_259(92)
	XIEITE_DETAIL_259(93)
	XIEITE_DETAIL_259(94)
	XIEITE_DETAIL_259(95)
	XIEITE_DETAIL_259(96)
	XIEITE_DETAIL_259(97)
	XIEITE_DETAIL_259(98)
	XIEITE_DETAIL_259(99)
	XIEITE_DETAIL_259(100)
	XIEITE_DETAIL_259(101)
	XIEITE_DETAIL_259(102)
	XIEITE_DETAIL_259(103)
	XIEITE_DETAIL_259(104)
	XIEITE_DETAIL_259(105)
	XIEITE_DETAIL_259(106)
	XIEITE_DETAIL_259(107)
	XIEITE_DETAIL_259(108)
	XIEITE_DETAIL_259(109)
	XIEITE_DETAIL_259(110)
	XIEITE_DETAIL_259(111)
	XIEITE_DETAIL_259(112)
	XIEITE_DETAIL_259(113)
	XIEITE_DETAIL_259(114)
	XIEITE_DETAIL_259(115)
	XIEITE_DETAIL_259(116)
	XIEITE_DETAIL_259(117)
	XIEITE_DETAIL_259(118)
	XIEITE_DETAIL_259(119)
	XIEITE_DETAIL_259(120)
	XIEITE_DETAIL_259(121)
	XIEITE_DETAIL_259(122)
	XIEITE_DETAIL_259(123)
	XIEITE_DETAIL_259(124)
	XIEITE_DETAIL_259(125)
	XIEITE_DETAIL_259(126)
	XIEITE_DETAIL_259(127)
	XIEITE_DETAIL_259(128)
	XIEITE_DETAIL_259(129)
	XIEITE_DETAIL_259(130)
	XIEITE_DETAIL_259(131)
	XIEITE_DETAIL_259(132)
	XIEITE_DETAIL_259(133)
	XIEITE_DETAIL_259(134)
	XIEITE_DETAIL_259(135)
	XIEITE_DETAIL_259(136)
	XIEITE_DETAIL_259(137)
	XIEITE_DETAIL_259(138)
	XIEITE_DETAIL_259(139)
	XIEITE_DETAIL_259(140)
	XIEITE_DETAIL_259(141)
	XIEITE_DETAIL_259(142)
	XIEITE_DETAIL_259(143)
	XIEITE_DETAIL_259(144)
	XIEITE_DETAIL_259(145)
	XIEITE_DETAIL_259(146)
	XIEITE_DETAIL_259(147)
	XIEITE_DETAIL_259(148)
	XIEITE_DETAIL_259(149)
	XIEITE_DETAIL_259(150)
	XIEITE_DETAIL_259(151)
	XIEITE_DETAIL_259(152)
	XIEITE_DETAIL_259(153)
	XIEITE_DETAIL_259(154)
	XIEITE_DETAIL_259(155)
	XIEITE_DETAIL_259(156)
	XIEITE_DETAIL_259(157)
	XIEITE_DETAIL_259(158)
	XIEITE_DETAIL_259(159)
	XIEITE_DETAIL_259(160)
	XIEITE_DETAIL_259(161)
	XIEITE_DETAIL_259(162)
	XIEITE_DETAIL_259(163)
	XIEITE_DETAIL_259(164)
	XIEITE_DETAIL_259(165)
	XIEITE_DETAIL_259(166)
	XIEITE_DETAIL_259(167)
	XIEITE_DETAIL_259(168)
	XIEITE_DETAIL_259(169)
	XIEITE_DETAIL_259(170)
	XIEITE_DETAIL_259(171)
	XIEITE_DETAIL_259(172)
	XIEITE_DETAIL_259(173)
	XIEITE_DETAIL_259(174)
	XIEITE_DETAIL_259(175)
	XIEITE_DETAIL_259(176)
	XIEITE_DETAIL_259(177)
	XIEITE_DETAIL_259(178)
	XIEITE_DETAIL_259(179)
	XIEITE_DETAIL_259(180)
	XIEITE_DETAIL_259(181)
	XIEITE_DETAIL_259(182)
	XIEITE_DETAIL_259(183)
	XIEITE_DETAIL_259(184)
	XIEITE_DETAIL_259(185)
	XIEITE_DETAIL_259(186)
	XIEITE_DETAIL_259(187)
	XIEITE_DETAIL_259(188)
	XIEITE_DETAIL_259(189)
	XIEITE_DETAIL_259(190)
	XIEITE_DETAIL_259(191)
	XIEITE_DETAIL_259(192)
	XIEITE_DETAIL_259(193)
	XIEITE_DETAIL_259(194)
	XIEITE_DETAIL_259(195)
	XIEITE_DETAIL_259(196)
	XIEITE_DETAIL_259(197)
	XIEITE_DETAIL_259(198)
	XIEITE_DETAIL_259(199)
	XIEITE_DETAIL_259(200)
	XIEITE_DETAIL_259(201)
	XIEITE_DETAIL_259(202)
	XIEITE_DETAIL_259(203)
	XIEITE_DETAIL_259(204)
	XIEITE_DETAIL_259(205)
	XIEITE_DETAIL_259(206)
	XIEITE_DETAIL_259(207)
	XIEITE_DETAIL_259(208)
	XIEITE_DETAIL_259(209)
	XIEITE_DETAIL_259(210)
	XIEITE_DETAIL_259(211)
	XIEITE_DETAIL_259(212)
	XIEITE_DETAIL_259(213)
	XIEITE_DETAIL_259(214)
	XIEITE_DETAIL_259(215)
	XIEITE_DETAIL_259(216)
	XIEITE_DETAIL_259(217)
	XIEITE_DETAIL_259(218)
	XIEITE_DETAIL_259(219)
	XIEITE_DETAIL_259(220)
	XIEITE_DETAIL_259(221)
	XIEITE_DETAIL_259(222)
	XIEITE_DETAIL_259(223)
	XIEITE_DETAIL_259(224)
	XIEITE_DETAIL_259(225)
	XIEITE_DETAIL_259(226)
	XIEITE_DETAIL_259(227)
	XIEITE_DETAIL_259(228)
	XIEITE_DETAIL_259(229)
	XIEITE_DETAIL_259(230)
	XIEITE_DETAIL_259(231)
	XIEITE_DETAIL_259(232)
	XIEITE_DETAIL_259(233)
	XIEITE_DETAIL_259(234)
	XIEITE_DETAIL_259(235)
	XIEITE_DETAIL_259(236)
	XIEITE_DETAIL_259(237)
	XIEITE_DETAIL_259(238)
	XIEITE_DETAIL_259(239)
	XIEITE_DETAIL_259(240)
	XIEITE_DETAIL_259(241)
	XIEITE_DETAIL_259(242)
	XIEITE_DETAIL_259(243)
	XIEITE_DETAIL_259(244)
	XIEITE_DETAIL_259(245)
	XIEITE_DETAIL_259(246)
	XIEITE_DETAIL_259(247)
	XIEITE_DETAIL_259(248)
	XIEITE_DETAIL_259(249)
	XIEITE_DETAIL_259(250)
	XIEITE_DETAIL_259(251)
	XIEITE_DETAIL_259(252)
	XIEITE_DETAIL_259(253)
	XIEITE_DETAIL_259(254)
	XIEITE_DETAIL_259(255)
	XIEITE_DETAIL_259(256)
}

#	undef XIEITE_DETAIL_0
#	undef XIEITE_DETAIL_1
#	undef XIEITE_DETAIL_2
#	undef XIEITE_DETAIL_3
#	undef XIEITE_DETAIL_4
#	undef XIEITE_DETAIL_5
#	undef XIEITE_DETAIL_6
#	undef XIEITE_DETAIL_7
#	undef XIEITE_DETAIL_8
#	undef XIEITE_DETAIL_9
#	undef XIEITE_DETAIL_10
#	undef XIEITE_DETAIL_11
#	undef XIEITE_DETAIL_12
#	undef XIEITE_DETAIL_13
#	undef XIEITE_DETAIL_14
#	undef XIEITE_DETAIL_15
#	undef XIEITE_DETAIL_16
#	undef XIEITE_DETAIL_17
#	undef XIEITE_DETAIL_18
#	undef XIEITE_DETAIL_19
#	undef XIEITE_DETAIL_20
#	undef XIEITE_DETAIL_21
#	undef XIEITE_DETAIL_22
#	undef XIEITE_DETAIL_23
#	undef XIEITE_DETAIL_24
#	undef XIEITE_DETAIL_25
#	undef XIEITE_DETAIL_26
#	undef XIEITE_DETAIL_27
#	undef XIEITE_DETAIL_28
#	undef XIEITE_DETAIL_29
#	undef XIEITE_DETAIL_30
#	undef XIEITE_DETAIL_31
#	undef XIEITE_DETAIL_32
#	undef XIEITE_DETAIL_33
#	undef XIEITE_DETAIL_34
#	undef XIEITE_DETAIL_35
#	undef XIEITE_DETAIL_36
#	undef XIEITE_DETAIL_37
#	undef XIEITE_DETAIL_38
#	undef XIEITE_DETAIL_39
#	undef XIEITE_DETAIL_40
#	undef XIEITE_DETAIL_41
#	undef XIEITE_DETAIL_42
#	undef XIEITE_DETAIL_43
#	undef XIEITE_DETAIL_44
#	undef XIEITE_DETAIL_45
#	undef XIEITE_DETAIL_46
#	undef XIEITE_DETAIL_47
#	undef XIEITE_DETAIL_48
#	undef XIEITE_DETAIL_49
#	undef XIEITE_DETAIL_50
#	undef XIEITE_DETAIL_51
#	undef XIEITE_DETAIL_52
#	undef XIEITE_DETAIL_53
#	undef XIEITE_DETAIL_54
#	undef XIEITE_DETAIL_55
#	undef XIEITE_DETAIL_56
#	undef XIEITE_DETAIL_57
#	undef XIEITE_DETAIL_58
#	undef XIEITE_DETAIL_59
#	undef XIEITE_DETAIL_60
#	undef XIEITE_DETAIL_61
#	undef XIEITE_DETAIL_62
#	undef XIEITE_DETAIL_63
#	undef XIEITE_DETAIL_64
#	undef XIEITE_DETAIL_65
#	undef XIEITE_DETAIL_66
#	undef XIEITE_DETAIL_67
#	undef XIEITE_DETAIL_68
#	undef XIEITE_DETAIL_69
#	undef XIEITE_DETAIL_70
#	undef XIEITE_DETAIL_71
#	undef XIEITE_DETAIL_72
#	undef XIEITE_DETAIL_73
#	undef XIEITE_DETAIL_74
#	undef XIEITE_DETAIL_75
#	undef XIEITE_DETAIL_76
#	undef XIEITE_DETAIL_77
#	undef XIEITE_DETAIL_78
#	undef XIEITE_DETAIL_79
#	undef XIEITE_DETAIL_80
#	undef XIEITE_DETAIL_81
#	undef XIEITE_DETAIL_82
#	undef XIEITE_DETAIL_83
#	undef XIEITE_DETAIL_84
#	undef XIEITE_DETAIL_85
#	undef XIEITE_DETAIL_86
#	undef XIEITE_DETAIL_87
#	undef XIEITE_DETAIL_88
#	undef XIEITE_DETAIL_89
#	undef XIEITE_DETAIL_90
#	undef XIEITE_DETAIL_91
#	undef XIEITE_DETAIL_92
#	undef XIEITE_DETAIL_93
#	undef XIEITE_DETAIL_94
#	undef XIEITE_DETAIL_95
#	undef XIEITE_DETAIL_96
#	undef XIEITE_DETAIL_97
#	undef XIEITE_DETAIL_98
#	undef XIEITE_DETAIL_99
#	undef XIEITE_DETAIL_100
#	undef XIEITE_DETAIL_101
#	undef XIEITE_DETAIL_102
#	undef XIEITE_DETAIL_103
#	undef XIEITE_DETAIL_104
#	undef XIEITE_DETAIL_105
#	undef XIEITE_DETAIL_106
#	undef XIEITE_DETAIL_107
#	undef XIEITE_DETAIL_108
#	undef XIEITE_DETAIL_109
#	undef XIEITE_DETAIL_110
#	undef XIEITE_DETAIL_111
#	undef XIEITE_DETAIL_112
#	undef XIEITE_DETAIL_113
#	undef XIEITE_DETAIL_114
#	undef XIEITE_DETAIL_115
#	undef XIEITE_DETAIL_116
#	undef XIEITE_DETAIL_117
#	undef XIEITE_DETAIL_118
#	undef XIEITE_DETAIL_119
#	undef XIEITE_DETAIL_120
#	undef XIEITE_DETAIL_121
#	undef XIEITE_DETAIL_122
#	undef XIEITE_DETAIL_123
#	undef XIEITE_DETAIL_124
#	undef XIEITE_DETAIL_125
#	undef XIEITE_DETAIL_126
#	undef XIEITE_DETAIL_127
#	undef XIEITE_DETAIL_128
#	undef XIEITE_DETAIL_129
#	undef XIEITE_DETAIL_130
#	undef XIEITE_DETAIL_131
#	undef XIEITE_DETAIL_132
#	undef XIEITE_DETAIL_133
#	undef XIEITE_DETAIL_134
#	undef XIEITE_DETAIL_135
#	undef XIEITE_DETAIL_136
#	undef XIEITE_DETAIL_137
#	undef XIEITE_DETAIL_138
#	undef XIEITE_DETAIL_139
#	undef XIEITE_DETAIL_140
#	undef XIEITE_DETAIL_141
#	undef XIEITE_DETAIL_142
#	undef XIEITE_DETAIL_143
#	undef XIEITE_DETAIL_144
#	undef XIEITE_DETAIL_145
#	undef XIEITE_DETAIL_146
#	undef XIEITE_DETAIL_147
#	undef XIEITE_DETAIL_148
#	undef XIEITE_DETAIL_149
#	undef XIEITE_DETAIL_150
#	undef XIEITE_DETAIL_151
#	undef XIEITE_DETAIL_152
#	undef XIEITE_DETAIL_153
#	undef XIEITE_DETAIL_154
#	undef XIEITE_DETAIL_155
#	undef XIEITE_DETAIL_156
#	undef XIEITE_DETAIL_157
#	undef XIEITE_DETAIL_158
#	undef XIEITE_DETAIL_159
#	undef XIEITE_DETAIL_160
#	undef XIEITE_DETAIL_161
#	undef XIEITE_DETAIL_162
#	undef XIEITE_DETAIL_163
#	undef XIEITE_DETAIL_164
#	undef XIEITE_DETAIL_165
#	undef XIEITE_DETAIL_166
#	undef XIEITE_DETAIL_167
#	undef XIEITE_DETAIL_168
#	undef XIEITE_DETAIL_169
#	undef XIEITE_DETAIL_170
#	undef XIEITE_DETAIL_171
#	undef XIEITE_DETAIL_172
#	undef XIEITE_DETAIL_173
#	undef XIEITE_DETAIL_174
#	undef XIEITE_DETAIL_175
#	undef XIEITE_DETAIL_176
#	undef XIEITE_DETAIL_177
#	undef XIEITE_DETAIL_178
#	undef XIEITE_DETAIL_179
#	undef XIEITE_DETAIL_180
#	undef XIEITE_DETAIL_181
#	undef XIEITE_DETAIL_182
#	undef XIEITE_DETAIL_183
#	undef XIEITE_DETAIL_184
#	undef XIEITE_DETAIL_185
#	undef XIEITE_DETAIL_186
#	undef XIEITE_DETAIL_187
#	undef XIEITE_DETAIL_188
#	undef XIEITE_DETAIL_189
#	undef XIEITE_DETAIL_190
#	undef XIEITE_DETAIL_191
#	undef XIEITE_DETAIL_192
#	undef XIEITE_DETAIL_193
#	undef XIEITE_DETAIL_194
#	undef XIEITE_DETAIL_195
#	undef XIEITE_DETAIL_196
#	undef XIEITE_DETAIL_197
#	undef XIEITE_DETAIL_198
#	undef XIEITE_DETAIL_199
#	undef XIEITE_DETAIL_200
#	undef XIEITE_DETAIL_201
#	undef XIEITE_DETAIL_202
#	undef XIEITE_DETAIL_203
#	undef XIEITE_DETAIL_204
#	undef XIEITE_DETAIL_205
#	undef XIEITE_DETAIL_206
#	undef XIEITE_DETAIL_207
#	undef XIEITE_DETAIL_208
#	undef XIEITE_DETAIL_209
#	undef XIEITE_DETAIL_210
#	undef XIEITE_DETAIL_211
#	undef XIEITE_DETAIL_212
#	undef XIEITE_DETAIL_213
#	undef XIEITE_DETAIL_214
#	undef XIEITE_DETAIL_215
#	undef XIEITE_DETAIL_216
#	undef XIEITE_DETAIL_217
#	undef XIEITE_DETAIL_218
#	undef XIEITE_DETAIL_219
#	undef XIEITE_DETAIL_220
#	undef XIEITE_DETAIL_221
#	undef XIEITE_DETAIL_222
#	undef XIEITE_DETAIL_223
#	undef XIEITE_DETAIL_224
#	undef XIEITE_DETAIL_225
#	undef XIEITE_DETAIL_226
#	undef XIEITE_DETAIL_227
#	undef XIEITE_DETAIL_228
#	undef XIEITE_DETAIL_229
#	undef XIEITE_DETAIL_230
#	undef XIEITE_DETAIL_231
#	undef XIEITE_DETAIL_232
#	undef XIEITE_DETAIL_233
#	undef XIEITE_DETAIL_234
#	undef XIEITE_DETAIL_235
#	undef XIEITE_DETAIL_236
#	undef XIEITE_DETAIL_237
#	undef XIEITE_DETAIL_238
#	undef XIEITE_DETAIL_239
#	undef XIEITE_DETAIL_240
#	undef XIEITE_DETAIL_241
#	undef XIEITE_DETAIL_242
#	undef XIEITE_DETAIL_243
#	undef XIEITE_DETAIL_244
#	undef XIEITE_DETAIL_245
#	undef XIEITE_DETAIL_246
#	undef XIEITE_DETAIL_247
#	undef XIEITE_DETAIL_248
#	undef XIEITE_DETAIL_249
#	undef XIEITE_DETAIL_250
#	undef XIEITE_DETAIL_251
#	undef XIEITE_DETAIL_252
#	undef XIEITE_DETAIL_253
#	undef XIEITE_DETAIL_254
#	undef XIEITE_DETAIL_255
#	undef XIEITE_DETAIL_256
#	undef XIEITE_DETAIL_257
#	undef XIEITE_DETAIL_258
#	undef XIEITE_DETAIL_259

#endif

// Thanks to halalaluyafail3 for help and corrections
