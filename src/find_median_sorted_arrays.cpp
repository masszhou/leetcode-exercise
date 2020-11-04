#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void printout(vector<int>& n)
{
    for (auto each : n){
        std::cout << each << ",";
    }
    std::cout << std::endl;
}

double findMedianSortedArrays_lazy(vector<int>& nums1, vector<int>& nums2)
{
    double res;
    vector<int> num_all;
    num_all.reserve(nums1.size() + nums2.size());
    num_all.insert(num_all.end(), nums1.begin(), nums1.end());
    num_all.insert(num_all.end(), nums2.begin(), nums2.end());
    sort(num_all.begin(), num_all.end());

    if (num_all.empty()){
        res = 0.0;
    }else if (num_all.size() % 2 == 0){
        res = static_cast<double>(num_all[num_all.size()/2]) + static_cast<double>(num_all[num_all.size()/2-1]);
        res /= 2.0;
    }else{
        res = num_all[(num_all.size()-1)/2];
    }
    return res;
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
    // key idea, find the split boundary without merge two list
    double res;

    return res;
}

void test1()
{
    vector<int> n1 = {1, 2, 5, 6};
    vector<int> n2 = {3, 4};

    double res = findMedianSortedArrays_lazy(n1, n2);
    std::cout << res << std::endl;
}

int main(int argc, char* argv[])
{
    test1();
}