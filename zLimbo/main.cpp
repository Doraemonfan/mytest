#include "zSelectSort.hpp"
#include "zTestSort.hpp"
#include "zInsertSort.hpp"
using namespace zLimbo;

void testSelect() {
	zTestInt(&zSelectSort<long>, "selectSort long: ");
	zTestInt(&zSelectSort2<long>, "selectSort2 long: ");
	zTestReal(&zSelectSort<double>, "selectSort double: ");
	zTestReal(&zSelectSort2<double>, "selectSort2 double: ");
}

void testInsert() {
	zTestInt(&zInsertSort<long>, "insertSort long: ");

}

int main() {
	//testSelect();
	testInsert();
	return 0;
}

