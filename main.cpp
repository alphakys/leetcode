//
//
//class BinarySearch {
//public:
//    int search(vector<int> &nums, int target) {
//
//        int len = nums.size();
//        int first = 0;
//        int end = len;
//        int pivot = (first + end) / 2;
//        int answer = 0;
//
//        while (first <= pivot) {
//            cout << "first : " << first << " pivot : " << pivot << " end : " << end << endl;
//            if (first == pivot && nums[pivot] != target) {
//                answer = -1;
//                break;
//            }
//            if (nums[pivot] < target) {
//                first = pivot + 1;
//                pivot = (first + end) / 2;
//            } else if (nums[pivot] == target) {
//                answer = pivot;
//                break;
//            } else {
//                end = pivot;
//                pivot = (first + end) / 2;
//            }
//
//        }
//        return answer;
//    }
//
//    int binarysearch2(int arr[], int n, int k) {
//        // code here
//        int r = n-1;
//        int l = 0;
//        int mid = l + (r-l)/2;
//
//        while(true){
//            if(l>r or r<l){ return -1;}
//
//            if(arr[mid] > k){
//                r = mid-1;
//                mid = l + (r-l)/2;
//            }else if (arr[mid] == k){ return mid; }
//            else{
//                l = mid+1;
//                mid = l + (r-l)/2;
//            }
//        }
//
//    }
//};
//
//
//class FirstBadVersion {
//public:
//    int search(vector<int> &nums, int n) {
//
//        int first = 0;
//        int end = n;
//
//        int pivot = n - 1;
//
//        while (first <= pivot) {
//            cout << "first : " << first << " pivot : " << pivot << " end : " << end << endl;
//
//            //if(first==pivot ){ break;}
//            if (nums[pivot] == 1 && nums[pivot - 1] == 1) {
//                end = pivot - 1;
//                pivot = (first + end) / 2;
//
//            } else if (nums[pivot] == 1 && nums[pivot - 1] == 0) {
//                //1과 end 사이에서 마지막 0을 찾아야함
//                //그리고 현재까지는 가장 작은 1이 end임을 알 수 있다. 하지만 더 작은 1이 있을 수 있으니 찾아야함
////            first = pivot+1;
////            pivot = (first + end)/2;
//                cout << pivot;
//                break;
//            } else if (nums[pivot] == 0 && nums[pivot + 1] == 0) {
//
//                first = pivot + 1;
//                pivot = (first + end) / 2;
//                //break;
//            } else {
//                cout << pivot + 1;
//                break;
//            }
//
//        }
//    }
//};
//
//
//class SearchInsertPosition {
//public:
//    int search(vector<int> &nums, int n) {
//
//        int end = nums.size() - 1;
//        int first = 0;
//        int target = 2;
//        int pivot = end;
//        int answer = 0;
//
//        if (target < nums[0]) { answer = 0; }
//        else if (target > nums[end]) { answer = end; }
//
//        while (first <= pivot) {
//            cout << "first : " << first << " pivot : " << pivot << " end : " << end << endl;
//
//            if (first == pivot && nums[pivot] != target) {
//                answer = end;
//                break;
//            }
//
//            if (nums[pivot] < target) {
//                first = pivot;
//                pivot = (first + end) / 2;
//
//            } else if (nums[pivot] == target) {
//                answer = pivot;
//                break;
//            } else if (nums[pivot] > target) {
//                end = pivot;
//                pivot = (first + end) / 2;
//
//            }
//
//        }
//
//        cout << "answer : " << answer;
//    }
//};
//
//class MergeSort {
//public:
//    int temp[100001] = {0,};
//
//    void conquer(int left, int mid, int right, vector<int> &nums) {
//
//        int idx = left;
//        int pivot = mid + 1;
//        int i = left;
//
//        if (left == right) {
//            temp[idx] = nums[left];
//            return;
//        }
//        while (idx < right) {
//
//            if (nums[left] > nums[pivot]) {
//                if (pivot < right) {
//                    temp[idx++] = nums[pivot];
//                    pivot++;
//                }
//                else {
//                    temp[idx++] = nums[pivot];
//                    for (; left <= mid; ++left) {
//                        temp[idx++] = nums[left];
//
//                    }
//
//                }
//
//            } else {
//                if (left < mid) {
//                    temp[idx++] = nums[left];
//                    left++;
//                }
//                else {
//                    temp[idx++] = nums[left];
//                    for (; pivot <= right; ++pivot) {
//                        temp[idx++] = nums[pivot];
//
//                    }
//                }
//
//            }
//        }
//
//        for (; i <= right; i++) {
//            nums[i] = temp[i];
//        }
//    }
//
//    void mergeSort(int left, int mid, int right, vector<int> &nums) {
//
//        if (left < mid) {
//            mergeSort(mid + 1, ((mid + 1) + right) / 2, right, nums);
//            mergeSort(left, (left + mid) / 2, mid, nums);
//
//        }
//        conquer(left, mid, right, nums);
//
//    }
//};
//
//
//class RotateArray {
//public:
//    int search(vector<int> &nums, int n) {
//
//        int len = nums.size();
//
//        vector<int> arr(len, 0);
//        int k = 2;
//
//        for (int i = 0; i < len; i++) {
//            int target_idx = i + k;
//            if (target_idx > (len - 1)) {
//                target_idx = target_idx % len;
//                arr[target_idx] = nums[i];
//            }
//            else { arr[target_idx] = nums[i]; }
//        }
//        //printList(arr); cout << endl;
//        nums = arr;
//
//    }
//};
//
//
//class MoveZeroes {
//public:
//    int search(vector<int> &nums, int n) {
//
//        int len = nums.size();
//        int zero_cnt = 0;
//        int idx = 0;
//
//        for (int i = 0; i < len; i++) {
//            cout << "i : " << i << endl;
//            if (nums[i] == 0) {
//                zero_cnt++;
//                continue;
//            }
//
//            if (i == len - 1) { nums[idx++] = nums[i]; }
//
//            for (int j = i + 1; j < len; ++j) {
//
//                if (nums[j] == 0) {
//                    zero_cnt++;
//                    continue;
//                } else if (nums[i] > nums[j]) {
//                    nums[idx++] = nums[j];
//                } else {
//                    nums[idx++] = nums[i];
//                    i = --j;
//                    break;
//                }
//            }
//            //printList(nums); cout << endl;
//        }
//
//        for (; idx < len; ++idx) {
//            nums[idx] = 0;
//        }
//        //printList(nums); cout << endl;
//
//        cout << zero_cnt << ", " << idx;
//
//
//    }
//};
//
//
//void printList(vector<int> &nums) {
//    int len = nums.size();
//
//    for (int i = 0; i < len; i++) {
//        cout << nums[i] << ' ';
//    }
//
//}
//
//void printArray(int arr[], int len) {
//
//    for (int i = 0; i < len; i++) {
//        cout << arr[i] << ' ';
//    }
//
//}
//
//int square(int num, int multiple) {
//
//    int value = 1;
//
//    for (int i = 0; i < multiple; i++) {
//        value = value * num;
//    }
//    return value;
//}
//
//class QuickSort {
//public:
//
//    void swap(int a, int b, vector<int> &nums) {
//        int tmp = nums[a];
//        nums[a] = nums[b];
//        nums[b] = tmp;
//    }
//
//    int quickConquer(int l, int r, vector<int> &nums) {
//
//        int right_most = r - 1;
//
//        for (; l < right_most;) {
//
//            if (nums[l] > nums[r]) {
//                if (nums[right_most] < nums[r]) {
//
//                    swap(l, right_most, nums);
//
//                } else {
//                    right_most--;
//                    continue;
//                }
//
//            } else {
//                if (nums[right_most] < nums[r]) {
//                    l++;
//                    continue;
//                }
//            }
//            l++;
//            right_most--;
//
//        }
//        //printList(nums); cout << endl;
//        if (nums[r] < nums[l]) { swap(r, l, nums); }
//        return l;
//    }
//
//    void quickDivide(int l, int r, vector<int> &nums) {
//        int mid = quickConquer(l, r, nums);
//        if (l == r) { return; }
//
//        if (l < mid) {
//            quickDivide(l, mid, nums);
//            quickDivide(mid + 1, r, nums);
//        } else if (l == mid) { quickDivide(mid + 1, r, nums); }
//        else if (r == mid) { quickDivide(l, mid, nums); }
//
//    }
//
//};
//
//
//class MoveToZeroes {
//public:
//
//    void swap(int a, int b, vector<int> &nums) {
//        int tmp = nums[a];
//        nums[a] = nums[b];
//        nums[b] = tmp;
//    }
//
//    // 0   1  2  3  4  5  6  7  8  9  10 11 12
//    //{0, 56, 5, 0, 0, 3, 2, 0, 6, 8, 0, 45, 1};
//    //{56, 0, 5, 0, 0, 3, 2, 0, 6, 8, 0, 45, 1};
//    int quickConquer(int l, int r, vector<int> &nums) {
//
//        int left_most = l + 1;
//
//        for (; left_most < r;) {
//            printf("[left_most -> %d, v -> %d], [r -> %d, v -> %d]\n", left_most, nums[left_most], r, nums[r]);
//            cout << "전 : ";
//            printList(nums);
//            cout << endl;
//            if (nums[left_most] == 0) {
//
//                if (nums[r] != 0) {
//
//                    swap(r, left_most, nums);
//                    left_most++, r--;
//                    //printList(nums); cout << endl;
//                } else { r--; }
//                cout << "후 : ";
//                printList(nums);
//                cout << endl;
//                continue;
//            }
//
//            if (nums[left_most] > nums[l]) {
//                if (nums[l] < nums[r]) {
//                    if (nums[left_most] != 0) { r--; }
//                    else {
//                        swap(r, left_most, nums);
//                        r--;
//                        //continue;
//                    }
//
//                } else {
//                    swap(r, left_most, nums);
//                    left_most++;
//                    r--;
//                    //continue;
//                }
//
//            } else {
//                if (nums[r] == 0) {
//                    r--;
//                    continue;
//                }
//
//                if (nums[r] < nums[l]) {
//                    left_most++;
//                    //continue;
//                } else {
//                    left_most++;
//                    r--;
//                }
//            }
//            //
//            cout << "후 : ";
//            printList(nums);
//            cout << endl;
//            //break;
//        }
//
//        if (nums[left_most] < nums[l]) {
//            if (nums[left_most] != 0) { swap(left_most, l, nums); }
//        }
//        //cout << left_most;
//        return left_most;
//    }
//
//    void quickDivide(int l, int r, vector<int> &nums) {
//        int mid = quickConquer(l, r, nums);
//
//        if (mid == r) { return; }
//
//        if (l < mid) {
//            if (nums[l] != 0) { quickDivide(l, mid, nums); }
//            //quickDivide(l, mid, nums);
//            if (nums[mid + 1] != 0) { quickDivide(mid + 1, r, nums); }
//            //quickDivide(mid+1, r, nums);
//        } else if (l == mid) { if (nums[mid + 1] != 0) { quickDivide(mid + 1, r, nums); }}
//        else if (r == mid) { if (nums[l] != 0) { quickDivide(l, mid, nums); }}
//
//    }
//
//};
//
//
//void swap(int a, int b, vector<int> &nums) {
//    int tmp = nums[a];
//    nums[a] = nums[b];
//    nums[b] = tmp;
//}
//
//
//class TwoSumII {
//public:
//
//    void solution() {
//        vector<int> numbers = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
//        int l = 0;
//        int r = numbers.size() - 1;
//        int target = 2;
//
//        vector<int> answer(2);
//
//        while (l < r) {
//            if (numbers[l] + numbers[r] > target) { r--; }
//            else if (numbers[l] + numbers[r] == target) {
//                answer[0] = l + 1;
//                answer[1] = r + 1;
//                break;
//            }
//            else { l++; }
//
//        }
//        printList(answer);
//    }
//
//};
//
//
//class ReverseWordsinaStringIII {
//public:
//
//    void solution() {
//        string s = "sdf ffff 3w wer4 dfssdfdsfds";
//
//        int len = s.size();
//        int idx = 0;
//        int l = 0;
//        char tmp = NULL;
//        int r;
//        while (idx < len) {
//            if (s[idx] == 32 or s[idx] == 32) {
//
//                r = idx - 1;
//                for (; l <= r; l++, r--) {
//                    tmp = s[l];
//                    s[l] = s[r];
//                    s[r] = tmp;
//                }
//                l = idx + 1;
//            };
//            idx++;
//        }
//
//        r = len - 1;
//
//        for (; l < r; l++, r--) {
//
//            tmp = s[l];
//            s[l] = s[r];
//            s[r] = tmp;
//        }
//
//    }
//
//};
//
//
//class ReverseString {
//public:
//
//    void solution() {
//        vector<char> s = {'H', 'a', 'n', 'n', 'a', 'h'};
//
//        int len = s.size();
//        int l = 0;
//        int r = s.size() - 1;
//
//        char tmp = NULL;
//        for (; l < r; l++, r--) {
//            tmp = s[l];
//            s[l] = s[r];
//            s[r] = tmp;
//        }
//
//        for (int i = 0; i < len; ++i) {
//            cout << s[i];
//        }
//
//    }
//
//};
//
//
//struct ListNode {
//    int val;
//    ListNode *next;
//
//    ListNode() : val(0), next(nullptr) {}
//
//    ListNode(int x) : val(x), next(nullptr) {}
//
//    ListNode(int x, ListNode *next) : val(x), next(next) {}
//} *start;
//
//
//typedef struct Node {
//    int data;
//    struct Node *next;
//
//    Node(int x) {
//        data = x;
//        next = nullptr;
//    }
//
//} Node;
//
//
//class LinkedList {
//
//private:
//    Node *head;
//
//public:
//    LinkedList() { head = nullptr; }
//
//    //Function to insert a node in the middle of the linked list.
//    Node *insertInMiddle(Node *head, int x) {
//        // Code here
//        int cnt = getCount(head);
//
//        int middle = (cnt / 2) + (cnt % 2);
//
//        Node *curr = head;
//        Node *prevNode;
//
//        while (curr != nullptr && middle > 0) {
//            prevNode = curr;
//            curr = curr->next;
//            middle--;
//        }
//
//        Node *n = new Node(x);
//        prevNode->next = n;
//        n->next = curr;
//        return head;
//
//    }
//
//    Node *insertAtBegining(Node *head, int x) {
//        // Your code here
//        if (head == nullptr) {
//            head = new Node(x);
//            return head;
//        }
//        else {
//            Node *n = new Node(x);
//            n->next = head;
//            return n;
//        }
//
//    }
//
//    //Function to insert a node at the end of the linked list.
//    Node *insertAtEnd(int x) {
//        // Your code here
//        if (head == nullptr) {
//            head = new Node(x);
//            return head;
//        }
//        else {
//
//            Node *curr = head;
//            while (curr->next != nullptr) {
//                curr = curr->next;
//            }
//            curr->next = new Node(x);
//
//            return head;
//        }
//
//    }
//
//    int getCount(struct Node *head) {
//
//        int len = 1;
//
//        Node *n = head;
//        while (n->next != nullptr) {
//            n = n->next;
//            len++;
//        }
//        return len;
//    }
//
//    void display() {
//        Node *n = head;
//        while (n != nullptr) {
//            printf("%d ", n->data);
//            n = n->next;
//        }
//
//    }
//
//    int GetNth(struct Node *head, int index) {
//        // Code here
//
//        Node *curr = head;
//        index--;
//        while (curr != nullptr) {
//            if (index == 0) {
//                return curr->data;
//            } else {
//                curr = curr->next;
//                index--;
//
//            }
//        }
//
//
//    }
//
//    int isLengthEvenOrOdd(struct Node *head) {
//        //Code here
//        return (getCount(head) % 2);
//    }
//
//
//    int sumOfLastN_Nodes(struct Node *head, int n) {
//        // Code here
//        Node *curr = head;
//        vector<int> arr;
//
//        while (curr != nullptr) {
//            arr.push_back(curr->data);
//            curr = curr->next;
//        }
//
//        int len = arr.size();
//
//        int sum = 0;
//
//        for (int i = len - 1; n-- > 0; i--) {
//            sum += arr[i];
//        }
//
//        return sum;
//    }
//
//    int fractional_node(struct Node *head, int k) {
//        // your code here
//        int element = ceil((double) getCount(head) / (double) k);
//
//        Node *curr = head;
//        while (element-- > 1) {
//
//            curr = curr->next;
//        }
//
//        return curr->data;
//    }
//
//    int modularNode(int k) {
//        // Code here
//        Node *n = head;
//        int result = NULL;
//
//        int index = 1;
//        while (n != nullptr) {
//            //cout << n->data/k << " " << n->data << " "<< n->data%k << endl;
//            if (index++ % k == 0) {
//                result = n->data;
//            }
//            n = n->next;
//        }
//
//        if (result == NULL) {
//            return -1;
//        } else {
//            return result;
//        }
//
//    }
//
//
//    void stackPush(int x) {
//        // Your Code
//        Node *n = head;
//
//        if (n == nullptr) {
//            n = new Node(x);
//            head = n;
//
//        } else {
//            while (n->next != nullptr) {
//                n = n->next;
//            }
//
//            n->next = new Node(x);
//
//        }
//
//    }
//
//    //Function to remove an item from top of the stack.
//    int stackPop() {
//        Node *n = head;
//
//        if (n == nullptr) {
//            return -1;
//        } else {
//            Node *prevNode = nullptr;
//            while (n->next != nullptr) {
//                prevNode = n;
//                n = n->next;
//            }
//
//            int answer = n->data;
//            if (prevNode == nullptr) {
//                head = nullptr;
//                return answer;
//            } else {
//                prevNode->next = nullptr;
//                delete prevNode->next;
//            }
//
//
//            return answer;
//        }
//
//    }
//
//    bool detectLoop(Node *head) {
//        // your code here
//        Node *curr = head;
//
//        unordered_set<Node *> s;
//        s.insert(head);
//        while (curr->next != nullptr) {
//
//            curr = curr->next;
//            if (!s.insert(curr).second) { return true; }
//        }
//
//        return false;
//    }
//
//    int getNthFromLast(Node *head, int n) {
//        // Your code here
//        int len = 0;
//        Node *curr = head;
//        while (head->next != nullptr) {
//            head = head->next;
//            len++;
//        }
//
//        if (len - n + 1 < 0)
//            return -1;
//
//        int i = 0;
//        while (i++ < len - n + 1) {
//            curr = curr->next;
//        }
//
//        return curr->data;
//
//    }
//
//    int getMiddle(Node *head) {
//        // Your code here
//        // two pointer one pointer 이용한 방식(두 포인터가 리스트의 끝까지 도달하는 시간차를 이용한 공격)
//        Node *one_ptr = head;
//        Node *two_ptr = head->next;
//
//        while (two_ptr != nullptr && two_ptr->next != nullptr) {
//            one_ptr = one_ptr->next;
//            two_ptr = two_ptr->next->next;
//        }
//
//        if (two_ptr == nullptr)
//            return one_ptr->data;
//        else if (two_ptr->next == nullptr)
//            return one_ptr->next->data;
//
////            count 이용한 방식
////            int len = 1;
////            Node* curr = head;
////
////            while(head->next != nullptr){
////                len++;
////                head= head->next;
////            }
////
////            int idx = len/2;
////
////            int i= 0;
////
////            while(i++ < idx){
////                curr = curr->next;
////            }
////
////            return curr->data;
//
//
//    }
//
//
//};
//
//typedef struct DoubleNode {
//    int data;
//    struct DoubleNode *prev;
//    struct DoubleNode *next;
//
//    DoubleNode(int x) {
//        data = x;
//        next = nullptr;
//        prev = nullptr;
//    }
//
//} DoubleNode;
//
//
//class DoublyLinkedList {
//
//private:
//    DoubleNode *head;
//
//public:
//    DoublyLinkedList() { head = nullptr; }
//
//    DoublyLinkedList(int x) {
//        head = new DoubleNode(x);
//    }
//
//    void addNode(int pos, int data) {
//        // Your code here
//        if (pos == -1) {
//            if (head == nullptr) { head = new DoubleNode(data); }
//            else {
//                DoubleNode *curr = head;
//
//                while (curr->next != nullptr) {
//                    curr = curr->next;
//                }
//                DoubleNode *nextNode = curr->next = new DoubleNode(data);
//                nextNode->prev = curr;
//
//            }
//
//        } else {
//            DoubleNode *n = head;
//
//            while (pos-- > 0) {
//                n = n->next;
//            }
//            DoubleNode *next_swap_node = n->next;
//            n->next = new DoubleNode(data);
//            n->next->next = next_swap_node;
//            n->next->prev = n;
//        }
//
//    }
//
//    void display() {
//        DoubleNode *n = head;
//
//        while (n != nullptr) {
//
//            printf("%d ", n->data);
//            n = n->next;
//        }
//
//    }
//
//
//};
//
//
//class HashTable {
//
//
//public:
//    int numIdenticalPairs(vector<int> &nums) {
//
//        int arr[100] = {0,};
//
//        int len = nums.size();
//
//        for (int i = 0; i < len; ++i) {
//            arr[nums[i] - 1]++;
//        }
//
//        int sum = 0;
//        for (int i = 0; i < 10; ++i) {
//
//            int val = arr[i] - 1;
//            int sum_val = 0;
//            while (val > 0) {
//                sum_val += val--;
//
//            }
//            sum += sum_val;
//        }
//
//        return sum;
//    }
//
//    int numJewelsInStones(string jewels, string stones) {
//        int arr[58] = {0,};
//
//        int cnt = stones.size();
//        for (int j = 0; j < cnt; ++j) {
//            arr[stones[j] - 65]++;
//        }
//
//        int len = jewels.size();
//
//        int sum = 0;
//
//        for (int i = 0; i < len; ++i) {
//
//            sum += arr[jewels[i] - 65];
//        }
//
//        return sum;
//    }
//
//
//};
//
//typedef struct TreeNode {
//    int data;
//    TreeNode *left;
//    TreeNode *right;
//
//    TreeNode() {
//        left = nullptr;
//        right = nullptr;
//    }
//
//    TreeNode(int x) {
//        data = x;
//        left = nullptr;
//        right = nullptr;
//    }
//
//};
//
//class Tree {
//private:
//    TreeNode *root;
//
//public:
//
//    Tree() {
//        root = nullptr;
//    }
//
//    void insertNode() {
//
//    }
//
//    vector<int> levelOrder(Node *node) {
//        //Your code here
//    }
//
//    void preorder(TreeNode *root) {
//        TreeNode *parent = root;
//        TreeNode *l_child = parent->left;
//        TreeNode *r_child = parent->right;
//
//        printf("%d ", parent->data);
//
//        if (l_child != nullptr) { preorder(l_child); }
//
//        if (r_child != nullptr) { preorder(r_child); }
//
//    }
//
//    void inOrder(TreeNode *root) {
//
//        TreeNode *parent = root;
//        TreeNode *leftChild = parent->left;
//        TreeNode *rightChild = parent->right;
//
//        if (leftChild != nullptr) {
//            inOrder(leftChild);
//        }
//
//        printf("%d ", parent->data);
//
//        if (rightChild != nullptr) {
//            inOrder(rightChild);
//        }
//
//        // using stack!
////        vector<int> answer;
////
////        Node* l = root->left;
////        Node* r = root->right;
////
////        Stack s;
////
////        s.push(root);
////
////        Node* parent = root;
////
////        // while(l != nullptr){
////
////        //     if(l->right !=nullptr)
////        //         s.push(l->right);
////        //     s.push(l);
////        //     l = l->left;
////        // }
////
////        //Node* n = s.pop();
////
////        // while(n != nullptr){
////        //     cout << n->data << endl;
////
////        //     n = s.pop();
////        // }
////
////        while(r != nullptr){
////            s.push(r);
////            if(r->left !=nullptr)
////                s.push(r->left);
////
////            r = r->right;
////        }
////
////        Node* n = s.pop();
////
////        while(n != nullptr){
////            cout << n->data << " ";
////
////            n = s.pop();
////        }
////        // s.push(r->data);
////        // s.push(parent->data);
////        // s.push(l->data);
////
////        return answer;
//    }
//
//    void postOrder(TreeNode *root) {
//
//        TreeNode *parent = root;
//        TreeNode *leftChild = parent->left;
//        TreeNode *rightChild = parent->right;
//
//        if (leftChild != nullptr) {
//            postOrder(leftChild);
//        }
//
//        if (rightChild != nullptr) {
//            postOrder(rightChild);
//        }
//
//        printf("%d ", parent->data);
//
//    }
//
//    int countLeaves(TreeNode *root) {
//        // Your code here
//        TreeNode *parent = root;
//        TreeNode *l_child = parent->left;
//        TreeNode *r_child = parent->right;
//
//        int answer = 0;
//
//        if (l_child == nullptr and r_child == nullptr)
//            return 1;
//
//        if (l_child != nullptr) {
//            answer += countLeaves(l_child);
//        }
//
//        if (r_child != nullptr) {
//            answer += countLeaves(r_child);
//        }
//
//        return answer;
//
//    }
//
//    int getSize(TreeNode *node) {
//        // Your code here
//        TreeNode *parent = node;
//        TreeNode *l_child = parent->left;
//        TreeNode *r_child = parent->right;
//
//        int cnt = 1;
//
//        if (l_child != nullptr) {
//            cnt += getSize(l_child);
//        }
//
//        if (r_child != nullptr) {
//            cnt += getSize(r_child);
//        }
//
//        return cnt;
//    }
//
//    long int sumBT(TreeNode *root) {
//        // Code here
//        TreeNode *parent = root;
//        TreeNode *l_child = parent->left;
//        TreeNode *r_child = parent->right;
//        long sum = 0;
//
//        sum += (long) (parent->data);
//
//        if (l_child != nullptr) {
//            sum += sumBT(l_child);
//        }
//
//        if (r_child != nullptr) {
//            sum += sumBT(r_child);
//        }
//
//        return sum;
//    }
//
//
//    int countNonLeafNodes(TreeNode *root) {
//        // Code here
//
//        TreeNode *parent = root;
//        TreeNode *l_child = parent->left;
//        TreeNode *r_child = parent->right;
//
//        int cnt = 0;
//
//        if (l_child != nullptr or r_child != nullptr) {
//            cnt++;
//        }
//
//
//        if (l_child != nullptr) {
//            cnt += countNonLeafNodes(l_child);
//        }
//
//        if (r_child != nullptr) {
//            cnt += countNonLeafNodes(r_child);
//        }
//
//        return cnt;
//
//    }
//
//    int heapHeight(int N, int arr[]) {
//        // code here
//        return log2(N);
//    }
//
//    int maxBinTreeGCD(vector<vector<int>> arr, int N) {
//        // code here
//
//        if (N < 3) {
//            return 0;
//        }
//        int parent_node = arr[0][0];
//        int curr_index = 0;
//
//        for (int i = 1; i < N - 1; i++) {
//            //cout << arr[i][0];
//            if (parent_node == arr[i][0] and curr_index == (i - 1)) {
//                cout << "p : " << parent_node << " idx : " << curr_index << endl;
//                parent_node = arr[++i][0];
//                curr_index = i;
//            }
//            // for(int j=0; j<2; j++){
//            //     if(arr[i][0] == )
//            // }
//            // cout << endl;
//        }
//
//    }
//
//    bool isIdentical(TreeNode *r1, TreeNode *r2) {
//        //Your Code here
//
//        // 1. r1, r2가 모두 left가 있을 때,
//        // 2. r1, r2중 하나가 null일 때,
//        // 3. r1, r2 모두가 null일 때
//
//        if (r1 == nullptr && r2 == nullptr)
//            return false;
//
//        if (r1->data == r2->data) {
//            if (r1->left != nullptr and r2->left != nullptr)
//                isIdentical(r1->left, r2->left);
//            else if (r1->left == nullptr and r2->left == nullptr) {
//
//            } else { return false; }
//
//
//            if (r1->right != nullptr and r2->right != nullptr)
//                isIdentical(r1->right, r2->right);
//            else if (r1->right == nullptr and r2->right == nullptr) {
//
//            } else { return false; }
//
//        } else {
//            return false;
//        }
//        return true;
//
//        // !!깔끔한 코드!!
////            if(r1==nullptr && r2==nullptr)
////                return true;
////
////            if(r1 != nullptr and r2 != nullptr){
////
////                return (
////                        (r1->data == r2->data) &&
////                        isIdentical(r1->left, r2->left)
////                isIdentical(r1->right, r2->right)
////
////                )
////            }
////
////            // one empty, one not -> false;
////            return false;
//    }
//
//
//};
//
//
//class Stack {
//#define stack_len 1000
//
//private:
//    int arr[stack_len];
//    int top = -1;
//
//public:
//    void push(int x) {
//        arr[++top] = x;
//    }
//
////Function to remove an item from top of the stack.
//    int pop() {
//        if (top == -1) {
//            //error를 return 할 수도 있다.
//            return top;
//        }
//
//        return arr[top--];
//
//    }
//
//};
//
//
//void get_gcd() {
//    int a, b;
//    scanf("%d %d", &a, &b);
//
//    int original_a = a;
//    int original_b = b;
//
//    while (a % b != 0) {
//        int tmp = a;
//        a = b;
//        b = tmp % b;
//    }
//
//    printf("%d\n", b);
//    printf("%d", (original_a / b) * (original_b / b) * b);
//}
//
//
//class StringSolution {
//public:
//    string reverseWord(string str) {
//
//        //Your code here
//        int i = 0;
//        for (; str[i] != 0; i++) {}
//
//        for (; i >= 0; i--) { printf("%c", str[i]); }
//
//
//    }
//
//    bool isAnagram(string a, string b){
//
//        // Your code here
//        int arr_a[26] = {0,};
//        int arr_b[26] = {0,};
//
//        int len_a = a.size();
//        int len_b = b.size();
//
//        if(len_a != len_b){ return false;}
//
//        for (int i = 0; i < len_a; ++i) {
//
//            arr_a[(int)(a[i]-97)]++;
//            arr_b[(int)(b[i]-97)]++;
//        }
//
//        for (int k = 0; k < 26; ++k) {
//
//            if(arr_b[k] != arr_a[k]){
//
//                return false;
//            }
//        }
//        return true;
//    }
//
//};
//
//typedef struct voidType{
//    void* ptr;
//}voidType;
//
//void printEvery(voidType a){
//
//    //cout << a;
//}
//
//class WindowSliding{
//public:
//    long maximumSumSubarray(int K, vector<int> &Arr , int N){
//        // code here
//        long sum = 0;
//        for (int i = 0; i < K; ++i) {
//            sum+= Arr[i];
//        }
//        long max_sum = sum;
//
//        for (int i = 1; i <= N-K; ++i) {
//            sum -= Arr[i-1];
//            sum += Arr[i+K-1];
//
//            if(max_sum < sum)
//            {
//                max_sum = sum;
//            }
//        }
//        return max_sum;
//
//    }
//
//};
//
//class Sorting{
//public:
//
//    int MissingNumber(vector<int>& array, int n) {
//        // Your code goes here
//        int check_arr[1000001] = {0,};
//        for (int i = 0; i < n-1; ++i) {
//            check_arr[array[i]]++;
//        }
//
//        for (int i = 1; i < n; ++i) {
//            if(check_arr[i] ==0){
//                return i;
//            }
//        }
//    }
//
//
//    void sort012(int a[], int n)
//    {
//        // code here
//        int check_arr[3] = {0,};
//
//        for (int i = 0; i < n; ++i) {
//            check_arr[a[i]]++;
//        }
//
//        int idx = 0;
//        for (int i = 0; i < 3; ++i) {
//            int len = check_arr[i];
//
//            for (int j = 0; j < len; ++j) {
//                a[idx++] = i;
//
//            }
//        }
//
//        //dutch nation flag
//
////        int low = 0;
////        int mid = 0;
////        int high = length-1;
////
////        int dutch_flag[length] = {0,};
////
////        for (int i = 0; i < length; i++) {
////
////            if(arr[i] == 0)
////            {
////                dutch_flag[low++] = 0;
////                mid = low;
////            }
////            else if(arr[i] == 1)
////            {
////                dutch_flag[mid++] = 1;
////            }
////            else if(arr[i] == 2)
////            {
////                dutch_flag[high--] = 2;
////            }
////        }
////
////        for (int i = 0; i < length; ++i) {
////            cout << dutch_flag[i] << " ";
////        }
//    }
//
//    bool check(vector<long long> A, vector<long long> B, int N) {
//        //code here
//
//        sort(A.begin(), A.end());
//        sort(B.begin(), B.end());
//
//
//        for (int i = 0; i < N; ++i) {
//            if(A[i] != B[i]){
//                return 0;
//            }
//        }
//
//        return 1;
//    }
//
//
//    int doUnion(int a[], int n, int b[], int m)  {
//        //code here
//        int check_arr[100001] = {0,};
//
//        int len = 0;
//        int second_idx = 0;
//        int second_len = 0;
//        int *p_arr = nullptr;
//
//        if(n<=m){
//            len =n;
//            second_idx = n;
//            second_len = m;
//            p_arr = b;
//        }else{
//            len =m;
//            second_idx = m;
//            second_len = n;
//            p_arr = a;
//        }
//        for (int i = 0; i <len; ++i) {
//            check_arr[a[i]]++;
//            check_arr[b[i]]++;
//        }
//
//        for (; second_idx < second_len; ++second_idx) {
//            check_arr[p_arr[second_idx]]++;
//        }
//
//        int cnt = 0;
//        for (int i = 0; i < 100001; ++i) {
//            if(check_arr[i]>0){
//                cnt++;
//            }
//        }
//
//        return cnt;
////        int len = 0;
////        int second_idx = 0;
////        int second_len = 0;
////        int *p_arr = nullptr;
////
////        int n = 18;
////        int m = 3;
////        set<int> s;
////
////        if(n<=m){
////            len =n;
////            second_idx = n;
////            second_len = m;
////            p_arr = b;
////        }else{
////            len =m;
////            second_idx = m;
////            second_len = n;
////            p_arr = a;
////        }
////
////        for (int i = 0; i <len; ++i) {
////            s.insert(a[i]);
////            s.insert(b[i]);
////        }
////
////        for (; second_idx < second_len; ++second_idx) {
////            s.insert(p_arr[second_idx]);
////        }
////
////        cout << s.size();
//    }
//};
//
//
//int get_size(int arr[]){
//    cout << sizeof(arr)<< endl;
//    return sizeof(arr)/sizeof(int);
//}



#include <iostream>
#include <vector>
#include <array>
#include <cstdlib>
#include <cmath>
#include <set>
#include <unordered_set>
#include <string>
#include <string.h>
#include <map>
#include <typeinfo>
#include <algorithm>
#include <stdio.h>

#define DEBUG

using namespace std;

#define Py_API_FUNC(int) 
#define TODAY "2023-09-1919"
#define pr(time) (time * 10)


#define Py_Is(x, y) ((x) == (y))

#define PY_SSIZE_T_CLEAN

#include <Python.h>
#include "python_module.h"

typedef struct Test{
    int a_param;
    int b_param;
} Test;



//class Workout_info(ctypes.Structure):
//_fields_ = [
//("id", ctypes.c_int),
//("user_id", ctypes.c_int),
//("workout_data__repAverageWeight", ctypes.POINTER(ctypes.c_int)),
//("machine_base_type_id", ctypes.c_int),
//("workout_type_id", ctypes.c_int),
//("workout_data__workoutRep", ctypes.c_int),
//("workout_data__weight", ctypes.c_double),
//("workout_data__leftAvgForce", ctypes.c_double),
//("workout_data__rightAvgForce", ctypes.c_double),
//("workout_data__calories_burned", ctypes.c_int),
//("workout_data__doneWorkoutTime", ctypes.c_wchar),
//("workout_data__workoutTime", ctypes.c_wchar),
//("workout_data__workout_time", ctypes.c_wchar),
//("workout_category", ctypes.c_wchar),
//
//]

int main() {

//    char s[] = "Hello World";
//    s[6] = 'x'; //try to edit letter at position 6
//    printf("%s", s);

// 이렇게 사용하지 말자 char str[]로 사용하도록 하자.
    char* ss = "Hello World";
//    *(ss+6) = 'x'; //try to edit letter at position 6
//    printf("%s", ss);

    //printf("%p\n", ss);

    *ss = '1';

    cout << ss;

//    for (int i = 0; i < 11; ++i) {
//        // (int)(*ss) = (int)(*ss) + 1;
//        *ss = 's';
//        // cout << (int)(*ss);
//        printf("%p %d %d\n", ss, *ss, i);
//
//        // ss += 1;
//    }


    //strftime()
//
//    wchar_t* program = Py_DecodeLocale(argv[0], NULL);
//    if (program==NULL){
//        fprintf(stderr, "Fatal error: cannot decode argv[0]\n");
//        exit(1);
//    }
//
//    if (PyImport_AppendInittab("spam", PyInit_spam) == -1) {
//        fprintf(stderr, "Error could not extend in-built modules table\n");
//        exit(1);
//    }
//
//    // Pass argv[0] to the Python interpreter
//    Py_SetProgramName(program);
//
//    // Initialize the Python interpreter. Required.
//    // If this step fails, it will be a fatal error.
//    Py_Initialize();
//
//    // Optionally import the module; alternatively,
//    // import can be deferred until the embedded script
//    // imports it
//
//    PyObject* pmodule = PyImport_ImportModule("spam");
//    if (!pmodule) {
//        PyErr_Print();
//        fprintf(stderr,  "Error: could not import module 'spam'\n");
//    }
//
//    PyMem_RawFree(program);

    // string은 원하는 문자열의 크기 +1 만큼 할당해야 한다.!!!!!!!!!!!!!!!!!!!!!!!!

//    char c1[] = "21";
//    printf("%p\n", c1);
//    printf("%p\n", c1[1]);
//
//    const char* arr[] = {&c1[0], &c1[1]};
//
//    printf("%p %p", arr[0], arr[1]);

    //cout << c[0] << endl;

    // cout << Py_Is(&a, 12) << endl;
    // PyAPI_FUNC(int) Py_Is(int *x, int *y);


    return 0;
}


    //int size = 10;
    // int* arr = (int*)malloc(size * sizeof(int));

//    int columns = 5;
//    int rows = 5;
//
//    // int** arr = (int**) malloc(columns * sizeof(int*));
//
//    int*** arr = (int***) malloc(3 * sizeof(int***));
//
//    for (int i = 0; i < 3; ++i) {
//        arr[i] = (int**) malloc(3 * sizeof(int**));
//        for (int j = 0; j < 3; ++j) {
//            arr[i][j] = (int*) malloc(3 * sizeof(int*));
//        }
//    }
//
//    int aa = 0;
//    for (int i = 0; i < 3; ++i) {
//
//        for (int j = 0; j < 3; ++j) {
//
//            for (int k = 0; k < 3; ++k) {
//                arr[i][j][k] = aa++;
//
//            }
//        }
//    }
//
//    for (int i = 0; i < 3; ++i) {
//
//        for (int j = 0; j < 3; ++j) {
//
//            for (int k = 0; k < 3; ++k) {
//                cout << arr[i][j][k] << endl;
//            }
//        }
//    }







//    int* linear_arr = (int*) malloc((columns * rows) * sizeof(int));
//
//    for (int j = 0; j < rows; ++j) {
//        cout << "columns -> " << columns * j << endl;
//        arr[j] = &linear_arr[columns * j];
//        cout << arr[j] << endl;
//    }
//
//    for (int i = 0; i < 5; i++) {
//        for (int j = 0; j < rows; ++j) {
//            arr[i][j] = j;
//            // cout << arr[i][j] << endl;
//        }
//        // cout << "---------" << endl;
//    }
//
//    for (int i = 0; i < 5; i++) {
//        for (int j = 0; j < 5; j++) {
//            cout << arr[i][j] << endl;
//        }
//    }


    // free(arr);





//
//
//
//    //    int N = 3;
////    int M = 3;
////
////    int after[3][3] = {{1, 2, 3},
////                       {2, 2, 1}};
////
////    int res = 0;
////    int x = N;
////    int y = M;
//
////    for(int i = 0; i <= x; i++){
////        for( j = 0; j <= y; j++){
////            res += before(i,j);
////        }
////    }
//
////    Input:
////    N = 4, K = 6
////    arr[] = {1, 5, 7, 1}
////    Output: 2
////    Explanation:
////    arr[0] + arr[1] = 1 + 5 = 6
////                              and arr[1] + arr[3] = 5 + 1 = 6.
//
////    int arr[] = {1, 5, 7, 1};
////    int n = 4;
////    int k = 6;
//
//
//
//    //printList(a);
//
////    int *bool_arr = new int[10000001] {0,};
////
////    int N = 2;
////
////    for (int i = 0; i < N; ++i) {
////        bool_arr[a[i]]++;
////        bool_arr[b[i]]++;
////    }
////
////    for (int i = 0; i < N; ++i) {
////        if(bool_arr[a[i]]<2){
////            cout << 0;
////        }
////    }
////
////    cout << 1;
////    delete[] bool_arr;
////
////    int n = sizeof(a)/sizeof(int);
////
////    int max = a[0];
////
////    for (int i = 0, j = n-1; i < j; ++i, --j) {
////        int flag = 0;
////        if(a[i]>a[j]){
////            flag = a[i];
////        }else{
////            flag = a[j];
////        }
////
////        if(flag>max){
////            max = flag;
////        }
////    }
////    cout << max;
////    return 0;
////
////
////    vector<int> answer;
////
////    int j = 0;
////    while(j<n-1){
////        int leader = a[j];
////
////        for (int i = j+1; i < n; ++i) {
////            if(a[i] > leader){
////                leader = a[i];
////                j = i;
////            }
////        }
////
////        answer.push_back(leader);
////        if(j ==n-1){
////            printList(answer);
////            break;
////        }
////        j++;
////
////    }
////
////    answer.push_back(a[n-1]);
////    printList(answer);
//
//
////
////    while(curr->next !=nullptr){
////        len++;
////        curr = curr->next;
////    }
////
////    while(len!=0){
////        Node* ptr = head;
////        for(int i=0; i<len; i++){
////            cout <<"t : " << ptr->data << " ";
////            ptr = ->next;
////        }
////
////        //curr->next =
////        len--;
////    }
////
////    return head;
//
////    int a[] = {1, 2, 3, 4, 5,54,6,7,5,234,234,123,23,4,23,12,123,12};
////    int b[] = {1, 2, 3};
////
////    int len = 0;
////    int second_idx = 0;
////    int second_len = 0;
////    int *p_arr = nullptr;
////
////    int n = 18;
////    int m = 3;
////    set<int> s;
////
////    if(n<=m){
////        len =n;
////        second_idx = n;
////        second_len = m;
////        p_arr = b;
////    }else{
////        len =m;
////        second_idx = m;
////        second_len = n;
////        p_arr = a;
////    }
////
////    map<int, int> map;
////
////    map.insert()
////    for (int i = 0; i <len; ++i) {
////        s.insert(a[i]);
////        s.insert(b[i]);
////    }
////
////    for (; second_idx < second_len; ++second_idx) {
////        s.insert(p_arr[second_idx]);
////    }
////
////    cout << s.size();
//
//
//
//
//
//
//
//
//
//void selectionSort(vector<int> nums) {
//    int len = nums.size();
//
//    for (int i = 0; i < len; i++) {
//        int min = nums[i];
//        int target = i;
//
//        for (int j = i + 1; j < len; j++) {
//
//            if (min > nums[j]) {
//                min = nums[j];
//                target = j;
//            }
//        }
//
//        int tmp = nums[i];
//        nums[i] = nums[target];
//        nums[target] = tmp;
//
//    }
//}
//
//
//void insertionSort(vector<int> nums) {
//    int len = nums.size();
//
//    for (int i = 1; i < len; i++) {
//
//        for (int j = i - 1; j >= 0; j--) {
//            if (nums[i] < nums[j]) {
//                int tmp = nums[i];
//                nums[i] = nums[j];
//                nums[j] = tmp;
//                i = j;
//            }
//        }
//    }
//}
//
//void twoPointers(vector<int> nums) {
//    int len = nums.size() - 1;
//    vector<int> arr(len + 1, 0);
//
//    int l = 0;
//    int r = len;
//
//    int l_num = 0;
//    int r_num = 0;
//
//    while (l <= r) {
//
//        l_num = abs(nums[l]);
//        r_num = abs(nums[r]);
//        if (l == r) {
//            arr[len--] = square(l_num, 2);
//            break;
//        }
//
//        if (l_num < r_num) {
//            cout << r_num << endl;
//            arr[len--] = square(r_num, 2);
//            r--;
//        }
//        else {
//            cout << l_num << endl;
//            arr[len--] = square(l_num, 2);
//            l++;
//        }
//
//    }
//
//    printList(arr);
//}