#pragma once

namespace LevyCurve {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for AboutMe
	/// </summary>
	public ref class AboutMe : public System::Windows::Forms::Form
	{
	public:
		AboutMe(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AboutMe()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ ExitButtonB;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ GoToSite;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	protected:


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AboutMe::typeid));
			this->ExitButtonB = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->GoToSite = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// ExitButtonB
			// 
			this->ExitButtonB->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->ExitButtonB->Location = System::Drawing::Point(452, 489);
			this->ExitButtonB->Name = L"ExitButtonB";
			this->ExitButtonB->Size = System::Drawing::Size(120, 60);
			this->ExitButtonB->TabIndex = 2;
			this->ExitButtonB->Text = L"Main page";
			this->ExitButtonB->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(508, 168);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Program: Levy C Curve\r\nRelease version: 1.01\r\nYear 2022\r\nDeveloped by Aleksey Kha"
				L"rin";
			// 
			// GoToSite
			// 
			this->GoToSite->Location = System::Drawing::Point(326, 489);
			this->GoToSite->Name = L"GoToSite";
			this->GoToSite->Size = System::Drawing::Size(120, 60);
			this->GoToSite->TabIndex = 2;
			this->GoToSite->Text = L"Developer site";
			this->GoToSite->UseVisualStyleBackColor = true;
			this->GoToSite->Click += gcnew System::EventHandler(this, &AboutMe::GoToSite_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox1->Location = System::Drawing::Point(57, 180);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(463, 303);
			this->pictureBox1->TabIndex = 5;
			this->pictureBox1->TabStop = false;
			// 
			// AboutMe
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(584, 561);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->GoToSite);
			this->Controls->Add(this->ExitButtonB);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(600, 600);
			this->MinimumSize = System::Drawing::Size(600, 600);
			this->Name = L"AboutMe";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"About program";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void GoToSite_Click(System::Object^ sender, System::EventArgs^ e);
	};
}
