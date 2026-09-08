# C++ Qt Task Manager

A desktop application for managing software developement tasks, built with C++ and Qt.

## Features
 
 - Display tasks in a table sorted by status
 - Add new tasks with input validation
 - Search tasks by programmer name
 - Store tasks in a text file
 - Open separate windows for 'open', 'in progress' and 'closed' tasks
 - Change a task's status from any status window
 - Synchronize changes across all application windows

## Technologies and concepts
 
 - C++
 - Qt Widgets
 - QTableView and custom table model
 - Layered architecture
 - Repository pattern
 - Observer pattern
 - File persistence
 - Input validation
 - Assertions and unit tests
	
## Project structure
- 'Task' - domain entity
- 'Repository' - file persistence
- 'Service' - application logic
- 'TaskValidare' - input validation
- 'TableModel' - Qt table model
- 'GUI' - main application window
- 'StareGUI' - status-specific windows
- 'Observer' - synchronization between windows
- 'teste' - automated tests

## Running the application
1. Install Qt and Visual Studio with the Qt Visual Studio Tools extension.
2. Configure a compatible Qt kit in Visual Studio.
3. Open 'Examen.sln'.
4. Build and run the solution.

## Data

The application loads and saves tasks using the 'tasks.txt' file.

## Status

Completed academic project developed for an Object-Oriented Programming practical examination.