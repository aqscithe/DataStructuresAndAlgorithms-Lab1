#include "ArrayBag.h"
#include <iostream>
#include <cstddef>


template<class ItemType>
ArrayBag<ItemType>::ArrayBag(): itemCount(0), maxItems(DEFAULT_CAPACITY)
{
}  // end default constructor

template<class ItemType>
int ArrayBag<ItemType>::getCurrentSize() const
{
	return itemCount;
}  // end getCurrentSize

template<class ItemType>
bool ArrayBag<ItemType>::isEmpty() const
{
	return itemCount == 0;
}  // end isEmpty

template<class ItemType>
bool ArrayBag<ItemType>::add(const ItemType& newEntry)
{
	bool hasRoomToAdd = (itemCount < maxItems) && !contains(newEntry);
	if (hasRoomToAdd)
	{
		items[itemCount] = newEntry;
		itemCount++;
	}  // end if
    
	return hasRoomToAdd;
}  // end add

template<class ItemType>
bool ArrayBag<ItemType>::remove(const ItemType& anEntry)
{
   int locatedIndex = getIndexOf(anEntry);
	bool canRemoveItem = !isEmpty() && (locatedIndex > -1);
	if (canRemoveItem)
	{
		itemCount--;
		items[locatedIndex] = items[itemCount];
	}  // end if
    
	return canRemoveItem;
}  // end remove

template<class ItemType>
void ArrayBag<ItemType>::clear()
{
	itemCount = 0;
}  // end clear

template <class ItemType>
void ArrayBag<ItemType>::sortBag()
{
   bubbleSort(items, itemCount);
} // end sortBag

template<class ItemType>
int ArrayBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const
{
   int frequency = 0;
   int curIndex = 0;       // Current array index
   while (curIndex < itemCount)
   {
      if (items[curIndex] == anEntry)
      {
         frequency++;
      }  // end if
      
      curIndex++;          // Increment to next entry
   }  // end while
   
   return frequency;
}  // end getFrequencyOf

template <class ItemType>
int ArrayBag<ItemType>::searchBag(const ItemType target, int binaryTechnique) const
{
   int index = -2;

   if(isSorted())
   {
      // Ensure that the bag is not empty
      if (itemCount > 0)
      {
         int last = itemCount - 1;

         // Verify version of binary search to use
         switch (binaryTechnique)
         {
            case 0:
            {
               // Recursive Search
               index = binarySearchRecursive(items, 0, last, target);
               break;
            }

            case 1:
            {
               // Iterative Search
               index = binarySearchIterative(items, 0, last, target);
               break;
            }
            
            default:
            {
               // Default behavior - Recursive Search
               index = binarySearchRecursive(items, 0, last, target);
               break;
            }
         } // end switch
      }
      else
      {
         // Signal that item was not found
         index = -1;
      } // end if
   }

   
    return index;
} // end searchBag

template <class ItemType>
void ArrayBag<ItemType>::displayBag() const
{
   if (!isEmpty())
   {
      std::vector<ItemType> bagContents = toVector();
      for (int index = 0; index < bagContents.size() - 1; index++)
      {
         std::cout << bagContents[index] << " | ";
      }
      
      std::cout << bagContents.back() << std::endl;
   } 
   else
   {
      std::cout << "Bag is empty" << std::endl;
   } // end if

} // end displayBag

template<class ItemType>
bool ArrayBag<ItemType>::contains(const ItemType& anEntry) const
{
	return getIndexOf(anEntry) > -1;
}  // end contains

/* ALTERNATE 1: First version
template<class ItemType>
bool ArrayBag<ItemType>::contains(const ItemType& target) const 
{
   return getFrequencyOf(target) > 0;
}  // end contains

// ALTERNATE 2: Second version 
template<class ItemType>
bool ArrayBag<ItemType>::contains(const ItemType& anEntry) const
{
   bool found = false;
   int curIndex = 0;        // Current array index
   while (!found && (curIndex < itemCount))
   {
      if (anEntry == items[curIndex])
      {
         found = true;
      } // end if
      
      curIndex++;           // Increment to next entry
   }  // end while   
   
   return found;
}  // end contains
*/

template<class ItemType>
std::vector<ItemType> ArrayBag<ItemType>::toVector() const
{
   std::vector<ItemType> bagContents;
	for (int i = 0; i < itemCount; i++)
		bagContents.push_back(items[i]);
      
   return bagContents;
}  // end toVector

// private
template<class ItemType>
int ArrayBag<ItemType>::getIndexOf(const ItemType& target) const
{
	bool found = false;
   int result = -1;
   int searchIndex = 0;
   
   // If the bag is empty, itemCount is zero, so loop is skipped
   while (!found && (searchIndex < itemCount))
   {
      if (items[searchIndex] == target)
      {
         found = true;
         result = searchIndex;
      } 
      else
      {
         searchIndex++;
      }  // end if
   }  // end while
   
   return result;
}  // end getIndexOf

template <typename ItemType>
void ArrayBag<ItemType>::bubbleSort(ItemType theArray[], int size)
{
   bool sorted = false;
   int pass = 1;
   while (!sorted && (pass < size))
   {
      // All entries up to theArray[size - pass] are sorted.
      // Assume sorted
      sorted = true;

      // Cycle through array up to theArray[size - pass - 1]
      for (int index = 0; index < size - pass; index++)
      {
         int nextIndex = index + 1;

         // Check if current index is greater than subsequent index
         if (theArray[index] > theArray[nextIndex])
         {
            // Exchange entries
            std::swap(theArray[index], theArray[nextIndex]);

            // Signals an exchange occurred
            sorted = false;
         } // end if
      } // end for
      
      // Move on to next pass
      pass++;
   } // end while

} // end bubbleSort


template <class ItemType>
int ArrayBag<ItemType>::binarySearchRecursive(const ItemType theArray[], int first, int last, const ItemType& target) const
{
   // Initial value -1 indicates target not found
   int index = -1;

   // Check base case(array has only 1 element)
   if (first == last)
   {
      // Target index is the remaining element
      if (theArray[first] == target) 
      {
        index = first; 
      } 
   }
   else
   {
      // Find mid point of array
      int mid = first + (last - first) / 2;

      // Handle case where the midpoint is the target
      if (theArray[mid] == target)
      {
         index = mid;
      } 

      // Check if target is left of midpoint
      else if(target < theArray[mid])
      {
         // Search array from theArray[first] to theArray[mid - 1]
         index = binarySearchRecursive(theArray, first, mid - 1, target);
      }

      // Else target is right of the midpoint
      else
      {
         // Search array from theArray[mid + 1] to theArray[last]
         index = binarySearchRecursive(theArray, mid + 1, last, target);
      } // end if
   } // end if

    return index;

} // end binarySearchRecursive

template <class ItemType>
int ArrayBag<ItemType>::binarySearchIterative(const ItemType theArray[], int first, int last, const ItemType& target) const
{
   // Loop continues as long as first index does not surpass last
   while (first <= last)
   {
      // Find mid point of array
      int mid = first + (last - first) / 2;

      // Base case where array has 1 element remaining.
      // Remaining element is the midpoint
      if (theArray[mid] == target)
      {
         return mid;
      }

      // Check if target is to the left of mid
      else if (target < theArray[mid])
      {
         // adjust last index to left of mid
         last = mid - 1;
      }

      // Target is to the right of mid
      else
      {
         // adjust first index to be right of mid
         first = mid + 1;
      } // end if
   } // end while

   // Returns -1 if target is not found
   return -1;

} // end binarySearchIterative

template <class ItemType>
bool ArrayBag<ItemType>::isSorted() const
{
	bool sorted = true;
	for (int index = 0; index < itemCount - 1; index++)
	{
		int nextIndex = index + 1;
		if (items[index] > items[nextIndex]) 
		{
			sorted = false;
		}
	}

   return sorted;
}
