#include "collision.h"

// Get barycentric coordinates of P with respect to triangle ABC
// p - Point to convert
// a - Triangle vertex A
// b - Triangle vertex B
// c - Triangle vertex C
// u - Output coordinate U
// v - Output coordinate V
// w - Output coordinate W
void get_barycentric_coords(Vec3f p, Vec3f a, Vec3f b, Vec3f c, float* u, float* v, float* w) {
  Vec3f v0 = {b.x - a.x, b.y - a.y, b.z - a.z};
  Vec3f v1 = {c.x - a.x, c.y - a.y, c.z - a.z};
  Vec3f v2 = {p.x - a.x, p.y - a.y, p.z - a.z};
  float d00 = vec3f_dot(v0, v0);
  float d01 = vec3f_dot(v0, v1);
  float d11 = vec3f_dot(v1, v1);
  float d20 = vec3f_dot(v2, v0);
  float d21 = vec3f_dot(v2, v1);
  float denom = d00 * d11 - d01 * d01;
  *v = (d11 * d20 - d01 * d21) / denom;
  *w = (d00 * d21 - d01 * d20) / denom;
  *u = 1.0f - *v - *w;
}

// Determine whether a 3D point lies within a 3D triangle
// p - Point to test
// v1 - Vertex 1 of the triangle
// v2 - Vertex 2 of the triangle
// v3 - Vertex 3 of the triangle
bool point_in_triangle(Vec3f p, Vec3f v1, Vec3f v2, Vec3f v3) {
  float u, v, w;
  get_barycentric_coords(p, v1, v2, v3, &u, &v, &w);
  return u >= 0 && u <= 1 &&
         v >= 0 && v <= 1 &&
         w >= 0 && w <= 1;
}

// Determine whether a moving sphere intersects with a plane
// If so, calculate the point of intersection and the normalized time of intersection
// r - Sphere radius
// pos1 - Current position of the sphere
// pos2 - Next position of the sphere
// plane - Plane to test the sphere against
// hit - Point of collision output (pass NULL if irrelevant)
// time - Normalized time of collision output (pass NULL if irrelevant)
bool moving_sphere_plane_intersect(float r, Vec3f pos1, Vec3f pos2, Plane plane, Vec3f* hit, float* time) {
  float d1, d2;

  d1 = plane_distance_to_point(plane, pos1);
  d2 = plane_distance_to_point(plane, pos2);

  // Check if the current position is already intersecting
  if (fabs(d1) <= r) {
    *time = 0;
    *hit = pos1;
    return TRUE;
  }

  // Check if there will be an intersection during this movement
  if (d1 > r && d2 < r) {
    *time = (d1 - r) / (d1 - d2);
    hit->x = (1 - (*time)) * pos1.x + (*time) * pos2.x;
    hit->y = (1 - (*time)) * pos1.y + (*time) * pos2.y;
    hit->z = (1 - (*time)) * pos1.z + (*time) * pos2.z;
    return TRUE;
  }

  return FALSE;
}

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
bool moving_sphere_quad_intersect(float r, Vec3f pos1, Vec3f pos2, Vec3f p1, Vec3f p2, Vec3f p3, Vec3f p4, Vec3f* hit, float* time) {
  Plane plane = plane_from_points(p1, p2, p3);
  Vec3f plane_hit;
  float plane_time;

  if (moving_sphere_plane_intersect(r, pos1, pos2, plane, &plane_hit, &plane_time)) {
    if (point_in_triangle(plane_hit, p1, p2, p3) || point_in_triangle(plane_hit, p2, p3, p4)) {
      *hit = plane_hit;
      *time = plane_time;
      return TRUE;
    }
  }

  return FALSE;
}
