#include <bits/stdc++.h>
#define v_int vector<int>
using namespace std;

bool inRange(int n,int l, int r) {
    return n>=l && n<=r;
}

bool insideBoundary(int x, int y, int n) {
    return inRange(x , 0, n-1) && inRange(y, 0, n-1);
}

v_int square[100];
int max_orders = 0;

int explore(int x,int y, int n, int order) {

    if(!insideBoundary(x, y, n) || square[x][y]==-1) {
        return 0;
    }
    order+=square[x][y];

    // dest_x = n-1, dest_y = n-1;
    if(x==n-1 && y==n-1) {
        max_orders = max(order, max_orders);
        return max_orders;
    }

    int right = explore(x, y+1, n, order);
    int down = explore(x+1, y, n, order);

    return max(right,down);

}


int main() {

    int n;
    cin>>n;

    int order = 0;


    // 3
    // 0 1 -1
    // 1 0 0
    // 1 1 1
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            int tem;
            cin>>tem;
            square[i].push_back(tem);
        }
    }

    // explore(source_x ,source_y , n, orders)
    cout<<explore(0,0,n,0)<<endl;
    // 4
    return 0;
}
