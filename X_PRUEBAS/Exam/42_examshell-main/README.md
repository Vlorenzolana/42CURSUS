# 42 Exam Practice Shell

⚡ An interactive practice environment for 42 School exams (Ranks 02-05) ⚡

## 📋 Overview

This project provides a comprehensive practice shell for 42 School examinations, offering interactive menus and practice exercises for different exam ranks. The shell simulates the actual exam environment and helps students prepare effectively.

## 🚀 Features

- **Interactive Menu System**: Clean, colorful terminal interface
- **Multiple Exam Ranks**: Support for Ranks 02, 03, 04 and 05
- **Practice Environment**: Dedicated workspace (`rendu` folder) for submissions
- **Command Practice**: Built-in command reference and practice
- **Easy Navigation**: Simple numbered menu system

## 📁 Project Structure

```
.
├── exam.sh           # Main entry point
├── Makefile          # Build configuration
├── README.md         # This file
└── .resources/       # Practice materials
    ├── main/         # Main menu and interface
    ├── rank02/       # Rank 02 exam exercises
    ├── rank03/       # Rank 03 exam exercises
    └── rank04/       # Rank 04 exam exercises
    └── rank05/       # Rank 05 exam exercises
```

## 🔧 Installation & Usage

### Quick Start

1. **Clone the repository**:
   ```bash
   git clone https://github.com/terminal-42s/42_examshell
   cd 42_examshell

2. **Run the exam shell**:
   ```bash
   make
   ```
   
   Or directly:
   ```bash
   bash exam.sh
   ```

### Menu Options

The main menu provides the following options:

- **🔄 1. Commands**: Access command reference and practice
- **🚀 2. Exam Rank 02**: Practice exercises for Rank 02 exam
- **📋 3. Exam Rank 03**: Practice exercises for Rank 03 exam  
- **📄 4. Exam Rank 04**: Practice exercises for Rank 04 exam
- **📄 5. Exam Rank 05**: Practice exercises for Rank 05 exam
- **📁 6. Open Rendu Folder**: Access your submission workspace

## 💡 How to Use

1. Launch the application using `make` or `bash exam.sh`
2. Select your desired exam rank or practice option
3. Follow the on-screen instructions
4. Complete exercises in the automatically created `rendu` folder
5. Use the practice environment to simulate real exam conditions

## 📝 Workspace

The shell automatically creates a `rendu` folder where you can:
- Write your solutions
- Test your code
- Practice exam submissions

## 🎯 Target Audience

This tool is designed for:
- 42 School students preparing for exams
- Anyone practicing C programming and system administration
- Students wanting to simulate exam conditions

## ⚙️ Requirements

- Bash shell
- Unix-like operating system (Linux/macOS)
- Terminal with color support (recommended)

## 🔄 Updates

The project includes update mechanisms to keep practice materials current with the latest exam requirements.

## 📚 Exam Ranks Covered

- **Rank 02**: Fundamental C programming concepts
- **Rank 03**: Advanced C programming and system calls
- **Rank 04**: Complex algorithms and data structures
- **Rank 05**: Advanced C++ programming and object-oriented design

## 🤝 Contributing

This is a practice tool for 42 School students. Contributions and improvements are welcome to enhance the learning experience.

## 📧 Support

For issues or questions regarding the practice environment, please refer to your 42 School resources or community.

---

**Good luck with your exams! 🍀**

*Made for 42 School students by 42 School students*
