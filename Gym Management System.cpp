#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;
class Gym;
class excersiceplan;
class trainer {
	string name;
	int id;
public:
	trainer()
	{

	}
	void setname(string name, int ID)
	{
		id = ID;
		this->name = name;
	}
	string getname()
	{
		return name;
	}
	void print() {
	
		cout << "Trainer name : " << name << endl;
	}
};


class Equipment {
	int id;
	string equipmentname[5];
public:
	Equipment()
	{

	}
	Equipment(string equipmentnames)
	{
		for (int i = 0; i < 5; i++) {
			this->equipmentname[i] = equipmentnames;
		}
		}
	void setequipmentnames(string equipmentnames,int ID)
	{
		id = ID;
		for (int i = 0; i < 5; i++) {
			this->equipmentname[i] = equipmentnames;
		}
	}
	string* getequipmentnames()
	{
		return equipmentname;
	}
	void print() {
		cout << "Equipment : " << equipmentname[0] << " (" << 5 << ")" << endl;
	}


};
class excerciseplan {
	int id;
	double duration;
	//customers* cust;
	trainer* trnr;
	Equipment* equip;

public:
	int numberofmembers;
	excerciseplan()
	{
		id = 0;
		duration = 0;
		trnr = nullptr;
		equip = nullptr;
		numberofmembers = 0;
	}
	excerciseplan(int ID, double Duration, trainer& obj, Equipment& obj1)
	{
		id = ID;
		duration = Duration;
		trnr = &obj;
		equip = &obj1;
	}
	void settrainer(trainer& obj) {
		trnr = &obj;
	}
	void setEquipment(Equipment& obj) {
		equip = &obj;
	}
	void setid(int ID)
	{
		this->id = ID;
	}
	int getid()
	{
		return id;
	}
	void setduration(int duration)
	{
		this->duration = duration;
	}
	double getduration()
	{
		return duration;
	}
	void print() {
		cout << "             Excersice plan                             " << endl;
		cout << "Plan no.: " << id << endl;
		cout << "Duration :" << duration << endl;
		trnr->print();
		equip->print();

	}
	~excerciseplan()
	{
		trnr = nullptr;
		equip = nullptr;
	}

};
class Date {
	int day;
	int month;
	int year;
public:
	Date() {
		month = 0;
		day = 0;
		year = 0;
	}
	Date(int d, int m, int y) {
		month = m;
		day = d;
		year = y;
	}
	void setDate(int d, int m, int y) {
		month = m;
		day = d;
		year = y;
	}
	void getDate(int& d, int& m, int& y) {
		if (m > 0 && m < 12) {
			m = month;
		}
		else {
			m = 0;
		}
		if (d > 0 && d < 32) {
			d = day;
		}
		else {
			d = 0;
		}
		y = year;
	}
	void printDate() {

		cout << day << "-" << month << "-" << year << endl;
	}

};
class customers {
	string name;
	int id;
	string address;
	string number;
	string email;
	
	int numofplans;// limit for a customer to take number of plan
	excerciseplan** excerciseplans;
	Date** date;
	Gym** gym;
	
public:


	customers()
	{
		this->name = "";
		this->id = 0;
		this->address = "";
		this->number = "";
		this->email = "";
		numofplans = 5;
		excerciseplans = new excerciseplan*[numofplans];
		date = new Date* [numofplans];
		//sub_id = new int[5];
	
		for (int i = 0; i < numofplans; i++) {

			excerciseplans[i] = nullptr;
			date[i] = nullptr;
		}
	}
	excerciseplan** getexcerciseplans() {
		return excerciseplans;
	}
	customers(string name, int id, string address, string number,excerciseplan &obj,Date &date1, string email)
	{
		this->name = name;
		this->id = id;
		this->address = address;
		this->number = number;
		this->email = email;
		/*for (int i = 0; i < numofplans; i++) {
			if (excerciseplans[i] != nullptr) {*/
				excerciseplans[obj.getid()-1] = &obj;
				date[obj.getid() - 1] = &date1;
				//break;
			//}
		
			
		//}
	}
	
	void removeplan(int k)
	{
		excerciseplans[k] = nullptr;
	}
	void setplan(excerciseplan& obj) {
	
		
		excerciseplans[obj.getid()] = &obj;
		
	

	}
	void setdate(Date& obj,int a) {
		date[a] = &obj;
	}

	void extend(int* sub_id, int size)
	{
		int* newsub_id = new int[size * 2];
		for (int i = 0; i < size; i++)
		{
			newsub_id[i] = sub_id[i];
		}
		delete[] sub_id;
		sub_id = nullptr;
		sub_id = newsub_id;
		size *= 2;
	}
	void setname(string name)
	{
		this->name = name;
	}
	string getname()
	{
		return name;
	}
	void setid(int ID)
	{
		this->id = ID;
	}
	int getid()
	{
		return id;
	}
	void setaddress(string address)
	{
		this->address = address;
	}
	string getaddress()
	{
		return address;
	}
	void setnumber(string number)
	{
		this->number = number;
	}
	string getnumber()
	{
		return number;
	}
	void setemail(string email)
	{
		this->email = email;
	}
	string getemail()
	{
		return email;
	}
	void print() {
		cout << "Customer Name : " << name << endl;
		cout << "Customer id : " << id<<endl;
		cout << "Address : " << address << endl;
		cout << "Number : " << number << endl;
		cout << "Email : " << email << endl;
	
	}
	void print_excerplanscust() {          /////Print excercise plans of each customer so that we can easily edit it
		cout << "Customer Name : " << name << endl;
		for (int i = 0; i < numofplans; i++) {
			if (excerciseplans[i] != nullptr) {
				excerciseplans[i]->print();
				//date[i]->printDate();
			}
		}
	}
	void print_subscription() {
		static int sub_id = 0;
			for (int i = 0; i < numofplans; i++) {
				if (excerciseplans[i] != nullptr) {
				//	cout << subscriptions[i]<<'\t';
					sub_id++;
					cout << sub_id << '\t';
					cout << name << '\t' << excerciseplans[i]->getid() << '\t';
					date[i]->printDate();
				
				}
				
			}
	
	}
	~customers()
	{
		for (int i = 0; i < numofplans; i++) {

			excerciseplans[i] = nullptr;
			date[i] = nullptr;
		}
	}


};

//class subscription {
//	int id;
//	excerciseplan* plans;
//	customers* customer;
//	Date* date;
//public:
//	subscription(int ID,excerciseplan &obj,customers &obj1, Date &obj2) {
//		id = ID;
//		plans = &obj;
//		customer = &obj1;
//		date = &obj2;
//	
//	}
//
//
//};

class Gym {
public:
	trainer** name;
	Equipment** equipmentnames;
	customers** cust;
	excerciseplan* plan;// composed but in dynamic array
	int* equipmentids;
	int* trainerids;
	int* customerids;
	
public:
	
	Gym()
	{
		 equipmentids=new int[3];
		 trainerids=new int[3];
		 customerids = new int[5];
	
		this->name = new trainer*[3];
		for (int i = 0; i < 3; i++) {
			this->name[i] = nullptr;
		}
		this->equipmentnames = new Equipment * [3];
		for (int i = 0; i < 3; i++) {
			this->equipmentnames[i] = nullptr;
		}
		this->plan = nullptr;

	}
	int* getequipmentid() {
	
		return equipmentids;
	}
	int* getcustomerid() {

		return customerids;
	}
	int* gettrainerid() {

		return trainerids;
	}
	Gym(trainer *name, Equipment* equipmentnames, customers* cust,excerciseplan* plan,int*x,int*y,int *z)
	{

		equipmentids = x;
		trainerids = y;
		customerids = z;
		int p = 0;//helping variable
		int k = 0;// helping variable
		this->name = new trainer*[3];
		for (int i = 0; i < 5; i++) {
			if (trainerids[k] == i) {
				this->name[p] = &name[i];
				k++;
				p++;
			}
		}
		k = 0;
		p = 0;
		this->equipmentnames = new Equipment * [3];
		for (int i = 0; i < 5; i++) {
			if (equipmentids[k] == i) {
		

				this->equipmentnames[p] = &equipmentnames[i];
				k++;
				p++;
			}
		}
		k = 0;
		p = 0;
		this->plan = plan;
	
		this-> cust = new customers*[5];
		for (int i = 0; i < 7; i++) {
			if (customerids[k] == i) {
			

				this->cust[p] = &cust[i];
				k++;
				p++;
			}
		}

	
	}

	~Gym()
	{
		for (int i = 0; i < 3; i++)
		 name[i]=nullptr;
		name = nullptr;
		for (int i = 0; i < 5; i++)
			 cust[i]=nullptr;
		cust = nullptr;
		for (int i = 0; i < 5; i++)
			 equipmentnames[i]=nullptr;
		equipmentnames = nullptr;
		for (int i = 0; i < 5; i++)
			delete[] plan;
	
	}

};
void choicefunc(Gym* gym) {
	int choice1 = 0;
	int choice2 = 0;
	int choice = 0;
	int id = 0;
	for (int h = 0; choice2 != -1; h++) {
		cout << "Welcome to GYm Managment" << endl;
		cout << "-> 1 Trainers" << endl;
		cout << "-> 2 Excercise plans" << endl;
		cout << "-> 3 Equipments " << endl;
		cout << "-> 4 Customers " << endl;
		cout << "-> 5 Subscriptions" << endl;
		cout << "-> 6 edit customers information" << endl;
	
		while (true)
		{
			cout << "Enter your choice what you want to see or do(1 to 6)" << endl;
			cin >> choice1;
			if (choice1 >= 0 && choice1 <= 6)
				break;
		}
		int j = 0;
		switch (choice1) {
		case 1:
			for (int i = 0; i < 3; i++) {
				gym->name[i]->print();
			}
			break;
		case 2:
			for (int i = 0; i < 5; i++) {
				gym->plan[i].print();
			}
			break;

		case 3:
			for (int i = 0; i < 3; i++) {
				gym->equipmentnames[i]->print();
			}
			break;
		case 4:
			for (int i = 0; i < 5; i++) {
				gym->cust[i]->print();
			}
			break;
		case 5:
			cout << "Sub id" << '\t' << "Name" << '\t' << "Plan id" << '\t' << "Date/time " << '\t' << endl;
			for (int i = 0; i < 5; i++) {
				gym->cust[i]->print_subscription();
			}
			break;
		case 6:
			while (true)
			{
				cout << "\n You want to change your exercise plan choose 1 otherwise choose 0 " << endl;
				cin >> choice;
				if (choice >= 0 && choice <= 4)
					break;
			}

			if (choice)
			{
				cout << "Enter your id: ";
				cout << "  (0 to 4)" << endl;


				cin >> id;
				gym->cust[id]->print_excerplanscust();
				cout << "Tell Your previous plan no: ";
				cin >> j;
				gym->cust[id]->removeplan(j); //nullptr
				cout << "Tell Your  new plan no: \n";

				cin >> j;
				if (gym->plan[j].numberofmembers >= 5) {
					/*check[k] = choice;
					k++;*/
					while (gym->plan[j].numberofmembers >= 5) {
						cout << "Excersice plan NOt available due to full capacity " << endl;
						cin >> j;
					}
					/*for (int j = 0; j < k; j++) {
						obj.plan[check[j]].print();
					}
				}*/



				}
			}
			gym->cust[id]->setplan(gym->plan[j]);
			cout << "Now your plan is: ";
			gym->cust[id]->print_excerplanscust();

			break;
		default:
			cout << "You need to enter from 1 to 5 to see information" << endl;

		}
		
		cout << "Enter -1 to Exit program otherwise enter 0" << endl;
		cin >> choice2;
	}

}
int main() {
	ifstream in;
	string name;
	string email;
	string number;
	string address;
	ifstream tr;
	ifstream eq;
	int id;

	int equipmentids[3] = {0,1,2};
	int trainerids[3] = { 0,1,2 };
	int customerids[5] = { 0,1,2,3,4 };



	in.open("Customers.txt", ios::in);
	trainer* trainers = new trainer[5];
	tr.open("Trainers.txt", ios::in);

	for (int i = 0; i < 5; i++)
	{
		getline(tr, name);
		trainers[i].setname(name, i + 1);
	}
	eq.open("Equipments.txt", ios::in);
	Equipment* equipments = new Equipment[5];
	
	for (int i = 0; i < 5; i++) {
		getline(eq, name);
		equipments[i].setequipmentnames(name, i + 1);
	}


	customers* cust = new customers[7];
	excerciseplan* plan = new excerciseplan[5];
	Date* date = new Date[5];
	Gym *gym=new Gym (trainers, equipments, cust, plan, equipmentids, trainerids, customerids);
	
	
	gym->plan[0].setid(0);
	gym->plan[0].setduration(60);
	gym->plan[0].settrainer(trainers[0]);
	gym->plan[0].setEquipment(equipments[0]);

	gym->plan[1].setid(1);
	gym->plan[1].setduration(90);
	gym->plan[1].settrainer(trainers[1]);
	gym->plan[1].setEquipment(equipments[1]);
	gym->plan[2].setid(2);
	gym->plan[2].setduration(60);
	gym->plan[2].settrainer(trainers[2]);
	gym->plan[2].setEquipment(equipments[2]);
	gym->plan[3].setid(3);
	gym->plan[3].setduration(90);
	gym->plan[3].settrainer(trainers[0]);
	gym->plan[3].setEquipment(equipments[2]);
	gym->plan[4].setid(4);
	gym->plan[4].setduration(60);
	gym->plan[4].settrainer(trainers[2]);
	gym->plan[4].setEquipment(equipments[2]);
	
	
	

	int idc = 0;
	for (int i = 0; i < 7; i++) {
		in >> idc;
		cust[idc].setid(idc);
		in >> address;
		cust[idc].setaddress(address);
		in >> email;
		cust[idc].setemail(email);
		in >> name;
		cust[idc].setname(name);
		in >> number;
		cust[idc].setnumber(number);

	}


	int k = 0;
	int d = 0;
	int m = 0;
	int y = 0;
	int choice = 0;
	int planid = 0;
	int customerid = 0;
	int subscriptions = 0;
	ifstream fin;
	fin.open("Subscription.txt", ios::in);
	ifstream din;
	din.open("Date_time.txt", ios::in);

	for (int i = 0; i < 5; i++) {
		din >> d;
		din >> m;
		din >> y;
		date[i].setDate(d, m, y);
	}
	for (int i = 0; i < 10; i++) {


		
		fin >> subscriptions;
		fin >> customerid;
		fin >> planid;
	
		gym->cust[customerid]->setplan(gym->plan[planid]);
		gym->cust[customerid]->setdate(date[planid],planid);

		//cust[i].print();
		gym->plan[planid].numberofmembers++;
		//obj.sub_id[i] = i;
	}
	int equipmentids2[3] = {0,3,4};
	int trainerids2[3] = {1,3,4};
	int customerids2[5] = {0,2,3,5,6};

	excerciseplan* plan2 = new excerciseplan[5];
	Gym *gym2=new Gym(trainers, equipments, cust, plan2, equipmentids2, trainerids2, customerids2);
	//equipmentids = new int[3];
	//trainerids = new int[3];
	//customerids = new int[5];

	gym2->plan[0].setid(0);
	gym2->plan[0].setduration(70);
	gym2->plan[0].settrainer(trainers[3]);
	gym2->plan[0].setEquipment(equipments[4]);

	gym2->plan[1].setid(1);
	gym2->plan[1].setduration(100);
	gym2->plan[1].settrainer(trainers[4]);
	gym2->plan[1].setEquipment(equipments[1]);
	gym2->plan[2].setid(2);
	gym2->plan[2].setduration(40);
	gym2->plan[2].settrainer(trainers[0]);
	gym2->plan[2].setEquipment(equipments[3]);
	gym2->plan[3].setid(3);
	gym2->plan[3].setduration(80);
	gym2->plan[3].settrainer(trainers[2]);
	gym2->plan[3].setEquipment(equipments[0]);
	gym2->plan[4].setid(4);
	gym2->plan[4].setduration(90);
	gym2->plan[4].settrainer(trainers[1]);
	gym2->plan[4].setEquipment(equipments[2]);
	for (int i = 0; i < 10; i++) {



		fin >> subscriptions;
		fin >> customerid;
		fin >> planid;

		gym2->cust[customerid]->setplan(gym2->plan[planid]);
		gym2->cust[customerid]->setdate(date[planid], planid);

		//cust[i].print();
		gym2->plan[planid].numberofmembers++;
		//obj.sub_id[i] = i;
	}


	cout << "We have Managment ment system of two Gyms" << endl;
		cout<<"enter 1 to handle 1st Gym and 2 to handle second Gym" << endl;
	do {
		cin >> choice;
		if (choice != 1 && choice != 2) {
			cout << "please enter either 1 or 2 " << endl;
		}
	} while (choice != 1&& choice != 2);
	if (choice == 1) {
		choicefunc(gym);
	}
	else if (choice == 2) {
		choicefunc(gym2);
	}



}

	




