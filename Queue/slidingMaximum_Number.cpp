#include<iostream>
#include<queue>
#include<vector>

using namespace std;

vector<int> MaxNum(vector<int>& arr,int k){
    if(k <=0 && k > arr.size()){
        return {-1};
    }

    vector<int> ans;
    priority_queue<int> pq;

    int maxnum = arr[0];
    for(int i =0;i<k;i++){
        pq.push(arr[i]);
    }

    ans.push_back(pq.top());

    for(int i=k;i<arr.size();i++){
        if(arr[i-k] == pq.top()){
            pq.pop();
        }
        pq.push(arr[i]);
        ans.push_back(pq.top());
    }

    return ans;
}

int main(){
    vector<int> arr = {1,3,-1,-3,5,3,6,7};
    int k = 3;

    vector<int> ans = MaxNum(arr,k);

    for(int i =0;i<ans.size();i++){
        cout<<ans[i]<<",";
    }
    cout<<endl;

    return 0;
}