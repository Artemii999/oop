#pragma once
#include <string>

class CPoint // // создаём класс для точки
{
public:
	double x;
	double y;
};

class CShape // создаём класс для обведённой фигуры
{
public:
	virtual double GetArea() const = 0;
	virtual double GetPerimeter() const = 0;
	virtual std::string ToString() const = 0;

	std::string GetOutlineColor() const;
	void SetOutlineColor(const std::string& color);

private:
	std::string m_outlineColor;
};
