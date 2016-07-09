#include <algorithm>
#include <cstdlib> 
#include <ctime>
#include <iostream>
#include <vector>

void print_vector(std::vector<int> &v)
{
	std::cout << "The size of our std::vector is now: " << v.size() << std::endl;
	std::cout << "Vector has values:";
	for (std::vector<int>::iterator it = v.begin() ; it != v.end(); ++it)
	{
		std::cout << " " << *it;
	}
	std::cout << std::endl << std::endl;
}

int main()
{
	std::cout << "ALGORITHM CLASS LESSON" << std::endl;

	/*
	 * Sometimes there exist very common algorithms that people need to use
	 * In this lesson we will discuss some of the obvious ones.
	 */

	std::cout << "Generating a random int std::vector with numbers [1, 100]" << std::endl;
	/* First we will need to set up the randomness of our program. To do this we
	 * will need to plant the seed to our random number generator. We can use the
	 * object srand to do this. For a seed, we need a number that changes often so
	 * we have a better random effect. There is a function called time() which can
	 * help us out. Since time is always moving forward, this is result will be
	 * different every time we run our program!
	 *
	 *	NOTE: ONLY CALL THIS SEED CODE ONCE FOR YOUR PROGRAM
	 *	simply set it and forget it. It has to be done just once.
	 */

	srand(time(0));

	// Now we set up our random std::vector
	std::vector<int> v;
	for(int i = 0; i < 5; i++)
	{
		v.push_back(rand()%100 + 1);
	}

	print_vector(v);



	/*
	 * Now let's assume (for some odd reason) you wanted to print some IDs
	 * in sorted order. Perhaps of some employee IDs, one would say. Since all IDs
	 * are simply integers, we can add them to a std::vector, sort the std::vector, and
	 * print the result.
	 */

	// This looks messy. It's order it with sorting!
	std::cout << "Sorting our messy std::vector" << std::endl;
	sort(v.begin(), v.end());

	print_vector(v);

	std::cout << "Find if a value exists" << std::endl;
	std::vector<int>::iterator find_iter = v.begin();
	find_iter = find(v.begin(), v.end(), v[3]);
	std::cout << "Does " << v[3] << " exist? ";
	if(find_iter == v.end())
		std::cout << "No it does not exist" << std::endl << std::endl;
	else
		std::cout << "Yes it exists: " << *find_iter << std::endl << std::endl;



	find_iter = find(v.begin(), v.end(), 10000);
	std::cout << "Does 10000 exist in our std::vector? ";
	if(find_iter == v.end())
		std::cout << "No it does not exist" << std::endl << std::endl;
	else
		std::cout << "Yes it exists: " << *find_iter << std::endl << std::endl;


	// Now let's shuffle our vector like a deck of cards! (This could come in handy for a game)
	std::cout << "Performing a random shuffle" << std::endl;
	random_shuffle(v.begin(), v.end());

	print_vector(v);

	/* Overall there are tons of useful functions you may want to try out.
	 * Here is a great place to start: http://www.cplusplus.com/reference/algorithm/
	 * Try out different functions see if there is anything you'd like to use.
	 * Remember, don't reinvent the wheel. Use previously working code that has been optimized.
	 */

	return 0;
}
