void scroll_bowser_1_dl_slideWater_mesh_vtx_0() {
	int i = 0;
	int count = 24;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(bowser_1_dl_slideWater_mesh_vtx_0);

	deltaY = (int)(-0.6000000238418579 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;

}
void scroll_bowser_1_dl_WaterCenter_mesh_vtx_0() {
	int i = 0;
	int count = 25;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	static int timeX;
	float amplitudeX = 0.08000000596046448;
	float frequencyX = 0.7;
	float offsetX = 0.0;
	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(bowser_1_dl_WaterCenter_mesh_vtx_0);

	deltaY = (int)(-0.20000000298023224 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		deltaX = (int)(amplitudeX * frequencyX * coss((frequencyX * (timeX + i) + offsetX) * (1024 * 16 - 1) / 6.28318530718) * 0x20);
		if (absi(currentX) > width) {
			deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
		}
#ifndef GBI_FLOATS
		vertices[i].n.ob[0] += (short) deltaX;
		vertices[i].n.ob[1] += (short) deltaX;
		vertices[i].n.ob[2] += (short) deltaX;
#else
		vertices[i].n.ob[0] += (float) deltaX;
		vertices[i].n.ob[1] += (float) deltaX;
		vertices[i].n.ob[2] += (float) deltaX;
#endif
		vertices[i].n.tc[1] += deltaY;
	}
	currentX += deltaX;
	timeX += 1;
	currentY += deltaY;

}
void scroll_bowser_1_dl_firstRoomWater_mesh_vtx_0() {
	int i = 0;
	int count = 6;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(bowser_1_dl_firstRoomWater_mesh_vtx_0);

	deltaX = (int)(-0.4000000059604645 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;

}
void scroll_bowser_1_dl_waterFallRoomWaterfalls_mesh_vtx_0() {
	int i = 0;
	int count = 42;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(bowser_1_dl_waterFallRoomWaterfalls_mesh_vtx_0);

	deltaY = (int)(-0.8500000238418579 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;

}
void scroll_bowser_1_dl_Water_mesh_vtx_0() {
	int i = 0;
	int count = 14;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(bowser_1_dl_Water_mesh_vtx_0);

	deltaX = (int)(-0.4000000059604645 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;

}
void scroll_bowser_1_dl_deathPlane_mesh_vtx_0() {
	int i = 0;
	int count = 9;
	int width = 64 * 0x20;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(bowser_1_dl_deathPlane_mesh_vtx_0);

	deltaY = (int)(-0.20000000298023224 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;

}
void scroll_bowser_1_dl_deathPlane_001_mesh_vtx_0() {
	int i = 0;
	int count = 9;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	static int currentY = 0;
	int deltaY;
	static int timeY;
	float amplitudeY = 0.10000000149011612;
	float frequencyY = 0.15000000596046448;
	float offsetY = 0.0;
	Vtx *vertices = segmented_to_virtual(bowser_1_dl_deathPlane_001_mesh_vtx_0);

	deltaX = (int)(0.23000000417232513 * 0x20) % width;
	deltaY = (int)(amplitudeY * frequencyY * coss((frequencyY * timeY + offsetY) * (1024 * 16 - 1) / 6.28318530718) * 0x20);

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}
	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
		vertices[i].n.tc[1] += deltaY;
	}
	currentX += deltaX;
	currentY += deltaY;
	timeY += 1;

}
void scroll_bowser_1_dl_instawarp_mesh_vtx_0() {
	int i = 0;
	int count = 7;
	int width = 64 * 0x20;
	int height = 64 * 0x20;

	static int currentX = 0;
	int deltaX;
	static int currentY = 0;
	int deltaY;
	static int timeY;
	float amplitudeY = 0.10000000149011612;
	float frequencyY = 0.05000000074505806;
	float offsetY = 0.0;
	Vtx *vertices = segmented_to_virtual(bowser_1_dl_instawarp_mesh_vtx_0);

	deltaX = (int)(-0.10000000149011612 * 0x20) % width;
	deltaY = (int)(amplitudeY * frequencyY * coss((frequencyY * timeY + offsetY) * (1024 * 16 - 1) / 6.28318530718) * 0x20);

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}
	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
		vertices[i].n.tc[1] += deltaY;
	}
	currentX += deltaX;
	currentY += deltaY;
	timeY += 1;

}
void scroll_bowser_1() {
	scroll_bowser_1_dl_slideWater_mesh_vtx_0();
	scroll_bowser_1_dl_WaterCenter_mesh_vtx_0();
	scroll_bowser_1_dl_firstRoomWater_mesh_vtx_0();
	scroll_bowser_1_dl_waterFallRoomWaterfalls_mesh_vtx_0();
	scroll_bowser_1_dl_Water_mesh_vtx_0();
	scroll_bowser_1_dl_deathPlane_mesh_vtx_0();
	scroll_bowser_1_dl_deathPlane_001_mesh_vtx_0();
	scroll_bowser_1_dl_instawarp_mesh_vtx_0();

}
