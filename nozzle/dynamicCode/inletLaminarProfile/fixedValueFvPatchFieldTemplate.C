/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | www.openfoam.com
     \\/     M anipulation  |
-------------------------------------------------------------------------------
    Copyright (C) 2019-2021 OpenCFD Ltd.
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

\*---------------------------------------------------------------------------*/

#include "fixedValueFvPatchFieldTemplate.H"
#include "addToRunTimeSelectionTable.H"
#include "fvPatchFieldMapper.H"
#include "volFields.H"
#include "surfaceFields.H"
#include "unitConversion.H"
#include "PatchFunction1.H"

//{{{ begin codeInclude

//}}} end codeInclude


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

// * * * * * * * * * * * * * * * Local Functions * * * * * * * * * * * * * * //

//{{{ begin localCode

//}}} end localCode


// * * * * * * * * * * * * * * * Global Functions  * * * * * * * * * * * * * //

// dynamicCode:
// SHA1 = 6731f04feb1e2c2dedd26e13142c25cd81a466aa
//
// unique function name that can be checked if the correct library version
// has been loaded
extern "C" void inletLaminarProfile_6731f04feb1e2c2dedd26e13142c25cd81a466aa(bool load)
{
    if (load)
    {
        // Code that can be explicitly executed after loading
    }
    else
    {
        // Code that can be explicitly executed before unloading
    }
}

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

makeRemovablePatchTypeField
(
    fvPatchVectorField,
    inletLaminarProfileFixedValueFvPatchVectorField
);

} // End namespace Foam


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::
inletLaminarProfileFixedValueFvPatchVectorField::
inletLaminarProfileFixedValueFvPatchVectorField
(
    const fvPatch& p,
    const DimensionedField<vector, volMesh>& iF
)
:
    parent_bctype(p, iF)
{
    if (false)
    {
        printMessage("Construct inletLaminarProfile : patch/DimensionedField");
    }
}


Foam::
inletLaminarProfileFixedValueFvPatchVectorField::
inletLaminarProfileFixedValueFvPatchVectorField
(
    const inletLaminarProfileFixedValueFvPatchVectorField& rhs,
    const fvPatch& p,
    const DimensionedField<vector, volMesh>& iF,
    const fvPatchFieldMapper& mapper
)
:
    parent_bctype(rhs, p, iF, mapper)
{
    if (false)
    {
        printMessage("Construct inletLaminarProfile : patch/DimensionedField/mapper");
    }
}


Foam::
inletLaminarProfileFixedValueFvPatchVectorField::
inletLaminarProfileFixedValueFvPatchVectorField
(
    const fvPatch& p,
    const DimensionedField<vector, volMesh>& iF,
    const dictionary& dict
)
:
    parent_bctype(p, iF, dict)
{
    if (false)
    {
        printMessage("Construct inletLaminarProfile : patch/dictionary");
    }
}


Foam::
inletLaminarProfileFixedValueFvPatchVectorField::
inletLaminarProfileFixedValueFvPatchVectorField
(
    const inletLaminarProfileFixedValueFvPatchVectorField& rhs
)
:
    parent_bctype(rhs),
    dictionaryContent(rhs)
{
    if (false)
    {
        printMessage("Copy construct inletLaminarProfile");
    }
}


Foam::
inletLaminarProfileFixedValueFvPatchVectorField::
inletLaminarProfileFixedValueFvPatchVectorField
(
    const inletLaminarProfileFixedValueFvPatchVectorField& rhs,
    const DimensionedField<vector, volMesh>& iF
)
:
    parent_bctype(rhs, iF)
{
    if (false)
    {
        printMessage("Construct inletLaminarProfile : copy/DimensionedField");
    }
}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::
inletLaminarProfileFixedValueFvPatchVectorField::
~inletLaminarProfileFixedValueFvPatchVectorField()
{
    if (false)
    {
        printMessage("Destroy inletLaminarProfile");
    }
}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

void
Foam::
inletLaminarProfileFixedValueFvPatchVectorField::updateCoeffs()
{
    if (this->updated())
    {
        return;
    }

    if (false)
    {
        printMessage("updateCoeffs inletLaminarProfile");
    }

//{{{ begin code
    #line 76 "/tmp/chevalier/OpenFOAM/nozzle/0/U.boundaryField.inlet"
const fvPatch& boundaryPatch = patch();
		const vectorField& Cf = boundaryPatch.Cf();
		const scalar a = 6.;
		
		const scalar t = this->db().time().value();
		const scalar S = max(int(t/5000)*.1,0);

		forAll(Cf, faceI) {
			const scalar y = Cf[faceI].y();
			const scalar z = Cf[faceI].z();
			const scalar r2 = y*y+z*z;
			const scalar ux = tanh(a*(1-r2));
			const scalar uth = S*ux;
			(*this)[faceI] = vector(ux,z*uth,y*uth);
		}
//}}} end code

    this->parent_bctype::updateCoeffs();
}


// ************************************************************************* //

