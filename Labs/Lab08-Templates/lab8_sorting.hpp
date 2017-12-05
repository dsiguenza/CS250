#ifndef _SORTING
#define _SORTING

/**
    Sets the value of a to the original value of b,
    and sets the value of b to the original value of a.

    @param <T&> a   The reference to an element of an array
    @param <T&> b   The reference to another element of an array
    @return <void>  No return - values are changed via pass-by-reference parameters
*/
template <typename T>
void Swap( T& a, T& b )
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}

/**
    Implementation of Selection Sort.
    See for reference: https://en.wikipedia.org/wiki/Selection_sort#Implementation

    @param <T[]> a  An array to sort
    @param <int> n  The size of the array a[]
    @return <void>  No return - array is passed-by-reference and modified directly
*/
template <typename T>
void SelectionSort( T a[], int n )
{

	//This code was ripped from the following source:: https://en.wikipedia.org/wiki/Selection_sort#Implementation

	/* a[0] to a[n-1] is the array to sort */
	int i, j;

	/* advance the position through the entire array */
	/*   (could do j < n-1 because single element is also min element) */
	for (j = 0; j < n - 1; j++)
	{
		/* find the min element in the unsorted a[j .. n-1] */

		/* assume the min is the first element */
		int iMin = j;
		/* test against elements after j to find the smallest */
		for (i = j + 1; i < n; i++) {
			/* if this element is less, then it is the new minimum */
			if (a[i] < a[iMin]) {
				/* found new minimum; remember its index */
				iMin = i;
			}
		}

		if (iMin != j)
		{
			swap(a[j], a[iMin]);
		}
	}
}

/**
    Display each element of the array, from 0 to n-1

    @param <T[]> a  An array to sort
    @param <int> n  The size of the array a[]
    @return <void>  No return
*/
template <typename T>
void DisplayArray(const T a[], int n)
{
	for (int i = 0; i < n; i++) 
	{
		cout << "'" << a[i] << "'" << " ";
	}
	cout << endl;
}

#endif
