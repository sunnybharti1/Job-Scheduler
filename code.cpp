#include <iostream>
#include <queue>
#include <vector>
#include <string>

// Job structure
struct Job {
    int id;
    std::string description;
    int priority;

    // Constructor
    Job(int id, std::string description, int priority)
        : id(id), description(description), priority(priority) {}
};

// Comparator for the priority queue
struct JobComparator {
    bool operator()(const Job& job1, const Job& job2) {
        // Higher priority jobs should come first
        return job1.priority < job2.priority;
    }
};

// Job Scheduler class
class JobScheduler {
private:
    std::priority_queue<Job, std::vector<Job>, JobComparator> jobQueue;

public:
    // Add a job to the scheduler
    void addJob(int id, const std::string& description, int priority) {
        Job newJob(id, description, priority);
        jobQueue.push(newJob);
        std::cout << "Job added: " << description << " with priority " << priority << std::endl;
    }

    // Execute the highest priority job
    void executeJob() {
        if (jobQueue.empty()) {
            std::cout << "No jobs to execute." << std::endl;
            return;
        }

        Job topJob = jobQueue.top();
        jobQueue.pop();
        std::cout << "Executing job: " << topJob.description << " with priority " << topJob.priority << std::endl;
    }

    // Display all jobs
    void displayJobs() {
        std::priority_queue<Job, std::vector<Job>, JobComparator> tempQueue = jobQueue;

        if (tempQueue.empty()) {
            std::cout << "No jobs in the queue." << std::endl;
            return;
        }

        while (!tempQueue.empty()) {
            Job job = tempQueue.top();
            tempQueue.pop();
            std::cout << "Job ID: " << job.id << ", Description: " << job.description << ", Priority: " << job.priority << std::endl;
        }
    }
};

// Main function to test the Job Scheduler
int main() {
    JobScheduler scheduler;

    scheduler.addJob(1, "Job A", 2);
    scheduler.addJob(2, "Job B", 1);
    scheduler.addJob(3, "Job C", 3);

    std::cout << "All jobs in the queue:" << std::endl;
    scheduler.displayJobs();

    std::cout << "\nExecuting jobs:" << std::endl;
    scheduler.executeJob();
    scheduler.executeJob();
    scheduler.executeJob();
    scheduler.executeJob(); // No jobs to execute

    return 0;
}
