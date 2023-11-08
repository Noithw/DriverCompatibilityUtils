#pragma once
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
template<typename T>
[[nodiscard]] inline T* Allocate(size_t count) {
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
template<typename T>
inline void Destroy(T* ptr) {
    ptr->~T();
}
}