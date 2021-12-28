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
        cout << "background:û�ҵ��û�" << endl;
        return "background:��ѯ�û���¼ʧ��";
    }
    /* ��ѯ��¼ */
    return "background:�����û���¼";
}

string Background::getPersonalSettings(string name) {
    map<string, string>::iterator l_it = custom_data.find(name);
    if(l_it == custom_data.end()) {
        cout << "background:û�ҵ��û�" << endl;
        return "background:�����û�������Ϣʧ��";
    }
    /* �����û�������Ϣ */
    return "background:�����û�������Ϣ";
}

bool Background::cleanPersonalRecord(string name) {
    map<string, string>::iterator l_it = custom_data.find(name);
    if(l_it == custom_data.end()) {
        cout << "background:û�ҵ��û�" << endl;
        cout << "background:ɾ���û���¼ʧ��" << endl;
        return false;
    }
    /* ɾ���û���¼ */
    return true;
}

bool Background::resetPersonalSettings(string name) {
    map<string, string>::iterator l_it = custom_data.find(name);
    if(l_it == custom_data.end()) {
        cout << "background:û�ҵ��û�" << endl;
        cout << "background:�����û�������Ϣʧ��" << endl;
        return false;
    }
    /* �޸��û�������Ϣ */
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
        cout << "��¼ʧ��,û�ҵ��û���Ϣ" << endl;
        return 3;
    }
    else if(l_it -> second != passwd) {
        cout << "��¼ʧ��,�������" << endl;
    }
    else if(l_it -> second == passwd){
        cout << "��¼�ɹ�" << endl;
        cout << "��ӭ�����û�����" << endl;
        return 1;
    }
    return 0;
}

/* ��Ϊû��ȥд��̨�࣬��������Ĳ��Ҽ�¼Ĭ��ȫ���ҵ� */
bool Custom::searchRecord(string typeOfRecord) {
    string name;
    cout << "������Ҫ��ѯ����ϵ��" << endl;
    cin >> name;
    map<string, string>::iterator l_it = custom_data.find(name);
    if(l_it == custom_data.end()) {
        cout << "û���ҵ���ϵ��" << endl;
        return false;
    }
    /* ���ڿ������Ӻ�̨�࣬��vector��ά���û���Ϣ */
    if(typeOfRecord == "word") {
        cout << "��̨��ѯing..." << endl;
        cout << "��ѯ�ɹ�" << endl;
        cout << "���ؼ�¼" << endl;
        //cout << "search word successfully" << endl << endl;
    }
    else if(typeOfRecord == "image") {
        cout << "��̨��ѯing..." << endl;
        cout << "��ѯ�ɹ�" << endl;
        cout << "���ؼ�¼" << endl;
        //cout << "search image successfully" << endl << endl;
    }
    else if(typeOfRecord == "video") {
        cout << "��̨��ѯing..." << endl;
        cout << "��ѯ�ɹ�" << endl;
        cout << "���ؼ�¼" << endl;
        //cout << "search video successfully" << endl << endl;
    }
    else if(typeOfRecord == "emoji") {
        cout << "��̨��ѯing..." << endl;
        cout << "��ѯ�ɹ�" << endl;
        cout << "���ؼ�¼" << endl;
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
        cout << "���Ϸ��Ĳ���" << endl;
    }
}

void Custom::manageRecord() {
    //cout << "manage record successfully" << endl;
    Background background;
    bool isClean = background.cleanPersonalRecord(
            name);
    if(isClean == 1) {
        cout << "�ɹ�ɾ����һЩ��Զ���û���¼" << endl;
    }
    else {
        cout << "ɾ��ʧ��" << endl;
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
        cout << "��¼ʧ��,û�ҵ��û���Ϣ" << endl;
        return 4;
    }
    else if(l_it -> second != passwd) {
        cout << "��¼ʧ��,�������" << endl;
    }
    else if(l_it -> second == passwd){
        cout << "��¼�ɹ�" << endl;
        cout << "��ӭ�������Ա����" << endl;
        return 2;
    }
    return 0;
}

void Admin::manageRecord(string name) {
    //cout << "manage record successfully" << endl;
    Background background;
    bool isClean = background.cleanPersonalRecord(name);
    if(isClean == 1) {
        cout << "�ɹ�ɾ����һЩ��Զ���û���¼" << endl;
    }
    else {
        cout << "ɾ��ʧ��" << endl;
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
        cout << "�����û�������Ϣʧ��" << endl;
    }
    else {
        cout << "�����û�������Ϣ�ɹ�" << endl;
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



/* ���ڿɽ�custom_data��admin_dataд���ļ����б��� */
map<string, string> custom_data;
map<string, string> admin_data;

//��ʼ���û�����custom_data������Ա����admin_data
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
    cout << "��������ĵ�¼����(custom or admin)�����֡�����" << endl;
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
        cout << "��ϣ������Ϊ�㴴��һ���û��˺���(input y or n)" << endl;
        cin >> isToRegister;
        if(isToRegister == "y") {
            Custom customForRegister;
            bool isCreate = customForRegister.createAccount(name, passwd);
            if(isCreate == 1) {
                cout << "�ɹ������û��˻�" << endl;
            }
            else {
                cout << "�����û��˻�ʧ��" << endl;
            }
        }
    }
    else if(isLogin == 4) {
        cout << "�޷���¼����Ա�˻�" << endl;
    }

    //return 0;
}

void timeForCustom(string name, string passwd) {
    Custom custom(name, passwd);
    int thing;
    /* custom */
    while(1) {
        cout << "\t\t\t����������������" << endl;
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
            cout << "��Ϊ���˻��������ֺ�����" << endl;
            cin >> newName >> newPasswd;
            bool isCreate = custom.createAccount(newName, newPasswd);
            if(isCreate == 1) {
                //cout << "create custom account successfully" << endl;
                cout << "�û��˻������ɹ�" << endl;
            }
            else {
                //cout << "custom account aready exits" << endl;
                cout << "���û��˻��Ѿ�����" << endl;
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
            //cout << "input type of records you want to search(word��image��video��emoji)" << endl;
            cout << "��������Ҫ��ѯ�ļ�¼����(word��image��video��emoji)" << endl;
            cin >> typeOfRecord;
            isSearch = custom.searchRecord(typeOfRecord);
            if(isSearch == 0) {
                //cout << "do not find the record" << endl;
                cout << "û���ҵ��ü�¼" << endl;
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
            cout << "�ɹ��˳�" << endl;
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
        cout << "����������������" << endl;
        cout << "*****" << endl;
        cout << "1.manage record" << endl;
        cout << "2.get custom record" << endl;
        cout << "3.get custom settings" << endl;
        cout << "4.reset custom settings" << endl;
        cout << "5.quit" << endl;
        cout << "*****" << endl;
        cin >> thing;
        if (thing == 1) {
            cout << "�����������û�����" << endl;
            cin >> customName;
            admin.manageRecord(customName);
        } else if (thing == 2) {
            cout << "�����������û�����" << endl;
            cin >> customName;
            admin.getPersonalRecord(customName);
        } else if (thing == 3) {
            cout << "�����������û�����" << endl;
            cin >> customName;
            admin.getPersonalSettings(customName);
        } else if (thing == 4) {
            cout << "�����������û�����" << endl;
            cin >> customName;
            admin.resetPersonalSettings(customName);
        } else if (thing == 5) {
            //cout << "succeed to quit" << endl;
            cout << "�ɹ��˳�" << endl;
            break;
        }
    }
}
#endif //CFILES_CONNECTION_H
