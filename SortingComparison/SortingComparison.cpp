#include<iostream>
#include<cstdlib>
#include<string>


using namespace std;


void swapping(int& a, int& b) {     //swap the content of a and b
	int temp;
	temp = a;
	a = b;
	b = temp;
}
void display(int* array, int size) {
	for (int i = 0; i < size; i++)
		cout << array[i] << " ";
	cout << endl;
}

void bubbleSort(int* array, int size) {
	for (int i = 0; i < size; i++) {
		int swaps = 0;         //flag to detect any swap is there or not
		for (int j = 0; j < size - i - 1; j++) {
			if (array[j] > array[j + 1]) {       //when the current item is bigger than next
				swapping(array[j], array[j + 1]);
				swaps = 1;    //set swap flag
			}
		}
		if (!swaps)
			break;       // No swap in this pass, so array is sorted
	}
}

void merge(int* array, int l, int m, int r) {
	int i, j, k, nl, nr;
	//size of left and right sub-arrays
	nl = m - l + 1; 
	nr = r - m;
	
	int larr[nl], rarr[nr];
	//fill left and right sub-arrays
	for (i = 0; i < nl; i++)
		larr[i] = array[l + i];
	for (j = 0; j < nr; j++)
		rarr[j] = array[m + 1 + j];
	i = 0; j = 0; k = l;
	//marge temp arrays to real array
	while (i < nl && j < nr) {
		if (larr[i] <= rarr[j]) {
			array[k] = larr[i];
			i++;
		}
		else {
			array[k] = rarr[j];
			j++;
		}
		k++;
	}
	while (i < nl) {       //extra element in left array
		array[k] = larr[i];
		i++; k++;
	}
	while (j < nr) {     //extra element in right array
		array[k] = rarr[j];
		j++; k++;
	}
}
void mergeSort(int* array, int l, int r)
{
	int m;
	if (l < r) {
		int m = l + (r - l) / 2;
		// Sort first and second arrays
		mergeSort(array, l, m);
		mergeSort(array, m + 1, r);
		merge(array, l, m, r);
	}
}

int Partition(int a[], int l, int h)
{
	int pivot, index, i;
	index = l;
	pivot = h;
	for (i = l; i < h; i++) {
		if (a[i] < a[pivot]) {
			swapping(a[i], a[index]);
			index++;
		}
	}
	swapping(a[pivot], a[index]);
	return index;
}
int RandomPivotPartition(int a[], int l, int h) {
	int pvt, n, temp;
	n = rand();
	pvt = l + n % (h - l + 1);
	swapping(a[h], a[pvt]);
	return Partition(a, l, h);
}
int QuickSort(int a[], int l, int h) {
	int pindex;
	if (l < h) {
		pindex = RandomPivotPartition(a, l, h);
		QuickSort(a, l, pindex - 1);
		QuickSort(a, pindex + 1, h);
	}
	return 0;
}

void insertionSort(int* array, int size) {
	int key, j;
	for (int i = 1; i < size; i++) {
		key = array[i];//take value
		j = i;
		while (j > 0 && array[j - 1] > key) {
			array[j] = array[j - 1];
			j--;
		}
		array[j] = key;   //insert in right place
	}
}

int main() 
{
	int arr[14] = { 15,26,98,156,457,1,56,12,11,256,154,224,4645,45 };
	int size = 14;

	cout << "Array before Sorting with InsertionSort: ";
	display(arr, size);
	insertionSort(arr, size);
	cout << "Array after Sorting: ";
	display(arr, size);

	cout << "Array before Sorting with InsertionSort: ";
	display(arr, size);
	bubbleSort(arr, size);
	cout << "Array after Sorting: ";
	display(arr, size);

	cout << "Array before Sorting with InsertionSort: ";
	display(arr, size);
	QuickSort(arr, 0, size-1);
	cout << "Array after Sorting: ";
	display(arr, size);

	cout << "Array before Sorting with InsertionSort: ";
	display(arr, size);
	mergeSort(arr, 0, size-1);
	cout << "Array after Sorting: ";
	display(arr, size);
}