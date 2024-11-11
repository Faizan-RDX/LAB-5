#include <iostream>
#include <string>
using namespace std;
class Student {
public:
	string name;
	int score;
	int timeTaken;
	Student(string n = "", int s = 0, int t = 0) : name(n), score(s), timeTaken(t) {}

	void display() {
		cout << "Name: " << name << ", Score: " << score << ", Time Taken: " << timeTaken << " seconds" << endl;
	}
};

class Queue {
private:
	Student arr[10]; 
	int front, rear, currentSize;

public:
	Queue() : front(0), rear(-1), currentSize(0) {}

	
	void enqueue(Student student) {
		if (isFull()) {
			cout << "Queue is full!" << endl;
		}
		else {
			rear = (rear + 1) % 10; 
			arr[rear] = student;
			currentSize++;
		}
	}

	
	Student dequeue() {
		if (isEmpty()) {
			cout << "Queue is empty!" << endl;
			return Student(); 
		}
		else {
			Student student = arr[front];
			front = (front + 1) % 10;  
			currentSize--;
			return student;
		}
	}

	Student peek() {
		if (isEmpty()) {
			cout << "Queue is empty!" << endl;
			return Student();
		}
		else {
			return arr[front];
		}
	}

	bool isFull() {
		return currentSize == 10; 
	}

	bool isEmpty() {
		return currentSize == 0;
	}
	int size() {
		return currentSize;
	}
};
int simpleRand() {
     int seed = 42; 
	seed = (seed * 37 + 13) % 100;
	return seed;
}

int main() {

	Queue waitingQueue;
	Queue completedQueue;

	int choice;
	string name;

	do {

		cout << "--------------------Menu---------------------------------" << endl;
		cout << "1. Add student to waiting queue" << endl;
		cout << "2. Start  quiz and generate scores" << endl;
		cout << "3. Display the scores, name, and time taken by the students" << endl;
		cout << "4. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
	
			cout << "Enter student's name: ";
			cin >> name;
			waitingQueue.enqueue(Student(name));
			cout << "Student " << name << " added to the waiting queue." << endl;
			break;

		case 2:

			if (waitingQueue.isEmpty()) {
				cout << "No students in the queue!" << endl;
			}
			else {
				cout << "Quiz started..." << endl;
				while (!waitingQueue.isEmpty()) {
					Student student = waitingQueue.dequeue();

	
					student.score = simpleRand() % 101;  
					student.timeTaken = simpleRand() % 111 + 10;

					completedQueue.enqueue(student); 
				}
				cout << "Quiz ended. All students have completed the quiz." << endl;
			}
			break;

		case 3:

			if (completedQueue.isEmpty()) {
				cout << "No students have completed the quiz yet!" << endl;
			}
			else {
				cout << "\nCompleted Students:\n";
				while (!completedQueue.isEmpty()) {
					Student student = completedQueue.dequeue();
					student.display();
				}
			}
			break;

		case 4:
			cout << "Exiting program..." << endl;
			break;

		default:
			cout << "Invalid choice! Please try again." << endl;
		}
	} while (choice != 4);

	return 0;
}
