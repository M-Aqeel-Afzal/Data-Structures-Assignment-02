#pragma once
#include <string>
#include<fstream>
#include<sstream>
#include<iostream>
using namespace std;
//#ifndef CITIZENSDB_H
//#define CITIZENSDB_H

struct node {
	int cnic = 0, count_num = 0;
	string name = "", fname = "", address = "", gender = "", nationality = "";
	string number = "", network = "", active_d = "", deactive_d = "", status = "";
	string  charge = "", punishment = "", fine = "";
	node* next;
	node* previous;
};

template <class T>
class DataPipeline {
public:
	node* head;
	node* tail;
	/*	A linkedlist based queue to implement databases
		Implement additional functions as per requirement
	*/


	DataPipeline() {
		head = NULL;
		tail = NULL;
	}

	void enqueue(const T& file1, const T& file2, const T& file3) {

		fstream f1, f2, f3;
		string word;
		int i = 0;
		string s2, s3; int n2;    //CBID file reading and constracting linked list
		f1.open(file1, ios::in);
		f2.open(file2, ios::in);
		f3.open(file3, ios::in);

		while (!f1.eof())
		{
			node* temp = new node;
			f1 >> word;

			stringstream s5(word);
			s5 >> n2;
			temp->cnic = n2;
			f1 >> temp->name;
			f1 >> temp->fname;
			f1 >> temp->gender;
			word = "";
			while (i < 3)
			{
				f1 >> s3;
				temp->address = temp->address + s3;
				temp->address = temp->address + " ";
				++i;
			}
			s3 = "";

			i = 0;
			f1 >> temp->nationality;
			temp->next = NULL;
			temp->previous = NULL;
			tail = head;
			if (head == NULL)
			{
				head = temp;
			}
			else
			{

				while (tail != NULL)
				{

					if (tail->next == NULL)
					{

						temp->previous = tail;
						tail->next = temp;

						break;
					}
					tail = tail->next;
				}
			}


		}
		f1.close();
		i = 1;
		// reading file2
		while (!f2.eof())
		{
			node* temp3 = new node;
			f2 >> word;
			stringstream s5(word);
			s5 >> n2;
			temp3->cnic = n2;
			f2 >> temp3->charge;

			word = "";
			while (i < 4)
			{
				f2 >> word;
				temp3->punishment = temp3->punishment + word;
				temp3->punishment = temp3->punishment + " ";
				++i;
			}
			word = "";

			i = 0;
			f2 >> temp3->fine;
			node* temp6 = new node;
			temp6 = head;
			while (temp6 != NULL)
			{

				if (temp6->cnic == n2)
				{

					temp6->charge = temp3->charge;
					temp6->punishment = temp3->punishment;
					temp6->fine = temp3->fine;
				}
				temp6 = temp6->next;
			}


		}
		f2.close();

		//        reading file3

		while (!f3.eof())
		{


			f3 >> word;
			node* temp4 = new node;
			stringstream s5(word);
			s5 >> n2;
			temp4->cnic = n2;
			f3 >> temp4->number;
			f3 >> temp4->network;
			f3 >> temp4->active_d;
			f3 >> temp4->deactive_d;
			f3 >> temp4->status;
			i = 0;
			node* temp7 = new node;
			node* temp8 = new node;
			temp7 = head;
			temp8 = head;
			while (temp7 != NULL)
			{
				while (temp8 != NULL)
				{
					if (temp8->cnic == n2)
						temp8->count_num++;
					temp8 = temp8->next;
				}
				if (temp7->cnic == n2)
				{

					temp7->number = temp4->number;
					temp7->network = temp4->network;
					temp7->active_d = temp4->active_d;
					temp7->deactive_d = temp4->deactive_d;
					temp7->status = temp4->status;

				}
				temp7 = temp7->next;
			}

		}
		f3.close();
	}
	void dequeue() {
		tail = head;
		while (tial != NULL)
		{
			if (tail->next == NULL)
			{
				tail = NULL;
				delete tail->next;
				break;
			}

			tail = tail->next;
		}
	}
	T front() {
		return head;
	}
	T back() {
		tail = head;
		while (tial != NULL)
		{
			if (tail->next == NULL)
			{
				return tail->next;
			}

			tail = tail->next;
		}

	}

	bool is_empty() {
		if (head == NULL)
			return 1;
		else
			return 0;
	}
};
template <class T>
class AD {
public:
	node* top = NULL;

	AD() {
		top = NULL;
	}

	string push_roll(node* temp) {

		string s1 = "";
		s1 += temp->name;
		s1 = s1 + " ";
		s1 += temp->fname;
		s1 = s1 + " ";
		s1 += temp->gender;
		s1 = s1 + " ";
		s1 += temp->address;
		s1 += temp->nationality;
		s1 = s1 + " ";
		s1 += temp->charge;
		s1 = s1 + " ";
		s1 += temp->punishment;
		s1 += temp->fine;
		s1 = s1 + " ";
		s1 += temp->number;
		s1 = s1 + " ";
		s1 += temp->network;
		s1 = s1 + " ";
		s1 += temp->active_d;
		s1 = s1 + " ";
		s1 += temp->deactive_d;
		s1 = s1 + " ";
		s1 += temp->status;


		return s1;
	}
	string Pop(node* temp) {

		string s1 = "";
		s1 += temp->name;
		s1 = s1 + " ";
		s1 += temp->fname;
		s1 = s1 + " ";
		s1 += temp->gender;
		s1 = s1 + " ";
		s1 += temp->address;
		s1 += temp->nationality;
		s1 = s1 + " ";
		s1 += temp->charge;
		s1 = s1 + " ";
		s1 += temp->punishment;
		s1 += temp->fine;
		s1 = s1 + " ";
		s1 += temp->number;
		s1 = s1 + " ";
		s1 += temp->network;
		s1 = s1 + " ";
		s1 += temp->active_d;
		s1 = s1 + " ";
		s1 += temp->deactive_d;
		s1 = s1 + " ";
		s1 += temp->status;

		return s1;
	}

	bool is_empty() {
		if (top == NULL)
			return true;
		else
			return 0;
	}

	void empty() {
		while (!is_empty()) {
			pop();
		}
	}
};


struct CBID_NODE {
	int CNIC = 0;
	string nam = "", fnam = "", addres = "", gende = "", nationalit = "";
	CBID_NODE* next;
	CBID_NODE* previous;
};
struct CCND_NODE {
	int CNIC = 0, count_nu;
	string numbe = "", numbe1 = "", numbe2 = "", numbe3 = "", networ = "", active_da = "", deactive_da = "", statu = "";
	CCND_NODE* next, * previous;
};
struct CCID_NODE {
	int CNIC = 0;
	string  charg = "", punishmen = "", fin = "";
	CCID_NODE* next;
	CCID_NODE* previous;
};


template <class T>
class Database {
	int count = 0, count1 = 0;
	CBID_NODE* CBID;                      //treated as head
	CBID_NODE* temp1;
	CCID_NODE* CCID;                        //treated as head
	CCID_NODE* temp2;
	CCND_NODE* CCND;                             //treated as head
	CCND_NODE* temp4;
	DataPipeline<string> dp;
	AD<string>   alien;
public:
	template <class T>
	Database(const T& file1, const T& file2, const T& file3)
	{

		dp.enqueue(file1, file2, file3);
		CCND = NULL;
		CCID = NULL;
		temp2 = NULL;
		CBID = NULL;
		temp1 = NULL;
		temp4 = NULL;
		dp.tail = dp.head;
		while (dp.tail != NULL)
		{
			CBID_NODE* temp3 = new CBID_NODE;

			temp3->CNIC = dp.tail->cnic;
			temp3->nam = dp.tail->name;
			temp3->fnam = dp.tail->fname;
			temp3->addres = dp.tail->address;
			temp3->gende = dp.tail->gender;
			temp3->nationalit = dp.tail->nationality;
			temp3->next = NULL;
			temp3->previous = NULL;
			if (CBID == NULL)
			{
				CBID = temp3;
			}
			else
			{
				temp1 = CBID;
				while (temp1 != NULL)
				{

					if (temp1->next == NULL)
					{
						temp1->next = temp3;
						temp3->previous = temp1;
						break;
					}
					temp1 = temp1->next;
				}

			}
			dp.tail = dp.tail->next;
		}

		dp.tail = dp.head;

		while (dp.tail != NULL)
		{
			CCID_NODE* temp5 = new CCID_NODE;
			temp5->CNIC = dp.tail->cnic;
			temp5->charg = dp.tail->charge;
			temp5->punishmen = dp.tail->punishment;
			temp5->fin = dp.tail->fine;

			temp5->next = NULL;
			temp5->previous = NULL;
			if (CCID == NULL)
			{
				CCID = temp5;
				CCID->next = CCID;
				CCID->previous = CCID;
				count++;
			}
			else
			{



				if (dp.tail->charge != "")
				{
					temp5->next = CCID->next;
					CCID->next = temp5;
					temp5->previous = CCID->previous;
					CCID->previous = temp5;
					CCID = temp5;

					count++;
				}

			}
			dp.tail = dp.tail->next;
		}

		dp.tail = dp.head;

		while (dp.tail != NULL)
		{
			CCND_NODE* temp6 = new CCND_NODE;
			CCND_NODE* temp7 = new CCND_NODE;
			temp6->CNIC = dp.tail->cnic;
			temp6->numbe = dp.tail->number;
			temp6->count_nu = dp.tail->count_num;
			temp6->networ = dp.tail->network;
			temp6->active_da = dp.tail->active_d;
			temp6->deactive_da = dp.tail->deactive_d;
			temp6->statu = dp.tail->status;
			temp6->next = NULL;
			temp6->previous = NULL;
			temp7 = CCND;
			if (CCND == NULL)
			{
				CCND = temp6;
				CCND->next = CCND;
				CCND->previous = CCND;
				count1++;
			}
			else
			{

				if (dp.tail->network != "")
				{

					temp6->next = CCND->next;
					CCND->next = temp6;
					temp6->previous = CCND->previous;
					CCND->previous = temp6;
					CCND = temp6;
					count1++;
				}
			}

			dp.tail = dp.tail->next;
		}




	}
	/*Return a string in following format "Name FName Gender Address Nationality Crimes(if any) Charges punishment fine number network activation_date deactivation_date status"
	 Refer to test cases for further clerification*/
	string CBID_Search_by_CNIC(int cnic) {
		CBID_NODE* temp = new CBID_NODE;
		temp = CBID;
		string s1 = "";
		while (temp != NULL)
		{

			if (temp->CNIC == cnic)
			{


				s1 += temp->nam;
				s1 = s1 + " ";
				s1 += temp->fnam;
				s1 = s1 + " ";
				s1 += temp->gende;
				s1 = s1 + " ";
				s1 += temp->addres;
				s1 += temp->nationalit;


			}
			temp = temp->next;

		}
		CCID_NODE* temp3 = new CCID_NODE;
		int n = count;
		temp3 = CCID;
		while (n > 0)
		{
			if (temp3->CNIC == cnic)
			{

				s1 = s1 + " ";
				s1 += temp3->charg;
				s1 = s1 + " ";
				s1 += temp3->punishmen;
				s1 += temp3->fin;

			}
			temp3 = temp3->next;
			n--;
		}


		n = count1;
		temp4 = CCND;
		while (n > 0)
		{

			if (temp4->CNIC == cnic)
			{

				s1 = s1 + " ";
				s1 += temp4->numbe;
				s1 = s1 + " ";
				s1 += temp4->networ;
				s1 = s1 + " ";
				s1 += temp4->active_da;
				s1 = s1 + " ";
				s1 += temp4->deactive_da;
				s1 = s1 + " ";
				s1 += temp4->statu;


			}
			temp4 = temp4->next;
			n--;
		}

		return s1;
	}
	string CCID_Search_by_CNIC(int cnic) {

		CBID_NODE* temp = new CBID_NODE;
		temp = CBID;
		string s1 = "";
		while (temp != NULL)
		{
			if (temp->CNIC == cnic)
			{


				s1 += temp->nam;
				s1 = s1 + " ";
				s1 += temp->fnam;
				s1 = s1 + " ";
				s1 += temp->gende;
				s1 = s1 + " ";
				s1 += temp->addres;
				s1 += temp->nationalit;


			}
			temp = temp->next;

		}
		CCID_NODE* temp3 = new CCID_NODE;
		int n = count;
		temp3 = CCID;
		while (n > 0)
		{
			if (temp3->CNIC == cnic)
			{

				s1 = s1 + " ";
				s1 += temp3->charg;
				s1 = s1 + " ";
				s1 += temp3->punishmen;
				s1 += temp3->fin;

			}
			temp3 = temp3->next;
			n--;
		}


		n = count1;
		temp4 = CCND;
		while (n > 0)
		{

			if (temp4->CNIC == cnic)
			{

				s1 = s1 + " ";
				s1 += temp4->numbe;
				s1 = s1 + " ";
				s1 += temp4->networ;
				s1 = s1 + " ";
				s1 += temp4->active_da;
				s1 = s1 + " ";
				s1 += temp4->deactive_da;
				s1 = s1 + " ";
				s1 += temp4->statu;


			}
			temp4 = temp4->next;
			n--;
		}

		return s1;
	}
	string CCND_Search_by_CNIC(int cnic) {

		CBID_NODE* temp = new CBID_NODE;
		temp = CBID;
		string s1 = "";
		while (temp != NULL)
		{
			if (temp->CNIC == cnic)
			{


				s1 += temp->nam;
				s1 = s1 + " ";
				s1 += temp->fnam;
				s1 = s1 + " ";
				s1 += temp->gende;
				s1 = s1 + " ";
				s1 += temp->addres;
				s1 += temp->nationalit;


			}
			temp = temp->next;

		}
		CCID_NODE* temp3 = new CCID_NODE;
		int n = count;
		temp3 = CCID;
		while (n > 0)
		{
			if (temp3->CNIC == cnic)
			{

				s1 = s1 + " ";
				s1 += temp3->charg;
				s1 = s1 + " ";
				s1 += temp3->punishmen;
				s1 += temp3->fin;

			}
			temp3 = temp3->next;
			n--;
		}


		n = count1;
		temp4 = CCND;
		while (n > 0)
		{

			if (temp4->CNIC == cnic)
			{

				s1 = s1 + " ";
				s1 += temp4->numbe;
				s1 = s1 + " ";
				s1 += temp4->networ;
				s1 = s1 + " ";
				s1 += temp4->active_da;
				s1 = s1 + " ";
				s1 += temp4->deactive_da;
				s1 = s1 + " ";
				s1 += temp4->statu;


			}
			temp4 = temp4->next;
			n--;
		}
		return s1;
	}
	template <class T>
	bool updateCBIDName(T Name, int cnic) {
		CBID_NODE* temp = new CBID_NODE;
		temp = CBID;
		while (temp != NULL)
		{
			if (temp->CNIC == cnic)
			{
				temp->nam = Name;
				return true;
			}
			temp = temp->next;

		}
		return false;
	}
	template <class T>
	bool updateCBIDFName(T Father_Name, int cnic) {

		CBID_NODE* temp = new CBID_NODE;
		temp = CBID;
		while (temp != NULL)
		{
			if (temp->CNIC == cnic)
			{
				temp->fnam = Father_Name;
				return true;
			}
			temp = temp->next;

		}
		return false;
	}
	template <class T>
	bool updateCBIDAddress(T Address, int cnic) {
		CBID_NODE* temp = new CBID_NODE;
		temp = CBID;
		while (temp != NULL)
		{
			if (temp->CNIC == cnic)
			{
				temp->addres = Address;
				return true;
			}
			temp = temp->next;

		}
		return false;
	}
	template <class T>
	bool updateCBIDNationality(T Nationality, int cnic) {
		CBID_NODE* temp = new CBID_NODE;
		temp = CBID;
		while (temp != NULL)
		{
			if (temp->CNIC == cnic)
			{
				temp->nationalit = Nationality;
				return true;
			}
			temp = temp->next;

		}
		return false;
	}
	template <class T>
	bool addCrime(int cnic, T charges, T punishment, T fine) {

		CCID_NODE* temp = new CCID_NODE;
		CCID_NODE* temp1 = new CCID_NODE;
		CBID_NODE* temp2 = new CBID_NODE;
		temp1->CNIC = cnic;
		temp1->charg = charges;
		temp1->punishmen = punishment;
		temp1->fin = fine;
		temp = CCID;
		int n = count;
		bool b1 = 0;
		temp2 = CBID;
		while (temp2 != NULL)
		{
			if (temp2->CNIC == cnic)
				b1 = 1;
			temp2 = temp2->next;
		}
		while (n > 0)
		{
			if (temp == CCID->previous && b1)
			{
				temp1->next = CCID->previous;             //setting next of last to head for making circular
				temp1->previous = temp->next;
				temp->next = temp1;
				count++;
				return true;
			}
			temp = temp->next;
			n--;
		}
		return false;
	}
	template <class T>
	bool updateCrime(int cnic, T charges, T punishment, T fine) {

		CCID_NODE* temp = new CCID_NODE;
		temp = CCID;
		int n = 0;
		while (n < count)
		{

			if (temp->CNIC == cnic)
			{

				temp->charg = charges;
				temp->punishmen = punishment;
				temp->fin = fine;
				return true;
			}
			temp = temp->next;
			n++;
		}
		return false;
	}
	bool deleteCrime(int cnic, T charges, T punishment, T fine) {

		CCID_NODE* temp = new CCID_NODE;
		temp = CCID;
		int n = count;
		while (n > 0)
		{
			if (temp->CNIC == cnic && temp->charg == charges)
			{
				temp->next->next->previous = temp->previous;
				temp->next = temp->next->next;
				count--;
				return true;
			}
			temp = temp->next;
			n--;
		}
		return false;
	}

	int addNumber(int cnic, int number)
	{
		string s2;
		stringstream s1(number);
		s1 >> s2;
		CCND_NODE* temp = new CCND_NODE;
		temp = CCND;
		int n = count1;
		while (n > 0)
		{
			if (temp->CNIC == cnic)
			{
				if (temp->numbe == "")
				{
					temp->numbe = s2;
					temp->count_nu++;
				}
				else if (temp->numbe1 == "")
				{
					temp->numbe1 = s2;
					temp->count_nu++;
				}
				else if (temp->numbe2 == "")
				{
					temp->numbe2 = s2;
					temp->count_nu++;
				}
				else if (temp->numbe3 == "")
				{
					temp->numbe3 = s2;
					temp->count_nu++;
				}
				return temp->count_nu;
			}
			temp = temp->next;
			n--;
		}
		return false;

		/*return number of cell-numbers registered on given cnic after adding this number*/

	}

	int checkRegistred_No(int cnic) {
		CCND_NODE* temp = new CCND_NODE;
		temp = CCND;
		int n = count1, n1 = 0;
		while (n > 0)
		{

			if (temp->CNIC == cnic)
			{

				n1 = temp->count_nu;
				if (temp->statu == "unactive")
					n1 = n1 - 1;
			}
			temp = temp->next;
			n--;
		}
		return n1;
		/*return number of cell-numbers registered on given cnic*/

	}

	bool swap(int cnic, int cnic1, T number, T number1) {
		CCND_NODE* temp = new CCND_NODE;
		temp = CCND;
		int n = count1;
		bool b1 = 0, b2 = 0;
		while (n > 0)
		{

			if (temp->CNIC == cnic)
			{
				temp->numbe = number1;
				b1 = 1;
			}
			if (temp->CNIC == cnic1)
			{
				temp->numbe = number;
				b2 = 1;
			}
			temp = temp->next;
			n--;
		}
		if (b1 & b2)
			return 1;
		else
			return 0;
	}

	string declareAlien(int cnic) {
		string s1 = "";
		dp.tail = dp.head;
		node* temp = new node;
		while (dp.tail != NULL)
		{

			if (dp.tail->cnic == cnic)
			{
				temp->name = dp.tail->name;
				temp->fname = dp.tail->fname;
				temp->address = dp.tail->address;
				temp->gender = dp.tail->gender;
				temp->fine = dp.tail->fine;
				temp->punishment = dp.tail->punishment;
				temp->charge = dp.tail->charge;
				temp->active_d = dp.tail->active_d;
				temp->network = dp.tail->network;
				temp->number = dp.tail->number;
				temp->nationality = "Alien";
				temp->deactive_d = "26/10/2020";
				temp->status = "unactive";
				temp->next = alien.top;
				alien.top = temp;
				s1 = alien.push_roll(temp);
				break;
			}
			dp.tail = dp.tail->next;
		}
		return s1;

		/*For Implementation of this function, Refer to CBID point 'iv', CCID point 'vi' and CCND point 'vii'. Also,
		write test-cases for this function yourself*/

	}
	//template<typename T>
	bool verifyAlienDBUpdate(int cnic) {
		/*Verify that given CNIC is moved from CBID to AD, Also add test-case for this function yourself*/

		node* temp = new node;
		temp = alien.top;
		while (temp != NULL)
		{
			if (temp->cnic == cnic)
			{
				if (temp->nationality == "Alien" && temp->status == "unactive")
					return 1;
				else
					return 0;
			}
			temp = temp->next;
		}

	}

	int printcount() {
		int total = 0;
		/*Print count of cell phone numbers registered on each network. For example: (Telenor= 10, Jazz= 5, Ufone= 8, Zong= 9, Total= 32)
		 Return total*/
		CCND_NODE* temp = new CCND_NODE;
		temp = CCND;
		int n = count1;
		while (n > 1)
		{
			if (temp->networ != "")
			{

				total = total + temp->count_nu;

			}
			temp = temp->next;
			n--;
		}
		//cout << total << endl;
		return total;
	}
	void Display_AD() {
		node* temp = new node;
		temp = alien.top;
		while (temp != NULL)
		{

			cout << alien.Pop(temp) << endl;
			temp = temp->next;
		}
		/*Display data as instructed in point (xiv) of PDF*/
	}

	~Database() {

		/* deallocate and cleanup */
	}
};

//#endif