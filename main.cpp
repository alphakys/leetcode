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

int main() {
    //10개
    vector<int> nums = {0,0,0,1,1,1,1,1,1,1};
    int n = 10;
    int first = 0;
    int end = n;

    int pivot = 10;
    int i = 0;
    while(i<=10){
        cout << "first : " << first << " pivot : " << pivot << " end : " << end << endl;

        if(nums[pivot]==1){
            end = pivot-1;
            pivot = (first + end)/2;
        }
        else{

        }

        i++;



    }





    return 0;
}


