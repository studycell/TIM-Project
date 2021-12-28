#ifndef FACTORY_H_
#define FACTORY_H_

 
#include "file.h"
using namespace std;



class File{
     public:
        string filename;
        string fileroad;
         
        virtual void create_obj(string name,string road)=0;
};

class Timfile: public File{
    
        void create_obj(string name,string road);
};

class WeiYunfile: public File{
    
        void create_obj(string name,string road);
};

class Localfile: public File{
        void create_obj(string name,string road);
              
};

class Factory{
    public:
        File * getobj(int type);
};


#endif