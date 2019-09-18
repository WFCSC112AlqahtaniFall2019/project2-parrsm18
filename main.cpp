#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;

// function declarations
void mergeSort(vector<int>& a, vector<int>& tmp, int left, int right);
void mergeSortedLists(vector<int>& a, vector<int>& tmp, int left, int middle, int right);

int main() {

    // get input: first is random seed, second is vector length
    int seed, length;
    cin >> seed >> length;
    srand(seed);

    vector<int> v(length);  // vector to be sorted
    vector<int> t(length);  // temporary workspace
    // unit test for merge


    /* your code here */


    // initialize and print input
    for(int i = 0; i < v.size(); i++) {
        v.at(i) = rand() % 100;
        cout << v.at(i) << '\t';
    }
    cout << endl;

    // sort v
    mergeSort(v, t,0, v.size() - 1);

    // print output
    for(int i = 0; i < v.size(); i++) {
        cout << v.at(i) << '\t';
    }
    cout << endl;

    // check output, make sure it's sorted
    for(int i = 1; i < v.size(); i++) {
        assert (v.at(i-1) <= v.at(i));
    }

    return 0;
}
// Merge Sort divides up into smaller
// mergesortedlists adds them up together

void mergeSort(vector<int>& a, vector<int>& tmp, int left, int right){
    if (right <= left){
        return;
    }
    else {
        int midpoint = (right + left) / 2;
        mergeSort(a, tmp, left, midpoint);
        mergeSort(a, tmp, midpoint + 1, right);
        mergeSortedLists(a, tmp, left, midpoint, right);

    }
}

void mergeSortedLists(vector<int>& a, vector<int>& tmp, int left, int middle, int right){
    int temp = left;
    int tempLeft = left;
    int tempRight = middle + 1;
    while (tempLeft <= middle && tempRight <= right){
        if(a.at(tempLeft) > a.at(tempRight)){
            tmp.at(temp) = a.at(tempRight);
            temp++;
            tempRight++;
        }
        else {
            tmp.at(temp) = a.at(tempLeft);
            temp++;
            tempLeft++;
        }
    }
    while (tempRight <= right){
        tmp.at(temp) = a.at(tempRight);
        temp++;
        tempRight++;
    }
    while (tempLeft <= middle){
        tmp.at(temp) = a.at(tempLeft);
        temp++;
        tempLeft++;
    }
    for (int i = left; i <= right; i++){
        a.at(i) = tmp.at(i);
    }
}

/* your code here */
