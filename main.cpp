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

    vector<int> conquer(int left, int mid, int right, int target, vector<int>& nums){

        int idx = left;
        int pivot = mid+1;
        vector<int> answer(2,0);
        int flag = 0;

        while(flag==0 && idx <= mid){

            for (; pivot <= right; ++pivot) {

                if(nums[idx] + nums[pivot] ==target){
                    //cout << "answer : " << idx+1 << ", " << pivot+1 << endl;
                    answer[0] = idx+1; answer[1] = pivot+1;

                    flag = 1;
                    break;

                }
            }
            idx++;
            pivot = mid+1;
        }

        return answer;
    }



    vector<int> mergeSort(int left, int mid, int right, int target, vector<int>& nums){
        //cout << "l " << left << " m "<< mid << " r "<< right <<endl;
        vector<int> answer(2);
        if(left <mid){

            answer = mergeSort(left, (left+mid)/2, mid, target, nums);
            if(answer[0]!=0){ return answer;}

            answer = mergeSort(mid+1, ((mid+1)+right)/2, right, target, nums);
            if(answer[0]!=0){ return answer;}

        }
        return conquer(left, mid, right, target, nums);

    }
};


int main() {
    //                  0  1  2 3 4  5   6   7       8        9     10 11  12
    vector<int> nums = {3,3,5,8,18,21,22,22,22,24,26};//{3,3,5,8,18,21,22,22,22,24,26,28,29,31,31,34,37,37,40,43,43,43,44,47,48,51,51,51,52,54,55,56,59,59,60,74,74,76,76,81,82,82,82,85,89,91,91,94,99,101,101,106,116,118,121,126,127,128,128,128,131,134,135,138,140,143,145,151,152,153,154,156,158,158,158,160,169,173,174,177,178,180,189,190,190,191,191,196,197,203,203,206,206,206,208,210,212,215,216,218,218,219,223,225,227,229,232,232,233,234,235,235,236,237,238,239,245,249,250,251,254,254,256,260,261,262,270,271,271,274,275,284,285,286,290,290,291,292,292,293,293,293,295,299,300,304,304,305,310,313,313,315,322,326,327,329,334,336,337,339,339,340,341,343,344,347,347,356,356,359,359,361,364,364,368,368,369,376,378,380,380,380,386,387,389,391,391,397,399,404,405,413,415,418,418,423,426,428,429,430,432,434,437,439,459,460,461,461,463,472,479,480,484,484,486,487,492,494,498,499,500,501,501,504,505,505,507,513,517,517,519,519,522,525,525,529,530,530,533,536,537,538,539,542,544,553,557,561,561,564,567,568,568,570,570,572,574,575,575,579,580,581,582,590,591,594,594,597,600,605,607,608,611,614,615,615,619,621,622,623,626,627,628,630,631,632,634,638,640,641,642,648,648,649,659,662,668,673,678,678,682,682,683,683,686,686,687,691,692,693,698,700,700,706,711,711,712,714,714,718,722,727,730,730,733,733,741,744,745,747,749,754,755,755,758,760,762,763,764,769,770,771,771,776,777,784,785,789,790,792,795,795,796,797,798,806,806,806,809,812,813,815,819,820,823,827,830,837,840,843,848,850,851,851,852,857,858,858,859,861,863,866,869,869,873,874,874,883,885,887,889,891,893,899,901,903,905,905,905,909,912,917,919,920,921,922,926,935,940,941,944,945,
    // 946,947,948,950,950,951,952,956,956,959,962,964,965,968,970,971,971,972,973,976,978,982,983,985,985,988,989,991,994,994,995,995,997,997};//,56, 5, 0, 0, 3, 2, 0, 6, 8, 0, 0, 0};

    int r = nums.size()-1;
    int l = 0;
    int mid = l+ (r-l)/2;
    int target = 6;

    vector<int> answer(2);

    if(r+1<4){
        int pivot = 1;
        while(l <= 1){

            for (;  pivot <= r; ++pivot) {
                //cout << l << pivot <<endl;
                if((nums[l] + nums[pivot]) == target){

                    answer[0] = l+1; answer[1] = pivot+1;
                    break;
                }
            }
            l++;
            pivot = 2;
        }
    }
    else{
        TwoSumII ts;
        answer = ts.mergeSort(l, mid,r, target, nums);
        printList(answer);
    }

    return 0;
}




//    if(r==1){ printList(nums);}
//    int l = 0;
//    int pivot = r;
//    int target = 100;
//
//    for (int i=0; i<5;i++) {
//        cout << "l :  " << l << " r : " << r << endl;
//        if(nums[r]>target){ r--; }
//        if(nums[l]>target){ r = l-1; }
//
//        if(nums[r]+nums[l]==target){
//            //cout << nums[r] << " , " << nums[l];
//            printf("%d, %d\n", l+1, r+1);
//            break;
//        }
//        else if(nums[r]+nums[l]> target){ r--; continue;}
//        else{ l++;}
//
//    }







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

























