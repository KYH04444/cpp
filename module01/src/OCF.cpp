/*********************************************************
				2025.01.08
				Yonghee Kim 

				module01 what is the OCF
**********************************************************/
#include <iostream>

class MyClass {
public:
    int* data;

    // 기본 생성자
    MyClass(int value = 0) {
        data = new int(value);
        std::cout << "기본 생성자 호출" << std::endl;
    }

    // 복사 생성자
    MyClass(const MyClass& other) {
        data = new int(*other.data);  // 깊은 복사
        std::cout << "복사 생성자 호출" << std::endl; 
    }

    /*
    Myclass cls1(10);  기본 생성자로 새로운 object 생성
    Myclass cls2 = cls1;  복사 생성자로 깊은 복사 진행 (독립적인 cls생성)
    만약 복사 생성자가 없다면 cls1과 cls2가 같아짐 cls1 data에 접근하여 값을 변경하면 cls2의 data값도 같이 변경됨
    복사 생성자를 사용하면 cls1의 data를 변경하더라도 cls2의 데이터는 변경되지 않음

    *cls2.data = 20
    cls1.data = 10
    cls2.data = 20으로 나온다

    즉 각 객체가 자신의 자원을 소유해서 독립적인 객체로 나뉘게 된다
    */ 

    // 복사 대입 연산자
    MyClass& operator=(const MyClass& other) {
        if (this == &other) {  // 자기 대입 방지
            std::cout << "자기 대입 방지" << std::endl;
            return *this;
        }

        delete data;  // 기존 자원 해제
        data = new int(*other.data);  // 깊은 복사
        std::cout << "복사 대입 연산자 호출" << std::endl;

        return *this;
    }
    /*
    복사 대입 연산자는 기존의 객체에 다른 객체로부터 값을 대입할 때 사용
    이미 생성된 객체에서 이미 할당된 자원을 해제하고 새롭게 생성된다는 것이 의의
    Myclass cls1(10);
    Myclass cls2(20);

    cls2 = cls1;
    cls1.data = 10
    cls2.data = 20으로 나옴 

    복사 대입 연산자는 일반적으로 자기 대입 방지를 위한 코드가 들어감    
    
    if (this == &other) {  // 자기 대입 방지
        std::cout << "자기 대입 방지" << std::endl;
        return *this;
    }
    만약 cls1 = cls2;를 하게되면 새로운 자원을 할당하게 되는데 이러면 같은 데이터를 사용하지만 메모리를 2개 사용하게됨
    */


    /*
    깊은 복사를 하는 이유: 얕은 복사를 진행하면 두 객체가 같은 메모리 주소를 공유하게 됨 이는 곧 이중 해제 오류를 발생 시킴
    깊은 복사: 값 자체를 복사 이를 새로운 주소에 넣음
    얕은 복사: 같은 메모리 주소를 복사
    class ShallowCopy {
    public:
        int* data;

        ShallowCopy(int value) {
            data = new int(value);
        }

        // 얕은 복사: 기본 복사 대입 연산자 사용
        ~ShallowCopy() {
            delete data;
        }
    };    

    int main() {
        ShallowCopy obj1(10);
        ShallowCopy obj2(20);

        obj2 = obj1;  // 얕은 복사 발생

        *obj2.data = 30;
        std::cout << *obj1.data << std::endl;  // 예상: 10, 실제: 30 (같은 메모리를 참조)

        return 0;
    }   
   */

    // 소멸자
    ~MyClass() {
        delete data;
        std::cout << "소멸자 호출" << std::endl;
    }
};

int main() {
    MyClass obj1(10);  // 기본 생성자 호출
    MyClass obj2(20);  // 기본 생성자 호출

    obj2 = obj1;  // 복사 대입 연산자 호출
    std::cout << "obj1.data: " << *obj1.data << std::endl;  // 출력: 10
    std::cout << "obj2.data: " << *obj2.data << std::endl;  // 출력: 10

    return 0;
}
