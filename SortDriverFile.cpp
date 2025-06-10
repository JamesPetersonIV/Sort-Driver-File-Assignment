#include <iostream>
//include fstream
#include <fstream>
#include <chrono>
#include <utility>
#include <algorithm>

using namespace std;

typedef std::string String;
typedef std::chrono::high_resolution_clock::time_point TimeVar;

#define duration(a) std::chrono::duration_cast<std::chrono::nanoseconds>(a).count()
#define timeNow() std::chrono::high_resolution_clock::now()
//caculate time
template<typename F, typename... Args>
double funcTime(F func, Args&&... args)
{
    TimeVar t1=timeNow();
    func(std::forward<Args>(args)...);
    return duration(timeNow()-t1);
}

//SelectionSort Function
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
void selectionSort(int sortArr[], int j)
{
    int w, p, min_index;
    // One by one move boundary of unsorted subarray
    for (w = 0; w < j-1; w++)
    {
        // Find the minimum element in unsorted array
        min_index = w;
        for (p = w+1; p < j; p++)
        if (sortArr[p] < sortArr[min_index])
            min_index = p;
 
        // Swap the found minimum element with the first element
        swap(&sortArr[min_index], &sortArr[w]);

        //print array
        cout << sortArr[w] << " ";
        cout << endl;
    }
}

//BubbleSort Function
void bubbleSort(int sortArr[], int n)
{
    int i, j;
   bool swapped;
   for (i = 0; i < n-1; i++)
   {
     swapped = false;
     for (j = 0; j < n-i-1; j++)
     {
        if (sortArr[j] > sortArr[j+1])
        {
           swap(&sortArr[j], &sortArr[j+1]);
           swapped = true;
        }
     }
 
     // IF no two elements were swapped by inner loop, then break
     if (swapped == false)
        break;
   }
                cout <<" "<< sortArr[i];
                cout <<" \n";
}

//InsertionSort Function
/* Function to sort an array using insertion sort*/
void insertionSort(int sortArr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = sortArr[i];
        j = i - 1;
 
        /* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
        while (j >= 0 && sortArr[j] > key)
        {
            sortArr[j + 1] = sortArr[j];
            j = j - 1;
        }
        sortArr[j + 1] = key;
        cout << sortArr[i] << " ";
        cout << endl;
    }
}

//MergeSort Function
// merge function take two intervals
// one from start to mid
// second from mid+1, to end
// and merge them in sorted order
void swapin(int &a, int &b) {     //swap the content of a and b
   int temp;
   temp = a;
   a = b;
   b = temp;
}


void merge(int *sortArr, int start, int mid, int end) {
	// create a temp array
	int temp[end - start + 1];

	// crawlers for both intervals and for temp
	int i = start, j = mid+1, k = 0;

	// traverse both arrays and in each iteration add smaller of both elements in temp 
	while(i <= mid && j <= end) {
		if(sortArr[i] <= sortArr[j]) {
			temp[k] = sortArr[i];
			k += 1; i += 1;
		}
		else {
			temp[k] = sortArr[j];
			k += 1; j += 1;
		}
	}

	// add elements left in the first interval 
	while(i <= mid) {
		temp[k] = sortArr[i];
		k += 1; i += 1;
	}

	// add elements left in the second interval 
	while(j <= end) {
		temp[k] = sortArr[j];
		k += 1; j += 1;
	}

	// copy temp to original interval
	for(i = start; i <= end; i += 1) {
		sortArr[i] = temp[i - start];
	}

}

// sortArr is an array of integer type
// start and end are the starting and ending index of current interval of sortArr

void mergeSort(int *sortArr, int start, int end) {

	if(start < end) {
		int mid = (start + end) / 2;
		mergeSort(sortArr, start, mid);
		mergeSort(sortArr, mid+1, end);
		merge(sortArr, start, mid, end);
	}

    int n;
    for(int i = 0; i<n; i++) 
    {
      cout << sortArr[i] << " ";
    }
}

//Quicksort Function
void swa(int *xp, int *yp)
{
    int tem = *xp;
    *xp = *yp;
    *yp = tem;
}
 
/* This function takes last element as pivot, places 
the pivot element at its correct position in sorted 
array, and places all smaller (smaller than pivot) 
to left of pivot and all greater elements to right 
of pivot */
int partition (int sortArr[], int low, int high) 
{ 
    int pivot = sortArr[high]; // pivot 
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far
  
    for (int j = low; j <= high - 1; j++) 
    { 
        // If current element is smaller than the pivot 
        if (sortArr[j] < pivot) 
        { 
            i++; // increment index of smaller element 
            swa(&sortArr[i], &sortArr[j]); 
        } 
    } 
    swa(&sortArr[i + 1], &sortArr[high]); 
    return (i + 1); 

    cout << sortArr[i] << " "; 
    cout << endl; 
} 
  
/* The main function that implements QuickSort 
arr[] --> Array to be sorted, 
low --> Starting index, 
high --> Ending index */
void quickSort(int sortArr[], int low, int high) 
{ 
    if (low < high) 
    { 
        /* pi is partitioning index, arr[p] is now 
        at right place */
        int pi = partition(sortArr, low, high); 
  
        // Separately sort elements before 
        // partition and after partition 
        quickSort(sortArr, low, pi - 1); 
        quickSort(sortArr, pi + 1, high); 
    } 
} 
  
 

//Function to show entirees
void showEntries(int Entries, int sortArr[])
{
    for(int i = 0; i < Entries; i++)
    {
        cout << sortArr[i] << '\t';
        if (!(i %10))
        {
            //cout << endl;
        }

    }
}

//program to store integers
//noOfEn stores number of entries
void readfile(char testdata[], int storage[], int &noOfEn)
{
    //create object of ifstream
    ifstream TD(testdata);

    TD >> noOfEn;

    //store entries in array using loop
    for(int i = 0; i < noOfEn; i++)
    {
        TD >> storage[i];
    }

}

int main()
{
    int n;
    int count, stor[100];
    char testdata[]={"testdata.txt"};
    readfile(testdata, stor, count);
    showEntries(count, stor);
    //system("read");

    cout << " " << endl;
    cout << " " << endl;
    cout << " Selection Sort " << endl;
    
    selectionSort(stor, count);

    cout << " " << endl;
    cout << " " << endl;
    cout << " Bubble Sort " << endl;

    bubbleSort(stor, count);

    cout << " " << endl;
    cout << " " << endl;
    cout << " Insertion Sort " << endl;

    insertionSort(stor, count);

    cout << " " << endl;
    cout << " " << endl;
    cout << " Merge Sort " << endl;

    mergeSort(stor, 0, count);

    cout << " " << endl;
    cout << " " << endl;
    cout << " Quick Sort " << endl;
    
    quickSort(stor, 0, count);

    cout << " " << endl;
    cout << " " << endl;

    
    ofstream myfile;
    myfile.open ("SORTDATA.txt");
    myfile<< "selection sort" <<funcTime(selectionSort, stor, count)<<"\n";
    myfile<< "bubble sort" <<funcTime(bubbleSort, stor, count)<<"\n";
    myfile<< "insertion sort" <<funcTime(insertionSort, stor, count)<<"\n";
    myfile<< "merge sort sort" <<funcTime(mergeSort, stor, 0, count)<<"\n";
    myfile<< "quick sort" <<funcTime(quickSort, stor, 0, count)<<"\n";
    myfile.close();
    
    

    return 0;
}
