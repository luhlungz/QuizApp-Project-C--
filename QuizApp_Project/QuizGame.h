#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "ReviewPage.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;
using namespace System::IO;

namespace QuizAppProject {

    generic<typename T>
    public ref struct QuizQuestion {
        String^ prompt;
        array<String^>^ options;
        String^ correct_answer;
    };

    generic<typename T>
    public ref class QuizGame {
    private:
        List<QuizQuestion<T>^>^ questions;
        int currentQuestionIndex; // Track the index of the current question
        int score;
        int totalQuestions;

    public:
        int GetScore() {
            return score;
        }

    public:
        QuizGame() {
            questions = gcnew List<QuizQuestion<T>^>();
            currentQuestionIndex = -1; // Initialize current question index
            score = 0;
            totalQuestions = 0;
        }

        List<QuizQuestion<T>^>^ GetQuestions() {
            return questions;
        }

        void LoadQuestionsFromFile(String^ filename) {
            // Clear existing questions
            questions->Clear();
            totalQuestions = 0;

            // Read the file line by line
            StreamReader^ reader = gcnew StreamReader(filename);
            String^ line;
            while ((line = reader->ReadLine()) != nullptr) {
                // Split the line into prompt, options, and correct answer
                array<String^>^ parts = line->Split('|');
                if (parts->Length == 3) {
                    QuizQuestion<T>^ question = gcnew QuizQuestion<T>();
                    question->prompt = parts[0];
                    question->options = parts[1]->Split(',');
                    question->correct_answer = parts[2];
                    questions->Add(question);
                }
            }
            reader->Close();
        }

        void ShowQuestion(Button^ button1, ProgressBar^ progressBar1, Label^ label6, Label^ label3, RadioButton^ radioButton1, RadioButton^ radioButton2, RadioButton^ radioButton3, RadioButton^ radioButton4) {
            // Reset the score if it's a new game
            if (currentQuestionIndex == -1) {
                score = 0;
            }

            // Check if there's a selected answer for the current question
            if (currentQuestionIndex >= 0 && currentQuestionIndex < questions->Count) {
                QuizQuestion<T>^ currentQuestion = questions[currentQuestionIndex];

                // Ensure at least one option is checked before proceeding
                if (!(radioButton1->Checked || radioButton2->Checked || radioButton3->Checked || radioButton4->Checked)) {
                    MessageBox::Show("Please select an answer before proceeding.");
                    return;
                }
            }

            currentQuestionIndex++; // Move to the next question
            if (currentQuestionIndex < 8) {
                // Get the current question
                QuizQuestion<T>^ currentQuestion = questions[currentQuestionIndex];

                // Clear the checked state of all radio buttons
                radioButton1->Checked = false;
                radioButton2->Checked = false;
                radioButton3->Checked = false;
                radioButton4->Checked = false;

                // Display the prompt and options
                label3->Text = currentQuestion->prompt;
                radioButton1->Text = currentQuestion->options[0];
                radioButton2->Text = currentQuestion->options[1];

                // Hide radioButton3 and radioButton4 if the question has only two options
                if (currentQuestion->options->Length == 2) {
                    radioButton3->Visible = false;
                    radioButton4->Visible = false;
                }
                else {
                    // If there are more than two options, ensure both radio buttons are visible
                    radioButton3->Visible = true;
                    radioButton4->Visible = true;
                    radioButton3->Text = currentQuestion->options[2];
                    radioButton4->Text = currentQuestion->options[3];
                }

                // Update progress bar
                progressBar1->Value = (currentQuestionIndex + 1) * 100 / 8;
                label6->Text = "Question " + (currentQuestionIndex + 1);
            }
            else {
                MessageBox::Show("No more questions left!");
                ShowScore();
            }
        }



        void CheckAnswer(String^ selectedAnswer, RadioButton^ radioButton1, RadioButton^ radioButton2,RadioButton^ radioButton3, RadioButton^ radioButton4) {
            if (currentQuestionIndex >= 0 && currentQuestionIndex < questions->Count) {
                // Check if currentQuestionIndex is within the valid range
                QuizQuestion<T>^ currentQuestion = questions[currentQuestionIndex];
                if (currentQuestion != nullptr) {
                    // Check if currentQuestion is not null
                    if (selectedAnswer != nullptr && selectedAnswer->Length > 0) {
                        // Check if selectedAnswer is not null and has length greater than 0
                        if (currentQuestion->correct_answer != nullptr) {
                            // Convert correct answer to string if it's not null
                            String^ correctAnswer = currentQuestion->correct_answer->ToString();

                            // Check if any radio button is checked
                            if (radioButton1->Checked || radioButton2->Checked || radioButton3->Checked || radioButton4->Checked) {
                                // Log or show message boxes for debugging
                                MessageBox::Show("Selected Answer: " + selectedAnswer + "\nCorrect Answer: " + correctAnswer);

                                // Compare selected answer with correct answer
                                if (selectedAnswer->Equals(correctAnswer, StringComparison::OrdinalIgnoreCase)) {
                                    MessageBox::Show("Correct!");
                                    score++;
                                }
                                else {
                                    MessageBox::Show("Incorrect!");
                                }
                            }
                        }
                    }
                }
            }
        }


        void ShowScore() {
            MessageBox::Show("Your Score: " + score + " out of 8 correct");
        }

        void UpdateProgressBar(ProgressBar^ progressBar1) {
            // Implement to update progress bar
        }

        void ShuffleQuestions() {
            Random^ rng = gcnew Random();
            int n = questions->Count;
            while (n > 1) {
                n--;
                int k = rng->Next(n + 1);
                QuizQuestion<T>^ value = questions[k];
                questions[k] = questions[n];
                questions[n] = value;
            }
        }
    };
}


/*void CheckAnswer(String^ selectedAnswer) {
    if (currentQuestionIndex >= 0 && currentQuestionIndex < questions->Count) {
        // Check if currentQuestionIndex is within the valid range
        QuizQuestion<T>^ currentQuestion = questions[currentQuestionIndex];
        if (currentQuestion != nullptr) {
            // Check if currentQuestion is not null
            if (selectedAnswer != nullptr && selectedAnswer->Length > 0) {
                // Check if selectedAnswer is not null and has length greater than 0
                if (currentQuestion->correct_answer != nullptr) {
                    // Convert correct answer to string if it's not null
                    String^ correctAnswer = currentQuestion->correct_answer->ToString();

                    // Log or show message boxes for debugging
                    MessageBox::Show("Selected Answer: " + selectedAnswer + "\nCorrect Answer: " + correctAnswer);

                    // Compare selected answer with correct answer
                    if (selectedAnswer->Equals(correctAnswer, StringComparison::OrdinalIgnoreCase)) {
                        MessageBox::Show("Correct!");
                        score++;
                    }
                    else {
                        MessageBox::Show("Incorrect!");
                    }
                }
                else {
                    MessageBox::Show("Error: Correct answer is null.");
                }
            }
            else {
                MessageBox::Show("Error: Selected answer is null or empty.");
            }
        }
        else {
            MessageBox::Show("Error: Current question is null.");
        }
    }
    else {
        MessageBox::Show("Error: Invalid question index.");
    }
}*/
	


