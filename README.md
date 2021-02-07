# Ordered-Map-using-AVL-Trees

## Task:
Implemented an Ordered Map which supports all the operations with complexity similar to Maps in C++ STL. The ordered map is implemented using AVL trees.

## Operations Implemented:
1. insert(key, value) – Insert the key value pair. If the key is already present, update it’s current value. Time Complexity - O(log n)
2. erase(key) – Erase the given key from the map if it is present. Time Complexity - O(log n)
3. find(key) – returns true if key was found else return 0. Time Complexity - O(log n)
4. map_obj[key] (subscript operator) – Access the element with the given key(if it is present in the map). Also, you should be able to modify the value at this key using this operator. If the value is not present, then insert this key with it’s corresponding assigned value. Time Complexity - O(log n)
5. size() – returns the number of keys present in the Map. Time Complexity - O(1)
6. clear() – removes all the elements from the Map. Time Complexity - O(n)
