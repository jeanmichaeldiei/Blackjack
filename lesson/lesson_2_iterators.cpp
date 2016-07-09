#include <iostream>
#include <vector>

void print_vector(std::vector<int> &v)
{
	std::cout << "The size of our vector is now: " << v.size() << std::endl;
	std::cout << "Vector has values:";
	for (std::vector<int>::iterator it = v.begin() ; it != v.end(); ++it)
	{
		std::cout << " " << *it;
	}
	std::cout << std::endl << std::endl;
}

int main()
{

	std::cout << "ITERATOR LESSON\n" << std::endl;
	std::vector<int> v;

	std::cout << "Adding elements to our vector using v.push_back()" << std::endl;
	for(int i = 1; i <= 5; i++)
	{
		// We want to add the numbers 1-5 to our std::vector
		v.push_back(i);
	}

	/* Now that we have a full vector, I'll show you the best way to traverse it.
	 * These containers provide access to an object called an iterator
	 */

	std::cout << "Printing std::vector values using an iterator" << std::endl;
	std::cout << "Vector has values:";
	for (std::vector<int>::iterator it = v.begin() ; it != v.end(); ++it)
	{
		// To view the value at the current iterator, you use the dereference operator
		std::cout << " " << *it;
	}
	std::cout << std::endl << std::endl;

	/*
	* As you can see, iterators can set to their corresponding values using addition and subtraction.
	* Doing it++ would shift the iterator to the next value.
	* Doing it-- would shift the iterator to the previous value.
	* Doing it+5 would shift the iterator to the next value 5 times.
	* Doing it-5 would shift the iterator to the previous value 5 times.
	*
	* You must specify the type of iterator you are using. In this case it's an iterator from the 
	* std::vector<int> class. Other classes have different iterators so it's important to specify this.
	* You will need iterators to work with a lot of standard library container functions
	*/

	// Let's try to use some other methods. First the insertion method
	std::cout << "Inserting an element into our vector requires an interator" << std::endl;
	// Insert a value at the beginning
	v.insert(v.begin(), -1);
	// Insert a value at the end
	v.insert(v.end(), 1000);
	// Insert a value at the 4th position (remember computer science uses 0-based counting)
	v.insert(v.begin()+3, 555);
	// Insert a value at the penultimate position
	v.insert(v.end()-1, 777);

	print_vector(v);

	// Similarly we can also erase values based on iterators
	std::cout << "Erasing the first value using our iterator" << std::endl;
	// Erase a the 3rd value
	v.erase(v.begin());
	print_vector(v);

	// Erase also works with a range
	std::cout << "Erasing from the range [ v[2], v[v.size()-2] )" << std::endl;
	v.erase(v.begin()+2, v.end()-2);
	print_vector(v);


	// Finally, you should note that there exist reverse_iterators for traversing everything backwards
	std::cout << "Traversing our vector backwards using a reverse_iterator" << std::endl;
	std::cout << "Vector has values:";
	for (std::vector<int>::reverse_iterator it = v.rbegin() ; it != v.rend(); ++it)
	{
		std::cout << " " << *it;
	}
	std::cout << std::endl << std::endl;


	return 0;
}