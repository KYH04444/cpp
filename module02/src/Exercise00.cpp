/************************************************
				2025.01.10
				Yonghee Kim 

				module02 Hot to use smart pointer
**************************************************/
#include <iostream>
#include <cstring>
#include <memory>

// class uniquePtr {
// public:
// 	int *data;

// 	uniquePtr(int value) {
// 		std::cout << "Unique pointer start\n"; 
// 		data = new int(value);
// 	}

// 	void print() {
// 		std::cout << "Unique pointer data: " << *data;
// 	}

// 	~ uniquePtr() {
// 		std::cout << "Unique pointer end\n";
// 		delete data;
// 	}
	
// };

// class sharedPtr {
// public:
// 	int *data;

// 	sharedPtr(int value){
// 		std::cout << "Shared pointer start\n";
// 		data = new int(value);
// 	}

// 	void print() {
// 		std::cout << "Sared pointer data: " << *data;
// 	}

// 	~sharedPtr() {
// 		std::cout << "Sared pointer end\n";
// 		delete data;
// 	}
// };

// class WeakPtr {
// public:
// 	int *data;
// 	WeakPtr(int value) {
// 		std::cout << "Weak pointer start\n";
// 		data = new int(value);
// 	}

// 	void print() {
// 		std::cout <<"Weak pointer data: " << *data; 
// 	}

// 	~WeakPtr() {
// 		std::cout << "Weak pointer end\n";
// 		delete data;
// 	}
// };

int main(int argc, char* argv[]) {
	std::string unique("unique");
	std::string shared("shared");
	std::string weak("weak");
	// std::string nullCommand;
	if(argc == 1) {
		std::cout << "Choose the one below  \n ./smtPtr unique\n ./smtPtr shared\n ./smtPtr weak\n";
	}

	else if(!strcmp(argv[1],"unique")) {
		std::unique_ptr<std::string> uniPtr1  = std::make_unique<std::string>("No.1 pointer");
		std::cout << "Unique pointer 1: " << *uniPtr1 << std::endl;
		std::unique_ptr<std::string> uniPtr2 = std::move(uniPtr1);
		std::cout << "Unique pointer is moved from pointer 1 to pointer 2.\n";
		std::cout << "Unique pointer 2: " << *uniPtr2 << std::endl;
		std::cout << "Unique pointer 1 is removed.\n";
	}

	else if(!strcmp(argv[1],"shared")) {
		std::shared_ptr<std::string> sharedPtr1 (new std::string("No.1 pointer"));
		std::cout << "Shared pointer 1: " <<*sharedPtr1 << std::endl;
		std::cout << "Pointer count: " << sharedPtr1.use_count() << std::endl;

		std::shared_ptr<std::string> sharedPtr2 = sharedPtr1;
		std::cout << "Shared pointer 2: " <<*sharedPtr2 << std::endl;
		std::cout << "Pointer count: " << sharedPtr1.use_count() << std::endl;

		std::shared_ptr<std::string> sharedPtr3 = sharedPtr1;
		std::cout << "Shared pointer 3: " <<*sharedPtr3 << std::endl;
		std::cout << "Pointer count: " << sharedPtr1.use_count() << std::endl;		

		std::cout << "pointer 1 adress: " << sharedPtr1 << std::endl;
		std::cout << "pointer 2 adress: " << sharedPtr2 << std::endl;
		std::cout << "pointer 3 adress: " << sharedPtr3 << std::endl;
	}

	else if(!strcmp(argv[1],"weak")) {
		class sharedPtrClsB;

		class sharedPtrClsA {
		public:
			std::shared_ptr<sharedPtrClsB> b_ptr;
		};

		class sharedPtrClsB {
		public:			
			std::shared_ptr<sharedPtrClsA> a_ptr;
		};



		std::shared_ptr<sharedPtrClsA> a(new sharedPtrClsA());
		std::shared_ptr<sharedPtrClsB> b(new sharedPtrClsB());
		
		std::cout << "-------------Before weak_ptr-------------\n";
		std::cout << "Shared pointer 1: " << a << std::endl;
		std::cout << "Shared pointer 2: " << b << std::endl;
		std::cout << "Pointer a count: " << a.use_count() << std::endl;		
		std::cout << "Pointer b count: " << b.use_count() << std::endl;		
		a->b_ptr = b;
		b->a_ptr = a;	

		std::cout << "Shared pointer 1: " << a << std::endl;
		std::cout << "Shared pointer 2: " << b << std::endl;

		std::cout << "Pointer a count: " << a.use_count() << std::endl;		
		std::cout << "Pointer b count: " << b.use_count() << std::endl;		


		class sharedPtrClsC {
		public:			
			std::weak_ptr<sharedPtrClsA> a_ptr;
		};

		std::shared_ptr<sharedPtrClsA> c(new sharedPtrClsA());
		std::shared_ptr<sharedPtrClsC> d(new sharedPtrClsC());
		
		std::cout << "-------------after weak_ptr-------------\n";
		std::cout << "Shared pointer 1: " << c << std::endl;
		std::cout << "Shared pointer 2: " << d << std::endl;
		std::cout << "Pointer a count: " << c.use_count() << std::endl;		
		std::cout << "Pointer b count: " << d.use_count() << std::endl;		
		c->b_ptr = b;
		d->a_ptr = a;	

		std::cout << "Shared pointer 1: " << c << std::endl;
		std::cout << "Shared pointer 2: " << d << std::endl;
		
		std::cout << "Pointer a count: " << c.use_count() << std::endl;		
		std::cout << "Pointer b count: " << d.use_count() << std::endl;		

	}

	return 0;
}
