#pragma once
#include "Shape.h"

class CSolidShape : public CShape // класс залитой фигуры наследуется от класса фигуры
{
public:
	std::string GetFillColor() const;
	void SetFillColor(const std::string& color);

private:
	std::string m_fillColor;
};
