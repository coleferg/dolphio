// Toad
static const Lights1 head_material_lights = gdSPDefLights1(
	0x92, 0x92, 0x92,
	0xFF, 0xFF, 0xFF, 0x9E, 0xBF, 0xD1);

static const Lights1 limb_material_lights = gdSPDefLights1(
	0x92, 0x92, 0x92,
	0xFF, 0xFF, 0xFF, 0x9E, 0xBF, 0xD1);

static const Lights1 body_to_shell_material_lights = gdSPDefLights1(
	0xB5, 0xB5, 0xB5,
	0xFF, 0xFF, 0xFF, 0x9E, 0xBF, 0xD1);

static const Lights1 body_material_lights = gdSPDefLights1(
	0x69, 0x69, 0x69,
	0xFF, 0xFF, 0xFF, 0x9E, 0xBF, 0xD1);

static const Lights1 shell_material_lights = gdSPDefLights1(
	0x94, 0x94, 0x94,
	0xFF, 0xFF, 0xFF, 0x9E, 0xBF, 0xD1);

static const Lights1 vest_material_lights = gdSPDefLights1(
	0xCF, 0xCF, 0xCF,
	0xFF, 0xFF, 0xFF, 0x9E, 0xBF, 0xD1);

// 0x06005908
static const Lights1 toad_seg6_lights_06005908 = gdSPDefLights1(
    0x7f, 0x7f, 0x7f,
    0xff, 0xff, 0xff, 200, -100, -80
);

// 0x06005920
ALIGNED8 static const u8 toad_seg6_texture_06005920[] = {
#include "actors/toad/toad_face.rgba16.inc.c"
};

ALIGNED8 static const u8 toadle_face_texture[] = {
	#include "actors/toad/toadle_face.custom.rgba16.inc.c"
};

ALIGNED8 static const u8 toadle_body_texture[] = {
	#include "actors/toad/toadle_body.custom.rgba16.inc.c"
};

// 0x06006120
ALIGNED8 static const u8 toad_seg6_texture_06006120[] = {
#include "actors/toad/toad_head.rgba16.inc.c"
};

// 0x06006120
ALIGNED8 static const u8 bowser_body_rgba16[] = {
#include "actors/bowser/bowser_body.rgba16.inc.c"
};

// 0x06006120
ALIGNED8 static const u8 bowser_claw_edge_rgba16[] = {
#include "actors/bowser/bowser_claw_edge.rgba16.inc.c"
};

const Gfx mat_head_material[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, TEXEL1, PRIMITIVE, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsDPSetCycleType(G_CYC_2CYCLE),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPTileSync(),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, toadle_face_texture),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 7, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0),
	gsDPLoadSync(),
	gsDPLoadTile(7, 0, 0, 124, 124),
	gsDPPipeSync(),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 0, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsDPTileSync(),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, toadle_body_texture),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 256, 6, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPLoadSync(),
	gsDPLoadTile(6, 0, 0, 124, 124),
	gsDPPipeSync(),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 256, 1, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(1, 0, 0, 124, 124),
	gsDPSetPrimColor(0, 255, 25, 25, 25, 255),
	gsDPSetEnvColor(187, 187, 187, 255),
	gsSPSetLights1(head_material_lights),
	gsSPEndDisplayList(),
};

const Gfx mat_revert_head_material[] = {
	gsDPPipeSync(),
	gsDPSetCycleType(G_CYC_1CYCLE),
	gsSPEndDisplayList(),
};


const Gfx mat_limb_material[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(PRIMITIVE, 0, TEXEL1, 0, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsDPSetCycleType(G_CYC_2CYCLE),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPTileSync(),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, toadle_body_texture),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 6, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPLoadSync(),
	gsDPLoadTile(6, 0, 0, 124, 124),
	gsDPPipeSync(),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 1, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(1, 0, 0, 124, 124),
	gsDPSetPrimColor(0, 0, 0, 149, 0, 255),
	gsDPSetEnvColor(187, 187, 187, 255),
	gsSPSetLights1(limb_material_lights),
	gsSPEndDisplayList(),
};

const Gfx mat_revert_limb_material[] = {
	gsDPPipeSync(),
	gsDPSetCycleType(G_CYC_1CYCLE),
	gsSPEndDisplayList(),
};


const Gfx mat_body_to_shell_material[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPTileSync(),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, bowser_claw_edge_rgba16),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 6, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPLoadSync(),
	gsDPLoadTile(7, 0, 0, 124, 252),
	gsDPPipeSync(),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 6, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 252),
	gsSPSetLights1(body_to_shell_material_lights),
	gsSPEndDisplayList(),
};


const Gfx mat_body_material[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPTileSync(),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, bowser_body_rgba16),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPLoadSync(),
	gsDPLoadTile(7, 0, 0, 124, 124),
	gsDPPipeSync(),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPSetLights1(body_material_lights),
	gsSPEndDisplayList(),
};


const Gfx mat_shell_material[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPTileSync(),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, toad_seg6_texture_06006120),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPLoadSync(),
	gsDPLoadTile(7, 0, 0, 124, 124),
	gsDPPipeSync(),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsDPSetEnvColor(187, 177, 177, 255),
	gsSPSetLights1(shell_material_lights),
	gsSPEndDisplayList(),
};


const Gfx mat_vest_material[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(PRIMITIVE, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, PRIMITIVE, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsSPSetGeometryMode(G_TEXTURE_GEN),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetPrimColor(0, 0, 51, 65, 180, 255),
	gsDPSetEnvColor(54, 63, 187, 255),
	gsSPSetLights1(vest_material_lights),
	gsSPEndDisplayList(),
};

const Gfx mat_revert_vest_material[] = {
	gsDPPipeSync(),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsSPEndDisplayList(),
};


// 0x06006920
static const Vtx toad_seg6_vertex_06006920[] = {
    {{{   -43,   -102,    106}, 0, {    36,    848}, {0xba, 0xcc, 0x5b, 0xff}}},
    {{{   -56,    -68,    103}, 0, {  -108,    448}, {0xa9, 0xfb, 0x5b, 0xff}}},
    {{{   -77,    -96,     50}, 0, {  -314,    702}, {0x94, 0xc1, 0x13, 0xff}}},
    {{{     0,   -135,     97}, 0, {   486,   1044}, {0x00, 0x8d, 0x34, 0xff}}},
    {{{   -42,   -128,     69}, 0, {    46,    990}, {0xbb, 0x9b, 0x1e, 0xff}}},
    {{{     0,    -99,    124}, 0, {   480,    722}, {0x00, 0xd4, 0x76, 0xff}}},
    {{{     0,    -55,    127}, 0, {   472,    332}, {0x00, 0xfe, 0x7e, 0xff}}},
    {{{    44,   -102,    106}, 0, {   930,    840}, {0x46, 0xcc, 0x5b, 0xff}}},
    {{{     0,    -29,    125}, 0, {   466,     92}, {0x00, 0x13, 0x7d, 0xff}}},
    {{{    57,    -68,    103}, 0, {  1058,    436}, {0x57, 0xfb, 0x5b, 0xff}}},
    {{{    78,    -96,     50}, 0, {  1274,    688}, {0x72, 0xcc, 0x0e, 0xff}}},
    {{{    43,   -128,     69}, 0, {   926,    980}, {0x47, 0x9a, 0x18, 0xff}}},
    {{{   -56,    -20,    101}, 0, {  -118,     16}, {0xb5, 0x11, 0x64, 0xff}}},
    {{{    57,    -20,    101}, 0, {  1052,      4}, {0x4a, 0x11, 0x65, 0xff}}},
    {{{     0,      4,    113}, 0, {   460,   -208}, {0x00, 0x2b, 0x77, 0xff}}},
};

// 0x06006A10
static const Vtx toad_seg6_vertex_06006A10[] = {
    {{{     0,   -143,      8}, 0, {  -546,    672}, {0xf8, 0x85, 0xe4, 0xff}}},
    {{{   -29,   -135,     34}, 0, {  -802,    592}, {0xc8, 0x8f, 0xfd, 0xff}}},
    {{{   -56,   -113,      7}, 0, {  -560,    370}, {0xab, 0xae, 0xd4, 0xff}}},
    {{{   -56,    -68,    103}, 0, {  -108,    448}, {0xa9, 0xfb, 0x5b, 0xff}}},
    {{{   -56,    -20,    101}, 0, {  -118,     16}, {0xb5, 0x11, 0x64, 0xff}}},
    {{{   -86,    -52,     32}, 0, {  -420,    314}, {0x84, 0xea, 0x06, 0xff}}},
    {{{   -77,    -96,     50}, 0, {  -314,    702}, {0x94, 0xc1, 0x13, 0xff}}},
    {{{    87,    -52,     32}, 0, {  1364,    296}, {0x7c, 0xf2, 0x16, 0xff}}},
    {{{    57,    -20,    101}, 0, {  1052,      4}, {0x4a, 0x11, 0x65, 0xff}}},
    {{{    57,    -68,    103}, 0, {  1058,    436}, {0x57, 0xfb, 0x5b, 0xff}}},
    {{{    78,    -96,     50}, 0, {  1274,    688}, {0x72, 0xcc, 0x0e, 0xff}}},
    {{{   -42,   -128,     69}, 0, { -1146,    510}, {0xbb, 0x9b, 0x1e, 0xff}}},
    {{{   -77,    -96,     50}, 0, {  -998,    182}, {0x94, 0xc1, 0x13, 0xff}}},
    {{{     0,   -135,     97}, 0, { -1412,    574}, {0x00, 0x8d, 0x34, 0xff}}},
    {{{   -86,    -52,     32}, 0, {  -858,   -260}, {0x84, 0xea, 0x06, 0xff}}},
    {{{   -61,    -80,    -18}, 0, {  -338,     40}, {0xb0, 0xc1, 0xb5, 0xff}}},
};

// 0x06006B10
static const Vtx toad_seg6_vertex_06006B10[] = {
    {{{     0,   -143,      8}, 0, {  -546,    672}, {0xf8, 0x85, 0xe4, 0xff}}},
    {{{   -56,   -113,      7}, 0, {  -560,    370}, {0xab, 0xae, 0xd4, 0xff}}},
    {{{     0,   -124,    -23}, 0, {  -254,    492}, {0x02, 0xa1, 0xad, 0xff}}},
    {{{   -61,    -80,    -18}, 0, {  -338,     40}, {0xb0, 0xc1, 0xb5, 0xff}}},
    {{{     0,   -135,     97}, 0, { -1412,    574}, {0x00, 0x8d, 0x34, 0xff}}},
    {{{    30,   -135,     34}, 0, {  -802,    592}, {0x33, 0x8e, 0xef, 0xff}}},
    {{{    43,   -128,     69}, 0, { -1146,    510}, {0x47, 0x9a, 0x18, 0xff}}},
    {{{     0,    -94,    -43}, 0, {   -92,    182}, {0x15, 0xb7, 0x9b, 0xff}}},
    {{{    57,   -113,      7}, 0, {  -560,    370}, {0x4d, 0xa9, 0xcf, 0xff}}},
    {{{    62,    -80,    -18}, 0, {  -338,     40}, {0x62, 0xc9, 0xc8, 0xff}}},
    {{{    78,    -96,     50}, 0, {  -998,    182}, {0x72, 0xcc, 0x0e, 0xff}}},
    {{{    87,    -52,     32}, 0, {  -858,   -260}, {0x7c, 0xf2, 0x16, 0xff}}},
};

// 0x06006BD0
static const Vtx toad_seg6_vertex_06006BD0[] = {
    {{{    34,    -28,     97}, 0, {   -26,    942}, {0x12, 0x9f, 0x4e, 0xff}}},
    {{{   142,    -44,     36}, 0, {  1040,   1000}, {0x45, 0xa0, 0x2c, 0xff}}},
    {{{    71,     13,    144}, 0, {    98,    396}, {0x28, 0xbb, 0x62, 0xff}}},
    {{{   -33,    -28,     97}, 0, {  -532,   1064}, {0xfb, 0x9e, 0x50, 0xff}}},
    {{{   176,      0,     13}, 0, {  1482,    566}, {0x78, 0xdd, 0x10, 0xff}}},
    {{{    89,     71,    148}, 0, {   306,   -192}, {0x3e, 0x0d, 0x6d, 0xff}}},
    {{{   -70,     13,    145}, 0, {  -966,    654}, {0xe6, 0xc0, 0x69, 0xff}}},
    {{{    34,    -28,     97}, 0, {   734,   1682}, {0x12, 0x9f, 0x4e, 0xff}}},
    {{{    76,    -57,     47}, 0, {   622,   1826}, {0x1f, 0x93, 0x38, 0xff}}},
    {{{   142,    -44,     36}, 0, {   640,   1996}, {0x45, 0xa0, 0x2c, 0xff}}},
    {{{    71,   -102,    -71}, 0, {   322,   1896}, {0x1d, 0x85, 0xfa, 0xff}}},
    {{{    34,    -88,     -5}, 0, {   458,   1758}, {0x0a, 0x86, 0x20, 0xff}}},
    {{{  -175,     48,    -12}, 0, {  -402,    498}, {0x88, 0x21, 0xed, 0xff}}},
    {{{   -70,    149,     72}, 0, {   194,     88}, {0xd3, 0x75, 0x12, 0xff}}},
    {{{  -141,     91,    -35}, 0, {  -264,    168}, {0xad, 0x52, 0xd1, 0xff}}},
};

// 0x06006CC0
static const Vtx toad_seg6_vertex_06006CC0[] = {
    {{{   -78,    122,    -51}, 0, {   490,    500}, {0xd3, 0x65, 0xc3, 0xff}}},
    {{{   -38,    154,      8}, 0, {  1016,    282}, {0xe4, 0x79, 0xe8, 0xff}}},
    {{{     0,    133,    -57}, 0, {   506,    -88}, {0x00, 0x70, 0xc5, 0xff}}},
    {{{   -70,    149,     72}, 0, {   194,     88}, {0xd3, 0x75, 0x12, 0xff}}},
    {{{    71,    149,     72}, 0, {  1052,    -96}, {0x26, 0x77, 0x15, 0xff}}},
    {{{    39,    154,      7}, 0, {   796,   -256}, {0x10, 0x7c, 0xee, 0xff}}},
    {{{   -38,    154,      8}, 0, {   320,   -154}, {0xe4, 0x79, 0xe8, 0xff}}},
    {{{   -87,    119,    122}, 0, {    22,    468}, {0xc3, 0x53, 0x49, 0xff}}},
    {{{    71,    149,     72}, 0, {  1066,     -2}, {0x26, 0x77, 0x15, 0xff}}},
    {{{   -70,    149,     72}, 0, {   120,     78}, {0xd3, 0x75, 0x12, 0xff}}},
    {{{    89,    119,    122}, 0, {  1202,    368}, {0x3a, 0x54, 0x4a, 0xff}}},
    {{{   -87,     71,    148}, 0, {    50,    828}, {0xc5, 0x10, 0x6f, 0xff}}},
    {{{    89,     71,    148}, 0, {  1230,    728}, {0x3e, 0x0d, 0x6d, 0xff}}},
    {{{   -70,     13,    145}, 0, {   200,   1082}, {0xe6, 0xc0, 0x69, 0xff}}},
    {{{  -141,     91,    -35}, 0, {   472,   1082}, {0xad, 0x52, 0xd1, 0xff}}},
    {{{   -70,     34,   -143}, 0, {  -446,    512}, {0xda, 0x31, 0x92, 0xff}}},
};

// 0x06006DC0
static const Vtx toad_seg6_vertex_06006DC0[] = {
    {{{  -141,     91,    -35}, 0, {   472,   1082}, {0xad, 0x52, 0xd1, 0xff}}},
    {{{   -70,    149,     72}, 0, {  1420,    692}, {0xd3, 0x75, 0x12, 0xff}}},
    {{{   -38,    154,      8}, 0, {  1016,    282}, {0xe4, 0x79, 0xe8, 0xff}}},
    {{{   -38,     90,   -112}, 0, {   -22,    184}, {0xf0, 0x54, 0xa3, 0xff}}},
    {{{   -78,    122,    -51}, 0, {   490,    500}, {0xd3, 0x65, 0xc3, 0xff}}},
    {{{     0,    133,    -57}, 0, {   506,    -88}, {0x00, 0x70, 0xc5, 0xff}}},
    {{{  -175,     48,    -12}, 0, {  -354,    -42}, {0x88, 0x21, 0xed, 0xff}}},
    {{{   -87,    119,    122}, 0, {  1274,     12}, {0xc3, 0x53, 0x49, 0xff}}},
    {{{   -70,    149,     72}, 0, {  1116,   -304}, {0xd3, 0x75, 0x12, 0xff}}},
    {{{  -175,      0,     13}, 0, {  -346,    408}, {0x87, 0xe0, 0x13, 0xff}}},
    {{{   -87,     71,    148}, 0, {  1280,    464}, {0xc5, 0x10, 0x6f, 0xff}}},
    {{{  -141,    -44,     37}, 0, {  -168,    914}, {0xba, 0xa7, 0x37, 0xff}}},
    {{{   -70,     34,   -143}, 0, {  -446,    512}, {0xda, 0x31, 0x92, 0xff}}},
    {{{    89,     71,    148}, 0, {   -76,    968}, {0x3e, 0x0d, 0x6d, 0xff}}},
    {{{   176,      0,     13}, 0, {  1032,    922}, {0x78, 0xdd, 0x10, 0xff}}},
    {{{   176,     47,    -12}, 0, {  1026,    610}, {0x79, 0x22, 0xf0, 0xff}}},
};

// 0x06006EC0
static const Vtx toad_seg6_vertex_06006EC0[] = {
    {{{  -141,    -44,     37}, 0, {  -168,    914}, {0xba, 0xa7, 0x37, 0xff}}},
    {{{   -70,     13,    145}, 0, {  1136,    958}, {0xe6, 0xc0, 0x69, 0xff}}},
    {{{   -87,     71,    148}, 0, {  1280,    464}, {0xc5, 0x10, 0x6f, 0xff}}},
    {{{   -66,    -61,     45}, 0, {   554,   1460}, {0xe7, 0x96, 0x3f, 0xff}}},
    {{{   -33,    -28,     97}, 0, {   706,   1508}, {0xfb, 0x9e, 0x50, 0xff}}},
    {{{   -70,     13,    145}, 0, {   842,   1372}, {0xe6, 0xc0, 0x69, 0xff}}},
    {{{  -141,    -44,     37}, 0, {   524,   1270}, {0xba, 0xa7, 0x37, 0xff}}},
    {{{   -33,    -88,     -5}, 0, {   432,   1586}, {0xec, 0x89, 0x25, 0xff}}},
    {{{   -70,   -102,    -71}, 0, {   266,   1534}, {0xd7, 0x88, 0x00, 0xff}}},
    {{{    89,     71,    148}, 0, {   -76,    968}, {0x3e, 0x0d, 0x6d, 0xff}}},
    {{{   176,     47,    -12}, 0, {  1026,    610}, {0x79, 0x22, 0xf0, 0xff}}},
    {{{    89,    119,    122}, 0, {   -82,    656}, {0x3a, 0x54, 0x4a, 0xff}}},
    {{{    34,    -88,     -5}, 0, {   458,   1758}, {0x0a, 0x86, 0x20, 0xff}}},
    {{{   142,     91,    -36}, 0, {   908,    228}, {0x54, 0x55, 0xd7, 0xff}}},
    {{{    71,    149,     72}, 0, {    18,    266}, {0x26, 0x77, 0x15, 0xff}}},
};

// 0x06006FB0
static const Vtx toad_seg6_vertex_06006FB0[] = {
    {{{   -88,    -72,   -121}, 0, {  -182,    430}, {0xc2, 0xae, 0xb7, 0xff}}},
    {{{  -175,     48,    -12}, 0, {  1388,    114}, {0x88, 0x21, 0xed, 0xff}}},
    {{{   -88,    -23,   -147}, 0, {  -130,    -66}, {0xc6, 0xf2, 0x91, 0xff}}},
    {{{  -175,      0,     13}, 0, {  1336,    612}, {0x87, 0xe0, 0x13, 0xff}}},
    {{{   -70,   -102,    -71}, 0, {   -80,    898}, {0xd7, 0x88, 0x00, 0xff}}},
    {{{  -141,    -44,     37}, 0, {  1138,   1040}, {0xba, 0xa7, 0x37, 0xff}}},
    {{{    34,    -88,     -5}, 0, {   458,   1758}, {0x0a, 0x86, 0x20, 0xff}}},
    {{{   -70,   -102,    -71}, 0, {   266,   1534}, {0xd7, 0x88, 0x00, 0xff}}},
    {{{    71,   -102,    -71}, 0, {   322,   1896}, {0x1d, 0x85, 0xfa, 0xff}}},
    {{{    71,    149,     72}, 0, {    18,    266}, {0x26, 0x77, 0x15, 0xff}}},
    {{{   142,     91,    -36}, 0, {   908,    228}, {0x54, 0x55, 0xd7, 0xff}}},
    {{{    79,    122,    -52}, 0, {   704,   -146}, {0x2c, 0x6b, 0xcf, 0xff}}},
    {{{    39,    154,      7}, 0, {   210,   -124}, {0x10, 0x7c, 0xee, 0xff}}},
    {{{    79,    122,    -52}, 0, {   -82,    342}, {0x2c, 0x6b, 0xcf, 0xff}}},
    {{{    39,     90,   -112}, 0, {   670,    514}, {0x1c, 0x58, 0xaa, 0xff}}},
    {{{     0,    133,    -57}, 0, {   430,   -262}, {0x00, 0x70, 0xc5, 0xff}}},
};

// 0x060070B0
static const Vtx toad_seg6_vertex_060070B0[] = {
    {{{    71,     34,   -144}, 0, {   848,   1202}, {0x2d, 0x32, 0x95, 0xff}}},
    {{{   -38,     90,   -112}, 0, {  1178,    -54}, {0xf0, 0x54, 0xa3, 0xff}}},
    {{{    39,     90,   -112}, 0, {   670,    514}, {0x1c, 0x58, 0xaa, 0xff}}},
    {{{   142,     91,    -36}, 0, {  -508,    890}, {0x54, 0x55, 0xd7, 0xff}}},
    {{{    79,    122,    -52}, 0, {   -82,    342}, {0x2c, 0x6b, 0xcf, 0xff}}},
    {{{     0,    133,    -57}, 0, {   430,   -262}, {0x00, 0x70, 0xc5, 0xff}}},
    {{{   142,    -44,     36}, 0, {   -38,    932}, {0x45, 0xa0, 0x2c, 0xff}}},
    {{{    71,   -102,    -71}, 0, {  1100,    968}, {0x1d, 0x85, 0xfa, 0xff}}},
    {{{    88,    -72,   -121}, 0, {  1238,    498}, {0x3a, 0xad, 0xb5, 0xff}}},
    {{{    88,    -24,   -147}, 0, {   -90,    608}, {0x3d, 0xf2, 0x93, 0xff}}},
    {{{   -70,     34,   -143}, 0, {   904,    182}, {0xda, 0x31, 0x92, 0xff}}},
    {{{    71,     34,   -144}, 0, {   -10,    212}, {0x2d, 0x32, 0x95, 0xff}}},
    {{{   -38,     90,   -112}, 0, {   662,   -172}, {0xf0, 0x54, 0xa3, 0xff}}},
    {{{   -88,    -23,   -147}, 0, {  1048,    572}, {0xc6, 0xf2, 0x91, 0xff}}},
    {{{    88,    -72,   -121}, 0, {   -72,    958}, {0x3a, 0xad, 0xb5, 0xff}}},
    {{{   -88,    -72,   -121}, 0, {  1066,    922}, {0xc2, 0xae, 0xb7, 0xff}}},
};

// 0x060071B0
static const Vtx toad_seg6_vertex_060071B0[] = {
    {{{   176,      0,     13}, 0, {  -180,    454}, {0x78, 0xdd, 0x10, 0xff}}},
    {{{    88,    -24,   -147}, 0, {  1236,     52}, {0x3d, 0xf2, 0x93, 0xff}}},
    {{{   176,     47,    -12}, 0, {  -182,      6}, {0x79, 0x22, 0xf0, 0xff}}},
    {{{    88,    -72,   -121}, 0, {  1238,    498}, {0x3a, 0xad, 0xb5, 0xff}}},
    {{{   142,    -44,     36}, 0, {   -38,    932}, {0x45, 0xa0, 0x2c, 0xff}}},
};

// 0x06007200
static const Vtx toad_seg6_vertex_06007200[] = {
    {{{   176,     47,    -12}, 0, {     0,      0}, {0x79, 0x22, 0xf0, 0xff}}},
    {{{    71,     34,   -144}, 0, {     0,      0}, {0x2d, 0x32, 0x95, 0xff}}},
    {{{   142,     91,    -36}, 0, {     0,      0}, {0x54, 0x55, 0xd7, 0xff}}},
    {{{   -38,    154,      8}, 0, {     0,      0}, {0xe4, 0x79, 0xe8, 0xff}}},
    {{{    39,    154,      7}, 0, {     0,      0}, {0x10, 0x7c, 0xee, 0xff}}},
    {{{     0,    133,    -57}, 0, {     0,      0}, {0x00, 0x70, 0xc5, 0xff}}},
    {{{    79,    122,    -52}, 0, {     0,      0}, {0x2c, 0x6b, 0xcf, 0xff}}},
    {{{   -88,    -23,   -147}, 0, {     0,      0}, {0xc6, 0xf2, 0x91, 0xff}}},
    {{{  -141,     91,    -35}, 0, {     0,      0}, {0xad, 0x52, 0xd1, 0xff}}},
    {{{   -70,     34,   -143}, 0, {     0,      0}, {0xda, 0x31, 0x92, 0xff}}},
    {{{  -175,     48,    -12}, 0, {     0,      0}, {0x88, 0x21, 0xed, 0xff}}},
    {{{    71,   -102,    -71}, 0, {     0,      0}, {0x1d, 0x85, 0xfa, 0xff}}},
    {{{   -88,    -72,   -121}, 0, {     0,      0}, {0xc2, 0xae, 0xb7, 0xff}}},
    {{{    88,    -72,   -121}, 0, {     0,      0}, {0x3a, 0xad, 0xb5, 0xff}}},
    {{{   -70,   -102,    -71}, 0, {     0,      0}, {0xd7, 0x88, 0x00, 0xff}}},
    {{{    88,    -24,   -147}, 0, {     0,      0}, {0x3d, 0xf2, 0x93, 0xff}}},
};

// 0x06007300 - 0x06007498
const Gfx toad_seg6_dl_06007300[] = {
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, toad_seg6_texture_06005920),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPLight(&toad_seg6_lights_06005908.l, 1),
    gsSPLight(&toad_seg6_lights_06005908.a, 2),
    gsSPVertex(toad_seg6_vertex_06006920, 15, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  3,  0,  4, 0x0),
    gsSP2Triangles( 2,  4,  0, 0x0,  0,  5,  6, 0x0),
    gsSP2Triangles( 3,  5,  0, 0x0,  6,  1,  0, 0x0),
    gsSP2Triangles( 6,  5,  7, 0x0,  3,  7,  5, 0x0),
    gsSP2Triangles( 1,  6,  8, 0x0,  8,  6,  9, 0x0),
    gsSP2Triangles( 7,  9,  6, 0x0, 10,  9,  7, 0x0),
    gsSP2Triangles( 3, 11,  7, 0x0,  7, 11, 10, 0x0),
    gsSP2Triangles( 8, 12,  1, 0x0, 13, 14,  8, 0x0),
    gsSP2Triangles( 9, 13,  8, 0x0, 12,  8, 14, 0x0),
    gsSPVertex(toad_seg6_vertex_06006A10, 16, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  3,  4,  5, 0x0),
    gsSP2Triangles( 5,  6,  3, 0x0,  7,  8,  9, 0x0),
    gsSP2Triangles( 9, 10,  7, 0x0,  1, 11, 12, 0x0),
    gsSP2Triangles(13, 11,  1, 0x0,  1, 12,  2, 0x0),
    gsSP2Triangles(13,  1,  0, 0x0,  2, 12, 14, 0x0),
    gsSP1Triangle( 2, 14, 15, 0x0),
    gsSPVertex(toad_seg6_vertex_06006B10, 12, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  2,  1,  3, 0x0),
    gsSP2Triangles( 4,  0,  5, 0x0,  4,  5,  6, 0x0),
    gsSP2Triangles( 2,  3,  7, 0x0,  5,  0,  2, 0x0),
    gsSP2Triangles( 5,  2,  8, 0x0,  8,  2,  7, 0x0),
    gsSP2Triangles( 8,  7,  9, 0x0,  6,  5,  8, 0x0),
    gsSP2Triangles( 6,  8, 10, 0x0, 10,  8,  9, 0x0),
    gsSP1Triangle(10,  9, 11, 0x0),
    gsSPEndDisplayList(),
};

// // 0x06007498 - 0x060076C0
// const Gfx toad_seg6_dl_06007498[] = {
//     gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, toad_seg6_texture_06006120),
//     gsDPLoadSync(),
//     gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
//     gsSPVertex(toad_seg6_vertex_06006BD0, 15, 0),
//     gsSP2Triangles( 0,  1,  2, 0x0,  3,  0,  2, 0x0),
//     gsSP2Triangles( 2,  1,  4, 0x0,  2,  4,  5, 0x0),
//     gsSP2Triangles( 3,  2,  6, 0x0,  6,  2,  5, 0x0),
//     gsSP2Triangles( 7,  8,  9, 0x0,  8, 10,  9, 0x0),
//     gsSP2Triangles( 8, 11, 10, 0x0, 12, 13, 14, 0x0),
//     gsSPVertex(toad_seg6_vertex_06006CC0, 16, 0),
//     gsSP2Triangles( 0,  1,  2, 0x0,  3,  4,  5, 0x0),
//     gsSP2Triangles( 3,  5,  6, 0x0,  7,  8,  9, 0x0),
//     gsSP2Triangles( 7, 10,  8, 0x0, 11, 10,  7, 0x0),
//     gsSP2Triangles(11, 12, 10, 0x0, 13, 12, 11, 0x0),
//     gsSP2Triangles(14,  1,  0, 0x0, 15, 14,  0, 0x0),
//     gsSPVertex(toad_seg6_vertex_06006DC0, 16, 0),
//     gsSP2Triangles( 0,  1,  2, 0x0,  3,  4,  5, 0x0),
//     gsSP2Triangles( 6,  7,  8, 0x0,  9,  7,  6, 0x0),
//     gsSP2Triangles( 9, 10,  7, 0x0, 11, 10,  9, 0x0),
//     gsSP2Triangles(12,  4,  3, 0x0, 13, 14, 15, 0x0),
//     gsSPVertex(toad_seg6_vertex_06006EC0, 15, 0),
//     gsSP2Triangles( 0,  1,  2, 0x0,  3,  4,  5, 0x0),
//     gsSP2Triangles( 3,  5,  6, 0x0,  7,  3,  6, 0x0),
//     gsSP2Triangles( 7,  6,  8, 0x0,  9, 10, 11, 0x0),
//     gsSP2Triangles(12,  7,  8, 0x0, 11, 10, 13, 0x0),
//     gsSP1Triangle(11, 13, 14, 0x0),
//     gsSPVertex(toad_seg6_vertex_06006FB0, 16, 0),
//     gsSP2Triangles( 0,  1,  2, 0x0,  0,  3,  1, 0x0),
//     gsSP2Triangles( 4,  3,  0, 0x0,  4,  5,  3, 0x0),
//     gsSP2Triangles( 6,  7,  8, 0x0,  9, 10, 11, 0x0),
//     gsSP2Triangles( 9, 11, 12, 0x0, 13, 14, 15, 0x0),
//     gsSPVertex(toad_seg6_vertex_060070B0, 16, 0),
//     gsSP2Triangles( 0,  1,  2, 0x0,  3,  0,  2, 0x0),
//     gsSP2Triangles( 3,  2,  4, 0x0,  2,  1,  5, 0x0),
//     gsSP2Triangles( 6,  7,  8, 0x0,  9, 10, 11, 0x0),
//     gsSP2Triangles(11, 10, 12, 0x0,  9, 13, 10, 0x0),
//     gsSP2Triangles(14, 13,  9, 0x0, 14, 15, 13, 0x0),
//     gsSPVertex(toad_seg6_vertex_060071B0, 5, 0),
//     gsSP2Triangles( 0,  1,  2, 0x0,  0,  3,  1, 0x0),
//     gsSP1Triangle( 4,  3,  0, 0x0),
//     gsSPEndDisplayList(),
// };

// 0x060076C0 - 0x06007710
const Gfx toad_seg6_dl_060076C0[] = {
    gsSPVertex(toad_seg6_vertex_06007200, 16, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  3,  4,  5, 0x0),
    gsSP2Triangles( 4,  6,  5, 0x0,  7,  8,  9, 0x0),
    gsSP2Triangles( 7, 10,  8, 0x0, 11, 12, 13, 0x0),
    gsSP2Triangles(11, 14, 12, 0x0,  0, 15,  1, 0x0),
    gsSPEndDisplayList(),
};


static const Vtx toadle_head_mesh_vtx[] = {
	{{{0, -124, 103},0, {0x20E, 0x8B0},{0x1, 0x4E, 0x9C, 0xFF}}},
	{{{-21, -123, 92},0, {0xFF26, 0x8C4},{0x5A, 0x4C, 0xD1, 0xFF}}},
	{{{-17, -124, 74},0, {0xFC9D, 0x94C},{0x50, 0x51, 0x37, 0xFF}}},
	{{{-21, -73, 97},0, {0xFF7A, 0x73F},{0x57, 0x17, 0xA7, 0xFF}}},
	{{{0, -70, 104},0, {0x20E, 0x729},{0x0, 0x1F, 0x85, 0xFF}}},
	{{{21, -73, 97},0, {0x49A, 0x722},{0xAA, 0x1A, 0xA7, 0xFF}}},
	{{{20, -123, 92},0, {0x4EF, 0x8AD},{0xA6, 0x4D, 0xD1, 0xFF}}},
	{{{17, -124, 74},0, {0x743, 0x92C},{0xAE, 0x53, 0x34, 0xFF}}},
	{{{0, -131, 72},0, {0xBEB, 0x9B9},{0x2, 0x71, 0x3A, 0xFF}}},
	{{{-17, -124, 74},0, {0x1147, 0x94C},{0x50, 0x51, 0x37, 0xFF}}},
	{{{-23, -82, 63},0, {0xFB5, 0x7E7},{0x64, 0x36, 0x3A, 0xFF}}},
	{{{0, -93, 55},0, {0xC22, 0x89A},{0x3, 0x3F, 0x6E, 0xFF}}},
	{{{-33, -46, 38},0, {0xF32, 0x527},{0x5A, 0x3A, 0x44, 0xFF}}},
	{{{2, -60, 27},0, {0xC39, 0x5EF},{0xF7, 0x47, 0x69, 0xFF}}},
	{{{-2, -26, 10},0, {0xC4D, 0x340},{0x0, 0x1F, 0x7B, 0xFF}}},
	{{{33, -42, 40},0, {0x954, 0x4F8},{0x9D, 0x31, 0x3E, 0xFF}}},
	{{{37, -8, 26},0, {0x9E4, 0x202},{0xA7, 0x7, 0x5A, 0xFF}}},
	{{{-3, 20, 12},0, {0xC5B, 0x6C},{0x1, 0xD6, 0x78, 0xFF}}},
	{{{17, 24, 25},0, {0xAF3, 0xFFEC},{0xC2, 0xCC, 0x62, 0xFF}}},
	{{{-4, 54, 37},0, {0xC88, 0xFE43},{0x5, 0x9A, 0x4B, 0xFF}}},
	{{{26, 44, 42},0, {0x9AE, 0xFEC7},{0xBA, 0xB2, 0x47, 0xFF}}},
	{{{27, 56, 69},0, {0x729, 0xFE0C},{0xB4, 0x9B, 0xF8, 0xFF}}},
	{{{-3, 66, 77},0, {0x12E, 0xFD0C},{0x5, 0x83, 0xE9, 0xFF}}},
	{{{-2, 48, 106},0, {0x1DD, 0xFE96},{0x0, 0xB0, 0x9E, 0xFF}}},
	{{{-34, 53, 69},0, {0xFCD3, 0xFE4B},{0x52, 0xA0, 0xF8, 0xFF}}},
	{{{-4, 54, 37},0, {0xF7DE, 0xFE43},{0x5, 0x9A, 0x4B, 0xFF}}},
	{{{-33, 41, 43},0, {0xFA81, 0xFEFB},{0x4F, 0xB6, 0x42, 0xFF}}},
	{{{-24, 25, 26},0, {0xF931, 0x10},{0x42, 0xCF, 0x61, 0xFF}}},
	{{{-3, 20, 12},0, {0xF7B1, 0x6C},{0x1, 0xD6, 0x78, 0xFF}}},
	{{{-42, -12, 27},0, {0xFA1F, 0x248},{0x5C, 0xF, 0x56, 0xFF}}},
	{{{-2, -26, 10},0, {0xF7A3, 0x340},{0x0, 0x1F, 0x7B, 0xFF}}},
	{{{-33, -46, 38},0, {0xFA88, 0x527},{0x5A, 0x3A, 0x44, 0xFF}}},
	{{{-56, 9, 52},0, {0xFBC7, 0xFD},{0x7B, 0xEF, 0x1C, 0xFF}}},
	{{{-42, -12, 27},0, {0xFA1F, 0x248},{0x5C, 0xF, 0x56, 0xFF}}},
	{{{-33, -46, 38},0, {0xFA88, 0x527},{0x5A, 0x3A, 0x44, 0xFF}}},
	{{{-49, -29, 78},0, {0xFD61, 0x37E},{0x78, 0x23, 0xEA, 0xFF}}},
	{{{-23, -82, 63},0, {0xFB0B, 0x7E7},{0x64, 0x36, 0x3A, 0xFF}}},
	{{{-28, -69, 80},0, {0xFD5B, 0x72F},{0x77, 0x28, 0xEA, 0xFF}}},
	{{{-17, -124, 74},0, {0xFC9D, 0x94C},{0x50, 0x51, 0x37, 0xFF}}},
	{{{-21, -123, 92},0, {0xFF26, 0x8C4},{0x5A, 0x4C, 0xD1, 0xFF}}},
	{{{-21, -73, 97},0, {0xFF7A, 0x73F},{0x57, 0x17, 0xA7, 0xFF}}},
	{{{-31, -43, 98},0, {0xFF59, 0x4F0},{0x58, 0x24, 0xAC, 0xFF}}},
	{{{0, -44, 116},0, {0x207, 0x4D7},{0x6, 0x22, 0x86, 0xFF}}},
	{{{0, -70, 104},0, {0x20E, 0x729},{0x0, 0x1F, 0x85, 0xFF}}},
	{{{21, -73, 97},0, {0x49A, 0x722},{0xAA, 0x1A, 0xA7, 0xFF}}},
	{{{31, -43, 103},0, {0x47B, 0x4C9},{0xA7, 0x25, 0xAD, 0xFF}}},
	{{{28, -69, 80},0, {0x697, 0x704},{0x86, 0x23, 0xF4, 0xFF}}},
	{{{20, -123, 92},0, {0x4EF, 0x8AD},{0xA6, 0x4D, 0xD1, 0xFF}}},
	{{{23, -82, 63},0, {0x8B6, 0x7C1},{0x9A, 0x30, 0x3B, 0xFF}}},
	{{{17, -124, 74},0, {0x743, 0x92C},{0xAE, 0x53, 0x34, 0xFF}}},
	{{{0, -93, 55},0, {0xC22, 0x89A},{0x3, 0x3F, 0x6E, 0xFF}}},
	{{{0, -131, 72},0, {0xBEB, 0x9B9},{0x2, 0x71, 0x3A, 0xFF}}},
	{{{2, -60, 27},0, {0xC39, 0x5EF},{0xF7, 0x47, 0x69, 0xFF}}},
	{{{33, -42, 40},0, {0x954, 0x4F8},{0x9D, 0x31, 0x3E, 0xFF}}},
	{{{46, -26, 77},0, {0x692, 0x33B},{0x85, 0x1D, 0xF3, 0xFF}}},
	{{{51, 14, 50},0, {0x83D, 0xA8},{0x88, 0xE5, 0x20, 0xFF}}},
	{{{37, -8, 26},0, {0x9E4, 0x202},{0xA7, 0x7, 0x5A, 0xFF}}},
	{{{17, 24, 25},0, {0xAF3, 0xFFEC},{0xC2, 0xCC, 0x62, 0xFF}}},
	{{{26, 44, 42},0, {0x9AE, 0xFEC7},{0xBA, 0xB2, 0x47, 0xFF}}},
	{{{27, 56, 69},0, {0x729, 0xFE0C},{0xB4, 0x9B, 0xF8, 0xFF}}},
	{{{36, 32, 84},0, {0x5DF, 0xFF3C},{0x9E, 0xC4, 0xCB, 0xFF}}},
	{{{-2, 48, 106},0, {0x1DD, 0xFE96},{0x0, 0xB0, 0x9E, 0xFF}}},
	{{{-2, 28, 115},0, {0x1EE, 0xFF99},{0x2, 0xCF, 0x8B, 0xFF}}},
	{{{-42, 32, 85},0, {0xFE08, 0xFF5E},{0x64, 0xCA, 0xC7, 0xFF}}},
	{{{-34, 53, 69},0, {0xFCD3, 0xFE4B},{0x52, 0xA0, 0xF8, 0xFF}}},
	{{{-42, 32, 85},0, {0xFE08, 0xFF5E},{0x64, 0xCA, 0xC7, 0xFF}}},
	{{{-2, 48, 106},0, {0x1DD, 0xFE96},{0x0, 0xB0, 0x9E, 0xFF}}},
	{{{-56, 9, 52},0, {0xFBC7, 0xFD},{0x7B, 0xEF, 0x1C, 0xFF}}},
	{{{-33, 41, 43},0, {0xFA81, 0xFEFB},{0x4F, 0xB6, 0x42, 0xFF}}},
	{{{-42, -12, 27},0, {0xFA1F, 0x248},{0x5C, 0xF, 0x56, 0xFF}}},
	{{{-24, 25, 26},0, {0xF931, 0x10},{0x42, 0xCF, 0x61, 0xFF}}},
	{{{-40, 2, 105},0, {0xFF3B, 0x12F},{0x5A, 0xF5, 0xA8, 0xFF}}},
	{{{-49, -29, 78},0, {0xFD61, 0x37E},{0x78, 0x23, 0xEA, 0xFF}}},
	{{{-31, -43, 98},0, {0xFF59, 0x4F0},{0x58, 0x24, 0xAC, 0xFF}}},
	{{{-28, -69, 80},0, {0xFD5B, 0x72F},{0x77, 0x28, 0xEA, 0xFF}}},
	{{{0, -23, 120},0, {0x205, 0x2FC},{0x6, 0x11, 0x82, 0xFF}}},
	{{{-1, 3, 120},0, {0x1FE, 0x118},{0x5, 0xF3, 0x82, 0xFF}}},
	{{{38, 4, 108},0, {0x490, 0x130},{0xA6, 0xEC, 0xA9, 0xFF}}},
	{{{31, -43, 103},0, {0x47B, 0x4C9},{0xA7, 0x25, 0xAD, 0xFF}}},
	{{{0, -44, 116},0, {0x207, 0x4D7},{0x6, 0x22, 0x86, 0xFF}}},
	{{{46, -26, 77},0, {0x692, 0x33B},{0x85, 0x1D, 0xF3, 0xFF}}},
	{{{51, 14, 50},0, {0x83D, 0xA8},{0x88, 0xE5, 0x20, 0xFF}}},
	{{{36, 32, 84},0, {0x5DF, 0xFF3C},{0x9E, 0xC4, 0xCB, 0xFF}}},
	{{{-2, 28, 115},0, {0x1EE, 0xFF99},{0x2, 0xCF, 0x8B, 0xFF}}},
	{{{28, -69, 80},0, {0x697, 0x704},{0x86, 0x23, 0xF4, 0xFF}}},
};

const Gfx toadle_head_mesh_tri_0[] = {
	gsSPVertex(toadle_head_mesh_vtx + 0, 32, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
	gsSP2Triangles(0, 4, 3, 0, 0, 5, 4, 0),
	gsSP2Triangles(0, 6, 5, 0, 0, 7, 6, 0),
	gsSP2Triangles(0, 8, 7, 0, 0, 9, 8, 0),
	gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
	gsSP2Triangles(11, 10, 12, 0, 11, 12, 13, 0),
	gsSP2Triangles(13, 12, 14, 0, 14, 15, 13, 0),
	gsSP2Triangles(14, 16, 15, 0, 17, 16, 14, 0),
	gsSP2Triangles(17, 18, 16, 0, 19, 18, 17, 0),
	gsSP2Triangles(19, 20, 18, 0, 19, 21, 20, 0),
	gsSP2Triangles(19, 22, 21, 0, 21, 22, 23, 0),
	gsSP2Triangles(23, 22, 24, 0, 25, 24, 22, 0),
	gsSP2Triangles(25, 26, 24, 0, 25, 27, 26, 0),
	gsSP2Triangles(25, 28, 27, 0, 27, 28, 29, 0),
	gsSP2Triangles(28, 30, 29, 0, 30, 31, 29, 0),
	gsSPVertex(toadle_head_mesh_vtx + 32, 32, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSP2Triangles(4, 3, 2, 0, 4, 5, 3, 0),
	gsSP2Triangles(6, 5, 4, 0, 6, 7, 5, 0),
	gsSP2Triangles(5, 7, 8, 0, 8, 9, 5, 0),
	gsSP2Triangles(10, 9, 8, 0, 8, 11, 10, 0),
	gsSP2Triangles(10, 11, 12, 0, 12, 13, 10, 0),
	gsSP2Triangles(14, 13, 12, 0, 12, 15, 14, 0),
	gsSP2Triangles(15, 16, 14, 0, 15, 17, 16, 0),
	gsSP2Triangles(17, 18, 16, 0, 17, 19, 18, 0),
	gsSP2Triangles(16, 18, 20, 0, 16, 20, 21, 0),
	gsSP2Triangles(14, 16, 21, 0, 14, 21, 22, 0),
	gsSP2Triangles(22, 21, 23, 0, 23, 21, 24, 0),
	gsSP2Triangles(25, 23, 24, 0, 25, 26, 23, 0),
	gsSP2Triangles(23, 26, 27, 0, 27, 28, 23, 0),
	gsSP2Triangles(29, 28, 27, 0, 28, 29, 30, 0),
	gsSP1Triangle(30, 29, 31, 0),
	gsSPVertex(toadle_head_mesh_vtx + 64, 21, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 1, 0, 0),
	gsSP2Triangles(0, 4, 3, 0, 4, 5, 3, 0),
	gsSP2Triangles(4, 6, 5, 0, 3, 7, 1, 0),
	gsSP2Triangles(8, 7, 3, 0, 9, 7, 8, 0),
	gsSP2Triangles(8, 10, 9, 0, 11, 7, 9, 0),
	gsSP2Triangles(7, 11, 12, 0, 13, 12, 11, 0),
	gsSP2Triangles(14, 13, 11, 0, 11, 15, 14, 0),
	gsSP2Triangles(9, 15, 11, 0, 16, 13, 14, 0),
	gsSP2Triangles(13, 16, 17, 0, 17, 18, 13, 0),
	gsSP2Triangles(19, 13, 18, 0, 13, 19, 12, 0),
	gsSP2Triangles(7, 12, 19, 0, 1, 7, 19, 0),
	gsSP1Triangle(14, 20, 16, 0),
	gsSPEndDisplayList(),
};

// 0x06007710 - 0x06007788
const Gfx toad_seg6_dl_06007710[] = {
	gsSPDisplayList(mat_head_material),
	gsSPDisplayList(toadle_head_mesh_tri_0),
	gsSPDisplayList(mat_revert_head_material),
    gsSPEndDisplayList(),
};


#ifndef VERSION_JP
// 0x06007788 - 0x06007808
const Gfx toad_seg6_us_dl_06007788[] = {
	gsSPDisplayList(mat_head_material),
	gsSPDisplayList(toadle_head_mesh_tri_0),
	gsSPDisplayList(mat_revert_head_material),
	gsSPEndDisplayList(),
    // gsDPPipeSync(),
    // gsDPSetCombineMode(G_CC_MODULATERGBFADE, G_CC_MODULATERGBFADE),
    // gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD),
    // gsDPSetRenderMode(G_RM_CUSTOM_AA_ZB_XLU_SURF, G_RM_NOOP2),
    // gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    // gsDPTileSync(),
    // gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 5, G_TX_NOLOD, G_TX_CLAMP, 5, G_TX_NOLOD),
    // gsDPSetTileSize(0, 0, 0, (32 - 1) << G_TEXTURE_IMAGE_FRAC, (32 - 1) << G_TEXTURE_IMAGE_FRAC),
    // gsSPDisplayList(toad_seg6_dl_06007300),
    // // gsSPDisplayList(toad_seg6_dl_06007498),
    // gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
    // gsDPPipeSync(),
    // gsDPSetCombineMode(G_CC_SHADEFADEA, G_CC_SHADEFADEA),
    // gsSPDisplayList(toad_seg6_dl_060076C0),
    // gsDPPipeSync(),
    // gsSPEndDisplayList(),
};
#endif

// 0x06007788
static const Lights1 toad_seg6_lights_06007788 = gdSPDefLights1(
    0x21, 0x13, 0x5a,
    0x42, 0x27, 0xb5, 0x28, 0x28, 0x28
);

// 0x060077A0
static const Vtx toad_seg6_vertex_060077A0[] = {
    {{{   -80,    -27,    -24}, 0, {     0,      0}, {0x90, 0x28, 0xd5, 0xff}}},
    {{{   -61,     26,     28}, 0, {     0,      0}, {0x9c, 0x3a, 0x32, 0xff}}},
    {{{   -61,     26,    -27}, 0, {     0,      0}, {0x93, 0x37, 0xdf, 0xff}}},
    {{{   -35,     68,    -34}, 0, {     0,      0}, {0xc6, 0x48, 0xaa, 0xff}}},
    {{{    36,     68,    -34}, 0, {     0,      0}, {0x57, 0x4b, 0xcb, 0xff}}},
    {{{    31,     26,    -60}, 0, {     0,      0}, {0x26, 0x35, 0x94, 0xff}}},
    {{{    36,     60,     20}, 0, {     0,      0}, {0x54, 0x4d, 0x35, 0xff}}},
    {{{    62,     26,     28}, 0, {     0,      0}, {0x63, 0x3f, 0x2d, 0xff}}},
    {{{    62,     26,    -27}, 0, {     0,      0}, {0x6d, 0x2e, 0xd5, 0xff}}},
    {{{    26,     29,     50}, 0, {     0,      0}, {0x45, 0x31, 0x5e, 0xff}}},
    {{{    81,    -23,     30}, 0, {     0,      0}, {0x6a, 0x2e, 0x33, 0xff}}},
    {{{    81,    -27,    -24}, 0, {     0,      0}, {0x71, 0x26, 0xd6, 0xff}}},
    {{{    40,    -30,    -76}, 0, {     0,      0}, {0x32, 0x25, 0x92, 0xff}}},
    {{{    40,    -18,     65}, 0, {     0,      0}, {0x4f, 0x32, 0x55, 0xff}}},
    {{{   -80,    -23,     30}, 0, {     0,      0}, {0x93, 0x2c, 0x2f, 0xff}}},
    {{{   -30,     26,    -60}, 0, {     0,      0}, {0xcf, 0x2b, 0x94, 0xff}}},
};

// 0x060078A0
static const Vtx toad_seg6_vertex_060078A0[] = {
    {{{   -35,     60,     20}, 0, {     0,      0}, {0xa1, 0x4b, 0x23, 0xff}}},
    {{{   -61,     26,    -27}, 0, {     0,      0}, {0x93, 0x37, 0xdf, 0xff}}},
    {{{   -61,     26,     28}, 0, {     0,      0}, {0x9c, 0x3a, 0x32, 0xff}}},
    {{{   -25,     29,     50}, 0, {     0,      0}, {0xc2, 0x3a, 0x5d, 0xff}}},
    {{{   -39,    -18,     65}, 0, {     0,      0}, {0xb7, 0x2a, 0x5e, 0xff}}},
    {{{   -35,     68,    -34}, 0, {     0,      0}, {0xc6, 0x48, 0xaa, 0xff}}},
    {{{    40,    -30,    -76}, 0, {     0,      0}, {0x32, 0x25, 0x92, 0xff}}},
    {{{   -39,    -30,    -76}, 0, {     0,      0}, {0xcd, 0x27, 0x93, 0xff}}},
    {{{   -30,     26,    -60}, 0, {     0,      0}, {0xcf, 0x2b, 0x94, 0xff}}},
    {{{    31,     26,    -60}, 0, {     0,      0}, {0x26, 0x35, 0x94, 0xff}}},
    {{{   -80,    -23,     30}, 0, {     0,      0}, {0x93, 0x2c, 0x2f, 0xff}}},
    {{{   -80,    -27,    -24}, 0, {     0,      0}, {0x90, 0x28, 0xd5, 0xff}}},
};

// 0x06007960 - 0x06007A48
const Gfx toad_seg6_dl_06007960[] = {
    gsSPLight(&toad_seg6_lights_06007788.l, 1),
    gsSPLight(&toad_seg6_lights_06007788.a, 2),
    gsSPVertex(toad_seg6_vertex_060077A0, 16, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  3,  4,  5, 0x0),
    gsSP2Triangles( 4,  6,  7, 0x0,  4,  7,  8, 0x0),
    gsSP2Triangles( 8,  5,  4, 0x0,  9,  7,  6, 0x0),
    gsSP2Triangles(10,  8,  7, 0x0, 10,  7,  9, 0x0),
    gsSP2Triangles(10, 11,  8, 0x0, 12,  8, 11, 0x0),
    gsSP2Triangles(12,  5,  8, 0x0, 10,  9, 13, 0x0),
    gsSP2Triangles( 0, 14,  1, 0x0, 15,  0,  2, 0x0),
    gsSPVertex(toad_seg6_vertex_060078A0, 12, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  2,  3,  0, 0x0),
    gsSP2Triangles( 4,  3,  2, 0x0,  0,  5,  1, 0x0),
    gsSP2Triangles( 6,  7,  8, 0x0,  6,  8,  9, 0x0),
    gsSP2Triangles( 5,  9,  8, 0x0,  4,  2, 10, 0x0),
    gsSP2Triangles( 8,  1,  5, 0x0,  8,  7, 11, 0x0),
    gsSPEndDisplayList(),
};


static const Vtx toadle_vest_mesh_vtx[] = {
	{{{-17, -28, 55},0, {0xFFF0, 0xFFF0},{0xB, 0xEA, 0x83, 0xFF}}},
	{{{-25, 94, 33},0, {0xFFF0, 0xFFF0},{0xE5, 0xB2, 0xA0, 0xFF}}},
	{{{-45, -32, 53},0, {0xFFF0, 0xFFF0},{0xA, 0xEA, 0x83, 0xFF}}},
	{{{-16, 45, 42},0, {0xFFF0, 0xFFF0},{0xB, 0xEA, 0x83, 0xFF}}},
	{{{-10, 95, 27},0, {0xFFF0, 0xFFF0},{0xEB, 0x98, 0xBA, 0xFF}}},
	{{{-25, 101, -8},0, {0xFFF0, 0xFFF0},{0x5, 0x89, 0x2C, 0xFF}}},
	{{{-10, 102, -7},0, {0xFFF0, 0xFFF0},{0x4, 0x93, 0x41, 0xFF}}},
	{{{-21, 56, -45},0, {0xFFF0, 0xFFF0},{0x0, 0xB1, 0x63, 0xFF}}},
	{{{42, 56, -45},0, {0xFFF0, 0xFFF0},{0x0, 0xB1, 0x63, 0xFF}}},
	{{{30, 102, -7},0, {0xFFF0, 0xFFF0},{0xFD, 0x93, 0x41, 0xFF}}},
	{{{45, 101, -8},0, {0xFFF0, 0xFFF0},{0xFA, 0x8A, 0x2E, 0xFF}}},
	{{{45, 94, 33},0, {0xFFF0, 0xFFF0},{0x1A, 0xB3, 0x9F, 0xFF}}},
	{{{30, 95, 27},0, {0xFFF0, 0xFFF0},{0x17, 0x9A, 0xB8, 0xFF}}},
	{{{37, 45, 42},0, {0xFFF0, 0xFFF0},{0xF9, 0xE9, 0x83, 0xFF}}},
	{{{65, -32, 53},0, {0xFFF0, 0xFFF0},{0xF6, 0xEB, 0x83, 0xFF}}},
	{{{37, -28, 55},0, {0xFFF0, 0xFFF0},{0xF6, 0xEB, 0x83, 0xFF}}},
};

const Gfx toadle_vest_mesh_tri_0[] = {
	gsSPVertex(toadle_vest_mesh_vtx + 0, 16, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
	gsSP2Triangles(1, 3, 4, 0, 4, 5, 1, 0),
	gsSP2Triangles(4, 6, 5, 0, 7, 5, 6, 0),
	gsSP2Triangles(6, 8, 7, 0, 6, 9, 8, 0),
	gsSP2Triangles(10, 8, 9, 0, 9, 11, 10, 0),
	gsSP2Triangles(9, 12, 11, 0, 13, 11, 12, 0),
	gsSP2Triangles(14, 11, 13, 0, 14, 13, 15, 0),
	gsSPEndDisplayList(),
};


// 0x06007A48 - 0x06007A80
const Gfx toad_seg6_dl_06007A48[] = {
	gsSPDisplayList(mat_vest_material),
	gsSPDisplayList(toadle_vest_mesh_tri_0),
	gsSPDisplayList(mat_revert_vest_material),
    gsSPEndDisplayList(),
    // gsDPPipeSync(),
    // gsDPSetCombineMode(G_CC_SHADEFADEA, G_CC_SHADEFADEA),
    // gsSPClearGeometryMode(G_CULL_BACK),
    // gsSPDisplayList(toad_seg6_dl_06007960),
    // gsDPPipeSync(),
    // gsSPSetGeometryMode(G_CULL_BACK),
    // gsSPEndDisplayList(),
};

#ifndef VERSION_JP
// 0x06007B00 - 0x06007B28
const Gfx toad_seg6_us_dl_06007B00[] = {
	gsSPDisplayList(mat_vest_material),
	gsSPDisplayList(toadle_vest_mesh_tri_0),
	gsSPDisplayList(mat_revert_vest_material),
    gsSPEndDisplayList(),
    // gsDPPipeSync(),
    // gsDPSetCombineMode(G_CC_SHADEFADEA, G_CC_SHADEFADEA),
    // gsSPDisplayList(toad_seg6_dl_06007960),
    // gsDPPipeSync(),
    // gsSPEndDisplayList(),
};
#endif

// 0x06007A80
static const Lights1 toad_seg6_lights_06007A80 = gdSPDefLights1(
    0x7f, 0x7f, 0x7f,
    0xff, 0xff, 0xff, 200, -100, -80
);

// 0x06007A98
static const Lights1 toad_seg6_lights_06007A98 = gdSPDefLights1(
    0x7f, 0x6a, 0x50,
    0xfe, 0xd5, 0xa1, 0x28, 0x28, 0x28
);

// 0x06007AB0
static const Vtx toad_seg6_vertex_06007AB0[] = {
    {{{    44,    -69,    -33}, 0, {     0,      0}, {0x21, 0x90, 0xd1, 0xff}}},
    {{{   -34,    -45,    -60}, 0, {     0,      0}, {0xdb, 0xd0, 0x91, 0xff}}},
    {{{    35,    -45,    -60}, 0, {     0,      0}, {0x2e, 0xf5, 0x8b, 0xff}}},
    {{{    71,    -33,     25}, 0, {     0,      0}, {0x74, 0x05, 0x32, 0xff}}},
    {{{    57,      9,     22}, 0, {     0,      0}, {0x67, 0x41, 0x23, 0xff}}},
    {{{    29,      9,     49}, 0, {     0,      0}, {0x2b, 0x33, 0x6b, 0xff}}},
    {{{    35,    -33,     61}, 0, {     0,      0}, {0x28, 0xe3, 0x74, 0xff}}},
    {{{    44,    -69,     34}, 0, {     0,      0}, {0x43, 0xa0, 0x2e, 0xff}}},
    {{{    71,    -38,    -29}, 0, {     0,      0}, {0x72, 0xdc, 0xd7, 0xff}}},
    {{{    57,      9,    -26}, 0, {     0,      0}, {0x69, 0x30, 0xce, 0xff}}},
    {{{   -43,    -69,     34}, 0, {     0,      0}, {0xdb, 0x96, 0x3a, 0xff}}},
    {{{   -34,    -33,     61}, 0, {     0,      0}, {0xcf, 0x04, 0x74, 0xff}}},
    {{{   -28,      9,    -51}, 0, {     0,      0}, {0xd6, 0x25, 0x8f, 0xff}}},
    {{{    29,      9,    -51}, 0, {     0,      0}, {0x21, 0x2d, 0x8f, 0xff}}},
};

// 0x06007B90
static const Vtx toad_seg6_vertex_06007B90[] = {
    {{{   -70,    -38,    -29}, 0, {     0,      0}, {0x8d, 0xfe, 0xcc, 0xff}}},
    {{{   -56,      9,     22}, 0, {     0,      0}, {0x96, 0x35, 0x2c, 0xff}}},
    {{{   -56,      9,    -26}, 0, {     0,      0}, {0x98, 0x3c, 0xda, 0xff}}},
    {{{    44,    -69,    -33}, 0, {     0,      0}, {0x21, 0x90, 0xd1, 0xff}}},
    {{{   -43,    -69,     34}, 0, {     0,      0}, {0xdb, 0x96, 0x3a, 0xff}}},
    {{{   -43,    -69,    -33}, 0, {     0,      0}, {0xc0, 0x99, 0xdc, 0xff}}},
    {{{   -34,    -45,    -60}, 0, {     0,      0}, {0xdb, 0xd0, 0x91, 0xff}}},
    {{{   -34,    -33,     61}, 0, {     0,      0}, {0xcf, 0x04, 0x74, 0xff}}},
    {{{   -28,      9,     49}, 0, {     0,      0}, {0xdf, 0x3f, 0x68, 0xff}}},
    {{{   -70,    -33,     25}, 0, {     0,      0}, {0x8c, 0xe2, 0x29, 0xff}}},
    {{{    29,      9,     49}, 0, {     0,      0}, {0x2b, 0x33, 0x6b, 0xff}}},
    {{{   -28,      9,    -51}, 0, {     0,      0}, {0xd6, 0x25, 0x8f, 0xff}}},
};

// 0x06007C50
static const Vtx toad_seg6_vertex_06007C50[] = {
    {{{    29,      9,     49}, 0, {     0,      0}, {0x2b, 0x33, 0x6b, 0xff}}},
    {{{    57,      9,     22}, 0, {     0,      0}, {0x67, 0x41, 0x23, 0xff}}},
    {{{    21,     55,     14}, 0, {     0,      0}, {0x22, 0x6d, 0x36, 0xff}}},
    {{{   -28,      9,     49}, 0, {     0,      0}, {0xdf, 0x3f, 0x68, 0xff}}},
    {{{    21,     55,    -28}, 0, {     0,      0}, {0x43, 0x60, 0xd0, 0xff}}},
    {{{    57,      9,    -26}, 0, {     0,      0}, {0x69, 0x30, 0xce, 0xff}}},
    {{{   -20,     55,    -28}, 0, {     0,      0}, {0xdc, 0x67, 0xc0, 0xff}}},
    {{{   -20,     55,     14}, 0, {     0,      0}, {0xc0, 0x65, 0x29, 0xff}}},
    {{{    29,      9,    -51}, 0, {     0,      0}, {0x21, 0x2d, 0x8f, 0xff}}},
    {{{   -28,      9,    -51}, 0, {     0,      0}, {0xd6, 0x25, 0x8f, 0xff}}},
    {{{   -56,      9,     22}, 0, {     0,      0}, {0x96, 0x35, 0x2c, 0xff}}},
    {{{   -56,      9,    -26}, 0, {     0,      0}, {0x98, 0x3c, 0xda, 0xff}}},
};

// 0x06007D10 - 0x06007EB0
const Gfx toad_seg6_dl_06007D10[] = {
    gsSPLight(&toad_seg6_lights_06007A80.l, 1),
    gsSPLight(&toad_seg6_lights_06007A80.a, 2),
    gsSPVertex(toad_seg6_vertex_06007AB0, 14, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  3,  4,  5, 0x0),
    gsSP2Triangles( 3,  5,  6, 0x0,  3,  6,  7, 0x0),
    gsSP2Triangles( 7,  8,  3, 0x0,  3,  9,  4, 0x0),
    gsSP2Triangles( 3,  8,  9, 0x0, 10,  7,  6, 0x0),
    gsSP2Triangles(10,  6, 11, 0x0, 11,  6,  5, 0x0),
    gsSP2Triangles( 7,  0,  8, 0x0,  0,  7, 10, 0x0),
    gsSP2Triangles( 2, 12, 13, 0x0,  2,  1, 12, 0x0),
    gsSP2Triangles( 2,  8,  0, 0x0,  2, 13,  9, 0x0),
    gsSP1Triangle( 2,  9,  8, 0x0),
    gsSPVertex(toad_seg6_vertex_06007B90, 12, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  3,  4,  5, 0x0),
    gsSP2Triangles( 3,  5,  6, 0x0,  7,  8,  1, 0x0),
    gsSP2Triangles( 7,  1,  9, 0x0,  7, 10,  8, 0x0),
    gsSP2Triangles( 7,  9,  4, 0x0,  5,  4,  9, 0x0),
    gsSP2Triangles( 5,  9,  0, 0x0,  0,  9,  1, 0x0),
    gsSP2Triangles(11,  6,  0, 0x0, 11,  0,  2, 0x0),
    gsSP1Triangle( 0,  6,  5, 0x0),
    gsSPLight(&toad_seg6_lights_06007A98.l, 1),
    gsSPLight(&toad_seg6_lights_06007A98.a, 2),
    gsSPVertex(toad_seg6_vertex_06007C50, 12, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  2,  3,  0, 0x0),
    gsSP2Triangles( 4,  2,  1, 0x0,  4,  1,  5, 0x0),
    gsSP2Triangles( 6,  7,  2, 0x0,  6,  2,  4, 0x0),
    gsSP2Triangles( 2,  7,  3, 0x0,  5,  8,  4, 0x0),
    gsSP2Triangles( 6,  8,  9, 0x0,  6,  4,  8, 0x0),
    gsSP2Triangles(10,  3,  7, 0x0,  7, 11, 10, 0x0),
    gsSP2Triangles( 7,  6, 11, 0x0,  9, 11,  6, 0x0),
    gsSPEndDisplayList(),
};

// BODY!

static const Vtx toadle_body_mesh_vtx[] = {
	{{{-102, -55, -10},0, {0xF742, 0x40C},{0x1D, 0x16, 0x86, 0xFF}}},
	{{{-104, 27, 4},0, {0xFA13, 0x6F6},{0x37, 0xDD, 0x93, 0xFF}}},
	{{{-115, -61, -3},0, {0xF76A, 0x6E4},{0x51, 0x29, 0xA7, 0xFF}}},
	{{{-97, 23, -5},0, {0xFA9B, 0x421},{0x9, 0xFE, 0x81, 0xFF}}},
	{{{-35, 101, -9},0, {0xFD2F, 0x420},{0xF2, 0x6, 0x82, 0xFF}}},
	{{{-38, 106, -1},0, {0xFCF6, 0x6DB},{0x18, 0xB7, 0x9B, 0xFF}}},
	{{{1, 111, -1},0, {0xFE18, 0x6EB},{0x3, 0xAD, 0xA0, 0xFF}}},
	{{{36, 101, -9},0, {0xFFB5, 0x3EE},{0x9, 0xFD, 0x81, 0xFF}}},
	{{{39, 107, -2},0, {0xFF31, 0x6FB},{0xE1, 0xB1, 0xA1, 0xFF}}},
	{{{105, 27, 4},0, {0x270, 0x6F6},{0xCC, 0xDF, 0x91, 0xFF}}},
	{{{98, 23, -5},0, {0x237, 0x3E6},{0xFD, 0xFF, 0x81, 0xFF}}},
	{{{103, -56, -10},0, {0x454, 0x3E5},{0xE6, 0x14, 0x85, 0xFF}}},
	{{{116, -61, -3},0, {0x4F2, 0x6FA},{0xB0, 0x29, 0xA7, 0xFF}}},
	{{{65, -110, -13},0, {0x66F, 0x3E9},{0xEE, 0x35, 0x8E, 0xFF}}},
	{{{69, -118, -14},0, {0x6CB, 0x6C2},{0xD6, 0x6B, 0xCA, 0xFF}}},
	{{{-65, -110, -13},0, {0xA98, 0x3A7},{0x15, 0x3A, 0x91, 0xFF}}},
	{{{-68, -119, -14},0, {0xA8B, 0x6C3},{0x2B, 0x6D, 0xCE, 0xFF}}},
	{{{-115, -61, -3},0, {0xC58, 0x6BD},{0x51, 0x29, 0xA7, 0xFF}}},
	{{{-102, -55, -10},0, {0xC73, 0x3C8},{0x1D, 0x16, 0x86, 0xFF}}},
	{{{-97, 23, -5},0, {0xFE67, 0x1119},{0x9, 0xFE, 0x81, 0xFF}}},
	{{{-102, -55, -10},0, {0x9AF, 0x1127},{0x1D, 0x16, 0x86, 0xFF}}},
	{{{-95, -15, 12},0, {0x3BB, 0xEBA},{0x70, 0xF8, 0xC5, 0xFF}}},
	{{{-96, -51, 12},0, {0x872, 0xEAD},{0x6C, 0x1E, 0xC4, 0xFF}}},
	{{{-79, -78, 12},0, {0xB65, 0xC76},{0x5A, 0x43, 0xC4, 0xFF}}},
	{{{-65, -110, -13},0, {0x113F, 0xBF8},{0x15, 0x3A, 0x91, 0xFF}}},
	{{{-59, -103, 11},0, {0xE58, 0xA3F},{0x2F, 0x62, 0xBE, 0xFF}}},
	{{{-2, -104, 11},0, {0xE2C, 0x221},{0x1, 0x73, 0xCA, 0xFF}}},
	{{{65, -110, -13},0, {0x113F, 0xF864},{0xEE, 0x35, 0x8E, 0xFF}}},
	{{{58, -103, 11},0, {0xE00, 0xFA02},{0xD4, 0x68, 0xC5, 0xFF}}},
	{{{80, -79, 12},0, {0xA5C, 0xF7DB},{0xA3, 0x44, 0xC9, 0xFF}}},
	{{{103, -56, -10},0, {0x7FE, 0xF2C0},{0xE6, 0x14, 0x85, 0xFF}}},
	{{{96, -52, 12},0, {0x6B9, 0xF5B5},{0x96, 0x1B, 0xC0, 0xFF}}},
	{{{95, -16, 12},0, {0x1AD, 0xF6BC},{0x90, 0xFB, 0xC4, 0xFF}}},
	{{{98, 23, -5},0, {0xFBA9, 0xF577},{0xFD, 0xFF, 0x81, 0xFF}}},
	{{{92, 22, 13},0, {0xFCA2, 0xF7C3},{0x99, 0xD8, 0xC1, 0xFF}}},
	{{{64, 60, 11},0, {0xF8CA, 0xFBEE},{0xAB, 0xB6, 0xC6, 0xFF}}},
	{{{36, 101, -9},0, {0xF2A1, 0xFF69},{0x9, 0xFD, 0x81, 0xFF}}},
	{{{35, 94, 9},0, {0xF4F3, 0x1A},{0xD0, 0xA4, 0xB7, 0xFF}}},
	{{{2, 96, 9},0, {0xF540, 0x455},{0xFE, 0x96, 0xBA, 0xFF}}},
	{{{-35, 101, -9},0, {0xF32E, 0x974},{0xF2, 0x6, 0x82, 0xFF}}},
	{{{-33, 94, 9},0, {0xF58E, 0x891},{0x2E, 0x9F, 0xBB, 0xFF}}},
	{{{-62, 61, 11},0, {0xFA49, 0xBAB},{0x58, 0xB7, 0xC9, 0xFF}}},
	{{{-90, 24, 13},0, {0xFF04, 0xEC6},{0x64, 0xD5, 0xBF, 0xFF}}},
	{{{-78, 16, 26},0, {0xFFA1, 0xC74},{0x3D, 0xEA, 0x93, 0xFF}}},
	{{{-82, -16, 27},0, {0x36B, 0xC53},{0x43, 0xF7, 0x95, 0xFF}}},
	{{{-83, -46, 28},0, {0x735, 0xC33},{0x47, 0xF, 0x98, 0xFF}}},
	{{{-70, -68, 29},0, {0x953, 0xA5D},{0x3B, 0x2B, 0x98, 0xFF}}},
	{{{-47, -87, 31},0, {0xB71, 0x887},{0x1A, 0x3D, 0x94, 0xFF}}},
	{{{7, -91, 31},0, {0xB19, 0x213},{0x1, 0x46, 0x96, 0xFF}}},
	{{{55, -89, 31},0, {0xAC1, 0xFBA0},{0xDB, 0x40, 0x99, 0xFF}}},
	{{{72, -68, 29},0, {0x81B, 0xFA25},{0xC0, 0x22, 0x98, 0xFF}}},
	{{{96, -52, 12},0, {0x6B9, 0xF5B5},{0x96, 0x1B, 0xC0, 0xFF}}},
	{{{82, -41, 28},0, {0x575, 0xF8AA},{0xBC, 0x5, 0x95, 0xFF}}},
	{{{72, -68, 29},0, {0x81B, 0xFA25},{0xC0, 0x22, 0x98, 0xFF}}},
	{{{95, -16, 12},0, {0x1AD, 0xF6BC},{0x90, 0xFB, 0xC4, 0xFF}}},
	{{{83, -9, 27},0, {0x188, 0xF95C},{0xBE, 0xFA, 0x94, 0xFF}}},
	{{{92, 22, 13},0, {0xFCA2, 0xF7C3},{0x99, 0xD8, 0xC1, 0xFF}}},
	{{{79, 22, 25},0, {0xFD9B, 0xFA0E},{0xC1, 0xE0, 0x96, 0xFF}}},
	{{{64, 60, 11},0, {0xF8CA, 0xFBEE},{0xAB, 0xB6, 0xC6, 0xFF}}},
	{{{58, 51, 24},0, {0xFA70, 0xFD6C},{0xCE, 0xCC, 0x97, 0xFF}}},
	{{{29, 77, 22},0, {0xF745, 0xCA},{0xE7, 0xC9, 0x90, 0xFF}}},
	{{{35, 94, 9},0, {0xF4F3, 0x1A},{0xD0, 0xA4, 0xB7, 0xFF}}},
	{{{2, 96, 9},0, {0xF540, 0x455},{0xFE, 0x96, 0xBA, 0xFF}}},
	{{{-4, 82, 22},0, {0xF799, 0x43C},{0xFE, 0xC3, 0x90, 0xFF}}},
	{{{-33, 94, 9},0, {0xF58E, 0x891},{0x2E, 0x9F, 0xBB, 0xFF}}},
	{{{-34, 79, 22},0, {0xF7EE, 0x7AD},{0x23, 0xC4, 0x95, 0xFF}}},
	{{{-62, 61, 11},0, {0xFA49, 0xBAB},{0x58, 0xB7, 0xC9, 0xFF}}},
	{{{-58, 50, 24},0, {0xFBC7, 0xA10},{0x37, 0xD0, 0x98, 0xFF}}},
	{{{-90, 24, 13},0, {0xFF04, 0xEC6},{0x64, 0xD5, 0xBF, 0xFF}}},
	{{{-78, 16, 26},0, {0xFFA1, 0xC74},{0x3D, 0xEA, 0x93, 0xFF}}},
	{{{-28, 21, 37},0, {0xFF52, 0x7F7},{0xD, 0xED, 0x83, 0xFF}}},
	{{{-31, -35, 40},0, {0x655, 0x7F0},{0xD, 0x5, 0x82, 0xFF}}},
	{{{-82, -16, 27},0, {0x36B, 0xC53},{0x43, 0xF7, 0x95, 0xFF}}},
	{{{-83, -46, 28},0, {0x735, 0xC33},{0x47, 0xF, 0x98, 0xFF}}},
	{{{-70, -68, 29},0, {0x953, 0xA5D},{0x3B, 0x2B, 0x98, 0xFF}}},
	{{{-47, -87, 31},0, {0xB71, 0x887},{0x1A, 0x3D, 0x94, 0xFF}}},
	{{{40, -37, 40},0, {0x575, 0xFD57},{0xEF, 0x3, 0x82, 0xFF}}},
	{{{7, -91, 31},0, {0xB19, 0x213},{0x1, 0x46, 0x96, 0xFF}}},
	{{{55, -89, 31},0, {0xAC1, 0xFBA0},{0xDB, 0x40, 0x99, 0xFF}}},
	{{{34, 17, 37},0, {0xFE54, 0xFEA5},{0xF1, 0xED, 0x83, 0xFF}}},
	{{{69, -118, -14},0, {0x23B, 0xE7E},{0xD6, 0x6B, 0xCA, 0xFF}}},
	{{{-68, -119, -14},0, {0x718, 0xA67},{0x2B, 0x6D, 0xCE, 0xFF}}},
	{{{-68, -108, -37},0, {0x617, 0x9C8},{0x32, 0x58, 0x4C, 0xFF}}},
	{{{-115, -61, -3},0, {0x784, 0x692},{0x51, 0x29, 0xA7, 0xFF}}},
	{{{-115, -51, -32},0, {0x607, 0x6B9},{0x71, 0x1A, 0x34, 0xFF}}},
	{{{-104, 27, 4},0, {0x4AF, 0x2FA},{0x37, 0xDD, 0x93, 0xFF}}},
	{{{-104, 25, -28},0, {0x3EF, 0x475},{0x6E, 0xCF, 0x28, 0xFF}}},
	{{{-37, 96, -30},0, {0xFFF3, 0x3C5},{0x32, 0x99, 0x37, 0xFF}}},
	{{{-38, 106, -1},0, {0xFF42, 0x23F},{0x18, 0xB7, 0x9B, 0xFF}}},
	{{{1, 111, -1},0, {0xFD8A, 0x393},{0x3, 0xAD, 0xA0, 0xFF}}},
	{{{39, 97, -31},0, {0xFD35, 0x5F5},{0xCF, 0x99, 0x38, 0xFF}}},
	{{{39, 107, -2},0, {0xFBDF, 0x4DB},{0xE1, 0xB1, 0xA1, 0xFF}}},
	{{{105, 27, 4},0, {0xFB4B, 0xA76},{0xCC, 0xDF, 0x91, 0xFF}}},
	{{{105, 24, -28},0, {0xFCF3, 0xA0B},{0x91, 0xD0, 0x27, 0xFF}}},
	{{{116, -51, -32},0, {0xFEBE, 0xC9C},{0x8F, 0x1A, 0x34, 0xFF}}},
	{{{116, -61, -3},0, {0xFE45, 0xE14},{0xB0, 0x29, 0xA7, 0xFF}}},
	{{{69, -107, -37},0, {0x1C4, 0xD4D},{0xCE, 0x59, 0x4B, 0xFF}}},
	{{{0, -63, -75},0, {0x29E, 0x9E6},{0x0, 0x31, 0x75, 0xFF}}},
	{{{-57, -45, -74},0, {0x3BE, 0x825},{0x26, 0x22, 0x74, 0xFF}}},
	{{{-70, 0, -76},0, {0x319, 0x6B1},{0x39, 0xF5, 0x71, 0xFF}}},
	{{{-53, 63, -64},0, {0x155, 0x56C},{0x36, 0xBE, 0x5E, 0xFF}}},
	{{{1, 70, -67},0, {0xFFAA, 0x642},{0x0, 0xBC, 0x6B, 0xFF}}},
	{{{54, 63, -63},0, {0xFE7B, 0x7AD},{0xC9, 0xBF, 0x5F, 0xFF}}},
	{{{73, 0, -74},0, {0xFF46, 0x9BE},{0xC4, 0xF3, 0x6F, 0xFF}}},
	{{{59, -46, -74},0, {0xA3, 0xAB0},{0xD9, 0x22, 0x74, 0xFF}}},
	{{{6, 4, -82},0, {0x108, 0x83D},{0xFE, 0xF7, 0x7F, 0xFF}}},
};

const Gfx toadle_body_mesh_tri_0[] = {
	gsSPVertex(toadle_body_mesh_vtx + 0, 19, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 1, 0, 0),
	gsSP2Triangles(4, 1, 3, 0, 4, 5, 1, 0),
	gsSP2Triangles(6, 5, 4, 0, 6, 4, 7, 0),
	gsSP2Triangles(7, 8, 6, 0, 7, 9, 8, 0),
	gsSP2Triangles(10, 9, 7, 0, 11, 9, 10, 0),
	gsSP2Triangles(11, 12, 9, 0, 13, 12, 11, 0),
	gsSP2Triangles(13, 14, 12, 0, 15, 14, 13, 0),
	gsSP2Triangles(15, 16, 14, 0, 15, 17, 16, 0),
	gsSP1Triangle(18, 17, 15, 0),
	gsSPEndDisplayList(),
};

const Gfx toadle_body_mesh_tri_1[] = {
	gsSPVertex(toadle_body_mesh_vtx + 19, 32, 0),
	gsSP2Triangles(0, 1, 2, 0, 1, 3, 2, 0),
	gsSP2Triangles(4, 3, 1, 0, 1, 5, 4, 0),
	gsSP2Triangles(5, 6, 4, 0, 7, 6, 5, 0),
	gsSP2Triangles(5, 8, 7, 0, 8, 9, 7, 0),
	gsSP2Triangles(10, 9, 8, 0, 8, 11, 10, 0),
	gsSP2Triangles(11, 12, 10, 0, 13, 12, 11, 0),
	gsSP2Triangles(11, 14, 13, 0, 14, 15, 13, 0),
	gsSP2Triangles(16, 15, 14, 0, 14, 17, 16, 0),
	gsSP2Triangles(17, 18, 16, 0, 19, 18, 17, 0),
	gsSP2Triangles(17, 20, 19, 0, 20, 21, 19, 0),
	gsSP2Triangles(22, 21, 20, 0, 22, 20, 0, 0),
	gsSP2Triangles(0, 23, 22, 0, 23, 0, 2, 0),
	gsSP2Triangles(24, 23, 2, 0, 24, 2, 25, 0),
	gsSP2Triangles(2, 26, 25, 0, 2, 3, 26, 0),
	gsSP2Triangles(4, 26, 3, 0, 4, 27, 26, 0),
	gsSP2Triangles(28, 27, 4, 0, 28, 4, 6, 0),
	gsSP2Triangles(7, 28, 6, 0, 7, 29, 28, 0),
	gsSP2Triangles(9, 29, 7, 0, 9, 30, 29, 0),
	gsSP2Triangles(10, 30, 9, 0, 10, 31, 30, 0),
	gsSP1Triangle(12, 31, 10, 0),
	gsSPVertex(toadle_body_mesh_vtx + 51, 29, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 1, 0, 0),
	gsSP2Triangles(3, 4, 1, 0, 5, 4, 3, 0),
	gsSP2Triangles(5, 6, 4, 0, 7, 6, 5, 0),
	gsSP2Triangles(7, 8, 6, 0, 9, 8, 7, 0),
	gsSP2Triangles(9, 7, 10, 0, 11, 9, 10, 0),
	gsSP2Triangles(11, 12, 9, 0, 13, 12, 11, 0),
	gsSP2Triangles(13, 14, 12, 0, 15, 14, 13, 0),
	gsSP2Triangles(15, 16, 14, 0, 17, 16, 15, 0),
	gsSP2Triangles(17, 18, 16, 0, 18, 19, 16, 0),
	gsSP2Triangles(20, 19, 18, 0, 20, 18, 21, 0),
	gsSP2Triangles(22, 20, 21, 0, 20, 22, 23, 0),
	gsSP2Triangles(24, 20, 23, 0, 24, 25, 20, 0),
	gsSP2Triangles(24, 26, 25, 0, 26, 27, 25, 0),
	gsSP2Triangles(25, 27, 2, 0, 1, 25, 2, 0),
	gsSP2Triangles(1, 28, 25, 0, 1, 4, 28, 0),
	gsSP2Triangles(4, 6, 28, 0, 28, 6, 8, 0),
	gsSP2Triangles(9, 28, 8, 0, 9, 19, 28, 0),
	gsSP2Triangles(9, 12, 19, 0, 12, 14, 19, 0),
	gsSP2Triangles(19, 14, 16, 0, 20, 28, 19, 0),
	gsSP1Triangle(20, 25, 28, 0),
	gsSPEndDisplayList(),
};

const Gfx toadle_body_mesh_tri_2[] = {
	gsSPVertex(toadle_body_mesh_vtx + 80, 26, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 2, 1, 0),
	gsSP2Triangles(3, 4, 2, 0, 5, 4, 3, 0),
	gsSP2Triangles(5, 6, 4, 0, 5, 7, 6, 0),
	gsSP2Triangles(5, 8, 7, 0, 7, 8, 9, 0),
	gsSP2Triangles(10, 7, 9, 0, 9, 11, 10, 0),
	gsSP2Triangles(12, 10, 11, 0, 12, 13, 10, 0),
	gsSP2Triangles(12, 14, 13, 0, 12, 15, 14, 0),
	gsSP2Triangles(15, 16, 14, 0, 15, 0, 16, 0),
	gsSP2Triangles(0, 2, 16, 0, 17, 16, 2, 0),
	gsSP2Triangles(17, 2, 18, 0, 4, 18, 2, 0),
	gsSP2Triangles(18, 4, 19, 0, 19, 4, 6, 0),
	gsSP2Triangles(20, 19, 6, 0, 20, 6, 7, 0),
	gsSP2Triangles(7, 21, 20, 0, 7, 10, 21, 0),
	gsSP2Triangles(21, 10, 22, 0, 13, 22, 10, 0),
	gsSP2Triangles(22, 13, 23, 0, 13, 14, 23, 0),
	gsSP2Triangles(23, 14, 24, 0, 24, 14, 16, 0),
	gsSP2Triangles(17, 24, 16, 0, 24, 17, 25, 0),
	gsSP2Triangles(17, 18, 25, 0, 19, 25, 18, 0),
	gsSP2Triangles(25, 19, 20, 0, 25, 20, 21, 0),
	gsSP2Triangles(21, 22, 25, 0, 22, 23, 25, 0),
	gsSP1Triangle(24, 25, 23, 0),
	gsSPEndDisplayList(),
};


// 0x06007EB0 - 0x06007ED8
const Gfx toad_seg6_dl_06007EB0[] = {
	gsSPDisplayList(mat_body_to_shell_material),
	gsSPDisplayList(toadle_body_mesh_tri_0),
	gsSPDisplayList(mat_body_material),
	gsSPDisplayList(toadle_body_mesh_tri_1),
	gsSPDisplayList(mat_shell_material),
	gsSPDisplayList(toadle_body_mesh_tri_2),
	gsSPEndDisplayList(),
    // gsDPPipeSync(),
    // gsDPSetCombineMode(G_CC_SHADEFADEA, G_CC_SHADEFADEA),
    // gsSPDisplayList(toad_seg6_dl_06007D10),
    // gsDPPipeSync(),
    // gsSPEndDisplayList(),
};

// 0x06007ED8
static const Lights1 toad_seg6_lights_06007ED8 = gdSPDefLights1(
    0x7f, 0x6a, 0x50,
    0xfe, 0xd5, 0xa1, 0x28, 0x28, 0x28
);

// 0x06007EF0
static const Vtx toad_seg6_vertex_06007EF0[] = {
    {{{     7,     14,    -12}, 0, {     0,      0}, {0x4b, 0x1f, 0x9f, 0xff}}},
    {{{    -1,     14,    -12}, 0, {     0,      0}, {0xcf, 0x36, 0x99, 0xff}}},
    {{{    11,     34,      0}, 0, {     0,      0}, {0x24, 0x79, 0xfc, 0xff}}},
    {{{     3,    -43,    -27}, 0, {     0,      0}, {0x35, 0x1e, 0x91, 0xff}}},
    {{{    11,    -43,     -2}, 0, {     0,      0}, {0x7e, 0xf5, 0x0a, 0xff}}},
    {{{   -11,     14,      0}, 0, {     0,      0}, {0x97, 0x46, 0x0d, 0xff}}},
    {{{    -1,     14,     13}, 0, {     0,      0}, {0xd2, 0x3f, 0x63, 0xff}}},
    {{{     7,     14,     13}, 0, {     0,      0}, {0x3d, 0x21, 0x69, 0xff}}},
    {{{     3,    -43,     28}, 0, {     0,      0}, {0x50, 0xee, 0x60, 0xff}}},
    {{{    20,    -51,    -15}, 0, {     0,      0}, {0x73, 0xf7, 0xcd, 0xff}}},
    {{{     4,    -57,     18}, 0, {     0,      0}, {0x62, 0xd9, 0x45, 0xff}}},
    {{{     4,    -57,    -25}, 0, {     0,      0}, {0x40, 0xbe, 0xa9, 0xff}}},
    {{{   -17,    -43,    -27}, 0, {     0,      0}, {0xcb, 0xf8, 0x8d, 0xff}}},
    {{{   -17,    -43,     28}, 0, {     0,      0}, {0xcd, 0xf9, 0x73, 0xff}}},
    {{{    12,    -76,      3}, 0, {     0,      0}, {0x42, 0xa7, 0x3b, 0xff}}},
    {{{    12,    -76,     -9}, 0, {     0,      0}, {0x50, 0xa6, 0xdb, 0xff}}},
};

// 0x06007FF0
static const Vtx toad_seg6_vertex_06007FF0[] = {
    {{{     4,    -57,     18}, 0, {     0,      0}, {0x62, 0xd9, 0x45, 0xff}}},
    {{{   -17,    -43,     28}, 0, {     0,      0}, {0xcd, 0xf9, 0x73, 0xff}}},
    {{{   -15,    -73,      8}, 0, {     0,      0}, {0xd4, 0x97, 0x37, 0xff}}},
    {{{     3,    -43,     28}, 0, {     0,      0}, {0x50, 0xee, 0x60, 0xff}}},
    {{{    12,    -76,      3}, 0, {     0,      0}, {0x42, 0xa7, 0x3b, 0xff}}},
    {{{   -15,    -73,    -12}, 0, {     0,      0}, {0xc5, 0xa6, 0xbe, 0xff}}},
    {{{   -17,    -43,    -27}, 0, {     0,      0}, {0xcb, 0xf8, 0x8d, 0xff}}},
    {{{     4,    -57,    -25}, 0, {     0,      0}, {0x40, 0xbe, 0xa9, 0xff}}},
    {{{    12,    -76,     -9}, 0, {     0,      0}, {0x50, 0xa6, 0xdb, 0xff}}},
    {{{   -35,    -43,      0}, 0, {     0,      0}, {0x83, 0xfa, 0xef, 0xff}}},
    {{{   -11,     14,      0}, 0, {     0,      0}, {0x97, 0x46, 0x0d, 0xff}}},
    {{{    -1,     14,     13}, 0, {     0,      0}, {0xd2, 0x3f, 0x63, 0xff}}},
    {{{    -1,     14,    -12}, 0, {     0,      0}, {0xcf, 0x36, 0x99, 0xff}}},
};

// 0x060080C0 - 0x060081F8
const Gfx toad_seg6_dl_060080C0[] = {
    gsSPLight(&toad_seg6_lights_06007ED8.l, 1),
    gsSPLight(&toad_seg6_lights_06007ED8.a, 2),
    gsSPVertex(toad_seg6_vertex_06007EF0, 16, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  1,  0,  3, 0x0),
    gsSP2Triangles( 0,  2,  4, 0x0,  4,  3,  0, 0x0),
    gsSP2Triangles( 2,  5,  6, 0x0,  6,  7,  2, 0x0),
    gsSP2Triangles( 4,  2,  7, 0x0,  5,  2,  1, 0x0),
    gsSP2Triangles( 7,  8,  4, 0x0,  4,  9,  3, 0x0),
    gsSP2Triangles( 4,  8, 10, 0x0, 11,  9,  4, 0x0),
    gsSP2Triangles( 4, 10, 11, 0x0,  1,  3, 12, 0x0),
    gsSP2Triangles(11,  3,  9, 0x0, 12,  3, 11, 0x0),
    gsSP2Triangles( 7, 13,  8, 0x0,  7,  6, 13, 0x0),
    gsSP2Triangles(10, 14, 15, 0x0, 10, 15, 11, 0x0),
    gsSPVertex(toad_seg6_vertex_06007FF0, 13, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  0,  3,  1, 0x0),
    gsSP2Triangles( 2,  4,  0, 0x0,  5,  6,  7, 0x0),
    gsSP2Triangles( 7,  8,  5, 0x0,  2,  8,  4, 0x0),
    gsSP2Triangles( 2,  5,  8, 0x0,  5,  2,  9, 0x0),
    gsSP2Triangles( 5,  9,  6, 0x0,  9,  2,  1, 0x0),
    gsSP2Triangles(10,  9,  1, 0x0, 10,  1, 11, 0x0),
    gsSP2Triangles( 9, 12,  6, 0x0,  9, 10, 12, 0x0),
    gsSPEndDisplayList(),
};

// LEFT ARM


static const Vtx toadle_arm_l_mesh_vtx[] = {
	{{{7, 14, -12},0, {0x1DE, 0xFBF8},{0xBA, 0xDE, 0x65, 0xFF}}},
	{{{-1, 14, -12},0, {0x9A, 0xFBF8},{0x30, 0xC6, 0x66, 0xFF}}},
	{{{11, 34, 0},0, {0x27F, 0xF8D0},{0xCF, 0x8B, 0x2, 0xFF}}},
	{{{3, -43, -27},0, {0x13C, 0x4FA},{0xC9, 0xEE, 0x71, 0xFF}}},
	{{{-17, -43, -27},0, {0xFE13, 0x4FA},{0x3F, 0x1, 0x6E, 0xFF}}},
	{{{4, -57, -25},0, {0x164, 0x730},{0xCD, 0x37, 0x66, 0xFF}}},
	{{{20, -51, -15},0, {0x3EB, 0x63D},{0x85, 0x20, 0xF8, 0xFF}}},
	{{{-15, -73, -12},0, {0xFE64, 0x9B7},{0x3C, 0x61, 0x38, 0xFF}}},
	{{{12, -76, -9},0, {0x2A8, 0xA30},{0xA3, 0x4B, 0x2A, 0xFF}}},
	{{{-11, 14, 0},0, {0xFF06, 0x32B},{0x6A, 0xBA, 0x3, 0xFF}}},
	{{{11, 34, 0},0, {0x27F, 0x32B},{0xCF, 0x8B, 0x2, 0xFF}}},
	{{{-1, 14, -12},0, {0x9A, 0x511},{0x30, 0xC6, 0x66, 0xFF}}},
	{{{-1, 14, 13},0, {0x9A, 0x11E},{0x31, 0xC3, 0x9C, 0xFF}}},
	{{{-11, 14, 0},0, {0x7E8, 0x32B},{0x6A, 0xBA, 0x3, 0xFF}}},
	{{{-17, -43, 28},0, {0xFEE6, 0xFEBF},{0x3A, 0xD, 0x90, 0xFF}}},
	{{{-1, 14, 13},0, {0x7E8, 0x11E},{0x31, 0xC3, 0x9C, 0xFF}}},
	{{{-35, -43, 0},0, {0xFEE6, 0x32B},{0x7F, 0x3, 0x0, 0xFF}}},
	{{{-1, 14, -12},0, {0x7E8, 0x511},{0x30, 0xC6, 0x66, 0xFF}}},
	{{{-17, -43, -27},0, {0xFEE6, 0x76F},{0x3F, 0x1, 0x6E, 0xFF}}},
	{{{-15, -73, -12},0, {0xFA29, 0x511},{0x3C, 0x61, 0x38, 0xFF}}},
	{{{-15, -73, 8},0, {0xFA29, 0x1E8},{0x37, 0x64, 0xC8, 0xFF}}},
	{{{4, -57, 18},0, {0xFCB0, 0x53},{0xB0, 0x36, 0xAE, 0xFF}}},
	{{{12, -76, 3},0, {0xF9B0, 0x2B2},{0xA2, 0x4A, 0xD6, 0xFF}}},
	{{{12, -76, -9},0, {0xF9B0, 0x497},{0xA3, 0x4B, 0x2A, 0xFF}}},
	{{{4, -57, -25},0, {0xFCB0, 0x71E},{0xCD, 0x37, 0x66, 0xFF}}},
	{{{11, -43, -2},0, {0xFEE6, 0x37C},{0x82, 0x10, 0xF9, 0xFF}}},
	{{{3, -43, 28},0, {0xFEE6, 0xFEBF},{0xBD, 0x14, 0x96, 0xFF}}},
	{{{7, 14, 13},0, {0x7E8, 0x11E},{0xB8, 0xDD, 0x9E, 0xFF}}},
	{{{11, 34, 0},0, {0xB10, 0x32B},{0xCF, 0x8B, 0x2, 0xFF}}},
	{{{7, 14, -12},0, {0x7E8, 0x511},{0xBA, 0xDE, 0x65, 0xFF}}},
	{{{3, -43, -27},0, {0xFEE6, 0x76F},{0xC9, 0xEE, 0x71, 0xFF}}},
	{{{-15, -73, 8},0, {0xFE64, 0x9B7},{0x37, 0x64, 0xC8, 0xFF}}},
	{{{12, -76, 3},0, {0x2A8, 0xA30},{0xA2, 0x4A, 0xD6, 0xFF}}},
	{{{4, -57, 18},0, {0x164, 0x730},{0xB0, 0x36, 0xAE, 0xFF}}},
	{{{-17, -43, 28},0, {0xFE13, 0x4FA},{0x3A, 0xD, 0x90, 0xFF}}},
	{{{3, -43, 28},0, {0x13C, 0x4FA},{0xBD, 0x14, 0x96, 0xFF}}},
	{{{7, 14, 13},0, {0x1DE, 0xFBF8},{0xB8, 0xDD, 0x9E, 0xFF}}},
	{{{-1, 14, 13},0, {0x9A, 0xFBF8},{0x31, 0xC3, 0x9C, 0xFF}}},
	{{{11, 34, 0},0, {0x27F, 0xF8D0},{0xCF, 0x8B, 0x2, 0xFF}}},
	{{{-15, -73, 8},0, {0xFE64, 0x1E8},{0x37, 0x64, 0xC8, 0xFF}}},
	{{{12, -76, -9},0, {0x2A8, 0x497},{0xA3, 0x4B, 0x2A, 0xFF}}},
	{{{12, -76, 3},0, {0x2A8, 0x2B2},{0xA2, 0x4A, 0xD6, 0xFF}}},
	{{{-15, -73, -12},0, {0xFE64, 0x511},{0x3C, 0x61, 0x38, 0xFF}}},
	{{{4, -57, -25},0, {0x164, 0x71E},{0xCD, 0x37, 0x66, 0xFF}}},
	{{{20, -51, -15},0, {0x3EB, 0x58A},{0x85, 0x20, 0xF8, 0xFF}}},
	{{{11, -43, -2},0, {0x27F, 0x37C},{0x82, 0x10, 0xF9, 0xFF}}},
	{{{3, -43, -27},0, {0x13C, 0x76F},{0xC9, 0xEE, 0x71, 0xFF}}},
};

const Gfx toadle_arm_l_mesh_tri_0[] = {
	gsSPVertex(toadle_arm_l_mesh_vtx + 0, 31, 0),
	gsSP2Triangles(0, 1, 2, 0, 1, 0, 3, 0),
	gsSP2Triangles(1, 3, 4, 0, 4, 3, 5, 0),
	gsSP2Triangles(5, 3, 6, 0, 7, 4, 5, 0),
	gsSP2Triangles(5, 8, 7, 0, 9, 10, 11, 0),
	gsSP2Triangles(10, 9, 12, 0, 13, 14, 15, 0),
	gsSP2Triangles(13, 16, 14, 0, 16, 13, 17, 0),
	gsSP2Triangles(16, 17, 18, 0, 19, 16, 18, 0),
	gsSP2Triangles(19, 20, 16, 0, 16, 20, 14, 0),
	gsSP2Triangles(21, 22, 23, 0, 21, 23, 24, 0),
	gsSP2Triangles(25, 21, 24, 0, 25, 26, 21, 0),
	gsSP2Triangles(27, 26, 25, 0, 25, 28, 27, 0),
	gsSP2Triangles(29, 28, 25, 0, 25, 30, 29, 0),
	gsSPVertex(toadle_arm_l_mesh_vtx + 31, 16, 0),
	gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
	gsSP2Triangles(2, 4, 3, 0, 5, 3, 4, 0),
	gsSP2Triangles(5, 6, 3, 0, 6, 5, 7, 0),
	gsSP2Triangles(8, 9, 10, 0, 8, 11, 9, 0),
	gsSP2Triangles(12, 13, 14, 0, 14, 13, 15, 0),
	gsSPEndDisplayList(),
};


// 0x060081F8 - 0x06008220
const Gfx toad_seg6_dl_060081F8[] = {
	gsSPDisplayList(mat_limb_material),
	gsSPDisplayList(toadle_arm_l_mesh_tri_0),
	gsSPDisplayList(mat_revert_limb_material),
    gsSPEndDisplayList(),
};

// 0x06008220
static const Lights1 toad_seg6_lights_06008220 = gdSPDefLights1(
    0x7f, 0x6a, 0x50,
    0xfe, 0xd5, 0xa1, 0x28, 0x28, 0x28
);

// 0x06008238
static const Vtx toad_seg6_vertex_06008238[] = {
    {{{    11,    -43,      3}, 0, {     0,      0}, {0x7d, 0xf5, 0xf5, 0xff}}},
    {{{     3,    -43,    -27}, 0, {     0,      0}, {0x40, 0xfa, 0x93, 0xff}}},
    {{{     7,     15,    -12}, 0, {     0,      0}, {0x4d, 0x1f, 0xa1, 0xff}}},
    {{{     3,    -43,     28}, 0, {     0,      0}, {0x41, 0x1c, 0x69, 0xff}}},
    {{{    20,    -51,     16}, 0, {     0,      0}, {0x73, 0xf7, 0x33, 0xff}}},
    {{{     4,    -57,    -17}, 0, {     0,      0}, {0x53, 0xc9, 0xb2, 0xff}}},
    {{{     4,    -57,     26}, 0, {     0,      0}, {0x54, 0xce, 0x50, 0xff}}},
    {{{    11,     34,      0}, 0, {     0,      0}, {0x25, 0x79, 0xff, 0xff}}},
    {{{     7,     15,     13}, 0, {     0,      0}, {0x3c, 0x22, 0x6a, 0xff}}},
    {{{    -1,     15,    -12}, 0, {     0,      0}, {0xcf, 0x37, 0x99, 0xff}}},
    {{{   -11,     15,      0}, 0, {     0,      0}, {0x98, 0x46, 0x0d, 0xff}}},
    {{{    -1,     15,     13}, 0, {     0,      0}, {0xd2, 0x40, 0x62, 0xff}}},
    {{{   -17,    -43,     28}, 0, {     0,      0}, {0xca, 0x05, 0x72, 0xff}}},
    {{{   -15,    -73,     13}, 0, {     0,      0}, {0xcc, 0x9b, 0x37, 0xff}}},
    {{{    12,    -76,     10}, 0, {     0,      0}, {0x3e, 0xa2, 0x3a, 0xff}}},
    {{{    12,    -76,     -2}, 0, {     0,      0}, {0x52, 0xa9, 0xda, 0xff}}},
};

// 0x06008338
static const Vtx toad_seg6_vertex_06008338[] = {
    {{{   -15,    -73,     -7}, 0, {     0,      0}, {0xcf, 0xa0, 0xbe, 0xff}}},
    {{{   -17,    -43,    -27}, 0, {     0,      0}, {0xd1, 0xe4, 0x8e, 0xff}}},
    {{{     4,    -57,    -17}, 0, {     0,      0}, {0x53, 0xc9, 0xb2, 0xff}}},
    {{{     3,    -43,    -27}, 0, {     0,      0}, {0x40, 0xfa, 0x93, 0xff}}},
    {{{    12,    -76,     -2}, 0, {     0,      0}, {0x52, 0xa9, 0xda, 0xff}}},
    {{{   -15,    -73,     13}, 0, {     0,      0}, {0xcc, 0x9b, 0x37, 0xff}}},
    {{{    12,    -76,     10}, 0, {     0,      0}, {0x3e, 0xa2, 0x3a, 0xff}}},
    {{{   -35,    -43,      0}, 0, {     0,      0}, {0x83, 0xf9, 0xf0, 0xff}}},
    {{{   -17,    -43,     28}, 0, {     0,      0}, {0xca, 0x05, 0x72, 0xff}}},
    {{{    -1,     15,    -12}, 0, {     0,      0}, {0xcf, 0x37, 0x99, 0xff}}},
    {{{   -11,     15,      0}, 0, {     0,      0}, {0x98, 0x46, 0x0d, 0xff}}},
};

// 0x060083E8 - 0x06008520
const Gfx toad_seg6_dl_060083E8[] = {
    gsSPLight(&toad_seg6_lights_06008220.l, 1),
    gsSPLight(&toad_seg6_lights_06008220.a, 2),
    gsSPVertex(toad_seg6_vertex_06008238, 16, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  3,  4,  0, 0x0),
    gsSP2Triangles( 5,  1,  0, 0x0,  0,  4,  6, 0x0),
    gsSP2Triangles( 0,  7,  8, 0x0,  8,  3,  0, 0x0),
    gsSP2Triangles( 2,  7,  0, 0x0,  6,  5,  0, 0x0),
    gsSP2Triangles( 9, 10,  7, 0x0,  7, 11,  8, 0x0),
    gsSP2Triangles( 7,  2,  9, 0x0, 11,  7, 10, 0x0),
    gsSP2Triangles(12,  3,  8, 0x0, 12,  8, 11, 0x0),
    gsSP2Triangles( 4,  3,  6, 0x0,  6,  3, 12, 0x0),
    gsSP2Triangles( 1,  9,  2, 0x0, 12, 11, 10, 0x0),
    gsSP2Triangles( 6, 12, 13, 0x0,  6, 14, 15, 0x0),
    gsSP2Triangles( 6, 15,  5, 0x0, 13, 14,  6, 0x0),
    gsSPVertex(toad_seg6_vertex_06008338, 11, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  1,  3,  2, 0x0),
    gsSP2Triangles( 2,  4,  0, 0x0,  4,  5,  0, 0x0),
    gsSP2Triangles( 4,  6,  5, 0x0,  7,  0,  5, 0x0),
    gsSP2Triangles( 8,  7,  5, 0x0,  3,  1,  9, 0x0),
    gsSP2Triangles( 1,  0,  7, 0x0,  9,  1,  7, 0x0),
    gsSP2Triangles( 8, 10,  7, 0x0,  9,  7, 10, 0x0),
    gsSPEndDisplayList(),
};

// Right Arm


static const Vtx toadle_arm_r_mesh_vtx[] = {
	{{{-1, 15, -12},0, {0xF1, 0x4FB},{0x30, 0xC4, 0x65, 0xFF}}},
	{{{-11, 15, 0},0, {0xFFA5, 0x36D},{0x6A, 0xBA, 0x3, 0xFF}}},
	{{{11, 34, 0},0, {0x27F, 0x36D},{0xCE, 0x8B, 0x2, 0xFF}}},
	{{{-1, 15, 13},0, {0xF1, 0x1BD},{0x30, 0xC2, 0x9C, 0xFF}}},
	{{{11, 34, 0},0, {0x27F, 0xFA61},{0xCE, 0x8B, 0x2, 0xFF}}},
	{{{7, 15, -12},0, {0x1FB, 0xFCD8},{0xB8, 0xDE, 0x63, 0xFF}}},
	{{{-1, 15, -12},0, {0xF1, 0xFCD8},{0x30, 0xC4, 0x65, 0xFF}}},
	{{{3, -43, -27},0, {0x176, 0x45C},{0xBD, 0x14, 0x6A, 0xFF}}},
	{{{-17, -43, -27},0, {0xFEDE, 0x45C},{0x3A, 0xD, 0x70, 0xFF}}},
	{{{4, -57, -17},0, {0x197, 0x62D},{0xB0, 0x36, 0x52, 0xFF}}},
	{{{-15, -73, -7},0, {0xFF21, 0x83F},{0x35, 0x65, 0x37, 0xFF}}},
	{{{12, -76, -2},0, {0x2A1, 0x8A3},{0xA2, 0x4A, 0x2A, 0xFF}}},
	{{{-17, -43, 28},0, {0xFF84, 0xFFCC},{0x3F, 0x2, 0x92, 0xFF}}},
	{{{-1, 15, 13},0, {0x708, 0x1BD},{0x30, 0xC2, 0x9C, 0xFF}}},
	{{{-11, 15, 0},0, {0x708, 0x36D},{0x6A, 0xBA, 0x3, 0xFF}}},
	{{{-35, -43, 0},0, {0xFF84, 0x36D},{0x7F, 0x3, 0x3, 0xFF}}},
	{{{-1, 15, -12},0, {0x708, 0x4FB},{0x30, 0xC4, 0x65, 0xFF}}},
	{{{-17, -43, -27},0, {0xFF84, 0x6EC},{0x3A, 0xD, 0x70, 0xFF}}},
	{{{-15, -73, -7},0, {0xFBA1, 0x455},{0x35, 0x65, 0x37, 0xFF}}},
	{{{-15, -73, 13},0, {0xFBA1, 0x1BD},{0x3C, 0x61, 0xC8, 0xFF}}},
	{{{-15, -73, 13},0, {0xFF21, 0x83F},{0x3C, 0x61, 0xC8, 0xFF}}},
	{{{12, -76, 10},0, {0x2A1, 0x8A3},{0xA3, 0x4B, 0xD6, 0xFF}}},
	{{{4, -57, 26},0, {0x197, 0x62D},{0xCD, 0x37, 0x9A, 0xFF}}},
	{{{-17, -43, 28},0, {0xFEDE, 0x45C},{0x3F, 0x2, 0x92, 0xFF}}},
	{{{3, -43, 28},0, {0x176, 0x45C},{0xC9, 0xEE, 0x8F, 0xFF}}},
	{{{20, -51, 16},0, {0x3AA, 0x565},{0x85, 0x20, 0x8, 0xFF}}},
	{{{7, 15, 13},0, {0x1FB, 0xFCD8},{0xBA, 0xDB, 0x9D, 0xFF}}},
	{{{-1, 15, 13},0, {0xF1, 0xFCD8},{0x30, 0xC2, 0x9C, 0xFF}}},
	{{{12, -76, -2},0, {0x2A1, 0x3AF},{0xA2, 0x4A, 0x2A, 0xFF}}},
	{{{-15, -73, 13},0, {0xFF21, 0x1BD},{0x3C, 0x61, 0xC8, 0xFF}}},
	{{{-15, -73, -7},0, {0xFF21, 0x455},{0x35, 0x65, 0x37, 0xFF}}},
	{{{12, -76, 10},0, {0x2A1, 0x221},{0xA3, 0x4B, 0xD6, 0xFF}}},
	{{{4, -57, 26},0, {0xFDB3, 0xE},{0xCD, 0x37, 0x9A, 0xFF}}},
	{{{12, -76, 10},0, {0xFB3D, 0x221},{0xA3, 0x4B, 0xD6, 0xFF}}},
	{{{12, -76, -2},0, {0xFB3D, 0x3AF},{0xA2, 0x4A, 0x2A, 0xFF}}},
	{{{4, -57, -17},0, {0xFDB3, 0x5A1},{0xB0, 0x36, 0x52, 0xFF}}},
	{{{11, -43, 3},0, {0xFF84, 0x309},{0x82, 0x10, 0x7, 0xFF}}},
	{{{3, -43, -27},0, {0xFF84, 0x6EC},{0xBD, 0x14, 0x6A, 0xFF}}},
	{{{7, 15, -12},0, {0x708, 0x4FB},{0xB8, 0xDE, 0x63, 0xFF}}},
	{{{11, 34, 0},0, {0x97F, 0x36D},{0xCE, 0x8B, 0x2, 0xFF}}},
	{{{7, 15, 13},0, {0x708, 0x1BD},{0xBA, 0xDB, 0x9D, 0xFF}}},
	{{{3, -43, 28},0, {0xFF84, 0xFFCC},{0xC9, 0xEE, 0x8F, 0xFF}}},
	{{{3, -43, 28},0, {0x176, 0xFFCC},{0xC9, 0xEE, 0x8F, 0xFF}}},
	{{{20, -51, 16},0, {0x3AA, 0x15A},{0x85, 0x20, 0x8, 0xFF}}},
	{{{11, -43, 3},0, {0x27F, 0x309},{0x82, 0x10, 0x7, 0xFF}}},
	{{{4, -57, 26},0, {0x197, 0xE},{0xCD, 0x37, 0x9A, 0xFF}}},
};

const Gfx toadle_arm_r_mesh_tri_0[] = {
	gsSPVertex(toadle_arm_r_mesh_vtx + 0, 32, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 2, 1, 0),
	gsSP2Triangles(4, 5, 6, 0, 7, 6, 5, 0),
	gsSP2Triangles(7, 8, 6, 0, 8, 7, 9, 0),
	gsSP2Triangles(10, 8, 9, 0, 9, 11, 10, 0),
	gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
	gsSP2Triangles(16, 15, 14, 0, 16, 17, 15, 0),
	gsSP2Triangles(17, 18, 15, 0, 15, 18, 19, 0),
	gsSP2Triangles(12, 15, 19, 0, 20, 21, 22, 0),
	gsSP2Triangles(22, 23, 20, 0, 22, 24, 23, 0),
	gsSP2Triangles(25, 24, 22, 0, 23, 24, 26, 0),
	gsSP2Triangles(23, 26, 27, 0, 4, 27, 26, 0),
	gsSP2Triangles(28, 29, 30, 0, 28, 31, 29, 0),
	gsSPVertex(toadle_arm_r_mesh_vtx + 32, 14, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSP2Triangles(0, 3, 4, 0, 3, 5, 4, 0),
	gsSP2Triangles(4, 5, 6, 0, 6, 7, 4, 0),
	gsSP2Triangles(4, 7, 8, 0, 8, 9, 4, 0),
	gsSP2Triangles(10, 11, 12, 0, 12, 11, 13, 0),
	gsSPEndDisplayList(),
};

// 0x06008520 - 0x06008560
const Gfx toad_seg6_dl_06008520[] = {
	gsSPDisplayList(mat_limb_material),
	gsSPDisplayList(toadle_arm_r_mesh_tri_0),
	gsSPDisplayList(mat_revert_limb_material),
	gsSPEndDisplayList(),
    // gsDPPipeSync(),
    // gsDPSetCombineMode(G_CC_SHADEFADEA, G_CC_SHADEFADEA),
    // gsSPDisplayList(toad_seg6_dl_060083E8),
    // gsDPPipeSync(),
    // gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
    // gsDPSetAlphaCompare(G_AC_NONE),
    // gsDPSetEnvColor(255, 255, 255, 255),
    // gsSPEndDisplayList(),
};

// US: 8608
#ifndef VERSION_JP
// 0x06008608 - 0x06008650
const Gfx toad_seg6_us_dl_06008608[] = {
	gsSPDisplayList(mat_limb_material),
	gsSPDisplayList(toadle_arm_r_mesh_tri_0),
	gsSPDisplayList(mat_revert_limb_material),
	gsSPEndDisplayList(),
    // gsDPPipeSync(),
    // gsDPSetCombineMode(G_CC_SHADEFADEA, G_CC_SHADEFADEA),
    // gsSPDisplayList(toad_seg6_dl_060083E8),
    // gsDPPipeSync(),
    // gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
    // gsDPSetAlphaCompare(G_AC_NONE),
    // gsDPSetEnvColor(255, 255, 255, 255),
    // gsDPSetRenderMode(G_RM_AA_ZB_XLU_SURF, G_RM_NOOP2),
    // gsSPEndDisplayList(),
};
#endif

// 0x06008560
static const Lights1 toad_seg6_lights_06008560 = gdSPDefLights1(
    0x34, 0x20, 0x0d,
    0x68, 0x40, 0x1b, 0x28, 0x28, 0x28
);

// 0x06008578
static const Vtx toad_seg6_vertex_06008578[] = {
    {{{   -17,     17,    -45}, 0, {     0,      0}, {0xce, 0x3b, 0x9d, 0xff}}},
    {{{    18,     17,    -45}, 0, {     0,      0}, {0x28, 0x51, 0xa8, 0xff}}},
    {{{    23,    -15,    -51}, 0, {     0,      0}, {0x1e, 0x98, 0xbf, 0xff}}},
    {{{   -22,    -15,    -51}, 0, {     0,      0}, {0xcf, 0xd9, 0x92, 0xff}}},
    {{{    46,    -15,    -25}, 0, {     0,      0}, {0x77, 0xe2, 0xe3, 0xff}}},
    {{{    34,    -15,     26}, 0, {     0,      0}, {0x70, 0xdf, 0x30, 0xff}}},
    {{{    17,    -15,     52}, 0, {     0,      0}, {0x2c, 0xab, 0x52, 0xff}}},
    {{{   -45,    -15,    -25}, 0, {     0,      0}, {0x89, 0xe0, 0xe6, 0xff}}},
    {{{   -33,    -15,     26}, 0, {     0,      0}, {0xa5, 0xb1, 0x27, 0xff}}},
    {{{   -16,    -15,     52}, 0, {     0,      0}, {0xc7, 0xda, 0x6a, 0xff}}},
    {{{    36,     17,    -20}, 0, {     0,      0}, {0x6f, 0x39, 0xea, 0xff}}},
    {{{   -35,     17,    -20}, 0, {     0,      0}, {0x9b, 0x4b, 0xf9, 0xff}}},
    {{{   -26,     11,     26}, 0, {     0,      0}, {0x99, 0x36, 0x31, 0xff}}},
    {{{   -13,      7,     47}, 0, {     0,      0}, {0xda, 0x51, 0x59, 0xff}}},
    {{{    14,      7,     47}, 0, {     0,      0}, {0x34, 0x3b, 0x63, 0xff}}},
    {{{    27,     11,     26}, 0, {     0,      0}, {0x5f, 0x45, 0x2e, 0xff}}},
};

// 0x06008678
static const Vtx toad_seg6_vertex_06008678[] = {
    {{{   -13,      7,     47}, 0, {     0,      0}, {0xda, 0x51, 0x59, 0xff}}},
    {{{    14,      7,     47}, 0, {     0,      0}, {0x34, 0x3b, 0x63, 0xff}}},
    {{{    14,     21,     26}, 0, {     0,      0}, {0x18, 0x6f, 0x37, 0xff}}},
    {{{   -13,     21,     26}, 0, {     0,      0}, {0xcf, 0x69, 0x31, 0xff}}},
    {{{   -26,     11,     26}, 0, {     0,      0}, {0x99, 0x36, 0x31, 0xff}}},
    {{{    18,     35,    -16}, 0, {     0,      0}, {0x37, 0x72, 0xfd, 0xff}}},
    {{{   -17,     35,    -16}, 0, {     0,      0}, {0xe0, 0x7a, 0xf3, 0xff}}},
    {{{    27,     11,     26}, 0, {     0,      0}, {0x5f, 0x45, 0x2e, 0xff}}},
    {{{   -35,     17,    -20}, 0, {     0,      0}, {0x9b, 0x4b, 0xf9, 0xff}}},
    {{{    34,    -15,     26}, 0, {     0,      0}, {0x70, 0xdf, 0x30, 0xff}}},
    {{{    36,     17,    -20}, 0, {     0,      0}, {0x6f, 0x39, 0xea, 0xff}}},
    {{{    18,     17,    -45}, 0, {     0,      0}, {0x28, 0x51, 0xa8, 0xff}}},
    {{{   -17,     17,    -45}, 0, {     0,      0}, {0xce, 0x3b, 0x9d, 0xff}}},
};

// 0x06008748 - 0x06008890
const Gfx toad_seg6_dl_06008748[] = {
    gsSPLight(&toad_seg6_lights_06008560.l, 1),
    gsSPLight(&toad_seg6_lights_06008560.a, 2),
    gsSPVertex(toad_seg6_vertex_06008578, 16, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  0,  2,  3, 0x0),
    gsSP2Triangles( 2,  4,  5, 0x0,  2,  5,  6, 0x0),
    gsSP2Triangles( 2,  7,  3, 0x0,  2,  8,  7, 0x0),
    gsSP2Triangles( 2,  9,  8, 0x0,  2,  6,  9, 0x0),
    gsSP2Triangles( 2,  1, 10, 0x0,  2, 10,  4, 0x0),
    gsSP2Triangles( 7, 11,  0, 0x0, 12, 11,  7, 0x0),
    gsSP2Triangles(12,  7,  8, 0x0,  7,  0,  3, 0x0),
    gsSP2Triangles(12,  8,  9, 0x0, 10,  5,  4, 0x0),
    gsSP2Triangles(12,  9, 13, 0x0, 14,  9,  6, 0x0),
    gsSP2Triangles(14, 13,  9, 0x0,  5, 14,  6, 0x0),
    gsSP1Triangle(10, 15,  5, 0x0),
    gsSPVertex(toad_seg6_vertex_06008678, 13, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  0,  2,  3, 0x0),
    gsSP2Triangles( 3,  4,  0, 0x0,  2,  5,  6, 0x0),
    gsSP2Triangles( 2,  6,  3, 0x0,  2,  1,  7, 0x0),
    gsSP2Triangles( 7,  5,  2, 0x0,  8,  4,  3, 0x0),
    gsSP2Triangles( 8,  3,  6, 0x0,  9,  7,  1, 0x0),
    gsSP2Triangles( 7, 10,  5, 0x0,  5, 10, 11, 0x0),
    gsSP2Triangles(11,  6,  5, 0x0, 11, 12,  6, 0x0),
    gsSP1Triangle( 6, 12,  8, 0x0),
    gsSPEndDisplayList(),
};

// Left Foot

static const Vtx toadle_foot_l_mesh_vtx[] = {
	{{{-35, 17, -20},0, {0x343, 0x42E},{0x6B, 0xBE, 0x11, 0xFF}}},
	{{{-13, 21, 26},0, {0x3B2, 0xFF2D},{0x26, 0x92, 0xCC, 0xFF}}},
	{{{-17, 35, -16},0, {0x538, 0x3BF},{0x2E, 0x8A, 0xA, 0xFF}}},
	{{{-35, 17, -20},0, {0xFE0F, 0x42E},{0x6B, 0xBE, 0x11, 0xFF}}},
	{{{-26, 11, 26},0, {0xFF09, 0xFF2D},{0x62, 0xBF, 0xD0, 0xFF}}},
	{{{-13, 21, 26},0, {0x73, 0xFF2D},{0x26, 0x92, 0xCC, 0xFF}}},
	{{{-13, 7, 47},0, {0x73, 0xFCE5},{0x2F, 0xBE, 0x9E, 0xFF}}},
	{{{14, 21, 26},0, {0x363, 0xFF2D},{0xDC, 0x93, 0xC9, 0xFF}}},
	{{{14, 7, 47},0, {0x363, 0xFCE5},{0xD0, 0xBF, 0x9E, 0xFF}}},
	{{{27, 11, 26},0, {0x4CD, 0xFF2D},{0x9D, 0xC2, 0xCF, 0xFF}}},
	{{{18, 35, -16},0, {0x3D2, 0x3BF},{0xD3, 0x8A, 0xB, 0xFF}}},
	{{{-17, 35, -16},0, {0x4, 0x3BF},{0x2E, 0x8A, 0xA, 0xFF}}},
	{{{18, 17, -45},0, {0x3D2, 0x6E6},{0xD2, 0xBE, 0x62, 0xFF}}},
	{{{36, 17, -20},0, {0x5C7, 0x42E},{0x94, 0xC0, 0x14, 0xFF}}},
	{{{-17, 17, -45},0, {0x4, 0x6E6},{0x2C, 0xBC, 0x62, 0xFF}}},
	{{{-17, 17, -45},0, {0x4, 0xA1},{0x2C, 0xBC, 0x62, 0xFF}}},
	{{{18, 17, -45},0, {0x3D2, 0xA1},{0xD2, 0xBE, 0x62, 0xFF}}},
	{{{23, -15, -51},0, {0x45D, 0x41B},{0xD0, 0x44, 0x60, 0xFF}}},
	{{{-22, -15, -51},0, {0xFF78, 0x41B},{0x2E, 0x44, 0x61, 0xFF}}},
	{{{-45, -15, -25},0, {0xFFC8, 0x4B9},{0x6B, 0x3F, 0x1B, 0xFF}}},
	{{{-17, 17, -45},0, {0x343, 0x6E6},{0x2C, 0xBC, 0x62, 0xFF}}},
	{{{-22, -15, -51},0, {0xFFC8, 0x78D},{0x2E, 0x44, 0x61, 0xFF}}},
	{{{-26, 11, 26},0, {0x29C, 0xFF2D},{0x62, 0xBF, 0xD0, 0xFF}}},
	{{{-33, -15, 26},0, {0xFFC8, 0xFF2D},{0x60, 0x49, 0xD8, 0xFF}}},
	{{{-16, -15, 52},0, {0xFFC8, 0xFC5A},{0x34, 0x42, 0xA0, 0xFF}}},
	{{{-13, 7, 47},0, {0x22C, 0xFCE5},{0x2F, 0xBE, 0x9E, 0xFF}}},
	{{{27, 11, 26},0, {0x29C, 0xFF2D},{0x9D, 0xC2, 0xCF, 0xFF}}},
	{{{36, 17, -20},0, {0x343, 0x42E},{0x94, 0xC0, 0x14, 0xFF}}},
	{{{18, 35, -16},0, {0x538, 0x3BF},{0xD3, 0x8A, 0xB, 0xFF}}},
	{{{34, -15, 26},0, {0xFFC8, 0xFF2D},{0xA0, 0x49, 0xD8, 0xFF}}},
	{{{14, 7, 47},0, {0x22C, 0xFCE5},{0xD0, 0xBF, 0x9E, 0xFF}}},
	{{{17, -15, 52},0, {0xFFC8, 0xFC5A},{0xCC, 0x42, 0xA0, 0xFF}}},
	{{{36, 17, -20},0, {0x343, 0x42E},{0x94, 0xC0, 0x14, 0xFF}}},
	{{{34, -15, 26},0, {0xFFC8, 0xFF2D},{0xA0, 0x49, 0xD8, 0xFF}}},
	{{{46, -15, -25},0, {0xFFC8, 0x4B9},{0x95, 0x3E, 0x1D, 0xFF}}},
	{{{23, -15, -51},0, {0xFFC8, 0x78D},{0xD0, 0x44, 0x60, 0xFF}}},
	{{{18, 17, -45},0, {0x343, 0x6E6},{0xD2, 0xBE, 0x62, 0xFF}}},
	{{{14, 7, 47},0, {0x363, 0x1B7},{0xD0, 0xBF, 0x9E, 0xFF}}},
	{{{-13, 7, 47},0, {0x73, 0x1B7},{0x2F, 0xBE, 0x9E, 0xFF}}},
	{{{-16, -15, 52},0, {0x1F, 0x41B},{0x34, 0x42, 0xA0, 0xFF}}},
	{{{17, -15, 52},0, {0x3B6, 0x41B},{0xCC, 0x42, 0xA0, 0xFF}}},
	{{{23, -15, -51},0, {0x45D, 0x78D},{0xD0, 0x44, 0x60, 0xFF}}},
	{{{46, -15, -25},0, {0x6DE, 0x4B9},{0x95, 0x3E, 0x1D, 0xFF}}},
	{{{34, -15, 26},0, {0x58F, 0xFF2D},{0xA0, 0x49, 0xD8, 0xFF}}},
	{{{17, -15, 52},0, {0x3B6, 0xFC5A},{0xCC, 0x42, 0xA0, 0xFF}}},
	{{{-16, -15, 52},0, {0x1F, 0xFC5A},{0x34, 0x42, 0xA0, 0xFF}}},
	{{{-33, -15, 26},0, {0xFE46, 0xFF2D},{0x60, 0x49, 0xD8, 0xFF}}},
	{{{-45, -15, -25},0, {0xFCF8, 0x4B9},{0x6B, 0x3F, 0x1B, 0xFF}}},
	{{{-22, -15, -51},0, {0xFF78, 0x78D},{0x2E, 0x44, 0x61, 0xFF}}},
};

const Gfx toadle_foot_l_mesh_tri_0[] = {
	gsSPVertex(toadle_foot_l_mesh_vtx + 0, 32, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
	gsSP2Triangles(5, 4, 6, 0, 6, 7, 5, 0),
	gsSP2Triangles(6, 8, 7, 0, 7, 8, 9, 0),
	gsSP2Triangles(9, 10, 7, 0, 7, 10, 11, 0),
	gsSP2Triangles(12, 11, 10, 0, 10, 13, 12, 0),
	gsSP2Triangles(12, 14, 11, 0, 11, 14, 3, 0),
	gsSP2Triangles(7, 11, 5, 0, 15, 16, 17, 0),
	gsSP2Triangles(15, 17, 18, 0, 19, 20, 21, 0),
	gsSP2Triangles(19, 0, 20, 0, 22, 0, 19, 0),
	gsSP2Triangles(22, 19, 23, 0, 22, 23, 24, 0),
	gsSP2Triangles(22, 24, 25, 0, 26, 27, 28, 0),
	gsSP2Triangles(27, 26, 29, 0, 29, 26, 30, 0),
	gsSP1Triangle(29, 30, 31, 0),
	gsSPVertex(toadle_foot_l_mesh_vtx + 32, 17, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 0, 2, 0),
	gsSP2Triangles(3, 4, 0, 0, 5, 6, 7, 0),
	gsSP2Triangles(5, 7, 8, 0, 9, 10, 11, 0),
	gsSP2Triangles(9, 11, 12, 0, 9, 12, 13, 0),
	gsSP2Triangles(9, 13, 14, 0, 9, 14, 15, 0),
	gsSP1Triangle(9, 15, 16, 0),
	gsSPEndDisplayList(),
};

// 0x06008890 - 0x060088B8
const Gfx toad_seg6_dl_06008890[] = {
	gsSPDisplayList(mat_limb_material),
	gsSPDisplayList(toadle_foot_l_mesh_tri_0),
	gsSPDisplayList(mat_revert_limb_material),
	gsSPEndDisplayList(),
    // gsDPPipeSync(),
    // gsDPSetCombineMode(G_CC_SHADEFADEA, G_CC_SHADEFADEA),
    // gsSPDisplayList(toad_seg6_dl_06008748),
    // gsDPPipeSync(),
    // gsSPEndDisplayList(),
};

// 0x060088B8
static const Lights1 toad_seg6_lights_060088B8 = gdSPDefLights1(
    0x34, 0x20, 0x0d,
    0x68, 0x40, 0x1b, 0x28, 0x28, 0x28
);

// 0x060088D0
static const Vtx toad_seg6_vertex_060088D0[] = {
    {{{   -22,    -15,     52}, 0, {     0,      0}, {0xe2, 0x98, 0x41, 0xff}}},
    {{{   -17,     17,     46}, 0, {     0,      0}, {0xd8, 0x51, 0x58, 0xff}}},
    {{{   -35,     17,     21}, 0, {     0,      0}, {0x91, 0x39, 0x16, 0xff}}},
    {{{    23,    -15,     52}, 0, {     0,      0}, {0x31, 0xd9, 0x6e, 0xff}}},
    {{{    18,     17,     46}, 0, {     0,      0}, {0x32, 0x3b, 0x63, 0xff}}},
    {{{   -45,    -15,     26}, 0, {     0,      0}, {0x89, 0xe2, 0x1d, 0xff}}},
    {{{   -33,    -15,    -25}, 0, {     0,      0}, {0x90, 0xdf, 0xd0, 0xff}}},
    {{{   -16,    -15,    -51}, 0, {     0,      0}, {0xd4, 0xab, 0xae, 0xff}}},
    {{{    46,    -15,     26}, 0, {     0,      0}, {0x77, 0xe0, 0x1a, 0xff}}},
    {{{    34,    -15,    -25}, 0, {     0,      0}, {0x5b, 0xb1, 0xd9, 0xff}}},
    {{{    17,    -15,    -51}, 0, {     0,      0}, {0x39, 0xda, 0x96, 0xff}}},
    {{{    27,     11,    -25}, 0, {     0,      0}, {0x67, 0x36, 0xcf, 0xff}}},
    {{{    36,     17,     21}, 0, {     0,      0}, {0x65, 0x4b, 0x07, 0xff}}},
    {{{   -13,      7,    -46}, 0, {     0,      0}, {0xcc, 0x3b, 0x9d, 0xff}}},
    {{{    14,      7,    -46}, 0, {     0,      0}, {0x26, 0x51, 0xa7, 0xff}}},
    {{{   -26,     11,    -25}, 0, {     0,      0}, {0xa1, 0x45, 0xd2, 0xff}}},
};

// 0x060089D0
static const Vtx toad_seg6_vertex_060089D0[] = {
    {{{   -13,     21,    -25}, 0, {     0,      0}, {0xe8, 0x6f, 0xc9, 0xff}}},
    {{{   -17,     35,     17}, 0, {     0,      0}, {0xc9, 0x72, 0x03, 0xff}}},
    {{{    18,     35,     17}, 0, {     0,      0}, {0x20, 0x7a, 0x0d, 0xff}}},
    {{{    14,     21,    -25}, 0, {     0,      0}, {0x31, 0x69, 0xcf, 0xff}}},
    {{{   -26,     11,    -25}, 0, {     0,      0}, {0xa1, 0x45, 0xd2, 0xff}}},
    {{{    14,      7,    -46}, 0, {     0,      0}, {0x26, 0x51, 0xa7, 0xff}}},
    {{{   -13,      7,    -46}, 0, {     0,      0}, {0xcc, 0x3b, 0x9d, 0xff}}},
    {{{    27,     11,    -25}, 0, {     0,      0}, {0x67, 0x36, 0xcf, 0xff}}},
    {{{    36,     17,     21}, 0, {     0,      0}, {0x65, 0x4b, 0x07, 0xff}}},
    {{{   -35,     17,     21}, 0, {     0,      0}, {0x91, 0x39, 0x16, 0xff}}},
    {{{    18,     17,     46}, 0, {     0,      0}, {0x32, 0x3b, 0x63, 0xff}}},
    {{{   -17,     17,     46}, 0, {     0,      0}, {0xd8, 0x51, 0x58, 0xff}}},
};

// 0x06008A90 - 0x06008BD8
const Gfx toad_seg6_dl_06008A90[] = {
    gsSPLight(&toad_seg6_lights_060088B8.l, 1),
    gsSPLight(&toad_seg6_lights_060088B8.a, 2),
    gsSPVertex(toad_seg6_vertex_060088D0, 16, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  0,  3,  4, 0x0),
    gsSP2Triangles( 0,  4,  1, 0x0,  0,  2,  5, 0x0),
    gsSP2Triangles( 0,  5,  6, 0x0,  0,  6,  7, 0x0),
    gsSP2Triangles( 0,  8,  3, 0x0,  0,  9,  8, 0x0),
    gsSP2Triangles( 0, 10,  9, 0x0,  0,  7, 10, 0x0),
    gsSP2Triangles( 8, 11, 12, 0x0,  8,  9, 11, 0x0),
    gsSP2Triangles( 8, 12,  4, 0x0,  8,  4,  3, 0x0),
    gsSP2Triangles(10, 11,  9, 0x0,  6,  5,  2, 0x0),
    gsSP2Triangles(10, 13, 14, 0x0, 10,  7, 13, 0x0),
    gsSP2Triangles(10, 14, 11, 0x0, 13,  7,  6, 0x0),
    gsSP2Triangles(13,  6, 15, 0x0,  6,  2, 15, 0x0),
    gsSPVertex(toad_seg6_vertex_060089D0, 12, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  0,  2,  3, 0x0),
    gsSP2Triangles( 1,  0,  4, 0x0,  0,  3,  5, 0x0),
    gsSP2Triangles( 0,  5,  6, 0x0,  6,  4,  0, 0x0),
    gsSP2Triangles( 7,  5,  3, 0x0,  3,  8,  7, 0x0),
    gsSP2Triangles( 3,  2,  8, 0x0,  1,  4,  9, 0x0),
    gsSP2Triangles(10,  8,  2, 0x0,  2, 11, 10, 0x0),
    gsSP2Triangles( 2,  1, 11, 0x0,  9, 11,  1, 0x0),
    gsSPEndDisplayList(),
};

// Right foot

static const Vtx toadle_foot_r_mesh_vtx[] = {
	{{{14, 21, -25},0, {0x383, 0x483},{0xDA, 0x92, 0x34, 0xFF}}},
	{{{18, 35, 17},0, {0x4EE, 0x40},{0xD2, 0x8A, 0xF6, 0xFF}}},
	{{{36, 17, 21},0, {0x31B, 0xFFD8},{0x95, 0xBE, 0xEF, 0xFF}}},
	{{{14, 21, -25},0, {0x354, 0x483},{0xDA, 0x92, 0x34, 0xFF}}},
	{{{36, 17, 21},0, {0x58F, 0xFFD8},{0x95, 0xBE, 0xEF, 0xFF}}},
	{{{27, 11, -25},0, {0x4A5, 0x483},{0x9E, 0xBF, 0x30, 0xFF}}},
	{{{14, 7, -46},0, {0x354, 0x6A4},{0xD1, 0xBE, 0x62, 0xFF}}},
	{{{-13, 21, -25},0, {0x97, 0x483},{0x24, 0x93, 0x37, 0xFF}}},
	{{{-13, 7, -46},0, {0x97, 0x6A4},{0x30, 0xBF, 0x62, 0xFF}}},
	{{{-26, 11, -25},0, {0xFF45, 0x483},{0x63, 0xC2, 0x31, 0xFF}}},
	{{{-17, 35, 17},0, {0x2F, 0x40},{0x2D, 0x8A, 0xF5, 0xFF}}},
	{{{18, 35, 17},0, {0x3BC, 0x40},{0xD2, 0x8A, 0xF6, 0xFF}}},
	{{{-17, 17, 46},0, {0x2F, 0xFD4F},{0x2E, 0xBE, 0x9E, 0xFF}}},
	{{{-35, 17, 21},0, {0xFE5B, 0xFFD8},{0x6C, 0xC0, 0xEC, 0xFF}}},
	{{{18, 17, 46},0, {0x3BC, 0xFD4F},{0xD4, 0xBC, 0x9E, 0xFF}}},
	{{{17, -15, -51},0, {0x3A2, 0x401},{0xCC, 0x42, 0x60, 0xFF}}},
	{{{-13, 7, -46},0, {0x97, 0x1C6},{0x30, 0xBF, 0x62, 0xFF}}},
	{{{14, 7, -46},0, {0x354, 0x1C6},{0xD1, 0xBE, 0x62, 0xFF}}},
	{{{-16, -15, -51},0, {0x49, 0x401},{0x34, 0x42, 0x60, 0xFF}}},
	{{{17, -15, -51},0, {0xFFDC, 0x726},{0xCC, 0x42, 0x60, 0xFF}}},
	{{{14, 7, -46},0, {0x217, 0x6A4},{0xD1, 0xBE, 0x62, 0xFF}}},
	{{{27, 11, -25},0, {0x27F, 0x483},{0x9E, 0xBF, 0x30, 0xFF}}},
	{{{34, -15, -25},0, {0xFFDC, 0x483},{0xA0, 0x49, 0x28, 0xFF}}},
	{{{46, -15, 26},0, {0xFFDC, 0xFF57},{0x95, 0x3F, 0xE5, 0xFF}}},
	{{{18, 17, 46},0, {0x31B, 0xFD4F},{0xD4, 0xBC, 0x9E, 0xFF}}},
	{{{23, -15, 52},0, {0xFFDC, 0xFCB3},{0xD2, 0x44, 0x9F, 0xFF}}},
	{{{-17, 35, 17},0, {0x4EE, 0x40},{0x2D, 0x8A, 0xF5, 0xFF}}},
	{{{-26, 11, -25},0, {0x27F, 0x483},{0x63, 0xC2, 0x31, 0xFF}}},
	{{{-35, 17, 21},0, {0x31B, 0xFFD8},{0x6C, 0xC0, 0xEC, 0xFF}}},
	{{{-33, -15, -25},0, {0xFFDC, 0x483},{0x60, 0x49, 0x28, 0xFF}}},
	{{{-13, 7, -46},0, {0x217, 0x6A4},{0x30, 0xBF, 0x62, 0xFF}}},
	{{{-16, -15, -51},0, {0xFFDC, 0x726},{0x34, 0x42, 0x60, 0xFF}}},
	{{{-33, -15, -25},0, {0xFFDC, 0x483},{0x60, 0x49, 0x28, 0xFF}}},
	{{{-45, -15, 26},0, {0xFFDC, 0xFF57},{0x6B, 0x3E, 0xE3, 0xFF}}},
	{{{-35, 17, 21},0, {0x31B, 0xFFD8},{0x6C, 0xC0, 0xEC, 0xFF}}},
	{{{-22, -15, 52},0, {0xFFDC, 0xFCB3},{0x30, 0x44, 0xA0, 0xFF}}},
	{{{-17, 17, 46},0, {0x31B, 0xFD4F},{0x2E, 0xBE, 0x9E, 0xFF}}},
	{{{-22, -15, 52},0, {0xFFAD, 0xFCB3},{0x30, 0x44, 0xA0, 0xFF}}},
	{{{-45, -15, 26},0, {0xFD58, 0xFF57},{0x6B, 0x3E, 0xE3, 0xFF}}},
	{{{-33, -15, -25},0, {0xFE8F, 0x483},{0x60, 0x49, 0x28, 0xFF}}},
	{{{-16, -15, -51},0, {0x49, 0x726},{0x34, 0x42, 0x60, 0xFF}}},
	{{{17, -15, -51},0, {0x3A2, 0x726},{0xCC, 0x42, 0x60, 0xFF}}},
	{{{34, -15, -25},0, {0x55B, 0x483},{0xA0, 0x49, 0x28, 0xFF}}},
	{{{46, -15, 26},0, {0x693, 0xFF57},{0x95, 0x3F, 0xE5, 0xFF}}},
	{{{23, -15, 52},0, {0x43D, 0xFCB3},{0xD2, 0x44, 0x9F, 0xFF}}},
	{{{-22, -15, 52},0, {0xFFAD, 0x401},{0x30, 0x44, 0xA0, 0xFF}}},
	{{{23, -15, 52},0, {0x43D, 0x401},{0xD2, 0x44, 0x9F, 0xFF}}},
	{{{18, 17, 46},0, {0x3BC, 0xC2},{0xD4, 0xBC, 0x9E, 0xFF}}},
	{{{-17, 17, 46},0, {0x2F, 0xC2},{0x2E, 0xBE, 0x9E, 0xFF}}},
};

const Gfx toadle_foot_r_mesh_tri_0[] = {
	gsSPVertex(toadle_foot_r_mesh_vtx + 0, 32, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
	gsSP2Triangles(5, 6, 3, 0, 7, 3, 6, 0),
	gsSP2Triangles(7, 6, 8, 0, 8, 9, 7, 0),
	gsSP2Triangles(10, 7, 9, 0, 7, 10, 11, 0),
	gsSP2Triangles(11, 10, 12, 0, 13, 12, 10, 0),
	gsSP2Triangles(11, 12, 14, 0, 14, 4, 11, 0),
	gsSP2Triangles(7, 11, 3, 0, 15, 16, 17, 0),
	gsSP2Triangles(15, 18, 16, 0, 19, 20, 21, 0),
	gsSP2Triangles(19, 21, 22, 0, 23, 22, 21, 0),
	gsSP2Triangles(23, 21, 2, 0, 23, 2, 24, 0),
	gsSP2Triangles(23, 24, 25, 0, 26, 27, 28, 0),
	gsSP2Triangles(29, 28, 27, 0, 30, 29, 27, 0),
	gsSP1Triangle(30, 31, 29, 0),
	gsSPVertex(toadle_foot_r_mesh_vtx + 32, 17, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 2, 1, 0),
	gsSP2Triangles(3, 4, 2, 0, 5, 6, 7, 0),
	gsSP2Triangles(5, 7, 8, 0, 5, 8, 9, 0),
	gsSP2Triangles(5, 9, 10, 0, 5, 10, 11, 0),
	gsSP2Triangles(5, 11, 12, 0, 13, 14, 15, 0),
	gsSP1Triangle(13, 15, 16, 0),
	gsSPEndDisplayList(),
};

// 0x06008BD8 - 0x06008C00
const Gfx toad_seg6_dl_06008BD8[] = {
	gsSPDisplayList(mat_limb_material),
	gsSPDisplayList(toadle_foot_r_mesh_tri_0),
	gsSPDisplayList(mat_revert_limb_material),
	gsSPEndDisplayList(),
    // gsDPPipeSync(),
    // gsDPSetCombineMode(G_CC_SHADEFADEA, G_CC_SHADEFADEA),
    // gsSPDisplayList(toad_seg6_dl_06008A90),
    // gsDPPipeSync(),
    // gsSPEndDisplayList(),
};
