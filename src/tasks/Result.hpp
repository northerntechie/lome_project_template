/**
 * Lome sample project - Algorithms
 *
 */
#pragma once

#include <concepts>
#include <memory>

enum class ReturnCode {
	Ok = 0,
	Failure,
	SuccessWithWarnings,
	_next,
};

template<typename T, typename Base>
concept DerivedFromBase = std::derived_from<T, Base>;

template<typename T, DerivedFromBase<ReturnCode> R>
class Result {
public:
	Result(T&& data, R returnCode)
	: mReturnCode(returnCode)
	{
		mData = std::make_unique<T>(std::move(data));
	}

	R getReturnCode() const
	{
		return mReturnCode;
	}

	std::unique_ptr<T> releaseData()
	{
		return std::move(mData);
	}
private:
	std::unique_ptr<T> mData;
	R mReturnCode;
};
