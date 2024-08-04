#include "Easy.h"
#include "ReviewPage.h"
#include "Medium.h"
#include "Hard.h"
#include "DashBoard.h"
#include "Login.h"
#include "Registration.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main(array<String^>^ args) {

    Application::SetCompatibleTextRenderingDefault(false);
    Application::EnableVisualStyles();

    QuizAppProject::Login lg;
    QuizAppProject::Registration rn;
    QuizAppProject::DashBoard db;
    QuizAppProject::Easy e;
    QuizAppProject::Hard h;
    QuizAppProject::Medium m;
    QuizAppProject::ReviewPage rp;
   
    Application::Run(% lg);
    Application::Run(% rn);
    Application::Run(% db);
    Application::Run(% e);
    Application::Run(% h);
    Application::Run(% m);
    Application::Run(% rp);

    return 0;
}

