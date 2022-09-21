// Gmsh project created on Fri May 15 17:21:02 2020
Mesh.MshFileVersion = 2.2;
R=1;
L=35*R; H=4*R;
r=1e-3;

// Base 'rectangle'
Point(1) = {0, 0, 0,  50*r};
Point(2) = {L, 0, 0,  75*r};
Point(3) = {L, H, 0, 500*r};
Point(4) = {0, H, 0, 500*r};
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
Point(12) = {.85*R,     R, 0,    r};
Point(13) = {.85*R, .85*R, 0, 10*r};
Point(14) = { 30*R,  .2*R, 0, 50*r};
Point(15) = { 30*R, 1.1*R, 0, 75*r};
Point(16) = {.85*R, 1.1*R, 0, 10*r};

// Main rectangle
Line(1)  = {1,   2};
Line(2)  = {2,   3};
Line(3)  = {3,   4};
Line(4)  = {4,   5};
Line(5)  = {5,  12};
Line(6)  = {12, 16};
Line(7)  = {16, 15};
Line(8)  = {15, 14};
Line(9)  = {14, 13};
Line(10) = {13, 12};
Line(11) = {5,   1};
// Inner zone
Line(12) = {12,  7};
Line(19) = {7,   8};
Line(20) = {8,   9};
Line(21) = {9,  10};
Line(22) = {10, 11};
Line(23) = {11,  7};
// Last nozzle segment
Line(24) = {7,   6};

// Surfaces
Line Loop(1) = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, -5, 11};
Line Loop(2) = {6, 7, 8, 9, 10, 12, 19, 20, 21, 22, 23, -12};
Line Loop(3) = {19, 20, 21, 22, 23, 24, -24};
For i In {1:3}
	Plane Surface(i) = {i};
EndFor
