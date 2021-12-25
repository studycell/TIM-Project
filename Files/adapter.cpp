#include "adapter.h"
extern set<MyFile> TimDiskFile;
extern set<MyFile> LocalFile;
extern set<MyFile> WeiyunDiskFile;
void TimDisk::viewfile(string filename,string fileroad){
    if(IsExistTimDisk(filename,fileroad))
        cout<<filename<<" is open success in TimDisk at "<<fileroad<<endl;
    else
        cout<<filename<<" is not exist in TimDisk at "<<fileroad<<endl;    
        
}

void TimDisk::createfile(string filename,string fileroad){
    if(IsExistTimDisk(filename,fileroad))
        cout<<filename<<" is already exist in TimDisk at "<<fileroad<<endl;
    else{
        TimDiskFile.insert(MyFile(filename,fileroad));
        cout<<filename<<" create success"<<endl;
    }    
}

void TimDisk::removefile(string filename,string fileroad){
    if(IsExistTimDisk(filename,fileroad)==0)
        cout<<filename<<" is not exist in TimDisk at "<<fileroad<<endl;
    else{
        set<MyFile>::iterator it;
        for(it=TimDiskFile.begin();it!=TimDiskFile.end();){
            if(it->filename==filename&&it->fileroad==fileroad){
                it=TimDiskFile.erase(it);
            }
            else{
                it++;
            }
        }
        cout<<filename<<" remove success"<<endl;
    }   
}

void TimDisk::searchfile(string filename){
    set<MyFile>::iterator it;
    bool flag=0;
    for(it=TimDiskFile.begin();it!=TimDiskFile.end();it++){
        if(it->filename==filename){
            cout<<filename<<" is exist in TimDisk at "<<it->fileroad<<endl;
            flag=1;
        }
    }
    if(flag==0)
        cout<<filename<<" is not exist in TimDisk "<<endl;    
}

void WeiyunDisk::view_Weiyunfile(string filename,string fileroad){
    if(IsExistWeiyunDisk(filename,fileroad))
        cout<<filename<<" is open success in WeiyunDisk at "<<fileroad<<endl;
    else
        cout<<filename<<" is not exist in WeiyunDisk at "<<fileroad<<endl;   
}

void WeiyunDisk::create_Weiyunfile(string filename,string fileroad){
    if(IsExistWeiyunDisk(filename,fileroad))
        cout<<filename<<" is already exist in WeiyunDisk at "<<fileroad<<endl;
    else{
        WeiyunDiskFile.insert(MyFile(filename,fileroad));
        cout<<filename<<" create success"<<endl;
    }    
}

void WeiyunDisk::remove_Weiyunfile(string filename,string fileroad){
    if(IsExistWeiyunDisk(filename,fileroad)==0)
        cout<<filename<<" is not exist in WeiyunDisk at "<<fileroad<<endl;
    else{
        set<MyFile>::iterator it;
        for(it=WeiyunDiskFile.begin();it!=WeiyunDiskFile.end();){
            if(it->filename==filename&&it->fileroad==fileroad){
                it=WeiyunDiskFile.erase(it);
            }
            else{
                it++;
            }
        }
        cout<<filename<<" remove success"<<endl;
    }   
}

void WeiyunDisk::search_Weiyunfile(string filename){
    set<MyFile>::iterator it;
    bool flag=0;
    for(it=WeiyunDiskFile.begin();it!=WeiyunDiskFile.end();it++){
        if(it->filename==filename){
            cout<<filename<<" is exist in WeiyunDisk at "<<it->fileroad<<endl;
            flag=1;
        }
    }
    if(flag==0)
        cout<<filename<<" is not exist in WeiyunDisk "<<endl;   
}

void Disk::viewfile(string filename,string fileroad){
    weiyun->view_Weiyunfile(filename,fileroad);
}

void Disk::removefile(string filename,string fileroad){
    weiyun->remove_Weiyunfile(filename,fileroad);
}

void Disk::createfile(string filename,string fileroad){
    weiyun->create_Weiyunfile(filename,fileroad);
}