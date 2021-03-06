Lights1 ball_Material_001_f3d_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFE, 0xFE, 0xFE, 0x28, 0x28, 0x28);

Vtx ball_Icosphere_mesh_vtx_cull[8] = {
	{{{-48, -50, -50},0, {-16, -16},{0x0, 0x0, 0x0, 0xFF}}},
	{{{-48, -50, 50},0, {-16, -16},{0x0, 0x0, 0x0, 0xFF}}},
	{{{-48, 50, 50},0, {-16, -16},{0x0, 0x0, 0x0, 0xFF}}},
	{{{-48, 50, -50},0, {-16, -16},{0x0, 0x0, 0x0, 0xFF}}},
	{{{48, -50, -50},0, {-16, -16},{0x0, 0x0, 0x0, 0xFF}}},
	{{{48, -50, 50},0, {-16, -16},{0x0, 0x0, 0x0, 0xFF}}},
	{{{48, 50, 50},0, {-16, -16},{0x0, 0x0, 0x0, 0xFF}}},
	{{{48, 50, -50},0, {-16, -16},{0x0, 0x0, 0x0, 0xFF}}},
};

Vtx ball_Icosphere_mesh_vtx_0[240] = {
	{{{0, -50, 0},0, {822, 1008},{0xD, 0x88, 0x28, 0xFF}}},
	{{{21, -43, 15},0, {775, 927},{0xD, 0x88, 0x28, 0xFF}}},
	{{{-8, -43, 25},0, {868, 927},{0xD, 0x88, 0x28, 0xFF}}},
	{{{36, -22, 26},0, {729, 847},{0x59, 0xAC, 0x22, 0xFF}}},
	{{{21, -43, 15},0, {682, 927},{0x59, 0xAC, 0x22, 0xFF}}},
	{{{43, -26, 0},0, {636, 847},{0x59, 0xAC, 0x22, 0xFF}}},
	{{{0, -50, 0},0, {77, 1008},{0xDE, 0x88, 0x19, 0xFF}}},
	{{{-8, -43, 25},0, {31, 927},{0xDE, 0x88, 0x19, 0xFF}}},
	{{{-26, -43, 0},0, {124, 927},{0xDE, 0x88, 0x19, 0xFF}}},
	{{{0, -50, 0},0, {263, 1008},{0xDE, 0x88, 0xE7, 0xFF}}},
	{{{-26, -43, 0},0, {217, 927},{0xDE, 0x88, 0xE7, 0xFF}}},
	{{{-8, -43, -25},0, {310, 927},{0xDE, 0x88, 0xE7, 0xFF}}},
	{{{0, -50, 0},0, {449, 1008},{0xD, 0x88, 0xD8, 0xFF}}},
	{{{-8, -43, -25},0, {403, 927},{0xD, 0x88, 0xD8, 0xFF}}},
	{{{21, -43, -15},0, {496, 927},{0xD, 0x88, 0xD8, 0xFF}}},
	{{{36, -22, 26},0, {729, 847},{0x73, 0xD6, 0x22, 0xFF}}},
	{{{43, -26, 0},0, {636, 847},{0x73, 0xD6, 0x22, 0xFF}}},
	{{{48, 0, 15},0, {682, 766},{0x73, 0xD6, 0x22, 0xFF}}},
	{{{-14, -22, 43},0, {915, 847},{0x3, 0xD6, 0x78, 0xFF}}},
	{{{13, -26, 40},0, {822, 847},{0x3, 0xD6, 0x78, 0xFF}}},
	{{{0, 0, 50},0, {868, 766},{0x3, 0xD6, 0x78, 0xFF}}},
	{{{-45, -22, 0},0, {170, 847},{0x8F, 0xD6, 0x28, 0xFF}}},
	{{{-34, -26, 25},0, {77, 847},{0x8F, 0xD6, 0x28, 0xFF}}},
	{{{-48, 0, 15},0, {124, 766},{0x8F, 0xD6, 0x28, 0xFF}}},
	{{{-14, -22, -43},0, {356, 847},{0xB7, 0xD6, 0xA1, 0xFF}}},
	{{{-34, -26, -25},0, {263, 847},{0xB7, 0xD6, 0xA1, 0xFF}}},
	{{{-29, 0, -40},0, {310, 766},{0xB7, 0xD6, 0xA1, 0xFF}}},
	{{{36, -22, -26},0, {543, 847},{0x43, 0xD6, 0x9D, 0xFF}}},
	{{{13, -26, -40},0, {449, 847},{0x43, 0xD6, 0x9D, 0xFF}}},
	{{{29, 0, -40},0, {496, 766},{0x43, 0xD6, 0x9D, 0xFF}}},
	{{{36, -22, 26},0, {729, 847},{0x66, 0xF0, 0x4A, 0xFF}}},
	{{{48, 0, 15},0, {682, 766},{0x66, 0xF0, 0x4A, 0xFF}}},
	{{{29, 0, 40},0, {775, 766},{0x66, 0xF0, 0x4A, 0xFF}}},
	{{{-14, -22, 43},0, {915, 847},{0xD9, 0xF0, 0x78, 0xFF}}},
	{{{0, 0, 50},0, {868, 766},{0xD9, 0xF0, 0x78, 0xFF}}},
	{{{-29, 0, 40},0, {961, 766},{0xD9, 0xF0, 0x78, 0xFF}}},
	{{{-45, -22, 0},0, {170, 847},{0x82, 0xF0, 0x0, 0xFF}}},
	{{{-48, 0, 15},0, {124, 766},{0x82, 0xF0, 0x0, 0xFF}}},
	{{{-48, 0, -15},0, {217, 766},{0x82, 0xF0, 0x0, 0xFF}}},
	{{{-14, -22, -43},0, {356, 847},{0xD9, 0xF0, 0x88, 0xFF}}},
	{{{-29, 0, -40},0, {310, 766},{0xD9, 0xF0, 0x88, 0xFF}}},
	{{{0, 0, -50},0, {403, 766},{0xD9, 0xF0, 0x88, 0xFF}}},
	{{{36, -22, -26},0, {543, 847},{0x66, 0xF0, 0xB6, 0xFF}}},
	{{{29, 0, -40},0, {496, 766},{0x66, 0xF0, 0xB6, 0xFF}}},
	{{{48, 0, -15},0, {589, 766},{0x66, 0xF0, 0xB6, 0xFF}}},
	{{{14, 22, 43},0, {822, 686},{0x34, 0x54, 0x50, 0xFF}}},
	{{{34, 26, 25},0, {729, 686},{0x34, 0x54, 0x50, 0xFF}}},
	{{{8, 43, 25},0, {775, 605},{0x34, 0x54, 0x50, 0xFF}}},
	{{{-36, 22, 26},0, {1008, 686},{0xC5, 0x54, 0x4A, 0xFF}}},
	{{{-13, 26, 40},0, {915, 686},{0xC5, 0x54, 0x4A, 0xFF}}},
	{{{-21, 43, 15},0, {961, 605},{0xC5, 0x54, 0x4A, 0xFF}}},
	{{{-36, 22, -26},0, {263, 686},{0xA7, 0x54, 0xDE, 0xFF}}},
	{{{-43, 26, 0},0, {170, 686},{0xA7, 0x54, 0xDE, 0xFF}}},
	{{{-21, 43, -15},0, {217, 605},{0xA7, 0x54, 0xDE, 0xFF}}},
	{{{14, 22, -43},0, {449, 686},{0x5, 0x54, 0xA1, 0xFF}}},
	{{{-13, 26, -40},0, {356, 686},{0x5, 0x54, 0xA1, 0xFF}}},
	{{{8, 43, -25},0, {403, 605},{0x5, 0x54, 0xA1, 0xFF}}},
	{{{45, 22, 0},0, {636, 686},{0x5C, 0x54, 0xE7, 0xFF}}},
	{{{34, 26, -25},0, {543, 686},{0x5C, 0x54, 0xE7, 0xFF}}},
	{{{26, 43, 0},0, {589, 605},{0x5C, 0x54, 0xE7, 0xFF}}},
	{{{26, 43, 0},0, {589, 605},{0x22, 0x78, 0xE7, 0xFF}}},
	{{{8, 43, -25},0, {496, 605},{0x22, 0x78, 0xE7, 0xFF}}},
	{{{0, 50, 0},0, {543, 524},{0x22, 0x78, 0xE7, 0xFF}}},
	{{{26, 43, 0},0, {589, 605},{0x3E, 0x65, 0xD3, 0xFF}}},
	{{{34, 26, -25},0, {543, 686},{0x3E, 0x65, 0xD3, 0xFF}}},
	{{{8, 43, -25},0, {496, 605},{0x3E, 0x65, 0xD3, 0xFF}}},
	{{{34, 26, -25},0, {543, 686},{0x34, 0x54, 0xB0, 0xFF}}},
	{{{14, 22, -43},0, {449, 686},{0x34, 0x54, 0xB0, 0xFF}}},
	{{{8, 43, -25},0, {496, 605},{0x34, 0x54, 0xB0, 0xFF}}},
	{{{8, 43, -25},0, {403, 605},{0xF3, 0x78, 0xD8, 0xFF}}},
	{{{-21, 43, -15},0, {310, 605},{0xF3, 0x78, 0xD8, 0xFF}}},
	{{{0, 50, 0},0, {356, 524},{0xF3, 0x78, 0xD8, 0xFF}}},
	{{{8, 43, -25},0, {403, 605},{0xE8, 0x65, 0xB7, 0xFF}}},
	{{{-13, 26, -40},0, {356, 686},{0xE8, 0x65, 0xB7, 0xFF}}},
	{{{-21, 43, -15},0, {310, 605},{0xE8, 0x65, 0xB7, 0xFF}}},
	{{{-13, 26, -40},0, {356, 686},{0xC5, 0x54, 0xB6, 0xFF}}},
	{{{-36, 22, -26},0, {263, 686},{0xC5, 0x54, 0xB6, 0xFF}}},
	{{{-21, 43, -15},0, {310, 605},{0xC5, 0x54, 0xB6, 0xFF}}},
	{{{-21, 43, -15},0, {217, 605},{0xD6, 0x78, 0x0, 0xFF}}},
	{{{-21, 43, 15},0, {124, 605},{0xD6, 0x78, 0x0, 0xFF}}},
	{{{0, 50, 0},0, {170, 524},{0xD6, 0x78, 0x0, 0xFF}}},
	{{{-21, 43, -15},0, {217, 605},{0xB3, 0x65, 0x0, 0xFF}}},
	{{{-43, 26, 0},0, {170, 686},{0xB3, 0x65, 0x0, 0xFF}}},
	{{{-21, 43, 15},0, {124, 605},{0xB3, 0x65, 0x0, 0xFF}}},
	{{{-43, 26, 0},0, {170, 686},{0xA7, 0x54, 0x22, 0xFF}}},
	{{{-36, 22, 26},0, {77, 686},{0xA7, 0x54, 0x22, 0xFF}}},
	{{{-21, 43, 15},0, {124, 605},{0xA7, 0x54, 0x22, 0xFF}}},
	{{{-21, 43, 15},0, {961, 605},{0xF3, 0x78, 0x28, 0xFF}}},
	{{{8, 43, 25},0, {868, 605},{0xF3, 0x78, 0x28, 0xFF}}},
	{{{0, 50, 0},0, {915, 524},{0xF3, 0x78, 0x28, 0xFF}}},
	{{{-21, 43, 15},0, {961, 605},{0xE8, 0x65, 0x49, 0xFF}}},
	{{{-13, 26, 40},0, {915, 686},{0xE8, 0x65, 0x49, 0xFF}}},
	{{{8, 43, 25},0, {868, 605},{0xE8, 0x65, 0x49, 0xFF}}},
	{{{-13, 26, 40},0, {915, 686},{0x5, 0x54, 0x5F, 0xFF}}},
	{{{14, 22, 43},0, {822, 686},{0x5, 0x54, 0x5F, 0xFF}}},
	{{{8, 43, 25},0, {868, 605},{0x5, 0x54, 0x5F, 0xFF}}},
	{{{8, 43, 25},0, {775, 605},{0x22, 0x78, 0x19, 0xFF}}},
	{{{26, 43, 0},0, {682, 605},{0x22, 0x78, 0x19, 0xFF}}},
	{{{0, 50, 0},0, {729, 524},{0x22, 0x78, 0x19, 0xFF}}},
	{{{8, 43, 25},0, {775, 605},{0x3E, 0x65, 0x2D, 0xFF}}},
	{{{34, 26, 25},0, {729, 686},{0x3E, 0x65, 0x2D, 0xFF}}},
	{{{26, 43, 0},0, {682, 605},{0x3E, 0x65, 0x2D, 0xFF}}},
	{{{34, 26, 25},0, {729, 686},{0x5C, 0x54, 0x19, 0xFF}}},
	{{{45, 22, 0},0, {636, 686},{0x5C, 0x54, 0x19, 0xFF}}},
	{{{26, 43, 0},0, {682, 605},{0x5C, 0x54, 0x19, 0xFF}}},
	{{{48, 0, -15},0, {589, 766},{0x71, 0x2A, 0xD8, 0xFF}}},
	{{{34, 26, -25},0, {543, 686},{0x71, 0x2A, 0xD8, 0xFF}}},
	{{{45, 22, 0},0, {636, 686},{0x71, 0x2A, 0xD8, 0xFF}}},
	{{{48, 0, -15},0, {589, 766},{0x65, 0x18, 0xB7, 0xFF}}},
	{{{29, 0, -40},0, {496, 766},{0x65, 0x18, 0xB7, 0xFF}}},
	{{{34, 26, -25},0, {543, 686},{0x65, 0x18, 0xB7, 0xFF}}},
	{{{29, 0, -40},0, {496, 766},{0x49, 0x2A, 0xA1, 0xFF}}},
	{{{14, 22, -43},0, {449, 686},{0x49, 0x2A, 0xA1, 0xFF}}},
	{{{34, 26, -25},0, {543, 686},{0x49, 0x2A, 0xA1, 0xFF}}},
	{{{0, 0, -50},0, {403, 766},{0xFD, 0x2A, 0x88, 0xFF}}},
	{{{-13, 26, -40},0, {356, 686},{0xFD, 0x2A, 0x88, 0xFF}}},
	{{{14, 22, -43},0, {449, 686},{0xFD, 0x2A, 0x88, 0xFF}}},
	{{{0, 0, -50},0, {403, 766},{0xD9, 0x18, 0x89, 0xFF}}},
	{{{-29, 0, -40},0, {310, 766},{0xD9, 0x18, 0x89, 0xFF}}},
	{{{-13, 26, -40},0, {356, 686},{0xD9, 0x18, 0x89, 0xFF}}},
	{{{-29, 0, -40},0, {310, 766},{0xBD, 0x2A, 0x9D, 0xFF}}},
	{{{-36, 22, -26},0, {263, 686},{0xBD, 0x2A, 0x9D, 0xFF}}},
	{{{-13, 26, -40},0, {356, 686},{0xBD, 0x2A, 0x9D, 0xFF}}},
	{{{-48, 0, -15},0, {217, 766},{0x8D, 0x2A, 0xDE, 0xFF}}},
	{{{-43, 26, 0},0, {170, 686},{0x8D, 0x2A, 0xDE, 0xFF}}},
	{{{-36, 22, -26},0, {263, 686},{0x8D, 0x2A, 0xDE, 0xFF}}},
	{{{-48, 0, -15},0, {217, 766},{0x83, 0x18, 0x0, 0xFF}}},
	{{{-48, 0, 15},0, {124, 766},{0x83, 0x18, 0x0, 0xFF}}},
	{{{-43, 26, 0},0, {170, 686},{0x83, 0x18, 0x0, 0xFF}}},
	{{{-48, 0, 15},0, {124, 766},{0x8D, 0x2A, 0x22, 0xFF}}},
	{{{-36, 22, 26},0, {77, 686},{0x8D, 0x2A, 0x22, 0xFF}}},
	{{{-43, 26, 0},0, {170, 686},{0x8D, 0x2A, 0x22, 0xFF}}},
	{{{-29, 0, 40},0, {961, 766},{0xBD, 0x2A, 0x63, 0xFF}}},
	{{{-13, 26, 40},0, {915, 686},{0xBD, 0x2A, 0x63, 0xFF}}},
	{{{-36, 22, 26},0, {1008, 686},{0xBD, 0x2A, 0x63, 0xFF}}},
	{{{-29, 0, 40},0, {961, 766},{0xD9, 0x18, 0x77, 0xFF}}},
	{{{0, 0, 50},0, {868, 766},{0xD9, 0x18, 0x77, 0xFF}}},
	{{{-13, 26, 40},0, {915, 686},{0xD9, 0x18, 0x77, 0xFF}}},
	{{{0, 0, 50},0, {868, 766},{0xFD, 0x2A, 0x78, 0xFF}}},
	{{{14, 22, 43},0, {822, 686},{0xFD, 0x2A, 0x78, 0xFF}}},
	{{{-13, 26, 40},0, {915, 686},{0xFD, 0x2A, 0x78, 0xFF}}},
	{{{29, 0, 40},0, {775, 766},{0x49, 0x2A, 0x5F, 0xFF}}},
	{{{34, 26, 25},0, {729, 686},{0x49, 0x2A, 0x5F, 0xFF}}},
	{{{14, 22, 43},0, {822, 686},{0x49, 0x2A, 0x5F, 0xFF}}},
	{{{29, 0, 40},0, {775, 766},{0x65, 0x18, 0x49, 0xFF}}},
	{{{48, 0, 15},0, {682, 766},{0x65, 0x18, 0x49, 0xFF}}},
	{{{34, 26, 25},0, {729, 686},{0x65, 0x18, 0x49, 0xFF}}},
	{{{48, 0, 15},0, {682, 766},{0x71, 0x2A, 0x28, 0xFF}}},
	{{{45, 22, 0},0, {636, 686},{0x71, 0x2A, 0x28, 0xFF}}},
	{{{34, 26, 25},0, {729, 686},{0x71, 0x2A, 0x28, 0xFF}}},
	{{{29, 0, -40},0, {496, 766},{0x27, 0x10, 0x88, 0xFF}}},
	{{{0, 0, -50},0, {403, 766},{0x27, 0x10, 0x88, 0xFF}}},
	{{{14, 22, -43},0, {449, 686},{0x27, 0x10, 0x88, 0xFF}}},
	{{{29, 0, -40},0, {496, 766},{0x27, 0xE8, 0x89, 0xFF}}},
	{{{13, -26, -40},0, {449, 847},{0x27, 0xE8, 0x89, 0xFF}}},
	{{{0, 0, -50},0, {403, 766},{0x27, 0xE8, 0x89, 0xFF}}},
	{{{13, -26, -40},0, {449, 847},{0x3, 0xD6, 0x88, 0xFF}}},
	{{{-14, -22, -43},0, {356, 847},{0x3, 0xD6, 0x88, 0xFF}}},
	{{{0, 0, -50},0, {403, 766},{0x3, 0xD6, 0x88, 0xFF}}},
	{{{-29, 0, -40},0, {310, 766},{0x9A, 0x10, 0xB6, 0xFF}}},
	{{{-48, 0, -15},0, {217, 766},{0x9A, 0x10, 0xB6, 0xFF}}},
	{{{-36, 22, -26},0, {263, 686},{0x9A, 0x10, 0xB6, 0xFF}}},
	{{{-29, 0, -40},0, {310, 766},{0x9B, 0xE8, 0xB7, 0xFF}}},
	{{{-34, -26, -25},0, {263, 847},{0x9B, 0xE8, 0xB7, 0xFF}}},
	{{{-48, 0, -15},0, {217, 766},{0x9B, 0xE8, 0xB7, 0xFF}}},
	{{{-34, -26, -25},0, {263, 847},{0x8F, 0xD6, 0xD8, 0xFF}}},
	{{{-45, -22, 0},0, {170, 847},{0x8F, 0xD6, 0xD8, 0xFF}}},
	{{{-48, 0, -15},0, {217, 766},{0x8F, 0xD6, 0xD8, 0xFF}}},
	{{{-48, 0, 15},0, {124, 766},{0x9A, 0x10, 0x4A, 0xFF}}},
	{{{-29, 0, 40},0, {31, 766},{0x9A, 0x10, 0x4A, 0xFF}}},
	{{{-36, 22, 26},0, {77, 686},{0x9A, 0x10, 0x4A, 0xFF}}},
	{{{-48, 0, 15},0, {124, 766},{0x9B, 0xE8, 0x49, 0xFF}}},
	{{{-34, -26, 25},0, {77, 847},{0x9B, 0xE8, 0x49, 0xFF}}},
	{{{-29, 0, 40},0, {31, 766},{0x9B, 0xE8, 0x49, 0xFF}}},
	{{{-34, -26, 25},0, {77, 847},{0xB7, 0xD6, 0x5F, 0xFF}}},
	{{{-14, -22, 43},0, {-16, 847},{0xB7, 0xD6, 0x5F, 0xFF}}},
	{{{-29, 0, 40},0, {31, 766},{0xB7, 0xD6, 0x5F, 0xFF}}},
	{{{0, 0, 50},0, {868, 766},{0x27, 0x10, 0x78, 0xFF}}},
	{{{29, 0, 40},0, {775, 766},{0x27, 0x10, 0x78, 0xFF}}},
	{{{14, 22, 43},0, {822, 686},{0x27, 0x10, 0x78, 0xFF}}},
	{{{0, 0, 50},0, {868, 766},{0x27, 0xE8, 0x77, 0xFF}}},
	{{{13, -26, 40},0, {822, 847},{0x27, 0xE8, 0x77, 0xFF}}},
	{{{29, 0, 40},0, {775, 766},{0x27, 0xE8, 0x77, 0xFF}}},
	{{{13, -26, 40},0, {822, 847},{0x43, 0xD6, 0x63, 0xFF}}},
	{{{36, -22, 26},0, {729, 847},{0x43, 0xD6, 0x63, 0xFF}}},
	{{{29, 0, 40},0, {775, 766},{0x43, 0xD6, 0x63, 0xFF}}},
	{{{48, 0, 15},0, {682, 766},{0x7E, 0x10, 0x0, 0xFF}}},
	{{{48, 0, -15},0, {589, 766},{0x7E, 0x10, 0x0, 0xFF}}},
	{{{45, 22, 0},0, {636, 686},{0x7E, 0x10, 0x0, 0xFF}}},
	{{{48, 0, 15},0, {682, 766},{0x7D, 0xE8, 0x0, 0xFF}}},
	{{{43, -26, 0},0, {636, 847},{0x7D, 0xE8, 0x0, 0xFF}}},
	{{{48, 0, -15},0, {589, 766},{0x7D, 0xE8, 0x0, 0xFF}}},
	{{{43, -26, 0},0, {636, 847},{0x73, 0xD6, 0xDE, 0xFF}}},
	{{{36, -22, -26},0, {543, 847},{0x73, 0xD6, 0xDE, 0xFF}}},
	{{{48, 0, -15},0, {589, 766},{0x73, 0xD6, 0xDE, 0xFF}}},
	{{{21, -43, -15},0, {496, 927},{0x3B, 0xAC, 0xB6, 0xFF}}},
	{{{13, -26, -40},0, {449, 847},{0x3B, 0xAC, 0xB6, 0xFF}}},
	{{{36, -22, -26},0, {543, 847},{0x3B, 0xAC, 0xB6, 0xFF}}},
	{{{21, -43, -15},0, {496, 927},{0x18, 0x9B, 0xB7, 0xFF}}},
	{{{-8, -43, -25},0, {403, 927},{0x18, 0x9B, 0xB7, 0xFF}}},
	{{{13, -26, -40},0, {449, 847},{0x18, 0x9B, 0xB7, 0xFF}}},
	{{{-8, -43, -25},0, {403, 927},{0xFB, 0xAC, 0xA1, 0xFF}}},
	{{{-14, -22, -43},0, {356, 847},{0xFB, 0xAC, 0xA1, 0xFF}}},
	{{{13, -26, -40},0, {449, 847},{0xFB, 0xAC, 0xA1, 0xFF}}},
	{{{-8, -43, -25},0, {310, 927},{0xCC, 0xAC, 0xB0, 0xFF}}},
	{{{-34, -26, -25},0, {263, 847},{0xCC, 0xAC, 0xB0, 0xFF}}},
	{{{-14, -22, -43},0, {356, 847},{0xCC, 0xAC, 0xB0, 0xFF}}},
	{{{-8, -43, -25},0, {310, 927},{0xC2, 0x9B, 0xD3, 0xFF}}},
	{{{-26, -43, 0},0, {217, 927},{0xC2, 0x9B, 0xD3, 0xFF}}},
	{{{-34, -26, -25},0, {263, 847},{0xC2, 0x9B, 0xD3, 0xFF}}},
	{{{-26, -43, 0},0, {217, 927},{0xA4, 0xAC, 0xE7, 0xFF}}},
	{{{-45, -22, 0},0, {170, 847},{0xA4, 0xAC, 0xE7, 0xFF}}},
	{{{-34, -26, -25},0, {263, 847},{0xA4, 0xAC, 0xE7, 0xFF}}},
	{{{-26, -43, 0},0, {124, 927},{0xA4, 0xAC, 0x19, 0xFF}}},
	{{{-34, -26, 25},0, {77, 847},{0xA4, 0xAC, 0x19, 0xFF}}},
	{{{-45, -22, 0},0, {170, 847},{0xA4, 0xAC, 0x19, 0xFF}}},
	{{{-26, -43, 0},0, {124, 927},{0xC2, 0x9B, 0x2D, 0xFF}}},
	{{{-8, -43, 25},0, {31, 927},{0xC2, 0x9B, 0x2D, 0xFF}}},
	{{{-34, -26, 25},0, {77, 847},{0xC2, 0x9B, 0x2D, 0xFF}}},
	{{{-8, -43, 25},0, {31, 927},{0xCC, 0xAC, 0x50, 0xFF}}},
	{{{-14, -22, 43},0, {-16, 847},{0xCC, 0xAC, 0x50, 0xFF}}},
	{{{-34, -26, 25},0, {77, 847},{0xCC, 0xAC, 0x50, 0xFF}}},
	{{{43, -26, 0},0, {636, 847},{0x59, 0xAC, 0xDE, 0xFF}}},
	{{{21, -43, -15},0, {589, 927},{0x59, 0xAC, 0xDE, 0xFF}}},
	{{{36, -22, -26},0, {543, 847},{0x59, 0xAC, 0xDE, 0xFF}}},
	{{{43, -26, 0},0, {636, 847},{0x4D, 0x9B, 0x0, 0xFF}}},
	{{{21, -43, 15},0, {682, 927},{0x4D, 0x9B, 0x0, 0xFF}}},
	{{{21, -43, -15},0, {589, 927},{0x4D, 0x9B, 0x0, 0xFF}}},
	{{{21, -43, 15},0, {682, 927},{0x2A, 0x88, 0x0, 0xFF}}},
	{{{0, -50, 0},0, {636, 1008},{0x2A, 0x88, 0x0, 0xFF}}},
	{{{21, -43, -15},0, {589, 927},{0x2A, 0x88, 0x0, 0xFF}}},
	{{{-8, -43, 25},0, {868, 927},{0xFB, 0xAC, 0x5F, 0xFF}}},
	{{{13, -26, 40},0, {822, 847},{0xFB, 0xAC, 0x5F, 0xFF}}},
	{{{-14, -22, 43},0, {915, 847},{0xFB, 0xAC, 0x5F, 0xFF}}},
	{{{-8, -43, 25},0, {868, 927},{0x18, 0x9B, 0x49, 0xFF}}},
	{{{21, -43, 15},0, {775, 927},{0x18, 0x9B, 0x49, 0xFF}}},
	{{{13, -26, 40},0, {822, 847},{0x18, 0x9B, 0x49, 0xFF}}},
	{{{21, -43, 15},0, {775, 927},{0x3B, 0xAC, 0x4A, 0xFF}}},
	{{{36, -22, 26},0, {729, 847},{0x3B, 0xAC, 0x4A, 0xFF}}},
	{{{13, -26, 40},0, {822, 847},{0x3B, 0xAC, 0x4A, 0xFF}}},
};

Gfx ball_Icosphere_mesh_tri_0[] = {
	gsSPVertex(ball_Icosphere_mesh_vtx_0 + 0, 30, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
	gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
	gsSP2Triangles(12, 13, 14, 0, 15, 16, 17, 0),
	gsSP2Triangles(18, 19, 20, 0, 21, 22, 23, 0),
	gsSP2Triangles(24, 25, 26, 0, 27, 28, 29, 0),
	gsSPVertex(ball_Icosphere_mesh_vtx_0 + 30, 30, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
	gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
	gsSP2Triangles(12, 13, 14, 0, 15, 16, 17, 0),
	gsSP2Triangles(18, 19, 20, 0, 21, 22, 23, 0),
	gsSP2Triangles(24, 25, 26, 0, 27, 28, 29, 0),
	gsSPVertex(ball_Icosphere_mesh_vtx_0 + 60, 30, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
	gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
	gsSP2Triangles(12, 13, 14, 0, 15, 16, 17, 0),
	gsSP2Triangles(18, 19, 20, 0, 21, 22, 23, 0),
	gsSP2Triangles(24, 25, 26, 0, 27, 28, 29, 0),
	gsSPVertex(ball_Icosphere_mesh_vtx_0 + 90, 30, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
	gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
	gsSP2Triangles(12, 13, 14, 0, 15, 16, 17, 0),
	gsSP2Triangles(18, 19, 20, 0, 21, 22, 23, 0),
	gsSP2Triangles(24, 25, 26, 0, 27, 28, 29, 0),
	gsSPVertex(ball_Icosphere_mesh_vtx_0 + 120, 30, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
	gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
	gsSP2Triangles(12, 13, 14, 0, 15, 16, 17, 0),
	gsSP2Triangles(18, 19, 20, 0, 21, 22, 23, 0),
	gsSP2Triangles(24, 25, 26, 0, 27, 28, 29, 0),
	gsSPVertex(ball_Icosphere_mesh_vtx_0 + 150, 30, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
	gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
	gsSP2Triangles(12, 13, 14, 0, 15, 16, 17, 0),
	gsSP2Triangles(18, 19, 20, 0, 21, 22, 23, 0),
	gsSP2Triangles(24, 25, 26, 0, 27, 28, 29, 0),
	gsSPVertex(ball_Icosphere_mesh_vtx_0 + 180, 30, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
	gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
	gsSP2Triangles(12, 13, 14, 0, 15, 16, 17, 0),
	gsSP2Triangles(18, 19, 20, 0, 21, 22, 23, 0),
	gsSP2Triangles(24, 25, 26, 0, 27, 28, 29, 0),
	gsSPVertex(ball_Icosphere_mesh_vtx_0 + 210, 30, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
	gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
	gsSP2Triangles(12, 13, 14, 0, 15, 16, 17, 0),
	gsSP2Triangles(18, 19, 20, 0, 21, 22, 23, 0),
	gsSP2Triangles(24, 25, 26, 0, 27, 28, 29, 0),
	gsSPEndDisplayList(),
};


Gfx mat_ball_Material_001_f3d[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPSetLights1(ball_Material_001_f3d_lights),
	gsSPEndDisplayList(),
};


Gfx ball_Icosphere_mesh[] = {
	gsSPClearGeometryMode(G_LIGHTING),
	gsSPVertex(ball_Icosphere_mesh_vtx_cull + 0, 8, 0),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPCullDisplayList(0, 7),
	gsSPDisplayList(mat_ball_Material_001_f3d),
	gsSPDisplayList(ball_Icosphere_mesh_tri_0),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsSPEndDisplayList(),
};



