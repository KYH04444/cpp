/*
출처: https://gdngy.tistory.com/183

포인터 사용으로 발생할 수 있는 이슈들
    1. 메모리 누수 delete안함
    2. 아무것도 가리키지 않는 널 포인터(nullptr)
    3. 해제된 메모리 가리키는 포인터 접근하면 Dangling pointer 현상 발생

Smart pointer 4가지
    std::auto_ptr - Deprecated(사용 권장 안함), std::unique_ptr이 대체
    std::unique_ptr
    std::shared_ptr
    std::weak_ptr


std::unique_ptr // 유일한 포인터
    std::unique_ptr<int> ptr1(new int(5));
    std::unique_ptr<int> ptr2 = ptr1; // Error 

    std::unique_ptr<int> ptr1(new int(5));
    std::unique_ptr<int> ptr2 = std::move(ptr1); // 다음과 같이 소유권을 이전, unique_ptr이 자원의 유일한 소유자임을 보장

    자주 쓰이는 문법 std::move()

std::shared_ptr // 공유 소유권 제공하는 포인터 - 인스턴스가 동일 메모리 가리킬 수 있게 함
    std::shared_ptr<int> ptr1(new int(5)); //shared_ptr은 reference count 기능이 있음
    std::shared_ptr<int> ptr2 = ptr1;      // ptr2, ptr1 모두 같은 주소를 가리키고 ref cnt가 2가됨, 만약 ref cnt가 0이되면 메모리 해제됨
    
    자주 쓰이는 문법 std::make_shared, std::use_count()
    std::shared_ptr<MyClass> sp = std::make_shared<MyClass>();
    sp->ptr = sp;

    std::use_count check하고 0되면 메모리 자동으로 해제

std::weak_ptr // 약한 참조 제공 - 스마트포인터가 순환 참조와 같은 문제가 발생할 때 도움을 줌
    *순환 참조: 참조하는 대상이 서로 물려있어 참조할 수 없게 되는 상황 (Circular reference)

    sutrect B;
    struct A {
        std::shared_ptr<B> b_ptr;
    };

    sutrect B {
        std::shared_ptr<A> a_ptr;
    };

    std::shared_ptr<A> a(new A());
    std::shared_ptr<B> b(new B());

    a->b_ptr = b;
    b->a_ptr = a; // 순환 참조 발생, ref cnt가 절대 0이 되지 않아 smart pointer가 알아서 해제되지 않고 메모리 누수 발생

    <weak_ptr 사용>
        sutrect B;
        struct A {
            std::shared_ptr<B> b_ptr;
        };

        sutrect B {
            std::weak_ptr<A> a_ptr;
        };

        std::shared_ptr<A> a(new A());
        std::shared_ptr<B> b(new B());

        a->b_ptr = b;
        b->a_ptr = a; // A가 파괴되면 std::weak_ptr은 자동으로 해제됨

    자주 쓰이는 문법 std::lock(), std::expired()
*/

s