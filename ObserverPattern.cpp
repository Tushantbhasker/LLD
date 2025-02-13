#include<bits/stdc++.h>
using namespace std;

class ISubscriber {
    public:
    virtual void notify() = 0;
};

class User : public ISubscriber{
    int id;
    public:
    User(int id) : id(id) {}
    void notify(){
        cout << "user:" << id << " notified" << endl;
    }
};
class Group {
    list<ISubscriber*> users;
    public:
    void notify(string s){
        for(auto& it : users){
            it->notify();
        }
    }
    void susbcribe(ISubscriber* user){
        users.push_back(user);
    }
    void romove(ISubscriber* user){
        users.remove(user);
    }

};

int main(){
    Group * group = new Group();

    User *user1 = new User(1);
    User *user2 = new User(2);
    User *user3 = new User(3);

    group->susbcribe(user1);
    group->susbcribe(user2);
    group->susbcribe(user3);

    group->notify("new msg");
    group->romove(user2);
    group->notify("new msg");

    return 0;
}