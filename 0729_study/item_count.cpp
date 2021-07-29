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


int getCntRemain(vector<int>& arr) {
    int res=0;
    for(int i=1; i<=N; i++) {

        auto it = find(arr.begin(), arr.end(), i);
        if (it == arr.end()) {
            res++;
        }
    }
    return res;
}

void recursive(int depth, int bucket_size, vector<int> &pArr) {
    if( depth == bucket_size ) {
        print_arr(pArr);

        int remain = getCntRemain(pArr);
        pArr.clear();
        //pArr.pop_back();

        if(remain >= bucket_size ) {
            recursive(0, bucket_size, pArr);
        } else {
            // check 가 false 인 item들 출력
            vector<int> remain_v;
            for(int i=1; i<=arr.size(); i++) {
                if( check[i] == false) {
                    remain_v.push_back(arr[i-1]);
                }wx
            }
            print_arr(remain_v);
            //replace(check.begin(), check.end(), true, false);
            //pArr.clear();

        }
        return ;
    }

    for(int i=1; i<N+1; i++) {
        if( !check[i] ) {
            check[i] = true;
            pArr.push_back(i);
            recursive(depth+1, bucket_size, pArr);
            check[i] = false;
            //pArr.pop_back();
        }
    }
}


void solve() {

    for(int i=1; i<N; i++) {
        // i개씩 묶는 조합
        replace(check.begin(), check.end(), true, false);

        vector<int> pArr;
        recursive(0, i, pArr);
        cout << endl;

    }
    print_arr(arr);
}

int main(void) {

    cin >> N;

    check = vector<bool>(N+1, false);
    for(int i=1; i<=N; i++) {
        arr.push_back(i);
    }
    solve();
}