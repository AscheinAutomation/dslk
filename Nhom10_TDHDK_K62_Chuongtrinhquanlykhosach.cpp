
#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <string.h>
using namespace std;
BOOL WINAPI SetConsoleTextAttribute(){
  HANDLE hConsoleOutput;
  WORD   wAttributes;
}
void SetColor(int backgound_color, int text_color)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    int color_code = backgound_color * 16 + text_color;
    SetConsoleTextAttribute(hStdout, color_code);
}
struct book {
    char* tittle;
    char* isbn;
    char* author;
    char* language;
    int year;
    int price;
    int stockLevel;
    book* next;
};

void menu() {
	 SetColor(0, 15);
	cout << "=======================MENU======================\n";
     SetColor(0, 4);
    cout << "1. Khoi tao kho sach                               "<< endl ;
     SetColor(0, 2);
    cout << "2. Nhap mot cuon sach vao kho                      " << endl;
     SetColor(0, 3);
    cout << "3. Ban mot quyen sach                              " << endl;
     SetColor(0, 7);
    cout << "4. Tim sach theo yeu cau                           " << endl;
     SetColor(0, 6);
    cout << "5. Loai cac quyen sach co muc ton kho thap hon K   " << endl;
     SetColor(0, 5);
    cout << "6. Xuat ra man hinh thong tin cua tua sach         " << endl;
     SetColor(0, 8);
    cout << "7. Thoat                                           " << endl;
    SetColor(0, 15);
    cout << "=================================================\n";
}
void inPut(book*& a) {
    char bien[200];
    SetColor(0, 1);
    cout << "Nhap tieu de cua sach: ";
    cin.ignore(); 
    cin.getline(bien, 200); 
    a->tittle = new char[strlen(bien)];
    strcpy(a->tittle, bien);
    SetColor(0, 8);
    cout << "Nhap ID cua sach: ";
    cin.getline(bien, 10);
    a->isbn = new char[strlen(bien)];
    strcpy(a->isbn, bien);
    SetColor(0, 9);
    cout << "Nhap tac gia cua sach: ";
    cin.getline(bien, 30);
    a->author = new char[strlen(bien)];
    strcpy(a->author, bien);
    SetColor(0, 10);
    cout << "Nhap ngon ngu cua sach: ";
    cin.getline(bien, 40);
    a->language = new char[strlen(bien)];
    strcpy(a->language, bien);
    SetColor(0, 11);
    cout << "Nhap nam xuat ban cua sach: ";
    cin >> a->year;
    SetColor(0, 12);
    cout << "Nhap gia cua sach: ";
    cin >> a->price;
    SetColor(0, 13);
    cout << "Nhap muc ton kho cua sach: ";
    cin >> a->stockLevel;
    }

book* get() {
    book* p = (book*)malloc(sizeof(struct book));
    if (p == NULL) {
        cout << "Loi bo nho" << endl;
    }
    else {
        inPut(p);
        p->next = NULL;
    }
    return p;
}
void print(book* &head){
    char name[200];
    cout << "Nhap ten sach muon xem: ";
    cin.ignore();
    cin.getline(name, 100);
    for (book* p = head; p; p = p->next) {
        if (strcmp(name, p->tittle) == 0) {
cout<<"ten tac pham:"<<p->tittle<<endl;	
SetColor(0, 9);
cout << "tac gia cua sach:"<<p->author<<endl;
SetColor(0, 6);
cout<<"ngon ngu:"<<p->language<<endl;
SetColor(0, 4);
cout<<"Nam xuat ban cua sach:"<<p->year<<endl;
SetColor(0, 11);
cout<<"gia sach:"<<p->price<<endl;
SetColor(0, 10);
cout<<"so quyen sach hien dang co:"<<p->stockLevel<<endl;
SetColor(0, 12);
    }
}
}
void outPutList(book* head) {
    int dem = 1;
    SetColor(0, 14);
    cout << setw(5) << left << "STT";
    cout << setw(20) << left << "Tieu De";
    cout << setw(15) << left << "ID";
    cout << setw(15) << left << "Tac Gia";
    cout << setw(15) << left << "Ngon Ngu";
    cout << setw(15) << left << "Nam Xuat Ban";
    cout << setw(15) << left << "Gia";
    cout << setw(15) << left << "Ton Kho";
    cout << endl;
    for (book* p = head; p != NULL; p = p->next) {
        cout << setw(5) << left << dem;
        cout << setw(20) << left << p->tittle;
        cout << setw(15) << left << p->isbn;
        cout << setw(15) << left << p->author;
        cout << setw(15) << left << p->language;
        cout << setw(15) << left << p->year;
        cout << setw(15) << left << p->price;
        cout << setw(15) << left << p->stockLevel;
        cout << endl;
        dem++;
    }
}
void initiazation(book*& head, book*& tail) {
    free(head);
    free(tail);
    head = tail = NULL;
}

void inPutABook(book*& head, book*& tail) {
    book* p = (book*)malloc(sizeof(struct book));
    if (p == NULL) {
        cout << "Loi bo nho" << endl;
    }
    else {
        char bien[200];
        cout << "Nhap ID cua sach: ";
        cin.ignore();
        cin.getline(bien, 10);
        p->isbn = new char[strlen(bien)];
        strcpy(p->isbn, bien);

        bool flag = false;
        for (book* pp = head; pp; pp = pp->next) {
            if (strcmp(p->isbn, pp->isbn) == 0) {
                cout << "Nhap muc ton kho cua sach: ";
                cin >> p->stockLevel;
                pp->stockLevel += p->stockLevel;
                flag = true;
            }
        }
        if (flag == false) {
        	SetColor(0, 1);
            cout << "Nhap tieu de cua sach: ";
            cin.getline(bien, 200); 
            p->tittle = new char[strlen(bien)];
            strcpy(p->tittle, bien);
            SetColor(0, 2);
            cout << "Nhap tac gia cua sach: ";
            cin.getline(bien, 30);
            p->author = new char[strlen(bien)];
            strcpy(p->author, bien);
            cout << "Nhap ngon ngu cua sach: ";
            SetColor(0, 11);
            cin.getline(bien, 40);
            p->language = new char[strlen(bien)];
            strcpy(p->language, bien);
            SetColor(0, 8);
            cout << "Nhap nam xuat ban cua sach: ";
            cin >> p->year;
            SetColor(0, 12);
            cout << "Nhap gia cua sach: ";
            cin >> p->price;
            SetColor(0, 13);
            cout << "Nhap muc ton kho cua sach: ";
            cin >> p->stockLevel;
            p->next = NULL;
            if (head == NULL) head = tail = p;
            else {
                tail->next = p;
                tail = p;
            }
        }
    }
}

void sellBook(book*& head) {
    char id[10];
    cout << "Nhap ID sach muon ban: ";
    cin.ignore();
    cin.getline(id, 10);
    for (book* p = head; p; p = p->next) {
        if (strcmp(id, p->isbn) == 0) {
            if (p->stockLevel > 0) {
                cout << "Tieu de sach: " << p->tittle << endl;
                cout << "Gia ban: " << p->price << endl;
                p->stockLevel--;
            }
            else cout << "OUT OF STOCK" << endl;
            break;
        }
    }
}

void findBook(book* head) {
    char name[100];
    cout << "Nhap ten sach can tim: ";
    cin.ignore();
    cin.getline(name, 100);
    int dem = 0;
    cout << setw(5) << left << "STT";
    cout << setw(20) << left << "Tieu De";
    cout << setw(15) << left << "ID";
    cout << endl;
    for (book* p = head; p; p = p->next) {
        if (strcmp(p->tittle, name) == 0) {
            dem++;
            cout << setw(5) << left << dem;
            cout << setw(20) << left << p->tittle;
            cout << setw(15) << left << p->isbn;
            cout << endl;
        }
    }
}

void deleteBook(book*& head, book*& tail, book*& p) {
    for (book* pp = head; pp; pp = pp->next) {
        if (p == head) {
            if (head == tail) {
                free(head);
                head = tail = NULL;
            }
            else {
                head = head->next;
            }
            break;
        }
        else if (p == tail) {
            if (head == tail) {
                free(head);
                head = tail = NULL;
            }
            else {
                book* r;
                for (r = head; r->next != tail; r = r->next);
                free(tail);
                tail = r;
                r->next = NULL;
            }
            break;
        }
        else {
            book* r;
            for (r = head; r != p; r = r->next);
            r->next = p->next;
            free(p);
        }
    }
}
void deleteListBook(book*& head, book*& tail) {
    int k;
    cout << "Nhap nguong K muon xoa: ";
    cin >> k;
    for (book* p = head; p; p = p->next) {
        if (p->stockLevel < k) {
            deleteBook(head, tail, p);
        }
    }
}

void destroyList(book*& head) {
    book* p;
    while (head) {
        p = head;
        head = head->next;
        free(p);
    }
}

int main() {
    book* head = NULL;
    book* tail = NULL;
    while (true) {
        int x = 0;

        menu();
        while (true) {
            cout << "Nhap yeu cau cua ban: ";
            cin >> x;
            if (x >= 1 && x <= 7) break;
            else cout << "Vui long nhap lai:" << endl;
		}
        cout << endl;
        switch (x)
        {
        case 1:
            initiazation(head, tail);
            cout << endl;
            break;
        case 2:
            inPutABook(head, tail);
            cout << endl;
            break;
        case 3:
            sellBook(head);
            cout << endl;
            break;
        case 4:
            findBook(head);
            cout << endl;
            break;
        case 5:
            deleteListBook(head, tail);
            cout << endl;
            break;
        case 6:
            print(head);
            cout << endl;
            break;
        case 7:
            goto exit;
            break;
        
        }
        outPutList(head);
        cout << endl;
    }
exit:;
    destroyList(head);
    return 0;
}
