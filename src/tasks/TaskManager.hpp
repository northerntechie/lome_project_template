/**
 * Lome sample project - Algorithms
 *
 */
#pragma once

#include "tasks/Result.hpp"

#include <functional>
#include <unordered_map>
#include <string_view>

class TaskManager {
public:
	struct TaskInfo {
		bool isAlive;
		std::uint64_t handle;
		std::string_view label;
		std::function<void()> completedCallback;
	};

	enum class Result {
		Ok,
		Failure,
		SuccessWithWarnings,
		_next,
	};

	TaskManager() = default;
	~TaskManager() = default;

	void cancel(std::string_view label);
	bool isCanceling(std::string_view label) const;
	void run(std::string_view label, std::function<Result()>&& task, std::function<void(Result&)> completed);
	bool wait(std::string_view label) const;

private:
	std::unordered_map<std::string_view, TaskInfo> tasks;
};
