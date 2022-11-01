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


int main() {
    //10개
    vector<int> nums = {1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    int n = nums.size();
    int first = 0;
    int end = n;

    int pivot = n-1;

    while(first<=pivot){
        cout << "first : " << first << " pivot : " << pivot << " end : " << end << endl;

        //if(first==pivot ){ break;}
        if(nums[pivot]==1 && nums[pivot-1]==1){
            end = pivot-1;
            pivot = (first + end)/2;

        }
        else if(nums[pivot]==1 && nums[pivot-1]==0){
            //1과 end 사이에서 마지막 0을 찾아야함
            //그리고 현재까지는 가장 작은 1이 end임을 알 수 있다. 하지만 더 작은 1이 있을 수 있으니 찾아야함
//            first = pivot+1;
//            pivot = (first + end)/2;
            cout << pivot;
            break;
        }
        else if(nums[pivot]==0 && nums[pivot+1]==0){

            first = pivot+1;
            pivot = (first + end)/2;
            //break;
        }
        else{
            cout << pivot+1;
            break;
        }

    }





    return 0;
}


