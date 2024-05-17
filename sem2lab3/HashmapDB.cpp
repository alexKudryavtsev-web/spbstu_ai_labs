#include <iostream>
#include <string>

using namespace std;

enum Gender {
	Male,
	Female,
	Other
};


struct Entity {
	string name = "";
	int age;
	Gender gender;
	string post;
	double salary;

	Entity(int age, Gender gender, string post, double salary) : age(age), gender(gender), post(post), salary(salary) {}

	Entity() = default;

	Entity& operator =(const Entity& other) {
		if (!other.name.empty()) {
			name = other.name;
		}
		age = other.age;
		gender = other.gender;
		post = other.post;
		salary = other.salary;
		return *this;
	}
};

struct DB {
	Entity* elements;
	int capacity = 5;
	int size = 0;
	DB() :elements(new Entity[5]) {}

	int hash(const string& key) {
		int sum = 0;
		for (size_t i = 0; i != key.length(); ++i) {
			sum += key[i];
		}
		sum %= capacity;
		return sum;
	}

	void realloc() {
		if (size + 1 == capacity) {
			Entity* NewEl = new Entity[capacity * 2];
			for (int i = 0; i < capacity; i++) {
				NewEl[i] = elements[i];
			}
			delete[]elements;
			elements = std::move(NewEl);
			capacity *= 2;
		}
	}

	DB& operator=(const DB& other) {
		if (this == &other) {
			return *this;
		}
		size = other.size;
		capacity = other.capacity;
		elements = nullptr;
		elements = new Entity[capacity];
		for (int i = 0; i < capacity; i++) {
			elements[i] = other.elements[i];
		}
		return *this;
	}

	Entity& operator[](const string& LastName) {
		realloc();
		int hashed = hash(LastName);
		if (!elements[hashed].name.empty()) {
			int tmp = hashed;
			for (; !elements[tmp].name.empty(); tmp++) {
				if (tmp == capacity - 1)
					tmp = 0;
				if (elements[tmp].name == LastName)
					return elements[tmp];
			}
			elements[tmp].name = LastName;
			size++;
			return elements[tmp];
		}
		else {
			elements[hashed].name = LastName;
			size++;
			return elements[hashed];
		}

	}

	void del(const string& LastName) {
		int hashed = hash(LastName);
		if (elements[hashed].name == LastName) {
			elements[hashed].name.clear();
			size--;
		}
		else {
			for (size_t i = hashed + 1;; ++i) {
				if (i == capacity - 1)
					i = 0;
				if (i == hashed) {
					cout << "There is no such person\n";
					break;
				}
				if (elements[i].name == LastName) {
					elements[i].name.clear();
					break;
				}
			}
		}
	}

	friend ostream& operator<<(ostream& os, const DB& db) {
		for (int i = 0; i < db.capacity; i++) {
			if (!db.elements[i].name.empty()) {
				os << "NAME: " << db.elements[i].name << " Age: " << db.elements[i].age << " Gender: " << db.elements[i].gender << " Post: " << db.elements[i].post << " Salary: " << db.elements[i].salary << "\n";
			}
		}
	
		return os;
	}

};