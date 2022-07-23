//Final Projek Struktur Data
// Kelompok 11
/* Randi, Rafael, Tifani, Hamim, Meylani*/
#include <iostream>
#include <cstdlib>
#include <conio.h>
#define max 100
using namespace std;

//penggunaan struct
struct antrean1{
    int data[max];
    string name[max];
    int awal;
    int akhir;
}Q;
struct antrean2{
    int dataN[max];
    string nameN[max];
    int awalN;
    int akhirN;
}R;
struct salin{
    int data_salin;
    string name_salin;
};
struct salinN{
    int data_salinN;
    string name_salinN;
};
    
//deklarasi variabel nama
string nama;
string namaN;
int no[100];

//Deklarasi Fungsi void Pasien
void bersih();
void tampil();
void input();
void hapus();
void fitur();

//Queue pada Pasien Rawat Inap
void bersih(){
    Q.awal=0;
    Q.akhir=0;
}
bool kosong(){
    if(Q.akhir==0){
        return true;
    }else{
        return false;
    }
}
bool penuh(){
    if(Q.akhir==max){
        return true;
    }else{
        return false;
    }
}
void tampil(){
    cout<<"\n";
    cout<<"Urutan Bubble sort Pasien Rawat Inap";
    struct salin salinan[Q.akhir];
    struct salin temp;
    for(int i=Q.awal; i<=Q.akhir;i++)
    {
        salinan[i].data_salin=Q.data[i];
        salinan[i].name_salin=Q.name[i];
     }
     for(int i = Q.awal; i < Q.akhir; i++) {
		for (int j = i+1; j < Q.akhir; j++){
			if (salinan[i].data_salin > salinan[j].data_salin){
				// pertukaran data
				temp = salinan[i];
				salinan[i] = salinan[j+1];
				salinan[j+1] = temp;
			}			
		}
	}
    if(!kosong()){
        for(int i=Q.awal;i<=Q.akhir-1;i++){
            cout<<"\nPasien dengan Nomor Rekam Medik\n";
            cout<<salinan[i].data_salin<<" | "<<salinan[i].name_salin;
            cout<<"\n";
        }
    }
    cout<<"\n";
}
void input(){
    //tampil();
    int i=0;
    if(!penuh()){
       // int no[100];
        string alamat, jenkel,umur;
        cout<<"DATA PASIEN RAWAT\n";
        cout<<"==================\n";
        
        cin.ignore();
        cout<<"Nama Pasien Rawat \t: ";
        getline(cin,nama);
        cout<<"Umur Pasien Rawat \t: ";
        getline(cin,umur);
        cout<<"Jenis Kelamin Pasien \t: ";
        getline(cin,jenkel);
        cout<<"Alamat Pasiem Rawat \t: ";
        getline(cin,alamat);
        cout<<"Nomor Rekam Medik \t: ";
        cin>>no[i];
        
        Q.data[Q.akhir]=no[i];
        Q.name[Q.akhir]=nama;
        Q.akhir++;
        
        //tampil();
        cin.ignore();
        cout<<"\nData berhasil ditambahkan\n";
        cout<<"Tekan Enter untuk ke halaman menu";
        cin.get();       
    }else{
        cout<<"Antrian Sudah Penuh !!"<<endl;
    }
    getchar();
}
void hapus(){
    tampil();
    if(!kosong()){
        cout<<"Mengambil data\" "<<Q.data[Q.awal]<<" | "<<Q.name[Q.awal]<<endl;
        for(int i=Q.awal;i<Q.akhir;i++){
            Q.data[i]=Q.data[i+1];
            Q.name[i]=Q.name[i+1];
        }
        Q.akhir--;
    }else{
        cout<<"Antrian Kosong";
    }
    getchar();
}

void inap(){
    int ya;
    
        fitur:
        cout<<"Rumah Sakit Rindu Sehat\n";
        cout<<"=====================\n";
        cout<<"1. Menginput data pasien rawat Inap\n";
        cout<<"2. Tampilkan Data Pasien Rawat Inap\n";
        cout<<"3. Hapus Urutan Pasien Rawat Inap\n";
        cout<<"4. Kosongkan Data Pasien Rawat Inap\n";
        cout<<"5. Fitur Utama Program\n";
        cout<<"=====================\n";
        cout<<"Masukan Pilihan : ";
        cin>>ya;
        switch(ya){
            case 1:
                input();
                system("cls");
                goto fitur;
                break;
            case 2:
                tampil();
                cin.ignore();
                cout<<"Tekan Enter untuk ke halaman menu";
                cin.get();
                system("cls");
                goto fitur;
                break;
             case 3:
                 hapus();
                 cout<<"Tekan Enter untuk ke halaman menu";
                cin.get();
                system("cls");
                goto fitur;
                break;
             case 4:
                 bersih();
                 cin.ignore();
                 cout<<"Tekan Enter untuk ke halaman menu";
                cin.get();
                system("cls");
                goto fitur;
                break;     
            case 5:
                cin.ignore();
                cout<<"\nTekan Enter untuk ke Menu Awal";
                cin.get();
                system ("cls");
                fitur();  
                break;
            default:
                cin.ignore();
                cout<<"Input yang anda masukan salah\n";
                cout<<"Tekan Enter untuk ke menu Rawat Jalan";
                cin.get();
                system("cls");
                goto fitur;  
        }    
}

//Queue Pasien Rawat Jalan
void bersih2(){
    R.awalN=0;
    R.akhirN=0;
}
bool kosong2(){
    if(R.akhirN==0){
        return true;
    }else{
        return false;
    }
}
bool penuh2(){
    if(R.akhirN==max){
        return true;
    }else{
        return false;
    }
}
void tampil2(){
    cout<<"\n";
    cout<<"Urutan Bubble sort Pasien Rawat Jalan";
    struct salinN salinanN[R.akhirN];
    struct salinN tempN;
    for(int i=R.awalN; i<=R.akhirN;i++)
    {
        salinanN[i].data_salinN=R.dataN[i];
        salinanN[i].name_salinN=R.nameN[i];
     }
     for(int i = R.awalN; i < R.akhirN; i++) {
		for (int j = i+1; j < R.akhirN; j++){
			if (salinanN[i].data_salinN > salinanN[j].data_salinN){
				// pertukaran data
				tempN = salinanN[i];
				salinanN[i] = salinanN[j+1];
				salinanN[j+1] = tempN;
			}			
		}
	}
    if(!kosong2()){
        for(int i=R.awalN;i<=R.akhirN-1;i++){
            cout<<"\nPasien dengan Nomor Rekam Medik\n";
            cout<<salinanN[i].data_salinN<<" | "<<salinanN[i].name_salinN;
            cout<<"\n";
        }
    }
    cout<<"\n";
}
void input2(){
    //tampil2();
    if(!penuh2()){
        int noN;
        string alamatN, jenkelN,umurN;
        cout<<"DATA PASIEN RAWAT\n";
        cout<<"==================\n";
        
        cin.ignore();
        cout<<"Nama Pasien Rawat \t: ";
        getline(cin,namaN);
        cout<<"Umur Pasien Rawat \t: ";
        getline(cin,umurN);
        cout<<"Jenis Kelamin Pasien \t: ";
        getline(cin,jenkelN);
        cout<<"Alamat Pasiem Rawat \t: ";
        getline(cin,alamatN);
        cout<<"Nomor Rekam Medik \t: ";
        cin>>noN;
        
        R.dataN[R.akhirN]=noN;
        R.nameN[R.akhirN]=namaN;
        R.akhirN++;
        
       // tampil2();
        cin.ignore();
        cout<<"\nData berhasil ditambahkan\n";
        cout<<"Tekan Enter untuk ke halaman menu";
        cin.get();       
    }else{
        cout<<"Antrian Sudah Penuh !!"<<endl;
    }
    getchar();
}
void hapus2(){
    tampil2();
    if(!kosong2()){
        cout<<"Mengambil data\" "<<R.dataN[R.awalN]<<" | "<<R.nameN[R.awalN]<<endl;
        for(int i=R.awalN;i<R.akhirN;i++){
            R.dataN[i]=R.dataN[i+1];
            R.nameN[i]=R.nameN[i+1];
        }
        R.akhirN--;
    }else{
        cout<<"Antrian Kosong";
    }
    getchar();
}

void jalan(){
    int yes;
    
        menu:
        cout<<"Rumah Sakit Rindu Sehat\n";
        cout<<"=====================\n";
        cout<<"1. Menginput data pasien rawat Jalan\n";
        cout<<"2. Tampilkan Data Pasien Rawat Jalan\n";
        cout<<"3. Hapus Urutan Pasien Rawat Jalan\n";
        cout<<"4. Kosongkan Data Pasien Rawat Jalan\n";
        cout<<"5. Fitur Utama Program\n";
        cout<<"=====================\n";
        cout<<"Masukan Pilihan : ";
        cin>>yes;
        switch(yes){
            case 1:
                input2();
                system("cls");
                goto menu;
                break;
            case 2:
                tampil2();
                cin.ignore();
                cout<<"Tekan Enter untuk ke halaman menu";
                cin.get();
                system("cls");
                goto menu;
                break;
             case 3:
                 hapus2();
                 cout<<"Tekan Enter untuk ke halaman menu";
                cin.get();
                system("cls");
                goto menu;
                break;
             case 4:
                 bersih2();
                 cin.ignore();
                 cout<<"Tekan Enter untuk ke halaman menu";
                cin.get();
                system("cls");
                goto menu;
                break;     
            case 5:
                cin.ignore();
                cout<<"\nTekan Enter untuk ke Menu Awal";
                cin.get();
                system ("cls");
                fitur();
                break;
            default:
                cin.ignore();
                cout<<"Input yang anda masukan salah\n";
                cout<<"Tekan Enter untuk ke menu Rawat Jalan";
                cin.get();
                system("cls");
                goto menu;                 
        }    
}
//CARI rawat inap Penggunaan Shearcing
void cari(){
	system("cls");
	string dicari;
	int  medik;
	bool find = false;
	cout<<"   Nama Pasien Yang Ingin dicari : ";
	cin>>dicari;
	cout<<"   Nomer Medik Pasien : ";
	cin>>medik;
	for(int i=0; i<Q.data[i]; i++){
		if(Q.name[i]==dicari && Q.data[i]==medik){
			find=true;
			break;
		}		
	}
	if(find){
		cout<<"\n   Nama "<<dicari<<" dengan nomor Medik "<<medik<<"  Berada di RS. Rindu Sehat.";
		cin.ignore();
	cout<<"\n   Tekan Enter,  Kembali ke Menu";
	cin.get();
	system("cls");
	fitur();
	}else{
		cout<<"\n   Maaf Nama tidak ditemukan\nSilahkan coba cari di Daftar Pasien rawat jalan";
		cin.ignore();
	cout<<"\n   Tekan Enter,  Kembali ke Menu";
	cin.get();
	system("cls");
	fitur();	
	}
}
//cari rawat jalan Penggunaan shearcing
void cari_new(){
	system("cls");
	string dicari_new;
	int  medik_new;
	bool find_new = false;
	cout<<"   Nama Pasien Yang Ingin dicari : ";
	cin>>dicari_new;
	cout<<"   Nomer Medik Pasien : ";
	cin>>medik_new;
	for(int i=0; i<R.dataN[i]; i++){
		if(R.nameN[i]==dicari_new && R.dataN[i]==medik_new){
			find_new=true;
			break;
		}
	}
	if(find_new){
		cout<<"\n   Nama "<<dicari_new<<" dengan nomor Medik "<<medik_new<<"  Berada di RS. Rindu Sehat.";
		cin.ignore();
	cout<<"\n   Tekan Enter,  Kembali ke Menu";
	cin.get();
	system("cls");
	fitur();
	}else{
		cout<<"\n   Maaf Nama tidak ditemukan\nSilahkan cari di Daftar Pasien rawat Inap";
		cin.ignore();
	cout<<"\n   Tekan Enter,  Kembali ke Menu";
	cin.get();
	system("cls");
	fitur();	
	}
}

void fitur(){
    int jwb;
    utama:
    cout<<"Rumah Sakit Rindu Sehat\n";
    cout<<"=====================\n";
    cout<<"1. Pasien Rawat Inap\n";
    cout<<"2. Pasien Rawat Jalan\n";
    cout<<"3. Cari data Pasien\n";
    cout<<"4. Pengurutan data Pasien\n";
    cout<<"5. Exit Program\n";
    cout<<"=====================\n";
    cout<<"Pilih Fitur di atas : ";
    cin>>jwb;
    system("cls");
    if(jwb==1){
        inap();
    }else if(jwb==2){
        jalan();
    }else if(jwb==3){
        int milih;
        cout<<"Status Pasien\n";
        cout<<"1. Pasien Rawat Inap\n";
        cout<<"2. Pasien Rawat Jalan\n";
        cout<<"Inputkan Angka : ";
        cin>>milih;
        if(milih==1){
            cari();
        }else if(milih==2){
            cari_new();
        }
    }else if(jwb==4){
        tampil();      
        tampil2();
        cin.ignore();
        cout<<"Tekan Enter untuk Kemnbali ke Fitur Utama";
        cin.get();
        system("cls");
        fitur();
    }else if(jwb==5){
        cout<<"Program Selesai Terima Kasih\n";
        cout<<"Lekas Sembuh dan Jangan Lupa Untuk Hidup Sehat\n";
    }else{
        cout<<"\nAngka yang anda masukan salah";
        cout<<"\nMohon ketikan angka (1-5) untuk memilih opsi yang benar";
        cin.ignore();
        cout<<"\nTekan Enter Untuk Ke Menu Awal";
        cin.get();
        system("cls");
        goto utama;
    }
}
int main(){
    fitur();
}