/*
 * CubicHermiteInterpolationInputSolver.cpp
 *
 *  Created on: Nov 23, 2015
 *      Author: delpopol
 */

#include "CubicHermiteInterpolationInputSolver.h"

CubicHermiteInterpolationInputSolver::CubicHermiteInterpolationInputSolver() {}

CubicHermiteInterpolationInputSolver::~CubicHermiteInterpolationInputSolver() {}

void CubicHermiteInterpolationInputSolver::setRef(const IntegerVector& ref) {
	this->ref = ref;
}

void CubicHermiteInterpolationInputSolver::setT0Int(const RealVector& t0Int) {
	t0_int = t0Int;
}

void CubicHermiteInterpolationInputSolver::setT1Int(const RealVector& t1Int) {
	t1_int = t1Int;
}

void CubicHermiteInterpolationInputSolver::setT2Int(const RealVector& t2Int) {
	t2_int = t2Int;
}

void CubicHermiteInterpolationInputSolver::setY0Int(const RealVector& y0Int) {
	y0_int = y0Int;
}

void CubicHermiteInterpolationInputSolver::setY1Int(const RealVector& y1Int) {
	y1_int = y1Int;
}

void CubicHermiteInterpolationInputSolver::setY2Int(const RealVector& y2Int) {
	y2_int = y2Int;
}

void CubicHermiteInterpolationInputSolver::setZ0Int(const RealVector& z0Int) {
	z0_int = z0Int;
}

void CubicHermiteInterpolationInputSolver::setZ1Int(const RealVector& z1Int) {
	z1_int = z1Int;
}

void CubicHermiteInterpolationInputSolver::setZ2Int(const RealVector& z2Int) {
	z2_int = z2Int;
}

const IntegerVector& CubicHermiteInterpolationInputSolver::getRef() const {
	return ref;
}

const RealVector& CubicHermiteInterpolationInputSolver::getT0Int() const {
	return t0_int;
}

const RealVector& CubicHermiteInterpolationInputSolver::getT1Int() const {
	return t1_int;
}

const RealVector& CubicHermiteInterpolationInputSolver::getT2Int() const {
	return t2_int;
}

const RealVector& CubicHermiteInterpolationInputSolver::getY0Int() const {
	return y0_int;
}

const RealVector& CubicHermiteInterpolationInputSolver::getY1Int() const {
	return y1_int;
}

const RealVector& CubicHermiteInterpolationInputSolver::getY2Int() const {
	return y2_int;
}

const RealVector& CubicHermiteInterpolationInputSolver::getZ0Int() const {
	return z0_int;
}

const RealVector& CubicHermiteInterpolationInputSolver::getZ1Int() const {
	return z1_int;
}

const RealVector& CubicHermiteInterpolationInputSolver::getZ2Int() const {
	return z2_int;
}
