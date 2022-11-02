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



int main() {
    //10개
    vector<int> nums = {8,9,5,98,56,21,89,2};

    int len = nums.size();
    int left = 0;
    int right = len-1;
    int mid = (left + right)/2;

    while(left<=mid){
        cout << "first : " << left << " pivot : " << mid << " end : " << right << rightl;

        if(left==mid && nums[mid] != target){ answer = right; break;}

        if(nums[mid] < target){
            left = mid;
            mid = (left + right)/2;

        }
        else if(nums[mid]== target ) {
            answer = mid;
            break;
        }
        else if(nums[mid]> target){
            right = mid;
            mid = (left + right)/2;

        }

    }




    return 0;
}























