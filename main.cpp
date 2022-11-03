#include <iostream>
#include <vector>
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

void printArray(int arr[]){
    int len = sizeof(arr);

    for(int i=0; i<len; i++){
        cout << arr[i] << ' ';
    }

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

int temp[8];

//            if(nums[i] > nums[j]){
//                int tmp = nums[right];
//                nums[right] = nums[i];
//                nums[i] = tmp;
//            }

void conquer(int left, int mid, int right, vector<int>& nums){

    int idx = left;
    //int flag = 0;
    int pivot = mid+1;

    //21 56 2 89

    for (int i = left; i <= mid; ++i) {

        for (int j = pivot; j <= right; ++j) {

            if(nums[i] > nums[j]){

                temp[idx++] = nums[j];
            }
            else{
                if(i==mid){temp[idx] = nums[j];}
                else{temp[idx++] = nums[i]; pivot = j;}
                break;
            }

        }

    }
    cout << "conquer : "; printArray(temp); cout << endl;
}

void divide(int left, int mid, int right, vector<int>& nums){
    cout << "left : " << left << " mid : " << mid << " right : " << right << endl;

    if(left == mid){

        cout << "nums left : "<< nums[left] << endl;
        conquer(left, mid, right, nums);
        //temp[left] = nums[left];
    }
    else{

        divide(mid+1, ((mid+1)+right)/2, right, nums);
        conquer(left, mid, right, nums);
        divide(left, (left+mid)/2, mid, nums);
        conquer(left,  mid, right, nums);
    }


}


//21 56    2 89

int main() {
                      //0 1 2  3  4  5  6 7
    vector<int> nums = {8,9,5,98,56,21,89,2};

    int len = nums.size();
    int left = 0;
    int right = len-1;
    int mid = (left + right)/2;

    divide(left, mid, right, nums);

    //printArray(tmp);








    return 0;
}























