void Merge_TwoSets(int *, int, int, int);
void MergeSortAlgo(int *a, int low, int high)
{
	int mid;
	if (low < high)
	{
		mid = (low + high) / 2;
		MergeSortAlgo(a, low, mid);
		MergeSortAlgo(a, mid + 1, high);
		Merge_TwoSets(a, low, high, mid);
	}
	return;
}
void Merge_TwoSets(int *a, int low, int high, int mid)
{
	int i, j, k, c[100];
	i = low;
	k = low;
	j = mid + 1;
	while (i <= mid && j <= high)
	{
		if (a[i] < a[j])
		{
			c[k] = a[i];
			k++;
			i++;
		}
		else
		{
			c[k] = a[j];
			k++;
			j++;
		}
	}
	while (i <= mid)
	{
		c[k] = a[i];
		k++;
		i++;
	}
	while (j <= high)
	{
		c[k] = a[j];
		k++;
		j++;
	}
	for (i = low; i < k; i++)
	{
		a[i] = c[i];
	}
}