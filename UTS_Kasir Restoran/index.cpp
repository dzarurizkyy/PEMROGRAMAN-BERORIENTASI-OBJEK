#include <iostream>
#include <string>

using namespace std;

// Procedure (Report)
void strukKosong();
void strukTidakAda();
void hapusBerhasil();

// Class 
class MenuRestoran {
	private:
		// Data Member
		int 
			hargaMenu,
			stokMenu;
		string
			kodeMenu,
			namaMenu; 
	public:
		// Pointer to object
		MenuRestoran * next;
		
		// Constructor
		MenuRestoran (string kode, string nama, int harga, int stok) { 
			this->kodeMenu   = kode;
			this->namaMenu   = nama;
			this->hargaMenu  = harga;
			this->stokMenu   = stok;
			this->next       = NULL;
		}
		
		// Destructor
		~MenuRestoran() {
			
		}
		
		// Method
		void setStok(int stok) {
			this->stokMenu = stok;
		}
		
		string getKode() {
			return this->kodeMenu;
		}
		
		string getNama() {
			return this->namaMenu;
		}
		
		int getHarga() {
			return this->hargaMenu;
		}
		
		int getStok() {
			return this->stokMenu;
		}
};

class LinkedList1 {
	private:
		// Data Member
		int noUrutA = 1, 
			noUrutB = 1;
	public:
		MenuRestoran* head;
		
		// Constructor
		LinkedList1() {
			this->head = NULL;
		}
		
		// Destructor
		~LinkedList1() {
			
		}
		
		// Method
		
		void tambahMenu(string nama, int harga, int stok) {
			string kode = "A";
			while(kode == "A" || kode == "B") {
				if(this->noUrutA >= 10) {
					kode = "B";	
					kode += to_string(this->noUrutB);
					this->noUrutB++;	
				}
				else {
					kode += to_string(this->noUrutA);	
				}
				this->noUrutA++;
			}
			
			MenuRestoran* newNode = new MenuRestoran(kode, nama, harga, stok);
			if(head == NULL) {
				head = newNode;
			}
			else {
				MenuRestoran* current = head;
				while(current->next != NULL) {
					current = current->next;
				}
				current->next = newNode;
			}
		}
		
	void tampilkanMenu() {
		MenuRestoran* current = head;
		cout << "------------------------------------------" << endl;
		cout << "Kode Menu" << " | " << "Daftar Menu" << " | " << " Harga" << "  | " << "Stok" << endl;
		cout << "------------------------------------------" << endl;
		while(current != NULL) {
			cout << "    " << current->getKode() << "    | " << current->getNama() << " | Rp" << current->getHarga() << " | " << current->getStok() << endl;
			current = current->next;
		}
			cout << "------------------------------------------\n" << endl;
		}
};

// Global Variable
LinkedList1 mn;

class Customer {
	private:
		// Data Member
		string 
			kodeCustomer,
			namaCustomer,
			tglPesanan,
			pesananCustomer;
		int
			totalPembayaran;
	public:
		Customer* next;
		  
		// Constructor
		Customer(string kode, string nama, string tanggal, int total) {
			this->kodeCustomer    = kode;
			this->namaCustomer    = nama;
			this->tglPesanan      = tanggal;
			this->totalPembayaran = total;
		}
		
		// Destructor
		~Customer() {
			
		}
		
		// Method
		string getKode() {
			return this->kodeCustomer;
		}
		
		string getNama() {
			return this->namaCustomer;
		}
		
		string getTglPesanan() {
			return this->tglPesanan;
		}
		
		string getPesananCustomer() {
			return this->pesananCustomer;	
		}
		
		int getTotal() {
			return this->totalPembayaran;
		}
		
		void setPesananCustomer(string pesanan) {
			this->pesananCustomer = pesanan;
		}
};

class LinkedList2 {
	private:
		// Data Member
		int noUrut = 1;
		int jumlahPesanan;
		Customer* head;
		MenuRestoran* pesanan;
	public:
		// Constructor
		LinkedList2() {
			this->head = NULL;
		}
		
		// Destructor
		~LinkedList2() {
			
		}
		
		// Method
		void tambahPesanan(string nama, string tanggal) {
			string kode = "CS";
			
			while(kode == "CS") {
				kode += to_string(this->noUrut);
				this->noUrut++;
			}
			
			cout << "Masukkan jumlah menu yang dipesan : ";
			cin  >> jumlahPesanan;
			cout << "\n------------------------------------------" << endl;
			
			string daftarPesanan[jumlahPesanan];			
			int hargaPesanan[jumlahPesanan];
			int stokPesanan[jumlahPesanan];
			int totalHarga = 0;
			
			for(int i=0; i<jumlahPesanan; i++) {
				string kodeMenu; 
				cout << "Masukkan kode menu ke-" << i+1 << " : ";
				cin  >> kodeMenu;
				MenuRestoran* current = mn.head;
				
				bool cekPesanan = false;
				while(current != NULL) {
					if(current->getKode() == kodeMenu) {
						cekPesanan = true;
						if(current->getStok() > 0) {
							daftarPesanan[i] = current->getNama();
							hargaPesanan[i]  = current->getHarga();
							stokPesanan[i]   = current->getStok() - 1;
							current->setStok(stokPesanan[i]);
							totalHarga += hargaPesanan[i];
 						}
 						else {
 							cout << "Stok " << current->getNama() << " sudah habis" << endl;	
						}
						break;
					}
					current = current->next;	
				}
				
				if(!cekPesanan) {
					cout << "Kode menu " << kodeMenu << " tidak tersedia" << endl;
					i--;
				}
			}
			
			if(totalHarga > 0) {
				Customer* newNode = new Customer(kode, nama, tanggal, totalHarga);
				newNode->setPesananCustomer("");
				
				for(int i = 0; i<jumlahPesanan; i++) {
					if(i == 0) {
						newNode->setPesananCustomer(" - " + daftarPesanan[i]);
					}
					else {
						newNode->setPesananCustomer(newNode->getPesananCustomer() += "\n - " + daftarPesanan[i]); 
					}
				}
				if(head == NULL) {
					head = newNode;
					newNode->next = NULL;
				}
				else {
					Customer* current = head;
					while(current->next != NULL) {
						current = current->next;
					}
					current->next = newNode;
					newNode->next = NULL;
				}
				cout << "------------------------------------------" << endl;
				cout << "Total Bayar            : Rp" << newNode->getTotal() << endl;
				cout << "------------------------------------------\n" << endl;
			}
		}
		
		void cariPesanan(string kode) {
			Customer* current = head;
			if(head == NULL) {
				strukKosong();
			}
			else {
				while(current != NULL && current->getKode() != kode) {
					current = current->next;
				}
				
				if(current == NULL) {
					strukTidakAda();
				}
				else {
					cout << "\n";
					cout << "----------------------------------------------" << endl;
					cout << "               DETAIL PESANAN                 " << endl;
					cout << "----------------------------------------------" << endl;
					cout << "Kode customer    : " << current->getKode() << endl;
					cout << "Nama customer    : " << current->getNama() << endl;
					cout << "Tanggal pesanan  : " << current->getTglPesanan() << endl;
					cout << "Total pembayaran : Rp" << current->getTotal() << "\n" << endl;
					cout << "----------------------------------------------" << endl;
					cout << "Daftar pesanan    " << endl;
					cout << "----------------------------------------------" << endl;
					cout << current->getPesananCustomer() << endl;
					cout << "----------------------------------------------\n" << endl;
				}
			}	
		}
		
		void hapusPesanan(string kode) {
			Customer* current = head;
			if(head == NULL) {
				strukKosong();
			}
			else {
				if(current != NULL && current->getKode() == kode) {
					head = current->next;
					delete current;
					hapusBerhasil();
				}
				else {
					Customer* prev = NULL;
					while(current != NULL && current->getKode() != kode) {
						prev = current;
						current = current->next;
					}
					
					if(current == NULL) {
						strukTidakAda();
					}
					else {
						prev->next = current->next;
						delete current;
						hapusBerhasil();
					}
				}
			}
		}
		
		void tampilkanPesanan() {
			int i = 1;
			Customer* current = head;
			if(head == NULL) {
				strukKosong();
			}
			else {
				while(current != NULL) {
					cout << "----------------------------------------------" << endl;
					cout << "              DETAIL PESANAN " << i << endl;
					cout << "----------------------------------------------\n" << endl;
					cout << "Kode customer    : " << current->getKode() << endl;
					cout << "Nama customer    : " << current->getNama() << endl;
					cout << "Tanggal pesanan  : " << current->getTglPesanan() << endl;
					cout << "Total pembayaran : Rp" << current->getTotal() << "\n" << endl;
					cout << "----------------------------------------------" << endl;
					cout << "Daftar pesanan    " << endl;
					cout << "----------------------------------------------" << endl;
					cout << current->getPesananCustomer() << endl;
					cout << "----------------------------------------------\n\n" << endl;
					current = current->next; 
					i++;
				}	
			}
		}
};

int main() {
	int pilihMenu;
	string temp1, temp2;
	
	mn.tambahMenu("Nasi Kuning", 18000, 30);
	mn.tambahMenu("Nasi Goreng", 20000, 50);
	mn.tambahMenu("Nasi Mawut ", 20000, 30);
	mn.tambahMenu("Nasi Padang", 25000, 30);
	mn.tambahMenu("Nasi Gila  ", 25000, 40);
	mn.tambahMenu("Nasi Bakar ", 25000, 30);
	mn.tambahMenu("Sate Ayam  ", 22000, 30);
	mn.tambahMenu("Soto       ", 15000, 40);
	mn.tambahMenu("Bakso      ", 18000, 50);
	mn.tambahMenu("Es Teh     ", 10000, 50);
	mn.tambahMenu("Es Jeruk   ", 12000, 40);
	mn.tambahMenu("Teh Tawar  ", 10000, 30);
	mn.tambahMenu("Teh Manis  ", 10000, 30);
	mn.tambahMenu("Kopi Hitam ", 10000, 40);
	mn.tambahMenu("Jus Alpukat", 16000, 30);
	mn.tambahMenu("Jus Mangga ", 16000, 30);
	mn.tambahMenu("Jus Melon  ", 16000, 30);
	mn.tambahMenu("Jus Jambu  ", 16000, 30);
	
	LinkedList2 cs;
		
	cout << "Nama \t: Dzaru Rizky Fathan Fortuna" << endl;
	cout << "NPM \t: 21081010283" << endl;
	cout << "Kelas \t: Pemrograman Berorientasi Objek F081 \n" << endl;
	
	Beranda:
	cout << "----------------------------------------------" << endl;
	cout << "\t RESTORAN KULINER NUSANTARA"<< endl;
	cout << "----------------------------------------------\n" << endl;
	cout << "1. Pesan Makanan/Minuman" << endl;
	cout << "2. Lihat Menu Restoran" << endl;
	cout << "3. Cari Struk Pelanggan" << endl;
	cout << "4. Lihat Semua Struk" << endl;
	cout << "5. Hapus Struk Pelanggan \n" << endl;
	
	cout << "Pilih : ";
	cin  >> pilihMenu;
	cin.ignore();
		
	system("cls");
	switch(pilihMenu) {
		case 1: {
			cout << "Nama Pelanggan  : ";
			getline(cin, temp1);
			cout << "Tanggal Pesanan : ";
			getline(cin, temp2);
			cout << "\n";
			
			mn.tampilkanMenu();		
			cs.tambahPesanan(temp1, temp2);
			goto KeluarProgram;
			break;
		}
		case 2: {
			mn.tampilkanMenu();
			KeluarProgram:
			while(true) {
				char keluar;
				cout << "Kembali ke beranda (y/n)? ";
				cin  >> keluar;
				if(keluar == 'y') {
					system("cls");
					goto Beranda;
				}
				else if(keluar == 'n') {
					cout << "\n";
					cout << "Program selesai....";
					break;
				}
				else {
					system("cls");
					cout << "Mohon maaf, input tidak valid. Mohon masukkan 'y' atau 'n'" << endl;
					cout << "----------------------------------------------" << endl;
				}
			}
			break;
		}
		case 3: {
			cout << "Kode Pesanan : ";
			cin  >> temp1;
			cs.cariPesanan(temp1);
			goto KeluarProgram;
			break;
		}
		case 4: {
			cs.tampilkanPesanan();
			goto KeluarProgram;
			break;
		}
		case 5: {
			cout << "Kode Pesanan : ";
			cin  >> temp1;
			cs.hapusPesanan(temp1);
			goto KeluarProgram;	
			break;
		}
		default: {
			system("cls");
			cout << "Mohon maaf, input tidak valid. Mohon masukkan 1/2/3/4/5 \n" << endl;
			goto Beranda;
			break;
		}
	}
	return 0;
}

// Procedure (Worker)
void strukTidakAda() {
	cout << "---------------------------------------------- " << endl;
	cout << "Kode struk pelanggan tidak tersedia... \n" << endl;
}

void strukKosong() {
	cout << "---------------------------------------------- " << endl;
	cout << "Data struk pelanggan masih kosong \n" << endl;
}

void hapusBerhasil() {
	cout << "---------------------------------------------- " << endl;
	cout << "Data struk pelanggan berhasil dihapus \n" << endl;
}