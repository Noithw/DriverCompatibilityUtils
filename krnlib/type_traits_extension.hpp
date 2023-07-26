#pragma once
#include <type_traits>

namespace krnlib {
namespace details {
#pragma region �ɱ�ģ��������ж��Ƿ����
template<class CompareT, class ThisType, class... RestTypes>
static constexpr bool is_first_type_same_v() {
	return std::is_same_v<CompareT, ThisType>;
}
template<class CompareT>
static constexpr bool is_first_type_same_v() {
	return false;
}
template<class CompareT, class ThisType, class... RestTypes>
static constexpr bool is_pure_first_type_same_v() {
	return std::is_same_v<CompareT, std::_Remove_cvref_t<ThisType>>;
}
template<class CompareT>
static constexpr bool is_pure_first_type_same_v() {
	return false;
}

template<class CompareT, class ThisType, class... RestTypes>
static constexpr bool is_only_one_type_and_same_v() {
	return std::is_same_v<CompareT, ThisType> && sizeof...(RestTypes) == 0;
}
template<class CompareT>
static constexpr bool is_only_one_type_and_same_v() {
	return false;
}
#pragma endregion

#pragma region �ɱ�ģ��������ж��Ƿ����ת��
template<class ToT, class ThisFromT, class... RestFromT>
static constexpr bool is_first_type_convertible_v() {
	return std::is_convertible_v<ThisFromT, ToT>;
}
template<class ToT>
static constexpr bool is_first_type_convertible_v() {
	return false;
}

template<class ToT, class ThisFromT, class... RestFromT>
static constexpr bool is_only_one_type_and_is_convertible_v_v() {
	return std::is_convertible_v<ThisFromT, ToT> && sizeof...(RestFromT) == 0;
}
template<class ToT>
static constexpr bool is_only_one_type_and_is_convertible_v_v() {
	return false;
}
#pragma endregion
}

// �жϿɱ�ģ������ĵ�һ�������Ƿ��ָ���������
template<class CompareT, class... Types>
static constexpr bool is_first_type_same_v = details::is_first_type_same_v<CompareT, Types...>();
// �жϿɱ�ģ������ĵ�һ������(ȥ��װ�κ�)�Ƿ��ָ���������
template<class CompareT, class... Types>
static constexpr bool is_pure_first_type_same_v = details::is_pure_first_type_same_v<CompareT, Types...>();
// �жϿɱ�ģ������Ƿ�ֻ��һ�����������Ƿ��ָ���������
template<class CompareT, class... Types>
static constexpr bool is_only_one_type_and_same_v = details::is_only_one_type_and_same_v<CompareT, Types...>();
// �жϿɱ�ģ������ĵ�һ�������Ƿ����ת��Ϊָ������
template<class ToT, class... FromT>
static constexpr bool is_first_type_convertible_v = details::is_first_type_convertible_v<ToT, FromT...>();
// �жϿɱ�ģ������Ƿ�ֻ��һ���������ҿ���ת��Ϊָ������
template<class ToT, class... FromT>
static constexpr bool is_only_one_type_and_is_convertible_v_v = details::is_only_one_type_and_is_convertible_v_v<ToT, FromT...>();
// �жϿɱ�ģ��������в����Ƿ��ָ�����������
template<class CompareT, class... Types>
static constexpr bool is_all_same_v = ((std::is_same_v<CompareT, Types>) && ...);
// �жϿɱ�ģ��������в����Ƿ񶼿���ת����ָ������
template<class ToT, class... FromT>
static constexpr bool is_all_convertible_v = ((std::is_convertible_v<FromT, ToT>) &&  ...);

// �Ƿ�������(��������, С��)
template<class T>
static constexpr bool is_number_v = std::is_integral_v<T> || std::is_floating_point_v<T>;
// �Ƿ����ַ���
template<class T>
static constexpr bool is_charptr_v = std::_Is_any_of_v<T, const char*, char*, char[]>;
// �Ƿ��ǿ��ַ���
template<class T>
static constexpr bool is_wcharptr_v = std::_Is_any_of_v<T, const wchar_t*, wchar_t*, wchar_t[]>;
// �Ƿ����ַ������߿��ַ���
template<class T>
static constexpr bool is_str_v = is_charptr_v<T> || is_wcharptr_v<T>;
// �Ƿ��ǽṹ��
template<class T>
static constexpr bool is_struct_v = std::is_pod_v<T> && !is_number_v<T> && !std::is_pointer_v<T>;
// �Ƿ�����
template<class T>
static constexpr bool is_class_v = !std::is_pod_v<T>;
// �Ƿ��Ƕ���(�ṹ��+��)
template<class T>
static constexpr bool is_object_v = is_struct_v<T> || is_class_v<T>;
// �Ƿ��Ƿ��ַ�����ָ��
template<class T>
static constexpr bool is_not_str_ptr_v = std::is_pointer_v<T> && !is_str_v<T>;
}