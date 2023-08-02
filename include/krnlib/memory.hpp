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
 * @return �ڴ�
*/
template<class T>
inline T* Allocate(size_t count) {
    return (T*)operator new(std::_Get_size_of_n<sizeof(T)>(count));
}

/**
 * @brief �ͷ��ڴ�
 * @param ptr Ҫ�ͷŵ��ڴ�
*/
inline void Deallocate(void* ptr) {
    operator delete(ptr);
}

/**
 * @brief ��һ���ڴ���ù��캯��
 * @tparam T ��������
 * @param ptr Ŀ���ڴ�
 * @param args ���캯������
 * @return Ŀ���ڴ�
*/
template<class T, class... ArgsT>
inline T* Construct(T* ptr, ArgsT&&... args) {
    return ::new(std::_Voidify_iter(ptr)) T(std::forward<ArgsT>(args)...);
}

/**
 * @brief ��һ���ڴ������������
 * @tparam T ��������
 * @param ptr Ŀ���ڴ�
*/
template<class T>
inline void Destroy(T* ptr) {
    ptr->~T();
}
}