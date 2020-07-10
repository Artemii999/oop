#include "pch.h"
#include "Shape.h"
// фигура
std::string CShape::GetOutlineColor() const // взять цвет обводки
{
	return m_outlineColor;
}

void CShape::SetOutlineColor(const std::string& color) // отдать цвет обводки
{
	m_outlineColor = color;
}
