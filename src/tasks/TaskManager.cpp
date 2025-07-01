/**
 * Lome sample project - Algorithms
 *
 */
#include "TaskManager.hpp"
#include <thread>

void TaskManager::cancel(std::string_view label)
{
	// TODO(): Needs implementation
}

bool TaskManager::isCanceling(std::string_view label) const
{
	// TODO(): Needs implementation
	return false;
}

void TaskManager::run(
	std::string_view label,
	std::function<Result()>&& task,
	std::function<void(Result&)> completed)
{
	auto thread_entry_point = [](
		std::function<Result()>&& func,
		std::function<void(Result&)> completed)
	{
		Result result = func();
		completed(result);
	};
	std::jthread worker(thread_entry_point, std::move(task), completed);
	worker.detach();
}

bool TaskManager::wait(std::string_view label) const
{
	// TODO(): Needs implementation
	return false;
}
