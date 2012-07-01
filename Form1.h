#pragma once


namespace kkkk {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace System::Diagnostics;

	/// <summary>
	/// Form1�� ���� ����Դϴ�.
	///
	/// ���: �� Ŭ������ �̸��� �����ϸ� �� Ŭ������ �����ϴ�
	///          ��� .resx ���ϰ� ���õ� �����Ǵ� ���ҽ� �����Ϸ� ������
	///          '���ҽ� ���� �̸�' �Ӽ��� �����ؾ� �մϴ�. �׷��� ���� ���
	///          �����̳ʴ� �� ���� ���õ� ����ȭ�� ���ҽ���
	///          �ùٸ��� ��ȣ �ۿ��� �� �����ϴ�.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: ������ �ڵ带 ���⿡ �߰��մϴ�.
			//
		}

	protected:
		/// <summary>
		/// ��� ���� ��� ���ҽ��� �����մϴ�.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::ComponentModel::IContainer^  components;
	protected: 

	private:
		/// <summary>
		/// �ʼ� �����̳� �����Դϴ�.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// �����̳� ������ �ʿ��� �޼����Դϴ�.
		/// �� �޼����� ������ �ڵ� ������� �������� ���ʽÿ�.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->pictureBox1->Location = System::Drawing::Point(40, 38);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(772, 595);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 500;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(872, 684);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

		long map(long x, long in_min, long in_max, long out_min, long out_max)
		{
			return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
		}









	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
				 

			 }



			 ref class items
			 {
			 private:
				 array<double> ^ data;
				 Random ^ r;
				 
			 public:

				 int num;

				 items(int num)
				 {
					 data = gcnew array<double>(num);
					 this->num = num;
					 r = gcnew Random();
				 }

				 ~items()
				 {
					 delete data, r;
					 
				 }

				 void newitem()
				 {
					 for (int x = 0; x<num; x++)
					 {
						data[x] = r->Next(0,200);
					 }
				 }
				 
				 array<double> ^ getItem()
				 {
					 return data;
				 }



			 };

			 void drawBar(Graphics ^ g1, items ^ my, int newWidth, Bitmap^ image1, Brush ^ br)
			 {
				 array<double> ^ num = my->getItem();
				 for (int x = 0; x<my->num; x++)
				 {
					 int nfrom = x*newWidth;
					 int nto = (x+1)*newWidth;
					 int nwidth = (nto - nfrom) / 2;

					 g1->FillRectangle(br, nfrom + nwidth / 2 + 1, image1->Height - num[x], nwidth, num[x]);					 
					 //g1->FillRectangle(Brushes::Aqua, x*newWidth, image1->Height - num[x], newWidth, num[x]);					 
				 }
			 }


			 ref class i2cLoc
			 {
				 Byte saddr;
				 UInt16 addr;
				 Int16 lower;
				 Int16 upper;
				 Byte bitmask;


				 delegate void ReadDele(unsigned char addr,  unsigned short control, array<Byte>^ data);
				 delegate void WriteDele(Byte addr, short control, Byte data);




			 public:

				 Byte rawData;

				 i2cLoc(Byte _saddr, UInt16 _addr, Int16 _low, Int16 _up) : saddr(_saddr), addr(_addr), lower(_low), upper(_up)
				 {

					 bitmask = ((1 << (upper - lower + 1) ) - 1);


					 // �Լ� ������ �ѱ��


				 }

			 public:
				 void myset(Byte _saddr, UInt16 _addr, Int16 _low, Int16 _up)
				 {

					 bitmask = ((1 << (upper - lower + 1) ) - 1);
					 
					 saddr = _saddr;
					  addr = _addr;
					  lower = _low;
					  upper = _up;
				 }

				 Byte read()
				 {
					 Byte tempData = 0;

					 // rawdata�� �����°� ���⼭

					 tempData = rawData >> lower;
					 tempData &= bitmask;
					 
					 return tempData;
				 }

				 void write(Byte data)
				 {
					 // ���� ���簪�� �о�´�. rawdata��

					 

					 Byte tempData = data & bitmask;
					 
					 tempData <<= lower;
					 rawData &= ~(bitmask << lower);
					 rawData  |= tempData;
					 
				 }

			 };

			 ref class histfieldItemBase
			 {

				 array<i2cLoc^> ^ i2cloc;


			 public:
				 histfieldItemBase(int i2cLength)
				 {

					 i2cloc = gcnew array<i2cLoc^>(i2cLength);

				 }


			 };

			 ref class histField
			 {
				 int number; 
				 int from;
				 int to;

			 };

			 



			 ref class HistBase
			 {
				 Brush ^ color;

			 public:
				 String ^ name;

				 void setColor(char c)
				 {
					 switch (c)
					 {
					 case 'r':
						color = Brushes::Red;
					 	break;
					 case 'g':
						 color = Brushes::Green;
						 break;
					 case 'b':
						 color = Brushes::Blue;
						 break;
					 case 'c':
						 color = Brushes::Cyan;
						 break;
					 case 'm':
						 color = Brushes::Magenta;
						 break;
					 case 'y':
						 color = Brushes::Yellow;
						 break;
					 }
				 }

				 Brush^ getColor()
				 {
					 return color;
				 }


			 };


			 void readpoint(unsigned char addr,  unsigned short control, array<Byte>^ data)
			 {
				 Debug::WriteLine("DDDDD");
			 }


	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {

				 Bitmap^ image1;
				 Bitmap^ image2;
				 System::Drawing::Font^ myfont = gcnew System::Drawing::Font("Tahoma", 10);

				 int sizex = 480;
				 int sizey = 480;

				 int offsetSide = 20;

				 image1 = gcnew Bitmap(
					 sizex, 
					 sizey
					 );


				 image2 = gcnew Bitmap(
					 sizex, 
					 sizey + offsetSide
					 );


				 i2cLoc ^ i2c = gcnew i2cLoc(0xf, 0x19f, 2, 5);
				 i2c->rawData = 0xFF;

				 static int cnt= 0;
				 i2c->write(cnt);

				 Byte bb = i2c->read();

				 Debug::Write(String::Format("{0:8}", Convert::ToString(bb, 2)) + "\t");

				 Debug::Write(cnt + "\t");
				 Debug::WriteLine(Convert::ToString(i2c->rawData, 2));

				 cnt++;

				 HistBase ^ histItem = gcnew HistBase;
				 histItem->setColor('m');
				 histItem->name = "HELLO WORLD!";

				 items ^ my = gcnew items(10);

				 my->newitem();

				 Graphics ^ g1 = Graphics::FromImage(image1);				 

				 System::Drawing::Pen^ myPen = gcnew System::Drawing::Pen(System::Drawing::Color::White);

				 g1->FillRectangle(Brushes::Gray, 0, 0, image1->Width, image1->Height);
				 int offsetx = (image1->Width) / 16;

				 for (int x = 0; x <= image1->Width; x += offsetx)
				 {
					 g1->DrawLine(myPen, x, 0, x, image1->Height);
				 }

				 for (int y = 0; y <=image1->Height; y += offsetx)
				 {
					 g1->DrawLine(myPen, 0, y, image1->Width, y);
				 }


				 // �� ��� ����
				 int newWidth = map(64 , 0, 1024, 0, sizex);

				 Random ^ r = gcnew Random();
				 int num[16] = {0,};

				 for (int x = 0; x<16; x++)
				 {
					num[x] = r->Next(0,200);
				 }
				 

				 for (int x = 0; x<16; x++)
				 {
					 int nfrom = x*newWidth;
					 int nto = (x+1)*newWidth;
					 int nwidth = (nto - nfrom) / 2;
					 
					 g1->FillRectangle(Brushes::Aqua, nfrom + nwidth / 2 + 1, image1->Height - num[x], nwidth, num[x]);					 
					 //g1->FillRectangle(Brushes::Aqua, x*newWidth, image1->Height - num[x], newWidth, num[x]);					 
				 }

				 drawBar(g1, my, 10, image1, histItem->getColor());


				 // ���� ��� ����
				 System::Drawing::Pen^ myPen1 = gcnew System::Drawing::Pen(System::Drawing::Color::Blue);
				 
				 for (int x = 0; x<16; x++)
				 {
					 num[x] = r->Next(0,200);
				 }

				 g1->SmoothingMode = System::Drawing::Drawing2D::SmoothingMode::AntiAlias;

				 for (int x = 0; x < 15; x++)
				 {
					g1->DrawLine(myPen1, x*newWidth, image1->Height - num[x], (x+1)*newWidth, (image1->Height - num[x+1]) );
				 }
				 
				 g1->SmoothingMode = System::Drawing::Drawing2D::SmoothingMode::None;


				 // ��ü �̹���
				 Graphics ^ g2 = Graphics::FromImage(image2);
				 g2->FillRectangle(Brushes::White, 0,0,image2->Width, image2->Height);

				 // Set format of string.
				 StringFormat ^ drawFormat = gcnew StringFormat();
				 drawFormat->LineAlignment = StringAlignment::Far;
				 drawFormat->Alignment = (StringAlignment::Near);

				 StringFormat ^ drawFormat1 = gcnew StringFormat();
				 drawFormat1->LineAlignment = StringAlignment::Far;
				 drawFormat1->Alignment = (StringAlignment::Far);

				 g2->DrawString("0", myfont, Brushes::Black, PointF(0, (float)image2->Height), drawFormat);
				 g2->DrawString("1024", myfont, Brushes::Black, PointF((float)image2->Width, (float)image2->Height), drawFormat1);
				 g2->DrawImage(image1, 0, 0);

				 pictureBox1->Image = image2;

/*
				 delete r;
				 delete g1, g2;
				 delete image1, image2;
				 delete drawFormat, drawFormat1;
				 delete myfont, myPen;
*/
			 }
};
}

