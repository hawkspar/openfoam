// Gmsh project created on Fri May 15 17:21:02 2020
Mesh.MshFileVersion = 2.2;
R=.1;
L=60*R; H=10*R; o=1;
r=1e-3;

// Base 'rectangle'
Point(1) = {0, 0, 0, 3*r};
Point(2) = {L, 0, 0, 3*r};
Point(3) = {L, H, 0, 100*r};
Point(4) = {0, H, 0, 50*r};
// Actual nozzle
Point(5) = {0, R, 0, 5*r};
Point(6) = {R, R, 0, r};
// Most refined area
Point(7)  = {.75*R, 	 R, 0, r};
Point(8)  = {.75*R,  .75*R, 0, r};
Point(9)  = {  5*R,  .75*R, 0, r};
Point(10) = {  5*R, 1.25*R, 0, r};
Point(11) = {.75*R, 1.25*R, 0, r};
// Less refined area
Point(12) = {.5*R,     R, 0, 2*r};
Point(13) = {.5*R,  .5*R, 0, 3*r};
Point(14) = {20*R,  .5*R, 0, 2*r};
Point(15) = {20*R, 1.5*R, 0, 3*r};
Point(16) = {.5*R, 1.5*R, 0, 2*r};

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
// Outer zone
Line(12) = {12,  7};
Line(13) = {7,   8};
Line(14) = {8,   9};
Line(15) = {9,  10};
Line(16) = {10, 11};
Line(17) = {11,  7};
// Inner zone
Line(18) = {7, 6};

// Surfaces
Line Loop(1) = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, -5, 11};
Line Loop(2) = {6, 7, 8, 9, 10, -12, 13, 14, 15, 16, 17, 12};
Line Loop(3) = {13, 14, 15, 16, 17, 18, -18};
For i In {1:3}
	Plane Surface(i) = {i};
EndFor
// Extruded face
Physical Surface("front") = Surface{:};
// Extrusion (all faces)
Rotate{{1,0,0},{0,0,0},o/2*Pi/180} { Surface{:}; } // Must rotate all at once to avoid 'chainsaw effect'
out[]=Extrude {{1,0,0},{0,0,0},-o*Pi/180} { Surface{:}; Layers{1}; Recombine; };

/*For i In {1:30}
	Printf("out[%g]=%g",i-1,out[i-1]);
EndFor*/

// Labelling
// Volume definition
Physical Volume("internal") = {out[1],out[14],out[28]};
// Extruding face
Physical Surface("back") = {out[0],out[13],out[27]};
// Left
Physical Surface("coflow") = {out[4]};
Physical Surface("inlet")  = {out[12]};
Physical Surface("wall")   = {out[5],out[20],out[34]};
// Top
Physical Surface("far") = {out[3]};
// Right
Physical Surface("outlet") = {out[2]};
