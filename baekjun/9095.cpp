// 9095번 1,2,3 더하기
#include <iostream>
#include <vector>

using namespace std;


void func(int cnt1, int cnt2, int cnt3, int n, int& count) {

    int checked = ( 3*cnt3 + 2*cnt2 + 1*cnt1 );
//cout << "checked = " << checked << endl;
    if( checked > n ) return ;
    else if( checked == n ) {
        count = count+1;
        //cout << "count value : " << count << cnt3 << cnt2 << cnt1 << endl;
        //return ;
    } else {
        func(cnt1+1, cnt2, cnt3, n, count);
        func(cnt1, cnt2+1, cnt3, n, count);
        func(cnt1, cnt2, cnt3+1, n, count);
    }

}


void solve(int n) {

    vector<int> input(n, -1);

    for(int i=0; i<n; i++) {
        cin >> input[i];
    }
   int res = 0;
   for(int i=0;i<n; i++) {
       res = 0;
       func(0,0,0,input[i], res);

       cout << res << endl;
   }

}

int main(void) {

    int N;
    cin >> N;

    solve(N);
}