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
// SHA1 = 530909921e876bd737eb6175d500428de8323784
//
// unique function name that can be checked if the correct library version
// has been loaded
extern "C" void farLaminarProfile_530909921e876bd737eb6175d500428de8323784(bool load)
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
    farLaminarProfileFixedValueFvPatchVectorField
);

} // End namespace Foam


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::
farLaminarProfileFixedValueFvPatchVectorField::
farLaminarProfileFixedValueFvPatchVectorField
(
    const fvPatch& p,
    const DimensionedField<vector, volMesh>& iF
)
:
    parent_bctype(p, iF)
{
    if (false)
    {
        printMessage("Construct farLaminarProfile : patch/DimensionedField");
    }
}


Foam::
farLaminarProfileFixedValueFvPatchVectorField::
farLaminarProfileFixedValueFvPatchVectorField
(
    const farLaminarProfileFixedValueFvPatchVectorField& rhs,
    const fvPatch& p,
    const DimensionedField<vector, volMesh>& iF,
    const fvPatchFieldMapper& mapper
)
:
    parent_bctype(rhs, p, iF, mapper)
{
    if (false)
    {
        printMessage("Construct farLaminarProfile : patch/DimensionedField/mapper");
    }
}


Foam::
farLaminarProfileFixedValueFvPatchVectorField::
farLaminarProfileFixedValueFvPatchVectorField
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
        printMessage("Construct farLaminarProfile : patch/dictionary");
    }
}


Foam::
farLaminarProfileFixedValueFvPatchVectorField::
farLaminarProfileFixedValueFvPatchVectorField
(
    const farLaminarProfileFixedValueFvPatchVectorField& rhs
)
:
    parent_bctype(rhs),
    dictionaryContent(rhs)
{
    if (false)
    {
        printMessage("Copy construct farLaminarProfile");
    }
}


Foam::
farLaminarProfileFixedValueFvPatchVectorField::
farLaminarProfileFixedValueFvPatchVectorField
(
    const farLaminarProfileFixedValueFvPatchVectorField& rhs,
    const DimensionedField<vector, volMesh>& iF
)
:
    parent_bctype(rhs, iF)
{
    if (false)
    {
        printMessage("Construct farLaminarProfile : copy/DimensionedField");
    }
}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::
farLaminarProfileFixedValueFvPatchVectorField::
~farLaminarProfileFixedValueFvPatchVectorField()
{
    if (false)
    {
        printMessage("Destroy farLaminarProfile");
    }
}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

void
Foam::
farLaminarProfileFixedValueFvPatchVectorField::updateCoeffs()
{
    if (this->updated())
    {
        return;
    }

    if (false)
    {
        printMessage("updateCoeffs farLaminarProfile");
    }

//{{{ begin code
    #line 142 "/tmp/chevalier/OpenFOAM/nozzle/0/U.boundaryField.far"
const fvPatch& boundaryPatch = patch();
		const vectorField& Cf = boundaryPatch.Cf();
		
		const scalar t = this->db().time().value();
		const scalar U_m = max(.5-max(int(t/250)*.025,0),.05);

		forAll(Cf, faceI) { (*this)[faceI] = vector(U_m,0,0); }
//}}} end code

    this->parent_bctype::updateCoeffs();
}


// ************************************************************************* //

