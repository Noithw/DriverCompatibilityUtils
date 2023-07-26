#pragma once
#include "krnlib/functional.hpp"

namespace krnlib {

template<class AssignParamT>
class BoolCallable {
public:
	//�ɵ��ö���, ������������ȡAssignParamTʵ��
	using GetValCallableT = krnlib::function<AssignParamT()>;
	//�ɵ��ö���, �����ʱ���õĶ���, ����һ��AssignParamT���͵Ĳ���, ���Զ���ֵ
	using TrueCallbackT = krnlib::function<void(AssignParamT)>;
	//�ɵ��ö���, �����ʱ���õĶ���
	using FalseCallbackT = krnlib::function<void()>;

	BoolCallable(bool bval, const GetValCallableT& get_val_call):
		bval_(bval),
		get_val_call_(get_val_call) {}
	~BoolCallable() {}

	// �����, ���ô����callback����, ���Զ�������Ҫ�Ĳ���
	BoolCallable& TrueIf(const TrueCallbackT& callback) {
		if (bval_)
			callback(get_val_call_());
		return *this;
	}

	// �����, ���ô����callback����
	BoolCallable& FalseIf(const FalseCallbackT& callback) {
		if (!bval_)
			callback();
		return *this;
	}

	operator bool() {
		return bval_;
	}

private:
	bool bval_;
	GetValCallableT get_val_call_;
};
}