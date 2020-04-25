#include <iostream>

using namespace std;
#include "list_child.h"
#include "list_parent.h"
#include "list_relasi.h"

void mainMenu();

void mainMenu()
{
    int choice;
    List_parent LP;
    List_child LC;
    List_relasi LR;
    DataPeminjam Datapeminjam;
    DataMotor DataMtr;
    address_parent P,T;
    address_child Q,U;
    address_relasi R,S;
    createListParent(LP);
    createListChild(LC);
    createListRelasi(LR);
    DataM(LC);
    int id;
    int idmotor;
    do
    {
        cout << "Menu Peminjaman Motor" << endl;
        cout << "1. Menginput Peminjaman Motor" << endl;
        cout << "2. Menginput Data Motor" << endl;
        cout << "3. Daftar motor yang ada" << endl;
        cout << "4. Catatan peminjaman motor" << endl;
        cout << "5. Edit data peminjaman motor" << endl;
        cout << "6. Delete Data Peminjaman" << endl;
        cout << "7. Delete Data Motor" << endl;
        cout << "8. Reset Data" << endl;
        cout << "9. 3 Data terbaru" << endl;
        cout << "10. Data peminjam" << endl;
        cout << "0. Quit" << endl;
        cout << "Masukan angka:";
        cin >> choice;
        switch (choice)
        {
        case 1:
            dataIdentitas(LP,Datapeminjam);
            inputDataPeminjam(LR,Datapeminjam);
            cout<<"alokasi";
            P = alokasiParent(Datapeminjam);
            cout<<Datapeminjam.ID<<endl;
            cout<<"masuk";
            insertAndsortParent(LP, P);
            cout<<"masuk2";
            cout<<Datapeminjam.IDMotor;
            Q = findElmChild(LC, Datapeminjam.IDMotor);
            cout<<info(Q).ID;
            insertLastRelasi(LR, alokasiRelasi(P,Q));
            break;
        case 2:
            inputDataMotor(DataMtr);
            insertAndsortChild(LC, alokasiChild(DataMtr));
            break;
        case 3:
            printInfoChild(LC);
            break;
        case 4:
            if(first(LR)!=NULL){
                printInfoRelasi(LR);
            }else{
                cout<<"kosong"<<endl;
            }
            break;
        case 5:
            int Id;
            cout<<"Masukkan ID peminjaman yang ingin dirubah datanya:";
            cin>>Id;
            R = findElmRelasiByParent(LR, Id);
            if (R == NULL)
            {
                cout<<"Data tidak ditemukan"<<endl;
            }
            else
            {
                inputDataPeminjam(LR, info(parent(R)));
            }
            break;
        case 6:
            cout << "Masukkan ID member yang ingin di hapus: ";
            cin >> id;
            P = findElmParent(LP, id);
            if (P != NULL)
            {
                R = findElmRelasiByParent(LR, info(P).ID);
                if (R != NULL)
                {
                    cout << "ID akan menggunakan Motor pada:" << endl;
                    printDate(info(P).waktucheckIn);
                    cout << "Dengan menghapus data peminjam maka akan menghapus data peminjaman motor" << endl;
                    cout << "Apakah anda ingin menghapusnya(Y/N)?";
                    char penentuDelete;
                    cin >> penentuDelete;
                    if (penentuDelete == 'Y')
                    {
                        disconnected(LR, info(P).ID);
                        cout << "dc sukses";
                        deleteByIDparent(LP, id);
                        cout << "Data berhasil dihapus.." << endl;
                    }
                }
            }
            else
            {
                cout << "Data Tidak ada.." << endl;
            }
            cout << endl;
            break;

        case 7:
            cout<<"Masukkan ID motor yang ingin dihapus: ";
            cin>>idmotor;
            if(first(LC)!=NULL){
                if (findElmChild(LC, idmotor)!=NULL){
                    deleteByIDChild(LC, idmotor);
                    cout<<"delete berhasil";
                }
            }else{
                cout<<"Data motor kosong"<<endl;
            }
            break;
        case 8:
            int i;
            R = first(LR);
            if(R!=NULL){
                i = CountRelasi(LR);
                while(i>0){
                    deleteFirstRelasi(LR, S);
                    dealokasiRelasi(S);
                    i--;
                }
            }
            P = first(LP);
            if(P!=NULL){
                i = CountParent(LP);
                while (i > 0)
                {
                    deleteFirstParent(LP, T);
                    dealokasiParent(T);
                    i--;
                }
            }
            Q = prev(first(LC));
            if(Q!=NULL){
                i = CountChild(LC);
                while(i>0){
                    deleteFirstChild(LC, U);
                    dealokasiChild(U);
                    i--;
                }
            }
            break;
        case 9:
            printInfoTerbaru(LR);
            break;
        case 10:
            printInfoParent(LP);
            break;
        }

        if (choice == 0)
        {
            break;
        }
    } while (true);

}

int main()
{
    mainMenu();

    return 0;
}
