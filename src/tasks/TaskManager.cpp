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

void TaskManager::run(std::string_view label, std::function<void()> task, std::function<void()> completed)
{
	std::jthread thread(task);
	thread.detach();
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
