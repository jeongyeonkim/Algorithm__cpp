// 1410
#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<pair<string, string>> replace_mark;


// 68ms 19.3MB
void findReplace(string& str){
    for(int i=0; i<replace_mark.size(); i++){
        if(str.compare(replace_mark[i].first) == 0){
            str = replace_mark[i].second;
            break;
        }
    }
}

string entityParser(string text) {
    replace_mark.push_back(make_pair("&quot;", "\""));
    replace_mark.push_back(make_pair("&apos;", "\'"));
    replace_mark.push_back(make_pair("&amp;", "&"));
    replace_mark.push_back(make_pair("&gt;", ">"));
    replace_mark.push_back(make_pair("&lt;", "<"));
    replace_mark.push_back(make_pair("&frasl;", "/"));

    string result = "";
    string replace_word = "";
    bool flag1 = false;

    for(int i=0; i<text.length(); i++){
        if(text[i] == '&'){
            if(flag1){
                result += text[i];
            }else{
                flag1 = true;
                replace_word = text[i];
            }
        } else if (text[i] == ';' && flag1){
            replace_word += text[i];


            findReplace(replace_word);
            result += replace_word;
            replace_word = "";
            flag1 = false;
        } else if(flag1){
            replace_word += text[i];
        } else {
            result += text[i];
        }
    }

    return result;
}

//------------------------------------------------------------------------------------------------------------------------

// 800ms 34MB
string replace_str(string str, string beforeStr, string afterStr){
    string result = str;
    int startIndex = 0;
    int endIndex = 0;

    while ((startIndex = result.find(beforeStr, endIndex)) != string::npos) {
        result.replace(result.begin() + startIndex, result.begin() + startIndex + beforeStr.length(), afterStr);
        endIndex = startIndex + afterStr.length();
    }

    return result;
}

string entityParser_1(string text) {
    replace_mark.push_back(make_pair("&quot;", "\""));
    replace_mark.push_back(make_pair("&apos;", "\'"));
    replace_mark.push_back(make_pair("&gt;", ">"));
    replace_mark.push_back(make_pair("&lt;", "<"));
    replace_mark.push_back(make_pair("&frasl;", "/"));
    
    for(int i=0; i<replace_mark.size(); i++){
        text = replace_str(text, replace_mark[i].first, replace_mark[i].second);
    }

    text = replace_str(text, "&amp;", "&");
    return text;
}

int main(){
    string str = "&amp; is an HTML entity but &ambassador; is not.";
    cout << entityParser(str);
}