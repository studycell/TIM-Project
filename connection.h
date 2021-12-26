//
// Created by Lenovo on 2021/12/23.
//

#ifndef CFILES_CONNECTION_H
#define CFILES_CONNECTION_H
#include <iostream>
#include <map>
#include <iterator>
#include <cstring>
#include "kongjian.h"
#include "Files.h"
#include "gongzuotai.h"
#include "relationship.h"

using namespace std;

/*class Background */
class Background {
public:
    string getPersonalRecord(string name);
    string getPersonalSettings(string name);
    bool cleanPersonalRecord(string name);
    bool resetPersonalSettings(string name);
};
extern map<string, string> custom_data;
extern map<string, string> admin_data;

string Background::getPersonalRecord(string name) {
    map<string, string>::iterator l_it = custom_data.find(name);
    if(l_it == custom_data.end()) {
        cout << "background:没找到用户" << endl;
        return "background:查询用户记录失败";
    }
    /* 查询记录 */
    return "background:返回用户记录";
}

string Background::getPersonalSettings(string name) {
    map<string, string>::iterator l_it = custom_data.find(name);
    if(l_it == custom_data.end()) {
        cout << "background:没找到用户" << endl;
        return "background:查找用户设置信息失败";
    }
    /* 查找用户设置信息 */
    return "background:返回用户设置信息";
}

bool Background::cleanPersonalRecord(string name) {
    map<string, string>::iterator l_it = custom_data.find(name);
    if(l_it == custom_data.end()) {
        cout << "background:没找到用户" << endl;
        cout << "background:删除用户记录失败" << endl;
        return false;
    }
    /* 删除用户记录 */
    return true;
}

bool Background::resetPersonalSettings(string name) {
    map<string, string>::iterator l_it = custom_data.find(name);
    if(l_it == custom_data.end()) {
        cout << "background:没找到用户" << endl;
        cout << "background:重制用户设置信息失败" << endl;
        return false;
    }
    /* 修改用户设置信息 */
    return true;
}
/***********NewsOperation***************/
class Strategy {
public:
    virtual void doNewsOperations() = 0;

};

class NewsOperation_sendNews:public Strategy {
public:
    void doNewsOperations();    /* send news */
};
void NewsOperation_sendNews::doNewsOperations() {
    cout<<"send news!"<<endl;
}

class NewsOperation_revokeNews:public Strategy {
public:
    void doNewsOperations();    /* revoke news */
};
void NewsOperation_revokeNews::doNewsOperations() {
    cout<<"revoke news!"<<endl;
}

class NewsOperation_receiveNews: public Strategy {
public:
    void doNewsOperations();    /* receive news */
};
void NewsOperation_receiveNews::doNewsOperations() {
    cout<<"receive news!"<<endl;
}

class Context {
    Strategy * strategy;
public:
    Context(Strategy * strategy) {
        this -> strategy = strategy;
    }
    void executeStrategy() {
        strategy -> doNewsOperations();
    }
};

/*********people***************/
class People {
    string name;
    string passwd;
public:
    int login(string name, string passwd);
};

class Custom: People {
    string name;
    string passwd;
public:
    Custom(string name, string passwd):name(name),passwd(passwd){}
    Custom(){}
    bool createAccount(string name, string passwd);
    void doNewsOperations(string typeOfOperations);
    bool searchRecord(string typeOfRecord);
    int login(string name, string passwd);
    void manageRecord();
    void getPersonalSettings();

};
extern map<string, string> custom_data;
extern map<string, string> admin_data;

bool Custom::createAccount(string name, string passwd) {
    map<string, string>::iterator l_it = custom_data.find(name);
    if(l_it == custom_data.end()) {
        custom_data[name] = passwd;
        return 1;
    }
    return 0;

}

int Custom::login(string name, string passwd) {
    map<string, string>::iterator l_it = custom_data.find(name);
    if(l_it == custom_data.end()) {
        cout << "登录失败,没找到用户信息" << endl;
        return 3;
    }
    else if(l_it -> second != passwd) {
        cout << "登录失败,密码错误" << endl;
    }
    else if(l_it -> second == passwd){
        cout << "登录成功" << endl;
        cout << "欢迎进入用户界面" << endl;
        return 1;
    }
    return 0;
}

/* 因为没有去写后台类，所以这里的查找记录默认全都找到 */
bool Custom::searchRecord(string typeOfRecord) {
    string name;
    cout << "请输入要查询的联系人" << endl;
    cin >> name;
    map<string, string>::iterator l_it = custom_data.find(name);
    if(l_it == custom_data.end()) {
        cout << "没有找到联系人" << endl;
        return false;
    }
    /* 后期可以增加后台类，用vector来维护用户信息 */
    if(typeOfRecord == "word") {
        cout << "后台查询ing..." << endl;
        cout << "查询成功" << endl;
        cout << "返回记录" << endl;
        //cout << "search word successfully" << endl << endl;
    }
    else if(typeOfRecord == "image") {
        cout << "后台查询ing..." << endl;
        cout << "查询成功" << endl;
        cout << "返回记录" << endl;
        //cout << "search image successfully" << endl << endl;
    }
    else if(typeOfRecord == "video") {
        cout << "后台查询ing..." << endl;
        cout << "查询成功" << endl;
        cout << "返回记录" << endl;
        //cout << "search video successfully" << endl << endl;
    }
    else if(typeOfRecord == "emoji") {
        cout << "后台查询ing..." << endl;
        cout << "查询成功" << endl;
        cout << "返回记录" << endl;
        //cout << "search emoji successfully" << endl << endl;
    }
    return true;
}

void Custom::doNewsOperations(string typeOfOperations) {
    if(typeOfOperations == "send") {
        Context * context1 = new Context(new NewsOperation_sendNews());
        context1 -> executeStrategy();
        delete context1;
    }
    else if(typeOfOperations == "revoke") {
        Context * context2 = new Context(new NewsOperation_revokeNews);
        context2 -> executeStrategy();
        delete context2;
    }
    else if(typeOfOperations == "receive") {
        Context * context3 = new Context(new NewsOperation_receiveNews);
        context3 -> executeStrategy();
        delete context3;
    }
    else {
        //cout << "invalid operations" << endl;
        cout << "不合法的操作" << endl;
    }
}

void Custom::manageRecord() {
    //cout << "manage record successfully" << endl;
    Background background;
    bool isClean = background.cleanPersonalRecord(
            name);
    if(isClean == 1) {
        cout << "成功删除了一些久远的用户记录" << endl;
    }
    else {
        cout << "删除失败" << endl;
    }
}

void Custom::getPersonalSettings() {
    Background background;
    string settings = background.getPersonalSettings(name);
    cout << settings << endl;
}





class Admin: People {
    string name;
    string passwd;

public:
    Admin(string name, string passwd):name(name),passwd(passwd){}
    Admin(){}
    int login(string name, string passwd);
    void manageRecord(string name);
    void getPersonalRecord(string name);
    void getPersonalSettings(string name);
    void resetPersonalSettings(string name);
};
int Admin::login(string name, string passwd) {
    map<string, string>::iterator l_it = admin_data.find(name);
    if(l_it == custom_data.end()) {
        cout << "登录失败,没找到用户信息" << endl;
        return 4;
    }
    else if(l_it -> second != passwd) {
        cout << "登录失败,密码错误" << endl;
    }
    else if(l_it -> second == passwd){
        cout << "登录成功" << endl;
        cout << "欢迎进入管理员界面" << endl;
        return 2;
    }
    return 0;
}

void Admin::manageRecord(string name) {
    //cout << "manage record successfully" << endl;
    Background background;
    bool isClean = background.cleanPersonalRecord(name);
    if(isClean == 1) {
        cout << "成功删除了一些久远的用户记录" << endl;
    }
    else {
        cout << "删除失败" << endl;
    }
}

void Admin::getPersonalRecord(string name) {
    Background background;
    string record = background.getPersonalRecord(name);
    cout << record << endl;
}

void Admin::getPersonalSettings(string name) {
    Background background;
    string settings = background.getPersonalSettings(name);
    cout << settings << endl;
}

void Admin::resetPersonalSettings(string name) {
    Background background;
    bool isSettings = background.resetPersonalSettings(name);
    if(isSettings == 0) {
        cout << "重制用户设置信息失败" << endl;
    }
    else {
        cout << "重制用户设置信息成功" << endl;
    }
}




class PeopleFactory {
    string name;
    string passwd;
public:
    PeopleFactory(string name, string passwd) {
        this -> name = name;
        this -> passwd = passwd;
    }
    int getLogin(string typeOfPeople);
};
int PeopleFactory::getLogin(string typeOfPeople) {
    if(typeOfPeople == "custom") {
        Custom customForLogin;
        return customForLogin.login(name, passwd);
    }
    else if(typeOfPeople == "admin") {
        Admin adminForLogin;
        return adminForLogin.login(name, passwd);
    }
    return 0;
}



/* 后期可将custom_data和admin_data写到文件进行保存 */
map<string, string> custom_data;
map<string, string> admin_data;

//初始化用户数据custom_data、管理员数据admin_data
void initPersonData() {
    custom_data["C1"] = "123";
    custom_data["C2"] = "456";
    admin_data["A1"] = "123";
    admin_data["A2"] = "456";
}

void timeForCustom(string, string);
void timeForAdmin(string, string);
void connection_main();

void connection_main() {
    string type;
    string name;
    string passwd;
    string typeOfPeople;
    string isToRegister;
    int isLogin = 0;

    initPersonData();
    cout << "       welcome come to TIM    " << endl << endl;
    cout << "请输入你的登录类型(custom or admin)、名字、密码" << endl;
    cin >> typeOfPeople >> name >> passwd;

    PeopleFactory peoplefactory(name, passwd);
    isLogin = peoplefactory.getLogin(typeOfPeople);
    if(isLogin == 1) {
        timeForCustom(name, passwd);
    }
    else if(isLogin == 2) {
        timeForAdmin(name, passwd);
    }
    else if(isLogin == 3) {
        cout << "你希望我们为你创建一个用户账号吗(input y or n)" << endl;
        cin >> isToRegister;
        if(isToRegister == "y") {
            Custom customForRegister;
            bool isCreate = customForRegister.createAccount(name, passwd);
            if(isCreate == 1) {
                cout << "成功创建用户账户" << endl;
            }
            else {
                cout << "创建用户账户失败" << endl;
            }
        }
    }
    else if(isLogin == 4) {
        cout << "无法登录管理员账户" << endl;
    }

    //return 0;
}

void timeForCustom(string name, string passwd) {
    Custom custom(name, passwd);
    int thing;
    /* custom */
    while(1) {
        cout << "\t\t\t请输入你想做的事" << endl;
        cout << "\t\t********************************" << endl;
        cout << "\t\t\t1.createAccount" << endl;
        cout << "\t\t\t2.send news" << endl;
        cout << "\t\t\t3.revoke news" << endl;
        cout << "\t\t\t4.receive news" << endl;
        cout << "\t\t\t5.search records" << endl;
        cout << "\t\t\t6.manage records" << endl;
        cout << "\t\t\t7.get settings" << endl;
        cout << "\t\t\t8.kongjian" << endl;
        cout << "\t\t\t9.File_manger" << endl;
        cout << "\t\t\t10.Workbench" << endl;
        cout << "\t\t\t11.Relational system"<<endl;
        cout << "\t\t\t0.quit"<<endl;
        cout << "\t\t********************************" << endl;
        cin >> thing;
        if(thing == 1) {
            string newName;
            string newPasswd;
            cout << "请为新账户输入名字和密码" << endl;
            cin >> newName >> newPasswd;
            bool isCreate = custom.createAccount(newName, newPasswd);
            if(isCreate == 1) {
                //cout << "create custom account successfully" << endl;
                cout << "用户账户创建成功" << endl;
            }
            else {
                //cout << "custom account aready exits" << endl;
                cout << "该用户账户已经存在" << endl;
            }
        }
        else if(thing == 2) {
            custom.doNewsOperations("send");
        }
        else if(thing == 3) {
            custom.doNewsOperations("revoke");
        }
        else if(thing == 4) {
            custom.doNewsOperations("receive");
        }
        else if(thing == 5) {
            string typeOfRecord;
            bool isSearch;
            //cout << "input type of records you want to search(word、image、video、emoji)" << endl;
            cout << "请输入你要查询的记录类型(word、image、video、emoji)" << endl;
            cin >> typeOfRecord;
            isSearch = custom.searchRecord(typeOfRecord);
            if(isSearch == 0) {
                //cout << "do not find the record" << endl;
                cout << "没有找到该记录" << endl;
            }
        }
        else if(thing == 6) {
            custom.manageRecord();
        }
        else if(thing == 7) {
            custom.getPersonalSettings();
        }
        else if(thing == 8){

            space_main(name);
        }
        else if(thing == 9)
        {
            Workbench();
        }
        else if(thing == 10)
        {
            gongzuotai();
        }
        else if(thing == 11)
        {
            Relate_main();
        }

        else if(thing == 0) {
            //cout << "succeed to quit" << endl;
            cout << "成功退出" << endl;
            break;
        }
    }
}

void timeForAdmin(string name, string passwd) {
    Admin admin(name, passwd);
    int thing;
    string customName;
    /* admin */
    while (1) {
        //cout << "input things you want to do" << endl;
        cout << "请输入你想做的事" << endl;
        cout << "*****" << endl;
        cout << "1.manage record" << endl;
        cout << "2.get custom record" << endl;
        cout << "3.get custom settings" << endl;
        cout << "4.reset custom settings" << endl;
        cout << "5.quit" << endl;
        cout << "*****" << endl;
        cin >> thing;
        if (thing == 1) {
            cout << "请输入管理的用户名字" << endl;
            cin >> customName;
            admin.manageRecord(customName);
        } else if (thing == 2) {
            cout << "请输入管理的用户名字" << endl;
            cin >> customName;
            admin.getPersonalRecord(customName);
        } else if (thing == 3) {
            cout << "请输入管理的用户名字" << endl;
            cin >> customName;
            admin.getPersonalSettings(customName);
        } else if (thing == 4) {
            cout << "请输入管理的用户名字" << endl;
            cin >> customName;
            admin.resetPersonalSettings(customName);
        } else if (thing == 5) {
            //cout << "succeed to quit" << endl;
            cout << "成功退出" << endl;
            break;
        }
    }
}
#endif //CFILES_CONNECTION_H
