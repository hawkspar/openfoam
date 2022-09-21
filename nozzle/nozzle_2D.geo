// Gmsh project created on Fri May 15 17:21:02 2020
Mesh.MshFileVersion = 2.2;
R=1;
L=60*R; H=15*R; o=1;
r=5e-4;

// Base 'rectangle'
Point(1) = {0, 0, 0,   20*r};
Point(2) = {L, 0, 0,  500*r};
Point(3) = {L, H, 0, 5000*r};
Point(4) = {0, H, 0, 5000*r};
// Actual nozzle

Point(5) = {0, R, 0, r};
Point(6) = {R, R, 0, r};
// Most refined area
Point(7)  = {.95*R,      R, 0, r};
Point(8)  = {.95*R,  .99*R, 0, r};
Point(9)  = {1.1*R,  .99*R, 0, r};
Point(10) = {1.1*R, 1.01*R, 0, r};
Point(11) = {.95*R, 1.01*R, 0, r};
// Less refined area
Point(12) = {.9*R,      R, 0,   r};
Point(13) = {.9*R,  .95*R, 0, 5*r};
Point(14) = { 2*R,  .95*R, 0, 5*r};
Point(15) = { 2*R, 1.03*R, 0, 7*r};
Point(16) = {.9*R, 1.03*R, 0, 7*r};
// Less refined area 2
Point(17) = {.85*R,     R, 0,     r};
Point(18) = {.85*R, .85*R, 0,  10*r};
Point(19) = { 20*R,  .4*R, 0, 100*r};
Point(20) = { 20*R,   3*R, 0, 400*r};
Point(21) = {.85*R, 1.1*R, 0,  10*r};

// Main rectangle
Line(1)  = {1,   2};
Line(2)  = {2,   3};
Line(3)  = {3,   4};
Line(4)  = {4,   5};
Line(5)  = {5,  17};
Line(6)  = {17, 21};
Line(7)  = {21, 20};
Line(8)  = {20, 19};
Line(9)  = {19, 18};
Line(10) = {18, 17};
Line(11) = {5,   1};
// Outer zone
Line(12) = {17, 12};
Line(13) = {12, 16};
Line(14) = {16, 15};
Line(15) = {15, 14};
Line(16) = {14, 13};
Line(17) = {13, 12};
// Inner zone
Line(18) = {12,  7};
Line(19) = {7,   8};
Line(20) = {8,   9};
Line(21) = {9,  10};
Line(22) = {10, 11};
Line(23) = {11,  7};
// Last nozzle segment
Line(24) = {7, 6};

// Surfaces
Line Loop(1) = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, -5, 11};
Line Loop(2) = {6, 7, 8, 9, 10, -12, 13, 14, 15, 16, 17, 12};
Line Loop(3) = {13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, -18};
Line Loop(4) = {19, 20, 21, 22, 23, 24, -24};
For i In {1:4}
	Plane Surface(i) = {i};
EndFor
