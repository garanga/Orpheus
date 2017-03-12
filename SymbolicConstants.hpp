/*
 * SymbolicConstants.hpp
 *
 *  Created on: Feb 1, 2017
 *      Author: pavel
 */

#ifndef SYMBOLICCONSTANTS_HPP_
#define SYMBOLICCONSTANTS_HPP_

enum class DisplacementConstraintType
{
	UX = 1 << 0,
	UY = 1 << 1,
	UXY = UX | UY
};

enum class ConcentratedLoadType
{
	FX = 1 << 0,
	FY = 1 << 1,
	FXY = FX | FY
};


enum class StaticStepConstants
{
	// matrixSolver
	DIRECT,
	ITERATIVE,
	//

};

enum class  Constant
{
	LAST
};


enum class ElementTypeEnum
{
    P4
};

enum class FileCodes
{
    MODELNAME,
    PARTNAME,
    DIMENSION,
    NODESPERELEMENT,
    NODES,
    ELEMENTS,
    STEP,
    FRAME,
    ENDOFFILE
};

enum class OutputSymbols
{
    OUTPUTEND = 0,
    U = 1,
    S = 2,
    E = 3,
    T = 4
};
#endif /* SYMBOLICCONSTANTS_HPP_ */
