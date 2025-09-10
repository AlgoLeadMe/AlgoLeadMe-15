#include<bits/stdc++.h>

using namespace std;

struct chat {
    char c;
    string id, name;
};

map<string, string> mp; // id, name

chat toChat(string input) {
    vector<string> sv; string temp;
    stringstream ss(input);

    while(getline(ss, temp, ' ')) {
        sv.push_back(temp);
    }

    if(sv.size() == 2) {
        return {'l', sv[1], mp[sv[1]]};
    }

    if(sv.size() == 3) {
        mp[sv[1]] = sv[2];

        if(sv[0] == "Enter") return {'e', sv[1], sv[2]};
        else{ // change
             return {'c', sv[1], sv[2]};
        }
    }
}

string toKoreanChat(chat ct) {
    string temp = "";
    string name = mp[ct.id];
    if(ct.c == 'l') {
        temp = name + "님이 나갔습니다.";
    }

    if(ct.c == 'e') {
        temp = name + "님이 들어왔습니다.";
    }

    return temp;
}

vector<string> solution(vector<string> rv) {
    vector<string> res;
    vector<chat> chats;
    for(int i = 0; i < rv.size(); i++) {
        auto ct = toChat(rv[i]);
        if(ct.c != 'c') chats.push_back(toChat(rv[i]));
    }

    for(auto ct : chats) {
        res.push_back(toKoreanChat(ct));
    }

    return res;
}
