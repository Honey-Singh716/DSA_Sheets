// #include<iostream>
// #include<queue>
// #include<vector>

// using namespace std;

// int dialor(int n){
//     if(n < 0){
//         return -1;
//     }
//     if(n == 0){
//         return 0;
//     }

//     vector<vector<int>> visited(10,vector<int>(10,0));
//     vector<vector<int>> moves = {{-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1}};

//     queue<pair<int,int>> q;
//     int count = 0;
//     int freq = 0;
//     for(int i =1;i<=6;i++){
//         q.push({i,0});
//         visited[0][i] = 1;

//         while(!q.empty()){
//             count++;

            
//             if(count == n){
//                 freq++;
//                 count = 0;
//             }


//         }
//     }

// }