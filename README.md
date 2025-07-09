# 🎰 Project Title: Casino Number Guessing Game (C++)

## 📖 Overview
The **Casino Number Guessing Game** is a C++ console-based project that simulates a fun and interactive casino environment. Players can create an account, log in securely, and place bets on their guesses of randomly generated numbers. The system tracks each player's balance and game history securely using file handling techniques. It offers a vibrant console experience with colored text output, making the game both educational and enjoyable.

---

## 🚀 Features

### 🔐 Login/Registration System
- User registration with a **username and password**
- Login system with **multiple attempts** for validation
- Data persistence using `players.txt` to store credentials and balances
- Auto-initialized balance for new users

### 🧠 Gameplay Logic
- Random number between **1 and 10** generated each round
- Players guess the number and place a **custom bet**
- **Win**: Player gets bet **added** to balance
- **Lose**: Bet is **deducted** from balance
- Real-time balance update

### 💾 File Handling
- User data stored in `players.txt`
- Secure update of balance via **temporary file replacement**
- Supports multiple players with independent accounts

### 🎨 Console UI Enhancements
- Uses **ANSI escape codes** for colored output:
  - ✅ Green for success
  - ❌ Red for errors
  - 📘 Cyan for input prompts
  - 💰 Yellow for balances
- Adds **emojis** for better user engagement

---

## 🛠️ Tools and Libraries

Utilized Standard C++ Libraries:

- `<iostream>` – Console input/output  
- `<fstream>` – File reading/writing  
- `<string>` – User input handling  
- `<cstdlib>` – Random number generation  
- `<ctime>` – Seeding random generator for unique results  

**Optional:**
- `<iomanip>` – Formatting outputs  
- `<conio.h>` – *(for future enhancements like password masking)*

---

## ⚙️ How It Works

### 🏁 Welcome & Login
- Displays a welcome screen
- Prompts for login or account creation
- Checks credentials from `players.txt`

### 🧩 Main Menu Options
1. **Create Account** – Registers new user and stores in file  
2. **Login** – Validates and retrieves user's balance  
3. **Play Game** – Starts betting round and updates balance  
4. **Exit** – Ends the session gracefully

### 🎮 Game Mechanics
- Player is shown their **balance**
- Enters guess and betting amount
- System generates a random number (1–10)
- Based on correctness:
  - ✅ Win → Gain bet amount
  - ❌ Lose → Deduct bet
- Updated balance saved back to file

---

## 🧑‍💻 Concepts Utilized
- **Object-Oriented Programming** – All logic inside a `Player` class  
- **File Handling** – Using `ifstream`, `ofstream`, and `temp.txt` for secure balance update  
- **Randomization** – Ensures fair and unpredictable gameplay  
- **Console Formatting** – Enhances UI with escape sequences and emojis  
- **Input Validation** – Prevents invalid entries like overspending

---

## 📂 File Structure
- `players.txt` – Stores: `username password balance`  
- `casino.cpp` – Main source code containing all game logic  
- `temp.txt` – Temporary file used during balance updates  

---

## ✨ Future Enhancements
- MySQL integration to replace text files  
- Leaderboard system to display top winners  
- Password masking using `getch()`  
- GUI version using SFML/Qt  
- **Admin Panel**:
  - View registered players  
  - Reset balances  
  - Monitor total wins/losses  

---

## 📜 Authors
Developed by:

- **Rishab Koul**
