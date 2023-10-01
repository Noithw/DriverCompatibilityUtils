#pragma once
#include "krnlib/detail/string_detail.hpp"
#include <fustd/generic/type_traits.hpp>

namespace krnlib {
using string = basic_string<char>;
using wstring = basic_string<wchar_t>;



/**
 * @brief ������ת��Ϊ�ַ���
 * @tparam T ��������
 * @param val Ҫת������ֵ
*/
template<fustd::integeral_t T>
_NODISCARD inline krnlib::string to_string(T val) {
    if constexpr (std::is_unsigned_v<std::decay_t<T>>)
        return details::UIntegralToString<char>(val);
    else
        return details::IntegralToString<char>(val);
}

/**
 * @brief ������ת��Ϊ���ַ���
 * @tparam T ��������
 * @param val Ҫת������ֵ
*/
template<fustd::integeral_t T>
_NODISCARD inline krnlib::wstring to_wstring(T val) {
    if constexpr (std::is_unsigned_v<std::decay_t<T>>)
        return details::UIntegralToString<wchar_t>(val);
    else
        return details::IntegralToString<wchar_t>(val);
}



/**
 * @brief ���ַ���ת��Ϊint������ֵ
 * @param str Ҫת�����ַ���
 * @param idx ��ѡ������ָ��ת��������λ��
 * @param base ��ѡ��������ֵ�Ľ���
*/
_NODISCARD inline int stoi(const krnlib::string& str, size_t* idx = nullptr, int base = 10) {
    return details::StrintToIntegral<int>(str, idx, base, "invalid stoi argument", "stoi argument out of range");
}

/**
 * @brief ���ַ���ת��Ϊlong������ֵ
 * @param str Ҫת�����ַ���
 * @param idx ��ѡ������ָ��ת��������λ��
 * @param base ��ѡ��������ֵ�Ľ���
*/
_NODISCARD inline long stol(const krnlib::string& str, size_t* idx = nullptr, int base = 10) {
    return details::StrintToIntegral<long>(str, idx, base, "invalid stol argument", "stol argument out of range");
}

/**
 * @brief ���ַ���ת��Ϊint������ֵ
 * @param str Ҫת�����ַ���
 * @param idx ��ѡ������ָ��ת��������λ��
 * @param base ��ѡ��������ֵ�Ľ���
*/
_NODISCARD inline unsigned long stoul(const krnlib::string& str, size_t* idx = nullptr, int base = 10) {
    return details::StrintToIntegral<unsigned long>(str, idx, base, "invalid stoul argument", "stoul argument out of range");
}

/**
 * @brief ���ַ���ת��Ϊlong long������ֵ
 * @param str Ҫת�����ַ���
 * @param idx ��ѡ������ָ��ת��������λ��
 * @param base ��ѡ��������ֵ�Ľ���
*/
_NODISCARD inline long long stoll(const krnlib::string& str, size_t* idx = nullptr, int base = 10) {
    return details::StrintToIntegral<long long>(str, idx, base, "invalid stoll argument", "stoll argument out of range");
}

/**
 * @brief ���ַ���ת��Ϊunsigned long long������ֵ
 * @param str Ҫת�����ַ���
 * @param idx ��ѡ������ָ��ת��������λ��
 * @param base ��ѡ��������ֵ�Ľ���
*/
_NODISCARD inline unsigned long long stoull(const krnlib::string& str, size_t* idx = nullptr, int base = 10) {
    return details::StrintToIntegral<unsigned long long>(str, idx, base, "invalid stoull argument", "stoull argument out of range");
}



/**
 * @brief �����ַ���ת��Ϊint������ֵ
 * @param str Ҫת���Ŀ��ַ���
 * @param idx ��ѡ������ָ��ת��������λ��
 * @param base ��ѡ��������ֵ�Ľ���
*/
_NODISCARD inline int stoi(const krnlib::wstring& str, size_t* idx = nullptr, int base = 10) {
    return details::StrintToIntegral<int>(str, idx, base, "invalid stoi argument", "stoi argument out of range");
}

/**
 * @brief �����ַ���ת��Ϊlong������ֵ
 * @param str Ҫת���Ŀ��ַ���
 * @param idx ��ѡ������ָ��ת��������λ��
 * @param base ��ѡ��������ֵ�Ľ���
*/
_NODISCARD inline long stol(const krnlib::wstring& str, size_t* idx = nullptr, int base = 10) {
    return details::StrintToIntegral<long>(str, idx, base, "invalid stol argument", "stol argument out of range");
}

/**
 * @brief �����ַ���ת��Ϊunsigned long������ֵ
 * @param str Ҫת���Ŀ��ַ���
 * @param idx ��ѡ������ָ��ת��������λ��
 * @param base ��ѡ��������ֵ�Ľ���
*/
_NODISCARD inline unsigned long stoul(const krnlib::wstring& str, size_t* idx = nullptr, int base = 10) {
    return details::StrintToIntegral<unsigned long>(str, idx, base, "invalid stoul argument", "stoul argument out of range");
}

/**
 * @brief �����ַ���ת��Ϊlong long������ֵ
 * @param str Ҫת���Ŀ��ַ���
 * @param idx ��ѡ������ָ��ת��������λ��
 * @param base ��ѡ��������ֵ�Ľ���
*/
_NODISCARD inline long long stoll(const krnlib::wstring& str, size_t* idx = nullptr, int base = 10) {
    return details::StrintToIntegral<long long>(str, idx, base, "invalid stoll argument", "stoll argument out of range");
}

/**
 * @brief �����ַ���ת��Ϊunsigned long long������ֵ
 * @param str Ҫת���Ŀ��ַ���
 * @param idx ��ѡ������ָ��ת��������λ��
 * @param base ��ѡ��������ֵ�Ľ���
*/
_NODISCARD inline unsigned long long stoull(const krnlib::wstring& str, size_t* idx = nullptr, int base = 10) {
    return details::StrintToIntegral<unsigned long long>(str, idx, base, "invalid stoull argument", "stoull argument out of range");
}
}