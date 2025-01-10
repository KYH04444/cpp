#include <iostream>
#include <cstring>

/*

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

std::shared_ptr // 공유 소유권 제공하는 포인터
    

*/