#ifndef BAG_INTERFACE_
#define BAG_INTERFACE_

#include <vector>

template<class ItemType>
class BagInterface
{
public:
	
	// Gets the current number of entries in this bag.
	// Returns the integer number of entries currently in the bag
	virtual int getCurrentSize() const = 0;
   
	// Sees whether this bag is empty.
	// Returns True if the bag is empty, or false if not
	virtual bool isEmpty() const = 0;
   
	// Adds a new entry to this bag.
	// If successful, newEntry is stored in the bag and
	// the count of items in the bag has increased by 1.
	// Input: newEntry  The object to be added as a new entry.
	// Returns True if addition was successful, or false if not
	virtual bool add(const ItemType& newEntry) = 0;
   
	// Removes one occurrence of a given entry from this bag,
	// if possible.
	// If successful, anEntry has been removed from the bag
	// and the count of items in the bag has decreased by 1.
	// Input: anEntry  The entry to be removed.
	// Returns: True if removal was successful, or false if not
	virtual bool remove(const ItemType& anEntry) = 0;
   
	// Removes all entries from this bag.
	// Result: Bag contains no items, and the count of items is 0
	virtual void clear() = 0;
   
	// Counts the number of times a given entry appears in bag.
	// Input: anEntry  The entry to be counted
	// Returns: The number of times anEntry appears in the bag
	virtual int getFrequencyOf(const ItemType& anEntry) const = 0;
   
	// Tests whether this bag contains a given entry.
	// Input: anEntry  The entry to locate
	// Returns: True if bag contains anEntry, or false otherwise
	virtual bool contains(const ItemType& anEntry) const = 0;
   
	// Empties and then fills a given vector with all entries that
	// are in this bag.
	// Returns: A vector containing all the entries in the bag
	virtual std::vector<ItemType> toVector() const = 0;

	// Prints the items in the bag to the screen.
	virtual void displayBag() const = 0;

	// Sorts entries in this bag
	// Result: Bag is sorted in ascending order
	virtual void sortBag() = 0;

	// Searches bag for target item.
	// Inputs: 	target - The item being searched for
	//			binaryTechnique - The binary search algorithm to use
	//				0 for recursive(default).
	//				1 for iterative.
	// Returns: The index of the target item, -1 if not found, -2 if
	// the bag is not sorted
	virtual int searchBag(const ItemType target, int binaryTechnique = 0) const = 0;
  
	// Destroys object and frees memory allocated by object.
	virtual ~BagInterface () { }
   
}; // end BagInterface
#endif
