#pragma once

#include <opencv2/videoio.hpp>

using namespace cv;

namespace Projectpaint {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for CameraForm
	/// </summary>
	public ref class CameraForm : public System::Windows::Forms::Form
	{
	public:
		CameraForm(void)
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
		~CameraForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::SplitContainer^ splitContainer1;
	private: System::Windows::Forms::PictureBox^ pictureBox;
	private: System::Windows::Forms::Label^ imageSizeLabel;
	private: System::Windows::Forms::Button^ startButton;
	private: System::Windows::Forms::Label^ captureFPSLabel;

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
			this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			this->pictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->startButton = (gcnew System::Windows::Forms::Button());
			this->imageSizeLabel = (gcnew System::Windows::Forms::Label());
			this->captureFPSLabel = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->BeginInit();
			this->splitContainer1->Panel1->SuspendLayout();
			this->splitContainer1->Panel2->SuspendLayout();
			this->splitContainer1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox))->BeginInit();
			this->SuspendLayout();
			// 
			// splitContainer1
			// 
			this->splitContainer1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer1->Location = System::Drawing::Point(0, 0);
			this->splitContainer1->Name = L"splitContainer1";
			// 
			// splitContainer1.Panel1
			// 
			this->splitContainer1->Panel1->Controls->Add(this->pictureBox);
			// 
			// splitContainer1.Panel2
			// 
			this->splitContainer1->Panel2->Controls->Add(this->captureFPSLabel);
			this->splitContainer1->Panel2->Controls->Add(this->startButton);
			this->splitContainer1->Panel2->Controls->Add(this->imageSizeLabel);
			this->splitContainer1->Size = System::Drawing::Size(284, 261);
			this->splitContainer1->SplitterDistance = 145;
			this->splitContainer1->TabIndex = 0;
			// 
			// pictureBox
			// 
			this->pictureBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pictureBox->Location = System::Drawing::Point(0, 0);
			this->pictureBox->Name = L"pictureBox";
			this->pictureBox->Size = System::Drawing::Size(145, 261);
			this->pictureBox->TabIndex = 0;
			this->pictureBox->TabStop = false;
			// 
			// startButton
			// 
			this->startButton->Location = System::Drawing::Point(48, 226);
			this->startButton->Name = L"startButton";
			this->startButton->Size = System::Drawing::Size(75, 23);
			this->startButton->TabIndex = 1;
			this->startButton->Text = L"Start";
			this->startButton->UseVisualStyleBackColor = true;
			this->startButton->Click += gcnew System::EventHandler(this, &CameraForm::startButton_Click);
			// 
			// imageSizeLabel
			// 
			this->imageSizeLabel->AutoSize = true;
			this->imageSizeLabel->Location = System::Drawing::Point(3, 9);
			this->imageSizeLabel->Name = L"imageSizeLabel";
			this->imageSizeLabel->Size = System::Drawing::Size(92, 13);
			this->imageSizeLabel->TabIndex = 0;
			this->imageSizeLabel->Text = L"Image Size : WxH";
			// 
			// captureFPSLabel
			// 
			this->captureFPSLabel->AutoSize = true;
			this->captureFPSLabel->Location = System::Drawing::Point(15, 22);
			this->captureFPSLabel->Name = L"captureFPSLabel";
			this->captureFPSLabel->Size = System::Drawing::Size(80, 13);
			this->captureFPSLabel->TabIndex = 2;
			this->captureFPSLabel->Text = L"FPS   :   Label2";
			// 
			// CameraForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->splitContainer1);
			this->Name = L"CameraForm";
			this->Text = L"CameraForm";
			this->splitContainer1->Panel1->ResumeLayout(false);
			this->splitContainer1->Panel2->ResumeLayout(false);
			this->splitContainer1->Panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->EndInit();
			this->splitContainer1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
		Bitmap^ bmp;
		bool isStart = false;
private: System::Void startButton_Click(System::Object^ sender, System::EventArgs^ e) {
	if (isStart) {
		isStart = false;
		startButton->Text = "Start";
		return;
	}

	VideoCapture capture(0);
	while (!capture.isOpened());
	int capWidth = (int)capture.get(CAP_PROP_FRAME_WIDTH);
	int capHeight = (int)capture.get(CAP_PROP_FRAME_HEIGHT);
	int capFPS = (int)capture.get(CAP_PROP_FPS);
	imageSizeLabel->Text = System::String::Format("{0:D}x{1:D}", capWidth, capHeight);
	captureFPSLabel->Text = System::String::Format("{0:D}", capFPS);
	isStart = true;

	bmp = gcnew Bitmap(capWidth, capHeight, Imaging::PixelFormat::Format24bppRgb);
	Rectangle rect = Rectangle(0, 0, bmp->Width, bmp->Height);
	startButton->Text = "Stop";

	while (isStart) {
		Mat frame;
		capture >> frame;

		// Convert OpenCV Mat to System Drawing Bitmap
		System::Drawing::Bitmap^ bmpFrame = gcnew System::Drawing::Bitmap(
			frame.cols, frame.rows, frame.step,
			System::Drawing::Imaging::PixelFormat::Format24bppRgb,
			(IntPtr)frame.data
		);

		pictureBox->Image = bmpFrame;
		Application::DoEvents();
	}

	pictureBox->Image = nullptr;  // Clear the image when stopping
}

};
}
