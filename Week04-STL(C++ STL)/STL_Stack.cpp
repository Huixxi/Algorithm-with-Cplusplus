#include <iostream>
#include <stack>
using namespace std;

int main(){
    stack<int> sta;  // LIFO(last in first out)
    for(int i = 0; i < 10; ++i)
        sta.push(i);
    while(!sta.empty()){
	int no = sta.top();
        sta.pop();
	cout << no << endl;
    }
    return 0;
}
