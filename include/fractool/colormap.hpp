#ifndef __FRACTOOL_COLORMAP_H__
#define __FRACTOOL_COLORMAP_H__

// Includes
#include <fractool/macros.hpp>
#include <map>
#include <string>

// Ink Colormap
const colormap COLORMAP_INK = {
	255, 255, 255,
	254, 254, 254,
	253, 253, 253,
	252, 252, 252,
	251, 251, 251,
	250, 250, 250,
	249, 249, 249,
	248, 248, 248,
	247, 247, 247,
	246, 246, 246,
	245, 245, 245,
	244, 244, 244,
	243, 243, 243,
	242, 242, 242,
	241, 241, 241,
	240, 240, 240,
	239, 239, 239,
	238, 238, 238,
	237, 237, 237,
	236, 236, 236,
	235, 235, 235,
	234, 234, 234,
	233, 233, 233,
	232, 232, 232,
	231, 231, 231,
	230, 230, 230,
	229, 229, 229,
	228, 228, 228,
	227, 227, 227,
	226, 226, 226,
	225, 225, 225,
	224, 224, 224,
	223, 223, 223,
	222, 222, 222,
	221, 221, 221,
	220, 220, 220,
	219, 219, 219,
	218, 218, 218,
	217, 217, 217,
	216, 216, 216,
	215, 215, 215,
	214, 214, 214,
	213, 213, 213,
	211, 211, 211,
	211, 211, 211,
	210, 210, 210,
	209, 209, 209,
	208, 208, 208,
	207, 207, 207,
	206, 206, 206,
	205, 205, 205,
	204, 204, 204,
	203, 203, 203,
	202, 202, 202,
	201, 201, 201,
	200, 200, 200,
	199, 199, 199,
	198, 198, 198,
	197, 197, 197,
	195, 195, 195,
	195, 195, 195,
	194, 194, 194,
	193, 193, 193,
	192, 192, 192,
	191, 191, 191,
	190, 190, 190,
	189, 189, 189,
	188, 188, 188,
	187, 187, 187,
	186, 186, 186,
	185, 185, 185,
	184, 184, 184,
	183, 183, 183,
	182, 182, 182,
	181, 181, 181,
	179, 179, 179,
	179, 179, 179,
	178, 178, 178,
	177, 177, 177,
	176, 176, 176,
	175, 175, 175,
	174, 174, 174,
	173, 173, 173,
	172, 172, 172,
	171, 171, 171,
	170, 170, 170,
	169, 169, 169,
	168, 168, 168,
	167, 167, 167,
	166, 166, 166,
	165, 165, 165,
	163, 163, 163,
	163, 163, 163,
	162, 162, 162,
	161, 161, 161,
	160, 160, 160,
	159, 159, 159,
	158, 158, 158,
	157, 157, 157,
	156, 156, 156,
	155, 155, 155,
	154, 154, 154,
	153, 153, 153,
	152, 152, 152,
	151, 151, 151,
	150, 150, 150,
	149, 149, 149,
	147, 147, 147,
	147, 147, 147,
	146, 146, 146,
	145, 145, 145,
	144, 144, 144,
	143, 143, 143,
	142, 142, 142,
	141, 141, 141,
	140, 140, 140,
	139, 139, 139,
	138, 138, 138,
	137, 137, 137,
	136, 136, 136,
	135, 135, 135,
	134, 134, 134,
	133, 133, 133,
	131, 131, 131,
	131, 131, 131,
	130, 130, 130,
	129, 129, 129,
	128, 128, 128,
	127, 127, 127,
	126, 126, 126,
	125, 125, 125,
	124, 124, 124,
	123, 123, 123,
	121, 121, 121,
	121, 121, 121,
	120, 120, 120,
	119, 119, 119,
	118, 118, 118,
	117, 117, 117,
	116, 116, 116,
	114, 114, 114,
	113, 113, 113,
	113, 113, 113,
	112, 112, 112,
	111, 111, 111,
	110, 110, 110,
	109, 109, 109,
	108, 108, 108,
	107, 107, 107,
	105, 105, 105,
	105, 105, 105,
	104, 104, 104,
	103, 103, 103,
	102, 102, 102,
	101, 101, 101,
	100, 100, 100,
	 98,  98,  98,
	 97,  97,  97,
	 97,  97,  97,
	 96,  96,  96,
	 95,  95,  95,
	 94,  94,  94,
	 93,  93,  93,
	 92,  92,  92,
	 91,  91,  91,
	 89,  89,  89,
	 89,  89,  89,
	 88,  88,  88,
	 87,  87,  87,
	 86,  86,  86,
	 85,  85,  85,
	 84,  84,  84,
	 82,  82,  82,
	 81,  81,  81,
	 81,  81,  81,
	 80,  80,  80,
	 79,  79,  79,
	 78,  78,  78,
	 77,  77,  77,
	 76,  76,  76,
	 75,  75,  75,
	 73,  73,  73,
	 73,  73,  73,
	 72,  72,  72,
	 71,  71,  71,
	 70,  70,  70,
	 69,  69,  69,
	 68,  68,  68,
	 66,  66,  66,
	 65,  65,  65,
	 65,  65,  65,
	 64,  64,  64,
	 63,  63,  63,
	 62,  62,  62,
	 61,  61,  61,
	 60,  60,  60,
	 59,  59,  59,
	 57,  57,  57,
	 56,  56,  56,
	 56,  56,  56,
	 55,  55,  55,
	 54,  54,  54,
	 53,  53,  53,
	 52,  52,  52,
	 50,  50,  50,
	 49,  49,  49,
	 48,  48,  48,
	 48,  48,  48,
	 47,  47,  47,
	 46,  46,  46,
	 45,  45,  45,
	 44,  44,  44,
	 43,  43,  43,
	 41,  41,  41,
	 40,  40,  40,
	 40,  40,  40,
	 39,  39,  39,
	 38,  38,  38,
	 37,  37,  37,
	 36,  36,  36,
	 34,  34,  34,
	 33,  33,  33,
	 32,  32,  32,
	 32,  32,  32,
	 31,  31,  31,
	 30,  30,  30,
	 29,  29,  29,
	 28,  28,  28,
	 27,  27,  27,
	 25,  25,  25,
	 24,  24,  24,
	 24,  24,  24,
	 23,  23,  23,
	 22,  22,  22,
	 21,  21,  21,
	 20,  20,  20,
	 18,  18,  18,
	 17,  17,  17,
	 16,  16,  16,
	 16,  16,  16,
	 15,  15,  15,
	 14,  14,  14,
	 13,  13,  13,
	 12,  12,  12,
	 11,  11,  11,
	  9,   9,   9,
	  8,   8,   8,
	  8,   8,   8,
	  7,   7,   7,
	  6,   6,   6,
	  5,   5,   5,
	  4,   4,   4,
	  2,   2,   2,
	  1,   1,   1,
	  0,   0,   0,
	  0,   0,   0
};

// Red2blue Colormap
const colormap COLORMAP_RED2BLUE = {
	  0,   0, 255,
	  1,   0, 254,
	  2,   0, 253,
	  3,   0, 252,
	  4,   0, 251,
	  5,   0, 250,
	  6,   0, 249,
	  7,   0, 248,
	  8,   0, 247,
	  9,   0, 246,
	 10,   0, 245,
	 11,   0, 244,
	 12,   0, 243,
	 13,   0, 242,
	 14,   0, 241,
	 15,   0, 240,
	 16,   0, 239,
	 17,   0, 238,
	 18,   0, 237,
	 19,   0, 236,
	 20,   0, 235,
	 21,   0, 234,
	 22,   0, 233,
	 23,   0, 232,
	 24,   0, 231,
	 25,   0, 230,
	 26,   0, 229,
	 27,   0, 228,
	 28,   0, 227,
	 29,   0, 226,
	 30,   0, 225,
	 31,   0, 224,
	 32,   0, 223,
	 32,   0, 222,
	 34,   0, 221,
	 35,   0, 220,
	 36,   0, 219,
	 36,   0, 218,
	 38,   0, 217,
	 39,   0, 216,
	 40,   0, 215,
	 40,   0, 214,
	 42,   0, 213,
	 43,   0, 211,
	 44,   0, 211,
	 44,   0, 210,
	 46,   0, 209,
	 47,   0, 208,
	 48,   0, 207,
	 48,   0, 206,
	 50,   0, 205,
	 51,   0, 204,
	 52,   0, 203,
	 52,   0, 202,
	 54,   0, 201,
	 55,   0, 200,
	 56,   0, 199,
	 56,   0, 198,
	 58,   0, 197,
	 59,   0, 195,
	 60,   0, 195,
	 60,   0, 194,
	 62,   0, 193,
	 63,   0, 192,
	 64,   0, 191,
	 65,   0, 190,
	 65,   0, 189,
	 67,   0, 188,
	 68,   0, 187,
	 69,   0, 186,
	 70,   0, 185,
	 71,   0, 184,
	 72,   0, 183,
	 73,   0, 182,
	 73,   0, 181,
	 75,   0, 179,
	 76,   0, 179,
	 77,   0, 178,
	 78,   0, 177,
	 79,   0, 176,
	 80,   0, 175,
	 81,   0, 174,
	 81,   0, 173,
	 83,   0, 172,
	 84,   0, 171,
	 85,   0, 170,
	 86,   0, 169,
	 87,   0, 168,
	 88,   0, 167,
	 89,   0, 166,
	 89,   0, 165,
	 91,   0, 163,
	 92,   0, 163,
	 93,   0, 162,
	 94,   0, 161,
	 95,   0, 160,
	 96,   0, 159,
	 97,   0, 158,
	 97,   0, 157,
	 99,   0, 156,
	100,   0, 155,
	101,   0, 154,
	102,   0, 153,
	103,   0, 152,
	104,   0, 151,
	105,   0, 150,
	105,   0, 149,
	107,   0, 147,
	108,   0, 147,
	109,   0, 146,
	110,   0, 145,
	111,   0, 144,
	112,   0, 143,
	113,   0, 142,
	113,   0, 141,
	115,   0, 140,
	116,   0, 139,
	117,   0, 138,
	118,   0, 137,
	119,   0, 136,
	120,   0, 135,
	121,   0, 134,
	121,   0, 133,
	123,   0, 131,
	124,   0, 131,
	125,   0, 130,
	126,   0, 129,
	127,   0, 128,
	128,   0, 127,
	129,   0, 126,
	130,   0, 125,
	131,   0, 124,
	131,   0, 123,
	133,   0, 121,
	134,   0, 121,
	135,   0, 120,
	136,   0, 119,
	137,   0, 118,
	138,   0, 117,
	139,   0, 116,
	140,   0, 114,
	141,   0, 113,
	142,   0, 113,
	143,   0, 112,
	144,   0, 111,
	145,   0, 110,
	146,   0, 109,
	147,   0, 108,
	147,   0, 107,
	149,   0, 105,
	150,   0, 105,
	151,   0, 104,
	152,   0, 103,
	153,   0, 102,
	154,   0, 101,
	155,   0, 100,
	156,   0,  98,
	157,   0,  97,
	158,   0,  97,
	159,   0,  96,
	160,   0,  95,
	161,   0,  94,
	162,   0,  93,
	163,   0,  92,
	163,   0,  91,
	165,   0,  89,
	166,   0,  89,
	167,   0,  88,
	168,   0,  87,
	169,   0,  86,
	170,   0,  85,
	171,   0,  84,
	172,   0,  82,
	173,   0,  81,
	174,   0,  81,
	175,   0,  80,
	176,   0,  79,
	177,   0,  78,
	178,   0,  77,
	179,   0,  76,
	179,   0,  75,
	181,   0,  73,
	182,   0,  73,
	183,   0,  72,
	184,   0,  71,
	185,   0,  70,
	186,   0,  69,
	187,   0,  68,
	188,   0,  66,
	189,   0,  65,
	190,   0,  65,
	191,   0,  64,
	192,   0,  63,
	193,   0,  62,
	194,   0,  61,
	195,   0,  60,
	195,   0,  59,
	197,   0,  57,
	198,   0,  56,
	199,   0,  56,
	200,   0,  55,
	201,   0,  54,
	202,   0,  53,
	203,   0,  52,
	204,   0,  50,
	205,   0,  49,
	206,   0,  48,
	207,   0,  48,
	208,   0,  47,
	209,   0,  46,
	210,   0,  45,
	211,   0,  44,
	211,   0,  43,
	213,   0,  41,
	214,   0,  40,
	215,   0,  40,
	216,   0,  39,
	217,   0,  38,
	218,   0,  37,
	219,   0,  36,
	220,   0,  34,
	221,   0,  33,
	222,   0,  32,
	223,   0,  32,
	224,   0,  31,
	225,   0,  30,
	226,   0,  29,
	227,   0,  28,
	227,   0,  27,
	229,   0,  25,
	230,   0,  24,
	231,   0,  24,
	232,   0,  23,
	233,   0,  22,
	234,   0,  21,
	235,   0,  20,
	236,   0,  18,
	237,   0,  17,
	238,   0,  16,
	239,   0,  16,
	240,   0,  15,
	241,   0,  14,
	242,   0,  13,
	243,   0,  12,
	243,   0,  11,
	245,   0,   9,
	246,   0,   8,
	247,   0,   8,
	248,   0,   7,
	249,   0,   6,
	250,   0,   5,
	251,   0,   4,
	252,   0,   2,
	253,   0,   1,
	254,   0,   0,
	255,   0,   0
};

// Blue2red Colormap
const colormap COLORMAP_BLUE2RED = {
	255,   0,   0,
	254,   0,   1,
	253,   0,   2,
	252,   0,   3,
	251,   0,   4,
	250,   0,   5,
	249,   0,   6,
	248,   0,   7,
	247,   0,   8,
	246,   0,   9,
	245,   0,  10,
	244,   0,  11,
	243,   0,  12,
	242,   0,  13,
	241,   0,  14,
	240,   0,  15,
	239,   0,  16,
	238,   0,  17,
	237,   0,  18,
	236,   0,  19,
	235,   0,  20,
	234,   0,  21,
	233,   0,  22,
	232,   0,  23,
	231,   0,  24,
	230,   0,  25,
	229,   0,  26,
	228,   0,  27,
	227,   0,  28,
	226,   0,  29,
	225,   0,  30,
	224,   0,  31,
	223,   0,  32,
	222,   0,  32,
	221,   0,  34,
	220,   0,  35,
	219,   0,  36,
	218,   0,  36,
	217,   0,  38,
	216,   0,  39,
	215,   0,  40,
	214,   0,  40,
	213,   0,  42,
	211,   0,  43,
	211,   0,  44,
	210,   0,  44,
	209,   0,  46,
	208,   0,  47,
	207,   0,  48,
	206,   0,  48,
	205,   0,  50,
	204,   0,  51,
	203,   0,  52,
	202,   0,  52,
	201,   0,  54,
	200,   0,  55,
	199,   0,  56,
	198,   0,  56,
	197,   0,  58,
	195,   0,  59,
	195,   0,  60,
	194,   0,  60,
	193,   0,  62,
	192,   0,  63,
	191,   0,  64,
	190,   0,  65,
	189,   0,  65,
	188,   0,  67,
	187,   0,  68,
	186,   0,  69,
	185,   0,  70,
	184,   0,  71,
	183,   0,  72,
	182,   0,  73,
	181,   0,  73,
	179,   0,  75,
	179,   0,  76,
	178,   0,  77,
	177,   0,  78,
	176,   0,  79,
	175,   0,  80,
	174,   0,  81,
	173,   0,  81,
	172,   0,  83,
	171,   0,  84,
	170,   0,  85,
	169,   0,  86,
	168,   0,  87,
	167,   0,  88,
	166,   0,  89,
	165,   0,  89,
	163,   0,  91,
	163,   0,  92,
	162,   0,  93,
	161,   0,  94,
	160,   0,  95,
	159,   0,  96,
	158,   0,  97,
	157,   0,  97,
	156,   0,  99,
	155,   0, 100,
	154,   0, 101,
	153,   0, 102,
	152,   0, 103,
	151,   0, 104,
	150,   0, 105,
	149,   0, 105,
	147,   0, 107,
	147,   0, 108,
	146,   0, 109,
	145,   0, 110,
	144,   0, 111,
	143,   0, 112,
	142,   0, 113,
	141,   0, 113,
	140,   0, 115,
	139,   0, 116,
	138,   0, 117,
	137,   0, 118,
	136,   0, 119,
	135,   0, 120,
	134,   0, 121,
	133,   0, 121,
	131,   0, 123,
	131,   0, 124,
	130,   0, 125,
	129,   0, 126,
	128,   0, 127,
	127,   0, 128,
	126,   0, 129,
	125,   0, 130,
	124,   0, 131,
	123,   0, 131,
	121,   0, 133,
	121,   0, 134,
	120,   0, 135,
	119,   0, 136,
	118,   0, 137,
	117,   0, 138,
	116,   0, 139,
	114,   0, 140,
	113,   0, 141,
	113,   0, 142,
	112,   0, 143,
	111,   0, 144,
	110,   0, 145,
	109,   0, 146,
	108,   0, 147,
	107,   0, 147,
	105,   0, 149,
	105,   0, 150,
	104,   0, 151,
	103,   0, 152,
	102,   0, 153,
	101,   0, 154,
	100,   0, 155,
	 98,   0, 156,
	 97,   0, 157,
	 97,   0, 158,
	 96,   0, 159,
	 95,   0, 160,
	 94,   0, 161,
	 93,   0, 162,
	 92,   0, 163,
	 91,   0, 163,
	 89,   0, 165,
	 89,   0, 166,
	 88,   0, 167,
	 87,   0, 168,
	 86,   0, 169,
	 85,   0, 170,
	 84,   0, 171,
	 82,   0, 172,
	 81,   0, 173,
	 81,   0, 174,
	 80,   0, 175,
	 79,   0, 176,
	 78,   0, 177,
	 77,   0, 178,
	 76,   0, 179,
	 75,   0, 179,
	 73,   0, 181,
	 73,   0, 182,
	 72,   0, 183,
	 71,   0, 184,
	 70,   0, 185,
	 69,   0, 186,
	 68,   0, 187,
	 66,   0, 188,
	 65,   0, 189,
	 65,   0, 190,
	 64,   0, 191,
	 63,   0, 192,
	 62,   0, 193,
	 61,   0, 194,
	 60,   0, 195,
	 59,   0, 195,
	 57,   0, 197,
	 56,   0, 198,
	 56,   0, 199,
	 55,   0, 200,
	 54,   0, 201,
	 53,   0, 202,
	 52,   0, 203,
	 50,   0, 204,
	 49,   0, 205,
	 48,   0, 206,
	 48,   0, 207,
	 47,   0, 208,
	 46,   0, 209,
	 45,   0, 210,
	 44,   0, 211,
	 43,   0, 211,
	 41,   0, 213,
	 40,   0, 214,
	 40,   0, 215,
	 39,   0, 216,
	 38,   0, 217,
	 37,   0, 218,
	 36,   0, 219,
	 34,   0, 220,
	 33,   0, 221,
	 32,   0, 222,
	 32,   0, 223,
	 31,   0, 224,
	 30,   0, 225,
	 29,   0, 226,
	 28,   0, 227,
	 27,   0, 227,
	 25,   0, 229,
	 24,   0, 230,
	 24,   0, 231,
	 23,   0, 232,
	 22,   0, 233,
	 21,   0, 234,
	 20,   0, 235,
	 18,   0, 236,
	 17,   0, 237,
	 16,   0, 238,
	 16,   0, 239,
	 15,   0, 240,
	 14,   0, 241,
	 13,   0, 242,
	 12,   0, 243,
	 11,   0, 243,
	  9,   0, 245,
	  8,   0, 246,
	  8,   0, 247,
	  7,   0, 248,
	  6,   0, 249,
	  5,   0, 250,
	  4,   0, 251,
	  2,   0, 252,
	  1,   0, 253,
	  0,   0, 254,
	  0,   0, 255
};

// Flower Colormap
const colormap COLORMAP_FLOWER = {
	 21,  12,  12,
	 22,  11,  11,
	 23,  10,  10,
	 24,   9,   9,
	 26,   9,   9,
	 27,   8,   8,
	 28,   7,   7,
	 30,   6,   6,
	 31,   6,   6,
	 33,   5,   5,
	 34,   5,   5,
	 35,   4,   4,
	 37,   4,   4,
	 39,   3,   3,
	 40,   3,   3,
	 42,   2,   2,
	 43,   2,   2,
	 45,   2,   2,
	 47,   1,   1,
	 48,   1,   1,
	 50,   1,   1,
	 52,   1,   1,
	 54,   1,   1,
	 55,   1,   1,
	 57,   1,   1,
	 59,   1,   1,
	 61,   1,   1,
	 63,   1,   1,
	 65,   1,   1,
	 67,   1,   1,
	 69,   1,   1,
	 71,   1,   1,
	 72,   1,   1,
	 74,   2,   2,
	 76,   2,   2,
	 78,   2,   2,
	 81,   3,   3,
	 83,   3,   3,
	 85,   4,   4,
	 87,   4,   4,
	 89,   5,   5,
	 91,   5,   5,
	 93,   6,   6,
	 95,   7,   7,
	 97,   7,   7,
	 99,   8,   8,
	101,   9,   9,
	104,  10,  10,
	106,  10,  10,
	108,  11,  11,
	110,  12,  12,
	112,  13,  13,
	114,  14,  14,
	117,  15,  15,
	119,  16,  16,
	121,  17,  17,
	123,  18,  18,
	125,  19,  19,
	128,  21,  21,
	130,  22,  22,
	132,  23,  23,
	134,  24,  24,
	136,  26,  26,
	138,  27,  27,
	141,  28,  28,
	143,  30,  30,
	145,  31,  31,
	147,  33,  33,
	149,  34,  34,
	151,  36,  36,
	154,  37,  37,
	156,  39,  39,
	158,  40,  40,
	160,  42,  42,
	162,  43,  43,
	164,  45,  45,
	166,  47,  47,
	168,  48,  48,
	170,  50,  50,
	173,  52,  52,
	175,  54,  54,
	177,  55,  55,
	179,  57,  57,
	181,  59,  59,
	183,  61,  61,
	185,  63,  63,
	187,  65,  65,
	188,  67,  67,
	190,  69,  69,
	192,  71,  71,
	194,  73,  73,
	196,  75,  75,
	198,  77,  77,
	200,  79,  79,
	201,  81,  81,
	203,  83,  83,
	205,  85,  85,
	207,  87,  87,
	208,  89,  89,
	210,  91,  91,
	212,  93,  93,
	213,  95,  95,
	215,  97,  97,
	217,  99,  99,
	218, 101, 101,
	220, 104, 104,
	221, 106, 106,
	223, 108, 108,
	224, 110, 110,
	225, 112, 112,
	227, 114, 114,
	228, 117, 117,
	229, 119, 119,
	231, 121, 121,
	232, 123, 123,
	233, 125, 125,
	234, 128, 128,
	236, 130, 130,
	237, 132, 132,
	238, 134, 134,
	239, 136, 136,
	240, 139, 139,
	241, 141, 141,
	242, 143, 143,
	243, 145, 145,
	244, 147, 147,
	245, 149, 149,
	245, 152, 152,
	246, 154, 154,
	247, 156, 156,
	248, 158, 158,
	248, 160, 160,
	249, 162, 162,
	250, 164, 164,
	250, 166, 166,
	251, 168, 168,
	251, 171, 171,
	252, 173, 173,
	252, 175, 175,
	253, 177, 177,
	253, 179, 179,
	253, 181, 181,
	254, 183, 183,
	254, 185, 185,
	254, 187, 187,
	254, 188, 188,
	254, 190, 190,
	254, 192, 192,
	254, 194, 194,
	254, 196, 196,
	254, 198, 198,
	254, 200, 200,
	254, 201, 201,
	254, 203, 203,
	254, 205, 205,
	254, 207, 207,
	254, 208, 208,
	253, 210, 210,
	253, 212, 212,
	253, 213, 213,
	252, 215, 215,
	252, 217, 217,
	251, 218, 218,
	251, 220, 220,
	250, 221, 221,
	250, 223, 223,
	249, 224, 224,
	248, 225, 225,
	248, 227, 227,
	247, 228, 228,
	246, 229, 229,
	246, 231, 231,
	245, 232, 232,
	244, 233, 233,
	243, 234, 234,
	242, 236, 236,
	241, 237, 237,
	240, 238, 238,
	239, 239, 239,
	238, 240, 240,
	237, 241, 241,
	236, 242, 242,
	235, 243, 243,
	233, 244, 244,
	232, 245, 245,
	231, 245, 245,
	230, 246, 246,
	228, 247, 247,
	227, 248, 248,
	226, 248, 248,
	224, 249, 249,
	223, 250, 250,
	221, 250, 250,
	220, 251, 251,
	218, 251, 251,
	217, 252, 252,
	215, 252, 252,
	213, 253, 253,
	212, 253, 253,
	210, 253, 253,
	209, 254, 254,
	207, 254, 254,
	205, 254, 254,
	203, 254, 254,
	202, 254, 254,
	200, 254, 254,
	198, 254, 254,
	196, 254, 254,
	194, 254, 254,
	192, 254, 254,
	191, 254, 254,
	189, 254, 254,
	187, 254, 254,
	185, 254, 254,
	183, 254, 254,
	181, 253, 253,
	179, 253, 253,
	177, 253, 253,
	175, 252, 252,
	173, 252, 252,
	171, 251, 251,
	169, 251, 251,
	167, 250, 250,
	164, 250, 250,
	162, 249, 249,
	160, 248, 248,
	158, 248, 248,
	156, 247, 247,
	154, 246, 246,
	152, 245, 245,
	150, 245, 245,
	147, 244, 244,
	145, 243, 243,
	143, 242, 242,
	141, 241, 241,
	139, 240, 240,
	137, 239, 239,
	134, 238, 238,
	132, 237, 237,
	130, 236, 236,
	128, 235, 235,
	126, 233, 233,
	123, 232, 232,
	121, 231, 231,
	119, 230, 230,
	117, 228, 228,
	115, 227, 227,
	112, 225, 225,
	110, 224, 224,
	108, 223, 223,
	106, 221, 221,
	104, 220, 220,
	102, 218, 218,
	100, 217, 217,
	 97, 215, 215,
	 95, 213, 213
};

// Colormap lookup table
const std::map<std::string, colormap> cmap_lookup = {
	{ "ink", COLORMAP_INK },
	{ "red2blue", COLORMAP_RED2BLUE },
	{ "blue2red", COLORMAP_BLUE2RED },
	{ "flower", COLORMAP_FLOWER }    
};

#endif // __FRACTOOL_COLORMAP_H__