#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 辅助函数：合并两个升序链表
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (!l1) return l2;
    if (!l2) return l1;

    if (l1->val < l2->val) {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    } else {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}

// 辅助函数：递归地合并链表
ListNode* mergeKListsHelper(vector<ListNode*>& lists, int left, int right) {
    if (left == right) {
        return lists[left];  // 只有一个链表时，直接返回
    }

    int mid = left + (right - left) / 2;
    ListNode* l1 = mergeKListsHelper(lists, left, mid);     // 合并左边的链表
    ListNode* l2 = mergeKListsHelper(lists, mid + 1, right); // 合并右边的链表

    return mergeTwoLists(l1, l2); // 合并左右两部分
}

// 分治合并 k 个链表
ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.empty()) return nullptr;
    return mergeKListsHelper(lists, 0, lists.size() - 1);
}

// 辅助函数：打印链表
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// 辅助函数：将二维数组转换为链表
ListNode* arrayToList(const vector<int>& arr) {
    if (arr.empty()) return nullptr;

    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;

    for (size_t i = 1; i < arr.size(); ++i) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }

    return head;
}

// 辅助函数：从字符串解析成二维数组
vector<vector<int>> parseInput(const string& input) {
    vector<vector<int>> result;
    stringstream ss;
    bool inArray = false;
    vector<int> currentList;
    
    for (char ch : input) {
        if (isdigit(ch) || ch == '-') {
            ss << ch;  // 将数字字符放入缓冲区
        } else if (ch == ',' || ch == ']') {
            if (!ss.str().empty()) {
                currentList.push_back(stoi(ss.str()));  // 将缓冲区中的数字转换为整数并加入当前列表
                ss.str("");  // 清空缓冲区
                ss.clear();
            }
            if (ch == ']') {
                result.push_back(currentList);  // 完成一个列表的读取
                currentList.clear();
            }
        }
    }
    return result;
}

int main() {
    // 从终端输入读取二维数组
    string input;
    cout << "Input:" << endl;
    getline(cin, input);

    // 解析输入为二维数组
    vector<vector<int>> parsedInput = parseInput(input);

    // 将二维数组转换为链表数组
    vector<ListNode*> lists;
    for (const auto& arr : parsedInput) {
        lists.push_back(arrayToList(arr));
    }

    // 合并链表
    ListNode* result = mergeKLists(lists);

    // 打印合并后的链表
    printList(result);

    return 0;
}
