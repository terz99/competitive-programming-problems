#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <cstring>

// constants used for the 'sign' array
const int EMPTY = 0;
const int POSITIVE = 1;
const int NEGATIVE = 2;

std::string transform(std::string one){

    // initialize 'sign' array to EMPTY
    int sign[105];
    for(int i = 0; i < 105; i++){
        sign[i] = EMPTY;
    }

    // before every alphabetic character there should be a sign that is why
    // we check if there is a sign before the first char. If not just add +
    if(one[0] != '-' || one[0] != '+'){
        one = "+" + one;
    }

    // modify the 'sign' array so every it contains data about the signs for
    // elements in the expression
    for(int i = 0; i < (int)one.length(); i++){

        if(isalpha(one[i])){
            if(one[i-1] != '-'){
                sign[i] = POSITIVE;
            } else {
                sign[i] = NEGATIVE;
            }
        }
    }

    // invert the signs of the elements which are within brackets and there is
    // a minus before the opening of the brackets
    std::stack<int> s;
    for(int i = 0; i < (int)one.length(); i++){

        if(one[i] == '('){
            s.push(i);
        } else if(one[i] == ')'){

            int startIdx = s.top();
            s.pop();
            if(one[startIdx-1] == '-'){

                for(int j = startIdx+1; j < i; j++){

                    if(sign[j] == POSITIVE){
                        sign[j] = NEGATIVE;
                    } else if(sign[j] == NEGATIVE){
                        sign[j] = POSITIVE;
                    }
                }
            }
        }
    }

    // simplify the expression by using the 'sign' array and omitting the brackets
    std::string res;
    for(int i = 0; i < (int)one.length(); i++){

        if(isalpha(one[i])){

            if(sign[i] == POSITIVE){
                res += "+";
            } else if(sign[i] == NEGATIVE){
                res += "-";
            }
            res += one[i];
        }
    }

    // initialize and modify the 'sign' array accordingly because the size of
    // the expression has changed
    for(int i = 0; i < 105; i++){
        sign[i] = EMPTY;
    }
    for(int i = 0; i < (int)res.length(); i++){

        if(isalpha(res[i])){
            if(res[i-1]  == '+'){
                sign[i] = POSITIVE;
            } else {
                sign[i] = NEGATIVE;
            }
        }
    }


    // cancel all the elements in the array which are the same but have
    // different signs (if any)
    int vis[26];
    memset(vis, -1, sizeof(vis));

    for(int i = 0; i < (int)res.length(); i++) {

        if (isalpha(res[i])) {

            int idx = (int) (res[i]-'a');
            if (vis[idx] != -1) {

                if (sign[i] != sign[vis[idx]]) {
                    res[i] = '_';
                    res[i-1] = '_';
                    res[vis[idx]] = '_';
                    res[vis[idx]-1] = '_';
                    vis[idx] = -1;
                }
            } else {
                vis[idx] = i;
            }
        }
    }

    // construct the final simplified expression and return it
    std::string tmp = res;
    res = "";
    for(int i = 0; i < (int)tmp.length(); i++){
        if(tmp[i] != '_'){
            res += tmp[i];
        }
    }

    return res;
}

int main() {

    int cases;
    std::cin >> cases;
    while(cases--){

        std::string one, two;
        std::cin >> one;
        std::cin >> two;

        one = transform(one);
        two = transform(two);

        // put all the chars from the expression strings in vectors and sort
        // them to avoid commutativity problems
        std::vector<char> vOne, vTwo;
        for(int i = 0; i < (int)one.length(); i++){
            vOne.push_back(one[i]);
        }
        for(int i = 0; i < (int)two.length(); i++){
            vTwo.push_back(two[i]);
        }
        std::sort(vOne.begin(), vOne.end());
        std::sort(vTwo.begin(), vTwo.end());

//        std::cout << one << std::endl;
//        std::cout << two << std::endl;
        if(vOne == vTwo){
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }

    return 0;
}