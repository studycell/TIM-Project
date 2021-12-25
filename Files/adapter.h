#ifndef ADAPTER_H_
#define ADAPTER_H_

#include "file.h"

class TimDisk{
    public:
        virtual void viewfile(string filename,string fileroad);
        virtual void removefile(string filename,string fileroad);
        virtual void createfile(string filename,string fileroad);
        virtual void searchfile(string filename);
};

class WeiyunDisk{
    public:
        virtual void view_Weiyunfile(string filename,string fileroad);
        virtual void remove_Weiyunfile(string filename,string fileroad);
        virtual void create_Weiyunfile(string filename,string fileroad);
        virtual void search_Weiyunfile(string filename);
};

class Disk: public TimDisk{
    private:
        WeiyunDisk *weiyun;
    public:
        Disk(WeiyunDisk* w):weiyun(w){}
        virtual void viewfile(string filename,string fileroad);
        virtual void removefile(string filename,string fileroad);
        virtual void createfile(string filename,string fileroad);     
};

#endif
