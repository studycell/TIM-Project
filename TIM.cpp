//
//Created by hansl on 2021/12/23 8:41
//
#include <iostream>
#include <map>
#include <iterator>
#include <cstring>
#include "connection.h"
#include "kongjian.h"
#include "gongzuotai.h"
#include "Files.h"
using namespace std;

void menu_1();
int main() {

    int i;
    menu_1();

    while(1) {
        void menu_1();
        printf("\t\t\t��ѡ��1��¼��ѡ��0�˳���:\n");
        scanf("%d", &i);
        switch (i) {
            case 1:
                connection_main();
                break;
//            case 2:
//                //3space_main(name);
//                break;
//            case 3:
//                Workbench();
//                break;
//            case 4:
//                gongzuotai();
//                break;
//            case 5:
//                Relate_main();
//                break;
//            case 6:
//                system("cls");
//                menu();
//                break;
            case 0:
                return 0;
            default:
                printf("���빦�ܺ��������������룺");

        }
    }

    system("pause");
}
void menu_1(){
    printf("\n\t\t****************************************\n");
    printf("\t\t\t      �� ӭ ʹ �� TIM �� ��\n");
    printf("\t\t\t\t 1.��¼�˻� \n");
//    printf("\t\t\t\t 2.TIM�ռ�\n");
//    printf("\t\t\t\t 3.�ļ�����\n");
//    printf("\t\t\t\t 4.����̨\n");
//    printf("\t\t\t\t 5.��ϵϵͳ\n");
//    printf("\t\t\t\t 6.�������˵�\n");
    printf("\t\t\t\t 0.�˳� \n");
    printf("\t\t****************************************\n");
}