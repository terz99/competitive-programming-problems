#include <iostream>
#include <set>

class Trie{

public:

    // constructors

    Trie(){
        root = NULL;

    }

    // service methods

    void insert(const std::string& input){

        if(root == NULL){
            root = new Node;
        }

        insertPrivate(root, input, 0);
    }

    std::set<std::string> getSuggestions(std::string& str){
        std::set<std::string> res;
        getSuggestionsPrivate(root, str, 0, res, "");
        return res;
    }

private:

    struct Node{

        bool isEnd;
        Node *edges[26];

        // constructors

        Node(){
            for(int i = 0; i < 26; i++) {
                edges[i] = NULL;
            }
            isEnd = false;
        }

        // destructors

        ~Node(){
        }
    };

    Node *root;

    // service methods

    int getInt(const char& c){
        return (int)(c-'a');
    }

    void insertPrivate(Node *p, std::string input, int idx){

        if(idx == (int)input.length()){
            p->isEnd = true;
            return;
        }
//        std::cout << input[idx] << std::endl;
        int next = getInt(input[idx]);
        if(p->edges[next] == NULL){
            p->edges[next] = new Node;
//            std::cout << "New edges created\n";
        }
        insertPrivate(p->edges[next], input, idx+1);

    }

    void getSuggestionsPrivate(Node *p, std::string str, int idx,
                               std::set<std::string> &res, std::string resstr){

        if(idx < (int)str.length()){

            int next = getInt(str[idx]);
            if(p->edges[next] != NULL){
                getSuggestionsPrivate(p->edges[next], str, idx+1, res,
                                      resstr + str[idx]);
            }
        } else {

            if(p->isEnd){
                res.insert(resstr);
            }

            for(int i = 0; i < 26; i++){
                if(p->edges[i] != NULL){
                    getSuggestionsPrivate(p->edges[i], str, idx, res,
                                          resstr + (char)(i+'a'));
                }
            }
        }
    }
};

int main() {

    int cases;
    std::cin >> cases;
    while(cases--){

        Trie t;
        int n;
        std::cin >> n;
        std::string input;
        for(int i = 0; i < n; i++){
            std::cin >> input;
            t.insert(input);
        }

        std::string query;
        std::cin >> query;
        for(int i = 1; i <= (int)query.length(); i++){

            std::string str = query.substr(0, i);
//            std::cout << str << std::endl;
            std::set<std::string> suggestions;
            suggestions = t.getSuggestions(str);
            if(suggestions.size() == 0){
                std::cout << 0 << std::endl;
                continue;
            }
            for(auto it = suggestions.begin(); it != suggestions.end(); it++){
                std::cout << *it << " ";
            }
            std::cout << std::endl;
        }
    }

    return 0;
}