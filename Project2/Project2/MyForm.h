#pragma once
#include "stdafx.h"
#include <iostream>
#include <string>
#include <msclr\marshal_cppstd.h>
#include <fstream>
#include "Linearstuff.h"

namespace Project2 {


	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{


	public:
		MyForm(Void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  btnFilSel;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	protected:

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
			this->btnFilSel = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// btnFilSel
			// 
			this->btnFilSel->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->btnFilSel->Location = System::Drawing::Point(12, 32);
			this->btnFilSel->Name = L"btnFilSel";
			this->btnFilSel->Size = System::Drawing::Size(324, 101);
			this->btnFilSel->TabIndex = 0;
			this->btnFilSel->Text = L"Select File";
			this->btnFilSel->UseVisualStyleBackColor = false;
			this->btnFilSel->Click += gcnew System::EventHandler(this, &MyForm::btnFilSel_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(312, 20);
			this->label1->TabIndex = 1;
			this->label1->Text = L"No File Selected... Please Select a .mol file.";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(37, 172);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(0, 20);
			this->label2->TabIndex = 2;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(348, 216);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->btnFilSel);
			this->Name = L"MyForm";
			this->Text = L"MyChemSheet";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void btnFilSel_Click(System::Object^  sender, System::EventArgs^  e) {
		std::string mol;
		std::string filepath;
		int filelen;

		openFileDialog1->ShowDialog();

		//validate if mol file
		msclr::interop::marshal_context context;
		mol = context.marshal_as<std::string>(openFileDialog1->FileName);
		filelen = mol.length() - 4;

		if (mol.substr(filelen, mol.length()) == ".mol")
		{

			if (mol.substr(filelen - 3, filelen - 2) == "(" &&
				mol.substr(filelen - 1, filelen) == ")")
				label1->Text = "Cannot open duplicate files; select an original .mol file.";

			label1->Text = openFileDialog1->FileName;

			//retype file location
			filepath = mol.substr(0, 1);
			filepath.append(":\\");
			mol.replace(0, 2, filepath);

			for (int g = 4; g < mol.length(); g++)
			{
				if (mol.substr(g, 1) == "\\")
				{
					mol.replace(g, 1, "/");
				}

			}

			//return molfile
			std::ofstream fout;
			fout.open("output2.txt");
			fout << mol;
		}

		else
			label1->Text = "Invalid File Type. Please Select Another File.";



	}
	};
}
