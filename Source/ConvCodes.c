// Adapted from: https://github.com/ttsou/turbofec/blob/master/tests/codes.c

#include "ConvCodes.h"

#include <stdint.h>

#define GETCODE(x) \
    const struct lte_conv_code* get_ ## x() { return &x; }

/* GSM XCCH */
static const struct lte_conv_code gsm_conv_xcch = {
	.n = 2,
	.k = 5,
	.len = 224,
	.gen = { 023, 033 },
};
GETCODE(gsm_conv_xcch)

/* GPRS CS2 */
static const struct lte_conv_code gsm_conv_cs2 = {
	.n = 2,
	.k = 5,
	.len = 290,
	.gen = { 023, 033 },
};
GETCODE(gsm_conv_cs2)

/* GPRS CS3 */
static const struct lte_conv_code gsm_conv_cs3 = {
	.n = 2,
	.k = 5,
	.len = 334,
	.gen = { 023, 033 },
};
GETCODE(gsm_conv_cs3)

/* GSM RACH */
static const struct lte_conv_code gsm_conv_rach = {
	.n = 2,
	.k = 5,
	.len = 14,
	.gen = { 023, 033 },
};
GETCODE(gsm_conv_rach)

/* GSM SCH */
static const struct lte_conv_code gsm_conv_sch = {
	.n = 2,
	.k = 5,
	.len = 35,
	.gen = { 023, 033 },
};
GETCODE(gsm_conv_sch)

/* GSM TCH-FR */
static const struct lte_conv_code gsm_conv_tch_fr = {
	.n = 2,
	.k = 5,
	.len = 185,
	.gen = { 023, 033 },
};
GETCODE(gsm_conv_tch_fr)

static int tch_hr_puncture[] = {
	  1,   4,   7,  10,  13,  16,  19,  22,  25,  28,  31,  34,
	 37,  40,  43,  46,  49,  52,  55,  58,  61,  64,  67,  70,
	 73,  76,  79,  82,  85,  88,  91,  94,  97, 100, 103, 106,
	109, 112, 115, 118, 121, 124, 127, 130, 133, 136, 139, 142,
	145, 148, 151, 154, 157, 160, 163, 166, 169, 172, 175, 178,
	181, 184, 187, 190, 193, 196, 199, 202, 205, 208, 211, 214,
	217, 220, 223, 226, 229, 232, 235, 238, 241, 244, 247, 250,
	253, 256, 259, 262, 265, 268, 271, 274, 277, 280, 283, 295,
	298, 301, 304, 307, 310, 313,  -1,
};

/* GSM TCH-HR */
static const struct lte_conv_code gsm_conv_tch_hr = {
	.n = 3,
	.k = 7,
	.len = 98,
	.gen = { 0133, 0145, 0175 },
	.punc = tch_hr_puncture,
};
GETCODE(gsm_conv_tch_hr)

static int tch_afs_12_2_puncture[] = {
	321, 325, 329, 333, 337, 341, 345, 349, 353, 357, 361, 363,
	365, 369, 373, 377, 379, 381, 385, 389, 393, 395, 397, 401,
	405, 409, 411, 413, 417, 421, 425, 427, 429, 433, 437, 441,
	443, 445, 449, 453, 457, 459, 461, 465, 469, 473, 475, 477,
	481, 485, 489, 491, 493, 495, 497, 499, 501, 503, 505, 507,
	-1,
};

/* GSM TCH-AFS12.2 */
static const struct lte_conv_code gsm_conv_tch_afs_12_2 = {
	.n = 2,
	.k = 5,
	.len = 250,
	.rgen = 023,
	.gen = { 020, 033 },
	.punc = tch_afs_12_2_puncture,
};
GETCODE(gsm_conv_tch_afs_12_2)

static int tch_afs_10_2_puncture[] = {
	  1,   4,   7,  10,  16,  19,  22,  28,  31,  34,  40,  43,
	 46,  52,  55,  58,  64,  67,  70,  76,  79,  82,  88,  91,
	 94, 100, 103, 106, 112, 115, 118, 124, 127, 130, 136, 139,
	142, 148, 151, 154, 160, 163, 166, 172, 175, 178, 184, 187,
	190, 196, 199, 202, 208, 211, 214, 220, 223, 226, 232, 235,
	238, 244, 247, 250, 256, 259, 262, 268, 271, 274, 280, 283,
	286, 292, 295, 298, 304, 307, 310, 316, 319, 322, 325, 328,
	331, 334, 337, 340, 343, 346, 349, 352, 355, 358, 361, 364,
	367, 370, 373, 376, 379, 382, 385, 388, 391, 394, 397, 400,
	403, 406, 409, 412, 415, 418, 421, 424, 427, 430, 433, 436,
	439, 442, 445, 448, 451, 454, 457, 460, 463, 466, 469, 472,
	475, 478, 481, 484, 487, 490, 493, 496, 499, 502, 505, 508,
	511, 514, 517, 520, 523, 526, 529, 532, 535, 538, 541, 544,
	547, 550, 553, 556, 559, 562, 565, 568, 571, 574, 577, 580,
	583, 586, 589, 592, 595, 598, 601, 604, 607, 609, 610, 613,
	616, 619, 621, 622, 625, 627, 628, 631, 633, 634, 636, 637,
	639, 640,  -1,
};

/* GSM TCH-AFS10.2 */
static const struct lte_conv_code gsm_conv_tch_afs_10_2 = {
	.n = 3,
	.k = 5,
	.len = 210,
	.rgen = 037,
	.gen = { 033, 025, 020 },
	.punc = tch_afs_10_2_puncture,
};
GETCODE(gsm_conv_tch_afs_10_2)

static int tch_afs_7_95_puncture[] = {
	  1,   2,   4,   5,   8,  22,  70, 118, 166, 214, 262, 310,
	317, 319, 325, 332, 334, 341, 343, 349, 356, 358, 365, 367,
	373, 380, 382, 385, 389, 391, 397, 404, 406, 409, 413, 415,
	421, 428, 430, 433, 437, 439, 445, 452, 454, 457, 461, 463,
	469, 476, 478, 481, 485, 487, 490, 493, 500, 502, 503, 505,
	506, 508, 509, 511, 512,  -1,
};

/* GSM TCH-AFS7.95 */
static const struct lte_conv_code gsm_conv_tch_afs_7_95 = {
	.n = 3,
	.k = 7,
	.len = 165,
	.rgen = 033,
	.gen = { 0100, 0145, 0175 },
	.punc = tch_afs_7_95_puncture,
};
GETCODE(gsm_conv_tch_afs_7_95)

static int tch_afs_7_4_puncture[] = {
	  0, 355, 361, 367, 373, 379, 385, 391, 397, 403, 409, 415,
	421, 427, 433, 439, 445, 451, 457, 460, 463, 466, 468, 469,
	471, 472,  -1,
};

/* GSM TCH-AFS7.4 */
static const struct lte_conv_code gsm_conv_tch_afs_7_4 = {
	.n = 3,
	.k = 5,
	.len = 154,
	.rgen = 037,
	.gen = { 033, 025, 020 },
	.punc = tch_afs_7_4_puncture,
};
GETCODE(gsm_conv_tch_afs_7_4)

static int tch_afs_6_7_puncture[] = {
	  1,   3,   7,  11,  15,  27,  39,  55,  67,  79,  95, 107,
	119, 135, 147, 159, 175, 187, 199, 215, 227, 239, 255, 267,
	279, 287, 291, 295, 299, 303, 307, 311, 315, 319, 323, 327,
	331, 335, 339, 343, 347, 351, 355, 359, 363, 367, 369, 371,
	375, 377, 379, 383, 385, 387, 391, 393, 395, 399, 401, 403,
	407, 409, 411, 415, 417, 419, 423, 425, 427, 431, 433, 435,
	439, 441, 443, 447, 449, 451, 455, 457, 459, 463, 465, 467,
	471, 473, 475, 479, 481, 483, 487, 489, 491, 495, 497, 499,
	503, 505, 507, 511, 513, 515, 519, 521, 523, 527, 529, 531,
	535, 537, 539, 543, 545, 547, 549, 551, 553, 555, 557, 559,
	561, 563, 565, 567, 569, 571, 573, 575,
	-1,
};

/* GSM TCH-AFS6.7 */
static const struct lte_conv_code gsm_conv_tch_afs_6_7 = {
	.n = 4,
	.k = 5,
	.len = 140,
	.rgen = 037,
	.gen = { 033, 025, 020, 020 },
	.punc = tch_afs_6_7_puncture,
};
GETCODE(gsm_conv_tch_afs_6_7)

static int tch_afs_5_9_puncture[] = {
	  0,   1,   3,   5,   7,  11,  15,  31,  47,  63,  79,  95,
	111, 127, 143, 159, 175, 191, 207, 223, 239, 255, 271, 287,
	303, 319, 327, 331, 335, 343, 347, 351, 359, 363, 367, 375,
	379, 383, 391, 395, 399, 407, 411, 415, 423, 427, 431, 439,
	443, 447, 455, 459, 463, 467, 471, 475, 479, 483, 487, 491,
	495, 499, 503, 507, 509, 511, 512, 513, 515, 516, 517, 519,
	-1,
};

/* GSM TCH-AFS5.9 */
static const struct lte_conv_code gsm_conv_tch_afs_5_9 = {
	.n = 4,
	.k = 7,
	.len = 124,
	.rgen = 0175,
	.gen = { 0133, 0145, 0100, 0100 },
	.punc = tch_afs_5_9_puncture,
};
GETCODE(gsm_conv_tch_afs_5_9)

static int tch_ahs_7_95_puncture[] = {
	  1,   3,   5,   7,  11,  15,  19,  23,  27,  31,  35,  43,
	 47,  51,  55,  59,  63,  67,  71,  79,  83,  87,  91,  95,
	 99, 103, 107, 115, 119, 123, 127, 131, 135, 139, 143, 151,
	155, 159, 163, 167, 171, 175, 177, 179, 183, 185, 187, 191,
	193, 195, 197, 199, 203, 205, 207, 211, 213, 215, 219, 221,
	223, 227, 229, 231, 233, 235, 239, 241, 243, 247, 249, 251,
	255, 257, 259, 261, 263, 265,
	-1,
};

/* GSM TCH-AHS7.95 */
static const struct lte_conv_code gsm_conv_tch_ahs_7_95 = {
	.n = 2,
	.k = 5,
	.len = 129,
	.rgen = 023,
	.gen = { 020, 033 },
	.punc = tch_ahs_7_95_puncture,
};
GETCODE(gsm_conv_tch_ahs_7_95)

static int tch_ahs_7_4_puncture[] = {
	  1,   3,   7,  11,  19,  23,  27,  35,  39,  43,  51,  55,
	 59,  67,  71,  75,  83,  87,  91,  99, 103, 107, 115, 119,
	123, 131, 135, 139, 143, 147, 151, 155, 159, 163, 167, 171,
	175, 179, 183, 187, 191, 195, 199, 203, 207, 211, 215, 219,
	221, 223, 227, 229, 231, 235, 237, 239, 243, 245, 247, 251,
	253, 255, 257, 259,  -1,
};

/* GSM TCH-AHS7.4 */
static const struct lte_conv_code gsm_conv_tch_ahs_7_4 = {
	.n = 2,
	.k = 5,
	.len = 126,
	.rgen = 023,
	.gen = { 020, 033 },
	.punc = tch_ahs_7_4_puncture,
};
GETCODE(gsm_conv_tch_ahs_7_4)

static int tch_ahs_6_7_puncture[] = {
	  1,   3,   9,  19,  29,  39,  49,  59,  69,  79,  89,  99,
	109, 119, 129, 139, 149, 159, 167, 169, 177, 179, 187, 189,
	197, 199, 203, 207, 209, 213, 217, 219, 223, 227, 229, 231,
	233, 235, 237, 239,  -1,
};

/* GSM TCH-AHS6.7 */
static const struct lte_conv_code gsm_conv_tch_ahs_6_7 = {
	.n = 2,
	.k = 5,
	.len = 116,
	.rgen = 023,
	.gen = { 020, 033 },
	.punc = tch_ahs_6_7_puncture,
};
GETCODE(gsm_conv_tch_ahs_6_7)

static int tch_ahs_5_9_puncture[] = {
	  1,  15,  71, 127, 139, 151, 163, 175, 187, 195, 203, 211,
	215, 219, 221, 223,  -1,
};

/* GSM TCH-AHS5.9 */
static const struct lte_conv_code gsm_conv_tch_ahs_5_9 = {
	.n = 2,
	.k = 5,
	.len = 108,
	.rgen = 023,
	.gen = { 020, 033 },
	.punc = tch_ahs_5_9_puncture,
};
GETCODE(gsm_conv_tch_ahs_5_9)

static int tch_ahs_5_15_puncture[] = {
	  0,   1,   3,   4,   6,   9,  12,  15,  18,  21,  27,  33,
	 39,  45,  51,  54, 57,  63,  69,  75,  81,  87,  90,  93,
	 99, 105, 111, 117, 123, 126, 129, 135, 141, 147, 153, 159,
	162, 165, 168, 171, 174, 177, 180, 183, 186, 189, 192, 195,
	198, 201, 204, 207, 210, 213, 216, 219, 222, 225, 228, 231,
	234, 237, 240, 243, 244, 246, 249, 252, 255, 256, 258, 261,
	264, 267, 268, 270, 273, 276, 279, 280, 282, 285, 288, 289,
	291, 294, 295, 297, 298, 300, 301,  -1,
};

/* GSM TCH-AHS5.15 */
static const struct lte_conv_code gsm_conv_tch_ahs_5_15 = {
	.n = 3,
	.k = 5,
	.len = 97,
	.rgen = 037,
	.gen = { 033, 025, 020 },
	.punc = tch_ahs_5_15_puncture,
};
GETCODE(gsm_conv_tch_ahs_5_15)

static int tch_ahs_4_75_puncture[] = {
	  1,   2,   4,   5,   7,   8,  10,  13,  16,  22,  28,  34,
	 40,  46,  52,  58, 64,  70,  76,  82,  88,  94, 100, 106,
	112, 118, 124, 130, 136, 142, 148, 151, 154, 160, 163, 166,
	172, 175, 178, 184, 187, 190, 196, 199, 202, 208, 211, 214,
	220, 223, 226, 232, 235, 238, 241, 244, 247, 250, 253, 256,
	259, 262, 265, 268, 271, 274, 275, 277, 278, 280, 281, 283,
	284,  -1,
};

/* GSM TCH-AHS4.75 */
static const struct lte_conv_code gsm_conv_tch_ahs_4_75 = {
	.n = 3,
	.k = 7,
	.len = 89,
	.rgen = 0133,
	.gen = { 0100, 0145, 0175 },
	.punc = tch_ahs_4_75_puncture,
};
GETCODE(gsm_conv_tch_ahs_4_75)

/* WiMax FCH */
static const struct lte_conv_code wimax_conv_fch = {
	.n = 2,
	.k = 7,
	.len = 48,
	.gen = { 0171, 0133 },
	.term = CONV_TERM_TAIL_BITING,
};
GETCODE(wimax_conv_fch)

/* LTE PBCH */
static const struct lte_conv_code lte_conv_pbch = {
	.n = 3,
	.k = 7,
	.len = 512,
	.gen = { 0133, 0171, 0165 },
	.term = CONV_TERM_TAIL_BITING,
};
GETCODE(lte_conv_pbch)
