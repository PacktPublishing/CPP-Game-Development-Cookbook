
// Bubble Sort
template <class T> 
void bubble_sort(T a[], int n)
{
	T temp;
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<n - i - 1; j++)
		{
			if (a[j]>a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1]; 
				a[j + 1] = temp;
			}
		}
	}
}

//Insertion Sort
template <class T>
void insertion_sort(T a[], int n)
{
	T key;
	for (int i = 1; i<n; i++)
	{
		key = a[i];
		int j = i - 1;
		while (j >= 0 && a[j]>key)
		{
			a[j + 1] = a[j];
			j = j - 1;
		}
		a[j + 1] = key;
	}
}

//Selection Sort
template <class T>
int minimum_element(T a, int low, int up)
{
	int min = low;
	while (low<up)
	{
		if (a[low]<a[min])
			min = low;
		low++;
	}
	return min;
}

template <class T>

void selection_sort(T a[], int n)
{
	int i = 0;
	int loc = 0;
	T temp;
	for (i = 0; i<n; i++)
	{
		loc = minimum_element(a, i, n);
		temp = a[loc];
		a[loc] = a[i];
		a[i] = temp;
	}
}

//Quick Sort
template <class T>
int partition(T a[], int p, int r)
{
	T x;
	int i;
	x = a[r];
	i = p - 1;
	for (int j = p; j <= r - 1; j++)
	{
		if (a[j] <= x)
		{
			i = i + 1;
			swap(a[i], a[j]);
		}
	}
	swap(a[i + 1], a[r]);
	return i + 1;
}
template <class T>
void quick_sort(T a[], int p, int r)
{
	int q;
	if (p<r)
	{
		q = partition(a, p, r);
		quick_sort(a, p, q - 1);
		quick_sort(a, q + 1, r);
	}
}

