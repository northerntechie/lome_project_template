/**
 * Lome sample project - Algorithms
 *
 */
#include "TaskManager.hpp"
#include <thread>

void TaskManager::cancel(std::string_view label)
{
}

bool TaskManager::isCanceling(std::string_view label) const
{
	return false;
}

template<typename T, typename R>
void TaskManager::run(std::string_view label, std::function<Result<T, R>()> task, std::function<void()> completed)
{
	
}

void TaskManager::runAndWait(std::string_view label, std::function<void()> task, std::function<void()> completed)
{
	std::jthread thread(task);

	thread.join();
	completed();
}

bool TaskManager::wait(std::string_view label) const
{
	return false;
}
