#include "pch.h"
#include "SolidShape.h"
// заполненная фигура
std::string CSolidShape::GetFillColor() const
{
	return m_fillColor;
}

void CSolidShape::SetFillColor(const std::string& color)
{
	m_fillColor = color;
}