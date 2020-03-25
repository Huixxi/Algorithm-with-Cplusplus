#include <iostream>
#include <queue>
using namespace std;

int main(){
    queue<int> q;  // FIFO(fast in first out)
    for(int i = 0; i < 10; ++i)
        q.push(i);
    while(!q.empty()){
	int no = q.front();
        q.pop();
	cout << no << endl;
    }
    return 0;
}
