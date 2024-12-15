//Write a Python program to store marks scored in subject “Fundamental of Data Structure” by N students 
//in the class. Write functions to compute the following: 
//a) The average score of class 
//b) Highest score and lowest score of class 
//c) Count of students who were absent for the test 
//d) Display mark with highest frequency

def Average(marks,n):
		sum=0
		for i in range(n):
			sum=sum+marks[i]			
		average=sum/n
		return average
	
def Maximum(marks,n):
		max=0
		for i in range(n):
			if(marks[i]>max):
			   max=marks[i]
		return max

def Minimum(marks,n):
		min=999
		for i in range(n):
			if(marks[i]<min and marks[i]>=0):
				min=marks[i]
		return min

def Absent(marks,n):
		cnt=0
		for i in range(n):
			if(marks[i]==-1):
				cnt=cnt+1	
		return cnt

def Cntmax(marks,n,s):
		cntmax=0
		for i in range(n):
			if(marks[i]==s):
				cntmax=cntmax+1
		return cntmax		
marks=[]
n=int(input("Enter number of students , if absent pleae enter -1:"))
for i in range(n):
	m=int(input("Enter your marks:"))
	marks.append(m)
i=1
while i<=6:
	print("please press'1' for average") 
	print("'2'for maximum marks") 
	print("'3' for minimum marks") 
	print("'4' for absent sudents")
	print("'5' for no.max marks")
	print("'6'for none")	
	opt=int(input("Enter your choice: "))
	match opt:
		case 1:	
			avg=Average(marks,n)
			print("Average is:",avg)
		case 2:
		     max=Maximum(marks,n)
		     print("Maximum marks:",max)
		case 3:
			min=Minimum(marks,n)		
			print("Minimum marks:",min)
		case 4:		
			cnt=Absent(marks,n)		
			print("No. of absent students:",cnt)
		case 5:
			s=Maximum(marks,n)
			cntmax=Cntmax(marks,n,s)		
			print("The no. of students having maximum marks:",cntmax)
		case 6:
			print("This option indictes you have choosen none!")
//if asked for highest frequency.
def mark_with_highest_frequency(marks):
    """
    Find the mark(s) occurring most frequently, ignoring absentees.
    """
    valid_marks = [mark for mark in marks if mark != -1]
    if not valid_marks:
        return None
    # Use a simple loop to count frequencies instead of a dictionary for simplicity
    max_freq = 0
    most_frequent = []
    for mark in set(valid_marks):
        freq = valid_marks.count(mark)
        if freq > max_freq:
            max_freq = freq
            most_frequent = [mark]
        elif freq == max_freq:
            most_frequent.append(mark)
    return most_frequent

//Write a Python program that computes the net amount of a bank account based on a transaction log from 
//console input. The transaction log format is shown as follows: D 100 W 200 (Withdrawal is not allowed 
//if balance is going negative. Write functions for withdraw and deposit) D means deposit while W means 
//withdrawal. Suppose the following input is supplied to the program: D 300, D 300, W 200, D 100. Then, 
//the output should be: 500


Accountbalance = 10000
a = int(input("Enter amount:"))
balance = str(input("Press D for deposit and W for withdraw:"))

if balance == "D":
    Accountbalance = Accountbalance + a
    print("Current Account balance is:", Accountbalance)

elif balance == "W":
    if Accountbalance >= a:
        c = Accountbalance - a
        print("Balance amount is:", c)
    else:
        print("Insufficient balance:", Accountbalance)

else:
    print("Invalid operation")


//  Write a Python program to compute following computation on matrix:
//a) Addition of two matrices 
//B) Subtraction of two matrices
//c) Multiplication of two matrices 
//d) Transpose of a matrix

def Addition(r, c, m, m1):
    print("Addition of two matrices using list comprehension:")
    print([[(m[i][j] + m1[i][j]) for j in range(c)] for i in range(r)])

    print("Addition of two matrices without using list comprehension:")
    for i in range(r):
        for j in range(c):
            print(m[i][j] + m1[i][j], end=" ")
        print()

def Subtraction(r, c, m, m1):
    print("Subtraction of two matrices using list comprehension:")
    print([[(m[i][j] - m1[i][j]) for j in range(c)] for i in range(r)])

    print("Subtraction of two matrices without using list comprehension:")
    for i in range(r):
        for j in range(c):
            print(m[i][j] - m1[i][j], end=" ")
        print()

def Transpose(r, c, m):
    print("Transpose of 1st matrix using list comprehension:")
    print([[(m[i][j]) for j in range(c)] for i in range(r)])

    print("Transpose of 1st matrix without using list comprehension:")
    for i in range(r):
        for j in range(c):
            print(m[j][i], end=" ")
        print()

def Transpose1(r, c, m1):
    print("Transpose of 2nd matrix using list comprehension:")
    print([[(m1[i][j]) for j in range(c)] for i in range(r)])

    print("Transpose of 2nd matrix without using list comprehension:")
    for i in range(r):
        for j in range(c):
            print(m1[j][i], end=" ")
        print()

def Multiplication(r, c, m, m1):
    print("Multiplication of matrices using list comprehension:")

    if r == c:
        for i in range(r):
            for j in range(c):
                sum = 0
                for k in range(c):
                    sum = sum + (m[i][k] * m1[k][j])
                print(sum, end=" ")

            print()
    else:
        print("Operation invalid")

# Main program
m = []
r = int(input("Enter the number of rows:"))
c = int(input("Enter the number of columns:"))

for i in range(r):
    a = []
    for j in range(c):
        ele = int(input("Enter elements:"))
        a.append(ele)
    m.append(a)

print("1st matrix is:")
for i in range(r):
    for j in range(c):
        print(m[i][j], end=" ")
    print()

m1 = []
for i in range(r):
    a = []
    for j in range(c):
        ele = int(input("Enter elements:"))
        a.append(ele)
    m1.append(a)

print("2nd matrix is:")
for i in range(r):
    for j in range(c):
        print(m1[i][j], end=" ")
    print()

i = 1
while i <= 6:
    print("Please press 1 for matrix addition;")
    print("Please press 2 for matrix subtraction:")
    print("Please press 3 for transpose of matrix 1:")
    print("Please press 4 for transpose of matrix 2:")
    print("Please press 5 for multiplication of matrix:")
    print("Please press 6 for none:")
    opt = int(input("Enter your choice:"))
    
    match opt:
        case 1:
            add = Addition(r, c, m, m1)
            print("Addition is:", add)

        case 2:
            sub = Subtraction(r, c, m, m1)
            print("Subtraction is:", sub)

        case 3:
            trp = Transpose(r, c, m)
            print("Transpose of 1st matrix is:", trp)

        case 4:
            trp1 = Transpose1(r, c, m1)
            print("Transpose of 2nd matrix is:", trp1)

        case 5:
            mlt = Multiplication(r, c, m, m1)
            print("Multiplication of matrix is:", mlt)

        case 6:
            print("You opted for none!")




//Write a Python program to store first year percentage of students in array. 
//Write function for sorting array of floating point numbers in ascending order 
//using
//a) Selection Sort
//b) Bubble sort and display top five scores

def Bubble(a, n): 
    for i in range(n): 
        for j in range(0, n-i-1): 
            if a[j] > a[j+1]: 
                temp = a[j] 
                a[j] = a[j+1] 
                a[j+1] = temp 
    
    for i in range(n): 
        print("The sorted list using bubble sort is:", a[i]) 
    return a

def Selection(a, n): 
    for i in range(n): 
        min = i 
        for j in range(i+1, n): 
            if a[j] < a[min]: 
                min = j 
        
        temp = a[i] 
        a[i] = a[min] 
        a[min] = temp 
    
    for i in range(n): 
        print("The sorted list using selection sort is:", a[i]) 
    return a

# Main program
a = [] 
n = int(input("Enter number of elements you want in list:")) 

for i in range(n): 
    m = float(input("Enter elements:")) 
    a.append(m)

s = 1 
while s <= 3: 
    print("Please press '1' for bubble sort:")
    print("Please press '2' for selection sort:")
    print("Please press '3' for none:")
    
    opt = int(input("Enter your choice: ")) 
    
    match opt: 
        case 1: 
            bubl = Bubble(a, n)
        case 2: 
            selt = Selection(a, n)
        case 3: 
            print("You opted for none")



//Write a Python program to store second year percentage of students in array. 
//Write function for sorting array of floating point numbers in ascending order 
//using
//a) Insertion sort
//b) Shell Sort and display top five scores

def Insertion(a, n): 
    for i in range(1, n):  # Start from index 1 as the first element is already sorted
        temp = a[i] 
        j = i - 1 
        while j >= 0 and a[j] > temp: 
            a[j + 1] = a[j] 
            j = j - 1 

        a[j + 1] = temp 

    print("The sorted list using insertion sort is:",)
    for i in range(n): 
        print(a[i]) 

def ShellSort(a, n): 
    d = n // 2 
    while d > 0: 
        for i in range(d, n): 
            temp = a[i] 
            j = i 
            while j >= d and a[j - d] > temp: 
                a[j] = a[j - d] 
                j = j - d 

            a[j] = temp 
        d //= 2  # Reduce gap size
    
    print("The sorted list using shell sort is:",)
    for i in range(n): 
        print(a[i]) 

# Main program
a = [] 
n = int(input("Enter number of elements you want in list:")) 

for i in range(n): 
    m = float(input("Enter elements:")) 
    a.append(m) 

s = 1 
while s <= 3: 
    print("Please press '1' for insertion sort:")
    print("Please press '2' for shell sort:")
    print("Please press '3' for none:")
    
    opt = int(input("Enter your choice: ")) 
    
    match opt: 
        case 1: 
            inst = Insertion(a, n)
        case 2: 
            shell = ShellSort(a, n)
        case 3: 
            print("You opted for none.")
 


//Write a python program to store first year percentage of students in array. 
//Write function for sorting array of floating point numbers in ascending order 
//using quick sort and display top five scores.     

def quickSort(arr,low,high):        # It takes array,lowest index and highest index as parameters
    if low<high:
        pivot_index = partition(arr,low,high)
        quickSort(arr,low,pivot_index - 1)
        quickSort(arr,pivot_index + 1,high)

def partition(arr,low,high):
    pivot = arr[high]
    i = low - 1
    for j in range(low,high):
        if arr[j]<=pivot:
            i+=1
            arr[i],arr[j] = arr[j],arr[i]
    arr[i+1],arr[high] = arr[high],arr[i+1]
    return i+1

arr = []
n=int(input("Enter the number of elements to be inserted : "))
for i in range(n):
    val=int(input("Enter the elements to be inserted : "))
    arr.append(val)

print("Before Sorting : ",arr)

quickSort(arr,0,len(arr)-1)

print("After sorting : ",arr)



//Department of Computer Engineering has student's club named 'Pinnacle Club'. 
//Students of second, third and final year of department can be granted 
//membership on request. Similarly one may cancel the membership of club. First 
//node is reserved for president of club and last node is reserved for secretary of 
//club. Write C++ program to maintain club member‘s information using singly 
//linked list. Store student PRN and Name. Write functions to: 
//a) Add and delete the members as well as president or even secretary. 
//b) Compute total number of members of club
//c) Display members 
//d) Two linked lists exists for two divisions. Concatenate two lists

#include <iostream>
#include <string>
using namespace std;

struct Node {
    int prn;
    string name;
    Node* next;
};

class PinnacleClub {
private:
    Node* head;
    Node* tail;

public:
    PinnacleClub() : head(nullptr), tail(nullptr) {}

    // Function to add a member
    void addMember(int prn, const string& name, bool isPresident = false, bool isSecretary = false) {
        Node* newNode = new Node{prn, name, nullptr};

        if (isPresident) {
            newNode->next = head;
            head = newNode;
            if (tail == nullptr) tail = head; // First member is both president and secretary.
        } else if (isSecretary) {
            if (tail != nullptr) {
                tail->next = newNode;
                tail = newNode;
            } else {
                head = tail = newNode; // First member is both president and secretary.
            }
        } else {
            if (head == nullptr) {
                head = tail = newNode; // First member
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        }
    }

    // Function to delete a member
    void deleteMember(int prn) {
        if (head == nullptr) {
            cout << "No members in the club to delete.\n";
            return;
        }

        if (head->prn == prn) { // Deleting the president
            Node* temp = head;
            head = head->next;
            delete temp;
            if (head == nullptr) tail = nullptr; // List becomes empty
            return;
        }

        Node* current = head;
        while (current->next != nullptr && current->next->prn != prn) {
            current = current->next;
        }

        if (current->next == nullptr) {
            cout << "Member with PRN " << prn << " not found.\n";
        } else {
            Node* temp = current->next;
            current->next = temp->next;
            if (temp == tail) tail = current; // Deleting the secretary
            delete temp;
        }
    }

    // Function to compute total number of members
    int countMembers() const {
        int count = 0;
        Node* current = head;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }

    // Function to display all members
    void displayMembers() const {
        if (head == nullptr) {
            cout << "No members in the club.\n";
            return;
        }

        Node* current = head;
        cout << "Club Members:\n";
        while (current != nullptr) {
            cout << "PRN: " << current->prn << ", Name: " << current->name << "\n";
            current = current->next;
        }
    }

    // Function to concatenate another club list
    void concatenate(PinnacleClub& other) {
        if (head == nullptr) {
            head = other.head;
            tail = other.tail;
        } else if (other.head != nullptr) {
            tail->next = other.head;
            tail = other.tail;
        }
        other.head = nullptr;
        other.tail = nullptr;
    }

    // Destructor to clean up memory
    ~PinnacleClub() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
};

int main() {
    PinnacleClub divisionA;
    PinnacleClub divisionB;

    // Adding members to Division A
    divisionA.addMember(1, "Alice", true); // President
    divisionA.addMember(2, "Bob");
    divisionA.addMember(3, "Charlie", false, true); // Secretary

    // Adding members to Division B
    divisionB.addMember(4, "David", true); // President
    divisionB.addMember(5, "Eve");
    divisionB.addMember(6, "Frank", false, true); // Secretary

    // Display members of both divisions
    cout << "Division A:\n";
    divisionA.displayMembers();
    cout << "\nDivision B:\n";
    divisionB.displayMembers();

    // Concatenate Division B into Division A
    divisionA.concatenate(divisionB);
    cout << "\nAfter concatenation, Division A:\n";
    divisionA.displayMembers();

    // Total members in Division A
    cout << "\nTotal members in Division A: " << divisionA.countMembers() << "\n";

    // Delete a member
    divisionA.deleteMember(2); // Deleting Bob
    cout << "\nAfter deleting Bob, Division A:\n";
    divisionA.displayMembers();

    return 0;
}

Write C++ program for storing binary number using doubly linked lists. Write
functions
a) to compute 1„s and 2„s complement
b) add two binary numberS

#include <iostream>
#include <string>

struct Node {
    char bit;
    Node* next;
    Node* prev;
    Node(char b) : bit(b), next(nullptr), prev(nullptr) {}
};

class BinaryNumber {
private:
    Node* head;
    Node* tail;

public:
    BinaryNumber() : head(nullptr), tail(nullptr) {}

    void append(char bit) {
        Node* newNode = new Node(bit);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void display() {
        Node* current = head;
        while (current) {
            std::cout << current->bit;
            current = current->next;
        }
        std::cout << std::endl;
    }

    BinaryNumber onesComplement() {
        BinaryNumber result;
        Node* current = head;
        while (current) {
            result.append(current->bit == '0' ? '1' : '0');
            current = current->next;
        }
        return result;
    }

    BinaryNumber twosComplement() {
        BinaryNumber onesComp = onesComplement();
        BinaryNumber result;
        Node* current = onesComp.tail;
        int carry = 1;
        while (current || carry) {
            char bit = (current ? current->bit : '0') - '0' + carry;
            // Convert char to int and add carry
            if (bit == 2) {
                result.append('0');
                carry = 1;
            } else {
                result.append('1' - bit); // Convert back to char
                carry = 0;
            }
            if (current) current = current->prev;
        }
        // Reverse result to get the correct order
        return reverse(result);
    }

    BinaryNumber reverse(const BinaryNumber& num) {
        BinaryNumber reversed;
        Node* current = num.tail;
        while (current) {
            reversed.append(current->bit);
            current = current->prev;
        }
        return reversed;
    }

    BinaryNumber add(const BinaryNumber& other) {
        BinaryNumber result;
        Node* current1 = tail;
        Node* current2 = other.tail;
        int carry = 0;
        while (current1 || current2 || carry) {
            int sum = carry;
            if (current1) {
                sum += current1->bit - '0'; // Convert char to int
                current1 = current1->prev;
            }
            if (current2) {
                sum += current2->bit - '0'; // Convert char to int
                current2 = current2->prev;
            }
            result.append((sum % 2) + '0'); // Convert back to char
            carry = sum / 2;
        }
        return reverse(result);
    }

    ~BinaryNumber() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    BinaryNumber bin1, bin2;

    // Input first binary number
    std::string input1;
    std::cout << "Enter first binary number: ";
    std::cin >> input1;
    for (char bit : input1) {
        bin1.append(bit);
    }

    // Input second binary number
    std::string input2;
    std::cout << "Enter second binary number: ";
    std::cin >> input2;
    for (char bit : input2) {
        bin2.append(bit);
    }

    // Display binary numbers
    std::cout << "First Binary Number: ";
    bin1.display();
    std::cout << "Second Binary Number: ";
    bin2.display();

    // Compute and display 1's and 2's complement
    std::cout << "1's Complement of first binary number: ";
    bin1.onesComplement().display();
    std::cout << "2's Complement of first binary number: ";
    bin1.twosComplement().display();

    // Add binary numbers and display result
    std::cout << "Sum of two binary numbers: ";
    bin1.add(bin2).display();

    return 0;
}


//Implement C++ program for expression conversion as infix to postfix and its 
//evaluation using stack based on given conditions:
//1. Operands and operator, both must be single character.
//2. Input Postfix expression must be in a desired format.
//3. Only '+', '-', '*' and '/ ' operators are expected.

#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <cmath>

using namespace std;

// Function to determine precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Function to check if a character is an operator
bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

// Function to convert infix to postfix
string infixToPostfix(const string& infix) {
    stack<char> s;
    string postfix;

    for (char ch : infix) {
        // If the character is an operand, add it to postfix
        if (isalnum(ch)) {
            postfix += ch;
        }
        // If the character is '(', push it onto the stack
        else if (ch == '(') {
            s.push(ch);
        }
        // If the character is ')', pop and add to postfix until '(' is encountered
        else if (ch == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop(); // Remove '('
        }
        // If the character is an operator
        else if (isOperator(ch)) {
            while (!s.empty() && precedence(s.top()) >= precedence(ch)) {
                postfix += s.top();
                s.pop();
            }
            s.push(ch);
        }
    }

    // Pop all remaining operators from the stack
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

// Function to evaluate a postfix expression
int evaluatePostfix(const string& postfix) {
    stack<int> s;

    for (char ch : postfix) {
        // If the character is a digit, push it onto the stack
        if (isdigit(ch)) {
            s.push(ch - '0'); // Convert char to int
        }
        // If the character is an operator, pop two elements and apply the operator
        else if (isOperator(ch)) {
            if (s.size() < 2) {
                cerr << "Error: Insufficient operands in the expression!" << endl;
                return -1; // Error value
            }
            int b = s.top(); s.pop();
            int a = s.top(); s.pop();
            switch (ch) {
                case '+': s.push(a + b); break;
                case '-': s.push(a - b); break;
                case '*': s.push(a * b); break;
                case '/': 
                    if (b == 0) {
                        cerr << "Error: Division by zero!" << endl;
                        return -1; // Error value
                    }
                    s.push(a / b); break;
            }
        }
    }

    if (s.size() != 1) {
        cerr << "Error: Invalid postfix expression!" << endl;
        return -1; // Error value
    }
    
    return s.top(); // The final result
}

int main() {
    string infix;

    cout << "Enter an infix expression: ";
    cin >> infix;

    // Convert infix to postfix
    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;

    // Evaluate the postfix expression
    int result = evaluatePostfix(postfix);
    if (result != -1) {
        cout << "Evaluation result: " << result << endl;
    }

    return 0;
}


//In any language program mostly syntax error occurs due to unbalancing 
//delimiter such as (),{},[]. Write C++ program using stack to check whether 
//given expression is well parenthesized or not


#include <iostream>
#include <stack>
#include <string>

bool isWellParenthesized(const std::string& expression) {
    std::stack<char> s;
    for (char ch : expression) {
        // Push opening brackets onto the stack
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        }
        // Check for closing brackets
        else if (ch == ')' || ch == '}' || ch == ']') {
            // If stack is empty or top doesn't match, it's unbalanced
            if (s.empty()) return false;
            char top = s.top();
            s.pop();
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false;
            }
        }
    }
    // In the end, the stack should be empty if well-parenthesized
    return s.empty();
}

int main() {
    std::string expression;

    std::cout << "Enter an expression: ";
    std::getline(std::cin, expression);

    if (isWellParenthesized(expression)) {
        std::cout << "The expression is well-parenthesized." << std::endl;
    } else {
        std::cout << "The expression is not well-parenthesized." << std::endl;
    }

    return 0;
}


//Queues are frequently used in computer programming, and a typical example 
//is the creation of a job queue by an operating system. If the operating system 
//does not use priorities, then the jobs are processed in the order they enter the 
//system. Write C++ program for simulating job queue. Write functions to add 
//job and delete job from queue.


#include <iostream>
#include <queue>
#include <string>

using namespace std;

// Job structure to represent a job in the queue
struct Job {
    int jobId;
    string jobName;

    // Constructor to initialize the job
    Job(int id, string name) : jobId(id), jobName(name) {}
};

// Function to add a job to the queue
void addJob(queue<Job>& jobQueue, int jobId, const string& jobName) {
    // Create a new job and push it to the queue
    Job newJob(jobId, jobName);
    jobQueue.push(newJob);
    cout << "Job added: " << newJob.jobId << " - " << newJob.jobName << endl;
}

// Function to delete a job from the queue
void deleteJob(queue<Job>& jobQueue) {
    if (!jobQueue.empty()) {
        // Get the job from the front of the queue
        Job job = jobQueue.front();
        jobQueue.pop();  // Remove the job from the queue
        cout << "Job deleted: " << job.jobId << " - " << job.jobName << endl;
    } else {
        cout << "No jobs to delete. The queue is empty!" << endl;
    }
}

// Function to display the jobs in the queue
void displayQueue(const queue<Job>& jobQueue) {
    if (jobQueue.empty()) {
        cout << "The queue is empty!" << endl;
        return;
    }
    queue<Job> tempQueue = jobQueue;  // Create a copy of the queue for display
    cout << "Jobs in the queue:" << endl;
    while (!tempQueue.empty()) {
        Job job = tempQueue.front();
        cout << job.jobId << " - " << job.jobName << endl;
        tempQueue.pop();
    }
}

int main() {
    queue<Job> jobQueue;  // Create an empty queue of jobs
    int choice, jobId;
    string jobName;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add Job to Queue\n";
        cout << "2. Delete Job from Queue\n";
        cout << "3. Display Jobs in Queue\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                // Adding a job
                cout << "Enter job ID: ";
                cin >> jobId;
                cout << "Enter job name: ";
                cin.ignore(); // to clear the newline character in the input buffer
                getline(cin, jobName);
                addJob(jobQueue, jobId, jobName);
                break;

            case 2:
                // Deleting a job
                deleteJob(jobQueue);
                break;

            case 3:
                // Displaying the jobs in the queue
                displayQueue(jobQueue);
                break;

            case 4:
                cout << "Exiting the program.\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
                break;
        }
    } while (choice != 4);

    return 0;
}

//A double-ended queue (deque) is a linear list in which additions and deletions may 
//be made at either end. Obtain a data representation mapping a deque into a 
//onedimensional array. Write C++ program to simulate deque with functions to add 
//and delete elements from either end of the deque.

#include <iostream>
using namespace std;

class Deque {
private:
    int* arr;       // Dynamic array to store deque elements
    int front;      // Front pointer
    int rear;       // Rear pointer
    int capacity;   // Maximum capacity of deque
    int size;       // Current size of deque

public:
    // Constructor to initialize the deque
    Deque(int cap) {
        capacity = cap;
        arr = new int[capacity];  // Allocate memory for the deque
        front = -1;
        rear = -1;
        size = 0;
    }

    // Destructor to free dynamically allocated memory
    ~Deque() {
        delete[] arr;
    }

    // Function to check if deque is full
    bool isFull() {
        return size == capacity;
    }

    // Function to check if deque is empty
    bool isEmpty() {
        return size == 0;
    }

    // Add an element at the front of deque
    void insertFront(int value) {
        if (isFull()) {
            cout << "Deque is full. Cannot insert at the front." << endl;
            return;
        }

        if (front == -1) { // Deque is empty
            front = rear = 0;
        } else {
            front = (front - 1 + capacity) % capacity; // Circular increment
        }

        arr[front] = value;
        size++;
    }

    // Add an element at the rear of deque
    void insertRear(int value) {
        if (isFull()) {
            cout << "Deque is full. Cannot insert at the rear." << endl;
            return;
        }

        if (rear == -1) { // Deque is empty
            front = rear = 0;
        } else {
            rear = (rear + 1) % capacity; // Circular increment
        }

        arr[rear] = value;
        size++;
    }

    // Delete an element from the front of deque
    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque is empty. Cannot delete from the front." << endl;
            return;
        }

        if (front == rear) { // Only one element
            front = rear = -1;
        } else {
            front = (front + 1) % capacity; // Circular increment
        }

        size--;
    }

    // Delete an element from the rear of deque
    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque is empty. Cannot delete from the rear." << endl;
            return;
        }

        if (front == rear) { // Only one element
            front = rear = -1;
        } else {
            rear = (rear - 1 + capacity) % capacity; // Circular decrement
        }

        size--;
    }

    // Get the element at the front of deque
    int getFront() {
        if (isEmpty()) {
            cout << "Deque is empty." << endl;
            return -1;
        }
        return arr[front];
    }

    // Get the element at the rear of deque
    int getRear() {
        if (isEmpty()) {
            cout << "Deque is empty." << endl;
            return -1;
        }
        return arr[rear];
    }

    // Display the elements of the deque
    void display() {
        if (isEmpty()) {
            cout << "Deque is empty." << endl;
            return;
        }

        cout << "Deque elements: ";
        for (int i = front; i != rear; i = (i + 1) % capacity) {
            cout << arr[i] << " ";
        }
        cout << arr[rear] << endl;
    }
};

int main() {
    Deque dq(5);  // Create a deque of capacity 5

    // Insert elements at the front
    dq.insertFront(10);
    dq.insertFront(20);
    dq.insertFront(30);

    // Insert elements at the rear
    dq.insertRear(40);
    dq.insertRear(50);

    // Display the deque
    dq.display();

    // Get front and rear elements
    cout << "Front element: " << dq.getFront() << endl;
    cout << "Rear element: " << dq.getRear() << endl;

    // Delete elements from the front
    dq.deleteFront();
    dq.deleteFront();

    // Display the deque after deletions
    dq.display();

    // Delete elements from the rear
    dq.deleteRear();
    dq.deleteRear();

    // Display the deque after deletions
    dq.display();

    return 0;
}


//Pizza parlor accepting maximum M orders. Orders are served in first come 
//first served basis. Order once placed cannot be cancelled. Write C++ program 
//to simulate the system using circular queue using array.

#include <iostream>
#include <string>

using namespace std;

class CircularQueue {
private:
    string* orders; // Array to store orders
    int front;           // Index to the front of the queue
    int rear;            // Index to the rear of the queue
    int capacity;        // Maximum capacity of the queue
    int size;            // Current number of orders in the queue

public:
    // Constructor to initialize the queue
    CircularQueue(int cap) {
        capacity = cap;
        orders = new string[capacity];
        front = -1;
        rear = -1;
        size = 0;
    }

    // Destructor to free memory
    ~CircularQueue() {
        delete[] orders;
    }

    // Function to place an order
    void placeOrder(const string& order) {
        if (size == capacity) {
            cout << "Order queue is full. Cannot place more orders." << endl;
            return;
        }

        rear = (rear + 1) % capacity; // Circular increment of rear
        orders[rear] = order;

        if (front == -1) {
            front = rear; // Set front if it's the first order
        }

        size++;
        cout << "Order placed: " << order << endl;
    }

    // Function to serve an order
    void serveOrder() {
        if (size == 0) {
            cout << "No orders to serve." << endl;
            return;
        }

        cout << "Serving order: " << orders[front] << endl;
        front = (front + 1) % capacity; // Circular increment of front
        size--;

        if (size == 0) {
            front = -1; // Reset front and rear if no orders left
            rear = -1;
        }
    }

    // Function to display current orders
    void displayOrders() const {
        if (size == 0) {
            cout << "No current orders." << endl;
            return;
        }

        cout << "Current orders in the queue: ";
        for (int i = 0; i < size; i++) {
            cout << orders[(front + i) % capacity] << " ";
        }
        cout << endl;
    }
};

int main() {
    int capacity;
    cout << "Enter the maximum number of orders the pizza parlor can accept: ";
    cin >> capacity;

    CircularQueue orderQueue(capacity); // Create a circular queue for orders

    int choice;
    string order;

    do {
        cout << "\nPizza Parlor Menu:\n";
        cout << "1. Place Order\n";
        cout << "2. Serve Order\n";
        cout << "3. Display Current Orders\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter the order (pizza name): ";
            cin >> order;
            orderQueue.placeOrder(order);
            break;
        case 2:
            orderQueue.serveOrder();
            break;
        case 3:
            orderQueue.displayOrders();
            break;
        case 4:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}


