// Steven Parrill 

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
    cout << "Enter seed value and length of array." << endl;
    cin >> seed >> length;
    srand(seed);

    vector<int> v(length);  // vector to be sorted
    vector<int> t(length);  // temporary workspace

    // unit test for merge
    vector <int> a{10,4,6,1};
    vector <int> b(4);
    mergeSort(a,b,0,a.size()-1);
    for(int i = 1; i < v.size(); i++) {
        assert (v.at(i-1) <= v.at(i));
    }

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
    if (right <= left){ //Base case
        return;
    }
    else {
        int midpoint = (right + left) / 2;
        mergeSort(a, tmp, left, midpoint); // Sorts the left half of list
        mergeSort(a, tmp, midpoint + 1, right); // Sorts the right half of list
        mergeSortedLists(a, tmp, left, midpoint, right); // Merges list back together
    }
}

void mergeSortedLists(vector<int>& a, vector<int>& tmp, int left, int middle, int right){
    int temp = left;
    int tempLeft = left;
    int tempRight = middle + 1;
    while (tempLeft <= middle && tempRight <= right){ // Sorts both halves of list
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
    while (tempRight <= right){ // Sorts remainder of right side of list
        tmp.at(temp) = a.at(tempRight);
        temp++;
        tempRight++;
    }
    while (tempLeft <= middle){ // Sorts remainder of left side of list
        tmp.at(temp) = a.at(tempLeft);
        temp++;
        tempLeft++;
    }
    for (int i = left; i <= right; i++){ // Copies the sorted vector in temp to a
        a.at(i) = tmp.at(i);
    }
}