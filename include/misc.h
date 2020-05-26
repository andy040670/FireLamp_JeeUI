/*
Copyright © 2020 Dmytro Korniienko (kDn)
JeeUI2 lib used under MIT License Copyright (c) 2019 Marsel Akhkamov

    This file is part of FireLamp_JeeUI.

    FireLamp_JeeUI is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    FireLamp_JeeUI is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with FireLamp_JeeUI.  If not, see <https://www.gnu.org/licenses/>.

  (Этот файл — часть FireLamp_JeeUI.

   FireLamp_JeeUI - свободная программа: вы можете перераспространять ее и/или
   изменять ее на условиях Стандартной общественной лицензии GNU в том виде,
   в каком она была опубликована Фондом свободного программного обеспечения;
   либо версии 3 лицензии, либо (по вашему выбору) любой более поздней
   версии.

   FireLamp_JeeUI распространяется в надежде, что она будет полезной,
   но БЕЗО ВСЯКИХ ГАРАНТИЙ; даже без неявной гарантии ТОВАРНОГО ВИДА
   или ПРИГОДНОСТИ ДЛЯ ОПРЕДЕЛЕННЫХ ЦЕЛЕЙ. Подробнее см. в Стандартной
   общественной лицензии GNU.

   Вы должны были получить копию Стандартной общественной лицензии GNU
   вместе с этой программой. Если это не так, см.
   <https://www.gnu.org/licenses/>.)
*/

#pragma once
#include <Arduino.h>

// шрифты для вывода текста
const uint8_t fontHEX[][5] PROGMEM = {
	{0x00, 0x00, 0x00, 0x00, 0x00}, //   0x20 32
	{0x00, 0x00, 0x6f, 0x00, 0x00}, // ! 0x21 33
	{0x00, 0x07, 0x00, 0x07, 0x00}, // " 0x22 34
	{0x14, 0x7f, 0x14, 0x7f, 0x14}, // # 0x23 35
	{0x00, 0x07, 0x04, 0x1e, 0x00}, // $ 0x24 36
	{0x23, 0x13, 0x08, 0x64, 0x62}, // % 0x25 37
	{0x36, 0x49, 0x56, 0x20, 0x50}, // & 0x26 38
	{0x00, 0x00, 0x07, 0x00, 0x00}, // ' 0x27 39
	{0x00, 0x1c, 0x22, 0x41, 0x00}, // ( 0x28 40
	{0x00, 0x41, 0x22, 0x1c, 0x00}, // ) 0x29 41
	{0x14, 0x08, 0x3e, 0x08, 0x14}, // * 0x2A 42
	{0x08, 0x08, 0x3e, 0x08, 0x08}, // + 0x2B 43
	{0x00, 0x50, 0x30, 0x00, 0x00}, // , 0x2C 44
	{0x08, 0x08, 0x08, 0x08, 0x08}, // - 0x2D 45
	{0x00, 0x60, 0x60, 0x00, 0x00}, // . 0x2E 46
	{0x20, 0x10, 0x08, 0x04, 0x02}, // / 0x2F 47
	{0x3e, 0x51, 0x49, 0x45, 0x3e}, // 0 0x30 48
	{0x00, 0x42, 0x7f, 0x40, 0x00}, // 1 0x31 49
	{0x42, 0x61, 0x51, 0x49, 0x46}, // 2 0x32 50
	{0x21, 0x41, 0x45, 0x4b, 0x31}, // 3 0x33 51
	{0x18, 0x14, 0x12, 0x7f, 0x10}, // 4 0x34 52
	{0x27, 0x45, 0x45, 0x45, 0x39}, // 5 0x35 53
	{0x3c, 0x4a, 0x49, 0x49, 0x30}, // 6 0x36 54
	{0x01, 0x71, 0x09, 0x05, 0x03}, // 7 0x37 55
	{0x36, 0x49, 0x49, 0x49, 0x36}, // 8 0x38 56
	{0x06, 0x49, 0x49, 0x29, 0x1e}, // 9 0x39 57
	{0x00, 0x36, 0x36, 0x00, 0x00}, // : 0x3A 58
	{0x00, 0x56, 0x36, 0x00, 0x00}, // ; 0x3B 59
	{0x08, 0x14, 0x22, 0x41, 0x00}, // < 0x3C 60
	{0x14, 0x14, 0x14, 0x14, 0x14}, // = 0x3D 61
	{0x00, 0x41, 0x22, 0x14, 0x08}, // > 0x3E 62
	{0x02, 0x01, 0x51, 0x09, 0x06}, // ? 0x3F 63
	{0x3e, 0x41, 0x5d, 0x49, 0x4e}, // @ 0x40 64
	{0x7e, 0x09, 0x09, 0x09, 0x7e}, // A 0x41 65
	{0x7f, 0x49, 0x49, 0x49, 0x36}, // B 0x42 66
	{0x3e, 0x41, 0x41, 0x41, 0x22}, // C 0x43 67
	{0x7f, 0x41, 0x41, 0x41, 0x3e}, // D 0x44 68
	{0x7f, 0x49, 0x49, 0x49, 0x41}, // E 0x45 69
	{0x7f, 0x09, 0x09, 0x09, 0x01}, // F 0x46 70
	{0x3e, 0x41, 0x49, 0x49, 0x7a}, // G 0x47 71
	{0x7f, 0x08, 0x08, 0x08, 0x7f}, // H 0x48 72
	{0x00, 0x41, 0x7f, 0x41, 0x00}, // I 0x49 73
	{0x20, 0x40, 0x41, 0x3f, 0x01}, // J 0x4A 74
	{0x7f, 0x08, 0x14, 0x22, 0x41}, // K 0x4B 75
	{0x7f, 0x40, 0x40, 0x40, 0x40}, // L 0x4C 76
	{0x7f, 0x02, 0x0c, 0x02, 0x7f}, // M 0x4D 77
	{0x7f, 0x04, 0x08, 0x10, 0x7f}, // N 0x4E 78
	{0x3e, 0x41, 0x41, 0x41, 0x3e}, // O 0x4F 79
	{0x7f, 0x09, 0x09, 0x09, 0x06}, // P 0x50 80
	{0x3e, 0x41, 0x51, 0x21, 0x5e}, // Q 0x51 81
	{0x7f, 0x09, 0x19, 0x29, 0x46}, // R 0x52 82
	{0x46, 0x49, 0x49, 0x49, 0x31}, // S 0x53 83
	{0x01, 0x01, 0x7f, 0x01, 0x01}, // T 0x54 84
	{0x3f, 0x40, 0x40, 0x40, 0x3f}, // U 0x55 85
	{0x0f, 0x30, 0x40, 0x30, 0x0f}, // V 0x56 86
	{0x3f, 0x40, 0x30, 0x40, 0x3f}, // W 0x57 87
	{0x63, 0x14, 0x08, 0x14, 0x63}, // X 0x58 88
	{0x07, 0x08, 0x70, 0x08, 0x07}, // Y 0x59 89
	{0x61, 0x51, 0x49, 0x45, 0x43}, // Z 0x5A 90
	{0x3c, 0x4a, 0x49, 0x29, 0x1e}, // [ 0x5B 91
	{0x02, 0x04, 0x08, 0x10, 0x20}, // \ 0x5C 92
	{0x00, 0x41, 0x7f, 0x00, 0x00}, // ] 0x5D 93
	{0x04, 0x02, 0x01, 0x02, 0x04}, // ^ 0x5E 94
	{0x40, 0x40, 0x40, 0x40, 0x40}, // _ 0x5F 95
	{0x00, 0x00, 0x03, 0x04, 0x00}, // ` 0x60 96
	{0x20, 0x54, 0x54, 0x54, 0x78}, // a 0x61 97
	{0x7f, 0x48, 0x44, 0x44, 0x38}, // b 0x62 98
	{0x38, 0x44, 0x44, 0x44, 0x20}, // c 0x63 99
	{0x38, 0x44, 0x44, 0x48, 0x7f}, // d 0x64 100
	{0x38, 0x54, 0x54, 0x54, 0x18}, // e 0x65 101
	{0x08, 0x7e, 0x09, 0x01, 0x02}, // f 0x66 102
	{0x0c, 0x52, 0x52, 0x52, 0x3e}, // g 0x67 103
	{0x7f, 0x08, 0x04, 0x04, 0x78}, // h 0x68 104
	{0x00, 0x44, 0x7d, 0x40, 0x00}, // i 0x69 105
	{0x20, 0x40, 0x44, 0x3d, 0x00}, // j 0x6A 106
	{0x00, 0x7f, 0x10, 0x28, 0x44}, // k 0x6B 107
	{0x00, 0x41, 0x7f, 0x40, 0x00}, // l 0x6C 108
	{0x7c, 0x04, 0x18, 0x04, 0x78}, // m 0x6D 109
	{0x7c, 0x08, 0x04, 0x04, 0x78}, // n 0x6E 110
	{0x38, 0x44, 0x44, 0x44, 0x38}, // o 0x6F 111
	{0x7c, 0x14, 0x14, 0x14, 0x08}, // p 0x70 112
	{0x08, 0x14, 0x14, 0x18, 0x7c}, // q 0x71 113
	{0x7c, 0x08, 0x04, 0x04, 0x08}, // r 0x72 114
	{0x48, 0x54, 0x54, 0x54, 0x20}, // s 0x73 115
	{0x04, 0x3f, 0x44, 0x40, 0x20}, // t 0x74 116
	{0x3c, 0x40, 0x40, 0x20, 0x7c}, // u 0x75 117
	{0x1c, 0x20, 0x40, 0x20, 0x1c}, // v 0x76 118
	{0x3c, 0x40, 0x30, 0x40, 0x3c}, // w 0x77 119
	{0x44, 0x28, 0x10, 0x28, 0x44}, // x 0x78 120
	{0x0c, 0x50, 0x50, 0x50, 0x3c}, // y 0x79 121
	{0x44, 0x64, 0x54, 0x4c, 0x44}, // z 0x7A 122
	{0x00, 0x08, 0x36, 0x41, 0x41}, // { 0x7B 123
	{0x00, 0x00, 0x7f, 0x00, 0x00}, // | 0x7C 124
	{0x41, 0x41, 0x36, 0x08, 0x00}, // } 0x7D 125
	{0x04, 0x02, 0x04, 0x08, 0x04}, // ~ 0x7E 126
	
	{0x7E, 0x11, 0x11, 0x11, 0x7E},	// А 0xC0 192
	{0x7F, 0x49, 0x49, 0x49, 0x33},	// Б 0xC1 193
	{0x7F, 0x49, 0x49, 0x49, 0x36},	// В 0xC2 194
	{0x7F, 0x01, 0x01, 0x01, 0x03},	// Г 0xC3 195
	{0xE0, 0x51, 0x4F, 0x41, 0xFF},	// Д 0xC4 196
	{0x7F, 0x49, 0x49, 0x49, 0x41},	// Е 0xC5 197
	{0x77, 0x08, 0x7F, 0x08, 0x77},	// Ж 0xC6 198
	{0x41, 0x49, 0x49, 0x49, 0x36},	// З 0xC7 199
	{0x7F, 0x10, 0x08, 0x04, 0x7F},	// И 0xC8 200
	{0x7C, 0x21, 0x12, 0x09, 0x7C},	// Й 0xC9 201
	{0x7F, 0x08, 0x14, 0x22, 0x41},	// К 0xCA 202
	{0x20, 0x41, 0x3F, 0x01, 0x7F},	// Л 0xCB 203
	{0x7F, 0x02, 0x0C, 0x02, 0x7F},	// М 0xCC 204
	{0x7F, 0x08, 0x08, 0x08, 0x7F},	// Н 0xCD 205
	{0x3E, 0x41, 0x41, 0x41, 0x3E},	// О 0xCE 206
	{0x7F, 0x01, 0x01, 0x01, 0x7F},	// П 0xCF 207
	{0x7F, 0x09, 0x09, 0x09, 0x06},	// Р 0xD0 208
	{0x3E, 0x41, 0x41, 0x41, 0x22},	// С 0xD1 209
	{0x01, 0x01, 0x7F, 0x01, 0x01},	// Т 0xD2 210
	{0x47, 0x28, 0x10, 0x08, 0x07},	// У 0xD3 211
	{0x1C, 0x22, 0x7F, 0x22, 0x1C},	// Ф 0xD4 212
	{0x63, 0x14, 0x08, 0x14, 0x63},	// Х 0xD5 213
	{0x7F, 0x40, 0x40, 0x40, 0xFF},	// Ц 0xD6 214
	{0x07, 0x08, 0x08, 0x08, 0x7F},	// Ч 0xD7 215
	{0x7F, 0x40, 0x7F, 0x40, 0x7F},	// Ш 0xD8 216
	{0x7F, 0x40, 0x7F, 0x40, 0xFF},	// Щ 0xD9 217
	{0x01, 0x7F, 0x48, 0x48, 0x30},	// Ъ 0xDA 218
	{0x7F, 0x48, 0x30, 0x00, 0x7F},	// Ы 0xDB 219
	{0x00, 0x7F, 0x48, 0x48, 0x30},	// Ь 0xDC 220
	{0x22, 0x41, 0x49, 0x49, 0x3E},	// Э 0xDD 221
	{0x7F, 0x08, 0x3E, 0x41, 0x3E},	// Ю 0xDE 222
	{0x46, 0x29, 0x19, 0x09, 0x7F},	// Я 0xDF 223

	{0x20, 0x54, 0x54, 0x54, 0x78},	// а 0xE0 224
	{0x3C, 0x4A, 0x4A, 0x49, 0x31},	// б 0xE1 225
	{0x7C, 0x54, 0x54, 0x28, 0x00},	// в 0xE2 226
	{0x7C, 0x04, 0x04, 0x0C, 0x00},	// г 0xE3 227
	{0xE0, 0x54, 0x4C, 0x44, 0xFC},	// д 0xE4 228
	{0x38, 0x54, 0x54, 0x54, 0x18},	// е 0xE5 229
	{0x6C, 0x10, 0x7C, 0x10, 0x6C},	// ж 0xE6 230
	{0x44, 0x54, 0x54, 0x28, 0x00},	// з 0xE7 231
	{0x7C, 0x20, 0x10, 0x08, 0x7C},	// и 0xE8 232
	{0x78, 0x42, 0x24, 0x12, 0x78},	// й 0xE9 233
	{0x7C, 0x10, 0x28, 0x44, 0x00},	// к 0xEA 234
	{0x20, 0x44, 0x3C, 0x04, 0x7C},	// л 0xEB 235
	{0x7C, 0x08, 0x10, 0x08, 0x7C},	// м 0xEC 236
	{0x7C, 0x10, 0x10, 0x10, 0x7C},	// н 0xED 237
	{0x38, 0x44, 0x44, 0x44, 0x38},	// о 0xEE 238
	{0x7C, 0x04, 0x04, 0x04, 0x7C},	// п 0xEF 239
	{0x7C, 0x14, 0x14, 0x14, 0x08},	// р 0xF0 240
	{0x38, 0x44, 0x44, 0x44, 0x00},	// с 0xF1 241
	{0x04, 0x04, 0x7C, 0x04, 0x04},	// т 0xF2 242
	{0x0C, 0x50, 0x50, 0x50, 0x3C},	// у 0xF3 243
	{0x30, 0x48, 0xFE, 0x48, 0x30},	// ф 0xF4 244
	{0x44, 0x28, 0x10, 0x28, 0x44},	// х 0xF5 245
	{0x7C, 0x40, 0x40, 0x7C, 0xC0},	// ц 0xF6 246
	{0x0C, 0x10, 0x10, 0x10, 0x7C},	// ч 0xF7 247
	{0x7C, 0x40, 0x7C, 0x40, 0x7C},	// ш 0xF8 248
	{0x7C, 0x40, 0x7C, 0x40, 0xFC},	// щ 0xF9 249
	{0x04, 0x7C, 0x50, 0x50, 0x20},	// ъ 0xFA 250
	{0x7C, 0x50, 0x50, 0x20, 0x7C},	// ы 0xFB 251
	{0x7C, 0x50, 0x50, 0x20, 0x00},	// ь 0xFC 252
	{0x28, 0x44, 0x54, 0x54, 0x38},	// э 0xFD 253
	{0x7C, 0x10, 0x38, 0x44, 0x38},	// ю 0xFE 254
	{0x08, 0x54, 0x34, 0x14, 0x7C},	// я 0xFF 255
	/*
	{0x7e, 0x09, 0x09, 0x09, 0x7e}, // А 192
	{0x7F, 0x49, 0x49, 0x49, 0x71}, // Б
	{0x7f, 0x49, 0x49, 0x49, 0x36}, // В
	{0x7F, 0x01, 0x01, 0x01, 0x01}, // Г
	{0x60, 0x3E, 0x21, 0x3F, 0x60}, // Д
	{0x7f, 0x49, 0x49, 0x49, 0x41}, // Е
	{0x76, 0x08, 0x7F, 0x08, 0x76}, // Ж
	{0x21, 0x41, 0x45, 0x4b, 0x31}, // З
	{0x7F, 0x20, 0x10, 0x08, 0x7F}, // И
	{0x7E, 0x20, 0x11, 0x08, 0x7E}, // Й
	{0x7f, 0x08, 0x14, 0x22, 0x41}, // К
	{0x70, 0x0E, 0x01, 0x01, 0x7F}, // Л
	{0x7f, 0x02, 0x0c, 0x02, 0x7f}, // М
	{0x7f, 0x08, 0x08, 0x08, 0x7f}, // Н
	{0x3e, 0x41, 0x41, 0x41, 0x3e}, // О
	{0x7F, 0x01, 0x01, 0x01, 0x7F}, // П
	{0x7f, 0x09, 0x09, 0x09, 0x06}, // Р
	{0x3e, 0x41, 0x41, 0x41, 0x22}, // С
	{0x01, 0x01, 0x7f, 0x01, 0x01}, // Т
	{0x07, 0x48, 0x48, 0x48, 0x7F}, // У
	{0x1C, 0x22, 0x7F, 0x22, 0x1C}, // Ф
	{0x63, 0x14, 0x08, 0x14, 0x63}, // Х
	{0x7F, 0x40, 0x40, 0x7F, 0xC0}, // Ц
	{0x07, 0x08, 0x08, 0x08, 0x7F}, // Ч
	{0x7F, 0x40, 0x7F, 0x40, 0x7F}, // Ш
	{0x7F, 0x40, 0x7F, 0x40, 0xFF}, // Щ
	{0x01, 0x7F, 0x48, 0x48, 0x70}, // Ъ
	{0x7F, 0x48, 0x70, 0x00, 0x7F}, // Ы
	{0x00, 0x7F, 0x48, 0x48, 0x70}, // Ь
	{0x22, 0x41, 0x49, 0x49, 0x3E}, // Э
	{0x7F, 0x08, 0x3E, 0x41, 0x3E}, // Ю
	{0x46, 0x29, 0x19, 0x09, 0x7F}, // Я 223

	{0x20, 0x54, 0x54, 0x54, 0x78}, //a 224
	{0x3c, 0x4a, 0x4a, 0x49, 0x31}, //б
	{0x7c, 0x54, 0x54, 0x28, 0x00}, //в
	{0x7c, 0x04, 0x04, 0x04, 0x0c}, //г
	{0xe0, 0x54, 0x4c, 0x44, 0xfc}, //д
	{0x38, 0x54, 0x54, 0x54, 0x18}, //e
	{0x6c, 0x10, 0x7c, 0x10, 0x6c}, //ж
	{0x44, 0x44, 0x54, 0x54, 0x28}, //з
	{0x7c, 0x20, 0x10, 0x08, 0x7c}, //и
	{0x7c, 0x41, 0x22, 0x11, 0x7c}, //й
	{0x7c, 0x10, 0x28, 0x44, 0x00}, //к
	{0x20, 0x44, 0x3c, 0x04, 0x7c}, //л
	{0x7c, 0x08, 0x10, 0x08, 0x7c}, //м
	{0x7c, 0x10, 0x10, 0x10, 0x7c}, //н
	{0x38, 0x44, 0x44, 0x44, 0x38}, //o
	{0x7c, 0x04, 0x04, 0x04, 0x7c}, //п
	{0x7C, 0x14, 0x14, 0x14, 0x08}, //p
	{0x38, 0x44, 0x44, 0x44, 0x20}, //c
	{0x04, 0x04, 0x7c, 0x04, 0x04}, //т
	{0x0C, 0x50, 0x50, 0x50, 0x3C}, //у
	{0x30, 0x48, 0xfc, 0x48, 0x30}, //ф
	{0x44, 0x28, 0x10, 0x28, 0x44}, //x
	{0x7c, 0x40, 0x40, 0x40, 0xfc}, //ц
	{0x0c, 0x10, 0x10, 0x10, 0x7c}, //ч
	{0x7c, 0x40, 0x7c, 0x40, 0x7c}, //ш
	{0x7c, 0x40, 0x7c, 0x40, 0xfc}, //щ
	{0x04, 0x7c, 0x50, 0x50, 0x20}, //ъ
	{0x7c, 0x50, 0x50, 0x20, 0x7c}, //ы
	{0x7c, 0x50, 0x50, 0x20, 0x00}, //ь
	{0x28, 0x44, 0x54, 0x54, 0x38}, //э
	{0x7c, 0x10, 0x38, 0x44, 0x38}, //ю
	{0x08, 0x54, 0x34, 0x14, 0x7c}, //я 255
*/
};

//----------------------------------------------------
// мини-класс таймера, версия 1.0

class timerMinim
{
  public:
	timerMinim() {_interval = 0;} // по дефолту - отключен

    timerMinim(uint32_t interval)				                  // объявление таймера с указанием интервала
    {
      _interval = interval;
      _timer = millis();
    }

    void setInterval(uint32_t interval)	                  // установка интервала работы таймера
    {
      _interval = interval;
    }

    bool isReady()						                              // возвращает true, когда пришло время. Сбрасывается в false сам (AUTO) или вручную (MANUAL)
    {
      if ((uint32_t)millis() - _timer >= _interval && _interval!=0){
        _timer = millis();
        return true;
      }
      else {
        return false;
      }
    }

    bool isReadyManual()                                   // возвращает true, когда пришло время. Без сбороса
    {
      if ((uint32_t)millis() - _timer >= _interval && _interval!=0){
        return true;
      }
      else {
        return false;
      }
    }

    void reset()							                              // ручной сброс таймера на установленный интервал
    {
      _timer = millis();
    }

  private:
    uint32_t _timer = 0;
    uint32_t _interval = 0;
};

//----------------------------------------------------
#if defined(LAMP_DEBUG) && DEBUG_TELNET_OUTPUT
	//#define LOG                   telnet
	#define LOG(func, ...) telnet.func(__VA_ARGS__)
#elif defined(LAMP_DEBUG)
	//#define LOG                   Serial
	#define LOG(func, ...) Serial.func(__VA_ARGS__)
#else
	#define LOG(func, ...) ;
#endif

#if defined(LAMP_DEBUG) && DEBUG_TELNET_OUTPUT
#define TELNET_PORT           (23U)                         // номер telnet порта
WiFiServer telnetServer(TELNET_PORT);                       // telnet сервер
WiFiClient telnet;                                          // обработчик событий telnet клиента
bool telnetGreetingShown = false;                           // признак "показано приветствие в telnet"

void handleTelnetClient()
{
  if (telnetServer.hasClient())
  {
    if (!telnet || !telnet.connected())
    {
      if (telnet)
      {
        telnet.stop();                                      // клиент отключился
        telnetGreetingShown = false;
      }
      telnet = telnetServer.available();                    // готов к подключению нового клиента
    }
    else
    {
      telnetServer.available().stop();                      // один клиент уже подключен, блокируем подключение нового
      telnetGreetingShown = false;
    }
  }

  if (telnet && telnet.connected() && telnet.available())
  {
    if (!telnetGreetingShown)
    {
      telnet.println(F("Подключение к устройтву по протоколу telnet установлено\n-------"));
      telnetGreetingShown = true;
    }
  }
}

#endif
//----------------------------------------------------
// устарело
/*
class TimerManager
{
  public:
    static bool TimerRunning;                               // флаг "таймер взведён"
    static bool TimerHasFired;                              // флаг "таймер отработал"
    static uint8_t TimerOption;                             // индекс элемента в списке List Picker'а
    static uint64_t TimeToFire;                             // время, в которое должен сработать таймер (millis)

    static void HandleTimer(                                // функция, обрабатывающая срабатывание таймера, гасит матрицу
      bool* ONflag,
      bool* settChanged,
      uint32_t* eepromTimeout,
      void (*changePower)())
    {
      if (!TimerManager::TimerHasFired &&
           TimerManager::TimerRunning &&
           millis() >= TimerManager::TimeToFire)
      {
        #ifdef GENERAL_DEBUG
        LOG.print(F("Выключение по таймеру\n\n"));
        #endif

        TimerManager::TimerRunning = false;
        TimerManager::TimerHasFired = true;
        FastLED.clear();
        delay(2);
        FastLED.show();
        *ONflag = !(*ONflag);
        changePower();
        *settChanged = true;
        *eepromTimeout = millis();
      }
    }
};
*/

