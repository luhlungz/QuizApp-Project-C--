# QuizApp — C++ Programming Quiz

An interactive technical quiz originally developed in C++/CLI and Windows Forms for a university project, now rebuilt as a complete browser experience.

## Live demo

**[Play QuizApp](https://luhlungz.github.io/QuizApp-Project-C--/)**

Choose **Continue as portfolio guest**, or create a local demonstration account.

## Features reproduced from the original project

- Local user registration and login
- Easy, Medium and Hard difficulty selection
- Eight questions randomly selected and shuffled each round
- Original 19-question programming and IT question bank
- Multiple-choice and true/false questions
- Required answer selection and clear-choice control
- Previous-question navigation in Easy mode
- 30-minute timer in Medium mode
- Original 30-second rapid timer in Hard mode
- Progress indicator, scoring and final answer review
- Responsive desktop and mobile design

## Improvements

- Corrected two inaccurate answers in the original question file: the machine-learning question and the constructor question
- Passwords created in the web demonstration are SHA-256 hashed before local storage
- Removed committed plaintext test accounts from `Users.txt`
- Added clear result feedback and a complete answer review
- Improved navigation, accessibility and validation

## Technologies

Original application: C++/CLI, Windows Forms, templates, file I/O and generic collections.  
Live demonstration: HTML5, CSS3, JavaScript, Web Crypto and browser local storage.

## Repository structure

- `QuizApp_Project/` — original C++/CLI source
- `docs/` — GitHub Pages demonstration

## Author

Lungani Zondi
