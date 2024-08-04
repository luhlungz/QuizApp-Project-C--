#pragma once
#include "QuizGame.h"

namespace QuizAppProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Medium
	/// </summary>
	public ref class Medium : public System::Windows::Forms::Form
	{
	private:
		int minutes;
		int seconds;

	private:
		// Declare instance of QuizGame
		QuizGame<String^>^ quizgame;

		String^ selectedAnswer;
		// Declare currentQuestionIndex here
		int currentQuestionIndex;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::RadioButton^ radioButton4;
	private: System::Windows::Forms::RadioButton^ radioButton3;
	private: System::Windows::Forms::RadioButton^ radioButton1;
	private: System::Windows::Forms::RadioButton^ radioButton2;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::ProgressBar^ progressBar1;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
		   List<QuizQuestion<String^>^>^ questions;

	public:
		Medium(void)
		{
			InitializeComponent();
			// Initialize the QuizGame instance
			quizgame = gcnew QuizGame<String^>(); // Provide the template argument
			// Load questions from file
			quizgame->LoadQuestionsFromFile("Questions.txt");
			// Shuffle questions
			quizgame->ShuffleQuestions();
			// Initialize current question index
			currentQuestionIndex = 0;
			// Retrieve questions from QuizGame
			questions = quizgame->GetQuestions();
			minutes = 30;
			seconds = 0;
			// Show the first question
			ShowQuestion(currentQuestionIndex);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Medium()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ timer1;

	protected:












	private: System::ComponentModel::IContainer^ components;

	protected:


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Medium::typeid));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->radioButton4 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Interval = 1000;
			this->timer1->Tick += gcnew System::EventHandler(this, &Medium::timer1_Tick);
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(1386, 586);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(81, 32);
			this->button1->TabIndex = 13;
			this->button1->Text = L"Next";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Medium::button1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::Red;
			this->label2->Location = System::Drawing::Point(27, 437);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(171, 20);
			this->label2->TabIndex = 6;
			this->label2->Text = L" + Clear My Choice";
			this->label2->Click += gcnew System::EventHandler(this, &Medium::label2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(27, 63);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(59, 20);
			this->label3->TabIndex = 7;
			this->label3->Text = L"label3";
			// 
			// radioButton4
			// 
			this->radioButton4->AutoSize = true;
			this->radioButton4->BackColor = System::Drawing::Color::Transparent;
			this->radioButton4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->radioButton4->Location = System::Drawing::Point(30, 351);
			this->radioButton4->Name = L"radioButton4";
			this->radioButton4->Size = System::Drawing::Size(137, 24);
			this->radioButton4->TabIndex = 4;
			this->radioButton4->TabStop = true;
			this->radioButton4->Text = L"radioButton4";
			this->radioButton4->UseVisualStyleBackColor = false;
			this->radioButton4->CheckedChanged += gcnew System::EventHandler(this, &Medium::radioButton4_CheckedChanged);
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->BackColor = System::Drawing::Color::Transparent;
			this->radioButton3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->radioButton3->Location = System::Drawing::Point(30, 282);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(137, 24);
			this->radioButton3->TabIndex = 3;
			this->radioButton3->TabStop = true;
			this->radioButton3->Text = L"radioButton3";
			this->radioButton3->UseVisualStyleBackColor = false;
			this->radioButton3->CheckedChanged += gcnew System::EventHandler(this, &Medium::radioButton3_CheckedChanged);
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->BackColor = System::Drawing::Color::Transparent;
			this->radioButton1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->radioButton1->Location = System::Drawing::Point(30, 149);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(137, 24);
			this->radioButton1->TabIndex = 1;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"radioButton1";
			this->radioButton1->UseVisualStyleBackColor = false;
			this->radioButton1->CheckedChanged += gcnew System::EventHandler(this, &Medium::radioButton1_CheckedChanged);
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->BackColor = System::Drawing::Color::Transparent;
			this->radioButton2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->radioButton2->Location = System::Drawing::Point(30, 217);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(137, 24);
			this->radioButton2->TabIndex = 2;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"radioButton2";
			this->radioButton2->UseVisualStyleBackColor = false;
			this->radioButton2->CheckedChanged += gcnew System::EventHandler(this, &Medium::radioButton2_CheckedChanged);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(26, 23);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(59, 20);
			this->label6->TabIndex = 8;
			this->label6->Text = L"label6";
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->panel1->Controls->Add(this->label6);
			this->panel1->Controls->Add(this->radioButton2);
			this->panel1->Controls->Add(this->radioButton1);
			this->panel1->Controls->Add(this->radioButton3);
			this->panel1->Controls->Add(this->radioButton4);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Location = System::Drawing::Point(7, 79);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1460, 477);
			this->panel1->TabIndex = 17;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Medium::panel1_Paint);
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(656, 25);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(811, 23);
			this->progressBar1->TabIndex = 15;
			this->progressBar1->Click += gcnew System::EventHandler(this, &Medium::progressBar1_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::Red;
			this->label4->Location = System::Drawing::Point(12, 25);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(95, 20);
			this->label4->TabIndex = 16;
			this->label4->Text = L"Time Left:";
			this->label4->Click += gcnew System::EventHandler(this, &Medium::label4_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::Transparent;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::White;
			this->label5->Location = System::Drawing::Point(559, 25);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(91, 20);
			this->label5->TabIndex = 18;
			this->label5->Text = L"Progress:";
			this->label5->Click += gcnew System::EventHandler(this, &Medium::label5_Click);
			// 
			// Medium
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(1479, 630);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->progressBar1);
			this->Controls->Add(this->button1);
			this->Name = L"Medium";
			this->Text = L"Medium";
			this->Load += gcnew System::EventHandler(this, &Medium::Medium_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		void ShowQuestion(int index) {
			// Use the QuizGame instance to show the question
			quizgame->ShowQuestion(button1, progressBar1, label6, label3, radioButton1, radioButton2, radioButton3, radioButton4);
		}

		void CheckAnswer(String^ selectedAnswer) {
			// Use the QuizGame instance to check the answer
			quizgame->CheckAnswer(selectedAnswer, radioButton1, radioButton2, radioButton3, radioButton4);
		}

		void UpdateProgressBar() {
			// Use the QuizGame instance to update the progress bar
			quizgame->UpdateProgressBar(progressBar1);
		}

		void ShuffleQuestions() {
			// Use the QuizGame instance to shuffle questions
			quizgame->ShuffleQuestions();
		}

#pragma endregion
	private: System::Void Medium_Load(System::Object^ sender, System::EventArgs^ e) {
		// Add this line inside the Medium_Load() event handler
		timer1->Start();
		// Set the radio buttons to unchecked
		radioButton1->Checked = false;
		radioButton2->Checked = false;
		radioButton3->Checked = false;
		radioButton4->Checked = false;
	}
private: System::Void radioButton1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	RadioButton^ radioButton = dynamic_cast<RadioButton^>(sender);
	if (radioButton != nullptr && radioButton->Checked) {
		selectedAnswer = radioButton->Text;
	}
}
private: System::Void radioButton2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	RadioButton^ radioButton = dynamic_cast<RadioButton^>(sender);
	if (radioButton != nullptr && radioButton->Checked) {
		selectedAnswer = radioButton->Text;
	}
}
private: System::Void radioButton3_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	RadioButton^ radioButton = dynamic_cast<RadioButton^>(sender);
	if (radioButton != nullptr && radioButton->Checked) {
		selectedAnswer = radioButton->Text;
	}
}
private: System::Void radioButton4_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	RadioButton^ radioButton = dynamic_cast<RadioButton^>(sender);
	if (radioButton != nullptr && radioButton->Checked) {
		selectedAnswer = radioButton->Text;
	}
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	// Check the answer only if it's a previously answered question
	if (currentQuestionIndex >= 0) {
		// Check the answer with the selectedAnswer variable
		CheckAnswer(selectedAnswer);
	}

	// Move to the next question if not the last one
	if (currentQuestionIndex < questions->Count - 1) {
		currentQuestionIndex++;
		UpdateProgressBar();
		ShowQuestion(currentQuestionIndex);
	}
	else {
		// Disable the next button
		button1->Enabled = false;
	}
}
private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	// Clear the selection of all radio buttons
	radioButton1->Checked = false;
	radioButton2->Checked = false;
	radioButton3->Checked = false;
	radioButton4->Checked = false;
}
private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
	// Decrement seconds
	seconds--;

	// If seconds reach zero, decrement minutes and reset seconds
	if (seconds < 0) {
		if (minutes > 0) {
			minutes--;
			seconds = 59;
		}
		else {
			// If minutes and seconds both reach zero, stop the timer
			timer1->Stop();
			MessageBox::Show("Time's up! End of Quiz.");
			button1->Enabled = false; // Disable next button
			// Show score or handle end of quiz here
			DisplayScore();
			return;
		}
	}

	// Update the label displaying the time left
	label4->Text = "Time Left: " + minutes.ToString("D2") + ":" + seconds.ToString("D2");
}
private: void DisplayScore() {
	// Assuming you have a QuizGame instance named quizgame
	int score = quizgame->GetScore();
	MessageBox::Show("Your Score: " + score);
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	if (currentQuestionIndex > questions->Count - 1) {
		currentQuestionIndex--;
		UpdateProgressBar();
		ShowQuestion(currentQuestionIndex);
	}
}
private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void progressBar1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
};
}
