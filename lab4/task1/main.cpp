// main.cpp: определяет точку входа для консольного приложения.
//

#include "pch.h"
#include "Point.h"
#include "ClineSegment.h"
#include "CTriangle.h"
#include "CRectangle.h"
#include "CCircle.h"
#include "IShape.h"
#include "CShapeMaker.h"
#include <memory>

using namespace std;

bool AreaMaxCompare(const std::shared_ptr<IShape> &shape1, const std::shared_ptr<IShape> &shape2)
{
	return(shape1->GetArea() < shape2->GetArea());
}

string FindAndGetInfoShapeWithMaxArea(vector<shared_ptr<IShape>> const& shapeList)
{
	auto max = max_element(shapeList.begin(), shapeList.end(), AreaMaxCompare);
	return (*max)->ToString();
}

bool PerimeterMinCompare(const std::shared_ptr<IShape> &shape1, const std::shared_ptr<IShape> &shape2)
{
	return(shape1->GetPerimeter() > shape2->GetPerimeter());
}

string FindAndGetInfoShapeWithMinPerimetr(vector<shared_ptr<IShape>> const& shapeList)
{
	auto max = max_element(shapeList.begin(), shapeList.end(), PerimeterMinCompare);
	return (*max)->ToString();
}

void PrintAllShapes(vector<std::shared_ptr<IShape>> const& shapeList)
{
	for (const auto shape : shapeList)
	{
		cout << shape->ToString() << "\n";
	}
}

int main()
{
	vector<shared_ptr<IShape>> shapeList;

	CShapeMaker shapeMaker(std::cin);

	while (auto shape = shapeMaker.ExecuteCommand())
	{
		shapeList.push_back(shape);
	}

	if (shapeList.empty())
	{
		cout << "You din't enter shapes\n";
		return 1;
	}

	cout << "You entered " << shapeList.size() << " shapes\n";

	cout << "Shape with max area: " << "\n";
	cout << FindAndGetInfoShapeWithMaxArea(shapeList) << "\n\n";

	cout << "Shape with min perimetr:" << "\n";
	cout << FindAndGetInfoShapeWithMinPerimetr(shapeList) << "\n\n";

	cout << "All entered shapes\n";
	PrintAllShapes(shapeList);

	return 0;
}

