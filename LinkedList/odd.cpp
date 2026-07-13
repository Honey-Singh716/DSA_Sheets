#include <iostream>
#include <vector>

using namespace std;


vector<int> oddNumbers(int l, int r) {
    vector<int> ans;
    
    int i = l;
    while(i<=r){
        
        if(i%2 == 0){
            i++;
        }
        else{
            ans.push_back(i);
            i += 2;
        }
    }
    
    return ans;
}


int main(){
    int l = 2;
    int r = 5;

    vector<int> result;

    result = oddNumbers(2,5);
   
    for(auto i : result){
        cout << i << " ";
    }

}