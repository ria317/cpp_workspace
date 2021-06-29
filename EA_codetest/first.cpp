// from - 프로그래머스
// 3*8 사이즈의 배열이 주어지고, 알파벳(소문자)이 배치되어 있음.( map 이라고 함)
//  a,b,a,c,c,d,d,a
//  e,e,f,f,f,j,j,j
//  k,k,w,w,i,i,z,k

// given : 3*8 배열과, 단어 리스트가 주어졌을 때
// 해당 단어가 map 각 열에있는거 하나씩은 무조건 사용해야 하고
// e단어 spell들이 배열안에 다 존재해야 함.
// 알파벳은 map 한 열안에서만 존재하고 중복될 수있으며, 여러 열에 존재하지는 않는다.
// ex) 'a'가 첫번째 열에 있으면, 2,3, 번째 열에는 존재할 수 없음.

// 조건을 충족하는 단어만 출력하기
#include <iostream>
#include <vector>
#include <string>

using namespace std;

string solution(vector<string> map, vector<string> letters) {


    string answer ="";

    return answer;
}

int main(void) {

    vector<string> map = {
        "aabccabb",
        "efikefkj",
        "wzwvmnml"
    };

    vector<string> letters = {
        "acefm",
        "assbm",
        "uics",
        "fbcw"
    };

    string res = solution(map, letters);
}

