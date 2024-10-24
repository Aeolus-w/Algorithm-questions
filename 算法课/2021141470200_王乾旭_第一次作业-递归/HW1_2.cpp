#include <iostream>
#include <vector>
#include <sstream>  
#include <cstdlib> 
#include <ctime>   

using namespace std;

void swap(vector<int>& arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(vector<int>& arr, int left, int right) {
    int pivotIndex = left + rand() % (right - left + 1);  
    int pivot = arr[pivotIndex];
    swap(arr, pivotIndex, right); 
    
    int i = left;  
    for (int j = left; j < right; ++j) {
        if (arr[j] < pivot) {
            swap(arr, i, j);
            ++i;
        }
    }
    swap(arr, i, right);  
    return i;  
}


void quickSelect(vector<int>& arr, int left, int right, int k) {
    if (left < right) {
        int pivotIndex = partition(arr, left, right);
        if (pivotIndex == k) {
            return;  
        } else if (pivotIndex < k) {
            quickSelect(arr, pivotIndex + 1, right, k);  
        } else {
            quickSelect(arr, left, pivotIndex - 1, k);  
        }
    }
}

vector<int> smallestKNumbers(vector<int>& arr, int k) {
    srand(time(0));  // 随机种子
    quickSelect(arr, 0, arr.size() - 1, k); 
    return vector<int>(arr.begin(), arr.begin() + k); 
}

vector<int> parseInputArray(string input) {
    vector<int> arr;
    stringstream ss(input);
    int number;
    while (ss >> number) {
        arr.push_back(number);  
    }
    return arr;
}

int main() {
    string input;
    cout << "Input arr: （只打数字，用空格隔开）";
    getline(cin, input);

    vector<int> arr = parseInputArray(input);

    int k;
    cout << "Input k: ";
    cin >> k;

    vector<int> ans = smallestKNumbers(arr, k);

    cout << "min " << k << " nums: ";
    for (int num : ans) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
