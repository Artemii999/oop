#include "pch.h"
#include "CreateShape.h"
#include "Shape.h"

void Info(const std::vector<std::shared_ptr<CShape>>& shapes)
{
	for (const auto shape : shapes)
	{
		std::cout << shape->ToString() << std::endl;
	}
}

bool AreaCompare(const std::shared_ptr<CShape>& shape1, const std::shared_ptr<CShape>& shape2)
{
	return (shape1->GetArea() < shape2->GetArea());
}

bool PerimeterCompare(const std::shared_ptr<CShape>& shape1, const std::shared_ptr<CShape>& shape2)
{
	return (shape1->GetPerimeter() < shape2->GetPerimeter());
}

std::string ShapeMaxArea(const std::vector<std::shared_ptr<CShape>>& shapes)
{
	auto max = std::max_element(shapes.begin(), shapes.end(), AreaCompare);
	return (*max)->ToString();
}

std::string ShapeMinPerimeter(const std::vector<std::shared_ptr<CShape>>& shapes)
{
	auto min = std::min_element(shapes.begin(), shapes.end(), PerimeterCompare);
	return (*min)->ToString();
}

int main()
{
	std::vector<std::shared_ptr<CShape>> shapes;
	CCreateShape createShape(std::cin);

	while (auto shape = createShape.ExecuteCommand())
	{
		shapes.push_back(shape);
	}

	if (!shapes.empty())
	{
		Info(shapes);

		std::cout << "Shape with max area: " << std::endl;
		std::cout << ShapeMaxArea(shapes) << std::endl;

		std::cout << "Shape with min perimeter: " << std::endl;
		std::cout << ShapeMinPerimeter(shapes) << std::endl;
	}

	return 0;
}