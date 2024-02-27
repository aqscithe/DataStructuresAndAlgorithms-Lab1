#ifndef ARRAY_BAG_
#define ARRAY_BAG_

#include "BagInterface.h"

template<class ItemType>
class ArrayBag : public BagInterface<ItemType>
{
private:
	static const int DEFAULT_CAPACITY = 30; // Small size to test for a full bag
	ItemType items[DEFAULT_CAPACITY];      // Array of bag items
	int itemCount;                         // Current count of bag items 
	int maxItems;                          // Max capacity of the bag
   
	// Returns either the index of the element in the array items that
	// contains the given target or -1, if the array does not contain 
	// the target.
	int getIndexOf(const ItemType& target) const;  

	// Uses the bubble sort algorithm to an array in ascending order 
	void bubbleSort(ItemType theArray[], int size);

	// Uses the recursive binary search algorithm, returning the index of 
	// the target item in the bag. If the target is not present, -1 is 
	// returned.
	int binarySearchRecursive(const ItemType theArray[], int first, int last, const ItemType& target) const;

	// Uses the iterative binary search algorithm, returning the index of
	// the target item in the bag. If the target is not present, -1 is 
	// returned
	int binarySearchIterative(const ItemType theArray[], int first, int last, const ItemType& target) const;

	// Checks if the bag is sorted. Returns true if so, but false if not.
	bool isSorted() const;

public:
	ArrayBag();
	int getCurrentSize() const;
	bool isEmpty() const;
	bool add(const ItemType& newEntry);
	bool remove(const ItemType& anEntry);
	void clear();
	void sortBag();
	void displayBag() const;
	bool contains(const ItemType& anEntry) const;
	int getFrequencyOf(const ItemType& anEntry) const;
	int searchBag(const ItemType target, int binaryTechnique = 0) const;
   std::vector<ItemType> toVector() const;
   
}; // end ArrayBag

#include "ArrayBag.cpp"
#endif
