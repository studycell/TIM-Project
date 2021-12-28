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
        cout<<"点赞成功";
    }
};

class Comment: public Operation
{
public:
    void operation() override
    {
        cout<<"评论成功";
    }
};

class Publish: public Operation
{
public:
    void operation() override
    {
        cout<<"发表成功";
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
        cout<<"成功删除点赞";
    }
};

class del_comment: public Delete
{
public:
    void del() override
    {
        cout<<"成功删除评论";
    }
};

class del_publish: public Delete
{
public:
    void del() override
    {
        cout<<"成功删除动态";
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
            cout<<"无对应操作";
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
            cout<<"无对应的删除操作";
            exit(-1);
        }
    }
};
class Interface
{
public:
    string description = "系统默认界面";
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
    RedInterface(){description = "红色界面";}
};

class BlueInterface: public Interface
{
public:
    BlueInterface(){description = "蓝色界面";}
};
class Animation1: public InterfaceDecorate
{
public:
    Interface * base;
    void getDescription() override
    {
        base->getDescription();
        cout<<",动画1";
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
        cout<<"，动画2";
    }
    explicit Animation2(Interface * d){base = d;}
};
void space_main(string user)
{
    cout<<"欢迎进入"<<user<<"用户空间"<<endl;
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
        cout<<"输入:\nThumb_up 点赞.\nComment 评论：\nPublish 发表："<<endl;
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
