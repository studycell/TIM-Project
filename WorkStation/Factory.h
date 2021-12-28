#ifndef F_H_
#define F_H_
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class list_calendar
{
    public:
    int caid;
    string content;
    string holiday;
};
class Calendar
{
    private:
    vector<list_calendar> calendarname;
    int num=0; 
    public:
    int visit(int i_caid);
    void modify(int i_caid);
    void create();
};
class list_schedule
{
    public:
    int scid;
    string title;
    string location;
    string people;
    string content;
};
class Schedule
{
    private:
    vector<list_schedule> schedulename;
    int num=0;
    public:
    int visit(int i_scid);
    void modify(int i_scid);
    void create();
};
class list_todo
{
    public:
    int toid;
    string content;
    bool state;
};
class Todo
{
    private:
    vector<list_todo> todoname;
    int num=0;
    public:
    void create();
    void modify(int i_toid);
    int visit(int i_toid);
};
class collect_filetype
{
    public:
    string file;
    string content;
    string note;
    string picture;
    void show(char firstchar);
};
class collect_function 
{
    public:
    void create();
    void visit();
    void modify();
    void upload();
    void download();
};
class Collect
{
    private:
    collect_function function;
    collect_filetype filetype;
    public:
    void use();
};
#endif