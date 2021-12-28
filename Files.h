#ifndef FILE_H_
#define FILE_H_

#include<iostream>
#include<string>
#include<set>
#include<windows.h>
#include<iterator>

using namespace std;

enum{
    TIM_DISK_TYPE=0,
    WEIYUN_DISK_TYPE,  
    LOCAL_TYPE
};

//第一项为文件名，第二项为文件路径
struct MyFile{
    string filename;
    string fileroad;
    MyFile(string a,string b):filename(a),fileroad(b){}
    friend bool operator <(const MyFile& b,const MyFile& a){
        return a.filename<b.filename;
    }
};

set<MyFile> TimDiskFile;
set<MyFile> LocalFile;
set<MyFile> WeiyunDiskFile;

void initfile(){
    TimDiskFile.insert(MyFile("book","/usr/src"));
    TimDiskFile.insert(MyFile("newspaper","/root"));
    TimDiskFile.insert(MyFile("article","/etc"));

    LocalFile.insert(MyFile("the world","D:/file"));
    LocalFile.insert(MyFile("jojo","D:/file"));

    WeiyunDiskFile.insert(MyFile("book","/home"));
    WeiyunDiskFile.insert(MyFile("paper","/home"));
}

bool IsExistTimDisk(string filename,string fileroad){
    set<MyFile>::iterator it;
    for(it=TimDiskFile.begin();it!=TimDiskFile.end();it++){
        if(it->filename==filename&&it->fileroad==fileroad)
            return 1;
    }
    return 0;
}

bool IsExistWeiyunDisk(string filename,string fileroad){
    set<MyFile>::iterator it;
    for(it=WeiyunDiskFile.begin();it!=WeiyunDiskFile.end();it++){
        if(it->filename==filename&&it->fileroad==fileroad)
            return 1;
    }
    return 0;
}

bool IsExistLocalDisk(string filename,string fileroad){
    set<MyFile>::iterator it;
    for(it=LocalFile.begin();it!=LocalFile.end();it++){
        if(it->filename==filename&&it->fileroad==fileroad)
            return 1;
    }
    return 0;  
}

/****************Factory***************/
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

class Factory_1{
    public:
        File * getobj(int type);
};

void Timfile::create_obj(string name,string road){
    
    filename=name;
    fileroad=road;
}

 
void WeiYunfile::create_obj(string name,string road){
    filename=name;
    fileroad=road;
}

void Localfile::create_obj(string name,string road){
    filename=name;
    fileroad=road;
}

File * Factory_1::getobj(int type){
    if(type==TIM_DISK_TYPE){
        return new Timfile();
    }
    else if(type==LOCAL_TYPE){
        return new Localfile();
    }
    else if(type==WEIYUN_DISK_TYPE){
        return new WeiYunfile();
    }
    return NULL;
}

/***********Adapter*************/
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

/*************Cmd*************/
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

void TimDiskReceiver::upload(string filename,string fileroad,string des){
    if(IsExistLocalDisk(filename,fileroad)){
        TimDiskFile.insert(MyFile(filename,des));
        cout<<filename<<" upload success"<<endl;
    }
    else{
        cout<<filename<<" is not exist in local "<<fileroad<<endl;
    }
}

void TimDiskReceiver::download(string filename,string fileroad,string des){
    if(IsExistTimDisk(filename,fileroad)){
        LocalFile.insert(MyFile(filename,des));
        cout<<filename<<" download success"<<endl;
    }
    else{
        cout<<filename<<" is not exist in TimDisk "<<fileroad<<endl;
    }
}

void WeiyunDiskReceiver::upload(string filename,string fileroad,string des){
    if(IsExistLocalDisk(filename,fileroad)){
        WeiyunDiskFile.insert(MyFile(filename,des));
        cout<<filename<<" upload success"<<endl;
    }
    else{
        cout<<filename<<" is not exist in local "<<fileroad<<endl;
    }
}

void WeiyunDiskReceiver::download(string filename,string fileroad,string des){
    if(IsExistWeiyunDisk(filename,fileroad)){
        LocalFile.insert(MyFile(filename,des));
        cout<<filename<<" download success"<<endl;
    }
    else{
        cout<<filename<<" is not exist in WeiyunDisk "<<fileroad<<endl;
    }
}

/*********接口*******************/
void menu(){
	//system("cls");
	cout << "\t\t\t\t**************************************" << endl;
	cout << "\t\t\t\t*                                    *" << endl;
	cout << "\t\t\t\t*         1.查看文件                  *" << endl;
	cout << "\t\t\t\t*         2.搜索文件                  *" << endl;
	cout << "\t\t\t\t*         3.删除文件                  *" << endl;
	cout << "\t\t\t\t*         4.创建文件                  *" << endl;
	cout << "\t\t\t\t*         5.上传文件                  *" << endl;  
	cout << "\t\t\t\t*         6.下载文件                  *" << endl;
	cout << "\t\t\t\t*         7.退出                      *" << endl;
	cout << "\t\t\t\t*                                    *" << endl;
	cout << "\t\t\t\t**************************************" << endl;
}

void Workbench(){
    initfile();
    WeiyunDisk *wei=new WeiyunDisk();
    TimDisk *tim2=new Disk(wei);  //指向微云网盘
	TimDisk *tim1=new TimDisk();  //指向Tim网盘
	Factory_1 fy;
	Receiver *rcv1=new TimDiskReceiver();
	Receiver *rcv2=new WeiyunDiskReceiver();
	string filename,fileroad,des;
	int n;
	int type;
	bool running=1;
	while(running){
		menu();
		cout<<"Please choose:";
		cin>>n;
		if(!(n>=1&&n<=7)){
			cout<<"Invalid number"<<endl;
			continue;
		}
		switch(n){
			case 1:{
				cout<<"Please input the disk(0:Tim,1:Weiyun):";
				cin>>type;
				if(!(type>=0&&type<=1)){
					cout<<"Invalid number"<<endl;
					break;
				}
				File *file=fy.getobj(type);
				cout<<"Please input the filename and the fileroad:";
				cin>>filename>>fileroad;
				file->create_obj(filename,fileroad);
				cout<<file->filename<<" "<<file->fileroad<<endl;
				if(type==TIM_DISK_TYPE){
					tim1->viewfile(file->filename,file->fileroad);
				}
				else{
					tim2->viewfile(file->filename,file->fileroad);
				}
				break;
			}
			case 2:{
				cout<<"Please input the disk(0:Tim,1:Weiyun):";
				cin>>type;
				if(!(type>=0&&type<=1)){
					cout<<"Invalid number"<<endl;
					break;
				}
				File *file=fy.getobj(type);
				cout<<"Please input the filename:";
				cin>>filename;
				file->create_obj(filename,"");
				if(type==TIM_DISK_TYPE){
					tim1->searchfile(file->filename);
				}
				else{
					tim2->searchfile(file->filename);
				}
				break;	
			}
			case 3:{
				cout<<"Please input the disk(0:Tim,1:Weiyun):";
				cin>>type;
				if(!(type>=0&&type<=1)){
					cout<<"Invalid number"<<endl;
					break;
				}
				File *file=fy.getobj(type);
				cout<<"Please input the filename and the fileroad:";
				cin>>filename>>fileroad;
				file->create_obj(filename,fileroad);
				if(type==TIM_DISK_TYPE){
					tim1->removefile(file->filename,file->fileroad);
				}
				else{
					tim2->removefile(file->filename,file->fileroad);
				}
				break;
			}
			case 4:{
				cout<<"Please input the disk(0:Tim,1:Weiyun):";
				cin>>type;
				if(!(type>=0&&type<=1)){
					cout<<"Invalid number"<<endl;
					break;
				}
				File *file=fy.getobj(type);
				cout<<"Please input the filename and the fileroad:";
				cin>>filename>>fileroad;
				file->create_obj(filename,fileroad);
				if(type==TIM_DISK_TYPE){
					tim1->createfile(file->filename,file->fileroad);
				}
				else{
					tim2->createfile(file->filename,file->fileroad);
				}
				break;	
			}
			case 5:{
				cout<<"Please input the disk(0:Tim,1:Weiyun):";
				cin>>type;
				if(!(type>=0&&type<=1)){
					cout<<"Invalid number"<<endl;
					break;
				}
				File *file=fy.getobj(type);
				cout<<"Please input the filename ,fileroad and des:";
				cin>>filename>>fileroad>>des;
				file->create_obj(filename,fileroad);
				if(type==TIM_DISK_TYPE){
					FileCommand cmd(rcv1,file->filename,file->fileroad,des);
					Invoker invoker(cmd);
					invoker.notify_upload();
					 
				}
				else{
					FileCommand cmd(rcv2,file->filename,file->fileroad,des);
					Invoker invoker(cmd);
					invoker.notify_upload();
				}
				break;	
			}
			case 6:{
				cout<<"Please input the disk(0:Tim,1:Weiyun):";
				cin>>type;
				if(!(type>=0&&type<=1)){
					cout<<"Invalid number"<<endl;
					break;
				}
				File *file=fy.getobj(type);
				cout<<"Please input the filename ,fileroad and des:";
				cin>>filename>>fileroad>>des;
				file->create_obj(filename,fileroad);
				if(type==TIM_DISK_TYPE){
					FileCommand cmd(rcv1,file->filename,file->fileroad,des);
					Invoker invoker(cmd);
					invoker.notify_download();
				}
				else{
					FileCommand cmd(rcv2,file->filename,file->fileroad,des);
					Invoker invoker(cmd);
					invoker.notify_download();
				}
				break;
			}	
			case 7:{
				running=0;
				break;
			}
			default:
				break;		
		}
	}

}

#endif