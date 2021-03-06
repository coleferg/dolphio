#ifndef SURFACE_LOAD_H
#define SURFACE_LOAD_H

#include <PR/ultratypes.h>

#include "types.h"
#include "engine/extended_bounds.h"
#include "./surface_collision.h"

extern u8 gSurfacePoolError;

struct SurfaceNode
{
    struct SurfaceNode *next;
    struct Surface *surface;
};

enum
{
    SPATIAL_PARTITION_FLOORS,
    SPATIAL_PARTITION_CEILS,
    SPATIAL_PARTITION_WALLS,
    SPATIAL_PARTITION_WATER
};

typedef struct SurfaceNode SpatialPartitionCell[4];

// Needed for bs bss reordering memes.
extern s32 unused8038BE90;

extern SpatialPartitionCell gStaticSurfacePartition[CELL_AMOUNT][CELL_AMOUNT];
extern SpatialPartitionCell gDynamicSurfacePartition[CELL_AMOUNT][CELL_AMOUNT];
extern struct SurfaceNode *sSurfaceNodePool;
extern struct Surface *sSurfacePool;
extern s16 sSurfacePoolSize;

s32 isWaterType(s16 surfType);
s32 isWaterBottom(s16 surfType);
void alloc_surface_pools(void);
#ifdef NO_SEGMENTED_MEMORY
u32 get_area_terrain_size(s16 *data);
#endif
void load_area_terrain(s16 index, s16 *data, s8 *surfaceRooms, s16 *macroObjects);
void clear_dynamic_surfaces(void);
void load_object_collision_model(void);

#endif // SURFACE_LOAD_H
