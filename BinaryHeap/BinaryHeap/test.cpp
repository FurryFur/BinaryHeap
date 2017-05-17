#include "catch.hpp"
#include "BinaryHeap.h"

TEST_CASE("Test insert")
{
	CBinaryHeap<int> heap;
	heap.Insert(3);
	heap.Insert(4);
	heap.Insert(7);
	heap.Insert(21);
	heap.Insert(10);
	heap.Insert(20);
	heap.Insert(8);

	heap.Insert(2);
	REQUIRE(heap.GetMin() == 2);

	REQUIRE(!heap.IsEmpty());
	REQUIRE(heap.GetSize() == 8);
}

TEST_CASE("Removal Test 1")
{
	CBinaryHeap<int> heap;
	heap.Insert(3);
	heap.Insert(4);
	heap.Insert(7);
	heap.Insert(21);
	heap.Insert(10);
	heap.Insert(20);
	heap.Insert(8);

	int iResult;
	heap.DeleteMin(iResult);
	REQUIRE(iResult == 3);
	REQUIRE(heap.GetMin() == 4);

	heap.DeleteMin(iResult);
	REQUIRE(iResult == 4);
	heap.DeleteMin(iResult);
	REQUIRE(iResult == 7);
	heap.DeleteMin(iResult);
	REQUIRE(iResult == 8);
	heap.DeleteMin(iResult);
	REQUIRE(iResult == 10);
	heap.DeleteMin(iResult);
	REQUIRE(iResult == 20);
	heap.DeleteMin(iResult);
	REQUIRE(iResult == 21);

	REQUIRE(heap.IsEmpty());
	REQUIRE(heap.GetSize() == 0);
}

TEST_CASE("Removal Test 2")
{
	CBinaryHeap<int> heap;
	heap.Insert(3);
	heap.Insert(6);
	heap.Insert(4);
	heap.Insert(21);
	heap.Insert(10);
	heap.Insert(7);
	heap.Insert(8);

	int iResult;
	heap.DeleteMin(iResult);
	REQUIRE(iResult == 3);
	REQUIRE(heap.GetMin() == 4);

	heap.DeleteMin(iResult);
	REQUIRE(iResult == 4);
	heap.DeleteMin(iResult);
	REQUIRE(iResult == 6);
	heap.DeleteMin(iResult);
	REQUIRE(iResult == 7);
	heap.DeleteMin(iResult);
	REQUIRE(iResult == 8);
	heap.DeleteMin(iResult);
	REQUIRE(iResult == 10);
	heap.DeleteMin(iResult);
	REQUIRE(iResult == 21);

	REQUIRE(heap.IsEmpty());
	REQUIRE(heap.GetSize() == 0);
}