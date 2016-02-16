/*
 * CubicHermiteInterpolationOutputSolver.h
 *
 *  Created on: Nov 23, 2015
 *      Author: delpopol
 */

#ifndef CUBICHERMITEINTERPOLATIONOUTPUTSOLVER_H_
#define CUBICHERMITEINTERPOLATIONOUTPUTSOLVER_H_

#include"StandardTypes.h"
using namespace Utils;

/*!
 * Output class for the cubic Hermite interpolator
 */
class CubicHermiteInterpolationOutputSolver {
public:
	CubicHermiteInterpolationOutputSolver();
	virtual ~CubicHermiteInterpolationOutputSolver();

	const RealVector& getY1() const;

	void setY1(const RealVector& y1);

	const RealVector& getY2() const;

	void setY2(const RealVector& y2);
private:
	RealVector y1;	/*!< Solution at time t1 */
	RealVector y2;	/*!< Solution at time t2 */
};

#endif /* CUBICHERMITEINTERPOLATIONOUTPUTSOLVER_H_ */
