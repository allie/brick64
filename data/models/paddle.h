Lights1 paddle_Material_001_f3d_lights = gdSPDefLights1(
	0x0, 0x7F, 0x7F,
	0x0, 0xFE, 0xFE, 0x28, 0x28, 0x28);

Lights1 paddle_Material_002_f3d_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFE, 0xFE, 0xFE, 0x28, 0x28, 0x28);

Vtx paddle_Cube_mesh_vtx_cull[8] = {
	{{{-100, -100, 0},0, {-16, -16},{0x0, 0x0, 0x0, 0xFF}}},
	{{{-100, -100, 4},0, {-16, -16},{0x0, 0x0, 0x0, 0xFF}}},
	{{{-100, 100, 4},0, {-16, -16},{0x0, 0x0, 0x0, 0xFF}}},
	{{{-100, 100, 0},0, {-16, -16},{0x0, 0x0, 0x0, 0xFF}}},
	{{{100, -100, 0},0, {-16, -16},{0x0, 0x0, 0x0, 0xFF}}},
	{{{100, -100, 4},0, {-16, -16},{0x0, 0x0, 0x0, 0xFF}}},
	{{{100, 100, 4},0, {-16, -16},{0x0, 0x0, 0x0, 0xFF}}},
	{{{100, 100, 0},0, {-16, -16},{0x0, 0x0, 0x0, 0xFF}}},
};

Vtx paddle_Cube_mesh_vtx_0[63] = {
	{{{-100, -100, 0},0, {368, 752},{0x81, 0x0, 0x0, 0xFF}}},
	{{{-100, -100, 4},0, {368, 1008},{0x81, 0x0, 0x0, 0xFF}}},
	{{{-100, -33, 4},0, {453, 1008},{0x81, 0x0, 0x0, 0xFF}}},
	{{{-100, 33, 4},0, {539, 1008},{0x81, 0x0, 0x0, 0xFF}}},
	{{{-100, 100, 0},0, {624, 752},{0x81, 0x0, 0x0, 0xFF}}},
	{{{-100, 100, 4},0, {624, 1008},{0x81, 0x0, 0x0, 0xFF}}},
	{{{-100, -100, 0},0, {368, 752},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-100, 100, 0},0, {624, 752},{0x0, 0x0, 0x81, 0xFF}}},
	{{{100, 100, 0},0, {624, 496},{0x0, 0x0, 0x81, 0xFF}}},
	{{{100, -100, 0},0, {368, 496},{0x0, 0x0, 0x81, 0xFF}}},
	{{{100, -100, 4},0, {368, 240},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{100, -100, 0},0, {368, 496},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{100, 100, 0},0, {624, 496},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{100, 33, 4},0, {539, 240},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{100, 100, 4},0, {624, 240},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{100, -33, 4},0, {453, 240},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{-100, -100, 4},0, {112, 240},{0x0, 0x81, 0x0, 0xFF}}},
	{{{-100, -100, 0},0, {112, 496},{0x0, 0x81, 0x0, 0xFF}}},
	{{{100, -100, 0},0, {368, 496},{0x0, 0x81, 0x0, 0xFF}}},
	{{{-33, -100, 4},0, {197, 240},{0x0, 0x81, 0x0, 0xFF}}},
	{{{33, -100, 4},0, {283, 240},{0x0, 0x81, 0x0, 0xFF}}},
	{{{100, -100, 4},0, {368, 240},{0x0, 0x81, 0x0, 0xFF}}},
	{{{100, 100, 4},0, {624, 240},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{100, 100, 0},0, {624, 496},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-100, 100, 0},0, {880, 496},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{33, 100, 4},0, {709, 240},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-33, 100, 4},0, {795, 240},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-100, 100, 4},0, {880, 240},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{96, 48, 4},0, {581, 667},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{96, 96, 4},0, {667, 667},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{48, 96, 4},0, {667, 581},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{5, 5, 4},0, {581, 581},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{5, 5, 4},0, {581, 581},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{48, 96, 4},0, {667, 581},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{0, 96, 4},0, {667, 496},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-33, 100, 4},0, {1008, 325},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{33, 100, 4},0, {1008, 667},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-48, 96, 4},0, {667, 411},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{0, 26, 4},0, {581, 496},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-5, 5, 4},0, {581, 411},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-96, 96, 4},0, {667, 325},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-96, 48, 4},0, {581, 325},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-26, 0, 4},0, {496, 411},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-96, 0, 4},0, {496, 325},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-100, 33, 4},0, {667, -16},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-100, -33, 4},0, {325, -16},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-96, -48, 4},0, {411, 325},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-5, -5, 4},0, {411, 411},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-48, -96, 4},0, {325, 411},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-96, -96, 4},0, {325, 325},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{0, -96, 4},0, {325, 496},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{0, -26, 4},0, {411, 496},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{48, -96, 4},0, {325, 581},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{33, -100, 4},0, {-16, 667},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-33, -100, 4},0, {-16, 325},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{5, -5, 4},0, {411, 581},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{96, -96, 4},0, {325, 667},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{96, -48, 4},0, {411, 667},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{26, 0, 4},0, {496, 581},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{96, 0, 4},0, {496, 667},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{100, 33, 4},0, {667, 1008},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{100, -33, 4},0, {325, 1008},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{96, 48, 4},0, {581, 667},{0x0, 0x0, 0x7F, 0xFF}}},
};

Gfx paddle_Cube_mesh_tri_0[] = {
	gsSPVertex(paddle_Cube_mesh_vtx_0 + 0, 32, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSP2Triangles(3, 4, 0, 0, 3, 5, 4, 0),
	gsSP2Triangles(6, 7, 8, 0, 6, 8, 9, 0),
	gsSP2Triangles(10, 11, 12, 0, 12, 13, 10, 0),
	gsSP2Triangles(12, 14, 13, 0, 13, 15, 10, 0),
	gsSP2Triangles(16, 17, 18, 0, 19, 16, 18, 0),
	gsSP2Triangles(18, 20, 19, 0, 18, 21, 20, 0),
	gsSP2Triangles(22, 23, 24, 0, 25, 22, 24, 0),
	gsSP2Triangles(24, 26, 25, 0, 24, 27, 26, 0),
	gsSP2Triangles(28, 29, 30, 0, 28, 30, 31, 0),
	gsSPVertex(paddle_Cube_mesh_vtx_0 + 32, 31, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 2, 1, 0),
	gsSP2Triangles(1, 4, 3, 0, 3, 5, 2, 0),
	gsSP2Triangles(6, 2, 5, 0, 6, 5, 7, 0),
	gsSP2Triangles(7, 5, 8, 0, 7, 8, 9, 0),
	gsSP2Triangles(10, 7, 9, 0, 10, 9, 11, 0),
	gsSP2Triangles(11, 9, 12, 0, 11, 12, 13, 0),
	gsSP2Triangles(13, 14, 11, 0, 15, 11, 14, 0),
	gsSP2Triangles(16, 15, 14, 0, 16, 14, 17, 0),
	gsSP2Triangles(18, 15, 16, 0, 18, 19, 15, 0),
	gsSP2Triangles(20, 19, 18, 0, 21, 20, 18, 0),
	gsSP2Triangles(21, 18, 16, 0, 16, 22, 21, 0),
	gsSP2Triangles(20, 23, 19, 0, 24, 23, 20, 0),
	gsSP2Triangles(24, 25, 23, 0, 25, 26, 23, 0),
	gsSP2Triangles(25, 27, 26, 0, 28, 27, 25, 0),
	gsSP2Triangles(25, 29, 28, 0, 28, 30, 27, 0),
	gsSP2Triangles(27, 30, 0, 0, 27, 0, 26, 0),
	gsSP2Triangles(15, 10, 11, 0, 0, 2, 6, 0),
	gsSPEndDisplayList(),
};Vtx paddle_Cube_mesh_vtx_1[36] = {
	{{{-100, 33, 4},0, {667, -16},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{-96, 48, 4},0, {581, 325},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{-96, 96, 4},0, {667, 325},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{-100, 100, 4},0, {1008, -16},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{-33, 100, 4},0, {1008, 325},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{-48, 96, 4},0, {667, 411},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{-33, -100, 4},0, {-16, 325},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{-48, -96, 4},0, {325, 411},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{-96, -96, 4},0, {325, 325},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{-100, -100, 4},0, {-16, -16},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{-100, -33, 4},0, {325, -16},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{-96, -48, 4},0, {411, 325},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{100, 33, 4},0, {667, 1008},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{96, 96, 4},0, {667, 667},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{96, 48, 4},0, {581, 667},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{100, 100, 4},0, {1008, 1008},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{33, 100, 4},0, {1008, 667},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{48, 96, 4},0, {667, 581},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{33, -100, 4},0, {-16, 667},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{96, -96, 4},0, {325, 667},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{48, -96, 4},0, {325, 581},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{100, -100, 4},0, {-16, 1008},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{100, -33, 4},0, {325, 1008},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{96, -48, 4},0, {411, 667},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{5, -5, 4},0, {411, 581},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{26, 0, 4},0, {496, 581},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{0, 0, 4},0, {496, 496},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{5, 5, 4},0, {581, 581},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{0, 26, 4},0, {581, 496},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{-5, 5, 4},0, {581, 411},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{-26, 0, 4},0, {496, 411},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{-5, -5, 4},0, {411, 411},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{0, -26, 4},0, {411, 496},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{0, 0, 4},0, {496, 496},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{-5, -5, 4},0, {411, 411},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{5, -5, 4},0, {411, 581},{0xFF, 0xFF, 0xFF, 0xFF}}},
};

Gfx paddle_Cube_mesh_tri_1[] = {
	gsSPVertex(paddle_Cube_mesh_vtx_1 + 0, 32, 0),
	gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
	gsSP2Triangles(2, 4, 3, 0, 5, 4, 2, 0),
	gsSP2Triangles(6, 7, 8, 0, 6, 8, 9, 0),
	gsSP2Triangles(8, 10, 9, 0, 8, 11, 10, 0),
	gsSP2Triangles(12, 13, 14, 0, 12, 15, 13, 0),
	gsSP2Triangles(15, 16, 13, 0, 13, 16, 17, 0),
	gsSP2Triangles(18, 19, 20, 0, 21, 19, 18, 0),
	gsSP2Triangles(21, 22, 19, 0, 19, 22, 23, 0),
	gsSP2Triangles(24, 25, 26, 0, 25, 27, 26, 0),
	gsSP2Triangles(27, 28, 26, 0, 26, 28, 29, 0),
	gsSP2Triangles(26, 29, 30, 0, 26, 30, 31, 0),
	gsSPVertex(paddle_Cube_mesh_vtx_1 + 32, 4, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 1, 0, 0),
	gsSPEndDisplayList(),
};


Gfx mat_paddle_Material_001_f3d[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetEnvColor(254, 254, 254, 76),
	gsSPSetLights1(paddle_Material_001_f3d_lights),
	gsSPEndDisplayList(),
};


Gfx mat_paddle_Material_002_f3d[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPClearGeometryMode(G_LIGHTING | G_SHADING_SMOOTH),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetEnvColor(254, 254, 254, 255),
	gsSPSetLights1(paddle_Material_002_f3d_lights),
	gsSPEndDisplayList(),
};

Gfx mat_revert_paddle_Material_002_f3d[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING | G_SHADING_SMOOTH),
	gsSPEndDisplayList(),
};


Gfx paddle_Cube_mesh[] = {
	gsSPClearGeometryMode(G_LIGHTING),
	gsSPVertex(paddle_Cube_mesh_vtx_cull + 0, 8, 0),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPCullDisplayList(0, 7),
	gsSPDisplayList(mat_paddle_Material_001_f3d),
	gsSPDisplayList(paddle_Cube_mesh_tri_0),
	gsSPDisplayList(mat_paddle_Material_002_f3d),
	gsSPDisplayList(paddle_Cube_mesh_tri_1),
	gsSPDisplayList(mat_revert_paddle_Material_002_f3d),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsSPEndDisplayList(),
};



