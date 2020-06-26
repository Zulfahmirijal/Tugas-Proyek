#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
 
 
void struk(int menu, string nama, ll id_person, ll id_book, int day, int month, int year, int jml);
 
bool isLeap(int y) 
{ 
	if (y%100 != 0 && y%4 == 0 || y %400 == 0) 
		return true; 
 
	return false; 
} 
int d2,m2,y2;
 
int offsetDays(int d, int m, int y) 
{ 
	int offset = d; 
 
	switch (m - 1) 
	{ 
	case 11: 
		offset += 30; 
	case 10: 
		offset += 31; 
	case 9: 
		offset += 30; 
	case 8: 
		offset += 31; 
	case 7: 
		offset += 31; 
	case 6: 
		offset += 30; 
	case 5: 
		offset += 31; 
	case 4: 
		offset += 30; 
	case 3: 
		offset += 31; 
	case 2: 
		offset += 28; 
	case 1: 
		offset += 31; 
	} 
 
	if (isLeap(y) && m > 2) 
		offset += 1; 
 
	return offset; 
} 
 
 
void revoffsetDays(int offset, int y, int *d, int *m) 
{ 
	int month[13] = { 0, 31, 28, 31, 30, 31, 30, 
					31, 31, 30, 31, 30, 31 }; 
 
	if (isLeap(y)) 
		month[2] = 29; 
 
	int i; 
	for (i = 1; i <= 12; i++) 
	{ 
		if (offset <= month[i]) 
			break; 
		offset = offset - month[i]; 
	} 
 
	*d = offset; 
	*m = i; 
} 
 
 
void addDays(int d1, int m1, int y1, int x) 
{ 
	int offset1 = offsetDays(d1, m1, y1); 
	int remDays = isLeap(y1)?(366-offset1):(365-offset1); 
 
	 
	int offset2; 
	if (x <= remDays) 
	{ 
		y2 = y1; 
		offset2 = offset1 + x; 
	} 
 
	else
	{ 
	
		x -= remDays; 
		y2 = y1 + 1; 
		int y2days = isLeap(y2)?366:365; 
		while (x >= y2days) 
		{ 
			x -= y2days; 
			y2++; 
			y2days = isLeap(y2)?366:365; 
		} 
		offset2 = x; 
	} 
 
	
	
	revoffsetDays(offset2, y2, &d2, &m2); 
 
} 
int main()
{
	string nama, name;
	int dd,mm,yyyy,pil,jml;
	ll id_peminjam,id_buku;
	srand(time(0));
  	
	cout << "SELAMAT DATANG DI PERPUSTAKAAN\n";
	cout << "MENU\n";
	cout << "1. PENGEMBALIAN BUKU\n";
	cout << "2. PEMINJAMAN BUKU\n";
	cout << "3. BUKU HILANG\n";
	cout << "Pilihan : \n";
	cin >> pil;
	if(pil == 1)
	{
		cout << "Nama peminjam\t: \n";
		cin >> nama;
		cout << "Nomor ID\t: " << endl;
		cin >> id_peminjam;
		cout <<"ID Peminjaman\t: " << endl;
		cin >> id_buku;
		cout << "Jumlah buku\t: " << endl;
		cin >> jml;
		cout << "Tanggal Peminjaman\t: " << endl;
		cin >> dd;
		cout << "Bulan\t\t: " << endl;
		cin >> mm;
		cout << "Tahun\t\t: " << endl;
		cin >> yyyy;
		struk(1,nama,id_peminjam,id_buku,dd,mm,yyyy,jml);
		
	} else if(pil == 2)
	{
		cout << "Nama peminjam\t: " << endl;
		cin >> nama;
		cout << "Nomor ID\t: " << endl;
		cin >> id_peminjam;
		cout <<"ID Peminjaman\t: " << endl;
		cin >> id_buku;
		cout << "Jumlah buku\t: " << endl;
		cin >> jml;
		struk(2,nama,id_peminjam, id_buku, dd,mm,yyyy,jml);
		
		
	}
	else if(pil == 3)
	{
		cout << "Nama peminjam\t: " << endl;
		cin >> nama;
		cout << "Nomor ID\t: " << endl;
		cin >> id_peminjam;
		cout <<"ID Peminjaman\t: " << endl;
		cin >> id_buku;
		cout << "Jumlah buku\t: " << endl;
		cin >> jml;
		cout << "ANDA DIDENDA SEBESAR : Rp. " << rand() * jml;
	}
	cout << "\n\nSearching nama peminjam : ";
	cin >> name;
	cout << "\n-------------------------------------\n";
	if (name == nama)
	{
		cout << "Nama : " << nama << endl;
		cout << "Nomor ID : " << id_peminjam;
	} else
	{
		cout << "\nTidak ditemukan" << endl;
	}
	
		
}
 
void struk(int menu, string nama, ll id_person, ll id_book, int day, int month, int year, int jml)
{
	
	 time_t now = time(0);
	int count = 1000;
   tm *ltm = localtime(&now);
	if (menu == 1)
	{
		addDays(day, month, year, 7); 
		cout << "---------------STRUK PENGEMBALIAN---------------\n";
		cout << "|Nama\t\t\t: " << nama << "\t\t\t|\n";
		cout << "|ID\t\t\t: " << id_person << "\t\t\t|\n";
		cout << "|ID Pinjam\t\t: " << id_book << "\t\t\t|\n";
		cout << "Tanggal Peminjaman\t: " << day << ", " << month << ", " << year << "\t\t|\n";
		cout << "|Tanggal Pengembalian\t: " << ltm->tm_mday << ":" << 1 + ltm->tm_mon<< ":" <<  1900 + ltm->tm_year<< "\t\t|\n";
		if (d2 < (ltm->tm_mday ))
		{
			
			cout << "\nAnda dikenakan denda sebanyak : Rp. " << (jml * (count * (((ltm->tm_mday - (d2 + 1) )  + 6) / 7)));
			
		}
		else if(d2 == ltm->tm_mday ){
			cout <<"TERIMA KASIH TELAH MENGEMBALIKAN BUKU TEPAT WAKTU\n";
 
		}
		cout <<"\nCATATAN : SERAHKAN STRUK INI KE PETUGAS\n";
		
	}
	else if(menu == 2)
	{
		month = 1 + ltm->tm_mon;
		day = ltm->tm_mday;
		year = 1900 + ltm->tm_year;
		addDays(day, month, year, 7); 
		cout << "---------------STRUK PEMINJAMAN---------------\n";
		cout << "|Nama\t\t: " << nama << "\t\t|\n";
		cout << "|ID\t\t: " << id_person << "\t\t|\n";
		cout << "|ID Pinjam\t\t: " << id_book << "\t\t|\n";
		cout << "Tanggal Peminjaman\t : " << ltm->tm_mday << ":" <<  1 + ltm->tm_mon << ":" << 1900 + ltm->tm_year << "\t|\n";
		cout <<"TERIMA KASIH, HARAP KEMBALIKAN BUKU SEBELUM TANGGAL: " << d2 << ", " << m2 << ", " << y2 << endl; 
		cout <<"CATATAN : SERAHKAN STRUK INI KE PETUGAS\n";
	}
}
