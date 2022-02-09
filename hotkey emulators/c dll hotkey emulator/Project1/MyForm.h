#pragma once

#using "System.Dll"
#using "System.Windows.Forms.Dll"
#using "System.Drawing.Dll"

#include <windows.h>
#include <tlhelp32.h>

namespace Project1 {

	using namespace System::Drawing;
	using namespace System::Reflection;
	#pragma comment(lib, "user32.lib") 

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Diagnostics;


	void press(BYTE key) {
		//Sleep(50);
		keybd_event(key, 0, 0, 0);
		keybd_event(key, 0, 2, 0);
		Sleep(50);
		keybd_event(key, 0, 0, 0);
		keybd_event(key, 0, 2, 0);
		Sleep(50);
		keybd_event(key, 0, 0, 0);
		keybd_event(key, 0, 2, 0);
		Sleep(100);
	}

	public ref class MyForm : public System::Windows::Forms::Form{
	public:
		MyForm(void){
			InitializeComponent();
		}

	protected:
		~MyForm(){
			if (components){
				delete components;
			}
		}
	internal: System::Windows::Forms::CheckBox^  CheckBox8;
	protected:
	internal: System::Windows::Forms::CheckBox^  CheckBox7;
	internal: System::Windows::Forms::CheckBox^  CheckBox6;
	internal: System::Windows::Forms::CheckBox^  CheckBox5;
	internal: System::Windows::Forms::CheckBox^  CheckBox4;
	internal: System::Windows::Forms::CheckBox^  CheckBox3;
	internal: System::Windows::Forms::CheckBox^  CheckBox2;
	internal: System::Windows::Forms::CheckBox^  CheckBox1;

	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void){
			this->CheckBox8 = (gcnew System::Windows::Forms::CheckBox());
			this->CheckBox7 = (gcnew System::Windows::Forms::CheckBox());
			this->CheckBox6 = (gcnew System::Windows::Forms::CheckBox());
			this->CheckBox5 = (gcnew System::Windows::Forms::CheckBox());
			this->CheckBox4 = (gcnew System::Windows::Forms::CheckBox());
			this->CheckBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->CheckBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->CheckBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->SuspendLayout();
			// 
			// CheckBox8
			// 
			this->CheckBox8->AutoSize = true;
			this->CheckBox8->BackColor = System::Drawing::Color::DarkSlateBlue;
			this->CheckBox8->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->CheckBox8->Font = (gcnew System::Drawing::Font(L"Corbel", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->CheckBox8->ForeColor = System::Drawing::Color::LemonChiffon;
			this->CheckBox8->Location = System::Drawing::Point(28, 90);
			this->CheckBox8->Name = L"CheckBox8";
			this->CheckBox8->Size = System::Drawing::Size(28, 18);
			this->CheckBox8->TabIndex = 15;
			this->CheckBox8->TabStop = false;
			this->CheckBox8->Text = L"\?";
			this->CheckBox8->TextAlign = System::Drawing::ContentAlignment::TopLeft;
			this->CheckBox8->UseVisualStyleBackColor = false;
			this->CheckBox8->Click += gcnew System::EventHandler(this, &MyForm::CheckBox8_Click);
			// 
			// CheckBox7
			// 
			this->CheckBox7->AutoSize = true;
			this->CheckBox7->BackColor = System::Drawing::Color::DarkSlateBlue;
			this->CheckBox7->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->CheckBox7->Font = (gcnew System::Drawing::Font(L"Corbel", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->CheckBox7->ForeColor = System::Drawing::Color::LemonChiffon;
			this->CheckBox7->Location = System::Drawing::Point(96, 90);
			this->CheckBox7->Name = L"CheckBox7";
			this->CheckBox7->Size = System::Drawing::Size(28, 18);
			this->CheckBox7->TabIndex = 14;
			this->CheckBox7->TabStop = false;
			this->CheckBox7->Text = L"x";
			this->CheckBox7->TextAlign = System::Drawing::ContentAlignment::TopLeft;
			this->CheckBox7->UseVisualStyleBackColor = false;
			this->CheckBox7->Click += gcnew System::EventHandler(this, &MyForm::CheckBox7_Click);
			// 
			// CheckBox6
			// 
			this->CheckBox6->AutoSize = true;
			this->CheckBox6->BackColor = System::Drawing::Color::DarkSlateBlue;
			this->CheckBox6->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->CheckBox6->Font = (gcnew System::Drawing::Font(L"Corbel", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->CheckBox6->ForeColor = System::Drawing::Color::LemonChiffon;
			this->CheckBox6->Location = System::Drawing::Point(83, 58);
			this->CheckBox6->Name = L"CheckBox6";
			this->CheckBox6->Size = System::Drawing::Size(62, 18);
			this->CheckBox6->TabIndex = 13;
			this->CheckBox6->TabStop = false;
			this->CheckBox6->Text = L"6";
			this->CheckBox6->TextAlign = System::Drawing::ContentAlignment::TopLeft;
			this->CheckBox6->UseVisualStyleBackColor = false;
			this->CheckBox6->Click += gcnew System::EventHandler(this, &MyForm::CheckBox6_Click);
			// 
			// CheckBox5
			// 
			this->CheckBox5->AutoSize = true;
			this->CheckBox5->BackColor = System::Drawing::Color::DarkSlateBlue;
			this->CheckBox5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->CheckBox5->Font = (gcnew System::Drawing::Font(L"Corbel", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->CheckBox5->ForeColor = System::Drawing::Color::LemonChiffon;
			this->CheckBox5->Location = System::Drawing::Point(83, 33);
			this->CheckBox5->Name = L"CheckBox5";
			this->CheckBox5->Size = System::Drawing::Size(53, 18);
			this->CheckBox5->TabIndex = 12;
			this->CheckBox5->TabStop = false;
			this->CheckBox5->Text = L"5";
			this->CheckBox5->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->CheckBox5->UseVisualStyleBackColor = false;
			this->CheckBox5->Click += gcnew System::EventHandler(this, &MyForm::CheckBox5_Click);
			// 
			// CheckBox4
			// 
			this->CheckBox4->AutoSize = true;
			this->CheckBox4->BackColor = System::Drawing::Color::DarkSlateBlue;
			this->CheckBox4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->CheckBox4->Font = (gcnew System::Drawing::Font(L"Corbel", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->CheckBox4->ForeColor = System::Drawing::Color::LemonChiffon;
			this->CheckBox4->Location = System::Drawing::Point(83, 8);
			this->CheckBox4->Name = L"CheckBox4";
			this->CheckBox4->Size = System::Drawing::Size(55, 18);
			this->CheckBox4->TabIndex = 11;
			this->CheckBox4->TabStop = false;
			this->CheckBox4->Text = L"4";
			this->CheckBox4->TextAlign = System::Drawing::ContentAlignment::TopLeft;
			this->CheckBox4->UseVisualStyleBackColor = false;
			this->CheckBox4->Click += gcnew System::EventHandler(this, &MyForm::CheckBox4_Click);
			// 
			// CheckBox3
			// 
			this->CheckBox3->AutoSize = true;
			this->CheckBox3->BackColor = System::Drawing::Color::DarkSlateBlue;
			this->CheckBox3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->CheckBox3->Font = (gcnew System::Drawing::Font(L"Corbel", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->CheckBox3->ForeColor = System::Drawing::Color::LemonChiffon;
			this->CheckBox3->Location = System::Drawing::Point(10, 58);
			this->CheckBox3->Name = L"CheckBox3";
			this->CheckBox3->Size = System::Drawing::Size(57, 18);
			this->CheckBox3->TabIndex = 10;
			this->CheckBox3->TabStop = false;
			this->CheckBox3->Text = L"3";
			this->CheckBox3->TextAlign = System::Drawing::ContentAlignment::TopLeft;
			this->CheckBox3->UseVisualStyleBackColor = false;
			this->CheckBox3->Click += gcnew System::EventHandler(this, &MyForm::CheckBox3_Click);
			// 
			// CheckBox2
			// 
			this->CheckBox2->AutoSize = true;
			this->CheckBox2->BackColor = System::Drawing::Color::DarkSlateBlue;
			this->CheckBox2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->CheckBox2->Font = (gcnew System::Drawing::Font(L"Corbel", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->CheckBox2->ForeColor = System::Drawing::Color::LemonChiffon;
			this->CheckBox2->Location = System::Drawing::Point(10, 33);
			this->CheckBox2->Name = L"CheckBox2";
			this->CheckBox2->Size = System::Drawing::Size(61, 18);
			this->CheckBox2->TabIndex = 9;
			this->CheckBox2->TabStop = false;
			this->CheckBox2->Text = L"2";
			this->CheckBox2->TextAlign = System::Drawing::ContentAlignment::TopLeft;
			this->CheckBox2->UseVisualStyleBackColor = false;
			this->CheckBox2->Click += gcnew System::EventHandler(this, &MyForm::CheckBox2_Click);
			// 
			// CheckBox1
			// 
			this->CheckBox1->AutoSize = true;
			this->CheckBox1->BackColor = System::Drawing::Color::DarkSlateBlue;
			this->CheckBox1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->CheckBox1->Font = (gcnew System::Drawing::Font(L"Corbel", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->CheckBox1->ForeColor = System::Drawing::Color::LemonChiffon;
			this->CheckBox1->Location = System::Drawing::Point(10, 8);
			this->CheckBox1->Name = L"CheckBox1";
			this->CheckBox1->Size = System::Drawing::Size(60, 18);
			this->CheckBox1->TabIndex = 8;
			this->CheckBox1->TabStop = false;
			this->CheckBox1->Text = L"1";
			this->CheckBox1->TextAlign = System::Drawing::ContentAlignment::TopLeft;
			this->CheckBox1->UseVisualStyleBackColor = false;
			this->CheckBox1->Click += gcnew System::EventHandler(this, &MyForm::CheckBox1_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::DarkSlateBlue;
			this->ClientSize = System::Drawing::Size(151, 110);
			this->ControlBox = false;
			this->Controls->Add(this->CheckBox8);
			this->Controls->Add(this->CheckBox7);
			this->Controls->Add(this->CheckBox6);
			this->Controls->Add(this->CheckBox5);
			this->Controls->Add(this->CheckBox4);
			this->Controls->Add(this->CheckBox3);
			this->Controls->Add(this->CheckBox2);
			this->Controls->Add(this->CheckBox1);
			this->ForeColor = System::Drawing::Color::Black;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"MyForm";
			this->Opacity = 0.8;
			this->ShowIcon = false;
			this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Hide;
			this->Text = L"key emulator";
			this->TopMost = true;
			this->ResumeLayout(false);
			this->PerformLayout();

			this->Cursor = gcnew System::Windows::Forms::Cursor(Assembly::GetExecutingAssembly()->GetManifestResourceStream("cursor.cur"));

		}
#pragma endregion


	private: System::Void CheckBox7_Click(System::Object^  sender, System::EventArgs^  e) {
		press(0x6A); //VK_NUMPAD*
		array<Process^>^ Processes = Process::GetProcessesByName("inj");
		for each (Process^ P in Processes)
			P->Kill();
		MyForm::Close();			
	}
	private: System::Void CheckBox8_Click(System::Object^  sender, System::EventArgs^  e) {
		Beep(900, 1);
		MessageBox::Show("dll hotkey emulator");
		this->CheckBox8->Checked = false;
	}
	private: System::Void CheckBox1_Click(System::Object^  sender, System::EventArgs^  e) {
		Beep(900, 1);
		press(0x61); //VK_NUMPAD1
		this->CheckBox1->Checked = false;
	}
	private: System::Void CheckBox2_Click(System::Object^  sender, System::EventArgs^  e) {
		Beep(900, 1);
		press(0x62); //VK_NUMPAD2
		this->CheckBox2->Checked = false;
	}
	private: System::Void CheckBox3_Click(System::Object^  sender, System::EventArgs^  e) {
		Beep(900, 1);
		press(0x63); //VK_NUMPAD3
		this->CheckBox3->Checked = false;
	}
	private: System::Void CheckBox4_Click(System::Object^  sender, System::EventArgs^  e) {
		Beep(900, 1);
		press(0x64); //VK_NUMPAD4
		this->CheckBox4->Checked = false;
	}
	private: System::Void CheckBox5_Click(System::Object^  sender, System::EventArgs^  e) {
		Beep(900, 1);
		press(0x65); //VK_NUMPAD5
		this->CheckBox5->Checked = false;
	}
	private: System::Void CheckBox6_Click(System::Object^  sender, System::EventArgs^  e) {
		Beep(900, 1);
		press(0x66); //VK_NUMPAD6
		this->CheckBox6->Checked = false;
	}
};
}
