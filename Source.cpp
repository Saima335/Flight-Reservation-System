/*////////////////////////////////////////
||	Group Members :					    ||
||		Saima Kausar(FA19-BCS-070)	    ||
||		Nimra Zafar(FA19-BCS-062)	    ||
////////////////////////////////////////*/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Date {
	int year;
	int month;
	int day;
public:
	//default constructor
	Date() {
		this->year = 2000;
		this->month = 1;
		this->day = 1;
	}
	//argument constructor
	Date(int year, int month, int day){
		if (year >= 0) {
			this->year = year;
		}
		if (month >= 1 && month <= 12) {
			this->month = month;
		}
		if (month % 2 != 0 || month == 8) {
			if (day >= 0 && day <= 31) {
				this->day = day;
			}
		}
		else if (month == 2) {
			if (isLeapYear()){
				if (day >= 0 && day <= 29) {
					this->day = day;
				}
			}
			else {
				if (day >= 0 && day <= 28) {
					this->day = day;
				}
			}
		}
		else {
			if (day >= 0 && day <= 30) {
				this->day = day;
			}
		}
	}
	//is leap year function
	bool isLeapYear() {
		if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
			return true;
		}
		else {
			return false;
		}
	}
	//setting day
	/*void setDay(int d){
		if (day >= 0 && day <= 31){
			day = d;
		}
	}*/
	//Getters
	int getDay() {
		return day;
	}
	int getMonth() {
		return month;
	}
	int getYear() {
		return year;
	}
	//At constructor call done (done once)
	Date(string date) { 
		date += '/';
		string d;
		int arr[3] = { 0,0,0 };
		for (int i = 0, k = 0; i < date.length(); i++)
		{
			if (date[i] != '/')
				d += date[i];
			else
			{
				arr[k] = stoi(d);
				k++;
				d = "";
			}
		}
		day = arr[0];
		month = arr[1];
		year = arr[2];
	}
	//Can be done whenever we want
	//put date string to class data members
	void setDate(string date) {
		date += '/';
		string d;
		int arr[3] = { 0,0,0 };
		for (int i = 0, k = 0; i < date.length(); i++)
		{
			if (date[i] != '/')
				d += date[i];
			else
			{
				arr[k] = stoi(d);
				k++;
				d = "";
			}
		}
		day = arr[0];
		month = arr[1];
		year = arr[2];
	}
	//getting date in string
	string getDate() {
		return to_string(day) + "/" + to_string(month) + "/" + to_string(year);
	}
	
	/*
	//Operator overloading
	//checking if date is greater than another date
	bool operator>(const Date& d) {
		if (year > d.year)
			return true;
		else if (year == d.year){
			if (month > d.month)
				return true;
			else if (month == d.month){
				if (day > d.day)
					return true;
			}
		}
		return false;
	}
	//checking if date is less than another date
	bool operator<(const Date& d) {
		if (year < d.year)
			return true;
		else if (year == d.year){
			if (month < d.month)
				return true;
			else if (month == d.month){
				if (day < d.day)
					return true;
			}
		}
		return false;
	}*/

	//const use to not change 
	//& use to pass by reference so deep copy
	//checking if date is equal to another date
	bool operator==(const Date& d) {
		//return ((!((*this) > d)) && (!((*this) < d)));
		//this act as pointer
		if (this->day == d.day && this->year == d.year && this->month == d.month) {
			return true;
		}
		else {
			return false;
		}
	}

	//Making two dates equal
	//operator use so if make object like date d1, date d2 and do d1=d2 then this function call
	Date& operator=(const Date& d)
	{
		year = d.year;
		month = d.month;
		day = d.day;
		return *this;
	}

};

class Time {
public:
	int hours;
	int minutes;
	Time() {
		hours = 0;
		minutes = 0;
	}
	Time(int h, int m) {
		if (h >= 0 && h<=24)
			hours = h;
		if (m >= 0 && m<=60)
			minutes = m;
	}
	int getHours() {
		return hours;
	}
	int getMinutes() {
		return minutes;
	}
	/*void setTime(int h, int m) {
		if (h >= 0 && h <= 24)
			hours = h;
		if (m >= 0 && m <= 60)
			minutes = m;
	}*/
	Time(string time) {
		time += ':';
		string d;
		int arr[2] = { 0,0 };
		for (int i = 0, k = 0; i < time.length(); i++)
		{
			if (time[i] != ':')
				d += time[i];
			else
			{
				arr[k] = stoi(d);
				k++;
				d = "";
			}
		}
		hours = arr[0];
		minutes = arr[1];
	}
	void setTime(string time) {
		time += ':';
		string d;
		int arr[2] = { 0,0 };
		for (int i = 0, k = 0; i < time.length(); i++)
		{
			if (time[i] != ':')
				d += time[i];
			else
			{
				arr[k] = stoi(d);
				k++;
				d = "";
			}
		}
		hours = arr[0];
		minutes = arr[1];
	}
	string getTime() {
		return to_string(hours) + ":" + to_string(minutes);
	}
	/*bool operator<(const Time& t){
		if (hours < t.hours)
			return true;
		else if (hours == t.hours){
			if (minutes < t.minutes)
				return true;
		}
		return false;
	}
	bool operator>(const Time& t){
		if (hours > t.hours)
			return true;
		else if (hours == t.hours){
			if (minutes > t.minutes)
				return true;
		}
		return false;
	}*/
	bool operator==(const Time& t){
		//return ((!((*this) > t)) && (!((*this) < t)));
		if (this->hours == t.hours && this->minutes == t.minutes) {
			return true;
		}
		else {
			return false;
		}
	}
	Time& operator=(const Time& t){
		hours = t.hours;
		minutes = t.minutes;
		return *this;
	}
	Time& operator-(const Time& t){
		hours = hours - t.hours;
		minutes = minutes - t.minutes;
		return *this;
	}
};

//WEIGHT CLASS
class Weight
{
public:
	//********************************************DATA MEMBERS********************************************//
	string airline;		//DESTINATION
	Date date;			//DATE OF FLIGHT
	Time time1;			//TIME OF TAKE OFF
	Time time2;			//TIME OF ARRIVAL
	int cost;			//COST OF FLIGHT

	int time_diff = time2.getHours() - time1.getHours();
	//****************************************************************************************************//

	//CONSTRUCTOR//
	Weight()
	{
		airline = "";
		date.setDate("0/0/0");
		time1.setTime("0:0");
		time2.setTime("0:0");
		cost = 0;
		time_diff = 0;
	}
	//***********//

	void setTimeDiff(int t)
	{
		time_diff = t;
	}
	int getTimeDiff()
	{
		return time_diff;
	}

	//**********OPERATORS OVERLOADED**********//
	bool operator== (const Weight& w)
	{
		return ((airline == w.airline) && (date == w.date) && (time1 == w.time1) && (time2 == w.time2) && (cost == w.cost) && (time_diff == w.time_diff));
	}
	bool operator!= (const Weight& w)
	{
		return (!((*this) == w));
	}
	Weight& operator= (const Weight& w)
	{
		if ((*this) != w)
		{
			airline = w.airline;
			date = w.date;
			time1 = w.time1;
			time2 = w.time2;
			cost = w.cost;
			time_diff = w.time_diff;
		}

		return *this;
	}
	bool operator< (const Weight& w)
	{
		return (cost < w.cost);
	}
	bool operator> (const Weight& w)
	{
		return (cost > w.cost);
	}
	bool operator<= (const Weight& w)
	{
		return (cost <= w.cost);
	}
	bool operator>= (const Weight& w)
	{
		return (cost >= w.cost);
	}
	//****************************************//

	//*****************OUTPUT*****************//
	void display()
	{
		cout << airline << " "
			<< cost << " "
			<< date.getDate() << " "
			<< time1.getTime() << " "
			<< time2.getTime() << " " << endl;
	}
	string toString(Weight& w) {
		return w.airline + "  " + w.date.getDate() + "  " + w.time1.getTime() + "    " + w.time2.getTime();
	}
	//****************************************//
};
//when write cout<<weight all data members will be printed
/*ostream& operator << (ostream& out, Weight& w)
{
	out << w.airline << " "
		<< w.cost << " "
		<< w.date.getDate() << " "
		<< w.time1.getTime() << " "
		<< w.time2.getTime() << " ";
	return out;
}*/

struct NodeL {
	Weight data;
	NodeL* next=NULL;
	NodeL operator=(NodeL*& rhs) {
		this->data = rhs->data;
		this->next = rhs->next;
		return *this;
	}
};

class List {
public:
	NodeL* head;
	NodeL* tail;
	int size;
	List() {
		head = NULL;
		tail = NULL;
		size = 0;
	}
	List(NodeL* n){
		head = n;
		tail = n;
		head->next = NULL;
		tail->next = NULL;
		size = 1;
	}
	bool operator!=(const List& rhs) {
		NodeL* current1 = this->head;
		NodeL* current2 = rhs.head;
		while (current1 != NULL && current2!= NULL) {
			if (current1->data == current2->data) {
				return false;
			}
		}
		return true;
	}
	Weight& getDataAt(int index)
	{
		NodeL* current = head;
		if (!isEmpty())
		{
			for (int i = 0; i < index; i++)
			{
				if (current->next != NULL)
				{
					current = current->next;
				}

			}
			return current->data;
		}
	}
	NodeL*& getNodeAt(int index)
	{
		NodeL* current = head;
		if (!isEmpty())
		{
			for (int i = 0; i < index; i++)
			{
				current = current->next;
			}
			return current;
		}
	}
	NodeL*& getNode(Weight data)
	{
		NodeL* current = head;
		if (!isEmpty())
		{
			for (int i = 0; i < size; i++)
			{
				if (current->data == data)
					return current;
				current = current->next;
			}
			return current;
		}
	}
	void insert(const Weight& newDataItem)
	{
		NodeL* temp = new NodeL;
		temp->data = newDataItem;
		temp->next = NULL;
		if (head == NULL)
		{
			head = temp;
			tail = head;
			size = 1;
		}
		else
		{
			tail->next = temp;
			tail = tail->next;
			size += 1;
		}
	}
	void insertAt(const Weight& newDataItem, int index)
	{
		if (index >= 0 && index <= size + 1)
		{
			NodeL* temp = new NodeL;
			temp->data = newDataItem;
			if (index == 0)
			{
				temp->next = NULL;
				head = temp;

			}
			else if (index == size)
			{
				tail->next = temp;
				tail = temp;
				temp->next = NULL;
			}
			else if (index < size)
			{

				NodeL* current = head;
				for (int i = 0; i < index - 1; i++)
				{
					current = current->next;
				}

				temp->next = current->next;
				current->next = temp;

			}
			size += 1;
		}
		else
		{
			cout << "Out of Range" << endl;
		}
	}
	void remove(NodeL* current)
	{
		if (!isEmpty())
		{
			NodeL* temp = head;
			while (temp->next != current && temp->next != NULL)
			{
				temp = temp->next;
			}
			NodeL* toDelete = temp->next;


			//IF ONLY 1 ELEMENT LEFT
			if (current == tail && current == head)
			{
				delete current;
				tail = NULL;
				head = tail;
				size = 0;
				return;
			}
			//IF CURRENT IS AT TAIL
			else if (current == tail)
			{
				toDelete = temp->next;
				tail = temp;
				tail->next = NULL;
			}
			//IF CURRENT IS AT HEAD
			else if (current == head)
			{
				toDelete = head;
				current = toDelete->next;
				head = current;
			}
			//IF CURRENT IS IN THE MIDDLE
			else
			{
				toDelete = temp->next;
				temp->next = toDelete->next;
				current = toDelete->next;
			}
			delete toDelete;
			size -= 1;
		}
		else
			cout << "Empty" << endl;

	}
	void removeAt(int index)
	{
		NodeL* current = NULL;
		if (index >= 0 && index < size)
		{
			current = head;
			for (int i = 0; i < index; i++)
			{
				current = current->next;
			}
			remove(current);
			return;
		}
		cout << "Out of Range" << endl;

	}
	/*void clear()
	{
		while (head != NULL)
		{
			remove();
		}
	}*/
	bool isEmpty()
	{
		if (head == NULL)
		{
			return true;
		}
		return false;
	}
	void display()
	{

		if (size != 0)
		{
			NodeL* current = head;

			while (current != NULL)
			{
				cout << "| ";
				current->data.display();
				cout<< " |" << endl;
				current = current->next;
			}
		}
		else
			cout << "Empty";

	}
	void sort()
	{
		if (!isEmpty())
		{
			Weight* ptr = new Weight[size];
			NodeL* current = head;
			for (int n = 0; n < size; n++)
			{
				ptr[n] = current->data;
				current = current->next;
			}
			Weight tmp;
			int i, j;
			for (i = 1; i < size; i++)
			{
				tmp = ptr[i];
				for (j = i; j > 0 && tmp < ptr[j - 1]; j--)
				{
					ptr[j] = ptr[j - 1];
				}
				ptr[j] = tmp;
			}
			current = head;
			for (int n = 0; n < size; n++)
			{
				current->data=ptr[n] ;
				current = current->next;
			}
			//delete ptr;
			return;
		}
		cout << "Empty" << endl;
	}
	bool duplicate()
	{
		NodeL* temp = head;
		NodeL* current = head;
		for (int i = 0; temp != NULL; i++)
		{
			current = head;
			for (int j = 0; current != NULL; j++)
			{
				if (temp != current && temp->data == current->data)
				{
					return true;
				}
				current = current->next;
			}
			temp = temp->next;
		}
		return false;

	}
};

//********************SORTING WEIGHTS********************// 
void sort_wrt_cost(List& w)
{
	Weight temp;
	for (int i = 0; i < w.size; i++)
	{
		for (int j = 0; j < w.size - 1; j++)
		{
			if (w.getDataAt(j).cost >= w.getDataAt(j + 1).cost)
			{
				swap(w.getDataAt(j), w.getDataAt(j + 1));
			}
		}
	}
}
void sort_wrt_days(List& w)
{
	Weight temp;
	for (int i = 0; i < w.size; i++)
	{
		for (int j = 0; j < w.size - 1; j++)
		{
			if (w.getDataAt(j).date.getDay() > w.getDataAt(j + 1).date.getDay())
			{
				swap(w.getDataAt(j), w.getDataAt(j + 1));
			}
		}
	}
}
void sort_wrt_time(List& w)
{
	Weight temp;
	for (int i = 0; i < w.size; i++)
	{
		int h1;
		int h2;
		for (int j = 0; j < w.size - 1; j++)
		{
			h1 = (w.getDataAt(j).time2.getHours() - w.getDataAt(j).time1.getHours());
			if (h1 < 0)
				h1 += 24;
			h2 = (w.getDataAt(j + 1).time2.getHours() - w.getDataAt(j + 1).time1.getHours());
			if (h2 < 0)
				h2 += 24;
			if (h1 > h2)
			{
				swap(w.getDataAt(j), w.getDataAt(j + 1));
			}
		}
	}
}

//*******************************************************//

//Node struct
struct Node {
	string data;             //WILL STORE CITY
	List weight;			//WILL STORE A LIST OF WEIGHTS SINCE THERE ARE MULTIPLE DIRECT EDGES B/W TWO VERTICES
	Node* next=NULL;
	Node& operator =(Node*& rhs) {
		this->data = rhs->data;
		this->next = rhs->next;
		this->weight = rhs->weight;
		return *this;
	}
	bool operator !=(Node*& rhs) {
		if (this->data != rhs->data && *this->next != rhs->next && this->weight != rhs->weight) {
			return true;
		}
		return false;
	}
};

//QUEUE CLASS
class Queue
{
	Node* front;
	Node* rear;
	int size;
public:
	Queue()
	{
		front = NULL;
		rear = front;
		size = 0;
	}
	/*~Queue()
	{
		clear();
	}*/
	void enqueue(string newDataItem)
	{
		if (isEmpty())
		{
			front = new Node;
			front->data = newDataItem;
			front ->next= NULL;
			
			rear = front;
			rear->next = NULL;
		}
		else
		{
			Node* newNode = new Node;
			newNode->next = NULL;
			newNode->data = newDataItem;
			rear->next = newNode;
			rear = newNode;
			rear->next = NULL;
		}
		size++;
	}
	void enqueue(string newDataItem, Weight weight)
	{
		if (isEmpty())
		{
			front ->next=NULL;
			front->data = newDataItem;
			rear = front;
			rear->next = NULL;
		}
		else
		{
			Node* newNode = new Node;
			newNode->next = NULL;
			newNode->data = newDataItem;
			rear->next = newNode;
			rear = newNode;
			rear->next = NULL;
		}
		rear->weight.insert(weight);
		size++;
	}
	string dequeue()
	{
		Node* current = NULL;
		if (!isEmpty())
		{
			string temp = front->data;
			current = front;
			front = front->next;
			delete current;
			size--;
			return temp;
		}
		cout << "Empty" << endl;
		//return -1;
	}
	void clear()
	{
		while (!isEmpty())
		{
			dequeue();
		}
	}
	bool isEmpty()
	{
		if (front == NULL)
		{
			return true;
		}
		return false;
	}
	void display()
	{
		Node* current = front;
		while (current != NULL)
		{
			cout << current->data << " ";
			current->weight.display();
			current = current->next;
		}
		cout << endl;
	}
	int getLength()
	{
		return size;
	}
	bool search(string data)
	{
		Node* current = front;
		while (current != NULL)
		{
			if (current->data == data)
				return true;
			current = current->next;
		}
		return false;
	}
	//min weight get and remove from queue
	Node * returnPriority()
	{
		if (!isEmpty())
		{
			Node* temp1 = NULL;
			temp1 = front;

			Node* toReturn = NULL;

			Weight min = temp1->weight.getDataAt(0);
			string data = temp1->data;

			int index = -1;
			for (int i = 0; i < size; i++)
			{
				if (temp1->weight.getDataAt(i) <= min)
				{
					min = temp1->weight.getDataAt(i);
					data = temp1->data;
					index = i;
				}
				temp1 = temp1->next;
			}
			toReturn = new Node;
			toReturn->data = data;
			toReturn->weight.insert(min);
			removeAt(index);
			return toReturn;
		}

	}
	void remove(Node* current)
	{
		if (!isEmpty())
		{
			Node* temp = front;
			while (temp->next != current && temp->next != NULL)
			{
				temp = temp->next;
			}
			Node* toDelete = temp->next;


			//IF ONLY 1 ELEMENT LEFT
			if (current == rear && current == front)
			{
				delete current;
				rear = NULL;
				front = rear;
				size = 0;
				return;
			}
			//IF CURRENT IS AT TAIL
			else if (current == rear)
			{
				toDelete = temp->next;
				rear = temp;
				rear->next = NULL;
				current = front;
			}
			//IF CURRENT IS AT HEAD
			else if (current == front)
			{
				toDelete = front;
				current = toDelete->next;
				front = current;
			}
			//IF CURRENT IS IN THE MIDDLE
			else
			{
				toDelete = temp->next;
				temp->next = toDelete->next;
				current = toDelete->next;
			}
			delete toDelete;
			size -= 1;
		}
		else
			cout << "Empty" << endl;
	}
	void removeAt(int index)
	{
		if (index >= 0 && index < size)
		{
			Node* current = front;
			for (int i = 0; i < index; i++)
			{
				current = current->next;
			}
			remove(current);
			return;
		}
		cout << "Out of Range" << endl;

	}


};

//STACK CLASS
class Stack
{
	Node* top;
	int size;
public:
	Stack()
	{
		top = NULL;
		size = 0;
	}
	/*~Stack()
	{
		clear();
	}*/
	//insert at first
	//top treated as last as last element inserted is at first
	void push(string newDataItem)
	{
		if (isEmpty())
		{
			top ->next=NULL;
			top->data = newDataItem;
		}
		else
		{
			Node* newNode = new Node;
			newNode->next = NULL;
			newNode->data = newDataItem;
			newNode->next = top;
			top = newNode;
		}
		size++;
	}
	//delete at start
	string pop()
	{
		if (!isEmpty())
		{
			string temp = top->data;
			Node* current = top;
			top = top->next;
			delete current;
			size--;
			return temp;
		}
		cout << "Empty" << endl;
		//return -1;
	}
	string getPop()
	{
		if (top != NULL)
			return top->data;
	}
	void clear()
	{
		while (!isEmpty())
		{
			pop();
		}
	}
	bool isEmpty()
	{
		if (top == NULL)
		{
			return true;
		}
		return false;
	}
	void display()
	{
		Node* current = top;
		while (current != NULL)
		{
			cout << current->data << " ";
			current = current->next;
		}
		cout << endl;
	}
	int getLength()
	{
		return size;
	}
	bool search(string data)
	{
		Node* current = top;
		while (current != NULL)
		{
			if (current->data == data)
				return true;
			current = current->next;
		}
		return false;
	}
};

//ADJACENCY LIST
class AdjList
{
public:
	//********************************************DATA MEMBERS********************************************//
	Node * head;		//HEAD OF THE LIST WILL ALWAYS BE A VERTEX WHILE OTHER ELEMENTS OF LIST WILL BE ITS NEIGHBOURS
	Node * tail;		//WILL OPTIMEZE INSERTIONS
	AdjList* next;	//POINTER TO NEXT LIST, WHERE THE NEXT LIST WILL BE POINTING TOWARDS ANOTHER VERTEX AND ITS NEIGHBOURS
	int size;				//SIZE OF THE LIST INCLUDING VERTEX AND ITS NEIGHBOURS
	int transitCost = 0;
	//****************************************************************************************************//

	//CONSTRUCTOR
	AdjList()
	{
		head = NULL;
		tail = NULL;
		size = 0;
		next = NULL;
	}
	AdjList(Node* n)
	{
		head = n;
		tail = n;
		head->next = NULL;
		tail->next = NULL;
		size = 1;
		next = NULL;
	}
	//destructor
	/*~AdjList()
	{
		clear();
	}*/

	//***********HELPER FUNCTIONS**********//
	void insert(const string newDataItem, Weight weight)
	{
		Node* temp = new Node;
		temp->data = newDataItem;
		temp->weight.insert(weight);	//FOR MULTIPLE WEIGHTS WITH DIRECT EDGE
		temp->next = NULL;

		if (head == NULL)
		{
			head = temp;
			tail = head;
			size = 1;
		}
		else
		{
			tail->next = temp;
			tail = tail->next;
			size += 1;
		}
	}
	//remove from start
	void removeFromStart()
	{
		Node* current = head->next;
		delete head;
		head = current;
		size--;
	}
	void remove(Node* current)
	{
		if (!isEmpty())
		{
			Node* temp = head;
			while (temp->next != current && temp->next != NULL)
			{
				temp = temp->next;
			}
			Node* toDelete = temp->next;


			//IF ONLY 1 ELEMENT LEFT
			if (current == tail && current == head)
			{
				delete current;
				tail = NULL;
				head = tail;
				size = 0;
				return;
			}
			//IF CURRENT IS AT TAIL
			else if (current == tail)
			{
				toDelete = temp->next;
				tail = temp;
				tail->next = NULL;
				//current = head;
			}
			//IF CURRENT IS AT HEAD
			else if (current == head)
			{
				toDelete = head;
				current = toDelete->next;
				head = current;
			}
			//IF CURRENT IS IN THE MIDDLE
			else
			{
				toDelete = temp->next;
				temp->next = toDelete->next;
				current = toDelete->next;
			}
			delete toDelete;
			size -= 1;
		}
		else
			cout << "Empty" << endl;

	}
	void removeAt(int index)
	{
		if (index >= 0 && index < size)
		{
			Node * current = head;
			for (int i = 0; i < index; i++)
			{
				current = current->next;
			}
			remove(current);
			return;
		}
		cout << "Out of Range" << endl;
	}
	void removeDataItem(const string newDataItem)
	{
		
		Node* previous = NULL;
		Node* current = head;
		for (int i = 0; i < size; i++)
		{
			if (current->data == newDataItem)
			{
				remove(current);
				break;
			}
			current = current->next;
		}
	}
	/*void clear()
	{
		while (head != NULL)
		{
			remove();
		}
	}*/
	bool isEmpty()
	{
		if (head == NULL)
		{
			return true;
		}
		return false;
	}
	int getSize()
	{
		return size;
	}
	bool search(string data)
	{
		Node* current = head;
		while (current != NULL)
		{
			if (current->data == data)
				return true;
			current = current->next;
		}
		return false;
	}
	//*************************************//

	//**************GETTERS****************//
	//RETURNS DATA AT INDEX
	string getDataAt(int index)
	{
		Node* current = head;
		if (!isEmpty())
		{
			for (int i = 0; i < index; i++)
			{
				current = current->next;
			}
			return current->data;
		}
	}

	//RETURNS NODE AT INDEX
	Node*& getNodeAt(int index)
	{
		Node* current = head;
		if (!isEmpty())
		{
			for (int i = 0; i < index; i++)
			{
				current = current->next;
			}
			return current;
		}
	}

	//RETURNS NODE WITH DATA
	Node*& getNode(string data)
	{
		Node* current = head;
		if (!isEmpty())
		{
			for (int i = 0; i < size; i++)
			{
				if (current->data == data)
					return current;
				current = current->next;
			}
			return current;
		}
	}
	//*************************************//

	//****************OUTPUT***************//
	//DISPLAYS LIST without weights
	void display()
	{
		if (size != 0)
		{
			Node* current = head;

			while (current != NULL)
			{
				cout << current->data << "->";
				//current->weight.display();
				//cout << string(current->data) << " -> ";
				current = current->next;
			}
			cout << "NULL" << endl;
		}
		else
			cout << "Empty" << endl;

	}

	//DISPLAYS LIST WITH WEIGHTS
	void displayWeighted()
	{
		if (size != 0)
		{
			Node* current = head;

			while (current != NULL)
			{
				cout << "" << current->data << endl << "Weight: " << endl;
				//cout << "" << string(current->data) << endl << "Weight: " << endl;
				current->weight.display();
				cout << "		|" << endl;
				cout << "		V" << endl;

				current = current->next;
			}
			cout << "	       NULL" << endl;
		}
		else
			cout << "Empty" << endl;

	}
	//*************************************//

};

//MAIN GRAPH CLASS
class Graph
{
	//********************************************DATA MEMBERS********************************************//
	//WILL MAINTAIN AN ADJACENCY LIST
	//EVERY ELEMENT IN THIS LIST WILL BE A VERTEX
	AdjList* head;
	AdjList* tail;

	int size;	//THE SIZE OF LIST WILL BE THE NUM OF VERTICES
	//****************************************************************************************************//
public:
	//**********CONSTRUCTOR**********//
	Graph()
	{
		head = NULL;
		tail = NULL;
		size = 0;
	}

	Graph(string fileFlights, string fileHotel)
	{
		head = NULL;
		tail = NULL;
		size = 0;

		//VARIABLES WE WILL USE TO READ FILE
		string line;
		string Vertex1;
		string Vertex2;
		string date;
		string time1;
		string time2;
		string airline;
		string cost;

		//VARIABLE TO INITIALIZE WEIGHTS
		Date actualDate;
		Time actualTime1;
		Time actualTime2;
		Weight w;

		//COUNTER WILL BE USED FOR READING INDIVIDUAL WORD IN STRING
		int counter = 0;
		//int line1 = 0;
		fstream file(fileFlights, ios::in);
		if (file.is_open())
		{
			while (!file.eof())
			{
				//cout << line1 << endl;
				//line1++;
				getline(file, line);
				line += ' ';
				for (int i = 0; i < line.length(); i++)
				{
					//WILL READ CITY1
					if (counter == 0)
					{
						if (line[i] != ' ')
							Vertex1 += line[i];
						else
							counter++;
					}

					//WILL READ CITY2
					else if (counter == 1)
					{
						if (line[i] != ' ')
							Vertex2 += line[i];
						else
							counter++;
					}

					//WILL READ DATE
					else if (counter == 2)
					{
						if (line[i] != ' ')
							date += line[i];
						else
						{
							counter++;
							actualDate.setDate(date);
						}

					}

					//WILL READ TIME1
					else if (counter == 3)
					{
						if (line[i] != ' ')
							time1 += line[i];
						else
						{
							counter++;
							actualTime1.setTime(time1);
						}
					}

					//WILL READ TIME2
					else if (counter == 4)
					{
						if (line[i] != ' ')
							time2 += line[i];
						else
						{
							counter++;
							actualTime2.setTime(time2);
						}
					}

					//WILL READ COST
					else if (counter == 5)
					{
						if (line[i] != ' ')
							cost += line[i];
						else
							counter++;
					}

					//WILL READ AIRLINE
					else if (counter == 6)
					{
						if (line[i] != ' ')
							airline += line[i];
						else //GRAPH WILL BE GENERATED HERE
						{


							//FOR MAIN GRAPH
							w.airline = airline;
							w.date = actualDate;
							w.time1 = actualTime1;
							w.time2 = actualTime2;
							w.cost = stoi(cost);

							insertVertex(Vertex1);
							insertVertex(Vertex2);
							insertEdge(Vertex1, Vertex2, w);
						}
					}
				}
				//RESETTING VARIABLES
				counter = 0;
				Vertex1 = "";
				Vertex2 = "";
				date = "";
				time1 = "";
				time2 = "";
				cost = "";
				airline = "";
			}
		}
		file.close();



		string place;
		file.open(fileHotel, ios::in);
		counter = 0;
		if (file.is_open())
		{
			while (!file.eof())
			{
				//cout << line1 << endl;
				//line1++;
				place = "";
				cost = "";
				counter = 0;
				getline(file, line);
				line += ' ';

				for (int i = 0; i < line.length(); i++)
				{
					//WILL READ CITY1
					if (counter == 0)
					{
						if (line[i] != ' ')
							place += line[i];
						else
							counter++;
					}
					//WILL READ AIRLINE
					else if (counter == 1)
					{
						if (line[i] != ' ')
							cost += line[i];
						else //GRAPH WILL BE GENERATED HERE
						{
							getList(place)->transitCost = stoi(cost);
						}
					}
				}

			}
		}
		file.close();

		//TO CHECK TRANSIT COSTS
		/*for (int i = 0; i < size; i++)
		{
			cout << getListAt(i)->getDataAt(0)<<" ";
			cout << getListAt(i)->transitCost << endl;;
		}*/
	}
	/*~Graph()
	{
		clear();
	}*/
	//**********************************************//

	//*********HELPERS*********//
	void clear()
	{
		while (!isEmpty())
		{
			remove();
		}
	}
	//remove from start
	void remove()
	{
		if (!isEmpty())
		{
			AdjList* cursor = head->next;
			delete head;
			head = cursor;
		}
	}
	bool isEmpty()
	{
		if (head == NULL)
			return true;
		return false;
	}
	//SEARCHES VERTICES IN LIST
	bool searchVertices(string data)
	{
		for (int i = 0; i < size; i++)
		{
			if (getListAt(i)->search(data))
				return true;
		}
		return false;
	}
	//************************//

	//**********************************INSERT**********************************//
	//INSERTS NEW VERTEX
	void insertVertex(string ver)
	{
		if (!searchVertices(ver))	//
		{
			if (head == NULL)
			{
				head = new AdjList;
				//cursor = head;
				tail = head;
			}
			else
			{
				tail->next = new AdjList;
				tail = tail->next;
			}
			Weight w;	//DEFAULT WEIGHT IS ZERO, MEANING THERE IS ZERO WEIGHT BETWEEN A NODE AND ITSELF
			tail->insert(ver, w);
			size++;
		}
		else
		{
			//	cout << "vertex already included" << endl;
		}
	}

	//INSERTS A DIRECTIONAL EDGE B/W TWO VERTICES
	void insertEdge(string src, string dest, Weight weight)
	{
		if (!getList(src)->search(dest))
		{
			//INSERTS NEIGHBOUR VERTICE WITH GIVEN WEIGHT
			getList(src)->insert(dest, weight);
		}
		else
		{
			//IF THAT NEIGHBOUR ALREADY EXISTS, WE INSERT ANOTHER WEIGHT TO THE DIRECT EDGE
			getList(src)->getNode(dest)->weight.insert(weight);
		}

	}

	//INSERTS AN UNDIRECTIONAL EDGE B/W TWO VERTICES
	void insertEdgeUnDirectional(string src, string dest, Weight weight)
	{
		//FOR UNDIRECTIONAL EDGE, EDGES WILL BE DOUBLY CONNECTED
		insertEdge(src, dest, weight);
		insertEdge(dest, src, weight);
	}
	//**************************************************************************//
	//****************************************GETTERS****************************************//
	//RETURNS LIST AT INDEX, MEANING IT WILL GIVE NEIGHBOURS OF VERTEX AT INDEX
	AdjList*& getListAt(int index)
	{
		AdjList* cursor = head;
		for (int i = 0; i < index; i++)
		{
			cursor = cursor->next;
		}
		return cursor;
	}

	//RETURNS LIST OF NEIGHBOURS OF DATA
	AdjList*& getList(string data)
	{
		AdjList* cursor = head;
		for (int i = 0; i < size; i++)
		{
			if (cursor->getDataAt(0) == data)
				return cursor;
			cursor = cursor->next;
		}
		return cursor;
	}

	//RETURNS INDEX OF WHERE THE VERTEX IS LYING
	int getIndex(string data)
	{
		AdjList* cursor = head;
		for (int i = 0; i < size; i++)
		{
			if (cursor->getDataAt(0) == data)
				return i;
			cursor = cursor->next;
		}
		return -1;
	}
	//***************************************************************************************//

	//*************************FLOYD WALA KAAAM BELOW WRT COST*************************//
	bool floydWarshall(string s, string d)//Passing SOurce and destination of type string
	{
		bool flag = true;
		//------CREAING AN 11x11 2D MATRIX OF OF NODES----------// 
		Node** Edge;
		Edge = new Node*[size];
		for (int i = 0; i < size; i++) {
			Edge[i] = new Node[size];
		}
		//-----------------------------------------------------//

		//------Weight temp is initialized with cost 0 (Min Value)----------// 
		Weight temp;
		temp.cost = 0;
		//....................................................//

		//.................Intializing all Edges of type Node with Empty data and cost 0................//
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				Edge[i][j].data = " ";
				Edge[i][j].weight.insert(temp);
			}
		}
		//....................................................//

		//------------A 2D Path Matrix of type int-----------//
		int** Path;
		Path = new int* [size];
		for (int i = 0; i < size; i++) {
			Path[i] = new int[size];
		}
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				Path[i][j] = -1;//Initializing data with -1
			}
		}
		//--------------------------------------------------//

		//------Mapping Graph to Matrix--------------------//
		//variabes used for mapping//
		AdjList* listTemp = new AdjList;
		Node* Temp;
		Node* Temp2;
		//outer loop from 0 to length of graph
		//start from list (present at each index of graph) starting node
		//Inner loop to all nodes present at a specific list
		//put node temp at edge[city][anothercity(of temp)]
		for (int i = 0; i < size; i++) {
			Temp = this->getListAt(i)->getNodeAt(0);
			Temp2 = Temp;
			while (Temp) {
				Edge[getIndex(Temp2->data)][getIndex(Temp->data)] = Temp;
				Temp = Temp->next;
			}
		}
		//put 0 cost at vertex to itself and 999999 at vertex with another
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (Edge[i][j].weight.getNodeAt(0)->data.cost == 0 && i != j) {
					Edge[i][j].weight.getNodeAt(0)->data.cost = 999999;
				}
			}
		}
		//UNCOMMENT TO CHECK IF GRAPH HAS BEEN CORRECTLY MAPPED-OTHER WISE DONT UNCOMMENT----//
		/*
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (Edge[i][j].data!=" ") {

					cout << Edge[i][j].weight.getNodeAt(0)->data.cost;

					cout << endl;

				}
				else {
					//cout << Edge[i][j].weight.getNodeAt(0)->data.cost;
					//Edge[i][j].weight.getNodeAt(0)->data.cost = 0;
					cout << "NO" << endl;
				}
				//cout << Edge[i][j].weight.getNodeAt(0)->data.cost;
			}
			cout << endl;
		}
		*/

		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (Edge[i][j].data != " ") {

					sort_wrt_cost(Edge[i][j].weight);//vimp
					//cout << Edge[i][j].weight.getNodeAt(0)->data.cost << " " << setw(8);
				}
				//else
					//cout << "NO" << " " << setw(8);

			}
			//cout << endl;
		}

		//--------------------APPLYING FLOYD-----------------//
		for (int k = 0; k < size; k++)
		{
			for (int i = 0; i < size; i++)
			{
				for (int j = 0; j < size; j++)
				{
					//donot alter this condition
					
					if (Edge[i][j].weight.getNodeAt(0)->data.cost > Edge[i][k].weight.getNodeAt(0)->data.cost + Edge[k][j].weight.getNodeAt(0)->data.cost && Edge[i][k].data!=" " && Edge[k][j].data != " ") {
						Edge[i][j].weight.getNodeAt(0)->data.cost = Edge[i][k].weight.getNodeAt(0)->data.cost + Edge[k][j].weight.getNodeAt(0)->data.cost;
						Path[i][j] = k;//maininting path matrix
					}
				}
			}
		}

		//system("CLS");
		//---------------------------//
		cout << " SOURCE : " << s << endl;
		cout << " Destination : " << d << endl;
		int transit = -1;//initializing transit with -1
		PathPrint(Path, getIndex(s), getIndex(d), transit); //this function will update the transit
		//cout << transit<<endl;
		if (Edge[getIndex(s)][getIndex(d)].weight.getNodeAt(0)->data.cost != 999999) {
			if (transit != -1) {
				if (Edge[transit][getIndex(d)].weight.getNodeAt(0)->data.cost != 999999 && Edge[getIndex(s)][transit].weight.getNodeAt(0)->data.cost != 999999)
				{
					cout << "THE PATH WITH MINIMUM COST IS :" << endl;
					cout << s << "---->" << getListAt(transit)->getNodeAt(0)->data << "---->" << d << endl;
					cout << endl;
					cout << "Flight 1 : " << s << "---->" << getListAt(transit)->getNodeAt(0)->data << endl;
					Edge[getIndex(s)][transit].weight.getNodeAt(0)->data.display();
					cout << endl;

					cout << "Flight 2 : " << getListAt(transit)->getNodeAt(0)->data << "---->" << d << endl;
					Edge[transit][getIndex(d)].weight.getNodeAt(0)->data.display();
					cout << endl;

					cout << "TOTAL FARE ESTIMATED = " << Edge[getIndex(s)][transit].weight.getNodeAt(0)->data.cost + Edge[transit][getIndex(d)].weight.getNodeAt(0)->data.cost << endl;
				}
				else {
					cout << "NO FLIGHTS POSSIBLE" << endl;
				}
			}
			else {
				cout << "THE PATH WITH MINIMUM COST IS :" << endl;
				cout << s << "---->" << d << endl;
				Edge[getIndex(s)][getIndex(d)].weight.getNodeAt(0)->data .display();
				cout << "TOTAL FARE ESTIMATED = " << Edge[getIndex(s)][getIndex(d)].weight.getNodeAt(0)->data.cost << endl;
			}
		}
		else
		{
			flag = false;
			cout << "NO FLIGHTS POSSIBLE" << endl;
		}
		return flag;
	}
	//Function that recursively prints all paths
	void PathPrint(int**& p, int s, int d, int& dummy) {

		int k = p[s][d];
		if (k != -1) {
			//With it's own
			if (k == 0) {
				dummy = 0;
				return;
			}
			PathPrint(p, s, k, dummy);
			dummy = printJaga(k);
			//cout << dummy;
			PathPrint(p, k, d, dummy);
		}
	}
	//This function returns and Prints the Transit between two Nodes
	int printJaga(int index) {
		cout << "FLIGHTS INCLUDE :";
		cout << getListAt(index)->getNodeAt(0)->data << endl;
		return index;
	}
	//*********************************************************************************//

	//*************************FLOYD2 WALA KAAAM BELOW WRT TRAVEL TIME************************//
	bool floydWarshall2(string s, string d)//Passing SOurce and destination of type string
	{

		//------CREAING AN 11x11 2D MATRIX OF OF NODES----------// 
		Node** Edge;
		Edge = new Node*[size];
		for (int i = 0; i < size; i++) {
			Edge[i] = new Node[size];
		}
		//-----------------------------------------------------//

		//------Weight temp is initialized with cost 99999 (Max Value)----------// 
		Weight temp;
		temp.time_diff = 0;
		//....................................................//

		//.................Intializing all Edges of type Node with Empty data and cost 99999................//
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				Edge[i][j].data = " ";
				Edge[i][j].weight.insert(temp);
			}
		}
		//....................................................//

		//------------A 2D Path Matrix of type int-----------//
		int** Path;
		Path = new int* [size];
		for (int i = 0; i < size; i++) {
			Path[i] = new int[size];
		}
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				Path[i][j] = -1;//Initializing data with -1
			}
		}
		//--------------------------------------------------//

		//------Mapping Graph to Matrix--------------------//
		//variabes used for mapping//

		AdjList* listTemp = new AdjList;
		Node* Temp;
		Node* Temp2;

		for (int i = 0; i < size; i++) {
			Temp = this->getListAt(i)->getNodeAt(0);
			Temp2 = Temp;
			while (Temp) {
				Edge[getIndex(Temp2->data)][getIndex(Temp->data)] = Temp;

				Temp = Temp->next;
			}
		}
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (Edge[i][j].weight.getNodeAt(0)->data.time_diff == 0 && i != j) {
					Edge[i][j].weight.getNodeAt(0)->data.time_diff = 999;
				}
			}
		}
		//UNCOMMENT TO CHECK IF GRAPH HAS BEEN CORRECTLY MAPPED-OTHER WISE DONT UNCOMMENT----//
		/*
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (Edge[i][j].data!=" ") {

					cout << Edge[i][j].weight.getNodeAt(0)->data.cost;

					cout << endl;

				}
				else {
					//cout << Edge[i][j].weight.getNodeAt(0)->data.cost;
					//Edge[i][j].weight.getNodeAt(0)->data.cost = 0;
					cout << "NO" << endl;
				}
				//cout << Edge[i][j].weight.getNodeAt(0)->data.cost;
			}
			cout << endl;
		}
		*/
		//-------------------------------------------------------//
		////Here Cost 99999 means no Direct Flight and 0 means the cost of node with itself
		//cout << "DISPLAYING THE Adjecancy MATRIX READ INITIALLY FROM GRAPH------" << endl;
		//for (int i = 0; i < size; i++)
		//{
		//	for (int j = 0; j < size; j++)
		//	{

		//		//cout << setw(8) << Edge[i][j].weight.getNodeAt(0)->data.time_diff << " ";

		//	}
		////	cout << endl;
		//}
		////THIS WILL SORT THE WEIGHTS OF EACH NODE (this loop is important donot comment sort---can comment the cout statements)
		////cout << endl << "SORTED-------" << endl;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (Edge[i][j].data != " ") {

					sort_wrt_time(Edge[i][j].weight);//vimp
					Edge[i][j].weight.getNodeAt(0)->data.time_diff = Edge[i][j].weight.getNodeAt(0)->data.time2.getHours() - Edge[i][j].weight.getNodeAt(0)->data.time1.getHours();
					if (Edge[i][j].weight.getNodeAt(0)->data.time_diff < 0) {
						Edge[i][j].weight.getNodeAt(0)->data.time_diff += 24;
					}

					//cout << setw(8);
					//cout << Edge[i][j].weight.getNodeAt(0)->data.time_diff << " " << setw(8);
				}
				//else
				//	cout << "NO" << " " << setw(8);

			}
			//cout << endl;
		}
		//Edge[0][2].weight.getNodeAt(0)->data.display();
		//cout << "-------------------" << endl;
		//--------------------APPLYING FLOYD-----------------//
		for (int k = 0; k < size; k++)
		{
			for (int i = 0; i < size; i++)
			{
				for (int j = 0; j < size; j++)
				{
					//donot alter this condition
					//if (Edge[i][j].weight.getNodeAt(0)->data.time_diff != 999) {
					if (Edge[i][j].weight.getNodeAt(0)->data.time_diff > (Edge[i][k].weight.getNodeAt(0)->data.time_diff + Edge[k][j].weight.getNodeAt(0)->data.time_diff) && Edge[i][k].data != " " && Edge[k][j].data != " ") {
						Edge[i][j].weight.getNodeAt(0)->data.time_diff = (Edge[i][k].weight.getNodeAt(0)->data.time_diff + Edge[k][j].weight.getNodeAt(0)->data.time_diff);
						Path[i][j] = k;//maininting path matrix
					}
					//}
				}
			}
		}
		//-------------------------------------------//
		//Printing Matrix After Floyd//
		//This matrix now contains minimum possible costs//
		//cost 99999 means no flight//

		//cout << "DISPLAYING FLOYD's MINIMUM COST MATRIX :-" << endl;
		//for (int i = 0; i < size; i++)
		//{
		//	for (int j = 0; j < size; j++)
		//	{
		//		//if (Edge[i][j].data != " ") {
		//		cout << setw(4) << Edge[i][j].weight.getNodeAt(0)->data.time_diff << " ";

		//		//}
		//		//else
		//			//cout << "NO" << " ";
		//	}
		//	cout << endl;
		//}

		//-------------------------//
		//Printing the Path Matrix After Floyd//
		//This matrix contains the transit between two Nodes//

/*
		cout << "DISPLAYING PATH MATIX :-" << endl;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				cout << setw(4) << Path[i][j] << " ";
			}
			cout << endl;
		}*/
		//---------------------------//
		cout << " SOURCE : " << s << endl;
		cout << " Destination : " << d << endl;
		int* transit = new int[2];
		for (int i = 0; i < 2; i++) {
			transit[i] = -1;
		}

		PathPrint2(Path, getIndex(s), getIndex(d), transit); //this function will update the transit
		//cout << transit[0] << "  "<<transit[1] << endl;
		if (transit[0] == transit[1]) {
			int t = transit[0];
			int transit = t;
			if (Edge[getIndex(s)][getIndex(d)].weight.getNodeAt(0)->data.time_diff != 999) {
				if (transit != -1) {
					if (Edge[transit][getIndex(d)].weight.getNodeAt(0)->data.time_diff != 999 && Edge[getIndex(s)][transit].weight.getNodeAt(0)->data.time_diff != 999)
					{
						cout << "THE PATH WITH MINIMUM Time IS :" << endl;
						cout << s << "---->" << getListAt(transit)->getNodeAt(0)->data << "---->" << d << endl;

						cout << "Flight 1 : " << s << "---->" << getListAt(transit)->getNodeAt(0)->data << endl;
						Edge[getIndex(s)][transit].weight.getNodeAt(0)->data.display();
						cout << "Flight 2 : " << getListAt(transit)->getNodeAt(0)->data << "---->" << d << endl;
						Edge[transit][getIndex(d)].weight.getNodeAt(0)->data.display();
						cout << "TOTAL Time  ESTIMATED = " << Edge[getIndex(s)][transit].weight.getNodeAt(0)->data.time_diff + Edge[transit][getIndex(d)].weight.getNodeAt(0)->data.time_diff << "hrs." << endl;
					}
					else {
						cout << "NO FLIGHTS POSSIBLE" << endl;
						return false;
					}
				}
				else {
					cout << "THE PATH WITH MINIMUM Time IS :" << endl;
					cout << s << "---->" << d << endl;
					Edge[getIndex(s)][getIndex(d)].weight.getNodeAt(0)->data .display();
					cout << "TOTAL FARE ESTIMATED = " << Edge[getIndex(s)][getIndex(d)].weight.getNodeAt(0)->data.time_diff << "hrs" << endl;
				}
			}
			else
			{
				cout << "NO FLIGHTS POSSIBLE" << endl;
				return false;
			}
		}
		else {
			if (Edge[getIndex(s)][getIndex(d)].weight.getNodeAt(0)->data.time_diff != 999) {
				if (transit[0] != -1 && transit[1] != -1) {
					if (Edge[transit[1]][getIndex(d)].weight.getNodeAt(0)->data.time_diff != 999 && Edge[getIndex(s)][transit[0]].weight.getNodeAt(0)->data.time_diff != 999 && Edge[transit[0]][transit[1]].weight.getNodeAt(0)->data.time_diff != 999)
					{
						cout << "THE PATH WITH MINIMUM Time IS :" << endl;
						cout << s << "---->" << getListAt(transit[0])->getNodeAt(0)->data << "---->" << getListAt(transit[1])->getNodeAt(0)->data << "---->" << d << endl;

						cout << "Flight 1 : " << s << "---->" << getListAt(transit[0])->getNodeAt(0)->data << endl;
						Edge[getIndex(s)][transit[0]].weight.getNodeAt(0)->data .display();
						cout << "Flight 2 : " << getListAt(transit[0])->getNodeAt(0)->data << "---->" << getListAt(transit[1])->getNodeAt(0)->data << endl;
						Edge[transit[0]][transit[1]].weight.getNodeAt(0)->data.display();
						cout << "Flight 3 : " << getListAt(transit[1])->getNodeAt(0)->data << "---->" << d << endl;
						Edge[transit[1]][getIndex(d)].weight.getNodeAt(0)->data.display();
						//cout << "1: "<< Edge[getIndex(s)][transit[0]].weight.getNodeAt(0)->data.time_diff <<endl;
						//cout << "2: "<< Edge[transit[0]][transit[1]].weight.getNodeAt(0)->data.time_diff <<endl;
						//cout << "3: " << Edge[transit[1]][getIndex(d)].weight.getNodeAt(0)->data.time_diff << endl;
						cout << "TOTAL Time  ESTIMATED = " << Edge[getIndex(s)][transit[0]].weight.getNodeAt(0)->data.time_diff + Edge[transit[0]][transit[1]].weight.getNodeAt(0)->data.time_diff + Edge[transit[1]][getIndex(d)].weight.getNodeAt(0)->data.time_diff << "hrs." << endl;
					}
					else
					{
						cout << "NO FLIGHTS POSSIBLE" << endl;
						return false;
					}
				}
				else {
					cout << "THE PATH WITH MINIMUM Time IS :" << endl;
					cout << s << "---->" << d << endl;
					Edge[getIndex(s)][getIndex(d)].weight.getNodeAt(0)->data .display();
					cout << "TOTAL FARE ESTIMATED = " << Edge[getIndex(s)][getIndex(d)].weight.getNodeAt(0)->data.time_diff << "hrs." << endl;
				}
			}
			else
			{
				cout << "NO FLIGHTS POSSIBLE" << endl;
				return false;
			}
		}
		return true;
	}
	//Function that recursively prints all paths
	void PathPrint2(int**& p, int s, int d, int* dummy, int count = 0) {
		int k = p[s][d];
		//cout << "K: " << k << endl;
		if (k != -1) {
			cout << "Entered" << endl;
			dummy[count] = printJaga2(k);
			PathPrint2(p, s, k, dummy);
			count++;
			dummy[count] = printJaga2(k);

			PathPrint2(p, k, d, dummy);
		}
	}
	//This function returns and Prints the Transit between two Nodes
	int printJaga2(int index) {
		return index;
	}
	//****************************************************************************************//

	//************************************OUTPUT************************************//
	//DISPLAYS THE ADJACENCY LIST ALONG WITH VERTICES AND THEIR NEIGHBOURS//
	void displayWeighted()
	{
		AdjList* cursor = head;
		for (int i = 0; i < size; i++)
		{
			cout << "Vertex " << i + 1 << ":" << endl;
			cursor->displayWeighted();
			cursor = cursor->next;
			cout << "******************************************" << endl;

		}
	}
	//Only display cities, not weights
	void display()
	{
		AdjList* cursor = head;
		for (int i = 0; i < size; i++)
		{
			cout << "Vertex " << i + 1 << ":" << endl;
			cursor->display();
			cursor = cursor->next;
			cout << "******************************************" << endl;

		}
	}

	//BREADTH FIRST TRAVERSAL
	void BFS(string startNode)
	{
		if (head == NULL) {
			return;
		}
		Queue tempQ;
		Node * temp;
		tempQ.enqueue(startNode);
		bool* visited = new bool[size];
		for (int i = 0; i < size; i++)
		{
			visited[i] = false;
		}
		visited[getIndex(startNode)] = true;

		while (!tempQ.isEmpty())
		{
			AdjList* cursor = getList(tempQ.dequeue());
			temp = cursor->getNodeAt(0); // 3
			cout << temp->data << endl;
			while (temp != NULL)
			{


				if (!(tempQ.search(temp->data)) && visited[getIndex(temp->data)] == false)
				{
					visited[getIndex(temp->data)] = true;
					tempQ.enqueue(temp->data);
				}
				temp = temp->next;

			}
		}
		delete visited;
	}

	//DEPTH FIRST TRAVERSAL
	void DFS(string startNode)
	{
		if (head == NULL) {
			return;
		}
		Stack tempS;
		Node * temp;
		tempS.push(startNode);
		bool* visited = new bool[size];
		for (int i = 0; i < size; i++)
		{
			visited[i] = false;
		}
		visited[getIndex(startNode)] = true;

		while (!tempS.isEmpty())
		{
			//tempS.display();
			AdjList* cursor = getList(tempS.pop());
			temp = cursor->getNodeAt(0); // 3
			cout << temp->data << endl;

			while (temp != NULL)
			{
				//cout << temp->data << endl;
				if (!(tempS.search(temp->data)) && visited[getIndex(temp->data)] == false)
				{

					visited[getIndex(temp->data)] = true;
					tempS.push(temp->data);
				}
				temp = temp->next;
			}
			//cout << endl;
		}
		delete visited;
	}

	//SHOWS PATH B/W TWO VERTICES
	bool showPath(string startNode, string dest, int wrt = 0)
	{
		if (getList(startNode)->search(dest))
		{
			Weight w;
			int hrs;
			cout << "Direct path exists" << endl;
			cout << startNode << " ---> " << dest << endl;
			//ALL FLIGHTS
			getList(startNode)->getNode(dest)->weight.display();
			if (wrt == 0)
			{
				sort_wrt_cost(getList(startNode)->getNode(dest)->weight);
			}
			else if (wrt == 1)
			{
				sort_wrt_days(getList(startNode)->getNode(dest)->weight);
			}
			else if (wrt == 2)
			{
				sort_wrt_time(getList(startNode)->getNode(dest)->weight);
			}



			//YOUR FLIGHT
			cout << "\nYour Flight:" << endl;
			getList(startNode)->getNode(dest)->weight.getDataAt(0) .display();
			cout << "Flight Time: ";
			w = getList(startNode)->getNode(dest)->weight.getDataAt(0);
			hrs = w.time2.getHours() - w.time1.getHours();
			if (hrs < 0)
				hrs += 24;
			cout << hrs << endl;
			return true;
		}
		else
		{
			cout << "No Direct Path Exists" << endl;
			return false;
		}

	}

	//DISPLAYS VERTICES (not neighbours)
	void displayVertices()
	{
		AdjList* cursor = head;
		for (int i = 0; i < size; i++)
		{
			cout << "* " << cursor->getDataAt(0) << endl;
			cursor = cursor->next;
		}
	}
	//*****************************************************************************//
};

//Returns a subgraph of main graph, with only the desired airlines.
Graph* getSubGraph(string data, string flights, string hotelCharges)
{
	Graph * gr1 = new Graph;
	//VARIABLES WE WILL USE TO READ FILE
	string line;
	string Vertex1;
	string Vertex2;
	string date;
	string time1;
	string time2;
	string airline;
	string cost;

	//VARIABLE TO INITIALIZE WEIGHTS
	Date actualDate;
	Time actualTime1;
	Time actualTime2;
	Weight w;

	//COUNTER WILL BE USED FOR READING INDIVIDUAL WORD IN STRING
	int counter = 0;
	//int line1 = 0;
	fstream file(flights, ios::in);
	if (file.is_open())
	{

		while (!file.eof())
		{
			//cout << line1 << endl;
			//line1++;
			getline(file, line);
			line += ' ';
			for (int i = 0; i < line.length(); i++)
			{
				//WILL READ CITY1
				if (counter == 0)
				{
					if (line[i] != ' ')
						Vertex1 += line[i];
					else
						counter++;
				}

				//WILL READ CITY2
				else if (counter == 1)
				{
					if (line[i] != ' ')
						Vertex2 += line[i];
					else
						counter++;
				}

				//WILL READ DATE
				else if (counter == 2)
				{
					if (line[i] != ' ')
						date += line[i];
					else
					{
						counter++;
						actualDate.setDate(date);
					}

				}

				//WILL READ TIME1
				else if (counter == 3)
				{
					if (line[i] != ' ')
						time1 += line[i];
					else
					{
						counter++;
						actualTime1.setTime(time1);
					}
				}

				//WILL READ TIME2
				else if (counter == 4)
				{
					if (line[i] != ' ')
						time2 += line[i];
					else
					{
						counter++;
						actualTime2.setTime(time2);
					}
				}

				//WILL READ COST
				else if (counter == 5)
				{
					if (line[i] != ' ')
						cost += line[i];
					else
						counter++;
				}

				//WILL READ AIRLINE
				else if (counter == 6)
				{
					if (line[i] != ' ')
						airline += line[i];
					else //GRAPH WILL BE GENERATED HERE
					{
						//FOR SUBGRAPH OF EMIRATES FLIGHTS
						if (airline == data)
						{
							w.airline = airline;
							w.date = actualDate;
							w.time1 = actualTime1;
							w.time2 = actualTime2;
							w.cost = stoi(cost);

							gr1->insertVertex(Vertex1);
							gr1->insertVertex(Vertex2);
							gr1->insertEdge(Vertex1, Vertex2, w);
						}

					}
				}
			}
			//RESETTING VARIABLES
			counter = 0;
			Vertex1 = "";
			Vertex2 = "";
			date = "";
			time1 = "";
			time2 = "";
			cost = "";
			airline = "";
		}
	}
	file.close();

	string place;
	file.open(hotelCharges, ios::in);
	counter = 0;
	if (file.is_open())
	{
		while (!file.eof())
		{
			//cout << line1 << endl;
			//line1++;
			place = "";
			cost = "";
			counter = 0;
			getline(file, line);
			line += ' ';

			for (int i = 0; i < line.length(); i++)
			{
				//WILL READ CITY1
				if (counter == 0)
				{
					if (line[i] != ' ')
						place += line[i];
					else
						counter++;
				}
				//WILL READ AIRLINE
				else if (counter == 1)
				{
					if (line[i] != ' ')
						cost += line[i];
					else //GRAPH WILL BE GENERATED HERE
					{
						if (gr1->getList(place) != NULL)
							gr1->getList(place)->transitCost = stoi(cost);
					}
				}
			}

		}
	}
	file.close();

	return gr1;
}

void UI(string flights, string hotelCharges)
{
	//int choice = 0;
	int airline = 0;
	bool airlineAll = false;
	string location;
	string destination;
	string transitLocation;
	string d;
	Date date;
	int typeOfFlight;
	int wrt;
	//string ready = "yes";
	//int counter;
	bool isFlight = true;
	bool Tflag = false;

	Graph* graph = new Graph(flights, hotelCharges);
	while (true)
	{
		int choice; 
		//counter = 0;
		cout << "\n\n*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*" << endl;
		cout << "Welcome to J International Airlines!" << endl;
		cout << endl;

		/*cout << "__  _" << endl;
		cout << "\ `/ |" << endl;
		cout << " \__`!" << endl;
		cout << " / ,' `-.__________________" << endl;
		cout << "'-'\\_____   J I A         \\_`-." << endl;
		cout << "   <____()-=O=O=O=O=O=[]====-- )" << endl;
		cout << "     `.___ ,-----,_______...- '" << endl;
		cout << "          /    .'" << endl;
		cout << "         /   .'" << endl;
		cout << "        /  .'         " << endl;
		cout << "        `-'" << endl;*/

		cout << "                             |" << endl;
		cout << "                _______     ^^^" << endl;
		cout << "               |**JIA**|  _^^^^^_" << endl;
		cout << "               |[]+++[]| | [][]  |" << endl;
		cout << "            ______+++++| |[][][] |" << endl;
		cout << "           |++++++|++[]| | [][][]|     " << endl;;
		cout << "           || || ||++++| |[][][] |" << "                                    __  _" << endl;
		cout << "           |++++++|_________ [][]|" << "                                    \ `/ |" << endl;
		cout << "           || || ||=|=|=|=|=| [] |" << "                                     \__`!" << endl;
		cout << "           |++++++|=|=|=|=|=|[][]|" << "                                     / ,' `-.__________________" << endl;
		cout << "___________|++HH++|  _HHHH__|   _________   _________  _________" << "      '-'\\_____   J I A         \\_`-." << endl;
		cout << "         _______________   ______________      ______________" << "            <____()-=O=O=O=O=O=[]====-- )" << endl;
		cout << "__________________  ___________    __________________    ____________" << "___   `.___ ,-----,_______...- '" << endl;
		cout << "         _______________                 _______________                        /    .'" << endl;
		cout << "__________________  ___________    __________________    _________________     /   .'" << endl;
		cout << "                                                                              /  .'         " << endl;
		cout << "                                                                              `-'" << endl;

		cout << endl;
		cout << "How may we help you?" << endl;
		cout << "1. Display All Flights" << endl;
		cout << "2. Display All Flights with their Information" << endl;
		cout << "3. Choose a specific airline" << endl;
		cout << "4. Book a Flight" << endl;
		cout << "5. Exit" << endl;
		cout << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*" << endl;
		cin >> choice;

		//EXIT
		if (choice == 5)
		{
			cout << "Goodbye!" << endl;
			break;
		}


		//DISPLAY FLIGHTS
		if (choice == 1)
		{
			cout << "Here are all the flights:" << endl;
			graph->display();
			continue;
		}

		//DISPLAY FLIGHTS WITH WEIGHTS
		else if (choice == 2)
		{
			cout << "Here are all the flights and their Information:" << endl;
			graph->displayWeighted();
			continue;
		}

		//CHOOSE AN AIRLINE
		else if (choice == 3)
		{
			cout << "what airline would you want to travel with?" << endl;
			cout << "1. Emirates \n2. Qatar \n3. ANA \n4. All Airlines\n";
			cin >> airline;
			if (airline == 1)
			{
				delete graph;
				graph = NULL;
				graph = getSubGraph("Emirates", flights, hotelCharges);
				airlineAll = true;
				continue;
			}
			else if (airline == 2)
			{
				delete graph;
				graph = NULL;
				graph = getSubGraph("Qatar", flights, hotelCharges);
				airlineAll = true;
				continue;
			}
			else if (airline == 3)
			{
				delete graph;
				graph = NULL;
				graph = getSubGraph("ANA", flights, hotelCharges);
				airlineAll = true;
				continue;
			}
			else if (airline == 4 && airlineAll == true)
			{
				delete graph;
				graph = NULL;
				graph = new Graph(flights, hotelCharges);
				continue;
			}
			else {
				cout << "Invalid" << endl;
				continue;
			}
		}

		//BOOK A FLIGHT
		else if (choice == 4)
		{
			cout << "What is your location ?" << endl;
			graph->displayVertices();

			cin >> location;
			if (!(graph->searchVertices(location))) {
				cout << "Invalid"<<endl;
				continue;
			}
			isFlight = true;
			while (isFlight)
			{


				if (Tflag == false)
				{
					cout << "What is your Destination ?" << endl;
					graph->displayVertices();

					cin >> destination;
					string atPlace = location;
					if (!(graph->searchVertices(destination))) {
						cout << "Invalid"<<endl;
						continue;
					}
					if (destination == atPlace) {
						cout << "Already at the place (no edge to vertex itself exist)"<<endl;
						continue;
					}
					cout << "Please enter desired day of flight." << endl;
					cin >> d;
					d += "/12/2019";
					date.setDate(d);

				}
				else
				{
					destination = transitLocation;
					Tflag = false;
				}

				cout << "Your Location: " << location << endl;
				cout << "Your Destination: " << destination << endl;
				cout << "Date of Travel: " << date.getDate() << endl;


				cout << "Any Transit Location?" << endl;
				cout << "* no" << endl;
				graph->displayVertices();
				cin >> transitLocation;

				if (transitLocation != "no")
				{
					swap(destination, transitLocation);
					Tflag = true;
				}

				cout << "\nWhat Type of Flight do you want?" << endl;
				cout << "1. Direct Flight." << endl;
				cout << "2. Connected Flight" << endl;
				cin >> typeOfFlight;

				if (typeOfFlight == 1)
				{
					cout << graph->getList(location)->search(destination) << endl;
					if (graph->getList(location)->search(destination))
					{
						cout << "Flight with highest priority of ?" << endl;
						cout << "1. Minimal Cost" << endl;
						cout << "2. Minimal Time" << endl;
						cout << "3. As Soon As Possible" << endl;
						cin >> wrt;
						graph->showPath(location, destination, (wrt - 1));
						isFlight = true;
					}
					else
					{
						cout << "No Direct Path Exists for your Flight" << endl;
						isFlight = false;
						break;
					}
				}
				else if (typeOfFlight == 2)
				{
					while (1) {
						cout << "Flight with highest priority of ?" << endl;
						cout << "1. Minimal Cost" << endl;
						cout << "2. Minimal Time" << endl;
						cin >> wrt;
						if (wrt == 1) {
							isFlight = graph->floydWarshall(location, destination);
							break;
						}
						else if (wrt == 2){
							isFlight = graph->floydWarshall2(location, destination);
							break;
						}
						else
							cout << "Invalid" << endl;
					}
					if (!isFlight) {
						Tflag = false;
					}
				}
				else {
					cout << "Invalid" << endl;
					isFlight = false;
					Tflag = false;
				}
				if (isFlight)
				{
					if (Tflag)
						cout << "\nTransit Cost: " << graph->getList(destination)->transitCost << endl;
					location = destination;
					cout << "You Have Arrived At: " << destination << endl;
					string travel;
					cout << "Would you want to continue traveling? ... enter yes: ";
					cin >> travel;
					if (travel == "yes") {
						cout << "Now where would you like to go?" << endl;
						isFlight = true;
					}
					else {
						isFlight = false;
						break;
					}
				}
			}
			continue;
		}
		else
			cout << "Invalid" << endl;

	}
}

void main() {
	/*List l;
	l.insert("hey");
	l.insert("hi");
	l.insert("done");
	l.display();
	l.removeAt(2);
	l.display();*/
	UI("Flights.txt", "HotelCharges_perday.txt");
}
