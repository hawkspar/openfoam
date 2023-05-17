// Gmsh project created on Fri May 15 17:21:02 2020
Mesh.MshFileVersion = 2.2;
h=1; l=45/2; e=3.75/2; // Slit width, length, distance nozzle to plate
a=8*h; H=h/2+a; L=l/2+a; E=4*e; // Infinity distances
r=7e-3;
// Outer wall
Point(5) = {0, h/2+h, 0,     20*r};
Point(6) = {0, h/2+h, l/2+h, 20*r};
Point(7) = {0, 0,     l/2+h, 20*r};
// Infinity
Point(8)  = {0, H, 0, 100*r};
Point(9)  = {0, H, L, 200*r};
Point(10) = {0, 0, L, 100*r};
// Plate
Point(18) = {E+e, 0, 0, 10*r};
Point(19) = {E+e, H, 0, 50*r};
Point(20) = {E+e, H, L, 75*r};
Point(21) = {E+e, 0, L, 50*r};
// Outer region
Line(5)  = {5,  6};
Line(6)  = {6,  7};
Line(7)  = {7, 10};
Line(8)  = {10, 9};
Line(9)  = {9,  8};
Line(10) = {8,  5};
// Plate
Line(11) = {18, 19};
Line(12) = {19, 20};
Line(13) = {20, 21};
Line(14) = {21, 18};
// Extrusion (all faces)
out[]=Extrude {E,0,0} { Line{5,6}; };

// Inflow rectangle
Point(1) = {E, 0,   0, 10*r};
Point(2) = {E, h/2, 0,    r};
Point(3) = {E, h/2, l/2,  r};
Point(4) = {E, 0,   l/2,  r};
// Inflow rectangle
Line(1) = {1, 2};
Line(2) = {2, 3};
Line(3) = {3, 4};
Line(4) = {4, 1};

// Loose ends (z ties)
Line(44) = {1,  18};
Line(45) = {8,  19};
Line(46) = {9,  20};
Line(47) = {10, 21};
// Loose ends (nozzle)
Line(48) = {22, 2};
Line(49) = {25, 4};

// Simple surfaces
Line Loop(1) = {5, 6, 7, 8, 9, 10};
Line Loop(2) = {11, 12, 13, 14};
// Weird surfaces
Line Loop(3) = {44, 11,-45, 10, 16, 48,-1};
Line Loop(4) = {44,-14,-47, -7, 21, 49, 4};
// Infinity planes
Line Loop(5) = {45, 12,-46, 9};
Line Loop(6) = {46, 13,-47, 8};
// Nozzle wall
Line Loop(7) = {-48, 15, 19, 49, -3, -2};
// Inlet
Line Loop(8) = {1, 2, 3, 4};
For i In {1:8}
	Plane Surface(i) = {i};
EndFor

// Main dish
Surface Loop(1) = {1,7,8,2,4,18,5,3,22,6};
Volume(1) = {1};

// Labelling
Physical Surface("inlet") = {8};
Physical Surface("symmetry_y") = {4};
Physical Surface("symmetry_z") = {3};
Physical Surface("infinity_x") = {1};
Physical Surface("infinity_y") = {5};
Physical Surface("infinity_z") = {6};
Physical Surface("wall") = {2,7,18,22};
Physical Volume("internal") = {1};
