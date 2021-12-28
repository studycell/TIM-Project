//
// Created by Lenovo on 2021/12/23.
//

#ifndef CFILES_KONGJIAN_H
#define CFILES_KONGJIAN_H
#include <iostream>
using namespace std;

class Operation
{
public:
    virtual ~Operation()= default;
    virtual void operation() = 0;
};

class Thumbs_up :public Operation
{
public:
    void operation() override
    {
        cout<<"���޳ɹ�";
    }
};

class Comment: public Operation
{
public:
    void operation() override
    {
        cout<<"���۳ɹ�";
    }
};

class Publish: public Operation
{
public:
    void operation() override
    {
        cout<<"����ɹ�";
    }
};

class Delete
{
public:
    virtual ~Delete()= default;
    virtual void del() = 0;
};

class del_thumb: public Delete
{
public:
    void del() override
    {
        cout<<"�ɹ�ɾ������";
    }
};

class del_comment: public Delete
{
public:
    void del() override
    {
        cout<<"�ɹ�ɾ������";
    }
};

class del_publish: public Delete
{
public:
    void del() override
    {
        cout<<"�ɹ�ɾ����̬";
    }
};
class Factory
{
public:
    static Operation * CreateOperation(string ope)
    {
        if (ope[0] == 'T')
            return new Thumbs_up();
        else if(ope[0] == 'C')
            return new Comment();
        else if(ope[0] == 'P')
            return new Publish();
        else{
            cout<<"�޶�Ӧ����";
            exit(-1);
        }
    }
    static Delete * CreateDelete(string ope)
    {
        if(ope[4] == 't')
            return new del_thumb();
        else if(ope[4] == 'c')
            return new del_comment();
        else if(ope[4] == 'p')
            return new del_publish();
        else
        {
            cout<<"�޶�Ӧ��ɾ������";
            exit(-1);
        }
    }
};
class Interface
{
public:
    string description = "ϵͳĬ�Ͻ���";
    virtual void getDescription(){cout<<description;}
};

class InterfaceDecorate: public Interface
{
public:
    void getDescription() override{cout<<description;}
};

class RedInterface: public Interface
{
public:
    RedInterface(){description = "��ɫ����";}
};

class BlueInterface: public Interface
{
public:
    BlueInterface(){description = "��ɫ����";}
};
class Animation1: public InterfaceDecorate
{
public:
    Interface * base;
    void getDescription() override
    {
        base->getDescription();
        cout<<",����1";
    }
    explicit Animation1(Interface * d){base = d;}
};

class Animation2: public InterfaceDecorate
{
public:
    Interface * base;
    void getDescription() override
    {
        base->getDescription();
        cout<<"������2";
    }
    explicit Animation2(Interface * d){base = d;}
};
void space_main(string user)
{
    cout<<"��ӭ����"<<user<<"�û��ռ�"<<endl;
    Operation * p1 = Factory::CreateOperation("Thumb_up");
    p1->operation();
    delete p1;
    cout<<endl;
    Interface * I1 = new RedInterface();
    I1->getDescription();
    cout<<endl;
    I1 = new Animation1(I1);
    I1->getDescription();
    cout<<endl;
    I1 = new Animation2(I1);
    I1->getDescription();
    cout<<endl;
    delete I1;
    while(1){

        string str;
        cout<<"����:\nThumb_up ����.\nComment ���ۣ�\nPublish ����"<<endl;
        cin>>str;
        if(str == "exit")
            break;
        Operation * p1 = Factory::CreateOperation(str);
        p1->operation();
        delete p1;
    }
    //return 0;
}
#endif //CFILES_KONGJIAN_H
