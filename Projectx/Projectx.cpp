#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Task {
    string taskName;
    string status;
    int duration;  // Duration of the task in days
};

struct Project {
    string projectName;
    string type;
    double budget;
    int daysAllocated;
    int numTasks;
    Task tasks[10];  // Assuming maximum 10 tasks per project
    double completionProbability;  // This will be calculated automatically
};

// Function to create real-world projects with cool tech names
void createRealWorldProjects(Project projects[5]) {
    // Real-world 1: "CyberX - The Digital Fortress" (Agile)
    projects[0].projectName = "CyberX - The Digital Fortress";
    projects[0].type = "Agile";
    projects[0].budget = 50000;
    projects[0].daysAllocated = 30;
    projects[0].numTasks = 3;
    projects[0].tasks[0] = { "Design Layout", "Completed", 7 };
    projects[0].tasks[1] = { "Implement Backend", "In Progress", 12 };
    projects[0].tasks[2] = { "Frontend Development", "Not Started", 10 };

    // Real-world 2: "Phoenix App - Rise Above" (Waterfall)
    projects[1].projectName = "Phoenix App - Rise Above";
    projects[1].type = "Waterfall";
    projects[1].budget = 75000;
    projects[1].daysAllocated = 40;
    projects[1].numTasks = 4;
    projects[1].tasks[0] = { "UI/UX Design", "Completed", 10 };
    projects[1].tasks[1] = { "Backend API", "Completed", 12 };
    projects[1].tasks[2] = { "App Testing", "In Progress", 8 };
    projects[1].tasks[3] = { "App Launch", "Not Started", 10 };

    // Real-world 3: "Project Nebula - Next-Gen AI" (Agile)
    projects[2].projectName = "Project Nebula - Next-Gen AI";
    projects[2].type = "Agile";
    projects[2].budget = 120000;
    projects[2].daysAllocated = 50;
    projects[2].numTasks = 5;
    projects[2].tasks[0] = { "AI Model Training", "Completed", 10 };
    projects[2].tasks[1] = { "Data Preprocessing", "In Progress", 15 };
    projects[2].tasks[2] = { "Algorithm Testing", "Not Started", 10 };
    projects[2].tasks[3] = { "Integration with App", "Not Started", 10 };
    projects[2].tasks[4] = { "Deployment", "Not Started", 5 };

    // Real-world 4: "Titan Protocol - Blockchain Revolution" (Waterfall)
    projects[3].projectName = "Titan Protocol - Blockchain Revolution";
    projects[3].type = "Waterfall";
    projects[3].budget = 90000;
    projects[3].daysAllocated = 60;
    projects[3].numTasks = 4;
    projects[3].tasks[0] = { "Blockchain Research", "Completed", 12 };
    projects[3].tasks[1] = { "Smart Contract Development", "In Progress", 15 };
    projects[3].tasks[2] = { "Deployment", "Not Started", 20 };
    projects[3].tasks[3] = { "Security Audits", "Not Started", 13 };

    // Real-world 5: "QuantumCore - AI-Powered Analytics" (Agile)
    projects[4].projectName = "QuantumCore - AI-Powered Analytics";
    projects[4].type = "Agile";
    projects[4].budget = 150000;
    projects[4].daysAllocated = 75;
    projects[4].numTasks = 6;
    projects[4].tasks[0] = { "Data Collection", "Completed", 10 };
    projects[4].tasks[1] = { "Data Analysis", "Completed", 12 };
    projects[4].tasks[2] = { "Machine Learning", "In Progress", 15 };
    projects[4].tasks[3] = { "Model Training", "In Progress", 18 };
    projects[4].tasks[4] = { "AI Integration", "Not Started", 12 };
    projects[4].tasks[5] = { "System Deployment", "Not Started", 8 };
}

// Function to calculate the Completion Probability automatically
void calculateCompletionProbability(Project& project) {
    int completedTasks = 0;
    for (int i = 0; i < project.numTasks; ++i) {
        if (project.tasks[i].status == "Completed") {
            completedTasks++;
        }
    }
    project.completionProbability = static_cast<double>(completedTasks) / project.numTasks * 100;
}

// Function to calculate Average Task Completion Time
double calculateAverageTaskCompletionTime(const Project& project) {
    int totalDuration = 0;
    for (int i = 0; i < project.numTasks; ++i) {
        totalDuration += project.tasks[i].duration;
    }
    return static_cast<double>(totalDuration) / project.numTasks;
}

// Function to calculate Budget Utilization Percentage
double calculateBudgetUtilization(const Project& project) {
    return (project.budget / 100000) * 100;  // Assuming max budget is 100,000
}

// Function to analyze completion trends (Completed, In Progress, Not Started)
void analyzeCompletionTrend(const Project& project) {
    int completed = 0, inProgress = 0, notStarted = 0;
    for (int i = 0; i < project.numTasks; ++i) {
        if (project.tasks[i].status == "Completed") completed++;
        if (project.tasks[i].status == "In Progress") inProgress++;
        if (project.tasks[i].status == "Not Started") notStarted++;
    }
    cout << "Completion Trend:" << endl;
    cout << "Completed: " << (completed * 100) / project.numTasks << "%" << endl;
    cout << "In Progress: " << (inProgress * 100) / project.numTasks << "%" << endl;
    cout << "Not Started: " << (notStarted * 100) / project.numTasks << "%" << endl;
}

// Function to estimate Total Days for Completion
int estimateTotalDaysForCompletion(const Project& project) {
    int totalDuration = 0;
    for (int i = 0; i < project.numTasks; ++i) {
        totalDuration += project.tasks[i].duration;
    }
    return totalDuration;
}

// Function to determine project feasibility based on completion probability
bool isProjectFeasible(const Project& project) {
    return project.completionProbability >= 50;
}

// Function to display Project Details
void displayProjectDetails(const Project& project) {
    cout << "Project Name: " << project.projectName << endl;
    cout << "Type: " << project.type << endl;
    cout << "Budget: $" << fixed << setprecision(2) << project.budget << endl;
    cout << "Days Allocated: " << project.daysAllocated << endl;
    cout << "Completion Probability: " << fixed << setprecision(2) << project.completionProbability << "%" << endl;
    cout << "\nTasks:" << endl;
    for (int i = 0; i < project.numTasks; ++i) {
        cout << "Task Name: " << project.tasks[i].taskName << endl;
        cout << "Status: " << project.tasks[i].status << endl;
        cout << "Duration: " << project.tasks[i].duration << " days" << endl;
        cout << "----------------------" << endl;
    }
    // Additional Features
    cout << "\nAverage Task Completion Time: " << calculateAverageTaskCompletionTime(project) << " days" << endl;
    cout << "Budget Utilization Percentage: " << calculateBudgetUtilization(project) << "%" << endl;
    analyzeCompletionTrend(project);
    cout << "Estimated Total Days for Completion: " << estimateTotalDaysForCompletion(project) << " days" << endl;
    cout << "Feasibility of Project: " << (isProjectFeasible(project) ? "Feasible" : "Not Feasible") << endl;
}

// Function to add a new project
void addNewProject(Project& project) {
    cout << "Enter Project Name: ";
    cin.ignore();  // To clear the input buffer
    getline(cin, project.projectName);

    cout << "Enter Project Type (Agile/Waterfall): ";
    cin >> project.type;

    cout << "Enter Budget: ";
    cin >> project.budget;

    cout << "Enter Days Allocated: ";
    cin >> project.daysAllocated;

    cout << "Enter Number of Tasks: ";
    cin >> project.numTasks;

    for (int i = 0; i < project.numTasks; ++i) {
        cout << "Enter Task " << i + 1 << " Name: ";
        cin.ignore();  // To clear the input buffer
        getline(cin, project.tasks[i].taskName);

        cout << "Enter Status (Completed/In Progress/Not Started): ";
        getline(cin, project.tasks[i].status);

        cout << "Enter Duration (in days): ";
        cin >> project.tasks[i].duration;
    }
}

int main() {
    Project projects[5];
    createRealWorldProjects(projects);

    int choice;
    do {
        cout << "\nWelcome to the Project Management Tool!" << endl;
        cout << " ProjectX - The Project Mastermind" << endl;  // Cool tool name
        cout << "\nMenu:" << endl;
        cout << "1. Add a New Project" << endl;
        cout << "2. Projects Dashboard" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
        {
            Project newProject;
            addNewProject(newProject);
            calculateCompletionProbability(newProject);
            displayProjectDetails(newProject);
        }
        break;
        case 2:
            cout << "Choose a Real-World Project:" << endl;
            for (int i = 0; i < 5; ++i) {
                cout << i + 1 << ". " << projects[i].projectName << endl;
            }

            int projectChoice;
            cout << "Enter your choice (1-5): ";
            cin >> projectChoice;

            if (projectChoice >= 1 && projectChoice <= 5) {
                calculateCompletionProbability(projects[projectChoice - 1]);
                displayProjectDetails(projects[projectChoice - 1]);
            }
            else {
                cout << "Invalid choice!" << endl;
            }
            break;
        case 3:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice, please try again!" << endl;
            break;
        }
    } while (choice != 3);

    return 0;
}

