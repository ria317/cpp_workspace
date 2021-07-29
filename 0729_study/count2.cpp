#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> arr;
vector<bool> check;

//N 의 갯수 1~ N 까지
//

int func(vector<string>& v_arr, int new_num ) {

    int size = v_arr.size();

    if( new_num > N ) {
        return v_arr.size();
    }

    for(int i=0; i<size; i++) {
        if( v_arr[i].find(",") == string::npos ) {
            // 괄호가없는경우.
        } else {

        }
    }

    return func(v_arr, new_num+1);

}

int main(void) {

    cin >> N;
    for(int i=0; i<N; i++) {

        arr.push_back(i+1);
    }

    for(int i=1; i<=N ; i++) {
        func();
    }
}