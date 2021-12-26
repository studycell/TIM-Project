//
//  relate.h
//  软件工程
//
//  Created by takeahint on 2021/12/25.
//

#ifndef relate_h
#define relate_h

#include <iostream>
#include <string>
using namespace std;

class Relate {
public:
    virtual void add()=0;
};

class Friend: public Relate {
public:
    void add(){};
};

class Group: public Relate {
public:
    void add(){};
};

class RelateFactory {
public:
    Relate *getRelate(char t) {
        if(t=='F') return new Friend();
        else return new Group();
    }
    void addfriends() {
        Relate *r;
        r=getRelate('F');
        cout<<"添加完成"<<endl;
    }
    void deletefriends() {
        cout<<"删除成功"<<endl;
    }
    void defriend() {
        cout<<"拉黑完成"<<endl;
    }
    void creategroups() {
        cout<<"创建成功"<<endl;
    }
    void joingroups() {
        cout<<"加入完成"<<endl;
    }
    void dissolvegroups() {
        cout<<"解散成功"<<endl;
    }
    void exitgroups() {
        cout<<"已退出"<<endl;
    }
}a;

class Classify {
public:
    virtual void doing() {};
    virtual void notdong() {};
};

class Sort1: public Classify {
public:
    void doing() {};
    void notdoing() {};
};

class Sort2: public Classify {
public:
    void doing() {};
    void notdoing() {};
};

class RelateCommand {
    Classify Sort;
public:
    RelateCommand(Classify s);
    virtual void executeCommand() {};
    virtual void cancelCommand() {};
};

class Task1: public RelateCommand {
    Classify Sort;
public:
    Task1(Classify s);
    void executeCommand() {};
    void cancelCommand() {};
};

class Task2: public RelateCommand {
    Classify Sort;
public:
    Task2(Classify s);
    void executeCommand() {};
    void cancelCommand() {};
};

class RelateInvoker {
    RelateCommand order;
    RelateCommand cancelorder;
public:
    void addOrder(RelateCommand task) {};
    void delOrder(RelateCommand task) {};
    void notifyDo() {};
    void notifyNotDo() {};
};
void R_menu() {
    cout << "\t\t\t\t**************************************" << endl;
    cout << "\t\t\t\t*                                    *" << endl;
    cout << "\t\t\t\t*         1.添加好友                  *" << endl;
    cout << "\t\t\t\t*         2.删除好友                  *" << endl;
    cout << "\t\t\t\t*         3.拉黑好友                  *" << endl;
    cout << "\t\t\t\t*         4.创建群聊                  *" << endl;
    cout << "\t\t\t\t*         5.加入群聊                  *" << endl;
    cout << "\t\t\t\t*         6.解散群聊                  *" << endl;
    cout << "\t\t\t\t*         7.退出群聊                  *" << endl;
    cout << "\t\t\t\t*         8.exit                     *" << endl;
    cout << "\t\t\t\t*                                    *" << endl;
    cout << "\t\t\t\t**************************************" << endl;
}
//
//  main.cpp
//  软件工程
//
//  Created by takeahint on 2021/12/25.
//

void Relate_main() {
    R_menu();
    int n;
    string num;
    bool running = 1;
    while (running) {
        cout << "Please choose:";
        cin >> n;
        if (!(n >= 1 && n <= 8)) {
            cout << "Invalid number" << endl;
            continue;
        }
        switch (n) {
            case 1: {
                cout << "Please input your friend's number:";
                cin >> num;
                if (num.length() > 11) {
                    cout << "Invalid number" << endl;
                    break;
                }
                a.addfriends();
                break;
            }
            case 2: {
                cout << "Please input your friend's number:";
                cin >> num;
                if (num.length() > 11) {
                    cout << "Invalid number" << endl;
                    break;
                }
                a.deletefriends();
                break;
            }
            case 3: {
                cout << "Please input your friend's number:";
                cin >> num;
                if (num.length() > 11) {
                    cout << "Invalid number" << endl;
                    break;
                }

                a.defriend();
                break;
            }
            case 4: {
                cout << "Please input the group's name:";
                cin >> num;
                a.creategroups();
                break;
            }
            case 5: {
                cout << "Please input the group's number:";
                cin >> num;
                if (num.length() > 11) {
                    cout << "Invalid number" << endl;
                    break;
                }
                a.joingroups();
                break;
            }
            case 6: {
                cout << "Please input the group's number:";
                cin >> num;
                if (num.length() > 11) {
                    cout << "Invalid number" << endl;
                    break;
                }
                a.dissolvegroups();
                break;
            }
            case 7: {
                cout << "Please input your friend's number:";
                cin >> num;
                if (num.length() > 11) {
                    cout << "Invalid number" << endl;
                    break;
                }
                a.exitgroups();
                break;
            }
            case 8: {
                running = 0;
                break;
            }
            default:
                break;
        }
    }
}

#endif /* relate_h */
