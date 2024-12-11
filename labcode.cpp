//1st code oop
#include <iostream>
using namespace std;
class Complex {
private:
 double real;
 double imag;
public:
 Complex() : real(0), imag(0) {}
 Complex(double r, double i) : real(r), imag(i) {}
 Complex operator+(const Complex& other) const {
    return Complex(real + other.real, imag + other.imag);
 }
 Complex operator*(const Complex& other) const {
    return Complex(real * other.real - imag * other.imag, 
    real * other.imag + imag * other.real);
 }
 friend ostream& operator<<(ostream& os, const Complex& c) {
 os << c.real;
    if (c.imag >= 0) {
    os << " + " << c.imag << "i";
    } else {
        os << " - " << -c.imag << "i";
    }
 return os;
 }
 friend istream& operator>>(istream& is, Complex& c) {
 char sign;
 is >> c.real >> sign;
if (sign == '+') {
    is >> c.imag;
} 
else if (sign == '-') {
    is >> c.imag;
    c.imag = -c.imag;
 }
 is >> sign;
 return is;
 }
};
int main() {
 Complex c1(3, 4);
 Complex c2(1, 2);
 Complex sum = c1 + c2;
 Complex product = c1 * c2;
 cout << "c1: " << c1 << endl;
 cout << "c2: " << c2 << endl;
 cout << "Sum: " << sum << endl;
 cout << "Product: " << product << endl;
 Complex c3;
 cout << "Enter a complex number (format: a + bi): ";
 cin >> c3;
 cout << "You entered: " << c3 << endl;
 return 0;
}

//second code oop
#include <iostream>
#include <string>
using namespace std;
class Student {
private:
 string name;
 int rollNumber;
 string className;
 char division;
 string dateOfBirth;
 string bloodGroup;
 string contactAddress;
 string telephoneNumber;
 string drivingLicenseNumber;
 static int totalStudents;
public:
 Student() : rollNumber(0), division('A') {
 totalStudents++;
 }
 Student(string name, int rollNumber, string 
className, char division,
 string dob, string bloodGroup, string 
address,
 string phone, string license) 
 : name(name), rollNumber(rollNumber), 
className(className), 
 division(division), dateOfBirth(dob), 
bloodGroup(bloodGroup), 
 contactAddress(address), 
telephoneNumber(phone), 
 drivingLicenseNumber(license) {
 totalStudents++;
 }
 Student(const Student &other) {
 name = other.name;
 rollNumber = other.rollNumber;
 className = other.className;
 division = other.division;
 dateOfBirth = other.dateOfBirth;
 bloodGroup = other.bloodGroup;
 contactAddress = other.contactAddress;
 telephoneNumber = 
other.telephoneNumber;
 drivingLicenseNumber = 
other.drivingLicenseNumber;
 totalStudents++;
 }
 ~Student() {
 totalStudents--;
 }
 static int getTotalStudents() {
 return totalStudents;
 }
 inline string getName() const {
 return name;
 }
 friend class StudentDatabase;
 void displayInfo() const {
 cout << "Name: " << name << "\n"
 << "Roll Number: " << rollNumber 
<< "\n"
 << "Class: " << className << "\n"
 << "Division: " << division << "\n"
 << "Date of Birth: " << dateOfBirth 
<< "\n"
 << "Blood Group: " << bloodGroup 
<< "\n"
 << "Contact Address: " << 
contactAddress << "\n"
 << "Telephone Number: " << 
telephoneNumber << "\n"
 << "Driving License Number: " << 
drivingLicenseNumber << "\n";
 }
};
int Student::totalStudents = 0;
class StudentDatabase {
public:
 void printTotalStudents() {
 cout << "Total Students: " << 
Student::getTotalStudents() << endl;
 }
};
int main() {
 Student s1("John Doe", 101, "10th", 'A', 
"01/01/2005", "O+", "123 Main St", 
"1234567890", "DL12345");
 s1.displayInfo();
 StudentDatabase db;
 db.printTotalStudents();
 return 0;
}

//3rd code oop
#include <iostream>
#include <string>
#include <stdexcept>
#include <limits>
using namespace std;
class Publication {
protected:
 string title;
 double price;
public:
 Publication(const string& title, double price) 
: title(title), price(price) {}
 virtual void display() const {
 cout << "Title: " << title << ", Price: Ru" 
<< price << endl;
 }
};
class Book : public Publication {
private:
 int pageCount;
public:
 Book(const string& title, double price, int 
pageCount)
 : Publication(title, price), 
pageCount(pageCount) {}
 void display() const override {
 Publication::display();
 cout << "Page Count: " << pageCount << 
endl;
 }
};
class Tape : public Publication {
private:
 int playingTime;
public:
 Tape(const string& title, double price, int 
playingTime)
 : Publication(title, price), 
playingTime(playingTime) {}
 void display() const override {
 Publication::display();
 cout << "Playing Time: " << playingTime 
<< " minutes" << endl;
 }
};

void getPublicationData(string& title, double& 
price) {
 cout << "Enter the title: ";
 getline(cin, title);
 cout << "Enter the price: ";
 cin >> price;
 
cin.ignore(numeric_limits<streamsize>::max(), 
'\n');
}
int main() {
 string title;
 double price;
 int pageCount, playingTime;
 cout << "Enter details for a Book:" << endl;
 getPublicationData(title, price);
 try {
 cout << "Enter the page count: ";
 cin >> pageCount;
 if (cin.fail()) throw runtime_error("Invalid 
input");
 
cin.ignore(numeric_limits<streamsize>::max(), 
'\n');
 Book book(title, price, pageCount);
 book.display();
 } catch (const exception&) {
 cout << "Invalid input for page count. 
Setting page count to zero." << endl;
 Book book(title, price, 0);
 book.display();
 }
 cout << "\nEnter details for a Tape:" << 
endl;
 getPublicationData(title, price);
 try {
 cout << "Enter the playing time in minutes: 
";
 cin >> playingTime;
 if (cin.fail()) throw runtime_error("Invalid 
input");
 
cin.ignore(numeric_limits<streamsize>::max(), 
'\n');
 Tape tape(title, price, playingTime);
 tape.display();
 } catch (const exception&) {
 cout << "Invalid input for playing time. 
Setting playing time to zero." << endl;
 Tape tape(title, price, 0);
 tape.display();
 }
 return 0;
}

//4th code oop
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() {
 ofstream output_file("output.txt");
 if (!output_file) {
 cerr << "Error opening output file." << 
endl;
 return 1;
 }
 output_file << "This is some information to 
be written to the file." << endl;
 output_file.close();
 ifstream input_file("output.txt");
 if (!input_file) {
 cerr << "Error opening input file." << 
endl;
 return 1;
 }
 string line;
 while (getline(input_file, line)) {
 cout << line << endl;
 }
 input_file.close();
 return 0;
}

// 5th code oop
#include <iostream>
using namespace std;
template <typename T>
void selectionSort(T arr[], int n) {
 for (int i = 0; i < n - 1; i++) {
 int minIndex = i;
 for (int j = i + 1; j < n; j++) {
 if (arr[j] < arr[minIndex]) {
 minIndex = j;
 }
 }
 if (minIndex != i) {
 T temp = arr[i];
 arr[i] = arr[minIndex];
 arr[minIndex] = temp;
 }
 }
}
int main() {
 int intArr[] = {5, 2, 8, 1, 9};
 int nInt = sizeof(intArr) / sizeof(intArr[0]);
 selectionSort(intArr, nInt);
 cout << "Sorted Integer Array: ";
 for (int i = 0; i < nInt; i++) {
 cout << intArr[i] << " ";
 }
 cout << endl;
 float floatArr[] = {3.14, 1.618, 2.718, 0.577, 
4.236};
 int nFloat = sizeof(floatArr) / 
sizeof(floatArr[0]);
 selectionSort(floatArr, nFloat);
 cout << "Sorted Float Array: ";
 for (int i = 0; i < nFloat; i++) {
 cout << floatArr[i] << " ";
 }
 cout << endl;
 return 0;
}

//6th code oop
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
struct Person {
 string name;
 string dob; 
 string telephone;
 Person(string n, string d, string t) : name(n), 
dob(d), telephone(t) {}
};
struct Item {
 int itemCode;
 string name;
 double cost;
 int quantity;
 Item(int code, string n, double c, int q) : 
itemCode(code), name(n), cost(c), quantity(q) {}
};
void displayPersons(const vector<Person>& 
persons) {
 cout << "Persons:\n";
 for (const auto& person : persons) {
 cout << "Name: " << person.name << ", 
DOB: " << person.dob << ", Telephone: " << 
person.telephone << endl;
 }
}
void displayItems(const vector<Item>& items) {
 cout << "Items:\n";
 for (const auto& item : items) {
 cout << "Item Code: " << item.itemCode 
<< ", Name: " << item.name << ", Cost: " << 
item.cost << ", Quantity: " << item.quantity << 
endl;
 }
}
bool comparePersons(const Person& a, const 
Person& b) {
 return a.name < b.name;
}
bool compareItems(const Item& a, const Item& 
b) {
 return a.itemCode < b.itemCode;
}
int main() {
 vector<Person> persons;
 vector<Item> items;
 persons.push_back(Person("Alice", "1990-01-
01", "123-456-7890"));
 persons.push_back(Person("Bob", "1985-05-
15", "987-654-3210"));
 persons.push_back(Person("Charlie", "1992-
03-30", "555-555-5555"));
 items.push_back(Item(101, "Laptop", 999.99, 
10));
 items.push_back(Item(102, "Smartphone", 
499.99, 20));
 items.push_back(Item(103, "Tablet", 299.99, 
15));
 displayPersons(persons);
 displayItems(items);
 sort(persons.begin(), persons.end(), 
comparePersons);

 sort(items.begin(), items.end(), 
compareItems);
 cout << "\nSorted Records:\n";
 displayPersons(persons);
 displayItems(items);
 string searchName;
 cout << "\nEnter name to search for a 
Person: ";
 cin >> searchName;
 auto it = find_if(persons.begin(), 
persons.end(), [&searchName](const Person& 
p) {
 return p.name == searchName;
 });
 if (it != persons.end()) {
 cout << "Found Person: " << it->name 
<< ", DOB: " << it->dob << ", Telephone: " 
<< it->telephone << endl;
 } else {
 cout << "Person not found!" << endl;
 }
 int searchCode;
 cout << "\nEnter item code to search for an 
Item: ";
 cin >> searchCode;
 auto itItem = find_if(items.begin(), 
items.end(), [searchCode](const Item& item) {
 return item.itemCode == searchCode;
 }
 );
 if (itItem != items.end()) {
 cout << "Found Item: " << itItem->name 
<< ", Cost: " << itItem->cost << ", Quantity: " 
<< itItem->quantity << endl;
 } else {
 cout << "Item not found!" << endl;
 }
 return 0;
}

//7th code oop
#include <iostream>
#include <map>
#include <string>
using namespace std;
int main() {
 std::map<std::string, int> statePopulation;
 statePopulation["California"] = 39538223;
 statePopulation["Texas"] = 29145505;
 statePopulation["Florida"] = 21538187;
 statePopulation["New York"] = 20201249;
 statePopulation["Pennsylvania"] = 13002700;
 std::string stateName;
 std::cout << "Enter the name of a state: ";
 std::getline(std::cin, stateName);
 auto it = statePopulation.find(stateName);
 if (it != statePopulation.end()) {
 std::cout << "The population of " << stateName << " is " << it->second << "." << std::endl;
 } else {
 std::cout << "State not found in the database." << std::endl;
 }
 return 0;
}
