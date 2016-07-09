#include <iostream>
#include <vector>

void print_vector(std::vector<int> &v)
{
	/* Notice how our parameter is a reference. From the CS240 lectures
	 * you should remember that passing references is better than passing
	 * a base case of a class. References have multiple benefits
	 *
	 * 1. They cannot be NULL so there is no need to make NULL checks on them
	 * 2. They are lightweight. They have the benefits of acting like a pointer
	 * 	  which means they take up very little space and are not copied over
	 * 3. They have the benefit of acting like a base class. No need to dereference
	 * 	  and keep track of "how many stars does my variable have?"
	 * 	  this makes the code a lot more readable and a lot less likely to have errors
	 *
	 */

	std::cout << "The size of our vector is now: " << v.size() << std::endl;

	// If the vector is empty, don't try to print each element
	if(v.size() == 0)
	{
		std::cout << "No elements to print. the vector is empty" << std::endl << std::endl;
		return;
	}

	std::cout << "The elements in order are: ";
	for(unsigned int i = 0; i < v.size() - 1 ; i++)
	{
		// To get a value, we can treat a std::vector like an array
		std::cout << v[i] << ", ";
	}
	std::cout << v[v.size()-1] << std::endl << std::endl;


	/* Good coding technique note:
	 * Because we wanted some special formatting for the last element, 
	 * we should perform the special case outside of our loop.
	 *
	 * Most beginners in programming would probably have done a loop like:
	 *
	 *  std::cout << "The elements in order are: ";
	 * 	for(unsigned int i = 0; i < v.size() ; i++)
	 *  {
	 *		std::cout << v[i];
	 *		if( i != v.size() -1 )
	 *			std::cout << ", ";
	 *		else
	 *			std::cout << std::endl;
	 * 	}
	 *
	 * While this code is correct, you are performing extra comparisons inside
	 * your for loop every iteration when you only have one special case
	 *
	 * In this situation, try to shrink the work of the for loop as much as possible.
	 * This makes the loop cleaner to understand and it is actually more efficient.
	 * The performance gained in a small program like this is minimal, but getting
	 * into a good habit will help a lot once you get into industry. This is the kind
	 * of code Google was asking me for during their interview. Can you think of what
	 * you would do for a special case in the front instead of the back? Try coding it.
	 *
	 */
}

void print_capacity_and_size(std::vector<int> &v)
{
	/* From lab 7 you learned that we keep track of a vector's size
	 * (the logical size of our array or how many elements we have)
	 * but we also keep track of capacity (the physical size of our array)
	 * or how much space we have actually allocated in memory
	 */
	std::cout << "Printing size and capacity" << std::endl;
	std::cout << "Size: " << v.size() << " Capacity: " << v.capacity() << std::endl << std::endl;
}


int main()
{
	std::cout << "VECTOR LESSON\n" << std::endl;

	/* local vector. Because I don't intend to pass it around
	 * from function to function. It's best to make it local only
	 * so the memory destroys itself when I get out of the function.
	 */
	std::vector<int> v;

	print_capacity_and_size(v);

	std::cout << "Adding elements to our vector using v.push_back()" << std::endl;
	for(int i = 1; i <= 5; i++)
	{
		// We want to add the numbers 1-5 to our vector
		v.push_back(i);
	}

	
	print_vector(v);


	//What are the size and capacity now?
	print_capacity_and_size(v);

	/* TIP: since the capacity of a std::vector starts off being small, if you have
	 * a vector as a member of an object and you expect that object to grow to a
	 * certain size. It would be smart to set an original capacity in the constructor
	 * of the object. That will reduce the overhead of resizing the vector.
	 *
	 * Don't forget, C and C++ are all about manual memory management. Don't choose
	 * a size you will never reach. That would be a huge waste of memory per object.
	 */

	std::cout << "Changing our capacity in order to prevent long resizes" << std::endl;
	v.reserve(10);
	print_capacity_and_size(v);

	/* 	As mentioned in the handout, we can call this method to pop
	*	The last element of our array, which is the most efficient.
	*/
	std::cout << "Popping the last element out" << std::endl;
	v.pop_back();


	print_vector(v);


	std::cout << "Let's change a value using array notation" << std::endl;
	// We can treat our vector object just like an array!
	v[2] = 100;
	v[3] = -1;


	print_vector(v);

	std::cout << "If we wanted to get rid of all of our elements in order to start over";
	std::cout << " we don't have to delete our object. we can simply call clear() " << std::endl;
	v.clear();

	print_vector(v);

	

	/* That's it for the first lesson. Now you know the basic techniques
	 * for using a vector. I hope this helped you out.
	 * Next we will cover a very important topic, iterators!
	 */

	std::cout << "END OF LESSON" << std::endl;
	return 0;
}
