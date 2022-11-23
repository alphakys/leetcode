#include <iostream>
#include <vector>
#include <array>
#include<cstdlib>

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



class TwoSumII{
public:
    vector<int> search(vector<int>& numbers, int n) {

    vector<int> answer(2,0);
    int len = numbers.size();

    int target = 200;
    int end = len;
    int duplicate = 0;

    for (int i = 0; i < len and (numbers[i]<=target or numbers[i]==0); i++) {
        cout << i <<" , " << end << endl;
        int sum = 0;
        duplicate = numbers[i]+numbers[i+1];
        for (int j = i+1; j < end; ++j) {
            //cout << j <<" , "<< endl;
            sum= numbers[i]+numbers[j];
            if(sum == duplicate){}

            if(sum==target){
                answer[0] = i+1; answer[1] = j+1;goto end;}
            else if(sum>target){ end = j;break;}
        }

    }

    end:
        return answer;


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


int main() {
    //                  0  1 2  3 4 5   6   7       8        9     10 11  12
    vector<int> nums = {-3,-3,-3,-3,-3,-3,-3,-3,-3,-3,-3,-3,-3,-3,-3,-3,3,4,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5};//,56, 5, 0, 0, 3, 2, 0, 6, 8, 0, 0, 0};

    //16
    //{-2,-1,5,11,44,66}
    // 생각 1. 두 수의 합이 target number가 되어야 한다는 말은 곧 두 수 모두 target 보다 작아야 한다는 점을 의미한다.
    //
    int r = nums.size()-1;
    if(r==1){ printList(nums);}
    int l = 0;
    int pivot = r;
    int target = 7;

    for (;;) {
        cout << "l :  " << l << " r : " << r << endl;

        //if(l==r){ l++; r = pivot;}
        if(nums[r]+nums[l]==target){
            //cout << nums[r] << " , " << nums[l];
            printf("%d, %d\n", l+1, r+1);
            break;
        }
        else if(nums[r]+nums[l]> target){ r--; continue;}
        else{ l++; r = pivot; }

    }


    //cout << "answer : " ; printList(nums);



    return 0;
}

// #Move To zeroes code

//    int l =0;
//    int r = nums.size()-1;
//
//    if(r==0){ return 0;}
//    while(nums[l] ==0 && l<r){ l++; }
//    cout << l << " " << nums[l] << endl;
//    swap(0,l,nums);
//    cout << "swap : "; printList(nums); cout << endl;
//    l = 0;
//    MoveToZeroes mz;
//    mz.quickDivide(l, r, nums);


//
//    cout << r << endl;
//    MoveToZeroes mz;
//    mz.quickDivide(l, r, nums);




//    int last = 0;
//    for (; l < r; ) {
//        //cout << "l : " <<l << " r : " << r << endl;
//        if(nums[l]==0 && nums[r] !=0){
//            swap(l,r,nums);
//            l++,r--;
//        }else if(nums[l]==0 && nums[r] ==0){r--;}
//        else if(nums[l]!=0 && nums[r] ==0){ l++;}
//        else if(nums[l]!=0 && nums[r] !=0){ l++;}
//        printList(nums);
//        cout << endl;
//    }


//    if(l==r){last = l;}
//    QuickSort qs;
//    qs.quickDivide(0,(last-1), nums);






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





















