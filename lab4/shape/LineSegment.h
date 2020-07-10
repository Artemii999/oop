#pragma once
#include "Shape.h"

class CLineSegment final : public CShape // создаём виртуальный класс для отрезок
{
public:
	CLineSegment(CPoint const& startPoint, CPoint const& endPoint, std::string const& outlineColor);
	double GetArea() const override;
	double GetPerimeter() const override;
	std::string ToString() const override;

	CPoint GetStartPoint() const;
	CPoint GetEndPoint() const;

private:
	CPoint m_startPoint;
	CPoint m_endPoint;
};
