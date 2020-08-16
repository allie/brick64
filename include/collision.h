#ifndef COLLISION_H
#define COLLISION_H

#include "common.h"
#include "vector.h"
#include "plane.h"

// Get barycentric coordinates of P with respect to triangle ABC
// p - Point to convert
// a - Triangle vertex A
// b - Triangle vertex B
// c - Triangle vertex C
// u - Output coordinate U
// v - Output coordinate V
// w - Output coordinate W
void get_barycentric_coords(Vec3f p, Vec3f a, Vec3f b, Vec3f c, float* u, float* v, float* w);

// Determine whether a 3D point lies within a 3D triangle
// p - Point to test
// v1 - Vertex 1 of the triangle
// v2 - Vertex 2 of the triangle
// v3 - Vertex 3 of the triangle
bool point_in_triangle(Vec3f p, Vec3f v1, Vec3f v2, Vec3f v3);

// Determine whether a moving sphere intersects with a plane
// If so, calculate the point of intersection and the normalized time of intersection
// r - Sphere radius
// pos1 - Current position of the sphere
// pos2 - Next position of the sphere
// plane - Plane to test the sphere against
// hit - Point of collision output (pass NULL if irrelevant)
// time - Normalized time of collision output (pass NULL if irrelevant)
bool moving_sphere_plane_intersect(float r, Vec3f pos1, Vec3f pos2, Plane plane, Vec3f* hit, float* time);

// Determine whether a moving sphere intersects with a quad
// If so, calculate the point of intersection and the normalized time of intersection
// r - Sphere radius
// pos1 - Current position of the sphere
// pos2 - Next position of the sphere
// p1 - Top left vertex of the quad
// p2 - Top right vertex of the quad
// p3 - Bottom left vertex of the quad
// p4 - Bottom right vertex of the quad
// hit - Point of collision output (pass NULL if irrelevant)
// time - Normalized time of collision output (pass NULL if irrelevant)
bool moving_sphere_quad_intersect(float r, Vec3f pos1, Vec3f pos2, Vec3f p1, Vec3f p2, Vec3f p3, Vec3f p4, Vec3f* hit, float* time);

#endif
