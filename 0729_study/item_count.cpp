#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> arr;
vector<bool> check;

void print_arr(vector<int> a) {
    cout << "(";
    for(int i=0; i<a.size(); i++) {
        cout << a[i];
    }
    cout << ")";


}


void recursive(int depth, int cnt, vector<int> &pArr) {
    if( depth == cnt+1 ) {
        print_arr(pArr);
        pArr.clear();
        return ;
    }

    for(int i=1; i<=cnt; i++) {
        if( !check[i]) {
            check[i] = true;
            pArr.push_back(i);
            recursive(depth+1, cnt, pArr);
            check[i] = false;

        }
    }
}

void solve() {

    for(int i=1; i<=N; i++) {
        vector<int> a = {i};
        print_arr(a);
    }
    for(int i=2; i<N; i++) {
        // i개씩 묶는 조합
        replace(check.begin(), check.end(), true, false);

        vector<int> pArr;
        recursive(1, i, pArr);

    }

    print_arr(arr);
}

int main(void) {

    cin >> N;

    check = vector<bool>(N, false);

    for(int i=1; i<=N; i++) {
        arr.push_back(i);
    }
    solve();
}