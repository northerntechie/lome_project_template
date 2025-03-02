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

	TaskManager() = default;
	~TaskManager() = default;

	void cancel(std::string_view label);
	bool isCanceling(std::string_view label) const;

	template<typename T, typename R>
	void run(std::string_view label, std::function<Result<T,R>()> task, std::function<void()> completed);

	void runAndWait(std::string_view label, std::function<void()> task, std::function<void()> completed);
	bool wait(std::string_view label) const;

private:
	std::unordered_map<std::string_view, TaskInfo> tasks;
};
