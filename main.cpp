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
    //printList(answer);



    }
};



int square(int num, int multiple){

    int value = 1;

    for(int i=0; i<multiple; i++){
        value = value*num;
    }
    return value;
}

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

void quickDivide(int l, int pivot, int r, vector<int>& nums){
    cout << "l : " << l << " pivot: " << pivot << " r: " << r << endl;
    if(l<pivot){
        quickDivide(l, l+ ((pivot-l)/2), pivot, nums);
        l = pivot+1;
        quickDivide(l, l+ ((r-l)/2), r, nums);
    }
}

void swap(int a, int b, vector<int>& nums){
    int tmp = nums[a];
    nums[a] = nums[b];
    nums[b] = tmp;
}

void quickConquer(int l, int mid, int r, vector<int>& nums){

    printf("mid : %d\n", nums[mid]);
    int pivot = r;
    int right_most = r-1;
    int flag = r;
    //{16,14,5,13, 10, 11,24,12,20,8}


    //{10, 80, 30, 90, 40, 50, 70}
    //{10, 80, 30, 50, 40, 90, 70}
    for (; l < mid or mid < right_most;) {
        cout << "l : " << nums[l] << " flag: " << nums[flag] << " right_most: " << nums[right_most] << endl;

        // l 크다
        if(nums[l] > nums[r]){
            //r 작다
            if(nums[right_most] < nums[r]){
                swap(l, right_most, nums);

            }else{
                //r 크
                swap(mid, l, nums);
            }

        }
        //l 작다
        else{
            //r 작다
            if(nums[right_most] < nums[r]){
                swap(mid, right_most, nums);
            }

        }
        l++;right_most--;
        printList(nums); cout << endl;

    }



//    swap(flag, mid, nums);
//    printList(nums); cout <<endl;

    //    if(nums[mid])
//    int tmp = nums[mid];
//    nums[mid] = nums[pivot];
//    nums[pivot] = tmp;
//    printList(nums); cout <<endl;

}

int main() {
    //                  0    1   2   3   4   5   6    7  8 9
    vector<int> nums = {10, 80, 70, 90, 40, 50, 30};//{16,14,20,13, 10,  5,24,12,8,11};   {16,14,5,13, 10, 11,24,12,20,8}
    //
    // 5 8 10 11 12 13 14 16 20 24


//    //{16,14,5,13, 10, 11,24,12,20,8}
//        /                        /
//    //{8,14,5,13, 10, 11,24,12,20,16}
//          /                  /
//    //{8,12,5,13, 10, 11,24,16,20,14}
//            /             /
//    //{8,12,5,13, 10, 11,24,16,20,14}
//               /       /
//    //{8,12,5,11, 10, 14,24,16,20,13}

    int len = nums.size();
    int l = 0;
    int r = len-1;
    int mid = l+ ((r-l)/2);

    quickConquer(l, mid, r, nums);
    //quickDivide(l, mid, r, nums);

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

























