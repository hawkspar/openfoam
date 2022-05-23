// Gmsh project created on Fri May 15 17:21:02 2020
Mesh.MshFileVersion = 2.2;
R=.1;
L=20*R; H=5*R; o=.1*R;
n_R=100; n_LR=150; n_HR=50;

// Base 'rectangle'
Point(1) = {0, 0, 0, r};
Point(2) = {L, 0, 0, r};
Point(3) = {L, H, 0, r};
Point(4) = {0, H, 0, r};
// Actual nozzle
Point(5) = {0, R, 0, r};
Point(6) = {R, R, 0, r};
// Nozzle projections
Point(7) = {L,R,0,r};
Point(8) = {R,0,0,r};
Point(9) = {R,H,0,r};

// Inlet rectangle
Line(1)  = {1, 8};
Line(2)  = {8, 6};
Line(3)  = {6, 5};
Line(4)  = {5, 1};
// Lower rectangle
Line(5)  = {8, 2};
Line(6)  = {2, 7};
Line(7)  = {7, 6};
// Top one
Line(8)  = {7, 3};
Line(9)  = {3, 9};
Line(10) = {9, 6};
// Coflow rectangle
Line(11) = {9, 4};
Line(12) = {4, 5};

Transfinite Line{1,3,11}  = n_R;
Transfinite Line{2,-4,6}  = n_R Using Progression .98;
Transfinite Line{5,-7,-9}   = n_LR Using Progression 1.02;
Transfinite Line{8,-10,-12} = n_HR Using Progression 1.02;

// Surfaces
Line Loop(1) = {  1,  2,  3,  4};
Line Loop(2) = {  5,  6,  7, -2};
Line Loop(3) = { -7,  8,  9, 10};
Line Loop(4) = { -3,-10, 11, 12};
For i In {1:4}
	Plane Surface(i) = {i};
EndFor
// Extruded face
Physical Surface("back") = Surface{:};
// Extrusion (all faces)
out[]=Extrude {0,0,o} { Physical Surface{1}; Layers{1}; Recombine; };
Transfinite Surface{:};
Recombine Surface{:};

//For i In {1:25}
//	Printf("out[%g]=%g",i-1,out[i-1]);
//EndFor

// Labelling
// Volume definition
Physical Volume("internal") = {out[1],out[7],out[13],out[19]};
// Extruding face
Physical Surface("front")   = {out[0],out[6],out[12],out[18]};
// Left
//Plane
Physical Surface("coflow") = {out[23]};
Physical Surface("inlet")  = {out[5]};
Physical Surface("wall") = {out[4]};
// Top
Physical Surface("far")={out[16],out[22]};
// Bottom
Physical Surface("bottom")={out[2],out[8]};
// Right
Physical Surface("outlet") = {out[9],out[15]};
