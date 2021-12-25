#include "file.h"
#include "adapter.h"
#include "factory.h"
#include "cmd.h"

extern set<MyFile> TimDiskFile;
extern set<MyFile> LocalFile;
extern set<MyFile> WeiyunDiskFile;

/*1234用适配者模式，其余用命令模式，文件类型为工厂模式*/
void menu();
int main(){
    initfile();
    WeiyunDisk *wei=new WeiyunDisk();
    TimDisk *tim2=new Disk(wei);  //指向微云网盘
	TimDisk *tim1=new TimDisk();  //指向Tim网盘
	Factory fy;
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
	return 0;

}

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