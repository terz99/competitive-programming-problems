#include <bits/stdc++.h>
using namespace std;

int findMinChanges(vector< vector<char> >& mat, int& n){

    if(n == 1){
        return 0;
    }
    
    int one_size = 0;
    int two_size = 0;
    int one[26];
    int two[26];
    int start_one[] = {0, 1};
    int start_two[] = {1, 0};
    memset(one, 0, sizeof(one));
    memset(two, 0, sizeof(two));
    for(int i = 0; i < n; i++){
        for(int j = start_one[i%2]; j < n; j += 2){
            one[(int)(mat[i][j]-'a')]++;
            one_size++;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = start_two[i%2]; j < n; j += 2){
            two[(int)(mat[i][j]-'a')]++;
            two_size++;
        }
    }

    vector< pair<int, char> > vOne, vTwo;
    for(int i = 0; i < 26; i++){
        if(one[i]){
            vOne.push_back( make_pair(one[i], (char)(i+'a')) );
        }
        if(two[i]){
            vTwo.push_back( make_pair(two[i], (char)(i+'a')) );
        }
    }

    sort(vOne.rbegin(), vOne.rend());
    sort(vTwo.rbegin(), vTwo.rend());

    if(vOne[0].second == vTwo[0].second){

        vOne.push_back( make_pair(0, ' ') );
        vTwo.push_back( make_pair(0, ' ') );

        return min((one_size-vOne[0].first)+(two_size-vTwo[1].first), 
        (one_size-vOne[1].first)+(two_size-vTwo[0].first));
    } else {
        return (one_size-vOne[0].first)+(two_size-vTwo[0].first);
    }
}

int main() {

    srand(static_cast<unsigned int>(time(NULL)));

    while(true) {

        char op;
        cin >> op;
        if(op == 'q') break;

        int n;
        vector< vector<char> > mat;
        if(op == 'n') {

            cin >> n;
            mat.resize(static_cast<unsigned long>(n));
            for (int i = 0; i < n; i++) {
                mat[i].resize(static_cast<unsigned long>(n));
                for (int j = 0; j < n; j++) {
                    cin >> mat[i][j];
                }
            }
        } else if(op == 'r') {

            n = rand() % 10 + 1;
            mat.resize(static_cast<unsigned long>(n));
            for (int i = 0; i < n; i++) {
                mat[i].resize(static_cast<unsigned long>(n));
                for (int j = 0; j < n; j++) {
                    int tmp = rand() % 26;
                    mat[i][j] = (char) (tmp + 'a');
                }
            }
        } else {
            continue;
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
        cout << findMinChanges(mat, n) << endl;
    }

    return 0;
}