#include <iostream>
#include <vector>
using namespace std;

class BinarySearch{
public:
    int search(vector<int>& nums, int target) {

    }
};

int main() {

    vector<int> nums = {2,5};
    int len = nums.size();
    int first = 0;
    int end = len;
    int pivot = (first+end)/2;
    int target = 2;
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
    cout << answer;
//    auto *bs = new BinarySearch();
//    bs->search(nums, 9);





    return 0;
}


