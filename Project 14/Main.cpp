#include <iostream>
#include <ctime>
#include <thread>
#include <chrono>
#include <algorithm>
#include "Vector.h"
#include "Random.h"
#include "Sort.h"
using namespace std;

template <typename T>
void print_vector(const Vector<T>&);

int main()
{
    Vector<int> nums1;
    Vector<int> ascending1, ascending2;
    Vector<int> descending1, descending2;
    
    for (int i = 1; i <= 1024; i++)
    {
        ascending1.push_back(2 * i);
        ascending2.push_back(2 * i);
    }

    for (int i = 1024; i > 0; i--)
    {
        descending1.push_back(3 * i);
        descending2.push_back(3 * i);
    }

    cout << "Before sorting: ";
    print_vector(ascending1);
    cout << endl;
    int ops1, ops2;

    insertionSort(ascending1, ops1);
    selectionSort(ascending2, ops2);

    cout << "After sorting (IS): ";
    print_vector(ascending1);
    cout << "After sorting (SS): ";
    print_vector(ascending2);
    cout << endl;
    cout << "insertionSOrt on 25 ASCENDING values: " << ops1 << endl;
    cout << "selectionSort on 25 ASCENDING values: " << ops2 << endl;
    cout << endl;

    cout << "Before sorting: ";
    print_vector(descending1);
    cout << endl;

    insertionSort(descending1, ops1);
    selectionSort(descending2, ops2);

    cout << "After sorting (IS): ";
    print_vector(descending1);
    cout << "After sorting (SS): ";
    print_vector(descending2);
    cout << "insertionSOrt on 25 DESCENDING values: " << ops1 << endl;
    cout << "selectionSort on 25 DESCENDING values: " << ops2 << endl;
    cout << endl << endl;

    for (int i = 1; i <= 10; i++)
    {
        nums1.clear();
        rand_seed();
        random_vector(25, 1, 500, nums1, 0);
        Vector<int> nums2(nums1);

        cout << endl;
        cout << "RANDOM sequences before sorting: " << endl;
        print_vector(nums1);
        cout << endl;

        insertionSort(nums1, ops1);
        selectionSort(nums2, ops2);

        cout << "After sorting: ";
        print_vector(nums1);
        print_vector(nums2);
        cout << endl;
        cout << "insertionSort on thse 25 values: " << ops1 << endl;
        cout << "selectionSort on these 25 values: " << ops2 << endl;

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}

template <typename T>
void print_vector(const Vector<T>& vec)
{
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    cout << endl;
    return;
}