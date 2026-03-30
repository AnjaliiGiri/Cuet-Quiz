#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"

#define MAX_QUESTIONS 60
#define TIME_EASY     45
#define TIME_MEDIUM   30
#define TIME_HARD     15

struct Question {
    char topic[30];
    char question[200];
    char options[4][100];
    char hint[150];
    int correct;
    int difficulty;
};

struct Score {
    char name[50];
    int score;
    int total;
    float percentage;
    char difficulty[10];
    char date[20];
};

struct TopicProgress {
    char topic[30];
    int attempted;
    int correct;
};

struct Question questions[MAX_QUESTIONS];
int totalQuestions = 0;

void loadQuestions() {

    strcpy(questions[0].topic, "Data Structures");
    strcpy(questions[0].question, "Which data structure uses LIFO principle?");
    strcpy(questions[0].options[0], "Queue");
    strcpy(questions[0].options[1], "Stack");
    strcpy(questions[0].options[2], "Array");
    strcpy(questions[0].options[3], "Linked List");
    strcpy(questions[0].hint, "Think of a pile of plates");
    questions[0].correct = 2;
    questions[0].difficulty = 1;

    strcpy(questions[1].topic, "Data Structures");
    strcpy(questions[1].question, "Queue follows which principle?");
    strcpy(questions[1].options[0], "LIFO");
    strcpy(questions[1].options[1], "FIFO");
    strcpy(questions[1].options[2], "Random");
    strcpy(questions[1].options[3], "Priority");
    strcpy(questions[1].hint, "Think of a line at a bank");
    questions[1].correct = 2;
    questions[1].difficulty = 1;

    strcpy(questions[2].topic, "Data Structures");
    strcpy(questions[2].question, "Which is NOT a linear data structure?");
    strcpy(questions[2].options[0], "Array");
    strcpy(questions[2].options[1], "Stack");
    strcpy(questions[2].options[2], "Tree");
    strcpy(questions[2].options[3], "Queue");
    strcpy(questions[2].hint, "Which one has branches?");
    questions[2].correct = 3;
    questions[2].difficulty = 1;

    strcpy(questions[3].topic, "Data Structures");
    strcpy(questions[3].question, "Time complexity of binary search is?");
    strcpy(questions[3].options[0], "O(n)");
    strcpy(questions[3].options[1], "O(n^2)");
    strcpy(questions[3].options[2], "O(log n)");
    strcpy(questions[3].options[3], "O(1)");
    strcpy(questions[3].hint, "It halves the search space each time");
    questions[3].correct = 3;
    questions[3].difficulty = 2;

    strcpy(questions[4].topic, "Data Structures");
    strcpy(questions[4].question, "Which traversal visits root first?");
    strcpy(questions[4].options[0], "Inorder");
    strcpy(questions[4].options[1], "Postorder");
    strcpy(questions[4].options[2], "Preorder");
    strcpy(questions[4].options[3], "Level order");
    strcpy(questions[4].hint, "PRE means before");
    questions[4].correct = 3;
    questions[4].difficulty = 2;

    strcpy(questions[5].topic, "Data Structures");
    strcpy(questions[5].question, "AVL tree is a?");
    strcpy(questions[5].options[0], "Unbalanced BST");
    strcpy(questions[5].options[1], "Self balancing BST");
    strcpy(questions[5].options[2], "Graph");
    strcpy(questions[5].options[3], "Hash table");
    strcpy(questions[5].hint, "Named after Adelson-Velsky and Landis");
    questions[5].correct = 2;
    questions[5].difficulty = 2;

    strcpy(questions[6].topic, "Data Structures");
    strcpy(questions[6].question, "Worst case time complexity of Quicksort?");
    strcpy(questions[6].options[0], "O(n log n)");
    strcpy(questions[6].options[1], "O(n)");
    strcpy(questions[6].options[2], "O(n^2)");
    strcpy(questions[6].options[3], "O(log n)");
    strcpy(questions[6].hint, "Happens when pivot is always smallest or largest");
    questions[6].correct = 3;
    questions[6].difficulty = 3;

    strcpy(questions[7].topic, "Data Structures");
    strcpy(questions[7].question, "Which data structure is used in BFS?");
    strcpy(questions[7].options[0], "Stack");
    strcpy(questions[7].options[1], "Queue");
    strcpy(questions[7].options[2], "Tree");
    strcpy(questions[7].options[3], "Heap");
    strcpy(questions[7].hint, "BFS explores level by level");
    questions[7].correct = 2;
    questions[7].difficulty = 3;

    strcpy(questions[8].topic, "Operating Systems");
    strcpy(questions[8].question, "OS stands for?");
    strcpy(questions[8].options[0], "Open System");
    strcpy(questions[8].options[1], "Operating System");
    strcpy(questions[8].options[2], "Output System");
    strcpy(questions[8].options[3], "Online System");
    strcpy(questions[8].hint, "Software that manages hardware");
    questions[8].correct = 2;
    questions[8].difficulty = 1;

    strcpy(questions[9].topic, "Operating Systems");
    strcpy(questions[9].question, "Which is NOT an OS scheduling algorithm?");
    strcpy(questions[9].options[0], "FCFS");
    strcpy(questions[9].options[1], "SJF");
    strcpy(questions[9].options[2], "Bubble Sort");
    strcpy(questions[9].options[3], "Round Robin");
    strcpy(questions[9].hint, "One of these is a sorting algorithm");
    questions[9].correct = 3;
    questions[9].difficulty = 1;

    strcpy(questions[10].topic, "Operating Systems");
    strcpy(questions[10].question, "Which scheduling gives minimum average waiting time?");
    strcpy(questions[10].options[0], "FCFS");
    strcpy(questions[10].options[1], "Round Robin");
    strcpy(questions[10].options[2], "SJF");
    strcpy(questions[10].options[3], "Priority");
    strcpy(questions[10].hint, "Shortest job goes first");
    questions[10].correct = 3;
    questions[10].difficulty = 2;

    strcpy(questions[11].topic, "Operating Systems");
    strcpy(questions[11].question, "Virtual memory uses which technique?");
    strcpy(questions[11].options[0], "Caching");
    strcpy(questions[11].options[1], "Paging");
    strcpy(questions[11].options[2], "Polling");
    strcpy(questions[11].options[3], "Buffering");
    strcpy(questions[11].hint, "Divides memory into fixed size blocks");
    questions[11].correct = 2;
    questions[11].difficulty = 2;

    strcpy(questions[12].topic, "Operating Systems");
    strcpy(questions[12].question, "Semaphore is used for?");
    strcpy(questions[12].options[0], "Memory Management");
    strcpy(questions[12].options[1], "Process Synchronization");
    strcpy(questions[12].options[2], "CPU Scheduling");
    strcpy(questions[12].options[3], "File Management");
    strcpy(questions[12].hint, "Controls access to shared resources");
    questions[12].correct = 2;
    questions[12].difficulty = 2;

    strcpy(questions[13].topic, "Operating Systems");
    strcpy(questions[13].question, "Deadlock requires which condition?");
    strcpy(questions[13].options[0], "Mutual Exclusion");
    strcpy(questions[13].options[1], "Preemption");
    strcpy(questions[13].options[2], "Single Resource");
    strcpy(questions[13].options[3], "No Waiting");
    strcpy(questions[13].hint, "One resource cannot be shared simultaneously");
    questions[13].correct = 1;
    questions[13].difficulty = 3;

    strcpy(questions[14].topic, "Operating Systems");
    strcpy(questions[14].question, "Banker's algorithm is used for?");
    strcpy(questions[14].options[0], "CPU Scheduling");
    strcpy(questions[14].options[1], "Deadlock Avoidance");
    strcpy(questions[14].options[2], "Memory Allocation");
    strcpy(questions[14].options[3], "Page Replacement");
    strcpy(questions[14].hint, "Named after banking resource allocation");
    questions[14].correct = 2;
    questions[14].difficulty = 3;

    strcpy(questions[15].topic, "DBMS");
    strcpy(questions[15].question, "SQL stands for?");
    strcpy(questions[15].options[0], "Structured Query Language");
    strcpy(questions[15].options[1], "Simple Query Language");
    strcpy(questions[15].options[2], "Standard Query Language");
    strcpy(questions[15].options[3], "Sequential Query Language");
    strcpy(questions[15].hint, "S stands for Structured");
    questions[15].correct = 1;
    questions[15].difficulty = 1;

    strcpy(questions[16].topic, "DBMS");
    strcpy(questions[16].question, "Primary key can have NULL values?");
    strcpy(questions[16].options[0], "Yes always");
    strcpy(questions[16].options[1], "Only sometimes");
    strcpy(questions[16].options[2], "No never");
    strcpy(questions[16].options[3], "Depends on DBMS");
    strcpy(questions[16].hint, "Primary key must uniquely identify each row");
    questions[16].correct = 3;
    questions[16].difficulty = 1;

    strcpy(questions[17].topic, "DBMS");
    strcpy(questions[17].question, "Which normal form removes partial dependency?");
    strcpy(questions[17].options[0], "1NF");
    strcpy(questions[17].options[1], "2NF");
    strcpy(questions[17].options[2], "3NF");
    strcpy(questions[17].options[3], "BCNF");
    strcpy(questions[17].hint, "Second normal form deals with partial dependency");
    questions[17].correct = 2;
    questions[17].difficulty = 2;

    strcpy(questions[18].topic, "DBMS");
    strcpy(questions[18].question, "ACID stands for?");
    strcpy(questions[18].options[0], "Atomicity Consistency Isolation Durability");
    strcpy(questions[18].options[1], "Access Control Integrity Data");
    strcpy(questions[18].options[2], "Atomic Concurrent Isolated Durable");
    strcpy(questions[18].options[3], "None of these");
    strcpy(questions[18].hint, "Properties of database transactions");
    questions[18].correct = 1;
    questions[18].difficulty = 2;

    strcpy(questions[19].topic, "DBMS");
    strcpy(questions[19].question, "Which JOIN returns all rows from both tables?");
    strcpy(questions[19].options[0], "INNER JOIN");
    strcpy(questions[19].options[1], "LEFT JOIN");
    strcpy(questions[19].options[2], "RIGHT JOIN");
    strcpy(questions[19].options[3], "FULL OUTER JOIN");
    strcpy(questions[19].hint, "FULL means everything from both sides");
    questions[19].correct = 4;
    questions[19].difficulty = 3;

    strcpy(questions[20].topic, "DBMS");
    strcpy(questions[20].question, "Which is used to prevent dirty reads?");
    strcpy(questions[20].options[0], "Shared Lock");
    strcpy(questions[20].options[1], "Exclusive Lock");
    strcpy(questions[20].options[2], "Timestamp");
    strcpy(questions[20].options[3], "Checkpoint");
    strcpy(questions[20].hint, "Locks prevent concurrent access issues");
    questions[20].correct = 1;
    questions[20].difficulty = 3;

    strcpy(questions[21].topic, "Networking");
    strcpy(questions[21].question, "HTTP uses which port?");
    strcpy(questions[21].options[0], "21");
    strcpy(questions[21].options[1], "80");
    strcpy(questions[21].options[2], "443");
    strcpy(questions[21].options[3], "25");
    strcpy(questions[21].hint, "Standard web browsing port");
    questions[21].correct = 2;
    questions[21].difficulty = 1;

    strcpy(questions[22].topic, "Networking");
    strcpy(questions[22].question, "DNS converts?");
    strcpy(questions[22].options[0], "IP to MAC");
    strcpy(questions[22].options[1], "Domain to IP");
    strcpy(questions[22].options[2], "IP to Domain");
    strcpy(questions[22].options[3], "MAC to IP");
    strcpy(questions[22].hint, "Like a phone book for the internet");
    questions[22].correct = 2;
    questions[22].difficulty = 1;

    strcpy(questions[23].topic, "Networking");
    strcpy(questions[23].question, "OSI model has how many layers?");
    strcpy(questions[23].options[0], "5");
    strcpy(questions[23].options[1], "4");
    strcpy(questions[23].options[2], "7");
    strcpy(questions[23].options[3], "6");
    strcpy(questions[23].hint, "Remember: Please Do Not Throw Sausage Pizza Away");
    questions[23].correct = 3;
    questions[23].difficulty = 2;

    strcpy(questions[24].topic, "Networking");
    strcpy(questions[24].question, "TCP is which type of protocol?");
    strcpy(questions[24].options[0], "Connectionless");
    strcpy(questions[24].options[1], "Connection oriented");
    strcpy(questions[24].options[2], "Broadcast");
    strcpy(questions[24].options[3], "Multicast");
    strcpy(questions[24].hint, "TCP does handshaking before data transfer");
    questions[24].correct = 2;
    questions[24].difficulty = 2;

    strcpy(questions[25].topic, "Networking");
    strcpy(questions[25].question, "Which layer handles routing?");
    strcpy(questions[25].options[0], "Physical");
    strcpy(questions[25].options[1], "Data Link");
    strcpy(questions[25].options[2], "Network");
    strcpy(questions[25].options[3], "Transport");
    strcpy(questions[25].hint, "IP addresses work at this layer");
    questions[25].correct = 3;
    questions[25].difficulty = 2;

    strcpy(questions[26].topic, "Networking");
    strcpy(questions[26].question, "Which protocol is used for secure HTTP?");
    strcpy(questions[26].options[0], "FTP");
    strcpy(questions[26].options[1], "SMTP");
    strcpy(questions[26].options[2], "TLS/SSL");
    strcpy(questions[26].options[3], "UDP");
    strcpy(questions[26].hint, "S in HTTPS stands for Secure");
    questions[26].correct = 3;
    questions[26].difficulty = 3;

    strcpy(questions[27].topic, "Networking");
    strcpy(questions[27].question, "Subnetting is used for?");
    strcpy(questions[27].options[0], "Encrypting data");
    strcpy(questions[27].options[1], "Dividing network into smaller parts");
    strcpy(questions[27].options[2], "Compressing data");
    strcpy(questions[27].options[3], "Routing between networks");
    strcpy(questions[27].hint, "Sub means smaller division");
    questions[27].correct = 2;
    questions[27].difficulty = 3;

    strcpy(questions[28].topic, "Algorithms");
    strcpy(questions[28].question, "Which algorithm uses divide and conquer?");
    strcpy(questions[28].options[0], "Bubble Sort");
    strcpy(questions[28].options[1], "Merge Sort");
    strcpy(questions[28].options[2], "Selection Sort");
    strcpy(questions[28].options[3], "Insertion Sort");
    strcpy(questions[28].hint, "It merges sorted halves");
    questions[28].correct = 2;
    questions[28].difficulty = 1;

    strcpy(questions[29].topic, "Algorithms");
    strcpy(questions[29].question, "Linear search time complexity?");
    strcpy(questions[29].options[0], "O(log n)");
    strcpy(questions[29].options[1], "O(n^2)");
    strcpy(questions[29].options[2], "O(n)");
    strcpy(questions[29].options[3], "O(1)");
    strcpy(questions[29].hint, "Checks each element one by one");
    questions[29].correct = 3;
    questions[29].difficulty = 1;

    strcpy(questions[30].topic, "Algorithms");
    strcpy(questions[30].question, "Dijkstra's algorithm is used for?");
    strcpy(questions[30].options[0], "Sorting");
    strcpy(questions[30].options[1], "Shortest Path");
    strcpy(questions[30].options[2], "Searching");
    strcpy(questions[30].options[3], "Hashing");
    strcpy(questions[30].hint, "Used in GPS navigation");
    questions[30].correct = 2;
    questions[30].difficulty = 2;

    strcpy(questions[31].topic, "Algorithms");
    strcpy(questions[31].question, "Which is a greedy algorithm?");
    strcpy(questions[31].options[0], "Merge Sort");
    strcpy(questions[31].options[1], "Dynamic Programming");
    strcpy(questions[31].options[2], "Kruskal's Algorithm");
    strcpy(questions[31].options[3], "Binary Search");
    strcpy(questions[31].hint, "Makes locally optimal choice at each step");
    questions[31].correct = 3;
    questions[31].difficulty = 2;

    strcpy(questions[32].topic, "Algorithms");
    strcpy(questions[32].question, "Space complexity of Merge Sort is?");
    strcpy(questions[32].options[0], "O(1)");
    strcpy(questions[32].options[1], "O(log n)");
    strcpy(questions[32].options[2], "O(n)");
    strcpy(questions[32].options[3], "O(n^2)");
    strcpy(questions[32].hint, "Needs extra array for merging");
    questions[32].correct = 3;
    questions[32].difficulty = 2;

    strcpy(questions[33].topic, "Algorithms");
    strcpy(questions[33].question, "Which problem is solved by dynamic programming?");
    strcpy(questions[33].options[0], "Binary Search");
    strcpy(questions[33].options[1], "Fibonacci Series");
    strcpy(questions[33].options[2], "Bubble Sort");
    strcpy(questions[33].options[3], "Linear Search");
    strcpy(questions[33].hint, "Overlapping subproblems and optimal substructure");
    questions[33].correct = 2;
    questions[33].difficulty = 3;

    strcpy(questions[34].topic, "Algorithms");
    strcpy(questions[34].question, "NP-Hard problems are?");
    strcpy(questions[34].options[0], "Easily solvable");
    strcpy(questions[34].options[1], "Solvable in polynomial time");
    strcpy(questions[34].options[2], "At least as hard as NP problems");
    strcpy(questions[34].options[3], "Linear time solvable");
    strcpy(questions[34].hint, "Hardest problems in computer science");
    questions[34].correct = 3;
    questions[34].difficulty = 3;

    strcpy(questions[35].topic, "Mathematics");
    strcpy(questions[35].question, "What is 2^10?");
    strcpy(questions[35].options[0], "512");
    strcpy(questions[35].options[1], "1024");
    strcpy(questions[35].options[2], "256");
    strcpy(questions[35].options[3], "2048");
    strcpy(questions[35].hint, "Important in computer memory sizes");
    questions[35].correct = 2;
    questions[35].difficulty = 1;

    strcpy(questions[36].topic, "Mathematics");
    strcpy(questions[36].question, "Binary representation of 10 is?");
    strcpy(questions[36].options[0], "1010");
    strcpy(questions[36].options[1], "1100");
    strcpy(questions[36].options[2], "1001");
    strcpy(questions[36].options[3], "1110");
    strcpy(questions[36].hint, "8+2=10");
    questions[36].correct = 1;
    questions[36].difficulty = 1;

    strcpy(questions[37].topic, "Mathematics");
    strcpy(questions[37].question, "What is the value of log2(64)?");
    strcpy(questions[37].options[0], "4");
    strcpy(questions[37].options[1], "8");
    strcpy(questions[37].options[2], "6");
    strcpy(questions[37].options[3], "5");
    strcpy(questions[37].hint, "2 to the power of what equals 64?");
    questions[37].correct = 3;
    questions[37].difficulty = 2;

    strcpy(questions[38].topic, "Mathematics");
    strcpy(questions[38].question, "How many bits in a byte?");
    strcpy(questions[38].options[0], "4");
    strcpy(questions[38].options[1], "16");
    strcpy(questions[38].options[2], "8");
    strcpy(questions[38].options[3], "32");
    strcpy(questions[38].hint, "Standard unit of digital information");
    questions[38].correct = 3;
    questions[38].difficulty = 1;

    strcpy(questions[39].topic, "Mathematics");
    strcpy(questions[39].question, "In Boolean algebra A + A' equals?");
    strcpy(questions[39].options[0], "0");
    strcpy(questions[39].options[1], "A");
    strcpy(questions[39].options[2], "1");
    strcpy(questions[39].options[3], "A'");
    strcpy(questions[39].hint, "A OR NOT A");
    questions[39].correct = 3;
    questions[39].difficulty = 3;

    strcpy(questions[40].topic, "Mathematics");
    strcpy(questions[40].question, "Two's complement of 0101 is?");
    strcpy(questions[40].options[0], "1010");
    strcpy(questions[40].options[1], "1011");
    strcpy(questions[40].options[2], "0101");
    strcpy(questions[40].options[3], "1001");
    strcpy(questions[40].hint, "Invert all bits then add 1");
    questions[40].correct = 2;
    questions[40].difficulty = 3;

    totalQuestions = 41;
}

void shuffleQuestions(int *indexes, int count) {
    srand(time(NULL));
    for (int i = count - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = indexes[i];
        indexes[i] = indexes[j];
        indexes[j] = temp;
    }
}

void saveScore(char *name, int score, int total, char *difficulty) {
    struct Score s;
    FILE *fp;
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);

    strcpy(s.name, name);
    s.score = score;
    s.total = total;
    s.percentage = (float)score / total * 100;
    strcpy(s.difficulty, difficulty);
    strftime(s.date, 20, "%d/%m/%Y", tm);

    fp = fopen("leaderboard.dat", "ab");
    if (fp != NULL) {
        fwrite(&s, sizeof(s), 1, fp);
        fclose(fp);
    }
}

void viewLeaderboard() {
    struct Score s;
    FILE *fp;
    int rank = 1;

    fp = fopen("leaderboard.dat", "rb");
    if (fp == NULL) {
        printf(RED "No scores yet! Take a quiz first!\n" RESET);
        return;
    }

    printf(CYAN "\n╔══════════════════════════════════════════════╗\n");
    printf("║              LEADERBOARD 🏆                  ║\n");
    printf("╚══════════════════════════════════════════════╝\n" RESET);
    printf(BOLD "%-5s %-15s %-8s %-8s %-8s %-10s %-10s\n" RESET,
           "Rank", "Name", "Score", "Total", "%", "Level", "Date");
    printf("────────────────────────────────────────────────────\n");

    while (fread(&s, sizeof(s), 1, fp)) {
        char *color = GREEN;
        if (s.percentage < 60) color = RED;
        else if (s.percentage < 80) color = YELLOW;

        printf("%-5d %-15s " GREEN "%-8d" RESET " %-8d %s%-7.1f%%" RESET " %-10s %-10s\n",
               rank++, s.name, s.score, s.total,
               color, s.percentage, s.difficulty, s.date);
    }

    fclose(fp);
}

void showTopicProgress(struct TopicProgress *progress, int count) {
    printf(CYAN "\n╔══════════════════════════════════════╗\n");
    printf("║         TOPIC WISE PROGRESS 📊       ║\n");
    printf("╚══════════════════════════════════════╝\n" RESET);
    printf(BOLD "%-20s %-10s %-10s %-10s\n" RESET,
           "Topic", "Attempted", "Correct", "Score");
    printf("──────────────────────────────────────────\n");

    for (int i = 0; i < count; i++) {
        if (progress[i].attempted > 0) {
            float percent = (float)progress[i].correct /
                           progress[i].attempted * 100;
            char *color = GREEN;
            if (percent < 60) color = RED;
            else if (percent < 80) color = YELLOW;

            printf("%-20s %-10d %-10d %s%.1f%%\n" RESET,
                   progress[i].topic,
                   progress[i].attempted,
                   progress[i].correct,
                   color, percent);
        }
    }
}

void startQuiz(int topicFilter, int difficultyFilter) {
    char name[50];
    int score = 0;
    int wrongIndexes[MAX_QUESTIONS];
    int wrongCount = 0;
    int answered = 0;
    int answer;
    int hintUsed = 0;
    int indexes[MAX_QUESTIONS];
    int indexCount = 0;
    time_t start, end;

    struct TopicProgress progress[6];
    char topicNames[6][30] = {
        "Data Structures", "Operating Systems",
        "DBMS", "Networking", "Algorithms", "Mathematics"
    };

    for (int i = 0; i < 6; i++) {
        strcpy(progress[i].topic, topicNames[i]);
        progress[i].attempted = 0;
        progress[i].correct = 0;
    }

    char diffNames[4][10] = {"", "Easy", "Medium", "Hard"};
    int timeLimit = TIME_MEDIUM;
    if (difficultyFilter == 1) timeLimit = TIME_EASY;
    else if (difficultyFilter == 3) timeLimit = TIME_HARD;

    for (int i = 0; i < totalQuestions; i++) {
        int topicMatch = (topicFilter == 0) ||
            (topicFilter == 1 && strcmp(questions[i].topic, "Data Structures") == 0) ||
            (topicFilter == 2 && strcmp(questions[i].topic, "Operating Systems") == 0) ||
            (topicFilter == 3 && strcmp(questions[i].topic, "DBMS") == 0) ||
            (topicFilter == 4 && strcmp(questions[i].topic, "Networking") == 0) ||
            (topicFilter == 5 && strcmp(questions[i].topic, "Algorithms") == 0) ||
            (topicFilter == 6 && strcmp(questions[i].topic, "Mathematics") == 0);

        int diffMatch = (difficultyFilter == 0) ||
                       (questions[i].difficulty == difficultyFilter);

        if (topicMatch && diffMatch) {
            indexes[indexCount++] = i;
        }
    }

    if (indexCount == 0) {
        printf(RED "No questions found!\n" RESET);
        return;
    }

    shuffleQuestions(indexes, indexCount);

    printf(CYAN "\nEnter your name: " RESET);
    fgets(name, 50, stdin);
    name[strcspn(name, "\n")] = 0;

    for (int q = 0; q < indexCount; q++) {
        int i = indexes[q];
        answered++;
        hintUsed = 0;

        char *diffColor = GREEN;
        char *diffLabel = "Easy  ";
        if (questions[i].difficulty == 2) { diffColor = YELLOW; diffLabel = "Medium"; }
        if (questions[i].difficulty == 3) { diffColor = RED;    diffLabel = "Hard  "; }

        printf(CYAN "\n┌────────────────────────────────────────┐\n");
        printf("│ Topic: %-30s   │\n", questions[i].topic);
        printf("│ Question: %-5d  Difficulty: %s%-6s%s   │\n",
               answered, diffColor, diffLabel, CYAN);
        printf("└────────────────────────────────────────┘\n" RESET);

        printf(BOLD "\n%s\n\n" RESET, questions[i].question);
        printf("1. %s\n", questions[i].options[0]);
        printf("2. %s\n", questions[i].options[1]);
        printf("3. %s\n", questions[i].options[2]);
        printf("4. %s\n", questions[i].options[3]);
        printf(YELLOW "\n⏱  Time limit: %d seconds\n" RESET, timeLimit);
        printf("Enter answer (1-4) or 9 for hint: ");

        time(&start);
        scanf("%d", &answer);
        while(getchar() != '\n');
        time(&end);

        if (answer == 9) {
            printf(MAGENTA "💡 Hint: %s\n" RESET, questions[i].hint);
            hintUsed = 1;
            printf("Now enter your answer (1-4): ");
            time(&start);
            scanf("%d", &answer);
            while(getchar() != '\n');
            time(&end);
        }

        int timeTaken = (int)(end - start);
        printf(CYAN "⏱  You answered in %d seconds\n" RESET, timeTaken);

        for (int t = 0; t < 6; t++) {
            if (strcmp(questions[i].topic, topicNames[t]) == 0) {
                progress[t].attempted++;
                break;
            }
        }

        if (timeTaken > timeLimit) {
            printf(RED "⏰ Time's up! Correct: %d. %s\n" RESET,
                   questions[i].correct,
                   questions[i].options[questions[i].correct - 1]);
            wrongIndexes[wrongCount++] = i;
        } else if (answer == questions[i].correct) {
            if (hintUsed)
                printf(YELLOW "✓ Correct! (Hint used)\n" RESET);
            else
                printf(GREEN "✓ Correct! 🎉\n" RESET);
            score++;
            for (int t = 0; t < 6; t++) {
                if (strcmp(questions[i].topic, topicNames[t]) == 0) {
                    progress[t].correct++;
                    break;
                }
            }
        } else {
            printf(RED "✗ Wrong! Correct: %d. %s\n" RESET,
                   questions[i].correct,
                   questions[i].options[questions[i].correct - 1]);
            wrongIndexes[wrongCount++] = i;
        }
    }

    float percentage = (float)score / answered * 100;

    printf(CYAN "\n╔══════════════════════════════════════╗\n");
    printf("║            QUIZ RESULTS 📊           ║\n");
    printf("╚══════════════════════════════════════╝\n" RESET);
    printf(BOLD "Name       : %s\n" RESET, name);
    printf(BOLD "Difficulty : %s\n" RESET,
           difficultyFilter == 0 ? "Mixed" : diffNames[difficultyFilter]);
    printf(GREEN "Score      : %d / %d\n" RESET, score, answered);
    printf(YELLOW "Percentage : %.1f%%\n" RESET, percentage);

    if (percentage >= 80)
        printf(GREEN BOLD "\n🌟 Excellent! You are ready for CUET PG!\n" RESET);
    else if (percentage >= 60)
        printf(YELLOW BOLD "\n👍 Good! Keep practicing!\n" RESET);
    else
        printf(RED BOLD "\n💪 Need more practice! Don't give up!\n" RESET);

    showTopicProgress(progress, 6);
    saveScore(name, score, answered,
              difficultyFilter == 0 ? "Mixed" : diffNames[difficultyFilter]);

    if (wrongCount > 0) {
        printf(YELLOW "\nReview wrong answers? (1=Yes 0=No): " RESET);
        int review;
        scanf("%d", &review);
        while(getchar() != '\n');

        if (review == 1) {
            printf(CYAN "\n=== WRONG ANSWERS REVIEW ===\n" RESET);
            for (int i = 0; i < wrongCount; i++) {
                int idx = wrongIndexes[i];
                printf(RED "\nQ: %s\n" RESET, questions[idx].question);
                printf(GREEN "✓ Answer: %d. %s\n" RESET,
                       questions[idx].correct,
                       questions[idx].options[questions[idx].correct - 1]);
                printf(MAGENTA "💡 Hint: %s\n" RESET, questions[idx].hint);
            }
        }
    }
}

void chooseTopic() {
    int topic, difficulty;

    printf(CYAN "\n=== Choose Topic ===\n" RESET);
    printf("1. Data Structures\n");
    printf("2. Operating Systems\n");
    printf("3. DBMS\n");
    printf("4. Networking\n");
    printf("5. Algorithms\n");
    printf("6. Mathematics\n");
    printf("0. All Topics\n");
    printf("Enter topic: ");
    scanf("%d", &topic);
    while(getchar() != '\n');

    printf(CYAN "\n=== Choose Difficulty ===\n" RESET);
    printf("1. Easy\n");
    printf("2. Medium\n");
    printf("3. Hard\n");
    printf("0. All Levels\n");
    printf("Enter difficulty: ");
    scanf("%d", &difficulty);
    while(getchar() != '\n');

    startQuiz(topic, difficulty);
}

int main() {
    int choice;
    loadQuestions();
    srand(time(NULL));

    do {
        printf(BOLD CYAN);
        printf("\n╔══════════════════════════════════════╗\n");
        printf("║       CUET PG QUIZ SYSTEM 📚         ║\n");
        printf("║        Your Study Companion          ║\n");
        printf("╚══════════════════════════════════════╝\n");
        printf(RESET);

        printf("1. Start Quiz (All Topics)\n");
        printf("2. Practice by Topic + Difficulty\n");
        printf("3. View Leaderboard\n");
        printf("0. Exit\n");
        printf("\nEnter choice: ");
        scanf("%d", &choice);
        while(getchar() != '\n');

        switch(choice) {
            case 1: startQuiz(0, 0); break;
            case 2: chooseTopic(); break;
            case 3: viewLeaderboard(); break;
            case 0: printf(GREEN "\nGood luck for CUET PG! 💪\n" RESET); break;
            default: printf(RED "Invalid choice!\n" RESET);
        }
    } while(choice != 0);

    return 0;
}
