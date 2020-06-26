#include<bits/stdc++.h>
 
using namespace std;
#define ll long long
 
float gajibersih(int gajipokok);
void tunjanganPajak(int gajipokok);
void gajitetap(int lembur, int golongan);
int main()
{
	
	int n,totaljamkerja,count = 0,i,j,temp;	
	cout << "Jumlah data pegawai : ";
	cin >> n;
	string data[n][3], nama;
	int jamkerja[n][2], gol[n];
	ll gaji[n];
	for (i = 0 ; i < n ; i++)
	{	
	
		cout << endl;
		cout << i+1 << "._________\n"; 
		cout << "Nama\t\t: ";
		cin >>  data[i][0];
		cout << "NIP\t\t: ";
		cin >>  data[i][1];
		cout << "Gaji\t\t: ";
		cin >> gaji[i];
		cout << "Golongan\t: ";
		cin >> gol[i];
		cout << "Jam kerja wajib\t: ";
		cin >> jamkerja[i][0];
		cout << "Total jam kerja\t: ";
		cin >> jamkerja[i][1];
			
	}
	cout << "\n\n===============DATA PEGAWAI===============\n";
	for( i = 0 ; i < n ; i ++)
	{
		cout << endl << i+1 << "--------------------------\n";
		cout << "Nama\t\t: " << data[i][0] << endl; 
		cout << "NIP\t\t: " << data[i][1] << endl;
		cout << "Gaji\t\t: " << gaji[i] << endl; 
		cout << "Golongan\t: " << gol[i] << endl;
		cout << "Total  Jam Kerja: " << jamkerja[i][1] << " jam" <<endl;
		totaljamkerja = jamkerja[i][1] - jamkerja[i][0];
		if ( totaljamkerja < 0) {
			cout << "Anda bolos kerja " << jamkerja[i][0] - jamkerja[i][1] << " jam" << ". Maaf gaji anda tidak dapat diproses. \nPerusahaan kami tidak toleran terhadap ketidak dispilinan pegawai."<< endl;
			continue;
		}else{
			cout << "Jam kerja lembur: " << totaljamkerja<<" jam"<<endl;		
			tunjanganPajak(gaji[i]);
			gajitetap((jamkerja[i][1] - jamkerja[i][0]), gol[i]);
		}
		
	}
	for(i = 0; i<n; i++) {
   		for(j = i+1; j<n; j++)
   		{
      		if(gaji[j] < gaji[i]) {
        		temp = gaji[i];
         		gaji[i] = gaji[j];
        	 	gaji[j] = temp;
      		}
   		}
	}
cout <<"\nUrutan gaji tertinggi...\n";
for(i = 0; i<n; i++) {
   cout <<gaji[i]<<"\n";
   }
	cout << "\n\nSearching nama pegawai : ";
	cin >> nama;
	cout << "\n-------------------------------------\n";
	for(i = 0 ; i < n ; i ++)
	{
		
		
		if (nama == data[i][0])
		{
			count++;
			cout << "Nama\t\t: " << data[i][0] << endl; 
			cout << "NIP\t\t: " << data[i][1] << endl;
			cout << "Gaji\t\t: " << gaji[i] << endl; 
			cout << "Golongan\t: " << gol[i] << endl;
			continue;
		}
		cout << "\n**********\n";
	}
	cout << "DITEMUKAN : " << count;
	
	
	
}
 
int gajibersih(float tunjangan, int gajipokok)
{
	int gajiBersih = (tunjangan + gajipokok);
	return gajiBersih;
}
 
void tunjanganPajak(int gajipokok)
{
	float tunjangan = 0.15 * gajipokok;
	float pajak = 0.1 * (tunjangan + gajipokok);
	cout << "Pajak\t\t: " << fixed << setprecision(0) << "Rp. " << pajak << endl;
	cout << "Tunjangan\t: " << fixed << setprecision(0) << "Rp. " <<  tunjangan <<endl;
	cout << "Gaji Bersih\t: " << fixed <<setprecision(0)<< "Rp. "<< gajibersih(tunjangan,gajipokok) - pajak;
}
 
void gajitetap(int lembur, int golongan)
{
	ll gajitetap;
	lembur = lembur <= 0 ? 0:lembur;
	switch(golongan){
	
		case 1:
			gajitetap = 500000 + (lembur * 5000);
			break;
		case 2:
			gajitetap = 300000 + (lembur * 3000);
			break;
		case 3:
			gajitetap = 250000 + (lembur * 2000);
			break;
		case 4:
			gajitetap = 100000 + (lembur * 1500);
			break;
		case 5:
			gajitetap = 50000 + (lembur * 1000);
			break;
		default:
			break;
	}
	cout << "\nGaji tetap\t: " <<"Rp. " <<  gajitetap;
			
}
