#ifndef GROUP15_H
#define GROUP15_H

#include "types.h"

// boo_castle
extern const GeoLayout boo_castle_geo[];
extern const Gfx boo_castle_seg6_dl_06017A10[];
extern const Gfx boo_castle_seg6_dl_06017A78[];
extern const Gfx boo_castle_seg6_dl_06017AD0[];
extern const Gfx boo_castle_seg6_dl_06017CE0[];

// lakitu_cameraman
extern const GeoLayout lakitu_geo[];
extern const Gfx lakitu_seg6_dl_06003C80[];
extern const Gfx lakitu_seg6_dl_06003DB0[];
extern const Gfx lakitu_seg6_dl_06003E30[];
extern const Gfx lakitu_seg6_dl_06004410[];
extern const Gfx lakitu_seg6_dl_06004680[];
extern const Gfx lakitu_seg6_dl_060047E8[];
extern const Gfx lakitu_seg6_dl_060049E0[];
extern const Gfx lakitu_seg6_dl_06004BA8[];
extern const Gfx lakitu_seg6_dl_06004BE8[];
extern const Gfx lakitu_seg6_dl_06004C30[];
extern const Gfx lakitu_seg6_dl_06004C60[];
extern const Gfx lakitu_seg6_dl_06004C88[];
extern const Gfx lakitu_seg6_dl_060051D0[];
extern const Gfx lakitu_seg6_dl_06005218[];
extern const Gfx lakitu_seg6_dl_06005360[];
extern const Gfx lakitu_seg6_dl_06005598[];
extern const Gfx lakitu_seg6_dl_060055E8[];
extern const Gfx lakitu_seg6_dl_06005610[];
extern const struct Animation *const lakitu_seg6_anims_060058F8[];

// mips
extern const GeoLayout mips_geo[];
extern const Gfx mips_seg6_dl_06010600[];
extern const Gfx mips_seg6_dl_06010748[];
extern const Gfx mips_seg6_dl_060107B8[];
extern const Gfx mips_seg6_dl_06010A98[];
extern const Gfx mips_seg6_dl_06010C40[];
extern const Gfx mips_seg6_dl_06010DB0[];
extern const Gfx mips_seg6_dl_06010E60[];
extern const Gfx mips_seg6_dl_06010FF8[];
extern const Gfx mips_seg6_dl_060110B0[];
extern const Gfx mips_seg6_dl_06011240[];
extern const Gfx mips_seg6_dl_06011310[];
extern const Gfx mips_seg6_dl_06011470[];
extern const Gfx mips_seg6_dl_06011520[];
extern const Gfx mips_seg6_dl_060116B0[];
extern const Gfx mips_seg6_dl_06011780[];
extern const Gfx mips_seg6_dl_060118E0[];
extern const Gfx mips_seg6_dl_06011990[];
extern const Gfx mips_seg6_dl_06011B00[];
extern const Gfx mips_seg6_dl_06011BB0[];
extern const Gfx mips_seg6_dl_06011D10[];
extern const Gfx mips_seg6_dl_06011DB0[];
extern const Gfx mips_seg6_dl_06011E88[];
extern const Gfx mips_seg6_dl_06011ED8[];
extern const Gfx mips_seg6_dl_06011F70[];
extern const Gfx mips_seg6_dl_06011FC0[];
extern const struct Animation *const mips_seg6_anims_06015634[];

// toad
// extern const GeoLayout toad_geo_000114[];
// extern const GeoLayout toad_geo_00027C[];
// extern const GeoLayout toad_geo[];
// extern const Gfx toad_seg6_dl_06007300[];
// extern const Gfx toad_seg6_dl_06007498[];
// extern const Gfx toad_seg6_dl_060076C0[];
// extern const Gfx toad_seg6_dl_06007710[];
// extern const Gfx toad_seg6_us_dl_06007788[];
// extern const Gfx toad_seg6_dl_06007960[];
// extern const Gfx toad_seg6_dl_06007A48[];
// extern const Gfx toad_seg6_us_dl_06007B00[];
// extern const Gfx toad_seg6_dl_06007D10[];
// extern const Gfx toad_seg6_dl_06007EB0[];
// extern const Gfx toad_seg6_dl_060080C0[];
// extern const Gfx toad_seg6_dl_060081F8[];
// extern const Gfx toad_seg6_dl_060083E8[];
// extern const Gfx toad_seg6_dl_06008520[];
// extern const Gfx toad_seg6_us_dl_06008608[];
// extern const Gfx toad_seg6_dl_06008748[];
// extern const Gfx toad_seg6_dl_06008890[];
// extern const Gfx toad_seg6_dl_06008A90[];
// extern const Gfx toad_seg6_dl_06008BD8[];
extern const GeoLayout toad_geo[];
Gfx* toad_toadle_head_mesh(Gfx* glistp);
Gfx* toad_toadle_foot_l_mesh(Gfx* glistp);
Gfx* toad_toadle_foot_r_mesh(Gfx* glistp);
Gfx* toad_toadle_arm_l_mesh(Gfx* glistp);
Gfx* toad_toadle_arm_r_mesh(Gfx* glistp);
Gfx* toad_toadle_body_mesh(Gfx* glistp);
Gfx* toad_toadle_vest_mesh(Gfx* glistp);
Gfx* toad_material_revert_render_settings(Gfx* glistp);
extern const struct Animation *const toad_seg6_anims_0600FB58[];

// water_ring
extern const GeoLayout water_ring_geo[];
extern const Gfx water_ring_seg6_dl_06013AC0[];
extern const Gfx water_ring_seg6_dl_gold[];
extern const struct Animation *const water_ring_seg6_anims_06013F7C[];
#include "toadle/geo_header.h"

#include "sloth/geo_header.h"

#include "monkat/geo_header.h"


#include "monkat/anim_header.h"

#include "sloth/anim_header.h"
#include "lizard/geo_header.h"


#include "lizard/anim_header.h"
#endif
