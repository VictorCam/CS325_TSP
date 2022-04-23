# CS325_TSP
CS325 Anaylsis of Algorithms [Project]

## Project
https://oregonstate.instructure.com/courses/1774562/assignments/7799150

## Project Report (Google Docs)
https://docs.google.com/document/d/1U9KtGudqF4P4ztoTKihwG6WMKFZo02TWNLqIWYsKo70/edit?usp=sharing

## TSP Files
https://oregonstate.instructure.com/courses/1774562/pages/tsp-files?module_item_id=19350430

## TSP Test Cases
https://oregonstate.instructure.com/courses/1774562/pages/tsp-test-cases?module_item_id=19350432

## How to run TSP.cpp file

1) g++ -std=c++11 TSP.cpp

2) ./a.out test-input-[number].txt

3) test-input-[number].txt.tour will be created


## Your program must
- Accept problem instances on the command line.
- Name the output file as the input file’s name with .tour appended (for example input tsp_example_1.txt will output tsp_example_1.txt.tour).
- Compile/Execute correctly and without debugging on the flip server according to specifications and any documentation you provide

## Input specifications
- A problem instance will always be given to you as a text file
- Each line defines a city and each line has three numbers separated by a white space

 - The first number is a city identifier
 - The second number is the city's x-coordinates
 - The third number is the city's y-coordinates

## Output specifications

- You must output your solution in another text file with n+1 lines, where n is the number of cities.
- The first line is the length of the tour your program computes.
- The next n lines should contain the city identifier in the order they are visited by your tour.

- Each city must be listed exactly once in this list.
- This is the certificate for your solution and your solutions will be checked. I they are not valid you will not receive credit for them.

## Check List

- Does your program correctly compute tour lengths for simple cases?
- Does your program read input files and options from the command line?
- Does your program meet the output specifications?
- Did you check that you produce solutions that verify correctly?
- Did you find solutions to the example instances?
- Did you find solutions to the test instances?
- Does your code compile/run without issue according to your documentation?
- Have you submitted your report to Canvas? In the comment section post the onid username of the person who submitted to TEACH.
- Have you submitted your solutions to the test cases, your source code and README file to TEACH?

## Extra Credit

Post your "best" tour for each test case to the competition discussion board by Friday at 11:59 pm. The minimum tour for each test case will be verified.  If the tours are valid the winning team will receive extra credit points.  The amount of extra credit depends on whether a team wins multiple test cases.   For winning one test case your team members will receive 3 points extra credit to be used towards a project score.  For two winning test cases your team will receive 5 points and for more than two 10 points.   This may result in over 100% for your project grade.
