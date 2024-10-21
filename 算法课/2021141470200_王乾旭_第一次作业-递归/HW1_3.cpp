#include <iostream>
#include <vector>

using namespace std;

// 辅助函数：合并两个有序数组并统计跨越两部分的逆序对
int mergeAndCount(vector<int>& arr, vector<pair<int, int>>& inversions, vector<int>& temp, int left, int mid, int right) {
    int i = left;    // 左半部分的起始索引
    int j = mid + 1; // 右半部分的起始索引
    int k = left;    // 临时数组的索引
    int invCount = 0;

    // 合并两个有序部分，并统计逆序对
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            invCount += (mid - i + 1);  // 统计逆序对数量
            for (int p = i; p <= mid; ++p) {
                inversions.push_back({arr[p], arr[j - 1]});  // 记录逆序对
            }
        }
    }

    // 复制剩余的左半部分
    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    // 复制剩余的右半部分
    while (j <= right) {
        temp[k++] = arr[j++];
    }

    // 将临时数组复制回原数组
    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }

    return invCount;
}

// 辅助函数：分治递归统计逆序对
int mergeSortAndCount(vector<int>& arr, vector<pair<int, int>>& inversions, vector<int>& temp, int left, int right) {
    int invCount = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;

        // 递归统计左半部分的逆序对
        invCount += mergeSortAndCount(arr, inversions, temp, left, mid);

        // 递归统计右半部分的逆序对
        invCount += mergeSortAndCount(arr, inversions, temp, mid + 1, right);

        // 统计跨越两部分的逆序对
        invCount += mergeAndCount(arr, inversions, temp, left, mid, right);
    }
    return invCount;
}

// 主函数：统计数组中的逆序对
int countInversions(vector<int>& arr) {
    vector<int> temp(arr.size());
    vector<pair<int, int>> inversions;  // 用于存储所有逆序对
    int invCount = mergeSortAndCount(arr, inversions, temp, 0, arr.size() - 1);

    // 打印所有逆序对
    cout << "Reverse Numer pair: " << endl;
    for (auto inv : inversions) {
        cout << "<" << inv.first << ", " << inv.second << ">" << endl;
    }

    return invCount;
}

int main() {
    vector<int> arr = {6, 3, 1, 4, 8, 10, 18, 9, 5, 2, 35};

    int result = countInversions(arr);
    cout << "Number of Reverse Numbers : " << result << endl;

    return 0;
}
