#pragma once
#ifdef WINNT
#include <ntifs.h>
#endif

namespace krnlib {
namespace details {
#ifdef WINNT
    // �ڴ��������
    constexpr POOL_TYPE kAllocPoolType = PagedPool;
    // �ڴ����Tag
    constexpr ULONG kAllocPoolTag = 'mMuF';
#endif // WINNT
}
}