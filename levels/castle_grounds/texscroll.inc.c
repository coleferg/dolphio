void scroll_castle_grounds_dl_headWater_mesh_vtx_0() {
	int i = 0;
	int count = 28;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(castle_grounds_dl_headWater_mesh_vtx_0);

	deltaX = (int)(0.3499999940395355 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;

}
void scroll_castle_grounds_dl_headWaterFall_mesh_vtx_0() {
	int i = 0;
	int count = 12;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(castle_grounds_dl_headWaterFall_mesh_vtx_0);

	deltaY = (int)(0.6000000238418579 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;

}
void scroll_castle_grounds_dl_lakeWater_mesh_vtx_0() {
	int i = 0;
	int count = 136;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(castle_grounds_dl_lakeWater_mesh_vtx_0);

	deltaX = (int)(-0.3499999940395355 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;

}
void scroll_castle_grounds() {
	scroll_castle_grounds_dl_headWater_mesh_vtx_0();
	scroll_castle_grounds_dl_headWaterFall_mesh_vtx_0();
	scroll_castle_grounds_dl_lakeWater_mesh_vtx_0();

}
