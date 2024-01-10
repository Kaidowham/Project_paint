#pragma once

#include "CameraForm.h"
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;

namespace Projectpaint {

	using namespace System::Runtime::InteropServices;
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
	private:
		enum class DrawState {
			NotDrawing,
			DrawLine, DrawingLine,
			DrawEllipse, DrawingEllipse,
			PencilDraw, PencilDrawing,
			FillBuget, FillingBuget
		} drawState;
	private: System::Windows::Forms::ToolStripSeparator^ toolStripSeparator2;
	private: System::Windows::Forms::ToolStripSeparator^ toolStripSeparator3;
	private: System::Windows::Forms::ToolStripButton^ cameraButton;
	private: System::Windows::Forms::ToolStripButton^ Pencil;
	private: System::Windows::Forms::ToolStripButton^ Fill;

		Bitmap^ tmpImage;
	public:
		MyForm(void)
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
	private: System::Windows::Forms::ToolStripContainer^ toolStripContainer1;
	private: System::Windows::Forms::MenuStrip^ menuStrip;

	private: System::Windows::Forms::ToolStripMenuItem^ fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ openFileMenu;




	private: System::Windows::Forms::ToolStripSeparator^ toolStripSeparator1;
	private: System::Windows::Forms::ToolStripMenuItem^ exitToolStripMenuItem;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog;
	private: System::Windows::Forms::PictureBox^ pictureBox;


	private: System::Windows::Forms::ToolStripMenuItem^ imageToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ drawLineToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ drawCircleToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ convertToHSVToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ saveFileMenuToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ saveAsToolStripMenuItem;
	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog;

	private: System::Windows::Forms::ToolStrip^ toolStrip;
	private: System::Windows::Forms::ToolStripButton^ toolStripButton1;
	private: System::Windows::Forms::ToolStripButton^ toolStripButton2;
	private: System::Windows::Forms::ToolStripButton^ toolStripButton3;
	private: System::Windows::Forms::StatusStrip^ statusStrip;

	private: System::Windows::Forms::ToolStripStatusLabel^ toolStripStatusLabel1;
	private: System::Windows::Forms::ToolStripStatusLabel^ pixelPointLabel;
	private: System::Windows::Forms::ToolStripStatusLabel^ pixelColorLabel;
	private: System::Windows::Forms::ToolStripStatusLabel^ imageSizeLabel;
	private: System::Windows::Forms::Panel^ pictureBoxPanel;
	private: System::Windows::Forms::ToolStripButton^ toolStripButton4;
	private: System::Windows::Forms::ToolStripButton^ toolStripButton5;
	private: System::Drawing::Point^ startPoint;






	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->toolStripContainer1 = (gcnew System::Windows::Forms::ToolStripContainer());
			this->statusStrip = (gcnew System::Windows::Forms::StatusStrip());
			this->toolStripStatusLabel1 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->pixelPointLabel = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->pixelColorLabel = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->imageSizeLabel = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->pictureBoxPanel = (gcnew System::Windows::Forms::Panel());
			this->pictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->menuStrip = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openFileMenu = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveFileMenuToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveAsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->imageToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->drawLineToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->drawCircleToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->convertToHSVToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStrip = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripButton1 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton2 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton3 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSeparator2 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripButton4 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton5 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSeparator3 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->cameraButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->Pencil = (gcnew System::Windows::Forms::ToolStripButton());
			this->Fill = (gcnew System::Windows::Forms::ToolStripButton());
			this->openFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileDialog = (gcnew System::Windows::Forms::SaveFileDialog());
			this->toolStripContainer1->BottomToolStripPanel->SuspendLayout();
			this->toolStripContainer1->ContentPanel->SuspendLayout();
			this->toolStripContainer1->TopToolStripPanel->SuspendLayout();
			this->toolStripContainer1->SuspendLayout();
			this->statusStrip->SuspendLayout();
			this->pictureBoxPanel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox))->BeginInit();
			this->menuStrip->SuspendLayout();
			this->toolStrip->SuspendLayout();
			this->SuspendLayout();
			// 
			// toolStripContainer1
			// 
			// 
			// toolStripContainer1.BottomToolStripPanel
			// 
			this->toolStripContainer1->BottomToolStripPanel->Controls->Add(this->statusStrip);
			// 
			// toolStripContainer1.ContentPanel
			// 
			this->toolStripContainer1->ContentPanel->Controls->Add(this->pictureBoxPanel);
			this->toolStripContainer1->ContentPanel->Size = System::Drawing::Size(393, 249);
			this->toolStripContainer1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->toolStripContainer1->Location = System::Drawing::Point(0, 0);
			this->toolStripContainer1->Name = L"toolStripContainer1";
			this->toolStripContainer1->Size = System::Drawing::Size(393, 320);
			this->toolStripContainer1->TabIndex = 0;
			this->toolStripContainer1->Text = L"toolStripContainer1";
			// 
			// toolStripContainer1.TopToolStripPanel
			// 
			this->toolStripContainer1->TopToolStripPanel->Controls->Add(this->menuStrip);
			this->toolStripContainer1->TopToolStripPanel->Controls->Add(this->toolStrip);
			// 
			// statusStrip
			// 
			this->statusStrip->Dock = System::Windows::Forms::DockStyle::None;
			this->statusStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->toolStripStatusLabel1,
					this->pixelPointLabel, this->pixelColorLabel, this->imageSizeLabel
			});
			this->statusStrip->Location = System::Drawing::Point(0, 0);
			this->statusStrip->Name = L"statusStrip";
			this->statusStrip->Size = System::Drawing::Size(393, 22);
			this->statusStrip->TabIndex = 0;
			// 
			// toolStripStatusLabel1
			// 
			this->toolStripStatusLabel1->Name = L"toolStripStatusLabel1";
			this->toolStripStatusLabel1->Size = System::Drawing::Size(378, 17);
			this->toolStripStatusLabel1->Spring = true;
			this->toolStripStatusLabel1->Text = L"toolStripStatusLabel1";
			// 
			// pixelPointLabel
			// 
			this->pixelPointLabel->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pixelPointLabel.Image")));
			this->pixelPointLabel->Name = L"pixelPointLabel";
			this->pixelPointLabel->Size = System::Drawing::Size(43, 17);
			this->pixelPointLabel->Text = L"X, Y";
			this->pixelPointLabel->Visible = false;
			// 
			// pixelColorLabel
			// 
			this->pixelColorLabel->Name = L"pixelColorLabel";
			this->pixelColorLabel->Size = System::Drawing::Size(79, 17);
			this->pixelColorLabel->Text = L"RGB=[R, G, B]";
			this->pixelColorLabel->Visible = false;
			// 
			// imageSizeLabel
			// 
			this->imageSizeLabel->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"imageSizeLabel.Image")));
			this->imageSizeLabel->Name = L"imageSizeLabel";
			this->imageSizeLabel->Size = System::Drawing::Size(49, 17);
			this->imageSizeLabel->Text = L"WxH";
			this->imageSizeLabel->Visible = false;
			// 
			// pictureBoxPanel
			// 
			this->pictureBoxPanel->AutoScroll = true;
			this->pictureBoxPanel->Controls->Add(this->pictureBox);
			this->pictureBoxPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pictureBoxPanel->Location = System::Drawing::Point(0, 0);
			this->pictureBoxPanel->Name = L"pictureBoxPanel";
			this->pictureBoxPanel->Size = System::Drawing::Size(393, 249);
			this->pictureBoxPanel->TabIndex = 1;
			// 
			// pictureBox
			// 
			this->pictureBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pictureBox->Location = System::Drawing::Point(0, 0);
			this->pictureBox->Name = L"pictureBox";
			this->pictureBox->Size = System::Drawing::Size(393, 249);
			this->pictureBox->TabIndex = 0;
			this->pictureBox->TabStop = false;
			this->pictureBox->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox_MouseDown);
			this->pictureBox->MouseEnter += gcnew System::EventHandler(this, &MyForm::pictureBox_MouseEnter);
			this->pictureBox->MouseLeave += gcnew System::EventHandler(this, &MyForm::pictureBox_MouseLeave);
			this->pictureBox->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox_MouseMove);
			this->pictureBox->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox_MouseUp);
			// 
			// menuStrip
			// 
			this->menuStrip->Dock = System::Windows::Forms::DockStyle::None;
			this->menuStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->fileToolStripMenuItem,
					this->imageToolStripMenuItem
			});
			this->menuStrip->Location = System::Drawing::Point(0, 0);
			this->menuStrip->Name = L"menuStrip";
			this->menuStrip->Size = System::Drawing::Size(393, 24);
			this->menuStrip->TabIndex = 0;
			this->menuStrip->Text = L"menuStrip";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->openFileMenu,
					this->saveFileMenuToolStripMenuItem, this->saveAsToolStripMenuItem, this->toolStripSeparator1, this->exitToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"&File";
			// 
			// openFileMenu
			// 
			this->openFileMenu->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"openFileMenu.Image")));
			this->openFileMenu->Name = L"openFileMenu";
			this->openFileMenu->Size = System::Drawing::Size(114, 22);
			this->openFileMenu->Text = L"&Open";
			this->openFileMenu->Click += gcnew System::EventHandler(this, &MyForm::openFileMenu_Click);
			// 
			// saveFileMenuToolStripMenuItem
			// 
			this->saveFileMenuToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"saveFileMenuToolStripMenuItem.Image")));
			this->saveFileMenuToolStripMenuItem->Name = L"saveFileMenuToolStripMenuItem";
			this->saveFileMenuToolStripMenuItem->Size = System::Drawing::Size(114, 22);
			this->saveFileMenuToolStripMenuItem->Text = L"&Save";
			this->saveFileMenuToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::saveFileMenuToolStripMenuItem_Click);
			// 
			// saveAsToolStripMenuItem
			// 
			this->saveAsToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"saveAsToolStripMenuItem.Image")));
			this->saveAsToolStripMenuItem->Name = L"saveAsToolStripMenuItem";
			this->saveAsToolStripMenuItem->Size = System::Drawing::Size(114, 22);
			this->saveAsToolStripMenuItem->Text = L"Save &As";
			this->saveAsToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::saveAsToolStripMenuItem_Click);
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(111, 6);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(114, 22);
			this->exitToolStripMenuItem->Text = L"E&xit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::exitToolStripMenuItem_Click);
			// 
			// imageToolStripMenuItem
			// 
			this->imageToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->drawLineToolStripMenuItem,
					this->drawCircleToolStripMenuItem, this->convertToHSVToolStripMenuItem
			});
			this->imageToolStripMenuItem->Name = L"imageToolStripMenuItem";
			this->imageToolStripMenuItem->Size = System::Drawing::Size(52, 20);
			this->imageToolStripMenuItem->Text = L"&Image";
			// 
			// drawLineToolStripMenuItem
			// 
			this->drawLineToolStripMenuItem->Name = L"drawLineToolStripMenuItem";
			this->drawLineToolStripMenuItem->Size = System::Drawing::Size(155, 22);
			this->drawLineToolStripMenuItem->Text = L"Draw &Line";
			this->drawLineToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::drawLineToolStripMenuItem_Click);
			// 
			// drawCircleToolStripMenuItem
			// 
			this->drawCircleToolStripMenuItem->Name = L"drawCircleToolStripMenuItem";
			this->drawCircleToolStripMenuItem->Size = System::Drawing::Size(155, 22);
			this->drawCircleToolStripMenuItem->Text = L"Draw &Circle";
			this->drawCircleToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::drawCircleToolStripMenuItem_Click);
			// 
			// convertToHSVToolStripMenuItem
			// 
			this->convertToHSVToolStripMenuItem->Name = L"convertToHSVToolStripMenuItem";
			this->convertToHSVToolStripMenuItem->Size = System::Drawing::Size(155, 22);
			this->convertToHSVToolStripMenuItem->Text = L"Convert to HSV";
			this->convertToHSVToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::convertToHSVToolStripMenuItem_Click);
			// 
			// toolStrip
			// 
			this->toolStrip->Dock = System::Windows::Forms::DockStyle::None;
			this->toolStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(10) {
				this->toolStripButton1,
					this->toolStripButton2, this->toolStripButton3, this->toolStripSeparator2, this->toolStripButton4, this->toolStripButton5, this->toolStripSeparator3,
					this->cameraButton, this->Pencil, this->Fill
			});
			this->toolStrip->Location = System::Drawing::Point(3, 24);
			this->toolStrip->Name = L"toolStrip";
			this->toolStrip->Size = System::Drawing::Size(239, 25);
			this->toolStrip->TabIndex = 1;
			// 
			// toolStripButton1
			// 
			this->toolStripButton1->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton1.Image")));
			this->toolStripButton1->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton1->Name = L"toolStripButton1";
			this->toolStripButton1->Size = System::Drawing::Size(23, 22);
			this->toolStripButton1->Text = L"toolStripButton1";
			this->toolStripButton1->Click += gcnew System::EventHandler(this, &MyForm::openFileMenu_Click);
			// 
			// toolStripButton2
			// 
			this->toolStripButton2->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton2.Image")));
			this->toolStripButton2->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton2->Name = L"toolStripButton2";
			this->toolStripButton2->Size = System::Drawing::Size(23, 22);
			this->toolStripButton2->Text = L"toolStripButton2";
			this->toolStripButton2->Click += gcnew System::EventHandler(this, &MyForm::saveFileMenuToolStripMenuItem_Click);
			// 
			// toolStripButton3
			// 
			this->toolStripButton3->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton3.Image")));
			this->toolStripButton3->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton3->Name = L"toolStripButton3";
			this->toolStripButton3->Size = System::Drawing::Size(23, 22);
			this->toolStripButton3->Text = L"toolStripButton3";
			this->toolStripButton3->Click += gcnew System::EventHandler(this, &MyForm::saveAsToolStripMenuItem_Click);
			// 
			// toolStripSeparator2
			// 
			this->toolStripSeparator2->Name = L"toolStripSeparator2";
			this->toolStripSeparator2->Size = System::Drawing::Size(6, 25);
			// 
			// toolStripButton4
			// 
			this->toolStripButton4->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton4.Image")));
			this->toolStripButton4->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton4->Name = L"toolStripButton4";
			this->toolStripButton4->Size = System::Drawing::Size(23, 22);
			this->toolStripButton4->Text = L"toolStripButton4";
			this->toolStripButton4->Click += gcnew System::EventHandler(this, &MyForm::drawLineToolStripMenuItem_Click);
			// 
			// toolStripButton5
			// 
			this->toolStripButton5->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton5.Image")));
			this->toolStripButton5->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton5->Name = L"toolStripButton5";
			this->toolStripButton5->Size = System::Drawing::Size(23, 22);
			this->toolStripButton5->Text = L"toolStripButton5";
			this->toolStripButton5->Click += gcnew System::EventHandler(this, &MyForm::drawCircleToolStripMenuItem_Click);
			// 
			// toolStripSeparator3
			// 
			this->toolStripSeparator3->Name = L"toolStripSeparator3";
			this->toolStripSeparator3->Size = System::Drawing::Size(6, 25);
			// 
			// cameraButton
			// 
			this->cameraButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->cameraButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"cameraButton.Image")));
			this->cameraButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->cameraButton->Name = L"cameraButton";
			this->cameraButton->Size = System::Drawing::Size(23, 22);
			this->cameraButton->Text = L"toolStripButton6";
			this->cameraButton->Click += gcnew System::EventHandler(this, &MyForm::cameraButton_Click);
			// 
			// Pencil
			// 
			this->Pencil->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->Pencil->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Pencil.Image")));
			this->Pencil->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->Pencil->Name = L"Pencil";
			this->Pencil->Size = System::Drawing::Size(23, 22);
			this->Pencil->Text = L"Pencil";
			this->Pencil->Click += gcnew System::EventHandler(this, &MyForm::pictureBox_MouseEnter);
			this->Pencil->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox_MouseMove);
			this->Pencil->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox_MouseUp);
			// 
			// Fill
			// 
			this->Fill->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->Fill->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Fill.Image")));
			this->Fill->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->Fill->Name = L"Fill";
			this->Fill->Size = System::Drawing::Size(23, 22);
			this->Fill->Text = L"Fill";
			this->Fill->Click += gcnew System::EventHandler(this, &MyForm::Fill_Click);
			// 
			// openFileDialog
			// 
			this->openFileDialog->FileName = L"openFileDialog";
			this->openFileDialog->Filter = L"Image files|*.jpg;*.png";
			// 
			// saveFileDialog
			// 
			this->saveFileDialog->DefaultExt = L"png";
			this->saveFileDialog->Filter = L"Image files|*.jpg;*.png";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->AutoScrollMinSize = System::Drawing::Size(250, 250);
			this->ClientSize = System::Drawing::Size(393, 320);
			this->Controls->Add(this->toolStripContainer1);
			this->MainMenuStrip = this->menuStrip;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->toolStripContainer1->BottomToolStripPanel->ResumeLayout(false);
			this->toolStripContainer1->BottomToolStripPanel->PerformLayout();
			this->toolStripContainer1->ContentPanel->ResumeLayout(false);
			this->toolStripContainer1->TopToolStripPanel->ResumeLayout(false);
			this->toolStripContainer1->TopToolStripPanel->PerformLayout();
			this->toolStripContainer1->ResumeLayout(false);
			this->toolStripContainer1->PerformLayout();
			this->statusStrip->ResumeLayout(false);
			this->statusStrip->PerformLayout();
			this->pictureBoxPanel->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox))->EndInit();
			this->menuStrip->ResumeLayout(false);
			this->menuStrip->PerformLayout();
			this->toolStrip->ResumeLayout(false);
			this->toolStrip->PerformLayout();
			this->ResumeLayout(false);

		}
		//void PictureBox_Paint(Object^ sender, PaintEventArgs^ e)
		//{
		//	// Your drawing logic goes here
		//	// Example: Draw a line
		//	Pen^ pen = gcnew Pen(Color::Black);
		//	e->Graphics->DrawLine(pen, 0, 0, pictureBox->Width, pictureBox->Height);

		//	// You can add more drawing logic here based on your requirements
		//	// Example: Draw a rectangle
		//	Brush^ brush = gcnew SolidBrush(Color::Red);
		//	e->Graphics->FillRectangle(brush, 50, 50, 100, 100);
		//}
#pragma endregion

	private:
		Bitmap^ bmp;

	private: System::Void openFileMenu_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			Bitmap^ image = gcnew Bitmap(openFileDialog->FileName);
			bmp = gcnew Bitmap(image->Size.Width, image->Size.Height, Imaging::PixelFormat::Format24bppRgb);
			bmp->SetResolution(image->HorizontalResolution, image->VerticalResolution);
			Graphics^ g = Graphics::FromImage(bmp);
			g->DrawImage(image, 0, 0);
			delete image;
			pictureBox->Image = bmp;
		}
	}
	private: System::Void exitToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		Close();
	}
	private: System::Void drawLineToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (bmp != nullptr) {
			drawState = DrawState::DrawLine;
			Cursor = Cursors::Cross;
		}
	}
	private: System::Void drawCircleToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (bmp != nullptr) {
			drawState = DrawState::DrawEllipse;
			Cursor = Cursors::Cross;
		}
	}
	private: System::Void convertToHSVToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		Rectangle rect = Rectangle(0, 0, bmp->Width, bmp->Height);
		System::Drawing::Imaging::BitmapData^ bmpData =
			bmp->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, bmp->PixelFormat);
		Mat image(bmp->Height, bmp->Width, CV_8UC3, bmpData->Scan0.ToPointer(), bmpData->Stride);
		cvtColor(image, image, COLOR_BGR2HSV);
		bmp->UnlockBits(bmpData);
		pictureBox->Image = bmp;
	}
	private: System::Void saveFileMenuToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (bmp != nullptr) {
			bmp->Save(openFileDialog->FileName);
		}
	}
	private: System::Void saveAsToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if ((bmp != nullptr) && (saveFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)) {
			bmp->Save(saveFileDialog->FileName);
		}
	}
	private: System::Void pictureBox_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
		pixelPointLabel->Visible = true;	pixelColorLabel->Visible = true;
	}
	private: System::Void pictureBox_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
		pixelPointLabel->Visible = false;	pixelColorLabel->Visible = false;
	}
	private: System::Void pictureBox_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (bmp == nullptr) return;
		if ((e->X >= 0) && (e->X < bmp->Width) && (e->Y >= 0) && (e->Y < bmp->Height)) {
			pixelPointLabel->Text = System::String::Format("{0}, {1}", e->X, e->Y);
			Color c = bmp->GetPixel(e->X, e->Y);
			pixelColorLabel->Text = System::String::Format("RGB=[{0}, {1}, {2}]", c.R, c.G, c.B);
		}
		if ((drawState == DrawState::DrawingLine) || (drawState == DrawState::DrawingEllipse)) {
			if (tmpImage != nullptr) delete tmpImage;
			tmpImage = (Bitmap^)bmp->Clone();
			// Lock Bitmap Bits …
			// …(เหมือนตอนเปดไฟล แตใชกับ tmpImage)
			// Do OpenCV function

			Rectangle rect = Rectangle(0, 0, tmpImage->Width, tmpImage->Height);
			System::Drawing::Imaging::BitmapData^ bmpData = tmpImage->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, tmpImage->PixelFormat);
			Mat image(tmpImage->Height, tmpImage->Width, CV_8UC3, bmpData->Scan0.ToPointer(), bmpData->Stride);

			switch (drawState) {
			case DrawState::DrawingLine:
				line(image, cv::Point(startPoint->X, startPoint->Y), cv::Point(e->X, e->Y), CV_RGB(0, 255, 0));
				break;
			case DrawState::DrawingEllipse:
				int dx = Math::Abs(startPoint->X - e->X);
				int dy = Math::Abs(startPoint->Y - e->Y);
				ellipse(image, cv::Point(startPoint->X, startPoint->Y), cv::Size(dx, dy), Math::Atan2(dy, dx), 0, 360, CV_RGB(0, 255, 0));
				break;
			case DrawState::PencilDrawing:
				line(image, cv::Point(startPoint->X, startPoint->Y), cv::Point(e->X, e->Y), CV_RGB(0, 0, 255));
				startPoint = gcnew System::Drawing::Point(e->X, e->Y);
				break;
			case DrawState::FillingBuget:
				//fill code here
				break;
			}
			// Unlock Bitmap Bits
			tmpImage->UnlockBits(bmpData);
			pictureBox->Image = tmpImage; // Show result
		}
	}

	private: System::Void pictureBox_MouseDown(System::Object^ sender, MouseEventArgs^ e) {
		if (bmp != nullptr) {
			switch (drawState) {
			case DrawState::DrawLine:
			case DrawState::DrawEllipse:
			case DrawState::PencilDraw:
				startPoint = gcnew System::Drawing::Point(e->X, e->Y);
				if (drawState == DrawState::DrawLine)
					drawState = DrawState::DrawingLine;
				else if (drawState == DrawState::DrawEllipse)
					drawState = DrawState::DrawingEllipse;
				else if (drawState == DrawState::PencilDraw)
					drawState = DrawState::PencilDrawing;
			case DrawState::FillBuget:
				if (drawState == DrawState::FillBuget)
					drawState = DrawState::FillingBuget;
			}
		}
	}
	private: System::Void pictureBox_MouseUp(System::Object^ sender, MouseEventArgs^ e) {
		if ((drawState == DrawState::DrawingLine) || (drawState == DrawState::DrawingEllipse) || (drawState == DrawState::FillingBuget) || (drawState == DrawState::PencilDrawing)) {
			delete startPoint;
			startPoint = nullptr;
			delete bmp;
			bmp = tmpImage;
			tmpImage = nullptr;
			drawState = DrawState::NotDrawing;
			Cursor = Cursors::Default;
		}
	}

	private: System::Void cameraButton_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		CameraForm^ cameraform = gcnew CameraForm();
		cameraform->ShowDialog();
	}
	private: System::Void Pencil_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		 if (bmp != nullptr) {
                        drawState = DrawState::PencilDraw;
                        Cursor = Cursors::Cross;
                }

	}
	private: System::Void Fill_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		 if (bmp != nullptr) {
                        drawState = DrawState::FillBuget;
                        Cursor = Cursors::Cross;
                }
	}
};
}
