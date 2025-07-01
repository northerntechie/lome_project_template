/**
 * Lome sample project - AlgorithmLibrary
 * 
 * Derived from "Algorithms in a Nutshell", Heineman, G.T., Pollice G., Selkow S.
 * O'Reilly, 2009
 * 
*/
#include "tasks/Result.hpp"
#include "tasks/TaskManager.hpp"
#include "test/Utils.hpp"
#include <chrono>
#include <thread>

namespace Test {
	void CreateTaskManager_runTaskCompletedWait_CompletedConfirmed()
	{
		TaskManager taskManager;
		bool completed = false;
		auto task = []() -> TaskManager::Result {
			return TaskManager::Result::Ok;
		};
		auto completedCallback = [&completed](TaskManager::Result& result) {
			completed = true;
		};

		taskManager.run("test_task", std::move(task), completedCallback);
		std::this_thread::sleep_for(std::chrono::milliseconds(100));

		TEST_ASSERT(completed, "Task did not complete");
	}
} // Test namespace
