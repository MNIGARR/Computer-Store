#include <iostream>
using namespace std;

//QEYD: Kechdiymiz her shey istifade olunsun
//
//class : Computer
//	fields :
//id(static)
//object_Id
//model(char*)
//vendor(char*)
//videocard(char*)
//monitor(char*)
//cpu_hz
//core
//ram
//disk_size
//isSSD(bool)
//cin, cout overload
//constructors
//destructor


//class : ComputerStore
//	store_name(char*)
//	store_address(char*)
//	Computer** computers; (array)
//	addComputer();
//deleteComputer(int id);
//cin, cout overload
//constructors
//destructor

class Computer {
	static int id;
	int objectId;
	char* model = nullptr;
	char* vendor = nullptr;
	char* videocard = nullptr;
	char* monitor = nullptr;
	double cpuHz;
	int core;
	int ram;
	int discSize;
public:
	//set
	void SetModel (const char* value) {
		delete[] model;
		int length = strlen(value) + 1;
		model = new char[length];
		strcpy_s(model, length, value);
	}
	void SetVendor (const char* value) {
		delete[] vendor;
		int length = strlen(value) + 1;
		vendor = new char[length];
		strcpy_s(vendor, length, value);

	}
	void SetVideocard(const char* value) {
		delete[] videocard;
		int length = strlen(value) + 1;
		videocard = new char[length];
		strcpy_s(videocard, length, value);
	}
	void SetMonitor(const char* value) {
		delete[] monitor;
		int length = strlen(value) + 1;
		monitor = new char[length];
		strcpy_s(monitor, length, value);
	}
	void SetCpuHz(double value) {
		cpuHz = value;
	}
	void SetCore(int value) {
		core = value;
	}
	void SetRam(int value) {
		ram = value;
	}
	void SetDiscSize(int value) {
		discSize = value;
	}

	//get
	int GetId() const {
		return id;
	}
	const char* GetModel() const {
		return model;
	}
	const char* GetVendor() const {
		return model;
	}
	const char* GetVideocard() const {
		return model;
	}
	const char* GetMonitor() const {
		return model;
	}
	double GetCpuHz() const {
		return cpuHz;
	}
	double GetCore() const {
		return core;
	}
	int GetRam() const {
		return ram;
	}
	int GetDiscSize() const {
		return discSize;
	}

	Computer() {
		objectId = id++;
		model = nullptr;
		vendor = nullptr;
		videocard = nullptr;
		monitor = nullptr;
		SetCpuHz(0);
		SetCore(0);
		SetRam(0);
		SetDiscSize(0);
	}

	Computer(const char* vendor, const char* model, const char* videocard, const char* monitor, double cpuHz, int core, int ram, int discSize) {
		objectId = id++;
		SetVendor(vendor);
		SetModel(model);
		SetVideocard(videocard);
		SetMonitor(monitor);
		SetCpuHz(cpuHz);
		SetCore(core);
		SetRam(ram);
		SetDiscSize(discSize);
	}

	Computer(const Computer& comp) {
		id = comp.id;
		SetModel(comp.model);
		SetVendor(comp.vendor);
		SetVideocard(comp.videocard);
		SetMonitor(comp.monitor);
		SetCpuHz(comp.cpuHz);
		SetCore(comp.core);
		SetRam(comp.ram);
		SetDiscSize(comp.discSize);
	}

	Computer& operator=(const Computer& comp) {
		SetModel(comp.model);
		SetVendor(comp.vendor);
		SetVideocard(comp.videocard);
		SetMonitor(comp.monitor);
		SetCpuHz(comp.cpuHz);
		SetCore(comp.core);
		SetRam(comp.ram);
		SetDiscSize(comp.discSize);
		return *this;
	}
		
	friend ostream& operator<<(ostream& out, const Computer& obj) {
				out << "\tComputer:\n" << "Object Id:" << obj.id << "\nVendor: " << obj.vendor << "\nModel: " << obj.model << "\nMonitor: " << obj.monitor << "\nCpu-Hz: " << obj.cpuHz << "\nCore: " << obj.core << "\nRam: " << obj.ram << "\nDisk size: " << obj.discSize << "\n";
				return out;
	}

	friend istream& operator>>(istream& in, Computer& obj) {
		char* bf = new char[40];
		cout << "Model: ";
		in.getline(bf, 40);
		obj.SetModel(bf);

		cout << "Vendor: ";
		in.getline(bf, 40);
		obj.SetVendor(bf);
		

		cout << "Videocard: ";
		in.getline(bf, 40);
		obj.SetVideocard(bf);
		
		cout << "Monitor: ";
		in.getline(bf, 40);
		obj.SetMonitor(bf);
		
		cout << "Cpu-Hz: ";
		double y;
		cin >> y;
		obj.SetCpuHz(y);
		
		cout << "Core: ";
		int c;
		cin >> c;
		obj.SetCore(c);
		
		cout << "Ram: ";
		int r;
		cin >> r;
		obj.SetRam(r);
		
		cout << "Disc Size: ";
		int d;
		cin >> d;
		obj.SetDiscSize(d);
		
		delete[] bf;
		return in;
	}

	~Computer() {
		delete[] model;
		delete[] vendor;
		delete[] videocard;
		delete[] monitor;
	}
};
int Computer::id;

class ComputerStore {
	char* storeName;
	char* storeAddress;
	int count;
	Computer** computers;
public:
	ComputerStore(const char* name, const char* add) {
		SetName(name);
		SetAddress(add);
		computers = nullptr;
		count = 0;
	}
		
	void SetName(const char* value) {
		delete[] storeName;
		int length = strlen(value) + 1;
		storeName = new char[length];
		strcpy_s(storeName, length, value);
	}
	void SetAddress(const char* value) {
		delete[] storeAddress;
		int length = strlen(value) + 1;
		storeAddress = new char[length];
		strcpy_s(storeAddress, length, value);
	}
	const char* GetName() { 
		return storeName;
	}
	const char* GetAddress() {
		return storeAddress;
	}
	
	void AddComputer(const Computer* value) {
		Computer** newArr = new Computer * [count + 1];
		for (int i = 0; i < count; i++) {
			newArr[i] = computers[i];
		}
		newArr[count] = new Computer(*value);
		delete[] computers;
		computers = newArr;
		count++;
		newArr = nullptr;
	}

	void DeleteComputer(int id) {
			int index = -1;
			for (int i = 0; i < count; i++) {
				if (computers[i]->GetId() == id) {
					index = i;
					break;
				}
			}
			if (index != -1) {
				Computer** newArr = new Computer * [count - 1];
				for (int i = 0; i < index; i++) {
					newArr[i] = computers[i];
				}
	
				for (int i = index; i < count; i++) {
					newArr[i] = computers[i + 1];
				}
				delete[] computers;
				computers = newArr;
				count--;
				newArr = nullptr;
			}
		}
	
	friend ostream& operator<<(ostream& out, const ComputerStore& obj) {
		out << obj.storeName << endl;
		out << obj.storeAddress << endl;
		for (int i = 0; i < obj.count; i++) {	
			cout << *obj.computers[i] << endl;
		}
		return out;
	}
	~ComputerStore() {
		for (int i = 0; i < count; i++)
			delete computers[i];
		delete[] computers;
	}
		
};

void main() {
	auto c = new Computer("asus", "zenbook pro dou", "gforce gtx 3060ti", "QLED", 10, 16, 64, 1000);
	ComputerStore store("medovik", "bufet");
	store.AddComputer(c);
	store.AddComputer(new Computer("asus", "zenbook pro", "gforce gtx 1050ti", "QLED", 2.8, 8, 16, 512));
	cout << store << endl;
	store.DeleteComputer(101);
	cout << store << endl;
}