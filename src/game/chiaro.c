#include <PR/ultratypes.h>
#include <PR/gbi.h>

#include "types.h"
#include "config.h"
#include "game_init.h"
#include "memory.h"
#include "ingame_menu.h"
#include "print.h"
#include "actors/common1.h"

Lights1 these_lights = gdSPDefLights1(
	0x9, 0x7F, 0x68,
	0x12, 0xFE, 0xD1, 0x28, 0x28, 0x28);

u32 chiaro_widths2[] = {
    0xb,
    0xb,
    0x11,
    0x11,
    0x1a,
    0x16,
    0x8,
    0xc,
    0xa,
    0xe,
    0x11,
    0x9,
    0xc,
    0x9,
    0xc,
    0x12,
    0xd,
    0x11,
    0x11,
    0x12,
    0x11,
    0x11,
    0x11,
    0x11,
    0x11,
    0x9,
    0x9,
    0xf,
    0x11,
    0xf,
    0x11,
    0x17,
    0x15,
    0x12,
    0x15,
    0x15,
    0x11,
    0x10,
    0x15,
    0x13,
    0x9,
    0xb,
    0x14,
    0x11,
    0x17,
    0x14,
    0x17,
    0x12,
    0x18,
    0x14,
    0x12,
    0x12,
    0x13,
    0x13,
    0x19,
    0x12,
    0x11,
    0x12,
    0xc,
    0xc,
    0x9,
    0x10,
    0xf,
    0xb,
    0x10,
    0x11,
    0x10,
    0x10,
    0x10,
    0xf,
    0x10,
    0x10,
    0x8,
    0x9,
    0x10,
    0x8,
    0x16,
    0x10,
    0x11,
    0x11,
    0x10,
    0xd,
    0xf,
    0xc,
    0x10,
    0xf,
    0x14,
    0xe,
    0xf,
    0xf,
    0xc,
    0x8,
    0xa,
    0xe
};

void mat_chiaro_display_sm64_material_layer1(char c) {
	// char *str = "What's up";
	
	// char c = str[4];
	int index = ((int) c) - 33;
	// int c = ((int) str[0]) - 33;
	u8 *(*fontLUT)[];

	fontLUT = segmented_to_virtual(&chiaro_lut);

	gDPPipeSync(gDisplayListHead++);
	gDPSetCombineLERP(gDisplayListHead++, TEXEL0, 0, SHADE, 0, 0, 0, 0, TEXEL0, TEXEL0, 0, SHADE, 0, 0, 0, 0, TEXEL0);
	gSPClearGeometryMode(gDisplayListHead++, G_LIGHTING);
	gDPSetRenderMode(gDisplayListHead++, G_RM_AA_ZB_XLU_SURF, G_RM_AA_ZB_XLU_SURF2);
	gSPTexture(gDisplayListHead++, 65535, 65535, 0, 0, 1);
	gDPTileSync(gDisplayListHead++);
	// gDPSetTextureImage(gDisplayListHead++, G_IM_FMT_IA, G_IM_SIZ_8b, 32, segmented_to_virtual(font_percent));
	gDPSetTextureImage(gDisplayListHead++, G_IM_FMT_IA, G_IM_SIZ_8b, 32,
		(*fontLUT)[index]);
	gDPSetTile(gDisplayListHead++, G_IM_FMT_IA, G_IM_SIZ_8b, 4, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0);
	gDPLoadSync(gDisplayListHead++);
	gDPLoadTile(gDisplayListHead++, 7, 0, 0, 124, 124);
	gDPPipeSync(gDisplayListHead++);
	gDPSetTile(gDisplayListHead++, G_IM_FMT_IA, G_IM_SIZ_8b, 4, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0);
	gDPSetTileSize(gDisplayListHead++, 0, 0, 0, 124, 124);
	gSPSetLights1(gDisplayListHead++, these_lights);
	gSPEndDisplayList(gDisplayListHead);
}

void mat_revert_chiaro_display_sm64_material_layer1(void) {
	gDPPipeSync(gDisplayListHead++);
	gSPSetGeometryMode(gDisplayListHead++, G_LIGHTING);
	gDPSetRenderMode(gDisplayListHead++, G_RM_AA_ZB_XLU_SURF, G_RM_NOOP2);
	// return glistp;
}

s32 get_str_len(char* str) {
    char c = 0;
    s32 length = 0;
    s32 srcIndex = 0;

	c = str[srcIndex];

	while (c != 0) {
        length++;
        srcIndex++;
        c = str[srcIndex];
    }

	return length;
}

void chiaro_display_char(char c, s32 strIndex, u32 width, s32 newLine, f32 lastLineLen) {
    Mtx *matrix = (Mtx *) alloc_display_list(sizeof(Mtx));

    if (matrix == NULL) {
        return;
    }

	// guScale(matrix, 16.0f, 16.0f, 1.0f);
	if (strIndex == 0) {
		guTranslate(
			matrix,
			((f32) SCREEN_WIDTH / 4.0f),
			((f32) SCREEN_HEIGHT - 20.0f),
			0.0f
		);
	} else if (newLine) {
		guTranslate(
			matrix,
			0.0f - lastLineLen,
			-25.0f,
			0.0f
		);
	} else {
		guTranslate(
			matrix,
			(f32) (width - 4),
			0.0f,
			0.0f
		);
	}

	gSPMatrix(gDisplayListHead++, VIRTUAL_TO_PHYSICAL(matrix++), G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_PUSH);
	gDPSetScissor(gDisplayListHead++, G_SC_NON_INTERLACE, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

	mat_chiaro_display_sm64_material_layer1(c);
	gSPDisplayList(gDisplayListHead++, segmented_to_virtual(chiaro_dl));
	mat_revert_chiaro_display_sm64_material_layer1();

	gDPPipeSync(gDisplayListHead++);
	gSPSetGeometryMode(gDisplayListHead++, G_LIGHTING);
	gSPClearGeometryMode(gDisplayListHead++, G_TEXTURE_GEN);
	gDPSetCombineLERP(gDisplayListHead++, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT);
	gSPTexture(gDisplayListHead++, 65535, 65535, 0, 0, 0);

	gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
	return;
}

void chiaro_display_chiaro_mesh(void) {
	char *str = "Created by;\n-The C o z i e s\n...You're welcome!\n1\n2\n3\n4\n5\n6\n7\n8\n9\n10";
	char c = 0;
	s32 strIndex = 0;
	u32 width = 0;
	s32 newLine = FALSE;
	f32 lastLineLen = 0.0f;
	// u32 *(*widths)[];
	// widths = segmented_to_virtual(chiaro_widths);

	c = str[strIndex];

	while (c != 0) {
		int index = ((int) c) - 33;
		switch (c)
		{
		case ' ':
			width += 0x9;
			// lastLineLen += (f32) 1.0f;
			newLine = FALSE;
			strIndex++;
			c = str[strIndex];
			break;
		
		case '\n':
			width = 0;
			newLine = TRUE;
			strIndex++;
			c = str[strIndex];
			break;
		
		default:
			chiaro_display_char(c, strIndex, width, newLine, lastLineLen);
			if (newLine) {
				newLine = FALSE;
				lastLineLen = 0.0f;
			}
			if (width) {
				lastLineLen += (f32) width - 4.0f;
			}
			width = chiaro_widths2[index];
			strIndex++;
			c = str[strIndex];
			break;
		}
	}

	// gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
	return;
}

// void chiaro_display_chiaro_mesh(void) {
//     Mtx *matrix = (Mtx *) alloc_display_list(sizeof(Mtx));
// 	// char *str = "Butt's up? Woah!";
// 	char *str = "Bam!IceCream?";
// 	char c = 0;
// 	s32 strIndex = 0;

// 	c = str[strIndex];

//     if (matrix == NULL) {
//         return;
//     }

//     // create_dl_identity_matrix();

//     // guOrtho(matrix, 0.0f, SCREEN_WIDTH, 0.0f, SCREEN_HEIGHT, -100.0f, 100.0f, 1.0f);

//     // Should produce G_RDPHALF_1 in Fast3D
//     // gSPPerspNormalize(gDisplayListHead++, 0xFFFF);

// 	// guScale(matrix, 16.0f, 16.0f, 1.0f);
// 	guTranslate(matrix,  ((f32) SCREEN_WIDTH / 2.0f), ((f32) SCREEN_HEIGHT / 2.0f), 0.0f);
//     // gSPMatrix(gDisplayListHead++, VIRTUAL_TO_PHYSICAL(matrix), G_MTX_PROJECTION | G_MTX_MUL | G_MTX_NOPUSH)

// 	gSPMatrix(gDisplayListHead++, VIRTUAL_TO_PHYSICAL(matrix++), G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_PUSH);
// 	gDPSetScissor(gDisplayListHead++, G_SC_NON_INTERLACE, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
// 	while (c != 0) {
// 		mat_chiaro_display_sm64_material_layer1(c);
// 		gSPDisplayList(gDisplayListHead++, segmented_to_virtual(chiaro_dl));
// 		mat_revert_chiaro_display_sm64_material_layer1();

// 		gDPPipeSync(gDisplayListHead++);
// 		gSPSetGeometryMode(gDisplayListHead++, G_LIGHTING);
// 		gSPClearGeometryMode(gDisplayListHead++, G_TEXTURE_GEN);
// 		gDPSetCombineLERP(gDisplayListHead++, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT);
// 		gSPTexture(gDisplayListHead++, 65535, 65535, 0, 0, 0);

// 		strIndex++;
// 		c = str[strIndex];
// 		guTranslate(
// 			matrix,
// 			((f32) SCREEN_WIDTH / 2.0f) + ((f32) strIndex) * 12.0f,
// 			((f32) SCREEN_HEIGHT / 2.0f),
// 			0.0f);
// 	}

// 	// gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
// 	return;
// }

