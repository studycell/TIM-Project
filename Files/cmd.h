#ifndef CMD_H_
#define CMD_H_

#include "file.h"

class Receiver{
    public:
         
        virtual void upload(string filename,string fileroad,string des){}
            
        virtual void download(string filename,string fileroad,string des){}
};

class TimDiskReceiver:public Receiver{
    public:
        virtual void upload(string filename,string fileroad,string des);
        virtual void download(string filename,string fileroad,string des);
};

class WeiyunDiskReceiver:public Receiver{
    public:
        virtual void upload(string filename,string fileroad,string des);
        virtual void download(string filename,string fileroad,string des);
};

class Command{
    public:
        
    virtual void uploadfile()=0;
    virtual void downloadfile()=0;
        
        
};

class FileCommand:public Command{
    private:
        Receiver *disk;
        string filename;
        string fileroad;
        string des;
    public:
        FileCommand(Receiver* d,string fn,string fr,string ds):disk(d),filename(fn),fileroad(fr),des(ds){}
        void uploadfile(){
            disk->upload(filename,fileroad,des);
        }
        void downloadfile(){
            disk->download(filename,fileroad,des);
        }
};


class Invoker{

    private:
        FileCommand cmd;
    public:
        Invoker(FileCommand c):cmd(c){}
        void notify_upload(){
            cmd.uploadfile();
        }
        void notify_download(){
            cmd.downloadfile();
        }



};





#endif