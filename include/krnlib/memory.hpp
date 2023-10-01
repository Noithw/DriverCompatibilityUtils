#pragma once
#if _MSVC_LANG >= 202002L
#pragma message("WARNING: There's no need to use this hpp file in C++20. You can directly use the standard library!")
#endif
#ifdef WINNT
#include <ntifs.h>
#endif
#include <memory>

namespace krnlib {
/**
 * @brief ����ָ�������Ķ����ڴ�(sizeof(T) * count)
 * @tparam T ��������
 * @param count ����
*/
template<class T>
inline T* Allocate(size_t count) {
    return (T*)operator new(sizeof(T) * count);
}

/**
 * @brief �ͷ��ڴ�
 * @param ptr Ҫ�ͷŵ��ڴ�
*/
inline void Deallocate(void* ptr) {
    operator delete(ptr);
}

/**
 * @brief ��һ���ڴ������������
 * @tparam T ��������
*/
template<class T>
inline void Destroy(T* ptr) {
    ptr->~T();
}
}