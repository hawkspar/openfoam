/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | www.openfoam.com
     \\/     M anipulation  |
-------------------------------------------------------------------------------
    Copyright (C) YEAR AUTHOR, AFFILIATION
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.

Description
    Template for use with codeStream.

\*---------------------------------------------------------------------------*/

#include "dictionary.H"
#include "Ostream.H"
#include "Pstream.H"
#include "pointField.H"
#include "tensor.H"
#include "unitConversion.H"

//{{{ begin codeInclude
#line 22 "/tmp/chevalier/OpenFOAM/nozzle/0/U.#codeStream"
#include "fvCFD.H"
//}}} end codeInclude

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

// * * * * * * * * * * * * * * * Local Functions * * * * * * * * * * * * * * //

//{{{ begin localCode

//}}} end localCode


// * * * * * * * * * * * * * * * Global Functions  * * * * * * * * * * * * * //

extern "C" void codeStream_a296f949d05a55d8f3c7b003e74f6206c769e0b9(Foam::Ostream& os, const Foam::dictionary& dict)
{
//{{{ begin code
    #line 39 "/tmp/chevalier/OpenFOAM/nozzle/0/U.#codeStream"
const IOdictionary& d = static_cast<const IOdictionary&>(dict);
        const fvMesh& mesh = refCast<const fvMesh>(d.db());
	const vectorField& CC = mesh.C(); //cell center 

	const scalar U_m = .5;
	const scalar a = 6;
	const scalar H = 20;
	vectorField U(mesh.nCells(), vector(0,0,0));
        forAll(U, i)
        {
		// Access cell centers coordinates
		const scalar y = CC[i].y();
		const scalar z = CC[i].z();
		const scalar r2 = y*y+z*z;
		if (r2<1) {
			U[i][0] = tanh(a*(1-r2));
		}
		else {
			const scalar r = (sqrt(r2)-1)/(H-1);
			U[i][0] = 2*U_m*r*(1-r/2);
		}
        }
        U.writeEntry("", os);
//}}} end code
}


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// ************************************************************************* //

