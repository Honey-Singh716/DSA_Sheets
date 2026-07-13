#include <iostream>
using namespace std;

void towerOfHanoi(int n, char source, char helper, char destination,int& count) {
    if (n == 1) {
        cout << "Move disk 1 from " << source
             << " to " << destination << endl;
        count++;
        return;
    }

    towerOfHanoi(n - 1, source, destination, helper,count);

    cout << "Move disk " << n
         << " from " << source
         << " to " << destination << endl;
    count++;

    towerOfHanoi(n - 1, helper, source, destination,count);
}

int main() {
    int n = 3;
    int count =0;
    towerOfHanoi(n, 'A', 'B', 'C',count);

    cout<<count<<endl;
}