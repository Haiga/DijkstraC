#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>
#include "Model\grafo\matrizes\dinamicMatrix.h"
#include "Model\grafo\dijkstra.h"
#include "Model\validators\validate.h"
float PI = 3.1415926535897;
using namespace std;
namespace grafo {

	using namespace System;
	using namespace System::Windows::Forms;
	using namespace System::Drawing;

	#define infinito 1000000000000;
	
	/// <summary>
	/// Sumário para grafoForm
	/// </summary>
	public ref class grafoForm : public System::Windows::Forms::Form
	{
	public:
		grafoForm(void)
		{
			InitializeComponent();
			//
			//TODO: Adicione o código do construtor aqui
			//
		}

	protected:
		/// <summary>
		/// Limpar os recursos que estão sendo usados.
		/// </summary>
		~grafoForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected:
	private: System::Windows::Forms::Label^  label_vertice;
	private: System::Windows::Forms::Label^  label_arestas;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox3;//
	private: System::Windows::Forms::Button^  button_go_result;
	private: System::Windows::Forms::ListBox^  listBox1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::TextBox^  textBox6;
	private: System::Windows::Forms::TextBox^  textBox7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::RadioButton^  radioButton2;
	private: System::Windows::Forms::RadioButton^  radioButton1;

	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;

	private:
		/// <summary>
		/// Variável de designer necessária.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necessário para suporte ao Designer - não modifique 
		/// o conteúdo deste método com o editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label_vertice = (gcnew System::Windows::Forms::Label());
			this->label_arestas = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->button_go_result = (gcnew System::Windows::Forms::Button());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(186, 28);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(218, 25);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Informações do Grafo";
			// 
			// label_vertice
			// 
			this->label_vertice->AutoSize = true;
			this->label_vertice->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_vertice->Location = System::Drawing::Point(45, 78);
			this->label_vertice->Name = L"label_vertice";
			this->label_vertice->Size = System::Drawing::Size(78, 24);
			this->label_vertice->TabIndex = 1;
			this->label_vertice->Text = L"Vértices";
			// 
			// label_arestas
			// 
			this->label_arestas->AutoSize = true;
			this->label_arestas->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_arestas->Location = System::Drawing::Point(282, 78);
			this->label_arestas->Name = L"label_arestas";
			this->label_arestas->Size = System::Drawing::Size(72, 24);
			this->label_arestas->TabIndex = 2;
			this->label_arestas->Text = L"Arestas";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(150, 127);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(70, 20);
			this->textBox1->TabIndex = 3;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &grafoForm::visualizarGrafo);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(360, 127);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(70, 20);
			this->textBox2->TabIndex = 4;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(0, 0);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 20);
			this->textBox3->TabIndex = 0;
			// 
			// button_go_result
			// 
			this->button_go_result->Location = System::Drawing::Point(76, 351);
			this->button_go_result->Name = L"button_go_result";
			this->button_go_result->Size = System::Drawing::Size(121, 60);
			this->button_go_result->TabIndex = 5;
			this->button_go_result->Text = L"   Obter Caminho     Va -> Vb";
			this->button_go_result->UseVisualStyleBackColor = true;
			this->button_go_result->Click += gcnew System::EventHandler(this, &grafoForm::obterResultados);
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(453, 127);
			this->listBox1->MultiColumn = true;
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(113, 121);
			this->listBox1->TabIndex = 6;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(298, 130);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(49, 13);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Vértice 1";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(298, 168);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(49, 13);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Vértice 2";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(360, 165);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(70, 20);
			this->textBox4->TabIndex = 9;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(57, 130);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(62, 13);
			this->label4->TabIndex = 10;
			this->label4->Text = L"Quantidade";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(332, 254);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 37);
			this->button1->TabIndex = 11;
			this->button1->Text = L"Adicionar Aresta";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &grafoForm::adicionarArestaBT);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(460, 257);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 37);
			this->button2->TabIndex = 12;
			this->button2->Text = L"Remover Aresta";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &grafoForm::removerArestaBT);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(316, 204);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(31, 13);
			this->label5->TabIndex = 13;
			this->label5->Text = L"Peso";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(360, 201);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(70, 20);
			this->textBox5->TabIndex = 14;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(393, 351);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(121, 60);
			this->button3->TabIndex = 15;
			this->button3->Text = L"Visualizar Grafo";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &grafoForm::visualizarGrafo);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(57, 309);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(50, 13);
			this->label6->TabIndex = 16;
			this->label6->Text = L"Vértice A";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(147, 309);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(50, 13);
			this->label7->TabIndex = 17;
			this->label7->Text = L"Vértice B";
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(60, 325);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(70, 20);
			this->textBox6->TabIndex = 18;
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(150, 325);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(70, 20);
			this->textBox7->TabIndex = 19;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(457, 110);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(105, 13);
			this->label8->TabIndex = 20;
			this->label8->Text = L"V1         V2       Peso";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->radioButton2);
			this->groupBox1->Controls->Add(this->radioButton1);
			this->groupBox1->Location = System::Drawing::Point(60, 168);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(209, 93);
			this->groupBox1->TabIndex = 23;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"groupBox1";
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Checked = true;
			this->radioButton2->Location = System::Drawing::Point(13, 60);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(112, 17);
			this->radioButton2->TabIndex = 1;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"Grafo Não Dirigido";
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Location = System::Drawing::Point(13, 27);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(89, 17);
			this->radioButton1->TabIndex = 0;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"Grafo Dirigido";
			this->radioButton1->UseVisualStyleBackColor = true;
			this->radioButton1->CheckedChanged += gcnew System::EventHandler(this, &grafoForm::visualizarGrafo);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Location = System::Drawing::Point(702, 96);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(322, 329);
			this->panel1->TabIndex = 25;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->Location = System::Drawing::Point(740, 28);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(247, 25);
			this->label9->TabIndex = 26;
			this->label9->Text = L"Representação do Grafo";
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(233, 351);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(121, 60);
			this->button4->TabIndex = 27;
			this->button4->Text = L"Gerar Grafo    Aleatório";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &grafoForm::gerarGrafoAleatorio);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(572, 165);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(52, 37);
			this->button5->TabIndex = 28;
			this->button5->Text = L"Limpar";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &grafoForm::button5_Click);
			// 
			// grafoForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->ClientSize = System::Drawing::Size(1073, 460);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->textBox7);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->button_go_result);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label_arestas);
			this->Controls->Add(this->label_vertice);
			this->Controls->Add(this->label1);
			this->Name = L"grafoForm";
			this->Text = L"grafoForm";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		
#pragma endregion
		
		private: System::Boolean forDirigido() {
			if (radioButton1->Checked) {
				return true;
			}
			return false;
		}

		private: System::Void obterResultados(System::Object^  sender, System::EventArgs^  e) {
			String ^ numeroVertice = gcnew String(textBox1->Text);
			String ^ verticeA = gcnew String(textBox6->Text);
			String ^ verticeB = gcnew String(textBox7->Text);
			Boolean validNumbers = true;
			alterColorLabels();
			if (!validator::validInteger(textBox1->Text)) {
				textBox1->BackColor = BackColor.Salmon;
				validNumbers = false;
			}
			if (!validator::validInteger(textBox6->Text)) {
				textBox6->BackColor = BackColor.Salmon;
				validNumbers = false;
			}
			if (!validator::validInteger(textBox7->Text)) {
				textBox7->BackColor = BackColor.Salmon;
				validNumbers = false;
			}
			if (!validNumbers) {
				return;
			}
			if (int::Parse(verticeA) > int::Parse(numeroVertice) || int::Parse(verticeB) > int::Parse(numeroVertice)) {
				MessageBox::Show("Vértice acima do número especificado");
				return;
			}
			mostrarResultado();
		}
		private: System::Void mostrarResultado() {
			int numeroDeVertices = int::Parse(textBox1->Text);
			float* custos = alocarArray(numeroDeVertices);
			float** matriz = alocarMatriz(numeroDeVertices, numeroDeVertices);
			for (int i = 0; i < numeroDeVertices; i++) {
				for (int j = 0; j < numeroDeVertices; j++) {
					if (i == j) {
						matriz[i][i] = 0;
					}
					else {
						matriz[i][j] = infinito;
					}
				}
			}
			array< String^ >^ items;
			for (int i = 0; i < listBox1->Items->Count; i++)
			{
				listBox1->SetSelected(i, true);
				items = gcnew array< String^ >(3);
				items = listBox1->SelectedItem->ToString()->Split('\t');
				if (int::Parse(items[0]) > numeroDeVertices || int::Parse(items[1]) > numeroDeVertices) {
					MessageBox::Show("Há Arestas acima da quantidade de vértices. Remova-as, ou aumente a quantidade de Vértices");
					return;
				}
				if (forDirigido()) {
					matriz[int::Parse(items[0]) - 1][int::Parse(items[1]) - 1] = float::Parse(items[2]);
				}
				else {
					matriz[int::Parse(items[0]) - 1][int::Parse(items[1]) - 1] = float::Parse(items[2]);
					matriz[int::Parse(items[1]) - 1][int::Parse(items[0]) - 1] = float::Parse(items[2]);

				}

			}
			String ^ mensagem = gcnew String("");
			custos = distanciasAoVertice((int::Parse(textBox6->Text)), matriz, numeroDeVertices);
			mensagem = mensagem + "Distâncias ao vértice " + textBox6->Text + ":\n";
			for (int i = 0; i < numeroDeVertices; i++) {
				if (custos[i] != 1000000000000) {
					mensagem = mensagem + "vértice " + (i + 1).ToString() + " = " + custos[i].ToString() + "\n";
				}
				else {
					mensagem = mensagem + "vértice " + (i + 1).ToString() + " = " + "infinito" + "\n";
				}

			}
			MessageBox::Show(mensagem);

			if ((custos[int::Parse(textBox7->Text) - 1]) == 1000000000000) {
				if (!temlimitacaoGrafica()) {
					gerarGrafo();
					return;
				}
			}
			if (!temlimitacaoGrafica()) {
				gerarGrafo();
				plotCaminho(numeroDeVertices, custos);
			}
			
		}


		private: System::Void adicionarArestaBT(System::Object^  sender, System::EventArgs^  e) {
			Boolean validNumbers = true;
			alterColorLabels();
			if (!validator::validInteger(textBox1->Text)) {
				textBox1->BackColor = BackColor.Salmon;
				validNumbers = false;
			}
			if (!validator::validInteger(textBox2->Text)) {
				textBox2->BackColor = BackColor.Salmon;
				validNumbers = false;
			}
			if (!validator::validInteger(textBox4->Text)) {
				textBox4->BackColor = BackColor.Salmon;
				validNumbers = false;
			}
			if (!validator::validFloat(textBox5->Text)) {
				textBox5->BackColor = BackColor.Salmon;
				validNumbers = false;
			}
			if (!validNumbers) {
				return;
			}
			if (int::Parse(textBox2->Text) > int::Parse(textBox1->Text) || int::Parse(textBox2->Text) > int::Parse(textBox1->Text)) {
				MessageBox::Show("Vértice acima do número especificado");
				return;
			}
			if (int::Parse(textBox2->Text) == int::Parse(textBox4->Text)) {
				textBox4->BackColor = BackColor.Salmon;
				MessageBox::Show("Vértice de origem deve ser diferente do de destino");
				return;
			}
			for (int i = 0; i < listBox1->Items->Count; i++)
			{
				listBox1->SetSelected(i, true);
				array< String^ >^ items = gcnew array< String^ >(3);
				items = listBox1->SelectedItem->ToString()->Split('\t');
				if (!forDirigido()) {
					if ((int::Parse(textBox2->Text) == int::Parse(items[0]) && int::Parse(textBox4->Text) == int::Parse(items[1])) || (int::Parse(textBox2->Text) == int::Parse(items[1]) && int::Parse(textBox4->Text) == int::Parse(items[0]))) {
						MessageBox::Show("Já há uma aresta entre esses vértices");
						return;
					}
				}
				else {
					if ((int::Parse(textBox2->Text) == int::Parse(items[0]) && int::Parse(textBox4->Text) == int::Parse(items[1]))) {
						MessageBox::Show("Já há uma aresta entre esses vértices");
						return;
					}
				}
				
				
			}

			if (listBox1->Items->Count > 0) {
				listBox1->SetSelected(listBox1->Items->Count - 1, false);
			}
			String ^ newItem = gcnew String("");
			newItem = (int::Parse(textBox2->Text)).ToString() +"\t"+ (int::Parse(textBox4->Text)).ToString() +"\t"+ (float::Parse(textBox5->Text)).ToString();
			
			listBox1->Items->Add(newItem);
			if (!temlimitacaoGrafica()) {
				visualizarGrafo(sender, e);
			}
		}
		private: System::Void removerArestaBT(System::Object^  sender, System::EventArgs^  e) {
			
			alterColorLabels();
			listBox1->Items->Remove(listBox1->SelectedItem);
			visualizarGrafo(sender, e);

		}

		private: System::Void visualizarGrafo(System::Object^  sender, System::EventArgs^  e) {
			if (!forDirigido()) {
				for (int i = 0; i < listBox1->Items->Count; i++)
				{
					listBox1->SetSelected(i, true);
					array< String^ >^ items = gcnew array< String^ >(3);
					items = listBox1->SelectedItem->ToString()->Split('\t');
					for (int j = i + 1; j < listBox1->Items->Count; j++)
					{
						listBox1->SetSelected(j, true);
						array< String^ >^ TempItems = gcnew array< String^ >(3);
						TempItems = listBox1->SelectedItem->ToString()->Split('\t');
						if (int::Parse(TempItems[0]) == int::Parse((items[1])) && int::Parse(TempItems[1]) == int::Parse((items[0]))) {
							MessageBox::Show("Há arestas duplicadas, remova-as!");
							return;
						}
					}
				}
			}
			Boolean validNumbers = true;
			alterColorLabels();

			if (!validator::validInteger(textBox1->Text)) {
				textBox1->BackColor = BackColor.Salmon;
				validNumbers = false;
			}
			if (!validNumbers) {
				return;
			}
			if (!temlimitacaoGrafica()) {
				gerarGrafo();
			}
			
		}
		
			
		private: System::Void gerarGrafo() {
			int numeroDeVertices = int::Parse(textBox1->Text);
			float angulo = 360/numeroDeVertices;
			Pen^ pDirigido = gcnew Pen(System::Drawing::Color::Black,3);
			panel1->CreateGraphics()->Clear(System::Drawing::Color::White);

			int x1, x2, i1, i2;
			array< String^ >^ items;
			for (int i = 0; i < listBox1->Items->Count; i++)
			{
				listBox1->SetSelected(i, true);
				items = gcnew array< String^ >(3);
				items = listBox1->SelectedItem->ToString()->Split('\t');
				
				i1 = int::Parse(items[0]);
				i2 = int::Parse(items[1]);
				
				plotarArestas(pDirigido, i1, i2);
				listBox1->SetSelected(i, false);
			}
			plotarVertices();
			plotarPesos();

		}
		private: System::Void plotarPesos() {
			float angulo = 360 / int::Parse(textBox1->Text);
			
			System::Drawing::Color^ color = gcnew System::Drawing::Color();
			System::Drawing::Font^ drawFont = gcnew System::Drawing::Font("Arial", 10, System::Drawing::FontStyle::Bold);
			System::Drawing::SolidBrush^ drawBrush = gcnew System::Drawing::SolidBrush(color->Blue);
		
			int x1, x2, i1, i2, randNum;
			array< String^ >^ items;
			Point p3;
			for (int i = 0; i < listBox1->Items->Count; i++) {
				listBox1->SetSelected(i, true);
				items = gcnew array< String^ >(3);
				items = listBox1->SelectedItem->ToString()->Split('\t');

				i1 = int::Parse(items[0]);
				i2 = int::Parse(items[1]);
				int addit = 0;
				if (forDirigido()) {
					if (i1 > i2) {
						addit = 8;
					}
				}
				randNum = rand() % 80 + 21;
				x1 = 3 * addit + int(145 + (randNum* (150 * sin(i1*angulo*PI / 180)) + (100 - randNum)*(140 * sin(i2*angulo*PI / 180))) / 100);
				x2 = 3 * addit + int(145 + (randNum* (150 * cos(i1*angulo*PI / 180)) + (100 - randNum)*(140 * cos(i2*angulo*PI / 180))) / 100);

				p3 = System::Drawing::Point(x1, x2);
				panel1->CreateGraphics()->DrawString(items[2], drawFont, drawBrush, p3);
				listBox1->SetSelected(i, false);
			}
		}
		private: System::Void plotCaminho(int numeroDeVertices,float* custos) {
			Pen^ pDirigido = gcnew Pen(System::Drawing::Color::Red, 3);

			Pen^ pInterna = gcnew Pen(System::Drawing::Color::Salmon);
			System::Drawing::Font^ drawFont = gcnew System::Drawing::Font("Arial", 10, System::Drawing::FontStyle::Bold);
			System::Drawing::SolidBrush^ drawBrush = gcnew System::Drawing::SolidBrush(Color::Blue);
			System::Drawing::SolidBrush^ drawBrushBlack = gcnew System::Drawing::SolidBrush(Color::Black);

			float angulo = 360 / numeroDeVertices;
			int vert1 = int::Parse(textBox6->Text) - 1;
			int vert2 = int::Parse(textBox7->Text) - 1;
			float custoAtual = custos[vert2];
			while(vert1!=vert2) {
				for (int i = 0; i < numeroDeVertices; i++) {
					float distVerticeItoVertice2 = 0;
					for (int j = 0; j < listBox1->Items->Count; j++)
					{
						listBox1->SetSelected(j, true);
						array< String^ >^ items = gcnew array< String^ >(3);
						items = listBox1->SelectedItem->ToString()->Split('\t');
						if (((vert2 + 1) == int::Parse(items[0]) && (i + 1) == int::Parse(items[1])) || ((vert2 + 1) == int::Parse(items[1]) && (i + 1) == int::Parse(items[0]))) {
							listBox1->SetSelected(j, false);
							distVerticeItoVertice2 = float::Parse(items[2]);
							break;
						}
					}
					if (distVerticeItoVertice2 != 0) {
						if (custoAtual - distVerticeItoVertice2 == custos[i]) {
							custoAtual = custoAtual - distVerticeItoVertice2;
							
							int i1 = i + 1;
							int i2 = vert2 + 1;
							int x1, x2;
								
							plotarArestas(pDirigido, i1, i2);
							plotarVertices();
							vert2 = i;
							break;
						}
					}
				}
			}
		}
		private: System::Void plotarArestas(Pen^ penUsada, int verticeA, int verticeB) {
			int numeroDeVertices = int::Parse(textBox1->Text);
			float angulo = 360 / numeroDeVertices;
			int addit = 0;
			int i1 = verticeA;
			int i2 = verticeB;
			int x1 ,x2;
			if (forDirigido()) {
				if (i1 > i2) {
					addit = 8;
				}
				Point p1 = System::Drawing::Point(155 + int(150 * sin(i1*angulo*PI / 180)), 160 + int(150 * cos(i1*angulo*PI / 180)));
				Point p2 = System::Drawing::Point(addit + 155 + int(150 * sin(i2*angulo*PI / 180)), 160 + int(150 * cos(i2*angulo*PI / 180)));
				int randNum = 6;


				x1 = int(157 + addit + (randNum* (150 * sin(i1*angulo*PI / 180)) + (100 - randNum)*(150 * sin(i2*angulo*PI / 180))) / 100);
				x2 = int(160 + (randNum* (150 * cos(i1*angulo*PI / 180)) + (100 - randNum)*(150 * cos(i2*angulo*PI / 180))) / 100);
				p1 = System::Drawing::Point(155 + addit + int(150 * sin(i1*angulo*PI / 180)), 160 + int(150 * cos(i1*angulo*PI / 180)));
				if (abs(x2 - (160 + int(150 * cos(i1*angulo*PI / 180)))<3)) {
					if (i1 > i2) {
						p1 = System::Drawing::Point(155 + int(150 * sin(i1*angulo*PI / 180)), 160 + 6 + int(150 * cos(i1*angulo*PI / 180)));
						x2 = x2 + 6;
					}
				}
				Point p3 = System::Drawing::Point(x1, x2);
				penUsada->EndCap = System::Drawing::Drawing2D::LineCap::ArrowAnchor;
				panel1->CreateGraphics()->DrawLine(penUsada, p1, p3);

			}
			else {

				Point p1 = System::Drawing::Point(155 + int(150 * sin(i1*angulo*PI / 180)), 160 + int(150 * cos(i1*angulo*PI / 180)));
				Point p2 = System::Drawing::Point(155 + int(150 * sin(i2*angulo*PI / 180)), 160 + int(150 * cos(i2*angulo*PI / 180)));

				int randNum = rand() % 80 + 21;
				x1 = int(145 + (randNum* (150 * sin(i1*angulo*PI / 180)) + (100 - randNum)*(140 * sin(i2*angulo*PI / 180))) / 100);
				x2 = int(145 + (randNum* (150 * cos(i1*angulo*PI / 180)) + (100 - randNum)*(140 * cos(i2*angulo*PI / 180))) / 100);

				Point p3 = System::Drawing::Point(x1, x2);
				penUsada->Width = 2;
				panel1->CreateGraphics()->DrawLine(penUsada, p1, p2);

			}
		}

		private: System::Void plotarVertices() {
			
			Pen^ penPreto = gcnew Pen(System::Drawing::Color::Black);
			Pen^ penSalmon = gcnew Pen(System::Drawing::Color::Salmon);
			System::Drawing::Font^ drawFont = gcnew System::Drawing::Font("Arial", 10, System::Drawing::FontStyle::Bold);
			System::Drawing::SolidBrush^ drawBrushBlack = gcnew System::Drawing::SolidBrush(Color::Black);


			int numeroDeVertices = int::Parse(textBox1->Text);
			float angulo = 360 / numeroDeVertices;
			String ^ newItem = gcnew String("");
			Point u;

			for (int i = 1; i <= numeroDeVertices; i++) {
				newItem = i.ToString();
				for (int j = 1; j <= 15; j++) {
					panel1->CreateGraphics()->DrawEllipse(penSalmon, 152 + int(150 * sin(i*angulo*PI / 180)), 152 + int(150 * cos(i*angulo*PI / 180)), j, j);
				}
				u = System::Drawing::Point(150 + int(150 * sin(i*angulo*PI / 180)), 150 + int(150 * cos(i*angulo*PI / 180)));
				panel1->CreateGraphics()->DrawString(newItem, drawFont, drawBrushBlack, u);
				panel1->CreateGraphics()->DrawEllipse(penPreto, 150 + int(150 * sin(i*angulo*PI / 180)), 150 + int(150 * cos(i*angulo*PI / 180)), 18, 18);
			}
		}

		private: System::Void alterColorLabels() {
			textBox1->BackColor = BackColor.White;
			textBox2->BackColor = BackColor.White;
			textBox4->BackColor = BackColor.White;
			textBox5->BackColor = BackColor.White;
			textBox6->BackColor = BackColor.White;
			textBox7->BackColor = BackColor.White;
		}
		private: System::Void gerarGrafoAleatorio(System::Object^  sender, System::EventArgs^  e) {
			
			alterColorLabels();
			if (!validator::validInteger(textBox1->Text)) {
				textBox1->BackColor = BackColor.Salmon;
				return;
			}
			int numVariaveis = int::Parse(textBox1->Text);
			
			listBox1->Items->Clear();
			if (forDirigido()) {

				for (int i = 1; i <= numVariaveis; i++) {
					for (int j = 1; j <= numVariaveis; j++) {
						if (i != j) {
							int randNum = rand() % 2;
							if (randNum == 1) {
								String ^ newItem = gcnew String("");
								newItem = (i).ToString() + "\t" + (j).ToString() + "\t" + (1+ rand() % 10).ToString();
								listBox1->Items->Add(newItem);
							}
						}
					}
				}
			}
			else {
				for (int i = 1; i <= numVariaveis; i++) {
					for (int j = i; j <=numVariaveis; j++) {
						if (i != j) {
							int randNum = rand() % 2;
							if (randNum == 1) {
								String ^ newItem = gcnew String("");
								newItem = (i).ToString() + "\t" + (j).ToString() + "\t" + (1 +rand() % 10).ToString();
								listBox1->Items->Add(newItem);
							}
						}
					}
				}
			}
			if (!temlimitacaoGrafica()) {
				visualizarGrafo(sender, e);
			}
			
		}
		
		private: System::Boolean temlimitacaoGrafica() {
			
			if (int::Parse(textBox1->Text) > 19) {
				System::Drawing::Font^ drawFont = gcnew System::Drawing::Font("Arial", 10, System::Drawing::FontStyle::Bold);
				System::Drawing::SolidBrush^ drawBrushBlack = gcnew System::Drawing::SolidBrush(Color::Black);
				Point u = System::Drawing::Point(50, 50);
				panel1->CreateGraphics()->Clear(System::Drawing::Color::White);
				panel1->CreateGraphics()->DrawString("Imagem desnecessariamente grande", drawFont, drawBrushBlack, u);
				return true;
			}
			return false;
		}
		private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
			listBox1->Items->Clear();
			if (validator::validInteger(textBox1->Text)) {
				if (!temlimitacaoGrafica()) {
					visualizarGrafo(sender, e);
				}
			}
		}
	};
}
