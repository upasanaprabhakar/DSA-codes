#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int minProduct(vector<int>&arr){
    int cn=0,cz=0,cp=0;
    int prod_pos=1;
    int prod_neg=1;
    int largest_negative=INT_MIN;
    for(int i=0;i<arr.size();i++){
        if(arr[i]<0){
            cn++;
            prod_neg*=arr[i];
            largest_negative=max(largest_negative,arr[i]);
        }
        if(arr[i]==0) cz++;
        if(arr[i]>0){
            cp++;
            prod_pos*=arr[i];
        }
    }
    if(cn==0){
        if(cz>0) return 0;
        else{
            auto it=min_element(arr.begin(),arr.end());
            return *it;
        }
    }
    else{
        if(cn%2==0){
            //even
            return(prod_neg/largest_negative)*prod_pos;
        }
        else{
            //odd
            return prod_neg*prod_pos;
        }
    }

}
int main()
{
    vector<int>arr={11,2,-1,-2,-3,3};
    cout<<minProduct(arr)<<"\n";   
    return 0;
}