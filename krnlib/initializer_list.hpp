/*
* ��Ϊ������������std::initializer_list���漰���ᷢ����ʽת���ĳ�ʼ��ʱ�ᱨ��(c++�������ͷ�ӿ϶����������˽����)
* �������Լ�ʵ����һ��ʹ�÷�����std::initializer_list����һ��������
* ����ȱ����ǲ������������ڱ����ھ�ȷ����ջ�еĴ�С, ����������ʱ��̬�ڶ��з����ڴ�
*/

#pragma once
#include <type_traits>
#include <utility>
#include <krnlib/memory.hpp>

namespace krnlib
{
namespace detail
{
/*
* InitListWrapper�����õݹ齫�ɱ�ģ��չ��, ������������ɶ��󱣴��뻺������
*
*   T                 Ҫ�������б���ɵĶ���
*   CurArgsSeek       ��������, ��ʶ��ǰ�ǲ����б��еĵڼ�������
*   Args              �����б�
*/
template<class T, size_t cur_args_idx, class... Args>
class InitListWrapper;
template<class T, size_t cur_args_idx>
class InitListWrapper<T, cur_args_idx> {
public:
    constexpr InitListWrapper(T* buffer) noexcept {}
};
template<class T, size_t cur_args_idx, class ThisArgT, class...RestArgsT>
class InitListWrapper<T, cur_args_idx, ThisArgT, RestArgsT...> : public InitListWrapper<T, cur_args_idx + 1, RestArgsT...>
{
public:
    using InheritedT = InitListWrapper<T, cur_args_idx + 1, RestArgsT...>;

    constexpr InitListWrapper(T* buffer, ThisArgT&& this_arg, RestArgsT&&... rest_args) :
        InheritedT(buffer, std::forward<RestArgsT>(rest_args)...)
    {
        /* ʹ��total���ڴ�, ����ǰ����total_begin�����T����*/
        Construct(&buffer[cur_args_idx], std::forward<ThisArgT>(this_arg));
    }
};
}
/*
* ģ��std::initializer_list
*/
template<class T>
class initializer_list
{
public:
    /*
    * ����һ���ɱ����ģ��, ����ģ���С�����ڴ�, Ȼ����InitListWrapper
    * InitListWrapper�ڲ���argsչ��, �����ݲ�����������˳�򱣴���buffer_��(�������)
    */
    template<class... ArgsT>
    initializer_list(ArgsT&&... args) :
        size_(sizeof...(args))
    {
        buffer_ = Allocate<T>(size_);
        using WrapperT = detail::InitListWrapper<T, 0, std::_Unrefwrap_t<ArgsT>...>;
        WrapperT(buffer_, std::forward<ArgsT>(args)...);
    }

    ~initializer_list() {
        Deallocate(buffer_);
    }

    T* begin() const noexcept {
        return buffer_;
    }
    T* end() const noexcept {
        return buffer_ + size_;
    }
    size_t size() const noexcept {
        return size_;
    }

private:
    T* buffer_;
    size_t size_;
};
}