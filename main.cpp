#include <iostream>
#include <vector>
#include <array>
#include<cstdlib>
#include <cmath>

using namespace std;

class BinarySearch{
public:
    int search(vector<int>& nums, int target) {

        int len = nums.size();
        int first = 0;
        int end = len;
        int pivot = (first+end)/2;
        int answer = 0;

        while(first <=pivot){
            cout << "first : " << first << " pivot : " << pivot << " end : " << end << endl;
            if(first==pivot && nums[pivot]!= target){answer = -1; break;}
            if(nums[pivot] <target){
                first = pivot+1;
                pivot = (first + end)/2;
            }else if(nums[pivot]== target){
                answer = pivot;
                break;
            }else{
                end = pivot;
                pivot = (first+end)/2;
            }

        }
        return answer;
    }
};


class FirstBadVersion{
public:
    int search(vector<int>& nums, int n) {

        int first = 0;
        int end = n;

        int pivot = n - 1;

        while (first <= pivot) {
            cout << "first : " << first << " pivot : " << pivot << " end : " << end << endl;

            //if(first==pivot ){ break;}
            if (nums[pivot] == 1 && nums[pivot - 1] == 1) {
                end = pivot - 1;
                pivot = (first + end) / 2;

            } else if (nums[pivot] == 1 && nums[pivot - 1] == 0) {
                //1과 end 사이에서 마지막 0을 찾아야함
                //그리고 현재까지는 가장 작은 1이 end임을 알 수 있다. 하지만 더 작은 1이 있을 수 있으니 찾아야함
//            first = pivot+1;
//            pivot = (first + end)/2;
                cout << pivot;
                break;
            } else if (nums[pivot] == 0 && nums[pivot + 1] == 0) {

                first = pivot + 1;
                pivot = (first + end) / 2;
                //break;
            } else {
                cout << pivot + 1;
                break;
            }

        }
    }
};


class SearchInsertPosition{
public:
    int search(vector<int>& nums, int n) {

        int end = nums.size()-1;
        int first = 0;
        int target = 2;
        int pivot = end;
        int answer = 0;

        if(target < nums[0]){ answer = 0; }
        else if(target > nums[end]){answer = end; }

        while(first<=pivot){
            cout << "first : " << first << " pivot : " << pivot << " end : " << end << endl;

            if(first==pivot && nums[pivot] != target){ answer = end; break;}

            if(nums[pivot] < target){
                first = pivot;
                pivot = (first + end)/2;

            }
            else if(nums[pivot]== target ) {
                answer = pivot;
                break;
            }
            else if(nums[pivot]> target){
                end = pivot;
                pivot = (first + end)/2;

            }

        }

        cout << "answer : " << answer;
    }
};

class MergeSort{
public:
    int temp[100001] = {0,};

    void conquer(int left, int mid, int right, vector<int>& nums){

        int idx = left;
        int pivot = mid+1;
        int i = left;

        if(left ==right){temp[idx] = nums[left];return;}
        while(idx < right){

            if(nums[left] > nums[pivot]){
                if(pivot<right){temp[idx++] = nums[pivot]; pivot++;}
                else{
                    temp[idx++] = nums[pivot];
                    for (; left <=mid; ++left) {
                        temp[idx++] = nums[left];

                    }

                }

            }
            else{
                if(left<mid){temp[idx++] = nums[left]; left++;}
                else{
                    temp[idx++] = nums[left];
                    for (; pivot <=right; ++pivot) {
                        temp[idx++] = nums[pivot];

                    }
                }

            }
        }

        for (; i <=right; i++) {
            nums[i]=temp[i];
        }
    }

    void mergeSort(int left, int mid, int right, vector<int>& nums){

        if(left <mid){
            mergeSort(mid+1, ((mid+1)+right)/2, right, nums);
            mergeSort(left, (left+mid)/2, mid, nums);

        }
        conquer(left,  mid, right, nums);

    }
};


class RotateArray{
public:
    int search(vector<int>& nums, int n) {

        int len = nums.size();

        vector<int> arr(len,0);
        int k = 2;

        for (int i = 0; i < len; i++) {
            int target_idx =i+k;
            if( target_idx > (len-1) ) { target_idx = target_idx % len; arr[target_idx] = nums[i]; }
            else{arr[target_idx] = nums[i];}
        }
        //printList(arr); cout << endl;
        nums = arr;

    }
};


class MoveZeroes{
public:
    int search(vector<int>& nums, int n) {

        int len = nums.size();
        int zero_cnt = 0;
        int idx = 0;

        for (int i = 0; i < len; i++) {
            cout <<"i : "<< i << endl;
            if(nums[i]==0){
                zero_cnt++;
                continue;
            }

            if(i==len-1){ nums[idx++] = nums[i]; }

            for (int j = i+1; j < len; ++j) {

                if(nums[j]==0){
                    zero_cnt++;
                    continue;
                }
                else if(nums[i] > nums[j]){
                    nums[idx++] = nums[j];
                }else{
                    nums[idx++] = nums[i];
                    i = --j;
                    break;
                }
            }
            //printList(nums); cout << endl;
        }

        for (; idx < len; ++idx) {
            nums[idx] = 0;
        }
        //printList(nums); cout << endl;

        cout << zero_cnt << ", " << idx;



    }
};


void printList(vector<int>& nums){
    int len = nums.size();

    for(int i=0; i<len; i++){
        cout << nums[i] << ' ';
    }

}

void printArray(int arr[], int len){

    for(int i=0; i<len; i++){
        cout << arr[i] << ' ';
    }

}

int square(int num, int multiple){

    int value = 1;

    for(int i=0; i<multiple; i++){
        value = value*num;
    }
    return value;
}

class QuickSort{
public:

    void swap(int a, int b, vector<int>& nums){
        int tmp = nums[a];
        nums[a] = nums[b];
        nums[b] = tmp;
    }

    int quickConquer(int l, int r, vector<int>& nums){

        int right_most = r-1;

        for (; l < right_most;) {

            if(nums[l] > nums[r]){
                if(nums[right_most] < nums[r]){

                    swap(l, right_most, nums);

                }else{
                    right_most--;
                    continue;
                }

            }
            else{
                if(nums[right_most] < nums[r]){
                    l++;
                    continue;
                }
            }
            l++;right_most--;

        }
        //printList(nums); cout << endl;
        if(nums[r] < nums[l]){ swap(r, l, nums); }
        return l;
    }

    void quickDivide(int l, int r, vector<int>& nums){
        int mid = quickConquer(l, r, nums);
        if(l==r){return;}

        if(l<mid){
            quickDivide(l, mid, nums);
            quickDivide(mid+1, r, nums);
        }else if(l==mid){ quickDivide(mid+1, r, nums);}
        else if(r==mid){ quickDivide(l, mid, nums); }

    }

};



class MoveToZeroes{
public:

    void swap(int a, int b, vector<int>& nums){
        int tmp = nums[a];
        nums[a] = nums[b];
        nums[b] = tmp;
    }

    // 0   1  2  3  4  5  6  7  8  9  10 11 12
    //{0, 56, 5, 0, 0, 3, 2, 0, 6, 8, 0, 45, 1};
    //{56, 0, 5, 0, 0, 3, 2, 0, 6, 8, 0, 45, 1};
    int quickConquer(int l, int r, vector<int>& nums){

        int left_most = l+1;

        for (; left_most < r;) {
            printf("[left_most -> %d, v -> %d], [r -> %d, v -> %d]\n", left_most, nums[left_most], r, nums[r]);
            cout << "전 : "; printList(nums); cout << endl;
            if(nums[left_most]==0){

                if(nums[r]!=0){

                    swap(r, left_most,nums); left_most++,r--;
                    //printList(nums); cout << endl;
                }
                else{ r--; }
                cout << "후 : "; printList(nums); cout << endl;
                continue;
            }

            if(nums[left_most] > nums[l]){
                if(nums[l] < nums[r]){
                    if(nums[left_most]!=0){ r--;}
                    else{
                        swap(r, left_most,nums);
                        r--;
                        //continue;
                    }

                }else{
                    swap(r, left_most,nums); left_most++; r--;
                    //continue;
                }

            }
            else{
                if(nums[r]==0){ r--;
                    continue;}

                if(nums[r] < nums[l]){
                    left_most++;
                    //continue;
                }else{ left_most++; r--;}
            }
            //
            cout << "후 : "; printList(nums); cout << endl;
            //break;
        }

        if(nums[left_most] < nums[l]){
            if(nums[left_most] !=0){ swap(left_most, l, nums);}
        }
        //cout << left_most;
        return left_most;
    }

    void quickDivide(int l, int r, vector<int>& nums){
        int mid = quickConquer(l, r, nums);

        if(mid==r){return;}

        if(l<mid){
            if(nums[l]!=0){ quickDivide(l, mid, nums);}
            //quickDivide(l, mid, nums);
            if(nums[mid+1]!=0){ quickDivide(mid+1, r, nums);}
            //quickDivide(mid+1, r, nums);
        }
        else if(l==mid){ if(nums[mid+1]!=0){ quickDivide(mid+1, r, nums);} }
        else if(r==mid){ if(nums[l]!=0){ quickDivide(l, mid, nums);} }

    }

};


void swap(int a, int b, vector<int>& nums){
    int tmp = nums[a];
    nums[a] = nums[b];
    nums[b] = tmp;
}


class TwoSumII{
public:

    void solution(){
        vector<int> numbers = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
        int l = 0;
        int r = numbers.size()-1;
        int target = 2;

        vector<int> answer(2);

        while(l<r){
            if(numbers[l] + numbers[r] > target){ r--; }
            else if(numbers[l] + numbers[r] == target){ answer[0] = l+1; answer[1] = r+1; break;}
            else{ l++;}

        }
        printList(answer);
    }

};


class ReverseWordsinaStringIII{
public:

    void solution(){
        string s = "sdf ffff 3w wer4 dfssdfdsfds";

        int len = s.size();
        int idx = 0;
        int l = 0;
        char tmp = NULL;
        int r;
        while(idx<len){
            if(s[idx] ==32 or s[idx] ==32){

                r = idx-1;
                for (; l<= r; l++,r--) {
                    tmp = s[l];
                    s[l] = s[r];
                    s[r] = tmp;
                }
                l = idx+1;
            };
            idx++;
        }

        r = len-1;

        for (; l< r; l++,r--) {

            tmp = s[l];
            s[l] = s[r];
            s[r] = tmp;
        }

    }

};


class ReverseString{
public:

    void solution(){
        vector<char> s = {'H','a','n','n','a','h'};

        int len  = s.size();
        int l = 0;
        int r = s.size()-1;

        char tmp = NULL;
        for (; l< r; l++,r--) {
            tmp = s[l];
            s[l] = s[r];
            s[r] = tmp;
        }

        for (int i = 0; i < len; ++i) {
            cout << s[i];
        }

    }

};



struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
}*start;


typedef struct Node {
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = nullptr;
    }

}Node;






class LinkedList{

    private:
        Node *head;

    public:
        LinkedList(){ head = nullptr; }

        //Function to insert a node in the middle of the linked list.
        Node* insertInMiddle(Node* head, int x)
        {
            // Code here
            int cnt = getCount(head);

            int middle = (cnt/2)+(cnt%2);

            Node* curr = head;
            Node* prevNode;

            while(curr!=nullptr && middle >0){
                prevNode = curr;
                curr = curr->next;
                middle--;
            }

            Node* n = new Node(x);
            prevNode->next = n;
            n->next = curr;
            return head;

        }

        Node *insertAtBegining(Node *head, int x) {
            // Your code here
            if(head ==nullptr) { head = new Node(x); return head;}
            else{
                Node *n = new Node(x);
                n->next = head;
                return n;
            }

        }

        //Function to insert a node at the end of the linked list.
        Node *insertAtEnd(int x)  {
            // Your code here
            if(head ==nullptr) { head = new Node(x); return head;}
            else{

                Node* curr = head;
                while(curr->next != nullptr){
                    curr = curr->next;
                }
                curr->next = new Node(x);

                return head;
            }

        }

        int getCount(struct Node* head){

            int len = 1;

            Node* n = head;
            while(n->next != nullptr){
                n = n->next;
                len++;
            }
            return len;
        }

        void display()
        {
            Node* n = head;
            while(n != nullptr){
                printf("%d ", n->data);
                n = n->next;
            }

        }

        int GetNth(struct Node* head, int index){
            // Code here

            Node *curr = head;
            index--;
            while(curr!=nullptr){
                if(index ==0){
                    return curr->data;
                }
                else{
                    curr = curr->next;
                    index--;

                }
            }


        }

        int isLengthEvenOrOdd(struct Node* head)
        {
            //Code here
            return (getCount(head)%2);
        }


        int sumOfLastN_Nodes(struct Node* head, int n)
        {
            // Code here
            Node* curr = head;
            vector<int> arr;

            while(curr != nullptr){
                arr.push_back(curr->data);
                curr = curr->next;
            }

            int len = arr.size();

            int sum = 0;

            for(int i=len-1; n-->0; i--){
                sum += arr[i];
            }

            return sum;
        }

        int fractional_node(struct Node *head, int k)
        {
            // your code here
            int element = ceil((double)getCount(head) / (double)k);

            Node* curr = head;
            while(element-- > 1){

                curr = curr->next;
            }

            return curr->data;
        }

        int modularNode(int k)
        {
            // Code here
            Node* n = head;
            int result = NULL;

            int index=1;
            while(n!= nullptr){
                //cout << n->data/k << " " << n->data << " "<< n->data%k << endl;
                if(index++%k ==0){
                    result= n->data;
                }
                n= n->next;
            }

            if(result ==NULL){
                return -1;
            }else{
                return result;
            }

        }


        void stackPush(int x)
        {
            // Your Code
            Node* n = head;

            if(n==nullptr){
                n = new Node(x);
                head = n;

            }
            else{
                while(n->next!=nullptr){
                    n = n->next;
                }

                n->next = new Node(x);

            }

        }

        //Function to remove an item from top of the stack.
        int stackPop()
        {
            Node* n = head;

            if(n==nullptr){
                return -1;
            }else{
                Node* prevNode = nullptr;
                while(n->next!=nullptr){
                    prevNode = n;
                    n = n->next;
                }

                int answer = n->data;
                if(prevNode ==nullptr){
                    head = nullptr;
                    return answer;
                }else{
                    prevNode->next = nullptr;
                    delete prevNode->next;
                }


                return answer;
            }

        }

};

typedef struct DoubleNode{
    int data;
    struct DoubleNode* prev;
    struct DoubleNode* next;

    DoubleNode(int x){
        data = x;
        next = nullptr;
        prev = nullptr;
    }

}DoubleNode;


class DoublyLinkedList{

    private:
        DoubleNode *head;

    public:
        DoublyLinkedList(){ head = nullptr; }

        DoublyLinkedList(int x){
            head = new DoubleNode(x);
        }

        void addNode(int pos, int data)
        {
            // Your code here
            if(pos==-1){
                if(head== nullptr){ head = new DoubleNode(data); }
                else{
                    DoubleNode *curr = head;

                    while(curr->next != nullptr){
                        curr = curr->next;
                    }
                    DoubleNode *nextNode = curr->next = new DoubleNode(data);
                    nextNode->prev = curr;

                }

            }else{
                DoubleNode *n = head;

                while(pos-- > 0){
                    n = n->next;
                }
                DoubleNode *next_swap_node = n->next;
                n->next = new DoubleNode(data);
                n->next->next = next_swap_node;
                n->next->prev = n;
            }

        }

        void display()
        {
            DoubleNode* n = head;

            while(n != nullptr){

                printf("%d ", n->data);
                n = n->next;
            }

        }



};


class HashTable{


    public:
        int numIdenticalPairs(vector<int>& nums) {

            int arr[100] = {0,};

            int len = nums.size();

            for (int i = 0; i < len; ++i) {
                arr[nums[i]-1]++;
            }

            int sum= 0;
            for (int i = 0; i < 10; ++i) {

                int val = arr[i]-1;
                int sum_val = 0;
                while(val > 0){
                    sum_val+=val--;

                }
                sum += sum_val;
            }

            return sum;
        }

        int numJewelsInStones(string jewels, string stones) {
            int arr[58] = {0,};

            int cnt = stones.size();
            for (int j = 0; j < cnt; ++j) {
                arr[stones[j]-65]++;
            }

            int len = jewels.size();

            int sum = 0;

            for (int i = 0; i < len; ++i) {

                sum += arr[jewels[i]-65];
            }

            return sum;
        }



};

typedef struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(){
        left = nullptr;
        right = nullptr;
    }

    TreeNode(int x){
        data = x;
        left = nullptr;
        right = nullptr;
    }

};

class Tree{
    private:
        TreeNode *root;

    public:

        Tree(){
            root = nullptr;
        }

        void insertNode(){

        }

        vector<int> levelOrder(Node* node)
        {
            //Your code here
        }

        void preorder(TreeNode* root)
        {
            TreeNode* parent = root;
            TreeNode* l_child = parent->left;
            TreeNode* r_child = parent->right;

            printf("%d ", parent->data);

            if(l_child !=nullptr){ preorder(parent); }

            if(r_child !=nullptr){ preorder(parent); }

        }

        void inOrder(TreeNode* root) {

            TreeNode* parent = root;
            TreeNode* leftChild = parent->left;
            TreeNode* rightChild = parent->right;

            if(leftChild !=nullptr){
                inOrder(leftChild);
            }

            printf("%d ", parent->data);

            if(rightChild !=nullptr){
                inOrder(rightChild);
            }

        }

        void postOrder(TreeNode* root) {

            TreeNode* parent = root;
            TreeNode* leftChild = parent->left;
            TreeNode* rightChild = parent->right;

            if(leftChild !=nullptr)
            {
                postOrder(leftChild);
            }

            if(rightChild !=nullptr)
            {
                postOrder(rightChild);
            }

            printf("%d ", parent->data);

        }

        int countLeaves(TreeNode* root)
        {
            // Your code here
            TreeNode* parent = root;
            TreeNode* l_child = parent->left;
            TreeNode* r_child = parent->right;

            int answer = 0;

            if(l_child ==nullptr and r_child ==nullptr)
                return 1;

            if(l_child !=nullptr){
                answer += countLeaves(l_child);
            }

            if(r_child !=nullptr){
                answer += countLeaves(r_child);
            }

            return answer;

        }

        int getSize(TreeNode* node)
        {
            // Your code here
            TreeNode* parent = node;
            TreeNode* l_child = parent->left;
            TreeNode* r_child = parent->right;

            int cnt = 1;

            if(l_child !=nullptr){
                cnt += getSize(l_child);
            }

            if(r_child !=nullptr){
                cnt += getSize(r_child);
            }

            return cnt;
        }

        long int sumBT(TreeNode* root)
        {
            // Code here
            TreeNode* parent = root;
            TreeNode* l_child = parent->left;
            TreeNode* r_child = parent->right;
            long sum = 0;

            sum += (long)(parent->data);

            if(l_child !=nullptr){
                sum += sumBT(l_child);
            }

            if(r_child !=nullptr){
                sum += sumBT(r_child);
            }

            return sum;
        }


        int countNonLeafNodes(TreeNode* root) {
            // Code here

            TreeNode* parent = root;
            TreeNode* l_child = parent->left;
            TreeNode* r_child = parent->right;

            int cnt = 0;

            if(l_child !=nullptr or r_child != nullptr) {
                cnt++;
            }


            if(l_child !=nullptr){
                cnt += countNonLeafNodes(l_child);
            }

            if(r_child !=nullptr){
                cnt += countNonLeafNodes(r_child);
            }

            return cnt;

        }

        int heapHeight(int N, int arr[]){
            // code here
            return log2(N);
        }

        int maxBinTreeGCD(vector<vector<int>> arr, int N) {
            // code here

            if(N<3){
                return 0;
            }
            int parent_node = arr[0][0];
            int curr_index = 0;

            for(int i=1; i< N-1; i++){
                //cout << arr[i][0];
                if(parent_node == arr[i][0] and curr_index == (i-1)){
                    cout << "p : " << parent_node << " idx : " << curr_index << endl;
                    parent_node = arr[++i][0];
                    curr_index = i;
                }
                // for(int j=0; j<2; j++){
                //     if(arr[i][0] == )
                // }
                // cout << endl;
            }

        }










};



class Stack{
#define stack_len 1000

private:
    int arr[stack_len];
    int top = -1;

public:
    void push(int x)
    {
        arr[++top] = x;
    }

//Function to remove an item from top of the stack.
    int pop()
    {
        if(top==-1){
            //error를 return 할 수도 있다.
            return top;
        }

        return arr[top--];

    }

};


int main() {
    //quotient q
    //remainder r
    int a, b;
    //scanf("%d %d", &a, &b);

    vector<int> collector;

    a = 22;
    b = 20;

    int small;
    if (a == b) {
        cout << a << endl;
        cout << a << endl;

        return 0;
    }else if(a>b){
        small = b;
    }else{
        small =a;
    }

    //24는 18에 대해서 3분의 4배다. 18분의 24

    for (; small >= 1 ; --small) {
        int divisor_a = a%small;
        int divisor_b = b%small;

        if( divisor_a == 0 and divisor_b == 0) { collector.push_back(small); }
    }

    cout << collector[0] << endl;
    cout << ( (a/collector[0]) * (b/collector[0]) )* collector[0];


    //printList(collector);
    //while((a%i++)!=0){}


//    a = 231;
//    int i=2;
//    for (;  ; ) {
//        while((a%i++)!=0){}
//        int q = a/(i-1);
//        if(q==1){
//            collector.push_back(i-1);
//            break;
//        }
//        else{
//            collector.push_back(i-1);
//            a =q;
//            i=2;
//        }
//
//    }

//    int q = a/2;
//    int r = a%2;

    //printf("%d %d", q,r);





    return 0;
}















void selectionSort(vector<int> nums){
    int len = nums.size();

    for (int i = 0; i < len; i++) {
        int min = nums[i];
        int target = i;

        for (int j = i+1; j < len; j++) {

            if(min> nums[j]){
                min = nums[j];
                target = j;
            }
        }

        int tmp = nums[i];
        nums[i] = nums[target];
        nums[target] = tmp;

    }
}


void insertionSort(vector<int> nums){
    int len = nums.size();

    for (int i = 1; i < len; i++) {

        for (int j = i-1; j >= 0; j--) {
            if(nums[i]<nums[j]){
                int tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
                i = j;
            }
        }
    }
}

void twoPointers(vector<int> nums){
    int len = nums.size()-1;
    vector<int> arr(len+1, 0);

    int l = 0;
    int r = len;

    int l_num = 0;
    int r_num = 0;

    while(l<=r){

        l_num = abs(nums[l]);
        r_num = abs(nums[r]);
        if(l==r){arr[len--] = square(l_num,2); break;}

        if(l_num < r_num){ cout << r_num<<endl; arr[len--] = square(r_num,2); r--;}
        else{cout << l_num<<endl; arr[len--] = square(l_num,2); l++;}

    }

    printList(arr);
}