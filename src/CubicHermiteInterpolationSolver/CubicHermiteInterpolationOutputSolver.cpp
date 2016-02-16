/*
 * CubicHermiteInterpolationOutputSolver.cpp
 *
 *  Created on: Nov 23, 2015
 *      Author: delpopol
 */

#include "CubicHermiteInterpolationOutputSolver.h"

CubicHermiteInterpolationOutputSolver::CubicHermiteInterpolationOutputSolver() {}

CubicHermiteInterpolationOutputSolver::~CubicHermiteInterpolationOutputSolver() {}

const RealVector& CubicHermiteInterpolationOutputSolver::getY1() const {
	return y1;
}

void CubicHermiteInterpolationOutputSolver::setY1(const RealVector& y1) {
	this->y1 = y1;
}

const RealVector& CubicHermiteInterpolationOutputSolver::getY2() const {
	return y2;
}

void CubicHermiteInterpolationOutputSolver::setY2(const RealVector& y2) {
	this->y2 = y2;
}
